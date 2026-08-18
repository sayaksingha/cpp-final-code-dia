#include "sd/include/ADCRuleDefinition.h"

using namespace SD;
BOOLEAN ADCRuleDefinition::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ADCRuleDefinition::ADCRuleDefinition()
{
	mADCRuleName = NULL;
	mTDFApplicationIdentifier = NULL;
	mFlowInformationGrpList = NULL;
	mServiceIdentifier = NULL;
	mRatingGroup = NULL;
	mReportingLevel = NULL;
	mOnline = NULL;
	mOffline = NULL;
	mMeteringMethod = NULL;
	mPrecedence = NULL;
	mFlowStatus = NULL;
	mQoSInformationGrp = NULL;
	mMonitoringKey = NULL;
	mSponsorIdentity = NULL;
	mApplicationServiceProviderIdentity = NULL;
	mRedirectInformationGrpList = NULL;
	mMuteNotification = NULL;
	mTrafficSteeringPolicyIdentifierDL = NULL;
	mTrafficSteeringPolicyIdentifierUL = NULL;
	mToSTrafficClass = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<20>(string("10000110111111111001"));
	mMandatoryAvpSetVal.reset();
}

ADCRuleDefinition::~ADCRuleDefinition()
{
	if(mADCRuleName != NULL)
		delete mADCRuleName;
	if(mTDFApplicationIdentifier != NULL)
		delete mTDFApplicationIdentifier;
	if(mFlowInformationGrpList != NULL){
		mFlowInformationGrpIterator = mFlowInformationGrpList->begin();
		while(mFlowInformationGrpIterator != mFlowInformationGrpList->end()){
	if(*mFlowInformationGrpIterator != NULL)
			delete (*mFlowInformationGrpIterator);
			mFlowInformationGrpIterator++;
		}
		delete mFlowInformationGrpList;
	}
	if(mServiceIdentifier != NULL)
		delete mServiceIdentifier;
	if(mRatingGroup != NULL)
		delete mRatingGroup;
	if(mReportingLevel != NULL)
		delete mReportingLevel;
	if(mOnline != NULL)
		delete mOnline;
	if(mOffline != NULL)
		delete mOffline;
	if(mMeteringMethod != NULL)
		delete mMeteringMethod;
	if(mPrecedence != NULL)
		delete mPrecedence;
	if(mFlowStatus != NULL)
		delete mFlowStatus;
	if(mQoSInformationGrp != NULL)
		delete mQoSInformationGrp;
	if(mMonitoringKey != NULL)
		delete mMonitoringKey;
	if(mSponsorIdentity != NULL)
		delete mSponsorIdentity;
	if(mApplicationServiceProviderIdentity != NULL)
		delete mApplicationServiceProviderIdentity;
	if(mRedirectInformationGrpList != NULL){
		mRedirectInformationGrpIterator = mRedirectInformationGrpList->begin();
		while(mRedirectInformationGrpIterator != mRedirectInformationGrpList->end()){
	if(*mRedirectInformationGrpIterator != NULL)
			delete (*mRedirectInformationGrpIterator);
			mRedirectInformationGrpIterator++;
		}
		delete mRedirectInformationGrpList;
	}
	if(mMuteNotification != NULL)
		delete mMuteNotification;
	if(mTrafficSteeringPolicyIdentifierDL != NULL)
		delete mTrafficSteeringPolicyIdentifierDL;
	if(mTrafficSteeringPolicyIdentifierUL != NULL)
		delete mTrafficSteeringPolicyIdentifierUL;
	if(mToSTrafficClass != NULL)
		delete mToSTrafficClass;
}

OctetString* ADCRuleDefinition::setADCRuleName(){
	mMandatoryAvpSetVal [ADCRuleDefinition_ADCRULENAME] = 1;
	if(mADCRuleName == NULL)
	{
		mADCRuleName = new OctetString();
		mTagsPresent[ADCRuleDefinition_ADCRULENAME] = 1;
		return mADCRuleName;
	}
	return mADCRuleName;
}

void ADCRuleDefinition::resetADCRuleName(){
	mTagsPresent[ADCRuleDefinition_ADCRULENAME] = 0;
	if(mADCRuleName != NULL)
	{
		delete mADCRuleName; 
		mADCRuleName = NULL;
	}
}

OctetString* ADCRuleDefinition::setTDFApplicationIdentifier(){
	if(mTDFApplicationIdentifier == NULL)
	{
		mTDFApplicationIdentifier = new OctetString();
		mTagsPresent[ADCRuleDefinition_TDFAPPLICATIONIDENTIFIER] = 1;
		return mTDFApplicationIdentifier;
	}
	return mTDFApplicationIdentifier;
}

void ADCRuleDefinition::resetTDFApplicationIdentifier(){
	mTagsPresent[ADCRuleDefinition_TDFAPPLICATIONIDENTIFIER] = 0;
	if(mTDFApplicationIdentifier != NULL)
	{
		delete mTDFApplicationIdentifier; 
		mTDFApplicationIdentifier = NULL;
	}
}

Unsigned32* ADCRuleDefinition::setServiceIdentifier(){
	mMandatoryAvpSetVal [ADCRuleDefinition_SERVICEIDENTIFIER] = 1;
	if(mServiceIdentifier == NULL)
	{
		mServiceIdentifier = new Unsigned32();
		mTagsPresent[ADCRuleDefinition_SERVICEIDENTIFIER] = 1;
		return mServiceIdentifier;
	}
	return mServiceIdentifier;
}

void ADCRuleDefinition::resetServiceIdentifier(){
	mTagsPresent[ADCRuleDefinition_SERVICEIDENTIFIER] = 0;
	if(mServiceIdentifier != NULL)
	{
		delete mServiceIdentifier; 
		mServiceIdentifier = NULL;
	}
}

Unsigned32* ADCRuleDefinition::setRatingGroup(){
	mMandatoryAvpSetVal [ADCRuleDefinition_RATINGGROUP] = 1;
	if(mRatingGroup == NULL)
	{
		mRatingGroup = new Unsigned32();
		mTagsPresent[ADCRuleDefinition_RATINGGROUP] = 1;
		return mRatingGroup;
	}
	return mRatingGroup;
}

void ADCRuleDefinition::resetRatingGroup(){
	mTagsPresent[ADCRuleDefinition_RATINGGROUP] = 0;
	if(mRatingGroup != NULL)
	{
		delete mRatingGroup; 
		mRatingGroup = NULL;
	}
}

ReportingLevel* ADCRuleDefinition::setReportingLevel(){
	mMandatoryAvpSetVal [ADCRuleDefinition_REPORTINGLEVEL] = 1;
	if(mReportingLevel == NULL)
	{
		mReportingLevel = new ReportingLevel();
		mTagsPresent[ADCRuleDefinition_REPORTINGLEVEL] = 1;
		return mReportingLevel;
	}
	return mReportingLevel;
}

void ADCRuleDefinition::resetReportingLevel(){
	mTagsPresent[ADCRuleDefinition_REPORTINGLEVEL] = 0;
	if(mReportingLevel != NULL)
	{
		delete mReportingLevel; 
		mReportingLevel = NULL;
	}
}

Online* ADCRuleDefinition::setOnline(){
	mMandatoryAvpSetVal [ADCRuleDefinition_ONLINE] = 1;
	if(mOnline == NULL)
	{
		mOnline = new Online();
		mTagsPresent[ADCRuleDefinition_ONLINE] = 1;
		return mOnline;
	}
	return mOnline;
}

void ADCRuleDefinition::resetOnline(){
	mTagsPresent[ADCRuleDefinition_ONLINE] = 0;
	if(mOnline != NULL)
	{
		delete mOnline; 
		mOnline = NULL;
	}
}

