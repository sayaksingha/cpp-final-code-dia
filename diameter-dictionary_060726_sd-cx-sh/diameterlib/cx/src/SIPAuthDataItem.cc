#include "cx/include/SIPAuthDataItem.h"

using namespace CX;
BOOLEAN SIPAuthDataItem::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

SIPAuthDataItem::SIPAuthDataItem()
{
	mSIPItemNumber = NULL;
	mSIPAuthenticationScheme = NULL;
	mSIPAuthenticate = NULL;
	mSIPAuthorization = NULL;
	mSIPAuthenticationContext = NULL;
	mConfidentialityKey = NULL;
	mIntegrityKey = NULL;
	mSIPDigestAuthenticateGrp = NULL;
	mFramedIPAddress = NULL;
	mFramedIPv6Prefix = NULL;
	mFramedInterfaceId = NULL;
	mLineIdentifierList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<12>(string("011101111111"));
	mMandatoryAvpSetVal.reset();
}

SIPAuthDataItem::~SIPAuthDataItem()
{
	if(mSIPItemNumber != NULL)
		delete mSIPItemNumber;
	if(mSIPAuthenticationScheme != NULL)
		delete mSIPAuthenticationScheme;
	if(mSIPAuthenticate != NULL)
		delete mSIPAuthenticate;
	if(mSIPAuthorization != NULL)
		delete mSIPAuthorization;
	if(mSIPAuthenticationContext != NULL)
		delete mSIPAuthenticationContext;
	if(mConfidentialityKey != NULL)
		delete mConfidentialityKey;
	if(mIntegrityKey != NULL)
		delete mIntegrityKey;
	if(mSIPDigestAuthenticateGrp != NULL)
		delete mSIPDigestAuthenticateGrp;
	if(mFramedIPAddress != NULL)
		delete mFramedIPAddress;
	if(mFramedIPv6Prefix != NULL)
		delete mFramedIPv6Prefix;
	if(mFramedInterfaceId != NULL)
		delete mFramedInterfaceId;
	if(mLineIdentifierList != NULL){
		mLineIdentifierIterator = mLineIdentifierList->begin();
		while(mLineIdentifierIterator != mLineIdentifierList->end()){
			delete (*mLineIdentifierIterator);
			mLineIdentifierIterator++;
		}
		delete mLineIdentifierList;
	}
}

Unsigned32* SIPAuthDataItem::setSIPItemNumber(){
	mMandatoryAvpSetVal [SIPAuthDataItem_SIPITEMNUMBER] = 1;
	if(mSIPItemNumber == NULL)
	{
		mSIPItemNumber = new Unsigned32();
		mTagsPresent[SIPAuthDataItem_SIPITEMNUMBER] = 1;
		return mSIPItemNumber;
	}
	return mSIPItemNumber;
}

void SIPAuthDataItem::resetSIPItemNumber(){
	mTagsPresent[SIPAuthDataItem_SIPITEMNUMBER] = 0;
	if(mSIPItemNumber != NULL)
	{
		delete mSIPItemNumber; 
		mSIPItemNumber = NULL;
	}
}

OctetString* SIPAuthDataItem::setSIPAuthenticationScheme(){
	mMandatoryAvpSetVal [SIPAuthDataItem_SIPAUTHENTICATIONSCHEME] = 1;
	if(mSIPAuthenticationScheme == NULL)
	{
		mSIPAuthenticationScheme = new OctetString();
		mTagsPresent[SIPAuthDataItem_SIPAUTHENTICATIONSCHEME] = 1;
		return mSIPAuthenticationScheme;
	}
	return mSIPAuthenticationScheme;
}

void SIPAuthDataItem::resetSIPAuthenticationScheme(){
	mTagsPresent[SIPAuthDataItem_SIPAUTHENTICATIONSCHEME] = 0;
	if(mSIPAuthenticationScheme != NULL)
	{
		delete mSIPAuthenticationScheme; 
		mSIPAuthenticationScheme = NULL;
	}
}

OctetString* SIPAuthDataItem::setSIPAuthenticate(){
	mMandatoryAvpSetVal [SIPAuthDataItem_SIPAUTHENTICATE] = 1;
	if(mSIPAuthenticate == NULL)
	{
		mSIPAuthenticate = new OctetString();
		mTagsPresent[SIPAuthDataItem_SIPAUTHENTICATE] = 1;
		return mSIPAuthenticate;
	}
	return mSIPAuthenticate;
}

void SIPAuthDataItem::resetSIPAuthenticate(){
	mTagsPresent[SIPAuthDataItem_SIPAUTHENTICATE] = 0;
	if(mSIPAuthenticate != NULL)
	{
		delete mSIPAuthenticate; 
		mSIPAuthenticate = NULL;
	}
}

OctetString* SIPAuthDataItem::setSIPAuthorization(){
	mMandatoryAvpSetVal [SIPAuthDataItem_SIPAUTHORIZATION] = 1;
	if(mSIPAuthorization == NULL)
	{
		mSIPAuthorization = new OctetString();
		mTagsPresent[SIPAuthDataItem_SIPAUTHORIZATION] = 1;
		return mSIPAuthorization;
	}
	return mSIPAuthorization;
}

