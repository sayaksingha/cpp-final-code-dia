// @(#) $Id: aaa_session_msg_rx.h,v 1.1.4.1.2.1.2.3 2024/05/15 13:10:19 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_session_msg_rx.h
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
#ifndef __AAA_SESSION_MSG_RX_H__
#define __AAA_SESSION_MSG_RX_H__

#include "aaa_session_server_factory.h"
#include "aaa_route_msg_router.h"

class DIAMETERBASEPROTOCOL_EXPORT AAA_ProxyHandler
{
    public:
        AAA_ProxyHandler(list<diameter_unsigned32_t> ApplicationIdList)
        {
			  m_ApplicationIdList = ApplicationIdList;	
        }
        virtual ~AAA_ProxyHandler() {
        }

        /// This function is called when incomming request message is received
		  virtual AAAReturnCode RequestMsg(DiameterMsg &msg, 
				  DiameterPeerEntry *source, 
				  DiameterPeerEntry *&dest) {
            // Incomming request messages are received here.
            return (AAA_ERR_SUCCESS);
        }

        /// This function is called when incomming answer message is received
		  virtual AAAReturnCode AnswerMsg(DiameterMsg &msg, 
				  DiameterPeerEntry *source,
				  DiameterPeerEntry *&dest) {
            return (AAA_ERR_SUCCESS);
        }

        /// This function is called when incomming error message is received
		  virtual AAAReturnCode ErrorMsg(DiameterMsg &msg, 
				  DiameterPeerEntry *source,
				  DiameterPeerEntry *&dest) {
            return (AAA_ERR_SUCCESS);
        }

        list<diameter_unsigned32_t> &ApplicationIdList() {
            return m_ApplicationIdList;
        }

    protected:
        //diameter_unsigned32_t m_ApplicationId;
        list<diameter_unsigned32_t> m_ApplicationIdList;
};

class DIAMETERBASEPROTOCOL_EXPORT DiameterSessionFactoryMap : 
    private std::map<diameter_unsigned32_t, DiameterServerSessionFactory*>
{
    private:
        typedef std::map<diameter_unsigned32_t, DiameterServerSessionFactory*>::iterator 
            MapIterator;
    public:
        bool Add(DiameterServerSessionFactory &factory) {
           insert(std::pair<diameter_unsigned32_t, DiameterServerSessionFactory*>
                (factory.GetApplicationId(), &factory));
           return (true);
        }
        DiameterServerSessionFactory *Lookup(diameter_unsigned32_t appId) {
           MapIterator i = find(appId);
           return (i == end()) ? NULL : i->second;
        }
        bool Remove(diameter_unsigned32_t appId) {
           MapIterator i = find(appId);
           if (i != end()) {
               erase(i);
               return (true);
           }
           return (false);
        }
        bool Empty() {
            return std::map<diameter_unsigned32_t, 
                DiameterServerSessionFactory*>::empty();
        }
};

class DIAMETERBASEPROTOCOL_EXPORT DiameterProxyHandlerMap : 
    private std::map<diameter_unsigned32_t, AAA_ProxyHandler*> 
{
    private:
        typedef std::map<diameter_unsigned32_t, AAA_ProxyHandler*>::iterator 
            MapIterator;
    public:
        bool Add(AAA_ProxyHandler &handler) {
			  for(auto const & ApplicationId : handler.ApplicationIdList()) 	
				  insert(std::pair<diameter_unsigned32_t, AAA_ProxyHandler*>
						  (ApplicationId, &handler));
           return (true);
        }
        AAA_ProxyHandler *Lookup(diameter_unsigned32_t appId) {
           MapIterator i = find(appId);
           return (i == end()) ? NULL : i->second;
        }
        bool Remove(diameter_unsigned32_t appId) {
           MapIterator i = find(appId);
           if (i != end()) {
               erase(i);
               return (true);
           }
           return (false);
        }
};

