
#ifndef DRA_HTTP_EVENT_PROCESSOR_H
#define DRA_HTTP_EVENT_PROCESSOR_H

#include "aaa_structs.h" 

class DRA_RelayRspEventWriter : public ACE_Task<ACE_MT_SYNCH>
{
	private:
		DRA_RelayRspEventWriter() 
			:m_Active(false),
			m_Condition(*(new ACE_Mutex)) {
			}			

		DRA_RelayRspEventWriter(DRA_RelayRspEventWriter const&)// copy constructor is private
			:m_Active(false),
			m_Condition(*(new ACE_Mutex)){
			}

		DRA_RelayRspEventWriter& operator=(DRA_RelayRspEventWriter const&)  // assignment operator is private
		{
			return *mDRA_RelayRspEventWriter;
		}

	public:

		static DRA_RelayRspEventWriter *Instance();

		static void Destroy();

		virtual ~DRA_RelayRspEventWriter() {
			Stop();
			delete &(m_Condition.mutex());
		}

		bool Start();
		void Stop();
		int SendReq(std::shared_ptr<string> &rJsonData);

	private:
		bool                                                   	m_Active;
		ACE_Condition<ACE_Mutex>                               	m_Condition;
		AAA_ProtectedQueue<std::shared_ptr<string>>   	 			m_SendQueue;
		static ACE_Mutex                                     		*m_ObjGuard;
		static DRA_RelayRspEventWriter 									*mDRA_RelayRspEventWriter;
		string 																	mFileWPath;
		FILE * 					  												mEvrFile = NULL ;

	private:

		bool EvrFileopen(struct tm &local_ctm);
		void EvrFileClose();
		void write( std::shared_ptr<string> &rJsonStr);

		int svc();

};

#define DRA_EVR_WRITER() DRA_RelayRspEventWriter::Instance()


#endif 