void SIPAuthDataItem::resetSIPAuthorization(){
	mTagsPresent[SIPAuthDataItem_SIPAUTHORIZATION] = 0;
	if(mSIPAuthorization != NULL)
	{
		delete mSIPAuthorization; 
		mSIPAuthorization = NULL;
	}
}

OctetString* SIPAuthDataItem::setSIPAuthenticationContext(){
	mMandatoryAvpSetVal [SIPAuthDataItem_SIPAUTHENTICATIONCONTEXT] = 1;
	if(mSIPAuthenticationContext == NULL)
	{
		mSIPAuthenticationContext = new OctetString();
		mTagsPresent[SIPAuthDataItem_SIPAUTHENTICATIONCONTEXT] = 1;
		return mSIPAuthenticationContext;
	}
	return mSIPAuthenticationContext;
}

void SIPAuthDataItem::resetSIPAuthenticationContext(){
	mTagsPresent[SIPAuthDataItem_SIPAUTHENTICATIONCONTEXT] = 0;
	if(mSIPAuthenticationContext != NULL)
	{
		delete mSIPAuthenticationContext; 
		mSIPAuthenticationContext = NULL;
	}
}

OctetString* SIPAuthDataItem::setConfidentialityKey(){
	mMandatoryAvpSetVal [SIPAuthDataItem_CONFIDENTIALITYKEY] = 1;
	if(mConfidentialityKey == NULL)
	{
		mConfidentialityKey = new OctetString();
		mTagsPresent[SIPAuthDataItem_CONFIDENTIALITYKEY] = 1;
		return mConfidentialityKey;
	}
	return mConfidentialityKey;
}

void SIPAuthDataItem::resetConfidentialityKey(){
	mTagsPresent[SIPAuthDataItem_CONFIDENTIALITYKEY] = 0;
	if(mConfidentialityKey != NULL)
	{
		delete mConfidentialityKey; 
		mConfidentialityKey = NULL;
	}
}

OctetString* SIPAuthDataItem::setIntegrityKey(){
	mMandatoryAvpSetVal [SIPAuthDataItem_INTEGRITYKEY] = 1;
	if(mIntegrityKey == NULL)
	{
		mIntegrityKey = new OctetString();
		mTagsPresent[SIPAuthDataItem_INTEGRITYKEY] = 1;
		return mIntegrityKey;
	}
	return mIntegrityKey;
}

void SIPAuthDataItem::resetIntegrityKey(){
	mTagsPresent[SIPAuthDataItem_INTEGRITYKEY] = 0;
	if(mIntegrityKey != NULL)
	{
		delete mIntegrityKey; 
		mIntegrityKey = NULL;
	}
}

OctetString* SIPAuthDataItem::setFramedIPAddress(){
	mMandatoryAvpSetVal [SIPAuthDataItem_FRAMEDIPADDRESS] = 1;
	if(mFramedIPAddress == NULL)
	{
		mFramedIPAddress = new OctetString();
		mTagsPresent[SIPAuthDataItem_FRAMEDIPADDRESS] = 1;
		return mFramedIPAddress;
	}
	return mFramedIPAddress;
}

void SIPAuthDataItem::resetFramedIPAddress(){
	mTagsPresent[SIPAuthDataItem_FRAMEDIPADDRESS] = 0;
	if(mFramedIPAddress != NULL)
	{
		delete mFramedIPAddress; 
		mFramedIPAddress = NULL;
	}
}

OctetString* SIPAuthDataItem::setFramedIPv6Prefix(){
	mMandatoryAvpSetVal [SIPAuthDataItem_FRAMEDIPV6PREFIX] = 1;
	if(mFramedIPv6Prefix == NULL)
	{
		mFramedIPv6Prefix = new OctetString();
		mTagsPresent[SIPAuthDataItem_FRAMEDIPV6PREFIX] = 1;
		return mFramedIPv6Prefix;
	}
	return mFramedIPv6Prefix;
}

void SIPAuthDataItem::resetFramedIPv6Prefix(){
	mTagsPresent[SIPAuthDataItem_FRAMEDIPV6PREFIX] = 0;
	if(mFramedIPv6Prefix != NULL)
	{
		delete mFramedIPv6Prefix; 
		mFramedIPv6Prefix = NULL;
	}
}

Unsigned64* SIPAuthDataItem::setFramedInterfaceId(){
	mMandatoryAvpSetVal [SIPAuthDataItem_FRAMEDINTERFACEID] = 1;
	if(mFramedInterfaceId == NULL)
	{
		mFramedInterfaceId = new Unsigned64();
		mTagsPresent[SIPAuthDataItem_FRAMEDINTERFACEID] = 1;
		return mFramedInterfaceId;
	}
	return mFramedInterfaceId;
}

void SIPAuthDataItem::resetFramedInterfaceId(){
	mTagsPresent[SIPAuthDataItem_FRAMEDINTERFACEID] = 0;
	if(mFramedInterfaceId != NULL)
	{
		delete mFramedInterfaceId; 
		mFramedInterfaceId = NULL;
	}
}

