// @(#) $Id: aaa_session_auth_client_fsm.h,v 1.1.2.1.2.2 2024/05/15 13:10:19 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_session_auth_client_fsm.h
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
#ifndef __AAA_SESSION_AUTH_CLIENT_FSM_H__
#define __AAA_SESSION_AUTH_CLIENT_FSM_H__

#include "aaa_session_auth_fsm.h"

class DIAMETERBASEPROTOCOL_EXPORT DiameterAuthSessionClientStateMachine :
	public DiameterAuthSessionStateMachine<DiameterAuthSessionClientStateMachine>
{  
	public:
		DiameterAuthSessionClientStateMachine(AAA_Task &t,
				DiameterAuthSession &a);
		virtual ~DiameterAuthSessionClientStateMachine() {
		}    

		void TxSTR(diameter_unsigned32_t cause);
		void TxASA(diameter_unsigned32_t rcode);
		void TxRAA(diameter_unsigned32_t rcode);
		void RxASR(DiameterMsg &msg);
		void RxSTA(DiameterMsg &msg);
		void RxRAR(DiameterMsg &msg);
};

class DiameterSessAuthClient_TxSSAR : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			std::unique_ptr<DiameterMsg> msg = std::move(fsm.PendingMsg());
			fsm.Session().TxDelivery(std::move(msg));
		}
};

class DiameterSessAuthClient_TxSSAR_Discard : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			std::unique_ptr<DiameterMsg> msg = std::move(fsm.PendingMsg());
			AAA_LOG((LM_INFO, "%T |SESSION| Message sent in invalid session state, discarding\n"));
			DiameterMsgHeaderDump::Dump(*msg);
		}
};

class DiameterSessAuthClient_RxSSA : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			std::unique_ptr<DiameterMsg> msg = std::move(fsm.PendingMsg());
			fsm.Session().RxDelivery(std::move(msg));

		}
};

class DiameterSessAuthClient_RxSSAA_Discard : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			std::unique_ptr<DiameterMsg> msg = std::move(fsm.PendingMsg());
			AAA_LOG((LM_INFO, "%T |SESSION| Message received in invalid session state, discarding\n"));
			DiameterMsgHeaderDump::Dump(*msg);
		}
};

class DiameterSessAuthClient_RxSSAA_GrantAccess : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.CancelAllTimer();
			if (fsm.Attributes().AuthSessionState() == 
					DIAMETER_SESSION_STATE_MAINTAINED) {
				fsm.ScheduleTimer(DIAMETER_SESSION_AUTH_EV_SESSION_TOUT_ST,
						fsm.Attributes().SessionTimeout(),
						0, DIAMETER_TIMER_TYPE_SESSION);
				fsm.ScheduleTimer(DIAMETER_SESSION_AUTH_EV_LIFETIME_TOUT,
						fsm.Attributes().AuthLifetime() +
						fsm.Attributes().AuthGrace(),
						0, DIAMETER_TIMER_TYPE_AUTH);

				AAA_LOG((LM_INFO, "%T |SESSION| Client session in open state\n"));
				AAA_LOG((LM_INFO, "%T |SESSION| Session Timeout: %d\n", 
							fsm.Attributes().SessionTimeout()));
				AAA_LOG((LM_INFO, "%T |SESSION| Auth Lifetime  : %d\n",
							fsm.Attributes().AuthLifetime()));
				AAA_LOG((LM_INFO, "%T |SESSION| Grace Period   : %d\n",
							fsm.Attributes().AuthGrace()));
			}
			else if (fsm.Attributes().SessionTimeout() > 0) {
				fsm.ScheduleTimer(DIAMETER_SESSION_AUTH_EV_SESSION_TOUT_NOST,
						fsm.Attributes().SessionTimeout(),
						0, DIAMETER_TIMER_TYPE_SESSION);

				AAA_LOG((LM_INFO, "%T |SESSION| Client session is stateless but has session timeout\n"));
				AAA_LOG((LM_INFO, "%T |SESSION| Session Timeout: %d\n", 
							fsm.Attributes().SessionTimeout()));
			}
			else {
				AAA_LOG((LM_INFO, "%T |SESSION| Client session is stateless with no session expiration set\n"));
			}
			fsm.Session().Success();
		}
};

class DiameterSessAuthClient_RxRAR : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			diameter_unsigned32_t rcode = AAA_SUCCESS;
			rcode = (diameter_unsigned32_t)fsm.Session().ReAuthenticate
				(fsm.Attributes().ReAuthRequestValue().reAuthType);             
			fsm.TxRAA(rcode);
		}
};

