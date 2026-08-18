// @(#) $Id: aaa_session_msg_mux.h,v 1.1.4.1.2.1 2018/02/21 23:00:48 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_session_msg_mux.h
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
#ifndef __AAA_SESSION_MSG_MUX_H__
#define __AAA_SESSION_MSG_MUX_H__

#include <map>
#include "diameter_parser.h"

template<class ARG>
class DiameterSessionMsgMuxHandler
{
    public:
        virtual ~DiameterSessionMsgMuxHandler() {
	}
        /// This function is called when incomming request message is received
        virtual AAAReturnCode RequestMsg(ARG &arg, DiameterMsg &msg) = 0;

        /// This function is called when incomming answer message is received
        virtual AAAReturnCode AnswerMsg(ARG &arg, DiameterMsg &msg) = 0;

        /// This function is called when incomming error message is received
        virtual AAAReturnCode ErrorMsg(ARG &arg, DiameterMsg &msg) = 0;

    protected:
        DiameterSessionMsgMuxHandler() {
	}
};

template<class ARG>
class DiameterSessionMsgMux
{
    public:
        DiameterSessionMsgMux(ARG &arg) :
            m_Arg(arg) {
	}
        virtual ~DiameterSessionMsgMux() {
	}
        void Register(AAACommandCode code, DiameterSessionMsgMuxHandler<ARG> &handler) {
	    m_Map.insert(std::pair<AAACommandCode, 
                         DiameterSessionMsgMuxHandler<ARG>* >
                          (code, &handler));
	}
        void Remove(AAACommandCode code) {
	    typename std::map<AAACommandCode, 
		    DiameterSessionMsgMuxHandler<ARG>* >::iterator i = m_Map.find(code);
            if (i != m_Map.end()) {
		m_Map.erase(i);
	    }
	}
        AAAReturnCode Mux(DiameterMsg &msg) {
	    typename std::map<AAACommandCode, 
		    DiameterSessionMsgMuxHandler<ARG>* >::iterator i = m_Map.find(msg.hdr.code);
            if (i != m_Map.end()) {
                if (msg.hdr.flags.e) {
                    return i->second->ErrorMsg(m_Arg, msg);
                }
                else {
                    return (msg.hdr.flags.r) ? 
                            i->second->RequestMsg(m_Arg, msg) :
                            i->second->AnswerMsg(m_Arg, msg);
		}
	    }
            return (AAA_ERR_FAILURE);
	}

    private:
        ARG &m_Arg;
	std::map<AAACommandCode, 
		 DiameterSessionMsgMuxHandler<ARG>* > m_Map;
};

#endif
