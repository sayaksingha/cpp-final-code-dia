// @(#) $Id: aaa_host_id_table.h,v 1.1.4.1.2.1.2.1 2019/10/11 22:16:53 mohan Exp $
//---------------------------------------------------------------
// NAME : aaa_host_id_table.h
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
#ifndef __AAA_HOST_ID_TABLE_H__
#define __AAA_HOST_ID_TABLE_H__

#include "ace/Singleton.h"

typedef struct
{
   std::string             identity;
   std::string             realm;
   diameter_unsigned32_t   tcp_listen_port;
   diameter_unsigned32_t   sctp_listen_port;
   std::list <std::string> advertised_hostname;
	int                     disable_host;
} DiameterHostIdData;

typedef std::list<DiameterHostIdData*> DiameterHostIdList;

class DiameterHostIdTable : private DiameterHostIdList
{
   public:
      DiameterHostIdTable() {
      }
      virtual ~DiameterHostIdTable() {
      }
      bool Add(DiameterHostIdData *e) 
		{
          ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
			 //Check if already exists in the list before adding into the list -- Mohan
          push_back(e);
          return true;
      }
      DiameterHostIdData *Lookup(std::string &hostname) 
		{
          ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
          DiameterHostIdList::iterator i;
          for (i = begin(); i != end(); i++) {
              //
              // Warning: This is a case in-sensitive lookup which may not
              //          be generally appropriate if we consider FQDN as
              //          a non ascii value.
              //
              // Deprecated:
              //  if ((*i)->identity == hostname) {
              //
              if (! strcasecmp((*i)->identity.c_str(), hostname.c_str())) {
                  return (*i);
              }
          }
          return (NULL);
      }
      DiameterHostIdData *Remove(std::string &hostname) 
		{
          ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
          DiameterHostIdList::iterator i;
          for (i = begin(); i != end(); i++) {
              //
              // Warning: This is a case in-sensitive lookup which may not
              //          be generally appropriate if we consider FQDN as
              //          a non ascii value.
              //
              // Deprecated:
              //  if ((*i)->identity == hostname) {
              //
              if (! strcasecmp((*i)->identity.c_str(), hostname.c_str())) {
                  erase(i);
                  return (*i);
              }
          }
          return (NULL);
      }
      DiameterHostIdData *First() {
          ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
          return (! empty()) ? front() : NULL;
      }
      DiameterHostIdData *Next(DiameterHostIdData *e) 
		{
          ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
          DiameterHostIdList::iterator i;
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
              DiameterHostIdData *e = front();
              pop_front();
              delete e;
          }
      }
      void Dump() {
          AAA_LOG((LM_INFO, "%T HOST_TABLE  Dumping Host Identity Table\n"));

			 DiameterHostIdList::iterator i;
			 for (i = begin(); i != end(); i++) {
				 AAA_LOG((LM_INFO, "%T HOST_TABLE                Host  : Identity = %s, Realm = %s\n"
							 "%T HOST_TABLE                        TCP Listen = %d, SCTP Listen = %d\n",
							 (*i)->identity.c_str(), (*i)->realm.c_str(), (*i)->tcp_listen_port, (*i)->sctp_listen_port));

				 std::list<std::string>::iterator it =
					 (*i)->advertised_hostname.begin();
				 for (; it != (*i)->advertised_hostname.end(); it++)
				 {
					 AAA_LOG((LM_INFO, "%T HOST_TABLE                        Hostnames Used = %s\n", (*it).c_str()));
				 }
          }
      }

   private:
      ACE_RW_Mutex m_Lock;
	public : 
		int mReloadflag   = 0;
		int mdisable_host = 0;
};


class DiameterReLoadHostIdTable : private DiameterHostIdList
{
   public:
      DiameterReLoadHostIdTable() {
      }
      virtual ~DiameterReLoadHostIdTable() {
      }
      bool Add(DiameterHostIdData *e) 
		{
          ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
			 //Check if already exists in the list before adding into the list -- Mohan
          push_back(e);
          return true;
      }
      DiameterHostIdData *Lookup(std::string &hostname) 
		{
          ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
          DiameterHostIdList::iterator i;
          for (i = begin(); i != end(); i++) {
              //
              // Warning: This is a case in-sensitive lookup which may not
              //          be generally appropriate if we consider FQDN as
              //          a non ascii value.
              //
              // Deprecated:
              //  if ((*i)->identity == hostname) {
              //
              if (! strcasecmp((*i)->identity.c_str(), hostname.c_str())) {
                  return (*i);
              }
          }
          return (NULL);
      }
      DiameterHostIdData *Remove(std::string &hostname) 
		{
          ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
          DiameterHostIdList::iterator i;
          for (i = begin(); i != end(); i++) {
              //
              // Warning: This is a case in-sensitive lookup which may not
              //          be generally appropriate if we consider FQDN as
              //          a non ascii value.
              //
              // Deprecated:
              //  if ((*i)->identity == hostname) {
              //
              if (! strcasecmp((*i)->identity.c_str(), hostname.c_str())) {
                  erase(i);
                  return (*i);
              }
          }
          return (NULL);
      }
      DiameterHostIdData *First() {
          ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
          return (! empty()) ? front() : NULL;
      }
      DiameterHostIdData *Next(DiameterHostIdData *e) 
		{
          ACE_Read_Guard<ACE_RW_Mutex> guard(m_Lock);
          DiameterHostIdList::iterator i;
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
              DiameterHostIdData *e = front();
              pop_front();
              delete e;
          }
	   }
		void Clearall() {
          ACE_Write_Guard<ACE_RW_Mutex> guard(m_Lock);
          while (! empty()) {
              pop_front();
          }
      }
      void Dump() {
          AAA_LOG((LM_INFO, "%T HOST_TABLE  Dumping Host Identity Table\n"));

			 DiameterHostIdList::iterator i;
			 for (i = begin(); i != end(); i++) {
				 AAA_LOG((LM_INFO, "%T HOST_TABLE                Host  : Identity = %s, Realm = %s\n"
							 "%T HOST_TABLE                        TCP Listen = %d, SCTP Listen = %d\n",
							 (*i)->identity.c_str(), (*i)->realm.c_str(), (*i)->tcp_listen_port, (*i)->sctp_listen_port));

				 std::list<std::string>::iterator it =
					 (*i)->advertised_hostname.begin();
				 for (; it != (*i)->advertised_hostname.end(); it++)
				 {
					 AAA_LOG((LM_INFO, "%T HOST_TABLE                        Hostnames Used = %s\n", (*it).c_str()));
				 }
          }
      }

   private:
      ACE_RW_Mutex m_Lock;
};

typedef ACE_Singleton<DiameterHostIdTable, ACE_Recursive_Thread_Mutex> DiameterHostIdTable_S;
#define DIAMETER_HOST_ID_TABLE() DiameterHostIdTable_S::instance()

typedef ACE_Singleton<DiameterReLoadHostIdTable, ACE_Recursive_Thread_Mutex> DiameterReLoadHostIdTable_S;
#define DIAMETER_RELOAD_HOST_ID_TABLE() DiameterReLoadHostIdTable_S::instance()

#endif /* __AAA_HOST_ID_TABLE_H__ */
