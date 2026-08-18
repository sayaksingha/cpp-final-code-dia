static const char *id = " @(#) $Id: aaa_parser.cc,v 1.1.4.1.2.1 2018/02/21 23:00:49 anandhv Exp $";
//----------------------------------------------------------------------
// NAME
// aaa_parser.cc
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
#include <ace/OS.h>
#include <list>
#include <typeinfo>
#include "resultcodes.h"    /* file location will be changed */
#include "diameter_parser.h"



//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
template<> void
DiameterMsgHeaderParser::parseRawToApp()// throw(DiameterErrorCode)
{

  AAAMessageBlock   *aBuffer   = getRawData();
  DiameterMsgHeader *aHeader   = getAppData();
// DiameterParseOption opt    = getDictData();

  DiameterMsgHeader &h = *aHeader;

  aBuffer->rd_ptr(aBuffer->base());

  char *p = aBuffer->rd_ptr();

  DiameterErrorCode st;
//  DiameterCommand *com;

  h.ver = *((AAAUInt8*)(p));
  h.length = ntohl(*((ACE_UINT32*)(p))) & 0x00ffffff;
  p += 4;

  h.flags.r = *((AAAUInt8*)(p)) >> 7;
  h.flags.p = *((AAAUInt8*)(p)) >> 6;
  h.flags.e = *((AAAUInt8*)(p)) >> 5;
  h.flags.t = *((AAAUInt8*)(p)) >> 4;

  h.code = ntohl(*((ACE_UINT32*)(p))) & 0x00ffffff;
  p += 4;

  h.appId = ntohl(*((ACE_UINT32*)(p)));
  p += 4;

  h.hh = ntohl(*((ACE_UINT32*)(p)));
  p += 4;

  h.ee = ntohl(*((ACE_UINT32*)(p)));
  p += 4;

  aBuffer->rd_ptr(p);

 return;
#if 0
  if (opt == DIAMETER_PARSE_LOOSE)
  {
	  return;
  }

  if ((com = DiameterCommandList::instance()->search(h.code, h.appId, h.flags.r)) == NULL)
  {
	  AAA_LOG((LM_ERROR, "command (%d,r-flag=%1d) not found\n", 
				  h.code, h.flags.r));
	  st.set(AAA_PARSE_ERROR_TYPE_NORMAL, AAA_COMMAND_UNSUPPORTED);
	  throw st;
  }

  if (com->flags.r && h.flags.e)
  {
	  AAA_LOG((LM_ERROR, "command (%d) e flag cannot be set for request\n", h.code));
	  st.set(AAA_PARSE_ERROR_TYPE_NORMAL, AAA_INVALID_BIT_IN_HEADER);
	  throw st;
  }

  if (com->flags.p == 0 && h.flags.p == 1)
  {
	  AAA_LOG((LM_ERROR, 
				  "command (%d) contains mismatch in p flag\n", 
				  h.code));
	  st.set(AAA_PARSE_ERROR_TYPE_NORMAL, AAA_INVALID_BIT_IN_HEADER);
	  throw st;
  }

  /* special handling for answer message with error flag set */
  if (! com->flags.r && h.flags.e)
  {
	  if (h.flags.p)
	  {
		  com = DiameterCommandList::instance()
			  ->search("PROXYABLE-ERROR-Answer");
	  }
	  else
	  {
		  com = DiameterCommandList::instance()
			  ->search("NON-PROXYABLE-ERROR-Answer");
	  }
	  if (com == NULL)
	  {
		  AAA_LOG((LM_ERROR, 
					  "No way to handle answer with error\n"));
		  st.set(AAA_PARSE_ERROR_TYPE_NORMAL, AAA_COMMAND_UNSUPPORTED);
		  throw st;
	  }
  }

  h.dictHandle = com;
#endif
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
	template<> void
DiameterMsgHeaderParser::parseAppToRaw()// throw(DiameterErrorCode)
{
	AAAMessageBlock *aBuffer   = getRawData();
	DiameterMsgHeader *aHeader = getAppData();
//	DiameterParseOption opt 	= getDictData();
	DiameterMsgHeader &h 		= *aHeader;


	char *p 			 	   = aBuffer->base();
//	DiameterCommand *com = 0;
	DiameterErrorCode st;

	aBuffer->wr_ptr(aBuffer->base());


#if 0
	if (opt != DIAMETER_PARSE_LOOSE)
	{
		if ((com = DiameterCommandList::instance()->search(h.code, h.appId, h.flags.r)) == NULL)
		{
			AAA_LOG((LM_ERROR, "command (%d,r-flag=%1d) not found\n", 
						h.code, h.flags.r));
			st.set(AAA_PARSE_ERROR_TYPE_NORMAL, AAA_COMMAND_UNSUPPORTED);
			throw st;
		}

		if (com->flags.r && h.flags.e)
		{
			AAA_LOG((LM_ERROR, 
						"command (%d) e flag cannot be set for request\n", 
						h.code));
			st.set(AAA_PARSE_ERROR_TYPE_NORMAL, AAA_INVALID_HDR_BITS);
			throw st;
		}

		if (com->flags.p == 0 && h.flags.p == 1)
		{
			AAA_LOG((LM_ERROR, 
						"command (%d) contains mismatch in p flag\n", 
						h.code));
			st.set(AAA_PARSE_ERROR_TYPE_NORMAL, AAA_INVALID_HDR_BITS);
			throw st;
		}

		/* special handling for answer message with error flag set */
		if (! com->flags.r && h.flags.e)
		{
			if (h.flags.p)
			{
				com = DiameterCommandList::instance()->search("PROXYABLE-ERROR-Answer");
			}
			else
			{
				com = DiameterCommandList::instance()->search("NON-PROXYABLE-ERROR-Answer");
			}
			if (com == NULL)
			{
				AAA_LOG((LM_ERROR, 
							"No way to handle answer with error\n"));
	      st.set(AAA_PARSE_ERROR_TYPE_NORMAL, AAA_COMMAND_UNSUPPORTED);
	      throw st;
	    }
	}
    }
#endif

  *((ACE_UINT32*)(p)) = ntohl(h.length);
  *((AAAUInt8*)(p)) = h.ver;
  p += 4;
  *((ACE_UINT32*)(p)) = ntohl(h.code);
  *((AAAUInt8*)(p)) = 
    (h.flags.r << 7) | (h.flags.p << 6)  | 
    (h.flags.e << 5) | (h.flags.t << 4);;

  p += 4;
  *((ACE_UINT32*)(p)) = ntohl(h.appId);
  p += 4;
  *((ACE_UINT32*)(p)) = ntohl(h.hh);
  p += 4;
  *((ACE_UINT32*)(p)) = ntohl(h.ee);
  p += 4;

  aBuffer->wr_ptr(p);
//  h.dictHandle = com;
}
