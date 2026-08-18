#include "sd/include/EventReportIndication.h"

using namespace SD;
BOOLEAN EventReportIndication::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

EventReportIndication::EventReportIndication()
{
	mANTrusted = NULL;
	mEventTriggerList = NULL;
	mUserCSGInformationGrp = NULL;
	mIPCANType = NULL;
	mANGWAddressList = NULL;
	m3GPPSGSNAddress = NULL;
	m3GPPSGSNIPv6Address = NULL;
	m3GPPSGSNMCCMNC = NULL;
	mFramedIPAddress = NULL;
	mRATType = NULL;
	mRAI = NULL;
	m3GPPUserLocationInfo = NULL;
	mTraceDataGrp = NULL;
	mTraceReference = NULL;
	m3GPP2BSID = NULL;
	m3GPPMSTimeZone = NULL;
	mRoutingRuleIdentifier = NULL;
	mUELocalIPAddress = NULL;
	mHeNBLocalIPAddress = NULL;
	mUDPSourcePort = NULL;
	mPresenceReportingAreaInformationGrp = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<21>(string("000000111000100001111"));
	mMandatoryAvpSetVal.reset();
}

EventReportIndication::~EventReportIndication()
{
	if(mANTrusted != NULL)
		delete mANTrusted;
	if(mEventTriggerList != NULL){
		mEventTriggerIterator = mEventTriggerList->begin();
		while(mEventTriggerIterator != mEventTriggerList->end()){
			delete (*mEventTriggerIterator);
			mEventTriggerIterator++;
		}
		delete mEventTriggerList;
	}
	if(mUserCSGInformationGrp != NULL)
		delete mUserCSGInformationGrp;
	if(mIPCANType != NULL)
		delete mIPCANType;
	if(mANGWAddressList != NULL){
		mANGWAddressIterator = mANGWAddressList->begin();
		while(mANGWAddressIterator != mANGWAddressList->end()){
			delete (*mANGWAddressIterator);
			mANGWAddressIterator++;
		}
		delete mANGWAddressList;
	}
	if(m3GPPSGSNAddress != NULL)
		delete m3GPPSGSNAddress;
	if(m3GPPSGSNIPv6Address != NULL)
		delete m3GPPSGSNIPv6Address;
	if(m3GPPSGSNMCCMNC != NULL)
		delete m3GPPSGSNMCCMNC;
	if(mFramedIPAddress != NULL)
		delete mFramedIPAddress;
	if(mRATType != NULL)
		delete mRATType;
	if(mRAI != NULL)
		delete mRAI;
	if(m3GPPUserLocationInfo != NULL)
		delete m3GPPUserLocationInfo;
	if(mTraceDataGrp != NULL)
		delete mTraceDataGrp;
	if(mTraceReference != NULL)
		delete mTraceReference;
	if(m3GPP2BSID != NULL)
		delete m3GPP2BSID;
	if(m3GPPMSTimeZone != NULL)
		delete m3GPPMSTimeZone;
	if(mRoutingRuleIdentifier != NULL)
		delete mRoutingRuleIdentifier;
	if(mUELocalIPAddress != NULL)
		delete mUELocalIPAddress;
	if(mHeNBLocalIPAddress != NULL)
		delete mHeNBLocalIPAddress;
	if(mUDPSourcePort != NULL)
		delete mUDPSourcePort;
	if(mPresenceReportingAreaInformationGrp != NULL)
		delete mPresenceReportingAreaInformationGrp;
}

ANTrusted* EventReportIndication::setANTrusted(){
	mMandatoryAvpSetVal [EventReportIndication_ANTRUSTED] = 1;
	if(mANTrusted == NULL)
	{
		mANTrusted = new ANTrusted();
		mTagsPresent[EventReportIndication_ANTRUSTED] = 1;
		return mANTrusted;
	}
	return mANTrusted;
}

void EventReportIndication::resetANTrusted(){
	mTagsPresent[EventReportIndication_ANTRUSTED] = 0;
	if(mANTrusted != NULL)
	{
		delete mANTrusted; 
		mANTrusted = NULL;
	}
}

IPCANType* EventReportIndication::setIPCANType(){
	mMandatoryAvpSetVal [EventReportIndication_IPCANTYPE] = 1;
	if(mIPCANType == NULL)
	{
		mIPCANType = new IPCANType();
		mTagsPresent[EventReportIndication_IPCANTYPE] = 1;
		return mIPCANType;
	}
	return mIPCANType;
}

void EventReportIndication::resetIPCANType(){
	mTagsPresent[EventReportIndication_IPCANTYPE] = 0;
	if(mIPCANType != NULL)
	{
		delete mIPCANType; 
		mIPCANType = NULL;
	}
}

OctetString* EventReportIndication::set3GPPSGSNAddress(){
	if(m3GPPSGSNAddress == NULL)
	{
		m3GPPSGSNAddress = new OctetString();
		mTagsPresent[EventReportIndication_3GPPSGSNADDRESS] = 1;
		return m3GPPSGSNAddress;
	}
	return m3GPPSGSNAddress;
}

void EventReportIndication::reset3GPPSGSNAddress(){
	mTagsPresent[EventReportIndication_3GPPSGSNADDRESS] = 0;
	if(m3GPPSGSNAddress != NULL)
	{
		delete m3GPPSGSNAddress; 
		m3GPPSGSNAddress = NULL;
	}
}

OctetString* EventReportIndication::set3GPPSGSNIPv6Address(){
	if(m3GPPSGSNIPv6Address == NULL)
	{
		m3GPPSGSNIPv6Address = new OctetString();
		mTagsPresent[EventReportIndication_3GPPSGSNIPV6ADDRESS] = 1;
		return m3GPPSGSNIPv6Address;
	}
	return m3GPPSGSNIPv6Address;
}

void EventReportIndication::reset3GPPSGSNIPv6Address(){
	mTagsPresent[EventReportIndication_3GPPSGSNIPV6ADDRESS] = 0;
	if(m3GPPSGSNIPv6Address != NULL)
	{
		delete m3GPPSGSNIPv6Address; 
		m3GPPSGSNIPv6Address = NULL;
	}
}

OctetString* EventReportIndication::set3GPPSGSNMCCMNC(){
	if(m3GPPSGSNMCCMNC == NULL)
	{
		m3GPPSGSNMCCMNC = new OctetString();
		mTagsPresent[EventReportIndication_3GPPSGSNMCCMNC] = 1;
		return m3GPPSGSNMCCMNC;
	}
	return m3GPPSGSNMCCMNC;
}

void EventReportIndication::reset3GPPSGSNMCCMNC(){
	mTagsPresent[EventReportIndication_3GPPSGSNMCCMNC] = 0;
	if(m3GPPSGSNMCCMNC != NULL)
	{
		delete m3GPPSGSNMCCMNC; 
		m3GPPSGSNMCCMNC = NULL;
	}
}

OctetString* EventReportIndication::setFramedIPAddress(){
	mMandatoryAvpSetVal [EventReportIndication_FRAMEDIPADDRESS] = 1;
	if(mFramedIPAddress == NULL)
	{
		mFramedIPAddress = new OctetString();
		mTagsPresent[EventReportIndication_FRAMEDIPADDRESS] = 1;
		return mFramedIPAddress;
	}
	return mFramedIPAddress;
}

void EventReportIndication::resetFramedIPAddress(){
	mTagsPresent[EventReportIndication_FRAMEDIPADDRESS] = 0;
	if(mFramedIPAddress != NULL)
	{
		delete mFramedIPAddress; 
		mFramedIPAddress = NULL;
	}
}

RATType* EventReportIndication::setRATType(){
	if(mRATType == NULL)
	{
		mRATType = new RATType();
		mTagsPresent[EventReportIndication_RATTYPE] = 1;
		return mRATType;
	}
	return mRATType;
}

void EventReportIndication::resetRATType(){
	mTagsPresent[EventReportIndication_RATTYPE] = 0;
	if(mRATType != NULL)
	{
		delete mRATType; 
		mRATType = NULL;
	}
}

OctetString* EventReportIndication::setRAI(){
	if(mRAI == NULL)
	{
		mRAI = new OctetString();
		mTagsPresent[EventReportIndication_RAI] = 1;
		return mRAI;
	}
	return mRAI;
}

