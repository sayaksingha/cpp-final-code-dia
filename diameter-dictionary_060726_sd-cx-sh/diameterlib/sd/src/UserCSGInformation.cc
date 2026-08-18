#include "sd/include/UserCSGInformation.h"

using namespace SD;
BOOLEAN UserCSGInformation::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

UserCSGInformation::UserCSGInformation()
{
	mCSGId = NULL;
	mCSGAccessMode = NULL;
	mCSGMembershipIndication = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("011"));
	mMandatoryAvpSetVal.reset();
}

UserCSGInformation::~UserCSGInformation()
{
	if(mCSGId != NULL)
		delete mCSGId;
	if(mCSGAccessMode != NULL)
		delete mCSGAccessMode;
	if(mCSGMembershipIndication != NULL)
		delete mCSGMembershipIndication;
}

Unsigned32* UserCSGInformation::setCSGId(){
	mMandatoryAvpSetVal [UserCSGInformation_CSGID] = 1;
	if(mCSGId == NULL)
	{
		mCSGId = new Unsigned32();
		mTagsPresent[UserCSGInformation_CSGID] = 1;
		return mCSGId;
	}
	return mCSGId;
}

void UserCSGInformation::resetCSGId(){
	mTagsPresent[UserCSGInformation_CSGID] = 0;
	if(mCSGId != NULL)
	{
		delete mCSGId; 
		mCSGId = NULL;
	}
}

CSGAccessMode* UserCSGInformation::setCSGAccessMode(){
	mMandatoryAvpSetVal [UserCSGInformation_CSGACCESSMODE] = 1;
	if(mCSGAccessMode == NULL)
	{
		mCSGAccessMode = new CSGAccessMode();
		mTagsPresent[UserCSGInformation_CSGACCESSMODE] = 1;
		return mCSGAccessMode;
	}
	return mCSGAccessMode;
}

void UserCSGInformation::resetCSGAccessMode(){
	mTagsPresent[UserCSGInformation_CSGACCESSMODE] = 0;
	if(mCSGAccessMode != NULL)
	{
		delete mCSGAccessMode; 
		mCSGAccessMode = NULL;
	}
}

CSGMembershipIndication* UserCSGInformation::setCSGMembershipIndication(){
	if(mCSGMembershipIndication == NULL)
	{
		mCSGMembershipIndication = new CSGMembershipIndication();
		mTagsPresent[UserCSGInformation_CSGMEMBERSHIPINDICATION] = 1;
		return mCSGMembershipIndication;
	}
	return mCSGMembershipIndication;
}

void UserCSGInformation::resetCSGMembershipIndication(){
	mTagsPresent[UserCSGInformation_CSGMEMBERSHIPINDICATION] = 0;
	if(mCSGMembershipIndication != NULL)
	{
		delete mCSGMembershipIndication; 
		mCSGMembershipIndication = NULL;
	}
}

Unsigned32* UserCSGInformation::getCSGId(){
	if(NULL == mCSGId) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CSGId is Null");
		throw lTssDiaMsgException;
	}
	if(!mCSGId->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCSGId->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CSGId is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCSGId->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCSGId->Decode(mspByteArray.get(), mCSGId->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CSGId")     ;
			throw lTssDiaMsgException;
		}
		mCSGId->mAvpDecodedFlag = true;
	}
	return mCSGId;
}

CSGAccessMode* UserCSGInformation::getCSGAccessMode(){
	if(NULL == mCSGAccessMode) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CSGAccessMode is Null");
		throw lTssDiaMsgException;
	}
	if(!mCSGAccessMode->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCSGAccessMode->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CSGAccessMode is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCSGAccessMode->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCSGAccessMode->Decode(mspByteArray.get(), mCSGAccessMode->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CSGAccessMode")     ;
			throw lTssDiaMsgException;
		}
		mCSGAccessMode->mAvpDecodedFlag = true;
	}
	return mCSGAccessMode;
}

CSGMembershipIndication* UserCSGInformation::getCSGMembershipIndication(){
	if(NULL == mCSGMembershipIndication) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CSGMembershipIndication is Null");
		throw lTssDiaMsgException;
	}
	if(!mCSGMembershipIndication->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCSGMembershipIndication->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CSGMembershipIndication is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCSGMembershipIndication->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCSGMembershipIndication->Decode(mspByteArray.get(), mCSGMembershipIndication->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CSGMembershipIndication")     ;
			throw lTssDiaMsgException;
		}
		mCSGMembershipIndication->mAvpDecodedFlag = true;
	}
	return mCSGMembershipIndication;
}



