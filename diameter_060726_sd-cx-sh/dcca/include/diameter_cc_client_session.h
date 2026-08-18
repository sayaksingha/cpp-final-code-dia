// @(#) $Id: diameter_cc_client_session.h,v 1.1.2.1 2018/02/21 23:29:55 shijuc Exp $
//---------------------------------------------------------------
// NAME : diameter_cc_client_session.h
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
#ifndef __CC_CLIENT_SESSION_H__
#define __CC_CLIENT_SESSION_H__

#include <string>
#include <list>
#include "ace/Synch.h"
#include "diameter_api.h"
#include "diameter_cc_client_fsm.h"
#include "diameter_cc_parser.h"
#include "diameter_cc_application.h"

/// Client Diameter CC session.  This class is defined as multiple
/// inheritance, one from AAAClientSession (defined in Diameter API)
/// and the other from DiameterCcClientStateMachine.
class DIAMETER_CC_CLIENT_EXPORTS DiameterCCClientSession : 
    public DiameterClientAuthSession, public DiameterCCClientStateMachine
{
public:

  /// Constuctor.
  DiameterCCClientSession(DiameterCCApplication&, DiameterJobHandle &h);

  /// Destructor.
  ~DiameterCCClientSession() {}

  /// Reimplemented from AAAClientSession. This is invoked during
  /// incomming message events. The msg argument is pre-allocated by
  /// the library and is valid only within the context of this
  /// method. It is the responsibility of the derived class to
  /// override this function and capture the events if it is
  /// interested in it.
  AAAReturnCode RequestMsg(DiameterMsg &msg);

  AAAReturnCode AnswerMsg(DiameterMsg &msg);

  AAAReturnCode ErrorMsg(DiameterMsg &msg)
  {
	  return AAA_ERR_SUCCESS;
  }

  /// Reimplemented from AAAClientSession. This is invoked during
  /// session disconnect event. Disconnection occurs when a session is
  /// terminated or the peer connection is disconnection and unable to
  /// recover. It is the responsibility of the derived class to
  /// override this function and capture this events if it is
  /// interested in it.
  AAAReturnCode Disconnect();

  AAAReturnCode ReClaimSession()
  {
	  return AAA_ERR_SUCCESS;
  }

  AAAReturnCode SessionTimeout() {
	  HandleTimeout();
	  return HandleSessionTimeout();
  }

  /// Reimplemented from AAAClientSession.
  AAAReturnCode HandleSessionTimeout();

  AAAReturnCode AuthorizationTimeout() {
	  return HandleAuthLifetimeTimeout();
  }

  /// Reimplemented from AAAClientSession.
  AAAReturnCode HandleAuthLifetimeTimeout();

  /// Reimplemented from AAAClientSession. This is invoked during
  /// session timeout event. Timeout occurs when a session is idle
  /// (not re- authorization) for a specified amount of time. It is
  /// the responsibility of the derived class to override this
  /// function and capture this events if it is interested in it.
  AAAReturnCode HandleTimeout();

  /// Reimplemented from AAAClientSession. This is invoked during
  /// session abort event. Abort occurs when the server decides to
  /// terminate the client session by sending an ASR. It is the
  /// responsibility of the derived class to override this function
  /// and capture this events if it is interested in it.
  AAAReturnCode AbortSession() { return AAA_ERR_SUCCESS; }

  virtual bool CreditControlFailureHandling();

  void Start() throw (AAA_Error)
  {
	  DiameterCCClientStateMachine::Start();
	  DiameterClientAuthSession::Begin();
  }

  DiameterCCApplication& DiameterCCApp();

protected:
  DiameterCCApplication& diameterCCApplication;

};

#endif
