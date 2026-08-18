#include "rx/include/AccessNetworkChargingIdentifier.h"

using namespace RX;
BOOLEAN AccessNetworkChargingIdentifier::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

AccessNetworkChargingIdentifier::AccessNetworkChargingIdentifier()
{
	mAccessNetworkChargingIdentifierValue = NULL;
	mFlowsGrpList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("11"));
	mMandatoryAvpSetVal.reset();
}

AccessNetworkChargingIdentifier::~AccessNetworkChargingIdentifier()
{
	if(mAccessNetworkChargingIdentifierValue != NULL)
		delete mAccessNetworkChargingIdentifierValue;
	if(mFlowsGrpList != NULL){
		mFlowsGrpIterator = mFlowsGrpList->begin();
		while(mFlowsGrpIterator != mFlowsGrpList->end()){
	if(*mFlowsGrpIterator != NULL)
			delete (*mFlowsGrpIterator);
			mFlowsGrpIterator++;
		}
		delete mFlowsGrpList;
	}
}

OctetString* AccessNetworkChargingIdentifier::setAccessNetworkChargingIdentifierValue(){
	mMandatoryAvpSetVal [AccessNetworkChargingIdentifier_ACCESSNETWORKCHARGINGIDENTIFIERVALUE] = 1;
	if(mAccessNetworkChargingIdentifierValue == NULL)
	{
		mAccessNetworkChargingIdentifierValue = new OctetString();
		mTagsPresent[AccessNetworkChargingIdentifier_ACCESSNETWORKCHARGINGIDENTIFIERVALUE] = 1;
		return mAccessNetworkChargingIdentifierValue;
	}
	return mAccessNetworkChargingIdentifierValue;
}

void AccessNetworkChargingIdentifier::resetAccessNetworkChargingIdentifierValue(){
	mTagsPresent[AccessNetworkChargingIdentifier_ACCESSNETWORKCHARGINGIDENTIFIERVALUE] = 0;
	if(mAccessNetworkChargingIdentifierValue != NULL)
	{
		delete mAccessNetworkChargingIdentifierValue; 
		mAccessNetworkChargingIdentifierValue = NULL;
	}
}

OctetString* AccessNetworkChargingIdentifier::getAccessNetworkChargingIdentifierValue(){
	if(NULL == mAccessNetworkChargingIdentifierValue) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccessNetworkChargingIdentifierValue is Null");
		throw lTssDiaMsgException;
	}
	if(!mAccessNetworkChargingIdentifierValue->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAccessNetworkChargingIdentifierValue->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AccessNetworkChargingIdentifierValue is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAccessNetworkChargingIdentifierValue->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAccessNetworkChargingIdentifierValue->Decode(mspByteArray.get(), mAccessNetworkChargingIdentifierValue->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccessNetworkChargingIdentifierValue")     ;
			throw lTssDiaMsgException;
		}
		mAccessNetworkChargingIdentifierValue->mAvpDecodedFlag = true;
	}
	return mAccessNetworkChargingIdentifierValue;
}