Unsigned32* SIPAuthDataItem::getSIPItemNumber(){
	if(NULL == mSIPItemNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPItemNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mSIPItemNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSIPItemNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPItemNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSIPItemNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSIPItemNumber->Decode(mspByteArray.get(), mSIPItemNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPItemNumber")     ;
			throw lTssDiaMsgException;
		}
		mSIPItemNumber->mAvpDecodedFlag = true;
	}
	return mSIPItemNumber;
}

OctetString* SIPAuthDataItem::getSIPAuthenticationScheme(){
	if(NULL == mSIPAuthenticationScheme) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPAuthenticationScheme is Null");
		throw lTssDiaMsgException;
	}
	if(!mSIPAuthenticationScheme->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSIPAuthenticationScheme->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPAuthenticationScheme is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSIPAuthenticationScheme->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSIPAuthenticationScheme->Decode(mspByteArray.get(), mSIPAuthenticationScheme->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthenticationScheme")     ;
			throw lTssDiaMsgException;
		}
		mSIPAuthenticationScheme->mAvpDecodedFlag = true;
	}
	return mSIPAuthenticationScheme;
}

OctetString* SIPAuthDataItem::getSIPAuthenticate(){
	if(NULL == mSIPAuthenticate) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPAuthenticate is Null");
		throw lTssDiaMsgException;
	}
	if(!mSIPAuthenticate->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSIPAuthenticate->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPAuthenticate is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSIPAuthenticate->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSIPAuthenticate->Decode(mspByteArray.get(), mSIPAuthenticate->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthenticate")     ;
			throw lTssDiaMsgException;
		}
		mSIPAuthenticate->mAvpDecodedFlag = true;
	}
	return mSIPAuthenticate;
}

OctetString* SIPAuthDataItem::getSIPAuthorization(){
	if(NULL == mSIPAuthorization) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPAuthorization is Null");
		throw lTssDiaMsgException;
	}
	if(!mSIPAuthorization->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSIPAuthorization->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPAuthorization is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSIPAuthorization->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSIPAuthorization->Decode(mspByteArray.get(), mSIPAuthorization->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthorization")     ;
			throw lTssDiaMsgException;
		}
		mSIPAuthorization->mAvpDecodedFlag = true;
	}
	return mSIPAuthorization;
}

OctetString* SIPAuthDataItem::getSIPAuthenticationContext(){
	if(NULL == mSIPAuthenticationContext) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPAuthenticationContext is Null");
		throw lTssDiaMsgException;
	}
	if(!mSIPAuthenticationContext->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSIPAuthenticationContext->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPAuthenticationContext is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSIPAuthenticationContext->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSIPAuthenticationContext->Decode(mspByteArray.get(), mSIPAuthenticationContext->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthenticationContext")     ;
			throw lTssDiaMsgException;
		}
		mSIPAuthenticationContext->mAvpDecodedFlag = true;
	}
	return mSIPAuthenticationContext;
}

OctetString* SIPAuthDataItem::getConfidentialityKey(){
	if(NULL == mConfidentialityKey) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ConfidentialityKey is Null");
		throw lTssDiaMsgException;
	}
	if(!mConfidentialityKey->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mConfidentialityKey->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ConfidentialityKey is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mConfidentialityKey->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mConfidentialityKey->Decode(mspByteArray.get(), mConfidentialityKey->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ConfidentialityKey")     ;
			throw lTssDiaMsgException;
		}
		mConfidentialityKey->mAvpDecodedFlag = true;
	}
	return mConfidentialityKey;
}

OctetString* SIPAuthDataItem::getIntegrityKey(){
	if(NULL == mIntegrityKey) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IntegrityKey is Null");
		throw lTssDiaMsgException;
	}
	if(!mIntegrityKey->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mIntegrityKey->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "IntegrityKey is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mIntegrityKey->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mIntegrityKey->Decode(mspByteArray.get(), mIntegrityKey->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IntegrityKey")     ;
			throw lTssDiaMsgException;
		}
		mIntegrityKey->mAvpDecodedFlag = true;
	}
	return mIntegrityKey;
}

SIPDigestAuthenticate* SIPAuthDataItem::getSIPDigestAuthenticate()
{
	if(mSIPDigestAuthenticateGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPDigestAuthenticate is Null");
		throw lTssDiaMsgException;
	}
	if(!mSIPDigestAuthenticateGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSIPDigestAuthenticateGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SIPDigestAuthenticate is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSIPDigestAuthenticateGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSIPDigestAuthenticateGrp->Decode(mspByteArray.get(), mSIPDigestAuthenticateGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPDigestAuthenticate")     ;
			throw lTssDiaMsgException;
		}
		mSIPDigestAuthenticateGrp->mAvpDecodedFlag = true;
	}
	return mSIPDigestAuthenticateGrp;
}

SIPDigestAuthenticate* SIPAuthDataItem::setSIPDigestAuthenticate(){
	if(mSIPDigestAuthenticateGrp == NULL)
		mSIPDigestAuthenticateGrp = new SIPDigestAuthenticate();
	mTagsPresent[SIPAuthDataItem_SIPDIGESTAUTHENTICATE] = 1;
	return mSIPDigestAuthenticateGrp;
}

