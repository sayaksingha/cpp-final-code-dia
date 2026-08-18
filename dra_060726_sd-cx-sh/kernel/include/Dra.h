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
using namespace S6A;
using namespace SLH;
using namespace CX;

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


		virtual void RIRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void RIAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);


		// Sd
		virtual void TSRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void TSAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void CCRequestReceivedSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void CCAnswerReceivedSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void RARequestReceivedSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void RAAnswerReceivedSd(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		
		// Sh
		virtual void UDRequestReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void UDAnswerReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void PURequestReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void PUAnswerReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void SNRequestReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void SNAnswerReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void PNRequestReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void PNAnswerReceivedSh(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		
		// Cx
		virtual void UARequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void UAAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void SARequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void SAAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void LIRequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void LIAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void MARequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void MAAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void RTRequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void RTAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void PPRequestReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		virtual void PPAnswerReceivedCx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		void FormASAnswer(DiameterMsg *msg);

		void SetAlarmForNextDay ();
		void GenerateFile( );
		void GenerateFileRx( );
		void GenerateFileSy( );
 	        void GenerateFileS6a();
		void GenerateFileSlh();
 		void GenerateFileSh();		
		void GenerateFileCx();

		void DisplayPegDetails( DiameterPeerEntry *peerEntry, int i,unsigned long& tps);
		void DisplayPegDetailsSy( DiameterPeerEntry *peerEntry, int i,unsigned long& tps);
		void DisplayPegDetailsRx( DiameterPeerEntry *peerEntry, int i,unsigned long& tps);
	        void DisplayPegDetailsS6a( DiameterPeerEntry *peerEntry, int i,unsigned long& tps);
		void DisplayPegDetailsSlh( DiameterPeerEntry *peerEntry, int i,unsigned long& tps);
		void DisplayPegDetailsSd(DiameterPeerEntry *peerEntry, int i, unsigned long& tps);
                void DisplayPegDetailsSh(DiameterPeerEntry *peerEntry, int i, unsigned long& tps);
                void DisplayPegDetailsCx(DiameterPeerEntry *peerEntry, int i, unsigned long& tps);

		void GenerateFileSd();
		void StoreMsccUsu(DiameterMsg *msg);
		void EvrWriter(DiameterMsg *msg);
		virtual void ccTccTimeExpired(string &lSessionId, int lApplId);

		bool GetActivePeer(DiameterMsg *msg, string &lListName);	

		protected : 
                void S6aHandleRequest(DiameterMsg *msg, DiameterPeerEntry *source, 
                          DiameterPeerEntry *&dest, const char* msgType);

void HandleRequest(DiameterMsg *msg, DiameterPeerEntry *source,
                           DiameterPeerEntry *&dest, const char* appType ,const char* msgType);

		void SessionBaseRoutingInitial(DiameterMsg *msg, DiameterPeerEntry *source,
		           DiameterPeerEntry *&dest, const char* appType, const char* msgType);
		void SessionBaseRoutingUpdate(DiameterMsg *msg, DiameterPeerEntry *source,
		           DiameterPeerEntry *&dest, const char* appType, const char* msgType);
		void SessionBaseRoutingRar(DiameterMsg *msg, DiameterPeerEntry *source,
		           DiameterPeerEntry *&dest, const char* appType, const char* msgType);
		void SessionBaseRoutingMidSession(DiameterMsg *msg, DiameterPeerEntry *source,
		           DiameterPeerEntry *&dest, const char* appType, const char* msgType);
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

