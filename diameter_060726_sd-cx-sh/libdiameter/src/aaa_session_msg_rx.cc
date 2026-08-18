static const char *id = " @(#) $Id: aaa_session_msg_rx.cc,v 1.1.4.1.2.1.2.4 2024/05/15 13:11:50 mram Exp $";
//----------------------------------------------------------------------
// NAME
// aaa_session_msg_rx.cc
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
#include "aaa_session_db.h"
#include "aaa_session_msg_rx.h"

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterSessionMsgRx::RxLocalMsgHandler::Request (std::unique_ptr<DiameterMsg> &msg,  
		DiameterPeerEntry *source, DiameterPeerEntry *&dest)
{
    // Note that request message needs to be 
    // maintained and will be delete by the
    // router when a corresponding answer 
    // is received

	std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
	AAA_LOG((LM_INFO,"%T |SESSION| %s Local Request Message Received\n", lLogText.c_str()));
    DiameterSessionId sid;

    if (sid.Get(*msg) == AAA_ERR_SUCCESS) 
	 {
        AAA_JobData *data = NULL;
        if (DIAMETER_SESSION_DB().Lookup(sid, data)) 
		  {
			  AAA_LOG((LM_INFO,"%T |SESSION| %s Session lookup success\n", lLogText.c_str()));
            try 
				{
               DiameterSessionIO *io = (DiameterSessionIO*)data;
               io->RxRequest(std::move(msg));
            }
            catch (...) 
				{
					AAA_LOG((LM_ERROR,"%T |SESSION| %s caught Exception on Session lookup\n", lLogText.c_str()));
					source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
            }
            return (0);
        }
        else if (m_SessionRx.m_SessionFactoryMap.Empty()) 
		  {
            m_SessionRx.RxUnknownSession(std::move(msg));
				source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
            return (0);
        }

		  AAA_LOG((LM_INFO,"%T |SESSION| %s creating new session\n", lLogText.c_str()));	
        DiameterServerSessionFactory *factory = m_SessionRx.m_SessionFactoryMap.Lookup(msg->hdr.mApplId);
        if (factory) 
		  {
            DiameterSessionIO *newSession = factory->CreateInstance();
            if (newSession) 
				{
                try 
					 {
                    newSession->RxRequest(std::move(msg));
                    DIAMETER_SESSION_DB().Add(sid, *newSession);
                }
                catch (DiameterBaseException &e) 
					 {
						 source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
                    if (e.Code() == DiameterBaseException::MISSING_SESSION_ID) 
						  {
                        delete newSession;
                    }
                    AAA_LOG((LM_ERROR,"%T |SESSION| %s Processing error in new session\n", lLogText.c_str()));
                }
                catch (...) 
					 {
						 source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
                    AAA_LOG((LM_ERROR,"%T |SESSION| %s Caught Exception on creating new session\n", lLogText.c_str()));
                }
                return (0);
            }
            else 
				{
					source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
					AAA_LOG((LM_ERROR,"%T |SESSION| %s Failed to create new session, discarding req msg\n", lLogText.c_str()));
            }
        }
        else {
			  source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
            AAA_LOG((LM_DEBUG,"%T |SESSION| %s Un-supported application id:%d, discarding req msg\n", lLogText.c_str(),msg.get()->hdr.mApplId));
        }
    }
    else 
	 {
		 source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		 AAA_LOG((LM_DEBUG,"%T |SESSION| %s Missing session id, discard req msg\n", lLogText.c_str()));
    }
    DiameterMsgHeaderDump::Dump(*msg);
    return (-1);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterSessionMsgRx::RxLocalMsgHandler::Answer(std::unique_ptr<DiameterMsg> &msg, 
		DiameterPeerEntry *source,  DiameterPeerEntry *&dest)
{
    // Note that answer message will be delete
    // when this function exits since they are
    // not stored by the router

	std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
	AAA_LOG((LM_INFO,"%T |SESSION| %s Local Answer Message Received\n", lLogText.c_str()));
    DiameterSessionId sid;
    if (sid.Get(*msg) == AAA_ERR_SUCCESS) 
	 {
        AAA_JobData *data = NULL;
        if (DIAMETER_SESSION_DB().Lookup(sid, data)) 
		  {
            try 
				{
               DiameterSessionIO *io = (DiameterSessionIO*)data;
               io->RxAnswer(std::move(msg));
            }
            catch (...) 
				{
					source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
					AAA_LOG((LM_ERROR,"%T |SESSION| %s caught Exception on Session lookup\n", lLogText.c_str()));
            }
            return (0);
        }
        else {
			  source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
            AAA_LOG((LM_DEBUG,"%T |SESSION| %s Unknown session id, discard answer msg\n", lLogText.c_str()));
        }
    }
    else {
		 source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		 AAA_LOG((LM_DEBUG,"%T |SESSION| %s Missing session id, discard answer msg\n", lLogText.c_str()));
    }
    DiameterMsgHeaderDump::Dump(*msg);
    return (-1);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAAReturnCode DiameterSessionMsgRx::RxUnknownSession(std::unique_ptr<DiameterMsg> msg)
{
    // special base protocol handling for unknown session id
    if (msg->hdr.mCmdCode == DIAMETER_MSGCODE_ABORTSESSION) 
	 {
        TxASA(msg);
        return (AAA_ERR_SUCCESS);
    }
	 std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
    AAA_LOG((LM_DEBUG,"%T |SESSION| %s Unknown session, discarding msg\n", lLogText.c_str()));
    return (AAA_ERR_FAILURE);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterSessionMsgRx::RxProxyMsgHandler::Request (std::unique_ptr<DiameterMsg> &msg, 
		DiameterPeerEntry *source,  DiameterPeerEntry *&dest)
{
    // Note that request message needs to be 
    // maintained and will be delete by the
    // router when a corresponding answer 
    // is received
    //return (0);
	std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
	AAA_LOG((LM_INFO,"%T |SESSION| %s Proxy Request Message Received\n", lLogText.c_str()));
	AAA_ProxyHandler *handler = m_SessionRx.m_ProxyHandlerMap.Lookup(msg->hdr.mApplId);

    if (handler) 
	 {
        return (handler->RequestMsg(*msg, source, dest) == AAA_ERR_SUCCESS) ? 0 : (-1);
    }
    else {
		 source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		 AAA_LOG((LM_ERROR,"%T |SESSION| %s No proxy support for appId=%d, forwarding message\n", lLogText.c_str(),msg->hdr.mApplId));
    }
    DiameterMsgHeaderDump::Dump(*msg);
    return (-1);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterSessionMsgRx::RxProxyMsgHandler::Answer (std::unique_ptr<DiameterMsg> &msg,
		DiameterPeerEntry *source,  DiameterPeerEntry *&dest)
{
    // Note that answer message will be delete
    // when this function exits since they are
    // not stored by the router
    //return (0);
    auto start = std::chrono::high_resolution_clock::now();
    std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
    AAA_LOG((LM_INFO,"%T |SESSION| %s Proxy Answer Message Received\n", lLogText.c_str()));
    AAA_ProxyHandler *handler = m_SessionRx.m_ProxyHandlerMap.Lookup(msg->hdr.mApplId);
    //AAA_ProxyHandler *handler = m_SessionRx.m_ProxyHandlerMap.Lookup (msg->hdr.mApplId);

    if (handler) 
	 {
		 handler->AnswerMsg(*msg, source, dest);
       auto end = std::chrono::high_resolution_clock::now();
       std::chrono::duration<double, std::milli> elapsed = end - start;
       AAA_LOG((LM_INFO,"%T |SESSION| Answer RTT: %.3f ms\n", elapsed.count()));
		 return (0);
    }
	 source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
	 AAA_LOG((LM_ERROR,"%T |SESSION| %s No proxy support for appId:%d, forwarding message\n", lLogText.c_str(),msg->hdr.mApplId));
    return (-1);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterSessionMsgRx::RxErrorMsgHandler::LocalErrorHandling(std::unique_ptr<DiameterMsg> &msg,
		DiameterPeerEntry *source,  DiameterPeerEntry *&dest) 
{
	std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
	AAA_LOG((LM_INFO,"%T |SESSION| %s Error in received message\n", lLogText.c_str()));
    DiameterSessionId sid;
    if (sid.Get(*msg) == AAA_ERR_SUCCESS) 
	 {
        AAA_ProxyHandler *handler = NULL;
        AAA_JobData *data = NULL;
        if (DIAMETER_SESSION_DB().Lookup(sid, data)) 
		  {
            try 
				{
               DiameterSessionIO *io = (DiameterSessionIO*)data;
               io->RxError(std::move(msg));
            }
            catch (...) {
					source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
					AAA_LOG((LM_ERROR,"%T |SESSION| %s caught Exception on Session lookup\n",lLogText.c_str()));
            }
            return (0);
        }
        else if ((handler = m_SessionRx.m_ProxyHandlerMap.Lookup(msg->hdr.mApplId))) 
		  {
            handler->ErrorMsg(*msg, source, dest);
            return (0);
        }
        else 
		  {
			  source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
			  AAA_LOG((LM_DEBUG,"%T |SESSION| %s Error message with no local handler, resume routing\n", lLogText.c_str()));
        }
    }
    else 
	 {
		 source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
		 AAA_LOG((LM_DEBUG,"%T |SESSION| %s Error message with missing session id\n", lLogText.c_str()));
    }
	 source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
	 AAA_LOG((LM_DEBUG, "%T |SESSION| %s Discarding message\n", lLogText.c_str()));
    return (-1);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterSessionMsgRx::TxASA(std::unique_ptr<DiameterMsg> &asr)
{
	std::string lLogText = LOG_DIAMETER_AVPS(*asr);	
	AAA_LOG((LM_INFO,"%T |SESSION| %s Sending ASA Message\n",lLogText.c_str()));
    /*
        8.5.2.  Abort-Session-Answer

        The Abort-Session-Answer (ASA), indicated by the Command-Code set to
        274 and the message flags' 'R' bit clear, is sent in response to the
        ASR.  The Result-Code AVP MUST be present, and indicates the
        disposition of the request.

        If the session identified by Session-Id in the ASR was successfully
        terminated, Result-Code is set to DIAMETER_SUCCESS.  If the session
        is not currently active, Result-Code is set to
        DIAMETER_UNKNOWN_SESSION_ID.  If the access device does not stop the
        session for any other reason, Result-Code is set to
        DIAMETER_UNABLE_TO_COMPLY.

        Message Format

            <ASA>  ::= < Diameter Header: 274, PXY >
                        < Session-Id >
                        { Result-Code }
                        { Origin-Host }
                        { Origin-Realm }
                        [ User-Name ]
                        [ Origin-State-Id ]
                        [ Error-Message ]
                        [ Error-Reporting-Host ]
                      * [ Failed-AVP ]
                      * [ Redirect-Host ]
                        [ Redirect-Host-Usage ]
                        [ Redirect-Max-Cache-Time ]
                      * [ Proxy-Info ]
                      * [ AVP ]
   */

   std::unique_ptr<DiameterMsg> msg(new DiameterMsg);
   ACE_OS::memset(&msg->hdr, 0, sizeof(msg->hdr));
   msg->hdr.mVersion = DIAMETER_PROTOCOL_VERSION;
   msg->hdr.mMsgLen = 0;
   msg->hdr.mCmdFlg.rBit = DIAMETER_FLAG_CLR;
   msg->hdr.mCmdFlg.pBit = DIAMETER_FLAG_CLR;
   msg->hdr.mCmdFlg.eBit = DIAMETER_FLAG_CLR;
   msg->hdr.mCmdCode = DIAMETER_MSGCODE_ABORTSESSION;
   msg->hdr.mApplId = DIAMETER_BASE_APPLICATION_ID;

   // required
   DiameterSessionId sid;
   sid.Get(*asr);
   sid.Set(*msg);
   msg->hdr.mHopByHopId = asr->hdr.mHopByHopId;
   msg->hdr.mEndToEndId = asr->hdr.mEndToEndId;

	diameter_integer32_t     rcodeAvp;
	std::string              orHostAvp;
	std::string					 orRealmAvp;
	std::string              orErrMsgAvp;
	std::string              orErrHostAvp;

// DiameterUInt32AvpWidget rcodeAvp((char *)DIAMETER_AVPNAME_RESULTCODE);
//   DiameterIdentityAvpWidget orHostAvp((char *)DIAMETER_AVPNAME_ORIGINHOST);
//   DiameterIdentityAvpWidget orRealmAvp((char *)DIAMETER_AVPNAME_ORIGINREALM);
//   DiameterUtf8AvpWidget orErrMsgAvp((char *)DIAMETER_AVPNAME_ERRORMESSAGE);
//   DiameterIdentityAvpWidget orErrHostAvp((char *)DIAMETER_AVPNAME_ERRORREPORTINGHOST);

   /*rcodeAvp           = AAA_UNKNOWN_SESSION_ID; -- TBC vicky
   orHostAvp          = DIAMETER_CFG_TRANSPORT()->identity;
   orRealmAvp         = DIAMETER_CFG_TRANSPORT()->realm;
   orErrMsgAvp        = std::string("Unknown Session Id");
   orErrHostAvp       = DIAMETER_CFG_TRANSPORT()->identity;*/

//   msg->acl.add(rcodeAvp());
//   msg->acl.add(orHostAvp());
//   msg->acl.add(orRealmAvp());
//   msg->acl.add(orErrMsgAvp());
//   msg->acl.add(orErrHostAvp());

   DIAMETER_MSG_ROUTER()->AnswerMsg(std::move(msg), 0);
}
