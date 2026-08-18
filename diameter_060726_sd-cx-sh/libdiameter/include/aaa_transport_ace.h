// @(#) $Id: aaa_transport_ace.h,v 1.1.4.1.2.1.2.5 2021/10/14 08:10:34 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_transport_ace.h
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
#ifndef __AAA_TRANSPORT_ACE_H__
#define __AAA_TRANSPORT_ACE_H__

#include "ace/Signal.h"
#include "ace/Sig_Handler.h"
#include "ace/Reactor.h"
#include "ace/Handle_Set.h"
#include "ace/SOCK_Connector.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/SOCK_SEQPACK_Acceptor.h"
#include "ace/SOCK_SEQPACK_Connector.h"
#include "aaa_transport_interface.h"
#include "aaa_host_id_table.h"

// interface implemented by transport
// specific IO (lower layer). Assumes
// lower layer is connection oriented
template<class ACE_ACCEPTOR,
         class ACE_CONNECTOR,
         class ACE_STREAM,
         class ACE_ADDRESS,
         int IP_PROTOCOL>
class Diameter_ACE_Transport : public DiameterTransportInterface<ACE_ADDRESS>
{
   public:
      typedef enum timeOut_s{
          ACCEPTOR_TIMEOUT = 10   // 10 sec
      } timeOut_t;

   public:
      Diameter_ACE_Transport() : m_PendingStream(0) {
      }
      virtual ~Diameter_ACE_Transport() {
         if (m_PendingStream) {
             ResetStream((DiameterTransportInterface<ACE_ADDRESS>*&)m_PendingStream);
         }
      }
      int Open() {
         return 0;
      }

