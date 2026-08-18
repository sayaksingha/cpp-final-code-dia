// @(#) $Id: aaa_peer_fsm.h,v 1.1.4.1.2.1.2.13 2024/05/15 13:08:41 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_peer_fsm.h
//
// COPYRIGHT
// TSS : - Copyright (C) 2001 Tayana Software Solution Pvt Ltd.,
//         All rights reserved. No part of this computer program
//         may be used or reproduced in any form by any
//         means without prior written permission of
//         Tayana Software Solution Pvt Ltd.
//
// DESCRIPTION
//
// Originated:
//----------------------------------------------------------------
#ifndef __AAA_PEER_FSM_H__
#define __AAA_PEER_FSM_H__

#include "aaa_peer_data.h"
///#include "DiaHandleMsg.h"

#define LOG(MSG)  AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d SId:%s %s \n",\
						         msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,\
									         msg->hdr.mCmdFlg.rBit,msg->sessionId.c_str(), MSG ) );\

typedef enum {
  DIAMETER_PEER_ST_CLOSED,
  DIAMETER_PEER_ST_WAIT_CONN_ACK,
  DIAMETER_PEER_ST_WAIT_I_CEA,
  DIAMETER_PEER_ST_WAIT_CONN_ACK_ELECT,
  DIAMETER_PEER_ST_WAIT_RETURNS,
  DIAMETER_PEER_ST_I_OPEN,
  DIAMETER_PEER_ST_R_OPEN,
  DIAMETER_PEER_ST_CLOSING
} DIAMETER_PEER_ST;

typedef enum {
  DIAMETER_PEER_EV_START,  
  DIAMETER_PEER_EV_STOP,
  DIAMETER_PEER_EV_TIMEOUT,  
  DIAMETER_PEER_EV_CONN_RETRY,  
  DIAMETER_PEER_EV_R_CONN_CER,  
  DIAMETER_PEER_EV_I_RCV_CONN_ACK,  
  DIAMETER_PEER_EV_I_RCV_CONN_NACK,
  DIAMETER_PEER_EV_R_RCV_CEA,  
  DIAMETER_PEER_EV_I_RCV_CEA,  
  DIAMETER_PEER_EV_I_PEER_DISC,  
  DIAMETER_PEER_EV_R_PEER_DISC,  
  DIAMETER_PEER_EV_I_RCV_NON_CEA,  
  DIAMETER_PEER_EV_WIN_ELECTION,  
  DIAMETER_PEER_EV_SEND_MESSAGE,  
  DIAMETER_PEER_EV_R_RCV_MESSAGE,  
  DIAMETER_PEER_EV_I_RCV_MESSAGE,  
  DIAMETER_PEER_EV_R_RCV_DWR,  
  DIAMETER_PEER_EV_I_RCV_DWR,
  DIAMETER_PEER_EV_R_RCV_DWA,  
  DIAMETER_PEER_EV_I_RCV_DWA,
  DIAMETER_PEER_EV_R_RCV_DPR,  
  DIAMETER_PEER_EV_I_RCV_DPR,
  DIAMETER_PEER_EV_R_RCV_CER,
  DIAMETER_PEER_EV_I_RCV_CER,
  DIAMETER_PEER_EV_R_RCV_DPA,
  DIAMETER_PEER_EV_I_RCV_DPA,
  DIAMETER_PEER_EV_WATCHDOG,
} DIAMETER_PEER_EV;

class DiameterPeerFsmException
{
   public:
      typedef enum {
          ALLOC_FAILURE = 0,
          INVALID_ID_TYPE,
      } ERROR_CODE;
    
   public:
      DiameterPeerFsmException(int code, std::string &desc) :
        m_Code(code), m_Description(desc) {
      }
      DiameterPeerFsmException(int code, const char* desc) :
        m_Code(code), m_Description(desc) {
      }
      int &Code() {
          return m_Code;
      }
      std::string &Description() {
          return m_Description;
      }

   private:
      int m_Code;
      std::string m_Description;
};

class DiameterPeerStateMachine;

class DiameterPeerR_ISendConnReq : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerR_AcceptSendCEA : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
      virtual void operator()(DiameterPeerStateMachine &fsm, std::unique_ptr<Diameter_IO_Base> m_IO, std::unique_ptr<DiameterMsg> m_Msg);
};

class DiameterPeerI_SendCER : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeer_ConnNack : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
      virtual void operator()(DiameterPeerStateMachine &fsm, std::unique_ptr<Diameter_IO_Base> m_IO, std::unique_ptr<DiameterMsg> m_Msg);
};

class DiameterPeer_Cleanup : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeer_ReConnect : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerR_Accept : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
      virtual void operator()(DiameterPeerStateMachine &fsm, std::unique_ptr<Diameter_IO_Base> m_IO,std::unique_ptr<DiameterMsg> m_Msg);
};

class DiameterPeer_Error : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeer_ProcessCEA : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerR_AcceptElect : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
      virtual void operator()(DiameterPeerStateMachine &fsm, std::unique_ptr<Diameter_IO_Base> m_IO,std::unique_ptr<DiameterMsg> m_Msg);
};

class DiameterPeer_Disconnect : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeer_DisconnectDPA : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerI_SendCERElect : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerR_SendCEA : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerR_SendCEAOpen : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerR_DisconnectResp : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerR_DisconnectIOpen : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerR_Reject : public AAA_Action<DiameterPeerStateMachine> {
   public:
   virtual void operator()(DiameterPeerStateMachine &fsm);
   virtual void operator()(DiameterPeerStateMachine &fsm, std::unique_ptr<Diameter_IO_Base> m_IO, std::unique_ptr<DiameterMsg> m_Msg);
};

