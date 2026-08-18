#include "sd/include/FixedUserLocationInfo.h"

using namespace SD;
BOOLEAN FixedUserLocationInfo::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

FixedUserLocationInfo::FixedUserLocationInfo()
{
	mSSID = NULL;
	mBSSID = NULL;
	mLogicalAccessID = NULL;
	mPhysicalAccessID = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<4>(string("0000"));
	mMandatoryAvpSetVal.reset();
}

FixedUserLocationInfo::~FixedUserLocationInfo()
{
	if(mSSID != NULL)
		delete mSSID;
	if(mBSSID != NULL)
		delete mBSSID;
	if(mLogicalAccessID != NULL)
		delete mLogicalAccessID;
	if(mPhysicalAccessID != NULL)
		delete mPhysicalAccessID;
}

OctetString* FixedUserLocationInfo::setSSID(){
	if(mSSID == NULL)
	{
		mSSID = new OctetString();
		mTagsPresent[FixedUserLocationInfo_SSID] = 1;
		return mSSID;
	}
	return mSSID;
}

void FixedUserLocationInfo::resetSSID(){
	mTagsPresent[FixedUserLocationInfo_SSID] = 0;
	if(mSSID != NULL)
	{
		delete mSSID; 
		mSSID = NULL;
	}
}

OctetString* FixedUserLocationInfo::setBSSID(){
	if(mBSSID == NULL)
	{
		mBSSID = new OctetString();
		mTagsPresent[FixedUserLocationInfo_BSSID] = 1;
		return mBSSID;
	}
	return mBSSID;
}

void FixedUserLocationInfo::resetBSSID(){
	mTagsPresent[FixedUserLocationInfo_BSSID] = 0;
	if(mBSSID != NULL)
	{
		delete mBSSID; 
		mBSSID = NULL;
	}
}

OctetString* FixedUserLocationInfo::setLogicalAccessID(){
	if(mLogicalAccessID == NULL)
	{
		mLogicalAccessID = new OctetString();
		mTagsPresent[FixedUserLocationInfo_LOGICALACCESSID] = 1;
		return mLogicalAccessID;
	}
	return mLogicalAccessID;
}

void FixedUserLocationInfo::resetLogicalAccessID(){
	mTagsPresent[FixedUserLocationInfo_LOGICALACCESSID] = 0;
	if(mLogicalAccessID != NULL)
	{
		delete mLogicalAccessID; 
		mLogicalAccessID = NULL;
	}
}

OctetString* FixedUserLocationInfo::setPhysicalAccessID(){
	if(mPhysicalAccessID == NULL)
	{
		mPhysicalAccessID = new OctetString();
		mTagsPresent[FixedUserLocationInfo_PHYSICALACCESSID] = 1;
		return mPhysicalAccessID;
	}
	return mPhysicalAccessID;
}

void FixedUserLocationInfo::resetPhysicalAccessID(){
	mTagsPresent[FixedUserLocationInfo_PHYSICALACCESSID] = 0;
	if(mPhysicalAccessID != NULL)
	{
		delete mPhysicalAccessID; 
		mPhysicalAccessID = NULL;
	}
}

OctetString* FixedUserLocationInfo::getSSID(){
	if(NULL == mSSID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SSID is Null");
		throw lTssDiaMsgException;
	}
	if(!mSSID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSSID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SSID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSSID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSSID->Decode(mspByteArray.get(), mSSID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SSID")     ;
			throw lTssDiaMsgException;
		}
		mSSID->mAvpDecodedFlag = true;
	}
	return mSSID;
}

OctetString* FixedUserLocationInfo::getBSSID(){
	if(NULL == mBSSID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "BSSID is Null");
		throw lTssDiaMsgException;
	}
	if(!mBSSID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mBSSID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "BSSID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mBSSID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mBSSID->Decode(mspByteArray.get(), mBSSID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding BSSID")     ;
			throw lTssDiaMsgException;
		}
		mBSSID->mAvpDecodedFlag = true;
	}
	return mBSSID;
}

