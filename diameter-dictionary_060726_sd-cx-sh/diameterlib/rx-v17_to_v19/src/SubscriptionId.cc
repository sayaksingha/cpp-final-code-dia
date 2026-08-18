#include "rx/include/SubscriptionId.h"

using namespace RX;
BOOLEAN SubscriptionId::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

SubscriptionId::SubscriptionId()
{
	mSubscriptionIdType = NULL;
	mSubscriptionIdData = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("11"));
	mMandatoryAvpSetVal.reset();
}

SubscriptionId::~SubscriptionId()
{
	if(mSubscriptionIdType != NULL)
		delete mSubscriptionIdType;
	if(mSubscriptionIdData != NULL)
		delete mSubscriptionIdData;
}

SubscriptionIdType* SubscriptionId::setSubscriptionIdType(){
	mMandatoryAvpSetVal [SubscriptionId_SUBSCRIPTIONIDTYPE] = 1;
	if(mSubscriptionIdType == NULL)
	{
		mSubscriptionIdType = new SubscriptionIdType();
		mTagsPresent[SubscriptionId_SUBSCRIPTIONIDTYPE] = 1;
		return mSubscriptionIdType;
	}
	return mSubscriptionIdType;
}

void SubscriptionId::resetSubscriptionIdType(){
	mTagsPresent[SubscriptionId_SUBSCRIPTIONIDTYPE] = 0;
	if(mSubscriptionIdType != NULL)
	{
		delete mSubscriptionIdType; 
		mSubscriptionIdType = NULL;
	}
}

OctetString* SubscriptionId::setSubscriptionIdData(){
	mMandatoryAvpSetVal [SubscriptionId_SUBSCRIPTIONIDDATA] = 1;
	if(mSubscriptionIdData == NULL)
	{
		mSubscriptionIdData = new OctetString();
		mTagsPresent[SubscriptionId_SUBSCRIPTIONIDDATA] = 1;
		return mSubscriptionIdData;
	}
	return mSubscriptionIdData;
}

void SubscriptionId::resetSubscriptionIdData(){
	mTagsPresent[SubscriptionId_SUBSCRIPTIONIDDATA] = 0;
	if(mSubscriptionIdData != NULL)
	{
		delete mSubscriptionIdData; 
		mSubscriptionIdData = NULL;
	}
}

SubscriptionIdType* SubscriptionId::getSubscriptionIdType(){
	if(NULL == mSubscriptionIdType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SubscriptionIdType is Null");
		throw lTssDiaMsgException;
	}
	if(!mSubscriptionIdType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSubscriptionIdType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SubscriptionIdType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSubscriptionIdType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSubscriptionIdType->Decode(mspByteArray.get(), mSubscriptionIdType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubscriptionIdType")     ;
			throw lTssDiaMsgException;
		}
		mSubscriptionIdType->mAvpDecodedFlag = true;
	}
	return mSubscriptionIdType;
}

OctetString* SubscriptionId::getSubscriptionIdData(){
	if(NULL == mSubscriptionIdData) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SubscriptionIdData is Null");
		throw lTssDiaMsgException;
	}
	if(!mSubscriptionIdData->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSubscriptionIdData->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SubscriptionIdData is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSubscriptionIdData->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSubscriptionIdData->Decode(mspByteArray.get(), mSubscriptionIdData->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubscriptionIdData")     ;
			throw lTssDiaMsgException;
		}
		mSubscriptionIdData->mAvpDecodedFlag = true;
	}
	return mSubscriptionIdData;
}



