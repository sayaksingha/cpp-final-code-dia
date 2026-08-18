// @(#) $Id: diameter_cc_proxy_rx_fsm.h,v 1.1.2.2 2024/03/20 10:41:04 mrafi Exp $
//---------------------------------------------------------------
// NAME : diameter_cc_proxy_fsm.h
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
#ifndef __CC_PROXY_RX_FSM_H__
#define __CC_PROXY_RX_FSM_H__

#include "framework.h"
#include "diameter_cc_parser.h"
#include "RxParser.h"
#include "DCCA_Header.h"

#ifdef WIN32
#if defined(DIAMETER_CC_PROXY_EXPORT)
#define DIAMETER_CC_PROXY_EXPORTS __declspec(dllexport)
#else
#define DIAMETER_CC_PROXY_EXPORTS __declspec(dllimport)
#endif
#else
#define DIAMETER_CC_PROXY_EXPORTS
#define DIAMETER_CC_PROXY_EXPORTS
#endif

class DiameterCCProxySession;

class DIAMETER_CC_PROXY_EXPORTS DiameterRxProxyStateMachine
    : public AAA_StateMachineWithTimer<DiameterRxProxyStateMachine>
{
public:
   /// Constructor.
   DiameterRxProxyStateMachine(DiameterCCProxySession &s,
                               ACE_Reactor &reactor, int); // TBC

   ~DiameterRxProxyStateMachine()
   {
      AAA_StateMachineWithTimer<DiameterRxProxyStateMachine>::Stop();
   }

   /// Store an event and notify the session.
   inline void RxNotify(AAA_Event ev)
   {
      Event(ev);
   }

   inline void RxNotify(AAA_Event ev,
                        DiameterMsg &msg, DiameterPeerEntry *source,
                        DiameterPeerEntry *&dest) // throw (int)
   {
      AAA_MutexScopeLock guard(mMutexRx);
      m_MsgRx = &msg;
      m_SrcRx = source;
      m_DestRx = &dest;
      m_Dest_asyncRx = dest;
      Event(ev);
   }

   virtual void Timeout(AAA_Event ev)
   {
      RxNotify(ev);
   }

   /// This is used for obtaining the reference to the proxy session
   /// object.
   inline DiameterCCProxySession &RxSession() { return sessionRx; }

   /// This is used for aborting the state machine.  Usually called
   /// when Notify() fails.
   virtual void Abort() = 0;

   virtual void ccASRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void ccASAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   virtual void ccRARequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void ccRAAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   virtual void ccAARequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void ccAAAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   virtual void ccSTRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
   virtual void ccSTAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;

   bool RejectRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
      source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
      std::string lLogText = LOG_DIAMETER_AVPS(*msg);
      switch (msg->hdr.mApplId)
      {
      case AAA_Rx_APP_ID:
      {
         RX::AAAnswer *rsp = new RX::AAAnswer;
         rsp->setSessionId()->setValue((UINT8 *)msg->sessionId.c_str(), msg->sessionId.length());
         rsp->setOriginRealm()->setValue((UINT8 *)msg->destinationRealm.c_str(), msg->destinationRealm.length());
         rsp->setResultCode()->setValue(AAA_TOO_BUSY);
         msg->baseClass.reset(rsp);
      }
      default:
         AAA_LOG((LM_ERROR, "%T |CC_FSM| %s Unsupported Application-Id:%d\n", lLogText.c_str(), msg->hdr.mApplId));
         return false;
      }

      msg->internalRspFlag = true;
      msg->hdr.mCmdFlg.pBit = DIAMETER_FLAG_SET;
      msg->hdr.mCmdFlg.eBit = DIAMETER_FLAG_SET;
      msg->hdr.mCmdFlg.rBit = DIAMETER_FLAG_CLR;
      return true;
   }

   virtual bool Reset(const std::string &sessionId, const int &appId) { return true; };

   bool AARequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
      ccAARequestReceived(msg, source, dest);
      return true;
   };

   bool AAAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
      ccAAAnswerReceived(msg, source, dest);
      return true;
   };

   bool STRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
      ccSTRequestReceived(msg, source, dest);
      return true;
   };

   bool STAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
      ccSTAnswerReceived(msg, source, dest);
      return true;
   };

   bool ASRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
      ccASRequestReceived(msg, source, dest);
      return true;
   };

   bool ASAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
      //   ccASAnswerReceived(msg, source, dest); Not Requried...
      return true;
   };

   bool RARequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
      ccRARequestReceived(msg, source, dest);
      return true;
   };

   bool RAAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)
   {
      //   ccRAAnswerReceived(msg, source, dest); Not Required...
      return true;
   };

   inline void SendSyncSessionDataRx(DiameterRxProxyStateMachine &sm, SyncOperation op,
                                     DiameterRxProxyEvent event, bool sessionTccExpiry = false);

private:
   DiameterCCProxySession &sessionRx;

public:
   int mModuleIdRx;
   DiameterMsg *m_MsgRx = NULL;
   DiameterPeerEntry *m_SrcRx = NULL;
   DiameterPeerEntry **m_DestRx = NULL;
   DiameterPeerEntry *m_Dest_asyncRx = NULL;
   string sessionIdRx = "";
   int appIdRx;

   //shared_ptr<DiameterMsg> m_shrRx;
   ACE_Mutex mMutexRx;
};

//========================================================================
// To Cancel Timer
//========================================================================
inline void CancelTccTimer(DiameterRxProxyStateMachine &sm)
{
   sm.CancelTimer(DiameterRxProxyEvent::EvTccExpiredRx);
}

//========================================================================
// To Start Timer
//========================================================================
inline void StartTccTimer(DiameterRxProxyStateMachine &sm)
{
   sm.ScheduleTimer(
       DiameterRxProxyEvent::EvTccExpiredRx,
       DIAMETER_CFG_ACCT_SESSION()->sessionTm,
       0,
       DiameterRxProxyEvent::EvTccExpiredRx);
}

#endif
