// static const char *id = " @(#) $Id: diameter_cc_application.cc,v 1.1.2.1.2.20 2024/06/14 12:36:45 mram Exp $";
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
// #include "aaa_session_db.h"
#include "aaa_session_storage.h"
#include "aaa_error_msg.h"
#include "diameter_cc_application.h"
#include "gx/include/CCRequest.h"
#include "ro/include/CCRequest.h"

using namespace GX;

DiameterGxProxySession::DiameterGxProxySession(AAA_Task &task, int lModuleId) : DiameterCCProxySession(task, lModuleId)
{
	m_Session = this;
	AAA_LOG((LM_INFO,"%T |CC_FSM| TBR PROXY APP CONSTRUCTOR\n"));
	// DIAMETER_PROXY_SESSION_ROOT()->Initialize(task);
}

//========================================================================================
// NAME: RequestMsg
// PARA: 
// RETU:
// DESC:
//========================================================================================
AAAReturnCode DiameterGxProxySession::RequestMsg(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{

	msg.internalRspFlag = false;
	AAA_JobData *data = NULL;
	std::string lLogText = LOG_DIAMETER_AVPS(msg);
	UINT32 lCC = msg.hdr.mCmdCode;
	UINT32 lAppId = msg.hdr.mApplId;

	switch (lCC)
	{
	case AAA_CommandCode::AAA_CCR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Credit Control Request Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_RAR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Re-Authentication Request Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_ASR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Abort Session Request Received\n", lLogText.c_str()));
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

	case AAA_CommandCode::AAA_AAR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s AA Request Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_STR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s ST Request Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_SLR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s SL Request Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_SNR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s SN Request Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_RIR_MSG:
	{
			AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s RI Request Received\n", lLogText.c_str()));
	}
	break;

	  case AAA_CommandCode::AAA_TSR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s TDF-Session Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_UDR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s User-Data Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_PUR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Profile-Update Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_SNR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Subscribe-Notifications Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_PNR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Push-Notification Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_UAR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s User-Authorization Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SAR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Server-Assignment Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_LIR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Location-Info Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_MAR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Multimedia-Auth Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_RTR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Registration-Termination Request Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_PPR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Push-Profile Request Received\n", lLogText.c_str()));
	  }
	  break;

	default:
	{
		AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s [Error]Unsupported Request Received\n", lLogText.c_str()));
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		DiameterErrorMsg::Generate(msg, AAA_COMMAND_UNSUPPORTED, source);
		return (AAA_ERR_UNKNOWN_CMD);
	}
	}

	string key = to_string(lAppId) + string(";") + msg.sessionId;
	bool ret = DIAMETER_NEW_SESSION_DB().Lookup(key, (void **)&data);

	if (ret )//&& (AAA_CommandCode::AAA_STR_MSG != lCC ))//&& lAppId != AAA_Sy_APP_ID))
	{
		try
		{
			DiameterGxProxySession *session = reinterpret_cast<DiameterGxProxySession *>(data);

			if (session)
			{
				AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Session DB lookup success!!, Key:%s\n", lLogText.c_str(), key.c_str()));
				session->RxRequest(msg, source, dest);
				return (AAA_ERR_SUCCESS);
			}
			else
			{
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
				AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Session DB lookup failed, relaying to application, Key:%s\n", lLogText.c_str(), key.c_str()));
			}
		}
		catch (...)
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Caught Exception on relaying to application\n", lLogText.c_str()));
		}
		return (AAA_ERR_FAILURE);
	}
	/*
			if(msg.hdr.mCmdCode == AAA_CommandCode::AAA_RAR_MSG || msg.hdr.mCmdCode == AAA_CommandCode::AAA_ASR_MSG)
			{
				AAA_LOG((LM_ERROR,"%T |CC_APP_BASE| %s Session lookup failed\n",lLogText.c_str()));
			 source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
				DiameterErrorMsg::Generate(msg, AAA_UNKNOWN_SESSION_ID, source);
			 return (AAA_ERR_FAILURE);
			}
	*/
	UINT32 lCCRequestType = 0;

	if (lCC == AAA_CommandCode::AAA_RAR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_RA_REQUEST;
	}
	else if (lCC == AAA_CommandCode::AAA_ASR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_AS_REQUEST;
	}
	else if (lCC == AAA_CommandCode::AAA_AAR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_INITIAL_REQUEST;
	}
	else if (lCC == AAA_CommandCode::AAA_STR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_TERMINATION_REQUEST;
	
	}
	else if (lCC == AAA_CommandCode::AAA_ULR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_EVENT_REQUEST;
	}
	else if (lCC == AAA_CommandCode::AAA_CLR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_EVENT_REQUEST;
	}
	else if (lCC == AAA_CommandCode::AAA_PUR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_EVENT_REQUEST;
	}
	else if (lCC == AAA_CommandCode::AAA_AIR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_EVENT_REQUEST;
	}
	else if (lCC == AAA_CommandCode::AAA_ISDR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_EVENT_REQUEST;
	}
	else if (lCC == AAA_CommandCode::AAA_DSR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_EVENT_REQUEST;
	}
	else if (lCC == AAA_CommandCode::AAA_RSR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_EVENT_REQUEST;
	}
	else if (lCC == AAA_CommandCode::AAA_NOR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_EVENT_REQUEST;
	}
	else if (lCC == AAA_CommandCode::AAA_RIR_MSG)
	{
		lCCRequestType = (UINT32)CC_TYPE_EVENT_REQUEST;
	}



	  else if (lCC == AAA_CommandCode::AAA_TSR_MSG)
	  {
	    lCCRequestType = (UINT32)CC_TYPE_INITIAL_REQUEST;
	  }
	  else if (lCC == AAA_CommandCode::AAA_SH_SNR_MSG) // Sh: opens the notification subscription
	  {
	    lCCRequestType = (UINT32)CC_TYPE_INITIAL_REQUEST;
	  }
	  else if (lCC == AAA_CommandCode::AAA_SH_PNR_MSG) // Sh: server-initiated, requires existing subscription
	  {
	    lCCRequestType = (UINT32)CC_TYPE_RA_REQUEST;
	  }
	  else if (lCC == AAA_CommandCode::AAA_SAR_MSG) // Cx: Server-Assignment-Request, registers server assignment
	  {
	    lCCRequestType = (UINT32)CC_TYPE_INITIAL_REQUEST;
	  }
	  else if (lCC == AAA_CommandCode::AAA_RTR_MSG) // Cx: Registration-Termination-Request, HSS-initiated
	  {
	    lCCRequestType = (UINT32)CC_TYPE_RA_REQUEST;
	  }
	  else if (lCC == AAA_CommandCode::AAA_PPR_MSG) // Cx: Push-Profile-Request, HSS-initiated
	  {
	    lCCRequestType = (UINT32)CC_TYPE_RA_REQUEST;
	  }
	  else if (lCC == AAA_CommandCode::AAA_SH_UDR_MSG || lCC == AAA_CommandCode::AAA_SH_PUR_MSG ||
		   lCC == AAA_CommandCode::AAA_UAR_MSG || lCC == AAA_CommandCode::AAA_LIR_MSG ||
		   lCC == AAA_CommandCode::AAA_MAR_MSG) // standalone queries: Sh UDR/PUR, Cx UAR/LIR/MAR
	  {
	    lCCRequestType = (UINT32)CC_TYPE_EVENT_REQUEST;
	  }


	else if (lCC == AAA_CommandCode::AAA_SLR_MSG || lCC == AAA_CommandCode::AAA_SNR_MSG)
	{
      if (lCC == AAA_CommandCode::AAA_SLR_MSG)
      {
         auto lReqType = reinterpret_cast<SY::SLRequest *>(msg.baseClass.get())->getSLRequestType()->getValue();
         lReqType == 0 ? lCCRequestType = CC_TYPE_INITIAL_REQUEST : 
            lCCRequestType = static_cast<UINT32>(CC_TYPE_SY_REQUEST);
      }
      else
         lCCRequestType = static_cast<UINT32>(CC_TYPE_SY_REQUEST);
	}
	else
	{
		switch (lAppId)
		{
		case AAA_Gx_APP_ID:
			lCCRequestType = reinterpret_cast<GX::CCRequest *>(msg.baseClass.get())->getCCRequestType()->getValue();
			break;
		case AAA_Ro_APP_ID:
			lCCRequestType = reinterpret_cast<RO::CCRequest *>(msg.baseClass.get())->getCCRequestType()->getValue();
			break;
		default:
			AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Unsupported Application-Id:%d (%d) (%d)\n",
					 lLogText.c_str(), lAppId, AAA_Gx_APP_ID, AAA_Ro_APP_ID));
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			return (AAA_ERR_FAILURE);
		}
	}

	if (CC_TYPE_INITIAL_REQUEST != lCCRequestType && CC_TYPE_EVENT_REQUEST != lCCRequestType )//&& CC_TYPE_SY_REQUEST != lCCRequestType && lCCRequestType != lCCRequestType  )
	{
		AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Session not found in session rDB, fetching from Redis...\n", lLogText.c_str()));
		SyncDccaProxySessionData syncData;
		memset(&syncData, 0, sizeof(SyncDccaProxySessionData));

		strcpy(syncData.sessionId, msg.sessionId.c_str());
		syncData.appId = lAppId;

		if (DIAMETER_CFG_TRANSPORT()->use_sentinel == 1 && GetSyncSessionData(syncData))
		{
			AAA_LOG((LM_ERROR, "%T |CC_APP_BASE|  %s syncData Source: %s , Dest :%s\n",
					 lLogText.c_str(), syncData.sourceName, syncData.destName));

			if (m_Session)
			{
				DiameterGxProxySession *newSession = m_Session->CreateInstance();

				if (newSession)
				{
					newSession->sessionId = msg.sessionId;
					newSession->appId = lAppId;

					newSession->sessionIdRx = msg.sessionId;
					newSession->appIdRx = lAppId;
					
					newSession->sessionIdSy = msg.sessionId;
					newSession->appIdSy = lAppId;
               		newSession->DiameterCCProxyStateMachine::UpdateStateOnSessSync(DCCA_DRA_ST_OPEN);
					try
					{

						if (true != DIAMETER_NEW_SESSION_DB().Add(key, newSession))
						{
							AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Sync Failed to add to session db\n", lLogText.c_str()));
							delete newSession;
							return (AAA_ERR_FAILURE);
						}

						newSession->SyncSessionData(syncData);
						newSession->RxRequest(msg, source, dest);

						AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Session DB lookup success\n", lLogText.c_str()));
						return (AAA_ERR_SUCCESS);
					}
					catch (...)
					{
						DIAMETER_NEW_SESSION_DB().Remove(key);
						delete newSession;
						AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Caught Exception on adding new session\n", lLogText.c_str()));
					}
				}
			}
		}

		if (lCC != AAA_CommandCode::AAA_RAR_MSG)
		{
			if (DCCA_CONFIG_HDLR()->mRelaywithoutInitial != true || (lCC != AAA_CommandCode::AAA_CCR_MSG))
			{
				AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s {CC-Request-Type:%d} Session lookup failed\n", lLogText.c_str(), lCCRequestType));
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
				DiameterErrorMsg::Generate(msg, AAA_UNKNOWN_SESSION_ID, source);
				return (AAA_ERR_FAILURE);
			}
			else
			{
				AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s {CC-Request-Type:%d} Session is not present in redis... Creating new\n", lLogText.c_str(), lCCRequestType));
			}
		}
	}

	if (m_Session)
	{
		DiameterGxProxySession *newSession = m_Session->CreateInstance();

		if (newSession)
		{
			try
			{
				bool ret = DIAMETER_NEW_SESSION_DB().Add(key, newSession);

				if (!ret)
				{
					AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Failed to add to session db\n", lLogText.c_str()));
					source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
					delete newSession;
					return (AAA_ERR_FAILURE);
				}

				AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s success to add session into DB\n", lLogText.c_str()));
				newSession->sessionId = msg.sessionId;
				newSession->appId = lAppId;

				newSession->sessionIdRx = msg.sessionId;
				newSession->appIdRx = lAppId;

				newSession->sessionIdSy = msg.sessionId;
				newSession->appIdSy = lAppId;
				
				newSession->sessionIdS6a = msg.sessionId;
				newSession->appIdS6a = lAppId;
			
			    newSession->sessionIdSlh = msg.sessionId;
				newSession->appIdSlh     = lAppId;
	
				newSession->RxRequest(msg, source, dest);

				if (msg.internalRspFlag)
				{
					AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Sending NACK\n", lLogText.c_str()));
					source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
					msg.internalRspFlag = false;
					return (AAA_ERR_FAILURE);
				}

				return (AAA_ERR_SUCCESS);
			}
			catch (DiameterBaseException &e)
			{
				DIAMETER_NEW_SESSION_DB().Remove(key);
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
				// if (e.Code() == DiameterBaseException::MISSING_SESSION_ID)
				//{
				delete newSession;
				//}
				AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Processing error in new session\n", lLogText.c_str()));
				return (AAA_ERR_FAILURE);
			}
			catch (...)
			{
				// Delete the session -- TBC
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
				AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Caught Exception on adding new session\n", lLogText.c_str()));
				DIAMETER_NEW_SESSION_DB().Remove(key);
				delete newSession;
			}
		}
		else
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Un-supported application id, discarding req msg\n", lLogText.c_str()));
		}
	}
	else
	{
		//cout<<"lCC is:"<<lCC<<endl;
		//if (lCC != AAA_CommandCode::AAA_RAR_MSG)
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Missing session id, discard req msg\n", lLogText.c_str()));
		}
		//else
		//	return (AAA_ERR_SUCCESS);
	}

	// source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR); //TBC-NK not required
	return (AAA_ERR_FAILURE);
}

