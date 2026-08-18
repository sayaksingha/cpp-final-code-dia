//@(#) $Id: TdraConstDef.h,v 1.1.2.1.2.1 2019/04/12 00:09:54 anandhv Exp $
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
#include <iostream>
#include <string>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/http/status.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <fstream>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <list>
#include <bitset>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <sstream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <cassert>
#include <exception>
#include <mutex>
#include "Types.h"
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/regex.hpp>
#include "framework.h"
using namespace std;



//Added by Abhishek for pipeline
constexpr uint16_t TOTAL_BUCKETS = 2048; 
constexpr uint16_t BUCKET_MASK = TOTAL_BUCKETS - 1;

struct RedisKeys 
{
    char hKeyBuf[64];
    char zKeyBuf[64];
    std::size_t hLen = 0;
    std::size_t zLen = 0;
    char tagBuf[16];
    std::size_t tagLen = 0;

    std::string_view hKey() const { return {hKeyBuf, hLen}; }
    std::string_view zKey() const { return {zKeyBuf, zLen}; }
    std::string_view tag() const { return {tagBuf, tagLen}; }
};
