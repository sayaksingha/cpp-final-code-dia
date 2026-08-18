// @(#) $Id: aaa_peer_table.h,v 1.1.4.1.2.1.2.16 2024/05/15 13:08:41 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_peer_table.h
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
#ifndef __AAA_PEER_TABLE_H__
#define __AAA_PEER_TABLE_H__

#include "aaa_peer_fsm.h"
#include "aaa_host_id_table.h"

class DIAMETERBASEPROTOCOL_EXPORT DiameterPeerEntry :
	public DiameterPeerStateMachine,
          DiameterRxMsgCollectorHandler
{
   public:
      DiameterPeerEntry(AAA_Task &task,
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
								int AnswerPeer,
								int TempDisconnection, bool lToSendDWR,sctp_rtoinfo rto) :
          DiameterPeerStateMachine(task, TempDisconnection),
          m_PeerInitiator(*this) 
	{
          PeerData().m_Identity = peername;
          PeerName() 	        = peername;
          PeerData().m_realmName = realmName;
          PeerData().m_Port = peerport;
          PeerData().m_Static = is_static;
          PeerData().m_Expiration = etime;
          PeerData().m_TLS = tls_enabled ? true : false;
          PeerData().m_UseSctp = use_sctp ? true : false;
          PeerData().m_UseStackIdentity = use_stack_identity ? true : false;
          PeerData().m_Client  = client ? true : false;
          PeerData().m_DisconnectCause = AAA_DISCONNECT_DONTWANTTOTALK;
			 DiameterHostIdData *hostIdData = DIAMETER_HOST_ID_TABLE()->Lookup(hostentry);

			 if(!hostIdData)
				 DiameterPeerFsmException(0,"Invalid host entry");

			 PeerData().m_HostEntry.m_Identity = hostIdData->identity;
			 PeerData().m_HostEntry.m_Realm = hostIdData->realm;
			 PeerData().m_HostEntry.m_AdvertisedHostName = hostIdData->advertised_hostname;
			 PeerData().m_HostPort = hostport;
          //AAA_StateMachineWithTimer<DiameterPeerStateMachine>::Start();
			 PeerData().m_Peg = new DiameterPeg;
			 PeerData().m_AnswerToPeer      = AnswerPeer;          //TBC Please Check this? 
			 PeerData().m_TempDisconnection = TempDisconnection;   //TBC Please Check this? 
			// PeerData().m_TempDisconnection = false;             //TBC Please Check this?  
		
			 PeerData().m_ToSendDWR = lToSendDWR;          //TBC Please Check this? 
			 PeerData().rto = rto;			 
			 //if(!PeerData().m_TempDisconnection)
				{
					//DiameterPeerStateMachine::DiameterPeerStateMachine(task);
					//m_PeerInitiator = *this;
					AAA_StateMachineWithTimer<DiameterPeerStateMachine>::Start();
				}

			 //PeerData().m_Peg = DiameterPeg::createInstance(); // PEG
//Register
      }
      virtual ~DiameterPeerEntry() {
          DiameterPeerStateMachine::Stop();
			 if(NULL != PeerData().m_Peg)
					delete PeerData().m_Peg;
      }

      void Start();// throw (AAA_Error);
      void Stop(DIAMETER_DISCONNECT_CAUSE cause, bool lSuspend = false);
      void StopPeerInitiator(DIAMETER_DISCONNECT_CAUSE cause);
//-------------
		void StopPeerStateMachine()
		{
			AAA_StateMachineWithTimer<DiameterPeerStateMachine>::Stop();
			if(NULL != PeerData().m_Peg)
				delete PeerData().m_Peg;
		}
		void StartPeerStateMachine()
		{
			AAA_StateMachineWithTimer<DiameterPeerStateMachine>::Start();
		}
		void StopThread()
		{
			DiameterPeerStateMachine::Stop();
			m_TxMsgCollector.Stop();
			AAA_StateMachine<DiameterPeerStateMachine>::Stop();


			if(NULL != PeerData().m_Peg)
				delete PeerData().m_Peg;
		}
		//----------


      bool IsOpen() {
          return ((state == DIAMETER_PEER_ST_I_OPEN) ||
                  (state == DIAMETER_PEER_ST_R_OPEN)) ?
              true : false;
      }
	
		Diameter_IO_Base* getIOObject()
		{
			switch(state)
			{
				case DIAMETER_PEER_ST_I_OPEN:
					{
						return PeerData().m_IOInitiator.get();
					}
				case DIAMETER_PEER_ST_R_OPEN:
					{
						return PeerData().m_IOResponder.get();
					}
				case DIAMETER_PEER_ST_WAIT_I_CEA:
					{
						return PeerData().m_IOInitiator.get();
					}
				default:
					{
						return NULL;
					}
			}
		}

      string GetPeerStatus() {
          return ((state == DIAMETER_PEER_ST_I_OPEN) ||
                  (state == DIAMETER_PEER_ST_R_OPEN)) ?
              "OPEN" : "CLOSE";
      }


      bool IsStatic() {
          return PeerData().m_Static;
      }

		DiameterHostEntry &HostEntry()
		{
			return PeerData().m_HostEntry;
		}

		DiameterPeg* Peg()
		{
			return PeerData().m_Peg;
		}
		
		std::string GetPeerName ()
		{
			return PeerData().m_Identity;
		}
	
		std::string GetRealmName ()
		{
			return PeerData().m_realmName;
		}

		bool IsClient ()
		{
			return PeerData().m_Client;
		}

		bool UseStackIdentity()
		{
			return PeerData().m_UseStackIdentity;
		}
//--------
		bool GetActionOnRoutNotFound()
		{
			return PeerData().m_AnswerToPeer;
		}
		bool GetConnectionStatus()
		{
			return PeerData().m_TempDisconnection;
		}
		bool ToSendDWRStatus()
		{
			return PeerData().m_ToSendDWR;
		}
//--------
	
      // Internal use only    
      void IncommingConnectionRequest(std::unique_ptr<Diameter_IO_Base> io,
                                      std::unique_ptr<DiameterMsg> cer);
      void ConnectionRequestAccepted(std::unique_ptr<Diameter_IO_Base> io);
      void ConnectionRequestFailed();
      void Dump() {
          AAA_LOG((LM_INFO, "%T |PEER_FSM| Peer : Host : %s, Port : %d, TLS : %d\n", PeerData().m_Identity.c_str(), PeerData().m_Port, PeerData().m_TLS));
      }

   protected:
      void HandleMessage(std::unique_ptr<DiameterMsg> msg);
      void Error(COLLECTOR_ERROR error, std::string &io_name);
      int SendErrorAnswer(std::unique_ptr<DiameterMsg> &msg);

      class PeerInitiator : public DiameterTcpConnector,
                                   DiameterSctpConnector
      {
          public:
             PeerInitiator(DiameterPeerEntry &e) :
                 m_Entry(e) {
             }

             int Connect(std::string &host,
                         int port,
                         bool useSctp,
								 std::string &hostentry,
								 int hostport, sctp_rtoinfo rto) {

                 return (useSctp) ?
                     DiameterSctpConnector::Open(host, port, hostentry, hostport, rto) :
                     DiameterTcpConnector::Open(host, port, hostentry, hostport, rto);
             }

             int Stop() 
				 {
                 DiameterSctpConnector::Close();
                 DiameterTcpConnector::Close();
                 return (0);
             }

          protected:
             int Success(Diameter_IO_Base *io) 
				 {
					 //printf("TBR  ;;; Peer initiator\n");
                 std::unique_ptr<Diameter_IO_Base> newIO(io);
                 m_Entry.ConnectionRequestAccepted(std::move(newIO));
                 return (0);
             }
             int Failed() {
					 //printf("TBR  ;;; Peer initiator failed\n");
                 m_Entry.ConnectionRequestFailed();
                 return (0);
             }

          private:
             DiameterPeerEntry &m_Entry;
      };

      friend class PeerInitiator;

   private:
      PeerInitiator m_PeerInitiator;
};
//--------------------
typedef std::list<DiameterPeerEntry*> DiameterPeerReloadList;