void EventReportIndication::resetRAI(){
	mTagsPresent[EventReportIndication_RAI] = 0;
	if(mRAI != NULL)
	{
		delete mRAI; 
		mRAI = NULL;
	}
}

OctetString* EventReportIndication::set3GPPUserLocationInfo(){
	if(m3GPPUserLocationInfo == NULL)
	{
		m3GPPUserLocationInfo = new OctetString();
		mTagsPresent[EventReportIndication_3GPPUSERLOCATIONINFO] = 1;
		return m3GPPUserLocationInfo;
	}
	return m3GPPUserLocationInfo;
}

void EventReportIndication::reset3GPPUserLocationInfo(){
	mTagsPresent[EventReportIndication_3GPPUSERLOCATIONINFO] = 0;
	if(m3GPPUserLocationInfo != NULL)
	{
		delete m3GPPUserLocationInfo; 
		m3GPPUserLocationInfo = NULL;
	}
}

OctetString* EventReportIndication::setTraceReference(){
	mMandatoryAvpSetVal [EventReportIndication_TRACEREFERENCE] = 1;
	if(mTraceReference == NULL)
	{
		mTraceReference = new OctetString();
		mTagsPresent[EventReportIndication_TRACEREFERENCE] = 1;
		return mTraceReference;
	}
	return mTraceReference;
}

void EventReportIndication::resetTraceReference(){
	mTagsPresent[EventReportIndication_TRACEREFERENCE] = 0;
	if(mTraceReference != NULL)
	{
		delete mTraceReference; 
		mTraceReference = NULL;
	}
}

OctetString* EventReportIndication::set3GPP2BSID(){
	mMandatoryAvpSetVal [EventReportIndication_3GPP2BSID] = 1;
	if(m3GPP2BSID == NULL)
	{
		m3GPP2BSID = new OctetString();
		mTagsPresent[EventReportIndication_3GPP2BSID] = 1;
		return m3GPP2BSID;
	}
	return m3GPP2BSID;
}

void EventReportIndication::reset3GPP2BSID(){
	mTagsPresent[EventReportIndication_3GPP2BSID] = 0;
	if(m3GPP2BSID != NULL)
	{
		delete m3GPP2BSID; 
		m3GPP2BSID = NULL;
	}
}

OctetString* EventReportIndication::set3GPPMSTimeZone(){
	if(m3GPPMSTimeZone == NULL)
	{
		m3GPPMSTimeZone = new OctetString();
		mTagsPresent[EventReportIndication_3GPPMSTIMEZONE] = 1;
		return m3GPPMSTimeZone;
	}
	return m3GPPMSTimeZone;
}

void EventReportIndication::reset3GPPMSTimeZone(){
	mTagsPresent[EventReportIndication_3GPPMSTIMEZONE] = 0;
	if(m3GPPMSTimeZone != NULL)
	{
		delete m3GPPMSTimeZone; 
		m3GPPMSTimeZone = NULL;
	}
}

OctetString* EventReportIndication::setRoutingRuleIdentifier(){
	if(mRoutingRuleIdentifier == NULL)
	{
		mRoutingRuleIdentifier = new OctetString();
		mTagsPresent[EventReportIndication_ROUTINGRULEIDENTIFIER] = 1;
		return mRoutingRuleIdentifier;
	}
	return mRoutingRuleIdentifier;
}

void EventReportIndication::resetRoutingRuleIdentifier(){
	mTagsPresent[EventReportIndication_ROUTINGRULEIDENTIFIER] = 0;
	if(mRoutingRuleIdentifier != NULL)
	{
		delete mRoutingRuleIdentifier; 
		mRoutingRuleIdentifier = NULL;
	}
}

Address* EventReportIndication::setUELocalIPAddress(){
	if(mUELocalIPAddress == NULL)
	{
		mUELocalIPAddress = new Address();
		mTagsPresent[EventReportIndication_UELOCALIPADDRESS] = 1;
		return mUELocalIPAddress;
	}
	return mUELocalIPAddress;
}

void EventReportIndication::resetUELocalIPAddress(){
	mTagsPresent[EventReportIndication_UELOCALIPADDRESS] = 0;
	if(mUELocalIPAddress != NULL)
	{
		delete mUELocalIPAddress; 
		mUELocalIPAddress = NULL;
	}
}

Address* EventReportIndication::setHeNBLocalIPAddress(){
	if(mHeNBLocalIPAddress == NULL)
	{
		mHeNBLocalIPAddress = new Address();
		mTagsPresent[EventReportIndication_HENBLOCALIPADDRESS] = 1;
		return mHeNBLocalIPAddress;
	}
	return mHeNBLocalIPAddress;
}

void EventReportIndication::resetHeNBLocalIPAddress(){
	mTagsPresent[EventReportIndication_HENBLOCALIPADDRESS] = 0;
	if(mHeNBLocalIPAddress != NULL)
	{
		delete mHeNBLocalIPAddress; 
		mHeNBLocalIPAddress = NULL;
	}
}

Unsigned32* EventReportIndication::setUDPSourcePort(){
	if(mUDPSourcePort == NULL)
	{
		mUDPSourcePort = new Unsigned32();
		mTagsPresent[EventReportIndication_UDPSOURCEPORT] = 1;
		return mUDPSourcePort;
	}
	return mUDPSourcePort;
}

void EventReportIndication::resetUDPSourcePort(){
	mTagsPresent[EventReportIndication_UDPSOURCEPORT] = 0;
	if(mUDPSourcePort != NULL)
	{
		delete mUDPSourcePort; 
		mUDPSourcePort = NULL;
	}
}

ANTrusted* EventReportIndication::getANTrusted(){
	if(NULL == mANTrusted) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ANTrusted is Null");
		throw lTssDiaMsgException;
	}
	if(!mANTrusted->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mANTrusted->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ANTrusted is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mANTrusted->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mANTrusted->Decode(mspByteArray.get(), mANTrusted->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ANTrusted")     ;
			throw lTssDiaMsgException;
		}
		mANTrusted->mAvpDecodedFlag = true;
	}
	return mANTrusted;
}

