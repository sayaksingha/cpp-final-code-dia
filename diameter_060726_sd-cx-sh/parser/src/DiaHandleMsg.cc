static const char *id = " @(#) $Id: DiaHandleMsg.cc,v 1.1.2.2.2.8 2021/01/28 00:52:15 anandhv Exp $";
//----------------------------------------------------------------------
// NAME
// DiaHandleMsg.cc
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
#include "DiaHandleMsg.h"
#include "S6Parser.h"
#include "GxParser.h"
#include "RoParser.h"
#include "RxParser.h"
#include "SyParser.h"
#include "SlhParser.h"
#include "SdParser.h"
#include "ShParser.h"
#include "CxParser.h"
//-------------------------------------------------------------------------------
// METHOD      : Constructor
// DESCRIPTION : Constructor function
// PARAMETER   :
// RETURN      :
// THROWS      : none
//-------------------------------------------------------------------------------
DiaHandleMsg::DiaHandleMsg()
{
}

//-------------------------------------------------------------------------------
// METHOD      : Constructor
// DESCRIPTION : Constructor function
// PARAMETER   :
// RETURN      :
// THROWS      : none
//-------------------------------------------------------------------------------
DiaHandleMsg::~DiaHandleMsg()
{
}

//-------------------------------------------------------------------------------
// METHOD      : Constructor
// DESCRIPTION : Constructor function
// PARAMETER   :
// RETURN      :
// THROWS      : none
//-------------------------------------------------------------------------------
void DiaHandleMsg::DecodeReqMsg(DiameterMsg &msg)
{
	switch(msg.hdr.mApplId)
	{
		case AAA_S6_APP_ID:
			{
				m_s6_parser.CreateReqMsg(msg);
			}
			break;

		case AAA_Gx_APP_ID:
			{
				m_gx_parser.CreateReqMsg(msg);
			}
			break;

		case AAA_Ro_APP_ID:
			{
				m_ro_parser.CreateReqMsg(msg);
			}
			break;

		case AAA_Rx_APP_ID:
			{
				m_rx_parser.CreateReqMsg(msg);
			}
			break;
		case AAA_Sy_APP_ID:
			{
				m_sy_parser.CreateReqMsg(msg);
			}
			break;
		case AAA_Slh_APP_ID:
			{
				m_slh_parser.CreateReqMsg(msg);
			}
			break;
		case AAA_Sd_APP_ID:
			{
				m_sd_parser.CreateReqMsg(msg);
			}
			break;
		 case AAA_Sh_APP_ID:
		      {
			m_sh_parser.CreateReqMsg(msg);
		      }
     		        break;
	         case AAA_Cx_APP_ID:
		      {
			m_cx_parser.CreateReqMsg(msg);
		      }
		      break;
		default:
			{
				TEXT lErrorText[100] = "";
				snprintf(lErrorText,sizeof(lErrorText),"Unsupported Application-Id:%d ..", msg.hdr.mApplId);

//				AppIDNotSupportedFlag = 1;			

				DiameterBaseException lBaseException(DiameterBaseException::UNEXPECTED_FIELD, lErrorText);
				throw lBaseException;
			}
			break;
	}

	return;
}

//-------------------------------------------------------------------------------
// METHOD      : Constructor
// DESCRIPTION : Constructor function
// PARAMETER   :
// RETURN      :
// THROWS      : none
//-------------------------------------------------------------------------------
void DiaHandleMsg::DecodeAnsMsg(DiameterMsg &msg)
{
	switch(msg.hdr.mApplId)
	{
		case AAA_S6_APP_ID:
			{
				m_s6_parser.CreateAnsMsg(msg);
			}
			break;

		case AAA_Gx_APP_ID:
			{
				m_gx_parser.CreateAnsMsg(msg);
			}
			break;

		case AAA_Ro_APP_ID:
			{
				m_ro_parser.CreateAnsMsg(msg);
			}
			break;

		case AAA_Rx_APP_ID:
			{
				m_rx_parser.CreateAnsMsg(msg);
			}
			break;
		case AAA_Sy_APP_ID:
			{
				m_sy_parser.CreateAnsMsg(msg);
			}
			break;
		case AAA_Slh_APP_ID:
			{
				m_slh_parser.CreateAnsMsg(msg);
			}
			break;
                //sd-sh-cx new interface adition
		case AAA_Sd_APP_ID:
			{
				m_sd_parser.CreateAnsMsg(msg);
			}
			break;
		 case AAA_Sh_APP_ID:
		      {
				m_sh_parser.CreateAnsMsg(msg);
		      }
		      break;
		case AAA_Cx_APP_ID:
		      {
				m_cx_parser.CreateAnsMsg(msg);
		      }
		      break;
		default:
			{
				TEXT lErrorText[100] = "";
				snprintf(lErrorText,sizeof(lErrorText),"Unsupported Application-Id:%d ...", msg.hdr.mApplId);
				DiameterBaseException lBaseException(DiameterBaseException::UNEXPECTED_FIELD, lErrorText);
				throw lBaseException;
			}
			break;
	}

	return;
}

