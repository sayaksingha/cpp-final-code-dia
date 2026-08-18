#include "base/include/CapabilityExchangeRequest.h"

using namespace BASE;
BOOLEAN CapabilityExchangeRequest::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

CapabilityExchangeRequest::CapabilityExchangeRequest()
{
	mSessionId = NULL;
	mOriginHost = NULL;
	mOriginRealm = NULL;
	mHostIPAddressList = NULL;
	mVendorId = NULL;
	mProductName = NULL;
	mOriginStateId = NULL;
	mSupportedVendorIdList = NULL;
	mAuthApplicationIdList = NULL;
	mInbandSecurityId = NULL;
	mAcctApplicationIdList = NULL;
	mVendorSpecificApplicationIdGrpList = NULL;
	mFirmwareRevision = NULL;
	mSourceModuleId = NULL;
	mDestModuleId = NULL;
	mCCRequestNumber = NULL;
	mResultCode = NULL;
	mCCRequestType = NULL;
	mUniqueMsgRefNo = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<19>(string("1111110100111011111"));
	mMandatoryAvpSetVal.reset();
}

CapabilityExchangeRequest::~CapabilityExchangeRequest()
{
	if(mSessionId != NULL)
		delete mSessionId;
	if(mOriginHost != NULL)
		delete mOriginHost;
	if(mOriginRealm != NULL)
		delete mOriginRealm;
	if(mHostIPAddressList != NULL){
		mHostIPAddressIterator = mHostIPAddressList->begin();
		while(mHostIPAddressIterator != mHostIPAddressList->end()){
			delete (*mHostIPAddressIterator);
			mHostIPAddressIterator++;
		}
		delete mHostIPAddressList;
	}
	if(mVendorId != NULL)
		delete mVendorId;
	if(mProductName != NULL)
		delete mProductName;
	if(mOriginStateId != NULL)
		delete mOriginStateId;
	if(mSupportedVendorIdList != NULL){
		mSupportedVendorIdIterator = mSupportedVendorIdList->begin();
		while(mSupportedVendorIdIterator != mSupportedVendorIdList->end()){
			delete (*mSupportedVendorIdIterator);
			mSupportedVendorIdIterator++;
		}
		delete mSupportedVendorIdList;
	}
	if(mAuthApplicationIdList != NULL){
		mAuthApplicationIdIterator = mAuthApplicationIdList->begin();
		while(mAuthApplicationIdIterator != mAuthApplicationIdList->end()){
			delete (*mAuthApplicationIdIterator);
			mAuthApplicationIdIterator++;
		}
		delete mAuthApplicationIdList;
	}
	if(mInbandSecurityId != NULL)
		delete mInbandSecurityId;
	if(mAcctApplicationIdList != NULL){
		mAcctApplicationIdIterator = mAcctApplicationIdList->begin();
		while(mAcctApplicationIdIterator != mAcctApplicationIdList->end()){
			delete (*mAcctApplicationIdIterator);
			mAcctApplicationIdIterator++;
		}
		delete mAcctApplicationIdList;
	}
	if(mVendorSpecificApplicationIdGrpList != NULL){
		mVendorSpecificApplicationIdGrpIterator = mVendorSpecificApplicationIdGrpList->begin();
		while(mVendorSpecificApplicationIdGrpIterator != mVendorSpecificApplicationIdGrpList->end()){
	if(*mVendorSpecificApplicationIdGrpIterator != NULL)
			delete (*mVendorSpecificApplicationIdGrpIterator);
			mVendorSpecificApplicationIdGrpIterator++;
		}
		delete mVendorSpecificApplicationIdGrpList;
	}
	if(mFirmwareRevision != NULL)
		delete mFirmwareRevision;
	if(mSourceModuleId != NULL)
		delete mSourceModuleId;
	if(mDestModuleId != NULL)
		delete mDestModuleId;
	if(mCCRequestNumber != NULL)
		delete mCCRequestNumber;
	if(mResultCode != NULL)
		delete mResultCode;
	if(mCCRequestType != NULL)
		delete mCCRequestType;
	if(mUniqueMsgRefNo != NULL)
		delete mUniqueMsgRefNo;
}

OctetString* CapabilityExchangeRequest::setSessionId(){
	mMandatoryAvpSetVal [CapabilityExchangeRequest_SESSIONID] = 1;
	if(mSessionId == NULL)
	{
		mSessionId = new OctetString();
		mTagsPresent[CapabilityExchangeRequest_SESSIONID] = 1;
		return mSessionId;
	}
	return mSessionId;
}

void CapabilityExchangeRequest::resetSessionId(){
	mTagsPresent[CapabilityExchangeRequest_SESSIONID] = 0;
	if(mSessionId != NULL)
	{
		delete mSessionId; 
		mSessionId = NULL;
	}
}

OctetString* CapabilityExchangeRequest::setOriginHost(){
	mMandatoryAvpSetVal [CapabilityExchangeRequest_ORIGINHOST] = 1;
	if(mOriginHost == NULL)
	{
		mOriginHost = new OctetString();
		mTagsPresent[CapabilityExchangeRequest_ORIGINHOST] = 1;
		return mOriginHost;
	}
	return mOriginHost;
}

void CapabilityExchangeRequest::resetOriginHost(){
	mTagsPresent[CapabilityExchangeRequest_ORIGINHOST] = 0;
	if(mOriginHost != NULL)
	{
		delete mOriginHost; 
		mOriginHost = NULL;
	}
}

OctetString* CapabilityExchangeRequest::setOriginRealm(){
	mMandatoryAvpSetVal [CapabilityExchangeRequest_ORIGINREALM] = 1;
	if(mOriginRealm == NULL)
	{
		mOriginRealm = new OctetString();
		mTagsPresent[CapabilityExchangeRequest_ORIGINREALM] = 1;
		return mOriginRealm;
	}
	return mOriginRealm;
}

void CapabilityExchangeRequest::resetOriginRealm(){
	mTagsPresent[CapabilityExchangeRequest_ORIGINREALM] = 0;
	if(mOriginRealm != NULL)
	{
		delete mOriginRealm; 
		mOriginRealm = NULL;
	}
}

Integer32* CapabilityExchangeRequest::setVendorId(){
	mMandatoryAvpSetVal [CapabilityExchangeRequest_VENDORID] = 1;
	if(mVendorId == NULL)
	{
		mVendorId = new Integer32();
		mTagsPresent[CapabilityExchangeRequest_VENDORID] = 1;
		return mVendorId;
	}
	return mVendorId;
}