list<EventTrigger*>* EventReportIndication::getEventTriggerList()
{
	if(mEventTriggerList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventTrigger is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr :* mEventTriggerList)
	{
		if(!itr->mAvpDecodedFlag)
		{
	if(mspByteArray.get() == NULL)
		{
	itr->mAvpDecodedFlag = true;
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventTrigger is Null");
		throw lTssDiaMsgException;
	}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventTrigger")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mEventTriggerList;
}

list<EventTrigger*>* EventReportIndication::setEventTriggerList() {
	mTagsPresent[EventReportIndication_EVENTTRIGGER] = 1;
	if(mEventTriggerList == NULL)
		mEventTriggerList = new list<EventTrigger*>;
	mMandatoryAvpSetVal [EventReportIndication_EVENTTRIGGER] = 1;
	mEventTriggerList->clear();
	return mEventTriggerList;
}

void EventReportIndication::resetEventTriggerList(){
	mTagsPresent[EventReportIndication_EVENTTRIGGER] = 0;
	if(mEventTriggerList != NULL)
		delete mEventTriggerList;
}

UserCSGInformation* EventReportIndication::getUserCSGInformation()
{
	if(mUserCSGInformationGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserCSGInformation is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserCSGInformationGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserCSGInformationGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserCSGInformation is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserCSGInformationGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserCSGInformationGrp->Decode(mspByteArray.get(), mUserCSGInformationGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserCSGInformation")     ;
			throw lTssDiaMsgException;
		}
		mUserCSGInformationGrp->mAvpDecodedFlag = true;
	}
	return mUserCSGInformationGrp;
}

UserCSGInformation* EventReportIndication::setUserCSGInformation(){
	if(mUserCSGInformationGrp == NULL)
		mUserCSGInformationGrp = new UserCSGInformation();
	mTagsPresent[EventReportIndication_USERCSGINFORMATION] = 1;
	mMandatoryAvpSetVal[EventReportIndication_USERCSGINFORMATION] = 1;
	return mUserCSGInformationGrp;
}

void EventReportIndication::resetUserCSGInformation(){
	mTagsPresent[EventReportIndication_USERCSGINFORMATION] = 0;
	if(mUserCSGInformationGrp != NULL)
		delete mUserCSGInformationGrp;
}

IPCANType* EventReportIndication::getIPCANType(){
	if(NULL == mIPCANType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IPCANType is Null");
		throw lTssDiaMsgException;
	}
	if(!mIPCANType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mIPCANType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IPCANType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mIPCANType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mIPCANType->Decode(mspByteArray.get(), mIPCANType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IPCANType")     ;
			throw lTssDiaMsgException;
		}
		mIPCANType->mAvpDecodedFlag = true;
	}
	return mIPCANType;
}

list<Address*>* EventReportIndication::getANGWAddressList()
{
	if(mANGWAddressList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ANGWAddress is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mANGWAddressList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ANGWAddress is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ANGWAddress")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mANGWAddressList;
}

list<Address*>* EventReportIndication::setANGWAddressList() {
	mTagsPresent[EventReportIndication_ANGWADDRESS] = 1;
	if(mANGWAddressList == NULL)
		mANGWAddressList = new list<Address*>;
	mANGWAddressList->clear();
	return mANGWAddressList;
}

void EventReportIndication::resetANGWAddressList(){
	mTagsPresent[EventReportIndication_ANGWADDRESS] = 0;
	if(mANGWAddressList != NULL)
		delete mANGWAddressList;
}

OctetString* EventReportIndication::get3GPPSGSNAddress(){
	if(NULL == m3GPPSGSNAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPSGSNAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPSGSNAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPSGSNAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPSGSNAddress->Decode(mspByteArray.get(), m3GPPSGSNAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNAddress")     ;
			throw lTssDiaMsgException;
		}
		m3GPPSGSNAddress->mAvpDecodedFlag = true;
	}
	return m3GPPSGSNAddress;
}

OctetString* EventReportIndication::get3GPPSGSNIPv6Address(){
	if(NULL == m3GPPSGSNIPv6Address) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNIPv6Address is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPSGSNIPv6Address->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPSGSNIPv6Address->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNIPv6Address is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPSGSNIPv6Address->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPSGSNIPv6Address->Decode(mspByteArray.get(), m3GPPSGSNIPv6Address->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNIPv6Address")     ;
			throw lTssDiaMsgException;
		}
		m3GPPSGSNIPv6Address->mAvpDecodedFlag = true;
	}
	return m3GPPSGSNIPv6Address;
}

OctetString* EventReportIndication::get3GPPSGSNMCCMNC(){
	if(NULL == m3GPPSGSNMCCMNC) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNMCCMNC is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPSGSNMCCMNC->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPSGSNMCCMNC->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPSGSNMCCMNC is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPSGSNMCCMNC->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPSGSNMCCMNC->Decode(mspByteArray.get(), m3GPPSGSNMCCMNC->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNMCCMNC")     ;
			throw lTssDiaMsgException;
		}
		m3GPPSGSNMCCMNC->mAvpDecodedFlag = true;
	}
	return m3GPPSGSNMCCMNC;
}

OctetString* EventReportIndication::getFramedIPAddress(){
	if(NULL == mFramedIPAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FramedIPAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!mFramedIPAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFramedIPAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FramedIPAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFramedIPAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFramedIPAddress->Decode(mspByteArray.get(), mFramedIPAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FramedIPAddress")     ;
			throw lTssDiaMsgException;
		}
		mFramedIPAddress->mAvpDecodedFlag = true;
	}
	return mFramedIPAddress;
}

RATType* EventReportIndication::getRATType(){
	if(NULL == mRATType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RATType is Null");
		throw lTssDiaMsgException;
	}
	if(!mRATType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRATType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RATType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRATType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRATType->Decode(mspByteArray.get(), mRATType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RATType")     ;
			throw lTssDiaMsgException;
		}
		mRATType->mAvpDecodedFlag = true;
	}
	return mRATType;
}

OctetString* EventReportIndication::getRAI(){
	if(NULL == mRAI) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RAI is Null");
		throw lTssDiaMsgException;
	}
	if(!mRAI->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRAI->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RAI is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRAI->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRAI->Decode(mspByteArray.get(), mRAI->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RAI")     ;
			throw lTssDiaMsgException;
		}
		mRAI->mAvpDecodedFlag = true;
	}
	return mRAI;
}

OctetString* EventReportIndication::get3GPPUserLocationInfo(){
	if(NULL == m3GPPUserLocationInfo) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPUserLocationInfo is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPUserLocationInfo->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPUserLocationInfo->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPUserLocationInfo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPUserLocationInfo->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPUserLocationInfo->Decode(mspByteArray.get(), m3GPPUserLocationInfo->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPUserLocationInfo")     ;
			throw lTssDiaMsgException;
		}
		m3GPPUserLocationInfo->mAvpDecodedFlag = true;
	}
	return m3GPPUserLocationInfo;
}

TraceData* EventReportIndication::getTraceData()
{
	if(mTraceDataGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceData is Null");
		throw lTssDiaMsgException;
	}
	if(!mTraceDataGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTraceDataGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceData is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTraceDataGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTraceDataGrp->Decode(mspByteArray.get(), mTraceDataGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceData")     ;
			throw lTssDiaMsgException;
		}
		mTraceDataGrp->mAvpDecodedFlag = true;
	}
	return mTraceDataGrp;
}

TraceData* EventReportIndication::setTraceData(){
	if(mTraceDataGrp == NULL)
		mTraceDataGrp = new TraceData();
	mTagsPresent[EventReportIndication_TRACEDATA] = 1;
	mMandatoryAvpSetVal[EventReportIndication_TRACEDATA] = 1;
	return mTraceDataGrp;
}

void EventReportIndication::resetTraceData(){
	mTagsPresent[EventReportIndication_TRACEDATA] = 0;
	if(mTraceDataGrp != NULL)
		delete mTraceDataGrp;
}

OctetString* EventReportIndication::getTraceReference(){
	if(NULL == mTraceReference) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceReference is Null");
		throw lTssDiaMsgException;
	}
	if(!mTraceReference->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTraceReference->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TraceReference is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTraceReference->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTraceReference->Decode(mspByteArray.get(), mTraceReference->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceReference")     ;
			throw lTssDiaMsgException;
		}
		mTraceReference->mAvpDecodedFlag = true;
	}
	return mTraceReference;
}

OctetString* EventReportIndication::get3GPP2BSID(){
	if(NULL == m3GPP2BSID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPP2BSID is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPP2BSID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPP2BSID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPP2BSID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPP2BSID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPP2BSID->Decode(mspByteArray.get(), m3GPP2BSID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPP2BSID")     ;
			throw lTssDiaMsgException;
		}
		m3GPP2BSID->mAvpDecodedFlag = true;
	}
	return m3GPP2BSID;
}

OctetString* EventReportIndication::get3GPPMSTimeZone(){
	if(NULL == m3GPPMSTimeZone) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPMSTimeZone is Null");
		throw lTssDiaMsgException;
	}
	if(!m3GPPMSTimeZone->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			m3GPPMSTimeZone->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "3GPPMSTimeZone is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = m3GPPMSTimeZone->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(m3GPPMSTimeZone->Decode(mspByteArray.get(), m3GPPMSTimeZone->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPMSTimeZone")     ;
			throw lTssDiaMsgException;
		}
		m3GPPMSTimeZone->mAvpDecodedFlag = true;
	}
	return m3GPPMSTimeZone;
}

