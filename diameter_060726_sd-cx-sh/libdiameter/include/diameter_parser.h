// @(#) $Id: diameter_parser.h,v 1.1.4.1.2.1.2.10 2024/05/15 13:11:22 mram Exp $
//---------------------------------------------------------------
// NAME : diameter_parser.h
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
#ifndef __DIAMETER_PARSER_H__
#define __DIAMETER_PARSER_H__


#include "aaa_parser_defs.h"
//#include "DiameterBasicDecEnc.h"
#include "base/include/DiameterBase.h"
#include "DiameterPeg.h"
#include <sys/syscall.h>
#include "gx/include/CCRequest.h"

using namespace BASE;
/*!
 *==================================================
 * Macros and Preprocessor Definitions
 *==================================================
 */

/*!
 * Open diameter version declaration
 */
#define DIAMETER_VERSION_MAJOR  0x05
#define DIAMETER_VERSION_MINOR  0x04
#define DIAMETER_VERSION_MICRO  0x06

/*!
 * Diameter default definitions
 */
#define DIAMETER_NO_VENDOR_ID              0x00
#define DIAMETER_BASE_APPLICATION_ID       0x00

/*!
 * Diameter flag definitions
 */
#define DIAMETER_PROTOCOL_VERSION          0x1
#define DIAMETER_FLAG_SET                  0x1
#define DIAMETER_FLAG_CLR                  0x0

#define TRY_DECODE(obj)\
   msg.rawbyteArray.offset = 0;\
   try\
   {\
      obj->Decode( &msg.rawbyteArray);\
   }\
   catch  (TssDiameterMsgException &st )\
   {\
		AAA_LOG((LM_INFO, "%T |PEER_FSM| HH:%d EE:%d CC:%d R:%d err:%s Decode Failed\n",\
					msg.hdr.mHopByHopId, msg.hdr.mEndToEndId,\
					msg.hdr.mCmdCode, msg.hdr.mCmdFlg.rBit,\
					st.getErrMessage()));\
		throw DiameterBaseException(DiameterBaseException::INVALID_ID_TYPE, "Decode Error");\
		return;\
	}

#define TRY_OCTET_STRING(var,obj,fun)\
   try\
   {\
      var.assign(obj->fun()->getValue()? (char*)obj->fun()->getValue():"" , obj->fun()->getLength() ? obj->fun()->getLength(): 0);\
   }\
   catch  (TssDiameterMsgException &st )\
   {\
      var = "";\
   }\
	catch (...)\
	{\
      var = "";\
	}\



#define TRY_INTEGER32(var,obj,fun)\
   try\
   {\
      var = obj->fun()->getValue();\
   }\
   catch  (TssDiameterMsgException &st )\
   {\
      var = 0;\
   }

//  Below are the Get AVP 

#define TRY_GETAVP_OCTET_STRING(obj , value , lArray ,code)\
   try\
   {\
      obj = GetAVP<OctetString>(&lArray, code);\
      value.assign(obj.getValue()? (char*)obj.getValue():"" , obj.getLength() ? obj.getLength(): 0);\
   }\
   catch  (TssDiameterMsgException &st )\
   {\
      value = "";\
   }\
	catch (...)\
	{\
      value = "";\
	}\

#define TRY_GETAVP_UINTEGER32(obj, value , lArray ,code)\
   try\
   {\
		obj = GetAVP<Unsigned32>(&lArray, code);\
      value = obj.getValue();\
   }\
   catch  (TssDiameterMsgException &st )\
   {\
      value = 0;\
   }


#define TRY_UNSIGNED32_LST(var,obj,fun)\
   try\
   {\
      list<Unsigned32*>::iterator x = obj->fun()->begin();\
      for (; x != obj->fun()->end(); x++)\
      {\
         var.push_back((*x)->getValue());\
      }\
   }\
   catch  (TssDiameterMsgException &st )\
   {\
   }





#define TRY_INTEGER32_LST(var,obj,fun)\
   try\
   {\
      list<Integer32*>::iterator x = obj->fun()->begin();\
      for (; x != obj->fun()->end(); x++)\
      {\
         var.push_back((*x)->getValue());\
      }\
   }\
   catch  (TssDiameterMsgException &st )\
   {\
   }