class DiameterPeerI_DisconnectSendCEA : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerR_SendMessage : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeer_Process : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
		virtual void operator()(DiameterPeerStateMachine &fsm, std::unique_ptr<DiameterMsg> dMsg, std::unique_ptr<Diameter_IO_Base> m_IO);
};

class DiameterPeerProcessDWRSendDWA : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeer_ProcessDWA : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerI_SendMessage : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerI_SendDPR : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerR_SendDPR : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerI_SendDPADisconnect : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerR_SendDPADisconnect : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerI_SendCEA : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeer_Watchdog : public AAA_Action<DiameterPeerStateMachine> {
   public:
      virtual void operator()(DiameterPeerStateMachine &fsm);
};

class DiameterPeerStateTable : public AAA_StateTable<DiameterPeerStateMachine>
{
   public:
      DiameterPeerStateTable() {

        AddStateTableEntry(DIAMETER_PEER_ST_I_OPEN,
                           DIAMETER_PEER_EV_I_RCV_MESSAGE,
                           DIAMETER_PEER_ST_I_OPEN,
                           m_acProcess);

        AddStateTableEntry(DIAMETER_PEER_ST_R_OPEN,
                           DIAMETER_PEER_EV_R_RCV_MESSAGE,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acProcess);

        AddStateTableEntry(DIAMETER_PEER_ST_I_OPEN,
                           DIAMETER_PEER_EV_SEND_MESSAGE,
                           DIAMETER_PEER_ST_I_OPEN,
                           m_acISendMessage);

        AddStateTableEntry(DIAMETER_PEER_ST_R_OPEN,
                           DIAMETER_PEER_EV_SEND_MESSAGE,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acRSendMessage);

        AddStateTableEntry(DIAMETER_PEER_ST_I_OPEN,
                           DIAMETER_PEER_EV_I_RCV_DWR,
                           DIAMETER_PEER_ST_I_OPEN,
                           m_acProcessDWRSendDWA);

        AddStateTableEntry(DIAMETER_PEER_ST_I_OPEN,
                           DIAMETER_PEER_EV_I_RCV_DWA,
                           DIAMETER_PEER_ST_I_OPEN,
                           m_acProcessDWA);

        AddStateTableEntry(DIAMETER_PEER_ST_R_OPEN,
                           DIAMETER_PEER_EV_R_RCV_DWR,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acProcessDWRSendDWA);

        AddStateTableEntry(DIAMETER_PEER_ST_R_OPEN,
                           DIAMETER_PEER_EV_R_RCV_DWA,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acProcessDWA);

        // ------------- DIAMETER_PEER_ST_R_OPEN ----------------  
        AddStateTableEntry(DIAMETER_PEER_ST_R_OPEN,
                           DIAMETER_PEER_EV_R_CONN_CER,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acRReject);

        AddStateTableEntry(DIAMETER_PEER_ST_R_OPEN,
                           DIAMETER_PEER_EV_STOP,
                           DIAMETER_PEER_ST_CLOSING,
                           m_acRSendDPR);

        AddStateTableEntry(DIAMETER_PEER_ST_R_OPEN,
                           DIAMETER_PEER_EV_R_RCV_DPR,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acRSendDPADisconnect);

        AddStateTableEntry(DIAMETER_PEER_ST_R_OPEN,
                           DIAMETER_PEER_EV_R_PEER_DISC,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acDisconnect);

        AddStateTableEntry(DIAMETER_PEER_ST_R_OPEN,
                           DIAMETER_PEER_EV_R_RCV_CER,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acRSendCEAOpen);

        AddStateTableEntry(DIAMETER_PEER_ST_R_OPEN,
                           DIAMETER_PEER_EV_R_RCV_CEA,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acProcessCEA);

        AddStateTableEntry(DIAMETER_PEER_ST_R_OPEN,
                           DIAMETER_PEER_EV_WATCHDOG,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acWatchdog);

        // ------------- DIAMETER_PEER_ST_I_OPEN ----------------  

        AddStateTableEntry(DIAMETER_PEER_ST_I_OPEN,
                           DIAMETER_PEER_EV_R_CONN_CER,
                           DIAMETER_PEER_ST_I_OPEN,
                           m_acRReject);

        AddStateTableEntry(DIAMETER_PEER_ST_I_OPEN,
                           DIAMETER_PEER_EV_STOP,
                           DIAMETER_PEER_ST_CLOSING,
                           m_acISendDPR);

        AddStateTableEntry(DIAMETER_PEER_ST_I_OPEN,
                           DIAMETER_PEER_EV_I_RCV_DPR,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acISendDPADisconnect);

        AddStateTableEntry(DIAMETER_PEER_ST_I_OPEN,
                           DIAMETER_PEER_EV_I_PEER_DISC,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acDisconnect);

        AddStateTableEntry(DIAMETER_PEER_ST_I_OPEN,
                           DIAMETER_PEER_EV_I_RCV_CER,
                           DIAMETER_PEER_ST_I_OPEN,
                           m_acISendCEA);

        AddStateTableEntry(DIAMETER_PEER_ST_I_OPEN,
                           DIAMETER_PEER_EV_I_RCV_CEA,
                           DIAMETER_PEER_ST_I_OPEN,
                           m_acProcessCEA);

        AddStateTableEntry(DIAMETER_PEER_ST_I_OPEN,
                           DIAMETER_PEER_EV_WATCHDOG,
                           DIAMETER_PEER_ST_I_OPEN,
                           m_acWatchdog);

        // ------------- DIAMETER_PEER_ST_CLOSED ----------------
        AddStateTableEntry(DIAMETER_PEER_ST_CLOSED,
                           DIAMETER_PEER_EV_START,
                           DIAMETER_PEER_ST_WAIT_CONN_ACK,
                           m_acISendConnReq);

        AddStateTableEntry(DIAMETER_PEER_ST_CLOSED,    
                           DIAMETER_PEER_EV_R_CONN_CER,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acRAcceptSendCEA);

        




        AddStateTableEntry(DIAMETER_PEER_ST_CLOSED,
                           DIAMETER_PEER_EV_CONN_RETRY,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acRetry);

        AddWildcardStateTableEntry(DIAMETER_PEER_ST_CLOSED,
                                   DIAMETER_PEER_ST_CLOSED,
                                   m_acCleanup);

        // ------------- DIAMETER_PEER_ST_WAIT_CONN_ACK ----------------
        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_CONN_ACK,
                           DIAMETER_PEER_EV_I_RCV_CONN_ACK,
                           DIAMETER_PEER_ST_WAIT_I_CEA,
                           m_acISendCER);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_CONN_ACK,
                           DIAMETER_PEER_EV_I_RCV_CONN_NACK,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acConnNack);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_CONN_ACK,
                           DIAMETER_PEER_EV_R_CONN_CER,
                           DIAMETER_PEER_ST_WAIT_CONN_ACK_ELECT,
                           m_acRAccept);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_CONN_ACK,
                           DIAMETER_PEER_EV_TIMEOUT,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acError);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_CONN_ACK,
                           DIAMETER_PEER_EV_STOP,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acError);

        // ------------- DIAMETER_PEER_ST_WAIT_CEA ----------------  
        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_I_CEA,
                           DIAMETER_PEER_EV_I_RCV_CEA,
                           DIAMETER_PEER_ST_I_OPEN,
                           m_acProcessCEA);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_I_CEA,
                           DIAMETER_PEER_EV_R_CONN_CER,
                           DIAMETER_PEER_ST_WAIT_RETURNS,
                           m_acRAcceptElect);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_I_CEA,
                           DIAMETER_PEER_EV_I_PEER_DISC,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acDisconnect);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_I_CEA,
                           DIAMETER_PEER_EV_I_RCV_NON_CEA,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acError);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_I_CEA,
                           DIAMETER_PEER_EV_TIMEOUT,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acError);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_I_CEA,
                           DIAMETER_PEER_EV_STOP,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acError);

        // ------------- DIAMETER_PEER_ST_WAIT_CONN_ACK_ELECT ----------------
        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_CONN_ACK_ELECT,
                           DIAMETER_PEER_EV_I_RCV_CONN_ACK,
                           DIAMETER_PEER_ST_WAIT_RETURNS,
                           m_acISendCERElect);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_CONN_ACK_ELECT,
                           DIAMETER_PEER_EV_I_RCV_CONN_NACK,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acRSendCEA);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_CONN_ACK_ELECT,
                           DIAMETER_PEER_EV_R_PEER_DISC,
                           DIAMETER_PEER_ST_WAIT_CONN_ACK,
                           m_acRDisconnectResp);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_CONN_ACK_ELECT,
                           DIAMETER_PEER_EV_R_CONN_CER,
                           DIAMETER_PEER_ST_WAIT_CONN_ACK_ELECT,
                           m_acRReject);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_CONN_ACK_ELECT,
                           DIAMETER_PEER_EV_TIMEOUT,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acError);

        // ------------- DIAMETER_PEER_ST_WAIT_RETURNS ----------------  
        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_RETURNS,
                           DIAMETER_PEER_EV_WIN_ELECTION,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acIDisconnectSendCEA);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_RETURNS,
                           DIAMETER_PEER_EV_I_PEER_DISC,
                           DIAMETER_PEER_ST_R_OPEN,
                           m_acIDisconnectSendCEA);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_RETURNS,
                           DIAMETER_PEER_EV_I_RCV_CEA,
                           DIAMETER_PEER_ST_I_OPEN,
                           m_acRDisconnectIOpen);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_RETURNS,
                           DIAMETER_PEER_EV_R_PEER_DISC,
                           DIAMETER_PEER_ST_WAIT_I_CEA,
                           m_acRDisconnectResp);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_RETURNS,
                           DIAMETER_PEER_EV_R_CONN_CER,
                           DIAMETER_PEER_ST_WAIT_RETURNS,
                           m_acRReject);

        AddStateTableEntry(DIAMETER_PEER_ST_WAIT_RETURNS,
                           DIAMETER_PEER_EV_TIMEOUT,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acError);

        // ------------- DIAMETER_PEER_ST_CLOSING ----------------  
        AddStateTableEntry(DIAMETER_PEER_ST_CLOSING,
                           DIAMETER_PEER_EV_I_RCV_DPA,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acDisconnectDPA);

        AddStateTableEntry(DIAMETER_PEER_ST_CLOSING,
                           DIAMETER_PEER_EV_R_RCV_DPA,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acDisconnectDPA);

        AddStateTableEntry(DIAMETER_PEER_ST_CLOSING,
                           DIAMETER_PEER_EV_TIMEOUT,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acError);

        AddStateTableEntry(DIAMETER_PEER_ST_CLOSING,
                           DIAMETER_PEER_EV_I_PEER_DISC,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acDisconnect);

        AddStateTableEntry(DIAMETER_PEER_ST_CLOSING,
                           DIAMETER_PEER_EV_R_PEER_DISC,
                           DIAMETER_PEER_ST_CLOSED,
                           m_acDisconnect);

        AddWildcardStateTableEntry(DIAMETER_PEER_ST_CLOSING,
                                   DIAMETER_PEER_ST_CLOSING);

        InitialState(DIAMETER_PEER_ST_CLOSED);
      }

   private:
      DiameterPeerR_ISendConnReq       m_acISendConnReq;
      DiameterPeerR_AcceptSendCEA      m_acRAcceptSendCEA;
      DiameterPeerI_SendCER            m_acISendCER;
      DiameterPeer_ConnNack            m_acConnNack;
      DiameterPeer_Cleanup             m_acCleanup;
      DiameterPeer_ReConnect           m_acRetry;
      DiameterPeerR_Accept             m_acRAccept;
      DiameterPeer_Error               m_acError;
      DiameterPeer_ProcessCEA          m_acProcessCEA;
      DiameterPeerR_AcceptElect        m_acRAcceptElect;
      DiameterPeer_Disconnect          m_acDisconnect;
      DiameterPeer_DisconnectDPA       m_acDisconnectDPA;
      DiameterPeerI_SendCERElect       m_acISendCERElect;
      DiameterPeerR_SendCEA            m_acRSendCEA;
      DiameterPeerR_SendCEAOpen        m_acRSendCEAOpen;
      DiameterPeerR_DisconnectResp     m_acRDisconnectResp;
      DiameterPeerR_DisconnectIOpen    m_acRDisconnectIOpen;
      DiameterPeerR_Reject             m_acRReject;
      DiameterPeerI_DisconnectSendCEA  m_acIDisconnectSendCEA;
      DiameterPeerR_SendMessage        m_acRSendMessage;
      DiameterPeer_Process             m_acProcess;
      DiameterPeerProcessDWRSendDWA    m_acProcessDWRSendDWA;
      DiameterPeer_ProcessDWA          m_acProcessDWA;
      DiameterPeerI_SendDPR            m_acISendDPR;
      DiameterPeerR_SendDPR            m_acRSendDPR;
      DiameterPeerI_SendDPADisconnect  m_acISendDPADisconnect;
      DiameterPeerR_SendDPADisconnect  m_acRSendDPADisconnect;
      DiameterPeerI_SendMessage        m_acISendMessage;
      DiameterPeerI_SendCEA            m_acISendCEA;
      DiameterPeer_Watchdog            m_acWatchdog; 
};