OctetString* FixedUserLocationInfo::getLogicalAccessID(){
	if(NULL == mLogicalAccessID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LogicalAccessID is Null");
		throw lTssDiaMsgException;
	}
	if(!mLogicalAccessID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mLogicalAccessID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LogicalAccessID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mLogicalAccessID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mLogicalAccessID->Decode(mspByteArray.get(), mLogicalAccessID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LogicalAccessID")     ;
			throw lTssDiaMsgException;
		}
		mLogicalAccessID->mAvpDecodedFlag = true;
	}
	return mLogicalAccessID;
}

OctetString* FixedUserLocationInfo::getPhysicalAccessID(){
	if(NULL == mPhysicalAccessID) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PhysicalAccessID is Null");
		throw lTssDiaMsgException;
	}
	if(!mPhysicalAccessID->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPhysicalAccessID->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PhysicalAccessID is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPhysicalAccessID->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPhysicalAccessID->Decode(mspByteArray.get(), mPhysicalAccessID->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PhysicalAccessID")     ;
			throw lTssDiaMsgException;
		}
		mPhysicalAccessID->mAvpDecodedFlag = true;
	}
	return mPhysicalAccessID;
}



int FixedUserLocationInfo::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case FixedUserLocationInfo_SSID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1524);
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
					if(!mSSID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSSID->getAvpOffsetLen().first], mSSID->getAvpOffsetLen().second);
						array->offset += mSSID->getAvpOffsetLen().second;
						array->size += mSSID->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSSID->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSSID->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SSID");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSSID->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSSID->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SSID");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FixedUserLocationInfo_BSSID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2716);
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
					if(!mBSSID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mBSSID->getAvpOffsetLen().first], mBSSID->getAvpOffsetLen().second);
						array->offset += mBSSID->getAvpOffsetLen().second;
						array->size += mBSSID->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mBSSID->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mBSSID->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding BSSID");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mBSSID->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mBSSID->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding BSSID");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FixedUserLocationInfo_LOGICALACCESSID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(302);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=13019;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mLogicalAccessID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mLogicalAccessID->getAvpOffsetLen().first], mLogicalAccessID->getAvpOffsetLen().second);
						array->offset += mLogicalAccessID->getAvpOffsetLen().second;
						array->size += mLogicalAccessID->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mLogicalAccessID->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mLogicalAccessID->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LogicalAccessID");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mLogicalAccessID->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mLogicalAccessID->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LogicalAccessID");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FixedUserLocationInfo_PHYSICALACCESSID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(313);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 128;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(128))
					{ 
						INT32 venderId=13019;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mPhysicalAccessID->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPhysicalAccessID->getAvpOffsetLen().first], mPhysicalAccessID->getAvpOffsetLen().second);
						array->offset += mPhysicalAccessID->getAvpOffsetLen().second;
						array->size += mPhysicalAccessID->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mPhysicalAccessID->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mPhysicalAccessID->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PhysicalAccessID");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mPhysicalAccessID->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mPhysicalAccessID->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PhysicalAccessID");
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


