#include "rx/include/Flows.h"

using namespace RX;
BOOLEAN Flows::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

Flows::Flows()
{
	mMediaComponentNumber = NULL;
	mFlowNumberList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("11"));
	mMandatoryAvpSetVal.reset();
}

Flows::~Flows()
{
	if(mMediaComponentNumber != NULL)
		delete mMediaComponentNumber;
	if(mFlowNumberList != NULL){
		mFlowNumberIterator = mFlowNumberList->begin();
		while(mFlowNumberIterator != mFlowNumberList->end()){
			delete (*mFlowNumberIterator);
			mFlowNumberIterator++;
		}
		delete mFlowNumberList;
	}
}

Unsigned32* Flows::setMediaComponentNumber(){
	mMandatoryAvpSetVal [Flows_MEDIACOMPONENTNUMBER] = 1;
	if(mMediaComponentNumber == NULL)
	{
		mMediaComponentNumber = new Unsigned32();
		mTagsPresent[Flows_MEDIACOMPONENTNUMBER] = 1;
		return mMediaComponentNumber;
	}
	return mMediaComponentNumber;
}

void Flows::resetMediaComponentNumber(){
	mTagsPresent[Flows_MEDIACOMPONENTNUMBER] = 0;
	if(mMediaComponentNumber != NULL)
	{
		delete mMediaComponentNumber; 
		mMediaComponentNumber = NULL;
	}
}

Unsigned32* Flows::getMediaComponentNumber(){
	if(NULL == mMediaComponentNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaComponentNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mMediaComponentNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMediaComponentNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaComponentNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMediaComponentNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMediaComponentNumber->Decode(mspByteArray.get(), mMediaComponentNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaComponentNumber")     ;
			throw lTssDiaMsgException;
		}
		mMediaComponentNumber->mAvpDecodedFlag = true;
	}
	return mMediaComponentNumber;
}