class DiameterSessionMsgRx
{
    public:
       DiameterSessionMsgRx() :
           m_LocalHandler(*this),
           m_ProxyHandler(*this),
           m_ErrorHandler(*this) {
           DIAMETER_MSG_ROUTER()->RegisterHandler
               (DiameterMsgRouterHandlerTable::H_LOCAL, &m_LocalHandler);
           DIAMETER_MSG_ROUTER()->RegisterHandler
               (DiameterMsgRouterHandlerTable::H_PROXY, &m_ProxyHandler);
           DIAMETER_MSG_ROUTER()->RegisterHandler
               (DiameterMsgRouterHandlerTable::H_ERROR, &m_ErrorHandler);
       }
       virtual ~DiameterSessionMsgRx() {
           DIAMETER_MSG_ROUTER()->RemoveHandler(DiameterMsgRouterHandlerTable::H_LOCAL);
           DIAMETER_MSG_ROUTER()->RemoveHandler(DiameterMsgRouterHandlerTable::H_PROXY);
           DIAMETER_MSG_ROUTER()->RemoveHandler(DiameterMsgRouterHandlerTable::H_ERROR);
       }
       DiameterSessionFactoryMap &SessionFactoryMap() {
           return m_SessionFactoryMap;
       }
       DiameterProxyHandlerMap &ProxyHandlerMap() {
           return m_ProxyHandlerMap;
       }

    protected:
       virtual AAAReturnCode RxUnknownSession(std::unique_ptr<DiameterMsg> msg);

    protected:
       class RxLocalMsgHandler : public DiameterMsgRouterHandler {
           public:
              RxLocalMsgHandler(DiameterSessionMsgRx &rx) :
                  m_SessionRx(rx) {
              }
              int Request(std::unique_ptr<DiameterMsg> &msg,
                          DiameterPeerEntry *source,
                          DiameterPeerEntry *&dest);
              int Answer(std::unique_ptr<DiameterMsg> &msg,
                         DiameterPeerEntry *source,
                         DiameterPeerEntry *&dest);
           private:
              DiameterSessionMsgRx &m_SessionRx;
       };
       class RxProxyMsgHandler : public DiameterMsgRouterHandler {
           public:
              RxProxyMsgHandler(DiameterSessionMsgRx &rx) :
                  m_SessionRx(rx) {
              }
              int Request(std::unique_ptr<DiameterMsg> &msg,
                          DiameterPeerEntry *source,
                          DiameterPeerEntry *&dest);
              int Answer(std::unique_ptr<DiameterMsg> &msg,
                          DiameterPeerEntry *source,
                         DiameterPeerEntry *&dest);
           private:
              DiameterSessionMsgRx &m_SessionRx;
       };
       class RxErrorMsgHandler : public DiameterMsgRouterHandler {
           public:
              RxErrorMsgHandler(DiameterSessionMsgRx &rx) :
                  m_SessionRx(rx) {
              }
              int Request(std::unique_ptr<DiameterMsg> &msg,
                          DiameterPeerEntry *source,
                          DiameterPeerEntry *&dest) {
					  std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
					  AAA_LOG((LM_DEBUG, "%T |SESSION| %s {Destination-Realm:%s} {Destination-Host:%s}, Request Message Error\n",
								  lLogText.c_str(),msg->destinationRealm.c_str(),msg->destinationHost.c_str()));
                  DiameterMsgHeaderDump::Dump(*msg);
                  return LocalErrorHandling(msg, source, dest);
              }
              int Answer(std::unique_ptr<DiameterMsg> &msg,
                         DiameterPeerEntry *source,
                         DiameterPeerEntry *&dest) {
					  std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
					  AAA_LOG((LM_DEBUG, "%T |SESSION| %s {Destination-Realm:%s} {Destination-Host:%s}, Answer Message Error\n",
								  lLogText.c_str(),msg->destinationRealm.c_str(),msg->destinationHost.c_str()));
                  DiameterMsgHeaderDump::Dump(*msg);
                  return LocalErrorHandling(msg, source, dest);
              }
              int LocalErrorHandling(std::unique_ptr<DiameterMsg> &msg,
                                     DiameterPeerEntry *source,
                                     DiameterPeerEntry *&dest);
           private:
              DiameterSessionMsgRx &m_SessionRx;
       };

    private:
       void TxASA(std::unique_ptr<DiameterMsg> &msg);

    private:
       DiameterSessionFactoryMap m_SessionFactoryMap;
       DiameterProxyHandlerMap m_ProxyHandlerMap;
       RxLocalMsgHandler m_LocalHandler;
       RxProxyMsgHandler m_ProxyHandler;
       RxErrorMsgHandler m_ErrorHandler;

       friend class RxLocalMsgHandler;
       friend class RxProxyMsgHandler;
       friend class RxErrorMsgHandler;
};

#endif // __AAA_SESSION_MSG_RX_H__

