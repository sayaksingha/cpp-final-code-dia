static const char *id = " @(#) $Id: diameter_cc_proxy_session.cc,v 1.1.2.1.2.14 2024/03/20 10:42:58 mrafi Exp $";
//----------------------------------------------------------------------
// NAME
// diameter_cc_proxy_session.cc
//
// COPYRIGHT
// Tayana Software Solutions Pvt Ltd -- Copyright(C) 2007
// All rights reserved. No part of this computer program
// may be used or reproduced in any form by any
// means without prior written permission of
// Tayana Software Solutions Pvt Ltd
//
// DESCRIPTION
//
// Originated :                                     Date:
//----------------------------------------------------------------------
#include "diameter_parser.h"
#include "diameter_cc_proxy_session.h"
#include "diameter_cc_proxy_fsm.h"
#include "diameter_cc_parser.h"
#include "diameter_cc_application.h"
#include "aaa_redis_pool.h"

// TBC--Abhishek--improve below code.
DiameterCCProxySession::DiameterCCProxySession(AAA_Task &task, int lModuleId) : DiameterCCProxyStateMachine(*this, *(task.reactor()), lModuleId),
   DiameterRxProxyStateMachine(*this, *(task.reactor()), lModuleId),   
   DiameterSyProxyStateMachine(*this, *(task.reactor()), lModuleId),   
   DiameterS6aProxyStateMachine(*this, *(task.reactor()), lModuleId),   
   DiameterSlhProxyStateMachine(*this , *(task.reactor()), lModuleId),
   DiameterSdProxyStateMachine(*this , *(task.reactor()), lModuleId),
   DiameterShProxyStateMachine(*this , *(task.reactor()), lModuleId),
   DiameterCxProxyStateMachine(*this , *(task.reactor()), lModuleId)
{
	DiameterCCProxyStateMachine::Start();
	DiameterRxProxyStateMachine::Start();
	DiameterSyProxyStateMachine::Start();
	DiameterS6aProxyStateMachine::Start();
	DiameterSlhProxyStateMachine::Start();
	DiameterSdProxyStateMachine::Start();	
        DiameterShProxyStateMachine::Start();
        DiameterCxProxyStateMachine::Start();
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : GetResultCode()
// DESCRIPTION : Template Added by Abhishek Chhabra for getResultCode Helper.
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
template <typename Primary, typename Fallback = void>
UINT32 DiameterCCProxySession::GetResultCode(DiameterMsg &msg)
{
	try
	{
		return reinterpret_cast<Primary *>(msg.baseClass.get())->getResultCode()->getValue();
	}
	catch (...)
	{
		// if constexpr (!std::is_same<Fallback, void>)
		// 	return reinterpret_cast<Fallback *>(msg.baseClass.get())->getResultCode()->getValue();
		AAA_LOG((LM_ERROR, "%T |SESSION| Failed to get Result code." ));
		throw;
	}
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : RxRequest()
// DESCRIPTION : Updated by Abhishek Chhabra for RX interface.
// PARAMETER   : DiameterMsg, DiameterPeerEntry, DiameterPeerEntry
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::RxRequest(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
	std::string lLogText = LOG_DIAMETER_AVPS(msg);
	switch (msg.hdr.mCmdCode)
	{
	case AAA_CCR_MSG:
	{
		try
		{
			UINT32 lCCRequestType = 0;


			if (msg.hdr.mApplId == AAA_ApplicationId::AAA_Sd_APP_ID)
			{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SD_CCR_MSG);   
			SdSession().SdNotify(DiameterSdProxyEvent::EvCCRequestSd, msg, source, dest);
			AAA_LOG((LM_INFO, "%T |SD_SESSION| %s CCR Message Received\n", lLogText.c_str()));
			return;
			}

			switch (msg.hdr.mApplId)
			{
			case AAA_Gx_APP_ID:
				lCCRequestType = reinterpret_cast<GX::CCRequest *>(msg.baseClass.get())->getCCRequestType()->getValue();
				break;
			case AAA_Ro_APP_ID:
				lCCRequestType = reinterpret_cast<RO::CCRequest *>(msg.baseClass.get())->getCCRequestType()->getValue();
				break;
			default:
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
				AAA_LOG((LM_ERROR, "%T |CC_SESSION| %s Unsupported Application-Id:%d .\n",
						 lLogText.c_str(), msg.hdr.mApplId));
				return;
			}

			switch (lCCRequestType)
			{
			case CC_TYPE_INITIAL_REQUEST:
			{
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s {CC-Request-Type:INITIAL_REQUEST} CCR Message Received\n",
						 lLogText.c_str()));
				if (msg.hdr.mCmdFlg.tBit)
				{
					Session().Notify(DiameterCCProxyEvent::EvInitialRequestRtx, msg, source, dest);
				}
				else
				{
					Session().Notify(DiameterCCProxyEvent::EvInitialRequest, msg, source, dest);
				}
			}
			break;
			case CC_TYPE_UPDATE_REQUEST:
			{
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s {CC-Request-Type:UPDATE_REQUEST} CCR Message Received\n",
						 lLogText.c_str()));
				Session().Notify(DiameterCCProxyEvent::EvUpdateRequest, msg, source, dest);
			}
			break;
			case CC_TYPE_TERMINATION_REQUEST:
			{
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s {CC-Request-Type:TERMINATION_REQUEST} CCR Message Received\n",
						 lLogText.c_str()));
				Session().Notify(DiameterCCProxyEvent::EvTerminationRequest, msg, source, dest);
			}
			break;
			case CC_TYPE_EVENT_REQUEST:
			{
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s {CC-Request-Type:EVENT_REQUEST} CCR Message Received\n",
						 lLogText.c_str()));
				Session().Notify(DiameterCCProxyEvent::EvEventRequest, msg, source, dest);
			}
			break;
			default:
			{
				// Add -log TBC
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s {CC-Request-Type: UNKNOWN_REQUEST} Unknown Message Received\n",
						 lLogText.c_str()));
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			}
			}
		}
		catch (TssDiameterMsgException &st)
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			AAA_LOG((LM_ERROR, "%T |CC_SESSION| %s Caught Exception on processing CCR Message code:%d Msg:%s\n",
					 lLogText.c_str(), st.getErrorCode(), st.getErrMessage()));
			//
		}
		catch (...)
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			AAA_LOG((LM_ERROR, "%T |CC_SESSION| %s Caught Exception on processing CCR Message\n",
					 lLogText.c_str()));
		}
	}
	break;
	case AAA_RAR_MSG:
	{
		try
		{
			// Session().Notify(DiameterCCProxyEvent::EvRARequest, msg, source, dest);
         source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_RAR_MSG);
			switch (msg.hdr.mApplId)
			{
			case AAA_Gx_APP_ID:
			{
				Session().Notify(DiameterCCProxyEvent::EvRARequest, msg, source, dest);
				UINT32 lRARequestType = reinterpret_cast<GX::RARequest *>(msg.baseClass.get())->getReAuthRequestType()->getValue();
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s <Re-Auth-Request-Type:%d> RAR Message Received\n",
						 lLogText.c_str(), lRARequestType));
			}
			break;
			case AAA_Ro_APP_ID:
				Session().Notify(DiameterCCProxyEvent::EvRARequest, msg, source, dest);
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s RAR Message Received\n",
						 lLogText.c_str()));
				break;
			case AAA_Rx_APP_ID:
				RxSession().RxNotify(DiameterRxProxyEvent::EvRARequestRx, msg, source, dest);
				AAA_LOG((LM_INFO, "%T |RX_SESSION| %s RAR Message Received\n", lLogText.c_str()));
				break;

			case AAA_Sd_APP_ID:                              // add
				SdSession().SdNotify(DiameterSdProxyEvent::EvRARequestSd, msg, source, dest);
				AAA_LOG((LM_INFO, "%T |SD_SESSION| %s RAR Message Received\n", lLogText.c_str()));
            break;
			
			default:
			{
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
				AAA_LOG((LM_ERROR, "%T |CC_SESSION| %s Unsupported Application-Id:%d ..\n",
						 lLogText.c_str(), msg.hdr.mApplId));
			}
				return;
			}
		}
		catch (...)
		{
			AAA_LOG((LM_ERROR, "%T |CC_SESSION| %s caught Exception:%d ..\n",
					 lLogText.c_str(), msg.hdr.mApplId));
		}
	}
	break;
	case AAA_ASR_MSG:
	{
		switch (msg.hdr.mApplId)
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_ASR_MSG);
		case AAA_Gx_APP_ID:
		{
			Session().Notify(DiameterCCProxyEvent::EvASRequest, msg, source, dest);
			AAA_LOG((LM_INFO, "%T |CC_SESSION| %s ASR Message Received\n",
					 lLogText.c_str()));
		}
		break;
		case AAA_Rx_APP_ID:
		{  source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_ASR_MSG);
			RxSession().RxNotify(DiameterRxProxyEvent::EvASRequestRx, msg, source, dest);
			AAA_LOG((LM_INFO, "%T |CC_SESSION| %s ASR Message Received\n",
					 lLogText.c_str()));
		}
		break;
		case AAA_Ro_APP_ID:
		{
			Session().Notify(DiameterCCProxyEvent::EvASRequest, msg, source, dest);
			AAA_LOG((LM_INFO, "%T |CC_SESSION| %s ASR Message Received\n",
					 lLogText.c_str()));
		}
		break;
		default:
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			AAA_LOG((LM_ERROR, "%T |CC_SESSION| %s Unsupported Application-Id:%d ..\n",
					 lLogText.c_str(), msg.hdr.mApplId));
		}
		}
	}
	break;
	case AAA_CommandCode::AAA_ULR_MSG:
	{
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_S6A_ULR_MSG);
		S6aSession().S6aNotify(DiameterS6aProxyEvent::EvULRequest, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |S6A_SESSION| %s ULR Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_AAR_MSG:
	{
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_AAR_MSG);
		RxSession().RxNotify(DiameterRxProxyEvent::EvAARequest, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |CC_SESSION| %s AAR Message Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_STR_MSG:
	{
		switch (msg.hdr.mApplId)
		{
		case AAA_Rx_APP_ID:
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_STR_MSG);
			RxSession().RxNotify(DiameterRxProxyEvent::EvSTRequest, msg, source, dest);
			AAA_LOG((LM_INFO, "%T |RX_SESSION| %s STR Message Received\n", lLogText.c_str()));
		}
		break;
		case AAA_Sy_APP_ID:
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SY_STR_MSG);
			SySession().SyNotify(DiameterSyProxyEvent::EvSTRequestSy, msg, source, dest);
			AAA_LOG((LM_INFO, "%T |SY_SESSION| %s STR Message Received\n", lLogText.c_str()));
		}
		break;
		default:
		{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			AAA_LOG((LM_ERROR, "%T |RX_SESSION| %s Unsupported Application-Id:%d ..\n", lLogText.c_str(), msg.hdr.mApplId));
		}
			return;
		}
	}
	break;
	case AAA_CommandCode::AAA_SLR_MSG:
	{ 
		/*cout<<"entered AAA_CommandCode::AAA_SLR_MSG\n\n";*/
		bool lSLRequestType = reinterpret_cast<SY::SLRequest *>(msg.baseClass.get())->getSLRequestType()->getValue();
		if(lSLRequestType == 1)
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SY_SLR_INTER_MSG);
		else
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SY_SLR_MSG);
		SySession().SyNotify(DiameterSyProxyEvent::EvSLRequest, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |CC_SESSION| %s SLR Message Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_SNR_MSG:
	{
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SY_SNR_MSG);
		SySession().SyNotify(DiameterSyProxyEvent::EvSNRequest, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |CC_SESSION| %s SNR Message Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_AIR_MSG:  // 318 - AIR
	{
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_S6A_AIR_MSG);
		S6aSession().S6aNotify(DiameterS6aProxyEvent::EvAIRequest, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |S6A_SESSION| %s AIR Received in seasion\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_PUR_MSG:  // 321 - PUR
	{
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_S6A_PUR_MSG);
		S6aSession().S6aNotify(DiameterS6aProxyEvent::EvPURequest, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |S6A_SESSION| %s PUR Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_CLR_MSG:  // 317 - CLR
	{
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_S6A_CLR_MSG);
		S6aSession().S6aNotify(DiameterS6aProxyEvent::EvCLRequest, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |S6A_SESSION| %s CLR Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_ISDR_MSG:  // 319 - IDR
	{
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_S6A_IDR_MSG);
		S6aSession().S6aNotify(DiameterS6aProxyEvent::EvISDRequest, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |S6A_SESSION| %s IDR Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_DSR_MSG:  // 320 - DSR
	{
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_S6A_DSR_MSG);
		S6aSession().S6aNotify(DiameterS6aProxyEvent::EvDSRequest, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |S6A_SESSION| %s DSR Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_RSR_MSG:  // 322 - RSR
	{
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_S6A_RSR_MSG);
		S6aSession().S6aNotify(DiameterS6aProxyEvent::EvResetRequest, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |S6A_SESSION| %s RSR Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_NOR_MSG:  // 323 - NOR
	{
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_S6A_NOR_MSG);
		S6aSession().S6aNotify(DiameterS6aProxyEvent::EvNORequest, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |S6A_SESSION| %s NOR Received\n", lLogText.c_str()));
	}
	break;
	case AAA_CommandCode::AAA_RIR_MSG:  // RIR	
	{
			source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SLH_RIR_MSG);
			SlhSession().SlhNotify(DiameterSlhProxyEvent::EvRIRequest, msg, source, dest);
			AAA_LOG((LM_INFO, "%T |SLH_SESSION| %s RIR Received\n", lLogText.c_str()));
	}
	break;

	case AAA_CommandCode::AAA_TSR_MSG:  // TSR — PCRF -> TDF, opens the session
	{
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SD_TSR_MSG);   // ** see caveat below **
				SdSession().SdNotify(DiameterSdProxyEvent::EvTSRequestSd, msg, source, dest);
				AAA_LOG((LM_INFO, "%T |SD_SESSION| %s TSR Received\n", lLogText.c_str()));
	}
	break;

	  case AAA_CommandCode::AAA_SH_UDR_MSG:  // UDR — User-Data-Request
	  {
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SH_UDR_MSG);
		ShSession().ShNotify(DiameterShProxyEvent::EvUDRequestSh, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |SH_SESSION| %s UDR Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_PUR_MSG:  // PUR — Profile-Update-Request
	  {
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SH_PUR_MSG);
		ShSession().ShNotify(DiameterShProxyEvent::EvPURequestSh, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |SH_SESSION| %s PUR Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_SNR_MSG:  // SNR — Subscribe-Notifications-Request, opens the subscription
	  {
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SH_SNR_MSG);
		ShSession().ShNotify(DiameterShProxyEvent::EvSNRequestSh, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |SH_SESSION| %s SNR Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SH_PNR_MSG:  // PNR — Push-Notification-Request, server-initiated mid-subscription
	  {
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SH_PNR_MSG);
		ShSession().ShNotify(DiameterShProxyEvent::EvPNRequestSh, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |SH_SESSION| %s PNR Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_UAR_MSG:  // UAR — User-Authorization-Request
	  {
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CX_UAR_MSG);
		CxSession().CxNotify(DiameterCxProxyEvent::EvUARequestCx, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |CX_SESSION| %s UAR Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_SAR_MSG:  // SAR — Server-Assignment-Request
	  {
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CX_SAR_MSG);
		CxSession().CxNotify(DiameterCxProxyEvent::EvSARequestCx, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |CX_SESSION| %s SAR Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_LIR_MSG:  // LIR — Location-Info-Request
	  {
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CX_LIR_MSG);
		CxSession().CxNotify(DiameterCxProxyEvent::EvLIRequestCx, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |CX_SESSION| %s LIR Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_MAR_MSG:  // MAR — Multimedia-Auth-Request
	  {
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CX_MAR_MSG);
		CxSession().CxNotify(DiameterCxProxyEvent::EvMARequestCx, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |CX_SESSION| %s MAR Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_RTR_MSG:  // RTR — Registration-Termination-Request, server-initiated
	  {
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CX_RTR_MSG);
		CxSession().CxNotify(DiameterCxProxyEvent::EvRTRequestCx, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |CX_SESSION| %s RTR Received\n", lLogText.c_str()));
	  }
	  break;
	  case AAA_CommandCode::AAA_PPR_MSG:  // PPR — Push-Profile-Request, server-initiated
	  {
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CX_PPR_MSG);
		CxSession().CxNotify(DiameterCxProxyEvent::EvPPRequestCx, msg, source, dest);
		AAA_LOG((LM_INFO, "%T |CX_SESSION| %s PPR Received\n", lLogText.c_str()));
	  }
	  break;

	default:
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		break;
	}
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : RxAnswer()
// DESCRIPTION : Updated by Abhishek Chhabra for Rx & Sy interface.
// PARAMETER   : DiameterMsg, DiameterPeerEntry, DiameterPeerEntry
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::RxAnswer(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
	std::string lLogText = LOG_DIAMETER_AVPS(msg);
	try
	{
		const UINT32 appId = msg.hdr.mApplId;
		const UINT32 cmdCode = msg.hdr.mCmdCode;

		if (appId == AAA_ApplicationId::AAA_Rx_APP_ID)
		{
			ProcessRxAppAnswers(msg, source, dest, lLogText);
			return;
		}
		else if (appId == AAA_ApplicationId::AAA_Sy_APP_ID)
		{
			ProcessSyAppAnswers(msg, source, dest, lLogText);
			return;
		}
		else if (appId == AAA_ApplicationId::AAA_S6a_APP_ID)
		{
			ProcessS6aAppAnswers(msg, source, dest, lLogText);
			return;
		}
		else if (appId == AAA_ApplicationId::AAA_Slh_APP_ID)
		{
			ProcessSlhAppAnswers(msg, source, dest, lLogText);
			return;
		}
		
		else if (appId == AAA_ApplicationId::AAA_Sd_APP_ID)    
		{
			ProcessSdAppAnswers(msg, source, dest, lLogText);
			return;
		}
	        else if (appId == AAA_ApplicationId::AAA_Sh_APP_ID)
		{
		  ProcessShAppAnswers(msg, source, dest, lLogText);
		  return;
		}
                else if (appId == AAA_ApplicationId::AAA_Cx_APP_ID)
		{
		  ProcessCxAppAnswers(msg, source, dest, lLogText);
		  return;
		}
		switch (cmdCode)
		{
		case AAA_CCR_MSG:
		{
			UINT32 lResultCode {0};
			UINT32 lCCRequestType {0};
			string lResultCodeString {""};
			switch (msg.hdr.mApplId)
			{
			case AAA_Gx_APP_ID:
				lResultCode = GetResultCode<GX::CCAnswer>(msg);
				lCCRequestType  = reinterpret_cast<GX::CCAnswer *>(msg.baseClass.get())->getCCRequestType()->getValue();
				break;
			case AAA_Ro_APP_ID:
				lResultCode = GetResultCode<RO::CCAnswer>(msg);
				lCCRequestType = reinterpret_cast<RO::CCAnswer *>(msg.baseClass.get())->getCCRequestType()->getValue();
				break;
			default:
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
				AAA_LOG((LM_ERROR, "%T |CC_SESSION| %s Unsupported Application-Id:%d ...\n",
						 lLogText.c_str(), msg.hdr.mApplId));
				return;
			}
			switch (lCCRequestType)
			{
			case CC_TYPE_INITIAL_REQUEST:
			{
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s {CC-Request-Type:INITIAL_REQUEST} <Result-Code:%d> CCA Message Received\n",
						 lLogText.c_str(), lResultCode));

				lResultCodeString = "I-" + to_string(lResultCode);
				if (false == DIAMETER_CFG_RESULT_CODE_CHECK()->IsPresent(lResultCodeString))
				{
					Session().Notify(DiameterCCProxyEvent::EvInitialRequestSuccessful, msg, source, dest);
					// source->Peg()->GeneratePeg(DiameterPeg::E_CCA_INITIAL_SUCCESS_MSG);
				}
				else
				{
					Session().Notify(DiameterCCProxyEvent::EvInitialRequestUnsuccessful, msg, source, dest);
				}
				source->PeerData().m_Peg->GeneratePeg(lResultCode != 2001 ? DiameterPeg::E_CCA_INITIAL_FAIL_MSG : DiameterPeg::E_CCA_INITIAL_SUCCESS_MSG);
			}
			break;
			case CC_TYPE_UPDATE_REQUEST:
			{
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s {CC-Request-Type:UPDATE_REQUEST} <Result-Code:%d> CCA Message Received\n",
						 lLogText.c_str(), lResultCode));

				lResultCodeString = "U-" + to_string(lResultCode);

				if (false == DIAMETER_CFG_RESULT_CODE_CHECK()->IsPresent(lResultCodeString))
				{
					Session().Notify(DiameterCCProxyEvent::EvUpdateRequestSuccessful, msg, source, dest);
					// source->Peg()->GeneratePeg(DiameterPeg::E_CCA_UPDATE_SUCCESS_MSG);
				}
				else
				{
                 
					Session().Notify(DiameterCCProxyEvent::EvUpdateRequestUnsuccessful, msg, source, dest);
					// source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CCA_UPDATE_FAIL_MSG);
				}
				source->PeerData().m_Peg->GeneratePeg(lResultCode != 2001 ? DiameterPeg::E_CCA_UPDATE_FAIL_MSG : DiameterPeg::E_CCA_UPDATE_SUCCESS_MSG);		
			}
			break;
			case CC_TYPE_TERMINATION_REQUEST:
			{
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s {CC-Request-Type:TERMINATION_REQUEST} <Result-Code:%d> CCA Message Received\n",
						 lLogText.c_str(), lResultCode));
				HandleCCResult(lResultCode, DiameterCCProxyEvent::EvTerminationRequestSuccessful, DiameterCCProxyEvent::EvTerminationRequestUnsuccessful, source, msg, dest, lLogText, DiameterPeg::E_CCA_TERMINATE_SUCCESS_MSG, DiameterPeg::E_CCA_TERMINATE_FAIL_MSG);
			}
			case CC_TYPE_EVENT_REQUEST:
			{
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s {CC-Request-Type:EVENT_REQUEST} <Result-Code:%d> CCA Message Received\n",
						 lLogText.c_str(), lResultCode));
				HandleCCResult(lResultCode, DiameterCCProxyEvent::EvEventRequestSuccessful, DiameterCCProxyEvent::EvEventRequestUnsuccessful, source, msg, dest, lLogText, DiameterPeg::E_CC_EVENT_SUCCESS_MSG, DiameterPeg::E_CC_EVENT_FAIL_MSG);
			}
			break;
			default:
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
				break;
			}
		}
		break;
		case AAA_RAR_MSG:
		{			
			UINT32 lResultCode {0};
			switch (msg.hdr.mApplId)
			{
			case AAA_Gx_APP_ID:
				lResultCode = GetResultCode<GX::RAAnswer>(msg);
				break;
			case AAA_Ro_APP_ID:
				lResultCode = GetResultCode<RO::RAAnswer>(msg);
				break;
			}
           
         HandleCCResult(lResultCode, DiameterCCProxyEvent::EvRARequestSuccessful, DiameterCCProxyEvent::EvRARequestUnsuccessful, source, msg, dest, lLogText, DiameterPeg::E_RAA_SUCCESS_MSG, DiameterPeg::E_RAA_FAIL_MSG);
		
      }
		break;
		case AAA_ASR_MSG:
		{
			UINT32 lResultCode = 0;
			try
			{
				lResultCode = msg.baseClass->getResultCode()->getValue();
			}
			catch (...)
			{
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s ASR Exception:RESULT CODE:NULL\n",
						 lLogText.c_str()));
			}
			HandleCCResult(lResultCode, DiameterCCProxyEvent::EvASRequestSuccessful, DiameterCCProxyEvent::EvASRequestUnsuccessful, source, msg, dest, lLogText, DiameterPeg::E_ASA_SUCCESS_MSG, DiameterPeg::E_ASA_FAIL_MSG);
		}
		break;
		case AAA_CommandCode::AAA_ULR_MSG:
		{
			UINT32 lResultCode = 0;
			try
			{
				lResultCode = msg.baseClass->getResultCode()->getValue();
			}
			catch (...)
			{
				AAA_LOG((LM_INFO, "%T |CC_SESSION| %s ASR Exception:RESULT CODE:NULL\n",
						 lLogText.c_str()));
			}
			HandleCCResult(lResultCode, DiameterCCProxyEvent::EvEventRequestSuccessful, DiameterCCProxyEvent::EvEventRequestUnsuccessful, source, msg, dest, lLogText, DiameterPeg::E_ULA_SUCCESS_MSG, DiameterPeg::E_ULA_FAIL_MSG);
		}
		break;
		default:
			AAA_LOG((LM_INFO, "%T |CC_SESSION| %s Unhandled Command Code: %d\n", lLogText.c_str(), cmdCode));
			break;
		}
	}
	catch (...)
	{
		AAA_LOG((LM_INFO, "%T |CC_SESSION| %s Exception caught while processing Answer\n", lLogText.c_str()));
	}
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : ProcessRxAppAnswers()
// DESCRIPTION : Added by Abhishek Chhabra for Rx interface.
// PARAMETER   : DiameterMsg, DiameterPeerEntry, DiameterPeerEntry, const std::string
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::ProcessRxAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText)
{
	UINT32 resultCode = 0;
	try
	{
		switch (msg.hdr.mCmdCode)
		{
		case AAA_RAR_MSG:
			resultCode = GetResultCode<RX::RARequest, RX::RAAnswer>(msg);

			this->HandleRxResult(resultCode, DiameterRxProxyEvent::EvRARequestSuccessfulRx, DiameterRxProxyEvent::EvRARequestUnsuccessfulRx, source, msg, dest, logText, DiameterPeg::E_RAA_SUCCESS_MSG, DiameterPeg::E_RAA_FAIL_MSG);
			break;

		case AAA_ASR_MSG:
			resultCode = GetResultCode<RX::ASRequest>(msg);
			HandleRxResult(resultCode, DiameterRxProxyEvent::EvASRequestSuccessfulRx, DiameterRxProxyEvent::EvASRequestUnsuccessfulRx, source, msg, dest, logText, DiameterPeg::E_ASA_SUCCESS_MSG, DiameterPeg::E_ASA_FAIL_MSG);
			break;
		case AAA_AAR_MSG:
			resultCode = GetResultCode<RX::AARequest>(msg);
			HandleRxResult(resultCode, DiameterRxProxyEvent::EvAARequestSuccessful, DiameterRxProxyEvent::EvAARequestUnsuccessful, source, msg, dest, logText, DiameterPeg::E_AAA_SUCCESS_MSG, DiameterPeg::E_AAA_FAIL_MSG);
			break;
		case AAA_STR_MSG:
			resultCode = GetResultCode<RX::STRequest>(msg);
			HandleRxResult(resultCode, DiameterRxProxyEvent::EvSTRequestSuccessful, DiameterRxProxyEvent::EvSTRequestUnsuccessful, source, msg, dest, logText, DiameterPeg::E_STA_SUCCESS_MSG, DiameterPeg::E_STA_FAIL_MSG);
			break;

		default:
			AAA_LOG((LM_ERROR, "%T |RX_SESSION| %s Unhandled RX Command Code: %d\n", logText.c_str(), msg.hdr.mCmdCode));
			break;
		}
	}
	catch (const std::exception &e)
	{
		AAA_LOG((LM_ERROR, "%T |RX_SESSION| %s Error processing RxAppAnswers: %s\n", logText.c_str(), e.what()));
	}
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : ProcessRxAppAnswers()
// DESCRIPTION : Added by Abhishek Chhabra for Rx interface.
// PARAMETER   : DiameterMsg, DiameterPeerEntry, DiameterPeerEntry, const std::string
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::ProcessS6aAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText)
{
	UINT32 resultCode = 0;
	try
	{
		switch (msg.hdr.mCmdCode)
		{
			case AAA_ULR_MSG:
				resultCode = GetResultCode<S6A::UpdateLocationAnswer>(msg);
				this->HandleS6aResult(resultCode, DiameterS6aProxyEvent::EvULASuccessful, DiameterS6aProxyEvent::EvCommonUnsuccessfulAnswer, source, msg, dest, logText, DiameterPeg::E_ULA_SUCCESS_MSG, DiameterPeg::E_ULA_FAIL_MSG);
				break;
			case AAA_AIR_MSG:
				resultCode = GetResultCode<S6A::AuthenticationInformationRequest>(msg);
				HandleS6aResult(resultCode, DiameterS6aProxyEvent::EvAIASuccessful, DiameterS6aProxyEvent::EvCommonUnsuccessfulAnswer, source, msg, dest, logText, DiameterPeg::E_S6A_AIA_SUCCESS_MSG, DiameterPeg::E_S6A_AIA_FAIL_MSG);
				break;
			case AAA_PUR_MSG:
				resultCode = GetResultCode<S6A::PurgeUERequest>(msg);
				HandleS6aResult(resultCode, DiameterS6aProxyEvent::EvPUASuccessful, DiameterS6aProxyEvent::EvCommonUnsuccessfulAnswer, source, msg, dest, logText, DiameterPeg::E_S6A_PUA_SUCCESS_MSG, DiameterPeg::E_S6A_PUA_FAIL_MSG);
				break;
			case AAA_NOR_MSG:
				resultCode = GetResultCode<S6A::NotifyRequest>(msg);
				HandleS6aResult(resultCode, DiameterS6aProxyEvent::EvNOASuccessful, DiameterS6aProxyEvent::EvCommonUnsuccessfulAnswer, source, msg, dest, logText, DiameterPeg::E_S6A_NOA_SUCCESS_MSG, DiameterPeg::E_S6A_NOA_FAIL_MSG);
				break;
			case AAA_CLR_MSG:
				resultCode = GetResultCode<S6A::CancelLocationRequest>(msg);
				HandleS6aResult(resultCode, DiameterS6aProxyEvent::EvCLASuccessful, DiameterS6aProxyEvent::EvCommonUnsuccessfulAnswer, source, msg, dest, logText, DiameterPeg::E_S6A_CLA_SUCCESS_MSG, DiameterPeg::E_S6A_CLA_FAIL_MSG);
				break;
			case AAA_ISDR_MSG:
				resultCode = GetResultCode<S6A::InsertSubscriberDataRequest>(msg);
				HandleS6aResult(resultCode, DiameterS6aProxyEvent::EvISDASuccessful, DiameterS6aProxyEvent::EvCommonUnsuccessfulAnswer, source, msg, dest, logText, DiameterPeg::E_S6A_IDA_SUCCESS_MSG, DiameterPeg::E_S6A_IDA_FAIL_MSG);
				break;
			case AAA_DSR_MSG:
				resultCode = GetResultCode<S6A::DeleteSubscriberDataRequest>(msg);
				HandleS6aResult(resultCode, DiameterS6aProxyEvent::EvDSASuccessful, DiameterS6aProxyEvent::EvCommonUnsuccessfulAnswer, source, msg, dest, logText, DiameterPeg::E_S6A_DSA_SUCCESS_MSG, DiameterPeg::E_S6A_DSA_FAIL_MSG);
				break;
			case AAA_RSR_MSG:
				resultCode = GetResultCode<S6A::ResetRequest>(msg);
				HandleS6aResult(resultCode, DiameterS6aProxyEvent::EvResetSuccessful, DiameterS6aProxyEvent::EvCommonUnsuccessfulAnswer, source, msg, dest, logText, DiameterPeg::E_S6A_RSA_SUCCESS_MSG, DiameterPeg::E_S6A_RSA_FAIL_MSG);
				break;
			default:
				AAA_LOG((LM_ERROR, "%T |S6A_SESSION| %s Unhandled S6A Command Code: %d\n", logText.c_str(), msg.hdr.mCmdCode));
				break;
		}
	}
	catch (const std::exception &e)
	{
		AAA_LOG((LM_ERROR, "%T |S6A_SESSION| %s Error processing S6a App Answers: %s\n", logText.c_str(), e.what()));
	}
}



//-------------------------------------------------------------------------------------------------------
// METHOD      : ProcessRxAppAnswers()
// DESCRIPTION : Added by Abhishek Chhabra for Rx interface.
// PARAMETER   : DiameterMsg, DiameterPeerEntry, DiameterPeerEntry, const std::string
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------

void DiameterCCProxySession::ProcessSlhAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText)
{
        UINT32 resultCode = 0;
        try
        {
			switch (msg.hdr.mCmdCode)
			{
				case AAA_RIR_MSG:
					resultCode = GetResultCode<SLH::LCSRoutingInfoAnswer>(msg);
					HandleSlhResult(resultCode, DiameterSlhProxyEvent::EvRIAnswerSuccessful, DiameterSlhProxyEvent::EvRIAnswerUnsuccessful, source, msg, dest, logText, DiameterPeg::E_SLH_RIA_SUCCESS_MSG, DiameterPeg::E_SLH_RIA_FAIL_MSG);
					break;
				default:
					AAA_LOG((LM_ERROR, "%T |SLH_SESSION| %s Unhandled SLH Command Code: %d\n", logText.c_str(), msg.hdr.mCmdCode));
					break;
			}
		}
        catch (const std::exception &e)
        {
                AAA_LOG((LM_ERROR, "%T |SLH_SESSION| %s Error processing SLH App Answers: %s\n", logText.c_str(), e.what()));
        }
}


//-------------------------------------------------------------------------------------------------------
// METHOD      : HandleSdResult()
// DESCRIPTION : Handling Sd results
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------


void DiameterCCProxySession::ProcessSdAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText)
{
      UINT32 resultCode = 0;
      try
      {
              switch (msg.hdr.mCmdCode)
              {
                      case AAA_TSR_MSG:
                              resultCode = GetResultCode<SD::TDFSessionAnswer>(msg);
                              HandleSdResult(resultCode, DiameterSdProxyEvent::EvTSAnswerSuccessfulSd, DiameterSdProxyEvent::EvTSAnswerUnsuccessfulSd, source, msg, dest, logText, DiameterPeg::E_SD_TSA_SUCCESS_MSG, DiameterPeg::E_SD_TSA_FAIL_MSG);
			      break;
                      case AAA_CCR_MSG:
                              resultCode = GetResultCode<SD::CreditControlAnswer>(msg);
                              HandleSdResult(resultCode, DiameterSdProxyEvent::EvCCAnswerSuccessfulSd, DiameterSdProxyEvent::EvCCAnswerUnsuccessfulSd, source, msg, dest, logText, DiameterPeg::E_SD_CCA_SUCCESS_MSG, DiameterPeg::E_SD_CCA_FAIL_MSG);			      
			      break;
                      case AAA_RAR_MSG:
                              resultCode = GetResultCode<SD::ReAuthAnswer>(msg);
                              HandleSdResult(resultCode, DiameterSdProxyEvent::EvRARequestSuccessfulSd, DiameterSdProxyEvent::EvRARequestUnsuccessfulSd, source, msg, dest, logText, DiameterPeg::E_SD_RAA_SUCCESS_MSG, DiameterPeg::E_SD_RAA_FAIL_MSG);
			      break;
                      default:
                              AAA_LOG((LM_ERROR, "%T |SD_SESSION| %s Unhandled SD Command Code: %d\n", logText.c_str(), msg.hdr.mCmdCode));
                              break;
              }
      }
      catch (const std::exception &e)
      {
              AAA_LOG((LM_ERROR, "%T |SD_SESSION| %s Error processing SD App Answers: %s\n", logText.c_str(), e.what()));
      }
}
//-------------------------------------------------------------------------------------------------------
// METHOD      : ProcessShAppAnswers()
// DESCRIPTION : Handling Sh results
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::ProcessShAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText)
{
      UINT32 resultCode = 0;
      try
      {
              switch (msg.hdr.mCmdCode)
              {
                      case AAA_SH_UDR_MSG:
                              resultCode = GetResultCode<SH::UserDataAnswer>(msg);
                              HandleShResult(resultCode, DiameterShProxyEvent::EvUDAnswerSuccessfulSh, DiameterShProxyEvent::EvUDAnswerUnsuccessfulSh, source, msg, dest, logText, DiameterPeg::E_SH_UDA_SUCCESS_MSG, DiameterPeg::E_SH_UDA_FAIL_MSG);
                              break;
                      case AAA_SH_PUR_MSG:
                              resultCode = GetResultCode<SH::ProfileUpdateAnswer>(msg);
                              HandleShResult(resultCode, DiameterShProxyEvent::EvPUAnswerSuccessfulSh, DiameterShProxyEvent::EvPUAnswerUnsuccessfulSh, source, msg, dest, logText, DiameterPeg::E_SH_PUA_SUCCESS_MSG, DiameterPeg::E_SH_PUA_FAIL_MSG);
                              break;
                      case AAA_SH_SNR_MSG:
                              resultCode = GetResultCode<SH::SubscribeNotificationsAnswer>(msg);
                              HandleShResult(resultCode, DiameterShProxyEvent::EvSNAnswerSuccessfulSh, DiameterShProxyEvent::EvSNAnswerUnsuccessfulSh, source, msg, dest, logText, DiameterPeg::E_SH_SNA_SUCCESS_MSG, DiameterPeg::E_SH_SNA_FAIL_MSG);
                              break;
                      case AAA_SH_PNR_MSG:
                              resultCode = GetResultCode<SH::PushNotificationAnswer>(msg);
                              HandleShResult(resultCode, DiameterShProxyEvent::EvPNAnswerSuccessfulSh, DiameterShProxyEvent::EvPNAnswerUnsuccessfulSh, source, msg, dest, logText, DiameterPeg::E_SH_PNA_SUCCESS_MSG, DiameterPeg::E_SH_PNA_FAIL_MSG);
                              break;
                      default:
                              AAA_LOG((LM_ERROR, "%T |SH_SESSION| %s Unhandled SH Command Code: %d\n", logText.c_str(), msg.hdr.mCmdCode));
                              break;
              }
      }
      catch (const std::exception &e)
      {
              AAA_LOG((LM_ERROR, "%T |SH_SESSION| %s Error processing SH App Answers: %s\n", logText.c_str(), e.what()));
      }
}



