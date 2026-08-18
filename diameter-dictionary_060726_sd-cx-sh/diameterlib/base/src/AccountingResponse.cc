#include "base/include/AccountingResponse.h"

using namespace BASE;
BOOLEAN AccountingResponse::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

AccountingResponse::AccountingResponse()
{
	mSessionId = NULL;
	mResultCode = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mOriginStateId = NULL;
	mAccountingRecordType = NULL;
	mAccountingRecordNumber = NULL;
	mAcctApplicationId = NULL;
	mVendorSpecificApplicationIdGrpList = NULL;
	mUserName = NULL;
	mAccountingSubSessionId = NULL;
	mAcctSessionId = NULL;
	mAcctMultiSessionId = NULL;
	mErrorMessage = NULL;
	mErrorReportingHost = NULL;
	mAcctInterimInterval = NULL;
	mAccountingRealtimeRequired = NULL;
	mEventTimestamp = NULL;
	mProxyInfoGrpList = NULL;
	mRouteRecordList = NULL;
	mCCRequestType = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<21>(string("111011001111101111111"));
	mMandatoryAvpSetVal.reset();
}

AccountingResponse::~AccountingResponse()
{
	if(mSessionId != NULL)
		delete mSessionId;
	if(mResultCode != NULL)
		delete mResultCode;
	if(mOriginHost != NULL)
		delete mOriginHost;
	if(mOriginRealm != NULL)
		delete mOriginRealm;
	if(mOriginStateId != NULL)
		delete mOriginStateId;
	if(mAccountingRecordType != NULL)
		delete mAccountingRecordType;
	if(mAccountingRecordNumber != NULL)
		delete mAccountingRecordNumber;
	if(mAcctApplicationId != NULL)
		delete mAcctApplicationId;
	if(mVendorSpecificApplicationIdGrpList != NULL){
		mVendorSpecificApplicationIdGrpIterator = mVendorSpecificApplicationIdGrpList->begin();
		while(mVendorSpecificApplicationIdGrpIterator != mVendorSpecificApplicationIdGrpList->end()){
	if(*mVendorSpecificApplicationIdGrpIterator != NULL)
			delete (*mVendorSpecificApplicationIdGrpIterator);
			mVendorSpecificApplicationIdGrpIterator++;
		}
		delete mVendorSpecificApplicationIdGrpList;
	}
	if(mUserName != NULL)
		delete mUserName;
	if(mAccountingSubSessionId != NULL)
		delete mAccountingSubSessionId;
	if(mAcctSessionId != NULL)
		delete mAcctSessionId;
	if(mAcctMultiSessionId != NULL)
		delete mAcctMultiSessionId;
	if(mErrorMessage != NULL)
		delete mErrorMessage;
	if(mErrorReportingHost != NULL)
		delete mErrorReportingHost;
	if(mAcctInterimInterval != NULL)
		delete mAcctInterimInterval;
	if(mAccountingRealtimeRequired != NULL)
		delete mAccountingRealtimeRequired;
	if(mEventTimestamp != NULL)
		delete mEventTimestamp;
	if(mProxyInfoGrpList != NULL){
		mProxyInfoGrpIterator = mProxyInfoGrpList->begin();
		while(mProxyInfoGrpIterator != mProxyInfoGrpList->end()){
	if(*mProxyInfoGrpIterator != NULL)
			delete (*mProxyInfoGrpIterator);
			mProxyInfoGrpIterator++;
		}
		delete mProxyInfoGrpList;
	}
	if(mRouteRecordList != NULL){
		mRouteRecordIterator = mRouteRecordList->begin();
		while(mRouteRecordIterator != mRouteRecordList->end()){
			delete (*mRouteRecordIterator);
			mRouteRecordIterator++;
		}
		delete mRouteRecordList;
	}
	if(mCCRequestType != NULL)
		delete mCCRequestType;
}