//========================================================================================
// NAME: AnswerMsg
// PARA: 
// RETU:
// DESC:
//========================================================================================
AAAReturnCode DiameterGxProxySession::AnswerMsg(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
	AAA_JobData *data = NULL;
	std::string lLogText = LOG_DIAMETER_AVPS(msg);
	switch (msg.hdr.mCmdCode)
	{
	case AAA_CommandCode::AAA_CCR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Credit Control Answer Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_RAR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Re-Authentication Answer Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_ASR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Abort Session Anwser Received\n", lLogText.c_str()));
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


	case AAA_CommandCode::AAA_ULR_MSG:
	{
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Update Location Anwser Received\n", lLogText.c_str()));
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
			AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Router Info Anwser Received\n", lLogText.c_str()));
	}
	break;

	  case AAA_CommandCode::AAA_TSR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s TDF-Session Answer Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_UDR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s User-Data Answer Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_PUR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Profile-Update Answer Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_SNR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Subscribe-Notifications Answer Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_PNR_MSG:
	  {
	    AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Push-Notification Answer Received\n", lLogText.c_str()));
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
		AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s [Error]Unsupported Answer Received\n", lLogText.c_str()));
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
			DiameterGxProxySession *session = reinterpret_cast<DiameterGxProxySession *>(data);

			if (session)
			{
				session->RxAnswer(msg, source, dest);
				AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Relayed to application, key:%s\n", lLogText.c_str(),key.c_str()));
				return (AAA_ERR_SUCCESS);
			}
			else
			{
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
				AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Session DB lookup failed, relaying to application, Key:%s\n", lLogText.c_str(), key.c_str()));
				// return AAA_UNKNOWN_SESSION_ID;
			}
		}
		catch (...)
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Caught Exception on relaying to application\n", lLogText.c_str()));
		}
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Session not found in session DB, fetching from Redis, Key:%s.\n", lLogText.c_str(),key.c_str()));
		SyncDccaProxySessionData syncData;
		memset(&syncData, 0, sizeof(SyncDccaProxySessionData));

		strcpy(syncData.sessionId, msg.sessionId.c_str());
		syncData.appId = msg.hdr.mApplId;

		if (DIAMETER_CFG_TRANSPORT()->use_sentinel == 1 && GetSyncSessionData(syncData))
		{
			if (m_Session)
			{
				DiameterGxProxySession *newSession = m_Session->CreateInstance();
				if (newSession)
				{
					newSession->sessionId = msg.sessionId;
					newSession->appId = msg.hdr.mApplId;

					newSession->sessionIdRx = msg.sessionId;
					newSession->appIdRx = msg.hdr.mApplId;

					newSession->DiameterCCProxyStateMachine::UpdateStateOnSessSync(DCCA_DRA_ST_OPEN);
					try
					{
						newSession->SyncSessionData(syncData);

						if (true != DIAMETER_NEW_SESSION_DB().Add(key, newSession))
						{
							AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Sync Failed to add to session db\n", lLogText.c_str()));
							delete newSession;
							return (AAA_ERR_FAILURE);
						}

						newSession->RxAnswer(msg, source, dest);
						AAA_LOG((LM_INFO, "%T |CC_APP_BASE| Sync success to add to session db %s \n", lLogText.c_str()));
						return (AAA_ERR_SUCCESS);
					}
					catch (...)
					{
						AAA_LOG((LM_ERROR, "%T |CC_APP_BASE| %s Caught Exception on adding new session\n", lLogText.c_str()));
					}
				}
			}
		}

		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Unknown session id, discard answer msg\n", lLogText.c_str()));
	}
	//	}
	//	else {
	//		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
	//		AAA_LOG((LM_INFO,"%T |CC_APP_BASE| %s Missing session id, discard answer msg\n",LOG_DIAMETER_AVPS(msg).c_str()));
	//	}

	// source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR); TBC--NK.NOt required here
	return (AAA_ERR_FAILURE);
}

