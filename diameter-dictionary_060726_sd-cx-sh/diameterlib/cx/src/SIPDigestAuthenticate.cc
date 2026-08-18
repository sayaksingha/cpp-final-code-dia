#include "cx/include/SIPDigestAuthenticate.h"

using namespace CX;
BOOLEAN SIPDigestAuthenticate::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

SIPDigestAuthenticate::SIPDigestAuthenticate()
{
	mDigestRealm = NULL;
	mDigestAlgorithm = NULL;
	mDigestQoP = NULL;
	mDigestHA1 = NULL;
	mAlternateDigestAlgorithm = NULL;
	mAlternateDigestHA1 = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<6>(string("001111"));
	mMandatoryAvpSetVal.reset();
}

SIPDigestAuthenticate::~SIPDigestAuthenticate()
{
	if(mDigestRealm != NULL)
		delete mDigestRealm;
	if(mDigestAlgorithm != NULL)
		delete mDigestAlgorithm;
	if(mDigestQoP != NULL)
		delete mDigestQoP;
	if(mDigestHA1 != NULL)
		delete mDigestHA1;
	if(mAlternateDigestAlgorithm != NULL)
		delete mAlternateDigestAlgorithm;
	if(mAlternateDigestHA1 != NULL)
		delete mAlternateDigestHA1;
}

OctetString* SIPDigestAuthenticate::setDigestRealm(){
	mMandatoryAvpSetVal [SIPDigestAuthenticate_DIGESTREALM] = 1;
	if(mDigestRealm == NULL)
	{
		mDigestRealm = new OctetString();
		mTagsPresent[SIPDigestAuthenticate_DIGESTREALM] = 1;
		return mDigestRealm;
	}
	return mDigestRealm;
}

void SIPDigestAuthenticate::resetDigestRealm(){
	mTagsPresent[SIPDigestAuthenticate_DIGESTREALM] = 0;
	if(mDigestRealm != NULL)
	{
		delete mDigestRealm; 
		mDigestRealm = NULL;
	}
}

OctetString* SIPDigestAuthenticate::setDigestAlgorithm(){
	mMandatoryAvpSetVal [SIPDigestAuthenticate_DIGESTALGORITHM] = 1;
	if(mDigestAlgorithm == NULL)
	{
		mDigestAlgorithm = new OctetString();
		mTagsPresent[SIPDigestAuthenticate_DIGESTALGORITHM] = 1;
		return mDigestAlgorithm;
	}
	return mDigestAlgorithm;
}

void SIPDigestAuthenticate::resetDigestAlgorithm(){
	mTagsPresent[SIPDigestAuthenticate_DIGESTALGORITHM] = 0;
	if(mDigestAlgorithm != NULL)
	{
		delete mDigestAlgorithm; 
		mDigestAlgorithm = NULL;
	}
}

OctetString* SIPDigestAuthenticate::setDigestQoP(){
	mMandatoryAvpSetVal [SIPDigestAuthenticate_DIGESTQOP] = 1;
	if(mDigestQoP == NULL)
	{
		mDigestQoP = new OctetString();
		mTagsPresent[SIPDigestAuthenticate_DIGESTQOP] = 1;
		return mDigestQoP;
	}
	return mDigestQoP;
}

void SIPDigestAuthenticate::resetDigestQoP(){
	mTagsPresent[SIPDigestAuthenticate_DIGESTQOP] = 0;
	if(mDigestQoP != NULL)
	{
		delete mDigestQoP; 
		mDigestQoP = NULL;
	}
}

OctetString* SIPDigestAuthenticate::setDigestHA1(){
	mMandatoryAvpSetVal [SIPDigestAuthenticate_DIGESTHA1] = 1;
	if(mDigestHA1 == NULL)
	{
		mDigestHA1 = new OctetString();
		mTagsPresent[SIPDigestAuthenticate_DIGESTHA1] = 1;
		return mDigestHA1;
	}
	return mDigestHA1;
}

void SIPDigestAuthenticate::resetDigestHA1(){
	mTagsPresent[SIPDigestAuthenticate_DIGESTHA1] = 0;
	if(mDigestHA1 != NULL)
	{
		delete mDigestHA1; 
		mDigestHA1 = NULL;
	}
}

