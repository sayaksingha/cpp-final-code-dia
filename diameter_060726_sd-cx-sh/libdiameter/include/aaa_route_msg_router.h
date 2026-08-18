// @(#) $Id: aaa_route_msg_router.h,v 1.1.4.1.2.1.2.6 2024/05/15 13:08:41 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_route_msg_router.h
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
#ifndef __ROUTE_MSG_ROUTER_H__
#define __ROUTE_MSG_ROUTER_H__

#include "ace/Synch.h"
#include "ace/Singleton.h"
#include "aaa_route_framework.h"

typedef enum routerParams_s{
   DIAMETER_ROUTER_RETX_DIVISOR = 2,
   DIAMETER_ROUTER_MIN_RETX_INTERVAL = 300,
   DIAMETER_ROUTER_MAX_RETX_COUNT    = 10,
   DIAMETER_H2H_MIN_RETX_INTERVAL	 = 120
} routerParams_t;

class AAA_SyncHopByHopHandler;

class DiameterMsgRouterHandler
{
   public:
       virtual int Request(std::unique_ptr<DiameterMsg> &msg,
                           DiameterPeerEntry *source,
                           DiameterPeerEntry *&dest) = 0;
       virtual int Answer(std::unique_ptr<DiameterMsg> &msg,
                          DiameterPeerEntry *source,
                          DiameterPeerEntry *&dest)  = 0;

   protected:
      virtual ~DiameterMsgRouterHandler() { }
};

class DiameterMsgRouterHandlerTable
{
   /*
      Notes on the use of DiameterMsgRouterHandler. 
      In all cases, once the router has invoked
      the handler, the msg is consumed by the handler.
      The only exception is when you use H_PROXY.
      The router will not give up ownernship of
      msg to the handler so care should be given
      to its use
    */
   public:
       typedef enum {
           H_LOCAL,
           H_PROXY,
           H_ERROR,

           H_MAX
       } H_TYPE;
    
       void RegisterHandler(H_TYPE type,
                            DiameterMsgRouterHandler *h) {
           m_Handlers[type] = h;
       }
       void RemoveHandler(H_TYPE type) {
           m_Handlers[type] = NULL;
       }
       DiameterMsgRouterHandler *operator[](H_TYPE type) {
           return m_Handlers[type];
       }

   protected:
       DiameterMsgRouterHandlerTable() {
           for (int i=0; i<H_MAX; i++) {
               m_Handlers[i] = NULL;
           }
       }
       DiameterMsgRouterHandler *m_Handlers[H_MAX];
};