#define TRY_HOST_IP_ADDRESS_LST(var,obj,fun)\
   try\
   {\
      list<Address*>::iterator x = obj->fun()->begin();\
      for (; x != obj->fun()->end(); x++)\
      {\
         diameter_address_t *newAddr = new diameter_address_t;\
         (*newAddr).type = AAA_ADDRESS_IP;\
         (*newAddr).value.assign((*x)->getValue() ? (char*)(*x)->getValue():"" , (*x)->getLength() ? (*x)->getLength(): 0);\
         var.push_back(newAddr);\
      }\
   }\
   catch  (TssDiameterMsgException &st )\
   {\
   }

#define TRY_VENDOR_SPECIFIC_APPID_LST(var,obj,fun)\
	try{\
		list<VendorSpecificApplicationId*>::iterator x = obj->fun()->begin();\
		for (; x != obj->fun()->end(); x++)\
		{\
			DiameterDataVendorSpecificApplicationId vsid = { 0, 0, 0 };\
			try\
			{\
				vsid.vendorId  = (*x)->getVendorId()->getValue();\
			}\
			catch  (TssDiameterMsgException &st )\
			{\
			}\
			try\
			{\
				vsid.authAppId = (*x)->getAuthApplicationId()->getValue();\
			}\
			catch  (TssDiameterMsgException &st )\
			{\
			}\
			try\
			{\
				vsid.acctAppId = (*x)->getAcctApplicationId()->getValue();\
			}\
			catch  (TssDiameterMsgException &st )\
			{\
			}\
			if ((vsid.acctAppId != 0) || (vsid.authAppId != 0)) {\
				var.push_back(vsid);\
			}\
		}\
	}\
	catch(TssDiameterMsgException &e)\
	{\
	}

/*!
 *==================================================
 * The following definitions are for diameter specific
 * parsing support. Some basic data types have been
 * derived from the generic aaa_parser_api
 *==================================================
 */

/*!
 * DiameterApplicationId identifies a particular client session to the API.
 * The application id is passed to AAAStartSession(), and is attached to
 * incoming messages, to indicate with which client session the message
 * is associated.
 */
typedef ACE_UINT32     DiameterApplicationId;

/*!
 * The result codes are values returned from remote servers as part
 * of messages. They correspond directly to the result codes in the
 * Diameter specification [1]:
 */
typedef ACE_UINT32     DiameterResultCode;

/*!
 *==================================================
 * Pre-defined enumration
 *==================================================
 */

/*!
 * The AVP flags defines the flags set in the AVP header.
 * They correspond directly to the avp flags defined in the
 * Diameter specification [1]:
 */
typedef enum 
{
    DIAMETER_AVP_FLAG_NONE                 =   0x0,
    DIAMETER_AVP_FLAG_MANDATORY            =   DIAMETER_FLAG_SET,
    DIAMETER_AVP_FLAG_RESERVED             =   0x2,
    DIAMETER_AVP_FLAG_VENDOR_SPECIFIC      =   0x4,
    DIAMETER_AVP_FLAG_END_TO_END_ENCRYPT   =   0x10,
    DIAMETER_AVP_FLAG_UNKNOWN              =   0x10000,
    DIAMETER_AVP_FLAG_ENCRYPT              =   0x40000,
} DiameterAvpFlagEnum;

/*!
 * values possible for transport field of diameter_uri_t
 */
enum transport
{
    DIAMETER_TRANSPORT_PROTO_TCP           = 0,
    DIAMETER_TRANSPORT_PROTO_SCTP		   = 1,
    DIAMETER_TRANSPORT_PROTO_UDP           = -1,
} ;

/*!
 * values possible for protocol field of diameter_uri_t
 */
enum protocol{
    DIAMETER_PROTO_DIAMETER = 0,
    DIAMETER_PROTO_RADIUS   = 1,
    DIAMETER_PROTO_TACACSPLUS = -1,
} ;

/*!
 * values possible for scheme field of diameter_uri_t
 */
enum scheme{
    DIAMETER_SCHEME_AAA = 0,
    DIAMETER_SCHEME_AAAS
};

/*!
 * Parser options
 */
enum DiameterParseOption 
{
    DIAMETER_PARSE_LOOSE     = 0,
    DIAMETER_PARSE_STRICT    = 1,
};

/*!
 * Parser error enumration.
 */
enum DiameterParserError 
{
    DIAMETER_DICTIONARY_ERROR,
    DIAMETER_HEADER_ERROR,
    DIAMETER_PAYLOAD_ERROR
};

/*!
 *==================================================
 * The following definitions are for diameter specific
 * data type definitions for storing parsed data.
 *==================================================
 */

/*!
 * Data type definitions for AAA Parser
 */
typedef ACE_INT32                  diameter_integer32_t;

