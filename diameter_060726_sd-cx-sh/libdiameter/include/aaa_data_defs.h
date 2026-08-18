// @(#) $Id: aaa_data_defs.h,v 1.1.4.1.2.2.2.21 2024/05/15 13:08:41 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_data_defs.h
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
#ifndef __AAA_DATA_DEFS_H__
#define __AAA_DATA_DEFS_H__

#ifdef WIN32
#include "StdAfx.h"
#endif
#include "diameter_parser.h"
#include "aaa_rbtree.h" 
#include "ace/Singleton.h"
#include <netdb.h>
#include "base/include/CapabilityExchangeRequest.h"
#include "base/include/CapabilityExchangeAnswer.h"
#include "base/include/DeviceWatchdogAnswer.h"
#include "base/include/DeviceWatchdogRequest.h"
#include "base/include/DisconnectPeerAnswer.h"
#include "base/include/DisconnectPeerRequest.h"
#include "aaa_structs.h"
#include "DiaHandleMsg.h"
#include <boost/tokenizer.hpp>

// Windows specific export declarations
#if defined (WIN32)
#if defined (DIAMETERBASEPROTOCOL_EXPORTS)
#define DIAMETERBASEPROTOCOL_EXPORT ACE_Proper_Export_Flag
#define DIAMETERBASEPROTOCOL_EXPORT_ONLY ACE_Proper_Export_Flag
#define DIAMETERBASEPROTOCOL_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#define DIAMETERBASEPROTOCOL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#else
#define DIAMETERBASEPROTOCOL_EXPORT ACE_Proper_Import_Flag
#define DIAMETERBASEPROTOCOL_EXPORT_ONLY
#define DIAMETERBASEPROTOCOL_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#define DIAMETERBASEPROTOCOL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif				// DIAMETERBASEPROTOCOL_EXPORTS
#else
#define DIAMETERBASEPROTOCOL_EXPORT
#define DIAMETERBASEPROTOCOL_EXPORT_ONLY
#define DIAMETERBASEPROTOCOL_SINGLETON_DECLARATION(T)
#define DIAMETERBASEPROTOCOL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif				// WIN32

// AVP names used internally
#define DIAMETER_AVPNAME_SESSIONID             "Session-Id"
#define DIAMETER_AVPNAME_RESULTCODE            "Result-Code"
#define DIAMETER_AVPNAME_ORIGINHOST            "Origin-Host"
#define DIAMETER_AVPNAME_ORIGINREALM           "Origin-Realm"
#define DIAMETER_AVPNAME_ORIGINSTATEID         "Origin-State-Id"
#define DIAMETER_AVPNAME_DESTHOST              "Destination-Host"
#define DIAMETER_AVPNAME_DESTREALM             "Destination-Realm"
#define DIAMETER_AVPNAME_AUTHSESSIONSTATE      "Auth-Session-State"
#define DIAMETER_AVPNAME_AUTHAPPID             "Auth-Application-Id"
#define DIAMETER_AVPNAME_ACCTAPPID             "Acct-Application-Id"
#define DIAMETER_AVPNAME_VENDORAPPID           "Vendor-Specific-Application-Id"
#define DIAMETER_AVPNAME_REAUTHREQTYPE         "Re-Auth-Request-Type"
#define DIAMETER_AVPNAME_TERMINATION           "Termination-Cause"
#define DIAMETER_AVPNAME_AUTHSESSIONSTATE      "Auth-Session-State"
#define DIAMETER_AVPNAME_ERRRORREPORTINGHOST   "Error-Reporting-Host"
#define DIAMETER_AVPNAME_AUTHLIFETIME          "Authorization-Lifetime"
#define DIAMETER_AVPNAME_AUTHGRACE             "Auth-Grace-Period"
#define DIAMETER_AVPNAME_SESSIONTIMEOUT        "Session-Timeout"
#define DIAMETER_AVPNAME_HOSTIP                "Host-IP-Address"
#define DIAMETER_AVPNAME_VENDORID              "Vendor-Id"
#define DIAMETER_AVPNAME_PRODUCTNAME           "Product-Name"
#define DIAMETER_AVPNAME_ROUTERECORD           "Route-Record"
#define DIAMETER_AVPNAME_REDIRECTHOST          "Redirect-Host"
#define DIAMETER_AVPNAME_REDIRECTHOSTUSAGE     "Redirect-Host-Usage"
#define DIAMETER_AVPNAME_USERNAME              "User-Name"
#define DIAMETER_AVPNAME_FIRMWAREREV           "Firmware-Revision"
#define DIAMETER_AVPNAME_INBANDSECID           "Inband-Security-Id"
#define DIAMETER_AVPNAME_SUPPORTEDVENDORID     "Supported-Vendor-Id"
#define DIAMETER_AVPNAME_ERRORMESSAGE          "Error-Message"
#define DIAMETER_AVPNAME_ERRORREPORTINGHOST    "Error-Reporting-Host"
#define DIAMETER_AVPNAME_DISCONNECT_CAUSE      "Disconnect-Cause"
#define DIAMETER_AVPNAME_ACCTREC_TYPE          "Accounting-Record-Type"
#define DIAMETER_AVPNAME_ACCTREC_NUM           "Accounting-Record-Number"
#define DIAMETER_AVPNAME_ACCTSUBSID            "Accounting-Sub-Session-Id"
#define DIAMETER_AVPNAME_ACCTREALTIME          "Accounting-Realtime-Required"
#define DIAMETER_AVPNAME_ACCTSID               "Acct-Session-Id"
#define DIAMETER_AVPNAME_ACCTMULTISID          "Acct-Multi-Session-Id"
#define DIAMETER_AVPNAME_ACCTINTERVAL          "Acct-Interim-Interval"
#define DIAMETER_AVPNAME_CLASS                 "Class"
#define DIAMETER_AVPNAME_PROXYINFO             "Proxy-Info"
#define DIAMETER_AVPNAME_PROXYHOST             "Proxy-Host"
#define DIAMETER_AVPNAME_PROXYSTATE            "Proxy-State"
#define DIAMETER_AVPNAME_WILDCARD              "AVP"

