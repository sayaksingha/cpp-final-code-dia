// @(#) $Id: aaa_route_framework.h,v 1.1.4.1.2.1.2.10 2024/05/15 13:08:41 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_route_framework.h
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
#ifndef __ROUTE_FRAMEWORK_H__
#define __ROUTE_FRAMEWORK_H__

#include "diameter_parser.h"
#include "aaa_peer_table.h"
#include "aaa_route_id_generator.h"

typedef enum {
   AAA_ROUTE_RESULT_SUCCESS,
   AAA_ROUTE_RESULT_FAILED,
   AAA_ROUTE_RESULT_NEXT_CHAIN
} AAA_ROUTE_RESULT;

// abstract class for a routing node
class DiameterRoutingNode
{
   public:
       AAA_ROUTE_RESULT Route(std::unique_ptr<DiameterMsg> msg,
                              DiameterPeerEntry *source) 
		 {
           DiameterPeerEntry *dest = NULL;
           //std::unique_ptr<DiameterMsg> pending;
           //AAA_ROUTE_RESULT r = Lookup(msg, pending, source, dest);
           AAA_ROUTE_RESULT r = Lookup(msg, source, dest);
           Dump(r);

           switch (r) 
			  {
               case AAA_ROUTE_RESULT_SUCCESS:
                   //return Process(msg, pending, source, dest);
                   return Process(std::move(msg),source, dest);
               case AAA_ROUTE_RESULT_NEXT_CHAIN:
                   if (m_Next) 
						 {
                       return m_Next->Route(std::move(msg), source);
                   }
                   // fall through
               default:
						 std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
						 AAA_LOG((LM_ERROR, "%T |ROUTE| %s {Destination-Realm:%s} {Destination-Host:%s}, Message failed to route\n", 
									 lLogText.c_str(), msg->destinationRealm.c_str(),msg->destinationHost.c_str()));
                   DiameterMsgHeaderDump::Dump(*msg);
                   break;
           }
           return (r);
       }

       DiameterRoutingNode *Next() 
		 {
           return m_Next;
		 }

       void Next(DiameterRoutingNode *next) 
		 {
           m_Next = next;
       }

       std::string &Name() {
           return m_Name;
       }
                                       //std::unique_ptr<DiameterMsg> &p,
       virtual AAA_ROUTE_RESULT Lookup(std::unique_ptr<DiameterMsg> &m,
													DiameterPeerEntry *source,
                                       DiameterPeerEntry *&dest) = 0;

       virtual AAA_ROUTE_RESULT Process(std::unique_ptr<DiameterMsg> m,
                                        //std::unique_ptr<DiameterMsg> &p,
                                        DiameterPeerEntry *source,
                                        DiameterPeerEntry *&dest) = 0;

       virtual ~DiameterRoutingNode() {
       }
   protected:
       DiameterRoutingNode(DiameterRoutingNode *next = NULL,
                       const char *name = "") :
           m_Next(next), m_Name(name) {
       }
       void Dump(AAA_ROUTE_RESULT r) {
#if AAA_ROUTE_DEBUG
           switch (r) {
               case AAA_ROUTE_RESULT_NEXT_CHAIN:
                   AAA_LOG((LM_DEBUG, "%T |ROUTE| Route lookup %s defer to next chain\n", m_Name.c_str()));
                   break;
               case AAA_ROUTE_RESULT_SUCCESS:
                   AAA_LOG((LM_DEBUG, "%T |ROUTE| Route lookup %s successful, processing msg\n", m_Name.c_str()));
                   break;
               default:
                   AAA_LOG((LM_DEBUG, "%T |ROUTE| Route lookup %s failed, discarding msg\n", m_Name.c_str()));
                   break;
           }
#endif
       }

   private:
       DiameterRoutingNode *m_Next;
       std::string m_Name;
};

