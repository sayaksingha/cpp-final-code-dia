#include<DRA_ConfigHandler.h>

DRA_ConfigHandler*   DRA_ConfigHandler::mDRA_ConfigHandler = NULL;
mutex*          		 DRA_ConfigHandler::mMutexLock    		  = new mutex;
//-------------------------------------------------------------
// METHOD      : DRA_ConfigHandler()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
DRA_ConfigHandler::DRA_ConfigHandler()
{
}

//-------------------------------------------------------------
// METHOD      : DRA_ConfigHandler()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
DRA_ConfigHandler::DRA_ConfigHandler( DRA_ConfigHandler const& wicpExecuter)
{

}

//-------------------------------------------------------------
// METHOD      : DRA_ConfigHandler()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
DRA_ConfigHandler& DRA_ConfigHandler::operator=( DRA_ConfigHandler const& DRA_ConfigHandlerObj)
{
   DRA_ConfigHandler *DRA_ConfigHandlerPtr = new DRA_ConfigHandler();
   return  *DRA_ConfigHandlerPtr;
}


//-------------------------------------------------------------
// METHOD      : GetInstance()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
DRA_ConfigHandler* DRA_ConfigHandler::GetInstance()
{
	if( mDRA_ConfigHandler == NULL)
	{
		lock_guard<mutex> myLock(*mMutexLock);
		if ( mDRA_ConfigHandler == NULL)
		{
			mDRA_ConfigHandler = new DRA_ConfigHandler();
			mDRA_ConfigHandler->Init();
		}
	}
	return mDRA_ConfigHandler;
}

//-------------------------------------------------------------
// METHOD      : Init()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DRA_ConfigHandler::Init()
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

	mApplnFileName = "DRA_Configuration.json";
	if ( LoadConfigurationFromFile())
	{
		return true;
	}
	AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Error in reading DRA configuration\n"));
	return false;
}

