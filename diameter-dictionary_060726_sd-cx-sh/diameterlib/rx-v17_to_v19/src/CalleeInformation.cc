#include "rx/include/CalleeInformation.h"

using namespace RX;
BOOLEAN CalleeInformation::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

CalleeInformation::CalleeInformation()
{
	mCalledPartyAddress = NULL;
	mRequestedPartyAddress = NULL;
	mCalledAssertedIdentity = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("111"));
	mMandatoryAvpSetVal.reset();
}

CalleeInformation::~CalleeInformation()
{
	if(mCalledPartyAddress != NULL)
		delete mCalledPartyAddress;
	if(mRequestedPartyAddress != NULL)
		delete mRequestedPartyAddress;
	if(mCalledAssertedIdentity != NULL)
		delete mCalledAssertedIdentity;
}

OctetString* CalleeInformation::setCalledPartyAddress(){
	mMandatoryAvpSetVal [CalleeInformation_CALLEDPARTYADDRESS] = 1;
	if(mCalledPartyAddress == NULL)
	{
		mCalledPartyAddress = new OctetString();
		mTagsPresent[CalleeInformation_CALLEDPARTYADDRESS] = 1;
		return mCalledPartyAddress;
	}
	return mCalledPartyAddress;
}

void CalleeInformation::resetCalledPartyAddress(){
	mTagsPresent[CalleeInformation_CALLEDPARTYADDRESS] = 0;
	if(mCalledPartyAddress != NULL)
	{
		delete mCalledPartyAddress; 
		mCalledPartyAddress = NULL;
	}
}

OctetString* CalleeInformation::setRequestedPartyAddress(){
	mMandatoryAvpSetVal [CalleeInformation_REQUESTEDPARTYADDRESS] = 1;
	if(mRequestedPartyAddress == NULL)
	{
		mRequestedPartyAddress = new OctetString();
		mTagsPresent[CalleeInformation_REQUESTEDPARTYADDRESS] = 1;
		return mRequestedPartyAddress;
	}
	return mRequestedPartyAddress;
}

void CalleeInformation::resetRequestedPartyAddress(){
	mTagsPresent[CalleeInformation_REQUESTEDPARTYADDRESS] = 0;
	if(mRequestedPartyAddress != NULL)
	{
		delete mRequestedPartyAddress; 
		mRequestedPartyAddress = NULL;
	}
}

OctetString* CalleeInformation::setCalledAssertedIdentity(){
	mMandatoryAvpSetVal [CalleeInformation_CALLEDASSERTEDIDENTITY] = 1;
	if(mCalledAssertedIdentity == NULL)
	{
		mCalledAssertedIdentity = new OctetString();
		mTagsPresent[CalleeInformation_CALLEDASSERTEDIDENTITY] = 1;
		return mCalledAssertedIdentity;
	}
	return mCalledAssertedIdentity;
}

void CalleeInformation::resetCalledAssertedIdentity(){
	mTagsPresent[CalleeInformation_CALLEDASSERTEDIDENTITY] = 0;
	if(mCalledAssertedIdentity != NULL)
	{
		delete mCalledAssertedIdentity; 
		mCalledAssertedIdentity = NULL;
	}
}

OctetString* CalleeInformation::getCalledPartyAddress(){
	if(NULL == mCalledPartyAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CalledPartyAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!mCalledPartyAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCalledPartyAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CalledPartyAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCalledPartyAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCalledPartyAddress->Decode(mspByteArray.get(), mCalledPartyAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CalledPartyAddress")     ;
			throw lTssDiaMsgException;
		}
		mCalledPartyAddress->mAvpDecodedFlag = true;
	}
	return mCalledPartyAddress;
}

OctetString* CalleeInformation::getRequestedPartyAddress(){
	if(NULL == mRequestedPartyAddress) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RequestedPartyAddress is Null");
		throw lTssDiaMsgException;
	}
	if(!mRequestedPartyAddress->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRequestedPartyAddress->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RequestedPartyAddress is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRequestedPartyAddress->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRequestedPartyAddress->Decode(mspByteArray.get(), mRequestedPartyAddress->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RequestedPartyAddress")     ;
			throw lTssDiaMsgException;
		}
		mRequestedPartyAddress->mAvpDecodedFlag = true;
	}
	return mRequestedPartyAddress;
}

OctetString* CalleeInformation::getCalledAssertedIdentity(){
	if(NULL == mCalledAssertedIdentity) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CalledAssertedIdentity is Null");
		throw lTssDiaMsgException;
	}
	if(!mCalledAssertedIdentity->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCalledAssertedIdentity->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CalledAssertedIdentity is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCalledAssertedIdentity->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCalledAssertedIdentity->Decode(mspByteArray.get(), mCalledAssertedIdentity->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CalledAssertedIdentity")     ;
			throw lTssDiaMsgException;
		}
		mCalledAssertedIdentity->mAvpDecodedFlag = true;
	}
	return mCalledAssertedIdentity;
}



