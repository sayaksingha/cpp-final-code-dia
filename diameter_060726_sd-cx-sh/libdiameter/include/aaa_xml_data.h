// @(#) $Id: aaa_xml_data.h,v 1.1.4.1.2.1.2.2 2019/10/11 22:22:56 mohan Exp $
//---------------------------------------------------------------
// NAME : aaa_xml_data.h
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
#ifndef __AAA_XML_DATA_H__
#define __AAA_XML_DATA_H__

#include "aaa_data_defs.h"
#include "aaa_route_table.h"
#include "aaa_peer_table.h"
#include "aaa_host_id_table.h"
#include "aaa_xml_sax_parser.h"

class DiameterXMLConfigParser
{
   public:
      virtual ~DiameterXMLConfigParser() {
      }
      virtual void Load(AAA_Task &task, 
                        char *cfgfile);      
      virtual int ReLoad(AAA_Task &task, 
                        char *cfgfile);      
      virtual void dump();
};

class DiameterConfigValidation
{
   public:
      static bool IsApplicationIdSupported(diameter_unsigned32_t appId);
};

#endif // __AAA_XML_DATA_H__