int SubscriptionId::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case SubscriptionId_SUBSCRIPTIONIDTYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(450);
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
					if(!mSubscriptionIdType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSubscriptionIdType->getAvpOffsetLen().first], mSubscriptionIdType->getAvpOffsetLen().second);
						array->offset += mSubscriptionIdType->getAvpOffsetLen().second;
						array->size += mSubscriptionIdType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SubscriptionIdType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mSubscriptionIdType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SubscriptionIdType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SubscriptionId_SUBSCRIPTIONIDDATA:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(444);
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
					if(!mSubscriptionIdData->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSubscriptionIdData->getAvpOffsetLen().first], mSubscriptionIdData->getAvpOffsetLen().second);
						array->offset += mSubscriptionIdData->getAvpOffsetLen().second;
						array->size += mSubscriptionIdData->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSubscriptionIdData->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSubscriptionIdData->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SubscriptionIdData");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSubscriptionIdData->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSubscriptionIdData->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SubscriptionIdData");
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


int SubscriptionId::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 450:
				{
						mMandatoryAvpSetVal [SubscriptionId_SUBSCRIPTIONIDTYPE] = 1;
					if( NULL == this->setSubscriptionIdType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubscriptionIdType");
						throw lTssDiaMsgException;
					}
					mSubscriptionIdType->setAvpCode(450);
					mSubscriptionIdType->setAvpVendorId(lVenderId);
					mSubscriptionIdType->SetDataType((DiameterDataType)7);
					mSubscriptionIdType->mspByteArray = mspByteArray;
					mSubscriptionIdType->mAvpDecodedFlag = false;
					mSubscriptionIdType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 444:
				{
						mMandatoryAvpSetVal [SubscriptionId_SUBSCRIPTIONIDDATA] = 1;
					if( NULL == this->setSubscriptionIdData())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubscriptionIdData");
						throw lTssDiaMsgException;
					}
					mSubscriptionIdData->setAvpCode(444);
					mSubscriptionIdData->setAvpVendorId(lVenderId);
					mSubscriptionIdData->SetDataType((DiameterDataType)5);
					mSubscriptionIdData->mspByteArray = mspByteArray;
					mSubscriptionIdData->mAvpDecodedFlag = false;
					mSubscriptionIdData->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* SubscriptionId::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubscriptionId")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 450:
			{
				if(mSubscriptionIdType != NULL)
					return mSubscriptionIdType->Find(array, avpCode);
				else
					return NULL;
			}
			case 444:
			{
				if(mSubscriptionIdData != NULL)
					return mSubscriptionIdData->Find(array, avpCode);
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


BOOLEAN SubscriptionId::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubscriptionId")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 450:
			{
				if(mSubscriptionIdType != NULL)
				{
					DiameterBaseInterface* inf =  mSubscriptionIdType->Find(this->mspByteArray.get(), avpCode);
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
			case 444:
			{
				if(mSubscriptionIdData != NULL)
				{
					DiameterBaseInterface* inf =  mSubscriptionIdData->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> SubscriptionId::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN SubscriptionId::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SubscriptionId")     ;
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
			case 450:
			{
				if(mSubscriptionIdType != NULL)
				{
					DiameterBaseInterface* inf =  mSubscriptionIdType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 444:
			{
				if(mSubscriptionIdData != NULL)
				{
					DiameterBaseInterface* inf =  mSubscriptionIdData->Find(this->mspByteArray.get(), avpCode);
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


INT32 SubscriptionId::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 SubscriptionId::getAvpCode()
{
	return mAvpCode;
}
INT32 SubscriptionId::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 SubscriptionId::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 SubscriptionId::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> SubscriptionId::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void SubscriptionId::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case SubscriptionId_SUBSCRIPTIONIDTYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "450" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SubscriptionIdType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSubscriptionIdType()->Display(tab+1);
			}
				break;
			case SubscriptionId_SUBSCRIPTIONIDDATA:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "444" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SubscriptionIdData" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getSubscriptionIdData()->Display(tab+1);
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


BOOLEAN SubscriptionId::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case SubscriptionId_SUBSCRIPTIONIDTYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 450");
				}
				else
					sprintf(lMissingAvpInfo, "%s,450", lMissingAvpInfo);
			}
				break;
			case SubscriptionId_SUBSCRIPTIONIDDATA:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 444");
				}
				else
					sprintf(lMissingAvpInfo, "%s,444", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
