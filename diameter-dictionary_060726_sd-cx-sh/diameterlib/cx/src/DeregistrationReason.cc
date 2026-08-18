#include "cx/include/DeregistrationReason.h"

using namespace CX;
BOOLEAN DeregistrationReason::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

DeregistrationReason::DeregistrationReason()
{
	mReasonCode = NULL;
	mReasonInfo = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("11"));
	mMandatoryAvpSetVal.reset();
}

DeregistrationReason::~DeregistrationReason()
{
	if(mReasonCode != NULL)
		delete mReasonCode;
	if(mReasonInfo != NULL)
		delete mReasonInfo;
}

ReasonCode* DeregistrationReason::setReasonCode(){
	mMandatoryAvpSetVal [DeregistrationReason_REASONCODE] = 1;
	if(mReasonCode == NULL)
	{
		mReasonCode = new ReasonCode();
		mTagsPresent[DeregistrationReason_REASONCODE] = 1;
		return mReasonCode;
	}
	return mReasonCode;
}

void DeregistrationReason::resetReasonCode(){
	mTagsPresent[DeregistrationReason_REASONCODE] = 0;
	if(mReasonCode != NULL)
	{
		delete mReasonCode; 
		mReasonCode = NULL;
	}
}

OctetString* DeregistrationReason::setReasonInfo(){
	mMandatoryAvpSetVal [DeregistrationReason_REASONINFO] = 1;
	if(mReasonInfo == NULL)
	{
		mReasonInfo = new OctetString();
		mTagsPresent[DeregistrationReason_REASONINFO] = 1;
		return mReasonInfo;
	}
	return mReasonInfo;
}

void DeregistrationReason::resetReasonInfo(){
	mTagsPresent[DeregistrationReason_REASONINFO] = 0;
	if(mReasonInfo != NULL)
	{
		delete mReasonInfo; 
		mReasonInfo = NULL;
	}
}

ReasonCode* DeregistrationReason::getReasonCode(){
	if(NULL == mReasonCode) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReasonCode is Null");
		throw lTssDiaMsgException;
	}
	if(!mReasonCode->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mReasonCode->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReasonCode is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mReasonCode->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mReasonCode->Decode(mspByteArray.get(), mReasonCode->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReasonCode")     ;
			throw lTssDiaMsgException;
		}
		mReasonCode->mAvpDecodedFlag = true;
	}
	return mReasonCode;
}

OctetString* DeregistrationReason::getReasonInfo(){
	if(NULL == mReasonInfo) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReasonInfo is Null");
		throw lTssDiaMsgException;
	}
	if(!mReasonInfo->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mReasonInfo->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReasonInfo is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mReasonInfo->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mReasonInfo->Decode(mspByteArray.get(), mReasonInfo->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReasonInfo")     ;
			throw lTssDiaMsgException;
		}
		mReasonInfo->mAvpDecodedFlag = true;
	}
	return mReasonInfo;
}



int DeregistrationReason::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case DeregistrationReason_REASONCODE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(616);
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
					if(!mReasonCode->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mReasonCode->getAvpOffsetLen().first], mReasonCode->getAvpOffsetLen().second);
						array->offset += mReasonCode->getAvpOffsetLen().second;
						array->size += mReasonCode->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReasonCode");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mReasonCode->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReasonCode");
						throw lTssDiaMsgException;
					}
				}
				break;
			case DeregistrationReason_REASONINFO:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(617);
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
					if(!mReasonInfo->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mReasonInfo->getAvpOffsetLen().first], mReasonInfo->getAvpOffsetLen().second);
						array->offset += mReasonInfo->getAvpOffsetLen().second;
						array->size += mReasonInfo->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mReasonInfo->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mReasonInfo->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReasonInfo");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mReasonInfo->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mReasonInfo->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReasonInfo");
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


int DeregistrationReason::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 616:
				{
						mMandatoryAvpSetVal [DeregistrationReason_REASONCODE] = 1;
					if( NULL == this->setReasonCode())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReasonCode");
						throw lTssDiaMsgException;
					}
					mReasonCode->setAvpCode(616);
					mReasonCode->setAvpVendorId(lVenderId);
					mReasonCode->SetDataType((DiameterDataType)7);
					mReasonCode->mspByteArray = mspByteArray;
					mReasonCode->mAvpDecodedFlag = false;
					mReasonCode->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 617:
				{
						mMandatoryAvpSetVal [DeregistrationReason_REASONINFO] = 1;
					if( NULL == this->setReasonInfo())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReasonInfo");
						throw lTssDiaMsgException;
					}
					mReasonInfo->setAvpCode(617);
					mReasonInfo->setAvpVendorId(lVenderId);
					mReasonInfo->SetDataType((DiameterDataType)5);
					mReasonInfo->mspByteArray = mspByteArray;
					mReasonInfo->mAvpDecodedFlag = false;
					mReasonInfo->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* DeregistrationReason::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DeregistrationReason")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 616:
			{
				if(mReasonCode != NULL)
					return mReasonCode->Find(array, avpCode);
				else
					return NULL;
			}
			case 617:
			{
				if(mReasonInfo != NULL)
					return mReasonInfo->Find(array, avpCode);
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


BOOLEAN DeregistrationReason::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DeregistrationReason")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 616:
			{
				if(mReasonCode != NULL)
				{
					DiameterBaseInterface* inf =  mReasonCode->Find(this->mspByteArray.get(), avpCode);
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
			case 617:
			{
				if(mReasonInfo != NULL)
				{
					DiameterBaseInterface* inf =  mReasonInfo->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> DeregistrationReason::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN DeregistrationReason::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding DeregistrationReason")     ;
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
			case 616:
			{
				if(mReasonCode != NULL)
				{
					DiameterBaseInterface* inf =  mReasonCode->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 617:
			{
				if(mReasonInfo != NULL)
				{
					DiameterBaseInterface* inf =  mReasonInfo->Find(this->mspByteArray.get(), avpCode);
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


INT32 DeregistrationReason::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 DeregistrationReason::getAvpCode()
{
	return mAvpCode;
}
INT32 DeregistrationReason::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 DeregistrationReason::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 DeregistrationReason::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> DeregistrationReason::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void DeregistrationReason::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case DeregistrationReason_REASONCODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "616" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ReasonCode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getReasonCode()->Display(tab+1);
			}
				break;
			case DeregistrationReason_REASONINFO:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "617" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ReasonInfo" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getReasonInfo()->Display(tab+1);
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


BOOLEAN DeregistrationReason::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case DeregistrationReason_REASONCODE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 616");
				}
				else
					sprintf(lMissingAvpInfo, "%s,616", lMissingAvpInfo);
			}
				break;
			case DeregistrationReason_REASONINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 617");
				}
				else
					sprintf(lMissingAvpInfo, "%s,617", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
