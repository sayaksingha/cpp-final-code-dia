// @(#) $Id: diameter_cc_server_session.h,v 1.1.2.1 2018/02/21 23:29:56 shijuc Exp $
//---------------------------------------------------------------
// NAME : diameter_cc_server_session.h
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
#ifndef __CC_SERVER_SESSION_H__
#define __CC_SERVER_SESSION_H__
#include <string>
#include <list>
#include "ace/Synch.h"
#include "diameter_api.h"
#include "diameter_cc_server_fsm.h"
#include "diameter_cc_parser.h"
#include "diameter_cc_application.h"

/// Diameter CC Server session.  This class is defined as multiple
/// inheritance, one from AAAServerSession (defined in Diameter API)
/// and the other from DiameterCcServerStateMachine.
class DIAMETER_CC_SERVER_EXPORTS DiameterCCServerSession : 
	public DiameterServerAuthSession, public DiameterCCServerStateMachine
{
	public:

		/// Constuctor.
		DiameterCCServerSession(DiameterCCApplication &diameterCCApplication, 
				diameter_unsigned32_t appId=CCApplicationId);

		/// Destructor.
		~DiameterCCServerSession() {}

		/// Reimplemented from AAAServerSession. 
		AAAReturnCode RequestMsg(DiameterMsg &msg);

		AAAReturnCode AnswerMsg(DiameterMsg &msg);

		AAAReturnCode ErrorMsg(DiameterMsg &msg);

		/// Reimplemented from AAAServerSession. 
		AAAReturnCode Disconnect();

		AAAReturnCode ReClaimSession();

		AAAReturnCode SessionTimeout();

		/// Reimplemented from AAAServerSession.
		AAAReturnCode HandleSessionTimeout();

		AAAReturnCode AuthorizationTimeout();

		/// Reimplemented from AAAServerSession.
		AAAReturnCode HandleAuthLifetimeTimeout();

		/// Reimplemented from AAAServerSession.
		AAAReturnCode HandleAuthGracePeriodTimeout();

		/// Reimplemented from AAAServerSession.
		AAAReturnCode AbortSession() { return AAA_ERR_SUCCESS; }

		/// Reimplemented from AAAServerSession. This is a general timeout
		/// event handler.
		AAAReturnCode HandleTimeout();

		void Start() throw (AAA_Error);
};

#endif
