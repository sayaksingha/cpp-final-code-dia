// @(#) $Id: DRA_ConfigHandler.h,v 1.1.2.12 2021/11/26 04:23:01 anandhv Exp $
//--------------------------------------------------------------------------------
// NAME           : BreRuleApi.h
//
// COPYRIGHT      : TSS -- Copyright (C) 2012 Tayana Software Solutions Pvt Ltd.,
//                  All rights reserved. No part of this computer program
//                  may be used or reproduced in any form by any
//                  means without prior written permission of
//                  Tayana Software Solutions Pvt Ltd.
//
// Originated     : Nandagopi 
//-------------------------------------------------------------------------------
#ifndef  DRA_CONFIG_HDLR_H
#define  DRA_CONFIG_HDLR_H 

#include "DRA_Http.h"

class DRA_ConfigHandler
{
	private:
		// Private so that it can  not be called
		DRA_ConfigHandler();  

		// copy constructor is private
		DRA_ConfigHandler(DRA_ConfigHandler const&);             

		// assignment operator is private
		DRA_ConfigHandler& operator=(DRA_ConfigHandler const&);  

		//Member variables
		static mutex               				*mMutexLock;

		static DRA_ConfigHandler     			   *mDRA_ConfigHandler;

		string 											mProductHome;

		string 											mProductCfgPath;

		string 											mApplnFileName;

		bool 												Decode( boost::property_tree::ptree pt );

		bool												LoadConfigurationFromFile();

		bool 												ReadStringCfg( string lKey, string &lData, int mMinLen, int mMaxLen);

		bool 												ReadIntegerCfg( string lKey, int &lData, int mMinVal, int mMaxMal);
		bool 												ReadIntegerCfgResultCodeMSCC( string lKey, int &lData, int mMinVal, int mMaxMal);

		bool 												Init();

		bool 												DecodeHttpHostConfig(string &lData);

		bool 												DecodeResultCode(string &lData);
		
		bool 												StrTokenizer(string lData);
		bool 												StrTokenMainResultCode(string lData);

		bool 												DecodeMSCC(boost::property_tree::ptree pt);
		map<string, string>     					mConfigMap;

	public:

		static DRA_ConfigHandler*    			   GetInstance();

		string 											mDRA_ApplnFilePath;
		string 											mDRA_ApplnFileName;

		string 											mDRA_HttpApplnFilePath;
		string 											mDRA_HttpApplnFileName;

		string 											mDiameterConfigFilePath;			
		string 											mDiameterConfigFileName;			
		string 											mDiameterCfgpcrfFleName;			

		string 											mRoutingFilePath;			
		string 											mRoutingFileName;			

		string 											mDictionaryFilePath;			
		string 											mDictionaryFileName;		
		
		string 											mTrafficFilePath;	

		map<int, std::shared_ptr<DRA_HttpHostInfo>> mHostMap;

		map<int, int>                          mResultCodeMap;
	
		map<string,int> 								mResultCodeMSCCMap;
		
		map<int,bool> 								   mResultCodeMSCCforPCRFMap;
		map<int,bool> 								   mResultCodeforPCRFMap;

	   map<int,bool>								   mApplicationIdMSCCMap;

		string 										   mOrignHostGSURegulerExp;

      string                                 mOHAsrRelayCfg;

		int 												mGSUccOutputOctet;
		int 												mGSUccInputOctet;
		int 												mVolumeQuotaThresholdPercentage;
		int 												mCCTotalOctetsThreshold;
		
		int 												mClientId;

		string 											mClientPwd;

		int 												mHttpClientUpccThreadSize;

		string											mUpccRechEvrFilePath;

		string											mOrignHostRegulerExp;

		int 												mStartUpccHttpFlg;
		
		int                                    mAndOrFlg;

		int                                    mMsccResultCodMapActiveFlag;
		int                                    mInputOutputOctetsActiveFlag;
		int                                    mVolumeQuotaThresholdActiveFlag;

		bool												mRelayDataOnErrToPcrfFlg;
		bool 												mRelayAsrToPcrfFlg;
	
		bool												mRelayMessagetopcrf;
		bool 												mWriteMessagetofile;
		bool 												mLPushtoRedis;
		bool 												mDoNotRelay_asr;
		bool 												mDrop_asr;
		string											mUpccCgiName;
		string											mOHForMsccEvr;
		
		bool 												mDetailedEvrFlag;
		bool 												mDetailedEvrOnTimeOutFlag;
		bool                                   mApplRoutingLogic;

		int                                 mNoOfPrcfNodes;
                string                              mDefPcrfNode;
};


#define DRA_CONFIG_HDLR() DRA_ConfigHandler::GetInstance()

#define DRA_MIN_STR_LEN            0
#define DRA_MAX_STR_LEN            200

#define DRA_MIN_AVP_VALUE          50000
#define DRA_MAX_AVP_VALUE          100000

#define DRA_MIN_HOST_STR_LEN       0
#define DRA_MAX_HOST_STR_LEN       2000

#define DRA_MIN_PWD_LEN            3
#define DRA_MAX_PWD_LEN            20

#define DRA_MIN_CID_VALUE          0
#define DRA_MAX_CID_VALUE          100000

#define DRA_MIN_HCU_SIZE           1
#define DRA_MAX_HCU_SIZE           50

#define DRA_MIN_BOOL_SIZE          0
#define DRA_MAX_BOOL_SIZE          1

#endif
