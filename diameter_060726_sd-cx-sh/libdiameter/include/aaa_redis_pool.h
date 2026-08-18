#ifndef __REDIS_POOL_H__
#define __REDIS_POOL_H__

#include "Redis.h"
#include "RedisPool.h"

class RedisSessionPool :public ACE_Task<ACE_MT_SYNCH> , public Redis
{
   public:
      RedisSessionPool() : m_Active(false),m_Condition(*(new ACE_Mutex))
		{ 
			pthread_mutex_init(&m_Pmutex, NULL);
		}
	
		bool start(int lNoOfTask);
		void stop();
		int  svc();
		bool syncSession(SyncDccaProxySessionData &data);
		bool startConn();
		private:
		bool                                                          m_Active;
		ACE_Condition<ACE_Mutex>                                      m_Condition;
		AAA_ProtectedQueue<std::shared_ptr<SyncDccaProxySessionData>> m_SendQueue;
		redisContext*                                                 m_redis_ctx;

		pthread_mutex_t m_Pmutex;
};

class RedisHbHPool :public ACE_Task<ACE_MT_SYNCH> //, public Redis
{
   public:
      RedisHbHPool() : m_Active(false),m_Condition(*(new ACE_Mutex))
		{
         pthread_mutex_init(&m_Pmutex, NULL);
		}

      bool start(int lNoOfTask);
      void stop();
      int  svc();
		bool syncHbH(SyncHopByHopIdData&);
		bool startConn();

      private:
      bool                                                     m_Active;
      ACE_Condition<ACE_Mutex>                                 m_Condition;
      AAA_ProtectedQueue<std::shared_ptr<SyncHopByHopIdData>>  m_SendQueue;
		redisContext*                                            m_redis_ctx;

		pthread_mutex_t m_Pmutex;
};

/*
class RedisHbHPoolDel :public ACE_Task<ACE_MT_SYNCH> , public Redis
{
   public:
      RedisHbHPoolDel() : m_Active(false),m_Condition(*(new ACE_Mutex)){}

      bool start();
      void stop();
      int  svc();
      bool syncHbH(SyncHopByHopIdData&);
      bool startConn();

      private:
      bool                                                     m_Active;
      ACE_Condition<ACE_Mutex>                                 m_Condition;
      //AAA_ProtectedQueue<std::shared_ptr<DiameterBase>>      m_SendQueue;
      AAA_ProtectedQueue<std::shared_ptr<SyncHopByHopIdData>>  m_SendQueue;
      static   ACE_Mutex                                       *m_ObjGuard;
      //Redis                                                    mHbHSyncAdd;
      //Redis                                                    mHbHSyncDel;
      redisContext*                                            m_redis_ctx;
};
*/
typedef ACE_Singleton<RedisSessionPool, ACE_Thread_Mutex> RedisSessionPool_S;
#define DIAMETER_SESSION_SYNC() RedisSessionPool_S::instance()

typedef ACE_Singleton<RedisHbHPool, ACE_Thread_Mutex> RedisHbHPool_S;
#define DIAMETER_HBH_SYNC() RedisHbHPool_S::instance()

//typedef ACE_Singleton<RedisHbHPoolDel, ACE_Thread_Mutex> RedisHbHPoolDel_S;
//#define DIAMETER_HBH_D_SYNC() RedisHbHPoolDel_S::instance()
#endif
