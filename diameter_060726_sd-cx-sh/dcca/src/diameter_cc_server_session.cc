static const char *id = " @(#) $Id: diameter_cc_server_session.cc,v 1.1.2.1 2018/02/21 23:29:58 shijuc Exp $";
//----------------------------------------------------------------------
// NAME
// diameter_cc_server_session.cc
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
#include "diameter_parser.h"
#include "diameter_cc_server_session.h"
#include "diameter_cc_server_fsm.h"
#include "diameter_cc_parser.h"
#include "diameter_cc_application.h"

DiameterCCServerSession::DiameterCCServerSession(DiameterCCApplication &ccApplication, 
		diameter_unsigned32_t appId) : DiameterServerAuthSession(ccApplication.Task(), appId),
	DiameterCCServerStateMachine(*this, ccApplication.Task().JobHandle(), 
			*(ccApplication.Task().reactor()))

{
}

AAAReturnCode DiameterCCServerSession::RequestMsg(DiameterMsg &msg)
{
	return AAA_ERR_SUCCESS;
}

AAAReturnCode DiameterCCServerSession::AnswerMsg(DiameterMsg &msg)
{
	return AAA_ERR_SUCCESS;
}

AAAReturnCode DiameterCCServerSession::ErrorMsg(DiameterMsg &msg)
{
	return AAA_ERR_SUCCESS;
}

AAAReturnCode DiameterCCServerSession::Disconnect() 
{ 
	Notify(DiameterCCServerStateMachine::EvSgDisconnect);
	return AAA_ERR_SUCCESS; 
}

AAAReturnCode DiameterCCServerSession::ReClaimSession() 
{ 
	return AAA_ERR_SUCCESS; 
}

AAAReturnCode DiameterCCServerSession::SessionTimeout() 
{
	HandleTimeout();
	return HandleSessionTimeout();
}

AAAReturnCode DiameterCCServerSession::AuthorizationTimeout() 
{
	HandleAuthGracePeriodTimeout();
	return HandleAuthLifetimeTimeout();
}

AAAReturnCode DiameterCCServerSession::HandleSessionTimeout() 
{ 
	Notify(DiameterCCServerStateMachine::EvSgSessionTimeout);
	return AAA_ERR_SUCCESS; 
}

AAAReturnCode DiameterCCServerSession::HandleAuthLifetimeTimeout()
{ 
	return AAA_ERR_SUCCESS; 
}

AAAReturnCode DiameterCCServerSession::HandleAuthGracePeriodTimeout()
{ 
	return AAA_ERR_SUCCESS; 
}

AAAReturnCode DiameterCCServerSession::HandleTimeout() 
{ 
	Notify(DiameterCCServerStateMachine::EvSgTimeout);
	return AAA_ERR_SUCCESS; 
}

void DiameterCCServerSession::Start() throw (AAA_Error)
{
	DiameterCCServerStateMachine::Start();
}
