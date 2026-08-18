#include "sd/include/UserEquipmentInfo.h"

using namespace SD;
BOOLEAN UserEquipmentInfo::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

UserEquipmentInfo::UserEquipmentInfo()
{
	mUserEquipmentInfoType = NULL;
	mUserEquipmentInfoValue = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("00"));
	mMandatoryAvpSetVal.reset();
}

UserEquipmentInfo::~UserEquipmentInfo()
{
	if(mUserEquipmentInfoType != NULL)
		delete mUserEquipmentInfoType;
	if(mUserEquipmentInfoValue != NULL)
		delete mUserEquipmentInfoValue;
}

UserEquipmentInfoType* UserEquipmentInfo::setUserEquipmentInfoType(){
	if(mUserEquipmentInfoType == NULL)
	{
		mUserEquipmentInfoType = new UserEquipmentInfoType();
		mTagsPresent[UserEquipmentInfo_USEREQUIPMENTINFOTYPE] = 1;
		return mUserEquipmentInfoType;
	}
	return mUserEquipmentInfoType;
}

void UserEquipmentInfo::resetUserEquipmentInfoType(){
	mTagsPresent[UserEquipmentInfo_USEREQUIPMENTINFOTYPE] = 0;
	if(mUserEquipmentInfoType != NULL)
	{
		delete mUserEquipmentInfoType; 
		mUserEquipmentInfoType = NULL;
	}
}

OctetString* UserEquipmentInfo::setUserEquipmentInfoValue(){
	if(mUserEquipmentInfoValue == NULL)
	{
		mUserEquipmentInfoValue = new OctetString();
		mTagsPresent[UserEquipmentInfo_USEREQUIPMENTINFOVALUE] = 1;
		return mUserEquipmentInfoValue;
	}
	return mUserEquipmentInfoValue;
}

void UserEquipmentInfo::resetUserEquipmentInfoValue(){
	mTagsPresent[UserEquipmentInfo_USEREQUIPMENTINFOVALUE] = 0;
	if(mUserEquipmentInfoValue != NULL)
	{
		delete mUserEquipmentInfoValue; 
		mUserEquipmentInfoValue = NULL;
	}
}

UserEquipmentInfoType* UserEquipmentInfo::getUserEquipmentInfoType(){
	if(NULL == mUserEquipmentInfoType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoType is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserEquipmentInfoType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserEquipmentInfoType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserEquipmentInfoType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserEquipmentInfoType->Decode(mspByteArray.get(), mUserEquipmentInfoType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoType")     ;
			throw lTssDiaMsgException;
		}
		mUserEquipmentInfoType->mAvpDecodedFlag = true;
	}
	return mUserEquipmentInfoType;
}

OctetString* UserEquipmentInfo::getUserEquipmentInfoValue(){
	if(NULL == mUserEquipmentInfoValue) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoValue is Null");
		throw lTssDiaMsgException;
	}
	if(!mUserEquipmentInfoValue->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUserEquipmentInfoValue->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UserEquipmentInfoValue is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUserEquipmentInfoValue->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUserEquipmentInfoValue->Decode(mspByteArray.get(), mUserEquipmentInfoValue->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoValue")     ;
			throw lTssDiaMsgException;
		}
		mUserEquipmentInfoValue->mAvpDecodedFlag = true;
	}
	return mUserEquipmentInfoValue;
}



int UserEquipmentInfo::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case UserEquipmentInfo_USEREQUIPMENTINFOTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(459);
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
					if(!mUserEquipmentInfoType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUserEquipmentInfoType->getAvpOffsetLen().first], mUserEquipmentInfoType->getAvpOffsetLen().second);
						array->offset += mUserEquipmentInfoType->getAvpOffsetLen().second;
						array->size += mUserEquipmentInfoType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mUserEquipmentInfoType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case UserEquipmentInfo_USEREQUIPMENTINFOVALUE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(460);
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
					if(!mUserEquipmentInfoValue->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mUserEquipmentInfoValue->getAvpOffsetLen().first], mUserEquipmentInfoValue->getAvpOffsetLen().second);
						array->offset += mUserEquipmentInfoValue->getAvpOffsetLen().second;
						array->size += mUserEquipmentInfoValue->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mUserEquipmentInfoValue->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mUserEquipmentInfoValue->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoValue");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mUserEquipmentInfoValue->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mUserEquipmentInfoValue->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UserEquipmentInfoValue");
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


int UserEquipmentInfo::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 459:
				{
					if( NULL == this->setUserEquipmentInfoType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoType");
						throw lTssDiaMsgException;
					}
					mUserEquipmentInfoType->setAvpCode(459);
					mUserEquipmentInfoType->setAvpVendorId(lVenderId);
					mUserEquipmentInfoType->SetDataType((DiameterDataType)7);
					mUserEquipmentInfoType->mspByteArray = mspByteArray;
					mUserEquipmentInfoType->mAvpDecodedFlag = false;
					mUserEquipmentInfoType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 460:
				{
					if( NULL == this->setUserEquipmentInfoValue())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfoValue");
						throw lTssDiaMsgException;
					}
					mUserEquipmentInfoValue->setAvpCode(460);
					mUserEquipmentInfoValue->setAvpVendorId(lVenderId);
					mUserEquipmentInfoValue->SetDataType((DiameterDataType)5);
					mUserEquipmentInfoValue->mspByteArray = mspByteArray;
					mUserEquipmentInfoValue->mAvpDecodedFlag = false;
					mUserEquipmentInfoValue->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* UserEquipmentInfo::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 459:
			{
				if(mUserEquipmentInfoType != NULL)
					return mUserEquipmentInfoType->Find(array, avpCode);
				else
					return NULL;
			}
			case 460:
			{
				if(mUserEquipmentInfoValue != NULL)
					return mUserEquipmentInfoValue->Find(array, avpCode);
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


BOOLEAN UserEquipmentInfo::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfo")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 459:
			{
				if(mUserEquipmentInfoType != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoType->Find(this->mspByteArray.get(), avpCode);
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
			case 460:
			{
				if(mUserEquipmentInfoValue != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoValue->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> UserEquipmentInfo::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN UserEquipmentInfo::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UserEquipmentInfo")     ;
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
			case 459:
			{
				if(mUserEquipmentInfoType != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 460:
			{
				if(mUserEquipmentInfoValue != NULL)
				{
					DiameterBaseInterface* inf =  mUserEquipmentInfoValue->Find(this->mspByteArray.get(), avpCode);
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


INT32 UserEquipmentInfo::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 UserEquipmentInfo::getAvpCode()
{
	return mAvpCode;
}
INT32 UserEquipmentInfo::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 UserEquipmentInfo::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 UserEquipmentInfo::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> UserEquipmentInfo::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void UserEquipmentInfo::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case UserEquipmentInfo_USEREQUIPMENTINFOTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "459" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserEquipmentInfoType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getUserEquipmentInfoType()->Display(tab+1);
			}
				break;
			case UserEquipmentInfo_USEREQUIPMENTINFOVALUE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "460" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UserEquipmentInfoValue" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(0)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(0)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(0)==true)?"Protected":""));
				this->getUserEquipmentInfoValue()->Display(tab+1);
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


BOOLEAN UserEquipmentInfo::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case UserEquipmentInfo_USEREQUIPMENTINFOTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 459");
				}
				else
					sprintf(lMissingAvpInfo, "%s,459", lMissingAvpInfo);
			}
				break;
			case UserEquipmentInfo_USEREQUIPMENTINFOVALUE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 460");
				}
				else
					sprintf(lMissingAvpInfo, "%s,460", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
