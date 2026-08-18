// @(#) $Id: diameter_cc_proxy_fsm.h,v 1.1.2.1.2.14 2024/03/20 10:40:40 mrafi Exp $
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
#ifndef __CC_PROXY_FSM_H__
#define __CC_PROXY_FSM_H__

#include "framework.h"
#include "diameter_cc_parser.h"
#include "GxParser.h"
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

#define DIAMETER_DEC_SESSION_CNT( _AdditionalLog)\
DIAMETER_SESSION_INFO()->lock.lock();\
if(DIAMETER_SESSION_INFO()->currrentSessions > 0)\
	DIAMETER_SESSION_INFO()->currrentSessions--;\
	DIAMETER_SESSION_INFO()->lock.unlock();\
	AAA_LOG((LM_CRITICAL,"%T |CC_FSM| %s %s, Sessions:(%d/%d)\n",\
				lLogText.c_str(),\
				_AdditionalLog.c_str(),\
				unsigned(DIAMETER_SESSION_INFO()->currrentSessions),\
				DIAMETER_CFG_SESSION()->maxSessions));

/*
typedef enum {
     EvInitialRequest,
     EvInitialRequestSuccessful,
     EvInitialRequestUnsuccessful,

     EvUpdateRequest,
     EvUpdateRequestSuccessful,
     EvUpdateRequestUnsuccessful,

     EvTerminationRequest,
     EvTerminationRequestSuccessful,
     EvTerminationRequestUnsuccessful,

     EvEventRequest,
     EvEventRequestSuccessful,
     EvEventRequestUnsuccessful,

     EvRARequest,
     EvRARequestSuccessful,
     EvRARequestUnsuccessful,

     EvASRequest,
     EvASRequestSuccessful,
     EvASRequestUnsuccessful,

     EvTccExpired,

     EvSgDisconnect,
     EvSgSessionTimeout,
     EvSgTimeout
} DiameterCCProxyEvent;

 typedef struct {
	char sessionId[150];
	char sourceName[150];
	char destName[150];
	DiameterCCProxyEvent event;
	SyncOperation        op;
	int  						mModuleId;
} SyncDccaProxySessionData;
*/
class DiameterCCProxySession;

class DIAMETER_CC_PROXY_EXPORTS DiameterCCProxyStateMachine 
  : public AAA_StateMachineWithTimer<DiameterCCProxyStateMachine> 
{
 public:
  /// Constructor.
  DiameterCCProxyStateMachine(DiameterCCProxySession& s,
                               ACE_Reactor &reactor , int ); // TBC

  ~DiameterCCProxyStateMachine() 
  {
	 //cout<<"%T |CC_FSM| TBR PROXY FSM DESTRUCTOR sessionId:" << sessionId << "\n";
	 //AAA_LOG((LM_DEBUG,"%T |CC_FSM| TBR PROXY FSM DESTRUCTOR sessionId:%s\n",sessionId ));
    AAA_StateMachineWithTimer<DiameterCCProxyStateMachine>::Stop(); 
  }

/*  enum {
	  EvInitialRequest,
	  EvInitialRequestSuccessful,
	  EvInitialRequestUnsuccessful,

	  EvUpdateRequest,
	  EvUpdateRequestSuccessful,
	  EvUpdateRequestUnsuccessful,

	  EvTerminationRequest,
	  EvTerminationRequestSuccessful,
	  EvTerminationRequestUnsuccessful,

	  EvEventRequest,
	  EvEventRequestSuccessful,
	  EvEventRequestUnsuccessful,

	  EvTccExpired,

	  EvSgDisconnect,
	  EvSgSessionTimeout,
	  EvSgTimeout

  };*/

  /// Store an event and notify the session.
  inline void Notify(AAA_Event ev) { //throw (int) {
		Event(ev);
  }

  inline void Notify(AAA_Event ev,
		  DiameterMsg &msg, DiameterPeerEntry *source, 
		  DiameterPeerEntry *&dest) // throw (int) 
  {
	  AAA_MutexScopeLock guard(mMutex);
	  m_Msg  = &msg;
	  m_Src  = source;
	  m_Dest = &dest;
	  m_Dest_async = dest;
	  Event(ev);
  }

  virtual void Timeout(AAA_Event ev) {
    Notify(ev);
  }

  /// This is used for obtaining the reference to the proxy session
  /// object.
  inline DiameterCCProxySession& Session() { return session; }

  /// This is used for aborting the state machine.  Usually called
  /// when Notify() fails.
  virtual void Abort() = 0;

  virtual void ccInitialRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
  virtual void ccInitialRequestRtxReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
  virtual void ccInitialAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)  = 0;

  virtual void ccUpdateRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
  virtual void ccUpdateAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)  = 0;

  virtual void ccTerminateRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
  virtual void ccTerminateAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)  = 0;

  virtual void ccEventRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
  virtual void ccEventAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)  = 0;

  virtual void ccASRequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
  virtual void ccASAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)  = 0;

  virtual void ccRARequestReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) = 0;
  virtual void ccRAAnswerReceived(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest)  = 0;

  virtual void ccTccTimeExpired(string &lSessionId, int lApplId) = 0;

  /// Initial Request action.  
  bool InitialRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		ccInitialRequestReceived(msg, source, dest);
		source->Peg()->GeneratePeg(DiameterPeg::E_CCR_INITIAL_MSG);
		return true;
	};
  
  /// Initial Request action.  
  bool InitialRequestRtx(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		ccInitialRequestRtxReceived(msg, source, dest);
		source->Peg()->GeneratePeg(DiameterPeg::E_CCR_INITIAL_MSG);
		return true;
	};

  bool InitialAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
	  ccInitialAnswerReceived(msg, source, dest);
	  //source->Peg()->GeneratePeg(DiameterPeg::E_CCA_INITIAL_SUCCESS_MSG);
	  return true;
  };

  /// Update Request action.  
  bool UpdateRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
		ccUpdateRequestReceived(msg, source, dest);
		source->Peg()->GeneratePeg(DiameterPeg::E_CCR_UPDATE_MSG);
		return true;
  };

  bool UpdateAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
	  ccUpdateAnswerReceived(msg, source, dest);
	  //source->Peg()->GeneratePeg(DiameterPeg::E_CCA_UPDATE_SUCCESS_MSG);
	  return true;
  };

  /// Termination Request action.  
  bool TerminationRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
	  ccTerminateRequestReceived(msg, source, dest);
	  source->Peg()->GeneratePeg(DiameterPeg::E_CCR_TERMINATE_MSG);
	  return true;
  };

  bool TerminationAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
	  ccTerminateAnswerReceived(msg, source, dest);
	  //source->Peg()->GeneratePeg(DiameterPeg::E_CCA_TERMINATE_SUCCESS_MSG);
	  return true;
  };

  bool RejectRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
	  source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		std::string lLogText = LOG_DIAMETER_AVPS(*msg);
	  switch(msg->hdr.mApplId)
	  {
		  case AAA_Gx_APP_ID:
			{		
			  GX::CCAnswer* rsp = new GX::CCAnswer;
				
					
				//rsp->setHopByHopId(msg->hdr.mHopByHopId);
				//rsp->setEndToEndId(msg->hdr.mEndToEndId);
				//AAA_LOG((LM_ERROR,"%T |CC_FSM| %s Application-Id:%d\n",lLogText.c_str(),msg->hdr.mApplId));
				//msg->baseClass->setHopByHopId(msg->hdr.mHopByHopId);
				//msg->baseClass->setEndToEndId(msg->hdr.mEndToEndId);
				//msg->baseClass->setApplnId(msg->hdr.mApplId);
			  
			  rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(),(UINT32)msg->sessionId.length());
			  rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(),(UINT32)msg->destinationRealm.length());
			  rsp->setResultCode()->setValue(AAA_TOO_BUSY);	
			  msg->baseClass.reset(rsp);
			}
			  break;	 
		  case AAA_Ro_APP_ID:
			{
			  RO::CCAnswer* rsp = new RO::CCAnswer;	
			  rsp->setSessionId()->setValue((UINT8*)msg->sessionId.c_str(),msg->sessionId.length());
			  rsp->setOriginRealm()->setValue((UINT8*)msg->destinationRealm.c_str(),msg->destinationRealm.length());	
			  rsp->setResultCode()->setValue(AAA_TOO_BUSY);	
			  msg->baseClass.reset(rsp);	
			}
			  break;
		  default:
//			  std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
			  AAA_LOG((LM_ERROR,"%T |CC_FSM| %s Unsupported Application-Id:%d\n",lLogText.c_str(),msg->hdr.mApplId));
			  return false;
	  }
	  
	  msg->internalRspFlag   = true;	
	  msg->hdr.mCmdFlg.pBit  = DIAMETER_FLAG_SET;
	  msg->hdr.mCmdFlg.eBit  = DIAMETER_FLAG_SET;
	  msg->hdr.mCmdFlg.rBit  = DIAMETER_FLAG_CLR;
	  return true;	
  }	

  //virtual bool Reset(DiameterMsg *msg) {return true;};
  virtual bool Reset(const std::string& sessionId, const int& appId) {return true;};	

  // Event Request action.  
  bool EventRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
	  ccEventRequestReceived(msg, source, dest);
	  return true;
  };

  bool EventAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
	  ccEventAnswerReceived(msg, source, dest);
	  return true;
  };

 bool ASRequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
     ccASRequestReceived(msg, source, dest);
     return true;
  };

  bool ASAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
     ccASAnswerReceived(msg, source, dest);
     return true;
  };

 bool RARequest(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
     ccRARequestReceived(msg, source, dest);
     //source->Peg()->GeneratePeg(DiameterPeg::E_RAR_MSG);
     return true;
  };

  bool RAAnswer(DiameterMsg *msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) {
     ccRAAnswerReceived(msg, source, dest);
     return true;
  };

  inline void SendSyncSessionData(DiameterCCProxyStateMachine& sm, SyncOperation op, 
		  DiameterCCProxyEvent event, bool sessionTccExpiry = false);

	bool TccTimeExpired(string &lSessionId, int lApplId) {
		ccTccTimeExpired(lSessionId, lApplId);
		return true;
	}

 private:
  DiameterCCProxySession	&session;

 public:

  int 					mModuleId;
  DiameterMsg			*m_Msg = NULL;
  DiameterPeerEntry  *m_Src = NULL;
  DiameterPeerEntry  **m_Dest = NULL;
  DiameterPeerEntry  *m_Dest_async = NULL;
  string             sessionId = "";
  int 					appId;	
  bool					mInitialRecvFlg   = false;

  bool					mUpdateRecvFlg    = false; // Added for increase session count
  bool					mTerminateRecvFlg = false; //Added for increase session count
  shared_ptr<DiameterMsg> m_shr;
  ACE_Mutex 			mMutex;
  //std::string 			mSid;

};

#endif