list<Flows*>* AccessNetworkChargingIdentifier::getFlowsGrpList()
{
	if(mFlowsGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Flows is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mFlowsGrpList)
	{
		if(mFlowsGrpList != NULL)
		{
		if(mFlowsGrpList->size() == 0)
		{
			mTagsPresent[AccessNetworkChargingIdentifier_FLOWS] = 0;
			mFlowsGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Flows is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "Flows is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Flows")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mFlowsGrpList;
}

list<Flows*>* AccessNetworkChargingIdentifier::setFlowsGrpList(){
	mTagsPresent[AccessNetworkChargingIdentifier_FLOWS] = 1;
	if(mFlowsGrpList == NULL)
		mFlowsGrpList = new list<Flows*>;
	mMandatoryAvpSetVal[AccessNetworkChargingIdentifier_FLOWS] = 1;
	mFlowsGrpList->clear();
	return mFlowsGrpList;
}

void AccessNetworkChargingIdentifier::resetFlowsGrpList(){
	mTagsPresent[AccessNetworkChargingIdentifier_FLOWS] = 0;
	if(mFlowsGrpList != NULL)
		delete mFlowsGrpList;
}



int AccessNetworkChargingIdentifier::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case AccessNetworkChargingIdentifier_ACCESSNETWORKCHARGINGIDENTIFIERVALUE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(503);
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
					if(!mAccessNetworkChargingIdentifierValue->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAccessNetworkChargingIdentifierValue->getAvpOffsetLen().first], mAccessNetworkChargingIdentifierValue->getAvpOffsetLen().second);
						array->offset += mAccessNetworkChargingIdentifierValue->getAvpOffsetLen().second;
						array->size += mAccessNetworkChargingIdentifierValue->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mAccessNetworkChargingIdentifierValue->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mAccessNetworkChargingIdentifierValue->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccessNetworkChargingIdentifierValue");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mAccessNetworkChargingIdentifierValue->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mAccessNetworkChargingIdentifierValue->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AccessNetworkChargingIdentifierValue");
						throw lTssDiaMsgException;
					}
				}
				break;
			case AccessNetworkChargingIdentifier_FLOWS:
			{
				if( mFlowsGrpList->size() <= 0) {
					break;
				}

				mFlowsGrpIterator = this->getFlowsGrpList()->begin();
				while(mFlowsGrpIterator != mFlowsGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(510);
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
					if(((*mFlowsGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding Flows");
						throw lTssDiaMsgException;
					}
					
					mFlowsGrpIterator++;
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


int AccessNetworkChargingIdentifier::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 503:
				{
						mMandatoryAvpSetVal [AccessNetworkChargingIdentifier_ACCESSNETWORKCHARGINGIDENTIFIERVALUE] = 1;
					if( NULL == this->setAccessNetworkChargingIdentifierValue())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccessNetworkChargingIdentifierValue");
						throw lTssDiaMsgException;
					}
					mAccessNetworkChargingIdentifierValue->setAvpCode(503);
					mAccessNetworkChargingIdentifierValue->setAvpVendorId(lVenderId);
					mAccessNetworkChargingIdentifierValue->SetDataType((DiameterDataType)5);
					mAccessNetworkChargingIdentifierValue->mspByteArray = mspByteArray;
					mAccessNetworkChargingIdentifierValue->mAvpDecodedFlag = false;
					mAccessNetworkChargingIdentifierValue->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 510:
				{
						mMandatoryAvpSetVal [AccessNetworkChargingIdentifier_FLOWS] = 1;
					mTagsPresent[AccessNetworkChargingIdentifier_FLOWS] = 1;
					Flows *lFlows = new Flows();
					if( lFlows == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Flows");
						throw lTssDiaMsgException;
					}
					lFlows->setAvpCode(510);
					lFlows->SetDataType((DiameterDataType)6);
					lFlows->mspByteArray = mspByteArray;
					lFlows->mAvpDecodedFlag = false;
					lFlows->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mFlowsGrpList == NULL)
						this->setFlowsGrpList();
					mFlowsGrpList->push_back(lFlows);
					mBaseInterfaceList.push_back(lFlows);
					
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


DiameterBaseInterface* AccessNetworkChargingIdentifier::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccessNetworkChargingIdentifier")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 503:
			{
				if(mAccessNetworkChargingIdentifierValue != NULL)
					return mAccessNetworkChargingIdentifierValue->Find(array, avpCode);
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


BOOLEAN AccessNetworkChargingIdentifier::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccessNetworkChargingIdentifier")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 503:
			{
				if(mAccessNetworkChargingIdentifierValue != NULL)
				{
					DiameterBaseInterface* inf =  mAccessNetworkChargingIdentifierValue->Find(this->mspByteArray.get(), avpCode);
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
			case 510:
			{
				if(mFlowsGrpList != NULL)
				{
					for(auto itr = mFlowsGrpList->begin(); itr != mFlowsGrpList->end(); ++itr)
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
std::shared_ptr<byteArray> AccessNetworkChargingIdentifier::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN AccessNetworkChargingIdentifier::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AccessNetworkChargingIdentifier")     ;
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
			case 503:
			{
				if(mAccessNetworkChargingIdentifierValue != NULL)
				{
					DiameterBaseInterface* inf =  mAccessNetworkChargingIdentifierValue->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 510:
			{
				if(mFlowsGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mFlowsGrpList->begin(); itr != mFlowsGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mFlowsGrpList->begin(); itr != mFlowsGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
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


INT32 AccessNetworkChargingIdentifier::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 AccessNetworkChargingIdentifier::getAvpCode()
{
	return mAvpCode;
}
INT32 AccessNetworkChargingIdentifier::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 AccessNetworkChargingIdentifier::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 AccessNetworkChargingIdentifier::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> AccessNetworkChargingIdentifier::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void AccessNetworkChargingIdentifier::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case AccessNetworkChargingIdentifier_ACCESSNETWORKCHARGINGIDENTIFIERVALUE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "503" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AccessNetworkChargingIdentifierValue" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getAccessNetworkChargingIdentifierValue()->Display(tab+1);
			}
				break;
			case AccessNetworkChargingIdentifier_FLOWS:
			{
				if( mFlowsGrpList->size() <= 0) {
					break;
				}

				mFlowsGrpIterator = this->getFlowsGrpList()->begin();
				while(mFlowsGrpIterator != this->getFlowsGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "510" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "Flows" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mFlowsGrpIterator)->Display(tab+1);
					mFlowsGrpIterator++;

				};

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


BOOLEAN AccessNetworkChargingIdentifier::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case AccessNetworkChargingIdentifier_ACCESSNETWORKCHARGINGIDENTIFIERVALUE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 503");
				}
				else
					sprintf(lMissingAvpInfo, "%s,503", lMissingAvpInfo);
			}
				break;
			case AccessNetworkChargingIdentifier_FLOWS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 510");
				}
				else
					sprintf(lMissingAvpInfo, "%s,510", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
