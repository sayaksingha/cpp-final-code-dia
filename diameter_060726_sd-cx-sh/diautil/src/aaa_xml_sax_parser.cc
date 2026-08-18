static const char *id = " @(#) $Id: aaa_xml_sax_parser.cc,v 1.1.4.1.2.1.2.2 2024/05/15 13:04:24 mram Exp $";
//----------------------------------------------------------------------
// NAME
// aaa_xml_sax_parser.cc
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
#include <string>
#include "framework.h"
#include <memory>
#include "aaa_xml_sax_parser.h"

//#if (ACE_MAJOR_VERSION == 5) && (ACE_MINOR_VERSION > 5)
#if (ACE_MAJOR_VERSION > 5)
#define OD_UTL_THROW_SPEC(X)
#else
#define OD_UTL_THROW_SPEC(X) ACE_THROW_SPEC(X)
#endif

class OD_UTL_XML_SAXHandler : 
  public ACEXML_DefaultHandler
{
  public:
     OD_UTL_XML_SAXHandler(const ACEXML_Char* name,
                           OD_Utl_XML_SaxParser &parser) :
        m_errorCount(0),
        m_fatalError(false),
        m_fileName(ACE::strnew (name)), 
        m_locator(NULL),
        m_parser(parser) {
     }
     virtual ~OD_UTL_XML_SAXHandler(void) {
        delete [] m_fileName;
     }

     // Methods inherit from ACEXML_ContentHandler.
//#if (ACE_MAJOR_VERSION == 5) && (ACE_MINOR_VERSION > 5)
/*#if (ACE_MAJOR_VERSION > 5)
     virtual void characters (const ACEXML_Char *ch,
                              size_t start,
                              size_t length ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
#else
     virtual void characters (const ACEXML_Char *ch,
                              int start,
                              int length ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
#endif*/

     virtual void characters (const ACEXML_Char *ch,
           size_t start,
           size_t length ACEXML_ENV_ARG_DECL){
        m_parser.characters(ch, start, length);
     }
     virtual void endDocument (ACEXML_ENV_SINGLE_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
         m_parser.endDocument();
     }
     virtual void endElement (const ACEXML_Char *namespaceURI,
                              const ACEXML_Char *localName,
                              const ACEXML_Char *qName ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
         m_parser.endElement(namespaceURI, localName, qName);
     }
     virtual void endPrefixMapping (const ACEXML_Char *prefix ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
     }  
     virtual void ignorableWhitespace (const ACEXML_Char *ch,
                                       int start,
                                       int length ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
     }
     virtual void processingInstruction (const ACEXML_Char *target,
                                         const ACEXML_Char *data ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
     }
     virtual void setDocumentLocator (ACEXML_Locator *locator) {
         m_locator = locator;
     }
     virtual void skippedEntity (const ACEXML_Char *name ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
     }
     virtual void startDocument (ACEXML_ENV_SINGLE_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
         m_parser.startDocument();
     }
     virtual void startElement (const ACEXML_Char *namespaceURI,
                                const ACEXML_Char *localName,
                                const ACEXML_Char *qName,
                                ACEXML_Attributes *atts ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) { 
         m_parser.startElement(namespaceURI, localName, qName, atts);
     }
     virtual void startPrefixMapping (const ACEXML_Char *prefix,
                                      const ACEXML_Char *uri ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
     }

     // *** Methods inherit from ACEXML_DTDHandler.
     virtual void notationDecl (const ACEXML_Char *name,
                                const ACEXML_Char *publicId,
                                const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
     }
     virtual void unparsedEntityDecl (const ACEXML_Char *name,
                                      const ACEXML_Char *publicId,
                                      const ACEXML_Char *systemId,
                                      const ACEXML_Char *notationName ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
     }

     // Methods inherit from ACEXML_EnitityResolver.
     virtual ACEXML_InputSource *resolveEntity (const ACEXML_Char *publicId,
                                                const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
         return (NULL);
     }

     // Methods inherit from ACEXML_ErrorHandler.
     virtual void error (ACEXML_SAXParseException &exception ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
         AAA_LOG ((LM_INFO, "Error %s: line: %d col: %d \n",
                    (m_locator->getSystemId() == 0 ? m_fileName : m_locator->getSystemId()),
                     m_locator->getLineNumber(),
                     m_locator->getColumnNumber()));
         exception.print();
         m_errorCount ++;
     }
     virtual void fatalError (ACEXML_SAXParseException &exception ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
         AAA_LOG ((LM_INFO, "Fatal error %s: line: %d col: %d \n",
                    (m_locator->getSystemId() == 0 ? m_fileName : m_locator->getSystemId()),
                     m_locator->getLineNumber(),
                     m_locator->getColumnNumber()));
         exception.print();
         m_fatalError = true;
     }
     virtual void warning (ACEXML_SAXParseException &exception ACEXML_ENV_ARG_DECL)
         OD_UTL_THROW_SPEC ((ACEXML_SAXException)) {
         AAA_LOG ((LM_INFO, "Warning %s: line: %d col: %d \n",
                    (m_locator->getSystemId() == 0 ? m_fileName : m_locator->getSystemId()),
                     m_locator->getLineNumber(),
                     m_locator->getColumnNumber()));
         exception.print();
     }

     // local methods
     int ErrorCount() {
         return m_errorCount;
     }
     bool FatalError() {
         return m_fatalError;
     }
  private:
     int m_errorCount;
     bool m_fatalError;
     ACEXML_Char* m_fileName;
     ACEXML_Locator* m_locator;
     OD_Utl_XML_SaxParser &m_parser;
};