// Command Codes used internally
#define DIAMETER_MSGCODE_ABORTSESSION          274
#define DIAMETER_MSGCODE_SESSIONTERMINATION    275
#define DIAMETER_MSGCODE_CAPABILITIES_EXCHG    257
#define DIAMETER_MSGCODE_WATCHDOG              280
#define DIAMETER_MSGCODE_DISCONNECT_PEER       282
#define DIAMETER_MSGCODE_ACCOUNTING            271
#define DIAMETER_MSGCODE_REAUTH                258

// Application Identifiers
#define DIAMETER_RELAY_APPLICATION_ID          0xffffffff

// Session state values
#define DIAMETER_SESSION_STATE_MAINTAINED        0
#define DIAMETER_SESSION_NO_STATE_MAINTAINED     1

// Re-auth-type values
#define DIAMETER_SESSION_AUTHORIZE_ONLY          0
#define DIAMETER_SESSION_AUTHORIZE_AUTHENTICATE  1

typedef enum {
	AAA_CCR_MSG                  = 272, 
	AAA_ULR_MSG		             = 316,
	AAA_CLR_MSG      	         = 317,
	AAA_AIR_MSG  		         = 318,
	AAA_ISDR_MSG                 = 319,
	AAA_DSR_MSG     	         = 320,
	AAA_PUR_MSG                  = 321,
	AAA_RSR_MSG                  = 322,
	AAA_NOR_MSG                  = 323,
	AAA_ME_IDENTITY_CHK_MSG      = 324,
	AAA_AAR_MSG                  = 265,     // Rx interface
	AAA_RAR_MSG                  = 258,     // Base/Rx interface
	AAA_ASR_MSG                  = 274,     // Base/Rx interface
	AAA_STR_MSG                  = 275,     // Base/Sy/Rx interface
	AAA_RIR_MSG                  = 8388622, // Slh Interface
	AAA_SLR_MSG                  = 8388635, // Sy Interface
	AAA_SNR_MSG                  = 8388636, // Sy Interface
	AAA_TSR_MSG                  = 8388637, // Sd Interface (TDF-Session-Request/Answer)
     	AAA_SH_UDR_MSG               = 306,     // Sh Interface (User-Data-Request/Answer)
  	AAA_SH_PUR_MSG               = 307,     // Sh Interface (Profile-Update-Request/Answer)
 	AAA_SH_SNR_MSG               = 308,     // Sh Interface (Subscribe-Notifications-Request/Answer)
        AAA_SH_PNR_MSG               = 309,     // Sh Interface (Push-Notification-Request/Answer)
	  AAA_UAR_MSG                  = 300,     // Cx Interface (User-Authorization-Request/Answer)
	  AAA_SAR_MSG                  = 301,     // Cx Interface (Server-Assignment-Request/Answer)
	  AAA_LIR_MSG                  = 302,     // Cx Interface (Location-Info-Request/Answer)
	  AAA_MAR_MSG                  = 303,     // Cx Interface (Multimedia-Auth-Request/Answer)
	  AAA_RTR_MSG                  = 304,     // Cx Interface (Registration-Termination-Request/Answer)
	  AAA_PPR_MSG                  = 305      // Cx Interface (Push-Profile-Request/Answer)
	       
} AAA_CommandCode;

