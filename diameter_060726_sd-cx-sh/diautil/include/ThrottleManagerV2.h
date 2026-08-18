#ifndef THROTTLEMANAGERV2_H
#define THROTTLEMANAGERV2_H
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <thread>
#include <mutex>
#include <map>
#include <list>
#include <chrono>
#include <cmath>
#include <functional>
#include <algorithm>
#include <type_traits>
#include <condition_variable>
using namespace std;

class ThrottleManagerV2
{
        public:
                using callback_function = std::function<void(bool,const string&)>;

                ~ThrottleManagerV2();
                static ThrottleManagerV2* GetInstance();
                static void DestroyInstance();
                void SetSystemTpt(const int& Threshold);
                int GetSytemTpt();
                void SetCummulationInterval(const int& intvl);
                int GetCummulationInterval();
                void SetScaleFactor(const float& factor);
                float GetScaleFactor();
                void AddPeers(const string& peerName, const int& Threshold);
                bool IsWindowAvailable(const string& PeerName);
                static void ExecuteIfAvailable(const string& peerName, callback_function funct);

        private:
                ThrottleManagerV2();
                static ThrottleManagerV2* mThrottleManagerV2Ptr;

                class Capability
                {
                        public:
                                Capability(){}
                                Capability(int intvl, int sysTpt):cummulationInterval(intvl),maxSystemTpt(sysTpt){};
                                float scaleFactor = 0;
                                int cummulationInterval = 0;
                                int maxSystemTpt = 0;
                                map<string,int> peerMaxTpt;
                };

                class CummulativeTpt
                {
                        public:
                                CummulativeTpt(int intvl):cummulationInterval(intvl),lastUpdate(chrono::high_resolution_clock::now()){}

                                void pushTpt(int tpt)
                                {
                                        if(unusedTpt.size() >= cummulationInterval)
                                                unusedTpt.pop_front();
                                        unusedTpt.push_back(tpt);
                                        lastUpdate = chrono::high_resolution_clock::now();
                                }

                                void clearTpt()
                                {
                                        unusedTpt.clear();
                                        lastUpdate = chrono::high_resolution_clock::now();
                                }

                                int accumulateTptAvg()
                                {
                                        return std::round(std::accumulate(unusedTpt.begin(), unusedTpt.end(), 0)/cummulationInterval);
                                }

                        private:
                                list<int> unusedTpt;
                                unsigned int cummulationInterval = 0;
                                chrono::time_point<chrono::high_resolution_clock> lastUpdate;

                };

                class FairShareTptAllocator
                {
                        public:
                                void AddPeers(const string& peerName)
                                {
                                        peerTptCummulation[peerName] = new CummulativeTpt(peerCapability.cummulationInterval);
                                }

                                int GetFairSharePeerTpt(const string& peerName)
                                {
                                        int maxPeekTpt = std::round( peerCapability.maxSystemTpt * peerCapability.scaleFactor );
                                        int totalTpt = 0;
                                        for(auto& peer : peerTptCummulation)
                                        {
                                                totalTpt += peer.second->accumulateTptAvg();
                                        }

                                        CummulativeTpt *cTpt = peerTptCummulation[peerName];
                                        if(totalTpt < maxPeekTpt)
                                                return cTpt->accumulateTptAvg();
                                        else
                                                return std::floor( ( peerCapability.scaleFactor - 1 ) * cTpt->accumulateTptAvg());
                                }

                                void SetUnUsedTpt(const string& peerName, int tpt)
                                {
                                        std::lock_guard<std::mutex> lk(peerMutex);
                                        CummulativeTpt *cTpt = peerTptCummulation[peerName];
                                        cTpt->pushTpt(tpt);
                                }

                                Capability peerCapability;
                        private:
                                map<string,CummulativeTpt*> peerTptCummulation;
                                mutex peerMutex;

                };

                class Unit
                {
                        public:
                                Unit(int _max):max(_max),lastUpdate(chrono::high_resolution_clock::now()){}
                                int current = 0;
                                int max = 0;
                                condition_variable cv;
                                mutex threadMutex;
                                bool processing = false;
                                bool busy = false;
                                chrono::time_point<chrono::high_resolution_clock> lastUpdate;
                                bool overflowFlag = false;
                                FairShareTptAllocator* allocator;
                };

                Capability                      mCapability;
                FairShareTptAllocator*          mAllocator;
                map<string,Unit*>               peerMap;
};

#endif