typedef ACE_UINT64                 diameter_integer64_t;

typedef ACE_UINT32                 diameter_unsigned32_t;

typedef ACE_UINT64                 diameter_unsigned64_t;

typedef diameter_unsigned32_t      diameter_enumerated_t;

typedef diameter_unsigned32_t      diameter_time_t;

typedef std::string                diameter_octetstring_t;

typedef diameter_octetstring_t     diameter_utf8string_t;

typedef diameter_utf8string_t      diameter_identity_t;

typedef class AAAAvpContainerList  diameter_grouped_t;

typedef diameter_unsigned32_t      diameter_time_t;  // Number of sec relative to 01/01/1900

/*!
 * values possible for transport field of diameter_diamident_t
 *
 * avp_t is a special type used only in this library
 * for constructing a raw AVP.  When using this type, specify
 * "AVP" as the avp_container type.
 * The string contains the entire AVP including AVP header.
 */
typedef diameter_octetstring_t     diameter_avp_t;

typedef struct {
    public:
        std::string    fqdn;
        ACE_UINT16     port;
        AAAInt8        transport:3;
        AAAInt8        protocol:3;
        AAAInt8        scheme:2;
} diameter_uri_t;

typedef struct
{
    public:
        ACE_UINT16               type;
        diameter_octetstring_t   value;
} diameter_address_t;

/*!
 *======================================================
 * The following are definitions for IP filter rule AVP
 *======================================================
 */
enum {
    DIAMETER_IPFILTER_RULE_SRCDST_EXACT,
    DIAMETER_IPFILTER_RULE_SRCDST_MASK,
    DIAMETER_IPFILTER_RULE_SRCDST_KEYWORD_ANY,
    DIAMETER_IPFILTER_RULE_SRCDST_KEYWORD_ASSIGNED
};

class DiameterIPFilterRuleSrcDst
{
    public:
        DiameterIPFilterRuleSrcDst(AAAUInt8 repr=DIAMETER_IPFILTER_RULE_SRCDST_EXACT,
                                   diameter_utf8string_t ipno=std::string(),
                                   AAAUInt8 bits=0,
                                   bool mod=true) :
            modifier(mod),
            representation(repr),
            ipno(ipno),
            bits(bits) {
        }

    public:
        bool         modifier;        /*! Modifier '!' maps to false */
        AAAUInt8     representation;  /*! One of the following:
                                          DIAMETER_IPFILTER_RULE_SRCDST_EXACT,
                                          DIAMETER_IPFILTER_RULE_SRCDST_MASK,
                                          DIAMETER_IPFILTER_RULE_SRCDST_KEYWORD_ANY,
                                          DIAMETER_IPFILTER_RULE_SRCDST_KEYWORD_ASSGINED.

                                          When representation is
                                          DIAMETER_IPFILTER_RULE_SRCDST_EXACT, only ipno is
                                          used.  When representation is
                                          DIAMETER_IPFILTER_RULE_SRCDST_MASK, ipno and bits
                                          are used.  For other represntations, both ipno and
                                          bits are not used.
                                        */

        diameter_utf8string_t  ipno;
        AAAUInt8               bits;
        std::list<AAAUInt16Range> portRangeList;   /*! list of port ranges. */
};

enum {
    DIAMETER_IPFILTER_RULE_IP_OPTION_SSRR    =   1,
    DIAMETER_IPFILTER_RULE_IP_OPTION_LSRR,
    DIAMETER_IPFILTER_RULE_IP_OPTION_RR,
    DIAMETER_IPFILTER_RULE_IP_OPTION_TS
};

enum {
    DIAMETER_IPFILTER_RULE_TCP_OPTION_MSS    =   1,
    DIAMETER_IPFILTER_RULE_TCP_OPTION_WINDOW,
    DIAMETER_IPFILTER_RULE_TCP_OPTION_SACK,
    DIAMETER_IPFILTER_RULE_TCP_OPTION_TS,
    DIAMETER_IPFILTER_RULE_TCP_OPTION_CC
};

enum {
    DIAMETER_IPFILTER_RULE_TCP_FLAG_FIN=1,
    DIAMETER_IPFILTER_RULE_TCP_FLAG_SYN,
    DIAMETER_IPFILTER_RULE_TCP_FLAG_RST,
    DIAMETER_IPFILTER_RULE_TCP_FLAG_PSH,
    DIAMETER_IPFILTER_RULE_TCP_FLAG_ACK,
    DIAMETER_IPFILTER_RULE_TCP_FLAG_URG
};

