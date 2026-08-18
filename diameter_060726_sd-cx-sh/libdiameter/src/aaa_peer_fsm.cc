static const char *id = " @(#) $Id: aaa_peer_fsm.cc,v 1.1.4.1.2.1.2.21 2024/05/15 13:11:22 mram Exp $";
//----------------------------------------------------------------------
// NAME
// aaa_peer_fsm.cc
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
#include "aaa_data_defs.h"
#include "aaa_peer_fsm.h"
#include "aaa_route_msg_router.h"
#include "aaa_error_msg.h"

using namespace BASE;

#define DIAMETER_PEER_CONNECT_ATTEMPT_TOUT 30

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DiameterPeerStateTable DiameterPeerStateMachine::m_StateTable;

class AAA_ApplicationIdLookup
{
   public:
      static inline bool Find(diameter_unsigned32_t id,
                              DiameterApplicationIdLst &lst) {
          DiameterApplicationIdLst::iterator i = lst.begin();
          for (; i!= lst.end(); i++) 
			 {
              if ((id == DIAMETER_RELAY_APPLICATION_ID) ||
                  (*i == DIAMETER_RELAY_APPLICATION_ID) ||
                  (*i == id)) {
                  return true;
              }
          }
          return false;
      }
      static inline bool Find(diameter_unsigned32_t id,
                              DiameterApplicationIdLst *lst[],
                              int count) {
          for (int i=0; i<count; i++) 
			 {
              if (Find(id, *(lst[i]))) 
				  {
                  return true;
              }
          }
          return false;
      }
      static inline bool Find(diameter_unsigned32_t id,
                              DiameterVendorSpecificIdLst &lst) {
          DiameterVendorSpecificIdLst::iterator i = lst.begin();
          for (; i != lst.end(); i++) {
              if (((*i).authAppId == id) ||
                  ((*i).acctAppId == id) ||
                  ((*i).authAppId == DIAMETER_RELAY_APPLICATION_ID) ||
                  ((*i).acctAppId == DIAMETER_RELAY_APPLICATION_ID) ||
                  (id == DIAMETER_RELAY_APPLICATION_ID) ||
                  (id == DIAMETER_RELAY_APPLICATION_ID)) {
                  return true;
              }
          }
          return false;
      }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_ISendConnReq::operator()(DiameterPeerStateMachine &fsm)
{
	if (fsm.PeerData().m_Suspend == true)
	{
		fsm.CancelTimer(DIAMETER_PEER_EV_CONN_RETRY);
		fsm.CancelTimer(DIAMETER_PEER_EV_TIMEOUT);
	}
	else
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]R_ISendConnReq\n",fsm.Data().m_Identity.c_str()));
		LogConnection(fsm.Data().m_Identity,false,true);
		fsm.ScheduleTimer(DIAMETER_PEER_EV_TIMEOUT,
				DIAMETER_PEER_CONNECT_ATTEMPT_TOUT,
				0,
				DIAMETER_PEER_EV_TIMEOUT);
	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION : Added by Abhishek Chhabra to have the unique m_IO for each fsm
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_AcceptSendCEA::operator()(DiameterPeerStateMachine &fsm, std::unique_ptr<Diameter_IO_Base> m_IO, std::unique_ptr<DiameterMsg> m_Msg)
{
   fsm.PeerData().m_IOResponder   = std::move(m_IO);
   std::unique_ptr<DiameterMsg> cer = std::move(m_Msg);
   fsm.DisassembleCER(*cer);
   std::string message;
   diameter_unsigned32_t rcode;

   bool valid = fsm.ValidatePeer(rcode, message);

   fsm.SendCEA(rcode, message);

   std::string lLogText = LOG_DIAMETER_AVPS(*cer);
   if (! valid)
   {
      AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_AcceptSendCEA, %s in connection attempt, discarding\n",
               lLogText.c_str(),fsm.Data().m_Identity.c_str(),message.c_str()));
      fsm.Cleanup();
   }
   else
   {
      fsm.CancelTimer(DIAMETER_PEER_EV_TIMEOUT);
      if(fsm.m_Data.m_ToSendDWR == 1)
      {
         AAA_LOG((LM_DEBUG, "%T |PEER_FSM| [PEER]%s Scheduling Timer for WATCHDOG\n",lLogText.c_str()));
         fsm.ScheduleTimer(DIAMETER_PEER_EV_WATCHDOG,
               DIAMETER_CFG_TRANSPORT()->watchdog_timeout,
               0,
               DIAMETER_PEER_EV_WATCHDOG);
         fsm.StopReConnect();
      }

      fsm.Connected();
   }
   LogConnection(fsm.Data().m_Identity,true,false);
   fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CER_MSG);
}
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_AcceptSendCEA::operator()(DiameterPeerStateMachine &fsm)
{
	fsm.PeerData().m_IOResponder   = std::move(fsm.m_CurrentPeerEventParam->m_IO);
	std::unique_ptr<DiameterMsg> cer = std::move(fsm.m_CurrentPeerEventParam->m_Msg);

	fsm.DisassembleCER(*cer);

    std::string message;
    diameter_unsigned32_t rcode;

    bool valid = fsm.ValidatePeer(rcode, message);

    fsm.SendCEA(rcode, message);

	 std::string lLogText = LOG_DIAMETER_AVPS(*cer);	
    if (! valid) 
	 {
		 AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_AcceptSendCEA, %s in connection attempt, discarding\n", 
					 lLogText.c_str(),fsm.Data().m_Identity.c_str(),message.c_str()));
        fsm.Cleanup();
    }
    else 
	 {
		 fsm.CancelTimer(DIAMETER_PEER_EV_TIMEOUT);
		 if(fsm.m_Data.m_ToSendDWR == 1)
		 {
			 AAA_LOG((LM_DEBUG, "%T |PEER_FSM| [PEER]%s Scheduling Timer for WATCHDOG\n",lLogText.c_str()));
			 fsm.ScheduleTimer(DIAMETER_PEER_EV_WATCHDOG,
					 DIAMETER_CFG_TRANSPORT()->watchdog_timeout,
					 0,
					 DIAMETER_PEER_EV_WATCHDOG);
			 fsm.StopReConnect();
		 }

		 fsm.Connected();
	 }
	 LogConnection(fsm.Data().m_Identity,true,false);
	 fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CER_MSG);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerI_SendCER::operator()(DiameterPeerStateMachine &fsm)
{
	if (fsm.PeerData().m_Suspend == true)
	{
		fsm.CancelTimer(DIAMETER_PEER_EV_TIMEOUT);
	}
	else
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]I_SendCER, Connection attempt accepted\n",fsm.Data().m_Identity.c_str()));
		fsm.PeerData().m_IOInitiator = std::move(fsm.m_CurrentPeerEventParam->m_IO);
		LogConnection(fsm.Data().m_Identity,false,false);
		fsm.SendCER();
		fsm.ScheduleTimer(DIAMETER_PEER_EV_TIMEOUT,
				DIAMETER_PEER_CONNECT_ATTEMPT_TOUT,
				0,
				DIAMETER_PEER_EV_TIMEOUT);
	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeer_ConnNack::operator()(DiameterPeerStateMachine &fsm)
{
	AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]ConnNack, Sending Nack\n",fsm.Data().m_Identity.c_str()));
	fsm.Cleanup();
	fsm.DoReConnect(); 
	fsm.Error(AAA_UNABLE_TO_COMPLY);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeer_ConnNack::operator()(DiameterPeerStateMachine &fsm, std::unique_ptr<Diameter_IO_Base> m_IO, std::unique_ptr<DiameterMsg> m_Msg)
{
	AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]ConnNack Overload, Sending Nack\n",fsm.Data().m_Identity.c_str()));
	typedef enum {
		CLEANUP_IO_I = 0x00000001,
		CLEANUP_IO_R = 0x00000002,
		CLEANUP_FSM  = 0x00000004,
		CLEANUP_ALL  = 0xffffffff
	} CLEANUP_FLG;
	fsm.Cleanup(CLEANUP_ALL, false, std::move(m_IO));
	fsm.DoReConnect();
	fsm.Error(AAA_UNABLE_TO_COMPLY);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeer_Cleanup::operator()(DiameterPeerStateMachine &fsm)
{
	if(fsm.PeerData().m_Suspend == true )
	{
		fsm.Disconnected (fsm.PeerData().m_DisconnectCause);
		fsm.Cleanup(DiameterPeerStateMachine::CLEANUP_ALL, true);
		fsm.m_TxMsgCollector.Stop();
	}
	else
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| [PEER]%s [ACT]Cleanup\n",fsm.Data().m_Identity.c_str()));

		fsm.Cleanup();
		fsm.DoReConnect();
	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeer_ReConnect::operator()(DiameterPeerStateMachine &fsm)
{
	AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]ReConnect, Retrying peer connection\n",fsm.Data().m_Identity.c_str()));

	fsm.StopReConnect();
	reinterpret_cast<DiameterPeerEntry*>(&fsm)->Start();
	//sleep(10);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_Accept::operator()(DiameterPeerStateMachine &fsm)
{
	fsm.PeerData().m_IOResponder = std::move(fsm.m_CurrentPeerEventParam->m_IO);
	std::unique_ptr<DiameterMsg> cer = std::move(fsm.m_CurrentPeerEventParam->m_Msg);

	fsm.DisassembleCER(*cer);

	std::string message;
	diameter_unsigned32_t rcode;

	std::string lLogText = LOG_DIAMETER_AVPS(*cer);	
	if (! fsm.ValidatePeer(rcode, message)) {
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_Accept, %s during election, Discarding\n", 
					lLogText.c_str(), fsm.Data().m_Identity.c_str(), message.c_str()));
		fsm.Cleanup();
	}
	else {
		AAA_LOG((LM_INFO, "%T |PEER_FSM| %s,[PEER]%s [ACT]R_Accept, Peer capabilities accepted\n",
					lLogText.c_str(),fsm.Data().m_Identity.c_str()));
	}

	fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CER_MSG);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_Accept::operator()(DiameterPeerStateMachine &fsm, std::unique_ptr<Diameter_IO_Base> m_IO,std::unique_ptr<DiameterMsg> m_Msg)
{
   fsm.PeerData().m_IOResponder = std::move(m_IO);
   std::unique_ptr<DiameterMsg> cer = std::move(m_Msg);

   fsm.DisassembleCER(*cer);

   std::string message;
   diameter_unsigned32_t rcode;

   std::string lLogText = LOG_DIAMETER_AVPS(*cer);
   if (! fsm.ValidatePeer(rcode, message)) {
      AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_Accept, %s during election, Discarding\n",
               lLogText.c_str(), fsm.Data().m_Identity.c_str(), message.c_str()));
      fsm.Cleanup();
   }
   else {
      AAA_LOG((LM_INFO, "%T |PEER_FSM| %s,[PEER]%s [ACT]R_Accept, Peer capabilities accepted\n",
               lLogText.c_str(),fsm.Data().m_Identity.c_str()));
   }

   fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CER_MSG);
}
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeer_Error::operator()(DiameterPeerStateMachine &fsm)
{
	if(fsm.PeerData().m_Suspend == true )
	{
		fsm.Disconnected (fsm.PeerData().m_DisconnectCause);
		fsm.Cleanup(DiameterPeerStateMachine::CLEANUP_ALL, true);
		fsm.m_TxMsgCollector.Stop();
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| [PEER]%s [ACT]Error Peer, connection did not complete, closing\n",fsm.Data().m_Identity.c_str()));

		Diameter_IO_Base *io = NULL;
		if (fsm.m_Data.m_Client == 1)
		{
			io = fsm.m_Data.m_IOInitiator.get();
			AAA_LOG((LM_ERROR,"%T |PEER_FSM| Got IO Initiator PeerName:%s",fsm.Data().m_Identity.c_str()));
		
			if( io )
				io->Close();
		}
		else
		{
			io = fsm.m_Data.m_IOResponder.get();
			AAA_LOG((LM_ERROR,"%T |PEER_FSM| Got IO Responder PeerName:%s",fsm.Data().m_Identity.c_str()));

			if( io )
				io->Close();
		}

		fsm.Cleanup();
		fsm.ErrorCount() = 0;
		fsm.DoReConnect();
		//fsm.Error(AAA_LIMITED_SUCCESS);
	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeer_ProcessCEA::operator()(DiameterPeerStateMachine &fsm)
{
	diameter_unsigned32_t rCode = 0;
	std::string  rErrorMsg;

	std::unique_ptr<DiameterMsg> cea = std::move(fsm.m_CurrentPeerEventParam->m_Msg);

	std::string lLogText = LOG_DIAMETER_AVPS(*cea);	
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| %s, [PEER]%s [ACT]ProcessCEA \n",lLogText.c_str(),fsm.Data().m_Identity.c_str()));
	
   fsm.DisassembleCEA(*cea, rCode, rErrorMsg);

	DiameterMsgResultCode rcode(*cea);

	if ( rcode.InterpretedResultCode(rCode) ==
			DiameterMsgResultCode::RCODE_SUCCESS) 
	{
		fsm.StopReConnect();
		fsm.CancelTimer(DIAMETER_PEER_EV_TIMEOUT);

		if(fsm.m_Data.m_ToSendDWR == 1)
		{
			AAA_LOG((LM_DEBUG, "%T |PEER_FSM| [PEER]%s Scheduling Timer for WATCHDOG\n",lLogText.c_str()));
			fsm.ScheduleTimer(DIAMETER_PEER_EV_WATCHDOG,
					DIAMETER_CFG_TRANSPORT()->watchdog_timeout,
					0,
					DIAMETER_PEER_EV_WATCHDOG);
		}

		AAA_LOG((LM_DEBUG, "%T PEER_FSM Local capabilities accepted by peer\n"));
		AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]ProcessCEA, peer accepted\n", lLogText.c_str(),fsm.Data().m_Identity.c_str()));
      fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CEA_SUCCESS_MSG);
		fsm.Connected();
	}
	else 
	{
		AAA_LOG((LM_INFO, "%T PEER_FSM %s Peer returned an error on CEA\n", rErrorMsg.c_str()));
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]ProcessCEA, peer rejected\n", lLogText.c_str(),fsm.Data().m_Identity.c_str()));
		fsm.Cleanup();
	}

	//fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CEA_SUCCESS_MSG);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_AcceptElect::operator()(DiameterPeerStateMachine &fsm)
{
	fsm.PeerData().m_IOResponder = std::move(fsm.m_CurrentPeerEventParam->m_IO);
	std::unique_ptr<DiameterMsg> cer = std::move(fsm.m_CurrentPeerEventParam->m_Msg);

	fsm.DisassembleCER(*cer);

	std::string message;
	diameter_unsigned32_t rcode;
	std::string lLogText = LOG_DIAMETER_AVPS(*cer);	

	if (! fsm.ValidatePeer(rcode, message)) 
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_AcceptElect, Result [%d:%s] during election, discarding\n", lLogText.c_str(), rcode, fsm.Data().m_Identity.c_str(), message.c_str()));
		fsm.Cleanup(DiameterPeerStateMachine::CLEANUP_ALL & ~DiameterPeerStateMachine::CLEANUP_IO_I);
	}
	else 
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_AcceptElect, peer elected\n",lLogText.c_str(),fsm.Data().m_Identity.c_str()));
		fsm.Elect();
	}

	fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CER_MSG);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_AcceptElect::operator()(DiameterPeerStateMachine &fsm , std::unique_ptr<Diameter_IO_Base> m_IO,std::unique_ptr<DiameterMsg> m_Msg)
{
   fsm.PeerData().m_IOResponder = std::move(m_IO);
   std::unique_ptr<DiameterMsg> cer = std::move(m_Msg);
   
   fsm.DisassembleCER(*cer);
   
   std::string message;
   diameter_unsigned32_t rcode;
   std::string lLogText = LOG_DIAMETER_AVPS(*cer);
   
   if (! fsm.ValidatePeer(rcode, message))
   {  
      AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_AcceptElect, Result [%d:%s] during election, discarding\n", lLogText.c_str(), rcode, fsm.Data().m_Identity.c_str(), message.c_str()));
      fsm.Cleanup(DiameterPeerStateMachine::CLEANUP_ALL & ~DiameterPeerStateMachine::CLEANUP_IO_I);
   }
   else
   {  
      AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_AcceptElect, peer elected\n",lLogText.c_str(),fsm.Data().m_Identity.c_str()));
      fsm.Elect();
   }
   
   fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CER_MSG);
}
void DiameterPeerI_SendCERElect::operator()(DiameterPeerStateMachine &fsm)
{
	AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]I_SendCERElect\n",fsm.Data().m_Identity.c_str()));
	fsm.PeerData().m_IOInitiator = std::move(fsm.m_CurrentPeerEventParam->m_IO);    
	fsm.SendCER();
	fsm.Elect();
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_SendCEA::operator()(DiameterPeerStateMachine &fsm)
{
	fsm.PeerData().m_IOResponder = std::move(fsm.m_CurrentPeerEventParam->m_IO);    
	std::string message = "Capabilities negotiation completed successfully (win-election)";

	fsm.SendCEA(AAA_SUCCESS, message);

	std::string lLogText = LOG_DIAMETER_AVPS(*fsm.m_CurrentPeerEventParam->m_Msg);
	
	fsm.CancelTimer(DIAMETER_PEER_EV_TIMEOUT);
	if(fsm.m_Data.m_ToSendDWR == 1)
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| [PEER]%s Scheduling Timer for WATCHDOG\n",lLogText.c_str()));
		fsm.ScheduleTimer(DIAMETER_PEER_EV_WATCHDOG,
				DIAMETER_CFG_TRANSPORT()->watchdog_timeout,
				0,
				DIAMETER_PEER_EV_WATCHDOG);
	}

	AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_SendCEA, Capabilities negotiation completed successfully (win-election)\n", lLogText.c_str(), fsm.Data().m_Identity.c_str(), message.c_str()));

	fsm.Connected();
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_SendCEAOpen::operator()(DiameterPeerStateMachine &fsm)
{
	std::unique_ptr<DiameterMsg> cer = std::move(fsm.m_CurrentPeerEventParam->m_Msg);

	fsm.DisassembleCER(*cer);

	std::string message;
	diameter_unsigned32_t rcode;

	std::string lLogText = LOG_DIAMETER_AVPS(*cer);	
	if (! fsm.ValidatePeer(rcode, message)) 
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_SendCEAOpen, %s during cap re-negotiation\n", lLogText.c_str(), fsm.Data().m_Identity.c_str(), message.c_str()));
	}
	else 
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_SendCEAOpen, Peer capabilities accepted\n", lLogText.c_str(),fsm.Data().m_Identity.c_str()));
	}

	fsm.SendCEA(rcode, message);

	fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CER_MSG);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_DisconnectResp::operator()(DiameterPeerStateMachine &fsm)
{
	AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]R_DisconnectResp, Disconnecting responder\n",fsm.Data().m_Identity.c_str()));
	DIAMETER_IO_GC().ScheduleForDeletion(std::move(fsm.PeerData().m_IOResponder));
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_DisconnectIOpen::operator()(DiameterPeerStateMachine &fsm)
{
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| [PEER]%s [ACT]R_DisconnectIOpen\n",fsm.Data().m_Identity.c_str()));

	diameter_unsigned32_t rCode = 0;
	std::string  rErrorMsg ;

	DiameterMsg  *cea = fsm.m_CurrentPeerEventParam->m_Msg.get();

	fsm.DisassembleCEA(*cea ,rCode , rErrorMsg );

	DiameterMsgResultCode rcode(*cea);

	if (rcode.InterpretedResultCode( rCode ) ==
			DiameterMsgResultCode::RCODE_SUCCESS) 
	{
		fsm.CancelTimer(DIAMETER_PEER_EV_TIMEOUT);
		if(fsm.m_Data.m_ToSendDWR == 1)
		{
			AAA_LOG((LM_DEBUG, "%T |PEER_FSM| [PEER]%s Scheduling Timer for WATCHDOG\n",fsm.Data().m_Identity.c_str()));
			fsm.ScheduleTimer(DIAMETER_PEER_EV_WATCHDOG,
					DIAMETER_CFG_TRANSPORT()->watchdog_timeout,
					0,
					DIAMETER_PEER_EV_WATCHDOG);
		}

		DIAMETER_IO_GC().ScheduleForDeletion(std::move(fsm.PeerData().m_IOResponder));

		AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]R_DisconnectIOpen, Initiator capabilities accepted\n",fsm.Data().m_Identity.c_str()));
		fsm.Connected();
		fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CEA_SUCCESS_MSG);
	}
	else {
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| [PEER]%s [ACT]R_DisconnectIOpen, %s Peer returned an error on CEA\n", fsm.Data().m_Identity.c_str(), rErrorMsg.c_str()));
		fsm.Cleanup();
	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_Reject::operator()(DiameterPeerStateMachine &fsm)
{
	std::string lLogText = LOG_DIAMETER_AVPS(*fsm.m_CurrentPeerEventParam->m_Msg.get());	
	AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_Reject, Responder connection attempt rejected.\n", lLogText.c_str(),fsm.Data().m_Identity.c_str()));
   
   std::unique_ptr<Diameter_IO_Base> io = std::move(fsm.m_CurrentPeerEventParam->m_IO);
	std::unique_ptr<DiameterMsg> msg = std::move(fsm.m_CurrentPeerEventParam->m_Msg);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION : Method Overloaded By Abhishek
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_Reject::operator()(DiameterPeerStateMachine &fsm, std::unique_ptr<Diameter_IO_Base> io,std::unique_ptr<DiameterMsg> cer)
{
	
	std::unique_ptr<DiameterMsg> msg = std::move(cer);
	std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
	//AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_Reject, Overloaded Method Called.....\n", lLogText.c_str()));
	AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_Reject, Overloaded Method Called.....\n", lLogText.c_str(),fsm.Data().m_Identity.c_str()));

	AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_Reject, Responder connection attempt rejected\n", lLogText.c_str(),fsm.Data().m_Identity.c_str()));
   
   	// std::unique_ptr<Diameter_IO_Base> io = std::move(io);


	std::string message = "Connection is already established, so Rejecting this.";
	fsm.SendCEA(5003, message, io.get()); //DIAMETER_AUTH_REJECTED
   sleep(1);
   io->Close();
   AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]Reject, disconnected.\n", fsm.Data().m_Identity.c_str()));
}
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerI_DisconnectSendCEA::operator()(DiameterPeerStateMachine &fsm)
{
	std::string message = "Capabilities negotiation completed successfully (win-election)";
	DIAMETER_IO_GC().ScheduleForDeletion(std::move(fsm.PeerData().m_IOInitiator));

	fsm.SendCEA(AAA_SUCCESS, message);

	fsm.CancelTimer(DIAMETER_PEER_EV_TIMEOUT);
	if(fsm.m_Data.m_ToSendDWR == 1)
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| [PEER]%s Scheduling Timer for WATCHDOG\n",fsm.Data().m_Identity.c_str()));
		fsm.ScheduleTimer(DIAMETER_PEER_EV_WATCHDOG,
				DIAMETER_CFG_TRANSPORT()->watchdog_timeout,
				0,
				DIAMETER_PEER_EV_WATCHDOG);
	}

	AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]I_DisconnectSendCEA, Capabilities negotiation completed successfully (win-election)\n", fsm.Data().m_Identity.c_str()));

	fsm.Connected();
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_SendMessage::operator()(DiameterPeerStateMachine &fsm)
{
#if ASYNC_SEND
	boost::shared_ptr<DiameterMsg> msg = fsm.DequeueSendMsg();
	if (fsm.Send(*msg, fsm.PeerData().m_IOResponder.get()) < 0) 
	{
		std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
		AAA_LOG((LM_INFO, 
					"%T |PEER_FSM| %s {Destination-Realm:%s} {Destination-Host:%s}, [PEER]%s [ACT]R_SendMessage, Error sending message\n", 
					lLogText.c_str(), msg->destinationRealm.c_str() msg->destinationHost.c_str(),fsm.Data().m_Identity.c_str()));
	}
#endif
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeer_Process::operator()(DiameterPeerStateMachine &fsm)
{
	fsm.TrafficFlag() = true;
	std::unique_ptr<DiameterMsg> msg = std::move(fsm.m_CurrentPeerEventParam->m_Msg);
	std::string 					lLogText; //TBC-Anshul	
	DiameterMsgQuery 				query(*msg);

	if (query.IsRequest()) 
	{
		try
		{
			DiaHandleMsg::DecodeReqMsg(*msg);
			lLogText = LOG_DIAMETER_AVPS(*msg);
			AAA_LOG((LM_CRITICAL, "%T |PEER_FSM| %s, [PEER]%s [ACT]Process\n", lLogText.c_str(), fsm.Data().m_Identity.c_str()));
			
			if(msg->hdr.mCmdFlg.tBit)
				fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_RETX_BIT);
		}
		catch (DiameterBaseException &err)
		{
			AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]Process,expection on decoding request message error[%d]: %s\n", 
						lLogText.c_str(), fsm.Data().m_Identity.c_str(), err.Code(), err.Description().c_str()));


			//if(DiaHandleMsg::AppIDNotSupportedFlag == 1)
			//{
			//	DiaHandleMsg::AppIDNotSupportedFlag = 0;
			return; ///PLEASE CHECK THIS , IF APPLICATION ID IS NOT PRESENT DROPING THE MESSAGE
			//}


			DiameterErrorMsg::Generate(*msg, AAA_INVALID_MESSAGE_LENGTH, 
					reinterpret_cast<DiameterPeerEntry*>(&fsm));

			if(fsm.m_TxMsgCollector.Send(msg, fsm.m_Data.m_IOResponder.get(), true) == 0)
			{
				AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]Process, error[%d]: %s,send error message success\n", 
							lLogText.c_str(),fsm.Data().m_Identity.c_str(), err.Code(), err.Description().c_str()));
			}
			else
			{
				AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]Process, error[%d]: %s,send error message, failed\n", 
							lLogText.c_str(),fsm.Data().m_Identity.c_str(), err.Code(), err.Description().c_str()));
			}

			return;
		}
		catch(TssDiameterMsgException &err)
		{
			AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]Process,expection on decoding request message, error[%d]: %s\n", 
						lLogText.c_str(), fsm.Data().m_Identity.c_str(), err.getErrorCode(), err.getErrMessage()));
			return;
		}
		catch(...)
		{
			AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]Process, expection on decoding request message\n", 
						lLogText.c_str(), fsm.Data().m_Identity.c_str()));
			return;
		}

		DIAMETER_MSG_ROUTER()->RequestMsg(std::move(msg),
				reinterpret_cast<DiameterPeerEntry*>(&fsm));
	}
	else 
	{
		try{

			DiaHandleMsg::DecodeAnsMsg(*msg);
			lLogText = LOG_DIAMETER_AVPS(*msg);

			try
			{
				AAA_LOG((LM_DEBUG, "%T |PEER_FSM| %s <Result-Code:%d>, [PEER]%s [ACT]Process\n", 
							lLogText.c_str(), msg->baseClass->getResultCode()->getValue(),fsm.Data().m_Identity.c_str()));
			}
			catch(TssDiameterMsgException &err)
			{
				AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]Process,TssDia exception on decoding request message, error[%d]: %s\n", 
							lLogText.c_str(), fsm.Data().m_Identity.c_str(), err.getErrorCode(), err.getErrMessage()));
			}

		}
		catch (DiameterBaseException &err)
		{
			AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]Process,Base expection on decoding request message, error[%d]: %s\n", 
						lLogText.c_str(), fsm.Data().m_Identity.c_str(), err.Code(), err.Description().c_str()));
			return;
		}
		catch(TssDiameterMsgException &err)
		{
			AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]Process,Tss expection on decoding request message, error[%d]: %s\n", 
						lLogText.c_str(), fsm.Data().m_Identity.c_str(), err.getErrorCode(), err.getErrMessage()));
			return;
		}
		catch(...)
		{
			AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]Process, expection on decoding answer message\n", 
						lLogText.c_str(), fsm.Data().m_Identity.c_str()));
			return;
		}

		DIAMETER_MSG_ROUTER()->AnswerMsg(std::move(msg),
				reinterpret_cast<DiameterPeerEntry*>(&fsm));
	}
}

 //-------------------------------------------------------------------------------
 // METHOD      :
 // DESCRIPTION :
 // PARAMETER   :
 // RETURN      :
 // THROWS      :
 //-------------------------------------------------------------------------------
 void DiameterPeer_Process::operator()(DiameterPeerStateMachine &fsm, std::unique_ptr<DiameterMsg> dMsg, std::unique_ptr<Diameter_IO_Base> m_IO)
{
//	std::string                lLogText;

	fsm.TrafficFlag() = true;
	fsm.ErrorCount() = 0;

	std::unique_ptr<DiameterMsg> msg = std::move(dMsg);
	DiameterMsgQuery query(*msg);
	if (query.IsRequest())
	{  
		TEXT lLogText[TSS_MAX_LOG_TEXT_LEN] = "";
		try
		{    
			//PRINT_DIAMETER_AVPS_ALL(*msg,lLogText);

			DiaHandleMsg::DecodeReqMsg(*msg);
			//PRINT_DIAMETER_AVPS_ALL(*msg,lLogText);
//			GENERATE_STACK_PEG_BASE(E_REQUEST_RECEIVED,msg->hdr.mCmdCode,msg->hdr.mApplId);

          AAA_LOG((LM_INFO,"PeerName:%s Process",fsm.Data().m_Identity.c_str()));
//			log_msg(TDSPEER028 , 1 ,  lLogText <<" PeerName:" << fsm.Data().m_Identity.c_str()<<" Process ", "");
		}     
		catch (DiameterBaseException &err)
		{    
         AAA_LOG((LM_ERROR, "PeerName:%s  Process, expection on decoding request message, error:%s",fsm.Data().m_Identity.c_str(),err.Description().c_str()));
//			log_msg(TDSPEER028 , 1 ,  lLogText << " PeerName:" <<fsm.Data().m_Identity.c_str()
//					<< " Process, expection on decoding request message, error "
//					<< err.Code() << err.Description().c_str(), "");

			DiameterErrorMsg::Generate(*msg, AAA_INVALID_MESSAGE_LENGTH,
					reinterpret_cast<DiameterPeerEntry*>(&fsm));

//			GENERATE_STACK_PEG_BASE(E_DROP_MESS,msg->hdr.mCmdCode,msg->hdr.mApplId);

			if(fsm.m_TxMsgCollector.Send(msg, fsm.m_Data.m_IOResponder.get(), true) == 0)
			{
            AAA_LOG((LM_ERROR,"PeerName:%s Process, Error:%s",fsm.Data().m_Identity.c_str(),err.Description().c_str()));
//				log_msg(TDSPEER028 , 1 ,  lLogText <<" PeerName:" << fsm.Data().m_Identity.c_str()
//						<<" Process, error:"    << err.Code()
//						<< err.Description().c_str() <<" send error message success", "");
			}
			else
			{
            AAA_LOG((LM_ERROR,"PeerName:%s Process, Error:%s",fsm.Data().m_Identity.c_str(),err.Description().c_str()));
//				log_msg(TDSPEER028 , 1 ,  lLogText <<" PeerName:" << fsm.Data().m_Identity.c_str()
//						<<" Process, error:"    << err.Code()
//						<< err.Description().c_str() <<" send error message failed", "");
			}
			return;
		}
		catch(TssDiameterMsgException &err)
		{    
         AAA_LOG((LM_ERROR,"PeerName:%s Process, Error  on decoding request message",fsm.Data().m_Identity.c_str()));
			//log_msg(TDSPEER029 , 1 ,  lLogText <<" PeerName:" <<fsm.Data().m_Identity.c_str()
			//		<<" Process, expection on decoding request message,error "
		//			<<err.getErrorCode() << err.getErrMessage(), "");
		//	GENERATE_STACK_PEG_BASE(E_DROP_MESS,msg->hdr.mCmdCode,msg->hdr.mApplId);
			return;
		}
		catch(...)
		{
         AAA_LOG((LM_ERROR,"PeerName:%s Process, Error on decoding request message",fsm.Data().m_Identity.c_str()));
			//log_msg(TDSPEER029 , 1 ,  lLogText <<" PeerName:" <<fsm.Data().m_Identity.c_str()
			//		<<" Process, expection on decoding request message ", "");
		//	GENERATE_STACK_PEG_BASE(E_DROP_MESS,msg->hdr.mCmdCode,msg->hdr.mApplId);
			return;
		}

      AAA_LOG((LM_ERROR,"RequestMsg is calleds"));
		//log_msg(TDSPEER031 , 1 ,  lLogText << " RequestMsg is called.", "");
		DIAMETER_MSG_ROUTER()->RequestMsg(std::move(msg),
				reinterpret_cast<DiameterPeerEntry*>(&fsm));
	}
	else
	{
		TEXT lLogText[TSS_MAX_LOG_TEXT_LEN] = "";
		//PRINT_DIAMETER_AVPS(*msg,lLogText);

		try
		{
			DiaHandleMsg::DecodeAnsMsg(*msg);
			//PRINT_DIAMETER_AVPS(*msg,lLogText);
			try
			{
            AAA_LOG((LM_ERROR,"Result-Code:%d PeerName:%s prcessing",msg->baseClass->getResultCode()->getValue(),fsm.Data().m_Identity.c_str()));
//				log_msg(TDSPEER030 , 1 ,  lLogText <<" Result-Code:"<<msg->baseClass->getResultCode()->getValue()
//						<< ",PeerName:" <<fsm.Data().m_Identity.c_str()
//						<< " Process ","");
			}
			catch(...)
			{
//				log_msg(TDSPEER031 , 1 ,  lLogText << " PeerName:" <<fsm.Data().m_Identity.c_str()
//						<< " Result Code is not set.", "");

			}
			try
			{
//				log_msg(TDSPEER030 , 1 ,  lLogText <<" Experimental Result-Code:"<<msg->baseClass->getExperimentalResultCode()->getValue()
//						<< ",PeerName:" <<fsm.Data().m_Identity.c_str()
//						<< " Process ","");
			}
			catch(...)
			{
//				log_msg(TDSPEER031 , 1 ,  lLogText << " PeerName:" <<fsm.Data().m_Identity.c_str()
//						<< " Experimental Result Code is not set.", "");

			}
		}
		catch (DiameterBaseException &err)
		{
//			log_msg(TDSPEER031 , 1 ,  lLogText <<" PeerName:"<<fsm.Data().m_Identity.c_str()
//					<<" Process, expection on decoding request message,error "
//					<<err.Code() << err.Description().c_str(), "");
//			GENERATE_STACK_PEG_BASE(E_DROP_MESS,msg->hdr.mCmdCode,msg->hdr.mApplId);
			return;
		}
		catch(TssDiameterMsgException &err)
		{
//			log_msg(TDSPEER031 , 1 ,  lLogText << " PeerName:"<<fsm.Data().m_Identity.c_str()
//					<< " Process, expection on decoding request message,error "
//					<< err.getErrorCode() << err.getErrMessage(), "");
//			GENERATE_STACK_PEG_BASE(E_DROP_MESS,msg->hdr.mCmdCode,msg->hdr.mApplId);
			return;
		}
		catch(...)
		{
//			log_msg(TDSPEER031 , 1 ,  lLogText << " PeerName:" <<fsm.Data().m_Identity.c_str()
//					<< " Process, expection on decoding request message", "");
//			GENERATE_STACK_PEG_BASE(E_DROP_MESS,msg->hdr.mCmdCode,msg->hdr.mApplId);
			return;
		}

//		log_msg(TDSPEER031 , 1 ,  lLogText << " AnswerMsg is called.", "");
		AAA_LOG((LM_ERROR,"AnswerMsg is calleds"));
		DIAMETER_MSG_ROUTER()->AnswerMsg(std::move(msg),
				reinterpret_cast<DiameterPeerEntry*>(&fsm));
	}

}
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerProcessDWRSendDWA::operator()(DiameterPeerStateMachine &fsm)
{

	std::unique_ptr<DiameterMsg> dwr = std::move(fsm.m_CurrentPeerEventParam->m_Msg);

	fsm.DisassembleDWR(*dwr);

	// TBD: do failover here
	string message = "Successfully send device watchdog Answer";
	fsm.SendDWA(AAA_SUCCESS, message);

	std::string lLogText = LOG_DIAMETER_AVPS(*dwr);	
	AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]ProcessDWRSendDWA, Successfully send device watchdog Answer\n",
				lLogText.c_str(),fsm.Data().m_Identity.c_str()));

	fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_DWR_MSG);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeer_ProcessDWA::operator()(DiameterPeerStateMachine &fsm)
{
	diameter_unsigned32_t rCode = 0;
	std::string  rErrorMsg;

	std::unique_ptr<DiameterMsg> dwa = std::move(fsm.m_CurrentPeerEventParam->m_Msg);

	fsm.DisassembleDWA(*dwa, rCode, rErrorMsg);

	DiameterMsgResultCode rcode(*dwa);

	std::string lLogText = LOG_DIAMETER_AVPS(*dwa);	

	if (rcode.InterpretedResultCode(rCode) ==
			DiameterMsgResultCode::RCODE_SUCCESS) 
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]ProcessDWA, <Result-Code:%d>\n",
					lLogText.c_str(), fsm.Data().m_Identity.c_str(), rCode));

		if(fsm.ErrorCount() > 0)
			fsm.ErrorCount()--;
		//		AAA_LOG((LM_INFO, "%T PEER_FSM DWA Success OP:%s OR:%s \n",	origHost.c_str(), errorMessage.c_str()));
	}
	else 
	{
		//		AAA_LOG((LM_INFO, "(%P|%t) Peer returned an error on OP:%s OR:%s Watchdog Err:%s:  closing peer \n", 
		//					origHost.c_str(), origRealm.c_str(),  errorMessage.c_str()));

		//In case of DIAMETER_TOO_BUSY error system will increament by counter and when it reaches to 2 then take an action to close the connection
		// and re establish
		if(rCode == 3004) //DIAMETER_TOO_BUSY
		{
			//fsm.ErrorCount()++;    
			return;
		}
		else //Other 3004 error, disconnect and reconnect
			fsm.ErrorCount() = 2;

		AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]ProcessDWA, <Result-Code:%d> Err:%s\n", 
					lLogText.c_str(),fsm.Data().m_Identity.c_str(),rCode,rErrorMsg.c_str()));

		if(fsm.ErrorCount() == 2)
		{
			fsm.ErrorCount() = 0;
			fsm.Cleanup();
			fsm.DoReConnect();
		}
	}

	fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_DWA_SUCCESS_MSG);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerI_SendMessage::operator()(DiameterPeerStateMachine &fsm)
{
#if ASYNC_SEND
	boost::shared_ptr<DiameterMsg> msg = fsm.DequeueSendMsg();

	if (fsm.Send(*msg, fsm.PeerData().m_IOInitiator.get()) < 0) 
	{
		std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
		AAA_LOG((LM_INFO, "%T |PEER_FSM| %s {Destination-Realm:%s} {Destination-Host:%s}, [PEER]%s [ACT]I_SendMessage, Error sending message\n", 
					lLogText.c_str(), msg->destinationRealm.c_str(), msg->destinationHost.c_str(),fsm.Data().m_Identity.c_str()));
	}
#endif
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerI_SendCEA::operator()(DiameterPeerStateMachine &fsm)
{
	std::unique_ptr<DiameterMsg> cer = std::move(fsm.m_CurrentPeerEventParam->m_Msg);

	fsm.DisassembleCER(*cer);	

	std::string message;
	diameter_unsigned32_t rcode;

	if (! fsm.ValidatePeer(rcode, message)) 
	{
		std::string lLogText = LOG_DIAMETER_AVPS(*cer);	
		AAA_LOG((LM_INFO, "%T |PEER_FSM| %s <Result-Code:%d>, [PEER]%s [ACT]I_SendCEA, %s during cap re-negotiation\n",
					lLogText.c_str(), rcode, fsm.Data().m_Identity.c_str(), message.c_str()));
	}
	fsm.SendCEA(rcode, message);

	fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_CER_MSG);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerI_SendDPR::operator()(DiameterPeerStateMachine &fsm)
{
	if(fsm.m_Data.m_ToSendDWR == 1)
	{
		fsm.CancelTimer(DIAMETER_PEER_EV_WATCHDOG);
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| [PEER]%s Canceled Timer for WATCHDOG\n",fsm.Data().m_Identity.c_str()));
	}

	fsm.ScheduleTimer(DIAMETER_PEER_EV_TIMEOUT,
			DIAMETER_PEER_CONNECT_ATTEMPT_TOUT,
			0,
			DIAMETER_PEER_EV_TIMEOUT);
	fsm.SendDPR(true);
	AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]I_SendDPR\n", fsm.Data().m_Identity.c_str()));
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_SendDPR::operator()(DiameterPeerStateMachine &fsm)
{

	if(fsm.m_Data.m_ToSendDWR == 1)
	{
		fsm.CancelTimer(DIAMETER_PEER_EV_WATCHDOG);
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| [PEER]%s Canceled Timer for WATCHDOG\n",fsm.Data().m_Identity.c_str()));
	}

	fsm.ScheduleTimer(DIAMETER_PEER_EV_TIMEOUT,
			DIAMETER_PEER_CONNECT_ATTEMPT_TOUT,
			0,
			DIAMETER_PEER_EV_TIMEOUT);
	fsm.SendDPR(false);
	AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]R_SendDPR\n", fsm.Data().m_Identity.c_str()));
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerI_SendDPADisconnect::operator()(DiameterPeerStateMachine &fsm)
{
	std::unique_ptr<DiameterMsg> dpr = std::move(fsm.m_CurrentPeerEventParam->m_Msg);

	std::string lLogText = LOG_DIAMETER_AVPS(*dpr);	
	AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]I_SendDPADisconnect, Peer initiator requested termination, disconnecting\n", lLogText.c_str(),fsm.Data().m_Identity.c_str()));
	fsm.SendDPA(true, AAA_SUCCESS);

	diameter_unsigned32_t cause = 0;
	fsm.DisassembleDPR(*dpr, cause);

	fsm.Cleanup();
	fsm.Disconnected ((cause) ? cause : AAA_DISCONNECT_UNKNOWN);

	fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_DPR_MSG);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerR_SendDPADisconnect::operator()(DiameterPeerStateMachine &fsm)
{
	std::unique_ptr<DiameterMsg> dpr = std::move(fsm.m_CurrentPeerEventParam->m_Msg);

	std::string lLogText = LOG_DIAMETER_AVPS(*dpr);	
	AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]R_SendDPADisconnect, Peer responder requested termination, disconnecting\n", lLogText.c_str(),fsm.Data().m_Identity.c_str()));
	fsm.SendDPA(false, AAA_SUCCESS);

	diameter_unsigned32_t cause = 0;
	fsm.DisassembleDPR(*dpr, cause);

	fsm.Cleanup();
	fsm.Disconnected ((cause ) ? cause : AAA_DISCONNECT_UNKNOWN);

	fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_DPR_MSG);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeer_Disconnect::operator()(DiameterPeerStateMachine &fsm)
{
	AAA_LOG((LM_INFO, "%T |PEER_FSM| [PEER]%s [ACT]Disconnect, General disconnection\n", fsm.Data().m_Identity.c_str()));
	fsm.Cleanup();
	fsm.ErrorCount() = 0;
	fsm.DoReConnect();
	fsm.Disconnected(AAA_DISCONNECT_TRANSPORT);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeer_DisconnectDPA::operator()(DiameterPeerStateMachine &fsm)
{
	diameter_unsigned32_t rCode = 0;
	std::string  rErrorMsg;

	std::unique_ptr<DiameterMsg> dpaMsg  = std::move(fsm.m_CurrentPeerEventParam->m_Msg);

	fsm.DisassembleDWA(*dpaMsg, rCode, rErrorMsg);

	DiameterMsgResultCode rcode(*dpaMsg);

	std::string lLogText = LOG_DIAMETER_AVPS(*dpaMsg);	
	if (rcode.InterpretedResultCode(rCode) == DiameterMsgResultCode::RCODE_SUCCESS) 
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| %s, [PEER]%s [ACT]DisconnectDPA, <Result-Code:%d>\n", lLogText.c_str(),fsm.Data().m_Identity.c_str(),rCode));
	}
	else 
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| %s, [PEER]%s [ACT]DisconnectDPA, <Result-Code:%d>\n", lLogText.c_str(),fsm.Data().m_Identity.c_str(), rCode));
		/*AAA_LOG((LM_INFO, "%T PEER_FSM DPA Peer returned an error on Watchdog: %s, closing peer:%s:%s\n",
		  origHost.c_str(), origRealm.c_str(), message.c_str()));*/
	}

	fsm.Disconnected (fsm.PeerData().m_DisconnectCause);
	//fsm.Cleanup();     //TBC - need to check 

	//--

	if(fsm.PeerData().m_Suspend == true )
	{
		fsm.Cleanup(DiameterPeerStateMachine::CLEANUP_ALL, true);
		fsm.m_TxMsgCollector.Stop();
	}
	else
	{
		fsm.ErrorCount() = 0;
		fsm.Cleanup();
	} 

	if (fsm.PeerData().m_DisconnectCause == AAA_DISCONNECT_REBOOTING) 
	{
		fsm.ErrorCount() = 0;
		fsm.DoReConnect();
	}

	fsm.PeerData().m_Peg->GeneratePeg(DiameterPeg::E_DWA_SUCCESS_MSG);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeer_Watchdog::operator()(DiameterPeerStateMachine &fsm)
{
	AAA_LOG((LM_ERROR, "%T |PEER_FSM| [PEER]%s [ACT]Watchdog ErrorCount():%d\n",fsm.Data().m_Identity.c_str(), fsm.ErrorCount()));

	if(fsm.ErrorCount() < DIAMETER_CFG_RELOAD()->max_dwr_count)	
	{
		if (fsm.TrafficFlag() != true)	
		{
			fsm.SendDWR();
		}
		else
		{
			fsm.TrafficFlag() = false;
		}
	}
	else
	{ 
		//fsm.Notify(DIAMETER_PEER_EV_STOP);
		reinterpret_cast<DiameterPeerEntry*>(&fsm)->StopPeerInitiator(fsm.PeerData().m_DisconnectCause);

		Diameter_IO_Base *io = (fsm.state == DIAMETER_PEER_ST_I_OPEN) ?
			fsm.m_Data.m_IOInitiator.get() :
			fsm.m_Data.m_IOResponder.get();

		if (io)
			io->Close();	

		fsm.Cleanup();   
		fsm.ErrorCount() = 0;
		fsm.Disconnected (fsm.PeerData().m_DisconnectCause);
		fsm.DoReConnect(); 
	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::DisassembleCER(DiameterMsg &msg)
{
	DiameterPeerCapabilities &cap = m_Data.m_PeerCapabilities;

	std::unique_ptr<CapabilityExchangeRequest> ce(new CapabilityExchangeRequest	);

	TRY_DECODE(ce);
	TRY_OCTET_STRING(cap.m_Host,  ce, getOriginHost);
	TRY_OCTET_STRING(cap.m_Realm, ce, getOriginRealm);

	while (! cap.m_HostIpLst.empty())
	{
		diameter_address_t *ip = cap.m_HostIpLst.front();
		cap.m_HostIpLst.pop_front();
		delete ip;
	}
	TRY_HOST_IP_ADDRESS_LST(cap.m_HostIpLst, ce, getHostIPAddressList);

	TRY_INTEGER32(cap.m_VendorId, ce, getVendorId);
	TRY_OCTET_STRING(cap.m_ProductName, ce, getProductName);
	TRY_INTEGER32(cap.m_OriginStateId, ce, getOriginStateId);
	TRY_INTEGER32_LST(cap.m_SupportedVendorIdLst, ce, getSupportedVendorIdList);
	TRY_INTEGER32_LST(cap.m_AuthAppIdLst, ce, getAuthApplicationIdList);
	TRY_INTEGER32(cap.m_InbandSecurityId, ce, getInbandSecurityId);
	TRY_UNSIGNED32_LST(cap.m_AcctAppIdLst, ce, getAcctApplicationIdList);

	while (! cap.m_VendorSpecificId.empty()) {
		cap.m_VendorSpecificId.pop_front();
	}
	TRY_VENDOR_SPECIFIC_APPID_LST(cap.m_VendorSpecificId, ce, getVendorSpecificApplicationIdGrpList);

	TRY_INTEGER32(cap.m_FirmwareRevision, ce, getFirmwareRevision);

	DumpPeerCapabilities();

}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::DisassembleCEA(DiameterMsg &msg, diameter_unsigned32_t & rCode, std::string &rErrorMsg)
{
	DiameterPeerCapabilities &cap = m_Data.m_PeerCapabilities;

	std::unique_ptr<CapabilityExchangeAnswer> ce(new CapabilityExchangeAnswer);

	TRY_DECODE(ce);
	TRY_INTEGER32(rCode, ce, getResultCode);
	TRY_OCTET_STRING(cap.m_Host, ce, getOriginHost);
	TRY_OCTET_STRING(cap.m_Realm, ce, getOriginRealm);

	while (! cap.m_HostIpLst.empty())
	{
		diameter_address_t *ip = cap.m_HostIpLst.front();
		cap.m_HostIpLst.pop_front();
		delete ip;
	}
	TRY_HOST_IP_ADDRESS_LST(cap.m_HostIpLst, ce, getHostIPAddressList);

	TRY_INTEGER32(cap.m_VendorId, ce, getVendorId);
	TRY_OCTET_STRING(cap.m_ProductName, ce, getProductName);
	TRY_INTEGER32(cap.m_OriginStateId, ce, getOriginStateId);
	TRY_OCTET_STRING(rErrorMsg, ce, getErrorMessage);

	TRY_INTEGER32_LST(cap.m_SupportedVendorIdLst, ce, getSupportedVendorIdList);
	TRY_INTEGER32_LST(cap.m_AuthAppIdLst, ce, getAuthApplicationIdList);
	TRY_INTEGER32(cap.m_InbandSecurityId, ce, getInbandSecurityId);
	TRY_UNSIGNED32_LST(cap.m_AcctAppIdLst, ce, getAcctApplicationIdList);

	while (! cap.m_VendorSpecificId.empty()) {
		cap.m_VendorSpecificId.pop_front();
	}
	TRY_VENDOR_SPECIFIC_APPID_LST(cap.m_VendorSpecificId, ce, getVendorSpecificApplicationIdGrpList);

	TRY_INTEGER32(cap.m_FirmwareRevision, ce, getFirmwareRevision);

	DumpPeerCapabilities();

}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::DisassembleDWR(DiameterMsg &msg)
{
	diameter_identity_t     Host;
	diameter_identity_t     Realm;
	diameter_unsigned32_t	origState ;

	std::unique_ptr < DeviceWatchdogRequest> dwr (new DeviceWatchdogRequest);

	TRY_DECODE(dwr);
	TRY_OCTET_STRING(Host,   dwr, getOriginHost);
	TRY_OCTET_STRING(Realm,  dwr, getOriginRealm);
	TRY_INTEGER32(origState, dwr, getOriginStateId);

	std::string lLogText = LOG_DIAMETER_AVPS(msg);	
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| %s Watchdog msg from [%s.%s], state=%d, time=%d\n", lLogText.c_str(), Host.c_str(), Realm.c_str(), origState, time(0)));
}

void DiameterPeerStateMachine::DisassembleDWA(DiameterMsg &msg, diameter_unsigned32_t &rCode, std::string &rErrorMsg)
{
	diameter_identity_t     Host;
	diameter_identity_t     Realm;
	diameter_unsigned32_t	origState;

	std::unique_ptr<DeviceWatchdogAnswer> dwa(new DeviceWatchdogAnswer);

	TRY_DECODE(dwa);
	TRY_INTEGER32(rCode,        dwa, getResultCode);
	TRY_OCTET_STRING(Host,      dwa, getOriginHost);
	TRY_OCTET_STRING(Realm,     dwa, getOriginRealm);
	TRY_INTEGER32(origState,    dwa, getOriginStateId);
	TRY_OCTET_STRING(rErrorMsg, dwa, getErrorMessage);

	std::string lLogText = LOG_DIAMETER_AVPS(msg);	
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| %s Watchdog msg from [%s.%s], state=%d, time=%d\n", lLogText.c_str(), Host.c_str(), Realm.c_str(), origState, time(0)));
}

void DiameterPeerStateMachine::DisassembleDPR(DiameterMsg &msg, diameter_unsigned32_t &cause)
{
	diameter_identity_t     Host;
	diameter_identity_t     Realm;

	std::unique_ptr <DisconnectPeerRequest> dpr (new DisconnectPeerRequest);

	TRY_DECODE(dpr);
	TRY_OCTET_STRING(Host,   dpr, getOriginHost);
	TRY_OCTET_STRING(Realm,  dpr, getOriginRealm);
	TRY_INTEGER32(cause,     dpr, getDisconnectCause);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::DisassembleDPA(DiameterMsg &msg, diameter_unsigned32_t &rCode, std::string &rErrorMsg)
{
	diameter_identity_t     Host;
	diameter_identity_t     Realm;

	std::unique_ptr<DisconnectPeerAnswer> dpa(new DisconnectPeerAnswer);

	TRY_DECODE(dpa);
	TRY_INTEGER32(rCode,        dpa, getResultCode);
	TRY_OCTET_STRING(Host,      dpa, getOriginHost);
	TRY_OCTET_STRING(Realm,     dpa, getOriginRealm);
	TRY_OCTET_STRING(rErrorMsg, dpa, getErrorMessage);
}

void DiameterPeerStateMachine::SendCER()
{
	/*
		5.3.1.  Capabilities-Exchange-Request

		The Capabilities-Exchange-Request (CER), indicated by the Command-
		Code set to 257 and the Command Flags' 'R' bit set, is sent to
		exchange local capabilities.  Upon detection of a transport failure,
		this message MUST NOT be sent to an alternate peer.

		When Diameter is run over SCTP [SCTP], which allows for connections
		to span multiple interfaces and multiple IP addresses, the
		Capabilities-Exchange-Request message MUST contain one Host-IP-
		Address AVP for each potential IP address that MAY be locally used
		when transmitting Diameter messages.


		Message Format

		<CER> ::= < Diameter Header: 257, REQ >
		{ Origin-Host }
		{ Origin-Realm }
		1* { Host-IP-Address }
		{ Vendor-Id }
		{ Product-Name }
		[ Origin-State-Id ]
	 * [ Supported-Vendor-Id ]
	 * [ Auth-Application-Id ]
	 * [ Inband-Security-Id ]
	 * [ Acct-Application-Id ]
	 * [ Vendor-Specific-Application-Id ]
	 [ Firmware-Revision ]
	 * [ AVP ]
	 */

	std::unique_ptr<DiameterMsg> msg(new DiameterMsg);
	//std::unique_ptr<DiameterMsg> msg = std::make_unique<DiameterMsg>();

	ACE_OS::memset(&msg->hdr, 0, sizeof(msg->hdr));
	ACE_OS::memset(&msg->rawbyteArray , 0, sizeof(msg->rawbyteArray));

	DiameterMsgHeader &h =	 msg->hdr;

	h.mVersion    	   = DIAMETER_PROTOCOL_VERSION;
	h.mMsgLen 	      = 128;
	h.mCmdFlg.rBit 	= DIAMETER_FLAG_SET;
	h.mCmdFlg.pBit 	= DIAMETER_FLAG_CLR;
	h.mCmdFlg.eBit 	= DIAMETER_FLAG_CLR;
	h.mCmdCode 	      = DIAMETER_MSGCODE_CAPABILITIES_EXCHG;
	h.mApplId 	      = DIAMETER_BASE_APPLICATION_ID;

	MsgIdTxMessage(*msg);

	std::unique_ptr<CapabilityExchangeRequest> cer(new CapabilityExchangeRequest );

	cer->getDiameterMsgHeader()->mVersion   = DIAMETER_PROTOCOL_VERSION;
	cer->setCmdFlag(128);
	cer->getDiameterMsgHeader()->mCmdCode   = DIAMETER_MSGCODE_CAPABILITIES_EXCHG;
	cer->getDiameterMsgHeader()->mApplId    = DIAMETER_BASE_APPLICATION_ID;

	msg->hdr.mCmdCode  = DIAMETER_MSGCODE_CAPABILITIES_EXCHG;
	msg->hdr.mApplId   = DIAMETER_BASE_APPLICATION_ID;
	cer->getDiameterMsgHeader()->mHopByHopId  =  msg->hdr.mHopByHopId;
	cer->getDiameterMsgHeader()->mEndToEndId  =  msg->hdr.mEndToEndId;

	cer->setOriginHost()->setValue((UINT8*)m_Data.m_HostEntry.m_Identity.c_str(), m_Data.m_HostEntry.m_Identity.size());
	cer->setOriginRealm()->setValue((UINT8*)m_Data.m_HostEntry.m_Realm.c_str(), m_Data.m_HostEntry.m_Realm.size());

	std::string host;
	DiameterHostByName::Lookup(m_Data.m_HostEntry.m_Identity.c_str(), host);

	Address *lHostIPAddress = new Address();
	lHostIPAddress->setValue((UINT8*)host.c_str(), host.size());

	list<Address*>* lHostIPAddrLst = cer->setHostIPAddressList();
	lHostIPAddrLst->push_back(lHostIPAddress);

	std::list<std::string>::iterator AdvHostIPAddressIt = m_Data.m_HostEntry.m_AdvertisedHostName.begin();
	for (; AdvHostIPAddressIt != m_Data.m_HostEntry.m_AdvertisedHostName.end(); AdvHostIPAddressIt++)
	{
		std::string advHost;
		DiameterHostByName::Lookup((*AdvHostIPAddressIt).c_str(), advHost);

		Address *lAdvHostIPAddress = new Address();
		lAdvHostIPAddress->setValue((UINT8*)advHost.c_str(), advHost.size());
		lHostIPAddrLst->push_back(lAdvHostIPAddress);
	}

	cer->setVendorId()->setValue(DIAMETER_CFG_GENERAL()->vendor);
	cer->setProductName()->setValue((UINT8*)DIAMETER_CFG_GENERAL()->product.c_str(), DIAMETER_CFG_GENERAL()->product.size());
	cer->setOriginStateId()->setValue(DIAMETER_CFG_RUNTIME()->originStateId);

	list<Integer32*>* SupportedVendorIdList = cer->setSupportedVendorIdList();
	DiameterApplicationIdLst::iterator SupportedVendorId = DIAMETER_CFG_GENERAL()->supportedVendorIdLst.begin();
	for (; SupportedVendorId != DIAMETER_CFG_GENERAL()->supportedVendorIdLst.end(); SupportedVendorId++)
	{
		Integer32 *lInteger32 = new Integer32();
		lInteger32->setValue(*SupportedVendorId);
		SupportedVendorIdList->push_back(lInteger32);
	}

	list<Integer32*>* AuthApplicationIdList = cer->setAuthApplicationIdList();

	DiameterApplicationIdLst::iterator AuthApplicationId = DIAMETER_CFG_GENERAL()->authAppIdLst.begin();

	for (; AuthApplicationId != DIAMETER_CFG_GENERAL()->authAppIdLst.end(); AuthApplicationId++)
	{
		auto *lInteger32 = new Integer32();
		lInteger32->setValue(*AuthApplicationId);
		AuthApplicationIdList->push_back(lInteger32);
	}

	cer->setInbandSecurityId()->setValue(m_Data.m_TLS);

	list<Unsigned32*>* AcctApplicationIdList = cer->setAcctApplicationIdList();
	DiameterApplicationIdLst::iterator AcctApplicationId = DIAMETER_CFG_GENERAL()->acctAppIdLst.begin();
	for (; AcctApplicationId != DIAMETER_CFG_GENERAL()->acctAppIdLst.end(); AcctApplicationId++)
	{
		auto *lInteger32 = new Unsigned32();
		lInteger32->setValue(*AcctApplicationId);
		AcctApplicationIdList->push_back(lInteger32);
	}

	//VendorSpecificApplicationID
	list<VendorSpecificApplicationId*>* lVendorSpecificApplicationIdList = cer->setVendorSpecificApplicationIdGrpList();
	DiameterVendorSpecificIdLst::iterator y = DIAMETER_CFG_GENERAL()->vendorSpecificId.begin();
	for (; y != DIAMETER_CFG_GENERAL()->vendorSpecificId.end(); y++)
	{
		DiameterDataVendorSpecificApplicationId vid = *y;
		VendorSpecificApplicationId *lVendorSpecificApplicationId = new VendorSpecificApplicationId();

		lVendorSpecificApplicationId->setVendorId()->setValue(vid.vendorId);
		/* Date: 01-07-2025 - Abhishek Chhabra
		 * Exactly one instance of either Auth-Application-Id or Acct-Application-Id AVP MUST be present.
		 */
		if (vid.authAppId!= 0)
			lVendorSpecificApplicationId->setAuthApplicationId()->setValue(vid.authAppId);
		else
			lVendorSpecificApplicationId->setAcctApplicationId()->setValue(vid.acctAppId);
		lVendorSpecificApplicationIdList->push_back(lVendorSpecificApplicationId);
	}

	cer->setFirmwareRevision()->setValue(DIAMETER_CFG_GENERAL()->version);

	if(DIAMETER_NO_ERR == cer->Encode(&msg->rawbyteArray))
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to Encode CER\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to Encode CER\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}

	if(m_TxMsgCollector.Send(msg, m_Data.m_IOInitiator.get(), true) == 0) 
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to send CER\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to send CER\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}

}
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------

void DiameterPeerStateMachine::SendCEA(diameter_unsigned32_t rcode,
		std::string &message)
{
	/*
		5.3.2.  Capabilities-Exchange-Answer

		The Capabilities-Exchange-Answer (CEA), indicated by the Command-Code
		set to 257 and the Command Flags' 'R' bit cleared, is sent in
		response to a CER message.

		When Diameter is run over SCTP [SCTP], which allows connections to
		span multiple interfaces, hence, multiple IP addresses, the
		Capabilities-Exchange-Answer message MUST contain one Host-IP-Address
		AVP for each potential IP address that MAY be locally used when
		transmitting Diameter messages.

		Message Format

		<CEA> ::= < Diameter Header: 257 >
		{ Result-Code }
		{ Origin-Host }
		{ Origin-Realm }
		1* { Host-IP-Address }
		{ Vendor-Id }
		{ Product-Name }
		[ Origin-State-Id ]
		[ Error-Message ]
	 * [ Failed-AVP ]
	 * [ Supported-Vendor-Id ]
	 * [ Auth-Application-Id ]
	 * [ Inband-Security-Id ]
	 * [ Acct-Application-Id ]
	 * [ Vendor-Specific-Application-Id ]
	 [ Firmware-Revision ]
	 * [ AVP ]
	 */


	std::unique_ptr<DiameterMsg> msg(new DiameterMsg);

	ACE_OS::memset(&msg->hdr, 0, sizeof(msg->hdr));
	ACE_OS::memset(&msg->rawbyteArray , 0, sizeof(msg->rawbyteArray));

	DiameterMsgHeader &h =   msg->hdr;

	h.mVersion    	= DIAMETER_PROTOCOL_VERSION;
	h.mMsgLen 	   = 0;
	h.mCmdFlg.rBit	= DIAMETER_FLAG_CLR;
	h.mCmdFlg.pBit	= DIAMETER_FLAG_CLR;
	h.mCmdFlg.eBit	= DIAMETER_FLAG_CLR;
	h.mCmdCode 	   = DIAMETER_MSGCODE_CAPABILITIES_EXCHG;
	h.mApplId 	   = DIAMETER_BASE_APPLICATION_ID;

	MsgIdTxMessage(*msg);

	std::unique_ptr<CapabilityExchangeAnswer> cea(new CapabilityExchangeAnswer);

	cea->getDiameterMsgHeader()->mVersion = DIAMETER_PROTOCOL_VERSION;
	cea->setCmdFlag(0);  
	cea->getDiameterMsgHeader()->mCmdCode = DIAMETER_MSGCODE_CAPABILITIES_EXCHG;
	cea->getDiameterMsgHeader()->mApplId  = DIAMETER_BASE_APPLICATION_ID;

	msg->hdr.mCmdCode = DIAMETER_MSGCODE_CAPABILITIES_EXCHG;
	msg->hdr.mApplId  = DIAMETER_BASE_APPLICATION_ID;
	cea->getDiameterMsgHeader()->mHopByHopId = msg->hdr.mHopByHopId;
	cea->getDiameterMsgHeader()->mEndToEndId = msg->hdr.mEndToEndId;

	cea->setResultCode()->setValue(rcode);
	cea->setOriginHost()->setValue((UINT8*)m_Data.m_HostEntry.m_Identity.c_str(), m_Data.m_HostEntry.m_Identity.size());
	cea->setOriginRealm()->setValue((UINT8*)m_Data.m_HostEntry.m_Realm.c_str(), m_Data.m_HostEntry.m_Realm.size());

	std::string host;
	DiameterHostByName::Lookup(m_Data.m_HostEntry.m_Identity.c_str(), host);

	Address *lHostIPAddress = new Address();
	lHostIPAddress->setValue((UINT8*)host.c_str(), host.size());

	list<Address*>* lHostIPAddrLst = cea->setHostIPAddressList();
	lHostIPAddrLst->push_back(lHostIPAddress);

	std::list<std::string>::iterator AdvHostIPAddressIt = m_Data.m_HostEntry.m_AdvertisedHostName.begin();
	for (; AdvHostIPAddressIt != m_Data.m_HostEntry.m_AdvertisedHostName.end(); AdvHostIPAddressIt++)
	{
		std::string advHost;
		DiameterHostByName::Lookup((*AdvHostIPAddressIt).c_str(), advHost);

		Address *lAdvHostIPAddress = new Address();
		lAdvHostIPAddress->setValue((UINT8*)advHost.c_str(), advHost.size());
		lHostIPAddrLst->push_back(lAdvHostIPAddress);
	}

	cea->setVendorId()->setValue(DIAMETER_CFG_GENERAL()->vendor);
	cea->setProductName()->setValue((UINT8*)DIAMETER_CFG_GENERAL()->product.c_str(), DIAMETER_CFG_GENERAL()->product.size());
	cea->setOriginStateId()->setValue(DIAMETER_CFG_RUNTIME()->originStateId);

	list<Integer32*>* SupportedVendorIdList = cea->setSupportedVendorIdList();
	DiameterApplicationIdLst::iterator SupportedVendorId = DIAMETER_CFG_GENERAL()->supportedVendorIdLst.begin();
	for (; SupportedVendorId != DIAMETER_CFG_GENERAL()->supportedVendorIdLst.end(); SupportedVendorId++)
	{
		Integer32 *lInteger32 = new Integer32();
		lInteger32->setValue(*SupportedVendorId);
		SupportedVendorIdList->push_back(lInteger32);
	}

	list<Integer32*>* AuthApplicationIdList = cea->setAuthApplicationIdList();
	DiameterApplicationIdLst::iterator AuthApplicationId = DIAMETER_CFG_GENERAL()->authAppIdLst.begin();

	for (; AuthApplicationId != DIAMETER_CFG_GENERAL()->authAppIdLst.end(); AuthApplicationId++)
		// for(auto* item : *AuthApplicationIdList)
	{
		auto *lInteger32 = new Integer32();
		lInteger32->setValue(*AuthApplicationId);
		AuthApplicationIdList->push_back(lInteger32);
	}

	cea->setInbandSecurityId()->setValue(m_Data.m_TLS);

	list<Unsigned32*>* AcctApplicationIdList = cea->setAcctApplicationIdList();
	DiameterApplicationIdLst::iterator AcctApplicationId = DIAMETER_CFG_GENERAL()->acctAppIdLst.begin();
	for (; AcctApplicationId != DIAMETER_CFG_GENERAL()->acctAppIdLst.end(); AcctApplicationId++)
	{
		auto *lInteger32 = new Unsigned32();
		lInteger32->setValue(*AcctApplicationId);
		AcctApplicationIdList->push_back(lInteger32);
	}

	//VendorSpecificApplicationID
	list<VendorSpecificApplicationId*>* lVendorSpecificApplicationIdList = cea->setVendorSpecificApplicationIdGrpList();
	DiameterVendorSpecificIdLst::iterator y = DIAMETER_CFG_GENERAL()->vendorSpecificId.begin();
	for (; y != DIAMETER_CFG_GENERAL()->vendorSpecificId.end(); y++)
	{
		DiameterDataVendorSpecificApplicationId vid = *y;
		VendorSpecificApplicationId *lVendorSpecificApplicationId = new VendorSpecificApplicationId();

		lVendorSpecificApplicationId->setVendorId()->setValue(vid.vendorId);
		/* Date: 01-07-2025 - Abhishek Chhabra
		 * Exactly one instance of either Auth-Application-Id or Acct-Application-Id AVP MUST be present.
		 */
		if (vid.authAppId!= 0)
			lVendorSpecificApplicationId->setAuthApplicationId()->setValue(vid.authAppId);
		else
			lVendorSpecificApplicationId->setAcctApplicationId()->setValue(vid.acctAppId);
		lVendorSpecificApplicationIdList->push_back(lVendorSpecificApplicationId);
	}

	cea->setFirmwareRevision()->setValue(DIAMETER_CFG_GENERAL()->version);

	DiameterMsgResultCode::RCODE interpretedRcode =  DiameterMsgResultCode::InterpretedResultCode(rcode);

	if ((message.length() > 0) && 
			(interpretedRcode != DiameterMsgResultCode::RCODE_NOT_PRESENT) &&
			(interpretedRcode != DiameterMsgResultCode::RCODE_SUCCESS)) 
	{
		cea->setErrorMessage()->setValue((UINT8*)message.c_str(), message.size());
	}

	if (DIAMETER_NO_ERR == cea->Encode( &msg->rawbyteArray))
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to Encode CEA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to Encode CEA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}

	// check resulting state to determine
	// which IO to use
	Diameter_IO_Base *io = (state == DIAMETER_PEER_ST_I_OPEN) ?
		m_Data.m_IOInitiator.get():
		m_Data.m_IOResponder.get();

	if (m_TxMsgCollector.Send(msg, io, true) == 0) 
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to send CEA\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to send CEA\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}

}