void SIPAuthDataItem::resetSIPDigestAuthenticate(){
	mTagsPresent[SIPAuthDataItem_SIPDIGESTAUTHENTICATE] = 0;
	if(mSIPDigestAuthenticateGrp != NULL)
		delete mSIPDigestAuthenticateGrp;
}

OctetString* SIPAuthDataItem::getFramedIPAddress(){
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

OctetString* SIPAuthDataItem::getFramedIPv6Prefix(){
	if(NULL == mFramedIPv6Prefix) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FramedIPv6Prefix is Null");
		throw lTssDiaMsgException;
	}
	if(!mFramedIPv6Prefix->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFramedIPv6Prefix->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FramedIPv6Prefix is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFramedIPv6Prefix->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFramedIPv6Prefix->Decode(mspByteArray.get(), mFramedIPv6Prefix->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FramedIPv6Prefix")     ;
			throw lTssDiaMsgException;
		}
		mFramedIPv6Prefix->mAvpDecodedFlag = true;
	}
	return mFramedIPv6Prefix;
}

Unsigned64* SIPAuthDataItem::getFramedInterfaceId(){
	if(NULL == mFramedInterfaceId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FramedInterfaceId is Null");
		throw lTssDiaMsgException;
	}
	if(!mFramedInterfaceId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFramedInterfaceId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FramedInterfaceId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFramedInterfaceId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFramedInterfaceId->Decode(mspByteArray.get(), mFramedInterfaceId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FramedInterfaceId")     ;
			throw lTssDiaMsgException;
		}
		mFramedInterfaceId->mAvpDecodedFlag = true;
	}
	return mFramedInterfaceId;
}

