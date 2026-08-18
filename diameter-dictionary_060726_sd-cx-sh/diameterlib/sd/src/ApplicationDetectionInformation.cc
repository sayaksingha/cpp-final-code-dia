#include "sd/include/ApplicationDetectionInformation.h"

using namespace SD;
BOOLEAN ApplicationDetectionInformation::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

ApplicationDetectionInformation::ApplicationDetectionInformation()
{
	mTDFApplicationIdentifier = NULL;
	mTDFApplicationInstanceIdentifier = NULL;
	mFlowInformationGrpList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("000"));
	mMandatoryAvpSetVal.reset();
}

ApplicationDetectionInformation::~ApplicationDetectionInformation()
{
	if(mTDFApplicationIdentifier != NULL)
		delete mTDFApplicationIdentifier;
	if(mTDFApplicationInstanceIdentifier != NULL)
		delete mTDFApplicationInstanceIdentifier;
	if(mFlowInformationGrpList != NULL){
		mFlowInformationGrpIterator = mFlowInformationGrpList->begin();
		while(mFlowInformationGrpIterator != mFlowInformationGrpList->end()){
	if(*mFlowInformationGrpIterator != NULL)
			delete (*mFlowInformationGrpIterator);
			mFlowInformationGrpIterator++;
		}
		delete mFlowInformationGrpList;
	}
}

OctetString* ApplicationDetectionInformation::setTDFApplicationIdentifier(){
	if(mTDFApplicationIdentifier == NULL)
	{
		mTDFApplicationIdentifier = new OctetString();
		mTagsPresent[ApplicationDetectionInformation_TDFAPPLICATIONIDENTIFIER] = 1;
		return mTDFApplicationIdentifier;
	}
	return mTDFApplicationIdentifier;
}

void ApplicationDetectionInformation::resetTDFApplicationIdentifier(){
	mTagsPresent[ApplicationDetectionInformation_TDFAPPLICATIONIDENTIFIER] = 0;
	if(mTDFApplicationIdentifier != NULL)
	{
		delete mTDFApplicationIdentifier; 
		mTDFApplicationIdentifier = NULL;
	}
}

OctetString* ApplicationDetectionInformation::setTDFApplicationInstanceIdentifier(){
	if(mTDFApplicationInstanceIdentifier == NULL)
	{
		mTDFApplicationInstanceIdentifier = new OctetString();
		mTagsPresent[ApplicationDetectionInformation_TDFAPPLICATIONINSTANCEIDENTIFIER] = 1;
		return mTDFApplicationInstanceIdentifier;
	}
	return mTDFApplicationInstanceIdentifier;
}

void ApplicationDetectionInformation::resetTDFApplicationInstanceIdentifier(){
	mTagsPresent[ApplicationDetectionInformation_TDFAPPLICATIONINSTANCEIDENTIFIER] = 0;
	if(mTDFApplicationInstanceIdentifier != NULL)
	{
		delete mTDFApplicationInstanceIdentifier; 
		mTDFApplicationInstanceIdentifier = NULL;
	}
}