typedef enum {
   AAA_S6_APP_ID     = 16777251,
   AAA_Gx_APP_ID     = 16777238,
   AAA_Ro_APP_ID     = 4,
   AAA_Rx_APP_ID     = 16777236,
   AAA_Sy_APP_ID     = 16777302,
   AAA_S6a_APP_ID    = 16777251,
   AAA_Slh_APP_ID    = 16777291,
   AAA_Sd_APP_ID     = 16777303,
   AAA_Sh_APP_ID     = 16777217,
   AAA_Cx_APP_ID     = 16777216
} AAA_ApplicationId;


/// Accounting record types
typedef enum {
	DIAMETER_ACCT_RECTYPE_EVENT = 1,
	DIAMETER_ACCT_RECTYPE_START = 2,
	DIAMETER_ACCT_RECTYPE_INTERIM = 3,
	DIAMETER_ACCT_RECTYPE_STOP = 4
} DIAMETER_ACCT_RECTYPE;

/// Accouting realtime required values
typedef enum {
	DIAMETER_ACCT_REALTIME_DELIVER_AND_GRANT = 1,
	DIAMETER_ACCT_REALTIME_GRANT_AND_STORE = 2,
	DIAMETER_ACCT_REALTIME_GRANT_AND_LOSE = 3
} DIAMETER_ACCT_REALTIME;

/// General timer type's
typedef enum {
	DIAMETER_TIMER_TYPE_ASR = 1,
	DIAMETER_TIMER_TYPE_SESSION = 2,
	DIAMETER_TIMER_TYPE_AUTH = 3,
	DIAMETER_TIMER_TYPE_INTERVAL = 4
} DIAMETER_TIMER_TYPE;

// Misc definitions
#define AAA_AUTH_SESSION_GRACE_PERIOD             5
#define AAA_AUTH_SESSION_RECLAMATION_PERIOD       60

// Configuration Data Structures
typedef std::list < diameter_unsigned32_t > DiameterApplicationIdLst;

typedef struct 
{
	diameter_unsigned32_t vendorId;	// vendor application id 
	diameter_unsigned32_t authAppId;	// auth application id
	diameter_unsigned32_t acctAppId;	// acct application id
} DiameterDataVendorSpecificApplicationId;

typedef std::list < DiameterDataVendorSpecificApplicationId >
    DiameterVendorSpecificIdLst;

typedef struct 
{
	std::string 				 product;	// readable string product name
	diameter_unsigned32_t    version;	// current version
	diameter_unsigned32_t 	 backend_auth;	// nasd is false ; aaad is true
	diameter_unsigned32_t 	 vendor;	// local vendor id
	diameter_unsigned32_t 	 threadCount;	// number of threads to use 
	DiameterApplicationIdLst supportedVendorIdLst;	// supported vendor application id
	DiameterApplicationIdLst authAppIdLst;	// auth application id
	DiameterApplicationIdLst acctAppIdLst;	// acct application id
	DiameterVendorSpecificIdLst vendorSpecificId;	// vendor specific app id 
	diameter_unsigned32_t	 sync_session; //enable/disable syncing
	std::string 				 node_id;	// readable string Node ID
	std::string 				 sync_ip;	// readable string Sync Ip
	diameter_unsigned32_t    sync_port;	// Sync Port
	diameter_unsigned32_t    sync_task;	// Number of threads
	diameter_unsigned32_t    sync_obj;	// Number of redis Objects
	diameter_unsigned32_t    sync_hbh;	// enable/disable syncing
	diameter_unsigned32_t    drop_duplicate_ULR_on_flooding;	// enable/disable syncing
} DiameterDataGeneral;