      void SetsctpInit(sctp_rtoinfo rto)//Temp added by anshul
      {
         if (IPPROTO_SCTP == IP_PROTOCOL)
         {
            sctp_initmsg   initmsg;
            memset(&initmsg, 0, sizeof(struct sctp_initmsg));
            initmsg.sinit_num_ostreams = 16;
            initmsg.sinit_max_instreams = 16;
            initmsg.sinit_max_attempts = DIAMETER_CFG_TRANSPORT()->sctp_init_max_attempts;

            //log_msg(TDSTRAN001, 1 ,"Diameter_ACE RTO:" << rto.srto_initial <<" " << rto.srto_max << " "<<rto.srto_min  ,"");
	    AAA_LOG((LM_DEBUG, "%T |TRANSPORT| Diameter_ACE RTO:INITIAL:%d MAX:%d MIN:%d\n",rto.srto_initial, rto.srto_max, rto.srto_min));

            int ret = m_Stream.set_option(IPPROTO_SCTP, SCTP_INITMSG, &initmsg, sizeof(sctp_initmsg));

            if (ret < 0) {
               perror("setsockopt SCTP_INITMSG");
	       AAA_LOG((LM_DEBUG, "%T |TRANSPORT| Diameter_ACE_Transport: IPPROTO_SCTP:%d IP_PROTOCOL:%d ret:\n", ((int)IPPROTO_SCTP), ((int)IP_PROTOCOL), ret));
            }

            ret = m_Stream.set_option(IPPROTO_SCTP, SCTP_RTOINFO, &rto, sizeof(sctp_rtoinfo));
            if (ret < 0) {
               perror("setsockopt SCTP_RTOINFO");
	       AAA_LOG((LM_DEBUG, "%T |TRANSPORT| Diameter_ACE_Transport: IPPROTO_SCTP:%d IP_PROTOCOL:%d ret:\n",((int)IPPROTO_SCTP), ((int)IP_PROTOCOL), ret));
            }
         }

      }

	
      //int Connect(std::string &hostname, int port) 
      int Connect(std::string &hostname, int port, std::string &hostentry, int hostport, sctp_rtoinfo &rto) 
		{
			//TBR ---------Added by Nandagopi
			if (m_PendingStream) {
				delete m_PendingStream;
				m_PendingStream = NULL;
			}			

         if (! m_PendingStream) {
             m_PendingStream = new Diameter_ACE_Transport
                  <ACE_ACCEPTOR, ACE_CONNECTOR, ACE_STREAM, ACE_ADDRESS, IP_PROTOCOL>;
             ACE_Time_Value tm(0, 0);
             ACE_ADDRESS dest(port, hostname.c_str());
				 DiameterHostIdData *hostId = DIAMETER_HOST_ID_TABLE()->Lookup(hostentry);

				 ACE_Multihomed_INET_Addr src;
				 char **name = new char*[hostId->advertised_hostname.size()];
				 std::list<std::string>::iterator i = hostId->advertised_hostname.begin();

				 for (int y = 0; i != hostId->advertised_hostname.end(); i++, y++)
				 {
					 name[y] = (char*)(*i).c_str();
				 }
				 src.set(hostport, hostId->identity.c_str(), 1,
#ifdef ACE_HAS_IPV6
						 (DIAMETER_CFG_TRANSPORT()->use_ipv6) ? AF_INET6 : AF_INET,
#else /* ! ACE_HAS_IPV6 */
						 AF_INET,
#endif /* ! ACE_HAS_IPV6 */
						 (const char**)name, hostId->advertised_hostname.size());
				 

				 //ACE_ADDRESS src(hostport, hostentry.c_str());
				 if (IPPROTO_SCTP == IP_PROTOCOL)
				 {
					 // Only open a new socket if we don't already have a valid handle.
					 if (m_PendingStream->Stream().get_handle () == ACE_INVALID_HANDLE &&
#if defined (ACE_HAS_LKSCTP)
						m_PendingStream->Stream().open (SOCK_STREAM,
#else
						 m_PendingStream->Stream().open (SOCK_SEQPACKET,
#endif /* ACE_HAS_LKSCTP */
						 dest.get_type(), IPPROTO_SCTP,	 true) == -1)
						 {
						 AAA_LOG((LM_ERROR, "%T |TRANSPORT| Diameter_ACE_Transport: IPPROTO_SCTP gethandle issue:%d IP_PROTOCOL:%d\n",
							 ((int)IPPROTO_SCTP), ((int)IP_PROTOCOL)));
							 return -1;
						 }

					 m_PendingStream->SetsctpInit(rto); //Added by anshul
				}

							 int rc = m_Connector.connect(m_PendingStream->Stream(),
						 dest, &tm, src, true);
					  //dest, &tm, ACE_Addr::sap_any, true);

				 delete[] name;

				 return AceAsynchResults(rc);
			}
			else
			{
				 AAA_LOG((LM_DEBUG, "%T |TRANSPORT|  Unable to send connecting m_PendingStream is already present \n"));
			}
			return (-1);
		}
		int Complete(DiameterTransportInterface<ACE_ADDRESS> *&iface) {
			iface = 0; 
         if (m_PendingStream) {
            int rc = m_Connector.complete(m_PendingStream->Stream());
            if (rc == 0) {
                return HandOverStream(iface, 
                                (DiameterTransportInterface<ACE_ADDRESS>*&)m_PendingStream);
            }
            else {
					   if( errno == ETIMEDOUT) {
							AAA_LOG((LM_ERROR, "%T |TRANSPORT| Connection ETIMEDOUT\n" ));
 						}
                return ((AceAsynchResults(rc) == 0) && (errno != ETIMEDOUT)) ? 0 :
                        ResetStream((DiameterTransportInterface<ACE_ADDRESS>*&)
                                    m_PendingStream);
            }
         }
         return (-1);
      }
      int Listen(int port, ACE_ADDRESS localAddr) {
         if (! m_PendingStream) {
             m_PendingStream = new Diameter_ACE_Transport
                 <ACE_ACCEPTOR, ACE_CONNECTOR, ACE_STREAM, ACE_ADDRESS, IP_PROTOCOL>;
             return AceAsynchResults(m_Acceptor.open(localAddr, true, AddressFamilyToUse(),
                                                     ACE_DEFAULT_BACKLOG, IP_PROTOCOL));
         }
			else
			{
				 AAA_LOG((LM_DEBUG, "%T |TRANSPORT| Already Listening on port :%d \n",port));
			}
         return (-1);
      }
      virtual int Accept(DiameterTransportInterface<ACE_ADDRESS> *&iface) {
         iface = 0;
         if (m_PendingStream) {
            ACE_Time_Value wait(ACCEPTOR_TIMEOUT, 0);
            int rc = m_Acceptor.accept(m_PendingStream->Stream(), 0, &wait); 
            if (rc == 0) {
                HandOverStream(iface, (DiameterTransportInterface<ACE_ADDRESS>*&)
                               m_PendingStream);
                m_PendingStream = new Diameter_ACE_Transport
                     <ACE_ACCEPTOR, ACE_CONNECTOR, ACE_STREAM, ACE_ADDRESS, IP_PROTOCOL>;
            }
            else if (AceAsynchResults(rc) < 0) {
                ResetStream((DiameterTransportInterface<ACE_ADDRESS>*&)
                            m_PendingStream);
                return (0);
            }
            return AceAsynchResults((rc == 0) ? 1 : rc);
         }
			else
			{
				AAA_LOG((LM_DEBUG, "%T |TRANSPORT| Unable to Accept m_PendingStream is NULL \n"));
			}
         return (-1);
      }

      int Send(void *data, size_t length) {
         return AceIOResults(m_Stream.send(data, length));
      }

      int Receive(void *data, size_t length, int timeout = 0) 
		{
         if (timeout > 0) 
			{
             ACE_Time_Value tm(0, timeout);
             return AceIOResults(m_Stream.recv(data, length, &tm));
         }
         return AceIOResults(m_Stream.recv(data, length));
      }
      int Close() {
         // close auxillary sockets
         m_Acceptor.close();

         // close data stream
         if (!AceAsynchResults(m_Stream.close_writer()) &&
             !AceAsynchResults(m_Stream.close_reader())) {
					//return (0);
         }
         return AceAsynchResults(m_Stream.close());
      }
      ACE_STREAM &Stream() {
         return m_Stream;
      }
      int TransportProtocolInUse() {
         return IP_PROTOCOL;
      }

   private:
      // template streams and factories
      ACE_STREAM     m_Stream;
      ACE_ACCEPTOR   m_Acceptor;
      ACE_CONNECTOR  m_Connector;

      // pending stream
      Diameter_ACE_Transport<ACE_ACCEPTOR,
                             ACE_CONNECTOR,
                             ACE_STREAM,
                             ACE_ADDRESS,
                             IP_PROTOCOL>
									  *m_PendingStream;

      int inline AceAsynchResults(int rc) {
         if (rc < 0) 
			{
             if ((errno == EWOULDBLOCK) || 
                 (errno == ETIME) ||
                 (errno == ETIMEDOUT) ||
                 (errno == EAGAIN)) 
				{ 
					 AAA_LOG((LM_ERROR, "%T |TRANSPORT| Async Transport Setup ERR: %s(%d)\n",
								 strerror(errno), errno));
                return (0);
				}
             AAA_LOG((LM_ERROR, "%T |TRANSPORT| PID:%d Async Transport Setup Reports: %s\n",strerror(errno)));
         }
         return (rc);
      }
      int inline AceIOResults(int rc) {
         if (rc < 0) 
			{
             if ((errno == EWOULDBLOCK) || 
                 (errno == ETIME) ||
                 (errno == EAGAIN)) {
 
					 AAA_LOG((LM_ERROR, "%T |TRANSPORT| Async IO Reports Err: %s(%d)\n",
								 strerror(errno), errno));
                return (0);
             }
             AAA_LOG((LM_ERROR, "%T |TRANSPORT| PID:%d Async IO Reports: %s\n", strerror(errno)));

             rc = (-1);
         }
         else if (rc == 0) {
             AAA_LOG((LM_ERROR, "%T |TRANSPORT| Async IO, peer has closed RC : %d\n", rc ));
             rc = (-1);
         }
         return (rc);
      }
      int inline ResetStream(DiameterTransportInterface<ACE_ADDRESS> *&stream) {
         delete stream;
         stream = NULL;
         return (-1);
      }
      int inline HandOverStream(DiameterTransportInterface<ACE_ADDRESS> *&dest,
                                DiameterTransportInterface<ACE_ADDRESS> *&src) {
         dest = src;
         src = NULL;
         return (1);
      }
      int inline AddressFamilyToUse() {
#ifdef ACE_HAS_IPV6
         return (DIAMETER_CFG_TRANSPORT()->use_ipv6) ? AF_INET6 : AF_INET;
#else /* ! ACE_HAS_IPV6 */
         return AF_INET;
#endif /* ! ACE_HAS_IPV6 */
      }
};

class Diameter_ACE_TransportAddress :
    public DiameterTransportAddress<ACE_INET_Addr>
{
   public:
      virtual int GetLocalAddresses(size_t &count,
                                    ACE_INET_Addr *&addrs) {
         return ACE::get_ip_interfaces
             (count, addrs);
      }
      virtual void *GetAddressPtr(ACE_INET_Addr &addr) {
#if defined (ACE_HAS_IPV6)
         if (addr.get_type() == AF_INET6) {
            sockaddr_in6 *in = (sockaddr_in6*)addr.get_addr();
            return in->sin6_addr.s6_addr;
         }
         else if (addr.get_type() == AF_INET) { 
#else
         if (addr.get_type() == AF_INET) { 
#endif
            sockaddr_in  *in = (sockaddr_in*)addr.get_addr();
            return &(in->sin_addr.s_addr);
         }
         return (NULL);
      }
      virtual int GetAddressSize(ACE_INET_Addr &addr) {
#if defined (ACE_HAS_IPV6)
          if (addr.get_type() == AF_INET6) {
             return sizeof(struct in6_addr);
          }
         else if (addr.get_type() == AF_INET) { 
#else
         if (addr.get_type() == AF_INET) { 
#endif
             return sizeof(struct in_addr);
         }
         return 0;
      }
};

class Diameter_IO_SigMask : public ACE_Event_Handler
{
    public:
       Diameter_IO_SigMask() {
          m_SigRegistrar.register_handler(SIGPIPE, this);
       }
       virtual int handle_signal(int signo,
                                 siginfo_t * = 0, 
                                 ucontext_t * = 0) {
           AAA_LOG((LM_ERROR, 
              "%T |TRANSPORT| SIGPIPE received, closing connection\n"));
#ifndef WIN32
           errno = EPIPE;
#endif
           return 0;
       }
   private:
       ACE_Sig_Handler m_SigRegistrar;
};

#endif 
