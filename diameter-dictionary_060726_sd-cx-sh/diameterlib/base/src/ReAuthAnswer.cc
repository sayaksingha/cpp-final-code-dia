#include "base/include/ReAuthAnswer.h"

using namespace BASE;
BOOLEAN ReAuthAnswer::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ReAuthAnswer::ReAuthAnswer()
{
	mSessionId = NULL;
	mResultCode = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mUserName = NULL;
	mOriginStateId = NULL;
	mErrorMessage = NULL;
	mErrorReportingHost = NULL;
	mRedirectHost = NULL;
	mRedirectHostUsage = NULL;
	mRedirectMaxCacheTime = NULL;
	mProxyInfoGrpList = NULL;
	mCCRequestType = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<13>(string("1111100111111"));
	mMandatoryAvpSetVal.reset();
}

ReAuthAnswer::~ReAuthAnswer()
{
	if(mSessionId != NULL)
		delete mSessionId;
	if(mResultCode != NULL)
		delete mResultCode;
	if(mOriginHost != NULL)
		delete mOriginHost;
	if(mOriginRealm != NULL)
		delete mOriginRealm;
	if(mUserName != NULL)
		delete mUserName;
	if(mOriginStateId != NULL)
		delete mOriginStateId;
	if(mErrorMessage != NULL)
		delete mErrorMessage;
	if(mErrorReportingHost != NULL)
		delete mErrorReportingHost;
	if(mRedirectHost != NULL)
		delete mRedirectHost;
	if(mRedirectHostUsage != NULL)
		delete mRedirectHostUsage;
	if(mRedirectMaxCacheTime != NULL)
		delete mRedirectMaxCacheTime;
	if(mProxyInfoGrpList != NULL){
		mProxyInfoGrpIterator = mProxyInfoGrpList->begin();
		while(mProxyInfoGrpIterator != mProxyInfoGrpList->end()){
	if(*mProxyInfoGrpIterator != NULL)
			delete (*mProxyInfoGrpIterator);
			mProxyInfoGrpIterator++;
		}
		delete mProxyInfoGrpList;
	}
	if(mCCRequestType != NULL)
		delete mCCRequestType;
}

