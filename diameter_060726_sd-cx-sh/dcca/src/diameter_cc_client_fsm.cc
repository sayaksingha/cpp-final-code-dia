static const char *id = " @(#) $Id: diameter_cc_client_fsm.cc,v 1.1.2.1.2.1 2024/05/15 13:03:29 mram Exp $";
//----------------------------------------------------------------------
// NAME
// diameter_cc_client_fsm.cc
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
#include <ace/Singleton.h>
#include <ace/Atomic_Op_T.h>
#include "diameter_cc_client_session.h"
#include "diameter_cc_client_fsm.h"
#include "diameter_cc_parser.h"

class DiameterCCClientAction 
  : public AAA_Action<DiameterCCClientStateMachine>
{
  virtual void operator()(DiameterCCClientStateMachine&)=0;
 protected:
  DiameterCCClientAction() {}
  ~DiameterCCClientAction() {}
};

/// State table used by DiameterCCClientStateMachine.
class DiameterCCClientStateTable_S 
  : public AAA_StateTable<DiameterCCClientStateMachine>
{
  friend class 
  ACE_Singleton<DiameterCCClientStateTable_S, ACE_Recursive_Thread_Mutex>;
  
  class AcInitialRequest : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Processing Initial Request.\n"));

      if(sm.InitialRequest())
        {
          AAA_LOG((LM_DEBUG, "(%P|%t) \tSent Initial Request.\n"));
        }
      else
        AAA_LOG((LM_DEBUG, "(%P|%t) \tCould not send Initial Request.\n"));
    }
  }; 

  class AcSuccessfulAnswer : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
    }
  }; 

  class AcInitialAnswer : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Processing Initial Answer.\n"));

      sm.InitialAnswer(); 
    }
  }; 

  class AcGrantService : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Service Granted.\n"));
    }
  }; 

  class AcTerminateService : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Service Terminated.\n"));
    }
  }; 

  class AcTerminationRequest : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Processing Termination Request.\n"));

      if(sm.TerminationRequest())
        AAA_LOG((LM_DEBUG, "(%P|%t) \tSent Termination Request.\n"));
      else
        AAA_LOG((LM_DEBUG, "(%P|%t) \tCould not send Terminate Request.\n"));
    }
  }; 

  class AcTerminationAnswer : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Recieved Termination Answer.\n"));
    }
  }; 

  class AcTxExpired : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Tx Expired.\n"));
      sm.TxExpired();
    }
  }; 

  class AcServiceTerminated : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Service Terminated.\n"));
    }
  }; 

  class AcGrantedUnitsElapsed : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Granted Units Elapsed.\n"));
    }
  }; 

  class AcSendUpdateRequest : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Send Update Request.\n"));
    }
  }; 

  class AcSendRAAAndUpdate : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Send RAA and Update.\n"));
    }
  }; 

  class AcUpdateAnswer : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Update Answer.\n"));
    }
  }; 

  class AcTccExpired : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Tcc Expired.\n"));
    }
  }; 



  class AcChangeInRating : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Change In Rating.\n"));
    }
  };

  class AcRARReceived : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) RAR Received.\n"));
    }
  };

  class AcDirectDebitingRequest : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Processing Direct Debiting Request.\n"));

      if(sm.DirectDebitingRequest())
        AAA_LOG((LM_DEBUG, "(%P|%t) \tSent Direct Debiting Request.\n"));
      else
        AAA_LOG((LM_DEBUG, "(%P|%t) \tCould not send Direct Debiting Request.\n"));
    }
  }; 

  class AcDirectDebitingAnswer : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Processing Direct Debiting Answer.\n"));

      sm.DirectDebitingAnswer();
    }
  }; 

  class AcRefundAccountRequest : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Processing Refund Account Request.\n"));

      if(sm.RefundAccountRequest())
        AAA_LOG((LM_DEBUG, "(%P|%t) \tSent Refund Account Request.\n"));
      else
        AAA_LOG((LM_DEBUG, "(%P|%t) \tCould not send Refund Account Request.\n"));
    }
  }; 

  class AcRefundAccountAnswer : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Processing Refund Account Answer.\n"));

      sm.RefundAccountAnswer();
    }
  }; 

  class AcCheckBalanceRequest : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Processing Check Balance Request.\n"));

      if(sm.CheckBalanceRequest())
        AAA_LOG((LM_DEBUG, "(%P|%t) \tSent Check Balance Request.\n"));
      else
        AAA_LOG((LM_DEBUG, "(%P|%t) \tCould not send Check Balance Request.\n"));
    }
  }; 

  class AcCheckBalanceAnswer : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Processing Check Balancet Answer.\n"));

      sm.CheckBalanceAnswer();
    }
  }; 

  class AcPriceEnquiryRequest : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Processing Price Enquiry Request.\n"));

      if(sm.PriceEnquiryRequest())
        AAA_LOG((LM_DEBUG, "(%P|%t) \tSent Price Enquiry Request.\n"));
      else
        AAA_LOG((LM_DEBUG, "(%P|%t) \tCould not send Price Enquiry Request.\n"));
    }
  }; 

  class AcPriceEnquiryAnswer : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Processing Price Enquiry Answer.\n"));

      sm.PriceEnquiryAnswer();
    }
  }; 

  class AcServiceError : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Service Error.\n"));
    }
  }; 

  class AcStoreRequestWithTFlag : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Store Request With TFlag.\n"));
    }
  };

  class AcStoreRequest : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {
      AAA_LOG((LM_DEBUG, "(%P|%t) Store Request.\n"));
    }
  }; 

  class AcFailedAnswer : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Failed Answer.\n"));
    }
  }; 

  class AcFailureToSend : public DiameterCCClientAction 
  {
    void operator()(DiameterCCClientStateMachine& sm)
    {

      AAA_LOG((LM_DEBUG, "(%P|%t) Failure To Send.\n"));
    }
  };         

  enum state {
    StIdle,
    StPendingI,
    StOpen,
    StPendingU,
    StPendingT,
    StPendingE,
    StPendingB,
    StTerminated
  };

  AcInitialRequest acInitalRequest;
  AcSuccessfulAnswer acSuccessfulAnswer;
  AcInitialAnswer acInitialAnswer;
  
  AcGrantService acGrantService;
  AcTerminateService acTerminateService;
  AcTerminationRequest acTerminationRequest;
  AcTerminationAnswer acTerminationAnswer;
  AcTxExpired acTxExpired;
  AcServiceTerminated acServiceTerminated;
  AcChangeInRating acChangeInRating;
  AcGrantedUnitsElapsed acGrantedUnitsElapsed;
  AcSendUpdateRequest acSendUpdateRequest;
  AcSendRAAAndUpdate acSendRAAAndUpdate;
  AcUpdateAnswer acUpdateAnswer;
  AcTccExpired acTccExpired;
  AcRARReceived acRARReceived;
 
  AcDirectDebitingRequest acDirectDebitingRequest;
  AcDirectDebitingAnswer acDirectDebitingAnswer;
  
  AcRefundAccountRequest acRefundAccountRequest;
  AcRefundAccountAnswer acRefundAccountAnswer;
  
  AcCheckBalanceRequest acCheckBalanceRequest;
  AcCheckBalanceAnswer acCheckBalanceAnswer;
  
  AcPriceEnquiryRequest acPriceEnquiryRequest;
  AcPriceEnquiryAnswer acPriceEnquiryAnswer;
  
  AcServiceError acServiceError;
  AcStoreRequestWithTFlag acStoreRequestWithTFlag;
  AcStoreRequest acStoreRequest;
  AcFailedAnswer acFailedAnswer;
  AcFailureToSend acFailureToSend;

  DiameterCCClientStateTable_S() 
  {
    AddStateTableEntry(StIdle, 
                       DiameterCCClientStateMachine::EvInitialRequest,
                       StPendingI, acInitalRequest);

    AddStateTableEntry(StIdle,
                       DiameterCCClientStateMachine::EvDirectDebitingRequest,
                       StPendingE,acDirectDebitingRequest);
    AddStateTableEntry(StIdle,
                       DiameterCCClientStateMachine::EvRefundAccountRequest,
                       StPendingE,acRefundAccountRequest);
    AddStateTableEntry(StIdle,
                       DiameterCCClientStateMachine::EvCheckBalanceRequest,
                       StPendingE,acCheckBalanceRequest);
    AddStateTableEntry(StIdle,
                       DiameterCCClientStateMachine::EvPriceEnquiryRequest,
                       StPendingE,acPriceEnquiryRequest);
    AddStateTableEntry(StIdle,
                       DiameterCCClientStateMachine::EvStoredEventSent,
                       StPendingB);
    // Late answer received
    AddStateTableEntry(StIdle,
                       DiameterCCClientStateMachine::EvInitialAnswer,
                       StIdle);
    
    AddWildcardStateTableEntry(StIdle, StTerminated);

    AddStateTableEntry(StPendingI,
                       DiameterCCClientStateMachine::EvInitialAnswer,
                       StOpen,acInitialAnswer);
    AddStateTableEntry(StPendingI,
                       DiameterCCClientStateMachine::EvGrantWOSession,
                       StIdle,acGrantService);
    AddStateTableEntry(StPendingI,
                       DiameterCCClientStateMachine::EvTerminateService,
                       StIdle,acTerminateService);
    AddStateTableEntry(StPendingI,
                       DiameterCCClientStateMachine::EvTxExpired,
                       StPendingI,acTxExpired);

    AddStateTableEntry(StPendingI,
                       DiameterCCClientStateMachine::EvGrantService,
                       StPendingI,acGrantService);
    AddStateTableEntry(StPendingI,
                       DiameterCCClientStateMachine::EvServiceTerminated,
                       StPendingI,acServiceTerminated);
    AddStateTableEntry(StPendingI,
                       DiameterCCClientStateMachine::EvChangeInRating,
                       StPendingI,acChangeInRating);
    AddWildcardStateTableEntry(StPendingI, StTerminated);

    AddStateTableEntry(StOpen,
                       DiameterCCClientStateMachine::EvGrantedUnitsElapsed,
                       StOpen,acGrantedUnitsElapsed);
    AddStateTableEntry(StOpen,
                       DiameterCCClientStateMachine::EvSentUpdateRequest,
                       StPendingU);
    AddStateTableEntry(StOpen,
                       DiameterCCClientStateMachine::EvTerminationRequest,
                       StPendingT,
                       acTerminationRequest);
    AddStateTableEntry(StOpen,
                       DiameterCCClientStateMachine::EvChangeInRating,
                       StPendingU,acSendUpdateRequest);
    AddStateTableEntry(StOpen,
                       DiameterCCClientStateMachine::EvServiceTerminated,
                       StPendingT);
    AddStateTableEntry(StOpen,
                       DiameterCCClientStateMachine::EvRARReceived,
                       StPendingU,acSendRAAAndUpdate);
    AddWildcardStateTableEntry(StOpen, StTerminated);

    AddStateTableEntry(StPendingU,
                       DiameterCCClientStateMachine::EvUpdateAnswer,
                       StOpen,acUpdateAnswer);
    AddStateTableEntry(StPendingU,
                       DiameterCCClientStateMachine::EvGrantWOSession,
                       StIdle,acGrantService);
    AddStateTableEntry(StPendingU,
                       DiameterCCClientStateMachine::EvTerminateService,
                       StIdle,acTerminateService);
    AddStateTableEntry(StPendingU,
                       DiameterCCClientStateMachine::EvTccExpired,
                       StPendingU,acTccExpired);
    AddStateTableEntry(StPendingU,
                       DiameterCCClientStateMachine::EvGrantService,
                       StPendingU,acGrantService);
    AddStateTableEntry(StPendingU,
                       DiameterCCClientStateMachine::EvServiceTerminated,
                       StPendingU,acServiceTerminated);
    AddStateTableEntry(StPendingU,
                       DiameterCCClientStateMachine::EvChangeInRating,
                       StPendingU,acChangeInRating);
    AddStateTableEntry(StPendingU,
                       DiameterCCClientStateMachine::EvRARReceived,
                       StPendingU,acRARReceived);
    AddWildcardStateTableEntry(StPendingU, StTerminated);

    AddStateTableEntry(StPendingT,
                       DiameterCCClientStateMachine::EvSuccessfulTerminationAnswer,
                       StIdle);
    AddStateTableEntry(StPendingT,
                       DiameterCCClientStateMachine::EvTerminationAnswer,
                       StIdle,
                       acTerminationAnswer);
    AddStateTableEntry(StPendingT,
                       DiameterCCClientStateMachine::EvFailure,
                       StIdle);
    AddStateTableEntry(StPendingT,
                       DiameterCCClientStateMachine::EvChangeInRating,
                       StPendingT);
    AddWildcardStateTableEntry(StPendingT, StTerminated);

    AddStateTableEntry(StPendingE,
                       DiameterCCClientStateMachine::EvDirectDebitingAnswer,
                       StIdle,acDirectDebitingAnswer);
    AddStateTableEntry(StPendingE,
                       DiameterCCClientStateMachine::EvRefundAccountAnswer,
                       StIdle,acRefundAccountAnswer);
    AddStateTableEntry(StPendingE,
                       DiameterCCClientStateMachine::EvCheckBalanceAnswer,
                       StIdle,acCheckBalanceAnswer);
    AddStateTableEntry(StPendingE,
                       DiameterCCClientStateMachine::EvPriceEnquiryAnswer,
                       StIdle,acPriceEnquiryAnswer);
    AddStateTableEntry(StPendingE,
                       DiameterCCClientStateMachine::EvFailure,
                       StIdle,acServiceError);
    AddStateTableEntry(StPendingE,
                       DiameterCCClientStateMachine::EvTerminateService,
                       StIdle,acTerminateService);
    AddStateTableEntry(StPendingE,
                       DiameterCCClientStateMachine::EvGrantService,
                       StIdle,acGrantService);
    AddStateTableEntry(StPendingE,
                       DiameterCCClientStateMachine::EvTccExpired,
                       StPendingE,acTccExpired);
    AddStateTableEntry(StPendingE,
                       DiameterCCClientStateMachine::EvStoreRequestWithTFlag,
                       StIdle,acStoreRequestWithTFlag);
    AddStateTableEntry(StPendingE,
                       DiameterCCClientStateMachine::EvStoreRequest,
                       StIdle,acStoreRequest);
    AddWildcardStateTableEntry(StPendingE, StTerminated);

    AddStateTableEntry(StPendingB,
                       DiameterCCClientStateMachine::EvSuccessfulAnswer,
                       StIdle,acSuccessfulAnswer);
    AddStateTableEntry(StPendingB,
                       DiameterCCClientStateMachine::EvFailedAnswer,
                       StIdle,acFailedAnswer);
    AddStateTableEntry(StPendingB,
                       DiameterCCClientStateMachine::EvFailureToSend,
                       StIdle,acFailureToSend);
    AddWildcardStateTableEntry(StPendingB, StTerminated);
    
    InitialState(StIdle);
  }
  ~DiameterCCClientStateTable_S() {}
};