struct sctprto
{
   sctp_rtoinfo         rto;
   sctprto()
   {
      memset(&rto, 0, sizeof(sctp_rtoinfo));
   }
};

typedef struct {
	std::string hostname;	// hostname of peer
	diameter_unsigned32_t port;	// port number
	diameter_unsigned32_t use_sctp;	// Use SCTP for this connection
	diameter_unsigned32_t use_stack_identity;	// Set orgination host and realm of that of stack
	diameter_unsigned32_t tls_enabled;	// TLS support
	diameter_unsigned32_t client;	// Client or Server
	std::string host_entry;	// host entry name of peer
	diameter_unsigned32_t host_port;	// host port number
	std::string realmname;
	sctprto msctprto;
} DiameterDataPeer;

typedef struct 
{
	//std::string 			 identity;	// local hostname
	//std::string 			 realm;	// local realm
	//diameter_unsigned32_t tcp_listen_port;	// TCP listening port
	//diameter_unsigned32_t sctp_listen_port;	// SCTP listening port
	diameter_unsigned32_t use_ipv6;	// TLS listening port
	diameter_unsigned32_t watchdog_timeout;	// Watchdog timeout
	diameter_unsigned32_t reconnect_interval;	// ReConnect interval
	diameter_unsigned32_t reconnect_max;	// ReConnect max
	diameter_unsigned32_t retx_interval;	// Req ReTx interval
	diameter_unsigned32_t retx_max_count;	// Req ReTx max count
	diameter_unsigned32_t rx_buffer_size;	// Receive Buffer Size
	diameter_unsigned32_t max_pending_backlog;//Maximum pending backlog allowed in job queue
	diameter_unsigned32_t listen_any_ip_addr;//listen on the specified port of any ip addr(1-enable)
	diameter_unsigned32_t hbh_timeout;       //expire time for hobbyhobId from redis
	diameter_unsigned32_t retx_interval_flag; //Re-transmission flag
	diameter_unsigned32_t retx_h2h_interval;  //HopbyHop id expire time from map for re transmission
	diameter_unsigned32_t ActiveDefPeerFlag;	
	diameter_unsigned32_t asyncMsg = 0;
	std::string           route_record_host_name;
	std::string           route_record_realm_name;
	diameter_unsigned32_t sctp_init_max_attempts;

	diameter_unsigned32_t use_sentinel;	
	//std::list < std::string > advertised_hostname;	// List of hostnames used by this node
	// addresses provided by this peer
} DiameterDataTransportMngt;

typedef struct {
	diameter_unsigned32_t stateful;	// stateful/stateless session flags
	diameter_unsigned32_t sessionTm;	// session timer
	diameter_unsigned32_t rxsessionTm;	// session timer
	diameter_unsigned32_t txTimeout;	// session timer
	diameter_unsigned32_t ulrSidRm;	// session timer
	diameter_unsigned32_t lifetimeTm;	// lifetime timer
	diameter_unsigned32_t graceTm;	// grace period timer
	diameter_unsigned32_t abortRetryTm;	// abort retry timer
} DiameterDataAuthSession;

typedef struct 
{
	diameter_unsigned32_t sessionTm;	// lifetime timer
	diameter_unsigned32_t rxsessionTm;	// lifetime timer
	diameter_unsigned32_t txTimeout;	// lifetime timer
	diameter_unsigned32_t ulrSidRm;	// lifetime timer
	diameter_unsigned32_t recIntervalTm;	// record interval
	diameter_unsigned32_t realtime;	// realtime required value
} DiameterDataAcctSession;

typedef struct 
{
	diameter_unsigned32_t maxSessions;	// maximum number of sessions allowed
	DiameterDataAuthSession authSessions;	// auth session config
	DiameterDataAcctSession acctSessions;	// acct session config
} DiameterDataSessionMngt;

typedef struct {
	diameter_integer32_t debug:1;	// debug flag
	diameter_integer32_t trace:1;	// trace flag
	diameter_integer32_t info:1;	// info flag
	diameter_integer32_t critical:1;	// info flag
	diameter_integer32_t emergency:1;	// info flag
	diameter_integer32_t alert:1;	// info flag
	diameter_integer32_t reserved:26;	// un-used
} DiameterDataLogFlags;

