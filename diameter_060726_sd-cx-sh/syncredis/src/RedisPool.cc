#include "RedisPool.h"

BOOLEAN RedisPool::Init()
{
   mRedisObjPoolMgr = ObjectPoolMgr<Redis>::GetInstance();
   if(!mRedisObjPoolMgr->Init(DIAMETER_CFG_GENERAL()->sync_obj, 600, false))
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

BOOLEAN RedisPool::Release(Redis *lRedis)
{
   mRedisObjPoolMgr->Checkin(lRedis);
   return true;
}