//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION : Method Overloaded By Abhishek Chhabra
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::SendCEA(diameter_unsigned32_t rcode,
	std::string &message, Diameter_IO_Base* io)
   //std::unique_ptr<Diameter_IO_Base> io)
{
	/*
		5.3.2.  Capabilities-Exchange-Answer

		The Capabilities-Exchange-Answer (CEA), indicated by the Command-Code
		set to 257 and the Command Flags' 'R' bit cleared, is sent in
		response to a CER message.

		When Diameter is run over SCTP [SCTP], which allows connections to
		span multiple interfaces, hence, multiple IP addresses, the
		Capabilities-Exchange-Answer message MUST contain one Host-IP-Address
		AVP for each potential IP address that MAY be locally used when
		transmitting Diameter messages.

		Message Format

		<CEA> ::= < Diameter Header: 257 >
		{ Result-Code }
		{ Origin-Host }
		{ Origin-Realm }
		1* { Host-IP-Address }
		{ Vendor-Id }
		{ Product-Name }
		[ Origin-State-Id ]
		[ Error-Message ]
	 * [ Failed-AVP ]
	 * [ Supported-Vendor-Id ]
	 * [ Auth-Application-Id ]
	 * [ Inband-Security-Id ]
	 * [ Acct-Application-Id ]
	 * [ Vendor-Specific-Application-Id ]
	 [ Firmware-Revision ]
	 * [ AVP ]
	 */

	std::unique_ptr<DiameterMsg> msg(new DiameterMsg);

	ACE_OS::memset(&msg->hdr, 0, sizeof(msg->hdr));
	ACE_OS::memset(&msg->rawbyteArray , 0, sizeof(msg->rawbyteArray));

	DiameterMsgHeader &h =   msg->hdr;

	h.mVersion    	= DIAMETER_PROTOCOL_VERSION;
	h.mMsgLen 	   = 0;
	h.mCmdFlg.rBit	= DIAMETER_FLAG_CLR;
	h.mCmdFlg.pBit	= DIAMETER_FLAG_CLR;
	h.mCmdFlg.eBit	= DIAMETER_FLAG_CLR;
	h.mCmdCode 	   = DIAMETER_MSGCODE_CAPABILITIES_EXCHG;
	h.mApplId 	   = DIAMETER_BASE_APPLICATION_ID;

	MsgIdTxMessage(*msg);

	std::unique_ptr<CapabilityExchangeAnswer> cea(new CapabilityExchangeAnswer);

	cea->getDiameterMsgHeader()->mVersion = DIAMETER_PROTOCOL_VERSION;
	cea->setCmdFlag(0);  
	cea->getDiameterMsgHeader()->mCmdCode = DIAMETER_MSGCODE_CAPABILITIES_EXCHG;
	cea->getDiameterMsgHeader()->mApplId  = DIAMETER_BASE_APPLICATION_ID;

	msg->hdr.mCmdCode = DIAMETER_MSGCODE_CAPABILITIES_EXCHG;
	msg->hdr.mApplId  = DIAMETER_BASE_APPLICATION_ID;
	cea->getDiameterMsgHeader()->mHopByHopId = msg->hdr.mHopByHopId;
	cea->getDiameterMsgHeader()->mEndToEndId = msg->hdr.mEndToEndId;

	cea->setResultCode()->setValue(rcode);
	cea->setOriginHost()->setValue((UINT8*)m_Data.m_HostEntry.m_Identity.c_str(), m_Data.m_HostEntry.m_Identity.size());
	cea->setOriginRealm()->setValue((UINT8*)m_Data.m_HostEntry.m_Realm.c_str(), m_Data.m_HostEntry.m_Realm.size());

	std::string host;
	DiameterHostByName::Lookup(m_Data.m_HostEntry.m_Identity.c_str(), host);

	Address *lHostIPAddress = new Address();
	lHostIPAddress->setValue((UINT8*)host.c_str(), host.size());

	list<Address*>* lHostIPAddrLst = cea->setHostIPAddressList();
	lHostIPAddrLst->push_back(lHostIPAddress);

	std::list<std::string>::iterator AdvHostIPAddressIt = m_Data.m_HostEntry.m_AdvertisedHostName.begin();
	for (; AdvHostIPAddressIt != m_Data.m_HostEntry.m_AdvertisedHostName.end(); AdvHostIPAddressIt++)
	{
		std::string advHost;
		DiameterHostByName::Lookup((*AdvHostIPAddressIt).c_str(), advHost);

		Address *lAdvHostIPAddress = new Address();
		lAdvHostIPAddress->setValue((UINT8*)advHost.c_str(), advHost.size());
		lHostIPAddrLst->push_back(lAdvHostIPAddress);
	}

	cea->setVendorId()->setValue(DIAMETER_CFG_GENERAL()->vendor);
	cea->setProductName()->setValue((UINT8*)DIAMETER_CFG_GENERAL()->product.c_str(), DIAMETER_CFG_GENERAL()->product.size());
	cea->setOriginStateId()->setValue(DIAMETER_CFG_RUNTIME()->originStateId);

	list<Integer32*>* SupportedVendorIdList = cea->setSupportedVendorIdList();
	DiameterApplicationIdLst::iterator SupportedVendorId = DIAMETER_CFG_GENERAL()->supportedVendorIdLst.begin();
	for (; SupportedVendorId != DIAMETER_CFG_GENERAL()->supportedVendorIdLst.end(); SupportedVendorId++)
	{
		Integer32 *lInteger32 = new Integer32();
		lInteger32->setValue(*SupportedVendorId);
		SupportedVendorIdList->push_back(lInteger32);
	}

	list<Integer32*>* AuthApplicationIdList = cea->setAuthApplicationIdList();
	DiameterApplicationIdLst::iterator AuthApplicationId = DIAMETER_CFG_GENERAL()->authAppIdLst.begin();

	for (; AuthApplicationId != DIAMETER_CFG_GENERAL()->authAppIdLst.end(); AuthApplicationId++)
		// for(auto* item : *AuthApplicationIdList)
	{
		auto *lInteger32 = new Integer32();
		lInteger32->setValue(*AuthApplicationId);
		AuthApplicationIdList->push_back(lInteger32);
	}

	cea->setInbandSecurityId()->setValue(m_Data.m_TLS);

	list<Unsigned32*>* AcctApplicationIdList = cea->setAcctApplicationIdList();
	DiameterApplicationIdLst::iterator AcctApplicationId = DIAMETER_CFG_GENERAL()->acctAppIdLst.begin();
	for (; AcctApplicationId != DIAMETER_CFG_GENERAL()->acctAppIdLst.end(); AcctApplicationId++)
	{
		auto *lInteger32 = new Unsigned32();
		lInteger32->setValue(*AcctApplicationId);
		AcctApplicationIdList->push_back(lInteger32);
	}

	//VendorSpecificApplicationID
	list<VendorSpecificApplicationId*>* lVendorSpecificApplicationIdList = cea->setVendorSpecificApplicationIdGrpList();
	DiameterVendorSpecificIdLst::iterator y = DIAMETER_CFG_GENERAL()->vendorSpecificId.begin();
	for (; y != DIAMETER_CFG_GENERAL()->vendorSpecificId.end(); y++)
	{
		DiameterDataVendorSpecificApplicationId vid = *y;
		VendorSpecificApplicationId *lVendorSpecificApplicationId = new VendorSpecificApplicationId();

		lVendorSpecificApplicationId->setVendorId()->setValue(vid.vendorId);
		lVendorSpecificApplicationId->setAuthApplicationId()->setValue(vid.authAppId);
		lVendorSpecificApplicationId->setAcctApplicationId()->setValue(vid.acctAppId);
		lVendorSpecificApplicationIdList->push_back(lVendorSpecificApplicationId);
	}

	cea->setFirmwareRevision()->setValue(DIAMETER_CFG_GENERAL()->version);

	DiameterMsgResultCode::RCODE interpretedRcode =  DiameterMsgResultCode::InterpretedResultCode(rcode);

	if ((message.length() > 0) && 
			(interpretedRcode != DiameterMsgResultCode::RCODE_NOT_PRESENT) &&
			(interpretedRcode != DiameterMsgResultCode::RCODE_SUCCESS)) 
	{
		cea->setErrorMessage()->setValue((UINT8*)message.c_str(), message.size());
	}

	if (DIAMETER_NO_ERR == cea->Encode( &msg->rawbyteArray))
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to Encode CEA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to Encode CEA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}

   // check resulting state to determine
	// which IO to use
	// Diameter_IO_Base *io = (state == DIAMETER_PEER_ST_I_OPEN) ? m_Data.m_IOInitiator.get(): m_Data.m_IOResponder.get();

	//if (m_TxMsgCollector.Send(msg, io.get(), true) == 0) 
	if (m_TxMsgCollector.Send(msg, io, true) == 0) 
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to send CEA\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to send CEA\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}
}
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------

