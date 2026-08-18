
#include "aaa_redis_pool.h"

bool RedisSessionPool::start(int lNoOfTask)
{
	if (! m_Active && (activate(THR_NEW_LWP,lNoOfTask) == 0)) { }
   return m_Active;
}

void RedisSessionPool::stop()
{
   m_Active = false;
   m_Condition.signal();
}

bool RedisSessionPool::syncSession(SyncDccaProxySessionData &data)
{
	std::shared_ptr<SyncDccaProxySessionData> lSyncData = make_shared<SyncDccaProxySessionData>(data);
	AAA_LOG((LM_ERROR,"%T |REDIS-POOL| Message Received Queue Size:%d\n",m_SendQueue.Size()));
	m_SendQueue.Enqueue(lSyncData);
	m_Condition.signal();
	return true;
}

bool RedisSessionPool::startConn()
{
	return Init(m_redis_ctx, (char*)DIAMETER_CFG_GENERAL()->sync_ip.c_str(), DIAMETER_CFG_GENERAL()->sync_port, 10);
}

int RedisSessionPool::svc()
{
	m_Active = true;
	
   AAA_LOG((LM_ERROR,"%T |REDIS-POOL| Thread started RedisSessionPool \n"));
	do
   {
      //AAA_MutexScopeLock guard(m_Condition.mutex());
      //m_Condition.wait();
//startConn();
		if (m_SendQueue.IsEmpty())
      {
         AAA_MutexScopeLock guard(m_Condition.mutex());
         m_Condition.wait();
      }
		
      while (! m_SendQueue.IsEmpty())
      {
			//std::shared_ptr<SyncDccaProxySessionData> data = m_SendQueue.Dequeue();
			std::shared_ptr<SyncDccaProxySessionData> data ;
			
			//Protect with additional mutex lock ==> Not an condition variable.. Normal lock.
         pthread_mutex_lock(&m_Pmutex);
         if ( ! m_SendQueue.IsEmpty())
         {
				AAA_LOG((LM_CRITICAL,"%T |REDIS-POOL| Message Received dequeue size:%d \n",m_SendQueue.Size()));
            data = m_SendQueue.Dequeue();
         }
         else
         {
            //release additional mutex lock ==> Not an condition variable.. Normal lock.
            pthread_mutex_unlock(&m_Pmutex);
            continue;
         }
         //release additional mutex lock ==> Not an condition variable.. Normal lock.
         pthread_mutex_unlock(&m_Pmutex);


			std::string key     = std::to_string(data->appId) + "_" + string(data->sessionId);
			Redis *lRedis = DIAMETER_SYNC()->Acquire();

			if(SYNC_OP_ADD == data->op)
			{
				std::map<std::string, std::string> multipleKV;

				multipleKV["node"]  = DIAMETER_CFG_GENERAL()->node_id;
				multipleKV["type"]  = "sid";
				multipleKV["sId"]   = data->sessionId;
				multipleKV["sName"] = data->sourceName;
				multipleKV["dName"] = data->destName;
				multipleKV["appId"]   = to_string(data->appId);
				multipleKV["event"] = to_string(data->event);
				multipleKV["op"]    = to_string(data->op);
				multipleKV["mid"]   = to_string(data->mModuleId);

				int expTime = (DIAMETER_CFG_ACCT_SESSION()->sessionTm + 60);
				if(lRedis != NULL && lRedis->insert(key, multipleKV,expTime))
				{
					AAA_LOG((LM_INFO,"%T |REDIS-POOLInserted into REDIS Key:%s\n", key.c_str()));
				}
				else
				{
					AAA_LOG((LM_ERROR,"%T |REDIS-POOLInsertion failed into REDIS Key:%s\n",key.c_str()));
				}
			}
			else
			{
				if(lRedis != NULL && lRedis->remove(key))
				{
					AAA_LOG((LM_INFO,"%T |REDIS-POOLRemoved from REDIS Key:%s\n",key.c_str()));
				}
				else
				{
					AAA_LOG((LM_ERROR,"%T |REDIS-POOLDeletion failed REDIS Key:%s\n",key.c_str()));
				}
			}
			if(lRedis != NULL)
				DIAMETER_SYNC()->Release(lRedis);
		}
	}while(m_Active);
}