Offline* ADCRuleDefinition::setOffline(){
	mMandatoryAvpSetVal [ADCRuleDefinition_OFFLINE] = 1;
	if(mOffline == NULL)
	{
		mOffline = new Offline();
		mTagsPresent[ADCRuleDefinition_OFFLINE] = 1;
		return mOffline;
	}
	return mOffline;
}

void ADCRuleDefinition::resetOffline(){
	mTagsPresent[ADCRuleDefinition_OFFLINE] = 0;
	if(mOffline != NULL)
	{
		delete mOffline; 
		mOffline = NULL;
	}
}

MeteringMethod* ADCRuleDefinition::setMeteringMethod(){
	mMandatoryAvpSetVal [ADCRuleDefinition_METERINGMETHOD] = 1;
	if(mMeteringMethod == NULL)
	{
		mMeteringMethod = new MeteringMethod();
		mTagsPresent[ADCRuleDefinition_METERINGMETHOD] = 1;
		return mMeteringMethod;
	}
	return mMeteringMethod;
}

void ADCRuleDefinition::resetMeteringMethod(){
	mTagsPresent[ADCRuleDefinition_METERINGMETHOD] = 0;
	if(mMeteringMethod != NULL)
	{
		delete mMeteringMethod; 
		mMeteringMethod = NULL;
	}
}

Unsigned32* ADCRuleDefinition::setPrecedence(){
	mMandatoryAvpSetVal [ADCRuleDefinition_PRECEDENCE] = 1;
	if(mPrecedence == NULL)
	{
		mPrecedence = new Unsigned32();
		mTagsPresent[ADCRuleDefinition_PRECEDENCE] = 1;
		return mPrecedence;
	}
	return mPrecedence;
}

void ADCRuleDefinition::resetPrecedence(){
	mTagsPresent[ADCRuleDefinition_PRECEDENCE] = 0;
	if(mPrecedence != NULL)
	{
		delete mPrecedence; 
		mPrecedence = NULL;
	}
}

FlowStatus* ADCRuleDefinition::setFlowStatus(){
	mMandatoryAvpSetVal [ADCRuleDefinition_FLOWSTATUS] = 1;
	if(mFlowStatus == NULL)
	{
		mFlowStatus = new FlowStatus();
		mTagsPresent[ADCRuleDefinition_FLOWSTATUS] = 1;
		return mFlowStatus;
	}
	return mFlowStatus;
}

void ADCRuleDefinition::resetFlowStatus(){
	mTagsPresent[ADCRuleDefinition_FLOWSTATUS] = 0;
	if(mFlowStatus != NULL)
	{
		delete mFlowStatus; 
		mFlowStatus = NULL;
	}
}

OctetString* ADCRuleDefinition::setMonitoringKey(){
	if(mMonitoringKey == NULL)
	{
		mMonitoringKey = new OctetString();
		mTagsPresent[ADCRuleDefinition_MONITORINGKEY] = 1;
		return mMonitoringKey;
	}
	return mMonitoringKey;
}

void ADCRuleDefinition::resetMonitoringKey(){
	mTagsPresent[ADCRuleDefinition_MONITORINGKEY] = 0;
	if(mMonitoringKey != NULL)
	{
		delete mMonitoringKey; 
		mMonitoringKey = NULL;
	}
}

OctetString* ADCRuleDefinition::setSponsorIdentity(){
	mMandatoryAvpSetVal [ADCRuleDefinition_SPONSORIDENTITY] = 1;
	if(mSponsorIdentity == NULL)
	{
		mSponsorIdentity = new OctetString();
		mTagsPresent[ADCRuleDefinition_SPONSORIDENTITY] = 1;
		return mSponsorIdentity;
	}
	return mSponsorIdentity;
}

void ADCRuleDefinition::resetSponsorIdentity(){
	mTagsPresent[ADCRuleDefinition_SPONSORIDENTITY] = 0;
	if(mSponsorIdentity != NULL)
	{
		delete mSponsorIdentity; 
		mSponsorIdentity = NULL;
	}
}

OctetString* ADCRuleDefinition::setApplicationServiceProviderIdentity(){
	mMandatoryAvpSetVal [ADCRuleDefinition_APPLICATIONSERVICEPROVIDERIDENTITY] = 1;
	if(mApplicationServiceProviderIdentity == NULL)
	{
		mApplicationServiceProviderIdentity = new OctetString();
		mTagsPresent[ADCRuleDefinition_APPLICATIONSERVICEPROVIDERIDENTITY] = 1;
		return mApplicationServiceProviderIdentity;
	}
	return mApplicationServiceProviderIdentity;
}

void ADCRuleDefinition::resetApplicationServiceProviderIdentity(){
	mTagsPresent[ADCRuleDefinition_APPLICATIONSERVICEPROVIDERIDENTITY] = 0;
	if(mApplicationServiceProviderIdentity != NULL)
	{
		delete mApplicationServiceProviderIdentity; 
		mApplicationServiceProviderIdentity = NULL;
	}
}

MuteNotification* ADCRuleDefinition::setMuteNotification(){
	if(mMuteNotification == NULL)
	{
		mMuteNotification = new MuteNotification();
		mTagsPresent[ADCRuleDefinition_MUTENOTIFICATION] = 1;
		return mMuteNotification;
	}
	return mMuteNotification;
}

void ADCRuleDefinition::resetMuteNotification(){
	mTagsPresent[ADCRuleDefinition_MUTENOTIFICATION] = 0;
	if(mMuteNotification != NULL)
	{
		delete mMuteNotification; 
		mMuteNotification = NULL;
	}
}

OctetString* ADCRuleDefinition::setTrafficSteeringPolicyIdentifierDL(){
	if(mTrafficSteeringPolicyIdentifierDL == NULL)
	{
		mTrafficSteeringPolicyIdentifierDL = new OctetString();
		mTagsPresent[ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERDL] = 1;
		return mTrafficSteeringPolicyIdentifierDL;
	}
	return mTrafficSteeringPolicyIdentifierDL;
}

void ADCRuleDefinition::resetTrafficSteeringPolicyIdentifierDL(){
	mTagsPresent[ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERDL] = 0;
	if(mTrafficSteeringPolicyIdentifierDL != NULL)
	{
		delete mTrafficSteeringPolicyIdentifierDL; 
		mTrafficSteeringPolicyIdentifierDL = NULL;
	}
}

OctetString* ADCRuleDefinition::setTrafficSteeringPolicyIdentifierUL(){
	if(mTrafficSteeringPolicyIdentifierUL == NULL)
	{
		mTrafficSteeringPolicyIdentifierUL = new OctetString();
		mTagsPresent[ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERUL] = 1;
		return mTrafficSteeringPolicyIdentifierUL;
	}
	return mTrafficSteeringPolicyIdentifierUL;
}

void ADCRuleDefinition::resetTrafficSteeringPolicyIdentifierUL(){
	mTagsPresent[ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERUL] = 0;
	if(mTrafficSteeringPolicyIdentifierUL != NULL)
	{
		delete mTrafficSteeringPolicyIdentifierUL; 
		mTrafficSteeringPolicyIdentifierUL = NULL;
	}
}

OctetString* ADCRuleDefinition::setToSTrafficClass(){
	mMandatoryAvpSetVal [ADCRuleDefinition_TOSTRAFFICCLASS] = 1;
	if(mToSTrafficClass == NULL)
	{
		mToSTrafficClass = new OctetString();
		mTagsPresent[ADCRuleDefinition_TOSTRAFFICCLASS] = 1;
		return mToSTrafficClass;
	}
	return mToSTrafficClass;
}

