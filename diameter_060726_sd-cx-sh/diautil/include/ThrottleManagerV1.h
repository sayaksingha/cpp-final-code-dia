#ifndef THROTTLEMANAGERV1_H
#define THROTTLEMANAGERV1_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <thread>
#include <mutex>
#include <map>
#include <chrono>
#include <functional>
#include <condition_variable>
using namespace std;

class ThrottleManagerV1
{
        public:
                using callback_function = std::function<void(bool)>;

                ~ThrottleManagerV1();
					 static ThrottleManagerV1* GetInstance();
					 static void DestroyInstance();
                void AddPeer(const string& peerName, const int& Threshold);
					 void AlterPeer(const string& peerName, const int& Threshold);
					 void DeletePeer(const string& peerName);
                bool IsWindowAvailable(const string& PeerName);
                static void ExecuteIfAvailable(ThrottleManagerV1& mgr,const string& peerName, callback_function funct);

        private:
					 ThrottleManagerV1();
					 static ThrottleManagerV1* mThrottleManagerV1Ptr;
					 class Unit
					 {
						 public:
							 Unit(int _max):max(_max),lastUpdate(chrono::high_resolution_clock::now()){}
							 int current = 0;
							 int max = 0;
							 condition_variable cv;
							 mutex   threadMutex;
							 bool processing = false;
							 bool busy = false;
							 chrono::time_point<chrono::high_resolution_clock> lastUpdate;
					 };

					 map<string,Unit*> mPeerMap;
};
#endif
