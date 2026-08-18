// @(#) $Id: Redis.cc,v 1.1.4.13 2021/11/26 04:19:30 anandhv Exp $
//----------------------------------------------------------------------------
// NAME
// Redis.cc
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
// Originated: Raghu DV                                        18-APR-2018
//----------------------------------------------------------------------------
#include "Redis.h"
#include <functional>
#include <pthread.h> 												//TBC-AP


//----------------------------------------------------------------------
// METHOD      : ReadConfig
// DESCRIPTION : Read Reis releated configurations
// PARAMETERS  :
// RETURN      : UINT32
//----------------------------------------------------------------------
Redis::Redis()
{
     mRedisContextDRA 				= NULL;
}
//----------------------------------------------------------------------
// METHOD      : ReadConfig
// DESCRIPTION : Read Reis releated configurations
// PARAMETERS  :
// RETURN      : UINT32
//----------------------------------------------------------------------
Redis::~Redis()
{
	disconnect();
}

//----------------------------------------------------------------------
// METHOD      : Init
// DESCRIPTION : Initialize Redis context
// PARAMETERS  : None
// RETURN      : UINT32
//----------------------------------------------------------------------
bool Redis::Init()
{
   strcpy(mRedisHostname,  (char*)DIAMETER_CFG_GENERAL()->sync_ip.c_str());
   mRedisPort = DIAMETER_CFG_GENERAL()->sync_port;
   mRedisConnectionTimeout = 10;

   if(false == this->connect(mRedisHostname, mRedisPort, mRedisConnectionTimeout))
   {
      AAA_LOG((LM_CRITICAL, "%T |SYNC_REDIS| Redis connection failed\n"));
      //return false;
   }
	else
	{
      AAA_LOG((LM_INFO, "%T |SYNC_REDIS| Redis connection established\n"));
	}
   return true;
}

//----------------------------------------------------------------------
// METHOD      : Init
// DESCRIPTION : Initialize Redis context
// PARAMETERS  : None
// RETURN      : UINT32
//----------------------------------------------------------------------
bool Redis::Init(redisContext * ctx, char* hostname, int port, int timeout)
{
	strcpy(mRedisHostname, hostname);
	mRedisPort = port;
	mRedisConnectionTimeout = timeout;

	if(false == this->connect(hostname, port, timeout))
	{
		AAA_LOG((LM_CRITICAL, "%T |SYNC_REDIS| Redis connection failed\n"));
		return false;
	}
	else
	{
      AAA_LOG((LM_INFO, "%T |SYNC_REDIS| Redis connection established\n"));
	}
	return true;
}
//----------------------------------------------------------------------
// METHOD      : GetNextSmIdSeq
// DESCRIPTION : Connect to redis server
// PARAMETERS  : 
// RETURN      : 
//----------------------------------------------------------------------
bool Redis::connect(const char *hostname, int port, int timeout)
{
	struct timeval lTimeout = { timeout, 0 }; 
	
	mRedisContextDRA = redisConnectWithTimeout(hostname, port, lTimeout);
	
	if (mRedisContextDRA == NULL || mRedisContextDRA->err) 
	{
		if (mRedisContextDRA) 
		{
			AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Connection error: %s\n", mRedisContextDRA->errstr));
			redisFree(mRedisContextDRA);
		} 
		else 
		{
			AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Connection error: can't allocate redis context\n"));
		}
		
		mRedisContextDRA= NULL;
		return false;
	}
	
	if ( DCCA_CONFIG_HDLR()->mRedisPasswd.compare("") != 0) 
	{
		if ( DCCA_CONFIG_HDLR()->mRedisUserName.compare("") == 0)
		{
			AAA_LOG((LM_INFO, "%T |SYNC_REDIS| Authorizing Connection using only pwd.\n"));
			redisReply *reply; 
			reply = (redisReply*)redisCommand(mRedisContextDRA, "AUTH %s", DCCA_CONFIG_HDLR()->mRedisPasswd.c_str()); 
			
			if(reply != NULL)
				freeReplyObject(reply);
		}
		else
		{
			AAA_LOG((LM_INFO, "%T |SYNC_REDIS| Authorizing Connection using both username and pwd.\n"));
			redisReply *reply; 
			reply = (redisReply*)redisCommand(mRedisContextDRA, "AUTH %s %s", DCCA_CONFIG_HDLR()->mRedisUserName.c_str(), DCCA_CONFIG_HDLR()->mRedisPasswd.c_str()); 
			
			if(reply != NULL)
				freeReplyObject(reply);
		}
	}

	AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Connection Successfull\n"));
	return true;
}
//----------------------------------------------------------------------
// METHOD      : disconnect
// DESCRIPTION : Free the redis context
// PARAMETERS  : 
// RETURN      : 
//----------------------------------------------------------------------
void Redis::disconnect()
{
	if(NULL != mRedisContextDRA)
		redisFree(mRedisContextDRA);
	mRedisContextDRA = NULL;
}
//----------------------------------------------------------------------
// METHOD      : ReConnected
// DESCRIPTION : 
// PARAMETERS  :
// RETURN      :
//----------------------------------------------------------------------
bool Redis::reConnect(redisContext*& ctx )
{
	struct timeval lTimeout = { mRedisConnectionTimeout, 0 };
	
	if( NULL != ctx) 
   {
		redisFree(ctx);
		ctx=NULL;
	}

	ctx = redisConnectWithTimeout(mRedisHostname, mRedisPort ,lTimeout);
	
	if (ctx == NULL || ctx->err) 
	{
		if (ctx) 
		{
			AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Re-Connection error: %s\n", ctx->errstr));
			redisFree(ctx);
			ctx = NULL;
		} 
		else 
		{
			AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Re-Connection error: can't allocate redis context\n"));
		}
		return false;
	}

	if ( DCCA_CONFIG_HDLR()->mRedisPasswd.compare("") != 0) 
	{
		if ( DCCA_CONFIG_HDLR()->mRedisUserName.compare("") == 0)
		{
			AAA_LOG((LM_INFO, "%T |SYNC_REDIS| Authorizing Connection using only pwd.\n"));
			redisReply *reply; 
			reply = (redisReply*)redisCommand(mRedisContextDRA, "AUTH %s", DCCA_CONFIG_HDLR()->mRedisPasswd.c_str()); 
			
			if(reply != NULL)
				freeReplyObject(reply);
		}
		else
		{
			AAA_LOG((LM_INFO, "%T |SYNC_REDIS| Authorizing Connection using both username and pwd.\n"));
			redisReply *reply; 
			reply = (redisReply*)redisCommand(mRedisContextDRA, "AUTH %s %s", DCCA_CONFIG_HDLR()->mRedisUserName.c_str(), DCCA_CONFIG_HDLR()->mRedisPasswd.c_str()); 
			
			if(reply != NULL)
				freeReplyObject(reply);
		}
	}

	return true;
}