void ADCRuleDefinition::resetToSTrafficClass(){
	mTagsPresent[ADCRuleDefinition_TOSTRAFFICCLASS] = 0;
	if(mToSTrafficClass != NULL)
	{
		delete mToSTrafficClass; 
		mToSTrafficClass = NULL;
	}
}

OctetString* ADCRuleDefinition::getADCRuleName(){
	if(NULL == mADCRuleName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleName is Null");
		throw lTssDiaMsgException;
	}
	if(!mADCRuleName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mADCRuleName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ADCRuleName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mADCRuleName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mADCRuleName->Decode(mspByteArray.get(), mADCRuleName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleName")     ;
			throw lTssDiaMsgException;
		}
		mADCRuleName->mAvpDecodedFlag = true;
	}
	return mADCRuleName;
}

OctetString* ADCRuleDefinition::getTDFApplicationIdentifier(){
	if(NULL == mTDFApplicationIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TDFApplicationIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mTDFApplicationIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTDFApplicationIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TDFApplicationIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTDFApplicationIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTDFApplicationIdentifier->Decode(mspByteArray.get(), mTDFApplicationIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TDFApplicationIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mTDFApplicationIdentifier->mAvpDecodedFlag = true;
	}
	return mTDFApplicationIdentifier;
}

list<FlowInformation*>* ADCRuleDefinition::getFlowInformationGrpList()
{
	if(mFlowInformationGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowInformation is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mFlowInformationGrpList)
	{
		if(mFlowInformationGrpList != NULL)
		{
		if(mFlowInformationGrpList->size() == 0)
		{
			mTagsPresent[ADCRuleDefinition_FLOWINFORMATION] = 0;
			mFlowInformationGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowInformation is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowInformation is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowInformation")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mFlowInformationGrpList;
}

list<FlowInformation*>* ADCRuleDefinition::setFlowInformationGrpList(){
	mTagsPresent[ADCRuleDefinition_FLOWINFORMATION] = 1;
	if(mFlowInformationGrpList == NULL)
		mFlowInformationGrpList = new list<FlowInformation*>;
	mFlowInformationGrpList->clear();
	return mFlowInformationGrpList;
}

void ADCRuleDefinition::resetFlowInformationGrpList(){
	mTagsPresent[ADCRuleDefinition_FLOWINFORMATION] = 0;
	if(mFlowInformationGrpList != NULL)
		delete mFlowInformationGrpList;
}

Unsigned32* ADCRuleDefinition::getServiceIdentifier(){
	if(NULL == mServiceIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mServiceIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mServiceIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mServiceIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mServiceIdentifier->Decode(mspByteArray.get(), mServiceIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mServiceIdentifier->mAvpDecodedFlag = true;
	}
	return mServiceIdentifier;
}

Unsigned32* ADCRuleDefinition::getRatingGroup(){
	if(NULL == mRatingGroup) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RatingGroup is Null");
		throw lTssDiaMsgException;
	}
	if(!mRatingGroup->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRatingGroup->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RatingGroup is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRatingGroup->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRatingGroup->Decode(mspByteArray.get(), mRatingGroup->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RatingGroup")     ;
			throw lTssDiaMsgException;
		}
		mRatingGroup->mAvpDecodedFlag = true;
	}
	return mRatingGroup;
}

ReportingLevel* ADCRuleDefinition::getReportingLevel(){
	if(NULL == mReportingLevel) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReportingLevel is Null");
		throw lTssDiaMsgException;
	}
	if(!mReportingLevel->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mReportingLevel->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReportingLevel is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mReportingLevel->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mReportingLevel->Decode(mspByteArray.get(), mReportingLevel->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReportingLevel")     ;
			throw lTssDiaMsgException;
		}
		mReportingLevel->mAvpDecodedFlag = true;
	}
	return mReportingLevel;
}

Online* ADCRuleDefinition::getOnline(){
	if(NULL == mOnline) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Online is Null");
		throw lTssDiaMsgException;
	}
	if(!mOnline->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOnline->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Online is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOnline->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOnline->Decode(mspByteArray.get(), mOnline->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Online")     ;
			throw lTssDiaMsgException;
		}
		mOnline->mAvpDecodedFlag = true;
	}
	return mOnline;
}

Offline* ADCRuleDefinition::getOffline(){
	if(NULL == mOffline) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Offline is Null");
		throw lTssDiaMsgException;
	}
	if(!mOffline->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOffline->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Offline is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOffline->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOffline->Decode(mspByteArray.get(), mOffline->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Offline")     ;
			throw lTssDiaMsgException;
		}
		mOffline->mAvpDecodedFlag = true;
	}
	return mOffline;
}

MeteringMethod* ADCRuleDefinition::getMeteringMethod(){
	if(NULL == mMeteringMethod) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MeteringMethod is Null");
		throw lTssDiaMsgException;
	}
	if(!mMeteringMethod->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMeteringMethod->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MeteringMethod is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMeteringMethod->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMeteringMethod->Decode(mspByteArray.get(), mMeteringMethod->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MeteringMethod")     ;
			throw lTssDiaMsgException;
		}
		mMeteringMethod->mAvpDecodedFlag = true;
	}
	return mMeteringMethod;
}

Unsigned32* ADCRuleDefinition::getPrecedence(){
	if(NULL == mPrecedence) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Precedence is Null");
		throw lTssDiaMsgException;
	}
	if(!mPrecedence->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPrecedence->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Precedence is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPrecedence->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPrecedence->Decode(mspByteArray.get(), mPrecedence->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Precedence")     ;
			throw lTssDiaMsgException;
		}
		mPrecedence->mAvpDecodedFlag = true;
	}
	return mPrecedence;
}

FlowStatus* ADCRuleDefinition::getFlowStatus(){
	if(NULL == mFlowStatus) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowStatus is Null");
		throw lTssDiaMsgException;
	}
	if(!mFlowStatus->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFlowStatus->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowStatus is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFlowStatus->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFlowStatus->Decode(mspByteArray.get(), mFlowStatus->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowStatus")     ;
			throw lTssDiaMsgException;
		}
		mFlowStatus->mAvpDecodedFlag = true;
	}
	return mFlowStatus;
}

QoSInformation* ADCRuleDefinition::getQoSInformation()
{
	if(mQoSInformationGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "QoSInformation is Null");
		throw lTssDiaMsgException;
	}
	if(!mQoSInformationGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mQoSInformationGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "QoSInformation is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mQoSInformationGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mQoSInformationGrp->Decode(mspByteArray.get(), mQoSInformationGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding QoSInformation")     ;
			throw lTssDiaMsgException;
		}
		mQoSInformationGrp->mAvpDecodedFlag = true;
	}
	return mQoSInformationGrp;
}

QoSInformation* ADCRuleDefinition::setQoSInformation(){
	if(mQoSInformationGrp == NULL)
		mQoSInformationGrp = new QoSInformation();
	mTagsPresent[ADCRuleDefinition_QOSINFORMATION] = 1;
	mMandatoryAvpSetVal[ADCRuleDefinition_QOSINFORMATION] = 1;
	return mQoSInformationGrp;
}

void ADCRuleDefinition::resetQoSInformation(){
	mTagsPresent[ADCRuleDefinition_QOSINFORMATION] = 0;
	if(mQoSInformationGrp != NULL)
		delete mQoSInformationGrp;
}

OctetString* ADCRuleDefinition::getMonitoringKey(){
	if(NULL == mMonitoringKey) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MonitoringKey is Null");
		throw lTssDiaMsgException;
	}
	if(!mMonitoringKey->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMonitoringKey->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MonitoringKey is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMonitoringKey->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMonitoringKey->Decode(mspByteArray.get(), mMonitoringKey->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MonitoringKey")     ;
			throw lTssDiaMsgException;
		}
		mMonitoringKey->mAvpDecodedFlag = true;
	}
	return mMonitoringKey;
}

