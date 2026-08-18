#include "rx/include/UserEquipmentInfoExtension.h"

using namespace RX;
BOOLEAN UserEquipmentInfoExtension::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

UserEquipmentInfoExtension::UserEquipmentInfoExtension()
{
	mUserEquipmentInfoIMEISV = NULL;
	mUserEquipmentInfoMAC = NULL;
	mUserEquipmentInfoEUI64 = NULL;
	mUserEquipmentInfoModifiedEUI64 = NULL;
	mUserEquipmentInfoIMEI = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<5>(string("00000"));
	mMandatoryAvpSetVal.reset();
}

UserEquipmentInfoExtension::~UserEquipmentInfoExtension()
{
	if(mUserEquipmentInfoIMEISV != NULL)
		delete mUserEquipmentInfoIMEISV;
	if(mUserEquipmentInfoMAC != NULL)
		delete mUserEquipmentInfoMAC;
	if(mUserEquipmentInfoEUI64 != NULL)
		delete mUserEquipmentInfoEUI64;
	if(mUserEquipmentInfoModifiedEUI64 != NULL)
		delete mUserEquipmentInfoModifiedEUI64;
	if(mUserEquipmentInfoIMEI != NULL)
		delete mUserEquipmentInfoIMEI;
}

OctetString* UserEquipmentInfoExtension::setUserEquipmentInfoIMEISV(){
	if(mUserEquipmentInfoIMEISV == NULL)
	{
		mUserEquipmentInfoIMEISV = new OctetString();
		mTagsPresent[UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEISV] = 1;
		return mUserEquipmentInfoIMEISV;
	}
	return mUserEquipmentInfoIMEISV;
}

void UserEquipmentInfoExtension::resetUserEquipmentInfoIMEISV(){
	mTagsPresent[UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEISV] = 0;
	if(mUserEquipmentInfoIMEISV != NULL)
	{
		delete mUserEquipmentInfoIMEISV; 
		mUserEquipmentInfoIMEISV = NULL;
	}
}

OctetString* UserEquipmentInfoExtension::setUserEquipmentInfoMAC(){
	if(mUserEquipmentInfoMAC == NULL)
	{
		mUserEquipmentInfoMAC = new OctetString();
		mTagsPresent[UserEquipmentInfoExtension_USEREQUIPMENTINFOMAC] = 1;
		return mUserEquipmentInfoMAC;
	}
	return mUserEquipmentInfoMAC;
}

void UserEquipmentInfoExtension::resetUserEquipmentInfoMAC(){
	mTagsPresent[UserEquipmentInfoExtension_USEREQUIPMENTINFOMAC] = 0;
	if(mUserEquipmentInfoMAC != NULL)
	{
		delete mUserEquipmentInfoMAC; 
		mUserEquipmentInfoMAC = NULL;
	}
}

OctetString* UserEquipmentInfoExtension::setUserEquipmentInfoEUI64(){
	if(mUserEquipmentInfoEUI64 == NULL)
	{
		mUserEquipmentInfoEUI64 = new OctetString();
		mTagsPresent[UserEquipmentInfoExtension_USEREQUIPMENTINFOEUI64] = 1;
		return mUserEquipmentInfoEUI64;
	}
	return mUserEquipmentInfoEUI64;
}

void UserEquipmentInfoExtension::resetUserEquipmentInfoEUI64(){
	mTagsPresent[UserEquipmentInfoExtension_USEREQUIPMENTINFOEUI64] = 0;
	if(mUserEquipmentInfoEUI64 != NULL)
	{
		delete mUserEquipmentInfoEUI64; 
		mUserEquipmentInfoEUI64 = NULL;
	}
}

OctetString* UserEquipmentInfoExtension::setUserEquipmentInfoModifiedEUI64(){
	if(mUserEquipmentInfoModifiedEUI64 == NULL)
	{
		mUserEquipmentInfoModifiedEUI64 = new OctetString();
		mTagsPresent[UserEquipmentInfoExtension_USEREQUIPMENTINFOMODIFIEDEUI64] = 1;
		return mUserEquipmentInfoModifiedEUI64;
	}
	return mUserEquipmentInfoModifiedEUI64;
}

void UserEquipmentInfoExtension::resetUserEquipmentInfoModifiedEUI64(){
	mTagsPresent[UserEquipmentInfoExtension_USEREQUIPMENTINFOMODIFIEDEUI64] = 0;
	if(mUserEquipmentInfoModifiedEUI64 != NULL)
	{
		delete mUserEquipmentInfoModifiedEUI64; 
		mUserEquipmentInfoModifiedEUI64 = NULL;
	}
}

