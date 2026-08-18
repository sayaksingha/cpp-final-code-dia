static const char *id = " @(#) $Id: ThrottleManagerV2.cc,v 1.1.2.1 2018/03/20 03:18:17 shijuc Exp $";
//----------------------------------------------------------------------
// NAME
//       ThrottleManagerV2.cc
//
// COPYRIGHT
// Tayana Software Solutions Ltd -- Copyright(C) 2018
// All rights reserved. No part of this computer program
// may be used or reproduced in any form by any
// means without prior written permission of
// Tayana Software Solutions Ltd
//
// DESCRIPTION : Handle peer wise throughput for diameter stack
//
// Originated :  Shighil P                               DATE:5-MARCH-2018
//----------------------------------------------------------------------
#include "ThrottleManagerV2.h"

ThrottleManagerV2* ThrottleManagerV2::mThrottleManagerV2Ptr = nullptr;
//-----------------------------------------------------------------------------------------------
// METHOD       : GetInstance() 
// DESCRIPTION  : 
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
ThrottleManagerV2* ThrottleManagerV2::GetInstance()
{
        if(nullptr == mThrottleManagerV2Ptr)
                mThrottleManagerV2Ptr = new ThrottleManagerV2;

        return mThrottleManagerV2Ptr;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : DestroyInstance()
// DESCRIPTION  :
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void ThrottleManagerV2::DestroyInstance()
{
        if(nullptr != mThrottleManagerV2Ptr)
                delete mThrottleManagerV2Ptr;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ThrottleManagerV2
// DESCRIPTION  : constructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
ThrottleManagerV2::ThrottleManagerV2()
{
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ~ThrottleManagerV2() 
// DESCRIPTION  : Destructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
ThrottleManagerV2::~ThrottleManagerV2()
{
        for(auto& peer : peerMap)
                delete  peer.second;

        peerMap.clear();

        if(nullptr != mAllocator)
                delete mAllocator;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : SetSystemTpt
// DESCRIPTION  :	set system level max threshold 
// PARAMETER    : const int&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void ThrottleManagerV2::SetSystemTpt(const int& Threshold)
{
        if(Threshold == 0)
                throw std::invalid_argument( "Throttle API :: TPT cannot to configured to zero");
        mCapability.maxSystemTpt = Threshold;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : GetSytemTpt
// DESCRIPTION  : get system level max threshold
// PARAMETER    : NONE
// RETURN       : int
//-----------------------------------------------------------------------------------------------
int ThrottleManagerV2::GetSytemTpt()
{
        return mCapability.maxSystemTpt;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : SetCummulationInterval
// DESCRIPTION  : Set cummulation interval
// PARAMETER    : const int&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void ThrottleManagerV2::SetCummulationInterval(const int& intvl)
{
        if(intvl == 0)
                throw std::invalid_argument( "Throttle API :: TPT cummulation interval configured to zero");
        mCapability.cummulationInterval = intvl;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : GetCummulationInterval
// DESCRIPTION  : get cummulation interval
// PARAMETER    : NONE
// RETURN       : int
//-----------------------------------------------------------------------------------------------
int ThrottleManagerV2::GetCummulationInterval()
{
        return mCapability.cummulationInterval;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : SetScaleFactor
// DESCRIPTION  :	set scaling factor for system level threshold 
// PARAMETER    : const float&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void  ThrottleManagerV2::SetScaleFactor(const float& factor)
{
        if(factor == 0.0)
                throw std::invalid_argument("Throttle API :: TPT scale factor configured to zero");
        mCapability.scaleFactor = factor;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : GetScaleFactor
// DESCRIPTION  : get scaling factor for system level threshold
// PARAMETER    : NONE
// RETURN       : float
//-----------------------------------------------------------------------------------------------
float  ThrottleManagerV2::GetScaleFactor()
{
        return mCapability.scaleFactor;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : AddPeers
// DESCRIPTION  : Add peer wise threshold
// PARAMETER    : const string&, const int&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void ThrottleManagerV2::AddPeers(const string& peerName, const int& Threshold)
{
        int totalTpt = 0;
        for(auto& peer : peerMap)
                totalTpt += peer.second->max;

        if((totalTpt + Threshold) > mCapability.maxSystemTpt)
                throw std::invalid_argument("Throttle API :: Peer TPT Exceeded system TPT");

        Unit *lUnit = new Unit(Threshold);
        if(nullptr == mAllocator)
        {
                mAllocator = new FairShareTptAllocator;
                mAllocator->peerCapability = mCapability;
        }
        mAllocator->AddPeers(peerName);
        lUnit->allocator = mAllocator;
        peerMap[peerName] = lUnit;

        return;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : IsWindowAvailable 
// DESCRIPTION  : check if threshold is exceeded
// PARAMETER    : const string&
// RETURN       : bool 
//-----------------------------------------------------------------------------------------------
bool ThrottleManagerV2::IsWindowAvailable(const string& PeerName)
{
        Unit *peer = peerMap[PeerName];

        if(nullptr == peer)
        {
                //throw exception - if needed// std::throw runtime_error("Throttle API :: Unknown Peer");
                return false;
        }

        chrono::time_point<chrono::high_resolution_clock> lCurrentTime = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = lCurrentTime - peer->lastUpdate;

        if(diff.count() > 1)
        {
                std::lock_guard<std::mutex> lk(peer->threadMutex);
                int unusedTpt = peer->max - peer->current;
                if(unusedTpt < 0)
                        peer->allocator->SetUnUsedTpt(PeerName, 0);
                else
                        peer->allocator->SetUnUsedTpt(PeerName,unusedTpt);
                peer->busy = false;
                peer->current = 0;
                peer->overflowFlag = false;
        }

        if(peer->busy)
        {
                if(peer->allocator->GetFairSharePeerTpt(PeerName) > 0)
                        peer->overflowFlag = true;
                else
                        return false;
        }

        std::unique_lock<std::mutex> lk(peer->threadMutex);
        peer->cv.wait(lk, [&peer]{return !(peer->processing);});

        peer->processing = true;
        if((peer->current+1 <= peer->max && !peer->overflowFlag)
                || ((peer->current+1 <= peer->max + peer->allocator->GetFairSharePeerTpt(PeerName))
                && peer->overflowFlag))
        {
                peer->current++;
                peer->processing = false;
                peer->lastUpdate = chrono::high_resolution_clock::now();

                lk.unlock();
                peer->cv.notify_one();
                return true;
        }
        else
        {
                peer->busy = true;
                peer->processing = false;
                peer->lastUpdate = chrono::high_resolution_clock::now();
                lk.unlock();
                peer->cv.notify_all();
                return false;
        }
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ExecuteIfAvailable
// DESCRIPTION  : execute a call back function according to the threshold check  
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void ThrottleManagerV2::ExecuteIfAvailable(const string& peerName, callback_function funct )
{
        ThrottleManagerV2 *msg = ThrottleManagerV2::GetInstance();
        funct(msg->IsWindowAvailable(peerName), peerName);
        return;
}