void OD_Utl_XML_SaxParser::startDocument(ACEXML_ENV_SINGLE_ARG_DECL)
{
}

void OD_Utl_XML_SaxParser::endDocument(ACEXML_ENV_SINGLE_ARG_DECL)
{
}

 void OD_Utl_XML_SaxParser::startElement(const ACEXML_Char *namespaceURI,
                                         const ACEXML_Char *localName,
                                         const ACEXML_Char *qName,
                                         ACEXML_Attributes *atts ACEXML_ENV_ARG_DECL)
{
   OD_Utl_XML_ElementMap::iterator i = 
       m_elementMap.find(std::string(qName));
   if (i != m_elementMap.end()) {
       i->second->startElement(atts);
       m_currentElement = i->second;
   }
}

void OD_Utl_XML_SaxParser::characters(const ACEXML_Char *ch,
                                      int start,
                                      int length ACEXML_ENV_ARG_DECL)
{
   if (m_currentElement) {
       m_currentElement->characters(ch, start, length);
   }
}
                                      
void OD_Utl_XML_SaxParser::endElement(const ACEXML_Char *namespaceURI,
                                       const ACEXML_Char *localName,
                                       const ACEXML_Char *qName ACEXML_ENV_ARG_DECL)
{
   OD_Utl_XML_ElementMap::iterator i = 
       m_elementMap.find(std::string(qName));
   if (i != m_elementMap.end()) {
       i->second->endElement();
   }
   m_currentElement = NULL;
}

void OD_Utl_XML_SaxParser::Load(char* xmlFile)
{
   ACEXML_FileCharStream *fstm = NULL;
   if (xmlFile == NULL) {
       throw OD_Utl_XML_SaxException((char *)"No dictionary file specified");
   }

   fstm = new ACEXML_FileCharStream;
   if (fstm == NULL) {
       throw OD_Utl_XML_SaxException((char *)"Allocation failure");
   }
   
   if (fstm->open (xmlFile) != 0) 
   {
       std::string err = "Failed to open XML file: ";
       err += xmlFile;
       throw OD_Utl_XML_SaxException(err);
   }

	auto_ptr<ACEXML_DefaultHandler> handler
       (new OD_UTL_XML_SAXHandler(xmlFile, (*this)));

   if (handler.get() == NULL) {
       throw OD_Utl_XML_SaxException((char *)"Allocation failure");
   }

   ACEXML_Parser parser;
   ACEXML_InputSource input(fstm);

   parser.setContentHandler(handler.get());
   parser.setDTDHandler(handler.get());
   parser.setErrorHandler(handler.get());
   parser.setEntityResolver(handler.get());
    
   try {
      for (unsigned int passes = 0; passes < m_numPasses; passes ++) {
          parser.parse(&input ACEXML_ENV_ARG_NOT_USED);
      }
   }
   catch (ACEXML_SAXException &ex) {
       ex.print();
       throw OD_Utl_XML_SaxException((char *)"Parsing failure");
   }

   OD_UTL_XML_SAXHandler *h = static_cast<OD_UTL_XML_SAXHandler*>(handler.get());
   if (h->FatalError() || (h->ErrorCount() > 0)) {
       throw OD_Utl_XML_SaxException((char *)"Parsing failure");
   }       
}