typedef struct 
{
   int m_OrigHH;
   int m_localHH;
	string m_sid;
   DiameterPeerEntry *m_Source;
   DiameterPeerEntry *m_Dest;
   ACE_Time_Value m_ReTxExpireTime;
   unsigned int m_ReTxCount;
   std::unique_ptr<DiameterMsg> m_ReqMessage;
} DiameterRouterPendingReq;

typedef DiameterRouterPendingReq* DiameterRouterPendingReqPtr;

typedef struct
{
	int 		m_OrigHH;
	int 	 	m_localHH;
	string 	m_sid;
   ACE_Time_Value m_H2hExpireTime;
} DiameterRetransmitMsgMapper;

typedef DiameterRetransmitMsgMapper* DiameterRetransmitMsgMapperPtr;

template<class ARG>
class DiameterDeliveryRoutingNode : public DiameterRoutingNode
{
   private:

       class PendingReqCleanup : public AAA_IterAction<DiameterRouterPendingReqPtr> 
		 {
          public:
             virtual bool operator()(DiameterRouterPendingReqPtr &r) {
                delete r;
                return true;
             }
       };

       template<class THRESHOLD>
       class PendingReqReTxCheck : public AAA_IterAction<DiameterRouterPendingReqPtr> 
		 {
          public:
             PendingReqReTxCheck(THRESHOLD thold,
                AAA_Action<DiameterRouterPendingReqPtr> &act) :
                m_Threshold(thold),
                m_Action(act) {
             }
             virtual bool operator()(DiameterRouterPendingReqPtr &r) 
				 {
                if (match(r)) 
					 {
                    if (r->m_ReTxCount < DIAMETER_CFG_TRANSPORT()->retx_max_count) 
						  {
                        r->m_ReTxCount++;
                        m_Action(r);
                    }
                    else 
						  {
							//	std::string lLogText = LOG_DIAMETER_AVPS(*(r->m_ReqMessage)); //TCB-Anshul 2 jan
                        AAA_LOG((LM_ERROR,
											"%T |ROUTE| SId:%s OrigHH:%d  localHH:%d Re-Transmission count exceeded, Request discarded\n",
											r->m_sid.c_str() ,  r->m_OrigHH  , r->m_localHH ));
                        delete r;
                        return (true);
                    }
                }
                return (false);
             }
             virtual bool match(DiameterRouterPendingReqPtr &r) = 0;
          protected:
             THRESHOLD m_Threshold;
             AAA_Action<DiameterRouterPendingReqPtr> &m_Action;
       };

       class PendingReqAgeCheck : public PendingReqReTxCheck<ACE_Time_Value> 
		 {
          public:
             PendingReqAgeCheck(ACE_Time_Value thold,
                AAA_Action<DiameterRouterPendingReqPtr> &act) :
                PendingReqReTxCheck<ACE_Time_Value>(thold, act) {
             }
             virtual bool match(DiameterRouterPendingReqPtr &r) 
				 {
                return (r->m_ReTxExpireTime < 
                        PendingReqReTxCheck<ACE_Time_Value>::m_Threshold);
             }
       };

       class PendingReqPeerCheck : public PendingReqReTxCheck<DiameterPeerEntry*> 
		 {
          public:
             PendingReqPeerCheck(DiameterPeerEntry *peer,
                AAA_Action<DiameterRouterPendingReqPtr> &act) :
                PendingReqReTxCheck<DiameterPeerEntry*>(peer, act) {
             }
             virtual bool match(DiameterRouterPendingReqPtr &r) 
				 {
					// TBC-NK:
					// Getting Segv while processing pending message in transmit queue
					// because we are removing message from retransmit queue
					 AAA_LOG((LM_DEBUG, "%T |ROUTE|  deleting connection \n" ));
					 return false;
                //return (r->m_Dest ==
                  //      PendingReqReTxCheck<DiameterPeerEntry*>::m_Threshold);
             }
       };