void CapabilityExchangeRequest::resetVendorId(){
	mTagsPresent[CapabilityExchangeRequest_VENDORID] = 0;
	if(mVendorId != NULL)
	{
		delete mVendorId; 
		mVendorId = NULL;
	}
}

OctetString* CapabilityExchangeRequest::setProductName(){
	if(mProductName == NULL)
	{
		mProductName = new OctetString();
		mTagsPresent[CapabilityExchangeRequest_PRODUCTNAME] = 1;
		return mProductName;
	}
	return mProductName;
}

void CapabilityExchangeRequest::resetProductName(){
	mTagsPresent[CapabilityExchangeRequest_PRODUCTNAME] = 0;
	if(mProductName != NULL)
	{
		delete mProductName; 
		mProductName = NULL;
	}
}

Unsigned32* CapabilityExchangeRequest::setOriginStateId(){
	mMandatoryAvpSetVal [CapabilityExchangeRequest_ORIGINSTATEID] = 1;
	if(mOriginStateId == NULL)
	{
		mOriginStateId = new Unsigned32();
		mTagsPresent[CapabilityExchangeRequest_ORIGINSTATEID] = 1;
		return mOriginStateId;
	}
	return mOriginStateId;
}

void CapabilityExchangeRequest::resetOriginStateId(){
	mTagsPresent[CapabilityExchangeRequest_ORIGINSTATEID] = 0;
	if(mOriginStateId != NULL)
	{
		delete mOriginStateId; 
		mOriginStateId = NULL;
	}
}

Integer32* CapabilityExchangeRequest::setInbandSecurityId(){
	if(mInbandSecurityId == NULL)
	{
		mInbandSecurityId = new Integer32();
		mTagsPresent[CapabilityExchangeRequest_INBANDSECURITYID] = 1;
		return mInbandSecurityId;
	}
	return mInbandSecurityId;
}

void CapabilityExchangeRequest::resetInbandSecurityId(){
	mTagsPresent[CapabilityExchangeRequest_INBANDSECURITYID] = 0;
	if(mInbandSecurityId != NULL)
	{
		delete mInbandSecurityId; 
		mInbandSecurityId = NULL;
	}
}

Integer32* CapabilityExchangeRequest::setFirmwareRevision(){
	if(mFirmwareRevision == NULL)
	{
		mFirmwareRevision = new Integer32();
		mTagsPresent[CapabilityExchangeRequest_FIRMWAREREVISION] = 1;
		return mFirmwareRevision;
	}
	return mFirmwareRevision;
}

void CapabilityExchangeRequest::resetFirmwareRevision(){
	mTagsPresent[CapabilityExchangeRequest_FIRMWAREREVISION] = 0;
	if(mFirmwareRevision != NULL)
	{
		delete mFirmwareRevision; 
		mFirmwareRevision = NULL;
	}
}

Integer32* CapabilityExchangeRequest::setSourceModuleId(){
	mMandatoryAvpSetVal [CapabilityExchangeRequest_SOURCEMODULEID] = 1;
	if(mSourceModuleId == NULL)
	{
		mSourceModuleId = new Integer32();
		mTagsPresent[CapabilityExchangeRequest_SOURCEMODULEID] = 1;
		return mSourceModuleId;
	}
	return mSourceModuleId;
}

void CapabilityExchangeRequest::resetSourceModuleId(){
	mTagsPresent[CapabilityExchangeRequest_SOURCEMODULEID] = 0;
	if(mSourceModuleId != NULL)
	{
		delete mSourceModuleId; 
		mSourceModuleId = NULL;
	}
}

Integer32* CapabilityExchangeRequest::setDestModuleId(){
	mMandatoryAvpSetVal [CapabilityExchangeRequest_DESTMODULEID] = 1;
	if(mDestModuleId == NULL)
	{
		mDestModuleId = new Integer32();
		mTagsPresent[CapabilityExchangeRequest_DESTMODULEID] = 1;
		return mDestModuleId;
	}
	return mDestModuleId;
}

void CapabilityExchangeRequest::resetDestModuleId(){
	mTagsPresent[CapabilityExchangeRequest_DESTMODULEID] = 0;
	if(mDestModuleId != NULL)
	{
		delete mDestModuleId; 
		mDestModuleId = NULL;
	}
}

Unsigned32* CapabilityExchangeRequest::setCCRequestNumber(){
	mMandatoryAvpSetVal [CapabilityExchangeRequest_CCREQUESTNUMBER] = 1;
	if(mCCRequestNumber == NULL)
	{
		mCCRequestNumber = new Unsigned32();
		mTagsPresent[CapabilityExchangeRequest_CCREQUESTNUMBER] = 1;
		return mCCRequestNumber;
	}
	return mCCRequestNumber;
}

void CapabilityExchangeRequest::resetCCRequestNumber(){
	mTagsPresent[CapabilityExchangeRequest_CCREQUESTNUMBER] = 0;
	if(mCCRequestNumber != NULL)
	{
		delete mCCRequestNumber; 
		mCCRequestNumber = NULL;
	}
}

Unsigned32* CapabilityExchangeRequest::setResultCode(){
	mMandatoryAvpSetVal [CapabilityExchangeRequest_RESULTCODE] = 1;
	if(mResultCode == NULL)
	{
		mResultCode = new Unsigned32();
		mTagsPresent[CapabilityExchangeRequest_RESULTCODE] = 1;
		return mResultCode;
	}
	return mResultCode;
}

void CapabilityExchangeRequest::resetResultCode(){
	mTagsPresent[CapabilityExchangeRequest_RESULTCODE] = 0;
	if(mResultCode != NULL)
	{
		delete mResultCode; 
		mResultCode = NULL;
	}
}

CCRequestType* CapabilityExchangeRequest::setCCRequestType(){
	mMandatoryAvpSetVal [CapabilityExchangeRequest_CCREQUESTTYPE] = 1;
	if(mCCRequestType == NULL)
	{
		mCCRequestType = new CCRequestType();
		mTagsPresent[CapabilityExchangeRequest_CCREQUESTTYPE] = 1;
		return mCCRequestType;
	}
	return mCCRequestType;
}

void CapabilityExchangeRequest::resetCCRequestType(){
	mTagsPresent[CapabilityExchangeRequest_CCREQUESTTYPE] = 0;
	if(mCCRequestType != NULL)
	{
		delete mCCRequestType; 
		mCCRequestType = NULL;
	}
}