class DiameterSessAuthClient_TxSTR_NoSvc : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.TxSTR(AAA_REALM_NOT_SERVED);
		}
};

class DiameterSessAuthClient_TxSTR_ProcError : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.TxSTR(AAA_AVP_UNSUPPORTED);
		}
};

class DiameterSessAuthClient_TxSTR_Fail : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.TxSTR(AAA_AUTHORIZATION_REJECTED);
		}
};

class DiameterSessAuthClient_SessionTimeout : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.CancelAllTimer();
			fsm.Session().SessionTimeout();
			fsm.Session().Reset();
		}
};

class DiameterSessAuthClient_SessionTimeoutState : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.CancelAllTimer();
			fsm.TxSTR(AAA_AUTHORIZATION_REJECTED);
			fsm.Session().SessionTimeout();
		}
};

class DiameterSessAuthClient_AuthTimeout : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.CancelAllTimer();
			fsm.TxSTR(AAA_AUTHORIZATION_REJECTED);
			fsm.Session().AuthorizationTimeout();
		}
};

class DiameterSessAuthClient_UserAbort : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.CancelAllTimer();
			fsm.TxSTR(AAA_AUTHORIZATION_REJECTED);
		}
};

class DiameterSessAuthClient_TxASA_Success : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.TxASA(AAA_SUCCESS);
		}
};

class DiameterSessAuthClient_TxASA_TxSTR_Success : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.TxASA(AAA_SUCCESS);
			fsm.TxSTR(AAA_SUCCESS);
		}
};

class DiameterSessAuthClient_TxASA_Fail : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.TxASA(AAA_UNABLE_TO_COMPLY);
		}
};

class DiameterSessAuthClient_Disconnect : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.Session().Disconnect();
			fsm.CancelAllTimer();
			fsm.Session().Reset();
		}
};

class DiameterSessAuthClient_Cleanup : 
	public AAA_Action<DiameterAuthSessionClientStateMachine> 
{
	public:
		virtual void operator()(DiameterAuthSessionClientStateMachine &fsm) {
			fsm.CancelAllTimer();
			fsm.Session().AbortSession();
			fsm.Session().Reset();
		}
};

class AAA_SessAuthClientStateTable : 
	public AAA_StateTable<DiameterAuthSessionClientStateMachine>
{
	public:
		AAA_SessAuthClientStateTable() {

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Idle      Client or Device Requests      Send       Pending
				access                         service
				specific
				auth req
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_IDLE,
					DIAMETER_SESSION_AUTH_EV_REQUEST_ACCESS,
					DIAMETER_SESSION_AUTH_ST_PENDING);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Idle      ASR Received                   Send ASA   Idle
				for unknown session            with
				Result-Code
				= UNKNOWN_
				SESSION_ID
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_IDLE,
					DIAMETER_SESSION_AUTH_EV_RX_ASR_USID,
					DIAMETER_SESSION_AUTH_ST_IDLE);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Idle      Service-specific authorization Discard      Idle
				req sent                       service
				specific
				auth req
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_IDLE,
					DIAMETER_SESSION_AUTH_EV_TX_SSAR,
					DIAMETER_SESSION_AUTH_ST_IDLE,
					m_acTxSSARDiscard);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Idle      Service-specific authorization Discard      Idle
				answer received                service
				specific
				auth answer
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_IDLE,
					DIAMETER_SESSION_AUTH_EV_RX_SSAA,
					DIAMETER_SESSION_AUTH_ST_IDLE,
					m_acRxSSAADiscard);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Idle     Any                            None       Idle
				*/
			AddWildcardStateTableEntry(DIAMETER_SESSION_AUTH_ST_IDLE,
					DIAMETER_SESSION_AUTH_ST_IDLE);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Pending   Successful Service-specific    Grant      Open
				authorization answer           Access
				received with Auth-Session-
				State set to
				NO_STATE_MAINTAINED

				State     Event                          Action     New State
				-------------------------------------------------------------
				Pending   Successful Service-specific    Grant      Open
				authorization answer           Access
				received with default
				Auth-Session-State value
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_PENDING,
					DIAMETER_SESSION_AUTH_EV_SSAA_OK,
					DIAMETER_SESSION_AUTH_ST_OPEN,
					m_acGrantAccess);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Pending   Successful Service-specific    Sent STR   Discon
				authorization answer received
				but service not provided
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_PENDING,
					DIAMETER_SESSION_AUTH_EV_SSAA_NOSVC,
					DIAMETER_SESSION_AUTH_ST_DISC,
					m_acTxSTRNoSvc);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Pending   Error processing successful    Sent STR   Discon
				Service-specific authorization
				answer
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_PENDING,
					DIAMETER_SESSION_AUTH_EV_SSAA_ERROR,
					DIAMETER_SESSION_AUTH_ST_DISC,
					m_acTxSTRProcError);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Pending   Failed Service-specific        Cleanup    Idle
				authorization answer received
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_PENDING,
					DIAMETER_SESSION_AUTH_EV_SSAA_FAIL,
					DIAMETER_SESSION_AUTH_ST_IDLE,
					m_acCleanup);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Pending   Service-specific authorization Send       Pending
				req sent                       service
				specific
				auth req
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_PENDING,
					DIAMETER_SESSION_AUTH_EV_TX_SSAR,
					DIAMETER_SESSION_AUTH_ST_PENDING,
					m_acTxSSAR);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Pending   Service-specific authorization Accept       Pending
				answer received                service
				specific
				auth answer
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_PENDING,
					DIAMETER_SESSION_AUTH_EV_RX_SSAA,
					DIAMETER_SESSION_AUTH_ST_PENDING,
					m_acRxSSA);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Pending   Service to user is terminated  Discon.    Idle
				user/device
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_PENDING,
					DIAMETER_SESSION_AUTH_EV_STOP,
					DIAMETER_SESSION_AUTH_ST_IDLE,
					m_acDisconnect);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Pending  Any                            None       Pending
				*/
			AddWildcardStateTableEntry(DIAMETER_SESSION_AUTH_ST_PENDING,
					DIAMETER_SESSION_AUTH_ST_PENDING);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      User or client device          Send       Open
				requests access to service     service
				specific
				auth req
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_REQUEST_ACCESS,
					DIAMETER_SESSION_AUTH_ST_OPEN);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      Re-auth request received       Send       Open
				re-auth
				answer  
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_RX_RAR,
					DIAMETER_SESSION_AUTH_ST_OPEN,
					m_acRxRAR);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      Successful Service-specific    Provide    Open
				authorization answer received  Service
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_SSAA_OK,
					DIAMETER_SESSION_AUTH_ST_OPEN,
					m_acGrantAccess);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				[un-offic] Open      Service-specific authorization Process    Open
				requests received              service
				specific

