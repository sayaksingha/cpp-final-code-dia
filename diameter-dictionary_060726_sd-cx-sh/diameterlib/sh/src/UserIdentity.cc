#include "sh/include/UserIdentity.h"

using namespace SH;
BOOLEAN UserIdentity::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

UserIdentity::UserIdentity()
{
	mPublicIdentity = NULL;
	mMSISDN = NULL;
	mExternalIdentifier = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("111"));
	mMandatoryAvpSetVal.reset();
}

UserIdentity::~UserIdentity()
{
	if(mPublicIdentity != NULL)
		delete mPublicIdentity;
	if(mMSISDN != NULL)
		delete mMSISDN;
	if(mExternalIdentifier != NULL)
		delete mExternalIdentifier;
}

OctetString* UserIdentity::setPublicIdentity(){
	mMandatoryAvpSetVal [UserIdentity_PUBLICIDENTITY] = 1;
	if(mPublicIdentity == NULL)
	{
		mPublicIdentity = new OctetString();
		mTagsPresent[UserIdentity_PUBLICIDENTITY] = 1;
		return mPublicIdentity;
	}
	return mPublicIdentity;
}

void UserIdentity::resetPublicIdentity(){
	mTagsPresent[UserIdentity_PUBLICIDENTITY] = 0;
	if(mPublicIdentity != NULL)
	{
		delete mPublicIdentity; 
		mPublicIdentity = NULL;
	}
}

OctetString* UserIdentity::setMSISDN(){
	mMandatoryAvpSetVal [UserIdentity_MSISDN] = 1;
	if(mMSISDN == NULL)
	{
		mMSISDN = new OctetString();
		mTagsPresent[UserIdentity_MSISDN] = 1;
		return mMSISDN;
	}
	return mMSISDN;
}

void UserIdentity::resetMSISDN(){
	mTagsPresent[UserIdentity_MSISDN] = 0;
	if(mMSISDN != NULL)
	{
		delete mMSISDN; 
		mMSISDN = NULL;
	}
}

OctetString* UserIdentity::setExternalIdentifier(){
	mMandatoryAvpSetVal [UserIdentity_EXTERNALIDENTIFIER] = 1;
	if(mExternalIdentifier == NULL)
	{
		mExternalIdentifier = new OctetString();
		mTagsPresent[UserIdentity_EXTERNALIDENTIFIER] = 1;
		return mExternalIdentifier;
	}
	return mExternalIdentifier;
}

void UserIdentity::resetExternalIdentifier(){
	mTagsPresent[UserIdentity_EXTERNALIDENTIFIER] = 0;
	if(mExternalIdentifier != NULL)
	{
		delete mExternalIdentifier; 
		mExternalIdentifier = NULL;
	}
}

OctetString* UserIdentity::getPublicIdentity(){
	if(NULL == mPublicIdentity) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PublicIdentity is Null");
		throw lTssDiaMsgException;
	}
	if(!mPublicIdentity->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPublicIdentity->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PublicIdentity is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPublicIdentity->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPublicIdentity->Decode(mspByteArray.get(), mPublicIdentity->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PublicIdentity")     ;
			throw lTssDiaMsgException;
		}
		mPublicIdentity->mAvpDecodedFlag = true;
	}
	return mPublicIdentity;
}

OctetString* UserIdentity::getMSISDN(){
	if(NULL == mMSISDN) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MSISDN is Null");
		throw lTssDiaMsgException;
	}
	if(!mMSISDN->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMSISDN->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MSISDN is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMSISDN->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMSISDN->Decode(mspByteArray.get(), mMSISDN->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MSISDN")     ;
			throw lTssDiaMsgException;
		}
		mMSISDN->mAvpDecodedFlag = true;
	}
	return mMSISDN;
}

OctetString* UserIdentity::getExternalIdentifier(){
	if(NULL == mExternalIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExternalIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mExternalIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExternalIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExternalIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExternalIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExternalIdentifier->Decode(mspByteArray.get(), mExternalIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExternalIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mExternalIdentifier->mAvpDecodedFlag = true;
	}
	return mExternalIdentifier;
}



int UserIdentity::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case UserIdentity_PUBLICIDENTITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(601);
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
					if(!mPublicIdentity->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPublicIdentity->getAvpOffsetLen().first], mPublicIdentity->getAvpOffsetLen().second);
						array->offset += mPublicIdentity->getAvpOffsetLen().second;
						array->size += mPublicIdentity->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mPublicIdentity->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mPublicIdentity->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PublicIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mPublicIdentity->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mPublicIdentity->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PublicIdentity");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserIdentity_MSISDN:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(701);
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
					if(!mMSISDN->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMSISDN->getAvpOffsetLen().first], mMSISDN->getAvpOffsetLen().second);
						array->offset += mMSISDN->getAvpOffsetLen().second;
						array->size += mMSISDN->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mMSISDN->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mMSISDN->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MSISDN");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mMSISDN->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mMSISDN->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MSISDN");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserIdentity_EXTERNALIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(3111);
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
					if(!mExternalIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mExternalIdentifier->getAvpOffsetLen().first], mExternalIdentifier->getAvpOffsetLen().second);
						array->offset += mExternalIdentifier->getAvpOffsetLen().second;
						array->size += mExternalIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mExternalIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mExternalIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExternalIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mExternalIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mExternalIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExternalIdentifier");
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


