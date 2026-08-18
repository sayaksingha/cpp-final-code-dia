//----------------------------------------------------------------------
// NAME :  DraParser.cc
//
// COPYRIGHT :  Tayana Software Solutions Pvt Ltd -- Copyright(C) 2018
// 				 All rights reserved. No part of this computer program
// 				 may be used or reproduced in any form by any
// 				 means without prior written permission of
// 				 Tayana Software Solutions Pvt Ltd
//
// DESCRIPTION
//
// Originated :                                     Date:
//----------------------------------------------------------------------

#include "DraParser.h"


 //-------------------------------------------------------------------------------
 // METHOD      : DraParser 
 // DESCRIPTION :
 // PARAMETER   : no arguments
 // RETURN      : no return value
 // THROWS      : none
 //-------------------------------------------------------------------------------

DraParser::DraParser():
	_pLocator(0)
{
}

 //-------------------------------------------------------------------------------
 // METHOD      : 
 // DESCRIPTION :
 // PARAMETER   :
 // RETURN      : 
 // THROWS      : 
 //-------------------------------------------------------------------------------
DraParser::~DraParser()
{
}

 //-------------------------------------------------------------------------------
 // METHOD      : 
 // DESCRIPTION :
 // PARAMETER   :
 // RETURN      : 
 // THROWS      : 
 //-------------------------------------------------------------------------------
void DraParser::setDocumentLocator(const Locator* loc)
{
	_pLocator = loc;
}

 //-------------------------------------------------------------------------------
 // METHOD      : 
 // DESCRIPTION :
 // PARAMETER   :
 // RETURN      : 
 // THROWS      : 
 //-------------------------------------------------------------------------------
void DraParser::startDocument()
{
	mDictionary 	= false;
	mDebug			= 0;
	mReloadFlag		= 0;
}

 //-------------------------------------------------------------------------------
 // METHOD      : 
 // DESCRIPTION :
 // PARAMETER   :
 // RETURN      : 
 // THROWS      : 
 //-------------------------------------------------------------------------------