OctetString* UserEquipmentInfoExtension::setUserEquipmentInfoIMEI(){
	if(mUserEquipmentInfoIMEI == NULL)
	{
		mUserEquipmentInfoIMEI = new OctetString();
		mTagsPresent[UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEI] = 1;
		return mUserEquipmentInfoIMEI;
	}
	return mUserEquipmentInfoIMEI;
}

void UserEquipmentInfoExtension::resetUserEquipmentInfoIMEI(){
	mTagsPresent[UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEI] = 0;
	if(mUserEquipmentInfoIMEI != NULL)
	{
		delete mUserEquipmentInfoIMEI; 
		mUserEquipmentInfoIMEI = NULL;
	}
}

OctetString* UserEquipmentInfoExtension::getUserEquipmentInfoIMEISV(){
	if(NULL == mUserEquipmentInfoIMEISV) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoIMEISV is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserEquipmentInfoIMEISV->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserEquipmentInfoIMEISV->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoIMEISV is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserEquipmentInfoIMEISV->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserEquipmentInfoIMEISV->Decode(mspByteArray.get(), mUserEquipmentInfoIMEISV->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoIMEISV")     ;
			throw lTssDiaMsgException;
		}
		mUserEquipmentInfoIMEISV->mAvpDecodedFlag = true;
	}
	return mUserEquipmentInfoIMEISV;
}

OctetString* UserEquipmentInfoExtension::getUserEquipmentInfoMAC(){
	if(NULL == mUserEquipmentInfoMAC) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoMAC is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserEquipmentInfoMAC->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserEquipmentInfoMAC->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoMAC is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserEquipmentInfoMAC->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserEquipmentInfoMAC->Decode(mspByteArray.get(), mUserEquipmentInfoMAC->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoMAC")     ;
			throw lTssDiaMsgException;
		}
		mUserEquipmentInfoMAC->mAvpDecodedFlag = true;
	}
	return mUserEquipmentInfoMAC;
}

OctetString* UserEquipmentInfoExtension::getUserEquipmentInfoEUI64(){
	if(NULL == mUserEquipmentInfoEUI64) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoEUI64 is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserEquipmentInfoEUI64->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserEquipmentInfoEUI64->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoEUI64 is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserEquipmentInfoEUI64->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserEquipmentInfoEUI64->Decode(mspByteArray.get(), mUserEquipmentInfoEUI64->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoEUI64")     ;
			throw lTssDiaMsgException;
		}
		mUserEquipmentInfoEUI64->mAvpDecodedFlag = true;
	}
	return mUserEquipmentInfoEUI64;
}

OctetString* UserEquipmentInfoExtension::getUserEquipmentInfoModifiedEUI64(){
	if(NULL == mUserEquipmentInfoModifiedEUI64) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoModifiedEUI64 is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserEquipmentInfoModifiedEUI64->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserEquipmentInfoModifiedEUI64->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoModifiedEUI64 is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserEquipmentInfoModifiedEUI64->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserEquipmentInfoModifiedEUI64->Decode(mspByteArray.get(), mUserEquipmentInfoModifiedEUI64->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoModifiedEUI64")     ;
			throw lTssDiaMsgException;
		}
		mUserEquipmentInfoModifiedEUI64->mAvpDecodedFlag = true;
	}
	return mUserEquipmentInfoModifiedEUI64;
}

OctetString* UserEquipmentInfoExtension::getUserEquipmentInfoIMEI(){
	if(NULL == mUserEquipmentInfoIMEI) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoIMEI is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserEquipmentInfoIMEI->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserEquipmentInfoIMEI->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoIMEI is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserEquipmentInfoIMEI->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserEquipmentInfoIMEI->Decode(mspByteArray.get(), mUserEquipmentInfoIMEI->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoIMEI")     ;
			throw lTssDiaMsgException;
		}
		mUserEquipmentInfoIMEI->mAvpDecodedFlag = true;
	}
	return mUserEquipmentInfoIMEI;
}



