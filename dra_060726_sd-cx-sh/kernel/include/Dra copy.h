//----------------------------------------------------------------------
// NAME :  Dra.h
//
// COPYRIGHT :  Tayana Software Solutions Pvt Ltd -- Copyright(C) 2018
//              All rights reserved. No part of this computer program
//              may be used or reproduced in any form by any
//              means without prior written permission of
//              Tayana Software Solutions Pvt Ltd
//
// DESCRIPTION
//
// Originated :                                     Date:
//----------------------------------------------------------------------
#ifndef INCL_DRA_APP_H
#define INCL_DRA_APP_H

#include "TdraStructs.h"
#include "DraRouting.h"
#include "diameter_cc_application.h"
#include "GxParser.h"
#include "RoParser.h"
#include "Redis.h"
#include "DRA_ConfigHandler.h"
#include "DRA_RelayToPcrf.h"
#include "TGM_aaa_application.h"
#include "DRA_EvrWriter.h"
#include "LogApi.h"
//#include "TssRedis.h"
#include "DraRedisHelper.h" // New Redis Helper Added by Abhishek

#define CONFIG_FILE_NAME "/opt/dra/etc/config/diameter.xml"
using namespace GX;
using namespace RO;
using namespace SY;
#define MAX_FILE_PATH 100
#define MAX_FILE_NAME 100
#define TSS_DRA_APP_MAX_PEG_EVENTS 60

// Changes to be carried out 
// 1. To store the DraRouting Pointer.
// 2. To check the decode of message.

class Dra : public DiameterGxProxySession 
{

	public:

		Dra(AAA_Task &task, DraRouting &routing, int ModuleId);

		virtual DiameterGxProxySession* CreateInstance() ;
		virtual ~Dra ();

		int GetModuleId();

		BOOLEAN GetRoutingDetails (DiameterMsg &msg, DiameterPeerEntry *&dest);

		// Initial Request Recevied
		virtual void ccInitialRequestReceived(DiameterMsg *msg,  DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		
		virtual void ccInitialRequestRtxReceived(DiameterMsg *msg,  DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		virtual void ccInitialAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest); 

		virtual void ccUpdateRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		virtual void ccUpdateAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		virtual void ccTerminateRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest); 

		virtual void ccTerminateAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		virtual void ccEventRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		virtual void ccEventAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		virtual void ccRARequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		virtual void ccRAAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		virtual void ccASRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		virtual void ccASAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		virtual void FormAnswer(DiameterMsg *msg);
		
		virtual void ReplaceResultCodeMSCC(DiameterMsg *msg);
		
		virtual void CheckAndAddGUSOctets(DiameterMsg *msg);
		
		virtual void RelayCCAToPcrf(DiameterMsg *msg);
		
		virtual void RelayASRToPcrf(DiameterMsg *msg);

		virtual void VolumeQuotaThreshold(DiameterMsg *msg);

		virtual void SyncSourceDest(DiameterPeerEntry *source, DiameterPeerEntry *dest);

		virtual void CheckCCAMsg(DiameterMsg *msg);

