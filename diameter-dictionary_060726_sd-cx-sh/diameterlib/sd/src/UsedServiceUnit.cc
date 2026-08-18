#include "sd/include/UsedServiceUnit.h"

using namespace SD;
BOOLEAN UsedServiceUnit::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

UsedServiceUnit::UsedServiceUnit()
{
	mCCTotalOctets = NULL;
	mCCInputOctets = NULL;
	mCCOutputOctets = NULL;
	mCCTime = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<4>(string("1111"));
	mMandatoryAvpSetVal.reset();
}

UsedServiceUnit::~UsedServiceUnit()
{
	if(mCCTotalOctets != NULL)
		delete mCCTotalOctets;
	if(mCCInputOctets != NULL)
		delete mCCInputOctets;
	if(mCCOutputOctets != NULL)
		delete mCCOutputOctets;
	if(mCCTime != NULL)
		delete mCCTime;
}

Unsigned64* UsedServiceUnit::setCCTotalOctets(){
	mMandatoryAvpSetVal [UsedServiceUnit_CCTOTALOCTETS] = 1;
	if(mCCTotalOctets == NULL)
	{
		mCCTotalOctets = new Unsigned64();
		mTagsPresent[UsedServiceUnit_CCTOTALOCTETS] = 1;
		return mCCTotalOctets;
	}
	return mCCTotalOctets;
}

void UsedServiceUnit::resetCCTotalOctets(){
	mTagsPresent[UsedServiceUnit_CCTOTALOCTETS] = 0;
	if(mCCTotalOctets != NULL)
	{
		delete mCCTotalOctets; 
		mCCTotalOctets = NULL;
	}
}

Unsigned64* UsedServiceUnit::setCCInputOctets(){
	mMandatoryAvpSetVal [UsedServiceUnit_CCINPUTOCTETS] = 1;
	if(mCCInputOctets == NULL)
	{
		mCCInputOctets = new Unsigned64();
		mTagsPresent[UsedServiceUnit_CCINPUTOCTETS] = 1;
		return mCCInputOctets;
	}
	return mCCInputOctets;
}

void UsedServiceUnit::resetCCInputOctets(){
	mTagsPresent[UsedServiceUnit_CCINPUTOCTETS] = 0;
	if(mCCInputOctets != NULL)
	{
		delete mCCInputOctets; 
		mCCInputOctets = NULL;
	}
}

Unsigned64* UsedServiceUnit::setCCOutputOctets(){
	mMandatoryAvpSetVal [UsedServiceUnit_CCOUTPUTOCTETS] = 1;
	if(mCCOutputOctets == NULL)
	{
		mCCOutputOctets = new Unsigned64();
		mTagsPresent[UsedServiceUnit_CCOUTPUTOCTETS] = 1;
		return mCCOutputOctets;
	}
	return mCCOutputOctets;
}

void UsedServiceUnit::resetCCOutputOctets(){
	mTagsPresent[UsedServiceUnit_CCOUTPUTOCTETS] = 0;
	if(mCCOutputOctets != NULL)
	{
		delete mCCOutputOctets; 
		mCCOutputOctets = NULL;
	}
}

Unsigned32* UsedServiceUnit::setCCTime(){
	mMandatoryAvpSetVal [UsedServiceUnit_CCTIME] = 1;
	if(mCCTime == NULL)
	{
		mCCTime = new Unsigned32();
		mTagsPresent[UsedServiceUnit_CCTIME] = 1;
		return mCCTime;
	}
	return mCCTime;
}

void UsedServiceUnit::resetCCTime(){
	mTagsPresent[UsedServiceUnit_CCTIME] = 0;
	if(mCCTime != NULL)
	{
		delete mCCTime; 
		mCCTime = NULL;
	}
}

Unsigned64* UsedServiceUnit::getCCTotalOctets(){
	if(NULL == mCCTotalOctets) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCTotalOctets is Null");
		throw lTssDiaMsgException;
	}
	if(!mCCTotalOctets->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCCTotalOctets->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCTotalOctets is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCCTotalOctets->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCCTotalOctets->Decode(mspByteArray.get(), mCCTotalOctets->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCTotalOctets")     ;
			throw lTssDiaMsgException;
		}
		mCCTotalOctets->mAvpDecodedFlag = true;
	}
	return mCCTotalOctets;
}