OctetString* ADCRuleDefinition::getSponsorIdentity(){
	if(NULL == mSponsorIdentity) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SponsorIdentity is Null");
		throw lTssDiaMsgException;
	}
	if(!mSponsorIdentity->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSponsorIdentity->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SponsorIdentity is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSponsorIdentity->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSponsorIdentity->Decode(mspByteArray.get(), mSponsorIdentity->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SponsorIdentity")     ;
			throw lTssDiaMsgException;
		}
		mSponsorIdentity->mAvpDecodedFlag = true;
	}
	return mSponsorIdentity;
}

OctetString* ADCRuleDefinition::getApplicationServiceProviderIdentity(){
	if(NULL == mApplicationServiceProviderIdentity) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ApplicationServiceProviderIdentity is Null");
		throw lTssDiaMsgException;
	}
	if(!mApplicationServiceProviderIdentity->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mApplicationServiceProviderIdentity->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ApplicationServiceProviderIdentity is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mApplicationServiceProviderIdentity->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mApplicationServiceProviderIdentity->Decode(mspByteArray.get(), mApplicationServiceProviderIdentity->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ApplicationServiceProviderIdentity")     ;
			throw lTssDiaMsgException;
		}
		mApplicationServiceProviderIdentity->mAvpDecodedFlag = true;
	}
	return mApplicationServiceProviderIdentity;
}