class DiameterPeerReloadTable : private DiameterPeerReloadList
{
	public:
		DiameterPeerReloadTable() {
		}
		virtual ~DiameterPeerReloadTable() {
		}
		bool Add(DiameterPeerEntry *e)
		{
			ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
			push_back(e);
			return true;
		}
		void Dump() 
		{
			AAA_LOG((LM_DEBUG, "%T |PEER_FSM|  Dumping Peer Table\n"));
			//		AAA_LOG((LM_DEBUG, "%T |PEER_FSM|       Expire Time %d\n", m_ExpirationTime));
			DiameterPeerReloadList::iterator i;
			for (i = begin(); i != end(); i++) {
				(*i)->Dump();
			}
		}

		DiameterPeerEntry *Lookup(std::string &peername)
		{
			ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
			DiameterPeerReloadList::iterator i;
			for (i = begin(); i != end(); i++) {
#if 0
				//
				// Warning: This is a case in-sensitive lookup which may not
				//          be generally appropriate if we consider FQDN as
				//          a non ascii value.
				//
				// Deprecated:
				//  if ((*i)->Data().m_Identity == peername) {}
				//
				//if (! strncasecmp((*i)->Data().m_Identity.c_str(), peername.c_str())) {}
#endif
				if (0 == strncasecmp((*i)->Data().m_Identity.c_str(), peername.c_str() , peername.size()))
				{
					return (*i);
				}
			}
			return (NULL);
		}

