#include "framework.h"
#include "GenericObject.h"
#include "ObjectPoolManager.h"
#include "Redis.h"

class RedisPool
{
	private:
	public:
		RedisPool():mRedisObjPoolMgr(nullptr){};
		ObjectPoolMgr<Redis>        *mRedisObjPoolMgr;

	public:
		~RedisPool(){};
		BOOLEAN                       Init();
		BOOLEAN                       DeInit();
		Redis* 							   Acquire();
		BOOLEAN   						   Release(Redis*);
};

typedef ACE_Singleton<RedisPool, ACE_Thread_Mutex> RedisPool_S;
#define DIAMETER_SYNC() RedisPool_S::instance()
/*
BOOLEAN RedisPool::Init()
{
	mRedisObjPoolMgr = ObjectPoolMgr<Redis>::GetInstance();
	if(!mRedisObjPoolMgr->Init(10, 600, false))
	{
		return false;
	}
	return true;
}

BOOLEAN RedisPool::DeInit()
{
	return true;
}

Redis* RedisPool::Acquire()
{
	Redis *lRedis = mRedisObjPoolMgr->Checkout();
	if(lRedis == NULL)
		return NULL;
	else
		return lRedis;
}

BOOLEAN RedisPool::Release(Redis lRedis)
{
	mRedisObjPoolMgr->Checkin(*lRedis)
	return true;
}
*/