list<RedirectInformation*>* ADCRuleDefinition::getRedirectInformationGrpList()
{
	if(mRedirectInformationGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectInformation is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mRedirectInformationGrpList)
	{
		if(mRedirectInformationGrpList != NULL)
		{
		if(mRedirectInformationGrpList->size() == 0)
		{
			mTagsPresent[ADCRuleDefinition_REDIRECTINFORMATION] = 0;
			mRedirectInformationGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectInformation is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectInformation is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectInformation")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mRedirectInformationGrpList;
}

list<RedirectInformation*>* ADCRuleDefinition::setRedirectInformationGrpList(){
	mTagsPresent[ADCRuleDefinition_REDIRECTINFORMATION] = 1;
	if(mRedirectInformationGrpList == NULL)
		mRedirectInformationGrpList = new list<RedirectInformation*>;
	mRedirectInformationGrpList->clear();
	return mRedirectInformationGrpList;
}

void ADCRuleDefinition::resetRedirectInformationGrpList(){
	mTagsPresent[ADCRuleDefinition_REDIRECTINFORMATION] = 0;
	if(mRedirectInformationGrpList != NULL)
		delete mRedirectInformationGrpList;
}

MuteNotification* ADCRuleDefinition::getMuteNotification(){
	if(NULL == mMuteNotification) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MuteNotification is Null");
		throw lTssDiaMsgException;
	}
	if(!mMuteNotification->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMuteNotification->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MuteNotification is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMuteNotification->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMuteNotification->Decode(mspByteArray.get(), mMuteNotification->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MuteNotification")     ;
			throw lTssDiaMsgException;
		}
		mMuteNotification->mAvpDecodedFlag = true;
	}
	return mMuteNotification;
}

OctetString* ADCRuleDefinition::getTrafficSteeringPolicyIdentifierDL(){
	if(NULL == mTrafficSteeringPolicyIdentifierDL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TrafficSteeringPolicyIdentifierDL is Null");
		throw lTssDiaMsgException;
	}
	if(!mTrafficSteeringPolicyIdentifierDL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTrafficSteeringPolicyIdentifierDL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TrafficSteeringPolicyIdentifierDL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTrafficSteeringPolicyIdentifierDL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTrafficSteeringPolicyIdentifierDL->Decode(mspByteArray.get(), mTrafficSteeringPolicyIdentifierDL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TrafficSteeringPolicyIdentifierDL")     ;
			throw lTssDiaMsgException;
		}
		mTrafficSteeringPolicyIdentifierDL->mAvpDecodedFlag = true;
	}
	return mTrafficSteeringPolicyIdentifierDL;
}

OctetString* ADCRuleDefinition::getTrafficSteeringPolicyIdentifierUL(){
	if(NULL == mTrafficSteeringPolicyIdentifierUL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TrafficSteeringPolicyIdentifierUL is Null");
		throw lTssDiaMsgException;
	}
	if(!mTrafficSteeringPolicyIdentifierUL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTrafficSteeringPolicyIdentifierUL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TrafficSteeringPolicyIdentifierUL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTrafficSteeringPolicyIdentifierUL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTrafficSteeringPolicyIdentifierUL->Decode(mspByteArray.get(), mTrafficSteeringPolicyIdentifierUL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TrafficSteeringPolicyIdentifierUL")     ;
			throw lTssDiaMsgException;
		}
		mTrafficSteeringPolicyIdentifierUL->mAvpDecodedFlag = true;
	}
	return mTrafficSteeringPolicyIdentifierUL;
}

OctetString* ADCRuleDefinition::getToSTrafficClass(){
	if(NULL == mToSTrafficClass) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ToSTrafficClass is Null");
		throw lTssDiaMsgException;
	}
	if(!mToSTrafficClass->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mToSTrafficClass->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ToSTrafficClass is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mToSTrafficClass->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mToSTrafficClass->Decode(mspByteArray.get(), mToSTrafficClass->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ToSTrafficClass")     ;
			throw lTssDiaMsgException;
		}
		mToSTrafficClass->mAvpDecodedFlag = true;
	}
	return mToSTrafficClass;
}



int ADCRuleDefinition::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case ADCRuleDefinition_ADCRULENAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1096);
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
					if(!mADCRuleName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mADCRuleName->getAvpOffsetLen().first], mADCRuleName->getAvpOffsetLen().second);
						array->offset += mADCRuleName->getAvpOffsetLen().second;
						array->size += mADCRuleName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mADCRuleName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mADCRuleName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mADCRuleName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mADCRuleName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ADCRuleName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_TDFAPPLICATIONIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1088);
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
					if(!mTDFApplicationIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTDFApplicationIdentifier->getAvpOffsetLen().first], mTDFApplicationIdentifier->getAvpOffsetLen().second);
						array->offset += mTDFApplicationIdentifier->getAvpOffsetLen().second;
						array->size += mTDFApplicationIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTDFApplicationIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTDFApplicationIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TDFApplicationIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTDFApplicationIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTDFApplicationIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TDFApplicationIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_FLOWINFORMATION:
			{
				if( mFlowInformationGrpList->size() <= 0) {
					break;
				}

				mFlowInformationGrpIterator = this->getFlowInformationGrpList()->begin();
				while(mFlowInformationGrpIterator != mFlowInformationGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(1058);
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
					if(((*mFlowInformationGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowInformation");
						throw lTssDiaMsgException;
					}
					
					mFlowInformationGrpIterator++;
				}
				}
				break;
			case ADCRuleDefinition_SERVICEIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(439);
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
					if(!mServiceIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mServiceIdentifier->getAvpOffsetLen().first], mServiceIdentifier->getAvpOffsetLen().second);
						array->offset += mServiceIdentifier->getAvpOffsetLen().second;
						array->size += mServiceIdentifier->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceIdentifier");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mServiceIdentifier->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_RATINGGROUP:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(432);
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
					if(!mRatingGroup->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRatingGroup->getAvpOffsetLen().first], mRatingGroup->getAvpOffsetLen().second);
						array->offset += mRatingGroup->getAvpOffsetLen().second;
						array->size += mRatingGroup->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RatingGroup");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRatingGroup->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RatingGroup");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_REPORTINGLEVEL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1011);
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
					if(!mReportingLevel->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mReportingLevel->getAvpOffsetLen().first], mReportingLevel->getAvpOffsetLen().second);
						array->offset += mReportingLevel->getAvpOffsetLen().second;
						array->size += mReportingLevel->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReportingLevel");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mReportingLevel->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReportingLevel");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_ONLINE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1009);
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
					if(!mOnline->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOnline->getAvpOffsetLen().first], mOnline->getAvpOffsetLen().second);
						array->offset += mOnline->getAvpOffsetLen().second;
						array->size += mOnline->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Online");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mOnline->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Online");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_OFFLINE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1008);
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
					if(!mOffline->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOffline->getAvpOffsetLen().first], mOffline->getAvpOffsetLen().second);
						array->offset += mOffline->getAvpOffsetLen().second;
						array->size += mOffline->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Offline");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mOffline->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Offline");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_METERINGMETHOD:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1007);
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
					if(!mMeteringMethod->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMeteringMethod->getAvpOffsetLen().first], mMeteringMethod->getAvpOffsetLen().second);
						array->offset += mMeteringMethod->getAvpOffsetLen().second;
						array->size += mMeteringMethod->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MeteringMethod");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMeteringMethod->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MeteringMethod");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_PRECEDENCE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1010);
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
					if(!mPrecedence->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPrecedence->getAvpOffsetLen().first], mPrecedence->getAvpOffsetLen().second);
						array->offset += mPrecedence->getAvpOffsetLen().second;
						array->size += mPrecedence->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Precedence");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mPrecedence->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Precedence");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_FLOWSTATUS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(511);
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
					if(!mFlowStatus->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFlowStatus->getAvpOffsetLen().first], mFlowStatus->getAvpOffsetLen().second);
						array->offset += mFlowStatus->getAvpOffsetLen().second;
						array->size += mFlowStatus->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowStatus");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFlowStatus->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowStatus");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_QOSINFORMATION:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(1016);
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
				if((this->getQoSInformation()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding QoSInformation");
					throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_MONITORINGKEY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1066);
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
					if(!mMonitoringKey->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMonitoringKey->getAvpOffsetLen().first], mMonitoringKey->getAvpOffsetLen().second);
						array->offset += mMonitoringKey->getAvpOffsetLen().second;
						array->size += mMonitoringKey->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mMonitoringKey->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mMonitoringKey->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MonitoringKey");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mMonitoringKey->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mMonitoringKey->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MonitoringKey");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_SPONSORIDENTITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(531);
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
					if(!mSponsorIdentity->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSponsorIdentity->getAvpOffsetLen().first], mSponsorIdentity->getAvpOffsetLen().second);
						array->offset += mSponsorIdentity->getAvpOffsetLen().second;
						array->size += mSponsorIdentity->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSponsorIdentity->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSponsorIdentity->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SponsorIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSponsorIdentity->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSponsorIdentity->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SponsorIdentity");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_APPLICATIONSERVICEPROVIDERIDENTITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(532);
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
					if(!mApplicationServiceProviderIdentity->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mApplicationServiceProviderIdentity->getAvpOffsetLen().first], mApplicationServiceProviderIdentity->getAvpOffsetLen().second);
						array->offset += mApplicationServiceProviderIdentity->getAvpOffsetLen().second;
						array->size += mApplicationServiceProviderIdentity->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mApplicationServiceProviderIdentity->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mApplicationServiceProviderIdentity->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ApplicationServiceProviderIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mApplicationServiceProviderIdentity->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mApplicationServiceProviderIdentity->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ApplicationServiceProviderIdentity");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_REDIRECTINFORMATION:
			{
				if( mRedirectInformationGrpList->size() <= 0) {
					break;
				}

				mRedirectInformationGrpIterator = this->getRedirectInformationGrpList()->begin();
				while(mRedirectInformationGrpIterator != mRedirectInformationGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(1085);
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
					if(((*mRedirectInformationGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectInformation");
						throw lTssDiaMsgException;
					}
					
					mRedirectInformationGrpIterator++;
				}
				}
				break;
			case ADCRuleDefinition_MUTENOTIFICATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2809);
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
					if(!mMuteNotification->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMuteNotification->getAvpOffsetLen().first], mMuteNotification->getAvpOffsetLen().second);
						array->offset += mMuteNotification->getAvpOffsetLen().second;
						array->size += mMuteNotification->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MuteNotification");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMuteNotification->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MuteNotification");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERDL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2836);
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
					if(!mTrafficSteeringPolicyIdentifierDL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTrafficSteeringPolicyIdentifierDL->getAvpOffsetLen().first], mTrafficSteeringPolicyIdentifierDL->getAvpOffsetLen().second);
						array->offset += mTrafficSteeringPolicyIdentifierDL->getAvpOffsetLen().second;
						array->size += mTrafficSteeringPolicyIdentifierDL->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTrafficSteeringPolicyIdentifierDL->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTrafficSteeringPolicyIdentifierDL->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TrafficSteeringPolicyIdentifierDL");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTrafficSteeringPolicyIdentifierDL->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTrafficSteeringPolicyIdentifierDL->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TrafficSteeringPolicyIdentifierDL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERUL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2837);
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
					if(!mTrafficSteeringPolicyIdentifierUL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTrafficSteeringPolicyIdentifierUL->getAvpOffsetLen().first], mTrafficSteeringPolicyIdentifierUL->getAvpOffsetLen().second);
						array->offset += mTrafficSteeringPolicyIdentifierUL->getAvpOffsetLen().second;
						array->size += mTrafficSteeringPolicyIdentifierUL->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTrafficSteeringPolicyIdentifierUL->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTrafficSteeringPolicyIdentifierUL->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TrafficSteeringPolicyIdentifierUL");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTrafficSteeringPolicyIdentifierUL->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTrafficSteeringPolicyIdentifierUL->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TrafficSteeringPolicyIdentifierUL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ADCRuleDefinition_TOSTRAFFICCLASS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1014);
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
					if(!mToSTrafficClass->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mToSTrafficClass->getAvpOffsetLen().first], mToSTrafficClass->getAvpOffsetLen().second);
						array->offset += mToSTrafficClass->getAvpOffsetLen().second;
						array->size += mToSTrafficClass->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mToSTrafficClass->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mToSTrafficClass->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ToSTrafficClass");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mToSTrafficClass->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mToSTrafficClass->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ToSTrafficClass");
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