int UserEquipmentInfoExtension::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEISV:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(654);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 32;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(32))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mUserEquipmentInfoIMEISV->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUserEquipmentInfoIMEISV->getAvpOffsetLen().first], mUserEquipmentInfoIMEISV->getAvpOffsetLen().second);
						array->offset += mUserEquipmentInfoIMEISV->getAvpOffsetLen().second;
						array->size += mUserEquipmentInfoIMEISV->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUserEquipmentInfoIMEISV->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUserEquipmentInfoIMEISV->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoIMEISV");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUserEquipmentInfoIMEISV->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUserEquipmentInfoIMEISV->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoIMEISV");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOMAC:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(655);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 32;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(32))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mUserEquipmentInfoMAC->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUserEquipmentInfoMAC->getAvpOffsetLen().first], mUserEquipmentInfoMAC->getAvpOffsetLen().second);
						array->offset += mUserEquipmentInfoMAC->getAvpOffsetLen().second;
						array->size += mUserEquipmentInfoMAC->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUserEquipmentInfoMAC->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUserEquipmentInfoMAC->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoMAC");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUserEquipmentInfoMAC->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUserEquipmentInfoMAC->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoMAC");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOEUI64:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(656);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 32;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(32))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mUserEquipmentInfoEUI64->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUserEquipmentInfoEUI64->getAvpOffsetLen().first], mUserEquipmentInfoEUI64->getAvpOffsetLen().second);
						array->offset += mUserEquipmentInfoEUI64->getAvpOffsetLen().second;
						array->size += mUserEquipmentInfoEUI64->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUserEquipmentInfoEUI64->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUserEquipmentInfoEUI64->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoEUI64");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUserEquipmentInfoEUI64->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUserEquipmentInfoEUI64->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoEUI64");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOMODIFIEDEUI64:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(657);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 32;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(32))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mUserEquipmentInfoModifiedEUI64->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUserEquipmentInfoModifiedEUI64->getAvpOffsetLen().first], mUserEquipmentInfoModifiedEUI64->getAvpOffsetLen().second);
						array->offset += mUserEquipmentInfoModifiedEUI64->getAvpOffsetLen().second;
						array->size += mUserEquipmentInfoModifiedEUI64->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUserEquipmentInfoModifiedEUI64->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUserEquipmentInfoModifiedEUI64->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoModifiedEUI64");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUserEquipmentInfoModifiedEUI64->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUserEquipmentInfoModifiedEUI64->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoModifiedEUI64");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEI:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(658);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 32;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(32))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mUserEquipmentInfoIMEI->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUserEquipmentInfoIMEI->getAvpOffsetLen().first], mUserEquipmentInfoIMEI->getAvpOffsetLen().second);
						array->offset += mUserEquipmentInfoIMEI->getAvpOffsetLen().second;
						array->size += mUserEquipmentInfoIMEI->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUserEquipmentInfoIMEI->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUserEquipmentInfoIMEI->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoIMEI");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUserEquipmentInfoIMEI->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUserEquipmentInfoIMEI->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoIMEI");
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


