// @(#) $Id: aaa_peer_data.h,v 1.1.4.1.2.1.2.8 2024/05/15 13:08:41 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_peer_data.h
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
#ifndef __AAA_PEER_DATA_H__
#define __AAA_PEER_DATA_H__

#include "aaa_transport_collector.h"
#include "aaa_transport_ace.h"
#include "aaa_data_defs.h"

typedef Diameter_ACE_Transport<ACE_SOCK_Acceptor,
                               ACE_SOCK_Connector,
                               ACE_SOCK_Stream,
                               ACE_INET_Addr,
                               IPPROTO_TCP> DiameterTransportTCP;
typedef Diameter_ACE_Transport<ACE_SOCK_SEQPACK_Acceptor,
                               ACE_SOCK_SEQPACK_Connector,
                               ACE_SOCK_SEQPACK_Association,
                               ACE_Multihomed_INET_Addr,
                               IPPROTO_SCTP> DiameterTransportSCTP;

typedef Diameter_IO_Connector<DiameterTransportTCP,
                              ACE_INET_Addr,
                              DiameterRxMsgCollector> DiameterTcpConnector;
typedef Diameter_IO_Connector<DiameterTransportSCTP,
                              ACE_Multihomed_INET_Addr,
                              DiameterRxMsgCollector> DiameterSctpConnector;

typedef Diameter_IO_Acceptor<DiameterTransportTCP,
                             ACE_INET_Addr,
                             DiameterRxMsgCollector> DiameterTcpAcceptor;
typedef Diameter_IO_Acceptor<DiameterTransportSCTP,
                             ACE_Multihomed_INET_Addr,
                             DiameterRxMsgCollector> DiameterSctpAcceptor;

typedef Diameter_ACE_TransportAddress DiameterIpAddress;

typedef std::list<diameter_address_t*> DiameterHostIpLst;

typedef enum 
{
    DIAMETER_PEER_CONN_INITIATOR = 0,
    DIAMETER_PEER_CONN_RESPONDER,
    DIAMETER_PEER_CONN_MAX,
} DIAMETER_PEER_CONN;

typedef enum {
    AAA_DISCONNECT_REBOOTING       = 0,
    AAA_DISCONNECT_BUSY            = 1,
    AAA_DISCONNECT_DONTWANTTOTALK  = 2,
    AAA_DISCONNECT_UNKNOWN         = 1000,
    AAA_DISCONNECT_TRANSPORT       = 10001,
    AAA_DISCONNECT_TIMEOUT         = 10002,
    AAA_DISCONNECT_EXTERNAL        = 3,
} DIAMETER_DISCONNECT_CAUSE;

typedef struct
{
	diameter_unsigned32_t m_LastTxHopId = 0;
	diameter_unsigned32_t m_LastTxEndId = 0;

	diameter_unsigned32_t m_LastRxHopId = 0;
	diameter_unsigned32_t m_LastRxEndId = 0;

} DiameterMsgId;

typedef struct
{
   diameter_octetstring_t 		 m_Host;
   diameter_octetstring_t 		 m_Realm;
   diameter_utf8string_t 		 m_ProductName; 
   diameter_unsigned32_t 		 m_VendorId;
   diameter_unsigned32_t 		 m_InbandSecurityId;
   diameter_unsigned32_t 		 m_OriginStateId;
   diameter_unsigned32_t 	    m_FirmwareRevision;
   DiameterApplicationIdLst 	 m_SupportedVendorIdLst;
   DiameterApplicationIdLst 	 m_AuthAppIdLst;
   DiameterHostIpLst			 	 m_HostIpLst;
   DiameterApplicationIdLst 	 m_AcctAppIdLst;
   DiameterVendorSpecificIdLst m_VendorSpecificId;
   DiameterMsgId 					 m_MsgId;
} DiameterPeerCapabilities;

typedef struct
{
   std::string           m_Identity;
   std::string           m_Realm;
   std::list < std::string > m_AdvertisedHostName;
} DiameterHostEntry;

typedef struct
{
   diameter_octetstring_t m_Identity;
   diameter_octetstring_t m_realmName;
   diameter_unsigned32_t  m_Port;
   DIAMETER_DISCONNECT_CAUSE  m_DisconnectCause;
   int m_Expiration;
	bool m_Suspend = false;
   bool m_Static;
   bool m_TLS;
   bool m_UseSctp;
	bool m_UseStackIdentity;
	bool m_Client;
	bool m_AnswerToPeer;
	bool m_TempDisconnection = false;
	bool m_ToSendDWR = false;
   std::unique_ptr<Diameter_IO_Base> m_IOInitiator;
   std::unique_ptr<Diameter_IO_Base> m_IOResponder;
   DiameterPeerCapabilities m_PeerCapabilities;
   DiameterHostEntry m_HostEntry;
   diameter_unsigned32_t m_HostPort;
	DiameterPeg* m_Peg;
	sctp_rtoinfo rto;
} DiameterPeerData;


#endif /* __AAA_PEER_DATA_H__ */
