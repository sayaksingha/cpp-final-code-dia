static const char *id = " @(#) $Id: ThrottleManagerV1.cc,v 1.1.2.1 2018/03/20 03:18:16 shijuc Exp $";
//----------------------------------------------------------------------
// NAME
//       ThrottleManagerV1.cc
//
// COPYRIGHT
// Tayana Software Solutions Ltd -- Copyright(C) 2017
// All rights reserved. No part of this computer program
// may be used or reproduced in any form by any
// means without prior written permission of
// Tayana Software Solutions Ltd
//
// DESCRIPTION : Handle peer wise throughput for diameter stack 
//
// Originated :  Shighil P                               DATE:5-MARCH-2018
//----------------------------------------------------------------------
#include "ThrottleManagerV1.h"

ThrottleManagerV1* ThrottleManagerV1::mThrottleManagerV1Ptr = NULL;
//-----------------------------------------------------------------------------------------------
// METHOD       : ThrottleManagerV1
// DESCRIPTION  : Constructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
ThrottleManagerV1::ThrottleManagerV1()
{
}

//-----------------------------------------------------------------------------------------------
// METHOD       : ThrottleManagerV1
// DESCRIPTION  : destructor
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
ThrottleManagerV1::~ThrottleManagerV1()
{
        for(auto& peer : mPeerMap)
                delete  peer.second;

        mPeerMap.clear();
}

//-----------------------------------------------------------------------------------------------
// METHOD       : GetInstance()
// DESCRIPTION  : 
// PARAMETER    : NONE 
// RETURN       : ThrottleManagerV1*
//-----------------------------------------------------------------------------------------------
ThrottleManagerV1* ThrottleManagerV1::GetInstance()
{
        if(NULL == mThrottleManagerV1Ptr)
                mThrottleManagerV1Ptr = new ThrottleManagerV1;

        return mThrottleManagerV1Ptr;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : DestroyInstance()
// DESCRIPTION  :
// PARAMETER    : NONE 
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void ThrottleManagerV1::DestroyInstance()
{
        delete mThrottleManagerV1Ptr;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : AddPeer
// DESCRIPTION  : Add peers
// PARAMETER    : string, int
// RETURN       : NULL
//-----------------------------------------------------------------------------------------------
void ThrottleManagerV1::AddPeer(const string& peerName, const int& Threshold)
{
        Unit *lUnit = new Unit(Threshold);
        mPeerMap[peerName] = lUnit;
        return;
}

//-----------------------------------------------------------------------------------------------
// METHOD       : AlterPeer
// DESCRIPTION  : Add peers
// PARAMETER    : string, int
// RETURN       : NULL
//-----------------------------------------------------------------------------------------------
void ThrottleManagerV1::AlterPeer(const string& peerName, const int& Threshold)
{
		Unit *lUnit = mPeerMap[peerName];
		delete lUnit;
		lUnit = new Unit(Threshold);
		mPeerMap[peerName] = lUnit;
		return; 
}

//-----------------------------------------------------------------------------------------------
// METHOD       : DeletePeer
// DESCRIPTION  : Delete peers
// PARAMETER    : string&,
// RETURN       : NULL
//-----------------------------------------------------------------------------------------------
void ThrottleManagerV1::DeletePeer(const string& peerName)
{
	auto itr = mPeerMap.find(peerName);
	if(itr != mPeerMap.end())
		mPeerMap.erase(itr);
}

//-----------------------------------------------------------------------------------------------
// METHOD       : IsWindowAvailable
// DESCRIPTION  : Check if throughtput is available for a peer in current second
// PARAMETER    : string&
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
bool ThrottleManagerV1::IsWindowAvailable(const string& PeerName)
{
        Unit *peer = mPeerMap[PeerName];

        if(NULL == peer)
        {
                //throw exception - if needed
                return false;
        }

        chrono::time_point<chrono::high_resolution_clock> lCurrentTime = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = lCurrentTime - peer->lastUpdate;

        if(diff.count() > 1)
        {
					 std::lock_guard<std::mutex> lk(peer->threadMutex);
                peer->busy = false;
                peer->current = 0;
        }

        if(peer->busy)
        {
                return false;
        }

        std::unique_lock<std::mutex> lk(peer->threadMutex);
        peer->cv.wait(lk, [&peer]{return !(peer->processing);});

        peer->processing = true;
        if(peer->current+1 <= peer->max)
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
// DESCRIPTION  : Call back functions based on throughput availability
// PARAMETER    : NONE
// RETURN       : NONE
//-----------------------------------------------------------------------------------------------
void ThrottleManagerV1::ExecuteIfAvailable(ThrottleManagerV1& mgr,const string& peerName, callback_function funct )
{
	funct(mgr.IsWindowAvailable(peerName));
	return;
}