int ADCRuleDefinition::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1096:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_ADCRULENAME] = 1;
					if( NULL == this->setADCRuleName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleName");
						throw lTssDiaMsgException;
					}
					mADCRuleName->setAvpCode(1096);
					mADCRuleName->setAvpVendorId(lVenderId);
					mADCRuleName->SetDataType((DiameterDataType)5);
					mADCRuleName->mspByteArray = mspByteArray;
					mADCRuleName->mAvpDecodedFlag = false;
					mADCRuleName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1088:
				{
					if( NULL == this->setTDFApplicationIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TDFApplicationIdentifier");
						throw lTssDiaMsgException;
					}
					mTDFApplicationIdentifier->setAvpCode(1088);
					mTDFApplicationIdentifier->setAvpVendorId(lVenderId);
					mTDFApplicationIdentifier->SetDataType((DiameterDataType)5);
					mTDFApplicationIdentifier->mspByteArray = mspByteArray;
					mTDFApplicationIdentifier->mAvpDecodedFlag = false;
					mTDFApplicationIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1058:
				{
					mTagsPresent[ADCRuleDefinition_FLOWINFORMATION] = 1;
					FlowInformation *lFlowInformation = new FlowInformation();
					if( lFlowInformation == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowInformation");
						throw lTssDiaMsgException;
					}
					lFlowInformation->setAvpCode(1058);
					lFlowInformation->SetDataType((DiameterDataType)6);
					lFlowInformation->mspByteArray = mspByteArray;
					lFlowInformation->mAvpDecodedFlag = false;
					lFlowInformation->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mFlowInformationGrpList == NULL)
						this->setFlowInformationGrpList();
					mFlowInformationGrpList->push_back(lFlowInformation);
					mBaseInterfaceList.push_back(lFlowInformation);
					
				}
				break;
			case 439:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_SERVICEIDENTIFIER] = 1;
					if( NULL == this->setServiceIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceIdentifier");
						throw lTssDiaMsgException;
					}
					mServiceIdentifier->setAvpCode(439);
					mServiceIdentifier->setAvpVendorId(lVenderId);
					mServiceIdentifier->SetDataType((DiameterDataType)3);
					mServiceIdentifier->mspByteArray = mspByteArray;
					mServiceIdentifier->mAvpDecodedFlag = false;
					mServiceIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 432:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_RATINGGROUP] = 1;
					if( NULL == this->setRatingGroup())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RatingGroup");
						throw lTssDiaMsgException;
					}
					mRatingGroup->setAvpCode(432);
					mRatingGroup->setAvpVendorId(lVenderId);
					mRatingGroup->SetDataType((DiameterDataType)3);
					mRatingGroup->mspByteArray = mspByteArray;
					mRatingGroup->mAvpDecodedFlag = false;
					mRatingGroup->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1011:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_REPORTINGLEVEL] = 1;
					if( NULL == this->setReportingLevel())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReportingLevel");
						throw lTssDiaMsgException;
					}
					mReportingLevel->setAvpCode(1011);
					mReportingLevel->setAvpVendorId(lVenderId);
					mReportingLevel->SetDataType((DiameterDataType)7);
					mReportingLevel->mspByteArray = mspByteArray;
					mReportingLevel->mAvpDecodedFlag = false;
					mReportingLevel->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1009:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_ONLINE] = 1;
					if( NULL == this->setOnline())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Online");
						throw lTssDiaMsgException;
					}
					mOnline->setAvpCode(1009);
					mOnline->setAvpVendorId(lVenderId);
					mOnline->SetDataType((DiameterDataType)7);
					mOnline->mspByteArray = mspByteArray;
					mOnline->mAvpDecodedFlag = false;
					mOnline->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1008:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_OFFLINE] = 1;
					if( NULL == this->setOffline())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Offline");
						throw lTssDiaMsgException;
					}
					mOffline->setAvpCode(1008);
					mOffline->setAvpVendorId(lVenderId);
					mOffline->SetDataType((DiameterDataType)7);
					mOffline->mspByteArray = mspByteArray;
					mOffline->mAvpDecodedFlag = false;
					mOffline->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1007:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_METERINGMETHOD] = 1;
					if( NULL == this->setMeteringMethod())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MeteringMethod");
						throw lTssDiaMsgException;
					}
					mMeteringMethod->setAvpCode(1007);
					mMeteringMethod->setAvpVendorId(lVenderId);
					mMeteringMethod->SetDataType((DiameterDataType)7);
					mMeteringMethod->mspByteArray = mspByteArray;
					mMeteringMethod->mAvpDecodedFlag = false;
					mMeteringMethod->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1010:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_PRECEDENCE] = 1;
					if( NULL == this->setPrecedence())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Precedence");
						throw lTssDiaMsgException;
					}
					mPrecedence->setAvpCode(1010);
					mPrecedence->setAvpVendorId(lVenderId);
					mPrecedence->SetDataType((DiameterDataType)3);
					mPrecedence->mspByteArray = mspByteArray;
					mPrecedence->mAvpDecodedFlag = false;
					mPrecedence->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 511:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_FLOWSTATUS] = 1;
					if( NULL == this->setFlowStatus())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowStatus");
						throw lTssDiaMsgException;
					}
					mFlowStatus->setAvpCode(511);
					mFlowStatus->setAvpVendorId(lVenderId);
					mFlowStatus->SetDataType((DiameterDataType)7);
					mFlowStatus->mspByteArray = mspByteArray;
					mFlowStatus->mAvpDecodedFlag = false;
					mFlowStatus->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1016:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_QOSINFORMATION] = 1;
					mTagsPresent[ADCRuleDefinition_QOSINFORMATION] = 1;
						if( NULL == this->setQoSInformation()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding QoSInformation");
						throw lTssDiaMsgException;
						}
					mQoSInformationGrp->setAvpCode(1016);
					mQoSInformationGrp->SetDataType((DiameterDataType)6);
					mQoSInformationGrp->mspByteArray = mspByteArray;
					mQoSInformationGrp->mAvpDecodedFlag = false;
					mQoSInformationGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mQoSInformationGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1066:
				{
					if( NULL == this->setMonitoringKey())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MonitoringKey");
						throw lTssDiaMsgException;
					}
					mMonitoringKey->setAvpCode(1066);
					mMonitoringKey->setAvpVendorId(lVenderId);
					mMonitoringKey->SetDataType((DiameterDataType)5);
					mMonitoringKey->mspByteArray = mspByteArray;
					mMonitoringKey->mAvpDecodedFlag = false;
					mMonitoringKey->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 531:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_SPONSORIDENTITY] = 1;
					if( NULL == this->setSponsorIdentity())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SponsorIdentity");
						throw lTssDiaMsgException;
					}
					mSponsorIdentity->setAvpCode(531);
					mSponsorIdentity->setAvpVendorId(lVenderId);
					mSponsorIdentity->SetDataType((DiameterDataType)5);
					mSponsorIdentity->mspByteArray = mspByteArray;
					mSponsorIdentity->mAvpDecodedFlag = false;
					mSponsorIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 532:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_APPLICATIONSERVICEPROVIDERIDENTITY] = 1;
					if( NULL == this->setApplicationServiceProviderIdentity())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ApplicationServiceProviderIdentity");
						throw lTssDiaMsgException;
					}
					mApplicationServiceProviderIdentity->setAvpCode(532);
					mApplicationServiceProviderIdentity->setAvpVendorId(lVenderId);
					mApplicationServiceProviderIdentity->SetDataType((DiameterDataType)5);
					mApplicationServiceProviderIdentity->mspByteArray = mspByteArray;
					mApplicationServiceProviderIdentity->mAvpDecodedFlag = false;
					mApplicationServiceProviderIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1085:
				{
					mTagsPresent[ADCRuleDefinition_REDIRECTINFORMATION] = 1;
					RedirectInformation *lRedirectInformation = new RedirectInformation();
					if( lRedirectInformation == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectInformation");
						throw lTssDiaMsgException;
					}
					lRedirectInformation->setAvpCode(1085);
					lRedirectInformation->SetDataType((DiameterDataType)6);
					lRedirectInformation->mspByteArray = mspByteArray;
					lRedirectInformation->mAvpDecodedFlag = false;
					lRedirectInformation->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mRedirectInformationGrpList == NULL)
						this->setRedirectInformationGrpList();
					mRedirectInformationGrpList->push_back(lRedirectInformation);
					mBaseInterfaceList.push_back(lRedirectInformation);
					
				}
				break;
			case 2809:
				{
					if( NULL == this->setMuteNotification())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MuteNotification");
						throw lTssDiaMsgException;
					}
					mMuteNotification->setAvpCode(2809);
					mMuteNotification->setAvpVendorId(lVenderId);
					mMuteNotification->SetDataType((DiameterDataType)7);
					mMuteNotification->mspByteArray = mspByteArray;
					mMuteNotification->mAvpDecodedFlag = false;
					mMuteNotification->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2836:
				{
					if( NULL == this->setTrafficSteeringPolicyIdentifierDL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TrafficSteeringPolicyIdentifierDL");
						throw lTssDiaMsgException;
					}
					mTrafficSteeringPolicyIdentifierDL->setAvpCode(2836);
					mTrafficSteeringPolicyIdentifierDL->setAvpVendorId(lVenderId);
					mTrafficSteeringPolicyIdentifierDL->SetDataType((DiameterDataType)5);
					mTrafficSteeringPolicyIdentifierDL->mspByteArray = mspByteArray;
					mTrafficSteeringPolicyIdentifierDL->mAvpDecodedFlag = false;
					mTrafficSteeringPolicyIdentifierDL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2837:
				{
					if( NULL == this->setTrafficSteeringPolicyIdentifierUL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TrafficSteeringPolicyIdentifierUL");
						throw lTssDiaMsgException;
					}
					mTrafficSteeringPolicyIdentifierUL->setAvpCode(2837);
					mTrafficSteeringPolicyIdentifierUL->setAvpVendorId(lVenderId);
					mTrafficSteeringPolicyIdentifierUL->SetDataType((DiameterDataType)5);
					mTrafficSteeringPolicyIdentifierUL->mspByteArray = mspByteArray;
					mTrafficSteeringPolicyIdentifierUL->mAvpDecodedFlag = false;
					mTrafficSteeringPolicyIdentifierUL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1014:
				{
						mMandatoryAvpSetVal [ADCRuleDefinition_TOSTRAFFICCLASS] = 1;
					if( NULL == this->setToSTrafficClass())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ToSTrafficClass");
						throw lTssDiaMsgException;
					}
					mToSTrafficClass->setAvpCode(1014);
					mToSTrafficClass->setAvpVendorId(lVenderId);
					mToSTrafficClass->SetDataType((DiameterDataType)5);
					mToSTrafficClass->mspByteArray = mspByteArray;
					mToSTrafficClass->mAvpDecodedFlag = false;
					mToSTrafficClass->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* ADCRuleDefinition::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleDefinition")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1096:
			{
				if(mADCRuleName != NULL)
					return mADCRuleName->Find(array, avpCode);
				else
					return NULL;
			}
			case 1088:
			{
				if(mTDFApplicationIdentifier != NULL)
					return mTDFApplicationIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 439:
			{
				if(mServiceIdentifier != NULL)
					return mServiceIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 432:
			{
				if(mRatingGroup != NULL)
					return mRatingGroup->Find(array, avpCode);
				else
					return NULL;
			}
			case 1011:
			{
				if(mReportingLevel != NULL)
					return mReportingLevel->Find(array, avpCode);
				else
					return NULL;
			}
			case 1009:
			{
				if(mOnline != NULL)
					return mOnline->Find(array, avpCode);
				else
					return NULL;
			}
			case 1008:
			{
				if(mOffline != NULL)
					return mOffline->Find(array, avpCode);
				else
					return NULL;
			}
			case 1007:
			{
				if(mMeteringMethod != NULL)
					return mMeteringMethod->Find(array, avpCode);
				else
					return NULL;
			}
			case 1010:
			{
				if(mPrecedence != NULL)
					return mPrecedence->Find(array, avpCode);
				else
					return NULL;
			}
			case 511:
			{
				if(mFlowStatus != NULL)
					return mFlowStatus->Find(array, avpCode);
				else
					return NULL;
			}
			case 1066:
			{
				if(mMonitoringKey != NULL)
					return mMonitoringKey->Find(array, avpCode);
				else
					return NULL;
			}
			case 531:
			{
				if(mSponsorIdentity != NULL)
					return mSponsorIdentity->Find(array, avpCode);
				else
					return NULL;
			}
			case 532:
			{
				if(mApplicationServiceProviderIdentity != NULL)
					return mApplicationServiceProviderIdentity->Find(array, avpCode);
				else
					return NULL;
			}
			case 2809:
			{
				if(mMuteNotification != NULL)
					return mMuteNotification->Find(array, avpCode);
				else
					return NULL;
			}
			case 2836:
			{
				if(mTrafficSteeringPolicyIdentifierDL != NULL)
					return mTrafficSteeringPolicyIdentifierDL->Find(array, avpCode);
				else
					return NULL;
			}
			case 2837:
			{
				if(mTrafficSteeringPolicyIdentifierUL != NULL)
					return mTrafficSteeringPolicyIdentifierUL->Find(array, avpCode);
				else
					return NULL;
			}
			case 1014:
			{
				if(mToSTrafficClass != NULL)
					return mToSTrafficClass->Find(array, avpCode);
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


BOOLEAN ADCRuleDefinition::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleDefinition")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1096:
			{
				if(mADCRuleName != NULL)
				{
					DiameterBaseInterface* inf =  mADCRuleName->Find(this->mspByteArray.get(), avpCode);
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
			case 1088:
			{
				if(mTDFApplicationIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mTDFApplicationIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 1058:
			{
				if(mFlowInformationGrpList != NULL)
				{
					for(auto itr = mFlowInformationGrpList->begin(); itr != mFlowInformationGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
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
			case 439:
			{
				if(mServiceIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mServiceIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 432:
			{
				if(mRatingGroup != NULL)
				{
					DiameterBaseInterface* inf =  mRatingGroup->Find(this->mspByteArray.get(), avpCode);
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
			case 1011:
			{
				if(mReportingLevel != NULL)
				{
					DiameterBaseInterface* inf =  mReportingLevel->Find(this->mspByteArray.get(), avpCode);
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
			case 1009:
			{
				if(mOnline != NULL)
				{
					DiameterBaseInterface* inf =  mOnline->Find(this->mspByteArray.get(), avpCode);
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
			case 1008:
			{
				if(mOffline != NULL)
				{
					DiameterBaseInterface* inf =  mOffline->Find(this->mspByteArray.get(), avpCode);
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
			case 1007:
			{
				if(mMeteringMethod != NULL)
				{
					DiameterBaseInterface* inf =  mMeteringMethod->Find(this->mspByteArray.get(), avpCode);
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
			case 1010:
			{
				if(mPrecedence != NULL)
				{
					DiameterBaseInterface* inf =  mPrecedence->Find(this->mspByteArray.get(), avpCode);
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
			case 511:
			{
				if(mFlowStatus != NULL)
				{
					DiameterBaseInterface* inf =  mFlowStatus->Find(this->mspByteArray.get(), avpCode);
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
			case 1016:
			{
				if(mQoSInformationGrp != NULL)
				{
						pBaseInterface.push_back(mQoSInformationGrp);
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
			case 1066:
			{
				if(mMonitoringKey != NULL)
				{
					DiameterBaseInterface* inf =  mMonitoringKey->Find(this->mspByteArray.get(), avpCode);
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
			case 531:
			{
				if(mSponsorIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mSponsorIdentity->Find(this->mspByteArray.get(), avpCode);
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
			case 532:
			{
				if(mApplicationServiceProviderIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mApplicationServiceProviderIdentity->Find(this->mspByteArray.get(), avpCode);
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
			case 1085:
			{
				if(mRedirectInformationGrpList != NULL)
				{
					for(auto itr = mRedirectInformationGrpList->begin(); itr != mRedirectInformationGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
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
			case 2809:
			{
				if(mMuteNotification != NULL)
				{
					DiameterBaseInterface* inf =  mMuteNotification->Find(this->mspByteArray.get(), avpCode);
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
			case 2836:
			{
				if(mTrafficSteeringPolicyIdentifierDL != NULL)
				{
					DiameterBaseInterface* inf =  mTrafficSteeringPolicyIdentifierDL->Find(this->mspByteArray.get(), avpCode);
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
			case 2837:
			{
				if(mTrafficSteeringPolicyIdentifierUL != NULL)
				{
					DiameterBaseInterface* inf =  mTrafficSteeringPolicyIdentifierUL->Find(this->mspByteArray.get(), avpCode);
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
			case 1014:
			{
				if(mToSTrafficClass != NULL)
				{
					DiameterBaseInterface* inf =  mToSTrafficClass->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> ADCRuleDefinition::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ADCRuleDefinition::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ADCRuleDefinition")     ;
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
			case 1096:
			{
				if(mADCRuleName != NULL)
				{
					DiameterBaseInterface* inf =  mADCRuleName->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1088:
			{
				if(mTDFApplicationIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mTDFApplicationIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1058:
			{
				if(mFlowInformationGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mFlowInformationGrpList->begin(); itr != mFlowInformationGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mFlowInformationGrpList->begin(); itr != mFlowInformationGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 439:
			{
				if(mServiceIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mServiceIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 432:
			{
				if(mRatingGroup != NULL)
				{
					DiameterBaseInterface* inf =  mRatingGroup->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1011:
			{
				if(mReportingLevel != NULL)
				{
					DiameterBaseInterface* inf =  mReportingLevel->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1009:
			{
				if(mOnline != NULL)
				{
					DiameterBaseInterface* inf =  mOnline->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1008:
			{
				if(mOffline != NULL)
				{
					DiameterBaseInterface* inf =  mOffline->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1007:
			{
				if(mMeteringMethod != NULL)
				{
					DiameterBaseInterface* inf =  mMeteringMethod->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1010:
			{
				if(mPrecedence != NULL)
				{
					DiameterBaseInterface* inf =  mPrecedence->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 511:
			{
				if(mFlowStatus != NULL)
				{
					DiameterBaseInterface* inf =  mFlowStatus->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1016:
			{
				if(mQoSInformationGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mQoSInformationGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mQoSInformationGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 1066:
			{
				if(mMonitoringKey != NULL)
				{
					DiameterBaseInterface* inf =  mMonitoringKey->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 531:
			{
				if(mSponsorIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mSponsorIdentity->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 532:
			{
				if(mApplicationServiceProviderIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mApplicationServiceProviderIdentity->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1085:
			{
				if(mRedirectInformationGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mRedirectInformationGrpList->begin(); itr != mRedirectInformationGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mRedirectInformationGrpList->begin(); itr != mRedirectInformationGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 2809:
			{
				if(mMuteNotification != NULL)
				{
					DiameterBaseInterface* inf =  mMuteNotification->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2836:
			{
				if(mTrafficSteeringPolicyIdentifierDL != NULL)
				{
					DiameterBaseInterface* inf =  mTrafficSteeringPolicyIdentifierDL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2837:
			{
				if(mTrafficSteeringPolicyIdentifierUL != NULL)
				{
					DiameterBaseInterface* inf =  mTrafficSteeringPolicyIdentifierUL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1014:
			{
				if(mToSTrafficClass != NULL)
				{
					DiameterBaseInterface* inf =  mToSTrafficClass->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
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


INT32 ADCRuleDefinition::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 ADCRuleDefinition::getAvpCode()
{
	return mAvpCode;
}
INT32 ADCRuleDefinition::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 ADCRuleDefinition::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 ADCRuleDefinition::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> ADCRuleDefinition::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void ADCRuleDefinition::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case ADCRuleDefinition_ADCRULENAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1096" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ADCRuleName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getADCRuleName()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_TDFAPPLICATIONIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1088" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TDFApplicationIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getTDFApplicationIdentifier()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_FLOWINFORMATION:
			{
				if( mFlowInformationGrpList->size() <= 0) {
					break;
				}

				mFlowInformationGrpIterator = this->getFlowInformationGrpList()->begin();
				while(mFlowInformationGrpIterator != this->getFlowInformationGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1058" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowInformation" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mFlowInformationGrpIterator)->Display(tab+1);
					mFlowInformationGrpIterator++;

				};

			}
				break;
			case ADCRuleDefinition_SERVICEIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "439" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ServiceIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getServiceIdentifier()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_RATINGGROUP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "432" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RatingGroup" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getRatingGroup()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_REPORTINGLEVEL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1011" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ReportingLevel" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getReportingLevel()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_ONLINE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1009" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Online" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getOnline()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_OFFLINE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1008" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Offline" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getOffline()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_METERINGMETHOD:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1007" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MeteringMethod" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMeteringMethod()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_PRECEDENCE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1010" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Precedence" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getPrecedence()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_FLOWSTATUS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "511" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowStatus" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getFlowStatus()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_QOSINFORMATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1016" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "QoSInformation" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getQoSInformation()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_MONITORINGKEY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1066" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MonitoringKey" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getMonitoringKey()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_SPONSORIDENTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "531" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SponsorIdentity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSponsorIdentity()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_APPLICATIONSERVICEPROVIDERIDENTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "532" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ApplicationServiceProviderIdentity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getApplicationServiceProviderIdentity()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_REDIRECTINFORMATION:
			{
				if( mRedirectInformationGrpList->size() <= 0) {
					break;
				}

				mRedirectInformationGrpIterator = this->getRedirectInformationGrpList()->begin();
				while(mRedirectInformationGrpIterator != this->getRedirectInformationGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1085" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectInformation" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mRedirectInformationGrpIterator)->Display(tab+1);
					mRedirectInformationGrpIterator++;

				};

			}
				break;
			case ADCRuleDefinition_MUTENOTIFICATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2809" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MuteNotification" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getMuteNotification()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2836" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TrafficSteeringPolicyIdentifierDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getTrafficSteeringPolicyIdentifierDL()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2837" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TrafficSteeringPolicyIdentifierUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getTrafficSteeringPolicyIdentifierUL()->Display(tab+1);
			}
				break;
			case ADCRuleDefinition_TOSTRAFFICCLASS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1014" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ToSTrafficClass" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getToSTrafficClass()->Display(tab+1);
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


BOOLEAN ADCRuleDefinition::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<20> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ADCRuleDefinition_ADCRULENAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1096");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1096", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_TDFAPPLICATIONIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1088");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1088", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_FLOWINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1058");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1058", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_SERVICEIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 439");
				}
				else
					sprintf(lMissingAvpInfo, "%s,439", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_RATINGGROUP:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 432");
				}
				else
					sprintf(lMissingAvpInfo, "%s,432", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_REPORTINGLEVEL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1011");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1011", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_ONLINE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1009");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1009", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_OFFLINE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1008");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1008", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_METERINGMETHOD:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1007");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1007", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_PRECEDENCE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1010");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1010", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_FLOWSTATUS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 511");
				}
				else
					sprintf(lMissingAvpInfo, "%s,511", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_QOSINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1016");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1016", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_MONITORINGKEY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1066");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1066", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_SPONSORIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 531");
				}
				else
					sprintf(lMissingAvpInfo, "%s,531", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_APPLICATIONSERVICEPROVIDERIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 532");
				}
				else
					sprintf(lMissingAvpInfo, "%s,532", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_REDIRECTINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1085");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1085", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_MUTENOTIFICATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2809");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2809", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERDL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2836");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2836", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_TRAFFICSTEERINGPOLICYIDENTIFIERUL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2837");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2837", lMissingAvpInfo);
			}
				break;
			case ADCRuleDefinition_TOSTRAFFICCLASS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1014");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1014", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
