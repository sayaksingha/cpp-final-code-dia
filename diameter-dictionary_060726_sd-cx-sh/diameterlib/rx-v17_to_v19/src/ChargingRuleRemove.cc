#include "rx/include/ChargingRuleRemove.h"

using namespace RX;
BOOLEAN ChargingRuleRemove::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ChargingRuleRemove::ChargingRuleRemove()
{
	mChargingRuleName = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<1>(string("1"));
	mMandatoryAvpSetVal.reset();
}

ChargingRuleRemove::~ChargingRuleRemove()
{
	if(mChargingRuleName != NULL)
		delete mChargingRuleName;
}

OctetString* ChargingRuleRemove::setChargingRuleName(){
	mMandatoryAvpSetVal [ChargingRuleRemove_CHARGINGRULENAME] = 1;
	if(mChargingRuleName == NULL)
	{
		mChargingRuleName = new OctetString();
		mTagsPresent[ChargingRuleRemove_CHARGINGRULENAME] = 1;
		return mChargingRuleName;
	}
	return mChargingRuleName;
}

void ChargingRuleRemove::resetChargingRuleName(){
	mTagsPresent[ChargingRuleRemove_CHARGINGRULENAME] = 0;
	if(mChargingRuleName != NULL)
	{
		delete mChargingRuleName; 
		mChargingRuleName = NULL;
	}
}

OctetString* ChargingRuleRemove::getChargingRuleName(){
	if(NULL == mChargingRuleName) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ChargingRuleName is Null");
		throw lTssDiaMsgException;
	}
	if(!mChargingRuleName->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mChargingRuleName->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ChargingRuleName is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mChargingRuleName->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mChargingRuleName->Decode(mspByteArray.get(), mChargingRuleName->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ChargingRuleName")     ;
			throw lTssDiaMsgException;
		}
		mChargingRuleName->mAvpDecodedFlag = true;
	}
	return mChargingRuleName;
}



int ChargingRuleRemove::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case ChargingRuleRemove_CHARGINGRULENAME:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1005);
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
					if(!mChargingRuleName->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mChargingRuleName->getAvpOffsetLen().first], mChargingRuleName->getAvpOffsetLen().second);
						array->offset += mChargingRuleName->getAvpOffsetLen().second;
						array->size += mChargingRuleName->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mChargingRuleName->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mChargingRuleName->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ChargingRuleName");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mChargingRuleName->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mChargingRuleName->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ChargingRuleName");
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


int ChargingRuleRemove::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1005:
				{
						mMandatoryAvpSetVal [ChargingRuleRemove_CHARGINGRULENAME] = 1;
					if( NULL == this->setChargingRuleName())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ChargingRuleName");
						throw lTssDiaMsgException;
					}
					mChargingRuleName->setAvpCode(1005);
					mChargingRuleName->setAvpVendorId(lVenderId);
					mChargingRuleName->SetDataType((DiameterDataType)5);
					mChargingRuleName->mspByteArray = mspByteArray;
					mChargingRuleName->mAvpDecodedFlag = false;
					mChargingRuleName->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* ChargingRuleRemove::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ChargingRuleRemove")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1005:
			{
				if(mChargingRuleName != NULL)
					return mChargingRuleName->Find(array, avpCode);
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


BOOLEAN ChargingRuleRemove::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ChargingRuleRemove")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1005:
			{
				if(mChargingRuleName != NULL)
				{
					DiameterBaseInterface* inf =  mChargingRuleName->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> ChargingRuleRemove::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ChargingRuleRemove::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ChargingRuleRemove")     ;
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
			case 1005:
			{
				if(mChargingRuleName != NULL)
				{
					DiameterBaseInterface* inf =  mChargingRuleName->Find(this->mspByteArray.get(), avpCode);
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


INT32 ChargingRuleRemove::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 ChargingRuleRemove::getAvpCode()
{
	return mAvpCode;
}
INT32 ChargingRuleRemove::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 ChargingRuleRemove::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 ChargingRuleRemove::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> ChargingRuleRemove::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void ChargingRuleRemove::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case ChargingRuleRemove_CHARGINGRULENAME:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1005" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ChargingRuleName" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getChargingRuleName()->Display(tab+1);
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


BOOLEAN ChargingRuleRemove::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<1> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ChargingRuleRemove_CHARGINGRULENAME:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1005");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1005", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