       class RetransmiteReqCleanup : public AAA_IterAction<DiameterRetransmitMsgMapperPtr>
       {
          public:
             virtual bool operator()(DiameterRetransmitMsgMapperPtr &r) {
                delete r;
                return true;
             }
       };

       template<class THRESHOLD>
       class PendingRetransmitHopByHopIdCheck : public AAA_IterAction<DiameterRetransmitMsgMapperPtr>
       {
          public:
             PendingRetransmitHopByHopIdCheck(THRESHOLD thold,
                AAA_Action<DiameterRetransmitMsgMapperPtr> &act) :
                m_Threshold(thold),
                m_Action(act) {
             }
             virtual bool operator()(DiameterRetransmitMsgMapperPtr &r)
             {
                if (match(r))
                {
						 AAA_LOG((LM_ERROR,
									 "%T |ROUTE| SId:%s OrigHH:%d  localHH:%d time out, Discarded Message\n",
									 r->m_sid.c_str() ,  r->m_OrigHH  , r->m_localHH ));
						 delete r;
						 return (true);
					 }
					 return (false);
				 }
				 virtual bool match(DiameterRetransmitMsgMapperPtr &r) = 0;
			 protected:
				 THRESHOLD m_Threshold;
				 AAA_Action<DiameterRetransmitMsgMapperPtr> &m_Action;
		 };

		 class RetransmiteHopByHopIdAgeCheck :public PendingRetransmitHopByHopIdCheck<ACE_Time_Value>
		 {
				public:
				RetransmiteHopByHopIdAgeCheck(ACE_Time_Value thold, AAA_Action<DiameterRetransmitMsgMapperPtr> &act) :
					PendingRetransmitHopByHopIdCheck<ACE_Time_Value>(thold, act) {
				}

				virtual bool match(DiameterRetransmitMsgMapperPtr &r)
				{
					return (r->m_H2hExpireTime <
							PendingRetransmitHopByHopIdCheck<ACE_Time_Value>::m_Threshold);
				}
		 };
       
		 class DcRequestReTransmissionHopByHopId : public AAA_Action<DiameterRetransmitMsgMapperPtr> {
       	  public:
              virtual void operator()(DiameterRetransmitMsgMapperPtr &pReq) 
				  {
					}
		 };

	public:
		 virtual int RequestMsg(std::unique_ptr<DiameterMsg> msg,
				 DiameterPeerEntry *source,
				 DiameterPeerEntry *&dest) = 0;
		 int AnswerMsg(std::unique_ptr<DiameterMsg> msg, DiameterPeerEntry *source) 
		 {
			 return (Route(std::move(msg), source) == AAA_ROUTE_RESULT_SUCCESS) ?
				 0 : (-1);
		 }
		 virtual int GetSyncProxyHopByHopId(SyncHopByHopIdData &data)
		 {
			 return 0;
		 }

		 ARG &Arg() 
		 {
			 return m_Arg;
		 }

		 void ReTransmitCheck(DiameterPeerEntry *peer, 
				 AAA_Action<DiameterRouterPendingReqPtr> &act) 
		 {
			 PendingReqPeerCheck peerCheck(peer, act);
			 m_ReqMap.Iterate(peerCheck);
		 }

		 void ReTransmitCheck(ACE_Time_Value &current,
				 AAA_Action<DiameterRouterPendingReqPtr> &act) 
		 {
			 PendingReqAgeCheck ageCheck(current, act);
			 m_ReqMap.Iterate(ageCheck);
			
			 DcRequestReTransmissionHopByHopId  lH2Hact;
			 RetransmiteHopByHopIdAgeCheck Retrans_ageCheck(current, lH2Hact);	
			 m_RetrxHopByHopIdMap.Iterate(Retrans_ageCheck);
		 }

		 /* void ReTransmitHopByHopIdCheck(ACE_Time_Value &current,
				 AAA_Action<DiameterRetransmitMsgMapperPtr> &act)
		 {
			 RetransmiteHopByHopIdAgeCheck Retrans_ageCheck(current, act);	
			 m_RetrxHopByHopIdMap.Iterate(Retrans_ageCheck);
		 } */

