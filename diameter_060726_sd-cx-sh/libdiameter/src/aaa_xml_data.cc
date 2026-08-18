static const char *id = " @(#) $Id: aaa_xml_data.cc,v 1.1.4.1.2.1.2.20 2024/05/15 13:12:32 mram Exp $";
//----------------------------------------------------------------------
// NAME
// aaa_xml_data.cc
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
#include "aaa_xml_data.h"
#include "aaa_log_facility.h"
#include "aaa_peer_interface.h"

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlContentConvUInt32List :
  public OD_Utl_XML_ContentConv<std::list<diameter_unsigned32_t> >
{
  public:
     DiameterXmlContentConvUInt32List(OD_Utl_XML_Element *element = 0) :
         OD_Utl_XML_ContentConv<std::list<diameter_unsigned32_t> >(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  std::list<diameter_unsigned32_t> &arg) {
        arg.push_back(ACE_OS::atoi(ch));
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlContentConvStringList :
  public OD_Utl_XML_ContentConv<std::list<std::string> >
{
  public:
     DiameterXmlContentConvStringList(OD_Utl_XML_Element *element = 0) :
         OD_Utl_XML_ContentConv<std::list<std::string> >(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  std::list<std::string> &arg) {
        arg.push_back(std::string(ch));
     }
};

typedef OD_Utl_XML_ContentConvNull<diameter_unsigned32_t>
           DiameterXmlContentConvNull;
typedef OD_Utl_XML_RegisteredElement
           <std::list<diameter_unsigned32_t>, DiameterXmlContentConvUInt32List> 
            DiameterXmlUInt32ListElement;
typedef OD_Utl_XML_RegisteredElement
           <std::list<std::string>, DiameterXmlContentConvStringList> 
            DiameterXmlStringListElement;

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlVendorAppIdParser :
    public OD_Utl_XML_RegisteredElement
              <DiameterVendorSpecificIdLst, 
               OD_Utl_XML_ContentConvNull<DiameterVendorSpecificIdLst> > 
{
  public:
     DiameterXmlVendorAppIdParser(DiameterVendorSpecificIdLst &arg,
                              OD_Utl_XML_SaxParser &parser) :
         OD_Utl_XML_RegisteredElement
              <DiameterVendorSpecificIdLst,
               OD_Utl_XML_ContentConvNull<DiameterVendorSpecificIdLst> >
                  (arg, (char *)"vendor_specific_application_id", parser) {
     }
     virtual bool startElement(ACEXML_Attributes *atts) {
     	 if (! OD_Utl_XML_Element::startElement(atts)) {
     	 	 return false;
     	 }
         m_Id.authAppId = 0;
         m_Id.acctAppId = 0;
         m_Id.vendorId = 0;
         return true;
     }
     virtual bool endElement() {
         m_arg.push_back(m_Id);
     	 return OD_Utl_XML_Element::endElement();
     }
     DiameterDataVendorSpecificApplicationId &Get() {
     	 return m_Id;
     }

    private:
         DiameterDataVendorSpecificApplicationId m_Id;
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlAcctAppIdConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlAcctAppIdConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
         if (m_element->Parent()->Name() == std::string("configuration")) {
              DIAMETER_CFG_GENERAL()->acctAppIdLst.push_back(ACE_OS::atoi(ch));
         }
         else if (m_element->Parent()->Name() == std::string("vendor_specific_application_id")) {
              DiameterXmlVendorAppIdParser *vendorIdElm = 
                 (DiameterXmlVendorAppIdParser*)m_element->Parent();
              if (vendorIdElm->Get().authAppId == 0) {
                 vendorIdElm->Get().acctAppId = ACE_OS::atoi(ch);
              }
              else {
                 AAA_LOG((LM_ERROR,
                      "%T |XML| While adding acct-app-id, Vendor specific application id already has auth-app-id\n"));
                 throw;
              }
         }
         else {
             AAA_LOG((LM_ERROR, 
                  "%T |XML| acct app id has an invalid parent !!!\n"));
             throw;
         }
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlAuthAppIdConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlAuthAppIdConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
         if (m_element->Parent()->Name() == std::string("configuration")) {
              DIAMETER_CFG_GENERAL()->authAppIdLst.push_back(ACE_OS::atoi(ch));
         }
         else if (m_element->Parent()->Name() == std::string("vendor_specific_application_id")) {
              DiameterXmlVendorAppIdParser *vendorIdElm = 
                 (DiameterXmlVendorAppIdParser*)m_element->Parent();
              if (vendorIdElm->Get().acctAppId == 0) {
                 vendorIdElm->Get().authAppId = ACE_OS::atoi(ch);
              }
              else {
                 AAA_LOG((LM_ERROR,
                      "%T |XML| While adding auth-app-id, Vendor specific application id already has acct-app-id\n"));
                 throw;
              }
         }
         else {
             AAA_LOG((LM_ERROR, 
                  "%T |XML| auth app id has an invalid parent !!!\n"));
             throw;
         }
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlHostIdEntryParser :
    public OD_Utl_XML_RegisteredElement
              <diameter_unsigned32_t,
               OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> >
{
  public:
     DiameterXmlHostIdEntryParser(OD_Utl_XML_SaxParser &parser) :
         OD_Utl_XML_RegisteredElement
              <diameter_unsigned32_t,
               OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> >
                  (m_unused, (char *)"host_identity", parser) {
     }
     virtual bool startElement(ACEXML_Attributes *atts) {
       if (! OD_Utl_XML_Element::startElement(atts)) {
          return false;
       }
         ACE_NEW_NORETURN(m_hostId, DiameterHostIdData);
         return true;
     }
     virtual bool endElement() 
	  {
			if(1 == DIAMETER_HOST_ID_TABLE()->mReloadflag)
			{
				m_hostId->disable_host = DIAMETER_HOST_ID_TABLE()->mdisable_host;
					if (! DIAMETER_RELOAD_HOST_ID_TABLE()->Add(m_hostId)) {
						AAA_LOG((LM_INFO, "%T |XML| WARING !!! - Unable to add Reload host identity : %s\n",
									m_hostId->identity.c_str()));
					}
			}
			else
			{
				m_hostId->disable_host = DIAMETER_HOST_ID_TABLE()->mdisable_host;
				if (m_hostId->disable_host == 0)
					if (! DIAMETER_HOST_ID_TABLE()->Add(m_hostId)) {
						AAA_LOG((LM_INFO, "%T |XML| WARING !!! - Unable to add host identity : %s\n",
									m_hostId->identity.c_str()));
					}
			}
       return OD_Utl_XML_Element::endElement();
     }
     DiameterHostIdData *Get() {
       return m_hostId;
     }

  private:
     DiameterHostIdData *m_hostId;
     diameter_unsigned32_t m_unused;
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlRouteParser :
    public OD_Utl_XML_RegisteredElement
              <diameter_unsigned32_t, 
               OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> > 
{
  public:
     DiameterXmlRouteParser(char *name, OD_Utl_XML_SaxParser &parser) :
         OD_Utl_XML_RegisteredElement
              <diameter_unsigned32_t,
               OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> > 
                  (m_unused, name, parser),
                   m_route(NULL) {
     }
     virtual bool startElement(ACEXML_Attributes *atts) {
     	 if (! OD_Utl_XML_Element::startElement(atts)) {
     	 	 return false;
     	 }
         std::string empty("");
         ACE_NEW_NORETURN(m_route, DiameterRouteEntry(empty));
         return true;
     }
     virtual bool endElement() {
         if (Name() == std::string("route")) {
             DIAMETER_ROUTE_TABLE()->Add(*m_route);
         }
         else if (Name() == std::string("default_route")) {
             DIAMETER_ROUTE_TABLE()->DefaultRoute(*m_route);
         }
         else {
             AAA_LOG((LM_ERROR, 
                  "%T |XML| Route xml parser has an invalid name !!!\n"));
             delete m_route;
             throw;
         }
         m_route = NULL;
     	 return OD_Utl_XML_Element::endElement();
     }
     DiameterRouteEntry *Get() {
     	 return m_route;
     }

    private:
        DiameterRouteEntry *m_route;
        diameter_unsigned32_t m_unused;
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlRealmConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlRealmConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
         if ((m_element->Parent()->Name() == std::string("route")) ||
             (m_element->Parent()->Name() == std::string("default_route"))) {
              DiameterXmlRouteParser *rteElm = 
                  (DiameterXmlRouteParser*)m_element->Parent();
              rteElm->Get()->Realm() = ch;
         }
         else if (m_element->Parent()->Name() == std::string("host_identity")) {
              DiameterXmlHostIdEntryParser *hostElm =
                  (DiameterXmlHostIdEntryParser*)m_element->Parent();
              hostElm->Get()->realm = ch;
         }
         else {
             AAA_LOG((LM_ERROR, 
                  "%T |XML| realm has an invalid parent !!!\n"));
             throw;
         }
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlIdentityConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlIdentityConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlHostIdEntryParser *hostElm =
                 (DiameterXmlHostIdEntryParser*)m_element->Parent();
             hostElm->Get()->identity = ch;
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlTcpListenPortConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlTcpListenPortConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlHostIdEntryParser *hostElm =
                 (DiameterXmlHostIdEntryParser*)m_element->Parent();
             hostElm->Get()->tcp_listen_port = ACE_OS::atoi(ch);
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlSctpListenPortConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlSctpListenPortConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlHostIdEntryParser *hostElm =
                 (DiameterXmlHostIdEntryParser*)m_element->Parent();
             hostElm->Get()->sctp_listen_port = ACE_OS::atoi(ch);
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlAdvertisedHostnameConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlAdvertisedHostnameConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlHostIdEntryParser *hostElm =
                 (DiameterXmlHostIdEntryParser*)m_element->Parent();
             hostElm->Get()->advertised_hostname.push_back(std::string(ch));
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlPeerEntryParser :
    public OD_Utl_XML_RegisteredElement
              <diameter_unsigned32_t, 
               OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> > 
{
  public:
     DiameterXmlPeerEntryParser(AAA_Task &task, OD_Utl_XML_SaxParser &parser) :
         OD_Utl_XML_RegisteredElement
              <diameter_unsigned32_t,
               OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> > 
                  (m_unused, (char *)"peer", parser),
               m_task(task) {
     }
     virtual bool endElement() {
         DiameterPeerManager mngr(m_task);
         if (! mngr.Add(m_peerInfo.hostname,
                        m_peerInfo.port,
                        m_peerInfo.use_sctp,
								m_peerInfo.use_stack_identity,
                        m_peerInfo.tls_enabled,
                        0,
                        true,
								m_peerInfo.client,
								m_peerInfo.host_entry,
								m_peerInfo.host_port,
								m_peerInfo.realmname,
								m_peerInfo.msctprto.rto)) {   
             AAA_LOG((LM_INFO, "%T |XML| WARING !!! - Unable to add peer: %s\n", 
                     m_peerInfo.hostname.c_str()));
				  throw ACEXML_SAXException("Failed to add peer, exiting...\n");				 
         }
     	 return OD_Utl_XML_Element::endElement();
     }
     DiameterDataPeer &Get() {
     	 return m_peerInfo;
     }

  private:
     AAA_Task &m_task;
     DiameterDataPeer m_peerInfo;
     diameter_unsigned32_t m_unused;
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlHostnameConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlHostnameConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlPeerEntryParser *peerElm = 
                 (DiameterXmlPeerEntryParser*)m_element->Parent();
             peerElm->Get().hostname = ch;
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlRealmnameConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlRealmnameConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlPeerEntryParser *peerElm = 
                 (DiameterXmlPeerEntryParser*)m_element->Parent();
            peerElm->Get().realmname = ch;
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlPortConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlPortConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlPeerEntryParser *peerElm = 
                 (DiameterXmlPeerEntryParser*)m_element->Parent();
             peerElm->Get().port = ACE_OS::atoi(ch);
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlUseStackIdentityConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlUseStackIdentityConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlPeerEntryParser *peerElm = 
                 (DiameterXmlPeerEntryParser*)m_element->Parent();
             peerElm->Get().use_stack_identity = ACE_OS::atoi(ch);
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlsctpsrtoinitialConv :
   public DiameterXmlContentConvNull
{
   public:
      DiameterXmlsctpsrtoinitialConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
         }
      void content(const ACEXML_Char *ch,
            int start,
            int length,
            diameter_unsigned32_t &arg) {
         DiameterXmlPeerEntryParser *peerElm =
            (DiameterXmlPeerEntryParser*)m_element->Parent();
         peerElm->Get().msctprto.rto.srto_initial = ACE_OS::atoi(ch);
      }
};

class DiameterXmlsctpsrto_maxConv :
   public DiameterXmlContentConvNull
{
   public:
      DiameterXmlsctpsrto_maxConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
         }
      void content(const ACEXML_Char *ch,
            int start,
            int length,
            diameter_unsigned32_t &arg) {
         DiameterXmlPeerEntryParser *peerElm =
            (DiameterXmlPeerEntryParser*)m_element->Parent();
         peerElm->Get().msctprto.rto.srto_max = ACE_OS::atoi(ch);
      }
};

class DiameterXmlsctpsrto_minConv :
   public DiameterXmlContentConvNull
{
   public:
      DiameterXmlsctpsrto_minConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
         }
      void content(const ACEXML_Char *ch,
            int start,
            int length,
            diameter_unsigned32_t &arg) {
         DiameterXmlPeerEntryParser *peerElm =
            (DiameterXmlPeerEntryParser*)m_element->Parent();
         peerElm->Get().msctprto.rto.srto_min = ACE_OS::atoi(ch);
      }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlUseSctpConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlUseSctpConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlPeerEntryParser *peerElm = 
                 (DiameterXmlPeerEntryParser*)m_element->Parent();
             peerElm->Get().use_sctp = ACE_OS::atoi(ch);
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlTlsEnabledConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlTlsEnabledConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlPeerEntryParser *peerElm = 
                 (DiameterXmlPeerEntryParser*)m_element->Parent();
             peerElm->Get().tls_enabled = ACE_OS::atoi(ch);
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlClientConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlClientConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlPeerEntryParser *peerElm =
                 (DiameterXmlPeerEntryParser*)m_element->Parent();
             peerElm->Get().client = ACE_OS::atoi(ch);
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlHostentryConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlHostentryConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlPeerEntryParser *peerElm =
                 (DiameterXmlPeerEntryParser*)m_element->Parent();
             peerElm->Get().host_entry = ch;
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlHostportConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlHostportConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlPeerEntryParser *peerElm =
                 (DiameterXmlPeerEntryParser*)m_element->Parent();
             peerElm->Get().host_port = ACE_OS::atoi(ch);
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlRoleConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlRoleConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlRouteParser *rteElm = 
                 (DiameterXmlRouteParser*)m_element->Parent();
             rteElm->Get()->Action() = DIAMETER_ROUTE_ACTION(ACE_OS::atoi(ch));
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlAdvRouteConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlAdvRouteConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
            DiameterXmlRouteParser *rteElm = 
                 (DiameterXmlRouteParser*)m_element->Parent();
             rteElm->Get()->AdveriseRoute() = ACE_OS::atoi(ch)?true:false;
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlRouteApplicationParser :
    public OD_Utl_XML_RegisteredElement
              <diameter_unsigned32_t, 
               OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> > 
{
  public:
     DiameterXmlRouteApplicationParser(OD_Utl_XML_SaxParser &parser) :
         OD_Utl_XML_RegisteredElement
              <diameter_unsigned32_t,
               OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> > 
                  (m_unused, (char *)"application", parser),
                   m_routeApp(NULL) {
     }
     virtual bool startElement(ACEXML_Attributes *atts) {
     	 if (! OD_Utl_XML_Element::startElement(atts)) {
     	 	 return false;
     	 }
         ACE_NEW_NORETURN(m_routeApp, DiameterRouteApplication);
         return true;
     }
     virtual bool endElement() {
         DiameterXmlRouteParser *rteElm = 
                 (DiameterXmlRouteParser*)Parent();
         rteElm->Get()->Add(*m_routeApp);
         m_routeApp = NULL;
     	 return OD_Utl_XML_Element::endElement();
     }
     DiameterRouteApplication *Get() {
     	 return m_routeApp;
     }

    private:
        DiameterRouteApplication *m_routeApp;
        diameter_unsigned32_t m_unused;
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlVendorIdConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlVendorIdConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
         if (m_element->Parent()->Name() == std::string("configuration")) {
              DIAMETER_CFG_GENERAL()->vendor = ACE_OS::atoi(ch);
         }
         else if (m_element->Parent()->Name() == std::string("vendor_specific_application_id")) {
              DiameterXmlVendorAppIdParser *vendorIdElm = 
                 (DiameterXmlVendorAppIdParser*)m_element->Parent();
                 vendorIdElm->Get().vendorId = ACE_OS::atoi(ch);
         }
         else if (m_element->Parent()->Name() == std::string("application")) {
            DiameterXmlRouteApplicationParser *rteAppElm = 
                 (DiameterXmlRouteApplicationParser*)m_element->Parent();
             rteAppElm->Get()->VendorId() = ACE_OS::atoi(ch);
         }
         else {
             AAA_LOG((LM_ERROR, 
                  "%T |XML| vendor id has an invalid parent !!!\n"));
             throw;
         }
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlRteApplicationIdConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlRteApplicationIdConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
         DiameterXmlRouteApplicationParser *rteAppElm = 
               (DiameterXmlRouteApplicationParser*)m_element->Parent();
         diameter_unsigned32_t appId = ACE_OS::atoi(ch);
         if (DiameterConfigValidation::IsApplicationIdSupported(appId)) {
             rteAppElm->Get()->ApplicationId() = appId;
         }
         else {
             AAA_LOG((LM_ERROR,
                    "%T |XML| Configuration problem: Your advertising an app id in your route table for which your not advertising in your CER\n"));
            throw;
         }
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlRouteServerEntryParser :
  public OD_Utl_XML_RegisteredElement
             <diameter_unsigned32_t, 
              OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> > 
{
  public:
     DiameterXmlRouteServerEntryParser(OD_Utl_XML_SaxParser &parser) :
         OD_Utl_XML_RegisteredElement
              <diameter_unsigned32_t,
               OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> > 
                  (m_unused, (char *)"peer_entry", parser),
                   m_routeServer(NULL) {
     }
     virtual bool startElement(ACEXML_Attributes *atts) {
     	 if (! OD_Utl_XML_Element::startElement(atts)) {
             return false;
     	 }
         ACE_NEW_NORETURN(m_routeServer, DiameterRouteServerEntry);   
         return true;
     }
     virtual bool endElement() {
         DiameterXmlRouteApplicationParser *rteElm = 
                 (DiameterXmlRouteApplicationParser*)Parent();
         if (rteElm->Get()->Servers().Add(*m_routeServer)) {
             delete m_routeServer;
             throw;
         }
         m_routeServer = NULL;
     	 return OD_Utl_XML_Element::endElement();
     }
     DiameterRouteServerEntry *Get() {
     	 return m_routeServer;
     }

    private:
        DiameterRouteServerEntry *m_routeServer;
        diameter_unsigned32_t m_unused;
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlRteServerConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlRteServerConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
        DiameterXmlRouteServerEntryParser *rteServerElm = 
                (DiameterXmlRouteServerEntryParser*)m_element->Parent();
        rteServerElm->Get()->Server() = ch;
     }
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlRteServerMetricConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlRteServerMetricConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
        DiameterXmlRouteServerEntryParser *rteServerElm = 
               (DiameterXmlRouteServerEntryParser*)m_element->Parent();
        rteServerElm->Get()->Metric() = ACE_OS::atoi(ch);
     }
};

class DiameterXmlSessionTimeoutConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlSessionTimeoutConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
         if (m_element->Parent()->Name() == std::string("auth_sessions")) {
             DIAMETER_CFG_AUTH_SESSION()->sessionTm = ACE_OS::atoi(ch);
         }
         else if (m_element->Parent()->Name() == std::string("acct_sessions")) {
             DIAMETER_CFG_ACCT_SESSION()->sessionTm = ACE_OS::atoi(ch);
         }
         else {
             AAA_LOG((LM_ERROR, 
                  "%T |XML| session timeout has an invalid parent !!!\n"));
             throw;
         }
     }
};

class DiameterXmlRxSessionTimeoutConv :
   public DiameterXmlContentConvNull
{
  public:
     DiameterXmlRxSessionTimeoutConv(OD_Utl_XML_Element *element) :
         DiameterXmlContentConvNull(element) {
     }
     void content(const ACEXML_Char *ch,
                  int start,
                  int length,
                  diameter_unsigned32_t &arg) {
         if (m_element->Parent()->Name() == std::string("auth_sessions")) {
             DIAMETER_CFG_AUTH_SESSION()->rxsessionTm = ACE_OS::atoi(ch);
         }
         else if (m_element->Parent()->Name() == std::string("acct_sessions")) {
             DIAMETER_CFG_ACCT_SESSION()->rxsessionTm = ACE_OS::atoi(ch);
         }
         else {
             AAA_LOG((LM_ERROR,
                  "%T |XML| session timeout has an invalid parent !!!\n"));
             throw;
         }
     }
};
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlTxTimeoutConv :
	public DiameterXmlContentConvNull
{
	public:
		DiameterXmlTxTimeoutConv(OD_Utl_XML_Element *element) :
			DiameterXmlContentConvNull(element) {
			}
		void content(const ACEXML_Char *ch,
				int start,
				int length,
				diameter_unsigned32_t &arg) {
			if (m_element->Parent()->Name() == std::string("auth_sessions")) {
				DIAMETER_CFG_AUTH_SESSION()->txTimeout = ACE_OS::atoi(ch);
			}
			else if (m_element->Parent()->Name() == std::string("acct_sessions")) {
				DIAMETER_CFG_ACCT_SESSION()->txTimeout = ACE_OS::atoi(ch);
			}
			else {
				AAA_LOG((LM_DEBUG , "|XML| %T tx timeout has an invalid parent !!!"));
				throw;
			}
		}
};

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
class DiameterXmlUlrSessionRemoveConv :
	public DiameterXmlContentConvNull
{
	public:
		DiameterXmlUlrSessionRemoveConv(OD_Utl_XML_Element *element) :
			DiameterXmlContentConvNull(element) {
			}
		void content(const ACEXML_Char *ch,
				int start,
				int length,
				diameter_unsigned32_t &arg) {
			if (m_element->Parent()->Name() == std::string("auth_sessions")) {
				DIAMETER_CFG_AUTH_SESSION()->ulrSidRm = ACE_OS::atoi(ch);
			}
			else if (m_element->Parent()->Name() == std::string("acct_sessions")) {
				DIAMETER_CFG_ACCT_SESSION()->ulrSidRm = ACE_OS::atoi(ch);
			}
			else {
				AAA_LOG((LM_DEBUG , "|XML| %T tx timeout has an invalid parent !!!"));
				throw;
			}
		}
};

int DiameterXMLConfigParser::ReLoad(AAA_Task &task, char *cfgfile)
{
	DIAMETER_PEER_TABLE()->m_ReloadFlag   = 1;
	DIAMETER_HOST_ID_TABLE()->mReloadflag = 1;

	DiameterDataRoot &root = *DIAMETER_CFG_ROOT();


	OD_Utl_XML_SaxParser parserReload;

	unsigned int ltempcount = DIAMETER_CFG_RELOAD()->reloadCount;

	OD_Utl_XML_UInt32Element trans48(root.dynloadpeer.reloadCount,
			(char *)"reload_count", parserReload);

	try
	{
		parserReload.Load(cfgfile);
		if(DIAMETER_CFG_RELOAD()->reloadCount == ltempcount)
		{
			AAA_LOG((LM_INFO,"%T Diameter Config file is not Reloaded,Check Reload Count\n",""));
			return -1;
		}
		AAA_LOG((LM_INFO,"%T Diameter Config file is Reloading\n",""));
	}
	catch (OD_Utl_XML_SaxException &e)
	{
		e.Print();
		AAA_LOG((LM_INFO,"%T Err: Diameter Config file is not Reloaded\n",""));
		return -1;
	}
	catch (...)
	{
		AAA_LOG((LM_INFO,"%T Err: Diameter Config file is not Reloaded\n",""));
		return -1;
	}

	OD_Utl_XML_SaxParser parser;
	diameter_unsigned32_t m_unused;

	DiameterXmlHostIdEntryParser trans31(parser);

	OD_Utl_XML_UInt32Element trans54((ACE_UINT32&)DIAMETER_HOST_ID_TABLE()->mdisable_host,
			(char *)"disable_host", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlIdentityConv>
		trans32(m_unused, (char *)"identity", parser);
	/*OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlRealmConv>
	  trans33(m_unused, (char *)"realm", parser);*/
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlSctpListenPortConv>
		trans34(m_unused, (char *)"sctp_listen_port", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlTcpListenPortConv>
		trans35(m_unused, (char *)"tcp_listen_port", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlAdvertisedHostnameConv>
		trans36(m_unused, (char *)"advertised_hostname", parser);
	//	OD_Utl_XML_UInt32Element trans12((ACE_UINT32&)DIAMETER_PEER_TABLE()->ExpirationTime(),
	//			(char *)"expiration_time", parser);
	DiameterXmlPeerEntryParser trans13(task, parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlHostnameConv>
		trans14(m_unused, (char *)"hostname", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlUseSctpConv>
		trans15(m_unused, (char *)"use_sctp", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlPortConv>
		trans16(m_unused, (char *)"port", parser);
   OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlTlsEnabledConv>
		trans17(m_unused, (char *)"tls_enabled", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlClientConv>
		trans18(m_unused, (char *)"client", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlHostentryConv>
		trans19(m_unused, (char *)"host_entry", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlHostportConv>
		trans20(m_unused, (char *)"host_port", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlUseStackIdentityConv>
		trans37(m_unused, (char *)"use_stack_identity", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlRealmnameConv>
		trans41(m_unused, (char *)"realmname", parser);
	OD_Utl_XML_UInt32Element trans45((ACE_UINT32&)DIAMETER_PEER_TABLE()->AnswerToPeer(),
			(char *)"AnswerToPeer", parser);
	OD_Utl_XML_UInt32Element trans46((ACE_UINT32&)DIAMETER_PEER_TABLE()->TempDisconnection(),
			(char *)"TempDisconnection", parser);
	OD_Utl_XML_UInt32Element trans49((ACE_UINT32&)DIAMETER_PEER_TABLE()->ToSendDWR(),
			(char *)"send_dwr", parser);

        OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlsctpsrtoinitialConv>
                trans66(m_unused, (char *)"sctp_srto_initial", parser);
        OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlsctpsrto_maxConv>
                trans67(m_unused, (char *)"sctp_srto_max", parser);
        OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlsctpsrto_minConv>
                trans68(m_unused, (char *)"sctp_srto_min", parser);

	DiameterDataRoot2 &evr = *DIAMETER_CFG_EVR_ROOT();

   OD_Utl_XML_StringElement evr01(evr.evrinfo.evrinfostr,
         (char *)"evrinfo", parser);

	//diameter_unsigned32_t lPendingBacklogs;
	OD_Utl_XML_UInt32Element trans11(root.transport.max_pending_backlog,
			(char *)"max_pending_backlog", parser);

	OD_Utl_XML_UInt32Element sess01(root.session.maxSessions,
			(char *)"max_sessions", parser);

	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlSessionTimeoutConv>
		sess08(m_unused, (char *)"session_timeout", parser);

	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlTxTimeoutConv>
		sess11(m_unused, (char *)"tx_timeout", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlUlrSessionRemoveConv>
		sess13(m_unused, (char *)"ulr_session_remove", parser);
	
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,
		OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> >
			sess09(m_unused, (char *)"auth_sessions", parser);

	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,
		OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> >
			sess10(m_unused, (char *)"acct_sessions", parser);

	std::string lgp01, lgp02, lgp03, lgp04, lgp05 , lgp06, lgp07, lgp08;
	OD_Utl_XML_StringElement log01(lgp01, (char *)"debug", parser);
	OD_Utl_XML_StringElement log02(lgp02, (char *)"trace", parser);
	OD_Utl_XML_StringElement log03(lgp03, (char *)"info", parser);
	OD_Utl_XML_StringElement log06(lgp06, (char *)"critical", parser);
	OD_Utl_XML_StringElement log07(lgp07, (char *)"emergency", parser);
	OD_Utl_XML_StringElement log08(lgp08, (char *)"alert", parser);
	OD_Utl_XML_StringElement log04(lgp04, (char *)"console", parser);
	OD_Utl_XML_StringElement log05(lgp05, (char *)"syslog", parser);
	OD_Utl_XML_StringElement log09(root.log.logFile, (char *)"logfile", parser);
	OD_Utl_XML_StringElement log10(root.log.maxLogFileSize, (char *)"max_file_size", parser);
	OD_Utl_XML_StringElement log11(root.log.logFileSamplingInterval, (char *)"file_sampling_interval", parser);






	try {
		parser.Load(cfgfile);

		root.log.flags.reserved = 0;
		root.log.flags.debug = (lgp01 == std::string("enabled")) ? 1 : 0;
		root.log.flags.trace = (lgp02 == std::string("enabled")) ? 1 : 0;
		root.log.flags.info = (lgp03 == std::string("enabled")) ? 1 : 0;
		root.log.flags.critical = (lgp06 == std::string("enabled")) ? 1 : 0;
		root.log.flags.emergency = (lgp07 == std::string("enabled")) ? 1 : 0;
		root.log.flags.alert = (lgp08 == std::string("enabled")) ? 1 : 0;

		root.log.targets.reserved = 0;
		root.log.targets.console = (lgp04 == std::string("enabled")) ? 1 : 0;
		root.log.targets.syslog = (lgp05 == std::string("enabled")) ? 1 : 0;

	}
	catch (OD_Utl_XML_SaxException &e) {
		e.Print();
		throw;
	}
	catch (...) {
		throw;

	}
	return true;
}
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterXMLConfigParser::Load(AAA_Task &task, char *cfgfile)
{
	DiameterDataRoot &root = *DIAMETER_CFG_ROOT();

	OD_Utl_XML_SaxParser parser;
	diameter_unsigned32_t m_unused;

	// Root marker
	OD_Utl_XML_UInt32Element marker01(m_unused, (char *)"configuration", parser);

	// General Section    
	OD_Utl_XML_StringElement gen01(root.general.product, 
			(char *)"product", parser);
	OD_Utl_XML_UInt32Element gen02(root.general.version, 
			(char *)"version", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlVendorIdConv>
		gen03(m_unused, (char *)"vendor_id", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlAcctAppIdConv> 
		gen04(m_unused, (char *)"acct_application_id", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlAuthAppIdConv> 
		gen05(m_unused, (char *)"auth_application_id", parser);
	DiameterXmlUInt32ListElement gen06(root.general.supportedVendorIdLst,
			(char *)"supported_vendor_id", parser);
	DiameterXmlVendorAppIdParser gen07(root.general.vendorSpecificId, parser);

	OD_Utl_XML_StringElement gen08(root.general.node_id, 
			(char *)"node_id", parser);
	OD_Utl_XML_StringElement gen09(root.general.sync_ip, 
			(char *)"sync_ip", parser);
	OD_Utl_XML_UInt32Element gen10(root.general.sync_port, 
			(char *)"sync_port", parser);
	OD_Utl_XML_UInt32Element gen12(root.general.sync_task, 
			(char *)"sync_task", parser);
	OD_Utl_XML_UInt32Element gen13(root.general.sync_obj, 
			(char *)"sync_obj", parser);
	OD_Utl_XML_UInt32Element gen15(root.general.drop_duplicate_ULR_on_flooding,
			(char *)"drop_duplicate_ulr_On_flooding", parser);

	std::string lgen11; 
	OD_Utl_XML_StringElement gen11(lgen11, (char *)"sync_session", parser);

	std::string lgen14;
	OD_Utl_XML_StringElement gen14(lgen14, (char *)"sync_hbh", parser);

	// Transport Section
	OD_Utl_XML_UInt32Element trans04(root.transport.use_ipv6,
			(char *)"use_ipv6", parser);
	OD_Utl_XML_UInt32Element trans05(root.transport.watchdog_timeout, 
			(char *)"watchdog_timeout", parser);
	OD_Utl_XML_UInt32Element trans06(root.transport.reconnect_interval, 
			(char *)"reconnect_interval", parser);
	OD_Utl_XML_UInt32Element trans07(root.transport.reconnect_max,
			(char *)"reconnect_max", parser);
	OD_Utl_XML_UInt32Element trans08(root.transport.retx_interval, 
			(char *)"request_retransmission_interval", parser);
	OD_Utl_XML_UInt32Element trans09(root.transport.retx_max_count, 
			(char *)"max_request_retransmission_count", parser);
	OD_Utl_XML_UInt32Element trans10(root.transport.rx_buffer_size, 
			(char *)"receive_buffer_size", parser);
	OD_Utl_XML_UInt32Element trans11(root.transport.max_pending_backlog,
			(char *)"max_pending_backlog", parser);
	OD_Utl_XML_UInt32Element trans39(root.transport.listen_any_ip_addr,
			(char *)"listen_any_ip_addr", parser);

	OD_Utl_XML_UInt32Element trans40(root.transport.hbh_timeout,
			(char *)"hbh_timeout", parser);

	OD_Utl_XML_UInt32Element trans42(root.transport.retx_interval_flag,
			(char *)"retx_flag", parser);

	OD_Utl_XML_UInt32Element trans43(root.transport.retx_h2h_interval,
			(char *)"retx_h2h_interval", parser);
	OD_Utl_XML_UInt32Element trans47(root.dynloadpeer.dynamically_load_peer_flag,
			(char *)"dynamically_load_peer", parser);
	OD_Utl_XML_UInt32Element trans48(root.dynloadpeer.max_dwr_count,
			(char *)"max_dwr_count", parser);

	OD_Utl_XML_StringElement trans50(root.transport.route_record_host_name,
			(char *)"route_record_host_name", parser);

	OD_Utl_XML_StringElement trans51(root.transport.route_record_realm_name,
			(char *)"route_record_realm_name", parser);

	OD_Utl_XML_UInt32Element trans52(root.dynloadpeer.sendtopcrf,
			(char *)"sendtopcrf", parser);
	
	OD_Utl_XML_UInt32Element trans53(root.dynloadpeer.changelogs,
			(char *)"changelog", parser);

	OD_Utl_XML_UInt32Element trans56(root.dynloadpeer.reloadCount,
			(char *)"reload_count", parser);

	OD_Utl_XML_UInt32Element trans57(root.transport.asyncMsg,
			(char *)"asyncMsgFlag", parser);
	
	
	OD_Utl_XML_UInt32Element trans58(root.dynloadpeer.ebit,
			(char *)"process_ebit", parser);
	OD_Utl_XML_UInt32Element trans60(root.transport.sctp_init_max_attempts,
			(char *)"sctp_init_max_attempts", parser);

	OD_Utl_XML_UInt32Element trans61(root.transport.use_sentinel,
         (char *)"use_sentinel", parser);

	DiameterDataRoot2 &evr = *DIAMETER_CFG_EVR_ROOT();

	OD_Utl_XML_StringElement evr01(evr.evrinfo.evrinfostr,
			(char *)"evrinfo", parser);

	// Host Id table
	DiameterXmlHostIdEntryParser trans31(parser);

	OD_Utl_XML_UInt32Element trans54((ACE_UINT32&)DIAMETER_HOST_ID_TABLE()->mdisable_host,
			(char *)"disable_host", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlIdentityConv> 
		trans32(m_unused, (char *)"identity", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlRealmConv> 
		trans33(m_unused, (char *)"realm", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlSctpListenPortConv> 
		trans34(m_unused, (char *)"sctp_listen_port", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlTcpListenPortConv> 
		trans35(m_unused, (char *)"tcp_listen_port", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlAdvertisedHostnameConv> 
		trans36(m_unused, (char *)"advertised_hostname", parser);

	// Peer table
	OD_Utl_XML_UInt32Element trans12((ACE_UINT32&)DIAMETER_PEER_TABLE()->ExpirationTime(), 
			(char *)"expiration_time", parser);
	DiameterXmlPeerEntryParser trans13(task, parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlHostnameConv> 
		trans14(m_unused, (char *)"hostname", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlUseSctpConv> 
		trans15(m_unused, (char *)"use_sctp", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlPortConv> 
		trans16(m_unused, (char *)"port", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlTlsEnabledConv> 
		trans17(m_unused, (char *)"tls_enabled", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlClientConv>
		trans18(m_unused, (char *)"client", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlHostentryConv> 
		trans19(m_unused, (char *)"host_entry", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlHostportConv> 
		trans20(m_unused, (char *)"host_port", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlUseStackIdentityConv> 
		trans37(m_unused, (char *)"use_stack_identity", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlRealmnameConv> 
		trans41(m_unused, (char *)"realmname", parser);
	OD_Utl_XML_UInt32Element trans45((ACE_UINT32&)DIAMETER_PEER_TABLE()->AnswerToPeer(), 
			(char *)"AnswerToPeer", parser);
	OD_Utl_XML_UInt32Element trans46((ACE_UINT32&)DIAMETER_PEER_TABLE()->TempDisconnection(),
			(char *)"TempDisconnection", parser);
	OD_Utl_XML_UInt32Element trans49((ACE_UINT32&)DIAMETER_PEER_TABLE()->ToSendDWR(),
			(char *)"send_dwr", parser);

	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlsctpsrtoinitialConv>
		trans66(m_unused, (char *)"sctp_srto_initial", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlsctpsrto_maxConv>
		trans67(m_unused, (char *)"sctp_srto_max", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlsctpsrto_minConv>
		trans68(m_unused, (char *)"sctp_srto_min", parser);
	

	// Route table
	ACE_UINT32 transp_01 = 0;

	OD_Utl_XML_UInt32Element trans21(transp_01, (char *)"expire_time", parser);
	OD_Utl_XML_UInt32Element trans44(root.transport.ActiveDefPeerFlag, (char *)"def_peer_Active", parser); 
	DiameterXmlRouteParser trans22((char *)"route", parser);
	DiameterXmlRouteParser trans23((char *)"default_route", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlRoleConv> 
		trans24(m_unused, (char *)"role", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlRealmConv> 
		trans25(m_unused, (char *)"realm", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlAdvRouteConv> 
		trans38(m_unused, (char *)"advertise_route", parser);

	// Application table
	DiameterXmlRouteApplicationParser trans26(parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlRteApplicationIdConv> 
		trans27(m_unused, (char *)"application_id", parser);

	// Server entry
	DiameterXmlRouteServerEntryParser trans28(parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlRteServerConv> 
		trans29(m_unused, (char *)"server", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlRteServerMetricConv> 
		trans30(m_unused, (char *)"metric", parser);

	// Session management
	OD_Utl_XML_UInt32Element sess01(root.session.maxSessions,
			(char *)"max_sessions", parser);
	OD_Utl_XML_UInt32Element sess02(root.session.authSessions.stateful,
			(char *)"stateful", parser);
	OD_Utl_XML_UInt32Element sess03(root.session.authSessions.lifetimeTm,
			(char *)"lifetime_timeout", parser);
	OD_Utl_XML_UInt32Element sess04(root.session.authSessions.graceTm,
			(char *) "grace_period_timeout", parser);
	OD_Utl_XML_UInt32Element sess05(root.session.authSessions.abortRetryTm,
			(char *)"abort_retry_timeout", parser);
	OD_Utl_XML_UInt32Element sess06(root.session.acctSessions.recIntervalTm,
			(char *)"interim_interval", parser);
	OD_Utl_XML_UInt32Element sess07(root.session.acctSessions.realtime,
			(char *)"realtime", parser);

	OD_Utl_XML_StringElement err01(root.errCodeHdlr.allowErrorCodeStr, 
			(char *)"reset_err_code_list", parser);

	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlSessionTimeoutConv> 
		sess08(m_unused, (char *)"session_timeout", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlTxTimeoutConv>
           sess11(m_unused, (char *)"tx_timeout", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlUlrSessionRemoveConv>
           sess13(m_unused, (char *)"ulr_session_remove", parser);

	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  DiameterXmlRxSessionTimeoutConv>
      sess12(m_unused, (char *)"rx_session_timeout", parser);

	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  
		OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> > 
			sess09(m_unused, (char *)"auth_sessions", parser);
	OD_Utl_XML_RegisteredElement<diameter_unsigned32_t,  
		OD_Utl_XML_ContentConvNull<diameter_unsigned32_t> > 
			sess10(m_unused, (char *)"acct_sessions", parser);

	// logs
	std::string lgp01, lgp02, lgp03, lgp04, lgp05 , lgp06, lgp07, lgp08;
	OD_Utl_XML_StringElement log01(lgp01, (char *)"debug", parser);
	OD_Utl_XML_StringElement log02(lgp02, (char *)"trace", parser);
	OD_Utl_XML_StringElement log03(lgp03, (char *)"info", parser);
	OD_Utl_XML_StringElement log06(lgp06, (char *)"critical", parser);
	OD_Utl_XML_StringElement log07(lgp07, (char *)"emergency", parser);
	OD_Utl_XML_StringElement log08(lgp08, (char *)"alert", parser);
	OD_Utl_XML_StringElement log04(lgp04, (char *)"console", parser);
	OD_Utl_XML_StringElement log05(lgp05, (char *)"syslog", parser);
	OD_Utl_XML_StringElement log09(root.log.logFile, (char *)"logfile", parser);
	OD_Utl_XML_StringElement log10(root.log.maxLogFileSize, (char *)"max_file_size", parser);
	OD_Utl_XML_StringElement log11(root.log.logFileSamplingInterval, (char *)"file_sampling_interval", parser);

	try {
		parser.Load(cfgfile);

		// post setup for routing
		DIAMETER_ROUTE_TABLE()->ExpireTime(transp_01);

		// post parsing setup for logs
		root.log.flags.reserved = 0;
		root.log.flags.debug = (lgp01 == std::string("enabled")) ? 1 : 0;
		root.log.flags.trace = (lgp02 == std::string("enabled")) ? 1 : 0;
		root.log.flags.info = (lgp03 == std::string("enabled")) ? 1 : 0;
		root.log.flags.critical = (lgp06 == std::string("enabled")) ? 1 : 0;
		root.log.flags.emergency = (lgp07 == std::string("enabled")) ? 1 : 0;
		root.log.flags.alert = (lgp08 == std::string("enabled")) ? 1 : 0;

		root.log.targets.reserved = 0;
		root.log.targets.console = (lgp04 == std::string("enabled")) ? 1 : 0;
		root.log.targets.syslog = (lgp05 == std::string("enabled")) ? 1 : 0;

		/* Commented by Abhishek on 06-10-25, To always keep this enabled. 
       * root.general.sync_session = (lgen11 == std::string("enabled")) ? 1 : 0; 
		 * root.general.sync_hbh     = (lgen14 == std::string("enabled")) ? 1 : 0; 
       */
		root.general.sync_session = 1;
		root.general.sync_hbh     = 0;

		// post parsing setup for tx retries
		if (root.transport.retx_interval &&
				(root.transport.retx_interval > DIAMETER_ROUTER_MIN_RETX_INTERVAL)) {
			root.transport.retx_interval = DIAMETER_ROUTER_MIN_RETX_INTERVAL;
		}
		if (root.transport.retx_max_count &&
				(root.transport.retx_max_count > DIAMETER_ROUTER_MAX_RETX_COUNT)) {
			root.transport.retx_max_count = DIAMETER_ROUTER_MAX_RETX_COUNT;
		}

		if (root.transport.retx_max_count &&
				(root.transport.retx_h2h_interval < DIAMETER_H2H_MIN_RETX_INTERVAL )) {
			root.transport.retx_h2h_interval = DIAMETER_H2H_MIN_RETX_INTERVAL;
		}
		// buffer size validation
		if (root.transport.rx_buffer_size < MSG_COLLECTOR_MAX_MSG_LENGTH) {
			root.transport.rx_buffer_size = MSG_COLLECTOR_MAX_MSG_LENGTH;
		}
		else if (root.transport.rx_buffer_size >
				(MSG_COLLECTOR_MAX_MSG_LENGTH * MSG_COLLECTOR_MAX_MSG_BLOCK)) {
			root.transport.rx_buffer_size = MSG_COLLECTOR_MAX_MSG_LENGTH * (MSG_COLLECTOR_MAX_MSG_BLOCK/2);
		}

		if (! root.session.authSessions.stateful) {
			root.session.authSessions.stateful = DIAMETER_SESSION_STATE_MAINTAINED;
		}
		else {
			root.session.authSessions.stateful = DIAMETER_SESSION_NO_STATE_MAINTAINED;
		}

		this->dump();
	}
	catch (OD_Utl_XML_SaxException &e) {
		e.Print();
		throw;
	}
	catch (...) {
		throw;
	}
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterXMLConfigParser::dump()
{
	DiameterDataRoot &root = *DIAMETER_CFG_ROOT();

	AAA_LOG((LM_INFO, "%T |XML|                     Product : %s\n", 
				root.general.product.c_str()));
	AAA_LOG((LM_INFO, "%T |XML|                     Version : %d\n", 
				root.general.version));
	AAA_LOG((LM_INFO, "%T |XML|                   Vendor Id : %d\n", 
				root.general.vendor));

	DiameterApplicationIdLst *idList[] = { &root.general.supportedVendorIdLst,
		&root.general.authAppIdLst,
		&root.general.acctAppIdLst };
	char *label[] = { (char *)"Supported Vendor",
		(char *)"Auth Application",
		(char *)"Acct Application" };
	for (unsigned int i=0;
			i < sizeof(idList)/sizeof(DiameterApplicationIdLst*);
			i++) 
	{
		DiameterApplicationIdLst::iterator x = idList[i]->begin();

		for (; x != idList[i]->end(); x++) 
		{
			AAA_LOG((LM_INFO, "%T |XML|            %s : %d\n",
						label[i], *x));
		}
	}

	DiameterVendorSpecificIdLst::iterator n = 
		root.general.vendorSpecificId.begin();
	for (; n != root.general.vendorSpecificId.end(); n ++) {

		AAA_LOG((LM_INFO, "%T |XML|          Vendor Specific Id : "));
		if ((*n).vendorId > 0) {
			AAA_LOG((LM_INFO, "Vendor = %d, ", (*n)));
		}
		else {
			AAA_LOG((LM_INFO, "Vendor = --- "));
		}
		if ((*n).authAppId > 0) {
			AAA_LOG((LM_INFO, "Auth = %d ", (*n).authAppId));
		}
		else if ((*n).acctAppId > 0) {
			AAA_LOG((LM_INFO, "Acct = %d ", (*n).acctAppId));
		}
		AAA_LOG((LM_INFO, "%s\n", (((*n).authAppId == 0) && 
						((*n).acctAppId == 0)) ? "---" : ""));
	}

	AAA_LOG((LM_INFO, "%T |XML|                Sync Session : %s\n", 
				root.general.sync_session?"enabled":"disabled"));
	AAA_LOG((LM_INFO, "%T |XML|                    Sync Hbh : %s\n", 
				root.general.sync_hbh?"enabled":"disabled"));
	AAA_LOG((LM_INFO, "%T |XML|                     Node Id : %s\n", 
				root.general.node_id.c_str()));
	AAA_LOG((LM_INFO, "%T |XML|                     Sync IP : %s\n", 
				root.general.sync_ip.c_str()));
	AAA_LOG((LM_INFO, "%T |XML|                   Sync Port : %d\n", 
				root.general.sync_port));

	AAA_LOG((LM_INFO, "%T |XML|           Watch-Dog timeout : %d\n", 
				root.transport.watchdog_timeout));
	AAA_LOG((LM_INFO, "%T |XML|                    Use IPv6 : %d\n", 
				root.transport.use_ipv6));
	AAA_LOG((LM_INFO, "%T |XML|         Re-transmission Int : %d\n", 
				root.transport.retx_interval));
	AAA_LOG((LM_INFO, "%T |XML|            Max Re-trans Int : %d\n", 
				root.transport.retx_max_count));
	AAA_LOG((LM_INFO, "%T |XML|            Recv Buffer Size : %d\n", 
				root.transport.rx_buffer_size));

	// host id table
	DIAMETER_HOST_ID_TABLE()->Dump();

	// peer table
	DIAMETER_PEER_TABLE()->Dump();

	// route table
	DIAMETER_ROUTE_TABLE()->Dump();

	AAA_LOG((LM_INFO, "%T |XML|                    Max Sess : %d\n", 
				root.session.maxSessions));

	AAA_LOG((LM_INFO, "%T |XML|          Auth Stateful Auth : %s\n", 
				root.session.authSessions.stateful ? "stateful" : "stateless"));
	AAA_LOG((LM_INFO, "%T |XML|             Auth Session(T) : %d\n", 
				root.session.authSessions.sessionTm));
	AAA_LOG((LM_INFO, "%T |XML|            Auth Lifetime(T) : %d\n", 
				root.session.authSessions.lifetimeTm));
	AAA_LOG((LM_INFO, "%T |XML|               Auth Grace(T) : %d\n", 
				root.session.authSessions.graceTm));
	AAA_LOG((LM_INFO, "%T |XML|               Auth Abort(T) : %d\n", 
				root.session.authSessions.abortRetryTm));

	AAA_LOG((LM_INFO, "%T |XML|             Acct Session(T) : %d\n", 
				root.session.acctSessions.sessionTm));
	AAA_LOG((LM_INFO, "%T |XML|            Acct Interim Int : %d\n", 
				root.session.acctSessions.recIntervalTm));
	AAA_LOG((LM_INFO, "%T |XML|              Acct Real-Time : %d\n", 
				root.session.acctSessions.realtime));

	AAA_LOG((LM_INFO, "%T |XML|                   Debug Log : %s\n", 
				root.log.flags.debug ? "enabled" : "disabled"));
	AAA_LOG((LM_INFO, "%T |XML|                   Trace Log : %s\n", 
				root.log.flags.trace ? "enabled" : "disabled"));
	AAA_LOG((LM_INFO, "%T |XML|                    Info Log : %s\n", 
				root.log.flags.info ? "enabled" : "disabled"));
	AAA_LOG((LM_INFO, "%T |XML|                   Alert Log : %s\n", 
				root.log.flags.alert ? "enabled" : "disabled"));
	AAA_LOG((LM_INFO, "%T |XML|                Critical Log : %s\n", 
				root.log.flags.critical ? "enabled" : "disabled"));
	AAA_LOG((LM_INFO, "%T |XML|               Emergency Log : %s\n", 
				root.log.flags.emergency ? "enabled" : "disabled"));

	AAA_LOG((LM_INFO, "%T |XML|                 Console Log : %s\n", 
				root.log.targets.console ? "enabled" : "disabled"));
	AAA_LOG((LM_INFO, "%T |XML|                  Syslog Log : %s\n", 
				root.log.targets.syslog  ? "enabled" : "disabled"));

	AAA_LOG((LM_INFO, "%T |XML|                    Log File : %s\n",
				root.log.logFile.c_str()));
	AAA_LOG((LM_INFO, "%T |XML|               Max File Size : %s KB\n",
				root.log.maxLogFileSize.c_str()));
	AAA_LOG((LM_INFO, "%T |XML|      File Sampling interval : %s sec\n",
				root.log.logFileSamplingInterval.c_str()));
	AAA_LOG((LM_INFO, "%T |XML|             Re-Transmission : %s \n",
				root.transport.retx_interval_flag ? "enabled" : "disabled"));
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
bool DiameterConfigValidation::IsApplicationIdSupported(diameter_unsigned32_t appId)
{
	// Validate with acct app Id against what is advertised
	DiameterApplicationIdLst::iterator i;
	for (i = DIAMETER_CFG_GENERAL()->acctAppIdLst.begin();
			i != DIAMETER_CFG_GENERAL()->acctAppIdLst.end();
			i ++) 
	{
		if ((*i) == DIAMETER_RELAY_APPLICATION_ID) 
		{
			return (true);
		}
		else if ((*i) == appId) 
		{
			return (true);
		}
	}

	// Validate with auth app Id against what is advertised
	for (i = DIAMETER_CFG_GENERAL()->authAppIdLst.begin();
			i != DIAMETER_CFG_GENERAL()->authAppIdLst.end();
			i ++) 
	{
		if ((*i) == DIAMETER_RELAY_APPLICATION_ID) 
		{
			return (true);
		}
		else if ((*i) == appId) 
		{
			return (true);
		}
	}

	// Validate with vendor-specific-app-id againts what is advertised
	DiameterVendorSpecificIdLst::iterator y;
	for (y = DIAMETER_CFG_GENERAL()->vendorSpecificId.begin();
			y != DIAMETER_CFG_GENERAL()->vendorSpecificId.end();
			y ++) 
	{
		if (((*y).authAppId == DIAMETER_RELAY_APPLICATION_ID) ||
				((*y).acctAppId == DIAMETER_RELAY_APPLICATION_ID)) 
		{
			return (true);
		}

		if (((*y).authAppId != 0) && ((*y).authAppId == appId)) 
		{
			return (true);
		}
		else if (((*y).acctAppId != 0) && ((*y).acctAppId == appId)) 
		{
			return (true);
		}
	}

	return (false);
}