//----------------------------------------------------------------------
// METHOD      : isConnected
// DESCRIPTION : Free the redis context
// PARAMETERS  :
// RETURN      :
//----------------------------------------------------------------------
/*
bool Redis::isConnected()
{
   if(NULL != mRedisContextDRA)
		return true;
	return false;


}
*/
//----------------------------------------------------------------------
// METHOD      : Inser hash multiple set 
// DESCRIPTION : Insert multiple KV. 
// PARAMETERS  : 
// RETURN      : 
//----------------------------------------------------------------------
bool Redis::insert(std::string key, std::map<std::string, std::string> multipleKV, int expiretime, bool recnct) 
{
	redisReply  *reply =NULL;
	std::string command("HMSET ");
	bool        lInsertedFlag = true;
	

	command.append(key);

	for (auto it = multipleKV.begin(); it != multipleKV.end(); ++it)
		command.append(" " +it->first + " " + it->second);
	
	{ //TBC protected block -----------NKS
	
		//ACE_Write_Guard<ACE_RW_Mutex> guard(m_LockInsert);
	

		if(mRedisContextDRA == NULL) 
		{
			if(this->reConnect(mRedisContextDRA))
			{
				AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Re-connected\n"));
			}
			else
			{
				return false;
			}
		}

		reply = (redisReply * )redisCommand(mRedisContextDRA,command.c_str());

		if ( reply != NULL)
		{
			if(reply->type != REDIS_REPLY_STATUS)
			{
				AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| HMSET Error: %s, CMD:%s\n", reply->str, command.c_str()));
				freeReplyObject(reply);
				return false;
			}
			
			freeReplyObject(reply);
			return this->setExpiry(mRedisContextDRA, key, expiretime, true);
		}
		else
		{
			AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| HMSET Error: Object is NULL\n"));

			if(!recnct)
				return false;

			if(this->reConnect(mRedisContextDRA))
			{
				AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Re-connected\n"));
				lInsertedFlag = false;
			}
			else
			{
				return false;
			}
		}
	} //TBC --- Will release lock when comeout of block  ACE_Write_Guard<ACE_RW_Mutex> guard(m_LockInsert)

	if (!lInsertedFlag)
	{
		return this->insert(key, multipleKV, expiretime, false);
	}

	return true;
}

