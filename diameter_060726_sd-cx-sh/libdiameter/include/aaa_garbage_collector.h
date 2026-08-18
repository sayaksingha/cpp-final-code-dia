// @(#) $Id: aaa_garbage_collector.h,v 1.1.4.1.2.1.2.7 2024/06/14 12:37:19 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_garbage_collector.h
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
#ifndef __AAA_GARBAGE_COLLECTOR_H__
#define __AAA_GARBAGE_COLLECTOR_H__

#include "framework.h"

typedef enum delGrace_s{
	/*DELETION_GRACEPERIOD = 1000000, // usec
	DELETION_TRANSPORT_IO_GRACEPERIOD = 120000000*/
	DELETION_GRACEPERIOD = 5000000, // usec
	DELETION_TRANSPORT_IO_GRACEPERIOD = 600000000,	
}delGrace_t;

class DiameterGarbageCollectorAttribute
{
    public:
		  
   public:
        DiameterGarbageCollectorAttribute() :
           m_GracePeriod(0, DELETION_GRACEPERIOD) {
        }
        ACE_Time_Value &GracePeriod() {
           return m_GracePeriod;
        }
		  
		  int  &GracePeriodConst() {
           return mEnumGracePeriod;
        }

		  void SetTime()
		  {
				ACE_Time_Value lTimeVal(time(NULL), DELETION_GRACEPERIOD);
				m_GracePeriod = lTimeVal;
		  }

   protected:
        ACE_Time_Value m_GracePeriod;
		  int mEnumGracePeriod = DELETION_GRACEPERIOD;
};

class DiameterGarbageTransportCollectorAttribute
{
   public:
        DiameterGarbageTransportCollectorAttribute() :
           m_GracePeriod(0, DELETION_TRANSPORT_IO_GRACEPERIOD) {
        }

        ACE_Time_Value &GracePeriod() {
           return m_GracePeriod;
        }
        
		  int  &GracePeriodConst() {
           return mEnumGracePeriod;
        }

        void SetTime()
        {
           ACE_Time_Value lTimeVal(time(NULL), DELETION_TRANSPORT_IO_GRACEPERIOD);
           m_GracePeriod = lTimeVal;
        }

   protected:
        ACE_Time_Value m_GracePeriod;
		  int mEnumGracePeriod = DELETION_TRANSPORT_IO_GRACEPERIOD;
};

template <class T>
class DiameterGarbageCollector :
    public AAA_Job
{
    public:
        DiameterGarbageCollector(AAA_Task &t) :
            m_GroupedJob(AAA_GroupedJob::Create(t.Job(),
	                 (AAA_JobData*)this)),
            m_Enabled(true),
            m_ExitCondition(m_CondMutex) {
	}
        virtual ~DiameterGarbageCollector() {
            m_Enabled = false;
            AAA_MutexScopeLock guard(m_CondMutex);
            while (! m_DeleteQueue.IsEmpty()) {
                m_ExitCondition.wait();
            }
            m_GroupedJob->Stop();
	}
        //void ScheduleForDeletion(T &&obj) {
        void ScheduleForDeletion(T &obj) {
            if (m_Enabled) {
					obj.SetTime();
               m_DeleteQueue.Enqueue(&obj);
               Schedule(this);
	    }
	}
        void ScheduleForDeletion(std::unique_ptr<T> obj) {
            if (m_Enabled && obj.get()) {
					obj->SetTime();
               m_DeleteQueue.Enqueue(obj.release());
               Schedule(this);
	    }
	}

    protected:
        
		  int Schedule(AAA_Job *job, size_t backlogSize=1) 
		  {
            return m_GroupedJob->Schedule(job, backlogSize);
		  }

		  int Serve() 
		  {
			  if (this == nullptr) 
			  {
				  AAA_LOG((LM_INFO, "Error : 'this' pointer is NULL in Serve"));
				  m_ExitCondition.signal();
				  return (0);
			  }

			  AAA_MutexScopeLock guard(m_CondMutex);
			  try
			  {
				  AAA_LOG((LM_INFO, " PID:%d Inside Serve Function\n", getpid()));
				  if ( !m_DeleteQueue.IsEmpty())
				  {
					  AAA_LOG((LM_INFO, " PID:%d m_DeleteQueue is not empty\n", getpid()));
					  T *obj = m_DeleteQueue.Dequeue();

					  /*ACE_Time_Value lTimeVal(time(NULL), 0); 
					    if (obj->GracePeriod() > lTimeVal) 
					    {
					  //ACE_Time_Value lTimeValNew(0, DELETION_GRACEPERIOD); 
					  ACE_Time_Value lTimeValNew(0, (obj->GracePeriodConst())); 
					  //ACE_OS::sleep(obj->GracePeriod());
					  ACE_OS::sleep(lTimeValNew);
					  lTimeVal = time(NULL);
					  }*/

					  ACE_Time_Value lTimeVal(time(NULL), 0);

					  while (obj->GracePeriod() > lTimeVal)
					  {
						  ACE_Time_Value lTimeValNew(0, 1);
						  ACE_OS::sleep(lTimeValNew);
						  lTimeVal = time(NULL);
						  ACE_Time_Value m_GracePeriod1 = obj->GracePeriod();
						  long gracePeriodMicrosec = m_GracePeriod1.usec(); // Convert grace period to microseconds
						  long currentMicrosec = lTimeVal.usec(); // Convert current time to microseconds
		//				  AAA_LOG((LM_INFO, "PID:%d Time over for GC, deleting the object. GracePeriod: %ld microseconds, Current Time: %ld microseconds\n", getpid(), gracePeriodMicrosec, currentMicrosec));

					  }

					  if ( obj != nullptr )
					  {
		//				  AAA_LOG((LM_INFO, " PID:%d deleting the object\n", getpid()));
						  delete obj;
		//				  AAA_LOG((LM_INFO, " PID:%d deleted the object\n", getpid()));
						  obj = nullptr;
					  }
					  else
					  {
						  AAA_LOG((LM_INFO, " PID:%d object is null!\n",getpid()));
					  }
				  }
			  }
			  catch(exception &e)
			  {	
				  AAA_LOG((LM_INFO, " PID:%d exception :%s \n", getpid(),e.what()));
			  }	
			  catch(...)
			  {
				  AAA_LOG((LM_INFO, " PID:%d exception :\n", getpid()));
			  }	

			  AAA_LOG((LM_INFO, " PID:%d deleted the object sucessfully\n", getpid()));
			  m_ExitCondition.signal();
			  return (0);
		  }

    private: // job scheduling
		  AAA_JobHandle<AAA_GroupedJob> m_GroupedJob;
		  AAA_ProtectedQueue<T*> m_DeleteQueue;
		  bool m_Enabled;

    private: // exit protection
		  ACE_Condition<ACE_Mutex> m_ExitCondition;
		  ACE_Mutex m_CondMutex;
};

template <class T>
class DiameterGarbageCollectorSingleton
{
	public:
		virtual ~DiameterGarbageCollectorSingleton() {
		}
		void Initialize(AAA_Task &t) {
			m_Instance = std::unique_ptr< DiameterGarbageCollector<T> >
				(new DiameterGarbageCollector<T>(t));
		}
		void Release() {
			m_Instance.reset();
		}
		DiameterGarbageCollector<T> &Instance() {
			// this will throw when used improperly
			return (*m_Instance);
		}

	private:
		std::unique_ptr< DiameterGarbageCollector<T> > 
			m_Instance;
};

#endif // __AAA_GARBAGE_COLLECTOR_H__