OctetString* AccountingResponse::setSessionId(){
	mMandatoryAvpSetVal [AccountingResponse_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[AccountingResponse_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void AccountingResponse::resetSessionId(){
	mTagsPresent[AccountingResponse_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

Unsigned32* AccountingResponse::setResultCode(){
	mMandatoryAvpSetVal [AccountingResponse_RESULTCODE] = 1;
	if(mResultCode == NULL)
	{
		mResultCode = new Unsigned32();
		mTagsPresent[AccountingResponse_RESULTCODE] = 1;
		return mResultCode;
	}
	return mResultCode;
}

void AccountingResponse::resetResultCode(){
	mTagsPresent[AccountingResponse_RESULTCODE] = 0;
	if(mResultCode != NULL)
	{
		delete mResultCode; 
		mResultCode = NULL;
	}
}

OctetString* AccountingResponse::setOriginHost(){
	mMandatoryAvpSetVal [AccountingResponse_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[AccountingResponse_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void AccountingResponse::resetOriginHost(){
	mTagsPresent[AccountingResponse_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* AccountingResponse::setOriginRealm(){
	mMandatoryAvpSetVal [AccountingResponse_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[AccountingResponse_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void AccountingResponse::resetOriginRealm(){
	mTagsPresent[AccountingResponse_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

Unsigned32* AccountingResponse::setOriginStateId(){
	mMandatoryAvpSetVal [AccountingResponse_ORIGINSTATEID] = 1;
	if(mOriginStateId == NULL)
	{
		mOriginStateId = new Unsigned32();
		mTagsPresent[AccountingResponse_ORIGINSTATEID] = 1;
		return mOriginStateId;
	}
	return mOriginStateId;
}

void AccountingResponse::resetOriginStateId(){
	mTagsPresent[AccountingResponse_ORIGINSTATEID] = 0;
	if(mOriginStateId != NULL)
	{
		delete mOriginStateId; 
		mOriginStateId = NULL;
	}
}

AccountingRecordType* AccountingResponse::setAccountingRecordType(){
	mMandatoryAvpSetVal [AccountingResponse_ACCOUNTINGRECORDTYPE] = 1;
	if(mAccountingRecordType == NULL)
	{
		mAccountingRecordType = new AccountingRecordType();
		mTagsPresent[AccountingResponse_ACCOUNTINGRECORDTYPE] = 1;
		return mAccountingRecordType;
	}
	return mAccountingRecordType;
}

void AccountingResponse::resetAccountingRecordType(){
	mTagsPresent[AccountingResponse_ACCOUNTINGRECORDTYPE] = 0;
	if(mAccountingRecordType != NULL)
	{
		delete mAccountingRecordType; 
		mAccountingRecordType = NULL;
	}
}

Unsigned32* AccountingResponse::setAccountingRecordNumber(){
	mMandatoryAvpSetVal [AccountingResponse_ACCOUNTINGRECORDNUMBER] = 1;
	if(mAccountingRecordNumber == NULL)
	{
		mAccountingRecordNumber = new Unsigned32();
		mTagsPresent[AccountingResponse_ACCOUNTINGRECORDNUMBER] = 1;
		return mAccountingRecordNumber;
	}
	return mAccountingRecordNumber;
}

void AccountingResponse::resetAccountingRecordNumber(){
	mTagsPresent[AccountingResponse_ACCOUNTINGRECORDNUMBER] = 0;
	if(mAccountingRecordNumber != NULL)
	{
		delete mAccountingRecordNumber; 
		mAccountingRecordNumber = NULL;
	}
}

Unsigned32* AccountingResponse::setAcctApplicationId(){
	if(mAcctApplicationId == NULL)
	{
		mAcctApplicationId = new Unsigned32();
		mTagsPresent[AccountingResponse_ACCTAPPLICATIONID] = 1;
		return mAcctApplicationId;
	}
	return mAcctApplicationId;
}

void AccountingResponse::resetAcctApplicationId(){
	mTagsPresent[AccountingResponse_ACCTAPPLICATIONID] = 0;
	if(mAcctApplicationId != NULL)
	{
		delete mAcctApplicationId; 
		mAcctApplicationId = NULL;
	}
}

OctetString* AccountingResponse::setUserName(){
	mMandatoryAvpSetVal [AccountingResponse_USERNAME] = 1;
	if(mUserName == NULL)
	{
		mUserName = new OctetString();
		mTagsPresent[AccountingResponse_USERNAME] = 1;
		return mUserName;
	}
	return mUserName;
}

void AccountingResponse::resetUserName(){
	mTagsPresent[AccountingResponse_USERNAME] = 0;
	if(mUserName != NULL)
	{
		delete mUserName; 
		mUserName = NULL;
	}
}

Unsigned64* AccountingResponse::setAccountingSubSessionId(){
	mMandatoryAvpSetVal [AccountingResponse_ACCOUNTINGSUBSESSIONID] = 1;
	if(mAccountingSubSessionId == NULL)
	{
		mAccountingSubSessionId = new Unsigned64();
		mTagsPresent[AccountingResponse_ACCOUNTINGSUBSESSIONID] = 1;
		return mAccountingSubSessionId;
	}
	return mAccountingSubSessionId;
}

void AccountingResponse::resetAccountingSubSessionId(){
	mTagsPresent[AccountingResponse_ACCOUNTINGSUBSESSIONID] = 0;
	if(mAccountingSubSessionId != NULL)
	{
		delete mAccountingSubSessionId; 
		mAccountingSubSessionId = NULL;
	}
}

OctetString* AccountingResponse::setAcctSessionId(){
	mMandatoryAvpSetVal [AccountingResponse_ACCTSESSIONID] = 1;
	if(mAcctSessionId == NULL)
	{
		mAcctSessionId = new OctetString();
		mTagsPresent[AccountingResponse_ACCTSESSIONID] = 1;
		return mAcctSessionId;
	}
	return mAcctSessionId;
}

void AccountingResponse::resetAcctSessionId(){
	mTagsPresent[AccountingResponse_ACCTSESSIONID] = 0;
	if(mAcctSessionId != NULL)
	{
		delete mAcctSessionId; 
		mAcctSessionId = NULL;
	}
}

OctetString* AccountingResponse::setAcctMultiSessionId(){
	mMandatoryAvpSetVal [AccountingResponse_ACCTMULTISESSIONID] = 1;
	if(mAcctMultiSessionId == NULL)
	{
		mAcctMultiSessionId = new OctetString();
		mTagsPresent[AccountingResponse_ACCTMULTISESSIONID] = 1;
		return mAcctMultiSessionId;
	}
	return mAcctMultiSessionId;
}

void AccountingResponse::resetAcctMultiSessionId(){
	mTagsPresent[AccountingResponse_ACCTMULTISESSIONID] = 0;
	if(mAcctMultiSessionId != NULL)
	{
		delete mAcctMultiSessionId; 
		mAcctMultiSessionId = NULL;
	}
}

OctetString* AccountingResponse::setErrorMessage(){
	if(mErrorMessage == NULL)
	{
		mErrorMessage = new OctetString();
		mTagsPresent[AccountingResponse_ERRORMESSAGE] = 1;
		return mErrorMessage;
	}
	return mErrorMessage;
}

void AccountingResponse::resetErrorMessage(){
	mTagsPresent[AccountingResponse_ERRORMESSAGE] = 0;
	if(mErrorMessage != NULL)
	{
		delete mErrorMessage; 
		mErrorMessage = NULL;
	}
}

OctetString* AccountingResponse::setErrorReportingHost(){
	if(mErrorReportingHost == NULL)
	{
		mErrorReportingHost = new OctetString();
		mTagsPresent[AccountingResponse_ERRORREPORTINGHOST] = 1;
		return mErrorReportingHost;
	}
	return mErrorReportingHost;
}

void AccountingResponse::resetErrorReportingHost(){
	mTagsPresent[AccountingResponse_ERRORREPORTINGHOST] = 0;
	if(mErrorReportingHost != NULL)
	{
		delete mErrorReportingHost; 
		mErrorReportingHost = NULL;
	}
}

Unsigned32* AccountingResponse::setAcctInterimInterval(){
	mMandatoryAvpSetVal [AccountingResponse_ACCTINTERIMINTERVAL] = 1;
	if(mAcctInterimInterval == NULL)
	{
		mAcctInterimInterval = new Unsigned32();
		mTagsPresent[AccountingResponse_ACCTINTERIMINTERVAL] = 1;
		return mAcctInterimInterval;
	}
	return mAcctInterimInterval;
}

void AccountingResponse::resetAcctInterimInterval(){
	mTagsPresent[AccountingResponse_ACCTINTERIMINTERVAL] = 0;
	if(mAcctInterimInterval != NULL)
	{
		delete mAcctInterimInterval; 
		mAcctInterimInterval = NULL;
	}
}

AccountingRealtimeRequired* AccountingResponse::setAccountingRealtimeRequired(){
	mMandatoryAvpSetVal [AccountingResponse_ACCOUNTINGREALTIMEREQUIRED] = 1;
	if(mAccountingRealtimeRequired == NULL)
	{
		mAccountingRealtimeRequired = new AccountingRealtimeRequired();
		mTagsPresent[AccountingResponse_ACCOUNTINGREALTIMEREQUIRED] = 1;
		return mAccountingRealtimeRequired;
	}
	return mAccountingRealtimeRequired;
}

void AccountingResponse::resetAccountingRealtimeRequired(){
	mTagsPresent[AccountingResponse_ACCOUNTINGREALTIMEREQUIRED] = 0;
	if(mAccountingRealtimeRequired != NULL)
	{
		delete mAccountingRealtimeRequired; 
		mAccountingRealtimeRequired = NULL;
	}
}

OctetString* AccountingResponse::setEventTimestamp(){
	if(mEventTimestamp == NULL)
	{
		mEventTimestamp = new OctetString();
		mTagsPresent[AccountingResponse_EVENTTIMESTAMP] = 1;
		return mEventTimestamp;
	}
	return mEventTimestamp;
}

void AccountingResponse::resetEventTimestamp(){
	mTagsPresent[AccountingResponse_EVENTTIMESTAMP] = 0;
	if(mEventTimestamp != NULL)
	{
		delete mEventTimestamp; 
		mEventTimestamp = NULL;
	}
}

CCRequestType* AccountingResponse::setCCRequestType(){
	mMandatoryAvpSetVal [AccountingResponse_CCREQUESTTYPE] = 1;
	if(mCCRequestType == NULL)
	{
		mCCRequestType = new CCRequestType();
		mTagsPresent[AccountingResponse_CCREQUESTTYPE] = 1;
		return mCCRequestType;
	}
	return mCCRequestType;
}

void AccountingResponse::resetCCRequestType(){
	mTagsPresent[AccountingResponse_CCREQUESTTYPE] = 0;
	if(mCCRequestType != NULL)
	{
		delete mCCRequestType; 
		mCCRequestType = NULL;
	}
}

OctetString* AccountingResponse::getSessionId(){
	if(NULL == mSessionId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SessionId is Null");
		throw lTssDiaMsgException;
	}
	if(!mSessionId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSessionId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SessionId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSessionId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSessionId->Decode(mspByteArray.get(), mSessionId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SessionId")     ;
			throw lTssDiaMsgException;
		}
		mSessionId->mAvpDecodedFlag = true;
	}
	return mSessionId;
}

Unsigned32* AccountingResponse::getResultCode(){
	if(NULL == mResultCode) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ResultCode is Null");
		throw lTssDiaMsgException;
	}
	if(!mResultCode->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mResultCode->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ResultCode is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mResultCode->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mResultCode->Decode(mspByteArray.get(), mResultCode->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ResultCode")     ;
			throw lTssDiaMsgException;
		}
		mResultCode->mAvpDecodedFlag = true;
	}
	return mResultCode;
}

OctetString* AccountingResponse::getOriginHost(){
	if(NULL == mOriginHost) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginHost is Null");
		throw lTssDiaMsgException;
	}
	if(!mOriginHost->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOriginHost->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginHost is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOriginHost->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOriginHost->Decode(mspByteArray.get(), mOriginHost->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginHost")     ;
			throw lTssDiaMsgException;
		}
		mOriginHost->mAvpDecodedFlag = true;
	}
	return mOriginHost;
}

OctetString* AccountingResponse::getOriginRealm(){
	if(NULL == mOriginRealm) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginRealm is Null");
		throw lTssDiaMsgException;
	}
	if(!mOriginRealm->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOriginRealm->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginRealm is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOriginRealm->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOriginRealm->Decode(mspByteArray.get(), mOriginRealm->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginRealm")     ;
			throw lTssDiaMsgException;
		}
		mOriginRealm->mAvpDecodedFlag = true;
	}
	return mOriginRealm;
}

Unsigned32* AccountingResponse::getOriginStateId(){
	if(NULL == mOriginStateId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginStateId is Null");
		throw lTssDiaMsgException;
	}
	if(!mOriginStateId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mOriginStateId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "OriginStateId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mOriginStateId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mOriginStateId->Decode(mspByteArray.get(), mOriginStateId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginStateId")     ;
			throw lTssDiaMsgException;
		}
		mOriginStateId->mAvpDecodedFlag = true;
	}
	return mOriginStateId;
}

AccountingRecordType* AccountingResponse::getAccountingRecordType(){
	if(NULL == mAccountingRecordType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccountingRecordType is Null");
		throw lTssDiaMsgException;
	}
	if(!mAccountingRecordType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAccountingRecordType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccountingRecordType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAccountingRecordType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAccountingRecordType->Decode(mspByteArray.get(), mAccountingRecordType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccountingRecordType")     ;
			throw lTssDiaMsgException;
		}
		mAccountingRecordType->mAvpDecodedFlag = true;
	}
	return mAccountingRecordType;
}

Unsigned32* AccountingResponse::getAccountingRecordNumber(){
	if(NULL == mAccountingRecordNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccountingRecordNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mAccountingRecordNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAccountingRecordNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccountingRecordNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAccountingRecordNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAccountingRecordNumber->Decode(mspByteArray.get(), mAccountingRecordNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccountingRecordNumber")     ;
			throw lTssDiaMsgException;
		}
		mAccountingRecordNumber->mAvpDecodedFlag = true;
	}
	return mAccountingRecordNumber;
}

Unsigned32* AccountingResponse::getAcctApplicationId(){
	if(NULL == mAcctApplicationId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcctApplicationId is Null");
		throw lTssDiaMsgException;
	}
	if(!mAcctApplicationId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAcctApplicationId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcctApplicationId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAcctApplicationId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAcctApplicationId->Decode(mspByteArray.get(), mAcctApplicationId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcctApplicationId")     ;
			throw lTssDiaMsgException;
		}
		mAcctApplicationId->mAvpDecodedFlag = true;
	}
	return mAcctApplicationId;
}

list<VendorSpecificApplicationId*>* AccountingResponse::getVendorSpecificApplicationIdGrpList()
{
	if(mVendorSpecificApplicationIdGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorSpecificApplicationId is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mVendorSpecificApplicationIdGrpList)
	{
		if(mVendorSpecificApplicationIdGrpList != NULL)
		{
		if(mVendorSpecificApplicationIdGrpList->size() == 0)
		{
			mTagsPresent[AccountingResponse_VENDORSPECIFICAPPLICATIONID] = 0;
			mVendorSpecificApplicationIdGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorSpecificApplicationId is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorSpecificApplicationId is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding VendorSpecificApplicationId")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mVendorSpecificApplicationIdGrpList;
}

list<VendorSpecificApplicationId*>* AccountingResponse::setVendorSpecificApplicationIdGrpList(){
	mTagsPresent[AccountingResponse_VENDORSPECIFICAPPLICATIONID] = 1;
	if(mVendorSpecificApplicationIdGrpList == NULL)
		mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
	mMandatoryAvpSetVal[AccountingResponse_VENDORSPECIFICAPPLICATIONID] = 1;
	mVendorSpecificApplicationIdGrpList->clear();
	return mVendorSpecificApplicationIdGrpList;
}

void AccountingResponse::resetVendorSpecificApplicationIdGrpList(){
	mTagsPresent[AccountingResponse_VENDORSPECIFICAPPLICATIONID] = 0;
	if(mVendorSpecificApplicationIdGrpList != NULL)
		delete mVendorSpecificApplicationIdGrpList;
}

OctetString* AccountingResponse::getUserName(){
	if(NULL == mUserName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserName is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserName->Decode(mspByteArray.get(), mUserName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserName")     ;
			throw lTssDiaMsgException;
		}
		mUserName->mAvpDecodedFlag = true;
	}
	return mUserName;
}

Unsigned64* AccountingResponse::getAccountingSubSessionId(){
	if(NULL == mAccountingSubSessionId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccountingSubSessionId is Null");
		throw lTssDiaMsgException;
	}
	if(!mAccountingSubSessionId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAccountingSubSessionId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccountingSubSessionId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAccountingSubSessionId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAccountingSubSessionId->Decode(mspByteArray.get(), mAccountingSubSessionId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccountingSubSessionId")     ;
			throw lTssDiaMsgException;
		}
		mAccountingSubSessionId->mAvpDecodedFlag = true;
	}
	return mAccountingSubSessionId;
}

OctetString* AccountingResponse::getAcctSessionId(){
	if(NULL == mAcctSessionId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcctSessionId is Null");
		throw lTssDiaMsgException;
	}
	if(!mAcctSessionId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAcctSessionId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcctSessionId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAcctSessionId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAcctSessionId->Decode(mspByteArray.get(), mAcctSessionId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcctSessionId")     ;
			throw lTssDiaMsgException;
		}
		mAcctSessionId->mAvpDecodedFlag = true;
	}
	return mAcctSessionId;
}

OctetString* AccountingResponse::getAcctMultiSessionId(){
	if(NULL == mAcctMultiSessionId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcctMultiSessionId is Null");
		throw lTssDiaMsgException;
	}
	if(!mAcctMultiSessionId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAcctMultiSessionId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcctMultiSessionId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAcctMultiSessionId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAcctMultiSessionId->Decode(mspByteArray.get(), mAcctMultiSessionId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcctMultiSessionId")     ;
			throw lTssDiaMsgException;
		}
		mAcctMultiSessionId->mAvpDecodedFlag = true;
	}
	return mAcctMultiSessionId;
}

OctetString* AccountingResponse::getErrorMessage(){
	if(NULL == mErrorMessage) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ErrorMessage is Null");
		throw lTssDiaMsgException;
	}
	if(!mErrorMessage->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mErrorMessage->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ErrorMessage is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mErrorMessage->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mErrorMessage->Decode(mspByteArray.get(), mErrorMessage->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ErrorMessage")     ;
			throw lTssDiaMsgException;
		}
		mErrorMessage->mAvpDecodedFlag = true;
	}
	return mErrorMessage;
}

OctetString* AccountingResponse::getErrorReportingHost(){
	if(NULL == mErrorReportingHost) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ErrorReportingHost is Null");
		throw lTssDiaMsgException;
	}
	if(!mErrorReportingHost->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mErrorReportingHost->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ErrorReportingHost is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mErrorReportingHost->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mErrorReportingHost->Decode(mspByteArray.get(), mErrorReportingHost->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ErrorReportingHost")     ;
			throw lTssDiaMsgException;
		}
		mErrorReportingHost->mAvpDecodedFlag = true;
	}
	return mErrorReportingHost;
}

Unsigned32* AccountingResponse::getAcctInterimInterval(){
	if(NULL == mAcctInterimInterval) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcctInterimInterval is Null");
		throw lTssDiaMsgException;
	}
	if(!mAcctInterimInterval->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAcctInterimInterval->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcctInterimInterval is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAcctInterimInterval->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAcctInterimInterval->Decode(mspByteArray.get(), mAcctInterimInterval->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcctInterimInterval")     ;
			throw lTssDiaMsgException;
		}
		mAcctInterimInterval->mAvpDecodedFlag = true;
	}
	return mAcctInterimInterval;
}

AccountingRealtimeRequired* AccountingResponse::getAccountingRealtimeRequired(){
	if(NULL == mAccountingRealtimeRequired) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccountingRealtimeRequired is Null");
		throw lTssDiaMsgException;
	}
	if(!mAccountingRealtimeRequired->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAccountingRealtimeRequired->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccountingRealtimeRequired is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAccountingRealtimeRequired->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAccountingRealtimeRequired->Decode(mspByteArray.get(), mAccountingRealtimeRequired->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccountingRealtimeRequired")     ;
			throw lTssDiaMsgException;
		}
		mAccountingRealtimeRequired->mAvpDecodedFlag = true;
	}
	return mAccountingRealtimeRequired;
}

OctetString* AccountingResponse::getEventTimestamp(){
	if(NULL == mEventTimestamp) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventTimestamp is Null");
		throw lTssDiaMsgException;
	}
	if(!mEventTimestamp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mEventTimestamp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "EventTimestamp is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mEventTimestamp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mEventTimestamp->Decode(mspByteArray.get(), mEventTimestamp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventTimestamp")     ;
			throw lTssDiaMsgException;
		}
		mEventTimestamp->mAvpDecodedFlag = true;
	}
	return mEventTimestamp;
}

list<ProxyInfo*>* AccountingResponse::getProxyInfoGrpList()
{
	if(mProxyInfoGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ProxyInfo is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mProxyInfoGrpList)
	{
		if(mProxyInfoGrpList != NULL)
		{
		if(mProxyInfoGrpList->size() == 0)
		{
			mTagsPresent[AccountingResponse_PROXYINFO] = 0;
			mProxyInfoGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ProxyInfo is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ProxyInfo is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ProxyInfo")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mProxyInfoGrpList;
}

list<ProxyInfo*>* AccountingResponse::setProxyInfoGrpList(){
	mTagsPresent[AccountingResponse_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<ProxyInfo*>;
	mMandatoryAvpSetVal[AccountingResponse_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void AccountingResponse::resetProxyInfoGrpList(){
	mTagsPresent[AccountingResponse_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

list<OctetString*>* AccountingResponse::getRouteRecordList()
{
	if(mRouteRecordList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RouteRecord is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mRouteRecordList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RouteRecord is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RouteRecord")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mRouteRecordList;
}

list<OctetString*>* AccountingResponse::setRouteRecordList() {
	mTagsPresent[AccountingResponse_ROUTERECORD] = 1;
	if(mRouteRecordList == NULL)
		mRouteRecordList = new list<OctetString*>;
	mMandatoryAvpSetVal [AccountingResponse_ROUTERECORD] = 1;
	mRouteRecordList->clear();
	return mRouteRecordList;
}

void AccountingResponse::resetRouteRecordList(){
	mTagsPresent[AccountingResponse_ROUTERECORD] = 0;
	if(mRouteRecordList != NULL)
		delete mRouteRecordList;
}

CCRequestType* AccountingResponse::getCCRequestType(){
	if(NULL == mCCRequestType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCRequestType is Null");
		throw lTssDiaMsgException;
	}
	if(!mCCRequestType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCCRequestType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCRequestType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCCRequestType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCCRequestType->Decode(mspByteArray.get(), mCCRequestType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCRequestType")     ;
			throw lTssDiaMsgException;
		}
		mCCRequestType->mAvpDecodedFlag = true;
	}
	return mCCRequestType;
}



int AccountingResponse::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;
	unsigned lLengthOffset = 0;
	array->size=0;
	array->offset = 0;
	memset(array, 0, sizeof(byteArray));
	memcpy(&array->byte[ array->offset++], &mDiameterMsgHeader->mVersion, sizeof(UINT8));
	lLengthOffset = array->offset;
	array->offset +=3;
	UINT8   lCmdFlg = this->getCmdFlag();
	memcpy(&array->byte[ array->offset++], &lCmdFlg, sizeof(UINT8));
	array->byte[array->offset++] = (271>>16) & 0xFF;
	array->byte[array->offset++] = (271>>8) & 0xFF;
	array->byte[array->offset++] = (271) & 0xFF;
	lTempHtonlVar =  htonl(mDiameterMsgHeader->mApplId);
	memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_APPLN_ID_SIZE);
	array->offset += DIA_APPLN_ID_SIZE; 
	lTempHtonlVar =  htonl(mDiameterMsgHeader->mHopByHopId);
	memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_HOP_BY_HOP_ID_SIZE);
	array->offset += DIA_HOP_BY_HOP_ID_SIZE; 
	lTempHtonlVar =  htonl(mDiameterMsgHeader->mEndToEndId);
	memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_END_TO_END_ID_SIZE);
	array->offset += DIA_END_TO_END_ID_SIZE;
	array->size = array->offset;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case AccountingResponse_SESSIONID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(263);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mSessionId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSessionId->getAvpOffsetLen().first], mSessionId->getAvpOffsetLen().second);
						array->offset += mSessionId->getAvpOffsetLen().second;
						array->size += mSessionId->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSessionId->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSessionId->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SessionId");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSessionId->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSessionId->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SessionId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_RESULTCODE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(268);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mResultCode->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mResultCode->getAvpOffsetLen().first], mResultCode->getAvpOffsetLen().second);
						array->offset += mResultCode->getAvpOffsetLen().second;
						array->size += mResultCode->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ResultCode");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mResultCode->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ResultCode");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ORIGINHOST:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(264);
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
					if(!mOriginHost->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOriginHost->getAvpOffsetLen().first], mOriginHost->getAvpOffsetLen().second);
						array->offset += mOriginHost->getAvpOffsetLen().second;
						array->size += mOriginHost->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mOriginHost->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mOriginHost->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginHost");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mOriginHost->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mOriginHost->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginHost");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ORIGINREALM:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(296);
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
					if(!mOriginRealm->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOriginRealm->getAvpOffsetLen().first], mOriginRealm->getAvpOffsetLen().second);
						array->offset += mOriginRealm->getAvpOffsetLen().second;
						array->size += mOriginRealm->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mOriginRealm->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mOriginRealm->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginRealm");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mOriginRealm->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mOriginRealm->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginRealm");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ORIGINSTATEID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(278);
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
					if(!mOriginStateId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mOriginStateId->getAvpOffsetLen().first], mOriginStateId->getAvpOffsetLen().second);
						array->offset += mOriginStateId->getAvpOffsetLen().second;
						array->size += mOriginStateId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginStateId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mOriginStateId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding OriginStateId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ACCOUNTINGRECORDTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(480);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mAccountingRecordType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAccountingRecordType->getAvpOffsetLen().first], mAccountingRecordType->getAvpOffsetLen().second);
						array->offset += mAccountingRecordType->getAvpOffsetLen().second;
						array->size += mAccountingRecordType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccountingRecordType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAccountingRecordType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccountingRecordType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ACCOUNTINGRECORDNUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(485);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mAccountingRecordNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAccountingRecordNumber->getAvpOffsetLen().first], mAccountingRecordNumber->getAvpOffsetLen().second);
						array->offset += mAccountingRecordNumber->getAvpOffsetLen().second;
						array->size += mAccountingRecordNumber->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccountingRecordNumber");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAccountingRecordNumber->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccountingRecordNumber");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ACCTAPPLICATIONID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(259);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 0;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(0))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mAcctApplicationId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAcctApplicationId->getAvpOffsetLen().first], mAcctApplicationId->getAvpOffsetLen().second);
						array->offset += mAcctApplicationId->getAvpOffsetLen().second;
						array->size += mAcctApplicationId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AcctApplicationId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAcctApplicationId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AcctApplicationId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_VENDORSPECIFICAPPLICATIONID:
			{
				if( mVendorSpecificApplicationIdGrpList->size() <= 0) {
					break;
				}

				mVendorSpecificApplicationIdGrpIterator = this->getVendorSpecificApplicationIdGrpList()->begin();
				while(mVendorSpecificApplicationIdGrpIterator != mVendorSpecificApplicationIdGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(260);
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
					if(((*mVendorSpecificApplicationIdGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding VendorSpecificApplicationId");
						throw lTssDiaMsgException;
					}
					
					mVendorSpecificApplicationIdGrpIterator++;
				}
				}
				break;
			case AccountingResponse_USERNAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1);
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
					if(!mUserName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUserName->getAvpOffsetLen().first], mUserName->getAvpOffsetLen().second);
						array->offset += mUserName->getAvpOffsetLen().second;
						array->size += mUserName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUserName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUserName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUserName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUserName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ACCOUNTINGSUBSESSIONID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(287);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mAccountingSubSessionId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAccountingSubSessionId->getAvpOffsetLen().first], mAccountingSubSessionId->getAvpOffsetLen().second);
						array->offset += mAccountingSubSessionId->getAvpOffsetLen().second;
						array->size += mAccountingSubSessionId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccountingSubSessionId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAccountingSubSessionId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccountingSubSessionId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ACCTSESSIONID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(44);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mAcctSessionId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAcctSessionId->getAvpOffsetLen().first], mAcctSessionId->getAvpOffsetLen().second);
						array->offset += mAcctSessionId->getAvpOffsetLen().second;
						array->size += mAcctSessionId->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mAcctSessionId->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mAcctSessionId->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AcctSessionId");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mAcctSessionId->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mAcctSessionId->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AcctSessionId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ACCTMULTISESSIONID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(50);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mAcctMultiSessionId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAcctMultiSessionId->getAvpOffsetLen().first], mAcctMultiSessionId->getAvpOffsetLen().second);
						array->offset += mAcctMultiSessionId->getAvpOffsetLen().second;
						array->size += mAcctMultiSessionId->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mAcctMultiSessionId->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mAcctMultiSessionId->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AcctMultiSessionId");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mAcctMultiSessionId->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mAcctMultiSessionId->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AcctMultiSessionId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ERRORMESSAGE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(281);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 0;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(0))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mErrorMessage->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mErrorMessage->getAvpOffsetLen().first], mErrorMessage->getAvpOffsetLen().second);
						array->offset += mErrorMessage->getAvpOffsetLen().second;
						array->size += mErrorMessage->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mErrorMessage->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mErrorMessage->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ErrorMessage");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mErrorMessage->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mErrorMessage->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ErrorMessage");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ERRORREPORTINGHOST:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(294);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 32;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(32))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mErrorReportingHost->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mErrorReportingHost->getAvpOffsetLen().first], mErrorReportingHost->getAvpOffsetLen().second);
						array->offset += mErrorReportingHost->getAvpOffsetLen().second;
						array->size += mErrorReportingHost->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mErrorReportingHost->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mErrorReportingHost->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ErrorReportingHost");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mErrorReportingHost->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mErrorReportingHost->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ErrorReportingHost");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ACCTINTERIMINTERVAL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(85);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mAcctInterimInterval->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAcctInterimInterval->getAvpOffsetLen().first], mAcctInterimInterval->getAvpOffsetLen().second);
						array->offset += mAcctInterimInterval->getAvpOffsetLen().second;
						array->size += mAcctInterimInterval->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AcctInterimInterval");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAcctInterimInterval->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AcctInterimInterval");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_ACCOUNTINGREALTIMEREQUIRED:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(483);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mAccountingRealtimeRequired->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAccountingRealtimeRequired->getAvpOffsetLen().first], mAccountingRealtimeRequired->getAvpOffsetLen().second);
						array->offset += mAccountingRealtimeRequired->getAvpOffsetLen().second;
						array->size += mAccountingRealtimeRequired->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccountingRealtimeRequired");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAccountingRealtimeRequired->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccountingRealtimeRequired");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_EVENTTIMESTAMP:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(55);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 0;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(0))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mEventTimestamp->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mEventTimestamp->getAvpOffsetLen().first], mEventTimestamp->getAvpOffsetLen().second);
						array->offset += mEventTimestamp->getAvpOffsetLen().second;
						array->size += mEventTimestamp->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mEventTimestamp->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mEventTimestamp->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventTimestamp");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mEventTimestamp->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mEventTimestamp->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding EventTimestamp");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccountingResponse_PROXYINFO:
			{
				if( mProxyInfoGrpList->size() <= 0) {
					break;
				}

				mProxyInfoGrpIterator = this->getProxyInfoGrpList()->begin();
				while(mProxyInfoGrpIterator != mProxyInfoGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(284);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
						{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(((*mProxyInfoGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ProxyInfo");
						throw lTssDiaMsgException;
					}
					
					mProxyInfoGrpIterator++;
				}
				}
				break;
			case AccountingResponse_ROUTERECORD:
			{
					if( mRouteRecordList->size() <= 0) {
						break;
					}

					mRouteRecordIterator = this->getRouteRecordList()->begin();
					while(mRouteRecordIterator != mRouteRecordList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(282);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
 					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!(*mRouteRecordIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mRouteRecordIterator)->getAvpOffsetLen().first], (*mRouteRecordIterator)->getAvpOffsetLen().second);
						array->offset += (*mRouteRecordIterator)->getAvpOffsetLen().second;
						array->size += (*mRouteRecordIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mRouteRecordIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mRouteRecordIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RouteRecord");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mRouteRecordIterator++;
						continue;
					}
						if(((*mRouteRecordIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mRouteRecordIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RouteRecord");
							throw lTssDiaMsgException;
						}
						mRouteRecordIterator++;
				}
				}
				break;
			case AccountingResponse_CCREQUESTTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(416);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 64;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(64))
					{ 
						INT32 venderId=0;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mCCRequestType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCCRequestType->getAvpOffsetLen().first], mCCRequestType->getAvpOffsetLen().second);
						array->offset += mCCRequestType->getAvpOffsetLen().second;
						array->size += mCCRequestType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCRequestType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCCRequestType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCRequestType");
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

	if(DiameterTLVUtil::avp_msg_length_encode(lLengthOffset, array) == false){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);
		throw lTssDiaMsgException;
	}

	return DIAMETER_NO_ERR;
}