//----------------------------------------------------------------------
// METHOD      : Inser hash multiple set
// DESCRIPTION : Insert multiple KV.
// PARAMETERS  :
// RETURN      :
//----------------------------------------------------------------------
//bool Redis::insert(std::string data, int expiretime, bool recnct)
bool Redis::insert(std::string data, std::string lListName, int expiretime, bool recnct)
{
        redisReply  *reply =NULL;
        std::string command = "";
        //std::string command("LPUSH PCRF_RELAY ");
        bool        lInsertedFlag = true;

        command.append(data);

        { //TBC protected block -----------NKS

                //ACE_Write_Guard<ACE_RW_Mutex> guard(m_LockInsert);


                if(mRedisContextDRA == NULL)
                {
                        if(this->reConnect(mRedisContextDRA))
                        {
                                AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Re-connected\n"));
                        }
                        else
                        {
                                return false;
                        }
                }

                //reply = (redisReply * )redisCommand(mRedisContextDRA, "LPUSH PCRF_RELAY %s", command.c_str());
                reply = (redisReply * )redisCommand(mRedisContextDRA, "LPUSH %s %s", lListName.c_str(), command.c_str());

                if ( reply != NULL)
                {
                        if(reply->type != REDIS_REPLY_INTEGER)
                        {
                                AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| LPUSH Error: %s, CMD:%s\n", reply->str, command.c_str()));
                                freeReplyObject(reply);
                                return false;
                        }

                        freeReplyObject(reply);
                }
                else
                {
                        AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| LPUSH Error: Object is NULL\n"));

                        if(!recnct)
                                return false;

                        if(this->reConnect(mRedisContextDRA))
                        {
                                AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Re-connected\n"));
                                lInsertedFlag = false;
                        }
                        else
                        {
                                return false;
                        }
                }
        } //TBC --- Will release lock when comeout of block  ACE_Write_Guard<ACE_RW_Mutex> guard(m_LockInsert)

        if (!lInsertedFlag)
        {
                return this->insert(data, lListName, expiretime, false);
        }

        return true;
}

//----------------------------------------------------------------------
// METHOD      : setExpiry
// DESCRIPTION :  
// PARAMETERS  : 
// RETURN      : 
//----------------------------------------------------------------------
bool Redis::setExpiry(redisContext *&ctx, std::string key, int expiretime, bool recnct)
{
	bool        lExpiryFlag = true;
	redisReply  *reply =NULL;

	std::string command("EXPIRE ");
	command.append(key + " " + to_string(expiretime));

	reply = (redisReply * )redisCommand(ctx,command.c_str());
	if ( reply != NULL)
	{
		if(reply->type != REDIS_REPLY_STATUS && reply->str != NULL)
		{
			AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| HMSET Expire Time out Error: %s\n", reply->str));
			freeReplyObject(reply);
			return false;
		}
		freeReplyObject(reply);
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| HGETALL Error: Object is NULL\n"));
		
		if(!recnct)
		{
			return false;
		}

		if(this->reConnect(ctx))
		{
			AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Re-connected\n"));
			lExpiryFlag = false;
		}
		else
		{
			return false;
		}
	}

	if ( !lExpiryFlag)
	{	
		return this->setExpiry(ctx, key, expiretime, false);
	}

	return true;
}

//----------------------------------------------------------------------
// METHOD      : update
// DESCRIPTION : Update Multiple KV 
// PARAMETERS  : 
// RETURN      : 
//----------------------------------------------------------------------
bool Redis::update(std::string key, std::map<std::string, std::string> multipleKV)
{
	redisReply *reply = NULL;
	std::string command("HMSET ");
	command.append(key);

	for (auto it = multipleKV.begin(); it != multipleKV.end(); ++it)
		command.append(" " +it->first + " " + it->second);

	//ACE_Write_Guard<ACE_RW_Mutex> guard(m_LockInsert);	
	
	reply = (redisReply * )redisCommand(mRedisContextDRA,command.c_str());
	if(reply != NULL)
	{
		if(reply->type != REDIS_REPLY_STATUS)
		{
			AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| HMSET Error: %s\n", reply->str));
			freeReplyObject(reply);
			return false;
		}
		freeReplyObject(reply);
	}
	else
	{
		AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| HGETALL Error: Object is NULL\n"));
		return false;
	}
	return true;
}

