static const char *id = " @(#) $Id: aaa_peer_table.cc,v 1.1.4.1.2.1.2.8 2024/05/15 13:11:22 mram Exp $";
//----------------------------------------------------------------------
// NAME
// aaa_peer_table.cc
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
#include "aaa_peer_table.h"

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerEntry::Start() //throw (AAA_Error)
{
	if(PeerData().m_Client)
	{
		Notify(DIAMETER_PEER_EV_START);

		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| sending conection request to Peer:%s\n", PeerData().m_Identity.c_str() ));
		m_PeerInitiator.Connect(PeerData().m_Identity,
				PeerData().m_Port,
				PeerData().m_UseSctp,
				PeerData().m_HostEntry.m_Identity,
				PeerData().m_HostPort,
				PeerData().rto);
	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerEntry::Stop(DIAMETER_DISCONNECT_CAUSE cause, bool lSuspend)
{
	PeerData().m_DisconnectCause = cause;
	PeerData().m_Suspend = lSuspend;
	Notify(DIAMETER_PEER_EV_STOP);
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Disconnecting with Peer:%s\n", PeerData().m_Identity.c_str() ));
	m_PeerInitiator.Stop();
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerEntry::StopPeerInitiator(DIAMETER_DISCONNECT_CAUSE cause)
{
	PeerData().m_DisconnectCause = cause;
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Disconnecting with Peer ON DWR timeout:%s\n", PeerData().m_Identity.c_str() ));
	m_PeerInitiator.Stop();
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerEntry::IncommingConnectionRequest(std::unique_ptr<Diameter_IO_Base> io,
		std::unique_ptr<DiameterMsg> cer)
{
   DiameterRxMsgCollector *h = reinterpret_cast<DiameterRxMsgCollector*>(io->Handler());

   h->RegisterHandler(*this);

   MsgIdRxMessage(*cer);

   Notify(DIAMETER_PEER_EV_R_CONN_CER, std::move(cer), std::move(io));
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerEntry::ConnectionRequestAccepted(std::unique_ptr<Diameter_IO_Base> io)
{
   DiameterRxMsgCollector *h = reinterpret_cast<DiameterRxMsgCollector*>(io->Handler());
   h->RegisterHandler(*this);
   Notify(DIAMETER_PEER_EV_I_RCV_CONN_ACK, std::move(io));
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerEntry::ConnectionRequestFailed()
{
   Notify(DIAMETER_PEER_EV_I_RCV_CONN_NACK);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerEntry::HandleMessage(std::unique_ptr<DiameterMsg> msg)
{
   ////////////////////////////////////////////
   // inspect msg and send proper notification
   ////////////////////////////////////////////


   DiameterMsgQuery query(*msg);

   if (state == DIAMETER_PEER_ST_WAIT_I_CEA) 
	{
       if (! query.IsCapabilities() || query.IsRequest()) 
		 {
           Notify(DIAMETER_PEER_EV_I_RCV_NON_CEA);
           return;
       }

   }

   static diameter_unsigned32_t cmdCode[] = { 
                              DIAMETER_MSGCODE_CAPABILITIES_EXCHG,
                              DIAMETER_MSGCODE_WATCHDOG,
                              DIAMETER_MSGCODE_DISCONNECT_PEER 
                            };
   static AAA_Event requestIEv[] = { 
                              DIAMETER_PEER_EV_I_RCV_CER,
                              DIAMETER_PEER_EV_I_RCV_DWR,
                              DIAMETER_PEER_EV_I_RCV_DPR 
                            };
   static AAA_Event requestREv[] = { 
                              DIAMETER_PEER_EV_R_RCV_CER,
                              DIAMETER_PEER_EV_R_RCV_DWR,
                              DIAMETER_PEER_EV_R_RCV_DPR 
                            };
   static AAA_Event answerIEv[]  = { 
                              DIAMETER_PEER_EV_I_RCV_CEA,
                              DIAMETER_PEER_EV_I_RCV_DWA,
                              DIAMETER_PEER_EV_I_RCV_DPA 
                            };
   static AAA_Event answerREv[]  = { 
                              DIAMETER_PEER_EV_R_RCV_CEA,
                              DIAMETER_PEER_EV_R_RCV_DWA,
                              DIAMETER_PEER_EV_R_RCV_DPA 
                            };

   for (unsigned int i=0;
        i<sizeof(cmdCode)/sizeof(diameter_unsigned32_t);
        i++) 
	{
       if (cmdCode[i] == query.GetCommandCode()) 
		 {
           if (! MsgIdRxMessage(*msg) && ! query.IsRequest()) {
				  AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Invalid HH or EE in answer message\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode, msg->hdr.mCmdFlg.rBit));
				  return;
			  }
			  switch (state) {
				  case DIAMETER_PEER_ST_I_OPEN:
					  Notify(query.IsRequest() ?
							  requestIEv[i] : answerIEv[i],
							  std::move(msg));
					  break;
				  case DIAMETER_PEER_ST_R_OPEN:
					  Notify(query.IsRequest() ?
							  requestREv[i] : answerREv[i],
							  std::move(msg));
					  break;
				  case DIAMETER_PEER_ST_CLOSING:
					  if (PeerData().m_IOInitiator.get()) {
						  Notify(query.IsRequest() ?
								  requestIEv[i] : answerIEv[i], std::move(msg));
                   }
                   else {
                       Notify(query.IsRequest() ?
                              requestREv[i] : answerREv[i],
                       std::move(msg));
                   }
                   break;
               case DIAMETER_PEER_ST_WAIT_RETURNS:
               case DIAMETER_PEER_ST_WAIT_I_CEA:
                   if (query.IsCapabilities() && (! query.IsRequest())) 
						 {
                       Notify(DIAMETER_PEER_EV_I_RCV_CEA, std::move(msg));
                       break;
                   }
                   // fall through
					default:
						 AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d in unlikely state %d, discarding\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode, msg->hdr.mCmdFlg.rBit, state));
						break;
			  }
			  return;
		 }
	}

	switch (state) 
	{
		case DIAMETER_PEER_ST_I_OPEN:
		{
			Notify(DIAMETER_PEER_EV_I_RCV_MESSAGE, std::move(msg));
		}
		break;
		case DIAMETER_PEER_ST_R_OPEN:
		{
			Notify(DIAMETER_PEER_EV_R_RCV_MESSAGE, std::move(msg));
		}
		break;
		default:
			AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Received session non base protocol message\
						in an un-opened state, discarding\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode, msg->hdr.mCmdFlg.rBit, state));
			break;
	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerEntry::Error(COLLECTOR_ERROR error,
		std::string &io_name)
{
	switch (error) 
	{
		case CORRUPTED_BYTE_STREAM:
		case TRANSPORT_ERROR:
			if (io_name == std::string(AAA_IO_ACCEPTOR_NAME)) 
			  {
               Notify(DIAMETER_PEER_EV_R_PEER_DISC);
           }
           else if (io_name == std::string(AAA_IO_CONNECTOR_NAME)) 
			  {
               Notify(DIAMETER_PEER_EV_I_PEER_DISC);
           }
           else 
			  {
				  Cleanup();
			  }
           break;
       case PARSING_ERROR:
           // not fatal so disregard
           break;
       default:
           Cleanup();
           break;
   }
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterPeerEntry::SendErrorAnswer(std::unique_ptr<DiameterMsg> &msg)
{
   return DiameterPeerStateMachine::Send(msg);
}