int AccountingResponse::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
{
	if(mDiameterMsgHeader == NULL){
		mDiameterMsgHeader = new DiameterMsgHeader();
		if(mDiameterMsgHeader == NULL){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
		throw lTssDiaMsgException;
		}
	}
	mspByteArray = make_shared<byteArray>();
	memcpy(mspByteArray.get(), array, sizeof(byteArray));
	mAvpDecodedFlag = true;
	array->offset = 0;
	UINT32  	lMsgLen = 0;
	UINT8   	lCmdFlag= 0;
	memcpy( &mDiameterMsgHeader->mVersion, &array->byte[0],sizeof(UINT8));
	if( mDiameterMsgHeader->mVersion != 1){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_VERSION_ERR, "Version");
		throw lTssDiaMsgException;
	}

	array->offset++;
	if(false == DiameterTLVUtil::decodeMessageLength(array, mDiameterMsgHeader->mMsgLen))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	memcpy( &lCmdFlag, &array->byte[array->offset++],sizeof(UINT8));
	this->setCmdFlag(lCmdFlag)
;	if(false == DiameterTLVUtil::decodeAvpCmdIntegerValue(array, mDiameterMsgHeader->mCmdCode, DIA_CMD_CODE_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	if(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mApplId, DIA_APPLN_ID_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	if(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mHopByHopId, DIA_HOP_BY_HOP_ID_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	if(false == DiameterTLVUtil::decodeIntegerValue(array, mDiameterMsgHeader->mEndToEndId, DIA_END_TO_END_ID_SIZE))
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
		throw lTssDiaMsgException;
	}

	lMsgLen = (mDiameterMsgHeader->mMsgLen-array->offset);
	if( mDiameterMsgHeader->mMsgLen != array->size){
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Invalid Msg Len");
		throw lTssDiaMsgException;
	}
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
			case 263:
				{
						mMandatoryAvpSetVal [AccountingResponse_SESSIONID] = 1;
					if( NULL == this->setSessionId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SessionId");
						throw lTssDiaMsgException;
					}
					mSessionId->setAvpCode(263);
					mSessionId->setAvpVendorId(lVenderId);
					mSessionId->SetDataType((DiameterDataType)5);
					mSessionId->mspByteArray = mspByteArray;
					mSessionId->mAvpDecodedFlag = false;
					mSessionId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 268:
				{
						mMandatoryAvpSetVal [AccountingResponse_RESULTCODE] = 1;
					if( NULL == this->setResultCode())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ResultCode");
						throw lTssDiaMsgException;
					}
					mResultCode->setAvpCode(268);
					mResultCode->setAvpVendorId(lVenderId);
					mResultCode->SetDataType((DiameterDataType)3);
					mResultCode->mspByteArray = mspByteArray;
					mResultCode->mAvpDecodedFlag = false;
					mResultCode->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 264:
				{
						mMandatoryAvpSetVal [AccountingResponse_ORIGINHOST] = 1;
					if( NULL == this->setOriginHost())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginHost");
						throw lTssDiaMsgException;
					}
					mOriginHost->setAvpCode(264);
					mOriginHost->setAvpVendorId(lVenderId);
					mOriginHost->SetDataType((DiameterDataType)5);
					mOriginHost->mspByteArray = mspByteArray;
					mOriginHost->mAvpDecodedFlag = false;
					mOriginHost->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 296:
				{
						mMandatoryAvpSetVal [AccountingResponse_ORIGINREALM] = 1;
					if( NULL == this->setOriginRealm())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginRealm");
						throw lTssDiaMsgException;
					}
					mOriginRealm->setAvpCode(296);
					mOriginRealm->setAvpVendorId(lVenderId);
					mOriginRealm->SetDataType((DiameterDataType)5);
					mOriginRealm->mspByteArray = mspByteArray;
					mOriginRealm->mAvpDecodedFlag = false;
					mOriginRealm->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 278:
				{
						mMandatoryAvpSetVal [AccountingResponse_ORIGINSTATEID] = 1;
					if( NULL == this->setOriginStateId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding OriginStateId");
						throw lTssDiaMsgException;
					}
					mOriginStateId->setAvpCode(278);
					mOriginStateId->setAvpVendorId(lVenderId);
					mOriginStateId->SetDataType((DiameterDataType)3);
					mOriginStateId->mspByteArray = mspByteArray;
					mOriginStateId->mAvpDecodedFlag = false;
					mOriginStateId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 480:
				{
						mMandatoryAvpSetVal [AccountingResponse_ACCOUNTINGRECORDTYPE] = 1;
					if( NULL == this->setAccountingRecordType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccountingRecordType");
						throw lTssDiaMsgException;
					}
					mAccountingRecordType->setAvpCode(480);
					mAccountingRecordType->setAvpVendorId(lVenderId);
					mAccountingRecordType->SetDataType((DiameterDataType)7);
					mAccountingRecordType->mspByteArray = mspByteArray;
					mAccountingRecordType->mAvpDecodedFlag = false;
					mAccountingRecordType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 485:
				{
						mMandatoryAvpSetVal [AccountingResponse_ACCOUNTINGRECORDNUMBER] = 1;
					if( NULL == this->setAccountingRecordNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccountingRecordNumber");
						throw lTssDiaMsgException;
					}
					mAccountingRecordNumber->setAvpCode(485);
					mAccountingRecordNumber->setAvpVendorId(lVenderId);
					mAccountingRecordNumber->SetDataType((DiameterDataType)3);
					mAccountingRecordNumber->mspByteArray = mspByteArray;
					mAccountingRecordNumber->mAvpDecodedFlag = false;
					mAccountingRecordNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 259:
				{
					if( NULL == this->setAcctApplicationId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcctApplicationId");
						throw lTssDiaMsgException;
					}
					mAcctApplicationId->setAvpCode(259);
					mAcctApplicationId->setAvpVendorId(lVenderId);
					mAcctApplicationId->SetDataType((DiameterDataType)3);
					mAcctApplicationId->mspByteArray = mspByteArray;
					mAcctApplicationId->mAvpDecodedFlag = false;
					mAcctApplicationId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 260:
				{
						mMandatoryAvpSetVal [AccountingResponse_VENDORSPECIFICAPPLICATIONID] = 1;
					mTagsPresent[AccountingResponse_VENDORSPECIFICAPPLICATIONID] = 1;
					VendorSpecificApplicationId *lVendorSpecificApplicationId = new VendorSpecificApplicationId();
					if( lVendorSpecificApplicationId == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding VendorSpecificApplicationId");
						throw lTssDiaMsgException;
					}
					lVendorSpecificApplicationId->setAvpCode(260);
					lVendorSpecificApplicationId->SetDataType((DiameterDataType)6);
					lVendorSpecificApplicationId->mspByteArray = mspByteArray;
					lVendorSpecificApplicationId->mAvpDecodedFlag = false;
					lVendorSpecificApplicationId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mVendorSpecificApplicationIdGrpList == NULL)
						this->setVendorSpecificApplicationIdGrpList();
					mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
					mBaseInterfaceList.push_back(lVendorSpecificApplicationId);
					
				}
				break;
			case 1:
				{
						mMandatoryAvpSetVal [AccountingResponse_USERNAME] = 1;
					if( NULL == this->setUserName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserName");
						throw lTssDiaMsgException;
					}
					mUserName->setAvpCode(1);
					mUserName->setAvpVendorId(lVenderId);
					mUserName->SetDataType((DiameterDataType)5);
					mUserName->mspByteArray = mspByteArray;
					mUserName->mAvpDecodedFlag = false;
					mUserName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 287:
				{
						mMandatoryAvpSetVal [AccountingResponse_ACCOUNTINGSUBSESSIONID] = 1;
					if( NULL == this->setAccountingSubSessionId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccountingSubSessionId");
						throw lTssDiaMsgException;
					}
					mAccountingSubSessionId->setAvpCode(287);
					mAccountingSubSessionId->setAvpVendorId(lVenderId);
					mAccountingSubSessionId->SetDataType((DiameterDataType)4);
					mAccountingSubSessionId->mspByteArray = mspByteArray;
					mAccountingSubSessionId->mAvpDecodedFlag = false;
					mAccountingSubSessionId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 44:
				{
						mMandatoryAvpSetVal [AccountingResponse_ACCTSESSIONID] = 1;
					if( NULL == this->setAcctSessionId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcctSessionId");
						throw lTssDiaMsgException;
					}
					mAcctSessionId->setAvpCode(44);
					mAcctSessionId->setAvpVendorId(lVenderId);
					mAcctSessionId->SetDataType((DiameterDataType)5);
					mAcctSessionId->mspByteArray = mspByteArray;
					mAcctSessionId->mAvpDecodedFlag = false;
					mAcctSessionId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 50:
				{
						mMandatoryAvpSetVal [AccountingResponse_ACCTMULTISESSIONID] = 1;
					if( NULL == this->setAcctMultiSessionId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcctMultiSessionId");
						throw lTssDiaMsgException;
					}
					mAcctMultiSessionId->setAvpCode(50);
					mAcctMultiSessionId->setAvpVendorId(lVenderId);
					mAcctMultiSessionId->SetDataType((DiameterDataType)5);
					mAcctMultiSessionId->mspByteArray = mspByteArray;
					mAcctMultiSessionId->mAvpDecodedFlag = false;
					mAcctMultiSessionId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 281:
				{
					if( NULL == this->setErrorMessage())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ErrorMessage");
						throw lTssDiaMsgException;
					}
					mErrorMessage->setAvpCode(281);
					mErrorMessage->setAvpVendorId(lVenderId);
					mErrorMessage->SetDataType((DiameterDataType)5);
					mErrorMessage->mspByteArray = mspByteArray;
					mErrorMessage->mAvpDecodedFlag = false;
					mErrorMessage->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 294:
				{
					if( NULL == this->setErrorReportingHost())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ErrorReportingHost");
						throw lTssDiaMsgException;
					}
					mErrorReportingHost->setAvpCode(294);
					mErrorReportingHost->setAvpVendorId(lVenderId);
					mErrorReportingHost->SetDataType((DiameterDataType)5);
					mErrorReportingHost->mspByteArray = mspByteArray;
					mErrorReportingHost->mAvpDecodedFlag = false;
					mErrorReportingHost->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 85:
				{
						mMandatoryAvpSetVal [AccountingResponse_ACCTINTERIMINTERVAL] = 1;
					if( NULL == this->setAcctInterimInterval())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcctInterimInterval");
						throw lTssDiaMsgException;
					}
					mAcctInterimInterval->setAvpCode(85);
					mAcctInterimInterval->setAvpVendorId(lVenderId);
					mAcctInterimInterval->SetDataType((DiameterDataType)3);
					mAcctInterimInterval->mspByteArray = mspByteArray;
					mAcctInterimInterval->mAvpDecodedFlag = false;
					mAcctInterimInterval->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 483:
				{
						mMandatoryAvpSetVal [AccountingResponse_ACCOUNTINGREALTIMEREQUIRED] = 1;
					if( NULL == this->setAccountingRealtimeRequired())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccountingRealtimeRequired");
						throw lTssDiaMsgException;
					}
					mAccountingRealtimeRequired->setAvpCode(483);
					mAccountingRealtimeRequired->setAvpVendorId(lVenderId);
					mAccountingRealtimeRequired->SetDataType((DiameterDataType)7);
					mAccountingRealtimeRequired->mspByteArray = mspByteArray;
					mAccountingRealtimeRequired->mAvpDecodedFlag = false;
					mAccountingRealtimeRequired->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 55:
				{
					if( NULL == this->setEventTimestamp())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding EventTimestamp");
						throw lTssDiaMsgException;
					}
					mEventTimestamp->setAvpCode(55);
					mEventTimestamp->setAvpVendorId(lVenderId);
					mEventTimestamp->SetDataType((DiameterDataType)5);
					mEventTimestamp->mspByteArray = mspByteArray;
					mEventTimestamp->mAvpDecodedFlag = false;
					mEventTimestamp->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 284:
				{
						mMandatoryAvpSetVal [AccountingResponse_PROXYINFO] = 1;
					mTagsPresent[AccountingResponse_PROXYINFO] = 1;
					ProxyInfo *lProxyInfo = new ProxyInfo();
					if( lProxyInfo == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ProxyInfo");
						throw lTssDiaMsgException;
					}
					lProxyInfo->setAvpCode(284);
					lProxyInfo->SetDataType((DiameterDataType)6);
					lProxyInfo->mspByteArray = mspByteArray;
					lProxyInfo->mAvpDecodedFlag = false;
					lProxyInfo->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mProxyInfoGrpList == NULL)
						this->setProxyInfoGrpList();
					mProxyInfoGrpList->push_back(lProxyInfo);
					mBaseInterfaceList.push_back(lProxyInfo);
					
				}
				break;
			case 282:
				{
						mMandatoryAvpSetVal [AccountingResponse_ROUTERECORD] = 1;
					mTagsPresent[AccountingResponse_ROUTERECORD] = 1;
					OctetString *lRouteRecord = new OctetString();
					if( lRouteRecord == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RouteRecord");
						throw lTssDiaMsgException;
					}
					lRouteRecord->setAvpCode(282);
					lRouteRecord->setAvpVendorId(lVenderId);
					lRouteRecord->SetDataType((DiameterDataType)5);
					lRouteRecord->mspByteArray = mspByteArray;
					lRouteRecord->mAvpDecodedFlag = false;
					lRouteRecord->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mRouteRecordList == NULL)
						this->setRouteRecordList();
					mRouteRecordList->push_back(lRouteRecord);
					
				}
				break;
			case 416:
				{
						mMandatoryAvpSetVal [AccountingResponse_CCREQUESTTYPE] = 1;
					if( NULL == this->setCCRequestType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCRequestType");
						throw lTssDiaMsgException;
					}
					mCCRequestType->setAvpCode(416);
					mCCRequestType->setAvpVendorId(lVenderId);
					mCCRequestType->SetDataType((DiameterDataType)7);
					mCCRequestType->mspByteArray = mspByteArray;
					mCCRequestType->mAvpDecodedFlag = false;
					mCCRequestType->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* AccountingResponse::Find(byteArray *array, UINT32 avpCode)
{
		if(!mDecodeFlag && array != NULL)
			this->Decode(array);

		switch(avpCode)
		{
			case 263:
			{
				if(mSessionId != NULL)
					return mSessionId->Find(array, avpCode);
				else
					return NULL;
			}
			case 268:
			{
				if(mResultCode != NULL)
					return mResultCode->Find(array, avpCode);
				else
					return NULL;
			}
			case 264:
			{
				if(mOriginHost != NULL)
					return mOriginHost->Find(array, avpCode);
				else
					return NULL;
			}
			case 296:
			{
				if(mOriginRealm != NULL)
					return mOriginRealm->Find(array, avpCode);
				else
					return NULL;
			}
			case 278:
			{
				if(mOriginStateId != NULL)
					return mOriginStateId->Find(array, avpCode);
				else
					return NULL;
			}
			case 480:
			{
				if(mAccountingRecordType != NULL)
					return mAccountingRecordType->Find(array, avpCode);
				else
					return NULL;
			}
			case 485:
			{
				if(mAccountingRecordNumber != NULL)
					return mAccountingRecordNumber->Find(array, avpCode);
				else
					return NULL;
			}
			case 259:
			{
				if(mAcctApplicationId != NULL)
					return mAcctApplicationId->Find(array, avpCode);
				else
					return NULL;
			}
			case 1:
			{
				if(mUserName != NULL)
					return mUserName->Find(array, avpCode);
				else
					return NULL;
			}
			case 287:
			{
				if(mAccountingSubSessionId != NULL)
					return mAccountingSubSessionId->Find(array, avpCode);
				else
					return NULL;
			}
			case 44:
			{
				if(mAcctSessionId != NULL)
					return mAcctSessionId->Find(array, avpCode);
				else
					return NULL;
			}
			case 50:
			{
				if(mAcctMultiSessionId != NULL)
					return mAcctMultiSessionId->Find(array, avpCode);
				else
					return NULL;
			}
			case 281:
			{
				if(mErrorMessage != NULL)
					return mErrorMessage->Find(array, avpCode);
				else
					return NULL;
			}
			case 294:
			{
				if(mErrorReportingHost != NULL)
					return mErrorReportingHost->Find(array, avpCode);
				else
					return NULL;
			}
			case 85:
			{
				if(mAcctInterimInterval != NULL)
					return mAcctInterimInterval->Find(array, avpCode);
				else
					return NULL;
			}
			case 483:
			{
				if(mAccountingRealtimeRequired != NULL)
					return mAccountingRealtimeRequired->Find(array, avpCode);
				else
					return NULL;
			}
			case 55:
			{
				if(mEventTimestamp != NULL)
					return mEventTimestamp->Find(array, avpCode);
				else
					return NULL;
			}
			case 282:
			{
				if(mRouteRecordList != NULL && mRouteRecordList->size() > 0)
					return (mRouteRecordList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 416:
			{
				if(mCCRequestType != NULL)
					return mCCRequestType->Find(array, avpCode);
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


BOOLEAN AccountingResponse::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
		if(!mDecodeFlag && array != NULL)
			this->Decode(array);

		switch(avpCode)
		{
			case 263:
			{
				if(mSessionId != NULL)
				{
					DiameterBaseInterface* inf =  mSessionId->Find(this->mspByteArray.get(), avpCode);
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
			case 268:
			{
				if(mResultCode != NULL)
				{
					DiameterBaseInterface* inf =  mResultCode->Find(this->mspByteArray.get(), avpCode);
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
			case 264:
			{
				if(mOriginHost != NULL)
				{
					DiameterBaseInterface* inf =  mOriginHost->Find(this->mspByteArray.get(), avpCode);
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
			case 296:
			{
				if(mOriginRealm != NULL)
				{
					DiameterBaseInterface* inf =  mOriginRealm->Find(this->mspByteArray.get(), avpCode);
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
			case 278:
			{
				if(mOriginStateId != NULL)
				{
					DiameterBaseInterface* inf =  mOriginStateId->Find(this->mspByteArray.get(), avpCode);
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
			case 480:
			{
				if(mAccountingRecordType != NULL)
				{
					DiameterBaseInterface* inf =  mAccountingRecordType->Find(this->mspByteArray.get(), avpCode);
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
			case 485:
			{
				if(mAccountingRecordNumber != NULL)
				{
					DiameterBaseInterface* inf =  mAccountingRecordNumber->Find(this->mspByteArray.get(), avpCode);
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
			case 259:
			{
				if(mAcctApplicationId != NULL)
				{
					DiameterBaseInterface* inf =  mAcctApplicationId->Find(this->mspByteArray.get(), avpCode);
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
			case 260:
			{
				if(mVendorSpecificApplicationIdGrpList != NULL)
				{
					for(auto itr = mVendorSpecificApplicationIdGrpList->begin(); itr != mVendorSpecificApplicationIdGrpList->end(); ++itr)
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
			case 1:
			{
				if(mUserName != NULL)
				{
					DiameterBaseInterface* inf =  mUserName->Find(this->mspByteArray.get(), avpCode);
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
			case 287:
			{
				if(mAccountingSubSessionId != NULL)
				{
					DiameterBaseInterface* inf =  mAccountingSubSessionId->Find(this->mspByteArray.get(), avpCode);
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
			case 44:
			{
				if(mAcctSessionId != NULL)
				{
					DiameterBaseInterface* inf =  mAcctSessionId->Find(this->mspByteArray.get(), avpCode);
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
			case 50:
			{
				if(mAcctMultiSessionId != NULL)
				{
					DiameterBaseInterface* inf =  mAcctMultiSessionId->Find(this->mspByteArray.get(), avpCode);
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
			case 281:
			{
				if(mErrorMessage != NULL)
				{
					DiameterBaseInterface* inf =  mErrorMessage->Find(this->mspByteArray.get(), avpCode);
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
			case 294:
			{
				if(mErrorReportingHost != NULL)
				{
					DiameterBaseInterface* inf =  mErrorReportingHost->Find(this->mspByteArray.get(), avpCode);
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
			case 85:
			{
				if(mAcctInterimInterval != NULL)
				{
					DiameterBaseInterface* inf =  mAcctInterimInterval->Find(this->mspByteArray.get(), avpCode);
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
			case 483:
			{
				if(mAccountingRealtimeRequired != NULL)
				{
					DiameterBaseInterface* inf =  mAccountingRealtimeRequired->Find(this->mspByteArray.get(), avpCode);
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
			case 55:
			{
				if(mEventTimestamp != NULL)
				{
					DiameterBaseInterface* inf =  mEventTimestamp->Find(this->mspByteArray.get(), avpCode);
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
			case 284:
			{
				if(mProxyInfoGrpList != NULL)
				{
					for(auto itr = mProxyInfoGrpList->begin(); itr != mProxyInfoGrpList->end(); ++itr)
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
			case 282:
			{
				if(mRouteRecordList != NULL)
				{
					for(auto itr = mRouteRecordList->begin(); itr != mRouteRecordList->end(); ++itr)
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
			case 416:
			{
				if(mCCRequestType != NULL)
				{
					DiameterBaseInterface* inf =  mCCRequestType->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> AccountingResponse::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN AccountingResponse::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
		if(!mDecodeFlag && array != NULL)
			this->Decode(array);

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
			case 263:
			{
				if(mSessionId != NULL)
				{
					DiameterBaseInterface* inf =  mSessionId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 268:
			{
				if(mResultCode != NULL)
				{
					DiameterBaseInterface* inf =  mResultCode->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 264:
			{
				if(mOriginHost != NULL)
				{
					DiameterBaseInterface* inf =  mOriginHost->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 296:
			{
				if(mOriginRealm != NULL)
				{
					DiameterBaseInterface* inf =  mOriginRealm->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 278:
			{
				if(mOriginStateId != NULL)
				{
					DiameterBaseInterface* inf =  mOriginStateId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 480:
			{
				if(mAccountingRecordType != NULL)
				{
					DiameterBaseInterface* inf =  mAccountingRecordType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 485:
			{
				if(mAccountingRecordNumber != NULL)
				{
					DiameterBaseInterface* inf =  mAccountingRecordNumber->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 259:
			{
				if(mAcctApplicationId != NULL)
				{
					DiameterBaseInterface* inf =  mAcctApplicationId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 260:
			{
				if(mVendorSpecificApplicationIdGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mVendorSpecificApplicationIdGrpList->begin(); itr != mVendorSpecificApplicationIdGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mVendorSpecificApplicationIdGrpList->begin(); itr != mVendorSpecificApplicationIdGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 1:
			{
				if(mUserName != NULL)
				{
					DiameterBaseInterface* inf =  mUserName->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 287:
			{
				if(mAccountingSubSessionId != NULL)
				{
					DiameterBaseInterface* inf =  mAccountingSubSessionId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 44:
			{
				if(mAcctSessionId != NULL)
				{
					DiameterBaseInterface* inf =  mAcctSessionId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 50:
			{
				if(mAcctMultiSessionId != NULL)
				{
					DiameterBaseInterface* inf =  mAcctMultiSessionId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 281:
			{
				if(mErrorMessage != NULL)
				{
					DiameterBaseInterface* inf =  mErrorMessage->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 294:
			{
				if(mErrorReportingHost != NULL)
				{
					DiameterBaseInterface* inf =  mErrorReportingHost->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 85:
			{
				if(mAcctInterimInterval != NULL)
				{
					DiameterBaseInterface* inf =  mAcctInterimInterval->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 483:
			{
				if(mAccountingRealtimeRequired != NULL)
				{
					DiameterBaseInterface* inf =  mAccountingRealtimeRequired->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 55:
			{
				if(mEventTimestamp != NULL)
				{
					DiameterBaseInterface* inf =  mEventTimestamp->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 284:
			{
				if(mProxyInfoGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mProxyInfoGrpList->begin(); itr != mProxyInfoGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mProxyInfoGrpList->begin(); itr != mProxyInfoGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 282:
			{
				if(mRouteRecordList != NULL)
				{
					for(auto itr = mRouteRecordList->begin(); itr != mRouteRecordList->end(); ++itr)
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
			case 416:
			{
				if(mCCRequestType != NULL)
				{
					DiameterBaseInterface* inf =  mCCRequestType->Find(this->mspByteArray.get(), avpCode);
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




void AccountingResponse::Display(UINT32 tab)
{
	cout << setw(tab) << "" << "|" << setfill('=') << setw(59) << "|\n" << setfill(' '); 

	cout << setw(tab) << "" << "|"  << left <<  setw(12) << "Version" << ":" << setw(15) << (int)mDiameterMsgHeader->mVersion << "|" << setw(12)  << "MsgLen" << ":" << setw(15) << mDiameterMsgHeader->mMsgLen << "|" << "\n"; 
	TEXT lCmdFlg[100];
	sprintf( lCmdFlg, "%s %s %s %s", ((mDiameterMsgHeader->mCmdFlg.rBit==1)?"Request":"Response"), ((mDiameterMsgHeader->mCmdFlg.pBit==1)?"Proxiable":""), ((mDiameterMsgHeader->mCmdFlg.eBit==1)?"Error":""),((mDiameterMsgHeader->mCmdFlg.tBit ==1)?"Retransmitted":""));
	cout << setw(tab) << "" << "|"  << left <<  setw(12) << "CmdFlag" << ":" << setw(44) << lCmdFlg << "|\n"; 
	cout << setw(tab) << "" <<"|"  << left <<  setw(12) << "CmdCode" << ":" << setw(15) << mDiameterMsgHeader->mCmdCode << "|" << setw(12)  << "ApplnId" << ":" << setw(15) << mDiameterMsgHeader->mApplId << "|\n";
	cout << setw(tab) << "" << "|"  << left <<  setw(12) << "HopByHopId" << ":" << setw(15) << mDiameterMsgHeader->mHopByHopId << "|" << setw(12)  << "EndToEndId" << ":" << setw(15) << mDiameterMsgHeader->mEndToEndId << "|\n";
	cout << setw(tab) << "" << "|" << right << setfill('=') << setw(59) << "|\n" << setfill(' '); 

	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case AccountingResponse_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case AccountingResponse_RESULTCODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "268" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ResultCode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getResultCode()->Display(tab+1);
			}
				break;
			case AccountingResponse_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case AccountingResponse_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case AccountingResponse_ORIGINSTATEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "278" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginStateId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginStateId()->Display(tab+1);
			}
				break;
			case AccountingResponse_ACCOUNTINGRECORDTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "480" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AccountingRecordType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getAccountingRecordType()->Display(tab+1);
			}
				break;
			case AccountingResponse_ACCOUNTINGRECORDNUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "485" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AccountingRecordNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getAccountingRecordNumber()->Display(tab+1);
			}
				break;
			case AccountingResponse_ACCTAPPLICATIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "259" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AcctApplicationId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getAcctApplicationId()->Display(tab+1);
			}
				break;
			case AccountingResponse_VENDORSPECIFICAPPLICATIONID:
			{
				if( mVendorSpecificApplicationIdGrpList->size() <= 0) {
					break;
				}

				mVendorSpecificApplicationIdGrpIterator = this->getVendorSpecificApplicationIdGrpList()->begin();
				while(mVendorSpecificApplicationIdGrpIterator != this->getVendorSpecificApplicationIdGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "260" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "VendorSpecificApplicationId" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mVendorSpecificApplicationIdGrpIterator)->Display(tab+1);
					mVendorSpecificApplicationIdGrpIterator++;

				};

			}
				break;
			case AccountingResponse_USERNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getUserName()->Display(tab+1);
			}
				break;
			case AccountingResponse_ACCOUNTINGSUBSESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "287" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AccountingSubSessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getAccountingSubSessionId()->Display(tab+1);
			}
				break;
			case AccountingResponse_ACCTSESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "44" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AcctSessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getAcctSessionId()->Display(tab+1);
			}
				break;
			case AccountingResponse_ACCTMULTISESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "50" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AcctMultiSessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getAcctMultiSessionId()->Display(tab+1);
			}
				break;
			case AccountingResponse_ERRORMESSAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "281" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ErrorMessage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getErrorMessage()->Display(tab+1);
			}
				break;
			case AccountingResponse_ERRORREPORTINGHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "294" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ErrorReportingHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getErrorReportingHost()->Display(tab+1);
			}
				break;
			case AccountingResponse_ACCTINTERIMINTERVAL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "85" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AcctInterimInterval" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getAcctInterimInterval()->Display(tab+1);
			}
				break;
			case AccountingResponse_ACCOUNTINGREALTIMEREQUIRED:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "483" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AccountingRealtimeRequired" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getAccountingRealtimeRequired()->Display(tab+1);
			}
				break;
			case AccountingResponse_EVENTTIMESTAMP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "55" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "EventTimestamp" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getEventTimestamp()->Display(tab+1);
			}
				break;
			case AccountingResponse_PROXYINFO:
			{
				if( mProxyInfoGrpList->size() <= 0) {
					break;
				}

				mProxyInfoGrpIterator = this->getProxyInfoGrpList()->begin();
				while(mProxyInfoGrpIterator != this->getProxyInfoGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "284" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ProxyInfo" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mProxyInfoGrpIterator)->Display(tab+1);
					mProxyInfoGrpIterator++;

				};

			}
				break;
			case AccountingResponse_ROUTERECORD:
			{
				if( mRouteRecordList->size() <= 0) {
					break;
				}

				mRouteRecordIterator = this->getRouteRecordList()->begin();
				while(mRouteRecordIterator != this->getRouteRecordList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "282" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RouteRecord" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mRouteRecordIterator)->Display(tab+1);
					mRouteRecordIterator++;

				};

			}
				break;
			case AccountingResponse_CCREQUESTTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "416" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCRequestType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getCCRequestType()->Display(tab+1);
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


BOOLEAN AccountingResponse::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<21> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case AccountingResponse_SESSIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 263");
				}
				else
					sprintf(lMissingAvpInfo, "%s,263", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_RESULTCODE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 268");
				}
				else
					sprintf(lMissingAvpInfo, "%s,268", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ORIGINHOST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 264");
				}
				else
					sprintf(lMissingAvpInfo, "%s,264", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ORIGINREALM:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 296");
				}
				else
					sprintf(lMissingAvpInfo, "%s,296", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ORIGINSTATEID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 278");
				}
				else
					sprintf(lMissingAvpInfo, "%s,278", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ACCOUNTINGRECORDTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 480");
				}
				else
					sprintf(lMissingAvpInfo, "%s,480", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ACCOUNTINGRECORDNUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 485");
				}
				else
					sprintf(lMissingAvpInfo, "%s,485", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ACCTAPPLICATIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 259");
				}
				else
					sprintf(lMissingAvpInfo, "%s,259", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_VENDORSPECIFICAPPLICATIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 260");
				}
				else
					sprintf(lMissingAvpInfo, "%s,260", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_USERNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ACCOUNTINGSUBSESSIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 287");
				}
				else
					sprintf(lMissingAvpInfo, "%s,287", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ACCTSESSIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 44");
				}
				else
					sprintf(lMissingAvpInfo, "%s,44", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ACCTMULTISESSIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 50");
				}
				else
					sprintf(lMissingAvpInfo, "%s,50", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ERRORMESSAGE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 281");
				}
				else
					sprintf(lMissingAvpInfo, "%s,281", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ERRORREPORTINGHOST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 294");
				}
				else
					sprintf(lMissingAvpInfo, "%s,294", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ACCTINTERIMINTERVAL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 85");
				}
				else
					sprintf(lMissingAvpInfo, "%s,85", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ACCOUNTINGREALTIMEREQUIRED:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 483");
				}
				else
					sprintf(lMissingAvpInfo, "%s,483", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_EVENTTIMESTAMP:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 55");
				}
				else
					sprintf(lMissingAvpInfo, "%s,55", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_PROXYINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 284");
				}
				else
					sprintf(lMissingAvpInfo, "%s,284", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_ROUTERECORD:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 282");
				}
				else
					sprintf(lMissingAvpInfo, "%s,282", lMissingAvpInfo);
			}
				break;
			case AccountingResponse_CCREQUESTTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 416");
				}
				else
					sprintf(lMissingAvpInfo, "%s,416", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