OctetString* CapabilityExchangeRequest::setUniqueMsgRefNo(){
	mMandatoryAvpSetVal [CapabilityExchangeRequest_UNIQUEMSGREFNO] = 1;
	if(mUniqueMsgRefNo == NULL)
	{
		mUniqueMsgRefNo = new OctetString();
		mTagsPresent[CapabilityExchangeRequest_UNIQUEMSGREFNO] = 1;
		return mUniqueMsgRefNo;
	}
	return mUniqueMsgRefNo;
}

void CapabilityExchangeRequest::resetUniqueMsgRefNo(){
	mTagsPresent[CapabilityExchangeRequest_UNIQUEMSGREFNO] = 0;
	if(mUniqueMsgRefNo != NULL)
	{
		delete mUniqueMsgRefNo; 
		mUniqueMsgRefNo = NULL;
	}
}

OctetString* CapabilityExchangeRequest::getSessionId(){
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

OctetString* CapabilityExchangeRequest::getOriginHost(){
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

OctetString* CapabilityExchangeRequest::getOriginRealm(){
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

list<Address*>* CapabilityExchangeRequest::getHostIPAddressList()
{
	if(mHostIPAddressList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "HostIPAddress is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mHostIPAddressList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "HostIPAddress is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding HostIPAddress")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mHostIPAddressList;
}

list<Address*>* CapabilityExchangeRequest::setHostIPAddressList() {
	mTagsPresent[CapabilityExchangeRequest_HOSTIPADDRESS] = 1;
	if(mHostIPAddressList == NULL)
		mHostIPAddressList = new list<Address*>;
	mMandatoryAvpSetVal [CapabilityExchangeRequest_HOSTIPADDRESS] = 1;
	mHostIPAddressList->clear();
	return mHostIPAddressList;
}

void CapabilityExchangeRequest::resetHostIPAddressList(){
	mTagsPresent[CapabilityExchangeRequest_HOSTIPADDRESS] = 0;
	if(mHostIPAddressList != NULL)
		delete mHostIPAddressList;
}

Integer32* CapabilityExchangeRequest::getVendorId(){
	if(NULL == mVendorId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorId is Null");
		throw lTssDiaMsgException;
	}
	if(!mVendorId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mVendorId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "VendorId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mVendorId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mVendorId->Decode(mspByteArray.get(), mVendorId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding VendorId")     ;
			throw lTssDiaMsgException;
		}
		mVendorId->mAvpDecodedFlag = true;
	}
	return mVendorId;
}

OctetString* CapabilityExchangeRequest::getProductName(){
	if(NULL == mProductName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ProductName is Null");
		throw lTssDiaMsgException;
	}
	if(!mProductName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mProductName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ProductName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mProductName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mProductName->Decode(mspByteArray.get(), mProductName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ProductName")     ;
			throw lTssDiaMsgException;
		}
		mProductName->mAvpDecodedFlag = true;
	}
	return mProductName;
}

Unsigned32* CapabilityExchangeRequest::getOriginStateId(){
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

list<Integer32*>* CapabilityExchangeRequest::getSupportedVendorIdList()
{
	if(mSupportedVendorIdList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SupportedVendorId is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mSupportedVendorIdList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SupportedVendorId is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SupportedVendorId")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mSupportedVendorIdList;
}

list<Integer32*>* CapabilityExchangeRequest::setSupportedVendorIdList() {
	mTagsPresent[CapabilityExchangeRequest_SUPPORTEDVENDORID] = 1;
	if(mSupportedVendorIdList == NULL)
		mSupportedVendorIdList = new list<Integer32*>;
	mMandatoryAvpSetVal [CapabilityExchangeRequest_SUPPORTEDVENDORID] = 1;
	mSupportedVendorIdList->clear();
	return mSupportedVendorIdList;
}

void CapabilityExchangeRequest::resetSupportedVendorIdList(){
	mTagsPresent[CapabilityExchangeRequest_SUPPORTEDVENDORID] = 0;
	if(mSupportedVendorIdList != NULL)
		delete mSupportedVendorIdList;
}

list<Integer32*>* CapabilityExchangeRequest::getAuthApplicationIdList()
{
	if(mAuthApplicationIdList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AuthApplicationId is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mAuthApplicationIdList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AuthApplicationId is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AuthApplicationId")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mAuthApplicationIdList;
}

list<Integer32*>* CapabilityExchangeRequest::setAuthApplicationIdList() {
	mTagsPresent[CapabilityExchangeRequest_AUTHAPPLICATIONID] = 1;
	if(mAuthApplicationIdList == NULL)
		mAuthApplicationIdList = new list<Integer32*>;
	mMandatoryAvpSetVal [CapabilityExchangeRequest_AUTHAPPLICATIONID] = 1;
	mAuthApplicationIdList->clear();
	return mAuthApplicationIdList;
}

void CapabilityExchangeRequest::resetAuthApplicationIdList(){
	mTagsPresent[CapabilityExchangeRequest_AUTHAPPLICATIONID] = 0;
	if(mAuthApplicationIdList != NULL)
		delete mAuthApplicationIdList;
}

Integer32* CapabilityExchangeRequest::getInbandSecurityId(){
	if(NULL == mInbandSecurityId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "InbandSecurityId is Null");
		throw lTssDiaMsgException;
	}
	if(!mInbandSecurityId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mInbandSecurityId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "InbandSecurityId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mInbandSecurityId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mInbandSecurityId->Decode(mspByteArray.get(), mInbandSecurityId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding InbandSecurityId")     ;
			throw lTssDiaMsgException;
		}
		mInbandSecurityId->mAvpDecodedFlag = true;
	}
	return mInbandSecurityId;
}

list<Unsigned32*>* CapabilityExchangeRequest::getAcctApplicationIdList()
{
	if(mAcctApplicationIdList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcctApplicationId is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mAcctApplicationIdList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AcctApplicationId is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcctApplicationId")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mAcctApplicationIdList;
}

list<Unsigned32*>* CapabilityExchangeRequest::setAcctApplicationIdList() {
	mTagsPresent[CapabilityExchangeRequest_ACCTAPPLICATIONID] = 1;
	if(mAcctApplicationIdList == NULL)
		mAcctApplicationIdList = new list<Unsigned32*>;
	mAcctApplicationIdList->clear();
	return mAcctApplicationIdList;
}

void CapabilityExchangeRequest::resetAcctApplicationIdList(){
	mTagsPresent[CapabilityExchangeRequest_ACCTAPPLICATIONID] = 0;
	if(mAcctApplicationIdList != NULL)
		delete mAcctApplicationIdList;
}

list<VendorSpecificApplicationId*>* CapabilityExchangeRequest::getVendorSpecificApplicationIdGrpList()
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
			mTagsPresent[CapabilityExchangeRequest_VENDORSPECIFICAPPLICATIONID] = 0;
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

list<VendorSpecificApplicationId*>* CapabilityExchangeRequest::setVendorSpecificApplicationIdGrpList(){
	mTagsPresent[CapabilityExchangeRequest_VENDORSPECIFICAPPLICATIONID] = 1;
	if(mVendorSpecificApplicationIdGrpList == NULL)
		mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
	mMandatoryAvpSetVal[CapabilityExchangeRequest_VENDORSPECIFICAPPLICATIONID] = 1;
	mVendorSpecificApplicationIdGrpList->clear();
	return mVendorSpecificApplicationIdGrpList;
}

void CapabilityExchangeRequest::resetVendorSpecificApplicationIdGrpList(){
	mTagsPresent[CapabilityExchangeRequest_VENDORSPECIFICAPPLICATIONID] = 0;
	if(mVendorSpecificApplicationIdGrpList != NULL)
		delete mVendorSpecificApplicationIdGrpList;
}

Integer32* CapabilityExchangeRequest::getFirmwareRevision(){
	if(NULL == mFirmwareRevision) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FirmwareRevision is Null");
		throw lTssDiaMsgException;
	}
	if(!mFirmwareRevision->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFirmwareRevision->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FirmwareRevision is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFirmwareRevision->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFirmwareRevision->Decode(mspByteArray.get(), mFirmwareRevision->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FirmwareRevision")     ;
			throw lTssDiaMsgException;
		}
		mFirmwareRevision->mAvpDecodedFlag = true;
	}
	return mFirmwareRevision;
}

Integer32* CapabilityExchangeRequest::getSourceModuleId(){
	if(NULL == mSourceModuleId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SourceModuleId is Null");
		throw lTssDiaMsgException;
	}
	if(!mSourceModuleId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSourceModuleId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SourceModuleId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSourceModuleId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSourceModuleId->Decode(mspByteArray.get(), mSourceModuleId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SourceModuleId")     ;
			throw lTssDiaMsgException;
		}
		mSourceModuleId->mAvpDecodedFlag = true;
	}
	return mSourceModuleId;
}

Integer32* CapabilityExchangeRequest::getDestModuleId(){
	if(NULL == mDestModuleId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DestModuleId is Null");
		throw lTssDiaMsgException;
	}
	if(!mDestModuleId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mDestModuleId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DestModuleId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mDestModuleId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mDestModuleId->Decode(mspByteArray.get(), mDestModuleId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DestModuleId")     ;
			throw lTssDiaMsgException;
		}
		mDestModuleId->mAvpDecodedFlag = true;
	}
	return mDestModuleId;
}

Unsigned32* CapabilityExchangeRequest::getCCRequestNumber(){
	if(NULL == mCCRequestNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCRequestNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mCCRequestNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCCRequestNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCRequestNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCCRequestNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCCRequestNumber->Decode(mspByteArray.get(), mCCRequestNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCRequestNumber")     ;
			throw lTssDiaMsgException;
		}
		mCCRequestNumber->mAvpDecodedFlag = true;
	}
	return mCCRequestNumber;
}

Unsigned32* CapabilityExchangeRequest::getResultCode(){
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

CCRequestType* CapabilityExchangeRequest::getCCRequestType(){
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

OctetString* CapabilityExchangeRequest::getUniqueMsgRefNo(){
	if(NULL == mUniqueMsgRefNo) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UniqueMsgRefNo is Null");
		throw lTssDiaMsgException;
	}
	if(!mUniqueMsgRefNo->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUniqueMsgRefNo->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UniqueMsgRefNo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUniqueMsgRefNo->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUniqueMsgRefNo->Decode(mspByteArray.get(), mUniqueMsgRefNo->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UniqueMsgRefNo")     ;
			throw lTssDiaMsgException;
		}
		mUniqueMsgRefNo->mAvpDecodedFlag = true;
	}
	return mUniqueMsgRefNo;
}



int CapabilityExchangeRequest::Encode(byteArray *array)
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
	array->byte[array->offset++] = (257>>16) & 0xFF;
	array->byte[array->offset++] = (257>>8) & 0xFF;
	array->byte[array->offset++] = (257) & 0xFF;
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
			case CapabilityExchangeRequest_SESSIONID:
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
			case CapabilityExchangeRequest_ORIGINHOST:
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
			case CapabilityExchangeRequest_ORIGINREALM:
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
			case CapabilityExchangeRequest_HOSTIPADDRESS:
			{
					if( mHostIPAddressList->size() <= 0) {
						break;
					}

					mHostIPAddressIterator = this->getHostIPAddressList()->begin();
					while(mHostIPAddressIterator != mHostIPAddressList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(257);
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
					if(!(*mHostIPAddressIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mHostIPAddressIterator)->getAvpOffsetLen().first], (*mHostIPAddressIterator)->getAvpOffsetLen().second);
						array->offset += (*mHostIPAddressIterator)->getAvpOffsetLen().second;
						array->size += (*mHostIPAddressIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mHostIPAddressIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mHostIPAddressIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_TIME_LEN)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding HostIPAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mHostIPAddressIterator++;
						continue;
					}
						if(((*mHostIPAddressIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mHostIPAddressIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding HostIPAddress");
							throw lTssDiaMsgException;
						}
						mHostIPAddressIterator++;
				}
				}
				break;
			case CapabilityExchangeRequest_VENDORID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(266);
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
					if(!mVendorId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mVendorId->getAvpOffsetLen().first], mVendorId->getAvpOffsetLen().second);
						array->offset += mVendorId->getAvpOffsetLen().second;
						array->size += mVendorId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding VendorId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mVendorId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding VendorId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case CapabilityExchangeRequest_PRODUCTNAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(269);
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
					if(!mProductName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mProductName->getAvpOffsetLen().first], mProductName->getAvpOffsetLen().second);
						array->offset += mProductName->getAvpOffsetLen().second;
						array->size += mProductName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mProductName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mProductName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ProductName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mProductName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mProductName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ProductName");
						throw lTssDiaMsgException;
					}
				}
				break;
			case CapabilityExchangeRequest_ORIGINSTATEID:
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
			case CapabilityExchangeRequest_SUPPORTEDVENDORID:
			{
					if( mSupportedVendorIdList->size() <= 0) {
						break;
					}

					mSupportedVendorIdIterator = this->getSupportedVendorIdList()->begin();
					while(mSupportedVendorIdIterator != mSupportedVendorIdList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(265);
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
					if(!(*mSupportedVendorIdIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mSupportedVendorIdIterator)->getAvpOffsetLen().first], (*mSupportedVendorIdIterator)->getAvpOffsetLen().second);
						array->offset += (*mSupportedVendorIdIterator)->getAvpOffsetLen().second;
						array->size += (*mSupportedVendorIdIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SupportedVendorId");
							throw lTssDiaMsgException;
						}
						mSupportedVendorIdIterator++;
						continue;
					}
					if(((*mSupportedVendorIdIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SupportedVendorId");
						throw lTssDiaMsgException;
					}
					mSupportedVendorIdIterator++;
				}
				}
				break;
			case CapabilityExchangeRequest_AUTHAPPLICATIONID:
			{
					if( mAuthApplicationIdList->size() <= 0) {
						break;
					}

					mAuthApplicationIdIterator = this->getAuthApplicationIdList()->begin();
					while(mAuthApplicationIdIterator != mAuthApplicationIdList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(258);
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
					if(!(*mAuthApplicationIdIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mAuthApplicationIdIterator)->getAvpOffsetLen().first], (*mAuthApplicationIdIterator)->getAvpOffsetLen().second);
						array->offset += (*mAuthApplicationIdIterator)->getAvpOffsetLen().second;
						array->size += (*mAuthApplicationIdIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AuthApplicationId");
							throw lTssDiaMsgException;
						}
						mAuthApplicationIdIterator++;
						continue;
					}
					if(((*mAuthApplicationIdIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AuthApplicationId");
						throw lTssDiaMsgException;
					}
					mAuthApplicationIdIterator++;
				}
				}
				break;
			case CapabilityExchangeRequest_INBANDSECURITYID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(299);
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
					if(!mInbandSecurityId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mInbandSecurityId->getAvpOffsetLen().first], mInbandSecurityId->getAvpOffsetLen().second);
						array->offset += mInbandSecurityId->getAvpOffsetLen().second;
						array->size += mInbandSecurityId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding InbandSecurityId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mInbandSecurityId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding InbandSecurityId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case CapabilityExchangeRequest_ACCTAPPLICATIONID:
			{
					if( mAcctApplicationIdList->size() <= 0) {
						break;
					}

					mAcctApplicationIdIterator = this->getAcctApplicationIdList()->begin();
					while(mAcctApplicationIdIterator != mAcctApplicationIdList->end())
					{
						lengthOffset = 0;
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
					if(!(*mAcctApplicationIdIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mAcctApplicationIdIterator)->getAvpOffsetLen().first], (*mAcctApplicationIdIterator)->getAvpOffsetLen().second);
						array->offset += (*mAcctApplicationIdIterator)->getAvpOffsetLen().second;
						array->size += (*mAcctApplicationIdIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AcctApplicationId");
							throw lTssDiaMsgException;
						}
						mAcctApplicationIdIterator++;
						continue;
					}
					if(((*mAcctApplicationIdIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AcctApplicationId");
						throw lTssDiaMsgException;
					}
					mAcctApplicationIdIterator++;
				}
				}
				break;
			case CapabilityExchangeRequest_VENDORSPECIFICAPPLICATIONID:
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
			case CapabilityExchangeRequest_FIRMWAREREVISION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(267);
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
					if(!mFirmwareRevision->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFirmwareRevision->getAvpOffsetLen().first], mFirmwareRevision->getAvpOffsetLen().second);
						array->offset += mFirmwareRevision->getAvpOffsetLen().second;
						array->size += mFirmwareRevision->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FirmwareRevision");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFirmwareRevision->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FirmwareRevision");
						throw lTssDiaMsgException;
					}
				}
				break;
			case CapabilityExchangeRequest_SOURCEMODULEID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(21258);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
					{ 
						INT32 venderId=34826;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mSourceModuleId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSourceModuleId->getAvpOffsetLen().first], mSourceModuleId->getAvpOffsetLen().second);
						array->offset += mSourceModuleId->getAvpOffsetLen().second;
						array->size += mSourceModuleId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SourceModuleId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mSourceModuleId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SourceModuleId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case CapabilityExchangeRequest_DESTMODULEID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(21259);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 192;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(192))
					{ 
						INT32 venderId=34826;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mDestModuleId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mDestModuleId->getAvpOffsetLen().first], mDestModuleId->getAvpOffsetLen().second);
						array->offset += mDestModuleId->getAvpOffsetLen().second;
						array->size += mDestModuleId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DestModuleId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mDestModuleId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DestModuleId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case CapabilityExchangeRequest_CCREQUESTNUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(415);
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
					if(!mCCRequestNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCCRequestNumber->getAvpOffsetLen().first], mCCRequestNumber->getAvpOffsetLen().second);
						array->offset += mCCRequestNumber->getAvpOffsetLen().second;
						array->size += mCCRequestNumber->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCRequestNumber");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCCRequestNumber->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCRequestNumber");
						throw lTssDiaMsgException;
					}
				}
				break;
			case CapabilityExchangeRequest_RESULTCODE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(268);
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
			case CapabilityExchangeRequest_CCREQUESTTYPE:
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
			case CapabilityExchangeRequest_UNIQUEMSGREFNO:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(21250);
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
					if(!mUniqueMsgRefNo->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUniqueMsgRefNo->getAvpOffsetLen().first], mUniqueMsgRefNo->getAvpOffsetLen().second);
						array->offset += mUniqueMsgRefNo->getAvpOffsetLen().second;
						array->size += mUniqueMsgRefNo->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUniqueMsgRefNo->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUniqueMsgRefNo->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UniqueMsgRefNo");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUniqueMsgRefNo->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUniqueMsgRefNo->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UniqueMsgRefNo");
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