class DiameterMsgRouter : public DiameterRouterFramework,
                          public DiameterMsgRouterHandlerTable 
{
   public:

       class DcLocal : public DiameterDeliveryRoutingNode<DiameterMsgRouter> {
           public:
               DcLocal(DiameterMsgRouter &r) :
                   DiameterDeliveryRoutingNode<DiameterMsgRouter>(r, 0, (char *)"dcLocal") {
               }
               AAA_ROUTE_RESULT Process(std::unique_ptr<DiameterMsg> msg,
                                        //std::unique_ptr<DiameterMsg> &p,
                                        DiameterPeerEntry *source,
                                        DiameterPeerEntry *&dest);
               int RequestMsg(std::unique_ptr<DiameterMsg> msg,
                              DiameterPeerEntry *source,
                              DiameterPeerEntry *&dest);

               AAA_ROUTE_RESULT ErrorHandling(std::unique_ptr<DiameterMsg> msg,
                                              DiameterPeerEntry *source,
                                              DiameterPeerEntry *&dest);
       };

       class DcForward : public DiameterDeliveryRoutingNode<DiameterMsgRouter> {
           public:
               DcForward(DiameterMsgRouter &r) :
                   DiameterDeliveryRoutingNode<DiameterMsgRouter>(r, 0, (char *)"dcForward") {
               }
               AAA_ROUTE_RESULT Process(std::unique_ptr<DiameterMsg> msg,
                                        //std::unique_ptr<DiameterMsg> &p,
                                        DiameterPeerEntry *source,
                                        DiameterPeerEntry *&dest);
               int RequestMsg(std::unique_ptr<DiameterMsg> msg,
                              DiameterPeerEntry *source,
                              DiameterPeerEntry *&dest);
               int LoopDetection(std::unique_ptr<DiameterMsg> &msg);
       };

       class DcRouted : public DiameterDeliveryRoutingNode<DiameterMsgRouter> {
           public:
               DcRouted(DiameterMsgRouter &r) :
                   DiameterDeliveryRoutingNode<DiameterMsgRouter>(r, 0, (char *)"dcRouted") {
               }
               AAA_ROUTE_RESULT Process(std::unique_ptr<DiameterMsg> msg,
                                        //std::unique_ptr<DiameterMsg> &p,
                                        DiameterPeerEntry *source,
                                        DiameterPeerEntry *&dest);
               int RequestMsg(std::unique_ptr<DiameterMsg> msg,
                              DiameterPeerEntry *source,
                              DiameterPeerEntry *&dest);
					int SyncAddHopByHopId(SyncHopByHopIdData &data);
					int SyncDelHopByHopId(SyncHopByHopIdData &data);
					int GetSyncProxyHopByHopId(SyncHopByHopIdData &data);

	       int SendMsgAsync(std::unique_ptr<DiameterMsg> msg,
                     DiameterPeerEntry *source,
                     DiameterPeerEntry *dest);

	       int SendNackMsgAsync(std::unique_ptr<DiameterMsg> msg,
                     DiameterPeerEntry *source,
                     DiameterPeerEntry *dest);


       };

       class DcReject : public DiameterDeliveryRoutingNode<DiameterMsgRouter> {
           public:
               DcReject(DiameterMsgRouter &r) :
                   DiameterDeliveryRoutingNode<DiameterMsgRouter>(r, 0, (char *)"dcReject") {
               }
               AAA_ROUTE_RESULT Process(std::unique_ptr<DiameterMsg> msg,
                                        //std::unique_ptr<DiameterMsg> &p,
                                        DiameterPeerEntry *source,
                                        DiameterPeerEntry *&dest);
               int RequestMsg(std::unique_ptr<DiameterMsg> msg,
                              DiameterPeerEntry *source,
                              DiameterPeerEntry *&dest);
               AAA_ROUTE_RESULT Lookup(std::unique_ptr<DiameterMsg> &msg,
                                       //std::unique_ptr<DiameterMsg> &p,
													DiameterPeerEntry *source,
                                       DiameterPeerEntry *&dest);
		 //std::unique_ptr < DiameterMsg > GenerateError(DiameterMsg & request,	diameter_unsigned32_t	rcode) ;
       };

       class RcLocal : public DiameterRequestRoutingNode<DcLocal,
                       DiameterMsgRouter> {
           public:
               RcLocal(DiameterMsgRouter &r) :
                  DiameterRequestRoutingNode<DcLocal,
                                         DiameterMsgRouter>(r, 0, (char *)"rcLocal") { }

               AAA_ROUTE_RESULT Lookup(std::unique_ptr<DiameterMsg> &msg,
                                       //std::unique_ptr<DiameterMsg> &p,
													DiameterPeerEntry *source,
                                       DiameterPeerEntry *&dest);
       };

       class RcForwarded : public DiameterRequestRoutingNode<DcForward,
                           DiameterMsgRouter> {
           public:
               RcForwarded(DiameterMsgRouter &r) :
                   DiameterRequestRoutingNode<DcForward,
                                          DiameterMsgRouter>(r, 0, (char *)"rcForward") {
               }
               AAA_ROUTE_RESULT Lookup(std::unique_ptr<DiameterMsg> &msg,
                                       //std::unique_ptr<DiameterMsg> &p,
													DiameterPeerEntry *source,
                                       DiameterPeerEntry *&dest);
           };

       class RcRouted : public DiameterRequestRoutingNode<DcRouted,
                        DiameterMsgRouter> {
           public:
               RcRouted(DiameterMsgRouter &r) :
                   DiameterRequestRoutingNode<DcRouted,
                                          DiameterMsgRouter>(r, 0, (char *)"rcRouted") {
               }
               AAA_ROUTE_RESULT Lookup(std::unique_ptr<DiameterMsg> &msg,
                                       //std::unique_ptr<DiameterMsg> &p,
													DiameterPeerEntry *source,
                                       DiameterPeerEntry *&dest);
/*
	       int SendMsgAsync(std::unique_ptr<DiameterMsg> msg,
                     DiameterPeerEntry *source,
                     DiameterPeerEntry *dest);
*/

       };

       class RcRejected : public DiameterRequestRoutingNode<DcReject,
                          DiameterMsgRouter> {
           public:
               RcRejected(DiameterMsgRouter &r) :
                   DiameterRequestRoutingNode<DcReject,
                                          DiameterMsgRouter>(r, 0, (char *)"rcReject") {
               }
               AAA_ROUTE_RESULT Lookup(std::unique_ptr<DiameterMsg> &msg,
                                       //std::unique_ptr<DiameterMsg> &p,
													DiameterPeerEntry *source,
                                       DiameterPeerEntry *&dest);
       };

		 int SyncProxyAddHopByHopId(SyncHopByHopIdData &data)
		 {
			 return m_rcRouted.Delivery().SyncAddHopByHopId(data);
		 }

		 int SyncProxyDelHopByHopId(SyncHopByHopIdData &data)
		 {
			 return m_rcRouted.Delivery().SyncDelHopByHopId(data);
		 }

		 void RegisterSyncProxyHopByHopId(AAA_SyncHopByHopHandler* handler)
		 {
			 m_SyncH2hHdlr = handler;
		 }

		 void RemoveSyncProxyHopByHopId()
		 {
			 m_SyncH2hHdlr = NULL;
		 }
	         
		 int SendMsgAsync(std::unique_ptr<DiameterMsg> msg,
				 DiameterPeerEntry *source,
				 DiameterPeerEntry *dest)
		 {
			 return m_rcRouted.Delivery().SendMsgAsync(std::move(msg), source, dest);
		 }
		 int SendNackMsgAsync(std::unique_ptr<DiameterMsg> msg,
				 DiameterPeerEntry *source,
				 DiameterPeerEntry *dest)
		 {
			 return m_rcRouted.Delivery().SendNackMsgAsync(std::move(msg), source, dest);
		 }


	protected:
		 class DcRequestReTransmission : public AAA_Action<DiameterRouterPendingReqPtr> {
			 public:
				 DcRequestReTransmission(DiameterMsgRouter &r) : 
       	           m_Router(r) 
				   {
       	      }
              virtual void operator()(DiameterRouterPendingReqPtr &pReq) 
				  {
              	   /* 
                     The T flag is used as an indication of an application layer
                     retransmission event, e.g., due to failover to an alternate server.
                     It is defined only for request messages sent by Diameter clients or
                     agents.  For instance, after a reboot, a client may not know whether
                     it has already tried to send the accounting records in its non-
                     volatile memory before the reboot occurred.  Diameter servers MAY use
                     the T flag as an aid when processing requests and detecting duplicate
                     messages.  However, servers that do this MUST ensure that duplicates
                     are found even when the first transmitted request arrives at the
                     server after the retransmitted request.  It can be used only in cases
                     where no answer has been received from the Server for a request and
                     the request is sent again, (e.g., due to a failover to an alternate
                     peer, due to a recovered primary peer or due to a client re-sending a
                     stored record from non-volatile memory such as after reboot of a
                     client or agent).
                   */
						if (pReq->m_ReqMessage.get())
						{
							std::string lLogText = LOG_DIAMETER_AVPS(*pReq->m_ReqMessage);	
							pReq->m_ReqMessage->hdr.mCmdFlg.tBit = DIAMETER_FLAG_SET;

							AAA_LOG((LM_INFO, "%T |ROUTE| %s {Destination-Realm:%s} {Destination-Host:%s}, Request message re-transmission\n", 
										lLogText.c_str(),	
										pReq->m_ReqMessage->destinationRealm.c_str(),
										pReq->m_ReqMessage->destinationHost.c_str()));
							DiameterMsgHeaderDump::Dump(*(pReq->m_ReqMessage));


							ACE_Time_Value expire(DIAMETER_CFG_TRANSPORT()->retx_interval, 0);
							pReq->m_ReTxExpireTime = ACE_OS::gettimeofday() + expire;

							m_Router.RequestMsg(std::move(pReq->m_ReqMessage), pReq->m_Source);
						}
              }
          private:
              DiameterMsgRouter &m_Router;
       };

   public:

       DiameterMsgRouter() : m_rcLocal(*this),
                         m_rcForward(*this),
                         m_rcRouted(*this),
                         m_rcRejected(*this) {

           //m_RequestChain.Add(&m_rcLocal);
           m_RequestChain.Add(&m_rcForward);
           m_RequestChain.Add(&m_rcRouted);
           m_RequestChain.Add(&m_rcRejected);

           //m_DeliveryChain.Add(&m_rcLocal.Delivery());
           m_DeliveryChain.Add(&m_rcForward.Delivery());
           m_DeliveryChain.Add(&m_rcRouted.Delivery());
           m_DeliveryChain.Add(&m_rcRejected.Delivery());

			  m_SyncH2hHdlr = NULL;
       }
       void ReTransmitEvent(DiameterPeerEntry *peer = 0) 
		 {
           DcRequestReTransmission reTx(*this);
		//	  AAA_Action<DiameterRetransmitMsgMapperPtr> reTxHopByHopId;

           if (peer) 
			  {
               m_rcForward.Delivery().ReTransmitCheck(peer, reTx);
               m_rcRouted.Delivery().ReTransmitCheck(peer, reTx);
           }
           else 
			  {
               ACE_Time_Value current = ACE_OS::gettimeofday();
               m_rcForward.Delivery().ReTransmitCheck(current, reTx);
               m_rcRouted.Delivery().ReTransmitCheck(current, reTx);

           }
       }

   protected:

       friend class DcLocal;
       friend class DcForward;
       friend class DcRouted;

       class RedirectAgent {
           public:
               int Request(std::unique_ptr<DiameterMsg> &msg,
                           DiameterPeerEntry *source,
                           DiameterPeerEntry *&dest);
               int Answer(std::unique_ptr<DiameterMsg> &msg,
                          //std::unique_ptr<DiameterMsg> p,
                          DiameterPeerEntry *source,
                          DiameterPeerEntry *&dest);
               bool IsRedirected(std::unique_ptr<DiameterMsg> &msg);
       };

   private:
       RcLocal               m_rcLocal;
       RcForwarded           m_rcForward;
       RcRouted              m_rcRouted;
       RcRejected            m_rcRejected;
       RedirectAgent         m_RedirectAgent;

		 static AAA_SyncHopByHopHandler* m_SyncH2hHdlr;

};

typedef ACE_Singleton<DiameterMsgRouter, ACE_Recursive_Thread_Mutex> DiameterMsgRouter_S;
#define DIAMETER_MSG_ROUTER() DiameterMsgRouter_S::instance()

class DIAMETERBASEPROTOCOL_EXPORT AAA_SyncHopByHopHandler
{
	public:
		virtual int SendSyncData(SyncHopByHopIdData &data)
		{
			return (0);
		}

		virtual int GetSyncData(SyncHopByHopIdData &data)
		{
			return (0);
		}

		int RecvSyncData(SyncHopByHopIdData &data)
		{
			if(SYNC_OP_ADD == data.op)
			{
				return DIAMETER_MSG_ROUTER()->SyncProxyAddHopByHopId(data);
			}
			else
			{
				return DIAMETER_MSG_ROUTER()->SyncProxyDelHopByHopId(data);
			}
		}
};

#endif /* __ROUTE_MSG_ROUTER_H__ */