OctetString* SIPDigestAuthenticate::setAlternateDigestAlgorithm(){
	if(mAlternateDigestAlgorithm == NULL)
	{
		mAlternateDigestAlgorithm = new OctetString();
		mTagsPresent[SIPDigestAuthenticate_ALTERNATEDIGESTALGORITHM] = 1;
		return mAlternateDigestAlgorithm;
	}
	return mAlternateDigestAlgorithm;
}

void SIPDigestAuthenticate::resetAlternateDigestAlgorithm(){
	mTagsPresent[SIPDigestAuthenticate_ALTERNATEDIGESTALGORITHM] = 0;
	if(mAlternateDigestAlgorithm != NULL)
	{
		delete mAlternateDigestAlgorithm; 
		mAlternateDigestAlgorithm = NULL;
	}
}

OctetString* SIPDigestAuthenticate::setAlternateDigestHA1(){
	if(mAlternateDigestHA1 == NULL)
	{
		mAlternateDigestHA1 = new OctetString();
		mTagsPresent[SIPDigestAuthenticate_ALTERNATEDIGESTHA1] = 1;
		return mAlternateDigestHA1;
	}
	return mAlternateDigestHA1;
}

void SIPDigestAuthenticate::resetAlternateDigestHA1(){
	mTagsPresent[SIPDigestAuthenticate_ALTERNATEDIGESTHA1] = 0;
	if(mAlternateDigestHA1 != NULL)
	{
		delete mAlternateDigestHA1; 
		mAlternateDigestHA1 = NULL;
	}
}

OctetString* SIPDigestAuthenticate::getDigestRealm(){
	if(NULL == mDigestRealm) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DigestRealm is Null");
		throw lTssDiaMsgException;
	}
	if(!mDigestRealm->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mDigestRealm->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DigestRealm is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mDigestRealm->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mDigestRealm->Decode(mspByteArray.get(), mDigestRealm->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DigestRealm")     ;
			throw lTssDiaMsgException;
		}
		mDigestRealm->mAvpDecodedFlag = true;
	}
	return mDigestRealm;
}

OctetString* SIPDigestAuthenticate::getDigestAlgorithm(){
	if(NULL == mDigestAlgorithm) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DigestAlgorithm is Null");
		throw lTssDiaMsgException;
	}
	if(!mDigestAlgorithm->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mDigestAlgorithm->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DigestAlgorithm is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mDigestAlgorithm->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mDigestAlgorithm->Decode(mspByteArray.get(), mDigestAlgorithm->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DigestAlgorithm")     ;
			throw lTssDiaMsgException;
		}
		mDigestAlgorithm->mAvpDecodedFlag = true;
	}
	return mDigestAlgorithm;
}

OctetString* SIPDigestAuthenticate::getDigestQoP(){
	if(NULL == mDigestQoP) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DigestQoP is Null");
		throw lTssDiaMsgException;
	}
	if(!mDigestQoP->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mDigestQoP->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DigestQoP is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mDigestQoP->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mDigestQoP->Decode(mspByteArray.get(), mDigestQoP->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DigestQoP")     ;
			throw lTssDiaMsgException;
		}
		mDigestQoP->mAvpDecodedFlag = true;
	}
	return mDigestQoP;
}

OctetString* SIPDigestAuthenticate::getDigestHA1(){
	if(NULL == mDigestHA1) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DigestHA1 is Null");
		throw lTssDiaMsgException;
	}
	if(!mDigestHA1->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mDigestHA1->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "DigestHA1 is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mDigestHA1->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mDigestHA1->Decode(mspByteArray.get(), mDigestHA1->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DigestHA1")     ;
			throw lTssDiaMsgException;
		}
		mDigestHA1->mAvpDecodedFlag = true;
	}
	return mDigestHA1;
}

OctetString* SIPDigestAuthenticate::getAlternateDigestAlgorithm(){
	if(NULL == mAlternateDigestAlgorithm) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AlternateDigestAlgorithm is Null");
		throw lTssDiaMsgException;
	}
	if(!mAlternateDigestAlgorithm->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAlternateDigestAlgorithm->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AlternateDigestAlgorithm is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAlternateDigestAlgorithm->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAlternateDigestAlgorithm->Decode(mspByteArray.get(), mAlternateDigestAlgorithm->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AlternateDigestAlgorithm")     ;
			throw lTssDiaMsgException;
		}
		mAlternateDigestAlgorithm->mAvpDecodedFlag = true;
	}
	return mAlternateDigestAlgorithm;
}

