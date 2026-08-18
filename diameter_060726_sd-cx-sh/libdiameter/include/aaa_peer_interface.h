// @(#) $Id: aaa_peer_interface.h,v 1.1.4.1.2.1.2.12 2024/05/15 13:08:41 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_peer_interface.h
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
#ifndef __AAA_PEER_INTERFACE_H__
#define __AAA_PEER_INTERFACE_H__

#include "aaa_data_defs.h"
#include "aaa_peer_table.h"
#include "aaa_route_msg_router.h"

typedef enum 
{
    PEER_EVENT_CONN_NACK,
    PEER_EVENT_TIMEOUT_OR_NONCEA,
} PFSM_EV_ERR;
/*
inline void LogConnection(string peerName)
{
	std::string connFileName = DIAMETER_CFG_STARTUP()->productHome + "/var/log/PeerConnections.log";
	ofstream connfile (connFileName);
	if (connfile.is_open())
	{
		auto in_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		char mbstr[100];
		if(std::strftime(mbstr, sizeof(mbstr), "%F %X", std::localtime(&in_time_t)))
		{	
			connfile << mbstr << " [CER] Received from [Peer] " << peerName << std::endl;
		}
		connfile.close();
   }
   else 
   {
		AAA_LOG((LM_ERROR, "%T |TRANSPORT| Failed to write to file %s",connFileName.c_str()));
   }	
}
*/
class DiameterPeerEventInterface
{
   public:
      virtual void Connected() = 0;
      virtual void Disconnected(int cause) = 0;
      virtual void Error(PFSM_EV_ERR err) = 0;
      virtual ~DiameterPeerEventInterface() {
      }

      // TBD: Can add more events here when needed
};

class DIAMETERBASEPROTOCOL_EXPORT DiameterPeer :
   public DiameterPeerEntry
{
   public:
      DiameterPeer(AAA_Task &task,
               std::string &peername,
               int peerport,
               int use_sctp,
					int use_stack_identity,
               int tls_enabled,
               int etime,
               bool is_static,
					int client,
					std::string &hostentry,
					int hostport,
					std::string &realmName,
					int AnswerPeer,int TempDisconnection, bool lToSendDWR, sctp_rtoinfo rto) :
          DiameterPeerEntry(task,
                        peername,
                        peerport,
                        use_sctp,
                        use_stack_identity,
                        tls_enabled,
                        etime,
                        is_static,
								client,
								hostentry,
								hostport,
								realmName,
								AnswerPeer , TempDisconnection ,lToSendDWR, rto),
          m_EventInterface(NULL)	{
      }

      virtual void RegisterUserEventHandler (DiameterPeerEventInterface &handler) 
		{
         ACE_Write_Guard<ACE_RW_Mutex> guard(m_EventMtx);
         m_EventInterface = &handler;
      }

      virtual void RemoveUserEventHandler() 
		{
         ACE_Write_Guard<ACE_RW_Mutex> guard(m_EventMtx);
         m_EventInterface = NULL;
      }

   protected:
      virtual void Connected() 
		{
         ACE_Read_Guard<ACE_RW_Mutex> guard(m_EventMtx);
         if (m_EventInterface) 
			{
             m_EventInterface->Connected();
         }
      }

      virtual void Error(int resultCode) 
		{
         ACE_Read_Guard<ACE_RW_Mutex> guard(m_EventMtx);
         if (m_EventInterface) 
			{
             m_EventInterface->Error
                ((resultCode == AAA_LIMITED_SUCCESS) ?
                   PEER_EVENT_TIMEOUT_OR_NONCEA :
                   PEER_EVENT_CONN_NACK);
         }
      }

      virtual void Disconnected(int cause) 
		{

         DIAMETER_MSG_ROUTER()->ReTransmitEvent
            (static_cast<DiameterPeerEntry*>(this));

         ACE_Read_Guard<ACE_RW_Mutex> guard(m_EventMtx);
         if (m_EventInterface) {
             m_EventInterface->Disconnected(cause);
         }
      }

   private:
      ACE_RW_Mutex m_EventMtx;
      DiameterPeerEventInterface *m_EventInterface;
};

