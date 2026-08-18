 // @(#) $Id: DraParser.h,v 1.1.2.2.2.3 2021/11/26 04:23:01 anandhv Exp $";
 //-----------------------------------------------------------------------------
 // NAME           :  DraParser.h
 //
 // COPYRIGHT      :  TSS - Copyright (C) 2009 Tayana Software Solution Pvt Ltd.,
 //                   All rights reserved. No part of this computer program
 //                   may be used or reproduced in any form by any
 //                   means without prior written permission of
 //                   Tayana Software Solution Pvt Ltd.
 //
 // DESCRIPTION
 //
 // Originated By  :                                                    Date:
 //---------------------------------------------------------------------------

#ifndef INCL_DRA_LIB_PARSE_H
#define INCL_DRA_LIB_PARSE_H

#include "TdraStructs.h"

using namespace std;

using Poco::XML::SAXParser;
using Poco::XML::XMLReader;
using Poco::XML::XMLString;
using Poco::XML::XMLChar;
using Poco::XML::ContentHandler;
using Poco::XML::LexicalHandler;
using Poco::XML::Attributes;
using Poco::XML::Locator;

//----------------------------------------
//To store dictionary data eg:GxDictionary_Release13.xml
struct DictionaryData
{
	int									avpCode;
	string								name;
	string								mandatory;
	string								encrypt;
	string								vendorSpecific;
	string								protect;
	string								typeName;
};

struct AvpCodePathDet
{
	int									avpCode;
	string								name;
	std::map<int, UINT32>			avpCodePath;
	int 									applnId;
};
//----------------------------------------

//----------------------------------------
// To store Routing XML Active Peer list
struct ActivePeerData
{
	string								peerName;
	string								peerValue;
};

struct RRPeerData
{
	std::list<std::string>        roundRobinPeerList;
	std::string                   currentPeer;
	int									currentPeerIndx;
};

struct FOPeerData
{
	std::string				        	primaryPeer;
	std::string        				secondaryPeer;
};

struct PeerWeightageData
{
	int		      							maxWeight;
	int											processedWeight;
	bool											skipPeer;
};

struct WTPeerData
{
	std::map<std::string,PeerWeightageData> 		peerWeightage;
	std::string                   					currentPeer;
	int														processedCnt;
	//static int									iteratorIndex;
};

struct AVPPeerData
{
	std::string										avpName;
	std::string										avpValue;
	std::string										avpOperation;
	int                                    code;
};

enum EnumRoutingType
{
	UNKNOWN		= 0,
	ROUND_ROBIN = 1,
	FAIL_OVER   = 2,
	WEIGHTAGE   = 3,
	AVP_BASED	= 4
};

struct RoutingData
{
	EnumRoutingType				routingType;
	std::string						routingTypeName;
	std::string						methodName;
	std::string						defaultRouting;
	std::list<std::string> 		routingTypeNameList;
	std::map<std::string,std::string> avpRoutingMap;
};

struct ApplicationData
{
	int															cmdId;
	int															appId;
	RoutingData													routingData;
	std::string													connectedPeer;
	std::list<std::string> 									origHostList;//Reserved
	std::list<std::string> 									origRealm;//Reserved

	std::list<ActivePeerData> 								activePeerList;
	std::map<std::string,std::string>					activePeerMap;

	std::map<int,DictionaryData>  						avpSupportedData;
	std::map<string,AvpCodePathDet>  				   avpCodePathData;
	std::map<std::string,std::string> 					defaultForms;
	std::map<std::string,RRPeerData>    				roundRobinForms;
	std::map<std::string,FOPeerData>    				failOverForms;
	std::map<std::string,WTPeerData>    				weightageForms;
	std::map<std::string,std::string>					sessionMap; //To Store SID and Method Name used
	std::map<std::string,std::map<int,AVPPeerData>> avpForms;
	std::map<std::string,std::list<AVPPeerData>>    avpFormsList;
	std::map<std::string, EnumRoutingType> 			routingNameMap;

};
//----------------------------------------


class DraParser: public ContentHandler, public LexicalHandler
{
	public:
		DraParser();
		~DraParser();
		DraParser(char* dictFile, char* appFile);

		short 			 mReloadFlag;
		
	protected:
		void setDocumentLocator(const Locator* loc);
		void startDocument();
		void endDocument();
		void startElement(const XMLString& uri, const XMLString& localName, const XMLString& qname, const Attributes& attributes);
		void endElement(const XMLString& uri, const XMLString& localName, const XMLString& qname);
		void characters(const XMLChar ch[], int start, int length);
		void ignorableWhitespace(const XMLChar ch[], int start, int length);
		void processingInstruction(const XMLString& target, const XMLString& data);
		void startPrefixMapping(const XMLString& prefix, const XMLString& uri);
		void endPrefixMapping(const XMLString& prefix);
		void skippedEntity(const XMLString& name);
		void startDTD(const XMLString& name, const XMLString& publicId, const XMLString& systemId);
		void endDTD();
		void startEntity(const XMLString& name);
		void endEntity(const XMLString& name);
		void startCDATA();
		void endCDATA();
		void comment(const XMLChar ch[], int start, int length);
		bool reload(char* dictFile, char* appFile);

	private:
		const Locator* 						_pLocator;

		std::mutex 								mtx;           // mutex for critical section


		void tokenizeData(char * str, list<string> &rList);
		void tokenizeData(char * str, int &key, DictionaryData &rDictionaryData);

	protected:

		bool		     							mDictionary;
		short 									mDebug;
		string									mWeightageName;
		string									mAVPListName;
		WTPeerData								mWTPeerData;
		DictionaryData							mDictionaryData;
		ApplicationData						mApplicationData;
		ApplicationData						mApplicationDataTemp;
		std::map<int,DictionaryData>    	mDictionaryDataMap;
		std::map<int,DictionaryData>    	mDictionaryDataMapTemp;
		std::map<int,AVPPeerData>			mAVPPeerDataMap;
		std::list<AVPPeerData>           mAVPPeerDataList;

		void 										printData();

	protected:

		void where(const std::string& meth);
};

#endif 
