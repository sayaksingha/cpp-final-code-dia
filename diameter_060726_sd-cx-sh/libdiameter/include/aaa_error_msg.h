// @(#) $Id: aaa_error_msg.h,v 1.1.4.1.2.1.2.1 2019/04/19 01:49:43 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_error_msg.h
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
#ifndef __AAA_ERROR_MSG_H__
#define __AAA_ERROR_MSG_H__

#include "aaa_peer_table.h"

class DiameterErrorMsg 
{
	/*

	   7.2.  Error Bit

	   The 'E' (Error Bit) in the Diameter header is set when the request
	   caused a protocol-related error (see Section 7.1.3).  A message with
	   the 'E' bit MUST NOT be sent as a response to an answer message.
	   Note that a message with the 'E' bit set is still subjected to the
	   processing rules defined in Section 6.2.  When set, the answer
	   message will not conform to the ABNF specification for the command,
	   and will instead conform to the following ABNF:

	   Message Format

	   <answer-message> ::= < Diameter Header: code, ERR [PXY] >
	   0*1< Session-Id >
	   { Origin-Host }
	   { Origin-Realm }
	   { Result-Code }
	   [ Origin-State-Id ]
	   [ Error-Reporting-Host ]
	   [ Proxy-Info ]
	   * [ AVP ]

	   Note that the code used in the header is the same than the one found
	   in the request message, but with the 'R' bit cleared and the 'E' bit
	   set.  The 'P' bit in the header is set to the same value as the one
	   found in the request message.
	 */
  
 public:
	static void Generate(DiameterMsg &msg, diameter_unsigned32_t rcode, DiameterPeerEntry *source) 
	{
		DiaHandleMsg::SetAnswerParam(msg);

		msg.baseClass->setOriginHost()->setValue((UINT8*)source->HostEntry().m_Identity.c_str(), source->HostEntry().m_Identity.size());
		msg.baseClass->setOriginRealm()->setValue((UINT8*)source->HostEntry().m_Realm.c_str(), source->HostEntry().m_Realm.size());

		msg.baseClass->setResultCode()->setValue(rcode);
	}

};

#endif				// __AAA_ERROR_MSG_H__