//-------------------------------------------------------------------------------
// METHOD      : Constructor
// DESCRIPTION : Constructor function
// PARAMETER   :
// RETURN      :
// THROWS      : none
//-------------------------------------------------------------------------------
	template <class DATA>
void DiaHandleMsg::DecodeMsg(DiameterMsg &msg)
{
	std::shared_ptr<DATA> data(new DATA,  std::default_delete<DATA>());
// Check for NULL / Use Count  / Success HV
	TRY_DECODE(data);

	msg.baseClass = data;

	TRY_OCTET_STRING(msg.originationHost,  data, getOriginHost);
	TRY_OCTET_STRING(msg.originationRealm, data, getOriginRealm);
	//TRY_OCTET_STRING(msg.destinationHost, data, getDestinationHost);
	TRY_OCTET_STRING(msg.destinationRealm, data, getDestinationRealm);

	TRY_OCTET_STRING(msg.sessionId, data, getSessionId);
	return;
}

//-------------------------------------------------------------------------------
// METHOD      : Constructor
// DESCRIPTION : Constructor function
// PARAMETER   :
// RETURN      :
// THROWS      : none
//-------------------------------------------------------------------------------
BOOLEAN DiaHandleMsg::EncodeMsg(DiameterMsg &msg,byteArray& rawByte)
{
	try {
		msg.baseClass->getDiameterMsgHeader()->mVersion= DIAMETER_PROTOCOL_VERSION;

		msg.baseClass->getDiameterMsgHeader()->mCmdFlg.rBit = msg.hdr.mCmdFlg.rBit;
		msg.baseClass->getDiameterMsgHeader()->mCmdFlg.pBit = msg.hdr.mCmdFlg.pBit;
		msg.baseClass->getDiameterMsgHeader()->mCmdFlg.eBit = msg.hdr.mCmdFlg.eBit;
		msg.baseClass->getDiameterMsgHeader()->mCmdFlg.tBit = msg.hdr.mCmdFlg.tBit;
		msg.baseClass->getDiameterMsgHeader()->mCmdFlg.reservedBits = 0;

		msg.baseClass->getDiameterMsgHeader()->mCmdCode    = msg.hdr.mCmdCode;
		msg.baseClass->getDiameterMsgHeader()->mApplId     = msg.hdr.mApplId;
		msg.baseClass->getDiameterMsgHeader()->mHopByHopId = msg.hdr.mHopByHopId;
		msg.baseClass->getDiameterMsgHeader()->mEndToEndId = msg.hdr.mEndToEndId ;

		string SID = msg.baseClass->getSessionId()->ToString();
		
      AAA_LOG((LM_DEBUG , "%T |TRANSPORT|  Encode Diameter message SId:%s CMD:%d %s %s %s %s LHH:%d EE:%d AppId:%d\n",
					SID.c_str() , msg.hdr.mCmdCode, (msg.hdr.mCmdFlg.rBit?"REQ":""),
					(msg.hdr.mCmdFlg.pBit?"PXY":""), (msg.hdr.mCmdFlg.eBit?"ERR":""),
					(msg.hdr.mCmdFlg.tBit?"RTX":""),
					msg.hdr.mHopByHopId, msg.hdr.mEndToEndId, msg.hdr.mApplId));

		if(DIAMETER_NO_ERR != msg.baseClass->Encode(&rawByte ))
		{
			AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| Failed to encode Diameter message,SId:%s CMD:%d %s %s %s %s LHH:%d EE:%d AppId:%d\n",
						SID.c_str() , msg.hdr.mCmdCode, (msg.hdr.mCmdFlg.rBit?"REQ":""),
						(msg.hdr.mCmdFlg.pBit?"PXY":""), (msg.hdr.mCmdFlg.eBit?"ERR":""),
						(msg.hdr.mCmdFlg.tBit?"RTX":""),
						msg.hdr.mHopByHopId, msg.hdr.mEndToEndId, msg.hdr.mApplId));
			return false;
		}
		AAA_LOG((LM_DEBUG, "%T |TRANSPORT| Success to encode Diameter message,SId:%s CMD:%d %s %s %s %s LHH:%X EE:%X AppId:%d\n", SID.c_str() , msg.hdr.mCmdCode, (msg.hdr.mCmdFlg.rBit?"REQ":""),
					(msg.hdr.mCmdFlg.pBit?"PXY":""), (msg.hdr.mCmdFlg.eBit?"ERR":""),
					(msg.hdr.mCmdFlg.tBit?"RTX":""),
					msg.hdr.mHopByHopId, msg.hdr.mEndToEndId, msg.hdr.mApplId));

	}
	catch (TssDiameterMsgException d)
	{
		AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| Diameter packet Encode error,Err:%d Msg:%s \n", d.getErrorCode(),d.getErrMessage()));
		return false;
	}

	return true;
}