typedef struct 
{
	diameter_integer32_t console:1;	// enable|disable stdout target
	diameter_integer32_t syslog:1;	// enable|disable syslog target
	diameter_integer32_t reserved:30;	// un-used
} DiameterDataLogTragetFlags;

typedef struct {
	DiameterDataLogFlags flags;	// log flags
	DiameterDataLogTragetFlags targets;	// targets
	std::string logFile;
	std::string maxLogFileSize;
	std::string logFileSamplingInterval;
} DiameterDataLog;

typedef struct {
	diameter_integer32_t originStateId;	// runtime origin state
} DiameterRunTime;

typedef struct {
	std::string                productHome;
	std::time_t						startupTime;
} DiameterStartup;


typedef struct {
	diameter_unsigned32_t dynamically_load_peer_flag=0; 
	diameter_unsigned32_t max_dwr_count = 0; 
	diameter_unsigned32_t sendtopcrf  = 0;
	diameter_unsigned32_t ebit        = 0;
	diameter_unsigned32_t changelogs  = 0; 
	diameter_unsigned32_t reloadCount = 0;
	bool 		      drop_asr    = false;
	bool 		      ack_asr     = false;
} DiameterFlag;


typedef struct {
	std::string                						allowErrorCodeStr;
//	std::map<diameter_unsigned32_t, char>			errorCodeMap;
	std::map<string , char>								errorCodeMap;
	bool														mDecodedFlg = false;


	void DecodeErrorCodeList()
	{
		typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
		boost::char_separator<char> sep{","};
		tokenizer tok{allowErrorCodeStr, sep};
		for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
		{
			//diameter_unsigned32_t  lTemp = stoi(*it);
			//errorCodeMap.insert(make_pair(lTemp, ' '));
			string lTemp = string ((*it));
			errorCodeMap.insert(make_pair(lTemp , ' '));

		}
		mDecodedFlg = true;
	}

//	bool IsPresent( diameter_unsigned32_t resultCode)
	bool IsPresent( string resultCode)
	{
		if (!mDecodedFlg)
		{
			DecodeErrorCodeList();
		}
		auto it = errorCodeMap.find(resultCode);

		if (it != errorCodeMap.end())
		{
			return true;
		}
		return false;
	}

} DiameterAllowErrorCode;

/*
typedef struct {
   std::string                                  evrinfostr;
   std::map<string , int>                       evrMap;
   bool                                         mDecodedFlg = false;

	int mReloadCount = 0;

   void DecodeEvrList()
   {
		mReloadCount = DiameterFlag.reloadCount;
 
		boost::char_separator<char> sep("|");

		boost::tokenizer<boost::char_separator<char>> tokens(evrinfostr, sep);
		for (const auto& t : tokens) 
		{
			boost::char_separator<char> subsep(":");

			boost::tokenizer<boost::char_separator<char>> subtokens(t, subsep);
			boost::tokenizer<boost::char_separator<char>>::iterator it = subtokens.begin();

			string lTemp = string ((*it));
			int    lNum  = stoi(*(++it)); 
			evrMap.insert(make_pair(lTemp, lNum));
			AAA_LOG((LM_DEBUG, "%T |TBR-| Map KEY|VALUE:%s|%d\n",lTemp.c_str(),lNum));
		}
		mDecodedFlg = true;
	}
	
	int IsPresent( string &rApplId)
   {
      if (!mDecodedFlg || (mReloadCount != DiameterFlag reloadCount))
      {
         DecodeEvrList();
      }
      auto it = evrMap.find(rApplId);

      if (it != evrMap.end())
      {
         return it->second;
      }
      return 0;
   }

} DiameterEvrInfo;
*/

//typedef struct DiameterEvrInfo_S DiameterEvrInfo;

typedef struct 
{
	DiameterRunTime 				runtime;	// runtime configuration
	DiameterDataGeneral 			general;	// general configuration
	DiameterDataPeer           dataPeer;	// transport configuration
	DiameterDataTransportMngt  transport;	// transport configuration
	DiameterDataSessionMngt    session;	// session configuration
	DiameterDataLog 				log;	// logging configuration
	DiameterStartup				startup;
	DiameterAllowErrorCode	 	errCodeHdlr;
	DiameterFlag               dynloadpeer;
	//DiameterEvrInfo     evrinfo;
} DiameterDataRoot;