AAAReturnCode DiameterGxProxySession::ErrorMsg(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
	std::string lLogText = LOG_DIAMETER_AVPS(msg);
	AAA_LOG((LM_INFO, "%T |CC_APP_BASE| %s Error Message Received\n", lLogText.c_str()));
	return (AAA_ERR_FAILURE);
}

// bool DiameterGxProxySession::Reset(DiameterMsg *msg)
bool DiameterGxProxySession::Reset(const std::string &sessionId, const int &appId)
{
	char sid[180] = "";

	snprintf(sid, sizeof(sid), "%s", sessionId.c_str());

	string key = to_string(appId) + ";" + sessionId;

	if (true != DIAMETER_NEW_SESSION_DB().Remove(key))
	{
		// AAA_LOG((LM_INFO,"%T appId:%d sid:%s session DB Remove Failed\n", appId, sid));
		AAA_LOG((LM_ERROR, "%T appId:%d sid:%s session DB Remove Failed\n", appId, sid));
		return false;
	}
	else
	{
		// AAA_LOG((LM_INFO,"%T appId:%d sid:%s session DB Remove success\n", appId, sid));
		AAA_LOG((LM_ERROR, "%T appId:%d sid:%s going to schedule the session for clearance!!\n", appId, sid));
//		DIAMETER_PROXY_SESSION().ScheduleForDeletion(std::move(*this));
      	DIAMETER_PROXY_SESSION().ScheduleForDeletion( *this);
		// DIAMETER_PROXY_SESSION().GetQueue(std::move( *this));
		AAA_LOG((LM_ERROR, "%T appId:%d sid:%s session scheduled for clearance!!\n", appId, sid));
	}

	// AAA_JobData *data = NULL;
	// if (DIAMETER_NEW_SESSION_DB().Lookup(sessionId , (void**)&data))
	//{
	//	AAA_LOG((LM_ERROR,"%T sid:%s After Remove success\n", sessionId.c_str()));
	// }
	// else
	//	AAA_LOG((LM_ERROR,"%T sid:%s After Remove failed\n", sessionId.c_str()));

	// TBC------------NK Commented for testing purpose
	//  DIAMETER_PROXY_SESSION().ScheduleForDeletion( **this);
	// delete (this);

	return true;
}

