// @(#) $Id: aaa_session_fsm.h,v 1.1.4.1.2.1.2.2 2024/05/15 13:10:19 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_session_fsm.h
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
#ifndef __AAA_SESSION_FSM_H__
#define __AAA_SESSION_FSM_H__

#include "framework.h"
#include "diameter_parser.h"

template<class ARG, class DEBUG>
class DiameterSessionStateMachine : public AAA_StateMachineWithTimer<ARG>
{
   public:
      virtual ~DiameterSessionStateMachine() {
          AAA_StateMachineWithTimer<ARG>::Stop();
      }    
      AAA_State State() {
          return AAA_StateMachineWithTimer<ARG>::state;
      }
      bool IsRunning() {
          return AAA_StateMachine<ARG>::Running();
      }

   private:
      std::unique_ptr<DiameterMsg>  m_PendingMsg;
      ACE_Recursive_Thread_Mutex m_EventFsmMtx;

   public:
      std::unique_ptr<DiameterMsg> &PendingMsg() {
         return m_PendingMsg;
      }
      virtual void Notify(AAA_Event event) {
         AAA_ScopeLock<ACE_Recursive_Thread_Mutex> guard(m_EventFsmMtx);
         Process(event);
      }
      virtual void Notify(AAA_Event event,
                          std::unique_ptr<DiameterMsg> msg) {
         AAA_ScopeLock<ACE_Recursive_Thread_Mutex> guard(m_EventFsmMtx);
         m_PendingMsg = std::move(msg);
         Process(event);
      }
   protected:
      DiameterSessionStateMachine(AAA_Task &t,
                              AAA_StateTable<ARG> &table,
                              ARG &arg) :
          AAA_StateMachineWithTimer<ARG>(arg, table, *t.reactor()) {
      }
      virtual void Process(AAA_Event ev) {

         m_Debug.DumpEvent(AAA_StateMachineWithTimer<ARG>::state, ev);

         if (! AAA_StateMachineWithTimer<ARG>::Running()) {
             AAA_LOG((LM_ERROR, "%T |SESSION| Session not running\n"));
             return;
         }

         try {
             AAA_StateMachineWithTimer<ARG>::Event(ev);
         }
         catch (DiameterBaseException &err) {
             AAA_LOG((LM_ERROR, "%T |SESSION| FSM error[%d]: %s\n",
                        err.Code(), err.Description().c_str()));
         }
         catch (...) {
             AAA_LOG((LM_ERROR, "%T |SESSION| Unknown exception in FSM\n"));
         }
      }
      virtual void Timeout(AAA_Event ev) {
         Notify(ev);
      }

   private:   
      DEBUG m_Debug;
};

#endif /* __AAA_SESSION_FSM_H__ */