int UserEquipmentInfoExtension::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 654:
				{
					if( NULL == this->setUserEquipmentInfoIMEISV())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoIMEISV");
						throw lTssDiaMsgException;
					}
					mUserEquipmentInfoIMEISV->setAvpCode(654);
					mUserEquipmentInfoIMEISV->setAvpVendorId(lVenderId);
					mUserEquipmentInfoIMEISV->SetDataType((DiameterDataType)5);
					mUserEquipmentInfoIMEISV->mspByteArray = mspByteArray;
					mUserEquipmentInfoIMEISV->mAvpDecodedFlag = false;
					mUserEquipmentInfoIMEISV->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 655:
				{
					if( NULL == this->setUserEquipmentInfoMAC())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoMAC");
						throw lTssDiaMsgException;
					}
					mUserEquipmentInfoMAC->setAvpCode(655);
					mUserEquipmentInfoMAC->setAvpVendorId(lVenderId);
					mUserEquipmentInfoMAC->SetDataType((DiameterDataType)5);
					mUserEquipmentInfoMAC->mspByteArray = mspByteArray;
					mUserEquipmentInfoMAC->mAvpDecodedFlag = false;
					mUserEquipmentInfoMAC->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 656:
				{
					if( NULL == this->setUserEquipmentInfoEUI64())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoEUI64");
						throw lTssDiaMsgException;
					}
					mUserEquipmentInfoEUI64->setAvpCode(656);
					mUserEquipmentInfoEUI64->setAvpVendorId(lVenderId);
					mUserEquipmentInfoEUI64->SetDataType((DiameterDataType)5);
					mUserEquipmentInfoEUI64->mspByteArray = mspByteArray;
					mUserEquipmentInfoEUI64->mAvpDecodedFlag = false;
					mUserEquipmentInfoEUI64->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 657:
				{
					if( NULL == this->setUserEquipmentInfoModifiedEUI64())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoModifiedEUI64");
						throw lTssDiaMsgException;
					}
					mUserEquipmentInfoModifiedEUI64->setAvpCode(657);
					mUserEquipmentInfoModifiedEUI64->setAvpVendorId(lVenderId);
					mUserEquipmentInfoModifiedEUI64->SetDataType((DiameterDataType)5);
					mUserEquipmentInfoModifiedEUI64->mspByteArray = mspByteArray;
					mUserEquipmentInfoModifiedEUI64->mAvpDecodedFlag = false;
					mUserEquipmentInfoModifiedEUI64->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 658:
				{
					if( NULL == this->setUserEquipmentInfoIMEI())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoIMEI");
						throw lTssDiaMsgException;
					}
					mUserEquipmentInfoIMEI->setAvpCode(658);
					mUserEquipmentInfoIMEI->setAvpVendorId(lVenderId);
					mUserEquipmentInfoIMEI->SetDataType((DiameterDataType)5);
					mUserEquipmentInfoIMEI->mspByteArray = mspByteArray;
					mUserEquipmentInfoIMEI->mAvpDecodedFlag = false;
					mUserEquipmentInfoIMEI->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* UserEquipmentInfoExtension::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoExtension")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 654:
			{
				if(mUserEquipmentInfoIMEISV != NULL)
					return mUserEquipmentInfoIMEISV->Find(array, avpCode);
				else
					return NULL;
			}
			case 655:
			{
				if(mUserEquipmentInfoMAC != NULL)
					return mUserEquipmentInfoMAC->Find(array, avpCode);
				else
					return NULL;
			}
			case 656:
			{
				if(mUserEquipmentInfoEUI64 != NULL)
					return mUserEquipmentInfoEUI64->Find(array, avpCode);
				else
					return NULL;
			}
			case 657:
			{
				if(mUserEquipmentInfoModifiedEUI64 != NULL)
					return mUserEquipmentInfoModifiedEUI64->Find(array, avpCode);
				else
					return NULL;
			}
			case 658:
			{
				if(mUserEquipmentInfoIMEI != NULL)
					return mUserEquipmentInfoIMEI->Find(array, avpCode);
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


BOOLEAN UserEquipmentInfoExtension::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoExtension")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 654:
			{
				if(mUserEquipmentInfoIMEISV != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoIMEISV->Find(this->mspByteArray.get(), avpCode);
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
			case 655:
			{
				if(mUserEquipmentInfoMAC != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoMAC->Find(this->mspByteArray.get(), avpCode);
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
			case 656:
			{
				if(mUserEquipmentInfoEUI64 != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoEUI64->Find(this->mspByteArray.get(), avpCode);
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
			case 657:
			{
				if(mUserEquipmentInfoModifiedEUI64 != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoModifiedEUI64->Find(this->mspByteArray.get(), avpCode);
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
			case 658:
			{
				if(mUserEquipmentInfoIMEI != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoIMEI->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> UserEquipmentInfoExtension::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN UserEquipmentInfoExtension::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoExtension")     ;
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
			case 654:
			{
				if(mUserEquipmentInfoIMEISV != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoIMEISV->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 655:
			{
				if(mUserEquipmentInfoMAC != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoMAC->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 656:
			{
				if(mUserEquipmentInfoEUI64 != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoEUI64->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 657:
			{
				if(mUserEquipmentInfoModifiedEUI64 != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoModifiedEUI64->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 658:
			{
				if(mUserEquipmentInfoIMEI != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoIMEI->Find(this->mspByteArray.get(), avpCode);
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


INT32 UserEquipmentInfoExtension::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 UserEquipmentInfoExtension::getAvpCode()
{
	return mAvpCode;
}
INT32 UserEquipmentInfoExtension::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 UserEquipmentInfoExtension::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 UserEquipmentInfoExtension::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> UserEquipmentInfoExtension::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void UserEquipmentInfoExtension::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEISV:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "654" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserEquipmentInfoIMEISV" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getUserEquipmentInfoIMEISV()->Display(tab+1);
			}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOMAC:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "655" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserEquipmentInfoMAC" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getUserEquipmentInfoMAC()->Display(tab+1);
			}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOEUI64:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "656" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserEquipmentInfoEUI64" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getUserEquipmentInfoEUI64()->Display(tab+1);
			}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOMODIFIEDEUI64:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "657" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserEquipmentInfoModifiedEUI64" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getUserEquipmentInfoModifiedEUI64()->Display(tab+1);
			}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEI:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "658" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserEquipmentInfoIMEI" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getUserEquipmentInfoIMEI()->Display(tab+1);
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


BOOLEAN UserEquipmentInfoExtension::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<5> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEISV:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 654");
				}
				else
					sprintf(lMissingAvpInfo, "%s,654", lMissingAvpInfo);
			}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOMAC:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 655");
				}
				else
					sprintf(lMissingAvpInfo, "%s,655", lMissingAvpInfo);
			}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOEUI64:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 656");
				}
				else
					sprintf(lMissingAvpInfo, "%s,656", lMissingAvpInfo);
			}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOMODIFIEDEUI64:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 657");
				}
				else
					sprintf(lMissingAvpInfo, "%s,657", lMissingAvpInfo);
			}
				break;
			case UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEI:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 658");
				}
				else
					sprintf(lMissingAvpInfo, "%s,658", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