int DiameterGxProxySession::SyncSessionData(SyncDccaProxySessionData &syncData)
{
	std::string sourceName = syncData.sourceName;
	std::string destName = syncData.destName;

	DiameterPeerEntry *source = DIAMETER_PEER_TABLE()->Lookup(sourceName);
	DiameterPeerEntry *dest = DIAMETER_PEER_TABLE()->Lookup(destName);

	// Session().Notify(syncData.event);
	SyncSourceDest(source, dest);

	return 0;
#if 0
	DiameterMsg msg;

	msg.sessionId = string(syncData.sessionId);
	msg.hdr.mApplId = syncData.appId; 

	std::string lLogText = "";//string("<APPID :") + to_string(msg.hdr.mApplId) + string("> <Session-Id:") + msg.sessionId + string(">");
	string key = to_string(msg.hdr.mApplId) + msg.sessionId;

	//std::string lLogText = LOG_DIAMETER_AVPS(msg);
	AAA_JobData *data = NULL;
	if (DIAMETER_NEW_SESSION_DB().Lookup(key, (void**)&data))
	{
		try
		{
			DiameterGxProxySession *session = (DiameterGxProxySession*)data;
			session->SyncSessionData(syncData);
		}
		catch (...)
		{
			AAA_LOG((LM_ERROR,"%T |CC_APP_BASE| %s Caught Exception on Sync Session Data\n", lLogText.c_str()));
		}

		return (0);
	}

	if(m_Session)
	{
		DiameterGxProxySession *newSession = m_Session->CreateInstance();
		if (newSession)
		{
			try
			{
				newSession->SyncSessionData(syncData);

				if(true != DIAMETER_NEW_SESSION_DB().Add(key , newSession))
				{
					AAA_LOG((LM_ERROR,"%T |CC_APP_BASE| %s Sync Failed to add to session db\n", lLogText.c_str()));
					delete newSession;
					return (-1);
				}
			}
			catch (...)
			{
				AAA_LOG((LM_ERROR,"%T |CC_APP_BASE| %s Caught Exception on adding new session\n", lLogText.c_str()));
			}

			return (0);
		}
		else {
			AAA_LOG((LM_INFO,"%T |CC_APP_BASE| %s Un-supported application id, discarding req msg\n", lLogText.c_str()));
		}
	}
	else
	{
		AAA_LOG((LM_INFO,"%T |CC_APP_BASE| %s Missing session id, discard req msg\n", lLogText.c_str()));
	}

	return (-1);
#endif
}