class DIAMETERBASEPROTOCOL_EXPORT DiameterPeerManager
{
   public:
      DiameterPeerManager(AAA_Task &t) :
         m_Task(t) 
		{

      }
      bool Add(std::string &peername,
               int peerport,
               int use_sctp,
					int use_stack_identity,
               int tls_enabled,
               int etime,
               bool is_static,
					int client,
					std::string &hostentry,
					int hostport,
					std::string &realmName,sctp_rtoinfo rto) 
		{
			if (!is_static && (etime == 0)) 
			{
				etime = DIAMETER_PEER_TABLE()->ExpirationTime();
			}
			
			int AnswerPeer        = DIAMETER_PEER_TABLE()->AnswerToPeer();
			int TempDisconnection = DIAMETER_PEER_TABLE()->TempDisconnection();
			int lToSendDWR        = DIAMETER_PEER_TABLE()->ToSendDWR();

			try 
			{
				if (rto.srto_initial == 0 || rto.srto_max == 0 || rto.srto_min == 0 )
				{
					rto.srto_initial = 120;
					rto.srto_max     = 800;
					rto.srto_min     = 120;
				}

				DiameterHostIdData *hostId = DIAMETER_HOST_ID_TABLE()->First();

				while (hostId)
				{
					if( hostentry != hostId->identity)
					{
						hostId = DIAMETER_HOST_ID_TABLE()->Next(hostId);
						if (hostId != NULL)
							continue;
					}
					else if(hostentry == hostId->identity)
					{
						break;
					}
					AAA_LOG((LM_ERROR, "%T |TRANSPORT| Invalid host_entry:%s in peer table:%s ", hostentry.c_str(), 
								peername.c_str()));
					return false;
				}

				DiameterPeer *p = new DiameterPeer(m_Task,
						peername,
						peerport,
						use_sctp,
						use_stack_identity,
						tls_enabled,
						etime,
						is_static,
						client,
						hostentry,
						hostport,
						realmName,
						AnswerPeer,TempDisconnection,lToSendDWR, rto);
				if (p)
				{
					if(!(DIAMETER_PEER_TABLE()->m_ReloadFlag))
					{
						if(!(p->GetConnectionStatus()))
						{
							DIAMETER_PEER_TABLE()->Add(p);
						}
						else
						{
							delete p;
						}
						return true;
					}
					else
					{
						DIAMETER_PEER_RELOAD_TABLE()->Add(p);
						return true;
					}
				}
				else
				{
					AAA_LOG((LM_ERROR, "%T |TRANSPORT| Invalid host_entry in peer table\n"));
				}

			}
			catch(...)
			{
				AAA_LOG((LM_ERROR, "%T |TRANSPORT| Invalid host_entry:%s in peer table:%s ", hostentry.c_str(), peername.c_str()));
				return false;
			}
			return false;
		}

		bool Delete(std::string &peername) 
		{
			DiameterPeerEntry *e = DIAMETER_PEER_TABLE()->Remove(peername);
			if (e) 
			{
				e->Stop(AAA_DISCONNECT_DONTWANTTOTALK);
				delete e;
				return true;
			}
			return false;
		}

		DiameterPeer *Lookup(std::string &peername) 
		{
			return static_cast<DiameterPeer*>(DIAMETER_PEER_TABLE()->Lookup(peername));
		}

		void	DisplayPeers () 
		{
			DIAMETER_PEER_TABLE()->Dump();
		}

	private:
		AAA_Task &m_Task;
};

class DiameterPeerConnector
{
	public:
		static inline void Start() 
		{
			DiameterPeerEntry *e = DIAMETER_PEER_TABLE()->First();
		
			while (e) {
				if(!(e->GetConnectionStatus()))
				{
					e->Start();
				}
				e = DIAMETER_PEER_TABLE()->Next(e);
			}
		}
		static inline int GetNumOpenPeers() 
		{
			int count = 0;
			DiameterPeerEntry *e = DIAMETER_PEER_TABLE()->First();
			while (e) {
				count += (e->IsOpen()) ? 1 : 0;
				e = DIAMETER_PEER_TABLE()->Next(e);
			}
			return count;
		}
		static inline void Stop(DIAMETER_DISCONNECT_CAUSE cause) 
		{
			DiameterPeerEntry *e = DIAMETER_PEER_TABLE()->First();
			while (e) {
				e->Stop(cause);
				e = DIAMETER_PEER_TABLE()->Next(e);
			}
		}

		static inline void DisplayPeer ()
		{
			 DIAMETER_PEER_TABLE()->Dump ();
		}

		static DiameterPeerList* GetAllPeer ()
		{
			//cout << " DIAMETER_PEER_TABLE " << DIAMETER_PEER_TABLE()->GetPeerList() <<endl;
			return DIAMETER_PEER_TABLE()->GetPeerList();
		}
};		