//Initialization of dictionary and Applicdation file
DraParser::DraParser( char* dictFile, char* appFile)
{
	mtx.lock();
	SAXParser parser;

	parser.setFeature(XMLReader::FEATURE_NAMESPACES, true);
	parser.setFeature(XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
	parser.setContentHandler(this);
	parser.setProperty(XMLReader::PROPERTY_LEXICAL_HANDLER, static_cast<LexicalHandler*>(this));


	mDictionaryDataMap.clear();
	mAVPPeerDataMap.clear();
	mAVPPeerDataList.clear();

	//printf("############################ Init Start ############################ \n");
	//printf("Starting %s File Parsing\n", dictFile);
	parser.parse(dictFile);
	//printf("Ending %s File Parsing\n", dictFile);
	//printf("Starting %s File Parsing\n", appFile);
	parser.parse(appFile);
	//printf("Ending %s File Parsing\n", appFile);
	//printf("############################ Init End ############################# \n");
	mtx.unlock();

	//return true;
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
bool DraParser::reload( char* dictFile, char* appFile)
{
	mtx.lock();
	try
	{
		SAXParser parser;

		parser.setFeature(XMLReader::FEATURE_NAMESPACES, true);
		parser.setFeature(XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
		parser.setContentHandler(this);
		parser.setProperty(XMLReader::PROPERTY_LEXICAL_HANDLER, static_cast<LexicalHandler*>(this));

		//	sleep(2);

		//Copy data to temp variable 
		mDictionaryDataMapTemp 	= mDictionaryDataMap;
		mApplicationDataTemp	  	= mApplicationData;

		mDictionaryDataMap.clear();
		mAVPPeerDataMap.clear();
		mAVPPeerDataList.clear();

		//-----------------------------------------------------------
		//Clear mApplicationData map and list
		mApplicationData.routingData.routingTypeNameList.clear();
		mApplicationData.routingData.avpRoutingMap.clear();
		mApplicationData.origRealm.clear();
		mApplicationData.origRealm.clear();
		mApplicationData.activePeerList.clear();
		mApplicationData.avpSupportedData.clear();
		mApplicationData.defaultForms.clear();
		mApplicationData.roundRobinForms.clear();
		mApplicationData.failOverForms.clear();
		mApplicationData.weightageForms.clear();
		mApplicationData.sessionMap.clear();
		mApplicationData.avpForms.clear();
		mApplicationData.avpFormsList.clear();
		mApplicationData.routingNameMap.clear();
		//-----------------------------------------------------------

		//printf("############################ Init Start ############################ \n");
		//printf("Starting %s File Parsing\n", dictFile);
		parser.parse(dictFile);
		//printf("Ending %s File Parsing\n", dictFile);
		//printf("Starting %s File Parsing\n", appFile);
		parser.parse(appFile);
		//printf("Ending %s File Parsing\n", appFile);
		//printf("############################ Init End ############################# \n");
	}
	catch(Poco::Exception& e)
	{
		//std::cerr << e.displayText() << std::endl;
		mApplicationData 		= mApplicationDataTemp;
		mDictionaryDataMap 	= mDictionaryDataMapTemp;
		mDictionaryDataMapTemp.clear();
	}
	mtx.unlock();

	//return true;
}
//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::endDocument()
{
	if(mDebug >= 1)
	{
		printData();
	}
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::startElement(const XMLString& uri, const XMLString& localName, const XMLString& qname, const Attributes& attributes)
{

	//===== Dictionary File ===============================
	int ret = strcmp(localName.c_str(), "avp");
	if(ret == 0)
	{
		mDictionary = true;

		string lTempCode(attributes.getValue("code"));
		mDictionaryData.avpCode 			= atoi(lTempCode.c_str());
		mDictionaryData.name					= attributes.getValue("name");
		mDictionaryData.mandatory			= attributes.getValue("mandatory");
		mDictionaryData.encrypt				= attributes.getValue("may-encrypt");
		mDictionaryData.vendorSpecific	= attributes.getValue("vendor-specific");
		mDictionaryData.protect				= attributes.getValue("protected");
	}

	int ret1 = strcmp(localName.c_str(), "type");
	int ret2 = strcmp(localName.c_str(), "grouped");

	if((ret1 == 0) && (mDictionary == true))
	{
		mDictionaryData.typeName         = attributes.getValue("type-name");
		mDictionaryDataMap.insert(make_pair(mDictionaryData.avpCode, mDictionaryData));
		mDictionary = false;
	}
	else if((ret2 == 0) && (mDictionary == true))
	{
		mDictionaryData.typeName = "grouped";
		mDictionaryDataMap.insert(make_pair(mDictionaryData.avpCode, mDictionaryData));
		mDictionary = false;
	}
	//=======================================================

	//=======================================================
	ret = strcmp(localName.c_str(), "CmdId");
	if(ret == 0)
	{
		mApplicationData.cmdId = atoi(attributes.getValue("id").c_str());
	}
	ret = strcmp(localName.c_str(), "AppId");
	if(ret == 0)
	{
		mApplicationData.appId = atoi(attributes.getValue("id").c_str());
	}
	//=======================================================

	//=======================================================
	ret = strcmp(localName.c_str(), "Activepeer");
	if(ret == 0)
	{
		ActivePeerData lActivePeerData;

		lActivePeerData.peerName 	= attributes.getValue("name");
		lActivePeerData.peerValue 	= attributes.getValue("value");
		mApplicationData.activePeerList.push_front(lActivePeerData);
		mApplicationData.activePeerMap[lActivePeerData.peerValue] = lActivePeerData.peerName;
	}

	ret = strcmp(localName.c_str(), "AvpCodePath");
	if(ret == 0)
	{
		AvpCodePathDet lAvpCodePathDet;

		lAvpCodePathDet.avpCode = atoi(attributes.getValue("code").c_str());
		lAvpCodePathDet.name = attributes.getValue("name");
		lAvpCodePathDet.applnId = atoi(attributes.getValue("application_id").c_str());
		
		//string lAvpCodePath = attributes.getValue("avp_code_path");

		stringstream ss( attributes.getValue("avp_code_path") );
		int key = 1;
		while( ss.good() )
		{
			string substr;
			getline( ss, substr, ':' );
			lAvpCodePathDet.avpCodePath.insert( make_pair(key, stoi(substr)));
			key++;
		}

		string lMapKey = std::to_string(lAvpCodePathDet.applnId)+"_"+std::to_string(lAvpCodePathDet.avpCode);
		mApplicationData.avpCodePathData.insert(make_pair(lMapKey,lAvpCodePathDet));
	}

	ret = strcmp(localName.c_str(), "DefautlPeer");
	if(ret == 0)
	{
		mApplicationData.defaultForms.insert(make_pair(attributes.getValue("name"), attributes.getValue("peer")));
	}
	//=======================================================

	//=======================================================
	ret = strcmp(localName.c_str(), "RoundRobin");
	if(ret == 0)
	{
		RRPeerData lRRPeerData;
		tokenizeData((char *)attributes.getValue("peer-list").c_str(), lRRPeerData.roundRobinPeerList);
		lRRPeerData.currentPeer 		= lRRPeerData.roundRobinPeerList.front();
		lRRPeerData.currentPeerIndx 	= 0; 

		mApplicationData.roundRobinForms.insert(make_pair(attributes.getValue("name"), lRRPeerData));
		mApplicationData.routingNameMap.insert(make_pair(attributes.getValue("name"), ROUND_ROBIN));
	}
	//=======================================================

	//=======================================================
	ret = strcmp(localName.c_str(), "FailOver");
	if(ret == 0)
	{
		FOPeerData	lFOPeerData;
		lFOPeerData.primaryPeer 		= attributes.getValue("primary");
		lFOPeerData.secondaryPeer	 	= attributes.getValue("secondary"); 

		mApplicationData.failOverForms.insert(make_pair(attributes.getValue("name"), lFOPeerData));
		mApplicationData.routingNameMap.insert(make_pair(attributes.getValue("name"), FAIL_OVER));
	}
	//=======================================================

	//=======================================================
	ret = strcmp(localName.c_str(), "Weightage");
	if(ret == 0)
	{
		mWeightageName = attributes.getValue("name");
		mWTPeerData.peerWeightage.clear();
	}
	ret = strcmp(localName.c_str(), "PeerWeight");
	if(ret == 0)
	{
		if(mWTPeerData.peerWeightage.size() == 0)
		{
			mWTPeerData.currentPeer = attributes.getValue("name");
			mWTPeerData.processedCnt = 0;
		}
		PeerWeightageData lPeerWeightageData;
		
		lPeerWeightageData.maxWeight 			= atoi(attributes.getValue("weight").c_str());
		lPeerWeightageData.processedWeight	= 0;
		lPeerWeightageData.skipPeer			= false;

		mWTPeerData.peerWeightage.insert(make_pair(attributes.getValue("name"), lPeerWeightageData));
	}
	//=======================================================

	//=======================================================
	ret = strcmp(localName.c_str(), "AVPList");
	if(ret == 0)
	{
		mAVPListName = attributes.getValue("name");
	}
	ret = strcmp(localName.c_str(), "AVPData");
	if(ret == 0)
	{
		AVPPeerData	lAVPPeerData;

		lAVPPeerData.avpName					= attributes.getValue("name");
		lAVPPeerData.avpValue				= attributes.getValue("value");
		lAVPPeerData.avpOperation			= attributes.getValue("operation");
		lAVPPeerData.code 					= atoi(attributes.getValue("code").c_str());

		mAVPPeerDataMap.insert(make_pair(atoi(attributes.getValue("code").c_str()), lAVPPeerData));
		mAVPPeerDataList.push_back(lAVPPeerData);

		// ------------- SupportedAVP --------------- //
		DictionaryData lDictionaryData;

		lDictionaryData.avpCode = atoi(attributes.getValue("code").c_str());
		map<int,DictionaryData>::iterator it = mDictionaryDataMap.find(lDictionaryData.avpCode);
		if(it != mDictionaryDataMap.end())
		{
			lDictionaryData = it->second;
			mApplicationData.avpSupportedData.insert(make_pair(lDictionaryData.avpCode, lDictionaryData));
		}
		// ------------- SupportedAVP --------------- //
	}
	//=======================================================

	//=======================================================
	ret = strcmp(localName.c_str(), "RoutingList");
	if(ret == 0)
	{
		mApplicationData.routingData.routingType 			= (EnumRoutingType) atoi(attributes.getValue("routingType").c_str());
	}

	ret = strcmp(localName.c_str(), "RoutingTypeName");
	if(ret == 0)
	{
		if(mApplicationData.routingData.routingType == AVP_BASED)
		{
			//tokenizeData((char *)attributes.getValue("routingTypeName").c_str(), mApplicationData.routingData.routingTypeNameList);
			mApplicationData.routingData.avpRoutingMap.insert(make_pair(attributes.getValue("name"), attributes.getValue("method")));
			//mApplicationData.routingData.methodName		 	= attributes.getValue("methodName");
		}
		else
		{
			mApplicationData.routingData.routingTypeName 	= attributes.getValue("name");
		}
	}

	ret = strcmp(localName.c_str(), "DefaultRouting");
	if(ret == 0)
	{
		mApplicationData.routingData.defaultRouting	 	= attributes.getValue("name");
	}

	ret = strcmp(localName.c_str(), "Debug");
	if(ret == 0)
	{
		mDebug = atoi(attributes.getValue("value").c_str());
	}

	ret = strcmp(localName.c_str(), "Reload");
	if(ret == 0)
	{
		mReloadFlag = atoi(attributes.getValue("value").c_str());
	}
	//=======================================================
}

void DraParser::endElement(const XMLString& uri, const XMLString& localName, const XMLString& qname)
{
	/*where("endElement--------------1");
	  std::cout << "uri:       " << uri << std::endl
	  << "localName: " << localName << std::endl
	  << "qname:     " << qname << std::endl;
	  where("endElement--------------2");*/

	int ret = strcmp(localName.c_str(), "Weightage");
	if(ret == 0)
	{
		mApplicationData.weightageForms.insert(make_pair(mWeightageName, mWTPeerData));
		mApplicationData.routingNameMap.insert(make_pair(mWeightageName, WEIGHTAGE));
		mWeightageName = "";
		mWTPeerData.peerWeightage.clear();
	}
	ret = strcmp(localName.c_str(), "AVPList");
	if(ret == 0)
	{
		mApplicationData.avpForms.insert(make_pair(mAVPListName, mAVPPeerDataMap));
		mApplicationData.avpFormsList.insert(make_pair(mAVPListName, mAVPPeerDataList));
		mApplicationData.routingNameMap.insert(make_pair(mAVPListName, AVP_BASED));//Required??
		mAVPPeerDataMap.clear();
		mAVPPeerDataList.clear();
		mAVPListName = "";
	}
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::characters(const XMLChar ch[], int start, int length)
{
	//		where("characters");
	//		std::cout << "Value:" << std::string(ch + start, length) << std::endl;
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::ignorableWhitespace(const XMLChar ch[], int start, int length)
{
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::processingInstruction(const XMLString& target, const XMLString& data)
{
	std::cout << "target=" << target << ", data=" << data << std::endl;
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::startPrefixMapping(const XMLString& prefix, const XMLString& uri)
{
	std::cout << "prefix=" << prefix << " uri=" << uri << std::endl;
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::endPrefixMapping(const XMLString& prefix)
{
	std::cout << "prefix=" << prefix << std::endl;
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::skippedEntity(const XMLString& name)
{
	std::cout << "name=" << name << std::endl;
}

// LexicalHandler
void DraParser::startDTD(const XMLString& name, const XMLString& publicId, const XMLString& systemId)
{
	where("startDTD");
}

void DraParser::endDTD()
{
	where("endDTD");
}

void DraParser::startEntity(const XMLString& name)
{
	where("startEntity");
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::endEntity(const XMLString& name)
{
	where("endEntity");
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::startCDATA()
{
	where("startCDATA");
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::endCDATA()
{
	where("endCDATA");
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::comment(const XMLChar ch[], int start, int length)
{
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------

void DraParser::where(const std::string& meth)
{
	std::cout << "*** " << meth;
	if (_pLocator)
	{
		std::cout << " in "
			<< _pLocator->getSystemId()
			<< ", line " << _pLocator->getLineNumber() 
			<< ", col " << _pLocator->getColumnNumber() 
			<< std::endl;
	}
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::tokenizeData(char * str, list<string> &rList)
{
	char * pch;
	pch = strtok (str,",");
	while (pch != NULL)
	{
		rList.push_back(pch);
		pch = strtok (NULL, ",");
	}
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::tokenizeData(char * str, int &key, DictionaryData &rDictionaryData)
{
	char * pch;
	int charCnt = 0;
	pch = strtok (str,",");
	while (pch != NULL)
	{
		string lTempData(pch);

		switch(charCnt)
		{
			case 0:
				key = atoi(pch);
				break;
			case 1:
				rDictionaryData.name = lTempData;	
				break;
			case 2:
				rDictionaryData.typeName = lTempData;	
				break;
			default:
				break;
		};
		charCnt++;
		pch = strtok (NULL, ",");
	}
}

//-------------------------------------------------------------------------------
// METHOD      : 
// DESCRIPTION :
// PARAMETER   :
// RETURN      : 
// THROWS      : 
//-------------------------------------------------------------------------------
void DraParser::printData()
{
	std::cout << "================================== DICTIONARY DATA ====================================================" << std::endl;
	for(map<int,DictionaryData>::iterator it = mDictionaryDataMap.begin(); it != mDictionaryDataMap.end(); ++it)
	{
		std::cout << "------------------------------------------------------------------------------------" << std::endl;
		std::cout << "CODE                  : " << it->first << std::endl;
		std::cout << "NAME                  : " << it->second.name << std::endl;
		std::cout << "MANDATORY             : " << it->second.mandatory << std::endl;
		std::cout << "ENCRYPT               : " << it->second.encrypt << std::endl;
		std::cout << "VENDOR-SPECIFIC       : " << it->second.vendorSpecific << std::endl;
		std::cout << "PROTECTED             : " << it->second.protect << std::endl;
		std::cout << "TYPE-NAME             : " << it->second.typeName << std::endl;
		std::cout << "------------------------------------------------------------------------------------" << std::endl;
	}
	std::cout << "================================ END DICTIONARY DATA ==================================================" << std::endl;
	std::cout << std::endl;


	std::cout << "==================================== APPLICATION DATA =================================================" << std::endl;

	std::cout << "CMD-ID                   : " << mApplicationData.cmdId << std::endl;
	std::cout << "APP-ID                   : " << mApplicationData.appId << std::endl;
	std::cout << "ROUTING-TYPE             : " << mApplicationData.routingData.routingType << std::endl;
	if(mApplicationData.routingData.routingType != AVP_BASED)
	{
		std::cout << "ROUTING-TYPE-NAME        : " << mApplicationData.routingData.routingTypeName << std::endl;
	}
	else
	{
		/*for(list<std::string>::iterator Iterator = mApplicationData.routingData.routingTypeNameList.begin(); Iterator != mApplicationData.routingData.routingTypeNameList.end(); Iterator++)
		  {
		  std::cout << "ROUTING-TYPE-NAME-LIST: " << *Iterator;
		  }*/
		for(map<std::string,std::string>::iterator Iterator = mApplicationData.routingData.avpRoutingMap.begin(); Iterator != mApplicationData.routingData.avpRoutingMap.end(); ++Iterator)
		{
			std::cout << "------------------------------------------------------------------------------------" << std::endl;
			std::cout << "NAME                  : " << Iterator->first << std::endl;
			std::cout << "METHOD                : " << Iterator->second << std::endl;
			std::cout << "------------------------------------------------------------------------------------" << std::endl;
		}
	}
	std::cout << "DEFAULT-ROUTING          : " << mApplicationData.routingData.defaultRouting << std::endl;

	std::cout << "------------------------------ ACTIVE PEER LIST ------------------------------------" << std::endl;
	for(list<ActivePeerData>::iterator Iterator = mApplicationData.activePeerList.begin(); Iterator != mApplicationData.activePeerList.end(); Iterator++)
	{
		std::cout << "PEER-NAME             : " << Iterator->peerName << std::endl;
		std::cout << "PEER-VALUE            : " << Iterator->peerValue << std::endl;
	}
	std::cout << "------------------------------ END ACTIVE PEER LIST --------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------ SUPPORTED AVP DATA ----------------------------------" << std::endl;
	for(map<int,DictionaryData>::iterator it = mApplicationData.avpSupportedData.begin(); it != mApplicationData.avpSupportedData.end(); ++it)
	{
		std::cout << "------------------------------------------------------------------------------------" << std::endl;
		std::cout << "CODE                  : " << it->first << std::endl;
		std::cout << "NAME                  : " << it->second.name << std::endl;
		std::cout << "MANDATORY             : " << it->second.mandatory << std::endl;
		std::cout << "ENCRYPT               : " << it->second.encrypt << std::endl;
		std::cout << "VENDOR-SPECIFIC       : " << it->second.vendorSpecific << std::endl;
		std::cout << "PROTECTED             : " << it->second.protect << std::endl;
		std::cout << "TYPE-NAME             : " << it->second.typeName << std::endl;
		std::cout << "------------------------------------------------------------------------------------" << std::endl;
	}
	std::cout << "------------------------------ END SUPPORTED AVP DATA ------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------- DEFAULT FORMS -------------------------------------" << std::endl;
	for(map<std::string,std::string>::iterator it = mApplicationData.defaultForms.begin(); it != mApplicationData.defaultForms.end(); ++it)
	{
		std::cout << "NAME                  : " << it->first << std::endl;
		std::cout << "PEER                  : " << it->second << std::endl;
	}
	std::cout << "------------------------------- END DEFAULT FORMS ---------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------- ROUND-ROBIN FORMS ---------------------------------" << std::endl;
	for(map<std::string,RRPeerData>::iterator it = mApplicationData.roundRobinForms.begin(); it != mApplicationData.roundRobinForms.end(); ++it)
	{
		std::cout << "*************************************************************************"<< std::endl;
		std::cout << "NAME               : " << it->first << std::endl;
		RRPeerData lRRPeerData 					= it->second;
		std::cout << "CURRENT-PEER       : " << lRRPeerData.currentPeer << std::endl;
		std::cout << "CURRENT-INDEX      : " << lRRPeerData.currentPeerIndx << std::endl;

		std::cout << "-------------------------------------------------------------------------" << std::endl;
		for(list<std::string>::iterator Iterator = lRRPeerData.roundRobinPeerList.begin(); Iterator != lRRPeerData.roundRobinPeerList.end(); ++Iterator)
		{
			std::cout << "PEER	            : " << *Iterator << std::endl;
		}
		std::cout << "-------------------------------------------------------------------------" << std::endl;
		std::cout << "*************************************************************************"<< std::endl;
	}
	std::cout << "------------------------------- END ROUND-ROBIN FORMS -----------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------- FAIL-OVER FORMS -----------------------------------" << std::endl;
	for(map<std::string,FOPeerData>::iterator it = mApplicationData.failOverForms.begin(); it != mApplicationData.failOverForms.end(); ++it)
	{
		std::cout << "*************************************************************************"<< std::endl;
		std::cout << "NAME               : " << it->first << std::endl;
		FOPeerData lFOPeerData				= it->second;
		std::cout << "PRIMARY            : " << lFOPeerData.primaryPeer << std::endl;
		std::cout << "SECONDARY          : " << lFOPeerData.secondaryPeer << std::endl;
		std::cout << "*************************************************************************"<< std::endl;
	}
	std::cout << "------------------------------- END FAIL-OVER FORMS -------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------- WEIGHTAGE FORMS -----------------------------------" << std::endl;
	for(map<std::string,WTPeerData>::iterator it = mApplicationData.weightageForms.begin(); it != mApplicationData.weightageForms.end(); ++it)
	{
		std::cout << "*************************************************************************"<< std::endl;
		std::cout << "NAME               : " << it->first << std::endl;
		WTPeerData lWTPeerData 				= it->second;
		std::cout << "CURRENT-PEER       : " << it->second.currentPeer << std::endl;
		std::cout << "PROCESSED-COUNT    : " << it->second.processedCnt << std::endl;

		std::cout << "-------------------------------------------------------------------------" << std::endl;
		for(map<std::string,PeerWeightageData>::iterator iter = lWTPeerData.peerWeightage.begin(); iter != lWTPeerData.peerWeightage.end(); ++iter)
		{
			std::cout << "NAME					: " << iter->first << std::endl;
			PeerWeightageData lPeerWeightageData = iter->second;
			std::cout << "WEIGHT					: " << lPeerWeightageData.maxWeight << std::endl;
			std::cout << "PROCESSED  			: " << lPeerWeightageData.processedWeight << std::endl;
			std::cout << "SKIP					: " << lPeerWeightageData.skipPeer << std::endl;
		}
		std::cout << "-------------------------------------------------------------------------" << std::endl;
		std::cout << "*************************************************************************"<< std::endl;
	}
	std::cout << "------------------------------- END WEIGHTAGE FORMS -------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------- AVP FORMS -----------------------------------------" << std::endl;
	for(map<std::string,std::map<int,AVPPeerData>>::iterator it = mApplicationData.avpForms.begin(); it != mApplicationData.avpForms.end(); ++it)
	{
		std::cout << "*************************************************************************"<< std::endl;
		std::cout << "NAME               : " << it->first << std::endl;
		std::map<int,AVPPeerData> lAVPPeerDataMap = it->second;

		for(map<int,AVPPeerData>::iterator iter = lAVPPeerDataMap.begin(); iter != lAVPPeerDataMap.end(); ++iter)
		{
			std::cout << "-------------------------------------------------------------------------" << std::endl;
			std::cout << "CODE					: " << iter->first << std::endl;
			AVPPeerData lAVPPeerData			= iter->second;
			std::cout << "NAME					: " << lAVPPeerData.avpName << std::endl;
			std::cout << "VALUE					: " << lAVPPeerData.avpValue << std::endl;
			std::cout << "OPERATION				: " << lAVPPeerData.avpOperation << std::endl;
			std::cout << "-------------------------------------------------------------------------" << std::endl;
		}
		std::cout << "*************************************************************************"<< std::endl;
	}

	std::cout << "------------------------------- AVP FORMS LIST-------------------------------------" << std::endl;
	for(map<std::string,std::list<AVPPeerData>>::iterator it = mApplicationData.avpFormsList.begin(); it != mApplicationData.avpFormsList.end(); ++it)
	{
		std::cout << "*************************************************************************"<< std::endl;
		std::cout << "NAME               : " << it->first << std::endl;
		std::list<AVPPeerData> lAVPPeerDataMap = it->second;

		for(list<AVPPeerData>::iterator iter = lAVPPeerDataMap.begin(); iter != lAVPPeerDataMap.end(); ++iter)
		{
			std::cout << "-------------------------------------------------------------------------" << std::endl;
			std::cout << "NAME                                      : " << iter->avpName << std::endl;
			std::cout << "VALUE                                     : " << iter->avpValue << std::endl;
			std::cout << "OPERATION                                 : " << iter->avpOperation << std::endl;
			std::cout << "-------------------------------------------------------------------------" << std::endl;
		}
		std::cout << "*************************************************************************"<< std::endl;
	}

	std::cout << "------------------------------- END AVP FORMS -------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------- ROUTING METHODS -----------------------------------" << std::endl;
	for(map<std::string,EnumRoutingType>::iterator it = mApplicationData.routingNameMap.begin(); it != mApplicationData.routingNameMap.end(); ++it)
	{
		std::cout << "*************************************************************************"<< std::endl;
		std::cout << "NAME               : " << it->first << std::endl;
		std::cout << "TYPE					: " << it->second << std::endl;
		std::cout << "*************************************************************************"<< std::endl;
	}
	std::cout << "------------------------------- END ROUTING METHODS -------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "=================================== END APPLICATION DATA ==============================================" << std::endl;
	std::cout << std::endl;

}
