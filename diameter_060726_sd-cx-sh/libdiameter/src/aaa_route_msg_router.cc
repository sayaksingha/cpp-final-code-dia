static const char *id = " @(#) $Id: aaa_route_msg_router.cc,v 1.1.4.1.2.1.2.16 2024/05/15 13:11:22 mram Exp $";
//----------------------------------------------------------------------
// NAME
// aaa_route_msg_router.cc
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
#include "aaa_data_defs.h"
#include "aaa_route_table.h"
#include "aaa_peer_table.h"
#include "aaa_route_msg_router.h"
#include "resultcodes.h"
#include "aaa_error_msg.h"
#include "aaa_redis_pool.h"
/*
   6.1.  Diameter Request Routing Overview

   A request is sent towards its final destination using a combination
   of the Destination-Realm and Destination-Host AVPs, in one of these
   three combinations:

   -  a request that is not able to be proxied (such as CER) MUST NOT
   contain either Destination-Realm or Destination-Host AVPs.

   -  a request that needs to be sent to a home server serving a
   specific realm, but not to a specific server (such as the first
   request of a series of round-trips), MUST contain a Destination-
   Realm AVP, but MUST NOT contain a Destination-Host AVP.

   -  otherwise, a request that needs to be sent to a specific home
   server among those serving a given realm, MUST contain both the
   Destination-Realm and Destination-Host AVPs. 

   The Destination-Host AVP is used as described above when the
   destination of the request is fixed, which includes: 

   -  Authentication requests that span multiple round trips

   -  A Diameter message that uses a security mechanism that makes use
   of a pre-established session key shared between the source and the
   final destination of the message.

   -  Server initiated messages that MUST be received by a specific
   Diameter client (e.g., access device), such as the Abort-Session-
   Request message, which is used to request that a particular user's
   session be terminated.

   Note that an agent can forward a request to a host described in the
   Destination-Host AVP only if the host in question is included in its
   peer table (see Section 2.7).  Otherwise, the request is routed based
   on the Destination-Realm only (see Sections 6.1.6).

   The Destination-Realm AVP MUST be present if the message is
   proxiable.  Request messages that may be forwarded by Diameter agents
   (proxies, redirects or relays) MUST also contain an Acct-
   Application-Id AVP, an Auth-Application-Id AVP or a Vendor-Specific-
   Application-Id AVP.  A message that MUST NOT be forwarded by Diameter
   agents (proxies, redirects or relays) MUST not include the
   Destination-Realm in its ABNF.  The value of the Destination-Realm
   AVP MAY be extracted from the User-Name AVP, or other application-
   specific methods.

   When a message is received, the message is processed in the following
order:

1. If the message is destined for the local host, the procedures
listed in Section 6.1.4 are followed.

2. If the message is intended for a Diameter peer with whom the local
host is able to directly communicate, the procedures listed in
Section 6.1.5 are followed.  This is known as Request Forwarding.

3. The procedures listed in Section 6.1.6 are followed, which is
known as Request Routing.

4. If none of the above is successful, an answer is returned with the
Result-Code set to AAA_UNABLE_TO_DELIVER, with the E-bit set.

For routing of Diameter messages to work within an administrative
domain, all Diameter nodes within the realm MUST be peers.

Note the processing rules contained in this section are intended to
be used as general guidelines to Diameter developers.  Certain
implementations MAY use different methods than the ones described
here, and still comply with the protocol specification.  See Section
7 for more detail on error handling.
*/

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAA_ROUTE_RESULT DiameterMsgRouter::RcLocal::Lookup(std::unique_ptr<DiameterMsg> &msg,
      //std::unique_ptr<DiameterMsg> &p,
      DiameterPeerEntry *source,
      DiameterPeerEntry *&dest)
{

   /*
      6.1.4.  Processing Local Requests

      A request is known to be for local consumption when one of the
      following conditions occur:

      -  The Destination-Host AVP contains the local host's identity,

      -  The Destination-Host AVP is not present, the Destination-Realm AVP
      contains a realm the server is configured to process locally, and
      the Diameter application is locally supported, or

      -  Both the Destination-Host and the Destination-Realm are not
      present.

      When a request is locally processed, the rules in Section 6.2 should
      be used to generate the corresponding answer.
      */

   std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
   if (msg->destinationHost.size())
   {
      //
      // Warning: This is a case in-sensitive lookup which may not
      //          be generally appropriate if we consider FQDN as
      //          a non ascii value.
      //
      if (! strcasecmp(msg->destinationHost.c_str(),
               source->Data().m_HostEntry.m_Identity.c_str()))
      {
         AAA_LOG((LM_DEBUG, "%T |ROUTE| %s {DR:%s} APPID:%d Route Found\n",
                  lLogText.c_str(), msg->baseClass->getDestinationRealm()->getValue(), 
                  msg->hdr.mApplId));          //TBC-Anshul 28-dec
         return (AAA_ROUTE_RESULT_SUCCESS);
      } 

      AAA_LOG((LM_INFO, "%T |ROUTE| %s {DH:%s} present but not ours so try realm routing\n", 
               lLogText.c_str(), msg->baseClass->getDestinationHost()->getValue()));
      // next chain
   }
   else if (msg->destinationRealm.size()) 
   {
      //
      // Warning: This is a case in-sensitive lookup which may not
      //          be generally appropriate if we consider FQDN as
      //          a non ascii value.
      //
      if ((! strcasecmp(msg->destinationRealm.c_str(),
                  source->Data().m_HostEntry.m_Realm.c_str()))
            && DIAMETER_CFG_GENERAL()->backend_auth) // TBC backend_auth??? vicky
      {
         DiameterApplicationIdLst *idList[] = 
         {
            &DIAMETER_CFG_GENERAL()->authAppIdLst,
            &DIAMETER_CFG_GENERAL()->acctAppIdLst
         };

         for (unsigned int i=0;
               i<sizeof(idList)/sizeof(DiameterApplicationIdLst*);
               i++) 
         {
            DiameterApplicationIdLst::iterator x = idList[i]->begin();
            for (; x != idList[i]->end(); x++) 
            {
               if (*x == msg->hdr.mApplId) 
               {
                  AAA_LOG((LM_INFO, "%T |ROUTE| %s {DR:%s} APPID:%d Route Found\n", 
                           lLogText.c_str(), msg->baseClass->getDestinationRealm()->getValue(), msg->hdr.mApplId));
                  return (AAA_ROUTE_RESULT_SUCCESS);
               }
            }
         }

         DiameterVendorSpecificIdLst::iterator y =
            DIAMETER_CFG_GENERAL()->vendorSpecificId.begin();
         for (; y != DIAMETER_CFG_GENERAL()->vendorSpecificId.end();
               y++) 
         {
            if (((*y).authAppId == msg->hdr.mApplId) ||
                  ((*y).acctAppId == msg->hdr.mApplId)) 
            {
               AAA_LOG((LM_INFO, "%T |ROUTE| %s {DR:%s} APPID:%d, Route Found\n", 
                        lLogText.c_str(), msg->baseClass->getDestinationRealm()->getValue(), msg->hdr.mApplId));
               return (AAA_ROUTE_RESULT_SUCCESS);
            }
         }
      }

      AAA_LOG((LM_DEBUG, "%T |ROUTE| %s {DR:%s} APPID:%d, DR present but not ours or no supported id\n", 
               lLogText.c_str(),	msg->destinationRealm.c_str(), msg->hdr.mApplId));
      // next chain
   }
   else 
   {
      AAA_LOG((LM_ERROR, "%T |ROUTE| %s NO DestRealm & NO Destination Host \n", lLogText.c_str()));
      return (AAA_ROUTE_RESULT_SUCCESS);
   }
   AAA_LOG((LM_DEBUG, "%T |ROUTE| %s Going to next chain\n",lLogText.c_str())); //TBC-Anshul 28-dec
   return (AAA_ROUTE_RESULT_NEXT_CHAIN);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAA_ROUTE_RESULT DiameterMsgRouter::RcForwarded::Lookup(std::unique_ptr<DiameterMsg> &msg,	
      //std::unique_ptr<DiameterMsg> &p, 
      DiameterPeerEntry *source,
      DiameterPeerEntry *&dest)
{
   /*
      6.1.5.  Request Forwarding

      Request forwarding is done using the Diameter Peer Table.  The
      Diameter peer table contains all of the peers that the local node is
      able to directly communicate with.

      When a request is received, and the host encoded in the Destination-
      Host AVP is one that is present in the peer table, the message SHOULD
      be forwarded to the peer.
      */

   std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
   if (msg->destinationHost.size())
   {
      DiameterPeerEntry *peer = DIAMETER_PEER_TABLE()->Lookup(msg->destinationHost);

      if (peer) 
      {
         if (peer->IsOpen()) 
         {
            dest = peer;
            return (AAA_ROUTE_RESULT_SUCCESS);
         }
         // try routing it
      }
      AAA_LOG((LM_DEBUG, "%T |ROUTE| %s {DH:%s}, DestHost does not match any peer\n", 
               lLogText.c_str(),	msg->destinationHost.c_str()));
   }

   return (AAA_ROUTE_RESULT_NEXT_CHAIN);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAA_ROUTE_RESULT DiameterMsgRouter::RcRouted::Lookup(std::unique_ptr<DiameterMsg> &msg,	
      //std::unique_ptr<DiameterMsg> &p,
      DiameterPeerEntry *source,
      DiameterPeerEntry *&dest)
{
   /*
      6.1.6.  Request Routing

      Diameter request message routing is done via realms and Application
      Ids. A Diameter message that may be forwarded by Diameter agents
      (proxies, redirect agents, or relay agents) MUST include the target
      realm in the Destination-Realm AVP. Request routing SHOULD rely on
      the Destination-Realm AVP and the Application Id present in the
      request message header to aid in the routing decision. The realm MAY
      be retrieved from the User-Name AVP, which is in the form of a
      Network Access Identifier (NAI). The realm portion of the NAI is
      inserted in the Destination-Realm AVP.

      Diameter agents MAY have a list of locally supported realms and
      applications, and they MAY have a list of externally supported realms
      and applications. When a request is received that includes a realm
      and/or application that is not locally supported, the message is
      routed to the peer configured in the routing table (see Section 2.7).
      Realm names and Application Ids are the minimum supported routing
      criteria, additional information may be needed to support redirect
      semantics
      */


   std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
   try 
   {
      std::string destRealm = msg->destinationRealm;

      if(!destRealm.size())  
      {
         try
         {
            //destRealm.assign(msg->baseClass->getUserName()->getValue()? (char*)msg->baseClass->getUserName()->getValue():"" , vicky
            //		msg->baseClass->getUserName()->getLength() ? msg->baseClass->getUserName()->getLength(): 0);
         }
         catch (...)
         {
            AAA_LOG((LM_ERROR, "%T |ROUTE| %s, Can't determine DestRealm during realm routing\n", lLogText.c_str()));
            throw (0);
         }

         destRealm = destRealm.substr(destRealm.find("@",0), destRealm.length()-1);
      }

      DiameterRouteEntry *route = DIAMETER_ROUTE_TABLE()->Lookup(destRealm);

      // peer = DIAMETER_PEER_TABLE()->Lookup(  peerName );

      if (route == NULL) 
      {
         AAA_LOG((LM_INFO, "%T |ROUTE| {DR:%s} not in routing table\n", destRealm.c_str()));
         throw (0);
      }

      // look in the header first, base protocol only
      DiameterRouteApplication *app = route->Lookup(msg->hdr.mApplId, 0);

      if (app) 
      {
         // Local action is to redirect
         if (route->Action() == DIAMETER_ROUTE_ACTION_REDIRECT) 
         {
            AAA_LOG((LM_INFO, "%T |ROUTE | {DR:%s} is in routing table but it is set to re-direct\n", destRealm.c_str()));
            return (AAA_ROUTE_RESULT_SUCCESS);
         }

         // get the first available/open peer
         DiameterPeerEntry *peer = NULL;
         DiameterRouteServerEntry *server = app->Servers().First();

         while (server) 
         {
            peer = DIAMETER_PEER_TABLE()->Lookup(server->Server());
            if (peer && peer->IsOpen()) 
            {
               dest = peer;
               return (AAA_ROUTE_RESULT_SUCCESS);
            }

            server = app->Servers().Next(*server);
         }
         AAA_LOG((LM_INFO, "%T |ROUTE| {DR:%s} in routing table but no open peers support it\n", destRealm.c_str()));
      }
      else {
         AAA_LOG((LM_INFO, "%T |ROUTE| {DR:%s} is in routing table but no matching app Id, APPID:%d\n", 
                  destRealm.c_str(),msg->hdr.mApplId));
      }
   }
   catch (...) 
   {
      AAA_LOG((LM_DEBUG, "%T |ROUTE| Exception caugth\n")); //TBC-Anshul 28-dec
   }

   return (AAA_ROUTE_RESULT_NEXT_CHAIN);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAA_ROUTE_RESULT DiameterMsgRouter::RcRejected::Lookup(std::unique_ptr<DiameterMsg> &msg, 
      //std::unique_ptr<DiameterMsg> &p,
      DiameterPeerEntry *source,
      DiameterPeerEntry *&dest)
{
   /*
      6.1.  Diameter Request Routing Overview
      .
      .
      .
      4. If none of the above is successful, an answer is returned with the
      Result-Code set to AAA_UNABLE_TO_DELIVER, with the E-bit set.
      */

   std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
   AAA_LOG((LM_INFO, "%T |ROUTE| %s {DR:%s} {DH:%s} Router cannot deliver message, sending back with an error\n", 
            lLogText.c_str(), msg->destinationRealm.c_str(),msg->destinationHost.c_str()));
   return (AAA_ROUTE_RESULT_SUCCESS);
}


//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAA_ROUTE_RESULT DiameterMsgRouter::DcLocal::Process(std::unique_ptr<DiameterMsg> msg,
      //std::unique_ptr<DiameterMsg> &p,
      DiameterPeerEntry *source,
      DiameterPeerEntry *&dest)
{
   if (m_Arg.m_RedirectAgent.IsRedirected(msg)) 
   {
      //return (m_Arg.m_RedirectAgent.Answer(msg, p, source, dest) == 0) ?
      return (m_Arg.m_RedirectAgent.Answer(msg, source, dest) == 0) ?
         AAA_ROUTE_RESULT_SUCCESS: AAA_ROUTE_RESULT_FAILED;
   }

   if (msg->hdr.mCmdFlg.eBit) 
   {
      return ErrorHandling(std::move(msg), source, dest);
   }
   else if (dest) 
   {
      return (dest->Send(msg) >= 0) ?
         AAA_ROUTE_RESULT_SUCCESS: AAA_ROUTE_RESULT_FAILED;
   }
   else 
   {
      // original request must have been locally generated
      m_Arg[DiameterMsgRouterHandlerTable::H_LOCAL]->
         Answer(msg, source, dest);
   }
   return (AAA_ROUTE_RESULT_SUCCESS);
}

AAA_ROUTE_RESULT DiameterMsgRouter::DcLocal::ErrorHandling(std::unique_ptr<DiameterMsg> msg,
      DiameterPeerEntry *source,
      DiameterPeerEntry *&dest)
{
   /*
      Result-Code AVP values that are used to report protocol errors MUST
      only be present in answer messages whose 'E' bit is set.  When a
      request message is received that causes a protocol error, an answer
      message is returned with the 'E' bit set, and the Result-Code AVP is
      set to the appropriate protocol error value.  As the answer is sent
      back towards the originator of the request, each proxy or relay agent
      MAY take action on the message.

      1. Request        +---------+ Link Broken
      +-------------------------->|Diameter |----///----+
      |     +---------------------|         |           v
      +------+--+  | 2. answer + 'E' set | Relay 2 |     +--------+
      |Diameter |<-+ (Unable to Forward) +---------+     |Diameter|
      |         |                                        |  Home  |
      | Relay 1 |--+                     +---------+     | Server |
      +---------+  |   3. Request        |Diameter |     +--------+
      +-------------------->|         |           ^
      | Relay 3 |-----------+
      +---------+

      Figure 7:  Example of Protocol Error causing answer message

      Figure 7 provides an example of a message forwarded upstream by a
      Diameter relay.  When the message is received by Relay 2, and it
      detects that it cannot forward the request to the home server, an
      answer message is returned with the 'E' bit set and the Result-Code
      AVP set to DIAMETER_UNABLE_TO_DELIVER.
      */

   if (dest) 
   {
      return (dest->Send(msg) >= 0) ?
         AAA_ROUTE_RESULT_SUCCESS: AAA_ROUTE_RESULT_FAILED;
   }
   else {
      // original request must have been locally generated
      m_Arg[DiameterMsgRouterHandlerTable::H_ERROR]->
         Answer(msg, source, dest);
   }

   return (AAA_ROUTE_RESULT_SUCCESS);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterMsgRouter::DcLocal::RequestMsg(std::unique_ptr<DiameterMsg> msg,
      DiameterPeerEntry *source,
      DiameterPeerEntry *&dest)
{
   if (source) 
   {
      AAA_LOG((LM_DEBUG, "%T |ROUTE| storing HopByHopId ....\n"));
      Add(msg->hdr.mHopByHopId, msg, source, dest);
      m_Arg[DiameterMsgRouterHandlerTable::H_LOCAL]->
         Request(msg, source, dest);
   }
   else {
      AAA_LOG((LM_INFO, "%T |ROUTE| Looped back message detected, discarding ....\n"));
      DiameterMsgHeaderDump::Dump(*msg);
   }
   return (0);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAA_ROUTE_RESULT DiameterMsgRouter::DcForward::Process(std::unique_ptr<DiameterMsg> msg,
      //std::unique_ptr<DiameterMsg> &p,
      DiameterPeerEntry *source,
      DiameterPeerEntry *&dest)
{
   //return m_Arg.m_rcLocal.Delivery().Process(msg, p, source, dest);
   return m_Arg.m_rcLocal.Delivery().Process(std::move(msg), source, dest);
}
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterMsgRouter::DcForward::LoopDetection(std::unique_ptr<DiameterMsg> &msg)
{

   std::string lLogText = LOG_DIAMETER_AVPS(*msg);	

   AAA_LOG((LM_INFO, "%T |ROUTE| %s {OH:%s}, Check for LOOP_DETECTION , HOST_ENTRY:%s | HOSTNAME :%s \n", 
            lLogText.c_str(), msg->originationHost.c_str(),
            DIAMETER_CFG_TRANSPORT()->route_record_host_name.c_str() ,DIAMETER_CFG_DATAPEER()->hostname.c_str() ));


   if ( msg->baseClass )
   {

      try 
      {
         //	auto routeRecordList = msg->baseClass->getRouteRecordList() ;
         try 
         {
            for ( auto itr = msg->baseClass->getRouteRecordList()->begin() ; itr != msg->baseClass->getRouteRecordList()->end() ; ++itr)
            {

               //if ( (*itr)->ToString().compare(DIAMETER_CFG_DATAPEER()->host_entry) == 0 )
               if ( (*itr)->ToString().compare(DIAMETER_CFG_TRANSPORT()->route_record_host_name) == 0 )
               {

                  AAA_LOG((LM_ERROR, 
                           "(%P|%t) !!! WARNING !!!: Route record shows a loop in the message, sending back with error Received Dest:%s Config DataPeer:%s\n" ,
                           (*itr)->ToString().c_str() ,  DIAMETER_CFG_DATAPEER()->host_entry.c_str() ));
                  return 0;
               }
            }
         }
         catch  (TssDiameterMsgException &err )
         {
            AAA_LOG((LM_DEBUG, "%T |ROUTE| %s Exception caugth ,error[%d]: %s\n", lLogText.c_str(), 
                     err.getErrorCode(), err.getErrMessage())); //TBC-Anshul-dec
         }
      }
      catch  (DiameterBaseException &st )
      {
         AAA_LOG((LM_ERROR, "%T |ROUTE| %s Exception caugth, error[%d]: %s\n", lLogText.c_str(), 
                  st.Code(), st.Description().c_str()));  //TBC-Anshul 28-dec
      }
      /*
         for ( auto const &list : routeRecordList )
         {

         }
         */
      /*
      */
      //routeRecordList->
   }
#if 0
#endif
   /*
      A relay or proxy agent MUST check for forwarding loops when receiving
      requests.  A loop is detected if the server finds its own identity in
      a Route-Record AVP.  When such an event occurs, the agent MUST answer
      with the Result-Code AVP set to AAA_LOOP_DETECTED.
      */
   /*
      DiameterIdentityAvpContainerWidget rrecord(msg->acl);
      diameter_identity_t *rteRec = rrecord.GetAvp((char *)DIAMETER_AVPNAME_ROUTERECORD);
      for (int p=1; rteRec; p++) {
      if (*rteRec == (DIAMETER_CFG_TRANSPORT()->identity)) {
   // send back answer
   AAA_LOG((LM_INFO, "(%P|%t) !!! WARNING !!!: Route record shows a loop in the message, sending back with error\n"));
   return (0);
   }
   rteRec = rrecord.GetAvp((char *)DIAMETER_AVPNAME_ROUTERECORD, p);
   }
   */

   return (-1);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterMsgRouter::DcForward::RequestMsg(std::unique_ptr<DiameterMsg> msg,
      DiameterPeerEntry *source,
      DiameterPeerEntry *&dest)
{
   if (msg->hdr.mCmdFlg.tBit && LookupQueuedMessage(msg->hdr.mHopByHopId)) { 
      // locally re-transmitted messages


      int rcode = (dest->Send(msg, false) >= 0) ? 0 : (-1);
      StoreRequestMessage(msg->hdr.mHopByHopId, msg); //TBC-Dont Use this-NKS
      return rcode;
   }
   else if (LoopDetection(msg) == 0) {
      if (source) {
         DiameterErrorMsg::Generate(*msg, AAA_LOOP_DETECTED, source); 
         return (source->Send(msg) >= 0) ? 0 : (-1);
      }
      else {
         // request must have been locally generated
         m_Arg[DiameterMsgRouterHandlerTable::H_ERROR]->
            Request(msg, source, dest);
         return (-1);
      }
   }

   /*
      The Diameter protocol requires that agents maintain
      transaction state, which is used for failover purposes.
      Transaction state implies that upon forwarding a request,
      the Hop-by-Hop identifier is saved; the field is replaced
      with a locally unique identifier, which is restored to its
      original value when the corresponding answer is received.
      The request's state is released upon receipt of the answer.
      a stateless agent is one that only maintains transaction
      state.
      */
   int h2hIndex = 0 , rcode = 0 ;

   if (source) {
      int localHH = DIAMETER_HOPBYHOP_GEN()->Get();
      h2hIndex = Add(localHH, msg, source, dest);
      msg->hdr.mHopByHopId = localHH;
   }
   else {
      // locally generated
      if (msg->hdr.mHopByHopId == 0) {
         msg->hdr.mHopByHopId = DIAMETER_HOPBYHOP_GEN()->Get();
      }
      if (msg->hdr.mEndToEndId == 0){
         msg->hdr.mEndToEndId = DIAMETER_ENDTOEND_GEN()->Get();
      }
      h2hIndex = Add(msg->hdr.mHopByHopId, msg, source, dest);
   }

   rcode = (dest->Send(msg, false) >= 0) ? 0 : (-1);

   if (h2hIndex > 0) 
   {
      StoreRequestMessage(h2hIndex, msg); //TBC-Dont Use this-NKS
   }

   return rcode;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAA_ROUTE_RESULT DiameterMsgRouter::DcRouted::Process(std::unique_ptr<DiameterMsg> msg,
      //std::unique_ptr<DiameterMsg> &p,
      DiameterPeerEntry *source,
      DiameterPeerEntry *&dest)
{
   /*
      6.2.2.  Relaying and Proxying Answers

      If the answer is for a request which was proxied or relayed, the
      agent MUST restore the original value of the Diameter header's Hop-
      by-Hop Identifier field.

      If the last Proxy-Info AVP in the message is targeted to the local
      Diameter server, the AVP MUST be removed before the answer is
      forwarded.

      If a relay or proxy agent receives an answer with a Result-Code AVP
      indicating a failure, it MUST NOT modify the contents of the AVP.
      Any additional local errors detected SHOULD be logged, but not
      reflected in the Result-Code AVP.  If the agent receives an answer
      message with a Result-Code AVP indicating success, and it wishes to
      modify the AVP to indicate an error, it MUST modify the Result-Code
      AVP to contain the appropriate error in the message destined towards
      the access device as well as include the Error-Reporting-Host AVP and
      it MUST issue an STR on behalf of the access device.

      The agent MUST then send the answer to the host that it received the
      original request from.
      */

#if 0
   if (m_Arg.m_RedirectAgent.IsRedirected(msg)) 
   {
      return (m_Arg.m_RedirectAgent.Answer(msg, p, source, dest) == 0) ?
         AAA_ROUTE_RESULT_SUCCESS: AAA_ROUTE_RESULT_FAILED;
   }
#endif

   AAA_ROUTE_RESULT result = AAA_ROUTE_RESULT_SUCCESS;

   if (! dest) 
   {
      // original request must have been locally generated
      DiameterMsgRouterHandlerTable::H_TYPE type = (msg->hdr.mCmdFlg.eBit) ? 
         DiameterMsgRouterHandlerTable::H_ERROR : DiameterMsgRouterHandlerTable::H_LOCAL;
      m_Arg[type]->Answer(msg, source, dest);
   }
   else 
   {
      DiameterMsgRouterHandlerTable::H_TYPE type;
      if (DIAMETER_CFG_RELOAD()->ebit == 1)
      {
         type = DiameterMsgRouterHandlerTable::H_PROXY;	
      }
      else
      {
         type = (msg->hdr.mCmdFlg.eBit) ?
            DiameterMsgRouterHandlerTable::H_ERROR : DiameterMsgRouterHandlerTable::H_PROXY;
      }
#if 0
      DiameterMsgRouterHandlerTable::H_TYPE type = (msg->hdr.mCmdFlg.eBit) ? 
         DiameterMsgRouterHandlerTable::H_ERROR : DiameterMsgRouterHandlerTable::H_PROXY;
#endif 
      m_Arg[type]->Answer(msg, source, dest);

      //if(m_SyncH2hHdlr != NULL)
      if(DIAMETER_CFG_GENERAL()->sync_hbh)
      {
         SyncHopByHopIdData    data;

         data.op         = SYNC_OP_DEL;
         data.localH2H   = msg->localhh;
         data.origH2H    = msg->hdr.mHopByHopId;

         //memcpy(data.sourceName, source->PeerData().m_Identity.c_str(), source->PeerData().m_Identity.size());
         //memcpy(data.destName,   dest->PeerData().m_Identity.c_str(),   dest->PeerData().m_Identity.size());

         snprintf(data.sourceName, source->PeerData().m_Identity.size()+1, "%s", source->PeerData().m_Identity.c_str());
         snprintf(data.destName, dest->PeerData().m_Identity.size()+1, "%s", dest->PeerData().m_Identity.c_str());

         //m_SyncH2hHdlr->SendSyncData(data);
         //if(m_SyncH2hHdlr->SendSyncData(data)){ //TBC
         //AAA_LOG((LM_DEBUG,"%T |ROUTE| SId: %s Removed data from redis\n",msg->sessionId.c_str())); //TBC-AP
         //}
         if(DIAMETER_CFG_TRANSPORT()->use_sentinel ==1 )
            m_SyncH2hHdlr->SendSyncData(data);
         else
            DIAMETER_HBH_SYNC()->syncHbH(data);

      }

      if(dest->PeerData().m_UseStackIdentity)
      {
         msg->baseClass->setOriginHost()->setValue(const_cast<char*>(dest->HostEntry().m_Identity.c_str()));
         msg->baseClass->setOriginRealm()->setValue(const_cast<char*>(dest->HostEntry().m_Realm.c_str()));
      }

      result = (dest->Send(msg) >= 0) ? AAA_ROUTE_RESULT_SUCCESS : AAA_ROUTE_RESULT_FAILED;
   }

   return result;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterMsgRouter::DcRouted::RequestMsg(std::unique_ptr<DiameterMsg> msg,
      DiameterPeerEntry *source,
      DiameterPeerEntry *&dest)
{


#if 0
   DiameterIdentityAvpContainerWidget originHost(msg->acl);
   DiameterIdentityAvpContainerWidget destRealm(msg->acl);
   diameter_identity_t *DestRealm = destRealm.GetAvp((char *)DIAMETER_AVPNAME_DESTREALM);
   if (! DestRealm) {
      throw (0);
   }

   DiameterRouteEntry *route = DIAMETER_ROUTE_TABLE()->Lookup(*DestRealm);
   if (route == NULL) {
      throw (0);
   }

   if (route->Action() == DIAMETER_ROUTE_ACTION_LOCAL) {
      return m_Arg.m_rcLocal.Delivery().RequestMsg(msg, source, dest);
   }
   else if (route->Action() == DIAMETER_ROUTE_ACTION_REDIRECT) {
      return m_Arg.m_RedirectAgent.Request(msg, source, dest);
   }
   else {
      /*
         6.1.8.  Relaying and Proxying Requests

         A relay or proxy agent MUST append a Route-Record AVP to all requests
         forwarded.  The AVP contains the identity of the peer the request was
         received from.

         The Hop-by-Hop identifier in the request is saved, and replaced with
         a locally unique value.  The source of the request is also saved,
         which includes the IP address, port and protocol.

         A relay or proxy agent MAY include the Proxy-Info AVP in requests if
         it requires access to any local state information when the
         corresponding response is received.  Proxy-Info AVP has certain
         security implications and SHOULD contain an embedded HMAC with a
         node-local key.  Alternatively, it MAY simply use local storage to
         store state information.

         The message is then forwarded to the next hop, as identified in the
         Realm Routing Table.

         Figure 6 provides an example of message routing using the procedures
         listed in these sections.

         (Origin-Host=nas.mno.net)         (Origin-Host=nas.mno.net)
         (Origin-Realm=mno.net)     	    (Origin-Realm=mno.net)
         (DR=example.com)   (DR=example.com)
         (Route-Record=nas.example.net)
         +------+      ------>      +------+      ------>      +------+
         |      |     (Request)     |      |      (Request)    |      |
         | NAS  +-------------------+ DRL  +-------------------+ HMS  |
         |      |                   |      |                   |      |
         +------+     <------       +------+     <------       +------+
         example.net    (Answer)   example.net     (Answer)   example.com
         (Origin-Host=hms.example.com)   (Origin-Host=hms.example.com)
         (Origin-Realm=example.com)      (Origin-Realm=example.com)

         Figure 6: Routing of Diameter messages
         */
      int h2hIndex, rcode;
      diameter_identity_t *oHost = originHost.GetAvp((char *)DIAMETER_AVPNAME_ORIGINHOST);
      if (! oHost || ((*oHost) != DIAMETER_CFG_TRANSPORT()->identity)) {

         if (msg->hdr.mCmdFlg.tBit && LookupQueuedMessage(msg->hdr.mHopByHopId)) {
            // locally re-transmitted messages
            rcode = (dest->Send(msg, false) >= 0) ? 0 : (-1);
            StoreRequestMessage(msg->hdr.mHopByHopId, msg); //TBC-Dont Use this-NKS
            return rcode;
         }
         else {
            if (m_Arg.m_rcForward.Delivery().LoopDetection(msg) == 0) {
               std::unique_ptr<DiameterMsg> answerMsg = DiameterErrorMsg::Generate(*msg, AAA_LOOP_DETECTED);
               return (source->Send(answerMsg) >= 0) ? 0 : (-1);
            }

            DiameterIdentityAvpWidget rrecord((char *)DIAMETER_AVPNAME_ROUTERECORD);
            rrecord.Get() = DIAMETER_CFG_TRANSPORT()->identity;
            msg->acl.add(rrecord());
         }
      }
      if (route->Action() == DIAMETER_ROUTE_ACTION_PROXY) {
         if (m_Arg[DiameterMsgRouterHandlerTable::H_PROXY]->
               Request(msg, source, dest) != 0) {
            // Proxy has enforced a policy. 
            // Message will not be sent.
            return (0);
         }
      }

#endif
      /*
         The Diameter protocol requires that agents maintain
         transaction state, which is used for failover purposes.
         Transaction state implies that upon forwarding a request,
         the Hop-by-Hop identifier is saved; the field is replaced
         with a locally unique identifier, which is restored to its
         original value when the corresponding answer is received.
         The request's state is released upon receipt of the answer.
         A stateless agent is one that only maintains transaction
         state.
         */
      auto start  = std::chrono::high_resolution_clock::now();
      int rcode = -1;
      DiameterRouteEntry *route = DIAMETER_ROUTE_TABLE()->Lookup(msg->destinationRealm);
      std::string lLogText = LOG_DIAMETER_AVPS(*msg);	

      AAA_LOG((LM_DEBUG, "%T |ROUTE| %s {OH:%s}, DCRouted [ENTRY]\n", 
               lLogText.c_str(), source->Data().m_HostEntry.m_Identity.c_str() ));

      if (route == NULL) {
         AAA_LOG((LM_ERROR, "%T |ROUTE| %s {OH:%s}, DiameterRouteEntry NULL CRITICAL\n", 
                  lLogText.c_str(), source->Data().m_HostEntry.m_Identity.c_str() ));
         source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
         throw (0);
      }

      if (route->Action() == DIAMETER_ROUTE_ACTION_LOCAL) 
      {
         return m_Arg.m_rcLocal.Delivery().RequestMsg(std::move(msg), source, dest);
      }
      else if (route->Action() == DIAMETER_ROUTE_ACTION_REDIRECT) {
         return m_Arg.m_RedirectAgent.Request(msg, source, dest);
      }
      else if (route->Action() == DIAMETER_ROUTE_ACTION_PROXY) 
      {
         /*
            6.1.8.  Relaying and Proxying Requests
            */

         if(source)
         {
            if (!(msg->originationHost.empty()) || 
                  ((msg->originationHost) != source->Data().m_HostEntry.m_Identity)) 
            {

#if 0 
               if (msg->hdr.mCmdFlg.tBit && LookupQueuedMessage(msg->hdr.mHopByHopId)) {
                  rcode = (dest->Send(msg, false) >= 0) ? 0 : (-1);
                  AAA_LOG((LM_ERROR, "%T |ROUTE| %s {OH:%s}, locally re-transmitted 1 Sending msg back Source CRITICAL\n", 
                           lLogText.c_str(), source->Data().m_HostEntry.m_Identity.c_str() ));
                  StoreRequestMessage(msg->hdr.mHopByHopId, msg); //TBC-Dont Use this-NKS
                  source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
                  return rcode;
               }
               else {
#endif
                  if (m_Arg.m_rcForward.Delivery().LoopDetection(msg) == 0) 
                  {
                     DiameterErrorMsg::Generate(*msg, AAA_LOOP_DETECTED, source);
                     AAA_LOG((LM_ERROR, "%T |ROUTE| %s {OH:%s}, AAA_LOOP_DETECTED Sending msg back Source CRITICAL \n", 
                              lLogText.c_str(), source->Data().m_HostEntry.m_Identity.c_str() ));
                     source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
                     return (source->Send(msg) >= 0) ? 0 : (-1);
                     auto end = std::chrono::high_resolution_clock::now();
                     std::chrono::duration<double, std::milli> elapsed = end-start;
                     AAA_LOG((LM_INFO,"%T |ROUTE| %s Request Message RTT:%.3f ms",lLogText.c_str(), elapsed.count()));
                  }

#if 0 
               }
#endif
            }

            if ((m_Arg[DiameterMsgRouterHandlerTable::H_PROXY]->Request(msg, source, dest) != 0) || (msg->internalRspFlag == true) ) 
            {

               if (msg->hdr.mCmdCode == AAA_ASR_MSG && DIAMETER_CFG_RELOAD()->drop_asr == true)
               {
                  AAA_LOG((LM_DEBUG, "%T |ROUTE| %s ASR Droping msg\n",lLogText.c_str()));
                  return 0;
               }
               // Proxy has enforced a policy.
               // Message will not be sent.
               AAA_LOG((LM_ERROR, "%T |ROUTE| %s {DH:%s}, Sending Source CRITICAL msg\n", 
                        lLogText.c_str(), source->Data().m_HostEntry.m_Identity.c_str() ));

               if(msg->hdr.mCmdFlg.rBit  == DIAMETER_FLAG_SET)
               {
                  msg->hdr.mCmdFlg.pBit  = DIAMETER_FLAG_SET;
                  msg->hdr.mCmdFlg.eBit  = DIAMETER_FLAG_SET;
                  msg->hdr.mCmdFlg.rBit  = DIAMETER_FLAG_CLR;

                  DiaHandleMsg::SetAnswerParam(*msg, AAA_UNABLE_TO_DELIVER);	
               }


               source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
               return (source->Send(msg) >= 0) ? 0 : (-1);
               auto end = std::chrono::high_resolution_clock::now();
               std::chrono::duration<double, std::milli> elapsed = end-start;
               AAA_LOG((LM_INFO,"%T |ROUTE| %s Request Message RTT:%.3f ms",lLogText.c_str(), elapsed.count()));
            }

            if (msg->hdr.mCmdCode == AAA_ASR_MSG && DIAMETER_CFG_RELOAD()->ack_asr == true)
            {
               AAA_LOG((LM_DEBUG, "%T |ROUTE| %s Sending ASR msg\n",lLogText.c_str()));
               return (source->Send(msg) >= 0) ? 0 : (-1);
            }

            if(DIAMETER_CFG_TRANSPORT()->asyncMsg == 1)
            {
               //msg.release();
               return 0;
            }

            // Route Record
            if(route->AdveriseRoute())
            {

               list<OctetString*>* lRouteRecordList = NULL;
               try
               {
                  lRouteRecordList = msg->baseClass->getRouteRecordList();
               }
               catch (...)
               {

               }

               if ( lRouteRecordList == NULL)
               {
                  lRouteRecordList = msg->baseClass->setRouteRecordList();
               }

               OctetString *lRouteRecord = new OctetString();
               lRouteRecord->setValue((UINT8*)DIAMETER_CFG_TRANSPORT()->route_record_host_name.c_str() , DIAMETER_CFG_TRANSPORT()->route_record_host_name.size());
               lRouteRecordList->push_back(lRouteRecord);

               AAA_LOG((LM_INFO, "%T |ROUTE| %s {OH:%s}, Route Record is stored in \n",
                        lLogText.c_str(),DIAMETER_CFG_TRANSPORT()->route_record_host_name.c_str()  ));
            }

            //Origination host + orgination realm
            if(dest->PeerData().m_UseStackIdentity)
            {
               msg->baseClass->setOriginHost()->setValue(const_cast<char*>(dest->HostEntry().m_Identity.c_str())); 	
               msg->baseClass->setOriginRealm()->setValue(const_cast<char*>(dest->HostEntry().m_Realm.c_str())); 	
            }
         }
         else
         {
#if 0
            //TBC--------Commented By Nandagopi...
            if (msg->hdr.mCmdFlg.tBit && LookupQueuedMessage(msg->hdr.mHopByHopId)) {
               // locally re-transmitted messages

               rcode = (dest->Send(msg, false) >= 0) ? 0 : (-1);
               StoreRequestMessage(msg->hdr.mHopByHopId, msg); //TBC-Dont Use this-NKS
               AAA_LOG((LM_ERROR, "%T |ROUTE| %s {DR:%s} {DH:%s}, R-locally re-transmitted messages rcode:%d \n", 
                        lLogText.c_str(), msg->destinationRealm.c_str(),msg->destinationHost.c_str() , rcode));
               source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
               return rcode;
            }
            else {
               if (m_Arg.m_rcForward.Delivery().LoopDetection(msg) == 0) {

                  AAA_LOG((LM_ERROR, "%T |ROUTE| %s {DR:%s} {DH:%s}, LoopDetection \n", 
                           lLogText.c_str(), msg->destinationRealm.c_str(),msg->destinationHost.c_str()));
                  source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
                  return (-1);
               }
            }
#endif
            AAA_LOG((LM_ERROR, "%T |ROUTE| %s {OH:%s}, DCRouted Local retransmition not supported discarding the message\n", 
                     lLogText.c_str(), source->Data().m_HostEntry.m_Identity.c_str() ));
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> elapsed = end-start;
            AAA_LOG((LM_INFO,"%T |ROUTE| %s Request Message RTT:%.3f ms",lLogText.c_str(), elapsed.count()));
            return (-1);
         }

         int h2hIndex = 0;

         if (source) 
         {
            int localHH = 0;
            if (msg->hdr.mCmdFlg.tBit )
            {
               if ( -1 == (localHH = Lookup(msg->hdr.mHopByHopId, msg->hdr.mApplId, msg->sessionId)))
               {
                  localHH = DIAMETER_HOPBYHOP_GEN()->Get();
                  Add(msg->hdr.mHopByHopId,localHH,msg->hdr.mApplId, msg->sessionId); 
                  h2hIndex = Add(localHH, msg, source, dest);
               }
               else
               {
                  UpdateRequestTimeH2H(msg->hdr.mHopByHopId, localHH, msg->hdr.mApplId, msg->sessionId );
               }

               h2hIndex = localHH;
               if ( false == IsReqMsgPresent(localHH)) {
                  h2hIndex = Add(localHH, msg, source, dest);
               }
               else {
                  UpdateRequestTime(h2hIndex, msg, source, dest);
               }
            }
            else
            {
               localHH = DIAMETER_HOPBYHOP_GEN()->Get();
               Add(msg->hdr.mHopByHopId,localHH,msg->hdr.mApplId, msg->sessionId); 
               h2hIndex = Add(localHH, msg, source, dest);
            }

            //if(m_SyncH2hHdlr != NULL)
            if(DIAMETER_CFG_GENERAL()->sync_hbh )
            {
               SyncHopByHopIdData    data;

               data.op         = SYNC_OP_ADD;
               data.localH2H   = localHH;
               data.origH2H    = msg->hdr.mHopByHopId;

               //memcpy(data.sourceName, source->PeerData().m_Identity.c_str(), source->PeerData().m_Identity.size());
               //memcpy(data.destName,   dest->PeerData().m_Identity.c_str(),   dest->PeerData().m_Identity.size());

               snprintf(data.sourceName, source->PeerData().m_Identity.size()+1, "%s", source->PeerData().m_Identity.c_str());	
               snprintf(data.destName, dest->PeerData().m_Identity.size()+1, "%s", dest->PeerData().m_Identity.c_str());	

               if(DIAMETER_CFG_TRANSPORT()->use_sentinel ==1 )
                  m_SyncH2hHdlr->SendSyncData(data);
               else
                  DIAMETER_HBH_SYNC()->syncHbH(data);
            }

            msg->hdr.mHopByHopId = localHH;
            AAA_LOG((LM_DEBUG,"%T |ROUTE| %s Replaced original HH with Local HH:%d\n",lLogText.c_str(),msg->hdr.mHopByHopId ));  //TBC-Anshul
         }
         else 
         {
            // locally generated
            if (msg->hdr.mHopByHopId == 0) 
            {
               msg->hdr.mHopByHopId = DIAMETER_HOPBYHOP_GEN()->Get();
            }

            if (msg->hdr.mEndToEndId == 0) 
            {
               msg->hdr.mEndToEndId = DIAMETER_ENDTOEND_GEN()->Get();
            }

            h2hIndex = Add(msg->hdr.mHopByHopId, msg, source, dest);
         }

         if (h2hIndex > 0) 
         {
            if( dest != NULL)
            {
               // Log
               rcode = (dest->Send(msg, true) >= 0) ? 0 : (-1);
               AAA_LOG((LM_DEBUG, "%T |ROUTE| %s Message send \n",lLogText.c_str())); 
            }
            else
            {
               AAA_LOG((LM_ERROR, "%T |ROUTE| %s {OH:%s}, Dest object is null.. Message send failed\n", 
                        lLogText.c_str(), source->Data().m_HostEntry.m_Identity.c_str() ));
               auto end = std::chrono::high_resolution_clock::now();
               std::chrono::duration<double, std::milli> elapsed = end-start;
                  AAA_LOG((LM_INFO,"%T |ROUTE| %s Request Message RTT:%.3f ms",lLogText.c_str(), elapsed.count()));
               return (-1);
            }
         }
         else
         {
            AAA_LOG((LM_ERROR, "%T |ROUTE| %s {DR:%s} {DH:%s}, Failed store hhid\n",
                     lLogText.c_str(), msg->destinationRealm.c_str(),msg->destinationHost.c_str()));
         }
         auto end = std::chrono::high_resolution_clock::now();
         std::chrono::duration<double, std::milli> elapsed = end-start;
         if (rcode == 0 )
            AAA_LOG((LM_INFO,"%T |ROUTE| %s Successfully processed Request Message RTT:%.3f ms",lLogText.c_str(), elapsed.count()));
            AAA_LOG((LM_INFO,"%T |ROUTE| %s Successfully processed Request Message",lLogText.c_str()));
         return rcode;
      }
      else
      {
         //DiameterErrorMsg::Generate(*msg, AAA_UNABLE_TO_DELIVER , source); //TBC --Ask HV sir
         AAA_LOG((LM_ERROR, "%T |ROUTE| %s {OH:%s}, Route is not found\n", 
                  lLogText.c_str(), source->Data().m_HostEntry.m_Identity.c_str() ));
         //source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
         return -1;
      }
   }

   //-------------------------------------------------------------------------------
   // METHOD      :
   // DESCRIPTION :
   // PARAMETER   :
   // RETURN      :
   // THROWS      :
   //-------------------------------------------------------------------------------
   int DiameterMsgRouter::DcRouted::SendMsgAsync(std::unique_ptr<DiameterMsg> msg, DiameterPeerEntry *source, DiameterPeerEntry *dest)
   {
      int rcode    = -1;
      int h2hIndex = 0;

      if ( dest == NULL)
      {
         AAA_LOG((LM_ERROR, "%T |ROUTE| TBR 1 ====ASYN  SID:%s\n",msg->baseClass->getSessionId()->getValue()));
         return rcode;
      }

      std::string lLogText = LOG_DIAMETER_AVPS(*msg);
      DiameterRouteEntry *route = DIAMETER_ROUTE_TABLE()->Lookup(msg->destinationRealm);

      if(route->AdveriseRoute())
      {

         list<OctetString*>* lRouteRecordList = NULL;
         try
         {
            lRouteRecordList = msg->baseClass->getRouteRecordList();
         }
         catch (...){ }

         if ( lRouteRecordList == NULL)
         {
            lRouteRecordList = msg->baseClass->setRouteRecordList();
         }

         OctetString *lRouteRecord = new OctetString();
         lRouteRecord->setValue((UINT8*)DIAMETER_CFG_TRANSPORT()->route_record_host_name.c_str() , DIAMETER_CFG_TRANSPORT()->route_record_host_name.size());
         lRouteRecordList->push_back(lRouteRecord);

         AAA_LOG((LM_ERROR, "%T |ROUTE| %s {OH:%s}, Route Record is stored in \n", lLogText.c_str(), 
                  DIAMETER_CFG_TRANSPORT()->route_record_host_name.c_str()  ));
      }
      /*
         if(dest->PeerData().m_UseStackIdentity)
         {
         msg->baseClass->setOriginHost()->setValue(const_cast<char*>(dest->HostEntry().m_Identity.c_str()));
         msg->baseClass->setOriginRealm()->setValue(const_cast<char*>(dest->HostEntry().m_Realm.c_str()));
         }
         */

      if (source)
      {
         int localHH = 0;

         if (msg->hdr.mCmdFlg.tBit )
         {
            if ( -1 == (localHH = Lookup(msg->hdr.mHopByHopId, msg->hdr.mApplId, msg->sessionId)))
            {
               localHH = DIAMETER_HOPBYHOP_GEN()->Get();
               Add(msg->hdr.mHopByHopId,localHH,msg->hdr.mApplId, msg->sessionId);
               h2hIndex = Add(localHH, msg, source, dest);
            }
            else
            {
               UpdateRequestTimeH2H(msg->hdr.mHopByHopId, localHH, msg->hdr.mApplId, msg->sessionId );
            }

            h2hIndex = localHH;

            if ( false == IsReqMsgPresent(localHH)) {
               h2hIndex = Add(localHH, msg, source, dest);
            }
            else {
               UpdateRequestTime(h2hIndex, msg, source, dest);
            }
         }
         else
         {
            localHH = DIAMETER_HOPBYHOP_GEN()->Get();
            Add(msg->hdr.mHopByHopId,localHH,msg->hdr.mApplId, msg->sessionId);
            h2hIndex = Add(localHH, msg, source, dest);
         }

         //if(m_SyncH2hHdlr != NULL)
         if(DIAMETER_CFG_GENERAL()->sync_hbh)
         {
            SyncHopByHopIdData    data;

            data.op         = SYNC_OP_ADD;
            data.localH2H   = localHH;
            data.origH2H    = msg->hdr.mHopByHopId;

            memcpy(data.sourceName, source->PeerData().m_Identity.c_str(), source->PeerData().m_Identity.size());
            memcpy(data.destName,   dest->PeerData().m_Identity.c_str(),   dest->PeerData().m_Identity.size());

            if(DIAMETER_CFG_TRANSPORT()->use_sentinel ==1 )
               m_SyncH2hHdlr->SendSyncData(data);
            else
               DIAMETER_HBH_SYNC()->syncHbH(data);
         }

         msg->hdr.mHopByHopId = localHH;
         AAA_LOG((LM_DEBUG,"%T |ROUTE| %s Replaced original HH with Local HH:%X\n",lLogText.c_str(),msg->hdr.mHopByHopId ));  
      }
      else
      {
         // locally generated
         if (msg->hdr.mHopByHopId == 0)
         {
            msg->hdr.mHopByHopId = DIAMETER_HOPBYHOP_GEN()->Get();
         }

         if (msg->hdr.mEndToEndId == 0)
         {
            msg->hdr.mEndToEndId = DIAMETER_ENDTOEND_GEN()->Get();
         }

         h2hIndex = Add(msg->hdr.mHopByHopId, msg, source, dest);
      }

      if (h2hIndex > 0)
      {
         if( dest != NULL && dest->IsOpen())
         {
            rcode = (dest->Send(msg, true) >= 0) ? 0 : (-1);
            AAA_LOG((LM_DEBUG, "%T |ROUTE| %s Message send \n",lLogText.c_str()));
         }
         else
         {
            AAA_LOG((LM_ERROR, "%T |ROUTE| %s {OH:%s}, Dest object is null.. Message send failed\n",
                     lLogText.c_str(), source->Data().m_HostEntry.m_Identity.c_str() ));
            return (-1);
         }
      }
      else
      {
         AAA_LOG((LM_ERROR, "%T |ROUTE| %s {DR:%s} {DH:%s}, Failed store hhid\n",
                  lLogText.c_str(), msg->destinationRealm.c_str(),msg->destinationHost.c_str()));
      }

      return rcode;
   }

   //-------------------------------------------------------------------------------
   // METHOD      :
   // DESCRIPTION :
   // PARAMETER   :
   // RETURN      :
   // THROWS      :
   //-------------------------------------------------------------------------------
   int DiameterMsgRouter::DcRouted::SendNackMsgAsync(std::unique_ptr<DiameterMsg> msg, DiameterPeerEntry *source, DiameterPeerEntry *dest)
   {
      if(source != NULL)
      {
         AAA_LOG((LM_ERROR, "%T |ROUTE| DR:%s Success to Send NACK\n",
                  source->Data().m_HostEntry.m_Identity.c_str()));

         source->Send(msg,true);
      }
      else
      {
         AAA_LOG((LM_ERROR, "%T |ROUTE| Unable to Send NACK\n"));
         return 1;
      }
      return 0;
   }

   //-------------------------------------------------------------------------------
   // METHOD      :
   // DESCRIPTION :
   // PARAMETER   :
   // RETURN      :
   // THROWS      :
   //-------------------------------------------------------------------------------
   int DiameterMsgRouter::DcRouted::SyncAddHopByHopId(SyncHopByHopIdData &data)
   {
      std::unique_ptr<DiameterMsg> msg(new DiameterMsg);

      std::string sourceName = data.sourceName;
      std::string destName   = data.destName;
      //sourceName.assign(data.sourceName, strlen(data.sourceName));
      //destName.assign(data.destName, strlen(data.destName));

      msg->hdr.mHopByHopId = data.origH2H;

      DiameterPeerEntry* source = DIAMETER_PEER_TABLE()->Lookup(sourceName);
      DiameterPeerEntry* dest   = DIAMETER_PEER_TABLE()->Lookup(destName);

      Add(data.localH2H, msg, source, dest);

      return (0);
   }

   //-------------------------------------------------------------------------------
   // METHOD      :
   // DESCRIPTION :
   // PARAMETER   :
   // RETURN      :
   // THROWS      :
   //-------------------------------------------------------------------------------
   int DiameterMsgRouter::DcRouted::SyncDelHopByHopId(SyncHopByHopIdData &data)
   {
      return DeleteQueuedMessage(data.localH2H);
   }

   //-------------------------------------------------------------------------------
   // METHOD      :
   // DESCRIPTION :
   // PARAMETER   :
   // RETURN      :
   // THROWS      :
   //-------------------------------------------------------------------------------
   int DiameterMsgRouter::DcRouted::GetSyncProxyHopByHopId(SyncHopByHopIdData &data)
   {
      /*if(m_SyncH2hHdlr != NULL)
        {
        return m_SyncH2hHdlr->GetSyncData(data);
        }*/
      if(DIAMETER_CFG_GENERAL()->sync_hbh != 1)
      {
         return 0;
      }

      Redis *lRedis = DIAMETER_SYNC()->Acquire();

      std::string key = to_string(data.localH2H);
      std::map<std::string, std::string> multipleKV;

      if(lRedis != NULL && lRedis->read(key, multipleKV))
      {
         if ( multipleKV.empty()){
            DIAMETER_SYNC()->Release(lRedis);
            return 0;
         }

         auto it = multipleKV.begin();
         std::string dName = it->second;

         it++;
         if ( it == multipleKV.end())
         {
            DIAMETER_SYNC()->Release(lRedis);
            return 0;
         }

         std::string lH2H = it->second;

         it++;
         if ( it == multipleKV.end())
         {
            DIAMETER_SYNC()->Release(lRedis);
            return 0;
         }

         std::string node = it->second;

         it++;
         if ( it == multipleKV.end())
         {
            DIAMETER_SYNC()->Release(lRedis);
            return 0;
         }

         std::string oH2H = it->second;

         it++;
         if ( it == multipleKV.end())
         {
            DIAMETER_SYNC()->Release(lRedis);
            return 0;
         }

         std::string op = it->second;

         it++;
         if ( it == multipleKV.end())
         {
            DIAMETER_SYNC()->Release(lRedis);
            return 0;
         }

         std::string sName = it->second;

         data.op       = (SyncOperation)atoi(op.c_str());
         data.localH2H = atoi(lH2H.c_str());
         data.origH2H  = atoi(oH2H.c_str());
         snprintf(data.sourceName, sizeof(data.sourceName), "%s",  sName.c_str());
         snprintf(data.destName, sizeof(data.destName), "%s", dName.c_str());

         DIAMETER_SYNC()->Release(lRedis);
         return 1;
      }

      if (lRedis != NULL)
         DIAMETER_SYNC()->Release(lRedis);
      return 0;
   }

   //-------------------------------------------------------------------------------
   // METHOD      :
   // DESCRIPTION :
   // PARAMETER   :
   // RETURN      :
   // THROWS      :
   //-------------------------------------------------------------------------------
   AAA_ROUTE_RESULT DiameterMsgRouter::DcReject::Process(std::unique_ptr<DiameterMsg> msg,
         //std::unique_ptr<DiameterMsg> &p,
         DiameterPeerEntry *source,
         DiameterPeerEntry *&dest)
   {
      /*
         6.2.1.  Processing received Answers

         A Diameter client or proxy MUST match the Hop-by-Hop Identifier in an
         answer received against the list of pending requests.  The
         corresponding message should be removed from the list of pending
         requests.  It SHOULD ignore answers received that do not match a
         known Hop-by-Hop Identifier.
         */
      std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
      AAA_LOG((LM_ERROR, "%T |ROUTE| %s {DR:%s} {DH:%s}, Router rejected answer message\n", 
               lLogText.c_str(), msg->destinationRealm.c_str(),msg->destinationHost.c_str()));

      source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);
      DiameterMsgHeaderDump::Dump(*msg);
      return (AAA_ROUTE_RESULT_SUCCESS);
   }

   //-------------------------------------------------------------------------------
   // METHOD      :
   // DESCRIPTION :
   // PARAMETER   :
   // RETURN      :
   // THROWS      :
   //-------------------------------------------------------------------------------
   int DiameterMsgRouter::DcReject::RequestMsg(std::unique_ptr<DiameterMsg> msg,
         DiameterPeerEntry *source,
         DiameterPeerEntry *&dest)
   {
      /*
         6.1.  Diameter Request Routing Overview
         .
         .
         .
         4. If none of the above is successful, an answer is returned with the
         Result-Code set to AAA_UNABLE_TO_DELIVER, with the E-bit set.
         */
      std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
      AAA_LOG((LM_ERROR, "%T |ROUTE| %s {DR:%s} {DH:%s}, Router rejected request message\n", 
               lLogText.c_str(), msg->destinationRealm.c_str(),msg->destinationHost.c_str()));
      source->PeerData().m_Peg->GeneratePeg(DiameterPeg::E_SYS_ERR);

      DiameterMsgHeaderDump::Dump(*msg);

      if (! source) {
         // request must have been locally generated
         m_Arg[DiameterMsgRouterHandlerTable::H_ERROR]->
            Request(msg, source, dest);
         return (0);
      }
      else {
         DiameterErrorMsg::Generate(*msg, AAA_UNABLE_TO_DELIVER, source);
         if (false == DIAMETER_CFG_TRANSPORT()->route_record_host_name.empty() )
            msg->baseClass->setOriginHost()->setValue(const_cast<char*>( DIAMETER_CFG_TRANSPORT()->route_record_host_name.c_str() ) );

         if ( false == DIAMETER_CFG_TRANSPORT()->route_record_realm_name.empty() )
            msg->baseClass->setOriginRealm()->setValue(const_cast<char*>(DIAMETER_CFG_TRANSPORT()->route_record_realm_name.c_str()));

         return (source->Send(msg) == 0) ? 0 : (-1);
      }
   }

   //-------------------------------------------------------------------------------
   // METHOD      :
   // DESCRIPTION :
   // PARAMETER   :
   // RETURN      :
   // THROWS      :
   //-------------------------------------------------------------------------------
   AAA_ROUTE_RESULT DiameterMsgRouter::DcReject::Lookup(std::unique_ptr<DiameterMsg> &msg,
         //std::unique_ptr<DiameterMsg> &p,
         DiameterPeerEntry *source,
         DiameterPeerEntry *&dest)
   {
      /*
         6.2.1.  Processing received Answers

         A Diameter client or proxy MUST match the Hop-by-Hop Identifier in an
         answer received against the list of pending requests.  The
         corresponding message should be removed from the list of pending
         requests.  It SHOULD ignore answers received that do not match a
         known Hop-by-Hop Identifier.
         */
      return (AAA_ROUTE_RESULT_SUCCESS);
   }

   //-------------------------------------------------------------------------------
   // METHOD      :
   // DESCRIPTION :
   // PARAMETER   :
   // RETURN      :
   // THROWS      :
   //-------------------------------------------------------------------------------
   int DiameterMsgRouter::RedirectAgent::Request(std::unique_ptr<DiameterMsg> &msg,
         DiameterPeerEntry *source,
         DiameterPeerEntry *&dest)
   {
      /*
         6.1.7.  Redirecting requests

         When a redirect agent receives a request whose routing entry is set
         to REDIRECT, it MUST reply with an answer message with the 'E' bit
         set, while maintaining the Hop-by-Hop Identifier in the header, and
         include the Result-Code AVP to AAA_REDIRECT_INDICATION.  Each of
         the servers associated with the routing entry are added in separate
         Redirect-Host AVP.

         +------------------+
         |     Diameter     |
         |  Redirect Agent  |
         +------------------+
         ^    |    2. command + 'E' bit
         1. Request     |    |    Result-Code =
         joe@example.com |    |    AAA_REDIRECT_INDICATION +
         |    |    Redirect-Host AVP(s)
         |    v
         +-------------+  3. Request  +-------------+
         | example.com |------------->| example.net |
         |    Relay    |              |   Diameter  |
         |    Agent    |<-------------|    Server   |
         +-------------+  4. Answer   +-------------+

         Figure 5: Diameter Redirect Agent

         The receiver of the answer message with the 'E' bit set, and the
         Result-Code AVP set to AAA_REDIRECT_INDICATION uses the hop-by-
         hop field in the Diameter header to identify the request in the
         pending message queue (see Section 5.3) that is to be redirected.  If
         no transport connection exists with the new agent, one is created,
         and the request is sent directly to it.

         Multiple Redirect-Host AVPs are allowed.  The receiver of the answer
         message with the 'E' bit set selects exactly one of these hosts as
         the destination of the redirected message.
         */
      std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
      AAA_LOG((LM_INFO, "%T |ROUTE| %s {DR:%s} {DH:%s}, Request is being re-directed\n", 
               lLogText.c_str(), msg->destinationRealm.c_str(),msg->destinationHost.c_str()));

#if 0
      DiameterIdentityAvpContainerWidget destRealm(msg->acl);
      diameter_identity_t *DestRealm = destRealm.GetAvp((char *)DIAMETER_AVPNAME_DESTREALM);
      DiameterRouteEntry *route = DIAMETER_ROUTE_TABLE()->Lookup(*DestRealm);

      std::unique_ptr<DiameterMsg> answerMsg = DiameterErrorMsg::Generate(*msg, AAA_REDIRECT_INDICATION);

      AAA_LOG((LM_INFO, "(%P|%t) Request is being re-directed\n"));

      try {
         diameter_unsigned32_t *idPtr;
         char *avpNames[] = { (char *)DIAMETER_AVPNAME_AUTHAPPID,
            (char *)DIAMETER_AVPNAME_ACCTAPPID };
         DiameterUInt32AvpContainerWidget id(msg->acl);
         for (unsigned int i=0; i<sizeof(avpNames)/sizeof(char*); i++) 
         {
            if ((idPtr = id.GetAvp(avpNames[i]))) {
               break;
            }
         }

         DiameterRouteApplication *app = route->Lookup(msg->hdr.mApplId, 0);
         if ((app == NULL) && idPtr) {
            app = route->Lookup(*idPtr, 0); // base protocol only
         }
         else {
            DiameterGroupedAvpContainerWidget vendorSpecificId(msg->acl);
            diameter_grouped_t *grouped = vendorSpecificId.GetAvp
               ((char *)DIAMETER_AVPNAME_VENDORAPPID);
            if (grouped) {
               DiameterUInt32AvpContainerWidget gVendorId(*grouped);
               diameter_unsigned32_t *vid = gVendorId.GetAvp((char *)DIAMETER_AVPNAME_VENDORID);
               if (vid == NULL) {
                  AAA_LOG((LM_INFO, "(%P|%t) Vendor-Specific-Application-Id has no vendor ID AVP\n"));
                  return (-1);
               }

               diameter_unsigned32_t *value = NULL;
               char *avpNames[] = { (char *)DIAMETER_AVPNAME_AUTHAPPID,
                  (char *)DIAMETER_AVPNAME_ACCTAPPID };
               DiameterUInt32AvpContainerWidget gId(*grouped);
               for (unsigned int i=0; i<sizeof(avpNames)/sizeof(char*); i++) {
                  if ((value = gId.GetAvp(avpNames[i]))) {
                     break;
                  }
               }

               if (value) {
                  app = route->Lookup(*value, *vid);
               }
            }
         }

         if (app) {
            DiameterDiamUriAvpWidget redirect((char *)DIAMETER_AVPNAME_REDIRECTHOST);
            DiameterRouteServerEntry *server = app->Servers().First();
            while (server) {
               diameter_uri_t &uri = redirect.Get();
               uri.fqdn = server->Server();
               server = app->Servers().Next(*server);
            }
            if (! redirect.empty()) {
               DiameterEnumAvpWidget redirectUsage((char *)DIAMETER_AVPNAME_REDIRECTHOSTUSAGE);
               redirectUsage.Get() = route->RedirectUsage();
               answerMsg->acl.add(redirectUsage());
               answerMsg->acl.add(redirect());
            }
         }
      }
      catch (...) {
         return (-1);
      }

      return (source->Send(answerMsg) >= 0) ? 0 : (-1);
#endif
      return 0; // TBD_RET
   }

   //-------------------------------------------------------------------------------
   // METHOD      :
   // DESCRIPTION :
   // PARAMETER   :
   // RETURN      :
   // THROWS      :
   //-------------------------------------------------------------------------------
   int DiameterMsgRouter::RedirectAgent::Answer(std::unique_ptr<DiameterMsg> &msg,
         DiameterPeerEntry *source,
         DiameterPeerEntry *&dest)
   {
      /*
         2.8.3.  Redirect Agents

         Redirect agents are useful in scenarios where the Diameter routing
         configuration needs to be centralized.  An example is a redirect
         agent that provides services to all members of a consortium, but does
         not wish to be burdened with relaying all messages between realms.
         This scenario is advantageous since it does not require that the
         consortium provide routing updates to its members when changes are
         made to a member's infrastructure.

         Since redirect agents do not relay messages, and only return an
         answer with the information necessary for Diameter agents to
         communicate directly, they do not modify messages.  Since redirect
         agents do not receive answer messages, they cannot maintain session
         state.  Further, since redirect agents never relay requests, they are
         not required to maintain transaction state.

         The example provided in Figure 3 depicts a request issued from the
         access device, NAS, for the user bob@example.com.  The message is
         forwarded by the NAS to its relay, DRL, which does not have a routing
         entry in its Diameter Routing Table for example.com.  DRL has a
         default route configured to DRD, which is a redirect agent that
         returns a redirect notification to DRL, as well as HMS' contact
         information.  Upon receipt of the redirect notification, DRL
         establishes a transport connection with HMS, if one doesn't already
         exist, and forwards the request to it.

         +------+
         |      |
         | DRD  |
         |      |
         +------+
         ^    |
         2. Request  |    | 3. Redirection
         |    |    Notification
         |    v
         +------+    --------->     +------+     --------->    +------+
         |      |    1. Request     |      |     4. Request    |      |
         | NAS  |                   | DRL  |                   | HMS  |
         |      |    6. Answer      |      |     5. Answer     |      |
         +------+    <---------     +------+     <---------    +------+
         example.net                example.net               example.com

         Figure 3: Redirecting a Diameter Message

         Since redirect agents do not perform any application level
         processing, they provide relaying services for all Diameter
         applications, and therefore MUST advertise the Relay Application
         Identifier.
         */


      std::string lLogText = LOG_DIAMETER_AVPS(*msg);	
      AAA_LOG((LM_INFO, "%T |ROUTE| %s {DR:%s} {DH:%s}, Processing re-directed answer\n", 
               lLogText.c_str(), msg->destinationRealm.c_str(),msg->destinationHost.c_str()));


#if 0
      DiameterUInt32AvpContainerWidget resultCode(msg->acl);
      resultCode.DelAvp((char *)DIAMETER_AVPNAME_RESULTCODE);

      DiameterUriAvpContainerWidget redirect(msg->acl);
      diameter_uri_t *RedirectHost = redirect.GetAvp((char *)DIAMETER_AVPNAME_REDIRECTHOST);

      for (int h=1; RedirectHost; h++) {
         DiameterPeerEntry *peer = DIAMETER_PEER_TABLE()->Lookup(RedirectHost->fqdn);
         if (peer) {
            if (peer->IsOpen()) {
               DiameterIdentityAvpContainerWidget dhost(p->acl);
               diameter_identity_t *hostname = dhost.GetAvp((char *)DIAMETER_AVPNAME_DESTHOST);
               if (hostname) {
                  *hostname = RedirectHost->fqdn;
               }
               else {
                  DiameterIdentityAvpWidget destHost((char *)DIAMETER_AVPNAME_DESTHOST);
                  destHost.Get() = RedirectHost->fqdn;
                  p->acl.add(destHost());
               }
               AAA_LOG((LM_INFO, "(%P|%t) Redirecting msg to [%s]\n",
                        RedirectHost->fqdn.c_str()));
               return (peer->Send(p) >= 0) ? 0 : (-1);
            }
            else {
               AAA_LOG((LM_INFO, "(%P|%t) TBD: Have to try and connect to [%s]\n",
                        RedirectHost->fqdn.c_str()));
               // try opening it [TBD]
            }
         }
         else {
            AAA_LOG((LM_INFO, "(%P|%t) TBD: Have to try and connect to [%s]\n",
                     RedirectHost->fqdn.c_str()));
            // try to make connection to it [TBD]
         }

         RedirectHost = redirect.GetAvp((char *)DIAMETER_AVPNAME_REDIRECTHOST, h);
      }

#endif
      AAA_LOG((LM_INFO, "%T |ROUTE| %s {DR:%s} {DH:%s}, Suggested re-direct host is un-available\n", 
               lLogText.c_str(), msg->destinationRealm.c_str(),msg->destinationHost.c_str()));

      return (0);
   }

   //-------------------------------------------------------------------------------
   // METHOD      :
   // DESCRIPTION :
   // PARAMETER   :
   // RETURN      :
   // THROWS      :
   //-------------------------------------------------------------------------------
   bool DiameterMsgRouter::RedirectAgent::IsRedirected(std::unique_ptr<DiameterMsg> &msg)
   {
      /*
         The receiver of the answer message with the 'E' bit set, and the
         Result-Code AVP set to AAA_REDIRECT_INDICATION uses the hop-by-
         hop field in the Diameter header to identify the request in the
         pending message queue (see Section 5.3) that is to be redirected.  If
         no transport connection exists with the new agent, one is created,
         and the request is sent directly to it.

         Multiple Redirect-Host AVPs are allowed.  The receiver of the answer
         message with the 'E' bit set selects exactly one of these hosts as
         the destination of the redirected message.
         */
      return false;
#if 0
      DiameterMsgResultCode rcode(*msg);
      return ((msg->hdr.mCmdFlg.rBit == 0) &&
            (msg->hdr.mCmdFlg.eBit) &&
            (rcode.ResultCode() == AAA_REDIRECT_INDICATION));
#endif
   }

   AAA_SyncHopByHopHandler* DiameterMsgRouter::m_SyncH2hHdlr = NULL;
   //DiameterMsgRouter* DiameterMsgRouter::mDiameterMsgRouter=NULL;