//----------------------------------------------------------------------
// METHOD      : remove
// DESCRIPTION : Remove Key Value
// PARAMETERS  : 
// RETURN      : 
//----------------------------------------------------------------------
bool Redis::remove(std::string key,bool recnct)
{
	redisReply *reply         = NULL;
	std::string command("DEL ");
	bool        lRemoveFlag = true;

	command.append(key);

	{ //TBC protected block -----------NKS

		//ACE_Write_Guard<ACE_RW_Mutex> guard(m_LockDelete);
	
		if(mRedisContextDRA != NULL)
      {
			reply = (redisReply * )redisCommand(mRedisContextDRA,command.c_str());
         AAA_LOG((LM_INFO, "Deleted key:%s from Redis.",key));
      }

		if(reply != NULL)
		{
			if(reply->type != REDIS_REPLY_INTEGER)
			{
				AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| DEL Error: %s\n", reply->str));
				freeReplyObject(reply);
				return false;
			}
			freeReplyObject(reply);
		}	
		else
		{
			AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| DEL Error: Object is NULL\n"));


			if(!recnct)
			{
				return false;
			}

			if(this->reConnect(mRedisContextDRA))
			{
				AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Re-connected\n"));
				lRemoveFlag = false;
			}
			else
			{
				return false;
			}
		}	
	}

	if ( !lRemoveFlag)
	{
		return this->remove(key, false);
	}
	return true;
}