*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_RX_SSAR,
					DIAMETER_SESSION_AUTH_ST_OPEN,
					m_acRxSSA);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				[un-offic] Open      Service-specific authorization Send       Open
				requests received and user     service
				or client device can comply    specific
				auth answer
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_SSAR_OK,
					DIAMETER_SESSION_AUTH_ST_OPEN);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				[un-offic] Open      Service-specific authorization Send       Idle
				requests received and user     failed serv.
				or client device cannot comply specific
				answer,
				Cleanup
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_SSAR_FAIL,
					DIAMETER_SESSION_AUTH_ST_IDLE,
					m_acDisconnect);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      Failed Service-specific        Discon.    Idle
				authorization answer           user/device
				received.
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_SSAA_FAIL,
					DIAMETER_SESSION_AUTH_ST_IDLE,
					m_acDisconnect);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      Session-Timeout Expires on     Send STR   Discon
				Access Device
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_SESSION_TOUT_ST,
					DIAMETER_SESSION_AUTH_ST_DISC,
					m_acSessionTimeoutState);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      Session-Timeout Expires on     Discon.    Idle
				Access Device                  user/device
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_SESSION_TOUT_NOST,
					DIAMETER_SESSION_AUTH_ST_IDLE,
					m_acSessionTimeout);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      ASR Received,                  Send ASA   Discon
				client will comply with        with
				request to end the session     Result-Code
				= SUCCESS,
				Send STR.
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_RX_ASR_OK,
					DIAMETER_SESSION_AUTH_ST_DISC,
					m_acTxASATxSTRSuccess);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      ASR Received,                  Send ASA   Open
				client will not comply with    with
				request to end the session     Result-Code
				!= SUCCESS
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_RX_ASR_RETRY,
					DIAMETER_SESSION_AUTH_ST_OPEN,
					m_acTxASAFail);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      Authorization-Lifetime +       Send STR   Discon
				Auth-Grace-Period expires on
				access device
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_LIFETIME_TOUT,
					DIAMETER_SESSION_AUTH_ST_DISC,
					m_acAuthTimeout);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      Service to user is terminated  Discon.    Idle
				user/device
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_STOP,
					DIAMETER_SESSION_AUTH_ST_IDLE,
					m_acDisconnect);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				[un-offic] Open      Session being terminated by    Send STR   Discon
				user                                       
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_ABORT,
					DIAMETER_SESSION_AUTH_ST_DISC,
					m_acUserAbort);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      Service-specific authorization Send       Open
				req sent                       service
				specific
				auth req
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_TX_SSAR,
					DIAMETER_SESSION_AUTH_ST_OPEN,
					m_acTxSSAR);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open      Service-specific authorization Accept       Open
				answer received                service
				specific
				auth answer
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_EV_RX_SSAA,
					DIAMETER_SESSION_AUTH_ST_OPEN,
					m_acRxSSA);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Open     Any                            None       Open
				*/
			AddWildcardStateTableEntry(DIAMETER_SESSION_AUTH_ST_OPEN,
					DIAMETER_SESSION_AUTH_ST_OPEN);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Discon    ASR Received                   Send ASA   Discon
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_DISC,
					DIAMETER_SESSION_AUTH_EV_RX_ASR,
					DIAMETER_SESSION_AUTH_ST_DISC,
					m_acTxASASuccess);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Discon    STA Received                   Discon.    Idle
				user/device
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_DISC,
					DIAMETER_SESSION_AUTH_EV_RX_STA,
					DIAMETER_SESSION_AUTH_ST_IDLE,
					m_acDisconnect);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Discon    Session-Timeout Expires on     Cleanup    Idle
				Access Device
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_DISC,
					DIAMETER_SESSION_AUTH_EV_SESSION_TOUT_ST,
					DIAMETER_SESSION_AUTH_ST_IDLE,
					m_acDisconnect);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Discon    Authorization-Lifetime +       Cleanup    Idle
				Auth-Grace-Period expires on
				access device
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_DISC,
					DIAMETER_SESSION_AUTH_EV_LIFETIME_TOUT,
					DIAMETER_SESSION_AUTH_ST_IDLE,
					m_acDisconnect);         

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Discon    Service-specific authorization Discard      Discon
				req sent                       service
				specific
				auth req
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_DISC,
					DIAMETER_SESSION_AUTH_EV_TX_SSAR,
					DIAMETER_SESSION_AUTH_ST_DISC,
					m_acTxSSARDiscard);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Discon    Service-specific authorization Discard      Discon
				answer received                service
				specific
				auth req
				*/
			AddStateTableEntry(DIAMETER_SESSION_AUTH_ST_DISC,
					DIAMETER_SESSION_AUTH_EV_RX_SSAA,
					DIAMETER_SESSION_AUTH_ST_DISC,
					m_acRxSSAADiscard);

			/*
				State     Event                          Action     New State
				-------------------------------------------------------------
				Discon   Any                            None       Discon
				*/
			AddWildcardStateTableEntry(DIAMETER_SESSION_AUTH_ST_DISC,
					DIAMETER_SESSION_AUTH_ST_DISC);

			InitialState(DIAMETER_SESSION_AUTH_ST_IDLE);
		}

	private:



		DiameterSessAuthClient_TxSSAR               m_acTxSSAR;
		DiameterSessAuthClient_RxSSA                m_acRxSSA;


		DiameterSessAuthClient_TxSSAR_Discard       m_acTxSSARDiscard;
		DiameterSessAuthClient_RxSSAA_Discard       m_acRxSSAADiscard;
		DiameterSessAuthClient_RxSSAA_GrantAccess   m_acGrantAccess;
		DiameterSessAuthClient_RxRAR                m_acRxRAR;

		DiameterSessAuthClient_TxSTR_NoSvc          m_acTxSTRNoSvc;
		DiameterSessAuthClient_TxSTR_ProcError      m_acTxSTRProcError;
		DiameterSessAuthClient_TxSTR_Fail           m_acTxSTRFail;

		DiameterSessAuthClient_SessionTimeout       m_acSessionTimeout;
		DiameterSessAuthClient_SessionTimeoutState  m_acSessionTimeoutState;
		DiameterSessAuthClient_AuthTimeout          m_acAuthTimeout;
		DiameterSessAuthClient_UserAbort            m_acUserAbort;

		DiameterSessAuthClient_TxASA_Success        m_acTxASASuccess;
		DiameterSessAuthClient_TxASA_TxSTR_Success  m_acTxASATxSTRSuccess;
		DiameterSessAuthClient_TxASA_Fail           m_acTxASAFail;
		DiameterSessAuthClient_Cleanup              m_acCleanup;
		DiameterSessAuthClient_Disconnect           m_acDisconnect;
};

#endif /* __AAA_SESSION_AUTH_CLIENT_FSM_H__ */