OctetString* ApplicationDetectionInformation::getTDFApplicationIdentifier(){
	if(NULL == mTDFApplicationIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TDFApplicationIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mTDFApplicationIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTDFApplicationIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TDFApplicationIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTDFApplicationIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTDFApplicationIdentifier->Decode(mspByteArray.get(), mTDFApplicationIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TDFApplicationIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mTDFApplicationIdentifier->mAvpDecodedFlag = true;
	}
	return mTDFApplicationIdentifier;
}

OctetString* ApplicationDetectionInformation::getTDFApplicationInstanceIdentifier(){
	if(NULL == mTDFApplicationInstanceIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TDFApplicationInstanceIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mTDFApplicationInstanceIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mTDFApplicationInstanceIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TDFApplicationInstanceIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mTDFApplicationInstanceIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mTDFApplicationInstanceIdentifier->Decode(mspByteArray.get(), mTDFApplicationInstanceIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TDFApplicationInstanceIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mTDFApplicationInstanceIdentifier->mAvpDecodedFlag = true;
	}
	return mTDFApplicationInstanceIdentifier;
}

list<FlowInformation*>* ApplicationDetectionInformation::getFlowInformationGrpList()
{
	if(mFlowInformationGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowInformation is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mFlowInformationGrpList)
	{
		if(mFlowInformationGrpList != NULL)
		{
		if(mFlowInformationGrpList->size() == 0)
		{
			mTagsPresent[ApplicationDetectionInformation_FLOWINFORMATION] = 0;
			mFlowInformationGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowInformation is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowInformation is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowInformation")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mFlowInformationGrpList;
}

list<FlowInformation*>* ApplicationDetectionInformation::setFlowInformationGrpList(){
	mTagsPresent[ApplicationDetectionInformation_FLOWINFORMATION] = 1;
	if(mFlowInformationGrpList == NULL)
		mFlowInformationGrpList = new list<FlowInformation*>;
	mFlowInformationGrpList->clear();
	return mFlowInformationGrpList;
}

void ApplicationDetectionInformation::resetFlowInformationGrpList(){
	mTagsPresent[ApplicationDetectionInformation_FLOWINFORMATION] = 0;
	if(mFlowInformationGrpList != NULL)
		delete mFlowInformationGrpList;
}



int ApplicationDetectionInformation::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case ApplicationDetectionInformation_TDFAPPLICATIONIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1088);
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
					if(!mTDFApplicationIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTDFApplicationIdentifier->getAvpOffsetLen().first], mTDFApplicationIdentifier->getAvpOffsetLen().second);
						array->offset += mTDFApplicationIdentifier->getAvpOffsetLen().second;
						array->size += mTDFApplicationIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTDFApplicationIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTDFApplicationIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TDFApplicationIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTDFApplicationIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTDFApplicationIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TDFApplicationIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ApplicationDetectionInformation_TDFAPPLICATIONINSTANCEIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2802);
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
					if(!mTDFApplicationInstanceIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mTDFApplicationInstanceIdentifier->getAvpOffsetLen().first], mTDFApplicationInstanceIdentifier->getAvpOffsetLen().second);
						array->offset += mTDFApplicationInstanceIdentifier->getAvpOffsetLen().second;
						array->size += mTDFApplicationInstanceIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mTDFApplicationInstanceIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mTDFApplicationInstanceIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TDFApplicationInstanceIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mTDFApplicationInstanceIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mTDFApplicationInstanceIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TDFApplicationInstanceIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case ApplicationDetectionInformation_FLOWINFORMATION:
			{
				if( mFlowInformationGrpList->size() <= 0) {
					break;
				}

				mFlowInformationGrpIterator = this->getFlowInformationGrpList()->begin();
				while(mFlowInformationGrpIterator != mFlowInformationGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(1058);
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
					if(((*mFlowInformationGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowInformation");
						throw lTssDiaMsgException;
					}
					
					mFlowInformationGrpIterator++;
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


int ApplicationDetectionInformation::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1088:
				{
					if( NULL == this->setTDFApplicationIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TDFApplicationIdentifier");
						throw lTssDiaMsgException;
					}
					mTDFApplicationIdentifier->setAvpCode(1088);
					mTDFApplicationIdentifier->setAvpVendorId(lVenderId);
					mTDFApplicationIdentifier->SetDataType((DiameterDataType)5);
					mTDFApplicationIdentifier->mspByteArray = mspByteArray;
					mTDFApplicationIdentifier->mAvpDecodedFlag = false;
					mTDFApplicationIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2802:
				{
					if( NULL == this->setTDFApplicationInstanceIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TDFApplicationInstanceIdentifier");
						throw lTssDiaMsgException;
					}
					mTDFApplicationInstanceIdentifier->setAvpCode(2802);
					mTDFApplicationInstanceIdentifier->setAvpVendorId(lVenderId);
					mTDFApplicationInstanceIdentifier->SetDataType((DiameterDataType)5);
					mTDFApplicationInstanceIdentifier->mspByteArray = mspByteArray;
					mTDFApplicationInstanceIdentifier->mAvpDecodedFlag = false;
					mTDFApplicationInstanceIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1058:
				{
					mTagsPresent[ApplicationDetectionInformation_FLOWINFORMATION] = 1;
					FlowInformation *lFlowInformation = new FlowInformation();
					if( lFlowInformation == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowInformation");
						throw lTssDiaMsgException;
					}
					lFlowInformation->setAvpCode(1058);
					lFlowInformation->SetDataType((DiameterDataType)6);
					lFlowInformation->mspByteArray = mspByteArray;
					lFlowInformation->mAvpDecodedFlag = false;
					lFlowInformation->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mFlowInformationGrpList == NULL)
						this->setFlowInformationGrpList();
					mFlowInformationGrpList->push_back(lFlowInformation);
					mBaseInterfaceList.push_back(lFlowInformation);
					
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


DiameterBaseInterface* ApplicationDetectionInformation::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ApplicationDetectionInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1088:
			{
				if(mTDFApplicationIdentifier != NULL)
					return mTDFApplicationIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 2802:
			{
				if(mTDFApplicationInstanceIdentifier != NULL)
					return mTDFApplicationInstanceIdentifier->Find(array, avpCode);
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


BOOLEAN ApplicationDetectionInformation::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ApplicationDetectionInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1088:
			{
				if(mTDFApplicationIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mTDFApplicationIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 2802:
			{
				if(mTDFApplicationInstanceIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mTDFApplicationInstanceIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 1058:
			{
				if(mFlowInformationGrpList != NULL)
				{
					for(auto itr = mFlowInformationGrpList->begin(); itr != mFlowInformationGrpList->end(); ++itr)
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
std::shared_ptr<byteArray> ApplicationDetectionInformation::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN ApplicationDetectionInformation::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ApplicationDetectionInformation")     ;
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
			case 1088:
			{
				if(mTDFApplicationIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mTDFApplicationIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2802:
			{
				if(mTDFApplicationInstanceIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mTDFApplicationInstanceIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1058:
			{
				if(mFlowInformationGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mFlowInformationGrpList->begin(); itr != mFlowInformationGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mFlowInformationGrpList->begin(); itr != mFlowInformationGrpList->end(); ++itr)
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


INT32 ApplicationDetectionInformation::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 ApplicationDetectionInformation::getAvpCode()
{
	return mAvpCode;
}
INT32 ApplicationDetectionInformation::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 ApplicationDetectionInformation::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 ApplicationDetectionInformation::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> ApplicationDetectionInformation::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void ApplicationDetectionInformation::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case ApplicationDetectionInformation_TDFAPPLICATIONIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1088" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TDFApplicationIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getTDFApplicationIdentifier()->Display(tab+1);
			}
				break;
			case ApplicationDetectionInformation_TDFAPPLICATIONINSTANCEIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2802" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TDFApplicationInstanceIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getTDFApplicationInstanceIdentifier()->Display(tab+1);
			}
				break;
			case ApplicationDetectionInformation_FLOWINFORMATION:
			{
				if( mFlowInformationGrpList->size() <= 0) {
					break;
				}

				mFlowInformationGrpIterator = this->getFlowInformationGrpList()->begin();
				while(mFlowInformationGrpIterator != this->getFlowInformationGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1058" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowInformation" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mFlowInformationGrpIterator)->Display(tab+1);
					mFlowInformationGrpIterator++;

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


BOOLEAN ApplicationDetectionInformation::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case ApplicationDetectionInformation_TDFAPPLICATIONIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1088");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1088", lMissingAvpInfo);
			}
				break;
			case ApplicationDetectionInformation_TDFAPPLICATIONINSTANCEIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2802");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2802", lMissingAvpInfo);
			}
				break;
			case ApplicationDetectionInformation_FLOWINFORMATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1058");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1058", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