//----------------------------------------------------------------------
// METHOD      : remove
// DESCRIPTION : Remove Key Value
// PARAMETERS  : 
// RETURN      : 
//----------------------------------------------------------------------
bool Redis::removeOnTimeout(std::string key,bool recnct)
{
	redisReply *reply             = NULL;
	bool        lRemoveOnTimeFlag = true;
	std::string command("DEL ");
	command.append(key);
	

	{ //TBC protected block -----------NKS
		//ACE_Write_Guard<ACE_RW_Mutex> guard(m_LockDelTimeout);	

		if(mRedisContextDRA != NULL)
      {
			reply = (redisReply * )redisCommand(mRedisContextDRA,command.c_str());
         AAA_LOG((LM_INFO, "Deleted key:%s from Redis on Timeout.",key));
      }
		if(reply != NULL)
		{
			if(reply->type != REDIS_REPLY_INTEGER)
			{
				AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| DEL Error: %s\n", reply->str));
				freeReplyObject(reply);
				return false;
			}
			freeReplyObject(reply);
		}	
		else
		{

			AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| DEL Error: Object is NULL\n"));

			if(!recnct)
			{
				return false;
			}

			if(this->reConnect(mRedisContextDRA))
			{
				AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Re-connected\n"));
				lRemoveOnTimeFlag = false;
			}
			else
			{
				return false;
			}
		}
	}
	
	if ( !lRemoveOnTimeFlag)
	{
		return this->removeOnTimeout(key, false);
	}

	return true;
}
//----------------------------------------------------------------------
// METHOD      : read
// DESCRIPTION : Read value
// PARAMETERS  : 
// RETURN      : 
//----------------------------------------------------------------------
bool Redis::read(std::string key, std::map<std::string, std::string>& value,bool recnct)
{
	redisReply *reply     = NULL;
	bool        lReadFlag = true;	
	std::string command("HGETALL ");
	command.append(key);

	{ //TBC protected block -----------NKS
		
		//ACE_Write_Guard<ACE_RW_Mutex> guard(m_LockSelect);	
		if(mRedisContextDRA == NULL)
	   {
			if ( this->reConnect(mRedisContextDRA) == false)
				return false;
      }
		reply = (redisReply * )redisCommand(mRedisContextDRA,command.c_str());

		/*if(reply != NULL){
		  std::cout<<"TBR No. of Elements read :"<<reply->elements<<std::endl;
		  std::cout<<"TBR Type of Elements read :"<<reply->type<<std::endl;
		  std::cout<<"TBR Integer Elements read :"<<reply->integer<<std::endl;
		//std::cout<<"TBR str Elements read :"<<reply->str<<std::endl;
		}*/

		if(reply != NULL)
		{
			/*switch(reply->type)
			{
				case REDIS_REPLY_ARRAY:
					for (unsigned int i = 0; i < reply->elements; i+=2) 
					{
						value[reply->element[i]->str]	 = reply->element[i+1]->str;		
					}
					break;
				default:
					AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| HGETALL Error: %s\n", reply->str));
					freeReplyObject(reply);
					return false;
			}*/
         int    original_type = reply->type;
         size_t original_elements = reply->elements;
         void* original_element_ptr = (void*)reply->element; // Cast to void* for logging
         AAA_LOG((LM_INFO, "%T |SYNC_REDIS| Initial reply: type=%d, elements=%zu, element_ptr=%p", original_type, original_elements, original_element_ptr));

         if (reply->type == REDIS_REPLY_ARRAY)
         {
            if (reply->elements % 2 != 0)
            {
               AAA_LOG((LM_INFO, "%T |SYNC_REDIS| HGETALL returned odd number of elements: %u\n", reply->elements));
               freeReplyObject(reply);
               return false;
            }

            if (reply->type != original_type ||
                  reply->elements != original_elements ||
                  (void*)reply->element != original_element_ptr) 
            {
               AAA_LOG((LM_INFO, "RequestID: %s |SYNC_REDIS| MEMORY CORRUPTION DETECTED on redisReply object!"));
               AAA_LOG((LM_INFO, "Original: type=%d, elements=%zu, element_ptr=%p", original_type, original_elements, original_element_ptr));
               AAA_LOG((LM_INFO, "Corrupted: type=%d, elements=%zu, element_ptr=%p", reply->type, reply->elements, (void*)reply->element));
               // Potentially log more context about what happened between the original fetch and now
               // Then, probably best to freeReplyObject(reply) and return an error.
               freeReplyObject(reply);
               return false;
            }
            else
            {
               //AAA_LOG((LM_INFO, "|SYNC_REDIS| All Good!"));
            }

            const size_t MAX_EXPECTED_ELEMENTS = 20; // Example: Max 20 fields.
            uintptr_t element_ptr_as_int = (uintptr_t)reply->element;

            if (reply->elements > MAX_EXPECTED_ELEMENTS ||
                  (reply->elements > 0 && (reply->element == NULL || element_ptr_as_int < 0x1000)) ) 
            { // Check for huge count OR (if count > 0, element is NULL or suspiciously low)
               AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| HGETALL reply corruption suspected! elements: %zu (max_expected: %zu), element_ptr: %p\n",
                        reply->elements, MAX_EXPECTED_ELEMENTS, (void*)reply->element));
               // Log the full reply details for debugging this specific corruption event
               AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Corrupted reply details: reply=%p, type=%d, integer_val=%lld, len=%zu, str_val_preview='%.50s'\n",
                        (void*)reply, reply->type, reply->integer, reply->len, reply->str ? reply->str : "NULL_STR"));

               freeReplyObject(reply);
               return false; // Exit gracefully instead of crashing
            }
            else
            {
               //AAA_LOG((LM_INFO, "|SYNC_REDIS Debug| All Good!"));
            }

            for (unsigned int i = 0; i < reply->elements; i += 2)
            {
               if (reply->element[i] && reply->element[i+1] &&
                     reply->element[i]->type == REDIS_REPLY_STRING &&
                     reply->element[i+1]->type == REDIS_REPLY_STRING)
               {
                  value[reply->element[i]->str] = reply->element[i+1]->str;
                  AAA_LOG((LM_DEBUG, "Element[%u] type: %d, str: %s\n", i, reply->element[i] ? reply->element[i]->type : -1,
                           reply->element[i] && reply->element[i]->str ? reply->element[i]->str : "NULL"));
               }
               else
               {
                  AAA_LOG((LM_INFO, "%T |SYNC_REDIS| HGETALL element[%u] or element[%u] not a string or null\n", i, i+1));
               }
            }
         }
         else
         {
            AAA_LOG((LM_INFO, "%T |SYNC_REDIS| HGETALL Error: %s\n", reply->str ? reply->str : "NULL"));
            freeReplyObject(reply);
            return false;
         }

         freeReplyObject(reply);
      }
      else
      {
         AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| HGETALL Error: Object is NULL\n"));

         if(!recnct)
         {
            return false;
			}

			if(this->reConnect(mRedisContextDRA))
			{
				AAA_LOG((LM_ERROR, "%T |SYNC_REDIS| Re-connected\n"));
				lReadFlag = false;
			}
			else
			{
				return false;
			}
		}
	}

	if ( !lReadFlag)
	{
      return this->read(key,value, false);
   }

	//return false;
	return true;
}
