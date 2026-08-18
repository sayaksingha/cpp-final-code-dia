// static const char *id = " @(#) $Id: DCCA_RouteProxyHdlr.cc,v 1.1.2.9 2021/01/28 00:05:03 anandhv Exp $";
//----------------------------------------------------------------------
//  NAME
//  diameter_cc_application.cc
//
//  COPYRIGHT
//  Tayana Software Solutions Pvt Ltd -- Copyright(C) 2007
//  All rights reserved. No part of this computer program
//  may be used or reproduced in any form by any
//  means without prior written permission of
//  Tayana Software Solutions Pvt Ltd
//
//  DESCRIPTION
//
//  Originated :                                     Date:
//----------------------------------------------------------------------
#include "DCCA_RouteProxyHdlr.h"
#include "Redis.h"
#include "aaa_redis_pool.h"
using namespace GX;

//-------------------------------------------------------------------------------------------------------
// METHOD      : DCCA_RouteProxyHdlr()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
DCCA_RouteProxyHdlr::DCCA_RouteProxyHdlr(list<diameter_unsigned32_t> appIdList) : AAA_ProxyHandler(appIdList)
{
	mAAA_ProxySessionSyncHdlr = nullptr;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : RegisterSyncHdlr
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DCCA_RouteProxyHdlr::RegisterSyncHdlr(AAA_ProxySessionSyncHdlr &lAAA_ProxySessionSyncHdlr)
{
	mAAA_ProxySessionSyncHdlr = &lAAA_ProxySessionSyncHdlr;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : ErrorMsg()
// DESCRIPTION :
// PARAMETER   : DiameterMsg, DiameterPeerEntry, DiameterPeerEntry
// RETURN      : AAAReturnCode
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
AAAReturnCode DCCA_RouteProxyHdlr::ErrorMsg(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
	std::string lLogText = LOG_DIAMETER_AVPS(msg);
	AAA_LOG((LM_DEBUG, "%T |CC_APP_ROUTER| %s Error Message Received\n", lLogText.c_str()));
	source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_ERROR_BIT);
	return (AAA_ERR_FAILURE);
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : AnswerMsg()
// DESCRIPTION :
// PARAMETER   : DiameterMsg, DiameterPeerEntry, DiameterPeerEntry
// RETURN      : AAAReturnCode
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
AAAReturnCode DCCA_RouteProxyHdlr::AnswerMsg(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
	AAA_JobData *data = NULL;
	std::string lLogText = LOG_DIAMETER_AVPS(msg);
	switch (msg.hdr.mCmdCode)
	{
	case AAA_CommandCode::AAA_CCR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Credit Control Answer Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_ASR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Abort Session Anwser Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_RAR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Re-Authentication Answer Received App-Id:%d\n", lLogText.c_str(), msg.hdr.mApplId));
	}
	break;
	
        case AAA_CommandCode::AAA_ULR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Update Location Anwser Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_AAR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s AA Anwser Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_STR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s ST Answer Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_SLR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s SL Answer Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_SNR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s SN Answer Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_CLR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Cancel Location Answer Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_PUR_MSG:
        {

                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Purge UE Answer Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_AIR_MSG:
        {

                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Authentication Info Answer Received\n", lLogText.c_str()));}
        break;
        case AAA_CommandCode::AAA_ISDR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Insert Subs Data Answer Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_DSR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Delete Subs Data Answer Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_RSR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Reset Answer Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_NOR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Notify Answer Received\n", lLogText.c_str()));
        }
		break;
		case AAA_CommandCode::AAA_RIR_MSG:
		{
				AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Router Info Answer Received\n", lLogText.c_str()));
		}
		break;
        
		case AAA_CommandCode::AAA_TSR_MSG:                 // add
		{
					AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s TDF-Session Answer Received\n", lLogText.c_str()));
		}
		break;

		case AAA_CommandCode::AAA_SH_UDR_MSG:
		{
			AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s User-Data Answer Received\n", lLogText.c_str()));
		}
		break;
		case AAA_CommandCode::AAA_SH_PUR_MSG:
		{
			AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Profile-Update Answer Received\n", lLogText.c_str()));
		}
		break;
		case AAA_CommandCode::AAA_SH_SNR_MSG:
		{
			AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Subscribe-Notifications Answer Received\n", lLogText.c_str()));
		}
		break;
		case AAA_CommandCode::AAA_SH_PNR_MSG:
		{
			AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Push-Notification Answer Received\n", lLogText.c_str()));
		}
		break;
		case AAA_CommandCode::AAA_UAR_MSG:
		{
			AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s User-Authorization Answer Received\n", lLogText.c_str()));
		}
		break;
		case AAA_CommandCode::AAA_SAR_MSG:
		{
			AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Server-Assignment Answer Received\n", lLogText.c_str()));
		}
		break;
		case AAA_CommandCode::AAA_LIR_MSG:
		{
			AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Location-Info Answer Received\n", lLogText.c_str()));
		}
		break;
		case AAA_CommandCode::AAA_MAR_MSG:
		{
			AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Multimedia-Auth Answer Received\n", lLogText.c_str()));
		}
		break;
		case AAA_CommandCode::AAA_RTR_MSG:
		{
			AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Registration-Termination Answer Received\n", lLogText.c_str()));
		}
		break;
		case AAA_CommandCode::AAA_PPR_MSG:
		{
			AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Push-Profile Answer Received\n", lLogText.c_str()));
		}
		break;

		default:
		{
			AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s [Error] Unsupported Answer Received Sending Nack\n", lLogText.c_str()));
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			return (AAA_ERR_UNKNOWN_CMD);
		}
		break;
	}

	string key = to_string(msg.hdr.mApplId) + string(";") + msg.sessionId;
	bool ret = DIAMETER_NEW_SESSION_DB().Lookup(key, (void **)&data);
	if (ret)
	{
		try
		{
			DCCA_ProxyHandler *session = reinterpret_cast<DCCA_ProxyHandler *>(data);

			int lModuleId = session->GetModuleId();
			shared_ptr<DCCA_ProxyHandler> RouteInterface;
			if (!DCCA_PROXY_ROUTE_INSTANCE()->GetApplicationObj(lModuleId, RouteInterface))
			{
				AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s Session DB lookup failed, relaying to application\n", lLogText.c_str()));
				return (AAA_ERR_FAILURE); // TBC-Added by Nandagopi
			}

			AAA_LOG((LM_DEBUG, "%T |CC_APP_ROUTER| %s Session DB lookup success \n", lLogText.c_str()));
			RouteInterface->AnswerMsg(msg, source, dest);
			return (AAA_ERR_SUCCESS);
		}
		catch (...)
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s Caught Exception on relaying to application\n", lLogText.c_str()));
			return (AAA_ERR_FAILURE);
		}
	}
	else
	{
		SyncDccaProxySessionData syncData;
		memset(&syncData, 0, sizeof(SyncDccaProxySessionData));

		strcpy(syncData.sessionId, msg.sessionId.c_str());
		syncData.appId = msg.hdr.mApplId;

		if (DIAMETER_CFG_GENERAL()->sync_session )//&& GetSyncSessionData(syncData))
		{
			shared_ptr<DCCA_ProxyHandler> RouteInterface;
         syncData.mModuleId = 1000;
			if (DCCA_PROXY_ROUTE_INSTANCE()->GetApplicationObj(syncData.mModuleId, RouteInterface))
			{
				AAA_LOG((LM_DEBUG, "%T |CC_APP_ROUTER| %s Got Application Object\n ", lLogText.c_str()));
				RouteInterface->AnswerMsg(msg, source, dest);
				return (AAA_ERR_SUCCESS);
			}
		}

		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		AAA_LOG((LM_DEBUG, "%T |CC_APP_ROUTER| %s Unknown session id, discard answer msg\n", lLogText.c_str()));
	}

	return (AAA_ERR_FAILURE);
}

int DCCA_RouteProxyHdlr::GetSyncSessionData(SyncDccaProxySessionData &data)
{
	std::string key = to_string(data.appId) + "_" + string(data.sessionId);
	std::map<std::string, std::string> multipleKV;

	Redis *lRedis = DIAMETER_SYNC()->Acquire();

	if (lRedis != NULL && lRedis->read(key, multipleKV))
	{
		if (!multipleKV.size())
		{
			DIAMETER_SYNC()->Release(lRedis);
			return 0;
		}

		auto it = multipleKV.begin();
		std::string appId = it->second;

		it++;
		if (it == multipleKV.end())
		{
			DIAMETER_SYNC()->Release(lRedis);
			return 0;
		}

		std::string dName = it->second;

		it++;
		if (it == multipleKV.end())
		{
			DIAMETER_SYNC()->Release(lRedis);
			return 0;
		}

		std::string event = it->second;

		it++;
		if (it == multipleKV.end())
		{
			DIAMETER_SYNC()->Release(lRedis);
			return 0;
		}

		std::string modId = it->second;

		it++;
		if (it == multipleKV.end())
		{
			DIAMETER_SYNC()->Release(lRedis);
			return 0;
		}

		std::string node = it->second;

		it++;
		if (it == multipleKV.end())
		{
			DIAMETER_SYNC()->Release(lRedis);
			return 0;
		}

		std::string op = it->second;

		it++;
		if (it == multipleKV.end())
		{
			DIAMETER_SYNC()->Release(lRedis);
			return 0;
		}

		std::string sid = it->second;

		it++;
		if (it == multipleKV.end())
		{
			DIAMETER_SYNC()->Release(lRedis);
			return 0;
		}

		std::string sName = it->second;

		data.op = (SyncOperation)atoi(op.c_str());
		data.event = (DiameterCCProxyEvent)atoi(event.c_str());
		data.mModuleId = atoi(modId.c_str());

		snprintf(data.sessionId, sizeof(data.sessionId), "%s", sid.c_str());
		snprintf(data.sourceName, sizeof(data.sourceName), "%s", sName.c_str());
		snprintf(data.destName, sizeof(data.destName), "%s", dName.c_str());

		data.appId = atoi(appId.c_str());
		DIAMETER_SYNC()->Release(lRedis);
		return 1;
	}
	if (lRedis != NULL)
		DIAMETER_SYNC()->Release(lRedis);
	return (0);
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : RequestMsg()
// DESCRIPTION :
// PARAMETER   : DiameterMsg, DiameterPeerEntry, DiameterPeerEntry
// RETURN      : AAAReturnCode
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
AAAReturnCode DCCA_RouteProxyHdlr::RequestMsg(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
	AAA_JobData *data = NULL;

	std::string lLogText = LOG_DIAMETER_AVPS(msg);
	switch (msg.hdr.mCmdCode)
	{
	case AAA_CommandCode::AAA_CCR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Credit Control Request Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_ASR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Abort Session Request Received\n", lLogText.c_str()));
	}
	break;


        case AAA_CommandCode::AAA_ULR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Update Location Request Received\n", lLogText.c_str()));
        }

        break;
        case AAA_CommandCode::AAA_CLR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Cancel Location Request Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_PUR_MSG:
        {

                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Purge UE Request Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_AIR_MSG:
        {

                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Authentication Info Request Received\n", lLogText.c_str()));}
        break;
        case AAA_CommandCode::AAA_ISDR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Insert Subs Data Request Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_DSR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Delete Subs Data Request Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_RSR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Reset Request Received\n", lLogText.c_str()));
        }
        break;
        case AAA_CommandCode::AAA_NOR_MSG:
        {
                AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Notify Request Received\n", lLogText.c_str()));
        }

        break;

	case AAA_CommandCode::AAA_RAR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Re-Authentication Request Received. App-Id:%d\n", lLogText.c_str(), msg.hdr.mApplId));
	}
	break;
	case AAA_CommandCode::AAA_AAR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s AA Request Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_SLR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s SL Request Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_SNR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s SN Request Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_STR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s ST Request Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_RIR_MSG:
	{
			AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Router Info Request  Received\n", lLogText.c_str()));
	}
	break;	

	case AAA_CommandCode::AAA_TSR_MSG:                 // add
	{
				AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s TDF-Session Request Received\n", lLogText.c_str()));
	}
	break;
	  case AAA_CommandCode::AAA_SH_UDR_MSG:
	  {
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s User-Data Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_PUR_MSG:
	  {
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Profile-Update Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_SNR_MSG:
	  {
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Subscribe-Notifications Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_PNR_MSG:
	  {
		AAA_LOG((LM_INFO, "%T |CC_APP_ROUTER| %s Push-Notification Request Received\n", lLogText.c_str()));
	  }
	  break;
    
	  case AAA_CommandCode::AAA_UAR_MSG:
	    {
		  AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s User-Authorization Answer Received\n", lLogText.c_str()));
	    }
	    break;
	    case AAA_CommandCode::AAA_SAR_MSG:
	    {
		  AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Server-Assignment Answer Received\n", lLogText.c_str()));
	    }
	    break;
	    case AAA_CommandCode::AAA_LIR_MSG:
	    {
		  AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Location-Info Answer Received\n", lLogText.c_str()));
	    }
	    break;
	    case AAA_CommandCode::AAA_MAR_MSG:
	    {
		  AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Multimedia-Auth Answer Received\n", lLogText.c_str()));
	    }
	    break;
	    case AAA_CommandCode::AAA_RTR_MSG:
	    {
		  AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Registration-Termination Answer Received\n", lLogText.c_str()));
	    }
	    break;
	    case AAA_CommandCode::AAA_PPR_MSG:
	    {
		  AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Push-Profile Answer Received\n", lLogText.c_str()));
	    }
	    break;


	default:
	{
		AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s [Error]Unsupported Request Received\n", lLogText.c_str()));
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		DiameterErrorMsg::Generate(msg, AAA_COMMAND_UNSUPPORTED, source);
		return (AAA_ERR_UNKNOWN_CMD);
	}
	}

	string key = to_string(msg.hdr.mApplId) + string(";") + msg.sessionId;
	bool ret = DIAMETER_NEW_SESSION_DB().Lookup(key, (void **)&data);
	if (ret)
	{
		try
		{
			DCCA_ProxyHandler *session = reinterpret_cast<DCCA_ProxyHandler *>(data);

			if (!session)
			{
				AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s Session object is invalid (bad cast)\n", lLogText.c_str()));
				return (AAA_ERR_FAILURE);
			}

			int lModuleId = session->GetModuleId();
			shared_ptr<DCCA_ProxyHandler> RouteInterface;
			if (!DCCA_PROXY_ROUTE_INSTANCE()->GetApplicationObj(lModuleId, RouteInterface))
			{
				AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s Session DB lookup failed, relaying to application\n", lLogText.c_str()));
				return (AAA_ERR_FAILURE);
			}

			AAA_LOG((LM_DEBUG, "%T |CC_APP_ROUTER| %s Session DB lookup success \n", lLogText.c_str()));
			RouteInterface->RequestMsg(msg, source, dest);
			return (AAA_ERR_SUCCESS);
		}
		catch (...)
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s Caught Exception on relaying to application\n", lLogText.c_str()));
			return (AAA_ERR_FAILURE); // TBC-Added by nandagopi
		}
	}

	UINT32 lCCRequestType = 0;
	switch (msg.hdr.mCmdCode)
	{
	case AAA_CommandCode::AAA_ASR_MSG:
		lCCRequestType = static_cast<UINT32>(CC_TYPE_AS_REQUEST);
		break;
	case AAA_CommandCode::AAA_AAR_MSG:
		lCCRequestType = static_cast<UINT32>(CC_TYPE_INITIAL_REQUEST);
		break;
	case AAA_CommandCode::AAA_RAR_MSG:
		lCCRequestType = static_cast<UINT32>(CC_TYPE_RA_REQUEST);
		break;
	  case AAA_CommandCode::AAA_TSR_MSG:                                   // add
	        lCCRequestType = static_cast<UINT32>(CC_TYPE_INITIAL_REQUEST);   // add
		break;      
	  case AAA_CommandCode::AAA_SH_SNR_MSG:  // Sh: opens the notification subscription
		lCCRequestType = static_cast<UINT32>(CC_TYPE_INITIAL_REQUEST);
		break;
	  case AAA_CommandCode::AAA_SH_PNR_MSG:  // Sh: server-initiated, requires existing subscription
	        lCCRequestType = static_cast<UINT32>(CC_TYPE_RA_REQUEST);
	        break;		                                                      // add

       	  case AAA_CommandCode::AAA_SAR_MSG:  // Cx: Server-Assignment-Request, registers server assignment
	    lCCRequestType = static_cast<UINT32>(CC_TYPE_INITIAL_REQUEST);
	    break;
	  case AAA_CommandCode::AAA_RTR_MSG:  // Cx: Registration-Termination-Request, HSS-initiated
	    lCCRequestType = static_cast<UINT32>(CC_TYPE_RA_REQUEST);
	    break;
	  case AAA_CommandCode::AAA_PPR_MSG:  // Cx: Push-Profile-Request, HSS-initiated
	    lCCRequestType = static_cast<UINT32>(CC_TYPE_RA_REQUEST);
	    break;

	  case AAA_CommandCode::AAA_CLR_MSG:
   		case AAA_CommandCode::AAA_PUR_MSG:
		case AAA_CommandCode::AAA_AIR_MSG:
        case AAA_CommandCode::AAA_ISDR_MSG:
        case AAA_CommandCode::AAA_DSR_MSG:
        case AAA_CommandCode::AAA_RSR_MSG:
        case AAA_CommandCode::AAA_NOR_MSG:
	case AAA_CommandCode::AAA_ULR_MSG:
	case AAA_CommandCode::AAA_RIR_MSG: //For SLH
        case AAA_CommandCode::AAA_SH_UDR_MSG: //For Sh
	case AAA_CommandCode::AAA_SH_PUR_MSG: //For Sh
	case AAA_CommandCode::AAA_UAR_MSG: //For Cx: User-Authorization-Request, standalone query
    case AAA_CommandCode::AAA_LIR_MSG: //For Cx: Location-Info-Request, standalone query
    case AAA_CommandCode::AAA_MAR_MSG: //For Cx: Multimedia-Auth-Request, standalone query
		lCCRequestType = static_cast<UINT32>(CC_TYPE_EVENT_REQUEST);
		break;

	case AAA_CommandCode::AAA_STR_MSG:
		lCCRequestType = static_cast<UINT32>(CC_TYPE_EVENT_REQUEST);
		break;
	case AAA_CommandCode::AAA_SLR_MSG:
	case AAA_CommandCode::AAA_SNR_MSG:
		lCCRequestType = static_cast<UINT32>(CC_TYPE_SY_REQUEST);
		break;
	default:
	{
		switch (msg.hdr.mApplId)
		{
		case AAA_Gx_APP_ID:
			lCCRequestType = reinterpret_cast<GX::CCRequest *>(msg.baseClass.get())->getCCRequestType()->getValue();
			break;
		case AAA_Ro_APP_ID:
			lCCRequestType = reinterpret_cast<RO::CCRequest *>(msg.baseClass.get())->getCCRequestType()->getValue();
			break;
		case AAA_Sd_APP_ID:                                                                              // add
              lCCRequestType = reinterpret_cast<SD::CreditControlRequest *>(msg.baseClass.get())->getCCRequestType()->getValue();  // add
              break;
		default:
			AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s Unsupported Application-Id:%d\n", lLogText.c_str(), msg.hdr.mApplId));
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			return (AAA_ERR_FAILURE);
		}
	}
	}

	if (CC_TYPE_INITIAL_REQUEST != lCCRequestType && CC_TYPE_EVENT_REQUEST != lCCRequestType && CC_TYPE_SY_REQUEST != lCCRequestType)
	{
		SyncDccaProxySessionData syncData;
		memset(&syncData, 0, sizeof(SyncDccaProxySessionData));
		snprintf(syncData.sessionId, sizeof(syncData.sessionId), "%s", msg.sessionId.c_str());
		syncData.appId = msg.hdr.mApplId;

		if (DIAMETER_CFG_GENERAL()->sync_session )// && GetSyncSessionData(syncData))
		{
			shared_ptr<DCCA_ProxyHandler> RouteInterface;
         	syncData.mModuleId = 1000;
			if (DCCA_PROXY_ROUTE_INSTANCE()->GetApplicationObj(syncData.mModuleId, RouteInterface))
			{
				AAA_LOG((LM_DEBUG, "%T |CC_APP_ROUTER| %s Got Application Object\n ", lLogText.c_str()));
				RouteInterface->RequestMsg(msg, source, dest);
				return (AAA_ERR_SUCCESS);
			}
			else
			{
				AAA_LOG((LM_DEBUG, "%T |CC_APP_ROUTER| %s Not get Application Object\n ", lLogText.c_str()));
			}
		}

		if (DCCA_CONFIG_HDLR()->mRelaywithoutInitial != true || (msg.hdr.mCmdCode != AAA_CommandCode::AAA_CCR_MSG))
		{
			AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s {CC-Request-Type:%d} Session lookup failed\n", lLogText.c_str(), lCCRequestType));
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			DiameterErrorMsg::Generate(msg, AAA_UNKNOWN_SESSION_ID, source);
			return (AAA_ERR_FAILURE);
		}
	}

	list<int> lAvpList = DCCA_PROXY_ROUTE_INSTANCE()->GetInputAvpDetails();
	if (lAvpList.empty())
	{
		AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s Input param list empty \n", lLogText.c_str()));
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		return (AAA_ERR_FAILURE);
	}

	DCCA_PrepareInputMapData<std::shared_ptr<DiameterBase>> lDCCA_PrepareInputMapData;
	multimap<int, boost::any> lDataMap;

	lDCCA_PrepareInputMapData.DecodeRequest(msg.baseClass, lAvpList, lDataMap, msg.sessionId);

	if (lDataMap.empty())
	{
		AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s Input param decode failed \n", lLogText.c_str()));
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		return (AAA_ERR_FAILURE);
	}

	int lApplnId = 0;
	shared_ptr<DCCA_ProxyHandler> lRouteInterface;

	if (DCCA_PROXY_ROUTE_INSTANCE()->ApplyRouting(lDataMap, lApplnId, lRouteInterface, msg.sessionId))
	{
		if (lRouteInterface->RequestMsg(msg, source, dest) != AAA_ERR_SUCCESS)
		{
			return AAA_ERR_FAILURE;
		}
		AAA_LOG((LM_DEBUG, "%T |CC_APP_ROUTER| %s Application Routing success \n", lLogText.c_str()));
		return (AAA_ERR_SUCCESS);
	}

	AAA_LOG((LM_ERROR, "%T |CC_APP_ROUTER| %s Application routing failed \n", lLogText.c_str()));
	source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);

	return (AAA_ERR_FAILURE);
}
