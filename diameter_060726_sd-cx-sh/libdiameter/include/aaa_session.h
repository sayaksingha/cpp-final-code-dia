// @(#) $Id: aaa_session.h,v 1.1.4.1.2.1.2.1 2024/05/15 13:10:19 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_session.h
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
#ifndef __AAA_SESSION_H__
#define __AAA_SESSION_H__

#include "framework.h"
#include "aaa_data_defs.h"
#include "aaa_session_attributes.h"
#include "aaa_route_msg_router.h"
#include "aaa_garbage_collector.h"
#include "aaa_parser_defs.h"

class DIAMETERBASEPROTOCOL_EXPORT DiameterSessionIO :
    public AAA_JobData
{
    public:
        /// This fucntion sends a message to the peer session
        virtual AAAReturnCode Send(std::unique_ptr<DiameterMsg> msg) = 0;

        /// This fucntion is called by the internal message rx
        virtual void RxRequest(std::unique_ptr<DiameterMsg> msg) = 0;

        /// This fucntion is called by the internal message rx
        virtual void RxAnswer(std::unique_ptr<DiameterMsg> msg) = 0;

        /// This fucntion is called by the internal message rx
        virtual void RxError(std::unique_ptr<DiameterMsg> msg) = 0;

        virtual ~DiameterSessionIO() {
	}
};

template<class ATTRIBUTE>
class DiameterSession :
    public DiameterSessionIO,
    public DiameterGarbageCollectorAttribute
{
    public:
        virtual ~DiameterSession() {
        }
		
        /// This function is used for setting Auth-Session-State 
        virtual void SetSessionTimeout (diameter_unsigned32_t &timeout)
        {
        }

        /// This function is called when incomming request message is received
        virtual AAAReturnCode ReStart() 
		  {
            // For AAA clients, initialization can be
            // done here and a service specific request
            // message should be sent here. If successful
            // an AAA_ERR_SUCCESS must be returned else 
            // it is considered a failure. For AAA servers, 
            // the application can do initialization routines 
            // here and the return value of this handler is
            // ignored by the library.
            return (AAA_ERR_SUCCESS);
        }

        /// This function is called when incomming request message is received
        virtual AAAReturnCode RequestMsg(DiameterMsg &msg) {
            // Incomming request messages are received here.
            return (AAA_ERR_SUCCESS);
        }

        /// This function is called when incomming answer message is received
        virtual AAAReturnCode AnswerMsg(DiameterMsg &msg) {
            return (AAA_ERR_SUCCESS);
        }

        /// This function is called when incomming answer message is received
        virtual AAAReturnCode ErrorMsg(DiameterMsg &msg) {
            return (AAA_ERR_SUCCESS);
        }

        /// This function is called when session has gone to open state
        virtual AAAReturnCode Success() {
            return (AAA_ERR_SUCCESS);
        }

        /// This function is called on session disconnection
        virtual AAAReturnCode Disconnect() {
            return (AAA_ERR_SUCCESS);
        }

        /// This function is called when a stateless session is getting reclaimed
        virtual AAAReturnCode ReClaimSession() {
            return (AAA_ERR_SUCCESS);
        }

        /// This function is called on session timeout
        virtual AAAReturnCode SessionTimeout() {
            return (AAA_ERR_SUCCESS);
        }

        /// This fucntion is called internally to handle messages
        virtual AAAReturnCode RxDelivery(std::unique_ptr<DiameterMsg> msg) {
            // by default, discard msg
            return (AAA_ERR_SUCCESS);
	}

        /// This fucntion is called internally to route messages
        virtual AAAReturnCode TxDelivery(std::unique_ptr<DiameterMsg> msg);

        /// This function resets the current session attributes to default
        virtual AAAReturnCode Reset();

        /// This function returns the current session attributes
        ATTRIBUTE &Attributes() {
            return m_Attributes;
        }

    protected:
        DiameterSession(diameter_unsigned32_t appId) {
           Reset();
           m_Attributes.ApplicationId() = appId;
	}

    protected:
        ATTRIBUTE m_Attributes;
};






class DIAMETERBASEPROTOCOL_EXPORT DiameterAuthSession :
    public DiameterSession<DiameterAuthSessionAttributes>
{
    public:
        virtual ~DiameterAuthSession() {
        }

        /// This function is used for setting Auth-Session-State 
        virtual void SetAuthLifetimeTimeout(diameter_unsigned32_t &timeout)
        {
        }

        /// This function is used for setting Auth-Session-State 
        virtual void SetAuthGracePeriodTimeout(diameter_unsigned32_t &timeout)
        {
        }

        /// This function is used for setting Class AVP contents in STR msg
        virtual void SetClassAvp(diameter_octetstring_t &cls)
        {
        }

        /// This function called when an STA message contains a Class AVP
        virtual void ClassAvp(diameter_octetstring_t &cls)
        {
        }

        /// This function is used for setting Auth-Session-State 
        virtual void SetAuthSessionState(diameter_unsigned32_t &authState)
        {
        }

        /// This function is called when session has gone to open state
        virtual AAAReturnCode ReAuthenticate(diameter_unsigned32_t value) {
            return (AAA_ERR_SUCCESS);
        }

        /// This function is called on lifetime timeout
        virtual AAAReturnCode AuthorizationTimeout() {
            return (AAA_ERR_SUCCESS);
        }

        /// This function is called on rx of ASR
        virtual AAAReturnCode AbortSession() {
            return (AAA_ERR_SUCCESS);
        }

        virtual AAAReturnCode Reset() {
           return DiameterSession<DiameterAuthSessionAttributes>::Reset();
	}

    protected:
        DiameterAuthSession(diameter_unsigned32_t appId) : 
		DiameterSession<DiameterAuthSessionAttributes>(appId) {
           m_Attributes.SessionTimeout() = DIAMETER_CFG_AUTH_SESSION()->sessionTm;
           m_Attributes.AuthLifetime() = DIAMETER_CFG_AUTH_SESSION()->lifetimeTm;
           m_Attributes.AuthGrace() = DIAMETER_CFG_AUTH_SESSION()->graceTm;
           m_Attributes.AuthSessionState() = DIAMETER_CFG_AUTH_SESSION()->stateful;
	}
};

#include "aaa_session.inl"

#endif