/*! IPFilterRule type. */
class diameter_ipfilter_rule_t {
    public:
        diameter_ipfilter_rule_t() :
            frag(false),
            established(false),
            setup(false) {
        }

        AAAUInt8   action; /*! DIAMETER_IPFILTER_RULEACTION_PERMIT or
                             *  DIAMETER_IPFILTER_RULEACTION_DENY
                             */
        AAAUInt8   dir;    /*!
                             *  DIAMETER_IPFILTER_RULEDIRECTION_IN or
                             *  DIAMETER_IPFILTER_RULEDIRECTION_OUT
                             */
        AAAUInt8   proto;  /*!
                             *  The value 0 means wildcard number that matches
                             *  any protocol
                             */

        DiameterIPFilterRuleSrcDst src;
        DiameterIPFilterRuleSrcDst dst;

        /// Option rules.
        bool frag;          /*! indicates fragmented packets except for the first
                             *  fragment
                             */
        std::list<int> ipOptionList;  /*! IP Option list.  An entry with a
                                       *  negative value means that the option
                                       *  corresponding to its positive value
                                       *  is negated.
                                       */
        std::list<int> tcpOptionList; /*! TCP Option list. An entry with a
                                       * negative value means that the option
                                       * corresponding to its positive value
                                       * is negated.
                                       */
        bool           established;   /*! TCP packets only.  Match packets that have the
                                       * RST or ACK bits set.
                                       */
        bool           setup;         /*! TCP packets only.  Match packets that have the SYN
                                       * bit set but no ACK bit 
                                       */
        std::list<int> tcpFlagList;   /*! TCP Flag list. An entry with a
                                       *  negative value means that the flag
                                       *  corresponding to its positive value
                                       *  is negated.
                                       */
        std::list<AAAUInt8Range> icmpTypeRangeList; /*! ICMP Type Range list */
} ;

enum {
    DIAMETER_IPFILTER_RULE_ACTION_PERMIT,
    DIAMETER_IPFILTER_RULE_ACTION_DENY
};

enum {
    DIAMETER_IPFILTER_RULE_DIRECTION_IN,
    DIAMETER_IPFILTER_RULE_DIRECTION_OUT
};

enum SendMsgErrCode{
   DCCA_SUCCESS = 0,
   ERR_EXCEPTION,
   APPLICATION_ID_UNSUPPORTED,
   CC_REQUEST_TYPE_UNSUPPORTED,
   PEER_EMPTY,
   PEER_LOOKUP_FAILED,
   PEER_UNAVAILABLE,
   SESSION_DB_LOOKUP_FAILED,
   SESSION_CREATION_FAILED,
   MESSAGE_ENCODE_FAILED,
   DCCA_INVALID_CMD_CODE,
   DCCA_INVALID_REQ_TYPE,
   ROUTE_LOOKUP_FAILED
};


/*!
 *==================================================
 * The following are definitions for diameter
 * specific error codes including failed-avp
 * determination
 *==================================================
 */

/*! \brief DiameterErrorCode Diameter Specific Error Code
 *
 * parser functions throw this class instance when an error occurs.
 */
class AAA_PARSER_EXPORT_ONLY DiameterErrorCode :
   public AAAErrorCode
{
   public:
      /*!
       * constructor
       */
      DiameterErrorCode(void) {
      };

      /*!
       * Access function to retrieve all private data 
       *
       * \param type Error type
       * \param code Result or Bug code
       * \param avp AVP that had the error
       */
      void get(AAA_PARSE_ERROR_TYPE &type,
               int &code,
               std::string &avp) {
          AAAErrorCode::get(type, code);
          avp = this->avp;
      }

      /*!
       * Access function to set all private data 
       *
       * \param type Error type to set
       * \param code Result or Bug code to set
       * \param data Data dictionary entry
       */

//      void set(AAA_PARSE_ERROR_TYPE type,
//               int code,
//               AAADictionaryEntry* data);

      /*!
       * Access function to retrieve some private data.
       * Overlaod AAAErrorCode::get(..) to fix function
       * hiding.
       *
       * \param type Error type
       * \param code Result or Bug code
       */
      void get(AAA_PARSE_ERROR_TYPE &t, int &c) {
          AAAErrorCode::get(t, c);
      }

      /*!
       * Access function to set some private data 
       * Overlaod AAAErrorCode::set(..) to fix function
       * hiding.
       *
       * \param type Error type to set
       * \param code Result or Bug code to set
       */
      void set(AAA_PARSE_ERROR_TYPE t, int c) {
          AAAErrorCode::set(t, c);
      }

      /*!
       * !!! Backward compatibility only !!!
       *
       * \param type Error type
       * \param code Result or Bug code
       * \param avp AVP that had the error
       */
      void get(int &type,
               int &code,
               std::string &avp) {
          get((AAA_PARSE_ERROR_TYPE&)type, code, avp);
      }

      /*!
       * !!! Backward compatibility only !!!
       *
       * \param type Error type
       * \param code Result or Bug code
       */
      void get(int &t, int &c) {
          get((AAA_PARSE_ERROR_TYPE&)t, c);
      }

   private:
      std::string avp;   /**< errornous AVP */
};