OctetString* SIPDigestAuthenticate::getAlternateDigestHA1(){
	if(NULL == mAlternateDigestHA1) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AlternateDigestHA1 is Null");
		throw lTssDiaMsgException;
	}
	if(!mAlternateDigestHA1->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAlternateDigestHA1->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AlternateDigestHA1 is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAlternateDigestHA1->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAlternateDigestHA1->Decode(mspByteArray.get(), mAlternateDigestHA1->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AlternateDigestHA1")     ;
			throw lTssDiaMsgException;
		}
		mAlternateDigestHA1->mAvpDecodedFlag = true;
	}
	return mAlternateDigestHA1;
}



int SIPDigestAuthenticate::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case SIPDigestAuthenticate_DIGESTREALM:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(104);
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
					if(!mDigestRealm->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mDigestRealm->getAvpOffsetLen().first], mDigestRealm->getAvpOffsetLen().second);
						array->offset += mDigestRealm->getAvpOffsetLen().second;
						array->size += mDigestRealm->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mDigestRealm->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mDigestRealm->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DigestRealm");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mDigestRealm->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mDigestRealm->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DigestRealm");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPDigestAuthenticate_DIGESTALGORITHM:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(111);
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
					if(!mDigestAlgorithm->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mDigestAlgorithm->getAvpOffsetLen().first], mDigestAlgorithm->getAvpOffsetLen().second);
						array->offset += mDigestAlgorithm->getAvpOffsetLen().second;
						array->size += mDigestAlgorithm->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mDigestAlgorithm->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mDigestAlgorithm->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DigestAlgorithm");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mDigestAlgorithm->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mDigestAlgorithm->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DigestAlgorithm");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPDigestAuthenticate_DIGESTQOP:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(110);
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
					if(!mDigestQoP->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mDigestQoP->getAvpOffsetLen().first], mDigestQoP->getAvpOffsetLen().second);
						array->offset += mDigestQoP->getAvpOffsetLen().second;
						array->size += mDigestQoP->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mDigestQoP->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mDigestQoP->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DigestQoP");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mDigestQoP->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mDigestQoP->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DigestQoP");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPDigestAuthenticate_DIGESTHA1:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(121);
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
					if(!mDigestHA1->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mDigestHA1->getAvpOffsetLen().first], mDigestHA1->getAvpOffsetLen().second);
						array->offset += mDigestHA1->getAvpOffsetLen().second;
						array->size += mDigestHA1->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mDigestHA1->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mDigestHA1->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DigestHA1");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mDigestHA1->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mDigestHA1->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding DigestHA1");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPDigestAuthenticate_ALTERNATEDIGESTALGORITHM:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(662);
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
					if(!mAlternateDigestAlgorithm->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAlternateDigestAlgorithm->getAvpOffsetLen().first], mAlternateDigestAlgorithm->getAvpOffsetLen().second);
						array->offset += mAlternateDigestAlgorithm->getAvpOffsetLen().second;
						array->size += mAlternateDigestAlgorithm->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mAlternateDigestAlgorithm->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mAlternateDigestAlgorithm->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AlternateDigestAlgorithm");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mAlternateDigestAlgorithm->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mAlternateDigestAlgorithm->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AlternateDigestAlgorithm");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SIPDigestAuthenticate_ALTERNATEDIGESTHA1:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(663);
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
					if(!mAlternateDigestHA1->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAlternateDigestHA1->getAvpOffsetLen().first], mAlternateDigestHA1->getAvpOffsetLen().second);
						array->offset += mAlternateDigestHA1->getAvpOffsetLen().second;
						array->size += mAlternateDigestHA1->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mAlternateDigestHA1->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mAlternateDigestHA1->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AlternateDigestHA1");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mAlternateDigestHA1->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mAlternateDigestHA1->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AlternateDigestHA1");
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


