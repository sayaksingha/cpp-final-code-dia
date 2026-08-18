static const char *id = " @(#) $Id: diameter_cc_client_session.cc,v 1.1.2.1 2018/02/21 23:29:57 shijuc Exp $";
//----------------------------------------------------------------------
// NAME
// diameter_cc_client_session.cc
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
#include "diameter_cc_client_session.h"
#include "diameter_cc_application.h"

DiameterCCClientSession::DiameterCCClientSession
(DiameterCCApplication &ccApplication, DiameterJobHandle &h)
  : DiameterClientAuthSession(ccApplication.Task(), CCApplicationId),
    DiameterCCClientStateMachine(*this, 
                                 h,
                                 *(ccApplication.Task().reactor())),
    diameterCCApplication(ccApplication)

{
}

AAAReturnCode DiameterCCClientSession::RequestMsg(DiameterMsg &msg)
{
	Session().dccaMsg = msg;

/*	if(Session().CCA_DATA().CCRequestType.IsSet())
	{
		if (Session().CCA_DATA().CCRequestType == CC_TYPE_INITIAL_REQUEST)
		{
			Session().Notify(DiameterCCClientStateMachine::EvInitialAnswer);
		}
		else if(Session().CCA_DATA().CCRequestType == CC_TYPE_UPDATE_REQUEST)
		{
			Session().Notify(DiameterCCClientStateMachine::EvUpdateAnswer);
		}
		else if (Session().CCA_DATA().CCRequestType == CC_TYPE_TERMINATION_REQUEST)
		{
			Session().Notify(DiameterCCClientStateMachine::EvTerminationAnswer);
		}
		else if (Session().CCA_DATA().CCRequestType == CC_TYPE_EVENT_REQUEST)
		{
			if (Session().CCR_DATA().RequestedAction == CC_ACTION_DIRECT_DEBITING)
			{
				Session().Notify(DiameterCCClientStateMachine::EvDirectDebitingAnswer);
			}
			else if (Session().CCR_DATA().RequestedAction == CC_ACTION_REFUND_ACCOUNT)
			{
				Session().Notify(DiameterCCClientStateMachine::EvRefundAccountAnswer);
			}
			else if (Session().CCR_DATA().RequestedAction == CC_ACTION_CHECK_BALANCE)
			{
				Session().Notify(DiameterCCClientStateMachine::EvCheckBalanceAnswer);
			}
			else if (Session().CCR_DATA().RequestedAction == CC_ACTION_PRICE_ENQUIRY)
			{
				Session().Notify(DiameterCCClientStateMachine::EvPriceEnquiryAnswer);
			}
		}
	}*/

	return AAA_ERR_SUCCESS;
}

	AAAReturnCode
DiameterCCClientSession::AnswerMsg(DiameterMsg &msg)
{

/* if(Session().CCA_DATA().CCRequestType.IsSet())
   {
      if (Session().CCA_DATA().CCRequestType == CC_TYPE_INITIAL_REQUEST)
      {
         Session().Notify(DiameterCCClientStateMachine::EvInitialAnswer);
      }
      else if(Session().CCA_DATA().CCRequestType == CC_TYPE_UPDATE_REQUEST)
      {
         Session().Notify(DiameterCCClientStateMachine::EvUpdateAnswer);
      }
      else if (Session().CCA_DATA().CCRequestType == CC_TYPE_TERMINATION_REQUEST)
      {
         Session().Notify(DiameterCCClientStateMachine::EvTerminationAnswer);
      }
      else if (Session().CCA_DATA().CCRequestType == CC_TYPE_EVENT_REQUEST)
      {
         if (Session().CCR_DATA().RequestedAction == CC_ACTION_DIRECT_DEBITING)
         {
            Session().Notify(DiameterCCClientStateMachine::EvDirectDebitingAnswer);
         }
         else if (Session().CCR_DATA().RequestedAction == CC_ACTION_REFUND_ACCOUNT)
         {
            Session().Notify(DiameterCCClientStateMachine::EvRefundAccountAnswer);
         }
         else if (Session().CCR_DATA().RequestedAction == CC_ACTION_CHECK_BALANCE)
         {
            Session().Notify(DiameterCCClientStateMachine::EvCheckBalanceAnswer);
         }
         else if (Session().CCR_DATA().RequestedAction == CC_ACTION_PRICE_ENQUIRY)
         {
            Session().Notify(DiameterCCClientStateMachine::EvPriceEnquiryAnswer);
         }
      }
   }*/

	return AAA_ERR_SUCCESS;
}

	AAAReturnCode
DiameterCCClientSession::Disconnect() 
{ 
	AAA_LOG((LM_ERROR, "[%N] Session termination event received.\n"));
	Notify(DiameterCCClientStateMachine::EvSgDisconnect);
	return AAA_ERR_SUCCESS; 
}

	AAAReturnCode 
DiameterCCClientSession::HandleSessionTimeout() 
{ 
	AAA_LOG((LM_ERROR, "[%N] Session timeout received.\n"));
	Notify(DiameterCCClientStateMachine::EvSgSessionTimeout);
	return AAA_ERR_SUCCESS; 
}

	AAAReturnCode 
DiameterCCClientSession::HandleAuthLifetimeTimeout()
{ 
	AAA_LOG((LM_ERROR, "[%N] Timeout received.\n"));
	Notify(DiameterCCClientStateMachine::EvSgAuthLifetimeTimeout);
	return AAA_ERR_SUCCESS; 
}

	AAAReturnCode 
DiameterCCClientSession::HandleTimeout() 
{ 
	AAA_LOG((LM_ERROR, "[%N] Session timeout received.\n"));
	Notify(DiameterCCClientStateMachine::EvSgTimeout);
	return AAA_ERR_SUCCESS; 
}

bool 
DiameterCCClientSession::CreditControlFailureHandling()
{
	return true;
}

	DiameterCCApplication& 
DiameterCCClientSession:: DiameterCCApp()
{
	return diameterCCApplication;
}
