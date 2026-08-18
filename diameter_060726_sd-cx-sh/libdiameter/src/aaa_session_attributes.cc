static const char *id = " @(#) $Id: aaa_session_attributes.cc,v 1.1.4.1.2.1.2.1 2018/05/14 23:24:33 anandhv Exp $";
//----------------------------------------------------------------------
// NAME
// aaa_session_attributes.cc
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
#include "aaa_route_id_generator.h"
#include "aaa_session_attributes.h"

void DiameterSessionAttributes::MsgIdTxMessage(DiameterMsg &msg)
{
   if (msg.hdr.mCmdFlg.rBit) {
       if (msg.hdr.mHopByHopId == 0) {
           m_LastTxHopId = DIAMETER_HOPBYHOP_GEN()->Get();
           msg.hdr.mHopByHopId = m_LastTxHopId;
       }
       else {
	   m_LastTxHopId = msg.hdr.mHopByHopId;
       }
       if (msg.hdr.mEndToEndId == 0) {
           m_LastTxEndId = DIAMETER_ENDTOEND_GEN()->Get();
           msg.hdr.mEndToEndId = m_LastTxEndId;
       }
       else {
           m_LastTxEndId = msg.hdr.mEndToEndId;
       }
   }
   else {
       msg.hdr.mHopByHopId = m_LastRxHopId;
       msg.hdr.mEndToEndId = m_LastRxEndId;
   }
}

bool DiameterSessionAttributes::MsgIdRxMessage(DiameterMsg &msg)
{
   if (msg.hdr.mCmdFlg.rBit) {
       m_LastRxHopId = msg.hdr.mHopByHopId;
       m_LastRxEndId = msg.hdr.mEndToEndId;
       return (true);
   }
   return ((msg.hdr.mHopByHopId == m_LastTxHopId) &&
           (msg.hdr.mEndToEndId == m_LastTxEndId));
}

AAAReturnCode DiameterSessionId::Get(DiameterMsg &msg)
{
   diameter_utf8string_t *sid =  &(msg.sessionId);	

   try {
      if (sid == NULL) {
         throw (AAA_ERR_PARSING_FAILED);
      }
      ACE_UINT32 where1 = sid->find(";");
      if (where1 == std::string::npos) {
         throw (AAA_ERR_PARSING_FAILED);
      }
      DiameterId() = sid->substr(0, where1);

      ACE_UINT32 where2 = sid->find(";", ++ where1);
      if (where2 == std::string::npos) {
         throw (AAA_ERR_PARSING_FAILED);
      }
      std::string stringHigh = sid->substr(where1, where2-where1);
      High() = ACE_OS::strtoul(stringHigh.c_str(), NULL, 10);

      where1 = sid->find(";", ++ where2);
      if (where1 == std::string::npos) {
         std::string stringLow = sid->substr(where2);
         Low() = ACE_OS::atoi(stringLow.c_str());
      }
      else {
         std::string stringLow = sid->substr(where2, where1-where2);
         Low() = ACE_OS::atoi(stringLow.c_str());
         OptionalValue() = sid->substr(++ where1);
      }
		return (AAA_ERR_SUCCESS);
   }
   catch (AAAReturnCode rc) {
      return (rc);
   } 
}

AAAReturnCode DiameterSessionId::Set(DiameterMsg &msg)
{
	/*
   //DiameterUtf8AvpContainerWidget sidAvp(msg.acl);
   //diameter_utf8string_t &sid = sidAvp.AddAvp(DIAMETER_AVPNAME_SESSIONID);
   
   char nums[64];
   sprintf(nums, ";%u;%u", High(), Low());
   sid = DiameterId() + nums;

   if (OptionalValue().length() > 0) {
       sid += ";";
       sid += OptionalValue();
   }*/
   return (AAA_ERR_SUCCESS);
}

void DiameterSessionId::Dump()
{
   std::string dump;
   Dump(dump);
   AAA_LOG((LM_INFO, "%T |Session| Session id=%s\n", dump.c_str()));
}

void DiameterSessionId::Dump(std::string &dump)
{

   dump = DiameterId().c_str();
 /*  dump += ';';
 dump += (boost::lexical_cast<std::string>(High())).c_str();
 dump += ';';
 dump += (boost::lexical_cast<std::string>(Low())).c_str();
 dump += ';';
 dump += OptionalValue().c_str();   */
}
