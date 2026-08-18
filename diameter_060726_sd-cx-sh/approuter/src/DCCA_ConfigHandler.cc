#include<DCCA_ConfigHandler.h>

DCCA_ConfigHandler*   DCCA_ConfigHandler::mDCCA_ConfigHandler = NULL;
mutex*          		 DCCA_ConfigHandler::mMutexLock    		  = new mutex;
//-------------------------------------------------------------
// METHOD      : DCCA_ConfigHandler()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
DCCA_ConfigHandler::DCCA_ConfigHandler()
{
}

//-------------------------------------------------------------
// METHOD      : DCCA_ConfigHandler()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
DCCA_ConfigHandler::DCCA_ConfigHandler( DCCA_ConfigHandler const& wicpExecuter)
{

}

//-------------------------------------------------------------
// METHOD      : DCCA_ConfigHandler()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
DCCA_ConfigHandler& DCCA_ConfigHandler::operator=( DCCA_ConfigHandler const& DCCA_ConfigHandlerObj)
{
   DCCA_ConfigHandler *DCCA_ConfigHandlerPtr = new DCCA_ConfigHandler();
   return  *DCCA_ConfigHandlerPtr;
}


//-------------------------------------------------------------
// METHOD      : GetInstance()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
DCCA_ConfigHandler* DCCA_ConfigHandler::GetInstance()
{
	if( mDCCA_ConfigHandler == NULL)
	{
		lock_guard<mutex> myLock(*mMutexLock);
		if ( mDCCA_ConfigHandler == NULL)
		{
			mDCCA_ConfigHandler = new DCCA_ConfigHandler();
			mDCCA_ConfigHandler->Init();
		}
	}
	return mDCCA_ConfigHandler;
}

//-------------------------------------------------------------
// METHOD      : Init()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DCCA_ConfigHandler::Init()
{
	//Read product home and config path 
	TEXT*       lpTempPtr;
	lpTempPtr = getenv("PRODUCT_HOME");
	if (NULLPTR == lpTempPtr)
	{
		mProductHome = "/opt/dra/";
	}
	else
	{
		mProductHome = lpTempPtr;
	}

	lpTempPtr = getenv("PRODUCT_CFG");
	if (NULLPTR == lpTempPtr)
	{
		mProductCfgPath = "/etc/config/";
	}
	else
	{
		mProductCfgPath = lpTempPtr;
	}

	mApplnFileName = "DCCA_Configuration.json";
	if ( LoadConfigurationFromFile())
	{
		AAA_LOG((LM_ERROR,"%T |CC_DCCA_CFG| success in reading DCCA configuration\n")); //TBC-Anshul 28-dec
		return true;
	}
	AAA_LOG((LM_ERROR,"%T |CC_DCCA_CFG| Error in reading DCCA configuration\n"));
	return false;
}

