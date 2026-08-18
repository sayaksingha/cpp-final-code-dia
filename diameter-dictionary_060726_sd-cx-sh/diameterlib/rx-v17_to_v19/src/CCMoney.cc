#include "rx/include/CCMoney.h"

using namespace RX;
BOOLEAN CCMoney::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

CCMoney::CCMoney()
{
	mUnitValueGrpList = NULL;
	mCurrencyCode = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("11"));
	mMandatoryAvpSetVal.reset();
}

CCMoney::~CCMoney()
{
	if(mUnitValueGrpList != NULL){
		mUnitValueGrpIterator = mUnitValueGrpList->begin();
		while(mUnitValueGrpIterator != mUnitValueGrpList->end()){
	if(*mUnitValueGrpIterator != NULL)
			delete (*mUnitValueGrpIterator);
			mUnitValueGrpIterator++;
		}
		delete mUnitValueGrpList;
	}
	if(mCurrencyCode != NULL)
		delete mCurrencyCode;
}

Unsigned64* CCMoney::setCurrencyCode(){
	mMandatoryAvpSetVal [CCMoney_CURRENCYCODE] = 1;
	if(mCurrencyCode == NULL)
	{
		mCurrencyCode = new Unsigned64();
		mTagsPresent[CCMoney_CURRENCYCODE] = 1;
		return mCurrencyCode;
	}
	return mCurrencyCode;
}

void CCMoney::resetCurrencyCode(){
	mTagsPresent[CCMoney_CURRENCYCODE] = 0;
	if(mCurrencyCode != NULL)
	{
		delete mCurrencyCode; 
		mCurrencyCode = NULL;
	}
}

list<UnitValue*>* CCMoney::getUnitValueGrpList()
{
	if(mUnitValueGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UnitValue is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mUnitValueGrpList)
	{
		if(mUnitValueGrpList != NULL)
		{
		if(mUnitValueGrpList->size() == 0)
		{
			mTagsPresent[CCMoney_UNITVALUE] = 0;
			mUnitValueGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UnitValue is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UnitValue is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UnitValue")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mUnitValueGrpList;
}

list<UnitValue*>* CCMoney::setUnitValueGrpList(){
	mTagsPresent[CCMoney_UNITVALUE] = 1;
	if(mUnitValueGrpList == NULL)
		mUnitValueGrpList = new list<UnitValue*>;
	mMandatoryAvpSetVal[CCMoney_UNITVALUE] = 1;
	mUnitValueGrpList->clear();
	return mUnitValueGrpList;
}

void CCMoney::resetUnitValueGrpList(){
	mTagsPresent[CCMoney_UNITVALUE] = 0;
	if(mUnitValueGrpList != NULL)
		delete mUnitValueGrpList;
}

Unsigned64* CCMoney::getCurrencyCode(){
	if(NULL == mCurrencyCode) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CurrencyCode is Null");
		throw lTssDiaMsgException;
	}
	if(!mCurrencyCode->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mCurrencyCode->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CurrencyCode is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mCurrencyCode->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mCurrencyCode->Decode(mspByteArray.get(), mCurrencyCode->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CurrencyCode")     ;
			throw lTssDiaMsgException;
		}
		mCurrencyCode->mAvpDecodedFlag = true;
	}
	return mCurrencyCode;
}



int CCMoney::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case CCMoney_UNITVALUE:
			{
				if( mUnitValueGrpList->size() <= 0) {
					break;
				}

				mUnitValueGrpIterator = this->getUnitValueGrpList()->begin();
				while(mUnitValueGrpIterator != mUnitValueGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(445);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
						{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(((*mUnitValueGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UnitValue");
						throw lTssDiaMsgException;
					}
					
					mUnitValueGrpIterator++;
				}
				}
				break;
			case CCMoney_CURRENCYCODE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(425);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 96;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(96))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mCurrencyCode->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mCurrencyCode->getAvpOffsetLen().first], mCurrencyCode->getAvpOffsetLen().second);
						array->offset += mCurrencyCode->getAvpOffsetLen().second;
						array->size += mCurrencyCode->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CurrencyCode");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mCurrencyCode->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CurrencyCode");
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


int CCMoney::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 445:
				{
						mMandatoryAvpSetVal [CCMoney_UNITVALUE] = 1;
					mTagsPresent[CCMoney_UNITVALUE] = 1;
					UnitValue *lUnitValue = new UnitValue();
					if( lUnitValue == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UnitValue");
						throw lTssDiaMsgException;
					}
					lUnitValue->setAvpCode(445);
					lUnitValue->SetDataType((DiameterDataType)6);
					lUnitValue->mspByteArray = mspByteArray;
					lUnitValue->mAvpDecodedFlag = false;
					lUnitValue->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mUnitValueGrpList == NULL)
						this->setUnitValueGrpList();
					mUnitValueGrpList->push_back(lUnitValue);
					mBaseInterfaceList.push_back(lUnitValue);
					
				}
				break;
			case 425:
				{
						mMandatoryAvpSetVal [CCMoney_CURRENCYCODE] = 1;
					if( NULL == this->setCurrencyCode())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CurrencyCode");
						throw lTssDiaMsgException;
					}
					mCurrencyCode->setAvpCode(425);
					mCurrencyCode->setAvpVendorId(lVenderId);
					mCurrencyCode->SetDataType((DiameterDataType)4);
					mCurrencyCode->mspByteArray = mspByteArray;
					mCurrencyCode->mAvpDecodedFlag = false;
					mCurrencyCode->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* CCMoney::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCMoney")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 425:
			{
				if(mCurrencyCode != NULL)
					return mCurrencyCode->Find(array, avpCode);
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


BOOLEAN CCMoney::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCMoney")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 445:
			{
				if(mUnitValueGrpList != NULL)
				{
					for(auto itr = mUnitValueGrpList->begin(); itr != mUnitValueGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

					if(deepInspect)
					{
						for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCode, pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 425:
			{
				if(mCurrencyCode != NULL)
				{
					DiameterBaseInterface* inf =  mCurrencyCode->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> CCMoney::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN CCMoney::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CCMoney")     ;
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
			case 445:
			{
				if(mUnitValueGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mUnitValueGrpList->begin(); itr != mUnitValueGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mUnitValueGrpList->begin(); itr != mUnitValueGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 425:
			{
				if(mCurrencyCode != NULL)
				{
					DiameterBaseInterface* inf =  mCurrencyCode->Find(this->mspByteArray.get(), avpCode);
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


INT32 CCMoney::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 CCMoney::getAvpCode()
{
	return mAvpCode;
}
INT32 CCMoney::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 CCMoney::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 CCMoney::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> CCMoney::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void CCMoney::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case CCMoney_UNITVALUE:
			{
				if( mUnitValueGrpList->size() <= 0) {
					break;
				}

				mUnitValueGrpIterator = this->getUnitValueGrpList()->begin();
				while(mUnitValueGrpIterator != this->getUnitValueGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "445" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UnitValue" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
					(*mUnitValueGrpIterator)->Display(tab+1);
					mUnitValueGrpIterator++;

				};

			}
				break;
			case CCMoney_CURRENCYCODE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "425" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CurrencyCode" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getCurrencyCode()->Display(tab+1);
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


BOOLEAN CCMoney::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case CCMoney_UNITVALUE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 445");
				}
				else
					sprintf(lMissingAvpInfo, "%s,445", lMissingAvpInfo);
			}
				break;
			case CCMoney_CURRENCYCODE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 425");
				}
				else
					sprintf(lMissingAvpInfo, "%s,425", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