list<Unsigned32*>* Flows::getFlowNumberList()
{
	if(mFlowNumberList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowNumber is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mFlowNumberList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowNumber is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowNumber")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mFlowNumberList;
}

list<Unsigned32*>* Flows::setFlowNumberList() {
	mTagsPresent[Flows_FLOWNUMBER] = 1;
	if(mFlowNumberList == NULL)
		mFlowNumberList = new list<Unsigned32*>;
	mMandatoryAvpSetVal [Flows_FLOWNUMBER] = 1;
	mFlowNumberList->clear();
	return mFlowNumberList;
}

void Flows::resetFlowNumberList(){
	mTagsPresent[Flows_FLOWNUMBER] = 0;
	if(mFlowNumberList != NULL)
		delete mFlowNumberList;
}



int Flows::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case Flows_MEDIACOMPONENTNUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(518);
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
					if(!mMediaComponentNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMediaComponentNumber->getAvpOffsetLen().first], mMediaComponentNumber->getAvpOffsetLen().second);
						array->offset += mMediaComponentNumber->getAvpOffsetLen().second;
						array->size += mMediaComponentNumber->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MediaComponentNumber");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMediaComponentNumber->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MediaComponentNumber");
						throw lTssDiaMsgException;
					}
				}
				break;
			case Flows_FLOWNUMBER:
			{
					if( mFlowNumberList->size() <= 0) {
						break;
					}

					mFlowNumberIterator = this->getFlowNumberList()->begin();
					while(mFlowNumberIterator != mFlowNumberList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(509);
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
					if(!(*mFlowNumberIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mFlowNumberIterator)->getAvpOffsetLen().first], (*mFlowNumberIterator)->getAvpOffsetLen().second);
						array->offset += (*mFlowNumberIterator)->getAvpOffsetLen().second;
						array->size += (*mFlowNumberIterator)->getAvpOffsetLen().second;
						if(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)
						{
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowNumber");
							throw lTssDiaMsgException;
						}
						mFlowNumberIterator++;
						continue;
					}
					if(((*mFlowNumberIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowNumber");
						throw lTssDiaMsgException;
					}
					mFlowNumberIterator++;
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


int Flows::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 518:
				{
						mMandatoryAvpSetVal [Flows_MEDIACOMPONENTNUMBER] = 1;
					if( NULL == this->setMediaComponentNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaComponentNumber");
						throw lTssDiaMsgException;
					}
					mMediaComponentNumber->setAvpCode(518);
					mMediaComponentNumber->setAvpVendorId(lVenderId);
					mMediaComponentNumber->SetDataType((DiameterDataType)3);
					mMediaComponentNumber->mspByteArray = mspByteArray;
					mMediaComponentNumber->mAvpDecodedFlag = false;
					mMediaComponentNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 509:
				{
						mMandatoryAvpSetVal [Flows_FLOWNUMBER] = 1;
					mTagsPresent[Flows_FLOWNUMBER] = 1;
					Unsigned32 *lFlowNumber = new Unsigned32();
					if( lFlowNumber == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowNumber");
						throw lTssDiaMsgException;
					}
					lFlowNumber->setAvpCode(509);
					lFlowNumber->setAvpVendorId(lVenderId);
					lFlowNumber->SetDataType((DiameterDataType)3);
					lFlowNumber->mspByteArray = mspByteArray;
					lFlowNumber->mAvpDecodedFlag = false;
					lFlowNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mFlowNumberList == NULL)
						this->setFlowNumberList();
					mFlowNumberList->push_back(lFlowNumber);
					
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


DiameterBaseInterface* Flows::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Flows")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 518:
			{
				if(mMediaComponentNumber != NULL)
					return mMediaComponentNumber->Find(array, avpCode);
				else
					return NULL;
			}
			case 509:
			{
				if(mFlowNumberList != NULL && mFlowNumberList->size() > 0)
					return (mFlowNumberList->back())->Find(array, avpCode);
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


BOOLEAN Flows::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Flows")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 518:
			{
				if(mMediaComponentNumber != NULL)
				{
					DiameterBaseInterface* inf =  mMediaComponentNumber->Find(this->mspByteArray.get(), avpCode);
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
			case 509:
			{
				if(mFlowNumberList != NULL)
				{
					for(auto itr = mFlowNumberList->begin(); itr != mFlowNumberList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> Flows::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN Flows::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding Flows")     ;
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
			case 518:
			{
				if(mMediaComponentNumber != NULL)
				{
					DiameterBaseInterface* inf =  mMediaComponentNumber->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 509:
			{
				if(mFlowNumberList != NULL)
				{
					for(auto itr = mFlowNumberList->begin(); itr != mFlowNumberList->end(); ++itr)
					{
						DiameterBaseInterface* inf =  (*itr)->Find(this->mspByteArray.get(), avpCode);
						if(inf != NULL)
						{
							pBaseInterface.push_back(inf);
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


INT32 Flows::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 Flows::getAvpCode()
{
	return mAvpCode;
}
INT32 Flows::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 Flows::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 Flows::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> Flows::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void Flows::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case Flows_MEDIACOMPONENTNUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "518" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MediaComponentNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMediaComponentNumber()->Display(tab+1);
			}
				break;
			case Flows_FLOWNUMBER:
			{
				if( mFlowNumberList->size() <= 0) {
					break;
				}

				mFlowNumberIterator = this->getFlowNumberList()->begin();
				while(mFlowNumberIterator != this->getFlowNumberList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "509" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowNumber" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mFlowNumberIterator)->Display(tab+1);
					mFlowNumberIterator++;

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


BOOLEAN Flows::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case Flows_MEDIACOMPONENTNUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 518");
				}
				else
					sprintf(lMissingAvpInfo, "%s,518", lMissingAvpInfo);
			}
				break;
			case Flows_FLOWNUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 509");
				}
				else
					sprintf(lMissingAvpInfo, "%s,509", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
