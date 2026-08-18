// @(#) $Id: diameter_cc_proxy_session.h,v 1.1.2.1.2.8 2024/03/20 10:41:38 mrafi Exp $
//---------------------------------------------------------------
// NAME : diameter_cc_proxy_session.h
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
#ifndef __CC_PROXY_SESSION_H__
#define __CC_PROXY_SESSION_H__
#include <string>
#include <list>
#include "ace/Synch.h"
#include "diameter_api.h"
#include "diameter_cc_proxy_fsm.h"
#include "diameter_cc_proxy_rx_fsm.h"
#include "diameter_cc_proxy_sy_fsm.h"
#include "diameter_cc_proxy_s6a_fsm.h"
#include "diameter_cc_proxy_slh_fsm.h"
#include "diameter_cc_proxy_sd_fsm.h"
#include "diameter_cc_proxy_cx_fsm.h"
#include "diameter_cc_parser.h"
#include "diameter_cc_proxy_sh_fsm.h"
class DiameterGxProxySession;
class DiameterCCProxySessionSyncHdlr;

class DIAMETER_CC_PROXY_EXPORTS DiameterCCProxySession : public AAA_JobData,
															public DiameterCCProxyStateMachine,
															public DiameterRxProxyStateMachine,
															public DiameterSyProxyStateMachine, 
															public DiameterS6aProxyStateMachine,
															public DiameterSlhProxyStateMachine,
															public DiameterSdProxyStateMachine,
											                              public DiameterShProxyStateMachine,
														       public DiameterCxProxyStateMachine

{
public:
	// Constuctor.
	DiameterCCProxySession(AAA_Task &task, int moduleId);

	// Destructor.
	~DiameterCCProxySession()
	{
	}

	void RxRequest(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest) __attribute__((optimize(0)));

	void RxAnswer(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
	// Enhanced method
	void ProcessSyAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText);
	void ProcessRxAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText);
	void ProcessS6aAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText);
	void ProcessSlhAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText);
// new addition 07-07-26       
       	void ProcessSdAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText);
        void ProcessShAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText);
        void ProcessCxAppAnswers(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest, const std::string &logText);

	void HandleRxResult(UINT32 resultCode, DiameterRxProxyEvent successEvent, DiameterRxProxyEvent failEvent,
						DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
						const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg);
	void HandleCCResult(UINT32 resultCode, DiameterCCProxyEvent successEvent, DiameterCCProxyEvent failEvent,
						DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
						const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg);
	void HandleSyResult(UINT32 resultCode, DiameterSyProxyEvent successEvent, DiameterSyProxyEvent failEvent,
						DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
						const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg);
	void HandleS6aResult(UINT32 resultCode, DiameterS6aProxyEvent successEvent, DiameterS6aProxyEvent failEvent,
						DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,
						const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg);
	void HandleSlhResult(UINT32 resultCode, DiameterSlhProxyEvent successEvent, DiameterSlhProxyEvent failEvent,DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg);
   
	void HandleSdResult(UINT32 resultCode, DiameterSdProxyEvent successEvent, DiameterSdProxyEvent failEvent,DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg);
        void HandleShResult(UINT32 resultCode, DiameterShProxyEvent successEvent, DiameterShProxyEvent failEvent,DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg);	
	void HandleCxResult(UINT32 resultCode, DiameterCxProxyEvent successEvent, DiameterCxProxyEvent failEvent,DiameterPeerEntry *source, DiameterMsg &msg, DiameterPeerEntry *&dest,const std::string &logText, DiameterPeg::E_DccaAction successPeg, DiameterPeg::E_DccaAction failPeg);


	template <typename Primary, typename Fallback = void>
	UINT32 GetResultCode(DiameterMsg &msg);

	void RxError(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

	void Start(); // throw (AAA_Error);

	void Abort() {}

	// int SyncSessionData(SyncDccaProxySessionData &data);

	int GetSyncSessionData(SyncDccaProxySessionData &data);

	void RegisterProxySyncSession(DiameterCCProxySessionSyncHdlr &handler);

	void RemoveProxySyncSession();

	virtual void SyncSourceDest(DiameterPeerEntry *source, DiameterPeerEntry *dest) {}

	inline DiameterCCProxySessionSyncHdlr *SyncSessionHdlr() { return m_SyncSessionHdlr; }

private:
	static DiameterCCProxySessionSyncHdlr *m_SyncSessionHdlr;
};

class DIAMETER_CC_PROXY_EXPORTS DiameterCCProxySessionSyncHdlr : public AAA_ProxySessionSyncHdlr
{
public:
	void RegisterGxProxySession(DiameterGxProxySession *session);

	void RemoveGxProxySession();

	virtual int SendSyncData(SyncDccaProxySessionData &data) { return (0); }

	virtual int GetSyncData(SyncDccaProxySessionData &data) { return (0); }

	virtual int RemoveTimeoutData(SyncDccaProxySessionData &data) { return (0); }

	int RecvSyncData(SyncDccaProxySessionData &data);

private:
	static DiameterGxProxySession *m_Session;
};

#endif