		void deletePeer(std::string &peername)
		{
			ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
			DiameterPeerReloadList::iterator i;
			for (i = begin(); i != end(); i++) {		
				if (! strcasecmp((*i)->Data().m_Identity.c_str(), peername.c_str())) {
					DiameterPeerEntry *lPeerToBeDel = *i;
					i = erase(i);
					//erase(i);
					//delete(lPeerToBeDel);
					lPeerToBeDel->StopThread();
				}	
			}
		}

		DiameterPeerEntry *Remove(std::string &peername)
		{
			ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
			DiameterPeerReloadList::iterator i;
			for (i = begin(); i != end(); i++) {
#if 0
				// Warning: This is a case in-sensitive lookup which may not
				//          be generally appropriate if we consider FQDN as
				//          a non ascii value.
				//
				// Deprecated:
				//  if ((*i)->Data().m_Identity == peername) {}
#endif
				if (! strcasecmp((*i)->Data().m_Identity.c_str(), peername.c_str())) {
					DiameterPeerEntry *lPeerEntry = *i; 
					erase(i);
					//return (*i);
					return lPeerEntry;
				}
			}
			return (NULL);
		}

		void Remove()
		{
			ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
			DiameterPeerReloadList::iterator i;
			for (i = begin(); i != end(); ) {
				i = erase(i);
			}
		}

		DiameterPeerEntry *First() {
			ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
			return (! empty()) ? front() : NULL;
		}
		DiameterPeerEntry *Next(DiameterPeerEntry *e)
		{
			ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
			DiameterPeerReloadList::iterator i;
			for (i = begin(); i != end(); i++)
			{
				if (e == (*i))
				{
					i ++;
					if (i != end()) {
						return (*i);
					}
					break;
				}
			}
			return (NULL);
		}
		void Clear() {
			ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
			while (! empty()) {
				DiameterPeerEntry *e = front();
				pop_front();
				delete e;
			}
		}

	private :
		ACE_RW_Mutex m_Lock;

};
//-----------------------


typedef std::list<DiameterPeerEntry*> DiameterPeerList;

