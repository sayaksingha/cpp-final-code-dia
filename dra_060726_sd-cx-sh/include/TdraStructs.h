//@(#) $Id: TdraStructs.h,v 1.1.2.1.2.3 2024/12/20 07:24:38 mrafi Exp $
//-----------------------------------------------------------------------------
// NAME           : :TdraLimits.h
//
// COPYRIGHT      : TSS -- Copyright (C) 2009 Tayana Software Solutions Pvt Ltd.,
//                  All rights reserved. No part of this computer program
//                  may be used or reproduced in any form by any
//                  means without prior written permission of
//                  Tayana Software Solutions Pvt Ltd.
//
// Originated     : 28/11/2017
// Project        : TSS DRA
// Path           :
// Comments       : 3GPP TS 29.061 and TS 29.212 Gx Interface - Release 11
// Used Files     :
// Modified Date  :
// Review By      :
//
//----------------------------------------------------------------------------

#ifndef INCL_DRA_STRUCTS_DEF_H
#define INCL_DRA_STRUCTS_DEF_H


//----------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <mutex>
#include <sys/stat.h>
#include "Types.h"

#ifdef T
#undef T
#endif

//#include <boost/regex.hpp>
#include "boost/regex.hpp"

#ifdef INCL_CTRACE_DEF_H
#undef INCL_CTRACE_DEF_H
#include "ctrace.h"
#endif




#include "Poco/SAX/SAXParser.h"
#include "Poco/SAX/ContentHandler.h"
#include "Poco/SAX/LexicalHandler.h"
#include "Poco/SAX/Attributes.h"
#include "Poco/SAX/Locator.h"
#include "Poco/Exception.h"


#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <map>
#include <list>
#include <iterator>
#include <chrono>
#include <ctime>
#include <time.h>
#include <fstream>
#include "TdraConstDef.h"

struct MsccInfo
{
	UINT64 mUsuTotal   = 0;
	UINT64 mUsuCurrent = 0;
	UINT64 mGsuTotal   = 0;
};

//Added by Abhishek for pipeline
/*struct __attribute__((packed)) RoutingSessionData {
    uint32_t node_id;
    uint32_t local_h2h;
    uint32_t orig_h2h;
    uint32_t op_code;
    char type[4];
    char source_name[64];
    char dest_name[64];

    void host_to_network() {
        node_id = htonl(node_id); local_h2h = htonl(local_h2h);
        orig_h2h = htonl(orig_h2h); op_code = htonl(op_code);
    }
    void network_to_host() {
        node_id = ntohl(node_id); local_h2h = ntohl(local_h2h);
        orig_h2h = ntohl(orig_h2h); op_code = ntohl(op_code);
    }
}; */

#endif  