//-------------------------------------------------------------------------------------------------------
// METHOD      : ProcessCxAppAnswers()
// DESCRIPTION : Handling Cx results
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::ProcessCxAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText)
{
      UINT32 resultCode = 0;
      try
      {
              switch (msg.hdr.mCmdCode)
              {
                      case AAA_UAR_MSG:
                              resultCode = GetResultCode<CX::UserAuthorizationAnswer>(msg);
                              HandleCxResult(resultCode, DiameterCxProxyEvent::EvUAAnswerSuccessfulCx, DiameterCxProxyEvent::EvUAAnswerUnsuccessfulCx, source, msg, dest, logText, DiameterPeg::E_CX_UAA_SUCCESS_MSG, DiameterPeg::E_CX_UAA_FAIL_MSG);
                              break;
                      case AAA_SAR_MSG:
                              resultCode = GetResultCode<CX::ServerAssignmentAnswer>(msg);
                              HandleCxResult(resultCode, DiameterCxProxyEvent::EvSAAnswerSuccessfulCx, DiameterCxProxyEvent::EvSAAnswerUnsuccessfulCx, source, msg, dest, logText, DiameterPeg::E_CX_SAA_SUCCESS_MSG, DiameterPeg::E_CX_SAA_FAIL_MSG);
                              break;
                      case AAA_LIR_MSG:
                              resultCode = GetResultCode<CX::LocationInfoAnswer>(msg);
                              HandleCxResult(resultCode, DiameterCxProxyEvent::EvLIAnswerSuccessfulCx, DiameterCxProxyEvent::EvLIAnswerUnsuccessfulCx, source, msg, dest, logText, DiameterPeg::E_CX_LIA_SUCCESS_MSG, DiameterPeg::E_CX_LIA_FAIL_MSG);
                              break;
                      case AAA_MAR_MSG:
                              resultCode = GetResultCode<CX::MultimediaAuthAnswer>(msg);
                              HandleCxResult(resultCode, DiameterCxProxyEvent::EvMAAnswerSuccessfulCx, DiameterCxProxyEvent::EvMAAnswerUnsuccessfulCx, source, msg, dest, logText, DiameterPeg::E_CX_MAA_SUCCESS_MSG, DiameterPeg::E_CX_MAA_FAIL_MSG);
                              break;
                      case AAA_RTR_MSG:
                              resultCode = GetResultCode<CX::RegistrationTerminationAnswer>(msg);
                              HandleCxResult(resultCode, DiameterCxProxyEvent::EvRTAnswerSuccessfulCx, DiameterCxProxyEvent::EvRTAnswerUnsuccessfulCx, source, msg, dest, logText, DiameterPeg::E_CX_RTA_SUCCESS_MSG, DiameterPeg::E_CX_RTA_FAIL_MSG);
                              break;
                      case AAA_PPR_MSG:
                              resultCode = GetResultCode<CX::PushProfileAnswer>(msg);
                              HandleCxResult(resultCode, DiameterCxProxyEvent::EvPPAnswerSuccessfulCx, DiameterCxProxyEvent::EvPPAnswerUnsuccessfulCx, source, msg, dest, logText, DiameterPeg::E_CX_PPA_SUCCESS_MSG, DiameterPeg::E_CX_PPA_FAIL_MSG);
                              break;
                      default:
                              AAA_LOG((LM_ERROR, "%T |CX_SESSION| %s Unhandled CX Command Code: %d\n", logText.c_str(), msg.hdr.mCmdCode));
                              break;
              }
      }
      catch (const std::exception &e)
      {
              AAA_LOG((LM_ERROR, "%T |CX_SESSION| %s Error processing CX App Answers: %s\n", logText.c_str(), e.what()));
      }
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : HandleShResult()
// DESCRIPTION : Handling Sh results
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------

void DiameterCCProxySession::HandleShResult(UINT32 resultCode, DiameterShProxyEvent successEvent, DiameterShProxyEvent failEvent,
                                        DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
                                        const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg)
{
        if (resultCode == AAA_SUCCESS)
        {
                AAA_LOG((LM_INFO, "%T |SH_SESSION| %s Success: Result-Code=%d\n", logText.c_str(), resultCode));
                source->PeerData().m_Peg->GeneratePeg(successPeg);
                ShSession().ShNotify(successEvent, msg, source, dest);
        }
        else
        {
                AAA_LOG((LM_INFO, "%T |SH_SESSION| %s Failure: Result-Code=%d\n", logText.c_str(), resultCode));
                source->PeerData().m_Peg->GeneratePeg(failPeg);
                ShSession().ShNotify(failEvent, msg, source, dest);
        }
}


//-------------------------------------------------------------------------------------------------------
// METHOD      : HandleCxResult()
// DESCRIPTION : Handling Cx results
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------

void DiameterCCProxySession::HandleCxResult(UINT32 resultCode, DiameterCxProxyEvent successEvent, DiameterCxProxyEvent failEvent,
                                        DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
                                        const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg)
{
        if (resultCode == AAA_SUCCESS)
        {
                AAA_LOG((LM_INFO, "%T |CX_SESSION| %s Success: Result-Code=%d\n", logText.c_str(), resultCode));
                source->PeerData().m_Peg->GeneratePeg(successPeg);
                CxSession().CxNotify(successEvent, msg, source, dest);
        }
        else
        {
                AAA_LOG((LM_INFO, "%T |CX_SESSION| %s Failure: Result-Code=%d\n", logText.c_str(), resultCode));
                source->PeerData().m_Peg->GeneratePeg(failPeg);
                CxSession().CxNotify(failEvent, msg, source, dest);
        }
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : ProcessSyAppAnswers()
// DESCRIPTION : Added by Abhishek Chhabra for Rx interface.
// PARAMETER   : DiameterMsg, DiameterPeerEntry, DiameterPeerEntry, const std::string
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::ProcessSyAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText)
{
	UINT32 resultCode = 0;
	try
	{
		switch (msg.hdr.mCmdCode)
		{
		case AAA_SLR_MSG:
			resultCode = GetResultCode<SY::SLAnswer>(msg);
			HandleSyResult(resultCode, DiameterSyProxyEvent::EvSLAnswerSuccessful, DiameterSyProxyEvent::EvSLAnswerUnsuccessful, source, msg, dest, logText, DiameterPeg::E_SY_SLA_SUCCESS_MSG, DiameterPeg::E_SY_SLA_FAIL_MSG);
			break;

		case AAA_SNR_MSG:
			resultCode = GetResultCode<SY::SNAnswer>(msg);
			HandleSyResult(resultCode, DiameterSyProxyEvent::EvSNAnswerSuccessful, DiameterSyProxyEvent::EvSNAnswerUnsuccessful, source, msg, dest, logText, DiameterPeg::E_SY_SNA_SUCCESS_MSG, DiameterPeg::E_SY_SNA_FAIL_MSG);
			break;

		case AAA_STR_MSG:
			resultCode = GetResultCode<SY::STAnswer>(msg);
			HandleSyResult(resultCode, DiameterSyProxyEvent::EvSTAnswerSuccessfulSy, DiameterSyProxyEvent::EvSTAnswerUnsuccessfulSy, source, msg, dest, logText, DiameterPeg::E_SY_STA_SUCCESS_MSG, DiameterPeg::E_SY_STA_FAIL_MSG);
			break;

		default:
			AAA_LOG((LM_ERROR, "%T |RX_SESSION| %s Unhandled RX Command Code: %d\n", logText.c_str(), msg.hdr.mCmdCode));
			break;
		}
	}
	catch (const std::exception &e)
	{
		AAA_LOG((LM_ERROR, "%T |RX_SESSION| %s Error processing RxAppAnswers: %s\n", logText.c_str(), e.what()));
	}
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : HandleS6aResult()
// DESCRIPTION : Added by Abhishek Chhabra for  Shared Result Handling
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::HandleS6aResult(UINT32 resultCode, DiameterS6aProxyEvent successEvent, DiameterS6aProxyEvent failEvent,
					DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
					const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg)
{
	if (resultCode == AAA_SUCCESS)
	{
		AAA_LOG((LM_INFO, "%T |S6A_SESSION| %s Success: Result-Code=%d\n", logText.c_str(), resultCode));
		source->PeerData().m_Peg->GeneratePeg(successPeg);
		S6aSession().S6aNotify(successEvent, msg, source, dest);
	}
	else
	{
		AAA_LOG((LM_INFO, "%T |S6A_SESSION| %s Failure: Result-Code=%d\n", logText.c_str(), resultCode));
		source->PeerData().m_Peg->GeneratePeg(failPeg);
		S6aSession().S6aNotify(failEvent, msg, source, dest);
	}
}



//-------------------------------------------------------------------------------------------------------
// METHOD      : HandleSlhResult()
// DESCRIPTION : Added by Abhishek Chhabra for  Shared Result Handling
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::HandleSlhResult(UINT32 resultCode, DiameterSlhProxyEvent successEvent, DiameterSlhProxyEvent failEvent,
                                        DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
                                        const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg)
{
        if (resultCode == AAA_SUCCESS)
        {
                AAA_LOG((LM_INFO, "%T |SLH_SESSION| %s Success: Result-Code=%d\n", logText.c_str(), resultCode));
                source->PeerData().m_Peg->GeneratePeg(successPeg);
                SlhSession().SlhNotify(successEvent, msg, source, dest);
        }
        else
        {
                AAA_LOG((LM_INFO, "%T |SLH_SESSION| %s Failure: Result-Code=%d\n", logText.c_str(), resultCode));
                source->PeerData().m_Peg->GeneratePeg(failPeg);
                SlhSession().SlhNotify(failEvent, msg, source, dest);
        }
}



//-------------------------------------------------------------------------------------------------------
// METHOD      : HandleSdResult()
// DESCRIPTION : Handling Sd results
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------

void DiameterCCProxySession::HandleSdResult(UINT32 resultCode, DiameterSdProxyEvent successEvent, DiameterSdProxyEvent failEvent,
                                        DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
                                        const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg)
{
        if (resultCode == AAA_SUCCESS)
        {
                AAA_LOG((LM_INFO, "%T |SD_SESSION| %s Success: Result-Code=%d\n", logText.c_str(), resultCode));
                source->PeerData().m_Peg->GeneratePeg(successPeg);
                SdSession().SdNotify(successEvent, msg, source, dest);
        }
        else
        {
                AAA_LOG((LM_INFO, "%T |SD_SESSION| %s Failure: Result-Code=%d\n", logText.c_str(), resultCode));
                source->PeerData().m_Peg->GeneratePeg(failPeg);
                SdSession().SdNotify(failEvent, msg, source, dest);
        }
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : HandleRxResult()
// DESCRIPTION : Added by Abhishek Chhabra for  Shared Result Handling
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::HandleRxResult(UINT32 resultCode, DiameterRxProxyEvent successEvent, DiameterRxProxyEvent failEvent,
					DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
					const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg)
{
	if (resultCode == AAA_SUCCESS)
	{
		AAA_LOG((LM_INFO, "%T |RX_SESSION| %s Success: Result-Code=%d\n", logText.c_str(), resultCode));
		source->PeerData().m_Peg->GeneratePeg(successPeg);
		RxSession().RxNotify(successEvent, msg, source, dest);
	}
	else
	{
		AAA_LOG((LM_INFO, "%T |RX_SESSION| %s Failure: Result-Code=%d\n", logText.c_str(), resultCode));
		source->PeerData().m_Peg->GeneratePeg(failPeg);
		RxSession().RxNotify(failEvent, msg, source, dest);
	}
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : HandleCCResult()
// DESCRIPTION : Added by Abhishek Chhabra for  Shared Result Handling
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::HandleCCResult(UINT32 resultCode, DiameterCCProxyEvent successEvent, DiameterCCProxyEvent failEvent,
					DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
					const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg)
{
	if (resultCode == AAA_SUCCESS)
	{
		AAA_LOG((LM_INFO, "%T |CC_SESSION| %s Success: Result-Code=%d\n", logText.c_str(), resultCode));
		source->PeerData().m_Peg->GeneratePeg(successPeg);
		Session().Notify(successEvent, msg, source, dest);
	}
	else
	{
		AAA_LOG((LM_INFO, "%T |CC_SESSION| %s Failure: Result-Code=%d\n", logText.c_str(), resultCode));
		source->PeerData().m_Peg->GeneratePeg(failPeg);
		Session().Notify(failEvent, msg, source, dest);
	}
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : HandleSyResult()
// DESCRIPTION : Added by Abhishek Chhabra for  Shared Result Handling
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::HandleSyResult(UINT32 resultCode, DiameterSyProxyEvent successEvent, DiameterSyProxyEvent failEvent,
					DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
					const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg)
{
	if (resultCode == AAA_SUCCESS)
	{
		AAA_LOG((LM_INFO, "%T |SY_SESSION| %s Success: Result-Code=%d\n", logText.c_str(), resultCode));
		source->PeerData().m_Peg->GeneratePeg(successPeg);
		SySession().SyNotify(successEvent, msg, source, dest);
	}
	else
	{
		AAA_LOG((LM_INFO, "%T |SY_SESSION| %s Failure: Result-Code=%d\n", logText.c_str(), resultCode));
      source->PeerData().m_Peg->GeneratePeg(failPeg);
		SySession().SyNotify(failEvent, msg, source, dest);
	}
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : RxError()
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DiameterCCProxySession::RxError(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
	UINT32 lCCRequestType = 0;

	std::string lLogText = LOG_DIAMETER_AVPS(msg);
	switch (msg.hdr.mApplId)
	{
	case AAA_Gx_APP_ID:
		lCCRequestType = reinterpret_cast<GX::CCRequest *>(msg.baseClass.get())->getCCRequestType()->getValue();
		break;
	case AAA_Ro_APP_ID:
		lCCRequestType = reinterpret_cast<RO::CCRequest *>(msg.baseClass.get())->getCCRequestType()->getValue();
		break;
	default:
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		AAA_LOG((LM_ERROR, "%T |CC_SESSION| %s Unsupported Application-Id:%d ....\n", lLogText.c_str(), msg.hdr.mApplId));
		return;
	}

	switch (msg.hdr.mCmdCode)
	{
	case AAA_CCR_MSG:
	{
		// Session().Notify(DiameterCCProxyEvent::EvInitialRequest, msg, source, dest);
		AAA_LOG((LM_ERROR, "%T |CC_SESSION| %s {CC-Request-Type:%d} Error in CCR Message\n",
				 lLogText.c_str(), lCCRequestType));
	}
	break;
	case AAA_RAR_MSG:
	{
		// Session().Notify(DiameterCCProxyEvent::EvRARequest, msg, source, dest);
		AAA_LOG((LM_ERROR, "%T %s Error in RAR Message\n",
				 lLogText.c_str()));
	}
	break;
	case AAA_ASR_MSG:
	{
		// Session().Notify(DiameterCCProxyEvent::EvASRequest, msg, source, dest);
		AAA_LOG((LM_ERROR, "%T %s Error in RAR Message\n",
				 lLogText.c_str()));
	}
	break;
	default:
		source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		break;
	}
}

void DiameterCCProxySession::Start() // throw (AAA_Error)
{
	DiameterCCProxyStateMachine::Start(); // for gx, ro
	//DiameterRxProxyStateMachine::Start(); // for rx
	DiameterSyProxyStateMachine::Start(); // for rx
	DiameterS6aProxyStateMachine::Start(); // for s6a
	DiameterSlhProxyStateMachine::Start(); // for s6a
}
#if 0
int DiameterCCProxySession::SyncSessionData(SyncDccaProxySessionData &syncData)
{
	/*if(SYNC_OP_DEL == syncData.op)
	  {
	  DiameterMsg msg;
	  msg.sessionId = syncData.sessionId;

	  Reset(&msg);

	  return (0);
	  }*/

	std::string sourceName = syncData.sourceName;
	std::string destName   = syncData.destName;

	DiameterPeerEntry* source = DIAMETER_PEER_TABLE()->Lookup(sourceName);
	DiameterPeerEntry* dest   = DIAMETER_PEER_TABLE()->Lookup(destName);

	//Session().Notify(syncData.event);
	SyncSourceDest(source, dest);

	return (0);
}
#endif
int DiameterCCProxySession::GetSyncSessionData(SyncDccaProxySessionData &data)
{
	if(m_SyncSessionHdlr)
		return m_SyncSessionHdlr->GetSyncData(data);


	Redis *lRedis = DIAMETER_SYNC()->Acquire();

	std::string key = to_string(data.appId) + "_" + string(data.sessionId);
	std::map<std::string, std::string> multipleKV;
	AAA_LOG((LM_ERROR, "%T |CC_PROXY_SESSION| Redis Key:%s  .\n", key.c_str()));
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

void DiameterCCProxySession::RegisterProxySyncSession(DiameterCCProxySessionSyncHdlr &handler)
{
	handler.RegisterGxProxySession((DiameterGxProxySession *)this);
	m_SyncSessionHdlr = &handler;
}

void DiameterCCProxySession::RemoveProxySyncSession()
{
	m_SyncSessionHdlr->RemoveGxProxySession();
	m_SyncSessionHdlr = NULL;
}

void DiameterCCProxySessionSyncHdlr::RegisterGxProxySession(DiameterGxProxySession *session)
{
	m_Session = session;
}

void DiameterCCProxySessionSyncHdlr::RemoveGxProxySession()
{
	m_Session = NULL;
}

int DiameterCCProxySessionSyncHdlr::RecvSyncData(SyncDccaProxySessionData &data)
{
	return m_Session->SyncSessionData(data);
}

DiameterCCProxySessionSyncHdlr *DiameterCCProxySession::m_SyncSessionHdlr = NULL;
DiameterGxProxySession *DiameterCCProxySessionSyncHdlr::m_Session = NULL;