/*!
 *==================================================
 * This section defines the diameter message structure
 *
 * A diameter message is represented by a DiameterMessage
 * object. This inherits from AAAAvpContainerList which
 * contains one or more AVPs composing the messages
 *
 *==================================================
 */

/*!
 * Header bit field definition
 */
#define DIAMETER_HEADER_SIZE 20

#if 0

#endif
/*! \brief Message Diameter Message
 *
 * A class used for carrying AAAAvpContainerList and DiameterMsgHeader 
 * class instances between applications and the API.
 */
class DiameterMsg
{
    public:
        DiameterMsgHeader      hdr;                  /**< Message header */
		  byteArray              rawbyteArray;    

        DiameterErrorCode      status;               /**< Error status */

        time_t                 secondsTillExpire;    /**< Expiration time of message */
        time_t                 startTime;            /**< Time of transmission */

		  std::shared_ptr<DiameterBase>  baseClass;   
		  bool 						  internalRspFlag;

		  std::string            originationHost;
		  std::string            destinationHost;
		  std::string            destinationRealm;
		  std::string            originationRealm;
		  std::string            sessionId;
		  std::string            userName;

		  ACE_UINT32             originStateId;
		  ACE_UINT32             disConnectCause;
		  ACE_UINT32             errorCode;
		  ACE_UINT32             vendorId;
		  ACE_UINT32             resultCode;
		  ACE_UINT32             sessionTimeOut;

		  ACE_UINT32             localhh;

#if 0
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
#endif
		DiameterMsg()
		{
			//cout<<"%T |BASE| TBR BASE DIAMETERMSG CONSTRUCTOR\n";	
		}

	   DiameterMsg ( const DiameterMsg &rMsg)
		{
			//cout<<"%T |BASE| TBR BASE DIAMETERMSG CONSTRUCTOR\n";	
			hdr = rMsg.hdr;
			//rawbyteArray = rMsg.rawbyteArray;
			status = rMsg.status;
			secondsTillExpire = rMsg.secondsTillExpire;
			startTime = rMsg.startTime;
			baseClass = rMsg.baseClass;
			internalRspFlag = rMsg.internalRspFlag;
			originationHost = rMsg.originationHost;
			destinationHost = rMsg.destinationHost;
			destinationRealm = rMsg.destinationRealm;
			originationRealm = rMsg.originationRealm;
			sessionId = rMsg.sessionId;
			userName = rMsg.userName;
			originStateId = rMsg.originStateId;
			disConnectCause = rMsg.disConnectCause;
			errorCode = rMsg.errorCode;
			vendorId = rMsg.vendorId;
			resultCode = rMsg.resultCode;
			sessionTimeOut = rMsg.sessionTimeOut;
			localhh =  rMsg.localhh;
		}

		~DiameterMsg()
		{
			//cout<<"%T |BASE| TBR BASE DIAMETERMSG DISTRUCTOR\n";	
		}
};

/*!
 *==================================================
 * This section defines the diameter specific parsing
 * functions and objects
 *==================================================
 */

/*!
 * Diameter AVP value parser
 */
#if 0
typedef AAAParser<AAAMessageBlock*, 
		  AAAAvpContainerEntry*,
		  std::vector<AAAUInt8>,
		  AAADictionaryEntry*> DiameterAvpValueParser;

/*! Parsing starts from the current read pointer of the raw data,
 *  i.e., AAAMessageBlock.  When parsing is successful, the read
 *  pointer will proceed to one octet after the last octet of the
 *  AVP value.  When parsing fails, an error status is thrown.  A
 *  non-null dictionary data must be specified.
 */
template<> void AAA_PARSER_EXPORT_ONLY DiameterAvpValueParser::parseRawToApp();