typedef struct {
	diameter_unsigned32_t reAuthType;	// re-authentication type
	diameter_unsigned32_t resultCode;	// result code
} DiameterReAuthValue;

typedef ACE_Singleton < DiameterDataRoot, ACE_Thread_Mutex > DiameterDataRoot_S;

#define DIAMETER_CFG_ROOT()            (DiameterDataRoot_S::instance())
#define DIAMETER_CFG_STARTUP()			(&(DiameterDataRoot_S::instance()->startup))
#define DIAMETER_CFG_RUNTIME()         (&(DiameterDataRoot_S::instance()->runtime))
#define DIAMETER_CFG_GENERAL()         (&(DiameterDataRoot_S::instance()->general))
#define DIAMETER_CFG_DATAPEER()        (&(DiameterDataRoot_S::instance()->dataPeer))
#define DIAMETER_CFG_TRANSPORT()       (&(DiameterDataRoot_S::instance()->transport))
#define DIAMETER_CFG_SESSION()         (&(DiameterDataRoot_S::instance()->session))
#define DIAMETER_CFG_AUTH_SESSION()    (&(DiameterDataRoot_S::instance()->session.authSessions))
#define DIAMETER_CFG_ACCT_SESSION()    (&(DiameterDataRoot_S::instance()->session.acctSessions))
#define DIAMETER_CFG_LOG()             (&(DiameterDataRoot_S::instance()->log))
#define DIAMETER_CFG_RESULT_CODE_CHECK() (&(DiameterDataRoot_S::instance()->errCodeHdlr))
#define DIAMETER_CFG_RELOAD()             (&(DiameterDataRoot_S::instance()->dynloadpeer))
//#define DIAMETER_CFG_EVR_INFO() (&(DiameterDataRoot_S::instance()->evrinfo))

typedef struct
{
   std::string                                  evrinfostr;
   std::map<string , int>                       evrMap;
   bool                                         mDecodedFlg = false;

   int mReloadCount = 0;

   void DecodeEvrList()
   {
      mReloadCount = DIAMETER_CFG_RELOAD()->reloadCount;

		evrMap.clear();

      boost::char_separator<char> sep("|");
      boost::tokenizer<boost::char_separator<char>> tokens(evrinfostr, sep);
      for (const auto& t : tokens)
      {
         boost::char_separator<char> subsep(":");

         boost::tokenizer<boost::char_separator<char>> subtokens(t, subsep);
         boost::tokenizer<boost::char_separator<char>>::iterator it = subtokens.begin();

         string lTemp = string ((*it));
         int    lNum  = stoi(*(++it));
         evrMap.insert(make_pair(lTemp, lNum));
         AAA_LOG((LM_DEBUG, "%T |TRANSPORT| Evr Application Map KEY|VALUE:%s|%d\n",lTemp.c_str(),lNum));
      }
      mDecodedFlg = true;
   }

   int IsPresent( string &rApplId)
   {
      if (!mDecodedFlg || (mReloadCount != DIAMETER_CFG_RELOAD()->reloadCount))
      {
         DecodeEvrList();
      }
      auto it = evrMap.find(rApplId);

      if (it != evrMap.end())
      {
         return it->second;
      }
      return 0;
   }

} DiameterEvrInfo;

typedef struct 
{
	DiameterEvrInfo evrinfo;
} DiameterDataRoot2;

typedef ACE_Singleton < DiameterDataRoot2, ACE_Thread_Mutex > DiameterDataRoot2_S;
#define DIAMETER_CFG_EVR_ROOT() ((DiameterDataRoot2_S::instance()))
#define DIAMETER_CFG_EVR_INFO() (&(DiameterDataRoot2_S::instance()->evrinfo))

class DiameterBaseException {
	public:
		typedef enum {
			ALLOC_FAILURE = 0,
			INVALID_ID_TYPE,
			MISSING_SESSION_ID,
			MISSING_ORIGIN_HOST,
			MISSING_ORIGIN_REALM,
			IO_FAILURE,
			UNEXPECTED_FIELD
		} ERROR_CODE;

	public:
		DiameterBaseException(int code, std::string & desc):m_Code(code),
		m_Description(desc) {
		}

		DiameterBaseException(int code, const char *desc):m_Code(code),
		m_Description(desc) {
		}

		int &Code() {
			return m_Code;
		}
		std::string & Description() {
			return m_Description;
		}