//-------------------------------------------------------------------------------
// METHOD      : Constructor
// DESCRIPTION : Constructor function
// PARAMETER   :
// RETURN      :
// THROWS      : none
//-------------------------------------------------------------------------------
	template <class DATA>
void DiaHandleMsg::CreateInstance(DiameterMsg &msg, int resultCode)
{
	std::shared_ptr<DATA> data(new DATA,  std::default_delete<DATA>());
	// Check for Creation Success // HV
	
	data->setHopByHopId(msg.hdr.mHopByHopId);
   data->setEndToEndId(msg.hdr.mEndToEndId);
   data->setApplnId(msg.hdr.mApplId);

	data->setSessionId()->setValue((UINT8*)msg.sessionId.c_str(), msg.sessionId.length());
	data->setOriginRealm()->setValue((UINT8*)msg.destinationRealm.c_str(),(UINT32)msg.destinationRealm.length());
	if (false == DIAMETER_CFG_TRANSPORT()->route_record_host_name.empty())
		data->setOriginHost()->setValue(const_cast<char*>( DIAMETER_CFG_TRANSPORT()->route_record_host_name.c_str() ) );

	data->setResultCode()->setValue(resultCode);
	msg.baseClass = data;

	return;
}

//-------------------------------------------------------------------------------
// METHOD      : Constructor
// DESCRIPTION : Constructor function
// PARAMETER   :
// RETURN      :
// THROWS      : none
//-------------------------------------------------------------------------------
void DiaHandleMsg::SetAnswerParam(DiameterMsg &msg, int resultCode)
{
	msg.hdr.mCmdFlg.pBit  = DIAMETER_FLAG_SET;
	msg.hdr.mCmdFlg.eBit  = DIAMETER_FLAG_SET;
	msg.hdr.mCmdFlg.rBit  = DIAMETER_FLAG_CLR;
	msg.hdr.mCmdFlg.tBit  = DIAMETER_FLAG_CLR;

	msg.internalRspFlag = true;

	switch(msg.hdr.mApplId)
	{
		case AAA_S6_APP_ID:
			{
				m_s6_parser.SetAnswerParam(msg, resultCode);
			}
			break;

      case AAA_Gx_APP_ID:
         {
            m_gx_parser.SetAnswerParam(msg,resultCode);
         }
         break;

      case AAA_Ro_APP_ID:
         {
            m_ro_parser.SetAnswerParam(msg,resultCode);
         }
         break;

		case AAA_Rx_APP_ID:
         {
            m_rx_parser.SetAnswerParam(msg,resultCode);
         }
         break;
		case AAA_Sy_APP_ID:
         {
            m_sy_parser.SetAnswerParam(msg,resultCode);
         }
         break;
	case AAA_Slh_APP_ID:
         {
            m_slh_parser.SetAnswerParam(msg,resultCode);
         }
	 break;
	case AAA_Sd_APP_ID:
         {
            m_sd_parser.SetAnswerParam(msg,resultCode);
         }
         break;
        case AAA_Sh_APP_ID:
         {
            m_sh_parser.SetAnswerParam(msg,resultCode);
         
	 }

         break;

	case AAA_Cx_APP_ID:
         {
            m_cx_parser.SetAnswerParam(msg,resultCode);
         }
         break;
      default:
         break;
   }

   return;
}