//========================================================================================
// NAME:GetMessagefromDB
// PARA:std::string&, DiameterPeerEntry*, DiameterPeerEntry*
// RETU:
// DESC:
//========================================================================================
bool DiameterGxProxySession::GetMessagefromDB(std::string &rSessionId, DiameterPeerEntry *&source,
											  DiameterPeerEntry *&dest, unique_ptr<DiameterMsg> &rMsg)
{
	AAA_JobData *data = NULL;
	string lkey = to_string(AAA_S6_APP_ID) + string(";") + rSessionId;
	bool ret = DIAMETER_NEW_SESSION_DB().Lookup(lkey, (void **)&data);

	if (ret)
	{
		DiameterGxProxySession *session = reinterpret_cast<DiameterGxProxySession *>(data);
		if (session != NULL)
		{
			// dest   = *session->m_Dest;
			dest = session->m_Dest_async;
			source = session->m_Src;

			// Fallback to S6a state machine pointers if CC ones are empty.
			// Async S6A flows call S6aNotify(), which populates m_Dest_asyncS6a 
			// rather than the CC base class pointers.
			if (dest == NULL)
			{
				dest = session->m_Dest_asyncS6a;
			}
			if (source == NULL)
			{
				source = session->m_SrcS6a;
			}

#if 0
         if(session->m_Msg != NULL)
			{
				//DiameterMsg *lMsgPtr = new DiameterMsg( *session->m_Msg);
            //rMsg = unique_ptr<DiameterMsg>(lMsgPtr);  //Need to implement this ..we may get segv in case of parallel processing of same session ID.
            rMsg = unique_ptr<DiameterMsg>(session->m_Msg);
				return true;
			}
#endif
			if (session->m_shr != NULL)
			{
				DiameterMsg *lPtr = new DiameterMsg(*(session->m_shr).get());

				rMsg = unique_ptr<DiameterMsg>(lPtr);
				return true;
			}
		}
	}
	return false;
}

