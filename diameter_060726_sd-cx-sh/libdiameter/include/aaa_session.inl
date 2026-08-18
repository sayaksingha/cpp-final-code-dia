// @(#) $Id: aaa_session.inl,v 1.1.4.1.2.1.2.1 2024/05/15 13:10:19 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_session.inl
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
#ifndef __AAA_SESSION_INL__
#define __AAA_SESSION_INL__

template <class ATTRIBUTE>
AAAReturnCode DiameterSession<ATTRIBUTE>::TxDelivery(std::unique_ptr<DiameterMsg> msg) 
{
   m_Attributes.SessionId().Set(*msg);
   m_Attributes.MsgIdTxMessage(*msg);

   DiameterMsgQuery query(*msg);
   if (query.IsRequest()) {
      return (DIAMETER_MSG_ROUTER()->RequestMsg(std::move(msg), 0) ==
              AAA_ROUTE_RESULT_SUCCESS) ?
              AAA_ERR_SUCCESS : AAA_ERR_FAILURE;
   }
   else {
      return (DIAMETER_MSG_ROUTER()->AnswerMsg(std::move(msg), 0) ==
              AAA_ROUTE_RESULT_SUCCESS) ?
              AAA_ERR_SUCCESS : AAA_ERR_FAILURE;
   }
}

template <class ATTRIBUTE>
AAAReturnCode DiameterSession<ATTRIBUTE>::Reset() 
{
   return (AAA_ERR_SUCCESS);
}

#endif