/*! Parsing starts from the current write pointer of the raw data,
 *  i.e., AAAMessageBlock.  When parsing is successful, the write
 *  pointer will proceed to one octet after the last octet of the
 *  AVP value.  When parsing fails, an error status is thrown.  A
 *  non-null dictionary data must be specified.
 */
template<> void AAA_PARSER_EXPORT_ONLY DiameterAvpValueParser::parseAppToRaw();

#endif 
/*!
 * Diameter header parser definition
 */


/*
	class DiameterAvpRawData
	{
	public:
	AAAMessageBlock        *msgblock;
	byteArray              rawmsg;
//  DiameterAvpHeaderList  *ahl;
};
*/

//typedef AAAParser< DiameterAvpRawData*, DiameterAvpHeader* > DiameterAvpHeaderParser;



//typedef AAAParser < AAAMessageBlock*, DiameterMsgHeader* , byteArray*> DiameterMsgHeaderParser;

/*! Parsing starts from the head of the raw data, i.e.,
 *  AAAMessageBlock.  When parsing is successful, the read pointer
 *  will proceed to one octet after the last octet of the header,
 *  i.e., the first octet of the payload.  When parsing fails, an *
 *  error status is thrown.  When the DiameterParseOption is set to
 *  DIAMETER_PARSE_LOOSE, command flag validity check will be skipped.  When
 *  DiameterParseOption is set to DIAMETER_PARSE_STRICT, an AAADictionaryHandle will be
 *  set inside the DiameterMsgHeader so that the command
 *  dictionary can be passed to the payload parser. */
//template<> void AAA_PARSER_EXPORT_ONLY DiameterMsgHeaderParser::parseRawToApp();

/*! Parsing starts from the head of the raw data, i.e.,
 *  AAAMessageBlock.  When parsing is successful, the write pointer
 *  will proceed to one octet after the last octet of the header,
 *  i.e., the first octet of the payload.  When parsing fails, an
 *  error status is thrown.  When the DiameterParseOption is set to
 *  DIAMETER_PARSE_LOOSE, command flag validity check will be skipped.  When
 *  DiameterParseOption is set to DIAMETER_PARSE_STRICT, an AAADictionaryHandle will be
 *  set inside the DiameterMsgHeader so that the command dictionary
 *  can be passed to the payload parser.
 */

//template<> void AAA_PARSER_EXPORT_ONLY DiameterMsgHeaderParser::parseAppToRaw();



#if 0

/*!
 * Payload parser definition
 */
typedef AAAParser<AAAMessageBlock* , AAAAvpContainerList*, AAADictionaryHandle*> DiameterMsgPayloadParser;

/*! Parsing starts from the current read pointer of the raw data,
 *  i.e., AAAMessageBlock.  When parsing is successful, the read
 *  pointer will proceed to one octet after the last octet of the
 *  payload.  When parsing fails, an error status is thrown.  When a
 *  non-null dictionary data is set (the dictionary handle can be
 *  obtained from the header instance as a result of successful header
 *  paring), validity check on command semantics (e.g.,
 *  fixed/required/optional AVP check, check for the minumum/maximum
 *  number of elements in each AVP) is performed (strict parsing).
 *  When a null dictionary data is set, validity check on command
 *  semantics are not performed (loose parsing). 
 */
template<> void AAA_PARSER_EXPORT_ONLY DiameterMsgPayloadParser::parseRawToApp();// throw(DiameterErrorCode);

/*! Parsing starts from the current write pointer of the raw data,
 *  i.e., AAAMessageBlock.  When parsing is successful, the write
 *  pointer will proceed to one octet after the last octet of the
 *  payload.  When parsing fails, an error status is thrown.  When a
 *  non-null dictionary data is set (the dictionary handle can be
 *  obtained from the header instance as a result of successful header
 *  paring), validity check on command semantics (e.g.,
 *  fixed/required/optional AVP check, check for the minumum/maximum
 *  number of elements in each AVP) is performed (strict parsing).
 *  When a null dictionary data is set, validity check on command
 *  semantics are not performed (loose parsing).
 */
template<> void AAA_PARSER_EXPORT_ONLY DiameterMsgPayloadParser::parseAppToRaw();// throw(DiameterErrorCode);



/*! Functor type definition for AVP value parser creator.  The creator
 *  function takes null argument and returns a pointer to an AVP value
 *  parser.
 */
typedef boost::function0<DiameterAvpValueParser*> DiameterAvpValueParserFunctor;

/*!
 *==================================================
 * This section defines utility classes for easing
 * the use of the parser objects above
 *==================================================
 */
