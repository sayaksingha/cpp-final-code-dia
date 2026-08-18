// @(#) $Id: Redis.h,v 1.1.4.11 2021/11/26 04:19:30 anandhv Exp $
//----------------------------------------------------------------------------
// NAME
// SmsBillingApi.h
//
// COPYRIGHT
// Tayana Software Solutions Pvt Ltd -- Copyright (C) 2006,
// All rights reserved. No part of this computer program
// may be used or reproduced in any form by any
// means without prior written permission of
// Tayana Software Solutions Pvt Ltd.
//
// CLASS TYPE
//
// DESCRIPTION
// This class is a library  class for applications
// InHandler Base class provides common API's for all application to perform
// SMS Billing, to Write and Read request for all kind of operations.
//
// Originated: Kothari Komal                                       14-NOV-2012
//----------------------------------------------------------------------------
#ifndef INCL_REDIS_H
#define INCL_REDIS_H

//#include "Types.h"
#include "framework.h"
#include <stdio.h>
#include <map>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <hiredis/async.h>
#include <hiredis/adapters/libevent.h>
#include <hiredis/hiredis.h>
#include "aaa_log_facility.h"
#include "GenericObject.h"
#include "DCCA_ConfigHandler.h"

#define REDIS_CFG_PATH_LEN 250
#define REDIS_HOSTNAME_LEN 20
#define REDIS_MIN_PORT_VAL 1
#define REDIS_MAX_PORT_VAL 65536

class Redis: public GenericObject
{
	public:
		Redis();
		~Redis();
	
		bool Init();	
		bool Init(redisContext * ctx, char* hostname, int port, int timeout);
		bool connect(const char *hostname, int port, int timeout);
//		bool isConnected();
		void disconnect();

		bool reConnect(redisContext*&);

		bool insert(std::string key, std::map<std::string, std::string> multipleKV, int, bool recnct=true);
		//bool insert(std::string data, int expiretime=0, bool recnct=true);
		bool insert(std::string data, std::string lListName, int expiretime=0, bool recnct=true);

		bool update(std::string key, std::map<std::string, std::string> multipleKV);
		//bool remove(std::string key);
		//bool removeOnTimeout(std::string key);
		//bool read(std::string key, std::map<std::string, std::string>& value);
		bool read(std::string key, std::map<std::string, std::string>& value,bool recnct=true);
		bool setExpiry(redisContext *&ctx, std::string key, int expiretime, bool recnct=true);
		bool remove(std::string key,bool recnct=true);
		bool removeOnTimeout(std::string key,bool recnct=true);
	private:	
		char 					mRedisCfgPath[REDIS_CFG_PATH_LEN];
		//redisContext* 		mRedisContextInsertDRA;
		redisContext* 		mRedisContextDRA;
		//redisContext* 		mRedisContextDeleteDRA;
		//redisContext* 		mRedisContextDeleteDRAOnTimeout;
		//redisContext* 		mRedisContextSelectDRA;
		char 					mRedisHostname[REDIS_HOSTNAME_LEN];
		int 					mRedisPort;
		int  					mRedisConnectionTimeout;
		
		/*ACE_RW_Mutex 	 	m_LockInsert;
		ACE_RW_Mutex 	 	m_LockSelect;
		ACE_RW_Mutex 	 	m_LockDelete;
		ACE_RW_Mutex 	 	m_LockDelTimeout;
		*/
};
#endif
