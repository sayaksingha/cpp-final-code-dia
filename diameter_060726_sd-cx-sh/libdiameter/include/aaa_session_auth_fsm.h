// @(#) $Id: aaa_session_auth_fsm.h,v 1.1.4.1.2.1 2018/02/21 23:00:47 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_session_auth_fsm.h
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
#ifndef __AAA_SESSION_AUTH_FSM_H__
#define __AAA_SESSION_AUTH_FSM_H__

#include "aaa_session.h"
#include "aaa_session_fsm.h"

typedef enum {
    DIAMETER_SESSION_AUTH_ST_IDLE,
    DIAMETER_SESSION_AUTH_ST_PENDING,
    DIAMETER_SESSION_AUTH_ST_OPEN,
    DIAMETER_SESSION_AUTH_ST_DISC,
} DIAMETER_SESSION_AUTH_ST;

typedef enum {
    DIAMETER_SESSION_AUTH_EV_REQUEST_ACCESS,
    DIAMETER_SESSION_AUTH_EV_RX_ASR,
    DIAMETER_SESSION_AUTH_EV_RX_ASA_OK,
    DIAMETER_SESSION_AUTH_EV_RX_ASA_FAIL,
    DIAMETER_SESSION_AUTH_EV_RX_ASR_USID,
    DIAMETER_SESSION_AUTH_EV_RX_ASR_OK,
    DIAMETER_SESSION_AUTH_EV_RX_ASR_RETRY,
    DIAMETER_SESSION_AUTH_EV_TX_ASR_FAIL,
    DIAMETER_SESSION_AUTH_EV_RX_STR,
    DIAMETER_SESSION_AUTH_EV_RX_STA,
    DIAMETER_SESSION_AUTH_EV_TX_SSAR,
    DIAMETER_SESSION_AUTH_EV_RX_SSAR,
    DIAMETER_SESSION_AUTH_EV_TX_SSAA,
    DIAMETER_SESSION_AUTH_EV_RX_SSAA,
    DIAMETER_SESSION_AUTH_EV_RX_RAR,
    DIAMETER_SESSION_AUTH_EV_RX_RAA,
    DIAMETER_SESSION_AUTH_EV_SSAR_OK,
    DIAMETER_SESSION_AUTH_EV_SSAR_FAIL,
    DIAMETER_SESSION_AUTH_EV_SSAA_OK,
    DIAMETER_SESSION_AUTH_EV_SSAA_NOSVC,
    DIAMETER_SESSION_AUTH_EV_SSAA_ERROR,
    DIAMETER_SESSION_AUTH_EV_SSAA_FAIL,
    DIAMETER_SESSION_AUTH_EV_REAUTH,
    DIAMETER_SESSION_AUTH_EV_LIFETIME_TOUT,
    DIAMETER_SESSION_AUTH_EV_SESSION_TOUT_ST,
    DIAMETER_SESSION_AUTH_EV_SESSION_TOUT_NOST,
    DIAMETER_SESSION_AUTH_EV_SESSION_RECLAIM,
    DIAMETER_SESSION_AUTH_EV_ABORT,
    DIAMETER_SESSION_AUTH_EV_STOP,
} DIAMETER_SESSION_EV_AUTH;

class DiameterSessionAuthFsmDebug 
{
   public:
      void DumpEvent(AAA_State state, AAA_Event ev) {
#if AAA_SESSION_AUTH_DEBUG 
          static char *evStrTable[] = { "DIAMETER_SESSION_AUTH_EV_REQUEST_ACCESS",
                                        "DIAMETER_SESSION_AUTH_EV_RX_ASR",
                                        "DIAMETER_SESSION_AUTH_EV_RX_ASA_OK",
                                        "DIAMETER_SESSION_AUTH_EV_RX_ASA_FAIL",
                                        "DIAMETER_SESSION_AUTH_EV_RX_ASR_USID",
                                        "DIAMETER_SESSION_AUTH_EV_RX_ASR_OK",
                                        "DIAMETER_SESSION_AUTH_EV_RX_ASR_RETRY",
                                        "DIAMETER_SESSION_AUTH_EV_TX_ASR_FAIL",
                                        "DIAMETER_SESSION_AUTH_EV_RX_STR",
                                        "DIAMETER_SESSION_AUTH_EV_RX_STA",
                                        "DIAMETER_SESSION_AUTH_EV_TX_SSAR",
                                        "DIAMETER_SESSION_AUTH_EV_RX_SSAR",
                                        "DIAMETER_SESSION_AUTH_EV_TX_SSAA",
                                        "DIAMETER_SESSION_AUTH_EV_RX_SSAA",
                                        "DIAMETER_SESSION_AUTH_EV_RX_RAR",
                                        "DIAMETER_SESSION_AUTH_EV_RX_RAA",
                                        "DIAMETER_SESSION_AUTH_EV_SSAR_OK",
                                        "DIAMETER_SESSION_AUTH_EV_SSAR_FAIL",
                                        "DIAMETER_SESSION_AUTH_EV_SSAA_OK",
                                        "DIAMETER_SESSION_AUTH_EV_SSAA_NOSVC",
                                        "DIAMETER_SESSION_AUTH_EV_SSAA_ERROR",
                                        "DIAMETER_SESSION_AUTH_EV_SSAA_FAIL",
                                        "DIAMETER_SESSION_AUTH_EV_REAUTH",
                                        "DIAMETER_SESSION_AUTH_EV_LIFETIME_TOUT",
                                        "DIAMETER_SESSION_AUTH_EV_SESSION_TOUT_ST",
                                        "DIAMETER_SESSION_AUTH_EV_SESSION_TOUT_NOST",
                                        "DIAMETER_SESSION_AUTH_EV_SESSION_RECLAIM",
                                        "DIAMETER_SESSION_AUTH_EV_ABORT",
                                        "DIAMETER_SESSION_AUTH_EV_STOP"
          };
          static char *stStrTable[] = { "DIAMETER_SESSION_AUTH_ST_IDLE",
                                        "DIAMETER_SESSION_AUTH_ST_PENDING",
                                        "DIAMETER_SESSION_AUTH_ST_OPEN",
                                        "DIAMETER_SESSION_AUTH_ST_DISC"
          };
          AAA_LOG((LM_INFO, "(%P|%t) Auth session event [state=%s, event=%s]\n",
                    stStrTable[state], evStrTable[ev]));
#endif
      }
};

template<class ARG>
class DiameterAuthSessionStateMachine :
    public DiameterSessionStateMachine<ARG, DiameterSessionAuthFsmDebug>
{
   public:
      virtual ~DiameterAuthSessionStateMachine() {
      }    
      DiameterAuthSession &Session() {
          return m_Session;
      }
      DiameterAuthSessionAttributes &Attributes() {
          return m_Session.Attributes();
      }

   protected:
      DiameterAuthSessionStateMachine(AAA_Task &t,
                                  AAA_StateTable<ARG> &table,
                                  ARG &arg,
                                  DiameterAuthSession &s) :
          DiameterSessionStateMachine<ARG, DiameterSessionAuthFsmDebug>
           (t, table, arg),
          m_Session(s) {
      }

   protected:
      DiameterAuthSession &m_Session;
};

#endif /* __AAA_SESSION_AUTH_FSM_H__ */