#endif 

/*! \brief Generic Result code AVP checker
 *
 * Assist in setting and getting any Result-Code
 * AVP's present in a message list
 */
class DiameterMsgResultCode
{
    public:
        typedef enum {
            RCODE_NOT_PRESENT,
            RCODE_INFORMATIONAL,
            RCODE_SUCCESS,
            RCODE_PROTOCOL_ERROR,
            RCODE_TRANSIENT_FAILURE,
            RCODE_PERMANENT_FAILURE
        } RCODE;

    public:
        DiameterMsgResultCode(DiameterMsg &msg) :
            message(msg) {
        }

/*        diameter_unsigned32_t ResultCode() 
		  {
//         DiameterUInt32AvpContainerWidget resultCode(message.acl);
//         diameter_unsigned32_t *rc = resultCode.GetAvp((char *)"Result-Code");
//         return (rc) ? *rc : 0;
        }*/
        void ResultCode(diameter_unsigned32_t c) 
		  {
//            DiameterUInt32AvpContainerWidget resultCode(message.acl);
//            resultCode.AddAvp((char *)"Result-Code") = c;
        }

        static RCODE InterpretedResultCode(diameter_unsigned32_t code) 
		  {
            for (int i=RCODE_INFORMATIONAL; i<=RCODE_PERMANENT_FAILURE;
                i++) 
				{
                code -= 1000;
                if ((code/1000) == 0) {
                    return RCODE(i);
                }
            }
            return (RCODE_PERMANENT_FAILURE);
        }

/*        RCODE InterpretedResultCode() 
		  {
            diameter_unsigned32_t code = ResultCode();
            return (code) ? InterpretedResultCode(code) :
                            RCODE_NOT_PRESENT;
        }*/

    private:
        DiameterMsg &message;
};

/*! \brief Generic message header printer
 *
 * This is a useful class for debuggging
 */
class DiameterMsgHeaderDump {
    public:
        static void Dump(DiameterMsg &msg) {

				 AAA_LOG((LM_INFO, "%T |TRANSPORT|  Message header dump Len:%d Flag %s %s %s %s AppId:%d CmdCode:%d HH:%d EE:%d \n",
							 msg.hdr.mMsgLen , msg.hdr.mCmdFlg.rBit?" REQ":"", msg.hdr.mCmdFlg.pBit?" PXY":"",
							 msg.hdr.mCmdFlg.eBit?" ERR":"", msg.hdr.mCmdFlg.tBit?" TRX":"",
							 msg.hdr.mApplId , msg.hdr.mCmdCode,
							 msg.hdr.mHopByHopId ,msg.hdr.mEndToEndId));
        }
};

/*! \brief Wrapper functions for message composition/decomposition
 *
 * Assist in composing and decomposing DiameterMsg
 */
class DiameterMsgWidget
{
    public:
        DiameterMsgWidget(int code,
                    int request = true,
                    int appId = DIAMETER_BASE_APPLICATION_ID) :
            message(std::unique_ptr<DiameterMsg>(new DiameterMsg)) 
			{
            ACE_OS::memset(&(message->hdr), 0, sizeof(message->hdr));
            message->hdr.mVersion = DIAMETER_PROTOCOL_VERSION;
            message->hdr.mMsgLen = 0;
            message->hdr.mCmdFlg.rBit = request ? DIAMETER_FLAG_SET : DIAMETER_FLAG_CLR;
            message->hdr.mCmdFlg.pBit = DIAMETER_FLAG_CLR;
            message->hdr.mCmdFlg.eBit = DIAMETER_FLAG_CLR;
            message->hdr.mCmdFlg.tBit = DIAMETER_FLAG_CLR;
            message->hdr.mCmdCode  = code;
            message->hdr.mApplId   = appId;
        }
        ~DiameterMsgWidget() 
		  {

        }
        std::unique_ptr<DiameterMsg> &operator()() {
            return message;
        }
        DiameterMsg &Release() {
            return *(message.release());
        }
        void Dump() 
		  {
            if (message.get()) {
                DiameterMsgHeaderDump::Dump(*message);
                return;
            }
            AAA_LOG((LM_INFO, "Msg widget is un-assigned\n"));
        }

    private:
        std::unique_ptr<DiameterMsg> message;
};
/*
inline std::string hex_to_string(int n)
{
	std::stringstream stream;
	stream << std::hex << n;
	std::string result( stream.str() );
	return result;
}
*/