int SIPDigestAuthenticate::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 104:
				{
						mMandatoryAvpSetVal [SIPDigestAuthenticate_DIGESTREALM] = 1;
					if( NULL == this->setDigestRealm())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DigestRealm");
						throw lTssDiaMsgException;
					}
					mDigestRealm->setAvpCode(104);
					mDigestRealm->setAvpVendorId(lVenderId);
					mDigestRealm->SetDataType((DiameterDataType)5);
					mDigestRealm->mspByteArray = mspByteArray;
					mDigestRealm->mAvpDecodedFlag = false;
					mDigestRealm->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 111:
				{
						mMandatoryAvpSetVal [SIPDigestAuthenticate_DIGESTALGORITHM] = 1;
					if( NULL == this->setDigestAlgorithm())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DigestAlgorithm");
						throw lTssDiaMsgException;
					}
					mDigestAlgorithm->setAvpCode(111);
					mDigestAlgorithm->setAvpVendorId(lVenderId);
					mDigestAlgorithm->SetDataType((DiameterDataType)5);
					mDigestAlgorithm->mspByteArray = mspByteArray;
					mDigestAlgorithm->mAvpDecodedFlag = false;
					mDigestAlgorithm->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 110:
				{
						mMandatoryAvpSetVal [SIPDigestAuthenticate_DIGESTQOP] = 1;
					if( NULL == this->setDigestQoP())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DigestQoP");
						throw lTssDiaMsgException;
					}
					mDigestQoP->setAvpCode(110);
					mDigestQoP->setAvpVendorId(lVenderId);
					mDigestQoP->SetDataType((DiameterDataType)5);
					mDigestQoP->mspByteArray = mspByteArray;
					mDigestQoP->mAvpDecodedFlag = false;
					mDigestQoP->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 121:
				{
						mMandatoryAvpSetVal [SIPDigestAuthenticate_DIGESTHA1] = 1;
					if( NULL == this->setDigestHA1())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DigestHA1");
						throw lTssDiaMsgException;
					}
					mDigestHA1->setAvpCode(121);
					mDigestHA1->setAvpVendorId(lVenderId);
					mDigestHA1->SetDataType((DiameterDataType)5);
					mDigestHA1->mspByteArray = mspByteArray;
					mDigestHA1->mAvpDecodedFlag = false;
					mDigestHA1->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 662:
				{
					if( NULL == this->setAlternateDigestAlgorithm())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AlternateDigestAlgorithm");
						throw lTssDiaMsgException;
					}
					mAlternateDigestAlgorithm->setAvpCode(662);
					mAlternateDigestAlgorithm->setAvpVendorId(lVenderId);
					mAlternateDigestAlgorithm->SetDataType((DiameterDataType)5);
					mAlternateDigestAlgorithm->mspByteArray = mspByteArray;
					mAlternateDigestAlgorithm->mAvpDecodedFlag = false;
					mAlternateDigestAlgorithm->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 663:
				{
					if( NULL == this->setAlternateDigestHA1())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AlternateDigestHA1");
						throw lTssDiaMsgException;
					}
					mAlternateDigestHA1->setAvpCode(663);
					mAlternateDigestHA1->setAvpVendorId(lVenderId);
					mAlternateDigestHA1->SetDataType((DiameterDataType)5);
					mAlternateDigestHA1->mspByteArray = mspByteArray;
					mAlternateDigestHA1->mAvpDecodedFlag = false;
					mAlternateDigestHA1->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* SIPDigestAuthenticate::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPDigestAuthenticate")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 104:
			{
				if(mDigestRealm != NULL)
					return mDigestRealm->Find(array, avpCode);
				else
					return NULL;
			}
			case 111:
			{
				if(mDigestAlgorithm != NULL)
					return mDigestAlgorithm->Find(array, avpCode);
				else
					return NULL;
			}
			case 110:
			{
				if(mDigestQoP != NULL)
					return mDigestQoP->Find(array, avpCode);
				else
					return NULL;
			}
			case 121:
			{
				if(mDigestHA1 != NULL)
					return mDigestHA1->Find(array, avpCode);
				else
					return NULL;
			}
			case 662:
			{
				if(mAlternateDigestAlgorithm != NULL)
					return mAlternateDigestAlgorithm->Find(array, avpCode);
				else
					return NULL;
			}
			case 663:
			{
				if(mAlternateDigestHA1 != NULL)
					return mAlternateDigestHA1->Find(array, avpCode);
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


BOOLEAN SIPDigestAuthenticate::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPDigestAuthenticate")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 104:
			{
				if(mDigestRealm != NULL)
				{
					DiameterBaseInterface* inf =  mDigestRealm->Find(this->mspByteArray.get(), avpCode);
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
			case 111:
			{
				if(mDigestAlgorithm != NULL)
				{
					DiameterBaseInterface* inf =  mDigestAlgorithm->Find(this->mspByteArray.get(), avpCode);
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
			case 110:
			{
				if(mDigestQoP != NULL)
				{
					DiameterBaseInterface* inf =  mDigestQoP->Find(this->mspByteArray.get(), avpCode);
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
			case 121:
			{
				if(mDigestHA1 != NULL)
				{
					DiameterBaseInterface* inf =  mDigestHA1->Find(this->mspByteArray.get(), avpCode);
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
			case 662:
			{
				if(mAlternateDigestAlgorithm != NULL)
				{
					DiameterBaseInterface* inf =  mAlternateDigestAlgorithm->Find(this->mspByteArray.get(), avpCode);
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
			case 663:
			{
				if(mAlternateDigestHA1 != NULL)
				{
					DiameterBaseInterface* inf =  mAlternateDigestHA1->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> SIPDigestAuthenticate::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN SIPDigestAuthenticate::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SIPDigestAuthenticate")     ;
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
			case 104:
			{
				if(mDigestRealm != NULL)
				{
					DiameterBaseInterface* inf =  mDigestRealm->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 111:
			{
				if(mDigestAlgorithm != NULL)
				{
					DiameterBaseInterface* inf =  mDigestAlgorithm->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 110:
			{
				if(mDigestQoP != NULL)
				{
					DiameterBaseInterface* inf =  mDigestQoP->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 121:
			{
				if(mDigestHA1 != NULL)
				{
					DiameterBaseInterface* inf =  mDigestHA1->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 662:
			{
				if(mAlternateDigestAlgorithm != NULL)
				{
					DiameterBaseInterface* inf =  mAlternateDigestAlgorithm->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 663:
			{
				if(mAlternateDigestHA1 != NULL)
				{
					DiameterBaseInterface* inf =  mAlternateDigestHA1->Find(this->mspByteArray.get(), avpCode);
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


INT32 SIPDigestAuthenticate::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 SIPDigestAuthenticate::getAvpCode()
{
	return mAvpCode;
}
INT32 SIPDigestAuthenticate::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 SIPDigestAuthenticate::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 SIPDigestAuthenticate::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> SIPDigestAuthenticate::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void SIPDigestAuthenticate::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case SIPDigestAuthenticate_DIGESTREALM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "104" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DigestRealm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDigestRealm()->Display(tab+1);
			}
				break;
			case SIPDigestAuthenticate_DIGESTALGORITHM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "111" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DigestAlgorithm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDigestAlgorithm()->Display(tab+1);
			}
				break;
			case SIPDigestAuthenticate_DIGESTQOP:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "110" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DigestQoP" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDigestQoP()->Display(tab+1);
			}
				break;
			case SIPDigestAuthenticate_DIGESTHA1:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "121" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "DigestHA1" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getDigestHA1()->Display(tab+1);
			}
				break;
			case SIPDigestAuthenticate_ALTERNATEDIGESTALGORITHM:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "662" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AlternateDigestAlgorithm" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getAlternateDigestAlgorithm()->Display(tab+1);
			}
				break;
			case SIPDigestAuthenticate_ALTERNATEDIGESTHA1:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "663" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AlternateDigestHA1" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getAlternateDigestHA1()->Display(tab+1);
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


BOOLEAN SIPDigestAuthenticate::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<6> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case SIPDigestAuthenticate_DIGESTREALM:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 104");
				}
				else
					sprintf(lMissingAvpInfo, "%s,104", lMissingAvpInfo);
			}
				break;
			case SIPDigestAuthenticate_DIGESTALGORITHM:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 111");
				}
				else
					sprintf(lMissingAvpInfo, "%s,111", lMissingAvpInfo);
			}
				break;
			case SIPDigestAuthenticate_DIGESTQOP:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 110");
				}
				else
					sprintf(lMissingAvpInfo, "%s,110", lMissingAvpInfo);
			}
				break;
			case SIPDigestAuthenticate_DIGESTHA1:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 121");
				}
				else
					sprintf(lMissingAvpInfo, "%s,121", lMissingAvpInfo);
			}
				break;
			case SIPDigestAuthenticate_ALTERNATEDIGESTALGORITHM:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 662");
				}
				else
					sprintf(lMissingAvpInfo, "%s,662", lMissingAvpInfo);
			}
				break;
			case SIPDigestAuthenticate_ALTERNATEDIGESTHA1:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 663");
				}
				else
					sprintf(lMissingAvpInfo, "%s,663", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