class DiameterPeerTable : private DiameterPeerList
{
	public:
		DiameterPeerTable() : m_ExpirationTime(0) {
		}
		virtual ~DiameterPeerTable() {
		}
		bool Add(DiameterPeerEntry *e) 
		{
			ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
			push_back(e);
			return true;
		}
		DiameterPeerEntry *Lookup(std::string &peername) 
		{
			ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
			DiameterPeerList::iterator i;
			for (i = begin(); i != end(); i++) {
				//
				// Warning: This is a case in-sensitive lookup which may not
				//          be generally appropriate if we consider FQDN as
				//          a non ascii value.
				//
				// Deprecated:
				//  if ((*i)->Data().m_Identity == peername) {}
				//
				//if (! strncasecmp((*i)->Data().m_Identity.c_str(), peername.c_str())) {}
				if (0 == strncasecmp((*i)->Data().m_Identity.c_str(), peername.c_str() , peername.size())) 
				{
					return (*i);
				}
			}
			return (NULL);
		}
		DiameterPeerEntry *Remove(std::string &peername) 
		{
			ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
			DiameterPeerList::iterator i;
			for (i = begin(); i != end(); i++) {
				//
				// Warning: This is a case in-sensitive lookup which may not
				//          be generally appropriate if we consider FQDN as
				//          a non ascii value.
				//
				// Deprecated:
				//  if ((*i)->Data().m_Identity == peername) {}
				//
				if (! strcasecmp((*i)->Data().m_Identity.c_str(), peername.c_str())) {
					erase(i);
					return (*i);
				}
			}
			return (NULL);
		}
		DiameterPeerEntry *First() {
			ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
			return (! empty()) ? front() : NULL;
		}
		DiameterPeerEntry *Next(DiameterPeerEntry *e) 
		{
			ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
			DiameterPeerList::iterator i;
			for (i = begin(); i != end(); i++) 
			{
				if (e == (*i)) 
				{
					i ++;
					if (i != end()) {
						return (*i);
					}
					break;
				}
			}
			return (NULL);
		}

		void Clear() {
			ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
			while (! empty()) {
				DiameterPeerEntry *e = front();
				pop_front();
				delete e;
			}
		}
		int &ExpirationTime() {
			return m_ExpirationTime;
		}
		//----------      
		int &AnswerToPeer() {
			return m_AnswerPeer;
		}
		int &TempDisconnection() {
			return m_TempDisconnectionpeer;
		}

		bool &ToSendDWR() {
			return m_ToSendDWRFlag;
		}
		//---------
		void Dump() {
			AAA_LOG((LM_DEBUG, "%T |PEER_FSM|  Dumping Peer Table\n"));
			AAA_LOG((LM_DEBUG, "%T |PEER_FSM|       Expire Time %d\n", m_ExpirationTime));
			DiameterPeerList::iterator i;
			for (i = begin(); i != end(); i++) {
				(*i)->Dump();
			}
		}

		DiameterPeerList* GetPeerList ()
		{
			//cout << " 2 IAMETER_|PEER_FSM| GetPeerList "  <<endl;
			return dynamic_cast<DiameterPeerList*>(this);
		}


	private:
		ACE_RW_Mutex m_Lock;
		int m_ExpirationTime;
		int m_AnswerPeer = 0;
		int m_TempDisconnectionpeer = 0;
		bool m_ToSendDWRFlag=false;
	public:
		int m_ReloadFlag = 0;
};

typedef ACE_Singleton<DiameterPeerTable, ACE_Recursive_Thread_Mutex> DiameterPeerTable_S;
#define DIAMETER_PEER_TABLE() DiameterPeerTable_S::instance()

typedef ACE_Singleton<DiameterPeerReloadTable, ACE_Recursive_Thread_Mutex> DiameterPeerReloadTable_S;
#define DIAMETER_PEER_RELOAD_TABLE() DiameterPeerReloadTable_S::instance()

#endif /* __AAA_PEER_TABLE_H__ */