OctetString* EventReportIndication::getRoutingRuleIdentifier(){
	if(NULL == mRoutingRuleIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RoutingRuleIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mRoutingRuleIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRoutingRuleIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RoutingRuleIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRoutingRuleIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRoutingRuleIdentifier->Decode(mspByteArray.get(), mRoutingRuleIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RoutingRuleIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mRoutingRuleIdentifier->mAvpDecodedFlag = true;
	}
	return mRoutingRuleIdentifier;
}

Address* EventReportIndication::getUELocalIPAddress(){
	if(NULL == mUELocalIPAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UELocalIPAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!mUELocalIPAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUELocalIPAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UELocalIPAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUELocalIPAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUELocalIPAddress->Decode(mspByteArray.get(), mUELocalIPAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UELocalIPAddress")     ;
			throw lTssDiaMsgException;
		}
		mUELocalIPAddress->mAvpDecodedFlag = true;
	}
	return mUELocalIPAddress;
}

Address* EventReportIndication::getHeNBLocalIPAddress(){
	if(NULL == mHeNBLocalIPAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "HeNBLocalIPAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!mHeNBLocalIPAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mHeNBLocalIPAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "HeNBLocalIPAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mHeNBLocalIPAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mHeNBLocalIPAddress->Decode(mspByteArray.get(), mHeNBLocalIPAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding HeNBLocalIPAddress")     ;
			throw lTssDiaMsgException;
		}
		mHeNBLocalIPAddress->mAvpDecodedFlag = true;
	}
	return mHeNBLocalIPAddress;
}

Unsigned32* EventReportIndication::getUDPSourcePort(){
	if(NULL == mUDPSourcePort) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UDPSourcePort is Null");
		throw lTssDiaMsgException;
	}
	if(!mUDPSourcePort->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUDPSourcePort->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UDPSourcePort is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUDPSourcePort->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUDPSourcePort->Decode(mspByteArray.get(), mUDPSourcePort->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UDPSourcePort")     ;
			throw lTssDiaMsgException;
		}
		mUDPSourcePort->mAvpDecodedFlag = true;
	}
	return mUDPSourcePort;
}

PresenceReportingAreaInformation* EventReportIndication::getPresenceReportingAreaInformation()
{
	if(mPresenceReportingAreaInformationGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaInformation is Null");
		throw lTssDiaMsgException;
	}
	if(!mPresenceReportingAreaInformationGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPresenceReportingAreaInformationGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PresenceReportingAreaInformation is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPresenceReportingAreaInformationGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPresenceReportingAreaInformationGrp->Decode(mspByteArray.get(), mPresenceReportingAreaInformationGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaInformation")     ;
			throw lTssDiaMsgException;
		}
		mPresenceReportingAreaInformationGrp->mAvpDecodedFlag = true;
	}
	return mPresenceReportingAreaInformationGrp;
}

PresenceReportingAreaInformation* EventReportIndication::setPresenceReportingAreaInformation(){
	if(mPresenceReportingAreaInformationGrp == NULL)
		mPresenceReportingAreaInformationGrp = new PresenceReportingAreaInformation();
	mTagsPresent[EventReportIndication_PRESENCEREPORTINGAREAINFORMATION] = 1;
	return mPresenceReportingAreaInformationGrp;
}

void EventReportIndication::resetPresenceReportingAreaInformation(){
	mTagsPresent[EventReportIndication_PRESENCEREPORTINGAREAINFORMATION] = 0;
	if(mPresenceReportingAreaInformationGrp != NULL)
		delete mPresenceReportingAreaInformationGrp;
}



int EventReportIndication::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case EventReportIndication_ANTRUSTED:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1503);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mANTrusted->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mANTrusted->getAvpOffsetLen().first], mANTrusted->getAvpOffsetLen().second);
						array->offset += mANTrusted->getAvpOffsetLen().second;
						array->size += mANTrusted->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ANTrusted");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mANTrusted->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ANTrusted");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_EVENTTRIGGER:
			{
					if( mEventTriggerList->size() <= 0) {
						break;
					}

					mEventTriggerIterator = this->getEventTriggerList()->begin();
					while(mEventTriggerIterator != mEventTriggerList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1006);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
 					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!(*mEventTriggerIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mEventTriggerIterator)->getAvpOffsetLen().first], (*mEventTriggerIterator)->getAvpOffsetLen().second);
						array->offset += (*mEventTriggerIterator)->getAvpOffsetLen().second;
						array->size += (*mEventTriggerIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventTrigger");
							throw lTssDiaMsgException;
						}
						mEventTriggerIterator++;
						continue;
					}
					if(((*mEventTriggerIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventTrigger");
						throw lTssDiaMsgException;
					}
					mEventTriggerIterator++;
				}
				}
				break;
			case EventReportIndication_USERCSGINFORMATION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(2319);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
				array->size++;
				array->byte[array->offset++] = 192;
				lengthOffset = array->offset; 
				array->offset += 3; 
				array->size += 3; 
				if( true == DiameterTLVUtil::isVenderSpecific(192))
 						{ 
						INT32 venderId=10415;
					array->size+=4;
					lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
						array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
				} 
				if((this->getUserCSGInformation()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserCSGInformation");
					throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_IPCANTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1027);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mIPCANType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mIPCANType->getAvpOffsetLen().first], mIPCANType->getAvpOffsetLen().second);
						array->offset += mIPCANType->getAvpOffsetLen().second;
						array->size += mIPCANType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IPCANType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mIPCANType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IPCANType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_ANGWADDRESS:
			{
					if( mANGWAddressList->size() <= 0) {
						break;
					}

					mANGWAddressIterator = this->getANGWAddressList()->begin();
					while(mANGWAddressIterator != mANGWAddressList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1050);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
 					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!(*mANGWAddressIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mANGWAddressIterator)->getAvpOffsetLen().first], (*mANGWAddressIterator)->getAvpOffsetLen().second);
						array->offset += (*mANGWAddressIterator)->getAvpOffsetLen().second;
						array->size += (*mANGWAddressIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mANGWAddressIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mANGWAddressIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_TIME_LEN)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ANGWAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mANGWAddressIterator++;
						continue;
					}
						if(((*mANGWAddressIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mANGWAddressIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ANGWAddress");
							throw lTssDiaMsgException;
						}
						mANGWAddressIterator++;
				}
				}
				break;
			case EventReportIndication_3GPPSGSNADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(6);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!m3GPPSGSNAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPSGSNAddress->getAvpOffsetLen().first], m3GPPSGSNAddress->getAvpOffsetLen().second);
						array->offset += m3GPPSGSNAddress->getAvpOffsetLen().second;
						array->size += m3GPPSGSNAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPSGSNAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPSGSNAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPSGSNAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPSGSNAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_3GPPSGSNIPV6ADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(15);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!m3GPPSGSNIPv6Address->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPSGSNIPv6Address->getAvpOffsetLen().first], m3GPPSGSNIPv6Address->getAvpOffsetLen().second);
						array->offset += m3GPPSGSNIPv6Address->getAvpOffsetLen().second;
						array->size += m3GPPSGSNIPv6Address->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPSGSNIPv6Address->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPSGSNIPv6Address->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNIPv6Address");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPSGSNIPv6Address->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPSGSNIPv6Address->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNIPv6Address");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_3GPPSGSNMCCMNC:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(18);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!m3GPPSGSNMCCMNC->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPSGSNMCCMNC->getAvpOffsetLen().first], m3GPPSGSNMCCMNC->getAvpOffsetLen().second);
						array->offset += m3GPPSGSNMCCMNC->getAvpOffsetLen().second;
						array->size += m3GPPSGSNMCCMNC->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPSGSNMCCMNC->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPSGSNMCCMNC->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNMCCMNC");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPSGSNMCCMNC->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPSGSNMCCMNC->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPSGSNMCCMNC");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_FRAMEDIPADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(8);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mFramedIPAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFramedIPAddress->getAvpOffsetLen().first], mFramedIPAddress->getAvpOffsetLen().second);
						array->offset += mFramedIPAddress->getAvpOffsetLen().second;
						array->size += mFramedIPAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mFramedIPAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mFramedIPAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FramedIPAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mFramedIPAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mFramedIPAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FramedIPAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_RATTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1032);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mRATType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRATType->getAvpOffsetLen().first], mRATType->getAvpOffsetLen().second);
						array->offset += mRATType->getAvpOffsetLen().second;
						array->size += mRATType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RATType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRATType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RATType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_RAI:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(909);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mRAI->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRAI->getAvpOffsetLen().first], mRAI->getAvpOffsetLen().second);
						array->offset += mRAI->getAvpOffsetLen().second;
						array->size += mRAI->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRAI->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRAI->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RAI");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRAI->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRAI->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RAI");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_3GPPUSERLOCATIONINFO:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(22);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!m3GPPUserLocationInfo->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPUserLocationInfo->getAvpOffsetLen().first], m3GPPUserLocationInfo->getAvpOffsetLen().second);
						array->offset += m3GPPUserLocationInfo->getAvpOffsetLen().second;
						array->size += m3GPPUserLocationInfo->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPUserLocationInfo->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPUserLocationInfo->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPUserLocationInfo");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPUserLocationInfo->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPUserLocationInfo->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPUserLocationInfo");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_TRACEDATA:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(1458);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
				array->size++;
				array->byte[array->offset++] = 192;
				lengthOffset = array->offset; 
				array->offset += 3; 
				array->size += 3; 
				if( true == DiameterTLVUtil::isVenderSpecific(192))
 						{ 
						INT32 venderId=10415;
					array->size+=4;
					lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
						array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
				} 
				if((this->getTraceData()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceData");
					throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_TRACEREFERENCE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1459);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mTraceReference->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTraceReference->getAvpOffsetLen().first], mTraceReference->getAvpOffsetLen().second);
						array->offset += mTraceReference->getAvpOffsetLen().second;
						array->size += mTraceReference->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTraceReference->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTraceReference->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceReference");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTraceReference->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTraceReference->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TraceReference");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_3GPP2BSID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(9010);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
					{ 
						INT32 venderId=5535;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!m3GPP2BSID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPP2BSID->getAvpOffsetLen().first], m3GPP2BSID->getAvpOffsetLen().second);
						array->offset += m3GPP2BSID->getAvpOffsetLen().second;
						array->size += m3GPP2BSID->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPP2BSID->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPP2BSID->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPP2BSID");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPP2BSID->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPP2BSID->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPP2BSID");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_3GPPMSTIMEZONE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(23);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!m3GPPMSTimeZone->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[m3GPPMSTimeZone->getAvpOffsetLen().first], m3GPPMSTimeZone->getAvpOffsetLen().second);
						array->offset += m3GPPMSTimeZone->getAvpOffsetLen().second;
						array->size += m3GPPMSTimeZone->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( m3GPPMSTimeZone->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(m3GPPMSTimeZone->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPMSTimeZone");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((m3GPPMSTimeZone->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, m3GPPMSTimeZone->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding 3GPPMSTimeZone");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_ROUTINGRULEIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1077);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mRoutingRuleIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRoutingRuleIdentifier->getAvpOffsetLen().first], mRoutingRuleIdentifier->getAvpOffsetLen().second);
						array->offset += mRoutingRuleIdentifier->getAvpOffsetLen().second;
						array->size += mRoutingRuleIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRoutingRuleIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRoutingRuleIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RoutingRuleIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRoutingRuleIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRoutingRuleIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RoutingRuleIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_UELOCALIPADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2805);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mUELocalIPAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUELocalIPAddress->getAvpOffsetLen().first], mUELocalIPAddress->getAvpOffsetLen().second);
						array->offset += mUELocalIPAddress->getAvpOffsetLen().second;
						array->size += mUELocalIPAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUELocalIPAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUELocalIPAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_TIME_LEN)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UELocalIPAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUELocalIPAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUELocalIPAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UELocalIPAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_HENBLOCALIPADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2804);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mHeNBLocalIPAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mHeNBLocalIPAddress->getAvpOffsetLen().first], mHeNBLocalIPAddress->getAvpOffsetLen().second);
						array->offset += mHeNBLocalIPAddress->getAvpOffsetLen().second;
						array->size += mHeNBLocalIPAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mHeNBLocalIPAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mHeNBLocalIPAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_TIME_LEN)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding HeNBLocalIPAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mHeNBLocalIPAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mHeNBLocalIPAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding HeNBLocalIPAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_UDPSOURCEPORT:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2806);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mUDPSourcePort->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUDPSourcePort->getAvpOffsetLen().first], mUDPSourcePort->getAvpOffsetLen().second);
						array->offset += mUDPSourcePort->getAvpOffsetLen().second;
						array->size += mUDPSourcePort->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UDPSourcePort");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mUDPSourcePort->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UDPSourcePort");
						throw lTssDiaMsgException;
					}
				}
				break;
			case EventReportIndication_PRESENCEREPORTINGAREAINFORMATION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(2822);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
				array->size++;
				array->byte[array->offset++] = 128;
				lengthOffset = array->offset; 
				array->offset += 3; 
				array->size += 3; 
				if( true == DiameterTLVUtil::isVenderSpecific(128))
 						{ 
						INT32 venderId=10415;
					array->size+=4;
					lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
						array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
				} 
				if((this->getPresenceReportingAreaInformation()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PresenceReportingAreaInformation");
					throw lTssDiaMsgException;
					}
				}
				break;
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);
					throw lTssDiaMsgException;
				break;
		}
	}


	return DIAMETER_NO_ERR;
}