int FixedUserLocationInfo::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1524:
				{
					if( NULL == this->setSSID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SSID");
						throw lTssDiaMsgException;
					}
					mSSID->setAvpCode(1524);
					mSSID->setAvpVendorId(lVenderId);
					mSSID->SetDataType((DiameterDataType)5);
					mSSID->mspByteArray = mspByteArray;
					mSSID->mAvpDecodedFlag = false;
					mSSID->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2716:
				{
					if( NULL == this->setBSSID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding BSSID");
						throw lTssDiaMsgException;
					}
					mBSSID->setAvpCode(2716);
					mBSSID->setAvpVendorId(lVenderId);
					mBSSID->SetDataType((DiameterDataType)5);
					mBSSID->mspByteArray = mspByteArray;
					mBSSID->mAvpDecodedFlag = false;
					mBSSID->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 302:
				{
					if( NULL == this->setLogicalAccessID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LogicalAccessID");
						throw lTssDiaMsgException;
					}
					mLogicalAccessID->setAvpCode(302);
					mLogicalAccessID->setAvpVendorId(lVenderId);
					mLogicalAccessID->SetDataType((DiameterDataType)5);
					mLogicalAccessID->mspByteArray = mspByteArray;
					mLogicalAccessID->mAvpDecodedFlag = false;
					mLogicalAccessID->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 313:
				{
					if( NULL == this->setPhysicalAccessID())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PhysicalAccessID");
						throw lTssDiaMsgException;
					}
					mPhysicalAccessID->setAvpCode(313);
					mPhysicalAccessID->setAvpVendorId(lVenderId);
					mPhysicalAccessID->SetDataType((DiameterDataType)5);
					mPhysicalAccessID->mspByteArray = mspByteArray;
					mPhysicalAccessID->mAvpDecodedFlag = false;
					mPhysicalAccessID->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* FixedUserLocationInfo::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FixedUserLocationInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1524:
			{
				if(mSSID != NULL)
					return mSSID->Find(array, avpCode);
				else
					return NULL;
			}
			case 2716:
			{
				if(mBSSID != NULL)
					return mBSSID->Find(array, avpCode);
				else
					return NULL;
			}
			case 302:
			{
				if(mLogicalAccessID != NULL)
					return mLogicalAccessID->Find(array, avpCode);
				else
					return NULL;
			}
			case 313:
			{
				if(mPhysicalAccessID != NULL)
					return mPhysicalAccessID->Find(array, avpCode);
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


BOOLEAN FixedUserLocationInfo::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FixedUserLocationInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1524:
			{
				if(mSSID != NULL)
				{
					DiameterBaseInterface* inf =  mSSID->Find(this->mspByteArray.get(), avpCode);
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
			case 2716:
			{
				if(mBSSID != NULL)
				{
					DiameterBaseInterface* inf =  mBSSID->Find(this->mspByteArray.get(), avpCode);
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
			case 302:
			{
				if(mLogicalAccessID != NULL)
				{
					DiameterBaseInterface* inf =  mLogicalAccessID->Find(this->mspByteArray.get(), avpCode);
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
			case 313:
			{
				if(mPhysicalAccessID != NULL)
				{
					DiameterBaseInterface* inf =  mPhysicalAccessID->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> FixedUserLocationInfo::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN FixedUserLocationInfo::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FixedUserLocationInfo")     ;
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
			case 1524:
			{
				if(mSSID != NULL)
				{
					DiameterBaseInterface* inf =  mSSID->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2716:
			{
				if(mBSSID != NULL)
				{
					DiameterBaseInterface* inf =  mBSSID->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 302:
			{
				if(mLogicalAccessID != NULL)
				{
					DiameterBaseInterface* inf =  mLogicalAccessID->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 313:
			{
				if(mPhysicalAccessID != NULL)
				{
					DiameterBaseInterface* inf =  mPhysicalAccessID->Find(this->mspByteArray.get(), avpCode);
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


INT32 FixedUserLocationInfo::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 FixedUserLocationInfo::getAvpCode()
{
	return mAvpCode;
}
INT32 FixedUserLocationInfo::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 FixedUserLocationInfo::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 FixedUserLocationInfo::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> FixedUserLocationInfo::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void FixedUserLocationInfo::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case FixedUserLocationInfo_SSID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1524" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SSID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getSSID()->Display(tab+1);
			}
				break;
			case FixedUserLocationInfo_BSSID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2716" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "BSSID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getBSSID()->Display(tab+1);
			}
				break;
			case FixedUserLocationInfo_LOGICALACCESSID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "302" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "LogicalAccessID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getLogicalAccessID()->Display(tab+1);
			}
				break;
			case FixedUserLocationInfo_PHYSICALACCESSID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "313" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PhysicalAccessID" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPhysicalAccessID()->Display(tab+1);
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


BOOLEAN FixedUserLocationInfo::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<4> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case FixedUserLocationInfo_SSID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1524");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1524", lMissingAvpInfo);
			}
				break;
			case FixedUserLocationInfo_BSSID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2716");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2716", lMissingAvpInfo);
			}
				break;
			case FixedUserLocationInfo_LOGICALACCESSID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 302");
				}
				else
					sprintf(lMissingAvpInfo, "%s,302", lMissingAvpInfo);
			}
				break;
			case FixedUserLocationInfo_PHYSICALACCESSID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 313");
				}
				else
					sprintf(lMissingAvpInfo, "%s,313", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