	protected:
		 DiameterDeliveryRoutingNode(ARG &a,
				 DiameterRoutingNode *next = NULL,
				 char *name = "") :
			 DiameterRoutingNode(next, name),
			 m_Arg(a) {
			 }
		 virtual ~DiameterDeliveryRoutingNode() {
			 ClearQueuedMessages();
		 }

		 int Add(int localh2h,
				 std::unique_ptr<DiameterMsg> &msg,
				 DiameterPeerEntry *source,
				 DiameterPeerEntry *dest) 
		 {
			 DiameterRouterPendingReqPtr r = new DiameterRouterPendingReq;
			 if (r) 
			 {
				 ACE_Time_Value expire(DIAMETER_CFG_TRANSPORT()->retx_interval, 0);
				 r->m_ReTxExpireTime = ACE_OS::gettimeofday() + expire;
				 r->m_OrigHH = msg->hdr.mHopByHopId;
				 r->m_localHH = localh2h;
				 r->m_Source = source;
				  r->m_Dest = dest;
				  r->m_ReTxCount = 0;
				  r->m_sid   = msg->sessionId;
				  m_ReqMap.Add(localh2h, r);
				  return (localh2h);
			  }
			  return (-1);
		 }

		 DiameterRouterPendingReqPtr LookupQueuedMessage(int h2hId) 
		 {
			 DiameterRouterPendingReqPtr r = NULL;
			 m_ReqMap.Lookup(h2hId, r);
			 return r;
		 }
		 
		 bool IsReqMsgPresent(int h2hId) 
		 {
			 DiameterRouterPendingReqPtr r = NULL;
			 if ( m_ReqMap.Lookup(h2hId, r))
					return true;
			 return false;
		 }

		 int DeleteQueuedMessage(int h2hId) 
		 {
			 PendingReqCleanup dealloc;
			 return (m_ReqMap.Remove(h2hId, dealloc)) ? 0 : (-1);
		 }

		 void ClearQueuedMessages() {
			 PendingReqCleanup dealloc;
			 m_ReqMap.Iterate(dealloc);
		 }

		 int StoreRequestMessage(int h2hId,
				 std::unique_ptr<DiameterMsg> &msg) 
		{
			 DiameterRouterPendingReqPtr r = NULL;
			 if (m_ReqMap.Lookup(h2hId, r)) {
				 r->m_ReqMessage = std::move(msg);
				 ACE_Time_Value expire(DIAMETER_CFG_TRANSPORT()->retx_interval, 0);
				 r->m_ReTxExpireTime = ACE_OS::gettimeofday() + expire;
				 return (0);
			 }
			 return (-1);
		 }
		 
		 int UpdateRequestTime(int localh2h, std::unique_ptr<DiameterMsg> &msg, 
				 DiameterPeerEntry *source, DiameterPeerEntry *dest) 
		 {
			 if ( 0 == DeleteQueuedMessage(localh2h)) 
			 {
				 return Add(localh2h, msg, source, dest); 
			 }
			 return (-1);
		 }

		 int Add(int h2hId, int lh2hId, int appID, std::string &lSessionId)
		 {
			 /*std::string lMapKey = std::string(lSessionId) + "_" + std::to_string(appID) + "_"+ std::to_string(h2hId);

			 ACE_Time_Value expire(DIAMETER_CFG_TRANSPORT()->retx_h2h_interval, 0);				

			 DiameterRetransmitMsgMapperPtr lDiameterRetransmitMsgMapper = new DiameterRetransmitMsgMapper;
			 lDiameterRetransmitMsgMapper->m_OrigHH  			= h2hId;
			 lDiameterRetransmitMsgMapper->m_localHH 			= lh2hId;
			 lDiameterRetransmitMsgMapper->m_sid 	  			= lSessionId;
			 lDiameterRetransmitMsgMapper->m_H2hExpireTime 	= ACE_OS::gettimeofday() + expire;		
	
			 m_RetrxHopByHopIdMap.Add(lMapKey, lDiameterRetransmitMsgMapper);
          */
			 return (0);
		 }
		 