class DiameterPeerAcceptor : public DiameterTcpAcceptor,
	DiameterSctpAcceptor
{
	public:
		void Start(DiameterHostIdData *hostId) 
		{
			if(hostId)
			{
				m_hostIdentity = hostId->identity ;
			}
			else
			{
				return ;
			}

			if (hostId->tcp_listen_port > 0) 
			{
#ifdef ACE_HAS_IPV6
				ACE_INET_Addr hostIdentity(hostId->tcp_listen_port, hostId->identity.c_str(),
						(DIAMETER_CFG_TRANSPORT()->use_ipv6) ? AF_INET6 : AF_INET);
				DiameterTcpAcceptor::Open(hostId->tcp_listen_port, hostIdentity);
#else /* ! ACE_HAS_IPV6 */
				if(!DIAMETER_CFG_TRANSPORT()->listen_any_ip_addr)
				{
					ACE_INET_Addr hostIdentity(hostId->tcp_listen_port, hostId->identity.c_str(), AF_INET);
					DiameterTcpAcceptor::Open(hostId->tcp_listen_port, hostIdentity);
				}
				else
				{
					ACE_INET_Addr hostIdentity(hostId->tcp_listen_port, INADDR_ANY);
					DiameterTcpAcceptor::Open(hostId->tcp_listen_port, hostIdentity);
				}
#endif /* ! ACE_HAS_IPV6 */
				AAA_LOG((LM_INFO, "%T |TRANSPORT| TCP  Acceptor Listening at %d, binding to %s \n", hostId->tcp_listen_port, hostId->identity.c_str()));
			}

			if (hostId->sctp_listen_port > 0) 
			{
				AAA_LOG((LM_INFO, "%T |TRANSPORT| SCTP Acceptor Listening at %d, binding to ", hostId->sctp_listen_port));

				ACE_Multihomed_INET_Addr hostAddresses;

				if(!DIAMETER_CFG_TRANSPORT()->listen_any_ip_addr)
				{
					char **name = new char*[hostId->advertised_hostname.size()];
					std::list<std::string>::iterator i = hostId->advertised_hostname.begin();
					for (int y = 0; i != hostId->advertised_hostname.end(); i++, y++)
					{
							name[y] = (char*)((*i).c_str());
							AAA_LOG((LM_ERROR, "%s ", name[y]));
					}
					AAA_LOG((LM_ERROR, "\n"));

					hostAddresses.set(hostId->sctp_listen_port, hostId->identity.c_str(), 1,
#ifdef ACE_HAS_IPV6
							(DIAMETER_CFG_TRANSPORT()->use_ipv6) ? AF_INET6 : AF_INET,
#else /* ! ACE_HAS_IPV6 */
							AF_INET,
#endif /* ! ACE_HAS_IPV6 */
							(const char**)name, hostId->advertised_hostname.size());

					DiameterSctpAcceptor::Open(hostId->sctp_listen_port, hostAddresses);
					delete[] name;
				}
				else
				{
					ACE_UINT32 *name = new ACE_UINT32[hostId->advertised_hostname.size()];

					std::list<std::string>::iterator i = hostId->advertised_hostname.begin();

					for (int y = 0; i != hostId->advertised_hostname.end(); i++, y++) 
					{
						name[y] = (ACE_UINT32)(*((*i).c_str()));
						AAA_LOG((LM_ERROR, "%d ", name[y]));
					}
					AAA_LOG((LM_ERROR, "\n"));

					hostAddresses.set(hostId->sctp_listen_port, INADDR_ANY, 1,
							name, hostId->advertised_hostname.size());

					DiameterSctpAcceptor::Open(hostId->sctp_listen_port, hostAddresses);
					delete[] name;
				}

			}
		}

      void Stop() 
		{
          DiameterTcpAcceptor::Close();
          DiameterSctpAcceptor::Close();
      }

   protected:

    /*
        5.6.1.  Incoming connections

           When a connection request is received from a Diameter peer, it is
           not, in the general case, possible to know the identity of that peer
           until a CER is received from it.  This is because host and port
           determine the identity of a Diameter peer; and the source port of an
           incoming connection is arbitrary.  Upon receipt of CER, the identity
           of the connecting peer can be uniquely determined from Origin-Host.

           For this reason, a Diameter peer must employ logic separate from the
           state machine to receive connection requests, accept them, and await
           CER.  Once CER arrives on a new connection, the Origin-Host that
           identifies the peer is used to locate the state machine associated
           with that peer, and the new connection and CER are passed to the
           state machine as an R-Conn-CER event.

           The logic that handles incoming connections SHOULD close and discard
           the connection if any message other than CER arrives, or if an
           implementation-defined timeout occurs prior to receipt of CER.

           Because handling of incoming connections up to and including receipt
           of CER requires logic, separate from that of any individual state
           machine associated with a particular peer, it is described separately
           in this section rather than in the state machine above.
    */

      class PendingResponder : //public DiameterGarbageCollectorAttribute,
         public DiameterRxMsgCollectorHandler 
			{
            public:
               PendingResponder(DiameterPeerAcceptor &a,  std::unique_ptr<Diameter_IO_Base> io) :
                   m_IO(std::move(io)), m_Acceptor(a) 
				{
					DiameterRxMsgCollector *h = reinterpret_cast<DiameterRxMsgCollector*>(m_IO->Handler());
					h->RegisterHandler(*this);
				}

				virtual ~PendingResponder() 
				{

				}

				void HandleMessage(std::unique_ptr<DiameterMsg> msg) 
				{
					DiameterMsgQuery query(*msg);

					AAA_LOG((LM_DEBUG, "%T |TRANSPORT| HH:%d EE:%d CC:%d R:%d MsgLen:%d Handle Msg\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode, msg->hdr.mCmdFlg.rBit, msg->hdr.mMsgLen));

					if (query.IsCapabilities() && query.IsRequest()) 
					{
						std::string oHost;

						std::unique_ptr<CapabilityExchangeRequest> ce(new CapabilityExchangeRequest);

						try 
						{
							ce->Decode(&msg->rawbyteArray);
						}
						catch ( TssDiameterMsgException &st)
						{
							AAA_LOG((LM_ERROR, "%T |TRANSPORT| HH:%d EE:%d CC:%d R:%d MsgLen:%d CER Decode Failed\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode, msg->hdr.mCmdFlg.rBit, msg->hdr.mMsgLen));
						}

						try
						{
							oHost.assign(ce->getOriginHost()->getValue()? (char*)ce->getOriginHost()->getValue():"" , 
									ce->getOriginHost()->getLength() ? ce->getOriginHost()->getLength() : 0);
						}
						catch ( const char* pNullPtrException )
						{
							AAA_LOG((LM_ERROR, "%T |TRANSPORT| HH:%d EE:%d CC:%d R:%d MsgLen:%d OH Exception\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode, msg->hdr.mCmdFlg.rBit, msg->hdr.mMsgLen));
						}

						if(oHost.size())
						{
							LogConnection(oHost,true,true);
							DiameterPeerEntry *rDiameterPeerEntry = DIAMETER_PEER_TABLE()->Lookup(oHost);
							if (rDiameterPeerEntry) 
							{
								std::unique_ptr<PendingResponder> guard(this);
								m_Acceptor.RemoveFromPendingList(*this);
								rDiameterPeerEntry->IncommingConnectionRequest(std::move(m_IO), std::move(msg));
								return;
							}
							else
							{
								//Unknown peer
								AAA_LOG((LM_ERROR, "%T |TRANSPORT| HH:%d EE:%d CC:%d R:%d MsgLen:%d CER received from Unknown Peer, Peer:%s\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode, msg->hdr.mCmdFlg.rBit, msg->hdr.mMsgLen, oHost.c_str()));
	
								byteArray rawbyteArray;
								ACE_OS::memset(&rawbyteArray , 0, sizeof(rawbyteArray));

								std::unique_ptr<CapabilityExchangeAnswer> cea(new CapabilityExchangeAnswer );
								cea->getDiameterMsgHeader()->mVersion   = DIAMETER_PROTOCOL_VERSION;
								cea->setCmdFlag(32);
								cea->getDiameterMsgHeader()->mCmdCode   = DIAMETER_MSGCODE_CAPABILITIES_EXCHG;
								cea->getDiameterMsgHeader()->mApplId    = DIAMETER_BASE_APPLICATION_ID;		
								cea->getDiameterMsgHeader()->mHopByHopId  =  msg->hdr.mHopByHopId;
								cea->getDiameterMsgHeader()->mEndToEndId  =  msg->hdr.mEndToEndId;
							
								cea->setResultCode()->setValue(AAA_UNKNOWN_PEER);

								DiameterPeerEntry *rPeerEntry = DIAMETER_PEER_TABLE()->First();
								cea->setOriginHost()->setValue((UINT8*)rPeerEntry->HostEntry().m_Identity.c_str(),rPeerEntry->HostEntry().m_Identity.size());
								cea->setOriginRealm()->setValue((UINT8*)rPeerEntry->HostEntry().m_Realm.c_str(),rPeerEntry->HostEntry().m_Realm.size());	

								cea->setVendorId()->setValue(DIAMETER_CFG_GENERAL()->vendor);
								cea->setProductName()->setValue((UINT8*)DIAMETER_CFG_GENERAL()->product.c_str(), DIAMETER_CFG_GENERAL()->product.size());
								cea->setFirmwareRevision()->setValue(DIAMETER_CFG_GENERAL()->version);
							
								if (DIAMETER_NO_ERR == cea->Encode( &rawbyteArray))
   							{
      							AAA_LOG((LM_DEBUG, "%T |TRANSPORT| HH:%d EE:%d CC:%d R:%d Success to Encode CEA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
   							}
   							else
   							{
      							AAA_LOG((LM_ERROR, "%T |TRANSPORT| HH:%d EE:%d CC:%d R:%d Failed to Encode CEA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
									return;
   							}

								if(m_IO->SendData(&rawbyteArray))
								{
									 AAA_LOG((LM_DEBUG, "%T |TRANSPORT| HH:%d EE:%d CC:%d R:%d Success to send CEA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
								}	
								else
								{
									AAA_LOG((LM_ERROR, "%T |TRANSPORT| HH:%d EE:%d CC:%d R:%d Failed to send CEA\n", msg->hdr.mHopByHopId, msg->hdr.mEndToEndId, msg->hdr.mCmdCode,    msg->hdr.mCmdFlg.rBit));
								}
							}
						}
						/*
							CERs received from unknown peers MAY be silently
							discarded, or a CEA MAY be issued with the Result-Code
							AVP set to DIAMETER_UNKNOWN_PEER. In both cases, the
							transport connection is closed.  If the local policy
							permits receiving CERs from unknown hosts, a successful
							CEA MAY be returned.  If a CER from an unknown peer is
							answered with a successful CEA, the lifetime of the peer
							entry is equal to the lifetime of the transport connection.
							In case of a transport failure, all the pending transactions
							destined to the unknown peer can be discarded.
						*/
							
					}
					Error(DiameterRxMsgCollectorHandler::INVALID_MSG, m_IO->Name());
				}

				void Error(COLLECTOR_ERROR error, std::string &io_name) 
				{
					if (error == DiameterRxMsgCollectorHandler::PARSING_ERROR) 
					{
						AAA_LOG((LM_ERROR, "%T |TRANSPORT| io:%s Parsing Error\n", io_name.c_str()));

						return; // not considered fatal for now
					}
					AAA_LOG((LM_ERROR, "%T |TRANSPORT| Peer failed establishing state[%s:%d], closing\n", io_name.c_str(), error));
					std::unique_ptr<PendingResponder> guard(this);
					m_Acceptor.RemoveFromPendingList(*this);

					m_IO->Close();
					DIAMETER_IO_GC().ScheduleForDeletion(std::move(m_IO));
				}

				int SendErrorAnswer(std::unique_ptr<DiameterMsg> &msg) 
				{
					AAA_LOG((LM_ERROR, "%T |TRANSPORT| Peer message maybe malformed, ignoring during CER/CEA exchange\n"));
					return (0);
				}

				private:
				std::unique_ptr<Diameter_IO_Base> m_IO;
				DiameterPeerAcceptor &m_Acceptor;
			};

		friend class PendingResponder;

		int Success(Diameter_IO_Base *io) 
		{
			std::unique_ptr<Diameter_IO_Base> newIO(io);
			PendingResponder *rPendingResponder = new PendingResponder(*this, std::move(newIO));
			if (rPendingResponder) 
			{
				AAA_TokenScopeLock guard(m_ResponderToken);
				m_PendingResponders.push_back(rPendingResponder);
			}
			return (0);
		}

		int Failed() 
		{
			Stop();
			return (0);
		}

	protected:
		void RemoveFromPendingList(PendingResponder &r) 
		{
			AAA_TokenScopeLock guard(m_ResponderToken);
			std::list<PendingResponder*>::iterator i;
			for (i = m_PendingResponders.begin();
					i != m_PendingResponders.end();
					i++) 
			{
				if ((*i) == &r) 
				{
					m_PendingResponders.erase(i);
					//DIAMETER_IO_PR()->ScheduleForDeletion(*i);
					break;
				}
			}
		}

	private:
		std::list<PendingResponder*> m_PendingResponders;
		ACE_Token m_ResponderToken;

	public:
		std::string m_hostIdentity = "";
};

typedef std::list<DiameterPeerAcceptor*> DiameterPeerAcceptorList;

/*
typedef DiameterGarbageCollectorSingleton<PendingResponder>
             DiameterIOPR;

typedef ACE_Singleton<DiameterIOPR,
                      ACE_Recursive_Thread_Mutex>
                      DiameterIOPR_S;

#define DIAMETER_IO_PR_ROOT() (DiameterIOPR_S::instance())
#define DIAMETER_IO_PR()      (DiameterIOPR_S::instance()->Instance())
*/

#endif 