int CalleeInformation::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case CalleeInformation_CALLEDPARTYADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(832);
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
					if(!mCalledPartyAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCalledPartyAddress->getAvpOffsetLen().first], mCalledPartyAddress->getAvpOffsetLen().second);
						array->offset += mCalledPartyAddress->getAvpOffsetLen().second;
						array->size += mCalledPartyAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mCalledPartyAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mCalledPartyAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CalledPartyAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mCalledPartyAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mCalledPartyAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CalledPartyAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case CalleeInformation_REQUESTEDPARTYADDRESS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1251);
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
					if(!mRequestedPartyAddress->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRequestedPartyAddress->getAvpOffsetLen().first], mRequestedPartyAddress->getAvpOffsetLen().second);
						array->offset += mRequestedPartyAddress->getAvpOffsetLen().second;
						array->size += mRequestedPartyAddress->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mRequestedPartyAddress->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mRequestedPartyAddress->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RequestedPartyAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mRequestedPartyAddress->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mRequestedPartyAddress->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RequestedPartyAddress");
						throw lTssDiaMsgException;
					}
				}
				break;
			case CalleeInformation_CALLEDASSERTEDIDENTITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1250);
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
					if(!mCalledAssertedIdentity->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCalledAssertedIdentity->getAvpOffsetLen().first], mCalledAssertedIdentity->getAvpOffsetLen().second);
						array->offset += mCalledAssertedIdentity->getAvpOffsetLen().second;
						array->size += mCalledAssertedIdentity->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mCalledAssertedIdentity->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mCalledAssertedIdentity->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CalledAssertedIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mCalledAssertedIdentity->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mCalledAssertedIdentity->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CalledAssertedIdentity");
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


int CalleeInformation::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 832:
				{
						mMandatoryAvpSetVal [CalleeInformation_CALLEDPARTYADDRESS] = 1;
					if( NULL == this->setCalledPartyAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CalledPartyAddress");
						throw lTssDiaMsgException;
					}
					mCalledPartyAddress->setAvpCode(832);
					mCalledPartyAddress->setAvpVendorId(lVenderId);
					mCalledPartyAddress->SetDataType((DiameterDataType)5);
					mCalledPartyAddress->mspByteArray = mspByteArray;
					mCalledPartyAddress->mAvpDecodedFlag = false;
					mCalledPartyAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1251:
				{
						mMandatoryAvpSetVal [CalleeInformation_REQUESTEDPARTYADDRESS] = 1;
					if( NULL == this->setRequestedPartyAddress())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RequestedPartyAddress");
						throw lTssDiaMsgException;
					}
					mRequestedPartyAddress->setAvpCode(1251);
					mRequestedPartyAddress->setAvpVendorId(lVenderId);
					mRequestedPartyAddress->SetDataType((DiameterDataType)5);
					mRequestedPartyAddress->mspByteArray = mspByteArray;
					mRequestedPartyAddress->mAvpDecodedFlag = false;
					mRequestedPartyAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1250:
				{
						mMandatoryAvpSetVal [CalleeInformation_CALLEDASSERTEDIDENTITY] = 1;
					if( NULL == this->setCalledAssertedIdentity())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CalledAssertedIdentity");
						throw lTssDiaMsgException;
					}
					mCalledAssertedIdentity->setAvpCode(1250);
					mCalledAssertedIdentity->setAvpVendorId(lVenderId);
					mCalledAssertedIdentity->SetDataType((DiameterDataType)5);
					mCalledAssertedIdentity->mspByteArray = mspByteArray;
					mCalledAssertedIdentity->mAvpDecodedFlag = false;
					mCalledAssertedIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* CalleeInformation::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CalleeInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 832:
			{
				if(mCalledPartyAddress != NULL)
					return mCalledPartyAddress->Find(array, avpCode);
				else
					return NULL;
			}
			case 1251:
			{
				if(mRequestedPartyAddress != NULL)
					return mRequestedPartyAddress->Find(array, avpCode);
				else
					return NULL;
			}
			case 1250:
			{
				if(mCalledAssertedIdentity != NULL)
					return mCalledAssertedIdentity->Find(array, avpCode);
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


BOOLEAN CalleeInformation::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CalleeInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 832:
			{
				if(mCalledPartyAddress != NULL)
				{
					DiameterBaseInterface* inf =  mCalledPartyAddress->Find(this->mspByteArray.get(), avpCode);
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
			case 1251:
			{
				if(mRequestedPartyAddress != NULL)
				{
					DiameterBaseInterface* inf =  mRequestedPartyAddress->Find(this->mspByteArray.get(), avpCode);
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
			case 1250:
			{
				if(mCalledAssertedIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mCalledAssertedIdentity->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> CalleeInformation::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN CalleeInformation::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CalleeInformation")     ;
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
			case 832:
			{
				if(mCalledPartyAddress != NULL)
				{
					DiameterBaseInterface* inf =  mCalledPartyAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1251:
			{
				if(mRequestedPartyAddress != NULL)
				{
					DiameterBaseInterface* inf =  mRequestedPartyAddress->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1250:
			{
				if(mCalledAssertedIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mCalledAssertedIdentity->Find(this->mspByteArray.get(), avpCode);
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


INT32 CalleeInformation::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 CalleeInformation::getAvpCode()
{
	return mAvpCode;
}
INT32 CalleeInformation::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 CalleeInformation::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 CalleeInformation::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> CalleeInformation::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void CalleeInformation::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case CalleeInformation_CALLEDPARTYADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "832" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CalledPartyAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getCalledPartyAddress()->Display(tab+1);
			}
				break;
			case CalleeInformation_REQUESTEDPARTYADDRESS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1251" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RequestedPartyAddress" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getRequestedPartyAddress()->Display(tab+1);
			}
				break;
			case CalleeInformation_CALLEDASSERTEDIDENTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1250" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CalledAssertedIdentity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getCalledAssertedIdentity()->Display(tab+1);
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


BOOLEAN CalleeInformation::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case CalleeInformation_CALLEDPARTYADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 832");
				}
				else
					sprintf(lMissingAvpInfo, "%s,832", lMissingAvpInfo);
			}
				break;
			case CalleeInformation_REQUESTEDPARTYADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1251");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1251", lMissingAvpInfo);
			}
				break;
			case CalleeInformation_CALLEDASSERTEDIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1250");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1250", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