void DiameterPeerStateMachine::SendDWR()
{
	/*
		5.5.1.  Device-Watchdog-Request

		The Device-Watchdog-Request (DWR), indicated by the Command-Code set
		to 280 and the Command Flags' 'R' bit set, is sent to a peer when no
		traffic has been exchanged between two peers (see Section 5.5.3).
		Upon detection of a transport failure, this message MUST NOT be sent
		to an alternate peer.

		Message Format

		<DWR>  ::= < Diameter Header: 280, REQ >
		{ Origin-Host }
		{ Origin-Realm }
		[ Origin-State-Id ]
		*/

	std::unique_ptr<DiameterMsg> msg(new DiameterMsg);

	DiameterMsgHeader &h =   msg->hdr;

	ACE_OS::memset(&msg->hdr          , 0, sizeof(msg->hdr));
	ACE_OS::memset(&msg->rawbyteArray , 0, sizeof(msg->rawbyteArray));

	h.mVersion     = DIAMETER_PROTOCOL_VERSION;
	h.mMsgLen      = 0;
	h.mCmdFlg.rBit = DIAMETER_FLAG_SET;
	h.mCmdFlg.pBit = DIAMETER_FLAG_CLR;
	h.mCmdFlg.eBit = DIAMETER_FLAG_CLR;
	h.mCmdCode     = DIAMETER_MSGCODE_WATCHDOG;
	h.mApplId      = DIAMETER_BASE_APPLICATION_ID;

	MsgIdTxMessage(*msg);

	std::unique_ptr <DeviceWatchdogRequest > dwr (new DeviceWatchdogRequest);

	dwr->getDiameterMsgHeader()->mVersion    = DIAMETER_PROTOCOL_VERSION;
	dwr->setCmdFlag(128);
	dwr->getDiameterMsgHeader()->mCmdCode    = DIAMETER_MSGCODE_WATCHDOG;
	dwr->getDiameterMsgHeader()->mApplId     = DIAMETER_BASE_APPLICATION_ID;

	msg->hdr.mCmdCode 	   = DIAMETER_MSGCODE_WATCHDOG;
	msg->hdr.mApplId 			= DIAMETER_BASE_APPLICATION_ID;

	dwr->getDiameterMsgHeader()->mHopByHopId = msg->hdr.mHopByHopId ;
	dwr->getDiameterMsgHeader()->mEndToEndId = msg->hdr.mEndToEndId ;

	dwr->setOriginHost()->setValue((UINT8*)m_Data.m_HostEntry.m_Identity.c_str(), m_Data.m_HostEntry.m_Identity.size());
	dwr->setOriginRealm()->setValue((UINT8*)m_Data.m_HostEntry.m_Realm.c_str(), m_Data.m_HostEntry.m_Realm.size());
	dwr->setOriginStateId()->setValue(DIAMETER_CFG_RUNTIME()->originStateId);

	if(DIAMETER_NO_ERR == dwr->Encode(&msg->rawbyteArray))
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to Encode DWR\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to Encode DWR\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}

	// check resulting state to determine
	// which IO to use
	Diameter_IO_Base *io = (state == DIAMETER_PEER_ST_I_OPEN) ?
		m_Data.m_IOInitiator.get() :
		m_Data.m_IOResponder.get();
	if (m_TxMsgCollector.Send(msg, io, true) < 0) {
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to send DWR\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}
	else
	{
		(*this).ErrorCount()++;
		AAA_LOG((LM_INFO, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to send DWR\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}

}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::SendDWA(diameter_unsigned32_t rcode,
		std::string &message)
{
	/*
		5.5.2.  Device-Watchdog-Answer

		The Device-Watchdog-Answer (DWA), indicated by the Command-Code set
		to 280 and the Command Flags' 'R' bit cleared, is sent as a response
		to the Device-Watchdog-Request message.

		Message Format

		<DWA>  ::= < Diameter Header: 280 >
		{ Result-Code }
		{ Origin-Host }
		{ Origin-Realm }
		[ Error-Message ]
	 * [ Failed-AVP ]
	 [ Original-State-Id ]
	 */

	std::unique_ptr<DiameterMsg> msg(new DiameterMsg);
	DiameterMsgHeader &h =   msg->hdr;

	ACE_OS::memset(&msg->hdr          , 0, sizeof(msg->hdr));
	ACE_OS::memset(&msg->rawbyteArray , 0, sizeof(msg->rawbyteArray));

	h.mVersion     = DIAMETER_PROTOCOL_VERSION;
	h.mMsgLen      = 0;
	h.mCmdFlg.rBit = DIAMETER_FLAG_CLR;
	h.mCmdFlg.pBit = DIAMETER_FLAG_CLR;
	h.mCmdFlg.eBit = DIAMETER_FLAG_CLR;
	h.mCmdCode     = DIAMETER_MSGCODE_WATCHDOG;
	h.mApplId      = DIAMETER_BASE_APPLICATION_ID;

	MsgIdTxMessage(*msg);

	std::unique_ptr < DeviceWatchdogAnswer > dwa(new DeviceWatchdogAnswer);

	dwa->getDiameterMsgHeader()->mVersion  = DIAMETER_PROTOCOL_VERSION;
	dwa->setCmdFlag(0);
	dwa->getDiameterMsgHeader()->mCmdCode  = DIAMETER_MSGCODE_WATCHDOG;
	dwa->getDiameterMsgHeader()->mApplId   = DIAMETER_BASE_APPLICATION_ID;

	msg->hdr.mCmdCode = DIAMETER_MSGCODE_WATCHDOG;
	msg->hdr.mApplId 	= DIAMETER_BASE_APPLICATION_ID;
	dwa->getDiameterMsgHeader()->mHopByHopId = msg->hdr.mHopByHopId ;
	dwa->getDiameterMsgHeader()->mEndToEndId = msg->hdr.mEndToEndId ;

	dwa->setResultCode()->setValue(rcode);
	dwa->setOriginHost()->setValue((UINT8*)m_Data.m_HostEntry.m_Identity.c_str(), m_Data.m_HostEntry.m_Identity.size());
	dwa->setOriginRealm()->setValue((UINT8*)m_Data.m_HostEntry.m_Realm.c_str(), m_Data.m_HostEntry.m_Realm.size());

	DiameterMsgResultCode::RCODE interpretedRcode =  DiameterMsgResultCode::InterpretedResultCode(rcode);

	if ((message.length() > 0) &&
			(interpretedRcode != DiameterMsgResultCode::RCODE_NOT_PRESENT) &&
			(interpretedRcode != DiameterMsgResultCode::RCODE_SUCCESS))
	{
		dwa->setErrorMessage()->setValue((UINT8*)message.c_str(), message.size());
	}


	if(DIAMETER_NO_ERR == dwa->Encode(&msg->rawbyteArray))
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to Encode DWA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to Encode DWA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}

	Diameter_IO_Base *io = (state == DIAMETER_PEER_ST_I_OPEN) ?
		m_Data.m_IOInitiator.get() :
		m_Data.m_IOResponder.get();

	if (m_TxMsgCollector.Send(msg, io, true) < 0) 
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to send DWA\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to send DWA\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}

}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::SendDPR(bool initiator)
{
	/*
		5.4.1.  Disconnect-Peer-Request

		The Disconnect-Peer-Request (DPR), indicated by the Command-Code set
		to 282 and the Command Flags' 'R' bit set, is sent to a peer to
		inform its intentions to shutdown the transport connection.  Upon
		detection of a transport failure, this message MUST NOT be sent to an
		alternate peer.

		Message Format

		<DPR>  ::= < Diameter Header: 282, REQ >
		{ Origin-Host }
		{ Origin-Realm }
		{ Disconnect-Cause }
		*/


	std::unique_ptr<DiameterMsg> msg(new DiameterMsg);
	DiameterMsgHeader &h =   msg->hdr;

	ACE_OS::memset(&msg->hdr          , 0, sizeof(msg->hdr));
	ACE_OS::memset(&msg->rawbyteArray , 0, sizeof(msg->rawbyteArray));

	h.mVersion     = DIAMETER_PROTOCOL_VERSION;
	h.mMsgLen      = 0;
	h.mCmdFlg.rBit = DIAMETER_FLAG_SET;
	h.mCmdFlg.pBit = DIAMETER_FLAG_CLR;
	h.mCmdFlg.eBit = DIAMETER_FLAG_CLR;
	h.mCmdCode     = DIAMETER_MSGCODE_DISCONNECT_PEER;
	h.mApplId      = DIAMETER_BASE_APPLICATION_ID;

	MsgIdTxMessage(*msg);

	std::unique_ptr < DisconnectPeerRequest > dpr (new DisconnectPeerRequest);

	dpr->getDiameterMsgHeader()->mVersion   = DIAMETER_PROTOCOL_VERSION;
	dpr->setCmdFlag(128);
	dpr->getDiameterMsgHeader()->mCmdCode   = DIAMETER_MSGCODE_DISCONNECT_PEER ;
	dpr->getDiameterMsgHeader()->mApplId    = DIAMETER_BASE_APPLICATION_ID;

	msg->hdr.mCmdCode = DIAMETER_MSGCODE_DISCONNECT_PEER;
	msg->hdr.mApplId 	= DIAMETER_BASE_APPLICATION_ID;
	dpr->getDiameterMsgHeader()->mHopByHopId = msg->hdr.mHopByHopId ;
	dpr->getDiameterMsgHeader()->mEndToEndId = msg->hdr.mEndToEndId ;

	dpr->setOriginHost()->setValue((UINT8*)m_Data.m_HostEntry.m_Identity.c_str(), m_Data.m_HostEntry.m_Identity.size());
	dpr->setOriginRealm()->setValue((UINT8*)m_Data.m_HostEntry.m_Realm.c_str(), m_Data.m_HostEntry.m_Realm.size());
	dpr->setDisconnectCause()->setValue(m_Data.m_DisconnectCause);

	if( DIAMETER_NO_ERR == dpr->Encode ( &msg->rawbyteArray ) )
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to Encode DPR\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to Encode DPR\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}


	Diameter_IO_Base *io = (initiator) ? m_Data.m_IOInitiator.get() : m_Data.m_IOResponder.get();


	if (m_TxMsgCollector.Send(msg, io, true) < 0) {
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to send DPR\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to send DPR\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::SendDPA(bool initiator,
		diameter_unsigned32_t rcode)
{
	/*
		5.4.2.  Disconnect-Peer-Answer

		The Disconnect-Peer-Answer (DPA), indicated by the Command-Code set
		to 282 and the Command Flags' 'R' bit cleared, is sent as a response
		to the Disconnect-Peer-Request message.  Upon receipt of this
		message, the transport connection is shutdown.

		Message Format

		<DPA>  ::= < Diameter Header: 282 >
		{ Result-Code }
		{ Origin-Host }
		{ Origin-Realm }
		[ Error-Message ]
	 * [ Failed-AVP ]

*/

	std::unique_ptr<DiameterMsg> msg(new DiameterMsg);

	ACE_OS::memset(&msg->hdr          , 0, sizeof(msg->hdr));
	ACE_OS::memset(&msg->rawbyteArray , 0, sizeof(msg->rawbyteArray));

	DiameterMsgHeader &h = msg->hdr;

	h.mVersion     = DIAMETER_PROTOCOL_VERSION;
	h.mMsgLen      = 0;
	h.mCmdFlg.rBit = DIAMETER_FLAG_CLR;
	h.mCmdFlg.pBit = DIAMETER_FLAG_CLR;
	h.mCmdFlg.eBit = DIAMETER_FLAG_CLR;
	h.mCmdCode     = DIAMETER_MSGCODE_DISCONNECT_PEER;
	h.mApplId      = DIAMETER_BASE_APPLICATION_ID;

	MsgIdTxMessage(*msg);

	std::unique_ptr < DisconnectPeerAnswer > dpa(new DisconnectPeerAnswer );

	dpa->getDiameterMsgHeader()->mVersion   = DIAMETER_PROTOCOL_VERSION;
	dpa->setCmdFlag(0);
	dpa->getDiameterMsgHeader()->mCmdCode   = DIAMETER_MSGCODE_DISCONNECT_PEER ;
	dpa->getDiameterMsgHeader()->mApplId    = DIAMETER_BASE_APPLICATION_ID;

	msg->hdr.mCmdCode  = DIAMETER_MSGCODE_DISCONNECT_PEER;
	msg->hdr.mApplId   = DIAMETER_BASE_APPLICATION_ID;
	dpa->getDiameterMsgHeader()->mHopByHopId = msg->hdr.mHopByHopId ;
	dpa->getDiameterMsgHeader()->mEndToEndId = msg->hdr.mEndToEndId ;

	dpa->setResultCode()->setValue(rcode);
	dpa->setOriginHost()->setValue((UINT8*)m_Data.m_HostEntry.m_Identity.c_str(), m_Data.m_HostEntry.m_Identity.size());
	dpa->setOriginRealm()->setValue((UINT8*)m_Data.m_HostEntry.m_Realm.c_str(), m_Data.m_HostEntry.m_Realm.size());

	if( DIAMETER_NO_ERR == dpa->Encode ( &msg->rawbyteArray ) )
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to Encode DPA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to Encode DPA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
	}

	Diameter_IO_Base *io = (initiator) ? m_Data.m_IOInitiator.get() :	m_Data.m_IOResponder.get();

	if (m_TxMsgCollector.Send(msg, io, true) < 0) 
	{
		AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Failed to send DPA\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}
	else
	{
		AAA_LOG((LM_INFO, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Success to send DPA\n", h.mHopByHopId, h.mEndToEndId, h.mCmdCode,    h.mCmdFlg.rBit));
	}

}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::Elect()
{
	/*
		5.6.4.  The Election Process

		The election is performed on the responder.  The responder compares
		the Origin-Host received in the CER sent by its peer with its own
		Origin-Host.  If the local Diameter entity's Origin-Host is higher
		than the peer's, a Win-Election event is issued locally.

		The comparison proceeds by considering the shorter OctetString to be
		padded with zeros so that it length is the same as the length of the
		longer, then performing an octet-by-octet unsigned comparison with
		the first octet being most significant.  Any remaining octets are
		assumed to have value 0x80.
		*/
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Election occurring ...\n"));

	std::string localHost = m_Data.m_HostEntry.m_Identity;
	std::string peerHost = m_Data.m_PeerCapabilities.m_Host;

	if (localHost.length() < peerHost.length()) {
		localHost += std::string(peerHost.length() - localHost.length(), char(0x08));
	}
	else if (localHost.length() > peerHost.length()) {
		peerHost += std::string(localHost.length() - peerHost.length(), char(0x08));
	}
	else if (localHost == peerHost) {
		// advertising the same hostname
		Cleanup();
		return;
	}
	for (unsigned int i=0; i<localHost.size(); i++) {
		if (localHost[i] == peerHost[i]) {
			continue;
		}
		else if (localHost[i] > peerHost[i]) {
			Notify(DIAMETER_PEER_EV_WIN_ELECTION);
			AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Local peer wins election\n"));
			return;
		}
		else {
			break;
		}
	}
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Peer (%s) wins election\n", peerHost.c_str()));
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::Cleanup(unsigned int flags, bool lstateFlag)
{
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Cleaning up ...\n"));
	DiameterPeerCapabilities &cap = m_Data.m_PeerCapabilities;

	cap.m_Host = "";
	cap.m_Realm = "";
	
	while (! cap.m_HostIpLst.empty()) {
		diameter_address_t *ip = cap.m_HostIpLst.front();
		cap.m_HostIpLst.pop_front();
		delete ip;
	}
	
	cap.m_VendorId = 0;
	cap.m_ProductName = "";
	cap.m_OriginStateId = 0;

	DiameterApplicationIdLst *idList[] = {
		&cap.m_SupportedVendorIdLst,
		&cap.m_AuthAppIdLst,
		&cap.m_AcctAppIdLst
	};
	for (unsigned int i=0;
			i<sizeof(idList)/sizeof(DiameterApplicationIdLst*);
			i++) {
		while (! idList[i]->empty()) {
			idList[i]->pop_front();
		}
	}

	while (! cap.m_VendorSpecificId.empty()) {
		DiameterVendorSpecificIdLst::iterator x =
			cap.m_VendorSpecificId.begin();
		cap.m_VendorSpecificId.pop_front();
	}
	
	cap.m_InbandSecurityId = 0;
	cap.m_FirmwareRevision = 0;

	StopReConnect();
	CancelTimer(DIAMETER_PEER_EV_TIMEOUT);
	if(m_Data.m_ToSendDWR == 1)
	{
		CancelTimer(DIAMETER_PEER_EV_WATCHDOG);
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Canceled Timer for WATCHDOG\n"));
	}
	CancelTimer(DIAMETER_PEER_CONNECT_ATTEMPT_TOUT);
	
	if (flags & CLEANUP_FSM) {
		AAA_StateMachineWithTimer<DiameterPeerStateMachine>::Stop();
	}

	if (flags & CLEANUP_IO_R) {
		DIAMETER_IO_GC().ScheduleForDeletion(std::move(m_Data.m_IOResponder));
	}
	if (flags & CLEANUP_IO_I) {
		DIAMETER_IO_GC().ScheduleForDeletion(std::move(m_Data.m_IOInitiator));
	}

	if ((flags & CLEANUP_FSM) && (!lstateFlag)) 
	{
		m_CurrentPeerEventParam->m_Msg.reset();
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Scheduling for deletion\n"));
		DIAMETER_IO_GC().ScheduleForDeletion(std::move(m_CurrentPeerEventParam->m_IO));
		AAA_StateMachineWithTimer<DiameterPeerStateMachine>::Start();
	}

	m_CleanupSignal.signal();
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION : Method overload to cleanup the state machine and IO objects
//               based on the flags passed.
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::Cleanup(unsigned int flags, bool lstateFlag, std::unique_ptr<Diameter_IO_Base> IO)
{
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Overloaded Cleaning up ...\n"));
	DiameterPeerCapabilities &cap = m_Data.m_PeerCapabilities;

	cap.m_Host = "";
	cap.m_Realm = "";
	
	while (! cap.m_HostIpLst.empty()) {
		diameter_address_t *ip = cap.m_HostIpLst.front();
		cap.m_HostIpLst.pop_front();
		delete ip;
	}
	
	cap.m_VendorId = 0;
	cap.m_ProductName = "";
	cap.m_OriginStateId = 0;

	DiameterApplicationIdLst *idList[] = {
		&cap.m_SupportedVendorIdLst,
		&cap.m_AuthAppIdLst,
		&cap.m_AcctAppIdLst
	};
	for (unsigned int i=0;
			i<sizeof(idList)/sizeof(DiameterApplicationIdLst*);
			i++) {
		while (! idList[i]->empty()) {
			idList[i]->pop_front();
		}
	}

	while (! cap.m_VendorSpecificId.empty()) {
		DiameterVendorSpecificIdLst::iterator x =
			cap.m_VendorSpecificId.begin();
		cap.m_VendorSpecificId.pop_front();
	}
	
	cap.m_InbandSecurityId = 0;
	cap.m_FirmwareRevision = 0;

	StopReConnect();
	CancelTimer(DIAMETER_PEER_EV_TIMEOUT);
	if(m_Data.m_ToSendDWR == 1)
	{
		CancelTimer(DIAMETER_PEER_EV_WATCHDOG);
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Canceled Timer for WATCHDOG\n"));
	}
	CancelTimer(DIAMETER_PEER_CONNECT_ATTEMPT_TOUT);
	
	if (flags & CLEANUP_FSM) {
		AAA_StateMachineWithTimer<DiameterPeerStateMachine>::Stop();
	}

	if (flags & CLEANUP_IO_R) {
		DIAMETER_IO_GC().ScheduleForDeletion(std::move(m_Data.m_IOResponder));
	}
	if (flags & CLEANUP_IO_I) {
		DIAMETER_IO_GC().ScheduleForDeletion(std::move(m_Data.m_IOInitiator));
	}
	if ((flags & CLEANUP_FSM) && (!lstateFlag)) 
	{
		m_CurrentPeerEventParam->m_Msg.reset();
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Scheduling for deletion\n"));
		DIAMETER_IO_GC().ScheduleForDeletion(std::move(IO));
		AAA_StateMachineWithTimer<DiameterPeerStateMachine>::Start();
	}

	m_CleanupSignal.signal();
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::DumpPeerCapabilities()
{
	DiameterPeerCapabilities &cap = m_Data.m_PeerCapabilities;

	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Peer Capabilities\n"));
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM|             Hostname : %s\n", cap.m_Host.c_str()));
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM|                Realm : %s\n", cap.m_Realm.c_str()));

	DiameterHostIpLst::iterator x = cap.m_HostIpLst.begin();
	for (; x != cap.m_HostIpLst.end(); x++) 
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM|              Host IP : type=%d, %s\n", (*x)->type, inet_ntoa(*((struct in_addr*)(*x)->value.c_str()))));
	}

	AAA_LOG((LM_DEBUG, "%T |PEER_FSM|             VendorId : %d\n", cap.m_VendorId));
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM|         Product Name : %s\n", cap.m_ProductName.c_str()));
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM|           Orig State : %d\n", cap.m_OriginStateId));

	DiameterApplicationIdLst *idList[] = {
		&cap.m_SupportedVendorIdLst,
		&cap.m_AuthAppIdLst,
		&cap.m_AcctAppIdLst
	};
	char *label[] = { (char *)"Supported Vendor Id",
		(char *)"Auth Application Id",
		(char *)"Acct Application Id" };
	for (unsigned int i=0;
			i < sizeof(idList)/sizeof(DiameterApplicationIdLst*);
			i++) {
		DiameterApplicationIdLst::iterator x = idList[i]->begin();
		for (; x != idList[i]->end(); x++) {
			if ((i > 0) && ((*x) == DIAMETER_RELAY_APPLICATION_ID)) {
				AAA_LOG((LM_DEBUG, "%T |PEER_FSM|  %s : Relay\n", label[i]));
			}
			else {
				AAA_LOG((LM_DEBUG, "%T |PEER_FSM|  %s : %d\n", label[i], *x));
			}
		}
	}

	DiameterVendorSpecificIdLst::iterator y = cap.m_VendorSpecificId.begin();
	for (; y != cap.m_VendorSpecificId.end(); y++) {
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM|  Vendor Specific Id : "));
		if ((*y).vendorId > 0) {
			AAA_LOG((LM_DEBUG, "%T |PEER_FSM|      Vendor=%d, ", (*y)));
		}
		else {
			AAA_LOG((LM_DEBUG, "%T |PEER_FSM|      Vendor=--- "));
		}
		if ((*y).authAppId > 0) {
			if ((*y).authAppId == DIAMETER_RELAY_APPLICATION_ID) {
				AAA_LOG((LM_DEBUG, "%T |PEER_FSM|	 Auth=Relay"));
			}
			else {
				AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Auth=%d ", (*y).authAppId));
			}
		}
		if ((*y).acctAppId > 0) {
			if ((*y).authAppId == DIAMETER_RELAY_APPLICATION_ID) {
				AAA_LOG((LM_DEBUG, "%T |PEER_FSM|	 Acct=Relay"));
			}
			else {
				AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Acct=%d ", (*y).acctAppId));
			}
		}
		AAA_LOG((LM_INFO, "%s\n", (((*y).authAppId == 0) && ((*y).acctAppId == 0)) ? "---" : ""));
	}

	AAA_LOG((LM_DEBUG, "%T |PEER_FSM|           Inband Sec : %d\n", cap.m_InbandSecurityId));
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM|         Firmware Ver : %d\n", cap.m_FirmwareRevision));
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
bool DiameterPeerStateMachine::ValidatePeer(diameter_unsigned32_t &rcode,
		std::string &message)
{
	/*
		5.3.  Capabilities Exchange

		When two Diameter peers establish a transport connection, they MUST
		exchange the Capabilities Exchange messages, as specified in the peer
		state machine (see Section 5.6).  This message allows the discovery
		of a peer's identity and its capabilities (protocol version number,
		supported Diameter applications, security mechanisms, etc.)

		The receiver only issues commands to its peers that have advertised
		support for the Diameter application that defines the command.  A
		Diameter node MUST cache the supported applications in order to
		ensure that unrecognized commands and/or AVPs are not unnecessarily
		sent to a peer.

		A receiver of a Capabilities-Exchange-Req (CER) message that does not
		have any applications in common with the sender MUST return a
		Capabilities-Exchange-Answer (CEA) with the Result-Code AVP set to
		AAA_NO_COMMON_APPLICATION, and SHOULD disconnect the transport
		layer connection.  Note that receiving a CER or CEA from a peer
		advertising itself as a Relay (see Section 2.4) MUST be interpreted
		as having common applications with the peer.
		*/
	bool found = false;
	DiameterPeerCapabilities &cap = m_Data.m_PeerCapabilities;

	DiameterApplicationIdLst *localIdList[] = {
		&DIAMETER_CFG_GENERAL()->authAppIdLst,
		&DIAMETER_CFG_GENERAL()->acctAppIdLst
	};
	DiameterApplicationIdLst *idList[] = {
		&cap.m_AuthAppIdLst,
		&cap.m_AcctAppIdLst
	};
	for (unsigned int i=0;
			i < sizeof(idList)/sizeof(DiameterApplicationIdLst*);
			i++) 
	{
		DiameterApplicationIdLst::iterator x = idList[i]->begin();

		for (; x != idList[i]->end(); x++) 
		{
			if (AAA_ApplicationIdLookup::Find(*x, localIdList,
						sizeof(localIdList)/sizeof(DiameterApplicationIdLst*))) 
			{
				found = true;
				break;
			}

			if (AAA_ApplicationIdLookup::Find
					(*x, DIAMETER_CFG_GENERAL()->vendorSpecificId)) 
			{
				found = true;
				break;
			}
		}
		if (found) 
		{
			break;
		}
	}

	if (! found) 
	{
		DiameterVendorSpecificIdLst::iterator i = cap.m_VendorSpecificId.begin();
		for (; i != cap.m_VendorSpecificId.end(); i++) {
			if (AAA_ApplicationIdLookup::Find((*i).authAppId, localIdList,
						sizeof(localIdList)/sizeof(DiameterApplicationIdLst*))) {
				found = true;
				break;
			}
			if (AAA_ApplicationIdLookup::Find((*i).acctAppId, localIdList,
						sizeof(localIdList)/sizeof(DiameterApplicationIdLst*))) {
				found = true;
				break;
			}
			if (AAA_ApplicationIdLookup::Find
					((*i).authAppId, DIAMETER_CFG_GENERAL()->vendorSpecificId)) {
				found = true;
				break;
			}
			if (AAA_ApplicationIdLookup::Find
					((*i).acctAppId, DIAMETER_CFG_GENERAL()->vendorSpecificId)) {
				found = true;
				break;
			}
		}
	}

	if (! found) 
	{
		rcode = AAA_NO_COMMON_APPLICATION;
		message = "No common application id";
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| No common application id ...\n",message.c_str()));
		return false;
	}

	/*
		Similarly, a receiver of a Capabilities-Exchange-Req (CER) message
		that does not have any security mechanisms in common with the sender
		MUST return a Capabilities-Exchange-Answer (CEA) with the Result-Code
		AVP set to AAA_NO_COMMON_SECURITY, and SHOULD disconnect the
		transport layer connection.
		*/
	// INTEROP FIXES
	if (m_Data.m_TLS != cap.m_InbandSecurityId) 
	{
		rcode = AAA_NO_COMMON_SECURITY;
		message = "No matching in-band security id";
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| No matching in-band security id ...\n",message.c_str()));
		return false;
	}

	/*
		The CER and CEA messages MUST NOT be proxied, redirected or relayed.

		Since the CER/CEA messages cannot be proxied, it is still possible
		that an upstream agent receives a message for which it has no
		available peers to handle the application that corresponds to the
		Command-Code.  In such instances, the 'E' bit is set in the answer

		message (see Section 7.) with the Result-Code AVP set to
		AAA_UNABLE_TO_DELIVER to inform the downstream to take action
		(e.g., re-routing request to an alternate peer).

		With the exception of the Capabilities-Exchange-Request message, a
		message of type Request that includes the Auth-Application-Id or
		Acct-Application-Id AVPs, or a message with an application-specific
		command code, MAY only be forwarded to a host that has explicitly
		advertised support for the application (or has advertised the Relay
		Application Identifier).
		*/
	rcode = AAA_SUCCESS;
	message = "Capabilities negotiation completed successfully";
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Capabilities negotiation completed successfully ...\n",message.c_str()));
	return true;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::MsgIdTxMessage(DiameterMsg &msg)
{
	std::string lLogText = LOG_DIAMETER_AVPS(msg);	

	if (msg.hdr.mCmdFlg.rBit)
	{
		diameter_unsigned32_t hopId = DIAMETER_HOPBYHOP_GEN()->Get();
		diameter_unsigned32_t endId = DIAMETER_ENDTOEND_GEN()->Get();

		m_Data.m_PeerCapabilities.m_MsgId.m_LastTxHopId = hopId;
		m_Data.m_PeerCapabilities.m_MsgId.m_LastTxEndId = endId;

		msg.hdr.mHopByHopId = hopId;
		msg.hdr.mEndToEndId = endId;
	}
	else
	{
		std::string lLogText = LOG_DIAMETER_AVPS(msg);
		if(m_Data.m_PeerCapabilities.m_MsgId.m_LastRxHopId != 0 )
		{
			msg.hdr.mHopByHopId = m_Data.m_PeerCapabilities.m_MsgId.m_LastRxHopId;
		}
		else
		{
			msg.hdr.mHopByHopId = 0;
			AAA_LOG((LM_INFO,"%T |PEER_FSM| %s Sending a peer message but Hop Id is empty",lLogText.c_str()));
		}

		if(m_Data.m_PeerCapabilities.m_MsgId.m_LastRxEndId != 0 )
		{
			msg.hdr.mEndToEndId = m_Data.m_PeerCapabilities.m_MsgId.m_LastRxEndId;
		}
		else
		{
			msg.hdr.mEndToEndId = 0;
			AAA_LOG((LM_INFO,"%T |PEER_FSM| %s Sending a peer message but End Id is empty",lLogText.c_str()));
		}

	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
bool DiameterPeerStateMachine::MsgIdRxMessage(DiameterMsg &msg)
{
	if (msg.hdr.mCmdFlg.rBit)
	{
		m_Data.m_PeerCapabilities.m_MsgId.m_LastRxHopId = (msg.hdr.mHopByHopId);
		m_Data.m_PeerCapabilities.m_MsgId.m_LastRxEndId = (msg.hdr.mEndToEndId);
		return (true);
	}
	else
	{
		return (true);
	}
	return (false);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::DoReConnect()
{
	if (DIAMETER_CFG_TRANSPORT()->reconnect_interval > 0) 
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Re-Connected to Peer: %s\n",this->Data().m_Identity.c_str()));
		ScheduleTimer(DIAMETER_PEER_EV_CONN_RETRY,
				DIAMETER_CFG_TRANSPORT()->reconnect_interval,
				0,
				DIAMETER_PEER_EV_CONN_RETRY);
	}
	else
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Re-Connect interval is Zero, Peer: %s\n",this->Data().m_Identity.c_str()));
	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION : Added by Abhishek to handle reconnect and print the Peer
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
/*void DiameterPeerStateMachine::DoReConnect(const std::string peername)
{
	if (DIAMETER_CFG_TRANSPORT()->reconnect_interval > 0) 
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Overloaded Re-Connected to Peer: %s\n",peername.c_str()));
		ScheduleTimer(DIAMETER_PEER_EV_CONN_RETRY,
				DIAMETER_CFG_TRANSPORT()->reconnect_interval,
				0,
				DIAMETER_PEER_EV_CONN_RETRY);
	}
	else
	{
		AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Overloaded Re-Connect interval is Zero, Peer: %s\n",peername.c_str()));
	}
}*/

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterPeerStateMachine::StopReConnect()
{
	AAA_LOG((LM_DEBUG, "%T |PEER_FSM| Re-Connect stopped for Peer : %s\n",this->Data().m_Identity.c_str()));
	CancelTimer(DIAMETER_PEER_EV_CONN_RETRY);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterPeerStateMachine::TransportProtocolInUse()
{
	return (m_Data.m_IOInitiator.get() != NULL) ?
		m_Data.m_IOInitiator->TransportProtocolInUse():
		m_Data.m_IOResponder->TransportProtocolInUse();
}
