// @(#) $Id: diameter_cc_parser.h,v 1.1.2.1.2.2 2018/07/04 23:08:25 anandhv Exp $
//---------------------------------------------------------------
// NAME : diameter_cc_parser.h
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
#ifndef __DIAMETER_CC_PARSER_H__
#define __DIAMETER_CC_PARSER_H__

#include <utility>
#include <vector>
#include <cmath>
#include <atomic>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include "ace/Singleton.h"
#include "diameter_api.h"
#include "gx/include/CCRequest.h"
#include "gx/include/CCAnswer.h"
#include "gx/include/RARequest.h"
#include "gx/include/RAAnswer.h"
#include "ro/include/CCRequest.h"
#include "ro/include/CCAnswer.h"
#include "ro/include/RARequest.h"
#include "ro/include/RAAnswer.h"
#include "sy/include/SLRequest.h"

const diameter_unsigned32_t CCApplicationId = 4;
const AAACommandCode CC_CommandCode = 272;

enum {
  CC_TYPE_INITIAL_REQUEST = 1,
  CC_TYPE_UPDATE_REQUEST,
  CC_TYPE_TERMINATION_REQUEST,
  CC_TYPE_EVENT_REQUEST,
  CC_TYPE_RA_REQUEST,	
  CC_TYPE_AS_REQUEST,
  CC_TYPE_SY_REQUEST
};

enum {
  SL_TYPE_INITIAL_REQUEST = 0,
  SL_TYPE_INTERMEDIATE_REQUEST,
};

enum {
  CC_ACTION_DIRECT_DEBITING = 0,
  CC_ACTION_REFUND_ACCOUNT,
  CC_ACTION_CHECK_BALANCE,
  CC_ACTION_PRICE_ENQUIRY
};

typedef enum {
  CREDIT_CONTROL_FAILURE_HANDLING_TERMINATE = 0,
  CREDIT_CONTROL_FAILURE_HANDLING_CONTINUE = 1,
  CREDIT_CONTROL_FAILURE_HANDLING_RETRY_AND_TERMINATE = 2
} CreditControlFailureHandlingEnum;

typedef enum {
  DIRECT_DEBITING_FAILURE_HANDLING_TERMINATE_OR_BUFFER = 0,
  DIRECT_DEBITING_FAILURE_HANDLING_CONTINUE = 1
} DirectDebitingFailureHandlingEnum;

class SpinLock
{
public:
    void lock()
    {
        while(lck.test_and_set(std::memory_order_acquire))
        {}
    }
 
    void unlock()
    {
        lck.clear(std::memory_order_release);
    }
 
private:
    std::atomic_flag lck = ATOMIC_FLAG_INIT;
};

typedef struct {
  std::atomic<unsigned int> currrentSessions = {0};
  SpinLock lock;
  //std::condition_variable cv;
  //std::mutex   threadMutex;	
  //bool processing = false;	
  //bool busy = false;
  //chrono::time_point<chrono::high_resolution_clock> lastUpdate(chrono::high_resolution_clock::now());		
} DiameterSessionInfo;

typedef ACE_Singleton < DiameterSessionInfo, ACE_Null_Mutex > DiameterSessionInfo_S;

#define DIAMETER_SESSION_INFO() (DiameterSessionInfo_S::instance())

#endif //__DIAMETER_CC_PARSER_H__