bool RedisHbHPool::start(int lNoOfTask)
{
	if (! m_Active && (activate(THR_NEW_LWP, lNoOfTask) == 0)) { }
	return m_Active;
}

void RedisHbHPool::stop()
{
	m_Active = false;
	m_Condition.signal();
}

bool RedisHbHPool::syncHbH(SyncHopByHopIdData &data)
{
	std::shared_ptr<SyncHopByHopIdData> lSyncData = make_shared<SyncHopByHopIdData>(data);
   m_SendQueue.Enqueue(lSyncData);
   m_Condition.signal();
	return true;
}

bool RedisHbHPool::startConn()
{
    //Init(m_redis_ctx, (char*)DIAMETER_CFG_GENERAL()->sync_ip.c_str(), DIAMETER_CFG_GENERAL()->sync_port, 10);
	 return true;
}

int RedisHbHPool::svc()
{
	m_Active = true;

	AAA_LOG((LM_ERROR,"%T |REDIS-POOL| Thread started RedisHbHPool \n" ));
   do
   {

     // AAA_MutexScopeLock guard(m_Condition.mutex());
     // m_Condition.wait();
		
		if (m_SendQueue.IsEmpty())
      {
         AAA_MutexScopeLock guard(m_Condition.mutex());
         m_Condition.wait();
      }

      while (! m_SendQueue.IsEmpty())
      {
			
         //std::shared_ptr<SyncHopByHopIdData> data = m_SendQueue.Dequeue();

         std::shared_ptr<SyncHopByHopIdData> data;
			//Protect with additional mutex lock ==> Not an condition variable.. Normal lock.
		   pthread_mutex_lock(&m_Pmutex);	
         if ( ! m_SendQueue.IsEmpty())
         {
				AAA_LOG((LM_CRITICAL,"%T |REDIS-POOL| HH Message Received dequeue size:%d, \n",m_SendQueue.Size() ));
            data = m_SendQueue.Dequeue();
         }
         else
         {
            //release additional mutex lock ==> Not an condition variable.. Normal lock.
				pthread_mutex_unlock(&m_Pmutex);
            continue;
         }
         //release additional mutex lock ==> Not an condition variable.. Normal lock.
			pthread_mutex_unlock(&m_Pmutex);


			std::string key = to_string(data->localH2H);
			Redis *lRedis = DIAMETER_SYNC()->Acquire();
			if(SYNC_OP_ADD == data->op)
			{
				std::map<std::string, std::string> multipleKV;
				multipleKV["node"]  = DIAMETER_CFG_GENERAL()->node_id;
				multipleKV["type"]  = "hh";
				multipleKV["lH2H"]  = to_string(data->localH2H);
				multipleKV["oH2H"]  = to_string(data->origH2H);
				multipleKV["sName"] = data->sourceName;
				multipleKV["dName"] = data->destName;
            multipleKV["op"]    = to_string(data->op);

            int expTime = DIAMETER_CFG_TRANSPORT()->hbh_timeout;
				if(lRedis != NULL && lRedis->insert(key, multipleKV,expTime))
            {
               AAA_LOG((LM_INFO,"%T |REDIS-POOLHH Inserted into REDIS Key:%s\n",key.c_str()));
            }
            else
            {
               AAA_LOG((LM_ERROR,"%T |REDIS-POOLHH Insertion failed into REDIS Key:%s\n",key.c_str()));
            }
         }
         else
         {
            if(lRedis != NULL && lRedis->remove(key))
            {
               AAA_LOG((LM_INFO,"%T |REDIS-POOLHH Removed from REDIS Key:%s\n",key.c_str()));
            }
            else
            {
               AAA_LOG((LM_ERROR,"%T |REDIS-POOLHH Deletion failed REDIS Key:%s\n",key.c_str()));
            }
			 
         }
			if(lRedis != NULL)
				DIAMETER_SYNC()->Release(lRedis);
		}
	}while(m_Active);
}