inline std::string LOG_DIAMETER_AVPS(const DiameterMsg &msg)
{
	//std::string str = "::= <CC:"+to_string(msg.hdr.mCmdCode)+(msg.hdr.mCmdFlg.rBit?" REQ":"")+(msg.hdr.mCmdFlg.pBit?" PXY":"")+(msg.hdr.mCmdFlg.eBit?" ERR":"")+(msg.hdr.mCmdFlg.tBit?" TRX":"")+" HH:"+to_string(msg.hdr.mHopByHopId)+" EE:"+to_string(msg.hdr.mEndToEndId)+" APPID:"+to_string(msg.hdr.mApplId)+"> " + "<Session-Id:"+msg.sessionId+"> "+"{Origin-Host:"+msg.originationHost+"} {Origin-Realm:"+msg.originationRealm+"}";
	//return str;
	return (std::string("PID:")+to_string(syscall(SYS_gettid))+std::string("::= <CC:")+to_string(msg.hdr.mCmdCode)+ std::string(msg.hdr.mCmdFlg.rBit?" REQ":"")+ std::string(msg.hdr.mCmdFlg.pBit?" PXY":"")+ std::string(msg.hdr.mCmdFlg.eBit?" ERR":"")+ std::string(msg.hdr.mCmdFlg.tBit?" TRX":"")+ std::string(" HH:")+to_string(msg.hdr.mHopByHopId)+ std::string(" EE:")+to_string(msg.hdr.mEndToEndId)+ std::string(" APPID:")+to_string(msg.hdr.mApplId)+ std::string("> ") +  std::string("<SId:")+msg.sessionId+ std::string("> ")+ std::string("{OH:")+msg.originationHost+ std::string("} {OR:")+msg.originationRealm+ std::string("}"));

//	return (std::string("::= <CC:")+to_string(msg.hdr.mCmdCode)+ std::string(msg.hdr.mCmdFlg.rBit?" REQ":"")+ std::string(msg.hdr.mCmdFlg.pBit?" PXY":"")+ std::string(msg.hdr.mCmdFlg.eBit?" ERR":"")+ std::string(msg.hdr.mCmdFlg.tBit?" TRX":"")+ std::string(" HH:")+hex_to_string(msg.hdr.mHopByHopId)+ std::string(" EE:")+hex_to_string(msg.hdr.mEndToEndId)+ std::string(" APPID:")+to_string(msg.hdr.mApplId)+ std::string("> ") +  std::string("<SId:")+msg.sessionId+ std::string("> ")+ std::string("{OH:")+msg.originationHost+ std::string("} {OR:")+msg.originationRealm+ std::string("}"));


}


inline std::string LOG_DIAMETER_AVPS_L(const DiameterMsg &msg)
{
   //std::string str = "::= <CC:"+to_string(msg.hdr.mCmdCode)+(msg.hdr.mCmdFlg.rBit?" REQ":"")+(msg.hdr.mCmdFlg.pBit?" PXY":"")+(msg.hdr.mCmdFlg.eBit?" ERR":"")+(msg.hdr.mCmdFlg.tBit?" TRX":"")+" HH:"+to_string(msg.hdr.mHopByHopId)+" EE:"+to_string(msg.hdr.mEndToEndId)+" APPID:"+to_string(msg.hdr.mApplId)+"> " + "<Session-Id:"+msg.sessionId+"> "+"{Origin-Host:"+msg.originationHost+"} {Origin-Realm:"+msg.originationRealm+"}";
   //return str;
   return (std::string("PID:")+to_string(syscall(SYS_gettid))+std::string("::= <CC:")+to_string(msg.hdr.mCmdCode)+ std::string(msg.hdr.mCmdFlg.rBit?" REQ":"")+ std::string(msg.hdr.mCmdFlg.pBit?" PXY":"")+ std::string(msg.hdr.mCmdFlg.eBit?" ERR":"")+ std::string(msg.hdr.mCmdFlg.tBit?" TRX":"")+ std::string(" LHH:")+to_string(msg.hdr.mHopByHopId)+ std::string(" EE:")+to_string(msg.hdr.mEndToEndId)+ std::string(" APPID:")+to_string(msg.hdr.mApplId)+ std::string("> ") +  std::string("<SId:")+msg.sessionId+ std::string("> ")+ std::string("{OH:")+msg.originationHost+ std::string("} {OR:")+msg.originationRealm+ std::string("}"));
}


 
//#include "DiameterBasicTemplate.tcc"


#endif // __DIAMETER_PARSER_H__