		 int UpdateRequestTimeH2H(int h2hId, int lh2hId, int appID, std::string &lSessionId) 
		 {
			 if ( 0 == Delete(h2hId, appID, lSessionId))
			 {
				return Add(h2hId, lh2hId, appID, lSessionId);
			 }
			 return (-1);
		 }

		 int Lookup(int h2hId, int appID, std::string &lSessionId)
		 {
			 std::string lMapKey = std::string(lSessionId) + "_" + std::to_string(appID) + "_"+ std::to_string(h2hId);
			
			 //DiameterRetransmitMsgMapper lDiameterRetransmitMsgMapper; 
			 DiameterRetransmitMsgMapperPtr lDiameterRetransmitMsgMapper = NULL; 
			 if(m_RetrxHopByHopIdMap.Lookup(lMapKey,lDiameterRetransmitMsgMapper))
				 return lDiameterRetransmitMsgMapper->m_localHH;
			 else
				 return -1;
		 }

		 int Delete(int h2hId, int appID, std::string &lSessionId)
		 {
			 	std::string lMapKey = std::string(lSessionId) + "_" + std::to_string(appID) + "_"+ std::to_string(h2hId);
				RetransmiteReqCleanup dealloc;
				//cout<<m_RetrxHopByHopIdMap.map<string,DiameterRetransmitMsgMapperPtr>::size()<<endl;
				return (m_RetrxHopByHopIdMap.Remove( lMapKey , dealloc)) ? 0 : (-1);
		 }

#if 0
		 //void ClearhhStoreQueuedMessages()
		 //{
		//	 m_HHrx.Iterate();
		 //}
#endif

		 virtual AAA_ROUTE_RESULT Lookup(std::unique_ptr<DiameterMsg> &m,
				 //std::unique_ptr<DiameterMsg> &p,
				 DiameterPeerEntry *source,
				 DiameterPeerEntry *&dest) 
		 {
			 /*
				 6.2.1.  Processing received Answers

				 A Diameter client or proxy MUST match the Hop-by-Hop
				 Identifier in an answer received against the list of
				 pending requests.  The corresponding message should
				 be removed from the list of pending requests. It SHOULD
				 ignore answers received that do not match a known
				 Hop-by-Hop Identifier.
				 .
				 .
				 If the answer is for a request which was proxied
				 or relayed, the agent MUST restore the original
				 value of the Diameter header's Hop-by-Hop Identifier
				 field.
				 */
			 DiameterRouterPendingReqPtr r = NULL;

			 if (m_ReqMap.Lookup(m->hdr.mHopByHopId, r)) 
			 {
				 m->localhh = m->hdr.mHopByHopId;
				 dest = r->m_Source;
				 //p = r->m_ReqMessage;
				 m->hdr.mHopByHopId = r->m_OrigHH;
				 DeleteQueuedMessage(m->localhh);
				 return (AAA_ROUTE_RESULT_SUCCESS);
			 }
			 else
			 {
				 SyncHopByHopIdData data;
				 memset(&data, 0, sizeof(SyncHopByHopIdData));

				 data.localH2H = m->hdr.mHopByHopId;

				 if(GetSyncProxyHopByHopId(data))
				 {
					 std::string srcName = data.sourceName;
					 DiameterPeerEntry* srcPeer = DIAMETER_PEER_TABLE()->Lookup(srcName);

					 if(srcPeer == NULL)
						 return (AAA_ROUTE_RESULT_NEXT_CHAIN);

					 dest = srcPeer;
					 m->hdr.mHopByHopId = data.origH2H;

					 return (AAA_ROUTE_RESULT_SUCCESS);
				 }
			 }
			 return (AAA_ROUTE_RESULT_NEXT_CHAIN);
		 }

