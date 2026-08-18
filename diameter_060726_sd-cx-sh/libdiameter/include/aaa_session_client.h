// @(#) $Id: aaa_session_client.h,v 1.1.2.1.2.1 2024/05/15 13:10:19 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_session_client.h
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
#ifndef __AAA_SESSION_CLIENT_H__
#define __AAA_SESSION_CLIENT_H__


#include "diameter_parser.h"
#include "aaa_session_auth_client_fsm.h"

///
/// This class provides all the functionality of
/// an Diameter client auth session. Applications
/// needs to create an instance of this object
/// or derived from this object to create a diameter
/// client session.
///
class DIAMETERBASEPROTOCOL_EXPORT DiameterClientAuthSession :
    public DiameterAuthSession 
{
    public:
        DiameterClientAuthSession(AAA_Task &task,
                                  diameter_unsigned32_t id) :
           DiameterAuthSession(id),
           m_Fsm(task, *this) {
        }
        virtual ~DiameterClientAuthSession(); 

        // This function initializes an AAA client session
        AAAReturnCode Begin(char *optionValue = 0);

        /// This fucntion sends a message to the peer session
        virtual AAAReturnCode Send(std::unique_ptr<DiameterMsg> msg);

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

        /// This function resets the current session attributes to default
        virtual AAAReturnCode Reset();

    private:
        DiameterAuthSessionClientStateMachine m_Fsm;
};


#endif