//-------------------------------------------------------------------------------
// METHOD      : Constructor
// DESCRIPTION : Constructor function
// PARAMETER   :
// RETURN      :
// THROWS      : none
//-------------------------------------------------------------------------------
void DiaHandleMsg::DecodeBaseMsg(DiameterMsg &msg)
{
//	std::shared_ptr<DATA> data(new DATA,  std::default_delete<DATA>());
//	TRY_DECODE(data);
//	msg.baseClass = data;

#if 0
 Acct-             85  9.8.2   Unsigned32 | M  |  V  |
     Interim-Interval                       |    |     |
   Accounting-      483  9.8.7   Enumerated | M  |  V  |
     Realtime-Required                      |    |     |
   Acct-            50   9.8.5   UTF8String | M  |  V  |
     Multi-Session-Id                       |    |     |
   Accounting-      485  9.8.3   Unsigned32 | M  |  V  |
     Record-Number                          |    |     |
   Accounting-      480  9.8.1   Enumerated | M  |  V  |
     Record-Type                            |    |     |
   Acct-             44  9.8.4   OctetString| M  |  V  |
    Session-Id                              |    |     |
   Accounting-      287  9.8.6   Unsigned64 | M  |  V  |
     Sub-Session-Id                         |    |     |
   Acct-            259  6.9     Unsigned32 | M  |  V  |
     Application-Id                         |    |     |
   Auth-            258  6.8     Unsigned32 | M  |  V  |
     Application-Id                         |    |     |
   Auth-Request-    274  8.7     Enumerated | M  |  V  |
      Type                                  |    |     |
   Authorization-   291  8.9     Unsigned32 | M  |  V  |
     Lifetime                               |    |     |
   Auth-Grace-      276  8.10    Unsigned32 | M  |  V  |
     Period                                 |    |     |
   Auth-Session-    277  8.11    Enumerated | M  |  V  |
     State                                  |    |     |
   Re-Auth-Request- 285  8.12    Enumerated | M  |  V  |
     Type                                   |    |     |
   Class             25  8.20    OctetString| M  |  V  |
   Destination-Host 293  6.5     DiamIdent  | M  |  V  |
   Destination-     283  6.6     DiamIdent  | M  |  V  |
     Realm                                  |    |     |
   Disconnect-Cause 273  5.4.3   Enumerated | M  |  V  |
   Error-Message    281  7.3     UTF8String |    | V,M |
   Error-Reporting- 294  7.4     DiamIdent  |    | V,M |
     Host                                   |    |     |
   Event-Timestamp   55  8.21    Time       | M  |  V  |
   Experimental-    297  7.6     Grouped    | M  |  V  |
      Result                                |    |     |
   Experimental-    298  7.7     Unsigned32 | M  |  V  |
      Result-Code                           |    |     |
   Failed-AVP       279  7.5     Grouped    | M  |  V  |
   Firmware-        267  5.3.4   Unsigned32 |    | V,M |
     Revision                               |    |     |
   Host-IP-Address  257  5.3.5   Address    | M  |  V  |
   Inband-Security                          | M  |  V  |
      -Id           299  6.10    Unsigned32 |    |     |
   Multi-Round-     272  8.19    Unsigned32 | M  |  V  |
     Time-Out                               |    |     |
   Origin-Host      264  6.3     DiamIdent  | M  |  V  |
   Origin-Realm     296  6.4     DiamIdent  | M  |  V  |
   Origin-State-Id  278  8.16    Unsigned32 | M  |  V  |
   Product-Name     269  5.3.7   UTF8String |    | V,M |
   Proxy-Host       280  6.7.3   DiamIdent  | M  |  V  |
   Proxy-Info       284  6.7.2   Grouped    | M  |  V  |
   Proxy-State       33  6.7.4   OctetString| M  |  V  |
   Redirect-Host    292  6.12    DiamURI    | M  |  V  |
   Redirect-Host-   261  6.13    Enumerated | M  |  V  |
      Usage                                 |    |     |
   Redirect-Max-    262  6.14    Unsigned32 | M  |  V  |
      Cache-Time                            |    |     |
   Result-Code      268  7.1     Unsigned32 | M  |  V  |
   Route-Record     282  6.7.1   DiamIdent  | M  |  V  |
   Session-Id       263  8.8     UTF8String | M  |  V  |
   Session-Timeout   27  8.13    Unsigned32 | M  |  V  |
   Session-Binding  270  8.17    Unsigned32 | M  |  V  |
   Session-Server-  271  8.18    Enumerated | M  |  V  |
     Failover                               |    |     |
   Supported-       265  5.3.6   Unsigned32 | M  |  V  |
     Vendor-Id                              |    |     |
   Termination-     295  8.15    Enumerated | M  |  V  |
      Cause                                 |    |     |
   User-Name          1  8.14    UTF8String | M  |  V  |
   Vendor-Id        266  5.3.3   Unsigned32 | M  |  V  |
   Vendor-Specific- 260  6.11    Grouped    | M  |  V  |
      Application-Id                        |    |     |
   -----------------------------------------|----+-----|

  ======================================================
  # Below are the important Parameter which are decoded and kept
  ======================================================
	-----------------------------------------------------
   Destination-Host 293  6.5     DiamIdent  | M  |  V  |
   Destination-     283  6.6     DiamIdent  | M  |  V  |
     Realm                                  |    |     |
   Disconnect-Cause 273  5.4.3   Enumerated | M  |  V  |
   Origin-Host      264  6.3     DiamIdent  | M  |  V  |
   Origin-Realm     296  6.4     DiamIdent  | M  |  V  |
   Origin-State-Id  278  8.16    Unsigned32 | M  |  V  |
   Result-Code      268  7.1     Unsigned32 | M  |  V  |
   Route-Record     282  6.7.1   DiamIdent  | M  |  V  |
   Session-Id       263  8.8     UTF8String | M  |  V  |
   Session-Timeout   27  8.13    Unsigned32 | M  |  V  |
   Supported-       265  5.3.6   Unsigned32 | M  |  V  |
     Vendor-Id                              |    |     |
   Termination-     295  8.15    Enumerated | M  |  V  |
      Cause                                 |    |     |
   User-Name          1  8.14    UTF8String | M  |  V  |
   Vendor-Id        266  5.3.3   Unsigned32 | M  |  V  |
   Vendor-Specific- 260  6.11    Grouped    | M  |  V  |
      Application-Id                        |    |     |

		
		OctetString lOctetString;
      
		TRY_GETAVP_OCTET_STRING(lOctetString , msg.originationHost  , msg.rawbyteArray , 264);
		TRY_GETAVP_OCTET_STRING(lOctetString , msg.originationRealm , msg.rawbyteArray , 296);
		TRY_GETAVP_OCTET_STRING(lOctetString , msg.destinationHost  , msg.rawbyteArray , 293);
		TRY_GETAVP_OCTET_STRING(lOctetString , msg.destinationRealm , msg.rawbyteArray , 283);
		TRY_GETAVP_OCTET_STRING(lOctetString , msg.sessionId        , msg.rawbyteArray , 263);
		TRY_GETAVP_OCTET_STRING(lOctetString , msg.userName         , msg.rawbyteArray , 1);

		Unsigned32 lUnsigned32;

		TRY_GETAVP_UINTEGER32(lUnsigned32 , msg.originStateId , msg.rawbyteArray , 278);
		TRY_GETAVP_UINTEGER32(lUnsigned32 , msg.vendorId      , msg.rawbyteArray , 266);
     
#endif 
 /*	
		std::string            destinationHost;
		std::string            destinationRealm;
		std::string            originationRealm;
		std::string            sessionId;

		ACE_UINT32             originStateId;
		ACE_UINT32             disConnectCause;
		ACE_UINT32             errorCode;
		ACE_UINT32             vendorId;
		ACE_UINT32             resultCode;
		ACE_UINT32             sessionTimeOut;

 */
 return;
}

GxParser  DiaHandleMsg :: m_gx_parser;
RoParser  DiaHandleMsg :: m_ro_parser;
S6Parser  DiaHandleMsg :: m_s6_parser;
RxParser  DiaHandleMsg :: m_rx_parser;
SyParser  DiaHandleMsg :: m_sy_parser;
SlhParser DiaHandleMsg :: m_slh_parser;
SdParser  DiaHandleMsg :: m_sd_parser;
ShParser  DiaHandleMsg :: m_sh_parser;
CxParser  DiaHandleMsg :: m_cx_parser;
