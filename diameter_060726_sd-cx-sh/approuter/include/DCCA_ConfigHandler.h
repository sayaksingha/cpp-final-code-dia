// @(#) $Id: DCCA_ConfigHandler.h,v 1.1.2.3 2021/11/26 04:18:43 anandhv Exp $
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
#ifndef  DCCA_CONFIG_HDLR_H
#define  DCCA_CONFIG_HDLR_H 

#include "DCCA_Header.h" 

class DCCA_ConfigHandler
{
	private:
		// Private so that it can  not be called
		DCCA_ConfigHandler();  

		// copy constructor is private
		DCCA_ConfigHandler(DCCA_ConfigHandler const&);             

		// assignment operator is private
		DCCA_ConfigHandler& operator=(DCCA_ConfigHandler const&);  

		//Member variables
		static mutex               				*mMutexLock;

		static DCCA_ConfigHandler     			*mDCCA_ConfigHandler;

		string 											mProductHome;

		string 											mProductCfgPath;

		string 											mApplnFileName;

		bool 												Decode( boost::property_tree::ptree pt );

		bool												LoadConfigurationFromFile();

		bool 												ReadStringCfg( string lKey, string &lData, int mMinLen, int mMaxLen);

		bool 												ReadIntegerCfg( string lKey, int &lData, int mMinVal, int mMaxMal);

		bool 												Init();

		map<string, string>     					mConfigMap;

	public:

		static DCCA_ConfigHandler*    			GetInstance();

		string 											mAvpFileName;
		string 											mAvpFilePath;		
		int                                    mApplnIdAvpCode;	
		bool                                   mRelaywithoutInitial;

		string 											mRedisUserName = "";
	   string 											mRedisPasswd = "";
};


#define DCCA_CONFIG_HDLR() DCCA_ConfigHandler::GetInstance()


#endif
