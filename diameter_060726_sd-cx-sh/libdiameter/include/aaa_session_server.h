// @(#) $Id: aaa_session_server.h,v 1.1.4.1.2.1.2.1 2024/05/15 13:11:22 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_session_server.h
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
#ifndef __AAA_SESSION_SERVER_H__
#define __AAA_SESSION_SERVER_H__

#include "diameter_parser.h"
#include "aaa_session_auth_server_fsm.h"

///
/// This class provides all the functionality of
/// an Diameter client auth session. Applications
/// needs to use the server session factory which
/// generates instance of this class.
///
class DIAMETERBASEPROTOCOL_EXPORT DiameterServerAuthSession :
    public DiameterAuthSession 
{
    public:
        DiameterServerAuthSession(AAA_Task &task,
                              diameter_unsigned32_t id);
        virtual ~DiameterServerAuthSession() {
           m_Fsm.Stop();
        }

        /// This fucntion sends a message to the peer session
        virtual AAAReturnCode Send(std::unique_ptr<DiameterMsg> msg);

        /// Initiates a server side Re-Authentication
        AAAReturnCode ReAuth(diameter_unsigned32_t type);

        /// This function terminates the AAA session
        AAAReturnCode End();

    protected:
        /// This fucntion is called by the internal message rx
        virtual void RxRequest(std::unique_ptr<DiameterMsg> msg);

        /// This fucntion is called by the internal message rx
        virtual void RxAnswer(std::unique_ptr<DiameterMsg> msg);

        /// This fucntion is called by the internal message rx
        virtual void RxError(std::unique_ptr<DiameterMsg> msg);



        /// This fucntion is called internally to handle messages
        virtual AAAReturnCode RxDelivery(std::unique_ptr<DiameterMsg> msg);

        /// This fucntion is called internally to route messages
        virtual AAAReturnCode TxDelivery(std::unique_ptr<DiameterMsg> msg);

        /// This function resets the current session attributes to default
        virtual AAAReturnCode Reset();

    private:
        DiameterAuthSessionServerStateMachine m_Fsm;
};

///
/// Internal garbage collector definitions
///

typedef DiameterGarbageCollectorSingleton<DiameterAuthSession>
             DiameterServerAuthSessionGC;

typedef ACE_Singleton<DiameterServerAuthSessionGC,
                      ACE_Recursive_Thread_Mutex> 
                      DiameterServerAuthSessionGC_S;
#define DIAMETER_AUTH_SESSION_GC_ROOT() (DiameterServerAuthSessionGC_S::instance())
#define DIAMETER_AUTH_SESSION_GC() (DiameterServerAuthSessionGC_S::instance()->Instance()) 


#endif