	protected:
		 ARG &m_Arg;

	private:
		 AAA_ProtectedMap<int, DiameterRouterPendingReqPtr> m_ReqMap;
		 AAA_ProtectedMap<std::string, DiameterRetransmitMsgMapperPtr> m_RetrxHopByHopIdMap;
};

template<class DELIVERY_NODE, class ARG>
class DiameterRequestRoutingNode : public DiameterRoutingNode
{
	public:
		DELIVERY_NODE &Delivery() {
			return m_DeliveryNode;
		}
	protected:
		DiameterRequestRoutingNode(ARG &a,
				DiameterRoutingNode *next = NULL,
				char *name = "") :
			DiameterRoutingNode(next, name),
			m_DeliveryNode(a) { 
			}
		virtual ~DiameterRequestRoutingNode() {
		}

		AAA_ROUTE_RESULT Process(std::unique_ptr<DiameterMsg> msg,
				//std::unique_ptr<DiameterMsg> &p,
				DiameterPeerEntry *source,
				DiameterPeerEntry *&dest) 
		{
			return m_DeliveryNode.RequestMsg(std::move(msg), source, dest) == 0 ?
				AAA_ROUTE_RESULT_SUCCESS : AAA_ROUTE_RESULT_FAILED;
		}

		DELIVERY_NODE m_DeliveryNode;
};

class DiameterRoutingChain
{
	public:
		DiameterRoutingChain() : m_Head(NULL) {
		}
		virtual ~DiameterRoutingChain() {
		}
		AAA_ROUTE_RESULT Route(std::unique_ptr<DiameterMsg> msg,
				DiameterPeerEntry *source) {
			return (m_Head) ? m_Head->Route(std::move(msg), source) :
				AAA_ROUTE_RESULT_FAILED;
		}
		int Add(DiameterRoutingNode *n) {
			if (m_Head == NULL) {
				m_Head = n;
				return (0);
			}
			DiameterRoutingNode *next = m_Head;
			DiameterRoutingNode *prev = NULL;
			//Can take another variable as last and store last index
			//this helps to reduce the while loop -- Mohan
			while (next) {
				prev = next;
				next = next->Next();
			}
			prev->Next(n);
			return (0);
		}
		bool Lookup(DiameterRoutingNode *n) 
		{
			DiameterRoutingNode *next = m_Head;
			while (next) {
				if (next == n) {
					return (true);
				}
				next = next->Next();
			}
			return (false);
		}
		int Remove(DiameterRoutingNode *n) {
			DiameterRoutingNode *next = m_Head;
			DiameterRoutingNode *prev = NULL;
			while (next) {
				if (next == n) {
					if (prev) {
						prev->Next(next->Next());
					}
					else if (m_Head->Next()) {
						m_Head = m_Head->Next();
					}
					else {
						m_Head = NULL;
					}
					delete n;
					return (0);
				}
				prev = next;
				next = next->Next();
			}
			return (-1);
		}

	private:
		DiameterRoutingNode *m_Head;
};

class DiameterRouterFramework
{
	public:
		AAA_ROUTE_RESULT RequestMsg(std::unique_ptr<DiameterMsg> msg,
				DiameterPeerEntry *source) 
		{
			return m_RequestChain.Route(std::move(msg), source);
		}
		AAA_ROUTE_RESULT AnswerMsg(std::unique_ptr<DiameterMsg> msg,
				DiameterPeerEntry *source) {
			return m_DeliveryChain.Route(std::move(msg), source);
		}
		DiameterRoutingChain &Delvery() {
			return m_DeliveryChain;
		}
		DiameterRoutingChain &Request() {
			return m_RequestChain;
		}

	protected:
		DiameterRoutingChain m_DeliveryChain;
		DiameterRoutingChain m_RequestChain;
};

#endif /* __ROUTE_FRAMEWORK_H__ */