		virtual void ccAARequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void ccAAAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void ccSTRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void ccSTAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);


		virtual void SLRequestInitial(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void SLAnswerInitialSuccess(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void SLAnswerInitialFailed(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		virtual void SLRequestIntermediate(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void SLAnswerIntermediateSuccess(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void SLAnswerIntermediateFailed(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		
		virtual void SNRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void SNAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
        
		virtual void STRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
        virtual void STAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
                

		//s6a
		virtual void ULRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) ;
		virtual void ULAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);


virtual void AIRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void AIAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void PURequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void PUAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void CLRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void CLAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void IDRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void IDAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void DSRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void DSAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void ResetRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void ResetAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void NotifyRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
virtual void NotifyAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);


		void FormASAnswer(DiameterMsg *msg);

		void SetAlarmForNextDay ();
		void GenerateFile( );
		void GenerateFileRx( );
		void GenerateFileSy( );
                void GenerateFileS6a();
		
		void DisplayPegDetails( DiameterPeerEntry *peerEntry, int i,unsigned long& tps);
		void DisplayPegDetailsSy( DiameterPeerEntry *peerEntry, int i,unsigned long& tps);
		void DisplayPegDetailsRx( DiameterPeerEntry *peerEntry, int i,unsigned long& tps);
                void DisplayPegDetailsS6a( DiameterPeerEntry *peerEntry, int i,unsigned long& tps);
		void StoreMsccUsu(DiameterMsg *msg);
		void EvrWriter(DiameterMsg *msg);
		virtual void ccTccTimeExpired(string &lSessionId, int lApplId);

		bool GetActivePeer(DiameterMsg *msg, string &lListName);	

		protected : 

		AAA_Task    &mTask;
		DraRouting  *mRouting;

		// Below Needs to Be set only in Initial Request.
		DiameterPeerEntry *mDestPeerEntry   = nullptr;
		DiameterPeerEntry *mSourcePeerEntry = nullptr;

		ACE_RW_Mutex m_DraLock;
		int 			 mModuleId;

		map<UINT32, MsccInfo> mMsccInfo;
};

class DraSyncHopByHop : public Redis, public AAA_SyncHopByHopHandler
{
	public:
		bool StartConn()
		{
			return Init(m_redis_ctx, (char*)DIAMETER_CFG_GENERAL()->sync_ip.c_str(), DIAMETER_CFG_GENERAL()->sync_port, 10);
		}

		int SendSyncData(SyncHopByHopIdData &data)
		{
			std::string key = to_string(data.localH2H);
			if(SYNC_OP_ADD == data.op)
			{
				std::map<std::string, std::string> multipleKV;
				multipleKV["node"]  = DIAMETER_CFG_GENERAL()->node_id;
				multipleKV["type"]  = "hh";
				multipleKV["lH2H"]  = to_string(data.localH2H);
				multipleKV["oH2H"]  = to_string(data.origH2H);
				multipleKV["sName"] = data.sourceName;
				multipleKV["dName"] = data.destName;
				multipleKV["op"]    = to_string(data.op);

				
				int expTime = DIAMETER_CFG_TRANSPORT()->hbh_timeout;
            return insert(key, multipleKV, expTime);

			}
			else
			{
				return remove(key);
			}

			return 0;
		}

		int GetSyncData(SyncHopByHopIdData &data)
		{
			std::string key = to_string(data.localH2H);
			std::map<std::string, std::string> multipleKV;

			if(read(key, multipleKV))
			{
				if ( multipleKV.empty()){
					return 0;
				}
				
				auto it = multipleKV.begin();
				std::string dName = it->second;
				
				it++;
				if ( it == multipleKV.end())
					return 0;
				
				std::string lH2H = it->second;
				
				it++;
				if ( it == multipleKV.end())
					return 0;
				
				std::string node = it->second;
				
				it++;
				if ( it == multipleKV.end())
					return 0;
				
				std::string oH2H = it->second;
				
				it++;
				if ( it == multipleKV.end())
					return 0;
				
				std::string op = it->second;
				
				it++;
				if ( it == multipleKV.end())
					return 0;
				
				std::string sName = it->second;

				data.op       = (SyncOperation)atoi(op.c_str());
				data.localH2H = atoi(lH2H.c_str());
				data.origH2H  = atoi(oH2H.c_str());
				snprintf(data.sourceName, sizeof(data.sourceName), "%s",  sName.c_str());
				snprintf(data.destName, sizeof(data.destName), "%s", dName.c_str());

				return 1;
			}
			return 0;
		}

	private:
		redisContext* m_redis_ctx;
};

class DraSyncSession : public Redis, public DiameterCCProxySessionSyncHdlr
{
	public:
		bool StartConn()
		{
			return Init(m_redis_ctx, (char*)DIAMETER_CFG_GENERAL()->sync_ip.c_str(), DIAMETER_CFG_GENERAL()->sync_port, 10);
		}

		int SendSyncData(SyncDccaProxySessionData &data) 
		{
			std::string key     = std::to_string(data.appId) + "_" + string(data.sessionId);

			if(SYNC_OP_ADD == data.op)
			{
				std::map<std::string, std::string> multipleKV;

				multipleKV["node"]  = DIAMETER_CFG_GENERAL()->node_id;
				multipleKV["type"]  = "sid";
				multipleKV["sId"]   = data.sessionId;
				multipleKV["sName"] = data.sourceName;
				multipleKV["dName"] = data.destName;
				multipleKV["appId"]   = to_string(data.appId);
				multipleKV["event"] = to_string(data.event);
				multipleKV["op"]    = to_string(data.op);
				multipleKV["mid"]   = to_string(data.mModuleId);

				int expTime = (DIAMETER_CFG_ACCT_SESSION()->sessionTm + 60);
				return insert(key, multipleKV,expTime);
			}
			else
			{
				return remove(key);
			}

			return 0;
		}	
		
		int RemoveTimeoutData(SyncDccaProxySessionData &data) 
		{
			std::string key = to_string(data.appId) + "_" + string(data.sessionId);
			return removeOnTimeout(key);
		}	

		int GetSyncData(SyncDccaProxySessionData &data)
		{
			std::string key = to_string(data.appId) + "_" + string(data.sessionId);
			std::map<std::string, std::string> multipleKV;
			if(read(key, multipleKV))
			{
				if(!multipleKV.size())
					return 0;

				auto it = multipleKV.begin();
				std::string appId = it->second;
				
				it++;
				if ( it == multipleKV.end())
					return 0;

				std::string dName = it->second; 
				
				it++;
				if ( it == multipleKV.end())
					return 0;
				
				std::string event = it->second;
				
				it++;
				if ( it == multipleKV.end())
					return 0;
				
				std::string modId = it->second;
				
				it++;
				if ( it == multipleKV.end())
					return 0;
				
				std::string node = it->second;
				
				it++;
				if ( it == multipleKV.end())
					return 0;
				
				std::string op = it->second;
				
				it++;
				if ( it == multipleKV.end())
					return 0;
				
				std::string sid = it->second;
				
				it++;
				if ( it == multipleKV.end())
					return 0;
				
				std::string sName = it->second; 

				data.op        = (SyncOperation)atoi(op.c_str());
				data.event     = (DiameterCCProxyEvent)atoi(event.c_str());
				data.mModuleId = atoi(modId.c_str());
				
				snprintf(data.sessionId, sizeof(data.sessionId), "%s", sid.c_str());
				snprintf(data.sourceName,sizeof(data.sourceName), "%s", sName.c_str());
				snprintf(data.destName, sizeof(data.destName), "%s",  dName.c_str());
				
				data.appId       = atoi(appId.c_str());
				return 1;
			}
			return 0;
		}

	private:
		redisContext* m_redis_ctx;

};

//AB
//class DraSyncHopByHopSentnl : public Redis, public AAA_SyncHopByHopHandler
class DraSyncHopByHopSentnl : public TssRedis, public AAA_SyncHopByHopHandler
{
        public:
                bool StartConn()
                {
                        return Init();
                }

                int SendSyncData(SyncHopByHopIdData &data)
		{
			std::string key = to_string(data.localH2H);
			if(SYNC_OP_ADD == data.op)
			{
				std::map<std::string, std::string> multipleKV;
				multipleKV["node"]  = DIAMETER_CFG_GENERAL()->node_id;
				multipleKV["type"]  = "hh";
				multipleKV["lH2H"]  = to_string(data.localH2H);
				multipleKV["oH2H"]  = to_string(data.origH2H);
				multipleKV["sName"] = data.sourceName;
				multipleKV["dName"] = data.destName;
				multipleKV["op"]    = to_string(data.op);


				int expTime = DIAMETER_CFG_TRANSPORT()->hbh_timeout;
				//return insert(key, multipleKV, expTime);
				if(HashSet(key, multipleKV))
				{
					return Expire(key, expTime);
				}
				else
				{
					return false;
				}

			}
			else
			{
				//return remove(key);
				return Del(key);
			}

			return 0;
		}

		int GetSyncData(SyncHopByHopIdData &data)
		{
			std::string key = to_string(data.localH2H);
			std::map<std::string, std::string> multipleKV;

                        //if(read(key, multipleKV))
                        if(HashGetAll(key, multipleKV)) 
                        {
                                if ( multipleKV.empty()){
                                        return 0;
                                }

                                auto it = multipleKV.begin();
                                std::string dName = it->second;

                                it++;
                                if ( it == multipleKV.end())
                                        return 0;

                                std::string lH2H = it->second;

                                it++;
                                if ( it == multipleKV.end())
                                        return 0;

                                std::string node = it->second;

                                it++;
                                if ( it == multipleKV.end())
                                        return 0;

                                std::string oH2H = it->second;

                                it++;
                                if ( it == multipleKV.end())
                                        return 0;

                                std::string op = it->second;

                                it++;
                                if ( it == multipleKV.end())
                                        return 0;

                                std::string sName = it->second;
                                data.op       = (SyncOperation)atoi(op.c_str());
                                data.localH2H = atoi(lH2H.c_str());
                                data.origH2H  = atoi(oH2H.c_str());
                                snprintf(data.sourceName, sizeof(data.sourceName), "%s",  sName.c_str());
                                snprintf(data.destName, sizeof(data.destName), "%s", dName.c_str());

                                return 1;
                        }
                        return 0;
                }
};


/*class RedisHASerializer {
public:

    static constexpr size_t MAX_SERIALIZED_SIZE = 1024;

	static std::string_view Serialize(const SyncDccaProxySessionData& data, char* buffer, size_t bufferSize)
	{
		// 1. Sanity Check
		if (sizeof(SyncDccaProxySessionData) > bufferSize) {
			std::cerr << "[CRITICAL] Buffer too small for serialization!" << std::endl;
			return {};
		}

		// 2. Binary Copy (ALL 468 BYTES)
		std::memcpy(buffer, &data, sizeof(SyncDccaProxySessionData));

		// 3. Return View of FULL SIZE
		// DO NOT USE strlen(buffer) HERE! That is why you got 67 bytes.
		return std::string_view(buffer, sizeof(SyncDccaProxySessionData)); 
	}
	bool Deserialize(const std::string& input, SyncDccaProxySessionData& data) {
		if (input.size() != sizeof(SyncDccaProxySessionData)) {
			std::cerr << "[ERROR] Size mismatch! Redis: " << input.size() 
					<< " Struct: " << sizeof(SyncDccaProxySessionData) << std::endl;
			return false;
		}
		std::memcpy(&data, input.data(), sizeof(SyncDccaProxySessionData));
		return true;
	}
};*/

class DraSyncSessionSentnl : public TssRedis, public DiameterCCProxySessionSyncHdlr
{
	int mExpiryTime = (DIAMETER_CFG_ACCT_SESSION()->sessionTm + 60);
	std::vector<int> supported_apps;

        public:
                bool StartConn()
                {
					for (auto appId : DIAMETER_CFG_GENERAL()->authAppIdLst) 
					{
						supported_apps.push_back((int)appId);
					}
                    return Init("DraRedisHA.cfg");
                }

                int SendSyncData(SyncDccaProxySessionData &data)
                {
                        std::string key     = std::to_string(data.appId) + "_" + string(data.sessionId);

			auto t3 = std::chrono::steady_clock::now();
                        if(SYNC_OP_ADD == data.op)
					{
						std::map<std::string, std::string> multipleKV;

						multipleKV["node"]  = DIAMETER_CFG_GENERAL()->node_id;
						multipleKV["type"]  = "sid";
						multipleKV["sId"]   = data.sessionId;
						multipleKV["sName"] = data.sourceName;
						multipleKV["dName"] = data.destName;
						multipleKV["appId"]   = to_string(data.appId);
						multipleKV["event"] = to_string(data.event);
						multipleKV["op"]    = to_string(data.op);
						multipleKV["mid"]   = to_string(data.mModuleId);

						int expTime = (DIAMETER_CFG_ACCT_SESSION()->sessionTm + 60);
						//return insert(key, multipleKV,expTime);
						if(HashSet(key, multipleKV))
						{
							AAA_LOG((LM_INFO,"%T |DRA_APP| Successfully Sync Session in Redis\n" ));
							bool isEx = Expire(key, expTime);
							auto t4 = std::chrono::steady_clock::now();
							auto d_redis  = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
							AAA_LOG((LM_INFO, "%T |DRA_APP| Direct : RedisOp: %ldus \n", d_redis));

						}
						else
						{
							AAA_LOG((LM_INFO,"%T |DRA_APP| Failed to add Sync session in Redis.\n"));
							return false;
						}
					}
					else
					{
						AAA_LOG((LM_INFO,"%T |DRA_APP| Going to delete Sync Session from Redis\n" ));
						//return remove(key);
						return Del(key);
					}

					return 0;
				}

				int RemoveTimeoutData(SyncDccaProxySessionData &data)
				{
					std::string key = to_string(data.appId) + "_" + string(data.sessionId);
					//return removeOnTimeout(key);
				}

				int GetSyncData(SyncDccaProxySessionData &data)
				{
					std::string key = to_string(data.appId) + "_" + string(data.sessionId);
					std::map<std::string, std::string> multipleKV;
					//if(read(key, multipleKV))
					if(HashGetAll(key, multipleKV)) 
					{
						if(!multipleKV.size())
							return 0;

						auto it = multipleKV.begin();
						std::string appId = it->second;

						it++;
						if ( it == multipleKV.end())
							return 0;

						std::string dName = it->second;

						it++;
						if ( it == multipleKV.end())
							return 0;

						std::string event = it->second;

						it++;
						if ( it == multipleKV.end())
							return 0;

						std::string modId = it->second;

						it++;
						if ( it == multipleKV.end())
							return 0;

						std::string node = it->second;

						it++;
						if ( it == multipleKV.end())
							return 0;

						std::string op = it->second;

						it++;
						if ( it == multipleKV.end())
							return 0;

						std::string sid = it->second;

						it++;
						if ( it == multipleKV.end())
							return 0;

						std::string sName = it->second;

						data.op        = (SyncOperation)atoi(op.c_str());
						data.event     = (DiameterCCProxyEvent)atoi(event.c_str());
						data.mModuleId = atoi(modId.c_str());

										snprintf(data.sessionId, sizeof(data.sessionId), "%s", sid.c_str());
										snprintf(data.sourceName,sizeof(data.sourceName), "%s", sName.c_str());
										snprintf(data.destName, sizeof(data.destName), "%s",  dName.c_str());

										data.appId       = atoi(appId.c_str());
										return 1;
								}
								return 0;
						}

		//Added by Abhishek for pipeline
		// inline uint16_t GetBucketId(const std::string& session_id) 
		// {
		// 	uint32_t hash = 5381;
		// 	for (char c : session_id) hash = ((hash << 5) + hash) + c;	
		// 	return hash & BUCKET_MASK; 
		// }

		
		

		int SaveSessionDataInRedis(SyncDccaProxySessionData &data)
		{
			// 0. Start Timer (Low overhead)
			auto start_ts = std::chrono::steady_clock::now();

			uint16_t bid = HashUtils::GetBucketId(data.sessionId);

			// 1. Measure Bucket ID Calculation
			auto t1 = std::chrono::steady_clock::now();

			RedisKeys keys;
			HashUtils::GenerateKeys(bid, data.appId, keys);

			// 2. Measure Key Generation
			auto t2 = std::chrono::steady_clock::now();

			// Serialize Data
			char buffer[RedisHASerializer::MAX_BUFFER_SIZE];
			std::string_view binaryBlob = RedisHASerializer::Serialize(data, buffer, sizeof(buffer));

			// 3. Measure Serialization
			auto t3 = std::chrono::steady_clock::now();

			if (binaryBlob.size() <= 1)
			{
				AAA_LOG((LM_ERROR, "%T |DRA_APP| Failed to serialize Sync Session Data for Redis storage.\n"));
				return false; // Fail early
			}

			// Calculate Expiry
			auto now_sys = std::chrono::system_clock::now();
			long long expiry = std::chrono::duration_cast<std::chrono::seconds>(now_sys.time_since_epoch()).count() + mExpiryTime;

			bool result = HashSetWithTTL(keys.hKey(), data.sessionId, binaryBlob, keys.zKey(), expiry, keys.tag());

			// 4. Measure Redis Network/Wait Time
			auto t4 = std::chrono::steady_clock::now();

			// --- Performance Analysis Block (Calculates duration in microseconds for precision) ---
			// using microseconds (us) is better than milliseconds (ms) for internal logic profiling
			auto d_bucket = std::chrono::duration_cast<std::chrono::microseconds>(t1 - start_ts).count();
			auto d_keygen = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			auto d_serial = std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count();
			auto d_redis  = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
			auto d_total  = std::chrono::duration_cast<std::chrono::microseconds>(t4 - start_ts).count();

			// Print analysis (using printf for thread-safe atomic output usually, or your logger)
			// Format: [Stage: Time(us)] -> Total(us)
			// We log this regardless of success/fail to catch timeouts
			AAA_LOG((LM_INFO, "%T |DRA_APP| PERF: Bucket: %ldus | KeyGen: %ldus | Serial: %ldus | RedisOp: %ldus | TOTAL: %ldus\n",
						d_bucket, d_keygen, d_serial, d_redis, d_total));

			if (result)
			{
				AAA_LOG((LM_INFO, "%T |DRA_APP| Successfully Saved Sync Session Data in Redis, Key:%s\n", keys.hKey().data() ));
				/*SyncDccaProxySessionData restored;
				if (RedisHASerializer::Deserialize(binaryBlob, restored)) 
				{
					std::cout << "Restored SessionID: " << restored.sessionId << std::endl;
					std::cout << "Restored Source:    " << restored.sourceName << std::endl;
					std::cout << "Restored AppId:     " << restored.appId << endl;
					std::cout << "Restored event:     " << restored.event<< endl;
					std::cout << "Restored Modul:     " << restored.mModuleId<< endl;
					std::cout << "Restored op:        " << restored.op<< endl;
				} 
				else 
				{
					std::cerr << "Deserialization Failed!" << std::endl;
				}*/
				return true;
			}
			else
			{
				AAA_LOG((LM_ERROR, "%T |DRA_APP| Failed to Save Sync Session Data in Redis\n"));
				return false;
			}
		}	
		/*
		 * Uncomment it for release .. TBC
		 * int SaveSessionDataInRedis(SyncDccaProxySessionData &data) 
		 {
		// std::string key     = std::to_string(data.appId) + "_" + string(data.sessionId);

		uint16_t bid = GetBucketId(data.sessionId);
		RedisKeys keys;
		GenerateKeys(bid, data.appId, keys);
		// Serialize Data
		char buffer[RedisHASerializer::MAX_SERIALIZED_SIZE];
		std::string_view binaryBlob = RedisHASerializer::Serialize(data, buffer, sizeof(buffer));
		if (binaryBlob.size() <= 1) 
		{
		AAA_LOG((LM_ERROR,"%T |DRA_APP| Failed to serialize Sync Session Data for Redis storage.\n" ));
		}
		// Calculate Expiry
			auto now = std::chrono::system_clock::now();
			long long expiry = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count() + mExpiryTime;
			
			if(HashSetWithTTL(keys.hKey(), data.sessionId, binaryBlob, keys.zKey(), expiry, keys.tag()))
			{
				AAA_LOG((LM_INFO,"%T |DRA_APP| Successfully Saved Sync Session Data in Redis\n" ));
				return true; 
			}
			else
			{
				AAA_LOG((LM_ERROR,"%T |DRA_APP| Failed to Save Sync Session Data in Redis\n" ));
				return false;
			}

		}*/
		int GetSessionDataFromRedis(SyncDccaProxySessionData &data)
		{
			uint16_t bid = HashUtils::GetBucketId(data.sessionId);
			RedisKeys keys;
			HashUtils::GenerateKeys(bid, data.appId, keys);
			std::string val;
			if (HashGet(keys.hKey(), data.sessionId, val)) 
			{
				// if (val.size() == sizeof(SyncDccaProxySessionData)) 
				{
					//RedisHASerializer serializer; 

					//bool success = serializer.Deserialize(val, data);
					bool success = true;
					if (!RedisHASerializer::Deserialize(val, data))
					{
						/*std::cout << "Restored SessionID: " << data.sessionId << std::endl;
						std::cout << "Restored Source:    " << data.sourceName << std::endl;
						std::cout << "Restored AppId:     " << data.appId << endl;
						std::cout << "Restored event:     " << data.event<< endl;
						std::cout << "Restored Modul:     " << data.mModuleId<< endl;
						std::cout << "Restored op:        " << data.op<< endl;
					}

					if (!success) 
					{*/
						AAA_LOG((LM_ERROR,"%T |DRA_APP| Failed to Deserialize Sync Session Data from Redis, Key: %s\n", keys.hKey().data() ));
					}
					else 
					{
						AAA_LOG((LM_INFO,"%T |DRA_APP| Successfully Retrieved Sync Session Data from Redis, Key: %s\n", keys.hKey().data() ));
					}
					return success;
				}
			}
			return false;
		}
		// ---------------------------------------------------------
		// CLEANUP: The Reaper Thread
		// ---------------------------------------------------------
		bool isRunning = false;
		std::thread reaperThread;
		void StartReaper()
		{
			// 1. Logic Check
			if (isRunning) 
			{
				AAA_LOG((LM_INFO,"%T |DRA_APP| Reaper already running. Aborting start.\n" ));
				return;
			}

			// 2. CRITICAL FIX: Check if the thread object is dirty
			if (reaperThread.joinable()) 
			{
				AAA_LOG((LM_INFO,"%T |DRA_APP| Cleaning up old thread...\n" ));
				reaperThread.join(); // Wait for the old one to truly finish cleanup
			}

			isRunning = true;
			try 
			{
				// Now it is safe to assign
				reaperThread = std::thread(&DraSyncSessionSentnl::ReaperLoop, this);
			} 
			catch (const std::system_error& e) 
			{
				AAA_LOG((LM_ERROR,"%T |DRA_APP| Failed to create thread: %s\n", e.what() ));
				isRunning = false;
				return;
			}
		}
		void StopReaper() 
		{
			isRunning = false;
			if (reaperThread.joinable()) reaperThread.join();
		}
		private:
		void ReaperLoop() 
		{
			int current_bucket = 0; // Start at 0
			const std::string LUA_REAPER_SCRIPT = R"(
				local zset_key = KEYS[1]
				local hash_key = KEYS[2]
				local time_limit = ARGV[1]
				local limit_count = 1000 
				local expired = redis.call('ZRANGEBYSCORE', zset_key, 0, time_limit, 'LIMIT', 0, limit_count)
				if #expired > 0 then
					redis.call('HDEL', hash_key, unpack(expired))
					redis.call('ZREM', zset_key, unpack(expired)) 
				end
				return #expired
			)";
			while (isRunning) 
			{
				auto now = std::chrono::system_clock::now();
				long long current_ts = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
				std::string ts_str = std::to_string(current_ts);

				for (int app_id : supported_apps) 
				{

					// Process 20 buckets sequentially
					for (int i = 0; i < 20; ++i) 
					{
						// 1. Get the deterministic bucket ID
						uint16_t bid = current_bucket;

						// 2. Prepare keys
						RedisKeys keys;
						HashUtils::GenerateKeys(bid, app_id, keys);

						// 3. Clean it
						// Note: This cleans 0, then 1, then 2... guarantees coverage.
						long long deleted = Eval(LUA_REAPER_SCRIPT, {keys.zKeyBuf, keys.hKeyBuf}, {ts_str});

						if (deleted > 0) 
						{
							AAA_LOG((LM_INFO,"%T |DRA_APP| Reaper cleaned bucket %d for App %d, deleted %lld entries.\n", bid, app_id, deleted ));
						}

						// 4. Move to next bucket
						current_bucket++;
						if (current_bucket >= TOTAL_BUCKETS) 
						{
							current_bucket = 0; // Wrap around
						}
					}
				}
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		}
};




//auto TPTInstance = ThrottleManagerV2::GetInstance();

#endif 
#if 0

class DraSleeInterface :  public ServiceGenInterface
{
	public :

		DraSleeInterface () {}

		~DraSleeInterface (){}

		ServiceGenInterface* ServiceConnector ()
		{
			return (ServiceGenInterface*) SERV_MGR()->getServiceObject("DRA.ServiceDRA");
		}

		BOOLEAN   StartService (ServiceGenInterface *ptr)
		{

			SERV_MGR()->StoreServiceInfo("DRA.ServiceDRA", "DRA_1", "DRA.1.0", ptr, SRV_ST_STARTED, SRV_RECVR_AUTO);

			AAA_Task    lTask;
			bool        lReturnValue = false;

			lTask.Start(5);

			DiameterApplication    appCore(lTask, (char*)CONFIG_FILE_NAME);

			DraRouting lDraRouting ("/opt/dra/etc/config/GxDictionary.xml" , "/opt/dra/etc/config/Format.xml" , lReturnValue) ;

			Dra  myDra( lTask , lDraRouting);

			if ( lReturnValue )
			{
				if(AAA_ERR_FAILURE == appCore.RegisterProxyHandler(myDra ))
				{
					printf("--- TBR MAIn RESGISTER FIALED ---\n");
				}

				while(1)
					sleep(1);
			}

			appCore.Close();
			lTask.Stop();

		}
};
	extern "C"
ServiceGenInterface* ServCreate()
{
	return new DraSleeInterface();
}

	extern "C"
void ServDestroy(ServiceGenInterface* p)
{
	delete p;
}
#endif