list<OctetString*>* SIPAuthDataItem::getLineIdentifierList()
{
	if(mLineIdentifierList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LineIdentifier is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mLineIdentifierList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LineIdentifier is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LineIdentifier")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mLineIdentifierList;
}

list<OctetString*>* SIPAuthDataItem::setLineIdentifierList() {
	mTagsPresent[SIPAuthDataItem_LINEIDENTIFIER] = 1;
	if(mLineIdentifierList == NULL)
		mLineIdentifierList = new list<OctetString*>;
	mLineIdentifierList->clear();
	return mLineIdentifierList;
}

void SIPAuthDataItem::resetLineIdentifierList(){
	mTagsPresent[SIPAuthDataItem_LINEIDENTIFIER] = 0;
	if(mLineIdentifierList != NULL)
		delete mLineIdentifierList;
}



int SIPAuthDataItem::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case SIPAuthDataItem_SIPITEMNUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(613);
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
					if(!mSIPItemNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSIPItemNumber->getAvpOffsetLen().first], mSIPItemNumber->getAvpOffsetLen().second);
						array->offset += mSIPItemNumber->getAvpOffsetLen().second;
						array->size += mSIPItemNumber->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPItemNumber");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mSIPItemNumber->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPItemNumber");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPAuthDataItem_SIPAUTHENTICATIONSCHEME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(608);
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
					if(!mSIPAuthenticationScheme->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSIPAuthenticationScheme->getAvpOffsetLen().first], mSIPAuthenticationScheme->getAvpOffsetLen().second);
						array->offset += mSIPAuthenticationScheme->getAvpOffsetLen().second;
						array->size += mSIPAuthenticationScheme->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSIPAuthenticationScheme->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSIPAuthenticationScheme->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPAuthenticationScheme");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSIPAuthenticationScheme->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSIPAuthenticationScheme->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPAuthenticationScheme");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPAuthDataItem_SIPAUTHENTICATE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(609);
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
					if(!mSIPAuthenticate->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSIPAuthenticate->getAvpOffsetLen().first], mSIPAuthenticate->getAvpOffsetLen().second);
						array->offset += mSIPAuthenticate->getAvpOffsetLen().second;
						array->size += mSIPAuthenticate->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSIPAuthenticate->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSIPAuthenticate->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPAuthenticate");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSIPAuthenticate->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSIPAuthenticate->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPAuthenticate");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPAuthDataItem_SIPAUTHORIZATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(610);
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
					if(!mSIPAuthorization->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSIPAuthorization->getAvpOffsetLen().first], mSIPAuthorization->getAvpOffsetLen().second);
						array->offset += mSIPAuthorization->getAvpOffsetLen().second;
						array->size += mSIPAuthorization->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSIPAuthorization->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSIPAuthorization->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPAuthorization");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSIPAuthorization->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSIPAuthorization->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPAuthorization");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPAuthDataItem_SIPAUTHENTICATIONCONTEXT:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(611);
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
					if(!mSIPAuthenticationContext->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSIPAuthenticationContext->getAvpOffsetLen().first], mSIPAuthenticationContext->getAvpOffsetLen().second);
						array->offset += mSIPAuthenticationContext->getAvpOffsetLen().second;
						array->size += mSIPAuthenticationContext->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSIPAuthenticationContext->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSIPAuthenticationContext->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPAuthenticationContext");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSIPAuthenticationContext->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSIPAuthenticationContext->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPAuthenticationContext");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPAuthDataItem_CONFIDENTIALITYKEY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(625);
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
					if(!mConfidentialityKey->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mConfidentialityKey->getAvpOffsetLen().first], mConfidentialityKey->getAvpOffsetLen().second);
						array->offset += mConfidentialityKey->getAvpOffsetLen().second;
						array->size += mConfidentialityKey->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mConfidentialityKey->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mConfidentialityKey->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ConfidentialityKey");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mConfidentialityKey->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mConfidentialityKey->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ConfidentialityKey");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPAuthDataItem_INTEGRITYKEY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(626);
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
					if(!mIntegrityKey->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mIntegrityKey->getAvpOffsetLen().first], mIntegrityKey->getAvpOffsetLen().second);
						array->offset += mIntegrityKey->getAvpOffsetLen().second;
						array->size += mIntegrityKey->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mIntegrityKey->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mIntegrityKey->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IntegrityKey");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mIntegrityKey->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mIntegrityKey->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding IntegrityKey");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPAuthDataItem_SIPDIGESTAUTHENTICATE:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(635);
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
				if((this->getSIPDigestAuthenticate()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SIPDigestAuthenticate");
					throw lTssDiaMsgException;
					}
				}
				break;
			case SIPAuthDataItem_FRAMEDIPADDRESS:
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
			case SIPAuthDataItem_FRAMEDIPV6PREFIX:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(97);
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
					if(!mFramedIPv6Prefix->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFramedIPv6Prefix->getAvpOffsetLen().first], mFramedIPv6Prefix->getAvpOffsetLen().second);
						array->offset += mFramedIPv6Prefix->getAvpOffsetLen().second;
						array->size += mFramedIPv6Prefix->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mFramedIPv6Prefix->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mFramedIPv6Prefix->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FramedIPv6Prefix");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mFramedIPv6Prefix->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mFramedIPv6Prefix->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FramedIPv6Prefix");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPAuthDataItem_FRAMEDINTERFACEID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(96);
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
					if(!mFramedInterfaceId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFramedInterfaceId->getAvpOffsetLen().first], mFramedInterfaceId->getAvpOffsetLen().second);
						array->offset += mFramedInterfaceId->getAvpOffsetLen().second;
						array->size += mFramedInterfaceId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FramedInterfaceId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFramedInterfaceId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FramedInterfaceId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPAuthDataItem_LINEIDENTIFIER:
			{
					if( mLineIdentifierList->size() <= 0) {
						break;
					}

					mLineIdentifierIterator = this->getLineIdentifierList()->begin();
					while(mLineIdentifierIterator != mLineIdentifierList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(500);
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
					if(!(*mLineIdentifierIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mLineIdentifierIterator)->getAvpOffsetLen().first], (*mLineIdentifierIterator)->getAvpOffsetLen().second);
						array->offset += (*mLineIdentifierIterator)->getAvpOffsetLen().second;
						array->size += (*mLineIdentifierIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mLineIdentifierIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mLineIdentifierIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LineIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mLineIdentifierIterator++;
						continue;
					}
						if(((*mLineIdentifierIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mLineIdentifierIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LineIdentifier");
							throw lTssDiaMsgException;
						}
						mLineIdentifierIterator++;
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


int SIPAuthDataItem::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 613:
				{
						mMandatoryAvpSetVal [SIPAuthDataItem_SIPITEMNUMBER] = 1;
					if( NULL == this->setSIPItemNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPItemNumber");
						throw lTssDiaMsgException;
					}
					mSIPItemNumber->setAvpCode(613);
					mSIPItemNumber->setAvpVendorId(lVenderId);
					mSIPItemNumber->SetDataType((DiameterDataType)3);
					mSIPItemNumber->mspByteArray = mspByteArray;
					mSIPItemNumber->mAvpDecodedFlag = false;
					mSIPItemNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 608:
				{
						mMandatoryAvpSetVal [SIPAuthDataItem_SIPAUTHENTICATIONSCHEME] = 1;
					if( NULL == this->setSIPAuthenticationScheme())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthenticationScheme");
						throw lTssDiaMsgException;
					}
					mSIPAuthenticationScheme->setAvpCode(608);
					mSIPAuthenticationScheme->setAvpVendorId(lVenderId);
					mSIPAuthenticationScheme->SetDataType((DiameterDataType)5);
					mSIPAuthenticationScheme->mspByteArray = mspByteArray;
					mSIPAuthenticationScheme->mAvpDecodedFlag = false;
					mSIPAuthenticationScheme->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 609:
				{
						mMandatoryAvpSetVal [SIPAuthDataItem_SIPAUTHENTICATE] = 1;
					if( NULL == this->setSIPAuthenticate())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthenticate");
						throw lTssDiaMsgException;
					}
					mSIPAuthenticate->setAvpCode(609);
					mSIPAuthenticate->setAvpVendorId(lVenderId);
					mSIPAuthenticate->SetDataType((DiameterDataType)5);
					mSIPAuthenticate->mspByteArray = mspByteArray;
					mSIPAuthenticate->mAvpDecodedFlag = false;
					mSIPAuthenticate->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 610:
				{
						mMandatoryAvpSetVal [SIPAuthDataItem_SIPAUTHORIZATION] = 1;
					if( NULL == this->setSIPAuthorization())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthorization");
						throw lTssDiaMsgException;
					}
					mSIPAuthorization->setAvpCode(610);
					mSIPAuthorization->setAvpVendorId(lVenderId);
					mSIPAuthorization->SetDataType((DiameterDataType)5);
					mSIPAuthorization->mspByteArray = mspByteArray;
					mSIPAuthorization->mAvpDecodedFlag = false;
					mSIPAuthorization->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 611:
				{
						mMandatoryAvpSetVal [SIPAuthDataItem_SIPAUTHENTICATIONCONTEXT] = 1;
					if( NULL == this->setSIPAuthenticationContext())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthenticationContext");
						throw lTssDiaMsgException;
					}
					mSIPAuthenticationContext->setAvpCode(611);
					mSIPAuthenticationContext->setAvpVendorId(lVenderId);
					mSIPAuthenticationContext->SetDataType((DiameterDataType)5);
					mSIPAuthenticationContext->mspByteArray = mspByteArray;
					mSIPAuthenticationContext->mAvpDecodedFlag = false;
					mSIPAuthenticationContext->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 625:
				{
						mMandatoryAvpSetVal [SIPAuthDataItem_CONFIDENTIALITYKEY] = 1;
					if( NULL == this->setConfidentialityKey())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ConfidentialityKey");
						throw lTssDiaMsgException;
					}
					mConfidentialityKey->setAvpCode(625);
					mConfidentialityKey->setAvpVendorId(lVenderId);
					mConfidentialityKey->SetDataType((DiameterDataType)5);
					mConfidentialityKey->mspByteArray = mspByteArray;
					mConfidentialityKey->mAvpDecodedFlag = false;
					mConfidentialityKey->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 626:
				{
						mMandatoryAvpSetVal [SIPAuthDataItem_INTEGRITYKEY] = 1;
					if( NULL == this->setIntegrityKey())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding IntegrityKey");
						throw lTssDiaMsgException;
					}
					mIntegrityKey->setAvpCode(626);
					mIntegrityKey->setAvpVendorId(lVenderId);
					mIntegrityKey->SetDataType((DiameterDataType)5);
					mIntegrityKey->mspByteArray = mspByteArray;
					mIntegrityKey->mAvpDecodedFlag = false;
					mIntegrityKey->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 635:
				{
					mTagsPresent[SIPAuthDataItem_SIPDIGESTAUTHENTICATE] = 1;
						if( NULL == this->setSIPDigestAuthenticate()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPDigestAuthenticate");
						throw lTssDiaMsgException;
						}
					mSIPDigestAuthenticateGrp->setAvpCode(635);
					mSIPDigestAuthenticateGrp->SetDataType((DiameterDataType)6);
					mSIPDigestAuthenticateGrp->mspByteArray = mspByteArray;
					mSIPDigestAuthenticateGrp->mAvpDecodedFlag = false;
					mSIPDigestAuthenticateGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mSIPDigestAuthenticateGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 8:
				{
						mMandatoryAvpSetVal [SIPAuthDataItem_FRAMEDIPADDRESS] = 1;
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
			case 97:
				{
						mMandatoryAvpSetVal [SIPAuthDataItem_FRAMEDIPV6PREFIX] = 1;
					if( NULL == this->setFramedIPv6Prefix())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FramedIPv6Prefix");
						throw lTssDiaMsgException;
					}
					mFramedIPv6Prefix->setAvpCode(97);
					mFramedIPv6Prefix->setAvpVendorId(lVenderId);
					mFramedIPv6Prefix->SetDataType((DiameterDataType)5);
					mFramedIPv6Prefix->mspByteArray = mspByteArray;
					mFramedIPv6Prefix->mAvpDecodedFlag = false;
					mFramedIPv6Prefix->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 96:
				{
						mMandatoryAvpSetVal [SIPAuthDataItem_FRAMEDINTERFACEID] = 1;
					if( NULL == this->setFramedInterfaceId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FramedInterfaceId");
						throw lTssDiaMsgException;
					}
					mFramedInterfaceId->setAvpCode(96);
					mFramedInterfaceId->setAvpVendorId(lVenderId);
					mFramedInterfaceId->SetDataType((DiameterDataType)4);
					mFramedInterfaceId->mspByteArray = mspByteArray;
					mFramedInterfaceId->mAvpDecodedFlag = false;
					mFramedInterfaceId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 500:
				{
					mTagsPresent[SIPAuthDataItem_LINEIDENTIFIER] = 1;
					OctetString *lLineIdentifier = new OctetString();
					if( lLineIdentifier == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LineIdentifier");
						throw lTssDiaMsgException;
					}
					lLineIdentifier->setAvpCode(500);
					lLineIdentifier->setAvpVendorId(lVenderId);
					lLineIdentifier->SetDataType((DiameterDataType)5);
					lLineIdentifier->mspByteArray = mspByteArray;
					lLineIdentifier->mAvpDecodedFlag = false;
					lLineIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mLineIdentifierList == NULL)
						this->setLineIdentifierList();
					mLineIdentifierList->push_back(lLineIdentifier);
					
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


DiameterBaseInterface* SIPAuthDataItem::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthDataItem")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 613:
			{
				if(mSIPItemNumber != NULL)
					return mSIPItemNumber->Find(array, avpCode);
				else
					return NULL;
			}
			case 608:
			{
				if(mSIPAuthenticationScheme != NULL)
					return mSIPAuthenticationScheme->Find(array, avpCode);
				else
					return NULL;
			}
			case 609:
			{
				if(mSIPAuthenticate != NULL)
					return mSIPAuthenticate->Find(array, avpCode);
				else
					return NULL;
			}
			case 610:
			{
				if(mSIPAuthorization != NULL)
					return mSIPAuthorization->Find(array, avpCode);
				else
					return NULL;
			}
			case 611:
			{
				if(mSIPAuthenticationContext != NULL)
					return mSIPAuthenticationContext->Find(array, avpCode);
				else
					return NULL;
			}
			case 625:
			{
				if(mConfidentialityKey != NULL)
					return mConfidentialityKey->Find(array, avpCode);
				else
					return NULL;
			}
			case 626:
			{
				if(mIntegrityKey != NULL)
					return mIntegrityKey->Find(array, avpCode);
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
			case 97:
			{
				if(mFramedIPv6Prefix != NULL)
					return mFramedIPv6Prefix->Find(array, avpCode);
				else
					return NULL;
			}
			case 96:
			{
				if(mFramedInterfaceId != NULL)
					return mFramedInterfaceId->Find(array, avpCode);
				else
					return NULL;
			}
			case 500:
			{
				if(mLineIdentifierList != NULL && mLineIdentifierList->size() > 0)
					return (mLineIdentifierList->back())->Find(array, avpCode);
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


BOOLEAN SIPAuthDataItem::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthDataItem")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 613:
			{
				if(mSIPItemNumber != NULL)
				{
					DiameterBaseInterface* inf =  mSIPItemNumber->Find(this->mspByteArray.get(), avpCode);
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
			case 608:
			{
				if(mSIPAuthenticationScheme != NULL)
				{
					DiameterBaseInterface* inf =  mSIPAuthenticationScheme->Find(this->mspByteArray.get(), avpCode);
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
			case 609:
			{
				if(mSIPAuthenticate != NULL)
				{
					DiameterBaseInterface* inf =  mSIPAuthenticate->Find(this->mspByteArray.get(), avpCode);
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
			case 610:
			{
				if(mSIPAuthorization != NULL)
				{
					DiameterBaseInterface* inf =  mSIPAuthorization->Find(this->mspByteArray.get(), avpCode);
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
			case 611:
			{
				if(mSIPAuthenticationContext != NULL)
				{
					DiameterBaseInterface* inf =  mSIPAuthenticationContext->Find(this->mspByteArray.get(), avpCode);
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
			case 625:
			{
				if(mConfidentialityKey != NULL)
				{
					DiameterBaseInterface* inf =  mConfidentialityKey->Find(this->mspByteArray.get(), avpCode);
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
			case 626:
			{
				if(mIntegrityKey != NULL)
				{
					DiameterBaseInterface* inf =  mIntegrityKey->Find(this->mspByteArray.get(), avpCode);
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
			case 635:
			{
				if(mSIPDigestAuthenticateGrp != NULL)
				{
						pBaseInterface.push_back(mSIPDigestAuthenticateGrp);
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
			case 97:
			{
				if(mFramedIPv6Prefix != NULL)
				{
					DiameterBaseInterface* inf =  mFramedIPv6Prefix->Find(this->mspByteArray.get(), avpCode);
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
			case 96:
			{
				if(mFramedInterfaceId != NULL)
				{
					DiameterBaseInterface* inf =  mFramedInterfaceId->Find(this->mspByteArray.get(), avpCode);
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
			case 500:
			{
				if(mLineIdentifierList != NULL)
				{
					for(auto itr = mLineIdentifierList->begin(); itr != mLineIdentifierList->end(); ++itr)
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
std::shared_ptr<byteArray> SIPAuthDataItem::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN SIPAuthDataItem::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPAuthDataItem")     ;
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
			case 613:
			{
				if(mSIPItemNumber != NULL)
				{
					DiameterBaseInterface* inf =  mSIPItemNumber->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 608:
			{
				if(mSIPAuthenticationScheme != NULL)
				{
					DiameterBaseInterface* inf =  mSIPAuthenticationScheme->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 609:
			{
				if(mSIPAuthenticate != NULL)
				{
					DiameterBaseInterface* inf =  mSIPAuthenticate->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 610:
			{
				if(mSIPAuthorization != NULL)
				{
					DiameterBaseInterface* inf =  mSIPAuthorization->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 611:
			{
				if(mSIPAuthenticationContext != NULL)
				{
					DiameterBaseInterface* inf =  mSIPAuthenticationContext->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 625:
			{
				if(mConfidentialityKey != NULL)
				{
					DiameterBaseInterface* inf =  mConfidentialityKey->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 626:
			{
				if(mIntegrityKey != NULL)
				{
					DiameterBaseInterface* inf =  mIntegrityKey->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 635:
			{
				if(mSIPDigestAuthenticateGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mSIPDigestAuthenticateGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mSIPDigestAuthenticateGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
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
			case 97:
			{
				if(mFramedIPv6Prefix != NULL)
				{
					DiameterBaseInterface* inf =  mFramedIPv6Prefix->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 96:
			{
				if(mFramedInterfaceId != NULL)
				{
					DiameterBaseInterface* inf =  mFramedInterfaceId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 500:
			{
				if(mLineIdentifierList != NULL)
				{
					for(auto itr = mLineIdentifierList->begin(); itr != mLineIdentifierList->end(); ++itr)
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


INT32 SIPAuthDataItem::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 SIPAuthDataItem::getAvpCode()
{
	return mAvpCode;
}
INT32 SIPAuthDataItem::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 SIPAuthDataItem::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 SIPAuthDataItem::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> SIPAuthDataItem::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void SIPAuthDataItem::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case SIPAuthDataItem_SIPITEMNUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "613" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SIPItemNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSIPItemNumber()->Display(tab+1);
			}
				break;
			case SIPAuthDataItem_SIPAUTHENTICATIONSCHEME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "608" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SIPAuthenticationScheme" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSIPAuthenticationScheme()->Display(tab+1);
			}
				break;
			case SIPAuthDataItem_SIPAUTHENTICATE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "609" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SIPAuthenticate" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSIPAuthenticate()->Display(tab+1);
			}
				break;
			case SIPAuthDataItem_SIPAUTHORIZATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "610" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SIPAuthorization" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSIPAuthorization()->Display(tab+1);
			}
				break;
			case SIPAuthDataItem_SIPAUTHENTICATIONCONTEXT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "611" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SIPAuthenticationContext" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getSIPAuthenticationContext()->Display(tab+1);
			}
				break;
			case SIPAuthDataItem_CONFIDENTIALITYKEY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "625" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ConfidentialityKey" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getConfidentialityKey()->Display(tab+1);
			}
				break;
			case SIPAuthDataItem_INTEGRITYKEY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "626" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "IntegrityKey" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getIntegrityKey()->Display(tab+1);
			}
				break;
			case SIPAuthDataItem_SIPDIGESTAUTHENTICATE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "635" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SIPDigestAuthenticate" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getSIPDigestAuthenticate()->Display(tab+1);
			}
				break;
			case SIPAuthDataItem_FRAMEDIPADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "8" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FramedIPAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getFramedIPAddress()->Display(tab+1);
			}
				break;
			case SIPAuthDataItem_FRAMEDIPV6PREFIX:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "97" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FramedIPv6Prefix" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getFramedIPv6Prefix()->Display(tab+1);
			}
				break;
			case SIPAuthDataItem_FRAMEDINTERFACEID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "96" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FramedInterfaceId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getFramedInterfaceId()->Display(tab+1);
			}
				break;
			case SIPAuthDataItem_LINEIDENTIFIER:
			{
				if( mLineIdentifierList->size() <= 0) {
					break;
				}

				mLineIdentifierIterator = this->getLineIdentifierList()->begin();
				while(mLineIdentifierIterator != this->getLineIdentifierList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "500" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "LineIdentifier" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mLineIdentifierIterator)->Display(tab+1);
					mLineIdentifierIterator++;

				};

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


BOOLEAN SIPAuthDataItem::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<12> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case SIPAuthDataItem_SIPITEMNUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 613");
				}
				else
					sprintf(lMissingAvpInfo, "%s,613", lMissingAvpInfo);
			}
				break;
			case SIPAuthDataItem_SIPAUTHENTICATIONSCHEME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 608");
				}
				else
					sprintf(lMissingAvpInfo, "%s,608", lMissingAvpInfo);
			}
				break;
			case SIPAuthDataItem_SIPAUTHENTICATE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 609");
				}
				else
					sprintf(lMissingAvpInfo, "%s,609", lMissingAvpInfo);
			}
				break;
			case SIPAuthDataItem_SIPAUTHORIZATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 610");
				}
				else
					sprintf(lMissingAvpInfo, "%s,610", lMissingAvpInfo);
			}
				break;
			case SIPAuthDataItem_SIPAUTHENTICATIONCONTEXT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 611");
				}
				else
					sprintf(lMissingAvpInfo, "%s,611", lMissingAvpInfo);
			}
				break;
			case SIPAuthDataItem_CONFIDENTIALITYKEY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 625");
				}
				else
					sprintf(lMissingAvpInfo, "%s,625", lMissingAvpInfo);
			}
				break;
			case SIPAuthDataItem_INTEGRITYKEY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 626");
				}
				else
					sprintf(lMissingAvpInfo, "%s,626", lMissingAvpInfo);
			}
				break;
			case SIPAuthDataItem_SIPDIGESTAUTHENTICATE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 635");
				}
				else
					sprintf(lMissingAvpInfo, "%s,635", lMissingAvpInfo);
			}
				break;
			case SIPAuthDataItem_FRAMEDIPADDRESS:
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
			case SIPAuthDataItem_FRAMEDIPV6PREFIX:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 97");
				}
				else
					sprintf(lMissingAvpInfo, "%s,97", lMissingAvpInfo);
			}
				break;
			case SIPAuthDataItem_FRAMEDINTERFACEID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 96");
				}
				else
					sprintf(lMissingAvpInfo, "%s,96", lMissingAvpInfo);
			}
				break;
			case SIPAuthDataItem_LINEIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 500");
				}
				else
					sprintf(lMissingAvpInfo, "%s,500", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
