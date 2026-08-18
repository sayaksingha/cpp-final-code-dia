static const char *id = " @(#) $Id: aaa_route_table.cc,v 1.1.4.1.2.1.2.1 2018/05/14 23:24:33 anandhv Exp $";
//----------------------------------------------------------------------
// NAME
// aaa_route_table.cc
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
#include "aaa_route_table.h"
#include "aaa_log_facility.h"

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DiameterRouteServers::~DiameterRouteServers()
{
    while (! empty()) {
        DiameterRouteServerEntry *e = front();
        pop_front();
        delete e;
    }
}
    
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterRouteServers::Add(DiameterRouteServerEntry &e)
{
    Remove(e.Server());
    DiameterRouteServerList::iterator i;
    for (i = begin(); i != end(); i++) {
        if ((*i)->Metric() >= e.Metric()) {
            insert(i, &e);
            break;
        }
    }
    if (i == end()) {
        push_back(&e);
    }
    return (0);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DiameterRouteServerEntry *DiameterRouteServers::Lookup(std::string &server)
{
    DiameterRouteServerList::iterator i;
    for (i = begin(); i != end(); i ++) {
        if (server == (*i)->Server()) {
           return (*i);
        }
    }
    return (NULL);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DiameterRouteServerEntry *DiameterRouteServers::First()
{
    DiameterRouteServerEntry *e = front();
    return (e);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DiameterRouteServerEntry *DiameterRouteServers::Next(
    DiameterRouteServerEntry &prev)
{
    DiameterRouteServerList::iterator i;
    for (i = begin(); i != end(); i ++) 
	 {
       if (&prev == (*i)) 
		 {
           i ++;
           if (i != end()) 
			  {
               return (*i);
           }
           break;
       }
    }
    return (NULL);    
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterRouteServers::Remove(std::string &server)
{
    DiameterRouteServerList::iterator i;
    for (i = begin(); i != end(); i ++) {
       if (server == (*i)->Server()) {
           delete (*i);
           erase(i);
           return (1);
       }
    }
    return (0);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterRouteEntry::Add(DiameterRouteApplication &a)
{
    DiameterRouteAppIdMap *idMap;
    Remove(a.VendorId(), a.ApplicationId());
    DiameterRouteVendorIdMap::iterator x = m_Identifiers.find(a.VendorId());

    if (x == m_Identifiers.end()) 
	 {
        idMap = new DiameterRouteAppIdMap;
        m_Identifiers.insert(std::pair<int, DiameterRouteAppIdMap*>
             (a.VendorId(), idMap));
    }
    else {
        idMap = x->second;
    }
    idMap->insert(std::pair<int, DiameterRouteApplication*>
                  (a.ApplicationId(),
                   static_cast<DiameterRouteApplication*>(&a)));
    return (0);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DiameterRouteApplication *DiameterRouteEntry::Lookup(int appId, int vendorId)
{
    DiameterRouteVendorIdMap::iterator x = m_Identifiers.find(vendorId);
    if (x != m_Identifiers.end()) 
	 {
        DiameterRouteAppIdMap *id = x->second;
        DiameterRouteAppIdMap::iterator y = id->find(appId);
        return (y != id->end()) ? y->second : 0;
    }
    return (0);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DiameterRouteApplication *DiameterRouteEntry::First()
{
    DiameterRouteVendorIdMap::iterator x = m_Identifiers.begin();
    if (x != m_Identifiers.end()) {
        DiameterRouteAppIdMap *id = x->second;
        DiameterRouteAppIdMap::iterator y = id->begin();
        return (y != id->end()) ? y->second : 0;
    }
    return (0);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DiameterRouteApplication *DiameterRouteEntry::Next(DiameterRouteApplication &app)
{
    bool lookup = true;
    DiameterRouteVendorIdMap::iterator x = m_Identifiers.find(app.VendorId());
    for (; x != m_Identifiers.end(); x++) {
        DiameterRouteAppIdMap *id = x->second;
        DiameterRouteAppIdMap::iterator y = (lookup) ?
            id->find(app.ApplicationId()) : id->begin();
        for (y++; y != id->end(); y++) {
            return y->second;
        }
        lookup = false;
    }
    return (0);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterRouteEntry::Remove(int appId, int vendorId)
{
    DiameterRouteVendorIdMap::iterator x = m_Identifiers.find(vendorId);
    if (x != m_Identifiers.end()) {
       DiameterRouteAppIdMap *id = x->second;
       DiameterRouteAppIdMap::iterator y = id->find(appId);
       if (y != id->end()) {
           delete y->second;
           id->erase(y);
           if (id->empty()) {
               m_Identifiers.erase(x);
               delete id;
           }
           return (0);
        }
    }
    return (-1);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterRouteEntry::clear(void *userData)
{
    while (! m_Identifiers.empty()) {
        DiameterRouteVendorIdMap::iterator x = m_Identifiers.begin();
        DiameterRouteAppIdMap *id = x->second;
        while (! id->empty()) {
            DiameterRouteAppIdMap::iterator y = id->begin();
            DiameterRouteApplication *app = y->second;
            id->erase(y);
            delete app;
        }
        m_Identifiers.erase(x);
        delete id;
    }
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterRouteEntry::Dump(void *userData)
{
    AAA_LOG((LM_INFO, "%T |ROUTE|              Route  : Realm = %s, Action = %d, Redirect-Usage = %d\n", m_Realm.c_str(), m_Action, m_RedirectUsage));

    DiameterRouteVendorIdMap::iterator x = m_Identifiers.begin();
    for (; x != m_Identifiers.end(); x++) 
	 {
        DiameterRouteAppIdMap *id = x->second;
        DiameterRouteAppIdMap::iterator y = id->begin();
        for (; y != id->end(); y++) 
		  {
            DiameterRouteApplication *app = y->second;
            AAA_LOG((LM_INFO, "%T |ROUTE|                       Application Id=%d, Vendor=%d\n", app->ApplicationId(), app->VendorId()));
            DiameterRouteServerEntry *server = app->Servers().First();
            while (server) {
                AAA_LOG((LM_INFO, "%T |ROUTE|                          Server = %s, metric = %d\n", server->Server().c_str(), server->Metric()));
                server = app->Servers().Next(*server);
            }
        }
    }
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterRouteTable::Dump()
{
    AAA_LOG((LM_INFO, "%T |ROUTE|  Dumping Route Table\n"));
    AAA_LOG((LM_INFO, "%T |ROUTE|            Exp Time : %d\n", m_ExpireTime));
    m_Routes.Dump();
    if (m_DefaultRoute) {
        AAA_LOG((LM_INFO, "%T |ROUTE|      Default Route\n"));
        m_DefaultRoute->Dump(0);
    }
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterRouteEntry::DumpIntoFile(void *userData)
{

   TEXT  lFileName[256]="";
   FILE *lFilePointer;
   struct tm   *mtmStruct;
   timeval     mtimeval;
   gettimeofday(&mtimeval, NULL);
   mtmStruct = localtime(&(mtimeval.tv_sec));

   sprintf(lFileName, "/opt/wqr/var/Peer_Dump_File_%02d%02d%02d%02d%02d.txt",
         mtmStruct->tm_mday,
         mtmStruct->tm_mon+1,
         (mtmStruct->tm_year%100),
         mtmStruct->tm_hour,
         mtmStruct->tm_min);


   if ((lFilePointer = fopen(lFileName, "a")) != NULL)
   {
      fprintf(lFilePointer, " |ROUTE| Route  : Realm = %s, Action = %d, Redirect-Usage = %d\n",m_Realm.c_str(), m_Action, m_RedirectUsage);

      DiameterRouteVendorIdMap::iterator x = m_Identifiers.begin();
      for (; x != m_Identifiers.end(); x++)
      {
         DiameterRouteAppIdMap *id = x->second;
         DiameterRouteAppIdMap::iterator y = id->begin();
         for (; y != id->end(); y++)
         {
            DiameterRouteApplication *app = y->second;
            fprintf(lFilePointer," |ROUTE|                       Application Id=%d, Vendor=%d\n",app->ApplicationId(), app->VendorId());
            DiameterRouteServerEntry *server = app->Servers().First();
            while (server) {
               fprintf(lFilePointer," |ROUTE|                          Server = %s, metric = %d\n",server->Server().c_str(), server->Metric());
               server = app->Servers().Next(*server);
            }
         }
      }

      fclose(lFilePointer);
   }

}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterRouteTable::DumpIntoFile()
{
   TEXT  lFileName[256] ="";
   FILE *lFilePointer;
   struct tm   *mtmStruct;
   timeval     mtimeval;
   gettimeofday(&mtimeval, NULL);
   mtmStruct = localtime(&(mtimeval.tv_sec));

   sprintf(lFileName, "/opt/wqr/var/Peer_Dump_File_%02d%02d%02d%02d%02d.txt",
         mtmStruct->tm_mday,
         mtmStruct->tm_mon+1,
         (mtmStruct->tm_year%100),
         mtmStruct->tm_hour,
         mtmStruct->tm_min);


   if ((lFilePointer = fopen(lFileName, "r")) == NULL)
   {
      if ((lFilePointer = fopen(lFileName, "w")) != NULL)
      {
         fprintf(lFilePointer," |ROUTE|  Dumping Route Table\n");
         fprintf(lFilePointer," |ROUTE|            Exp Time : %d\n", m_ExpireTime);
         DumpIntoFile();
         if (m_DefaultRoute) {
            fprintf(lFilePointer," |ROUTE|      Default Route\n");
            m_DefaultRoute->Dump(0);
         }
      }
   }

   fclose(lFilePointer);
}