int UserCSGInformation::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case UserCSGInformation_CSGID:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1437);
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
					if(!mCSGId->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCSGId->getAvpOffsetLen().first], mCSGId->getAvpOffsetLen().second);
						array->offset += mCSGId->getAvpOffsetLen().second;
						array->size += mCSGId->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CSGId");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCSGId->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CSGId");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserCSGInformation_CSGACCESSMODE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2317);
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
					if(!mCSGAccessMode->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCSGAccessMode->getAvpOffsetLen().first], mCSGAccessMode->getAvpOffsetLen().second);
						array->offset += mCSGAccessMode->getAvpOffsetLen().second;
						array->size += mCSGAccessMode->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CSGAccessMode");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCSGAccessMode->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CSGAccessMode");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserCSGInformation_CSGMEMBERSHIPINDICATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2318);
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
					if(!mCSGMembershipIndication->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCSGMembershipIndication->getAvpOffsetLen().first], mCSGMembershipIndication->getAvpOffsetLen().second);
						array->offset += mCSGMembershipIndication->getAvpOffsetLen().second;
						array->size += mCSGMembershipIndication->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CSGMembershipIndication");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCSGMembershipIndication->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CSGMembershipIndication");
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


int UserCSGInformation::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1437:
				{
						mMandatoryAvpSetVal [UserCSGInformation_CSGID] = 1;
					if( NULL == this->setCSGId())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CSGId");
						throw lTssDiaMsgException;
					}
					mCSGId->setAvpCode(1437);
					mCSGId->setAvpVendorId(lVenderId);
					mCSGId->SetDataType((DiameterDataType)3);
					mCSGId->mspByteArray = mspByteArray;
					mCSGId->mAvpDecodedFlag = false;
					mCSGId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2317:
				{
						mMandatoryAvpSetVal [UserCSGInformation_CSGACCESSMODE] = 1;
					if( NULL == this->setCSGAccessMode())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CSGAccessMode");
						throw lTssDiaMsgException;
					}
					mCSGAccessMode->setAvpCode(2317);
					mCSGAccessMode->setAvpVendorId(lVenderId);
					mCSGAccessMode->SetDataType((DiameterDataType)7);
					mCSGAccessMode->mspByteArray = mspByteArray;
					mCSGAccessMode->mAvpDecodedFlag = false;
					mCSGAccessMode->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2318:
				{
					if( NULL == this->setCSGMembershipIndication())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CSGMembershipIndication");
						throw lTssDiaMsgException;
					}
					mCSGMembershipIndication->setAvpCode(2318);
					mCSGMembershipIndication->setAvpVendorId(lVenderId);
					mCSGMembershipIndication->SetDataType((DiameterDataType)7);
					mCSGMembershipIndication->mspByteArray = mspByteArray;
					mCSGMembershipIndication->mAvpDecodedFlag = false;
					mCSGMembershipIndication->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* UserCSGInformation::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserCSGInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1437:
			{
				if(mCSGId != NULL)
					return mCSGId->Find(array, avpCode);
				else
					return NULL;
			}
			case 2317:
			{
				if(mCSGAccessMode != NULL)
					return mCSGAccessMode->Find(array, avpCode);
				else
					return NULL;
			}
			case 2318:
			{
				if(mCSGMembershipIndication != NULL)
					return mCSGMembershipIndication->Find(array, avpCode);
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


BOOLEAN UserCSGInformation::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserCSGInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1437:
			{
				if(mCSGId != NULL)
				{
					DiameterBaseInterface* inf =  mCSGId->Find(this->mspByteArray.get(), avpCode);
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
			case 2317:
			{
				if(mCSGAccessMode != NULL)
				{
					DiameterBaseInterface* inf =  mCSGAccessMode->Find(this->mspByteArray.get(), avpCode);
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
			case 2318:
			{
				if(mCSGMembershipIndication != NULL)
				{
					DiameterBaseInterface* inf =  mCSGMembershipIndication->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> UserCSGInformation::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN UserCSGInformation::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserCSGInformation")     ;
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
			case 1437:
			{
				if(mCSGId != NULL)
				{
					DiameterBaseInterface* inf =  mCSGId->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2317:
			{
				if(mCSGAccessMode != NULL)
				{
					DiameterBaseInterface* inf =  mCSGAccessMode->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2318:
			{
				if(mCSGMembershipIndication != NULL)
				{
					DiameterBaseInterface* inf =  mCSGMembershipIndication->Find(this->mspByteArray.get(), avpCode);
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


INT32 UserCSGInformation::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 UserCSGInformation::getAvpCode()
{
	return mAvpCode;
}
INT32 UserCSGInformation::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 UserCSGInformation::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 UserCSGInformation::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> UserCSGInformation::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void UserCSGInformation::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case UserCSGInformation_CSGID:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1437" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CSGId" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getCSGId()->Display(tab+1);
			}
				break;
			case UserCSGInformation_CSGACCESSMODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2317" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CSGAccessMode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getCSGAccessMode()->Display(tab+1);
			}
				break;
			case UserCSGInformation_CSGMEMBERSHIPINDICATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2318" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CSGMembershipIndication" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getCSGMembershipIndication()->Display(tab+1);
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


BOOLEAN UserCSGInformation::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case UserCSGInformation_CSGID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1437");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1437", lMissingAvpInfo);
			}
				break;
			case UserCSGInformation_CSGACCESSMODE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2317");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2317", lMissingAvpInfo);
			}
				break;
			case UserCSGInformation_CSGMEMBERSHIPINDICATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2318");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2318", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