OctetString* ReAuthAnswer::setSessionId(){
	mMandatoryAvpSetVal [ReAuthAnswer_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[ReAuthAnswer_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void ReAuthAnswer::resetSessionId(){
	mTagsPresent[ReAuthAnswer_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

Unsigned32* ReAuthAnswer::setResultCode(){
	mMandatoryAvpSetVal [ReAuthAnswer_RESULTCODE] = 1;
	if(mResultCode == NULL)
	{
		mResultCode = new Unsigned32();
		mTagsPresent[ReAuthAnswer_RESULTCODE] = 1;
		return mResultCode;
	}
	return mResultCode;
}

void ReAuthAnswer::resetResultCode(){
	mTagsPresent[ReAuthAnswer_RESULTCODE] = 0;
	if(mResultCode != NULL)
	{
		delete mResultCode; 
		mResultCode = NULL;
	}
}

OctetString* ReAuthAnswer::setOriginHost(){
	mMandatoryAvpSetVal [ReAuthAnswer_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[ReAuthAnswer_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void ReAuthAnswer::resetOriginHost(){
	mTagsPresent[ReAuthAnswer_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* ReAuthAnswer::setOriginRealm(){
	mMandatoryAvpSetVal [ReAuthAnswer_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[ReAuthAnswer_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void ReAuthAnswer::resetOriginRealm(){
	mTagsPresent[ReAuthAnswer_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

OctetString* ReAuthAnswer::setUserName(){
	mMandatoryAvpSetVal [ReAuthAnswer_USERNAME] = 1;
	if(mUserName == NULL)
	{
		mUserName = new OctetString();
		mTagsPresent[ReAuthAnswer_USERNAME] = 1;
		return mUserName;
	}
	return mUserName;
}

void ReAuthAnswer::resetUserName(){
	mTagsPresent[ReAuthAnswer_USERNAME] = 0;
	if(mUserName != NULL)
	{
		delete mUserName; 
		mUserName = NULL;
	}
}

Unsigned32* ReAuthAnswer::setOriginStateId(){
	mMandatoryAvpSetVal [ReAuthAnswer_ORIGINSTATEID] = 1;
	if(mOriginStateId == NULL)
	{
		mOriginStateId = new Unsigned32();
		mTagsPresent[ReAuthAnswer_ORIGINSTATEID] = 1;
		return mOriginStateId;
	}
	return mOriginStateId;
}

void ReAuthAnswer::resetOriginStateId(){
	mTagsPresent[ReAuthAnswer_ORIGINSTATEID] = 0;
	if(mOriginStateId != NULL)
	{
		delete mOriginStateId; 
		mOriginStateId = NULL;
	}
}

OctetString* ReAuthAnswer::setErrorMessage(){
	if(mErrorMessage == NULL)
	{
		mErrorMessage = new OctetString();
		mTagsPresent[ReAuthAnswer_ERRORMESSAGE] = 1;
		return mErrorMessage;
	}
	return mErrorMessage;
}

void ReAuthAnswer::resetErrorMessage(){
	mTagsPresent[ReAuthAnswer_ERRORMESSAGE] = 0;
	if(mErrorMessage != NULL)
	{
		delete mErrorMessage; 
		mErrorMessage = NULL;
	}
}

OctetString* ReAuthAnswer::setErrorReportingHost(){
	if(mErrorReportingHost == NULL)
	{
		mErrorReportingHost = new OctetString();
		mTagsPresent[ReAuthAnswer_ERRORREPORTINGHOST] = 1;
		return mErrorReportingHost;
	}
	return mErrorReportingHost;
}

void ReAuthAnswer::resetErrorReportingHost(){
	mTagsPresent[ReAuthAnswer_ERRORREPORTINGHOST] = 0;
	if(mErrorReportingHost != NULL)
	{
		delete mErrorReportingHost; 
		mErrorReportingHost = NULL;
	}
}

OctetString* ReAuthAnswer::setRedirectHost(){
	mMandatoryAvpSetVal [ReAuthAnswer_REDIRECTHOST] = 1;
	if(mRedirectHost == NULL)
	{
		mRedirectHost = new OctetString();
		mTagsPresent[ReAuthAnswer_REDIRECTHOST] = 1;
		return mRedirectHost;
	}
	return mRedirectHost;
}

void ReAuthAnswer::resetRedirectHost(){
	mTagsPresent[ReAuthAnswer_REDIRECTHOST] = 0;
	if(mRedirectHost != NULL)
	{
		delete mRedirectHost; 
		mRedirectHost = NULL;
	}
}

RedirectHostUsage* ReAuthAnswer::setRedirectHostUsage(){
	mMandatoryAvpSetVal [ReAuthAnswer_REDIRECTHOSTUSAGE] = 1;
	if(mRedirectHostUsage == NULL)
	{
		mRedirectHostUsage = new RedirectHostUsage();
		mTagsPresent[ReAuthAnswer_REDIRECTHOSTUSAGE] = 1;
		return mRedirectHostUsage;
	}
	return mRedirectHostUsage;
}

void ReAuthAnswer::resetRedirectHostUsage(){
	mTagsPresent[ReAuthAnswer_REDIRECTHOSTUSAGE] = 0;
	if(mRedirectHostUsage != NULL)
	{
		delete mRedirectHostUsage; 
		mRedirectHostUsage = NULL;
	}
}

Unsigned32* ReAuthAnswer::setRedirectMaxCacheTime(){
	mMandatoryAvpSetVal [ReAuthAnswer_REDIRECTMAXCACHETIME] = 1;
	if(mRedirectMaxCacheTime == NULL)
	{
		mRedirectMaxCacheTime = new Unsigned32();
		mTagsPresent[ReAuthAnswer_REDIRECTMAXCACHETIME] = 1;
		return mRedirectMaxCacheTime;
	}
	return mRedirectMaxCacheTime;
}

void ReAuthAnswer::resetRedirectMaxCacheTime(){
	mTagsPresent[ReAuthAnswer_REDIRECTMAXCACHETIME] = 0;
	if(mRedirectMaxCacheTime != NULL)
	{
		delete mRedirectMaxCacheTime; 
		mRedirectMaxCacheTime = NULL;
	}
}

CCRequestType* ReAuthAnswer::setCCRequestType(){
	mMandatoryAvpSetVal [ReAuthAnswer_CCREQUESTTYPE] = 1;
	if(mCCRequestType == NULL)
	{
		mCCRequestType = new CCRequestType();
		mTagsPresent[ReAuthAnswer_CCREQUESTTYPE] = 1;
		return mCCRequestType;
	}
	return mCCRequestType;
}

void ReAuthAnswer::resetCCRequestType(){
	mTagsPresent[ReAuthAnswer_CCREQUESTTYPE] = 0;
	if(mCCRequestType != NULL)
	{
		delete mCCRequestType; 
		mCCRequestType = NULL;
	}
}

OctetString* ReAuthAnswer::getSessionId(){
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

Unsigned32* ReAuthAnswer::getResultCode(){
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

OctetString* ReAuthAnswer::getOriginHost(){
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

OctetString* ReAuthAnswer::getOriginRealm(){
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

OctetString* ReAuthAnswer::getUserName(){
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

Unsigned32* ReAuthAnswer::getOriginStateId(){
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

OctetString* ReAuthAnswer::getErrorMessage(){
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

OctetString* ReAuthAnswer::getErrorReportingHost(){
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

OctetString* ReAuthAnswer::getRedirectHost(){
	if(NULL == mRedirectHost) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectHost is Null");
		throw lTssDiaMsgException;
	}
	if(!mRedirectHost->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRedirectHost->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectHost is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRedirectHost->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRedirectHost->Decode(mspByteArray.get(), mRedirectHost->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectHost")     ;
			throw lTssDiaMsgException;
		}
		mRedirectHost->mAvpDecodedFlag = true;
	}
	return mRedirectHost;
}

RedirectHostUsage* ReAuthAnswer::getRedirectHostUsage(){
	if(NULL == mRedirectHostUsage) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectHostUsage is Null");
		throw lTssDiaMsgException;
	}
	if(!mRedirectHostUsage->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRedirectHostUsage->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectHostUsage is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRedirectHostUsage->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRedirectHostUsage->Decode(mspByteArray.get(), mRedirectHostUsage->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectHostUsage")     ;
			throw lTssDiaMsgException;
		}
		mRedirectHostUsage->mAvpDecodedFlag = true;
	}
	return mRedirectHostUsage;
}

Unsigned32* ReAuthAnswer::getRedirectMaxCacheTime(){
	if(NULL == mRedirectMaxCacheTime) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectMaxCacheTime is Null");
		throw lTssDiaMsgException;
	}
	if(!mRedirectMaxCacheTime->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRedirectMaxCacheTime->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectMaxCacheTime is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRedirectMaxCacheTime->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRedirectMaxCacheTime->Decode(mspByteArray.get(), mRedirectMaxCacheTime->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectMaxCacheTime")     ;
			throw lTssDiaMsgException;
		}
		mRedirectMaxCacheTime->mAvpDecodedFlag = true;
	}
	return mRedirectMaxCacheTime;
}

list<ProxyInfo*>* ReAuthAnswer::getProxyInfoGrpList()
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
			mTagsPresent[ReAuthAnswer_PROXYINFO] = 0;
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

list<ProxyInfo*>* ReAuthAnswer::setProxyInfoGrpList(){
	mTagsPresent[ReAuthAnswer_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<ProxyInfo*>;
	mMandatoryAvpSetVal[ReAuthAnswer_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void ReAuthAnswer::resetProxyInfoGrpList(){
	mTagsPresent[ReAuthAnswer_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

CCRequestType* ReAuthAnswer::getCCRequestType(){
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



int ReAuthAnswer::Encode(byteArray *array)
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
	array->byte[array->offset++] = (258>>16) & 0xFF;
	array->byte[array->offset++] = (258>>8) & 0xFF;
	array->byte[array->offset++] = (258) & 0xFF;
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
			case ReAuthAnswer_SESSIONID:
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
			case ReAuthAnswer_RESULTCODE:
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
			case ReAuthAnswer_ORIGINHOST:
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
						INT32 venderId=0;
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
			case ReAuthAnswer_ORIGINREALM:
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
						INT32 venderId=0;
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
			case ReAuthAnswer_USERNAME:
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
			case ReAuthAnswer_ORIGINSTATEID:
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
			case ReAuthAnswer_ERRORMESSAGE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(281);
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
			case ReAuthAnswer_ERRORREPORTINGHOST:
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
			case ReAuthAnswer_REDIRECTHOST:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(292);
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
					if(!mRedirectHost->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRedirectHost->getAvpOffsetLen().first], mRedirectHost->getAvpOffsetLen().second);
						array->offset += mRedirectHost->getAvpOffsetLen().second;
						array->size += mRedirectHost->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRedirectHost->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRedirectHost->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectHost");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRedirectHost->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRedirectHost->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectHost");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthAnswer_REDIRECTHOSTUSAGE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(261);
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
					if(!mRedirectHostUsage->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRedirectHostUsage->getAvpOffsetLen().first], mRedirectHostUsage->getAvpOffsetLen().second);
						array->offset += mRedirectHostUsage->getAvpOffsetLen().second;
						array->size += mRedirectHostUsage->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectHostUsage");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRedirectHostUsage->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectHostUsage");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthAnswer_REDIRECTMAXCACHETIME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(262);
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
					if(!mRedirectMaxCacheTime->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRedirectMaxCacheTime->getAvpOffsetLen().first], mRedirectMaxCacheTime->getAvpOffsetLen().second);
						array->offset += mRedirectMaxCacheTime->getAvpOffsetLen().second;
						array->size += mRedirectMaxCacheTime->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectMaxCacheTime");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRedirectMaxCacheTime->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectMaxCacheTime");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ReAuthAnswer_PROXYINFO:
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
			case ReAuthAnswer_CCREQUESTTYPE:
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


int ReAuthAnswer::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [ReAuthAnswer_SESSIONID] = 1;
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
						mMandatoryAvpSetVal [ReAuthAnswer_RESULTCODE] = 1;
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
						mMandatoryAvpSetVal [ReAuthAnswer_ORIGINHOST] = 1;
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
						mMandatoryAvpSetVal [ReAuthAnswer_ORIGINREALM] = 1;
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
			case 1:
				{
						mMandatoryAvpSetVal [ReAuthAnswer_USERNAME] = 1;
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
			case 278:
				{
						mMandatoryAvpSetVal [ReAuthAnswer_ORIGINSTATEID] = 1;
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
			case 292:
				{
						mMandatoryAvpSetVal [ReAuthAnswer_REDIRECTHOST] = 1;
					if( NULL == this->setRedirectHost())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectHost");
						throw lTssDiaMsgException;
					}
					mRedirectHost->setAvpCode(292);
					mRedirectHost->setAvpVendorId(lVenderId);
					mRedirectHost->SetDataType((DiameterDataType)5);
					mRedirectHost->mspByteArray = mspByteArray;
					mRedirectHost->mAvpDecodedFlag = false;
					mRedirectHost->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 261:
				{
						mMandatoryAvpSetVal [ReAuthAnswer_REDIRECTHOSTUSAGE] = 1;
					if( NULL == this->setRedirectHostUsage())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectHostUsage");
						throw lTssDiaMsgException;
					}
					mRedirectHostUsage->setAvpCode(261);
					mRedirectHostUsage->setAvpVendorId(lVenderId);
					mRedirectHostUsage->SetDataType((DiameterDataType)7);
					mRedirectHostUsage->mspByteArray = mspByteArray;
					mRedirectHostUsage->mAvpDecodedFlag = false;
					mRedirectHostUsage->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 262:
				{
						mMandatoryAvpSetVal [ReAuthAnswer_REDIRECTMAXCACHETIME] = 1;
					if( NULL == this->setRedirectMaxCacheTime())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectMaxCacheTime");
						throw lTssDiaMsgException;
					}
					mRedirectMaxCacheTime->setAvpCode(262);
					mRedirectMaxCacheTime->setAvpVendorId(lVenderId);
					mRedirectMaxCacheTime->SetDataType((DiameterDataType)3);
					mRedirectMaxCacheTime->mspByteArray = mspByteArray;
					mRedirectMaxCacheTime->mAvpDecodedFlag = false;
					mRedirectMaxCacheTime->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 284:
				{
						mMandatoryAvpSetVal [ReAuthAnswer_PROXYINFO] = 1;
					mTagsPresent[ReAuthAnswer_PROXYINFO] = 1;
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
			case 416:
				{
						mMandatoryAvpSetVal [ReAuthAnswer_CCREQUESTTYPE] = 1;
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


DiameterBaseInterface* ReAuthAnswer::Find(byteArray *array, UINT32 avpCode)
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
			case 1:
			{
				if(mUserName != NULL)
					return mUserName->Find(array, avpCode);
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
			case 292:
			{
				if(mRedirectHost != NULL)
					return mRedirectHost->Find(array, avpCode);
				else
					return NULL;
			}
			case 261:
			{
				if(mRedirectHostUsage != NULL)
					return mRedirectHostUsage->Find(array, avpCode);
				else
					return NULL;
			}
			case 262:
			{
				if(mRedirectMaxCacheTime != NULL)
					return mRedirectMaxCacheTime->Find(array, avpCode);
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


BOOLEAN ReAuthAnswer::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 292:
			{
				if(mRedirectHost != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectHost->Find(this->mspByteArray.get(), avpCode);
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
			case 261:
			{
				if(mRedirectHostUsage != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectHostUsage->Find(this->mspByteArray.get(), avpCode);
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
			case 262:
			{
				if(mRedirectMaxCacheTime != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectMaxCacheTime->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> ReAuthAnswer::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ReAuthAnswer::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 292:
			{
				if(mRedirectHost != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectHost->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 261:
			{
				if(mRedirectHostUsage != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectHostUsage->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 262:
			{
				if(mRedirectMaxCacheTime != NULL)
				{
					DiameterBaseInterface* inf =  mRedirectMaxCacheTime->Find(this->mspByteArray.get(), avpCode);
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




void ReAuthAnswer::Display(UINT32 tab)
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
			case ReAuthAnswer_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case ReAuthAnswer_RESULTCODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "268" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ResultCode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getResultCode()->Display(tab+1);
			}
				break;
			case ReAuthAnswer_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case ReAuthAnswer_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case ReAuthAnswer_USERNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getUserName()->Display(tab+1);
			}
				break;
			case ReAuthAnswer_ORIGINSTATEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "278" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginStateId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginStateId()->Display(tab+1);
			}
				break;
			case ReAuthAnswer_ERRORMESSAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "281" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ErrorMessage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getErrorMessage()->Display(tab+1);
			}
				break;
			case ReAuthAnswer_ERRORREPORTINGHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "294" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ErrorReportingHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getErrorReportingHost()->Display(tab+1);
			}
				break;
			case ReAuthAnswer_REDIRECTHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "292" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getRedirectHost()->Display(tab+1);
			}
				break;
			case ReAuthAnswer_REDIRECTHOSTUSAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "261" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectHostUsage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getRedirectHostUsage()->Display(tab+1);
			}
				break;
			case ReAuthAnswer_REDIRECTMAXCACHETIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "262" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectMaxCacheTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getRedirectMaxCacheTime()->Display(tab+1);
			}
				break;
			case ReAuthAnswer_PROXYINFO:
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
			case ReAuthAnswer_CCREQUESTTYPE:
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


BOOLEAN ReAuthAnswer::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<13> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ReAuthAnswer_SESSIONID:
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
			case ReAuthAnswer_RESULTCODE:
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
			case ReAuthAnswer_ORIGINHOST:
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
			case ReAuthAnswer_ORIGINREALM:
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
			case ReAuthAnswer_USERNAME:
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
			case ReAuthAnswer_ORIGINSTATEID:
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
			case ReAuthAnswer_ERRORMESSAGE:
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
			case ReAuthAnswer_ERRORREPORTINGHOST:
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
			case ReAuthAnswer_REDIRECTHOST:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 292");
				}
				else
					sprintf(lMissingAvpInfo, "%s,292", lMissingAvpInfo);
			}
				break;
			case ReAuthAnswer_REDIRECTHOSTUSAGE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 261");
				}
				else
					sprintf(lMissingAvpInfo, "%s,261", lMissingAvpInfo);
			}
				break;
			case ReAuthAnswer_REDIRECTMAXCACHETIME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 262");
				}
				else
					sprintf(lMissingAvpInfo, "%s,262", lMissingAvpInfo);
			}
				break;
			case ReAuthAnswer_PROXYINFO:
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
			case ReAuthAnswer_CCREQUESTTYPE:
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