//-------------------------------------------------------------
// METHOD      : Init()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DRA_ConfigHandler::LoadConfigurationFromFile()
{
	string filename = mProductHome + mProductCfgPath + mApplnFileName ;

	try
	{
		boost::property_tree::ptree pt;
		boost::property_tree::read_json(filename, pt);
		if (!Decode(pt))
		{
			AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Error in reading json DRA configuration\n"));
			return false;
		}
	}
	catch (std::exception const& e)
	{
		AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Exception cought err:%s . Error while reading json configuration\n", e.what() ));
	}

	//Read all configuration here.

	if ( !ReadStringCfg("DRA_APPLN_FILE_PATH", mDRA_ApplnFilePath, DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
	{
		//Invalid configuration
		return false;
	}

	if ( !ReadStringCfg("DRA_APPLN_FILE_NAME", mDRA_ApplnFileName, DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
	{
		//Invalid configuration
		return false;
	}

	if ( !ReadStringCfg("DRA_HTTP_APPLN_FILE_PATH", mDRA_HttpApplnFilePath, DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
	{
		//Invalid configuration
		return false;
	}

	if ( !ReadStringCfg("DRA_HTTP_APPLN_FILE_NAME", mDRA_HttpApplnFileName, DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
	{
		//Invalid configuration
		return false;
	}

	string lHttpHostCfg; 

	if ( !ReadStringCfg("DRA_UPCC_HOST_PORT_CONF", lHttpHostCfg, DRA_MIN_HOST_STR_LEN, DRA_MAX_HOST_STR_LEN))
	{
		//Invalid configuration
		return false;
	}

	string lResCodeList;
	if ( !ReadStringCfg("DRA_UPCC_RESULT_CODE_LIST", lResCodeList, DRA_MIN_HOST_STR_LEN, DRA_MAX_HOST_STR_LEN))
	{
		//Invalid configuration
		return false;
	}
	
	if (!this->DecodeResultCode(lResCodeList))
	{
		return false;
	}

	if (!this->DecodeHttpHostConfig(lHttpHostCfg))
	{
		return false;
	}

	if ( !ReadIntegerCfg("DRA_CLIENT_ID", mClientId, DRA_MIN_CID_VALUE, DRA_MAX_CID_VALUE))
	{
		//Invalid configuration
		return false;
	}

	if ( !ReadStringCfg("DRA_CLIENT_PWD", mClientPwd, DRA_MIN_PWD_LEN, DRA_MAX_PWD_LEN))
	{
		//Invalid configuration
		return false;
	}

	if ( !ReadIntegerCfg("DRA_UPCC_HTTP_CLIENT_THREAD_SIZE", mHttpClientUpccThreadSize, DRA_MIN_HCU_SIZE, DRA_MAX_HCU_SIZE))
	{
		//Invalid configuration
		return false;
	}

	if ( !ReadStringCfg("DRA_EVR_FILE_GEN_PATH", mUpccRechEvrFilePath, DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
	{
		//Invalid configuration
		return false;
	}

   if ( !ReadStringCfg("DRA_DIAMETER_FILE_PATH", mDiameterConfigFilePath , DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
   {
      //Invalid configuration
      return false;
   }

   if ( !ReadStringCfg("DRA_DIAMETER_FILE_NAME", mDiameterConfigFileName , DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
   {
      //Invalid configuration
      return false;
   }
   
	if ( !ReadStringCfg("DRA_PCRF_FILE_NAME", mDiameterCfgpcrfFleName , DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
   {
      //Invalid configuration
      return false;
   }


   if ( !ReadStringCfg("DRA_ROUTING_FILE_PATH", mRoutingFilePath , DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
   {
      //Invalid configuration
      return false;
   }

	if ( !ReadStringCfg("DRA_ROUTING_FILE_NAME", mRoutingFileName , DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
   {
      //Invalid configuration
      return false;
	}

   if ( !ReadStringCfg("DRA_DICTIONARY_FILE_PATH", mDictionaryFilePath , DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
   {
      //Invalid configuration
      return false;
   }

   if ( !ReadStringCfg("DRA_DICTIONARY_FILE_NAME", mDictionaryFileName , DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
   {
      //Invalid configuration
      return false;
	}

   if ( !ReadStringCfg("DRA_TRAFFIC_FILE_PATH", mTrafficFilePath , DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
   {
      //Invalid configuration
      return false;
   }
   
	if ( !ReadIntegerCfg("DRA_START_HTTP_UPCC_RELAY", mStartUpccHttpFlg, DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
	{
		//Invalid configuration
		mStartUpccHttpFlg = false;
	}

	if ( mStartUpccHttpFlg)
	{
		if ( !ReadStringCfg("DRA_UPCC_HTTP_CGI_NAME", mUpccCgiName, DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
		{
			//Invalid configuration
			return false;
		}
	}

	if ( !ReadIntegerCfg("DRA_CONFIG_MSCC_RESULT_MAPPING_ACTIVE", mMsccResultCodMapActiveFlag , DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
	{
		//Invalid configuration
		mMsccResultCodMapActiveFlag = false;
	}

	if (mMsccResultCodMapActiveFlag)
	{
		if ( !ReadIntegerCfg("DRA_CONFIG_AND_OR_MSCC", mAndOrFlg , DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
		{
			//Invalid configuration
			mAndOrFlg = 0;
		}

		if ( !ReadStringCfg("DRA_ORIGIN_HOST_MSCC", mOrignHostRegulerExp, DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
		{
			//Invalid configuration
			return false;
		}
	}

	if ( !ReadIntegerCfg("DRA_CONFIG_GSU_IN_OUT_OCTET_ACTIVE", mInputOutputOctetsActiveFlag , DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
	{
		mInputOutputOctetsActiveFlag = false;
	}

	if(mInputOutputOctetsActiveFlag)
	{
		if ( !ReadIntegerCfg("DRA_GSU_CCINPUT_OCTET", mGSUccInputOctet, DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
		{
			//Invalid configuration
			mGSUccInputOctet = 10000;
		}

		if ( !ReadIntegerCfg("DRA_GSU_CCOUTPUT_OCTET", mGSUccOutputOctet , DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
		{
			//Invalid configuration
			mGSUccOutputOctet = 10000;
		}
	}

	if ( !ReadIntegerCfg("DRA_GSU_VOLUME_QUOTA_THREAD_ACTIVE", mVolumeQuotaThresholdActiveFlag , DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
	{
		//Invalid configuration
		mVolumeQuotaThresholdActiveFlag = false; 
	}

	int lTempNum = 0; 
	if ( !ReadIntegerCfg("DRA_RELAY_MSG_TO_PCRF", lTempNum , DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
	{
		//Invalid configuration
		mRelayDataOnErrToPcrfFlg = false; 
	}
	else
	{
		mRelayDataOnErrToPcrfFlg = (bool)lTempNum; 
	}
	
	if (mRelayDataOnErrToPcrfFlg)
	{
		std::string lResultCodeMSCCforPCRFstr;
		if ( !ReadStringCfg("DRA_RESULT_CODE_MSCC_PCRF",lResultCodeMSCCforPCRFstr , DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
		{
			//Invalid configuration
			return false;
		}
		this->StrTokenizer(lResultCodeMSCCforPCRFstr);

		std::string lResultCodeforPCRFstr;
                if ( !ReadStringCfg("DRA_RESULT_CODE_PCRF",lResultCodeforPCRFstr , DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
                {
                        //Invalid configuration
                        return false;
                }
                this->StrTokenMainResultCode(lResultCodeforPCRFstr);	

		lTempNum = 0;
		if ( !ReadIntegerCfg("DRA_ASR_RL_PCRF_FLAG", lTempNum, DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
		{
			mRelayAsrToPcrfFlg = false; 
		}
		else
		{
			mRelayAsrToPcrfFlg = (bool)lTempNum;
		}

		lTempNum = 0;
		if ( !ReadIntegerCfg("DRA_RELAY_PCRF_FLAG", lTempNum, DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
		{
			mRelayMessagetopcrf = false;
		}
		else
		{
			mRelayMessagetopcrf = (bool)lTempNum;
		}

		lTempNum = 0;
		if ( !ReadIntegerCfg("DRA_WRITE_TO_FILE_FLAG", lTempNum, DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
		{
			mWriteMessagetofile = false;
		}
		else
		{
			mWriteMessagetofile = (bool)lTempNum;
		}
		
		lTempNum = 0;
		if ( !ReadIntegerCfg("DRA_PCRF_PUSH_TO_REDIS_FLAG", lTempNum, DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
		{
			mLPushtoRedis = false;
		}
		else
		{
			mLPushtoRedis = (bool)lTempNum;
		}
		
		lTempNum = 0;
                if ( !ReadIntegerCfg("DRA_PCRF_NO_OF_NODES", lTempNum, DRA_MIN_BOOL_SIZE, DRA_MAX_STR_LEN))
                {
                        mNoOfPrcfNodes = 0;
                }
                else
                {
                        mNoOfPrcfNodes = (bool)lTempNum;
			if(mNoOfPrcfNodes)
			{
				if ( !ReadStringCfg("DRA_PCRF_DEFAULT_NODE", mDefPcrfNode, DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
				{
					return false;
				}
			}
                }
	}
	else
	{
		mLPushtoRedis = false;
		mWriteMessagetofile = false;
		mRelayMessagetopcrf = false;
		mRelayAsrToPcrfFlg  = false;
	}

	lTempNum = 0;
	if ( !ReadIntegerCfg("DRA_DONOT_RELAY_ASR_FLAG", lTempNum, DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
	{
		mDoNotRelay_asr = false;
	}
	else
	{
		mDoNotRelay_asr = (bool)lTempNum;

		lTempNum = 0;
		if ( !ReadIntegerCfg("DRA_DROP_ASR_FLAG", lTempNum, DRA_MIN_BOOL_SIZE, DRA_MAX_BOOL_SIZE))
		{
			mDrop_asr = false;
		}
		else
		{
			mDrop_asr = (bool)lTempNum;
		}

	}

	if ( mInputOutputOctetsActiveFlag  || mVolumeQuotaThresholdActiveFlag || mRelayDataOnErrToPcrfFlg)
	{
		if ( !ReadStringCfg("DRA_ORIGIN_HOST_MSCC_GSU", mOrignHostGSURegulerExp, DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
		{
			//Invalid configuration
			return false;
		}
	}
	
	if ( !ReadStringCfg("DRA_ORIGIN_HOST_FOR_ASR_DROP", mOHAsrRelayCfg, DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
	{
		//Invalid configuration
		return false;
	}

	if (mVolumeQuotaThresholdActiveFlag)
	{
		if ( !ReadIntegerCfg("DRA_GSU_VOLUME_QUOTA_THREAD_PERCENT", mVolumeQuotaThresholdPercentage , DRA_MIN_BOOL_SIZE, 100))
		{
			//Invalid configuration
			mVolumeQuotaThresholdPercentage = 10;
		}

		if ( !ReadIntegerCfg("DRA_GSU_TOTAL_OCTETS_THRESHOLD", mCCTotalOctetsThreshold , -1, 100000000))
		{
			//Invalid configuration
			mCCTotalOctetsThreshold = 200;
		}

	}

	int lTemp=0;
	if ( !ReadIntegerCfg("DRA_MSCC_EVR_INFO", lTemp , DRA_MIN_BOOL_SIZE, 1))
	{
		//Invalid configuration
		mDetailedEvrFlag = false;
	}
	else
	{
		mDetailedEvrFlag = (bool)lTemp;
	}
	
	lTemp=0;
   if ( !ReadIntegerCfg("DRA_MSCC_EVR_INFO_ON_TIMEOUT", lTemp , DRA_MIN_BOOL_SIZE, 1))
   {
      //Invalid configuration
      mDetailedEvrOnTimeOutFlag = false;
   }
   else
   {
      mDetailedEvrOnTimeOutFlag = (bool)lTemp;
   }

	if(mDetailedEvrFlag)
	{
		if ( !ReadStringCfg("DRA_ORIGIN_HOST_FOR_MSCC_EVR", mOHForMsccEvr, DRA_MIN_STR_LEN, DRA_MAX_STR_LEN))
		{
			//Invalid configuration
			return false;
		}
	}

	lTemp = 1;
	if ( !ReadIntegerCfg("DRA_APPLY_ROUTING_LOGIC_NEW", lTemp , DRA_MIN_BOOL_SIZE, 100))
	{
		mApplRoutingLogic = true;
	}
	else
	{
		mApplRoutingLogic = (bool)lTemp;
	}
	
	//-----------
	try
	{
		boost::property_tree::ptree pt;
		boost::property_tree::read_json(filename, pt);
		if (!DecodeMSCC(pt))
		{
			AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Error in reading json DRA configuration\n"));
			return false;
		}
	}
	catch (std::exception const& e)
	{
		AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Exception cought err:%s . Error while reading json configuration\n", e.what() ));
	}

	return true;
}
//-------------------------------------------------------------
// METHOD      : DecodeHttpHostConfig
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DRA_ConfigHandler::StrTokenizer(string lData)
{
	boost::char_separator<char> sep(",");

	boost::tokenizer<boost::char_separator<char>> tokens(lData, sep);
	for (const auto& t : tokens) {
		try{
			int  lNum    = stoi(t);
			bool lvalue  = true;
			//lList.push_back(lNum);

			auto it = mResultCodeMSCCforPCRFMap.find(lNum);

			if ( it == mResultCodeMSCCforPCRFMap.end())
			{
				mResultCodeMSCCforPCRFMap.insert(make_pair(lNum ,lvalue));
			}
			else
			{
				mResultCodeMSCCforPCRFMap.erase(it);
				mResultCodeMSCCforPCRFMap.insert(make_pair(lNum ,lvalue));
			}
		}
		catch(...){
		}
	}
	return true;
}
bool DRA_ConfigHandler::StrTokenMainResultCode(string lData)
{
	boost::char_separator<char> sep(",");

        boost::tokenizer<boost::char_separator<char>> tokens(lData, sep);
        for (const auto& t : tokens) {
                try{
                        int  lNum    = stoi(t);
                        bool lvalue  = true;
                        //lList.push_back(lNum);

                        auto it = mResultCodeforPCRFMap.find(lNum);

                        if ( it == mResultCodeforPCRFMap.end())
                        {
                                mResultCodeforPCRFMap.insert(make_pair(lNum ,lvalue));
                        }
                        else
                        {
                                mResultCodeforPCRFMap.erase(it);
                                mResultCodeforPCRFMap.insert(make_pair(lNum ,lvalue));
                        }
                }
                catch(...){
                }
        }
        return true;
}

//-------------------------------------------------------------
// METHOD      : DecodeHttpHostConfig
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DRA_ConfigHandler::DecodeHttpHostConfig(string &lData)
{
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;

	boost::char_separator<char> lHostDetSep{","};

	tokenizer tok{lData, lHostDetSep};

	boost::char_separator<char> lDataSep{":"};

	int lKey = 1;
	for (const auto &t : tok)
	{
		tokenizer itok{ t, lDataSep};
		int count  = 1;
		std::shared_ptr<DRA_HttpHostInfo> lHttpHostInfo (new DRA_HttpHostInfo());

		for (const auto &it : itok)
		{
			switch(count)
			{
				case 1:
					{
						lHttpHostInfo->mHostIp = it;
					}
					break;
				case 2:
					{
						lHttpHostInfo->mPort = it;
					}
					break;
				case 3:
					{
						if ( it.compare("1") == 0)
						{
							lHttpHostInfo->mPostFlg = true;
						}
					}
					break;
				case 4:
					{
						if ( it.compare("1") == 0)
						{
							lHttpHostInfo->mSSLFlg = true;
						}
					}
					break;
				case 5:
					{
						if ( it.compare("1.0") == 0)
						{
							lHttpHostInfo->mHttpVer = 10;
						}
						else
						{
							lHttpHostInfo->mHttpVer = 11;
						}
					}
					break;
			}
			count++;
		}
		mHostMap.insert(make_pair(lKey, lHttpHostInfo));
		lKey++;

		if ( lKey > 2)
		{
			break;
		}
	}

	if (mHostMap.size() > 0)
	{
		return true;
	}

	AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Key:DRA_UPCC_HOST_PORT_CONF Host Configuration decode error\n" ));
	return false;
}

//-------------------------------------------------------------
// METHOD      : DecodeResultCode() 
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DRA_ConfigHandler::DecodeResultCode(string &lData)
{
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	boost::char_separator<char> lDataSep{":"};
	tokenizer tok{lData, lDataSep};

	for (const auto &resultCode : tok)
	{
		int lResultCode = stoi(resultCode);
		mResultCodeMap.insert(make_pair(lResultCode, lResultCode));
	}

	if (mResultCodeMap.size() > 0)
	{
		return true;
	}

	AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Key: Host Configuration decode error\n" ));
	return false;
}

//-------------------------------------------------------------
// METHOD      : Decode
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DRA_ConfigHandler::Decode( boost::property_tree::ptree pt)
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

	mApplicationIdMSCCMap.clear();
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("DRA_APPLICATION_ID_MSCC"))
	{
		int lkey   = stoi(v.first);
		int lvalue = stoi(v.second.data());
		auto it = mApplicationIdMSCCMap.find(lkey);

		if ( it == mApplicationIdMSCCMap.end())
		{
			mApplicationIdMSCCMap.insert(make_pair(lkey ,lvalue));
		}
		else
		{
			mApplicationIdMSCCMap.erase(it);
			mApplicationIdMSCCMap.insert(make_pair(lkey ,lvalue));
		}
	}
	return true;
}

//-------------------------------------------------------------
// METHOD      : DecodeMSCC
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------

bool DRA_ConfigHandler::DecodeMSCC( boost::property_tree::ptree pt)
{
	mResultCodeMSCCMap.clear();
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("DRA_RESULT_CODE_MSCC"))
	{
		//int lkey = stoi(v.first);
		string lkey = (v.first);
		int lvalue = stoi(v.second.data());
		auto it = mResultCodeMSCCMap.find(lkey);

		if ( it == mResultCodeMSCCMap.end())
		{
			mResultCodeMSCCMap.insert(make_pair(lkey ,lvalue));
		}
		else
		{
			mResultCodeMSCCMap.erase(it);
			mResultCodeMSCCMap.insert(make_pair(lkey ,lvalue));
		}
	}
	
	/*mResultCodeMSCCforPCRFMap.clear();
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("DRA_RESULT_CODE_MSCC_PCRF"))
	{
		//int lkey = stoi(v.first);
		int lkey = stoi(v.first);
		bool lvalue = stoi(v.second.data());
		auto it = mResultCodeMSCCforPCRFMap.find(lkey);

		if ( it == mResultCodeMSCCforPCRFMap.end())
		{
			mResultCodeMSCCforPCRFMap.insert(make_pair(lkey ,lvalue));
		}
		else
		{
			mResultCodeMSCCforPCRFMap.erase(it);
			mResultCodeMSCCforPCRFMap.insert(make_pair(lkey ,lvalue));
		}
	}
	*/
	return true;
}

bool DRA_ConfigHandler::ReadIntegerCfgResultCodeMSCC( string lKey, int &lData, int mMinVal, int mMaxVal)
{
	auto it =  mResultCodeMSCCMap.find(lKey);

	if ( it ==  mResultCodeMSCCMap.end())
	{
		AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Key:%s Configuration not found\n", lKey.c_str()));
		return false;
	}
	lData = it->second;

	if ( lData >= mMinVal && lData <= mMaxVal)
	{
		AAA_LOG((LM_INFO,"%T |CC_DRA_CFG| Key:%s Data:%d Configuration found\n", lKey.c_str() , lData));
		return true;
	}

	AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Key:%s Data:%d Min:%d Max:%d .Invalid Configuration \n", lKey.c_str(), lData, mMinVal, mMaxVal ));
	lData = -1;
	return false;
}



//-------------------------------------------------------------
// METHOD      : ReadStringCfg()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
bool DRA_ConfigHandler::ReadStringCfg( string lKey, string &lData, int mMinLen, int mMaxLen)
{
	auto it = mConfigMap.find(lKey);

	if ( it == mConfigMap.end())
	{
		AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Key:%s Configuration not found\n", lKey.c_str() ));
		return false;
	}
	lData = it->second;

	if ( lData.length() >= mMinLen && lData.length() <= mMaxLen)
	{
		AAA_LOG((LM_INFO,"%T |CC_DRA_CFG| Key:%s Data:%s Configuration found\n", lKey.c_str() , lData.c_str()));
		return true;
	}

	AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Key:%s Data:%s Min:%d Max:%d .Invalid Configuration \n", lKey.c_str(), lData.c_str(), mMinLen, mMaxLen ));
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
bool DRA_ConfigHandler::ReadIntegerCfg( string lKey, int &lData, int mMinVal, int mMaxVal)
{
	auto it = mConfigMap.find(lKey);

	if ( it == mConfigMap.end())
	{
		AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Key:%s Configuration not found\n", lKey.c_str() ));
		return false;
	}
	lData = stoi(it->second);

	if ( lData >= mMinVal && lData <= mMaxVal)
	{
		AAA_LOG((LM_INFO,"%T |CC_DRA_CFG| Key:%s Data:%d Configuration found\n", lKey.c_str() , lData));
		return true;
	}

	AAA_LOG((LM_ERROR,"%T |CC_DRA_CFG| Key:%s Data:%d Min:%d Max:%d .Invalid Configuration \n", lKey.c_str(), lData, mMinVal, mMaxVal ));
	lData = -1;
	return false;	
} 