int UserIdentity::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 601:
				{
						mMandatoryAvpSetVal [UserIdentity_PUBLICIDENTITY] = 1;
					if( NULL == this->setPublicIdentity())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PublicIdentity");
						throw lTssDiaMsgException;
					}
					mPublicIdentity->setAvpCode(601);
					mPublicIdentity->setAvpVendorId(lVenderId);
					mPublicIdentity->SetDataType((DiameterDataType)5);
					mPublicIdentity->mspByteArray = mspByteArray;
					mPublicIdentity->mAvpDecodedFlag = false;
					mPublicIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 701:
				{
						mMandatoryAvpSetVal [UserIdentity_MSISDN] = 1;
					if( NULL == this->setMSISDN())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MSISDN");
						throw lTssDiaMsgException;
					}
					mMSISDN->setAvpCode(701);
					mMSISDN->setAvpVendorId(lVenderId);
					mMSISDN->SetDataType((DiameterDataType)5);
					mMSISDN->mspByteArray = mspByteArray;
					mMSISDN->mAvpDecodedFlag = false;
					mMSISDN->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 3111:
				{
						mMandatoryAvpSetVal [UserIdentity_EXTERNALIDENTIFIER] = 1;
					if( NULL == this->setExternalIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExternalIdentifier");
						throw lTssDiaMsgException;
					}
					mExternalIdentifier->setAvpCode(3111);
					mExternalIdentifier->setAvpVendorId(lVenderId);
					mExternalIdentifier->SetDataType((DiameterDataType)5);
					mExternalIdentifier->mspByteArray = mspByteArray;
					mExternalIdentifier->mAvpDecodedFlag = false;
					mExternalIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* UserIdentity::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserIdentity")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 601:
			{
				if(mPublicIdentity != NULL)
					return mPublicIdentity->Find(array, avpCode);
				else
					return NULL;
			}
			case 701:
			{
				if(mMSISDN != NULL)
					return mMSISDN->Find(array, avpCode);
				else
					return NULL;
			}
			case 3111:
			{
				if(mExternalIdentifier != NULL)
					return mExternalIdentifier->Find(array, avpCode);
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


BOOLEAN UserIdentity::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserIdentity")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 601:
			{
				if(mPublicIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mPublicIdentity->Find(this->mspByteArray.get(), avpCode);
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
			case 701:
			{
				if(mMSISDN != NULL)
				{
					DiameterBaseInterface* inf =  mMSISDN->Find(this->mspByteArray.get(), avpCode);
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
			case 3111:
			{
				if(mExternalIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mExternalIdentifier->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> UserIdentity::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN UserIdentity::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserIdentity")     ;
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
			case 601:
			{
				if(mPublicIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mPublicIdentity->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 701:
			{
				if(mMSISDN != NULL)
				{
					DiameterBaseInterface* inf =  mMSISDN->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 3111:
			{
				if(mExternalIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mExternalIdentifier->Find(this->mspByteArray.get(), avpCode);
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


INT32 UserIdentity::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 UserIdentity::getAvpCode()
{
	return mAvpCode;
}
INT32 UserIdentity::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 UserIdentity::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 UserIdentity::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> UserIdentity::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void UserIdentity::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case UserIdentity_PUBLICIDENTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "601" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PublicIdentity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getPublicIdentity()->Display(tab+1);
			}
				break;
			case UserIdentity_MSISDN:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "701" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MSISDN" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMSISDN()->Display(tab+1);
			}
				break;
			case UserIdentity_EXTERNALIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "3111" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExternalIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getExternalIdentifier()->Display(tab+1);
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


BOOLEAN UserIdentity::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case UserIdentity_PUBLICIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 601");
				}
				else
					sprintf(lMissingAvpInfo, "%s,601", lMissingAvpInfo);
			}
				break;
			case UserIdentity_MSISDN:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 701");
				}
				else
					sprintf(lMissingAvpInfo, "%s,701", lMissingAvpInfo);
			}
				break;
			case UserIdentity_EXTERNALIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 3111");
				}
				else
					sprintf(lMissingAvpInfo, "%s,3111", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
