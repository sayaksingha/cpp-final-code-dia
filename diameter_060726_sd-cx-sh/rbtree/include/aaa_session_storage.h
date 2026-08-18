#include <vector>
#include <boost/algorithm/string.hpp>
#include "tss_rbtree.h"
#include <mutex>

#ifndef __AAA_SESSION_NEW_DB_H__
#define __AAA_SESSION_NEW_DB_H__


using namespace std;

typedef enum RBTreeNodeType{
	TYPE_RBTREE,
	TYPE_PAYLOAD
} TSS_RbTreeNodeType;



class chronotimediff
{
public  :
	chronotimediff ( std::string&& data):mString(data)
	{
		mCurrentTime1  = chrono::high_resolution_clock::now();
	}
	~chronotimediff ()
	{
		//chrono::time_point<chrono::high_resolution_clock> lCurrentTime1 = chrono::high_resolution_clock::now();
	//	bool ret = DIAMETER_NEW_SESSION_DB().Lookup(sessionId , (void**)&job);
		mCurrentTime2 = chrono::high_resolution_clock::now();
		std::chrono::duration<float> fs = mCurrentTime2 - mCurrentTime1;
		std::chrono::nanoseconds ms = std::chrono::duration_cast<std::chrono::nanoseconds>(fs);
		//cout<<"-"<< mString << "	session time: "<<ms.count()<<"ns\n";
		string time_val = std::to_string(ms.count());
		//AAA_LOG((LM_ERROR,"%T %P %t |TREE| %s time:%s\n",mString.c_str(),time_val.c_str()));
	}
	private :
	chrono::time_point<chrono::high_resolution_clock> mCurrentTime1;
	chrono::time_point<chrono::high_resolution_clock> mCurrentTime2;
   std::string mString ;	
};


class session_id_data : public TSS_RbTreeData
{
	public:
		session_id_data(std::string sid, void *data=NULL, TSS_RbTreeNodeType type=TYPE_PAYLOAD)
		{
			partSessionId = sid;
			nodeType      = type;
			this->data    = data;
		}

		virtual ~session_id_data()
		{
		}

		int operator < (TSS_RbTreeData &cmp)
		{
			session_id_data* obj = (session_id_data*)cmp.payload;

			//	if(nodeType == obj->getDataType())
			{
				return (partSessionId.compare(obj->PartSessionId()) < 0) ? true : false;
			}
		}

		int operator == (TSS_RbTreeData &cmp)
		{
			session_id_data *data = (session_id_data*)cmp.payload;
			return partSessionId == data->partSessionId ? true : false;
		}

		std::string PartSessionId()
		{
			return partSessionId;
		}

		void* getPayLoadData()
		{
			return data;
		}

		void* getPayLoadData(void *payLoadData)
		{
			payLoadData = data;
			return data;
		}

		void setPayLoadData(void* data)
		{
			this->data = data;
		}

		TSS_RbTreeNodeType getDataType()
		{
			return nodeType;
		}

		void setDataType(TSS_RbTreeNodeType type)
		{
			nodeType = type;
		}

		std::string& DiameterId()
		{
			return partSessionId;
		}
		void clear(void *userData = 0);

		void *data;
	private:
		std::string partSessionId;
		TSS_RbTreeNodeType nodeType;
};


class aaa_session_storage : public TSS_RbTreeTree
{
	public:
		aaa_session_storage();
		bool Add(std::string sid, void *payloaddata);

		bool Remove(const std::string sid);
		bool Lookup(std::string sid, void **data);
		void* _Remove(const std::string sid, void *appData);

	private:
		std::mutex mut;
};

class DiameterNewSessionDb/// : public TSS_RbTreeTree 
{
    public:
        bool Add(std::string id, AAA_JobData *data);
        bool Lookup( std::string id , AAA_JobData *&data);
        bool Remove(const std::string id );

  		   aaa_session_storage session_storage; 
    private:
        ACE_RW_Mutex m_rwMutex;

};

typedef ACE_Singleton<aaa_session_storage,
                      ACE_Recursive_Thread_Mutex>
                      DiameterNewSessionDb_S;

#define DIAMETER_NEW_SESSION_DB() (*DiameterNewSessionDb_S::instance())

#endif
