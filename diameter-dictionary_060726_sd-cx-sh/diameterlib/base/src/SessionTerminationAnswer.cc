#include "base/include/SessionTerminationAnswer.h"

using namespace BASE;
BOOLEAN SessionTerminationAnswer::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

SessionTerminationAnswer::SessionTerminationAnswer()
{
	mSessionId = NULL;
	mResultCode = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mUserName = NULL;
	mClassList = NULL;
	mOriginStateId = NULL;
	mErrorMessage = NULL;
	mErrorReportingHost = NULL;
	mRedirectHostList = NULL;
	mRedirectHostUsage = NULL;
	mRedirectMaxCacheTime = NULL;
	mProxyInfoGrpList = NULL;
	mCCRequestType = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<14>(string("11111001111111"));
	mMandatoryAvpSetVal.reset();
}

SessionTerminationAnswer::~SessionTerminationAnswer()
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
	if(mClassList != NULL){
		mClassIterator = mClassList->begin();
		while(mClassIterator != mClassList->end()){
			delete (*mClassIterator);
			mClassIterator++;
		}
		delete mClassList;
	}
	if(mOriginStateId != NULL)
		delete mOriginStateId;
	if(mErrorMessage != NULL)
		delete mErrorMessage;
	if(mErrorReportingHost != NULL)
		delete mErrorReportingHost;
	if(mRedirectHostList != NULL){
		mRedirectHostIterator = mRedirectHostList->begin();
		while(mRedirectHostIterator != mRedirectHostList->end()){
			delete (*mRedirectHostIterator);
			mRedirectHostIterator++;
		}
		delete mRedirectHostList;
	}
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