Unsigned64* UsedServiceUnit::getCCInputOctets(){
	if(NULL == mCCInputOctets) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCInputOctets is Null");
		throw lTssDiaMsgException;
	}
	if(!mCCInputOctets->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCCInputOctets->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCInputOctets is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCCInputOctets->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCCInputOctets->Decode(mspByteArray.get(), mCCInputOctets->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCInputOctets")     ;
			throw lTssDiaMsgException;
		}
		mCCInputOctets->mAvpDecodedFlag = true;
	}
	return mCCInputOctets;
}

Unsigned64* UsedServiceUnit::getCCOutputOctets(){
	if(NULL == mCCOutputOctets) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCOutputOctets is Null");
		throw lTssDiaMsgException;
	}
	if(!mCCOutputOctets->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCCOutputOctets->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCOutputOctets is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCCOutputOctets->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCCOutputOctets->Decode(mspByteArray.get(), mCCOutputOctets->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCOutputOctets")     ;
			throw lTssDiaMsgException;
		}
		mCCOutputOctets->mAvpDecodedFlag = true;
	}
	return mCCOutputOctets;
}

Unsigned32* UsedServiceUnit::getCCTime(){
	if(NULL == mCCTime) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCTime is Null");
		throw lTssDiaMsgException;
	}
	if(!mCCTime->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCCTime->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CCTime is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCCTime->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCCTime->Decode(mspByteArray.get(), mCCTime->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCTime")     ;
			throw lTssDiaMsgException;
		}
		mCCTime->mAvpDecodedFlag = true;
	}
	return mCCTime;
}



int UsedServiceUnit::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case UsedServiceUnit_CCTOTALOCTETS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(421);
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
					if(!mCCTotalOctets->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCCTotalOctets->getAvpOffsetLen().first], mCCTotalOctets->getAvpOffsetLen().second);
						array->offset += mCCTotalOctets->getAvpOffsetLen().second;
						array->size += mCCTotalOctets->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCTotalOctets");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCCTotalOctets->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCTotalOctets");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UsedServiceUnit_CCINPUTOCTETS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(412);
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
					if(!mCCInputOctets->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCCInputOctets->getAvpOffsetLen().first], mCCInputOctets->getAvpOffsetLen().second);
						array->offset += mCCInputOctets->getAvpOffsetLen().second;
						array->size += mCCInputOctets->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCInputOctets");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCCInputOctets->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCInputOctets");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UsedServiceUnit_CCOUTPUTOCTETS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(414);
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
					if(!mCCOutputOctets->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCCOutputOctets->getAvpOffsetLen().first], mCCOutputOctets->getAvpOffsetLen().second);
						array->offset += mCCOutputOctets->getAvpOffsetLen().second;
						array->size += mCCOutputOctets->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCOutputOctets");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCCOutputOctets->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCOutputOctets");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UsedServiceUnit_CCTIME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(420);
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
					if(!mCCTime->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCCTime->getAvpOffsetLen().first], mCCTime->getAvpOffsetLen().second);
						array->offset += mCCTime->getAvpOffsetLen().second;
						array->size += mCCTime->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCTime");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCCTime->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CCTime");
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