int CapabilityExchangeRequest::Decode(byteArray *array, INT16 lMLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [CapabilityExchangeRequest_SESSIONID] = 1;
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
			case 264:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_ORIGINHOST] = 1;
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
						mMandatoryAvpSetVal [CapabilityExchangeRequest_ORIGINREALM] = 1;
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
			case 257:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_HOSTIPADDRESS] = 1;
					mTagsPresent[CapabilityExchangeRequest_HOSTIPADDRESS] = 1;
					Address *lHostIPAddress = new Address();
					if( lHostIPAddress == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding HostIPAddress");
						throw lTssDiaMsgException;
					}
					lHostIPAddress->setAvpCode(257);
					lHostIPAddress->setAvpVendorId(lVenderId);
					lHostIPAddress->SetDataType((DiameterDataType)8);
					lHostIPAddress->mspByteArray = mspByteArray;
					lHostIPAddress->mAvpDecodedFlag = false;
					lHostIPAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mHostIPAddressList == NULL)
						this->setHostIPAddressList();
					mHostIPAddressList->push_back(lHostIPAddress);
					
				}
				break;
			case 266:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_VENDORID] = 1;
					if( NULL == this->setVendorId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding VendorId");
						throw lTssDiaMsgException;
					}
					mVendorId->setAvpCode(266);
					mVendorId->setAvpVendorId(lVenderId);
					mVendorId->SetDataType((DiameterDataType)1);
					mVendorId->mspByteArray = mspByteArray;
					mVendorId->mAvpDecodedFlag = false;
					mVendorId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 269:
				{
					if( NULL == this->setProductName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ProductName");
						throw lTssDiaMsgException;
					}
					mProductName->setAvpCode(269);
					mProductName->setAvpVendorId(lVenderId);
					mProductName->SetDataType((DiameterDataType)5);
					mProductName->mspByteArray = mspByteArray;
					mProductName->mAvpDecodedFlag = false;
					mProductName->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 278:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_ORIGINSTATEID] = 1;
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
			case 265:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_SUPPORTEDVENDORID] = 1;
					mTagsPresent[CapabilityExchangeRequest_SUPPORTEDVENDORID] = 1;
					Integer32 *lSupportedVendorId = new Integer32();
					if( lSupportedVendorId == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SupportedVendorId");
						throw lTssDiaMsgException;
					}
					lSupportedVendorId->setAvpCode(265);
					lSupportedVendorId->setAvpVendorId(lVenderId);
					lSupportedVendorId->SetDataType((DiameterDataType)1);
					lSupportedVendorId->mspByteArray = mspByteArray;
					lSupportedVendorId->mAvpDecodedFlag = false;
					lSupportedVendorId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mSupportedVendorIdList == NULL)
						this->setSupportedVendorIdList();
					mSupportedVendorIdList->push_back(lSupportedVendorId);
					
				}
				break;
			case 258:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_AUTHAPPLICATIONID] = 1;
					mTagsPresent[CapabilityExchangeRequest_AUTHAPPLICATIONID] = 1;
					Integer32 *lAuthApplicationId = new Integer32();
					if( lAuthApplicationId == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AuthApplicationId");
						throw lTssDiaMsgException;
					}
					lAuthApplicationId->setAvpCode(258);
					lAuthApplicationId->setAvpVendorId(lVenderId);
					lAuthApplicationId->SetDataType((DiameterDataType)1);
					lAuthApplicationId->mspByteArray = mspByteArray;
					lAuthApplicationId->mAvpDecodedFlag = false;
					lAuthApplicationId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mAuthApplicationIdList == NULL)
						this->setAuthApplicationIdList();
					mAuthApplicationIdList->push_back(lAuthApplicationId);
					
				}
				break;
			case 299:
				{
					if( NULL == this->setInbandSecurityId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding InbandSecurityId");
						throw lTssDiaMsgException;
					}
					mInbandSecurityId->setAvpCode(299);
					mInbandSecurityId->setAvpVendorId(lVenderId);
					mInbandSecurityId->SetDataType((DiameterDataType)1);
					mInbandSecurityId->mspByteArray = mspByteArray;
					mInbandSecurityId->mAvpDecodedFlag = false;
					mInbandSecurityId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 259:
				{
					mTagsPresent[CapabilityExchangeRequest_ACCTAPPLICATIONID] = 1;
					Unsigned32 *lAcctApplicationId = new Unsigned32();
					if( lAcctApplicationId == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AcctApplicationId");
						throw lTssDiaMsgException;
					}
					lAcctApplicationId->setAvpCode(259);
					lAcctApplicationId->setAvpVendorId(lVenderId);
					lAcctApplicationId->SetDataType((DiameterDataType)3);
					lAcctApplicationId->mspByteArray = mspByteArray;
					lAcctApplicationId->mAvpDecodedFlag = false;
					lAcctApplicationId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mAcctApplicationIdList == NULL)
						this->setAcctApplicationIdList();
					mAcctApplicationIdList->push_back(lAcctApplicationId);
					
				}
				break;
			case 260:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_VENDORSPECIFICAPPLICATIONID] = 1;
					mTagsPresent[CapabilityExchangeRequest_VENDORSPECIFICAPPLICATIONID] = 1;
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
			case 267:
				{
					if( NULL == this->setFirmwareRevision())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FirmwareRevision");
						throw lTssDiaMsgException;
					}
					mFirmwareRevision->setAvpCode(267);
					mFirmwareRevision->setAvpVendorId(lVenderId);
					mFirmwareRevision->SetDataType((DiameterDataType)1);
					mFirmwareRevision->mspByteArray = mspByteArray;
					mFirmwareRevision->mAvpDecodedFlag = false;
					mFirmwareRevision->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 21258:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_SOURCEMODULEID] = 1;
					if( NULL == this->setSourceModuleId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SourceModuleId");
						throw lTssDiaMsgException;
					}
					mSourceModuleId->setAvpCode(21258);
					mSourceModuleId->setAvpVendorId(lVenderId);
					mSourceModuleId->SetDataType((DiameterDataType)1);
					mSourceModuleId->mspByteArray = mspByteArray;
					mSourceModuleId->mAvpDecodedFlag = false;
					mSourceModuleId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 21259:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_DESTMODULEID] = 1;
					if( NULL == this->setDestModuleId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DestModuleId");
						throw lTssDiaMsgException;
					}
					mDestModuleId->setAvpCode(21259);
					mDestModuleId->setAvpVendorId(lVenderId);
					mDestModuleId->SetDataType((DiameterDataType)1);
					mDestModuleId->mspByteArray = mspByteArray;
					mDestModuleId->mAvpDecodedFlag = false;
					mDestModuleId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 415:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_CCREQUESTNUMBER] = 1;
					if( NULL == this->setCCRequestNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCRequestNumber");
						throw lTssDiaMsgException;
					}
					mCCRequestNumber->setAvpCode(415);
					mCCRequestNumber->setAvpVendorId(lVenderId);
					mCCRequestNumber->SetDataType((DiameterDataType)3);
					mCCRequestNumber->mspByteArray = mspByteArray;
					mCCRequestNumber->mAvpDecodedFlag = false;
					mCCRequestNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 268:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_RESULTCODE] = 1;
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
			case 416:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_CCREQUESTTYPE] = 1;
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
			case 21250:
				{
						mMandatoryAvpSetVal [CapabilityExchangeRequest_UNIQUEMSGREFNO] = 1;
					if( NULL == this->setUniqueMsgRefNo())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UniqueMsgRefNo");
						throw lTssDiaMsgException;
					}
					mUniqueMsgRefNo->setAvpCode(21250);
					mUniqueMsgRefNo->setAvpVendorId(lVenderId);
					mUniqueMsgRefNo->SetDataType((DiameterDataType)5);
					mUniqueMsgRefNo->mspByteArray = mspByteArray;
					mUniqueMsgRefNo->mAvpDecodedFlag = false;
					mUniqueMsgRefNo->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* CapabilityExchangeRequest::Find(byteArray *array, UINT32 avpCode)
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
			case 257:
			{
				if(mHostIPAddressList != NULL && mHostIPAddressList->size() > 0)
					return (mHostIPAddressList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 266:
			{
				if(mVendorId != NULL)
					return mVendorId->Find(array, avpCode);
				else
					return NULL;
			}
			case 269:
			{
				if(mProductName != NULL)
					return mProductName->Find(array, avpCode);
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
			case 265:
			{
				if(mSupportedVendorIdList != NULL && mSupportedVendorIdList->size() > 0)
					return (mSupportedVendorIdList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 258:
			{
				if(mAuthApplicationIdList != NULL && mAuthApplicationIdList->size() > 0)
					return (mAuthApplicationIdList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 299:
			{
				if(mInbandSecurityId != NULL)
					return mInbandSecurityId->Find(array, avpCode);
				else
					return NULL;
			}
			case 259:
			{
				if(mAcctApplicationIdList != NULL && mAcctApplicationIdList->size() > 0)
					return (mAcctApplicationIdList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 267:
			{
				if(mFirmwareRevision != NULL)
					return mFirmwareRevision->Find(array, avpCode);
				else
					return NULL;
			}
			case 21258:
			{
				if(mSourceModuleId != NULL)
					return mSourceModuleId->Find(array, avpCode);
				else
					return NULL;
			}
			case 21259:
			{
				if(mDestModuleId != NULL)
					return mDestModuleId->Find(array, avpCode);
				else
					return NULL;
			}
			case 415:
			{
				if(mCCRequestNumber != NULL)
					return mCCRequestNumber->Find(array, avpCode);
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
			case 416:
			{
				if(mCCRequestType != NULL)
					return mCCRequestType->Find(array, avpCode);
				else
					return NULL;
			}
			case 21250:
			{
				if(mUniqueMsgRefNo != NULL)
					return mUniqueMsgRefNo->Find(array, avpCode);
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


BOOLEAN CapabilityExchangeRequest::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 257:
			{
				if(mHostIPAddressList != NULL)
				{
					for(auto itr = mHostIPAddressList->begin(); itr != mHostIPAddressList->end(); ++itr)
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
			case 266:
			{
				if(mVendorId != NULL)
				{
					DiameterBaseInterface* inf =  mVendorId->Find(this->mspByteArray.get(), avpCode);
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
			case 269:
			{
				if(mProductName != NULL)
				{
					DiameterBaseInterface* inf =  mProductName->Find(this->mspByteArray.get(), avpCode);
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
			case 265:
			{
				if(mSupportedVendorIdList != NULL)
				{
					for(auto itr = mSupportedVendorIdList->begin(); itr != mSupportedVendorIdList->end(); ++itr)
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
			case 258:
			{
				if(mAuthApplicationIdList != NULL)
				{
					for(auto itr = mAuthApplicationIdList->begin(); itr != mAuthApplicationIdList->end(); ++itr)
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
			case 299:
			{
				if(mInbandSecurityId != NULL)
				{
					DiameterBaseInterface* inf =  mInbandSecurityId->Find(this->mspByteArray.get(), avpCode);
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
				if(mAcctApplicationIdList != NULL)
				{
					for(auto itr = mAcctApplicationIdList->begin(); itr != mAcctApplicationIdList->end(); ++itr)
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
			case 267:
			{
				if(mFirmwareRevision != NULL)
				{
					DiameterBaseInterface* inf =  mFirmwareRevision->Find(this->mspByteArray.get(), avpCode);
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
			case 21258:
			{
				if(mSourceModuleId != NULL)
				{
					DiameterBaseInterface* inf =  mSourceModuleId->Find(this->mspByteArray.get(), avpCode);
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
			case 21259:
			{
				if(mDestModuleId != NULL)
				{
					DiameterBaseInterface* inf =  mDestModuleId->Find(this->mspByteArray.get(), avpCode);
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
			case 415:
			{
				if(mCCRequestNumber != NULL)
				{
					DiameterBaseInterface* inf =  mCCRequestNumber->Find(this->mspByteArray.get(), avpCode);
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
			case 21250:
			{
				if(mUniqueMsgRefNo != NULL)
				{
					DiameterBaseInterface* inf =  mUniqueMsgRefNo->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> CapabilityExchangeRequest::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN CapabilityExchangeRequest::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
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
			case 257:
			{
				if(mHostIPAddressList != NULL)
				{
					for(auto itr = mHostIPAddressList->begin(); itr != mHostIPAddressList->end(); ++itr)
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
			case 266:
			{
				if(mVendorId != NULL)
				{
					DiameterBaseInterface* inf =  mVendorId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 269:
			{
				if(mProductName != NULL)
				{
					DiameterBaseInterface* inf =  mProductName->Find(this->mspByteArray.get(), avpCode);
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
			case 265:
			{
				if(mSupportedVendorIdList != NULL)
				{
					for(auto itr = mSupportedVendorIdList->begin(); itr != mSupportedVendorIdList->end(); ++itr)
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
			case 258:
			{
				if(mAuthApplicationIdList != NULL)
				{
					for(auto itr = mAuthApplicationIdList->begin(); itr != mAuthApplicationIdList->end(); ++itr)
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
			case 299:
			{
				if(mInbandSecurityId != NULL)
				{
					DiameterBaseInterface* inf =  mInbandSecurityId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 259:
			{
				if(mAcctApplicationIdList != NULL)
				{
					for(auto itr = mAcctApplicationIdList->begin(); itr != mAcctApplicationIdList->end(); ++itr)
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
			case 267:
			{
				if(mFirmwareRevision != NULL)
				{
					DiameterBaseInterface* inf =  mFirmwareRevision->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 21258:
			{
				if(mSourceModuleId != NULL)
				{
					DiameterBaseInterface* inf =  mSourceModuleId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 21259:
			{
				if(mDestModuleId != NULL)
				{
					DiameterBaseInterface* inf =  mDestModuleId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 415:
			{
				if(mCCRequestNumber != NULL)
				{
					DiameterBaseInterface* inf =  mCCRequestNumber->Find(this->mspByteArray.get(), avpCode);
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
			case 21250:
			{
				if(mUniqueMsgRefNo != NULL)
				{
					DiameterBaseInterface* inf =  mUniqueMsgRefNo->Find(this->mspByteArray.get(), avpCode);
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




void CapabilityExchangeRequest::Display(UINT32 tab)
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
			case CapabilityExchangeRequest_SESSIONID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "263" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SessionId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSessionId()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_ORIGINHOST:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "264" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginHost" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginHost()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_ORIGINREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "296" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginRealm()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_HOSTIPADDRESS:
			{
				if( mHostIPAddressList->size() <= 0) {
					break;
				}

				mHostIPAddressIterator = this->getHostIPAddressList()->begin();
				while(mHostIPAddressIterator != this->getHostIPAddressList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "257" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "HostIPAddress" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mHostIPAddressIterator)->Display(tab+1);
					mHostIPAddressIterator++;

				};

			}
				break;
			case CapabilityExchangeRequest_VENDORID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "266" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "VendorId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getVendorId()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_PRODUCTNAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "269" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ProductName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getProductName()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_ORIGINSTATEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "278" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "OriginStateId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getOriginStateId()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_SUPPORTEDVENDORID:
			{
				if( mSupportedVendorIdList->size() <= 0) {
					break;
				}

				mSupportedVendorIdIterator = this->getSupportedVendorIdList()->begin();
				while(mSupportedVendorIdIterator != this->getSupportedVendorIdList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "265" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SupportedVendorId" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mSupportedVendorIdIterator)->Display(tab+1);
					mSupportedVendorIdIterator++;

				};

			}
				break;
			case CapabilityExchangeRequest_AUTHAPPLICATIONID:
			{
				if( mAuthApplicationIdList->size() <= 0) {
					break;
				}

				mAuthApplicationIdIterator = this->getAuthApplicationIdList()->begin();
				while(mAuthApplicationIdIterator != this->getAuthApplicationIdList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "258" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AuthApplicationId" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mAuthApplicationIdIterator)->Display(tab+1);
					mAuthApplicationIdIterator++;

				};

			}
				break;
			case CapabilityExchangeRequest_INBANDSECURITYID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "299" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "InbandSecurityId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getInbandSecurityId()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_ACCTAPPLICATIONID:
			{
				if( mAcctApplicationIdList->size() <= 0) {
					break;
				}

				mAcctApplicationIdIterator = this->getAcctApplicationIdList()->begin();
				while(mAcctApplicationIdIterator != this->getAcctApplicationIdList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "259" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AcctApplicationId" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
					(*mAcctApplicationIdIterator)->Display(tab+1);
					mAcctApplicationIdIterator++;

				};

			}
				break;
			case CapabilityExchangeRequest_VENDORSPECIFICAPPLICATIONID:
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
			case CapabilityExchangeRequest_FIRMWAREREVISION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "267" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FirmwareRevision" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getFirmwareRevision()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_SOURCEMODULEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "21258" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SourceModuleId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSourceModuleId()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_DESTMODULEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "21259" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DestModuleId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getDestModuleId()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_CCREQUESTNUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "415" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCRequestNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getCCRequestNumber()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_RESULTCODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "268" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ResultCode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getResultCode()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_CCREQUESTTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "416" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCRequestType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getCCRequestType()->Display(tab+1);
			}
				break;
			case CapabilityExchangeRequest_UNIQUEMSGREFNO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "21250" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UniqueMsgRefNo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getUniqueMsgRefNo()->Display(tab+1);
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


BOOLEAN CapabilityExchangeRequest::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<19> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case CapabilityExchangeRequest_SESSIONID:
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
			case CapabilityExchangeRequest_ORIGINHOST:
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
			case CapabilityExchangeRequest_ORIGINREALM:
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
			case CapabilityExchangeRequest_HOSTIPADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 257");
				}
				else
					sprintf(lMissingAvpInfo, "%s,257", lMissingAvpInfo);
			}
				break;
			case CapabilityExchangeRequest_VENDORID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 266");
				}
				else
					sprintf(lMissingAvpInfo, "%s,266", lMissingAvpInfo);
			}
				break;
			case CapabilityExchangeRequest_PRODUCTNAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 269");
				}
				else
					sprintf(lMissingAvpInfo, "%s,269", lMissingAvpInfo);
			}
				break;
			case CapabilityExchangeRequest_ORIGINSTATEID:
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
			case CapabilityExchangeRequest_SUPPORTEDVENDORID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 265");
				}
				else
					sprintf(lMissingAvpInfo, "%s,265", lMissingAvpInfo);
			}
				break;
			case CapabilityExchangeRequest_AUTHAPPLICATIONID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 258");
				}
				else
					sprintf(lMissingAvpInfo, "%s,258", lMissingAvpInfo);
			}
				break;
			case CapabilityExchangeRequest_INBANDSECURITYID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 299");
				}
				else
					sprintf(lMissingAvpInfo, "%s,299", lMissingAvpInfo);
			}
				break;
			case CapabilityExchangeRequest_ACCTAPPLICATIONID:
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
			case CapabilityExchangeRequest_VENDORSPECIFICAPPLICATIONID:
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
			case CapabilityExchangeRequest_FIRMWAREREVISION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 267");
				}
				else
					sprintf(lMissingAvpInfo, "%s,267", lMissingAvpInfo);
			}
				break;
			case CapabilityExchangeRequest_SOURCEMODULEID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 21258");
				}
				else
					sprintf(lMissingAvpInfo, "%s,21258", lMissingAvpInfo);
			}
				break;
			case CapabilityExchangeRequest_DESTMODULEID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 21259");
				}
				else
					sprintf(lMissingAvpInfo, "%s,21259", lMissingAvpInfo);
			}
				break;
			case CapabilityExchangeRequest_CCREQUESTNUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 415");
				}
				else
					sprintf(lMissingAvpInfo, "%s,415", lMissingAvpInfo);
			}
				break;
			case CapabilityExchangeRequest_RESULTCODE:
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
			case CapabilityExchangeRequest_CCREQUESTTYPE:
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
			case CapabilityExchangeRequest_UNIQUEMSGREFNO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 21250");
				}
				else
					sprintf(lMissingAvpInfo, "%s,21250", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