//-------------------------------------------------------------
// METHOD      : Init()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DCCA_ConfigHandler::LoadConfigurationFromFile()
{
	string filename = mProductHome + mProductCfgPath + mApplnFileName ;

	try
	{
		boost::property_tree::ptree pt;
		boost::property_tree::read_json(filename, pt);
		if (!Decode(pt))
		{
			AAA_LOG((LM_ERROR,"%T |CC_DCCA_CFG| Error in reading json DCCA configuration\n"));
			return false;
		}
	}
	catch (std::exception const& e)
	{
		AAA_LOG((LM_ERROR,"%T |CC_DCCA_CFG| Exception cought err:%s . Error while reading json configuration\n", e.what() ));
	}

	//Read all configuration here.

	if ( !ReadStringCfg("DCCA_AVP_CFG_FILE_PATH", mAvpFilePath, DCCA_MIN_STR_LEN, DCCA_MAX_STR_LEN))
	{
		//Invalid configuration
		return false;
	}

	if ( !ReadStringCfg("DCCA_AVP_CFG_FILE_NAME", mAvpFileName, DCCA_MIN_STR_LEN, DCCA_MAX_STR_LEN))
	{
		//Invalid configuration
		return false;
	}

   if ( !ReadIntegerCfg("DCCA_APPLICATION_UNIQUE_ID", mApplnIdAvpCode, DCCA_MIN_AVP_VALUE, DCCA_MAX_AVP_VALUE))
   {
      //Invalid configuration
      return false;
   }

	int lTempVal = 0;
	if (!ReadIntegerCfg("DCCA_RELAY_UPDATES", lTempVal, DCCA_MIN_BOOL_SIZE, DCCA_MAX_BOOL_SIZE ))
	{
		mRelaywithoutInitial = false;
		//return false;	
	}
	else
	{
		mRelaywithoutInitial = (bool)lTempVal;
	}

	if ( !ReadStringCfg("DCCA_REDIS_USER_NAME", mRedisUserName, DCCA_MIN_STR_LEN, DCCA_MAX_STR_LEN))
	{
		mRedisUserName = "";
	}

	if ( !ReadStringCfg("DCCA_REDIS_PASSWD", mRedisPasswd, DCCA_MIN_STR_LEN, DCCA_MAX_STR_LEN))
	{
		mRedisPasswd = "";
	}

	return true;
}


//-------------------------------------------------------------
// METHOD      : Decode
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DCCA_ConfigHandler::Decode( boost::property_tree::ptree pt)
{
	mConfigMap.clear();

	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child(""))
	{
		auto it = mConfigMap.find(v.first);

		if ( it == mConfigMap.end())
		{
			mConfigMap.insert(make_pair(v.first ,v.second.data()));
		}
		else
		{
			mConfigMap.erase(it);
			mConfigMap.insert(make_pair(v.first ,v.second.data()));
		}
	}
	return true;
}

//-------------------------------------------------------------
// METHOD      : ReadStringCfg()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DCCA_ConfigHandler::ReadStringCfg( string lKey, string &lData, int mMinLen, int mMaxLen)
{
	auto it = mConfigMap.find(lKey);

	if ( it == mConfigMap.end())
   {	
		AAA_LOG((LM_ERROR,"%T |CC_DCCA_CFG| Key:%s Configuration not found\n", lKey.c_str() ));
		return false;
	}
	lData = it->second;

	if ( lData.length() >= mMinLen && lData.length() <= mMaxLen)
	{
		AAA_LOG((LM_INFO,"%T |CC_DCCA_CFG| Key:%s Data:%s Configuration found\n", lKey.c_str() , lData.c_str()));
		return true;
	}

	AAA_LOG((LM_ERROR,"%T |CC_DCCA_CFG| Key:%s Data:%s Min:%d Max:%d .Invalid Configuration \n", lKey.c_str(), lData.c_str(), mMinLen, mMaxLen ));
	lData = "";
	return false;	
} 

//-------------------------------------------------------------
// METHOD      : ReadIntegerCfg()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DCCA_ConfigHandler::ReadIntegerCfg( string lKey, int &lData, int mMinVal, int mMaxVal)
{
	auto it = mConfigMap.find(lKey);

	if ( it == mConfigMap.end())
	{
		AAA_LOG((LM_ERROR,"%T |CC_DCCA_CFG| Key:%s Configuration not found\n", lKey.c_str() ));
		return false;
	}
	lData = stoi(it->second);

	if ( lData >= mMinVal && lData <= mMaxVal)
	{
		AAA_LOG((LM_INFO,"%T |CC_DCCA_CFG| Key:%s Data:%d Configuration found\n", lKey.c_str() , lData));
		return true;
	}

	AAA_LOG((LM_ERROR,"%T |CC_DCCA_CFG| Key:%s Data:%d Min:%d Max:%d .Invalid Configuration \n", lKey.c_str(), lData, mMinVal, mMaxVal ));
	lData = -1;
	return false;	
} 