class DiameterPeerStateMachine :
    public AAA_StateMachineWithTimer<DiameterPeerStateMachine>,
           AAA_Job
{
   public:
      DiameterPeerData &Data() {
         return m_Data;
      }
      AAA_GroupedJob &Job() {
          return m_GroupedJob;
      }

      virtual int Send(std::unique_ptr<DiameterMsg> &msg, bool consume = true) 
		{
          ///  If using ASYNC SEND
          ///  EnqueueSendMsg(msg);
          ///  Notify(DIAMETER_PEER_EV_SEND_MESSAGE);
          if (! AAA_StateMachineWithTimer
             <DiameterPeerStateMachine>::Running()) 
		    {
				 LOG("Cannot send message, statemachine not running");
             return (-1);
          }

          switch (state) 
			 {
              case DIAMETER_PEER_ST_I_OPEN:
				      return m_TxMsgCollector.Send(msg, m_Data.m_IOInitiator.get(), consume);
              case DIAMETER_PEER_ST_R_OPEN:
                  return m_TxMsgCollector.Send(msg, m_Data.m_IOResponder.get(), consume);
              default:
                   LOG("Discarding msg to send, peer state is not open");
                  break;
          }
          return (0);
      }


		virtual int Send(std::shared_ptr<DiameterMsg> &msg, bool consume = true)
		{
			if (! AAA_StateMachineWithTimer
					<DiameterPeerStateMachine>::Running())
			{
				LOG("Cannot send message, statemachine not running");
				return (-1);
			}

			switch (state)
			{
				case DIAMETER_PEER_ST_I_OPEN:
					return m_TxMsgCollector.SendMsg(msg, m_Data.m_IOInitiator.get(), consume);
				case DIAMETER_PEER_ST_R_OPEN:
					return m_TxMsgCollector.SendMsg(msg, m_Data.m_IOResponder.get(), consume);
				default:
					LOG("Discarding msg to send, peer state is not open");
					break;
			}
			return (0);

		}



		//DiaHandleMsg m_DiaHandleMsg;

	private: // Event Queue

		typedef struct 
		{
			AAA_Event m_Event;
			std::unique_ptr<DiameterMsg> m_Msg;
			std::unique_ptr<Diameter_IO_Base> m_IO;
		} DiameterPeerEventParam;

		AAA_ProtectedPtrQueue<DiameterPeerEventParam> m_EventQueue;
		std::unique_ptr<DiameterPeerEventParam> m_CurrentPeerEventParam;
		unsigned char mErrCount;
		bool          mTrafficFlag = false;

	public:

		virtual void Notify(AAA_Event event) 
		{
			if (AAA_StateMachineWithTimer
					<DiameterPeerStateMachine>::Running()) 
			{
				if(DIAMETER_CFG_TRANSPORT()->max_pending_backlog <=  Job().BacklogSize())
				{
					AAA_LOG((LM_ERROR, "%T |PEER_FSM| Event:%d ,pending Backlogs exceeded max limit:%d\n",
                     event,DIAMETER_CFG_TRANSPORT()->max_pending_backlog));
					//return;
				}
				

				std::unique_ptr<DiameterPeerEventParam> e(new DiameterPeerEventParam);
				e->m_Event = event;
				m_EventQueue.Enqueue(std::move(e));
				Schedule(this);

			}
			else {
				AAA_LOG((LM_ERROR, "%T |PEER_FSM| Event:%d not processed, statemachine not running\n", 
							event));
			}
		}

		virtual void Notify(AAA_Event event,
				std::unique_ptr<DiameterMsg> msg) {
			if (AAA_StateMachineWithTimer
					<DiameterPeerStateMachine>::Running()) {
			
				DiameterMsgQuery query(*msg);

				AAA_LOG((LM_ERROR, "%T |PEER_FSM| SId:%s Event:%d, pending backlogs max limit:%d, Pending:%d Sending \n",
							 msg->sessionId.c_str() , event,
							DIAMETER_CFG_TRANSPORT()->max_pending_backlog, Job().BacklogSize()));

				if(DIAMETER_CFG_TRANSPORT()->max_pending_backlog <= Job().BacklogSize() && query.IsRequest())
				{
					AAA_LOG((LM_ERROR, 
						"%T |PEER_FSM| SId:%s Event:%d, pending backlogs exceeded max limit:%d, sending NACK \n", 
						msg->sessionId.c_str() , event,DIAMETER_CFG_TRANSPORT()->max_pending_backlog));
					
               byteArray rawbyteArray;
					DiaHandleMsg::DecodeReqMsg(*msg);
               DiaHandleMsg::SetAnswerParam(*msg,AAA_TOO_BUSY);

               if (DIAMETER_NO_ERR == msg->baseClass->Encode( &rawbyteArray))
               {
                  AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d SId:%s Success to Encode Response Msg\n",
									msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit, msg->sessionId.c_str()));
               }
               else
               {
                  AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d SId:%s Failed to Encode Response Msg\n",
									msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit , msg->sessionId.c_str()));
                  return;
               }
					
					bool ret = false;
					switch (state)
					{
						case DIAMETER_PEER_ST_I_OPEN:
							ret = Data().m_IOInitiator->SendData(&rawbyteArray);
							break; 
						case DIAMETER_PEER_ST_R_OPEN:
							ret = Data().m_IOResponder->SendData(&rawbyteArray); 
							break;
						default:
							AAA_LOG((LM_ERROR, "%T |PEER_FSM| Discarding msg to send, peer state is not open State:%d\n",state));
							return;
					}

					if(ret)
					{
						AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d SId:%s Success to send ACK\n", 
									msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit, msg->sessionId.c_str()));
					}
					else
					{
						AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d SId:%s Failed to send NACK\n", 
									msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit,  msg->sessionId.c_str()));
					}

					PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
               return;
				}
				std::unique_ptr<DiameterPeerEventParam> e(new DiameterPeerEventParam);
				e->m_Event = event;
				e->m_Msg = std::move(msg);
				m_EventQueue.Enqueue(std::move(e));
				Schedule(this);
			}
			else {
				AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Event:%d not processed, statemachine not running\n", 
							msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode, msg->hdr.mCmdFlg.rBit, 
							event));
			}
		}
		virtual void Notify(AAA_Event event,
				std::unique_ptr<Diameter_IO_Base> io) {
			if (AAA_StateMachineWithTimer
					<DiameterPeerStateMachine>::Running()) 
			{
				if(DIAMETER_CFG_TRANSPORT()->max_pending_backlog <= Job().BacklogSize())
				{
					AAA_LOG((LM_ERROR, "%T |PEER_FSM| Event:%d, pending Backlogs exceeded max limit:%d\n",
								event,DIAMETER_CFG_TRANSPORT()->max_pending_backlog));
					//return;
				}
				std::unique_ptr<DiameterPeerEventParam> e(new DiameterPeerEventParam);
				e->m_Event = event;
				e->m_IO = std::move(io);
				m_EventQueue.Enqueue(std::move(e));
				Schedule(this);
			}
			else {
				AAA_LOG((LM_ERROR, "%T |PEER_FSM| Event:%d not processed, statemachine not running\n", 
							event));
			}
		}

		virtual void Notify(AAA_Event event,
				std::unique_ptr<DiameterMsg> msg,
				std::unique_ptr<Diameter_IO_Base> io) 
		{
			if (AAA_StateMachineWithTimer
					<DiameterPeerStateMachine>::Running()) {
				DiameterMsgQuery query(*msg);
				if(DIAMETER_CFG_TRANSPORT()->max_pending_backlog <= Job().BacklogSize() &&
									msg->hdr.mCmdCode != DIAMETER_MSGCODE_CAPABILITIES_EXCHG && query.IsRequest())
				{
					AAA_LOG((LM_ERROR, "%T |PEER_FSM| Event:%d, pending Backlogs exceeded max limit:%d, Sending ACK\n",
								event,DIAMETER_CFG_TRANSPORT()->max_pending_backlog));
				
					byteArray rawbyteArray;
					DiaHandleMsg::DecodeReqMsg(*msg);
					DiaHandleMsg::SetAnswerParam(*msg,AAA_TOO_BUSY);
					if (DIAMETER_NO_ERR == msg->baseClass->Encode( &rawbyteArray))
					{
						AAA_LOG((LM_DEBUG, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d SId:%s Success to Encode Response Msg\n", 
									msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode, msg->hdr.mCmdFlg.rBit , msg->sessionId.c_str()));
					}
					else
					{
						AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d SId:%s Failed to Encode Response Msg\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit, msg->sessionId.c_str()));
						return;
					}

					if(io->SendData(&rawbyteArray))
					{
						AAA_LOG((LM_DEBUG, "%T |TRANSPORT| HH:%d EE:%d CC:%d R:%d Success to send ACK\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
					}
					else
					{
						AAA_LOG((LM_ERROR, "%T |TRANSPORT| HH:%d EE:%d CC:%d R:%d Failed to send NACK\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
					}

					PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
					return;
				}
				std::unique_ptr<DiameterPeerEventParam> e(new DiameterPeerEventParam);
				e->m_Event = event;
				e->m_Msg = std::move(msg);
				e->m_IO = std::move(io);
				m_EventQueue.Enqueue(std::move(e));
				Schedule(this);
			}
			else {
				AAA_LOG((LM_ERROR, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d Event:%d not processed, statemachine not running\n", 
							msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode, msg->hdr.mCmdFlg.rBit, 
							event));
			}
		}

	protected: // Constructor/Destructor

		DiameterPeerStateMachine(AAA_Task &t, bool mTxStart = false) :
			AAA_StateMachineWithTimer<DiameterPeerStateMachine>
			(*this, m_StateTable, *t.reactor()),
			m_CleanupSignal(m_CleanupMutex),
			m_GroupedJob(t.Job()) 
	{
		if (mTxStart!=true)
			m_TxMsgCollector.Start();

		mErrCount = 0;
	}
		virtual ~DiameterPeerStateMachine() {
			if (state != DIAMETER_PEER_ST_CLOSED) 
			{
				m_CleanupSignal.wait();
			}
			AAA_StateMachine<DiameterPeerStateMachine>::Stop();
			m_TxMsgCollector.Stop();
		}

	protected: // Notifications
		virtual void Connected() {
		}
		virtual void Error(int resultCode) {
		}
		virtual void Disconnected(int cause) {
		}

	protected: // Job servicing
      std::mutex m_EventFsmMtxx;
//		ACE_Mutex m_EventFsmMtx;
		virtual int Serve() 
		{
//			AAA_MutexScopeLock guard(m_EventFsmMtx);
         std::unique_lock<std::mutex> lck (m_EventFsmMtxx);
			m_CurrentPeerEventParam = m_EventQueue.Dequeue();
			
         AAA_LOG((LM_INFO , "%T |PEER_FSM| Serve processing Msg\n" ));


			//DumpEvent(m_CurrentPeerEventParam->m_Event, (char *)"Pre-Event");
         if(m_CurrentPeerEventParam)
         {
            if ( m_CurrentPeerEventParam->m_Event == DIAMETER_PEER_EV_R_CONN_CER )    
            {
               std::unique_ptr<DiameterPeerEventParam> lCurrentPeerEventParam = std::move(m_CurrentPeerEventParam);
               try
               {
                  AAA_StateMachineWithTimer<DiameterPeerStateMachine>::Event(
                  lCurrentPeerEventParam->m_Event,
                  std::move(lCurrentPeerEventParam->m_IO),
                  std::move(lCurrentPeerEventParam->m_Msg)
                  );
               }
               catch (DiameterPeerFsmException &err)
               {
                   AAA_LOG((LM_INFO , "%T |PEER_FSM| Parallel processing Error[%d]:%s\n" ,  err.Code(),err.Description()));
               }
               //catch (...)
               catch(TssDiameterMsgException &err)
               {
                  AAA_LOG((LM_INFO , "%T |PEER_FSM| Parallel processing Error[%d]:%s\n" ,  err.getErrorCode(),err.getErrMessage()));
               }
               catch (std::exception& err)
               {
                  AAA_LOG((LM_INFO , "%T |PEER_FSM| Parallel processing Error[%d]\n" ,  err.what()));
               }
               //DumpEvent(lCurrentPeerEventParam->m_Event, (char *)"Post-Event");
               lCurrentPeerEventParam.reset();
               return (0);//TDS_FRAME_WORKRETURN;
            }
				if ( m_CurrentPeerEventParam->m_Event == DIAMETER_PEER_EV_I_RCV_MESSAGE ||
						m_CurrentPeerEventParam->m_Event == DIAMETER_PEER_EV_R_RCV_MESSAGE )
				{
					std::unique_ptr<DiameterPeerEventParam> lCurrentPeerEventParam = std::move(m_CurrentPeerEventParam);
					lck.unlock();
					try
					{
						AAA_StateMachineWithTimer<DiameterPeerStateMachine>::Event(
								lCurrentPeerEventParam->m_Event,
								std::move(lCurrentPeerEventParam->m_Msg),
								std::move(lCurrentPeerEventParam->m_IO)
								);
					}
					catch (DiameterPeerFsmException &err)
					{
						//log_err(TDSPEER002, "Parallel processing Error[" << err.Code() << "]:" << err.Description(),"");
                  AAA_LOG((LM_INFO , "%T |PEER_FSM| Parallel processing Error[[%s]\n" ,  err.Description()));
					}
					//catch (...)
					catch(TssDiameterMsgException &err)
					{
						//log_err(TDSPEER002, "Parallel processing Error[" <<err.getErrorCode() << "]:" <<err.getErrMessage(),"");
                   AAA_LOG((LM_INFO , "%T |PEER_FSM| Parallel processing Error[%d]\n" , err.getErrorCode() ));
					}
					catch (std::exception& err)
					{
						//log_err(TDSPEER002, "Parallel processing Error[" <<err.what() << "]" ,"");
                  AAA_LOG((LM_INFO , "%T |PEER_FSM| Parallel processing Error[%s]\n" ,err.what()  ));
					}
					DumpEvent(lCurrentPeerEventParam->m_Event, (char *)"Post-Event");
					lCurrentPeerEventParam.reset();
					return 1;
				}

            try
            {
               AAA_StateMachineWithTimer<DiameterPeerStateMachine>::Event(m_CurrentPeerEventParam->m_Event);
            }
            catch (DiameterPeerFsmException &err)
            {
               AAA_LOG((LM_INFO , "%T |PEER_FSM| Parallel processing Error[%d]:%s\n" ,  err.Code(),err.Description()));
            }
            catch(TssDiameterMsgException &err)
            {
               AAA_LOG((LM_INFO , "%T |PEER_FSM| Parallel processing Error[%d]:%s\n" ,  err.getErrorCode(),err.getErrMessage()));
            }
            catch (std::exception& e)
            {
               AAA_LOG((LM_INFO , "%T |PEER_FSM| Parallel processing Error[%d]\n" ,  e.what()));
            }          
            //DumpEvent(m_CurrentPeerEventParam->m_Event, (char *)"Post-Event");
            m_CurrentPeerEventParam.reset();

         }         
         else
			{
            try 
            {
               AAA_StateMachineWithTimer
                  <DiameterPeerStateMachine>::Event
                  (m_CurrentPeerEventParam->m_Event);
            }
            catch (DiameterPeerFsmException &err) 
            {
               AAA_LOG((LM_ERROR, "%T |PEER_FSM| Error[%d]: %s\n",
                        err.Code(), err.Description().c_str()));
            }
            //catch (...) 
            catch(TssDiameterMsgException &err)
            {
               AAA_LOG((LM_ERROR, "%T |PEER_FSM| error[%d]: %s\n", err.getErrorCode(), err.getErrMessage()));
            }
            catch (std::exception& e) 
            {
               AAA_LOG((LM_ERROR, "%T |PEER_FSM| error:%s\n",e.what()));
            }
			//DumpEvent(m_CurrentPeerEventParam->m_Event, (char *)"Post-Event");
			m_CurrentPeerEventParam.reset();
         }



			return (0);
		}

		virtual int Schedule(AAA_Job* job, size_t backlogSize = 1) 
		{
			if (! AAA_StateMachineWithTimer
					<DiameterPeerStateMachine>::Running()) {
				return (-1);
			}
			return m_GroupedJob.Schedule(job, backlogSize);
		}

		virtual void Timeout(AAA_Event ev) 
		{
			Notify(ev);
		}
	public:
		DiameterPeerData &PeerData() {
			return m_Data;
		}

		unsigned char& ErrorCount()
		{
			return mErrCount;
		}

		bool& TrafficFlag()
		{
			return mTrafficFlag;
		}


		std::string  &PeerName() {
			return m_TxMsgCollector.PeerName();
		}

	protected: // Capabilities exchange

		virtual void SendCER();
		virtual void SendCEA(diameter_unsigned32_t rcode,
			std::string &message);
      virtual void SendCEA(diameter_unsigned32_t rcode,
         std::string &message, Diameter_IO_Base* io);//std::unique_ptr<Diameter_IO_Base> io);

		void DisassembleCER(DiameterMsg &msg);
		void DisassembleCEA(DiameterMsg &msg , diameter_unsigned32_t &rcode, std::string &message );

      bool ValidatePeer(diameter_unsigned32_t &rcode, std::string &message);

   protected: // Watchdog

      virtual void SendDWR();
      virtual void SendDWA(diameter_unsigned32_t rcode, std::string &message);

      void DisassembleDWR(DiameterMsg &msg);
		void DisassembleDWA(DiameterMsg &msg, diameter_unsigned32_t &rCode, std::string &rErrorMsg);

   protected: // Disconnection

      virtual void SendDPR(bool initiator);
      virtual void SendDPA(bool initiator, diameter_unsigned32_t rcode);

      void DisassembleDPR(DiameterMsg &msg, diameter_unsigned32_t &cause);
		void DisassembleDPA(DiameterMsg &msg, diameter_unsigned32_t &rCode, std::string &rErrorMsg);

   protected: // Message Id's

      void MsgIdTxMessage(DiameterMsg &msg);
      bool MsgIdRxMessage(DiameterMsg &msg);

   protected:  // Re-connection logic

      void DoReConnect();
      void StopReConnect();

   protected: // Update of peer SCTP addresses

      int TransportProtocolInUse();

   protected: // Message transmission thread
      DiameterTxMsgCollector m_TxMsgCollector;

   protected: // Auxillary

      void Elect();

      typedef enum {
          CLEANUP_IO_I = 0x00000001,
          CLEANUP_IO_R = 0x00000002,
          CLEANUP_FSM  = 0x00000004,
          CLEANUP_ALL  = 0xffffffff
      } CLEANUP_FLG;

      ACE_Mutex m_CleanupMutex;
      ACE_Condition<ACE_Mutex> m_CleanupSignal;

      virtual void Cleanup(unsigned int flags = CLEANUP_ALL, bool lStateflag=false);
      virtual void Cleanup(unsigned int flags, bool lStateflag, std::unique_ptr<Diameter_IO_Base> m_IO );

   protected:

      void DumpPeerCapabilities();
      void DumpEvent(AAA_Event ev, char *prefix) {
#if AAA_FSM_EVENT_DEBUG
          static char *evStrTable[] = { "DIAMETER_PEER_EV_START",  
                                        "DIAMETER_PEER_EV_STOP",
                                        "DIAMETER_PEER_EV_TIMEOUT",  
                                        "DIAMETER_PEER_EV_CONN_RETRY",  
                                        "DIAMETER_PEER_EV_R_CONN_CER",  
                                        "DIAMETER_PEER_EV_I_RCV_CONN_ACK",  
                                        "DIAMETER_PEER_EV_I_RCV_CONN_NACK",
                                        "DIAMETER_PEER_EV_R_RCV_CEA",  
                                        "DIAMETER_PEER_EV_I_RCV_CEA",  
                                        "DIAMETER_PEER_EV_I_PEER_DISC",  
                                        "DIAMETER_PEER_EV_R_PEER_DISC",  
                                        "DIAMETER_PEER_EV_I_RCV_NON_CEA",  
                                        "DIAMETER_PEER_EV_WIN_ELECTION",  
                                        "DIAMETER_PEER_EV_SEND_MESSAGE",  
                                        "DIAMETER_PEER_EV_R_RCV_MESSAGE",  
                                        "DIAMETER_PEER_EV_I_RCV_MESSAGE",  
                                        "DIAMETER_PEER_EV_R_RCV_DWR",  
                                        "DIAMETER_PEER_EV_I_RCV_DWR",
                                        "DIAMETER_PEER_EV_R_RCV_DWA",  
                                        "DIAMETER_PEER_EV_I_RCV_DWA",
                                        "DIAMETER_PEER_EV_R_RCV_DPR",  
                                        "DIAMETER_PEER_EV_I_RCV_DPR",
                                        "DIAMETER_PEER_EV_R_RCV_CER",
                                        "DIAMETER_PEER_EV_I_RCV_CER",
                                        "DIAMETER_PEER_EV_R_RCV_DPA",
                                        "DIAMETER_PEER_EV_I_RCV_DPA",
                                        "DIAMETER_PEER_EV_WATCHDOG"
          };
          static char *stStrTable[] = { "DIAMETER_PEER_ST_CLOSED",
                                        "DIAMETER_PEER_ST_WAIT_CONN_ACK",
                                        "DIAMETER_PEER_ST_WAIT_I_CEA",
                                        "DIAMETER_PEER_ST_WAIT_CONN_ACK_ELECT",
                                        "DIAMETER_PEER_ST_WAIT_RETURNS",
                                        "DIAMETER_PEER_ST_I_OPEN",
                                        "DIAMETER_PEER_ST_R_OPEN",
                                        "DIAMETER_PEER_ST_CLOSING"
          };
          AAA_LOG((LM_ERROR, "%T |PEER_FSM| EVENT DEBUG [state=%s, event=%s]: %s\n",
                    stStrTable[state], evStrTable[ev], prefix));
#endif // AAA_FSM_EVENT_DEBUG
      }

    public:
      friend class DiameterPeerR_AcceptSendCEA;
      friend class DiameterPeerI_SendCER;
      friend class DiameterPeer_Cleanup;
      friend class DiameterPeer_ConnNack;
      friend class DiameterPeerR_Accept;
      friend class DiameterPeer_Error;
      friend class DiameterPeer_ReConnect;
      friend class DiameterPeer_ProcessCEA;
      friend class DiameterPeerR_AcceptElect;
      friend class DiameterPeer_Disconnect;
      friend class DiameterPeer_DisconnectDPA;
      friend class DiameterPeerI_SendCERElect;
      friend class DiameterPeerR_SendCEA;
      friend class DiameterPeerR_SendCEAOpen;
      friend class DiameterPeerR_DisconnectResp;
      friend class DiameterPeerR_DisconnectIOpen;
      friend class DiameterPeerR_Reject;
      friend class DiameterPeerI_DisconnectSendCEA;
      friend class DiameterPeerR_SendMessage;
      friend class DiameterPeer_Process;
      friend class DiameterPeerProcessDWRSendDWA;
      friend class DiameterPeer_ProcessDWA;
      friend class DiameterPeerI_SendDPR;
      friend class DiameterPeerR_SendDPR;
      friend class DiameterPeerI_SendDPADisconnect;
      friend class DiameterPeerR_SendDPADisconnect;
      friend class DiameterPeerI_SendMessage;
      friend class DiameterPeerI_SendCEA;
      friend class DiameterPeer_Watchdog;

   private:

      AAA_GroupedJob &m_GroupedJob;
      DiameterPeerData m_Data;
      static DiameterPeerStateTable m_StateTable;
};

#endif /* __AAA_PEER_FSM_H__ */