typedef 
ACE_Singleton<DiameterCCClientStateTable_S, ACE_Recursive_Thread_Mutex> 
DiameterCCClientStateTable;

DiameterCCClientStateMachine::DiameterCCClientStateMachine
(DiameterCCClientSession& s, DiameterJobHandle &h, ACE_Reactor &reactor)
  : AAA_StateMachineWithTimer<DiameterCCClientStateMachine>
(*this, *DiameterCCClientStateTable::instance(), reactor, "AAA_CC_CLIENT"),
    session(s),
    handle(h)
    //account (boost::shared_ptr<DiameterCCAccount>())
{}

	void 
DiameterCCClientStateMachine::SendCCR()
{
	std::unique_ptr<DiameterMsg> msg;

	if (Session().Send(msg) != AAA_ERR_SUCCESS) {
		AAA_LOG((LM_ERROR, "(%P|%t) \tFailed sending message.\n"));
	}
	else {
		AAA_LOG((LM_DEBUG, "(%P|%t) \tSent CC Request Message.\n"));
	}
}

	bool
DiameterCCClientStateMachine::InitialRequest()
{
	SendCCR();
	ScheduleTimer(EvTxExpired,
			10,
			0,
			EvTxExpired);
	return true;
}

	bool
DiameterCCClientStateMachine::InitialAnswer()
{
	CancelTimer(EvTxExpired);
	AAA_LOG((LM_DEBUG, "(%P|%t) \tTimer Cancelled.\n"));
	return true;
}

	bool
DiameterCCClientStateMachine::TerminationRequest()
{
	SendCCR();
	return true;
}


	bool
DiameterCCClientStateMachine::DirectDebitingRequest()
{
	SendCCR();
	return true;
}

	bool
DiameterCCClientStateMachine::RefundAccountRequest()
{
	SendCCR();
	return true;
}

	bool
DiameterCCClientStateMachine::CheckBalanceRequest()
{
	SendCCR();
	return true;
}

	bool
DiameterCCClientStateMachine::PriceEnquiryRequest()
{
	SendCCR();
	return true;
}

	bool
DiameterCCClientStateMachine::TxExpired()
{
	return true;
}