int UsedServiceUnit::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 421:
				{
						mMandatoryAvpSetVal [UsedServiceUnit_CCTOTALOCTETS] = 1;
					if( NULL == this->setCCTotalOctets())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCTotalOctets");
						throw lTssDiaMsgException;
					}
					mCCTotalOctets->setAvpCode(421);
					mCCTotalOctets->setAvpVendorId(lVenderId);
					mCCTotalOctets->SetDataType((DiameterDataType)4);
					mCCTotalOctets->mspByteArray = mspByteArray;
					mCCTotalOctets->mAvpDecodedFlag = false;
					mCCTotalOctets->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 412:
				{
						mMandatoryAvpSetVal [UsedServiceUnit_CCINPUTOCTETS] = 1;
					if( NULL == this->setCCInputOctets())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCInputOctets");
						throw lTssDiaMsgException;
					}
					mCCInputOctets->setAvpCode(412);
					mCCInputOctets->setAvpVendorId(lVenderId);
					mCCInputOctets->SetDataType((DiameterDataType)4);
					mCCInputOctets->mspByteArray = mspByteArray;
					mCCInputOctets->mAvpDecodedFlag = false;
					mCCInputOctets->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 414:
				{
						mMandatoryAvpSetVal [UsedServiceUnit_CCOUTPUTOCTETS] = 1;
					if( NULL == this->setCCOutputOctets())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCOutputOctets");
						throw lTssDiaMsgException;
					}
					mCCOutputOctets->setAvpCode(414);
					mCCOutputOctets->setAvpVendorId(lVenderId);
					mCCOutputOctets->SetDataType((DiameterDataType)4);
					mCCOutputOctets->mspByteArray = mspByteArray;
					mCCOutputOctets->mAvpDecodedFlag = false;
					mCCOutputOctets->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 420:
				{
						mMandatoryAvpSetVal [UsedServiceUnit_CCTIME] = 1;
					if( NULL == this->setCCTime())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCTime");
						throw lTssDiaMsgException;
					}
					mCCTime->setAvpCode(420);
					mCCTime->setAvpVendorId(lVenderId);
					mCCTime->SetDataType((DiameterDataType)3);
					mCCTime->mspByteArray = mspByteArray;
					mCCTime->mAvpDecodedFlag = false;
					mCCTime->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* UsedServiceUnit::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsedServiceUnit")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 421:
			{
				if(mCCTotalOctets != NULL)
					return mCCTotalOctets->Find(array, avpCode);
				else
					return NULL;
			}
			case 412:
			{
				if(mCCInputOctets != NULL)
					return mCCInputOctets->Find(array, avpCode);
				else
					return NULL;
			}
			case 414:
			{
				if(mCCOutputOctets != NULL)
					return mCCOutputOctets->Find(array, avpCode);
				else
					return NULL;
			}
			case 420:
			{
				if(mCCTime != NULL)
					return mCCTime->Find(array, avpCode);
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


BOOLEAN UsedServiceUnit::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsedServiceUnit")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 421:
			{
				if(mCCTotalOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCTotalOctets->Find(this->mspByteArray.get(), avpCode);
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
			case 412:
			{
				if(mCCInputOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCInputOctets->Find(this->mspByteArray.get(), avpCode);
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
			case 414:
			{
				if(mCCOutputOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCOutputOctets->Find(this->mspByteArray.get(), avpCode);
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
			case 420:
			{
				if(mCCTime != NULL)
				{
					DiameterBaseInterface* inf =  mCCTime->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> UsedServiceUnit::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN UsedServiceUnit::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsedServiceUnit")     ;
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
			case 421:
			{
				if(mCCTotalOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCTotalOctets->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 412:
			{
				if(mCCInputOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCInputOctets->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 414:
			{
				if(mCCOutputOctets != NULL)
				{
					DiameterBaseInterface* inf =  mCCOutputOctets->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 420:
			{
				if(mCCTime != NULL)
				{
					DiameterBaseInterface* inf =  mCCTime->Find(this->mspByteArray.get(), avpCode);
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


INT32 UsedServiceUnit::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 UsedServiceUnit::getAvpCode()
{
	return mAvpCode;
}
INT32 UsedServiceUnit::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 UsedServiceUnit::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 UsedServiceUnit::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> UsedServiceUnit::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void UsedServiceUnit::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case UsedServiceUnit_CCTOTALOCTETS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "421" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCTotalOctets" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getCCTotalOctets()->Display(tab+1);
			}
				break;
			case UsedServiceUnit_CCINPUTOCTETS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "412" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCInputOctets" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getCCInputOctets()->Display(tab+1);
			}
				break;
			case UsedServiceUnit_CCOUTPUTOCTETS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "414" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCOutputOctets" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getCCOutputOctets()->Display(tab+1);
			}
				break;
			case UsedServiceUnit_CCTIME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "420" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CCTime" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getCCTime()->Display(tab+1);
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


BOOLEAN UsedServiceUnit::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<4> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case UsedServiceUnit_CCTOTALOCTETS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 421");
				}
				else
					sprintf(lMissingAvpInfo, "%s,421", lMissingAvpInfo);
			}
				break;
			case UsedServiceUnit_CCINPUTOCTETS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 412");
				}
				else
					sprintf(lMissingAvpInfo, "%s,412", lMissingAvpInfo);
			}
				break;
			case UsedServiceUnit_CCOUTPUTOCTETS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 414");
				}
				else
					sprintf(lMissingAvpInfo, "%s,414", lMissingAvpInfo);
			}
				break;
			case UsedServiceUnit_CCTIME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 420");
				}
				else
					sprintf(lMissingAvpInfo, "%s,420", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