//========================================================================================
// NAME:UpdateDB
// PARA:std::string&, DiameterPeerEntry*, DiameterPeerEntry*
// RETU:
// DESC:
//========================================================================================
// bool DiameterGxProxySession::UpdateDB(std::string& rSessionId, DiameterMsg *rMsg)
bool DiameterGxProxySession::UpdateDB(std::string &rSessionId, shared_ptr<DiameterMsg> rMsg)
{
	AAA_JobData *data = NULL;

	AAA_MutexScopeLock guard(m_EventCCFsmMtx);

	string lkey = to_string(AAA_S6_APP_ID) + string(";") + rSessionId;
	bool ret = DIAMETER_NEW_SESSION_DB().Lookup(lkey, (void **)&data);

	if (ret)
	{
		DiameterGxProxySession *session = reinterpret_cast<DiameterGxProxySession *>(data);
		if (session != NULL)
		{
			session->m_shr = std::move(rMsg);
			return true;
		}
	}
	return false;
}

//========================================================================================
// NAME:SendMsgAsync
// PARA:unique_ptr<DiameterMsg, DiameterPeerEntry* , DiameterPeerEntry*
// RETU:AAAReturnCode
// DESC
//========================================================================================
AAAReturnCode DiameterGxProxySession::SendMsgAsync(std::unique_ptr<DiameterMsg> msg, DiameterPeerEntry *source, DiameterPeerEntry *dest, string rSessionId)
{

	if (true == DIAMETER_CFG_ACCT_SESSION()->ulrSidRm)
	{
		if (0 != DIAMETER_MSG_ROUTER()->SendNackMsgAsync(std::move(msg), source, dest))
		{
			return AAA_ERR_FAILURE;
		}

		AAA_LOG((LM_INFO, "%T |CC_APP_BASE|  deleting the ulr for sid : %s\n", rSessionId));
		AAA_JobData *data = NULL;

		string lkey = to_string(AAA_S6_APP_ID) + string(";") + rSessionId;
		bool ret = DIAMETER_NEW_SESSION_DB().Lookup(lkey, (void **)&data);

		if (ret)
		{
			DiameterGxProxySession *session = reinterpret_cast<DiameterGxProxySession *>(data);
			if (session)
			{
				DiameterMsg *lmsg = msg.get();
				session->Notify(DiameterCCProxyEvent::EvInternalRspFromProxy, *lmsg, source, dest);
			}
		}
	}
	else
	{
		if (0 != DIAMETER_MSG_ROUTER()->SendMsgAsync(std::move(msg), source, dest))
		{
			return AAA_ERR_FAILURE;
		}
		AAA_LOG((LM_INFO, "%T |CC_APP_BASE|  not deleting the ulr for sid : %s\n", rSessionId));
	}

	return AAA_ERR_SUCCESS;
}

//========================================================================================
// NAME:SendNackMsgAsync
// PARA:unique_ptr<DiameterMsg, DiameterPeerEntry* , DiameterPeerEntry*
// RETU:AAAReturnCode
// DESC
//========================================================================================
AAAReturnCode DiameterGxProxySession::SendNackMsgAsync(std::unique_ptr<DiameterMsg> msg, DiameterPeerEntry *source, DiameterPeerEntry *dest, string rSessionId)
{
	if (0 != DIAMETER_MSG_ROUTER()->SendNackMsgAsync(std::move(msg), source, dest))
		return AAA_ERR_FAILURE;

	AAA_JobData *data = NULL;

	string lkey = to_string(AAA_S6_APP_ID) + string(";") + rSessionId;
	bool ret = DIAMETER_NEW_SESSION_DB().Lookup(lkey, (void **)&data);

	if (ret)
	{
		DiameterGxProxySession *session = reinterpret_cast<DiameterGxProxySession *>(data);
		if (session)
		{
			DiameterMsg *lmsg = msg.get();
			session->Notify(DiameterCCProxyEvent::EvInternalRspFromProxy, *lmsg, source, dest);
		}
	}

	return AAA_ERR_SUCCESS;
}