	private:
		int m_Code;
		std::string m_Description;
};

class DiameterMsgQuery {
	public:

		DiameterMsgQuery(DiameterMsg & msg): m_Msg(msg) {
		}

		bool IsRequest() 
		{
			return m_Msg.hdr.mCmdFlg.rBit;
		}

		bool IsAnswer() 
		{
			return !IsRequest();
		}

		bool IsCapabilities() 
		{
			return (m_Msg.hdr.mCmdCode == DIAMETER_MSGCODE_CAPABILITIES_EXCHG);
		}

		bool IsReAuth() 
		{
			return (m_Msg.hdr.mCmdCode == DIAMETER_MSGCODE_REAUTH);
		}

		bool IsWatchDog() 
		{
			return (m_Msg.hdr.mCmdCode == DIAMETER_MSGCODE_WATCHDOG);
		}

		bool IsPeerDisconnect() 
		{
			return (m_Msg.hdr.mCmdCode == DIAMETER_MSGCODE_DISCONNECT_PEER);
		}



		diameter_unsigned32_t GetCommandCode() 
		{
			return m_Msg.hdr.mCmdCode;
		}

		bool IsBaseProtocol() 
		{
			static diameter_unsigned32_t msgBaseProto[] = 
			{
				DIAMETER_MSGCODE_ABORTSESSION,
				DIAMETER_MSGCODE_SESSIONTERMINATION,
				DIAMETER_MSGCODE_CAPABILITIES_EXCHG,
				DIAMETER_MSGCODE_WATCHDOG,
				DIAMETER_MSGCODE_DISCONNECT_PEER,
				DIAMETER_MSGCODE_ACCOUNTING,
				DIAMETER_MSGCODE_REAUTH
			};
			
			for (unsigned int i = 0;
					i < sizeof(msgBaseProto) / sizeof(diameter_unsigned32_t);
					i++) 
			{
				if (msgBaseProto[i] == m_Msg.hdr.mCmdCode) 
				{
					return true;
				}
			}
			return false;
		}

	private:
		DiameterMsg & m_Msg;
};

class DiameterHostByName {
	public:
		static bool Lookup(std::string name, std::string &host)
		{
			char **pptr;
			struct hostent *hptr;
			int i;
			char temp[INET_ADDRSTRLEN] = "";

			hptr = gethostbyname(name.c_str());

			if(hptr == NULL)
			{
				return false;
			}

			switch(hptr->h_addrtype)
			{
				case AF_INET:
					{
						for(i =0, pptr = hptr->h_addr_list; *pptr != NULL; pptr++, i++)
						{
							inet_ntop(AF_INET, *pptr, temp, INET_ADDRSTRLEN);
							host = temp;
							return true;
						}
					}
					break;
				default:
					break;
			}

			return false;
		}
};

typedef enum {
	SYNC_OP_ADD,
	SYNC_OP_DEL
} SyncOperation;

typedef struct {
	int  localH2H;
	int  origH2H;
	char sourceName[150];
	char destName[150];
	SyncOperation  op;

} SyncHopByHopIdData;

typedef struct {
   int  appId;
   int  event;
   int                  mModuleId;
   SyncOperation        op;
   char sessionId[150];
   char sourceName[150];
   char destName[150];
} SyncDccaProxySessionData;

inline void LogConnection(string peerName,bool client, bool req)
{

	std::string connFileName = DIAMETER_CFG_STARTUP()->productHome + "/var/log/PeerConnections.log";
	ofstream connfile (connFileName,std::ofstream::out | std::ofstream::app);

	if (connfile.is_open())
	{
		auto in_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		char mbstr[100];
		if(std::strftime(mbstr, sizeof(mbstr), "%F %X", std::localtime(&in_time_t)))
		{
			if(client)
			{
				if(req)
					connfile << mbstr << " [CER] Received from [Peer] " << peerName << std::endl;
				else
					connfile << mbstr << " [CEA] Send to [Peer] " << peerName << std::endl;
			}
			else
			{
				if(req)
					connfile << mbstr << " [CER] Sent to [Peer] " << peerName << std::endl;
				else
					connfile << mbstr << " [CEA] Received from [Peer] " << peerName << std::endl;
			}
		}
		connfile.close();
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |TRANSPORT| Failed to write to file %s",connFileName.c_str()));
	}
}

#endif				// __AAA_DEFS_H__
