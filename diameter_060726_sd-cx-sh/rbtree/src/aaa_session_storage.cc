#include "aaa_session_storage.h"

aaa_session_storage::aaa_session_storage()
{

}

void session_id_data::clear(void *userData)
{
	return;
}


bool DiameterNewSessionDb::Add(std::string sessionId , AAA_JobData *jobdata)
{
	//ACE_Write_Guard<ACE_RW_Mutex> guard(m_rwMutex);

	void *storeJobData =  (void*) (jobdata);

//	aaa_session_storage session_storage;

	TSS_RbTreeData *data = new session_id_data(sessionId , storeJobData );

	//return session_storage.Insert(sessionId, data);

}


bool DiameterNewSessionDb::Lookup(std::string id , AAA_JobData *&jobdata)
{
	//ACE_Read_Guard<ACE_RW_Mutex> guard(m_rwMutex);
//	aaa_session_storage session_storage;
/*

	TSS_RbTreeData *rbdata  = NULL ;
	void *payLoadData = NULL;
   std::string sid = id ;
	session_storage.Find(sid, &payLoadData) ;

	if ( NULL != payLoadData)
	{
		jobdata = reinterpret_cast<AAA_JobData*>(reinterpret_cast<session_id_data*>(rbdata)->getPayLoadData());
		return true ;
	}*/
	return false;

}




bool DiameterNewSessionDb::Remove(const std::string id)
{
/*
//CE_Write_Guard<ACE_RW_Mutex> guard(m_rwMutex);

//	aaa_session_storage session_storage;
	TSS_RbTreeData *tempdata  = NULL ;
	void *tempPayLoad = NULL;
	//TSS_RbTreeData *rbdata = session_storage.Remove(id, tempdata);
	//TSS_RbTreeData *rbdata = session_storage.Remove(id, tempPayLoad);
	void *rbdata = session_storage.Remove(id, tempPayLoad);
	//TSS_RbTreeData *rbdata = session_storage.Remove(id, rbdata);

   if (NULL != rbdata)
   {
		delete rbdata;
      return true ;
   }*/
   return false;

}

bool aaa_session_storage::Add(std::string sid, void *payloaddata)
//bool aaa_session_storage::Insert(std::string sid, TSS_RbTreeData *payloaddata)
{
	//chronotimediff lchronotimediff( "insert" );
	std::lock_guard<std::mutex> guard(mut);
	vector<std::string> partSid;
	boost::split(partSid, sid, boost::is_any_of(";"));
	auto partSidIterator = partSid.begin();
	unsigned count = partSid.size() - 1;

	session_id_data tempData(*partSidIterator);
	TSS_RbTreeNode *parent = NULL;
	TSS_RbTreeNode *retNode = _Find(&tempData, &parent);
	TSS_RbTreeData *ret = NULL;
	//Node not present
	//TBA, if the parition of session id is one than that condition shall handle
	if(!retNode)
	{
		TSS_RbTreeTree *rbTree = new TSS_RbTreeTree();
		session_id_data* data = new session_id_data(*partSidIterator, (void*)rbTree, TYPE_RBTREE);
		ret = TSS_RbTreeTree::Insert(data, parent);
	}
	//Node present
	else 
	{
		ret = retNode->data;
	}
	partSidIterator++;
	count--;

	while(ret && count)
	{
		session_id_data *retPtr = static_cast<session_id_data*>(ret);
		TSS_RbTreeTree *retRbTree = reinterpret_cast<TSS_RbTreeTree*>(retPtr->getPayLoadData());

		if(retRbTree == NULL)
			return false;

		tempData.DiameterId() = *partSidIterator;
		TSS_RbTreeNode *parent = NULL;
		retNode = retRbTree->_Find(&tempData, &parent);
		//node present
		if(retNode)
		{
			ret = retNode->data;
		}
		else
		{
			TSS_RbTreeTree *rbTree = new TSS_RbTreeTree();
			session_id_data* data = new session_id_data(*partSidIterator, (void*)rbTree, TYPE_RBTREE);	
			ret = retRbTree->Insert(data, parent);
		}
		partSidIterator++;
		count--;
	}

	{
		session_id_data *retPtr = static_cast<session_id_data*>(ret);
		TSS_RbTreeTree *retRbTree = reinterpret_cast<TSS_RbTreeTree*>(retPtr->getPayLoadData());

		session_id_data* data = new session_id_data(*partSidIterator, payloaddata);
		ret = retRbTree->Insert(data);
		if(ret != data)
			delete data;
	}

	return true;

}

//TSS_RbTreeData* aaa_session_storage::Find(std::string sid)
bool aaa_session_storage::Lookup(std::string sid, void **payLoaddata)
{
	//chronotimediff lchronotimediff( "Lookup" );

	vector<std::string> partSid;
	void *dataTemp;
	boost::split(partSid, sid, boost::is_any_of(";"));
	auto partSidIterator = partSid.begin();
	unsigned count = partSid.size() - 1;

	std::lock_guard<std::mutex> guard(mut); //TBC -NK -14-JAN-2019
	session_id_data data(*partSidIterator);
	session_id_data *ret = (session_id_data*)TSS_RbTreeTree::Find(&data);

	partSidIterator++;
	count--;

	while(ret && count)
	{
		TSS_RbTreeTree *retRbTree = reinterpret_cast<TSS_RbTreeTree*>(ret->getPayLoadData());
		if(retRbTree == NULL)
			return false;

		data.DiameterId() = *partSidIterator;
		ret = static_cast<session_id_data*>(retRbTree->Find(&data));
		partSidIterator++;
		count--;
	}

	if(!count && ret)
	{
	   TSS_RbTreeTree	*retRbTree = reinterpret_cast<TSS_RbTreeTree*>(ret->getPayLoadData());
		data.DiameterId() = *partSidIterator;
		ret = reinterpret_cast<session_id_data*>(retRbTree->Find(&data));

		if (ret && (ret->getDataType() == TYPE_PAYLOAD))
		{
			*payLoaddata = ret->getPayLoadData();
			return true;
		}
	}

	return false;
}

bool aaa_session_storage::Remove(const std::string sid)
{
	void *appData;
	std::lock_guard<std::mutex> guard(mut);
	if(this->_Remove(sid, appData))
		return true;
	else
		return false;
}

void* aaa_session_storage::_Remove(const std::string sid, void *appData)
{
	char *savePtr;
	void *retData = NULL;
	session_id_data *ret = NULL;
	TSS_RbTreeNode *parent = NULL;
	

	if(sid.size() != 0)
	{
		string partSid = strtok_r((char*)sid.c_str(), ";", &savePtr);
		session_id_data data(partSid);
		TSS_RbTreeNode *retNode = _Find(&data, &parent);
		if(retNode != NULL)
			ret = (session_id_data*)retNode->data;
		else
			return NULL;

		if(ret && ret->getDataType() == TYPE_RBTREE)
		{
			aaa_session_storage *rbTree = reinterpret_cast<aaa_session_storage*>(ret->getPayLoadData());
			retData = rbTree->_Remove(string(savePtr), appData);
			if(rbTree->getNumOfNodes() == 0)
			{
				ret = (session_id_data*)this->Delete(retNode);
				delete rbTree;
				if ( ret != NULL )
					delete ret;


			}
			return retData;
		}
		else
		{
			ret = (session_id_data*)TSS_RbTreeTree::Delete(retNode);

			if ( ret != NULL )
         {
			   retData = (TSS_RbTreeData*)ret->getPayLoadData();
				delete ret;
         }
			return retData;	
		}
	}
	else
	{
		return retData;
	}
}

