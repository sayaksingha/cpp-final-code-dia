// @(#) $Id: diameter_cc_application.h,v 1.1.2.1.2.8 2024/05/15 13:03:29 mram Exp $
//---------------------------------------------------------------
// NAME : diameter_cc_application.h
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
#ifndef __CC_APPLICATION_H__
#define __CC_APPLICATION_H__


//class DiameterApplication;

#include "framework.h"
#include "diameter_api.h"
#include "diameter_cc_proxy_session.h"
#include "DCCA_Router.h"

/*
class DiameterCCApplication : public DiameterApplication 
{
	public:
		DiameterCCApplication(AAA_Task &task, char *cfgfile = NULL) : DiameterApplication(task, cfgfile)
	{
	}
};
*/

#define DCCA_DRA_ST_OPEN 7 

class DiameterGxProxySession : public DCCA_ProxyHandler, 
										 public DiameterCCProxySession , 
										 public DiameterGarbageCollectorAttribute
{
	public:
		DiameterGxProxySession(AAA_Task &task, int lModuleId);
		~DiameterGxProxySession()
		{
		};

		AAAReturnCode RequestMsg(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		AAAReturnCode AnswerMsg(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);

		AAAReturnCode ErrorMsg(DiameterMsg &msg, DiameterPeerEntry *source, DiameterPeerEntry *&dest);
		
		AAAReturnCode SendMsgAsync(std::unique_ptr<DiameterMsg> msg, DiameterPeerEntry *source, DiameterPeerEntry *dest, string rSession);
		
		AAAReturnCode SendNackMsgAsync(std::unique_ptr<DiameterMsg> msg, DiameterPeerEntry *source, DiameterPeerEntry *dest, string rSession);

		bool GetMessagefromDB(std::string& rSessionId, DiameterPeerEntry *&source, DiameterPeerEntry *&dest, unique_ptr<DiameterMsg> &rMsg);
		//bool UpdateDB(std::string& rSessionId, DiameterMsg *rMsg);
		bool UpdateDB(std::string& rSessionId, shared_ptr<DiameterMsg> rMsg);

		virtual DiameterGxProxySession* CreateInstance() = 0;

		//bool Reset(DiameterMsg  *msg);
		bool Reset(const string& sessionId, const int& appId);

		int SyncSessionData(SyncDccaProxySessionData &data);
		virtual void SyncSourceDest(DiameterPeerEntry *source, DiameterPeerEntry *dest) = 0;

	private:
		DiameterGxProxySession *m_Session; 
		ACE_Mutex m_EventCCFsmMtx;
};

///
/// Internal garbage collector definitions
///
typedef DiameterGarbageCollectorSingleton<DiameterGxProxySession> DiameterProxySession;

typedef ACE_Singleton<DiameterProxySession, ACE_Recursive_Thread_Mutex> DiameterProxySession_S;

#define DIAMETER_PROXY_SESSION_ROOT() (DiameterProxySession_S::instance())
#define DIAMETER_PROXY_SESSION()      (DiameterProxySession_S::instance()->Instance())


#endif
