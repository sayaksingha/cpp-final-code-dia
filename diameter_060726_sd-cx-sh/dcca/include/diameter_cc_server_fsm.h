// @(#) $Id: diameter_cc_server_fsm.h,v 1.1.2.1 2018/02/21 23:29:56 shijuc Exp $
//---------------------------------------------------------------
// NAME : diameter_cc_server_fsm.h
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
#ifndef __CC_SERVER_FSM_H__
#define __CC_SERVER_FSM_H__

#include "framework.h"
#include "diameter_cc_parser.h"

#ifdef WIN32
   #if defined(DIAMETER_CC_SERVER_EXPORT)
       #define DIAMETER_CC_SERVER_EXPORTS __declspec(dllexport)
   #else
       #define DIAMETER_CC_SERVER_EXPORTS __declspec(dllimport)
   #endif
#else
   #define DIAMETER_CC_SERVER_EXPORTS
   #define DIAMETER_CC_SERVER_EXPORTS
#endif

typedef AAA_JobHandle<AAA_GroupedJob> DiameterCCJobHandle;

class DiameterCCServerSession;

class DIAMETER_CC_SERVER_EXPORTS DiameterCCServerStateMachine 
  : public AAA_StateMachineWithTimer<DiameterCCServerStateMachine>,
    public AAA_EventQueueJob
{
 public:
  /// Constructor.
  DiameterCCServerStateMachine(DiameterCCServerSession& s,
                               DiameterCCJobHandle &h,
                               ACE_Reactor &reactor);

  ~DiameterCCServerStateMachine() 
  {
    handle.Job().Remove(this); 
    AAA_StateMachineWithTimer<DiameterCCServerStateMachine>::Stop(); 
  }

  enum {
    EvInitialRequest,
    EvValidInitialRequest,
    EvInvalidInitialRequest,
    EvInitialRequestSuccessful,
    EvInitialRequestUnsuccessful,

    EvUpdateRequest,
    EvValidUpdateRequest,
    EvInvalidUpdateRequest,
    EvUpdateRequestSuccessful,
    EvUpdateRequestUnsuccessful,

    EvTerminationRequest,
    EvValidTerminationRequest,
    EvInvalidTerminationRequest,
    EvTerminationRequestSuccessful,
    EvTerminationRequestUnsuccessful,

    EvDirectDebitingRequest,
    EvValidDirectDebitingRequest,
    EvInvalidDirectDebitingRequest,
    EvDirectDebitingRequestSuccessful,
    EvDirectDebitingRequestUnsuccessful,

    EvRefundAccountRequest,
    EvValidRefundAccountRequest,
    EvInvalidRefundAccountRequest,
    EvRefundAccountRequestSuccessful,
    EvRefundAccountRequestUnsuccessful,

    EvCheckBalanceRequest,
    EvValidCheckBalanceRequest,
    EvInvalidCheckBalanceRequest,
    EvCheckBalanceRequestSuccessful,
    EvCheckBalanceRequestUnsuccessful,

    EvPriceEnquiryRequest,
    EvValidPriceEnquiryRequest,
    EvInvalidPriceEnquiryRequest,
    EvPriceEnquiryRequestSuccessful,
    EvPriceEnquiryRequestUnsuccessful,

    EvTccExpired,

    EvSgDisconnect,
    EvSgSessionTimeout,
    EvSgTimeout

  };

  /// Store an event and notify the session.
  inline void Notify(AAA_Event ev) throw (int) {
    // Enqueue the event.
    if (AAA_EventQueueJob::Enqueue(ev) <= 0)
      Abort();

    if (handle.Job().Schedule(this) < 0)
      Abort();
  }

  virtual void Timeout(AAA_Event ev) {
    Notify(ev);
  }

  /// This is used for obtaining the reference to the server session
  /// object.
  inline DiameterCCServerSession& Session() { return session; }

  /// This is used for aborting the state machine.  Usually called
  /// when Notify() fails.
  virtual void Abort() = 0;

  /// This is used for constructing and sending an CCA.
  void SendCCA();

  /// Validate Initial Request.  
  virtual bool ValidateInitialRequest() {return true;};

  /// Initial Request action.  
  virtual bool InitialRequest() {return true;};

  virtual bool InitialAnswer() {return true;};

  /// Validate Update Request.  
  virtual bool ValidateUpdateRequest() {return true;};

  /// Update Request action.  
  virtual bool UpdateRequest() {return true;};

  /// Validate Termination Request.  
  virtual bool ValidateTerminationRequest() {return true;};

  /// Termination Request action.  
  virtual bool TerminationRequest() {return true;};

  /// Validate Direct Debiting Request.  
  virtual bool ValidateDirectDebitingRequest() {return true;};

  /// Direct Debiting Request action.  
  virtual bool DirectDebitingRequest() {return true;};

  /// Validate Refund Account Request.  
  virtual bool ValidateRefundAccountRequest() {return true;};

  /// Refund Account Request action.  
  virtual bool RefundAccountRequest() {return true;};

  /// Validate Check Balance Request.    
  virtual bool ValidateCheckBalanceRequest() {return true;};

  /// Check Balance Request action.  
  virtual bool CheckBalanceRequest() {return true;};

  /// Validate Price Enquiry Request.  
  virtual bool ValidatePriceEnquiryRequest() {return true;};

  /// Price Enquiry Request action.  
  virtual bool PriceEnquiryRequest() {return true;};

  inline AAA_JobData& JobData() { return *handle.Job().Data(); }

  template <class T> inline T& JobData(Type2Type<T>) 
  { return (T&)*handle.Job().Data(); }

 private:
  /// Inherited from AAA_EventQueueJob.  Not used.
  int Schedule(AAA_Job*, size_t=1) { return (-1); }

  /// Inherited from AAA_EventQueueJob.
  inline int Serve()
  {
    if (!AAA_EventQueueJob::ExistBacklog())
      {
        AAA_LOG((LM_ERROR, "%N: no backlog to serve."));
        return 0;
      }

    // Obtain the event to execute.
    AAA_Event ev = 0;
    AAA_EventQueueJob::Dequeue(ev);

    bool existBacklog = AAA_EventQueueJob::ExistBacklog();

    // Execute it.
    Event(ev);
    return existBacklog ? 1 : 0;
  }

  DiameterCCServerSession& session;

  // Job handle.
  DiameterCCJobHandle handle;

protected:
  DiameterMsg dccaMsg;

};

#endif