OctetString* SessionTerminationAnswer::setSessionId(){
	mMandatoryAvpSetVal [SessionTerminationAnswer_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[SessionTerminationAnswer_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void SessionTerminationAnswer::resetSessionId(){
	mTagsPresent[SessionTerminationAnswer_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

Unsigned32* SessionTerminationAnswer::setResultCode(){
	mMandatoryAvpSetVal [SessionTerminationAnswer_RESULTCODE] = 1;
	if(mResultCode == NULL)
	{
		mResultCode = new Unsigned32();
		mTagsPresent[SessionTerminationAnswer_RESULTCODE] = 1;
		return mResultCode;
	}
	return mResultCode;
}

void SessionTerminationAnswer::resetResultCode(){
	mTagsPresent[SessionTerminationAnswer_RESULTCODE] = 0;
	if(mResultCode != NULL)
	{
		delete mResultCode; 
		mResultCode = NULL;
	}
}

OctetString* SessionTerminationAnswer::setOriginHost(){
	mMandatoryAvpSetVal [SessionTerminationAnswer_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[SessionTerminationAnswer_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void SessionTerminationAnswer::resetOriginHost(){
	mTagsPresent[SessionTerminationAnswer_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* SessionTerminationAnswer::setOriginRealm(){
	mMandatoryAvpSetVal [SessionTerminationAnswer_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[SessionTerminationAnswer_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void SessionTerminationAnswer::resetOriginRealm(){
	mTagsPresent[SessionTerminationAnswer_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

OctetString* SessionTerminationAnswer::setUserName(){
	mMandatoryAvpSetVal [SessionTerminationAnswer_USERNAME] = 1;
	if(mUserName == NULL)
	{
		mUserName = new OctetString();
		mTagsPresent[SessionTerminationAnswer_USERNAME] = 1;
		return mUserName;
	}
	return mUserName;
}

void SessionTerminationAnswer::resetUserName(){
	mTagsPresent[SessionTerminationAnswer_USERNAME] = 0;
	if(mUserName != NULL)
	{
		delete mUserName; 
		mUserName = NULL;
	}
}

Unsigned32* SessionTerminationAnswer::setOriginStateId(){
	mMandatoryAvpSetVal [SessionTerminationAnswer_ORIGINSTATEID] = 1;
	if(mOriginStateId == NULL)
	{
		mOriginStateId = new Unsigned32();
		mTagsPresent[SessionTerminationAnswer_ORIGINSTATEID] = 1;
		return mOriginStateId;
	}
	return mOriginStateId;
}

void SessionTerminationAnswer::resetOriginStateId(){
	mTagsPresent[SessionTerminationAnswer_ORIGINSTATEID] = 0;
	if(mOriginStateId != NULL)
	{
		delete mOriginStateId; 
		mOriginStateId = NULL;
	}
}

OctetString* SessionTerminationAnswer::setErrorMessage(){
	if(mErrorMessage == NULL)
	{
		mErrorMessage = new OctetString();
		mTagsPresent[SessionTerminationAnswer_ERRORMESSAGE] = 1;
		return mErrorMessage;
	}
	return mErrorMessage;
}

void SessionTerminationAnswer::resetErrorMessage(){
	mTagsPresent[SessionTerminationAnswer_ERRORMESSAGE] = 0;
	if(mErrorMessage != NULL)
	{
		delete mErrorMessage; 
		mErrorMessage = NULL;
	}
}

OctetString* SessionTerminationAnswer::setErrorReportingHost(){
	if(mErrorReportingHost == NULL)
	{
		mErrorReportingHost = new OctetString();
		mTagsPresent[SessionTerminationAnswer_ERRORREPORTINGHOST] = 1;
		return mErrorReportingHost;
	}
	return mErrorReportingHost;
}

void SessionTerminationAnswer::resetErrorReportingHost(){
	mTagsPresent[SessionTerminationAnswer_ERRORREPORTINGHOST] = 0;
	if(mErrorReportingHost != NULL)
	{
		delete mErrorReportingHost; 
		mErrorReportingHost = NULL;
	}
}

RedirectHostUsage* SessionTerminationAnswer::setRedirectHostUsage(){
	mMandatoryAvpSetVal [SessionTerminationAnswer_REDIRECTHOSTUSAGE] = 1;
	if(mRedirectHostUsage == NULL)
	{
		mRedirectHostUsage = new RedirectHostUsage();
		mTagsPresent[SessionTerminationAnswer_REDIRECTHOSTUSAGE] = 1;
		return mRedirectHostUsage;
	}
	return mRedirectHostUsage;
}

void SessionTerminationAnswer::resetRedirectHostUsage(){
	mTagsPresent[SessionTerminationAnswer_REDIRECTHOSTUSAGE] = 0;
	if(mRedirectHostUsage != NULL)
	{
		delete mRedirectHostUsage; 
		mRedirectHostUsage = NULL;
	}
}

Unsigned32* SessionTerminationAnswer::setRedirectMaxCacheTime(){
	mMandatoryAvpSetVal [SessionTerminationAnswer_REDIRECTMAXCACHETIME] = 1;
	if(mRedirectMaxCacheTime == NULL)
	{
		mRedirectMaxCacheTime = new Unsigned32();
		mTagsPresent[SessionTerminationAnswer_REDIRECTMAXCACHETIME] = 1;
		return mRedirectMaxCacheTime;
	}
	return mRedirectMaxCacheTime;
}

void SessionTerminationAnswer::resetRedirectMaxCacheTime(){
	mTagsPresent[SessionTerminationAnswer_REDIRECTMAXCACHETIME] = 0;
	if(mRedirectMaxCacheTime != NULL)
	{
		delete mRedirectMaxCacheTime; 
		mRedirectMaxCacheTime = NULL;
	}
}

CCRequestType* SessionTerminationAnswer::setCCRequestType(){
	mMandatoryAvpSetVal [SessionTerminationAnswer_CCREQUESTTYPE] = 1;
	if(mCCRequestType == NULL)
	{
		mCCRequestType = new CCRequestType();
		mTagsPresent[SessionTerminationAnswer_CCREQUESTTYPE] = 1;
		return mCCRequestType;
	}
	return mCCRequestType;
}

void SessionTerminationAnswer::resetCCRequestType(){
	mTagsPresent[SessionTerminationAnswer_CCREQUESTTYPE] = 0;
	if(mCCRequestType != NULL)
	{
		delete mCCRequestType; 
		mCCRequestType = NULL;
	}
}

OctetString* SessionTerminationAnswer::getSessionId(){
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

Unsigned32* SessionTerminationAnswer::getResultCode(){
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

OctetString* SessionTerminationAnswer::getOriginHost(){
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

OctetString* SessionTerminationAnswer::getOriginRealm(){
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

OctetString* SessionTerminationAnswer::getUserName(){
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

list<OctetString*>* SessionTerminationAnswer::getClassList()
{
	if(mClassList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Class is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mClassList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Class is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Class")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mClassList;
}

list<OctetString*>* SessionTerminationAnswer::setClassList() {
	mTagsPresent[SessionTerminationAnswer_CLASS] = 1;
	if(mClassList == NULL)
		mClassList = new list<OctetString*>;
	mMandatoryAvpSetVal [SessionTerminationAnswer_CLASS] = 1;
	mClassList->clear();
	return mClassList;
}

void SessionTerminationAnswer::resetClassList(){
	mTagsPresent[SessionTerminationAnswer_CLASS] = 0;
	if(mClassList != NULL)
		delete mClassList;
}

Unsigned32* SessionTerminationAnswer::getOriginStateId(){
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

OctetString* SessionTerminationAnswer::getErrorMessage(){
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

OctetString* SessionTerminationAnswer::getErrorReportingHost(){
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

list<OctetString*>* SessionTerminationAnswer::getRedirectHostList()
{
	if(mRedirectHostList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectHost is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mRedirectHostList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectHost is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectHost")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mRedirectHostList;
}

list<OctetString*>* SessionTerminationAnswer::setRedirectHostList() {
	mTagsPresent[SessionTerminationAnswer_REDIRECTHOST] = 1;
	if(mRedirectHostList == NULL)
		mRedirectHostList = new list<OctetString*>;
	mMandatoryAvpSetVal [SessionTerminationAnswer_REDIRECTHOST] = 1;
	mRedirectHostList->clear();
	return mRedirectHostList;
}

void SessionTerminationAnswer::resetRedirectHostList(){
	mTagsPresent[SessionTerminationAnswer_REDIRECTHOST] = 0;
	if(mRedirectHostList != NULL)
		delete mRedirectHostList;
}

RedirectHostUsage* SessionTerminationAnswer::getRedirectHostUsage(){
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

Unsigned32* SessionTerminationAnswer::getRedirectMaxCacheTime(){
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

list<ProxyInfo*>* SessionTerminationAnswer::getProxyInfoGrpList()
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
			mTagsPresent[SessionTerminationAnswer_PROXYINFO] = 0;
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

list<ProxyInfo*>* SessionTerminationAnswer::setProxyInfoGrpList(){
	mTagsPresent[SessionTerminationAnswer_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<ProxyInfo*>;
	mMandatoryAvpSetVal[SessionTerminationAnswer_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void SessionTerminationAnswer::resetProxyInfoGrpList(){
	mTagsPresent[SessionTerminationAnswer_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}

CCRequestType* SessionTerminationAnswer::getCCRequestType(){
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



int SessionTerminationAnswer::Encode(byteArray *array)
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
	array->byte[array->offset++] = (275>>16) & 0xFF;
	array->byte[array->offset++] = (275>>8) & 0xFF;
	array->byte[array->offset++] = (275) & 0xFF;
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
			case SessionTerminationAnswer_SESSIONID:
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
			case SessionTerminationAnswer_RESULTCODE:
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
			case SessionTerminationAnswer_ORIGINHOST:
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
			case SessionTerminationAnswer_ORIGINREALM:
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
			case SessionTerminationAnswer_USERNAME:
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
			case SessionTerminationAnswer_CLASS:
			{
					if( mClassList->size() <= 0) {
						break;
					}

					mClassIterator = this->getClassList()->begin();
					while(mClassIterator != mClassList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(25);
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
					if(!(*mClassIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mClassIterator)->getAvpOffsetLen().first], (*mClassIterator)->getAvpOffsetLen().second);
						array->offset += (*mClassIterator)->getAvpOffsetLen().second;
						array->size += (*mClassIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mClassIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mClassIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Class");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mClassIterator++;
						continue;
					}
						if(((*mClassIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mClassIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Class");
							throw lTssDiaMsgException;
						}
						mClassIterator++;
				}
				}
				break;
			case SessionTerminationAnswer_ORIGINSTATEID:
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
			case SessionTerminationAnswer_ERRORMESSAGE:
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
			case SessionTerminationAnswer_ERRORREPORTINGHOST:
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
			case SessionTerminationAnswer_REDIRECTHOST:
			{
					if( mRedirectHostList->size() <= 0) {
						break;
					}

					mRedirectHostIterator = this->getRedirectHostList()->begin();
					while(mRedirectHostIterator != mRedirectHostList->end())
					{
						lengthOffset = 0;
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
					if(!(*mRedirectHostIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mRedirectHostIterator)->getAvpOffsetLen().first], (*mRedirectHostIterator)->getAvpOffsetLen().second);
						array->offset += (*mRedirectHostIterator)->getAvpOffsetLen().second;
						array->size += (*mRedirectHostIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mRedirectHostIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mRedirectHostIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectHost");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mRedirectHostIterator++;
						continue;
					}
						if(((*mRedirectHostIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mRedirectHostIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectHost");
							throw lTssDiaMsgException;
						}
						mRedirectHostIterator++;
				}
				}
				break;
			case SessionTerminationAnswer_REDIRECTHOSTUSAGE:
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
			case SessionTerminationAnswer_REDIRECTMAXCACHETIME:
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
			case SessionTerminationAnswer_PROXYINFO:
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
			case SessionTerminationAnswer_CCREQUESTTYPE:
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


int SessionTerminationAnswer::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [SessionTerminationAnswer_SESSIONID] = 1;
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
						mMandatoryAvpSetVal [SessionTerminationAnswer_RESULTCODE] = 1;
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
						mMandatoryAvpSetVal [SessionTerminationAnswer_ORIGINHOST] = 1;
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
						mMandatoryAvpSetVal [SessionTerminationAnswer_ORIGINREALM] = 1;
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
						mMandatoryAvpSetVal [SessionTerminationAnswer_USERNAME] = 1;
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
			case 25:
				{
						mMandatoryAvpSetVal [SessionTerminationAnswer_CLASS] = 1;
					mTagsPresent[SessionTerminationAnswer_CLASS] = 1;
					OctetString *lClass = new OctetString();
					if( lClass == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Class");
						throw lTssDiaMsgException;
					}
					lClass->setAvpCode(25);
					lClass->setAvpVendorId(lVenderId);
					lClass->SetDataType((DiameterDataType)5);
					lClass->mspByteArray = mspByteArray;
					lClass->mAvpDecodedFlag = false;
					lClass->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mClassList == NULL)
						this->setClassList();
					mClassList->push_back(lClass);
					
				}
				break;
			case 278:
				{
						mMandatoryAvpSetVal [SessionTerminationAnswer_ORIGINSTATEID] = 1;
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
						mMandatoryAvpSetVal [SessionTerminationAnswer_REDIRECTHOST] = 1;
					mTagsPresent[SessionTerminationAnswer_REDIRECTHOST] = 1;
					OctetString *lRedirectHost = new OctetString();
					if( lRedirectHost == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectHost");
						throw lTssDiaMsgException;
					}
					lRedirectHost->setAvpCode(292);
					lRedirectHost->setAvpVendorId(lVenderId);
					lRedirectHost->SetDataType((DiameterDataType)5);
					lRedirectHost->mspByteArray = mspByteArray;
					lRedirectHost->mAvpDecodedFlag = false;
					lRedirectHost->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mRedirectHostList == NULL)
						this->setRedirectHostList();
					mRedirectHostList->push_back(lRedirectHost);
					
				}
				break;
			case 261:
				{
						mMandatoryAvpSetVal [SessionTerminationAnswer_REDIRECTHOSTUSAGE] = 1;
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
						mMandatoryAvpSetVal [SessionTerminationAnswer_REDIRECTMAXCACHETIME] = 1;
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
						mMandatoryAvpSetVal [SessionTerminationAnswer_PROXYINFO] = 1;
					mTagsPresent[SessionTerminationAnswer_PROXYINFO] = 1;
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
						mMandatoryAvpSetVal [SessionTerminationAnswer_CCREQUESTTYPE] = 1;
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


DiameterBaseInterface* SessionTerminationAnswer::Find(byteArray *array, UINT32 avpCode)
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
			case 25:
			{
				if(mClassList != NULL && mClassList->size() > 0)
					return (mClassList->back())->Find(array, avpCode);
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
				if(mRedirectHostList != NULL && mRedirectHostList->size() > 0)
					return (mRedirectHostList->back())->Find(array, avpCode);
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


BOOLEAN SessionTerminationAnswer::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 25:
			{
				if(mClassList != NULL)
				{
					for(auto itr = mClassList->begin(); itr != mClassList->end(); ++itr)
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
				if(mRedirectHostList != NULL)
				{
					for(auto itr = mRedirectHostList->begin(); itr != mRedirectHostList->end(); ++itr)
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
std::shared_ptr<byteArray> SessionTerminationAnswer::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN SessionTerminationAnswer::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 25:
			{
				if(mClassList != NULL)
				{
					for(auto itr = mClassList->begin(); itr != mClassList->end(); ++itr)
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
				if(mRedirectHostList != NULL)
				{
					for(auto itr = mRedirectHostList->begin(); itr != mRedirectHostList->end(); ++itr)
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




void SessionTerminationAnswer::Display(UINT32 tab)
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
			case SessionTerminationAnswer_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case SessionTerminationAnswer_RESULTCODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "268" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ResultCode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getResultCode()->Display(tab+1);
			}
				break;
			case SessionTerminationAnswer_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case SessionTerminationAnswer_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case SessionTerminationAnswer_USERNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getUserName()->Display(tab+1);
			}
				break;
			case SessionTerminationAnswer_CLASS:
			{
				if( mClassList->size() <= 0) {
					break;
				}

				mClassIterator = this->getClassList()->begin();
				while(mClassIterator != this->getClassList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "25" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Class" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mClassIterator)->Display(tab+1);
					mClassIterator++;

				};

			}
				break;
			case SessionTerminationAnswer_ORIGINSTATEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "278" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginStateId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginStateId()->Display(tab+1);
			}
				break;
			case SessionTerminationAnswer_ERRORMESSAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "281" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ErrorMessage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getErrorMessage()->Display(tab+1);
			}
				break;
			case SessionTerminationAnswer_ERRORREPORTINGHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "294" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ErrorReportingHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getErrorReportingHost()->Display(tab+1);
			}
				break;
			case SessionTerminationAnswer_REDIRECTHOST:
			{
				if( mRedirectHostList->size() <= 0) {
					break;
				}

				mRedirectHostIterator = this->getRedirectHostList()->begin();
				while(mRedirectHostIterator != this->getRedirectHostList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "292" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectHost" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
					(*mRedirectHostIterator)->Display(tab+1);
					mRedirectHostIterator++;

				};

			}
				break;
			case SessionTerminationAnswer_REDIRECTHOSTUSAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "261" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectHostUsage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getRedirectHostUsage()->Display(tab+1);
			}
				break;
			case SessionTerminationAnswer_REDIRECTMAXCACHETIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "262" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectMaxCacheTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getRedirectMaxCacheTime()->Display(tab+1);
			}
				break;
			case SessionTerminationAnswer_PROXYINFO:
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
			case SessionTerminationAnswer_CCREQUESTTYPE:
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


BOOLEAN SessionTerminationAnswer::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<14> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case SessionTerminationAnswer_SESSIONID:
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
			case SessionTerminationAnswer_RESULTCODE:
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
			case SessionTerminationAnswer_ORIGINHOST:
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
			case SessionTerminationAnswer_ORIGINREALM:
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
			case SessionTerminationAnswer_USERNAME:
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
			case SessionTerminationAnswer_CLASS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 25");
				}
				else
					sprintf(lMissingAvpInfo, "%s,25", lMissingAvpInfo);
			}
				break;
			case SessionTerminationAnswer_ORIGINSTATEID:
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
			case SessionTerminationAnswer_ERRORMESSAGE:
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
			case SessionTerminationAnswer_ERRORREPORTINGHOST:
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
			case SessionTerminationAnswer_REDIRECTHOST:
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
			case SessionTerminationAnswer_REDIRECTHOSTUSAGE:
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
			case SessionTerminationAnswer_REDIRECTMAXCACHETIME:
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
			case SessionTerminationAnswer_PROXYINFO:
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
			case SessionTerminationAnswer_CCREQUESTTYPE:
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