int EventReportIndication::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
{
	mDecodeFlag = true;
	while( lMsgLen > 0)
	{
		UINT32  lAvpCode;
		UINT8   lAvpFlag = 0;
		UINT32  lAvpLen = 0;
		UINT32  lVenderId = 0;
		UINT32  lAvpHeaderLen = 8;
		UINT32  lAvpDataLen = 0;
		if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpCode, DIA_AVP_CODE_SIZE))
		{
			mDecodeFlag = false;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP code");
			throw lTssDiaMsgException;
		}
		memcpy( &lAvpFlag, &array->byte[array->offset++],sizeof(UINT8));
		if(false == DiameterTLVUtil::decodeAvpCmdIntegerValue(array, lAvpLen, DIA_AVP_LEN_SIZE))
		{
			mDecodeFlag = false;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP length");
			throw lTssDiaMsgException;
		}
		if(lAvpLen == 0)
		{
			mDecodeFlag = false;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP length");
			throw lTssDiaMsgException;
		}
		if( true == DiameterTLVUtil::isVenderSpecific(lAvpFlag))
		{ 
			lAvpHeaderLen = 12;
			if(false == DiameterTLVUtil::decodeIntegerValue(array, lVenderId, DIA_VENDER_SPEC_APPLN_ID_SIZE))
			{
				mDecodeFlag = false;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Vendor Id");
				throw lTssDiaMsgException;
			}

		}
		lAvpDataLen = lAvpLen-lAvpHeaderLen;
		switch(lAvpCode)
		{
			case 1503:
				{
						mMandatoryAvpSetVal [EventReportIndication_ANTRUSTED] = 1;
					if( NULL == this->setANTrusted())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ANTrusted");
						throw lTssDiaMsgException;
					}
					mANTrusted->setAvpCode(1503);
					mANTrusted->setAvpVendorId(lVenderId);
					mANTrusted->SetDataType((DiameterDataType)7);
					mANTrusted->mspByteArray = mspByteArray;
					mANTrusted->mAvpDecodedFlag = false;
					mANTrusted->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1006:
				{
						mMandatoryAvpSetVal [EventReportIndication_EVENTTRIGGER] = 1;
					mTagsPresent[EventReportIndication_EVENTTRIGGER] = 1;
					EventTrigger *lEventTrigger = new EventTrigger();
					if( lEventTrigger == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventTrigger");
						throw lTssDiaMsgException;
					}
					lEventTrigger->setAvpCode(1006);
					lEventTrigger->setAvpVendorId(lVenderId);
					lEventTrigger->SetDataType((DiameterDataType)7);
					lEventTrigger->mspByteArray = mspByteArray;
					lEventTrigger->mAvpDecodedFlag = false;
					lEventTrigger->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mEventTriggerList == NULL)
						this->setEventTriggerList();
					mEventTriggerList->push_back(lEventTrigger);
					
				}
				break;
			case 2319:
				{
						mMandatoryAvpSetVal [EventReportIndication_USERCSGINFORMATION] = 1;
					mTagsPresent[EventReportIndication_USERCSGINFORMATION] = 1;
						if( NULL == this->setUserCSGInformation()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserCSGInformation");
						throw lTssDiaMsgException;
						}
					mUserCSGInformationGrp->setAvpCode(2319);
					mUserCSGInformationGrp->SetDataType((DiameterDataType)6);
					mUserCSGInformationGrp->mspByteArray = mspByteArray;
					mUserCSGInformationGrp->mAvpDecodedFlag = false;
					mUserCSGInformationGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mUserCSGInformationGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1027:
				{
						mMandatoryAvpSetVal [EventReportIndication_IPCANTYPE] = 1;
					if( NULL == this->setIPCANType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IPCANType");
						throw lTssDiaMsgException;
					}
					mIPCANType->setAvpCode(1027);
					mIPCANType->setAvpVendorId(lVenderId);
					mIPCANType->SetDataType((DiameterDataType)7);
					mIPCANType->mspByteArray = mspByteArray;
					mIPCANType->mAvpDecodedFlag = false;
					mIPCANType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1050:
				{
					mTagsPresent[EventReportIndication_ANGWADDRESS] = 1;
					Address *lANGWAddress = new Address();
					if( lANGWAddress == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ANGWAddress");
						throw lTssDiaMsgException;
					}
					lANGWAddress->setAvpCode(1050);
					lANGWAddress->setAvpVendorId(lVenderId);
					lANGWAddress->SetDataType((DiameterDataType)8);
					lANGWAddress->mspByteArray = mspByteArray;
					lANGWAddress->mAvpDecodedFlag = false;
					lANGWAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mANGWAddressList == NULL)
						this->setANGWAddressList();
					mANGWAddressList->push_back(lANGWAddress);
					
				}
				break;
			case 6:
				{
					if( NULL == this->set3GPPSGSNAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNAddress");
						throw lTssDiaMsgException;
					}
					m3GPPSGSNAddress->setAvpCode(6);
					m3GPPSGSNAddress->setAvpVendorId(lVenderId);
					m3GPPSGSNAddress->SetDataType((DiameterDataType)5);
					m3GPPSGSNAddress->mspByteArray = mspByteArray;
					m3GPPSGSNAddress->mAvpDecodedFlag = false;
					m3GPPSGSNAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 15:
				{
					if( NULL == this->set3GPPSGSNIPv6Address())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNIPv6Address");
						throw lTssDiaMsgException;
					}
					m3GPPSGSNIPv6Address->setAvpCode(15);
					m3GPPSGSNIPv6Address->setAvpVendorId(lVenderId);
					m3GPPSGSNIPv6Address->SetDataType((DiameterDataType)5);
					m3GPPSGSNIPv6Address->mspByteArray = mspByteArray;
					m3GPPSGSNIPv6Address->mAvpDecodedFlag = false;
					m3GPPSGSNIPv6Address->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 18:
				{
					if( NULL == this->set3GPPSGSNMCCMNC())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPSGSNMCCMNC");
						throw lTssDiaMsgException;
					}
					m3GPPSGSNMCCMNC->setAvpCode(18);
					m3GPPSGSNMCCMNC->setAvpVendorId(lVenderId);
					m3GPPSGSNMCCMNC->SetDataType((DiameterDataType)5);
					m3GPPSGSNMCCMNC->mspByteArray = mspByteArray;
					m3GPPSGSNMCCMNC->mAvpDecodedFlag = false;
					m3GPPSGSNMCCMNC->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 8:
				{
						mMandatoryAvpSetVal [EventReportIndication_FRAMEDIPADDRESS] = 1;
					if( NULL == this->setFramedIPAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FramedIPAddress");
						throw lTssDiaMsgException;
					}
					mFramedIPAddress->setAvpCode(8);
					mFramedIPAddress->setAvpVendorId(lVenderId);
					mFramedIPAddress->SetDataType((DiameterDataType)5);
					mFramedIPAddress->mspByteArray = mspByteArray;
					mFramedIPAddress->mAvpDecodedFlag = false;
					mFramedIPAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1032:
				{
					if( NULL == this->setRATType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RATType");
						throw lTssDiaMsgException;
					}
					mRATType->setAvpCode(1032);
					mRATType->setAvpVendorId(lVenderId);
					mRATType->SetDataType((DiameterDataType)7);
					mRATType->mspByteArray = mspByteArray;
					mRATType->mAvpDecodedFlag = false;
					mRATType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 909:
				{
					if( NULL == this->setRAI())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RAI");
						throw lTssDiaMsgException;
					}
					mRAI->setAvpCode(909);
					mRAI->setAvpVendorId(lVenderId);
					mRAI->SetDataType((DiameterDataType)5);
					mRAI->mspByteArray = mspByteArray;
					mRAI->mAvpDecodedFlag = false;
					mRAI->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 22:
				{
					if( NULL == this->set3GPPUserLocationInfo())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPUserLocationInfo");
						throw lTssDiaMsgException;
					}
					m3GPPUserLocationInfo->setAvpCode(22);
					m3GPPUserLocationInfo->setAvpVendorId(lVenderId);
					m3GPPUserLocationInfo->SetDataType((DiameterDataType)5);
					m3GPPUserLocationInfo->mspByteArray = mspByteArray;
					m3GPPUserLocationInfo->mAvpDecodedFlag = false;
					m3GPPUserLocationInfo->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1458:
				{
						mMandatoryAvpSetVal [EventReportIndication_TRACEDATA] = 1;
					mTagsPresent[EventReportIndication_TRACEDATA] = 1;
						if( NULL == this->setTraceData()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceData");
						throw lTssDiaMsgException;
						}
					mTraceDataGrp->setAvpCode(1458);
					mTraceDataGrp->SetDataType((DiameterDataType)6);
					mTraceDataGrp->mspByteArray = mspByteArray;
					mTraceDataGrp->mAvpDecodedFlag = false;
					mTraceDataGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mTraceDataGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1459:
				{
						mMandatoryAvpSetVal [EventReportIndication_TRACEREFERENCE] = 1;
					if( NULL == this->setTraceReference())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TraceReference");
						throw lTssDiaMsgException;
					}
					mTraceReference->setAvpCode(1459);
					mTraceReference->setAvpVendorId(lVenderId);
					mTraceReference->SetDataType((DiameterDataType)5);
					mTraceReference->mspByteArray = mspByteArray;
					mTraceReference->mAvpDecodedFlag = false;
					mTraceReference->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 9010:
				{
						mMandatoryAvpSetVal [EventReportIndication_3GPP2BSID] = 1;
					if( NULL == this->set3GPP2BSID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPP2BSID");
						throw lTssDiaMsgException;
					}
					m3GPP2BSID->setAvpCode(9010);
					m3GPP2BSID->setAvpVendorId(lVenderId);
					m3GPP2BSID->SetDataType((DiameterDataType)5);
					m3GPP2BSID->mspByteArray = mspByteArray;
					m3GPP2BSID->mAvpDecodedFlag = false;
					m3GPP2BSID->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 23:
				{
					if( NULL == this->set3GPPMSTimeZone())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding 3GPPMSTimeZone");
						throw lTssDiaMsgException;
					}
					m3GPPMSTimeZone->setAvpCode(23);
					m3GPPMSTimeZone->setAvpVendorId(lVenderId);
					m3GPPMSTimeZone->SetDataType((DiameterDataType)5);
					m3GPPMSTimeZone->mspByteArray = mspByteArray;
					m3GPPMSTimeZone->mAvpDecodedFlag = false;
					m3GPPMSTimeZone->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1077:
				{
					if( NULL == this->setRoutingRuleIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RoutingRuleIdentifier");
						throw lTssDiaMsgException;
					}
					mRoutingRuleIdentifier->setAvpCode(1077);
					mRoutingRuleIdentifier->setAvpVendorId(lVenderId);
					mRoutingRuleIdentifier->SetDataType((DiameterDataType)5);
					mRoutingRuleIdentifier->mspByteArray = mspByteArray;
					mRoutingRuleIdentifier->mAvpDecodedFlag = false;
					mRoutingRuleIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2805:
				{
					if( NULL == this->setUELocalIPAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UELocalIPAddress");
						throw lTssDiaMsgException;
					}
					mUELocalIPAddress->setAvpCode(2805);
					mUELocalIPAddress->setAvpVendorId(lVenderId);
					mUELocalIPAddress->SetDataType((DiameterDataType)8);
					mUELocalIPAddress->mspByteArray = mspByteArray;
					mUELocalIPAddress->mAvpDecodedFlag = false;
					mUELocalIPAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2804:
				{
					if( NULL == this->setHeNBLocalIPAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding HeNBLocalIPAddress");
						throw lTssDiaMsgException;
					}
					mHeNBLocalIPAddress->setAvpCode(2804);
					mHeNBLocalIPAddress->setAvpVendorId(lVenderId);
					mHeNBLocalIPAddress->SetDataType((DiameterDataType)8);
					mHeNBLocalIPAddress->mspByteArray = mspByteArray;
					mHeNBLocalIPAddress->mAvpDecodedFlag = false;
					mHeNBLocalIPAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2806:
				{
					if( NULL == this->setUDPSourcePort())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UDPSourcePort");
						throw lTssDiaMsgException;
					}
					mUDPSourcePort->setAvpCode(2806);
					mUDPSourcePort->setAvpVendorId(lVenderId);
					mUDPSourcePort->SetDataType((DiameterDataType)3);
					mUDPSourcePort->mspByteArray = mspByteArray;
					mUDPSourcePort->mAvpDecodedFlag = false;
					mUDPSourcePort->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2822:
				{
					mTagsPresent[EventReportIndication_PRESENCEREPORTINGAREAINFORMATION] = 1;
						if( NULL == this->setPresenceReportingAreaInformation()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PresenceReportingAreaInformation");
						throw lTssDiaMsgException;
						}
					mPresenceReportingAreaInformationGrp->setAvpCode(2822);
					mPresenceReportingAreaInformationGrp->SetDataType((DiameterDataType)6);
					mPresenceReportingAreaInformationGrp->mspByteArray = mspByteArray;
					mPresenceReportingAreaInformationGrp->mAvpDecodedFlag = false;
					mPresenceReportingAreaInformationGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mPresenceReportingAreaInformationGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			default:
				array->offset+=lAvpDataLen;
				//printf("Unknown AvpCode received Avp:%d \n", lAvpCode );
					//TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
					//throw lTssDiaMsgException;
				break;
		}

		if( (lAvpLen % 4) == 0 )
		{
			lMsgLen = lMsgLen -lAvpLen;
		}
		else
		{
			lMsgLen = lMsgLen -( lAvpLen + ( 4-(lAvpLen%4)));
			array->offset+= ( 4-(lAvpLen%4));
		}
	}
	return DIAMETER_NO_ERR;
}


DiameterBaseInterface* EventReportIndication::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventReportIndication")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1503:
			{
				if(mANTrusted != NULL)
					return mANTrusted->Find(array, avpCode);
				else
					return NULL;
			}
			case 1006:
			{
				if(mEventTriggerList != NULL && mEventTriggerList->size() > 0)
					return (mEventTriggerList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 1027:
			{
				if(mIPCANType != NULL)
					return mIPCANType->Find(array, avpCode);
				else
					return NULL;
			}
			case 1050:
			{
				if(mANGWAddressList != NULL && mANGWAddressList->size() > 0)
					return (mANGWAddressList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 6:
			{
				if(m3GPPSGSNAddress != NULL)
					return m3GPPSGSNAddress->Find(array, avpCode);
				else
					return NULL;
			}
			case 15:
			{
				if(m3GPPSGSNIPv6Address != NULL)
					return m3GPPSGSNIPv6Address->Find(array, avpCode);
				else
					return NULL;
			}
			case 18:
			{
				if(m3GPPSGSNMCCMNC != NULL)
					return m3GPPSGSNMCCMNC->Find(array, avpCode);
				else
					return NULL;
			}
			case 8:
			{
				if(mFramedIPAddress != NULL)
					return mFramedIPAddress->Find(array, avpCode);
				else
					return NULL;
			}
			case 1032:
			{
				if(mRATType != NULL)
					return mRATType->Find(array, avpCode);
				else
					return NULL;
			}
			case 909:
			{
				if(mRAI != NULL)
					return mRAI->Find(array, avpCode);
				else
					return NULL;
			}
			case 22:
			{
				if(m3GPPUserLocationInfo != NULL)
					return m3GPPUserLocationInfo->Find(array, avpCode);
				else
					return NULL;
			}
			case 1459:
			{
				if(mTraceReference != NULL)
					return mTraceReference->Find(array, avpCode);
				else
					return NULL;
			}
			case 9010:
			{
				if(m3GPP2BSID != NULL)
					return m3GPP2BSID->Find(array, avpCode);
				else
					return NULL;
			}
			case 23:
			{
				if(m3GPPMSTimeZone != NULL)
					return m3GPPMSTimeZone->Find(array, avpCode);
				else
					return NULL;
			}
			case 1077:
			{
				if(mRoutingRuleIdentifier != NULL)
					return mRoutingRuleIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 2805:
			{
				if(mUELocalIPAddress != NULL)
					return mUELocalIPAddress->Find(array, avpCode);
				else
					return NULL;
			}
			case 2804:
			{
				if(mHeNBLocalIPAddress != NULL)
					return mHeNBLocalIPAddress->Find(array, avpCode);
				else
					return NULL;
			}
			case 2806:
			{
				if(mUDPSourcePort != NULL)
					return mUDPSourcePort->Find(array, avpCode);
				else
					return NULL;
			}
			default:
			{
				for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
				{
					DiameterBaseInterface* inf = (*itr)->Find(array, avpCode);
					if(inf != NULL)
						return inf;
				}
				return NULL;
			}
		}
}


BOOLEAN EventReportIndication::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventReportIndication")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1503:
			{
				if(mANTrusted != NULL)
				{
					DiameterBaseInterface* inf =  mANTrusted->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1006:
			{
				if(mEventTriggerList != NULL)
				{
					for(auto itr = mEventTriggerList->begin(); itr != mEventTriggerList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 2319:
			{
				if(mUserCSGInformationGrp != NULL)
				{
						pBaseInterface.push_back(mUserCSGInformationGrp);
				}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1027:
			{
				if(mIPCANType != NULL)
				{
					DiameterBaseInterface* inf =  mIPCANType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1050:
			{
				if(mANGWAddressList != NULL)
				{
					for(auto itr = mANGWAddressList->begin(); itr != mANGWAddressList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 6:
			{
				if(m3GPPSGSNAddress != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 15:
			{
				if(m3GPPSGSNIPv6Address != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNIPv6Address->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 18:
			{
				if(m3GPPSGSNMCCMNC != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNMCCMNC->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 8:
			{
				if(mFramedIPAddress != NULL)
				{
					DiameterBaseInterface* inf =  mFramedIPAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1032:
			{
				if(mRATType != NULL)
				{
					DiameterBaseInterface* inf =  mRATType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 909:
			{
				if(mRAI != NULL)
				{
					DiameterBaseInterface* inf =  mRAI->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 22:
			{
				if(m3GPPUserLocationInfo != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPUserLocationInfo->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1458:
			{
				if(mTraceDataGrp != NULL)
				{
						pBaseInterface.push_back(mTraceDataGrp);
				}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1459:
			{
				if(mTraceReference != NULL)
				{
					DiameterBaseInterface* inf =  mTraceReference->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 9010:
			{
				if(m3GPP2BSID != NULL)
				{
					DiameterBaseInterface* inf =  m3GPP2BSID->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 23:
			{
				if(m3GPPMSTimeZone != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPMSTimeZone->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 1077:
			{
				if(mRoutingRuleIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mRoutingRuleIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 2805:
			{
				if(mUELocalIPAddress != NULL)
				{
					DiameterBaseInterface* inf =  mUELocalIPAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 2804:
			{
				if(mHeNBLocalIPAddress != NULL)
				{
					DiameterBaseInterface* inf =  mHeNBLocalIPAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 2806:
			{
				if(mUDPSourcePort != NULL)
				{
					DiameterBaseInterface* inf =  mUDPSourcePort->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			case 2822:
			{
				if(mPresenceReportingAreaInformationGrp != NULL)
				{
						pBaseInterface.push_back(mPresenceReportingAreaInformationGrp);
				}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
					}
				}
				break;
			}
			default:
			{
				if(!deepInspect)
					break;
				for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
				{
					(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
				}
			}
		}
		if(pBaseInterface.size() > 0)
			return true;
		else
			return false;
}
std::shared_ptr<byteArray> EventReportIndication::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN EventReportIndication::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventReportIndication")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
	if(avpCodeMap.empty() || key > size)
	{
		return false;
	}
	auto it = avpCodeMap.find(key);
	if( it == avpCodeMap.end())
	{
		return false;
	}
	UINT32 avpCode = it->second;
		switch(avpCode)
		{
			case 1503:
			{
				if(mANTrusted != NULL)
				{
					DiameterBaseInterface* inf =  mANTrusted->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1006:
			{
				if(mEventTriggerList != NULL)
				{
					for(auto itr = mEventTriggerList->begin(); itr != mEventTriggerList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

				}
				break;
			}
			case 2319:
			{
				if(mUserCSGInformationGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mUserCSGInformationGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mUserCSGInformationGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 1027:
			{
				if(mIPCANType != NULL)
				{
					DiameterBaseInterface* inf =  mIPCANType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1050:
			{
				if(mANGWAddressList != NULL)
				{
					for(auto itr = mANGWAddressList->begin(); itr != mANGWAddressList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
						}
					}

				}
				break;
			}
			case 6:
			{
				if(m3GPPSGSNAddress != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 15:
			{
				if(m3GPPSGSNIPv6Address != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNIPv6Address->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 18:
			{
				if(m3GPPSGSNMCCMNC != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPSGSNMCCMNC->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 8:
			{
				if(mFramedIPAddress != NULL)
				{
					DiameterBaseInterface* inf =  mFramedIPAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1032:
			{
				if(mRATType != NULL)
				{
					DiameterBaseInterface* inf =  mRATType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 909:
			{
				if(mRAI != NULL)
				{
					DiameterBaseInterface* inf =  mRAI->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 22:
			{
				if(m3GPPUserLocationInfo != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPUserLocationInfo->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1458:
			{
				if(mTraceDataGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mTraceDataGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mTraceDataGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 1459:
			{
				if(mTraceReference != NULL)
				{
					DiameterBaseInterface* inf =  mTraceReference->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 9010:
			{
				if(m3GPP2BSID != NULL)
				{
					DiameterBaseInterface* inf =  m3GPP2BSID->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 23:
			{
				if(m3GPPMSTimeZone != NULL)
				{
					DiameterBaseInterface* inf =  m3GPPMSTimeZone->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1077:
			{
				if(mRoutingRuleIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mRoutingRuleIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2805:
			{
				if(mUELocalIPAddress != NULL)
				{
					DiameterBaseInterface* inf =  mUELocalIPAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2804:
			{
				if(mHeNBLocalIPAddress != NULL)
				{
					DiameterBaseInterface* inf =  mHeNBLocalIPAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2806:
			{
				if(mUDPSourcePort != NULL)
				{
					DiameterBaseInterface* inf =  mUDPSourcePort->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2822:
			{
				if(mPresenceReportingAreaInformationGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mPresenceReportingAreaInformationGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mPresenceReportingAreaInformationGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			default:
			{
					break;
			}
		}
		if(pBaseInterface.size() > 0)
			return true;
		else
			return false;
}


INT32 EventReportIndication::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 EventReportIndication::getAvpCode()
{
	return mAvpCode;
}
INT32 EventReportIndication::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 EventReportIndication::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 EventReportIndication::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> EventReportIndication::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void EventReportIndication::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case EventReportIndication_ANTRUSTED:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1503" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ANTrusted" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getANTrusted()->Display(tab+1);
			}
				break;
			case EventReportIndication_EVENTTRIGGER:
			{
				if( mEventTriggerList->size() <= 0) {
					break;
				}

				mEventTriggerIterator = this->getEventTriggerList()->begin();
				while(mEventTriggerIterator != this->getEventTriggerList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1006" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "EventTrigger" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mEventTriggerIterator)->Display(tab+1);
					mEventTriggerIterator++;

				};

			}
				break;
			case EventReportIndication_USERCSGINFORMATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2319" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserCSGInformation" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getUserCSGInformation()->Display(tab+1);
			}
				break;
			case EventReportIndication_IPCANTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1027" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "IPCANType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getIPCANType()->Display(tab+1);
			}
				break;
			case EventReportIndication_ANGWADDRESS:
			{
				if( mANGWAddressList->size() <= 0) {
					break;
				}

				mANGWAddressIterator = this->getANGWAddressList()->begin();
				while(mANGWAddressIterator != this->getANGWAddressList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1050" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ANGWAddress" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mANGWAddressIterator)->Display(tab+1);
					mANGWAddressIterator++;

				};

			}
				break;
			case EventReportIndication_3GPPSGSNADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "6" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPSGSNAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPSGSNAddress()->Display(tab+1);
			}
				break;
			case EventReportIndication_3GPPSGSNIPV6ADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "15" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPSGSNIPv6Address" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPSGSNIPv6Address()->Display(tab+1);
			}
				break;
			case EventReportIndication_3GPPSGSNMCCMNC:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "18" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPSGSNMCCMNC" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPSGSNMCCMNC()->Display(tab+1);
			}
				break;
			case EventReportIndication_FRAMEDIPADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "8" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FramedIPAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getFramedIPAddress()->Display(tab+1);
			}
				break;
			case EventReportIndication_RATTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1032" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RATType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getRATType()->Display(tab+1);
			}
				break;
			case EventReportIndication_RAI:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "909" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RAI" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getRAI()->Display(tab+1);
			}
				break;
			case EventReportIndication_3GPPUSERLOCATIONINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "22" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPUserLocationInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPUserLocationInfo()->Display(tab+1);
			}
				break;
			case EventReportIndication_TRACEDATA:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1458" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TraceData" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getTraceData()->Display(tab+1);
			}
				break;
			case EventReportIndication_TRACEREFERENCE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1459" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TraceReference" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getTraceReference()->Display(tab+1);
			}
				break;
			case EventReportIndication_3GPP2BSID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "9010" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPP2BSID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->get3GPP2BSID()->Display(tab+1);
			}
				break;
			case EventReportIndication_3GPPMSTIMEZONE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "23" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "3GPPMSTimeZone" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->get3GPPMSTimeZone()->Display(tab+1);
			}
				break;
			case EventReportIndication_ROUTINGRULEIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1077" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RoutingRuleIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getRoutingRuleIdentifier()->Display(tab+1);
			}
				break;
			case EventReportIndication_UELOCALIPADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2805" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UELocalIPAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getUELocalIPAddress()->Display(tab+1);
			}
				break;
			case EventReportIndication_HENBLOCALIPADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2804" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "HeNBLocalIPAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getHeNBLocalIPAddress()->Display(tab+1);
			}
				break;
			case EventReportIndication_UDPSOURCEPORT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2806" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UDPSourcePort" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getUDPSourcePort()->Display(tab+1);
			}
				break;
			case EventReportIndication_PRESENCEREPORTINGAREAINFORMATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2822" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PresenceReportingAreaInformation" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPresenceReportingAreaInformation()->Display(tab+1);
			}
				break;
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);
					throw lTssDiaMsgException;
				break;
		}
	}

}


BOOLEAN EventReportIndication::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<21> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case EventReportIndication_ANTRUSTED:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1503");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1503", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_EVENTTRIGGER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1006");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1006", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_USERCSGINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2319");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2319", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_IPCANTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1027");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1027", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_ANGWADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1050");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1050", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_3GPPSGSNADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 6");
				}
				else
					sprintf(lMissingAvpInfo, "%s,6", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_3GPPSGSNIPV6ADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 15");
				}
				else
					sprintf(lMissingAvpInfo, "%s,15", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_3GPPSGSNMCCMNC:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 18");
				}
				else
					sprintf(lMissingAvpInfo, "%s,18", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_FRAMEDIPADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 8");
				}
				else
					sprintf(lMissingAvpInfo, "%s,8", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_RATTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1032");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1032", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_RAI:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 909");
				}
				else
					sprintf(lMissingAvpInfo, "%s,909", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_3GPPUSERLOCATIONINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 22");
				}
				else
					sprintf(lMissingAvpInfo, "%s,22", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_TRACEDATA:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1458");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1458", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_TRACEREFERENCE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1459");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1459", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_3GPP2BSID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 9010");
				}
				else
					sprintf(lMissingAvpInfo, "%s,9010", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_3GPPMSTIMEZONE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 23");
				}
				else
					sprintf(lMissingAvpInfo, "%s,23", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_ROUTINGRULEIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1077");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1077", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_UELOCALIPADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2805");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2805", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_HENBLOCALIPADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2804");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2804", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_UDPSOURCEPORT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2806");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2806", lMissingAvpInfo);
			}
				break;
			case EventReportIndication_PRESENCEREPORTINGAREAINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2822");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2822", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
