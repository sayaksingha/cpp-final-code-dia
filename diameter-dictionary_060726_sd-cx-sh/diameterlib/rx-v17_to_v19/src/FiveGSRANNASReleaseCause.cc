#include "rx/include/FiveGSRANNASReleaseCause.h"

using namespace RX;
BOOLEAN FiveGSRANNASReleaseCause::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

FiveGSRANNASReleaseCause::FiveGSRANNASReleaseCause()
{
	mFiveGMMCause = NULL;
	mFiveGSMCause = NULL;
	mNGAPCauseGrpList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<3>(string("000"));
	mMandatoryAvpSetVal.reset();
}

FiveGSRANNASReleaseCause::~FiveGSRANNASReleaseCause()
{
	if(mFiveGMMCause != NULL)
		delete mFiveGMMCause;
	if(mFiveGSMCause != NULL)
		delete mFiveGSMCause;
	if(mNGAPCauseGrpList != NULL){
		mNGAPCauseGrpIterator = mNGAPCauseGrpList->begin();
		while(mNGAPCauseGrpIterator != mNGAPCauseGrpList->end()){
	if(*mNGAPCauseGrpIterator != NULL)
			delete (*mNGAPCauseGrpIterator);
			mNGAPCauseGrpIterator++;
		}
		delete mNGAPCauseGrpList;
	}
}

Unsigned32* FiveGSRANNASReleaseCause::setFiveGMMCause(){
	if(mFiveGMMCause == NULL)
	{
		mFiveGMMCause = new Unsigned32();
		mTagsPresent[FiveGSRANNASReleaseCause_FIVEGMMCAUSE] = 1;
		return mFiveGMMCause;
	}
	return mFiveGMMCause;
}

void FiveGSRANNASReleaseCause::resetFiveGMMCause(){
	mTagsPresent[FiveGSRANNASReleaseCause_FIVEGMMCAUSE] = 0;
	if(mFiveGMMCause != NULL)
	{
		delete mFiveGMMCause; 
		mFiveGMMCause = NULL;
	}
}

Unsigned32* FiveGSRANNASReleaseCause::setFiveGSMCause(){
	if(mFiveGSMCause == NULL)
	{
		mFiveGSMCause = new Unsigned32();
		mTagsPresent[FiveGSRANNASReleaseCause_FIVEGSMCAUSE] = 1;
		return mFiveGSMCause;
	}
	return mFiveGSMCause;
}

void FiveGSRANNASReleaseCause::resetFiveGSMCause(){
	mTagsPresent[FiveGSRANNASReleaseCause_FIVEGSMCAUSE] = 0;
	if(mFiveGSMCause != NULL)
	{
		delete mFiveGSMCause; 
		mFiveGSMCause = NULL;
	}
}

Unsigned32* FiveGSRANNASReleaseCause::getFiveGMMCause(){
	if(NULL == mFiveGMMCause) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FiveGMMCause is Null");
		throw lTssDiaMsgException;
	}
	if(!mFiveGMMCause->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFiveGMMCause->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FiveGMMCause is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFiveGMMCause->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFiveGMMCause->Decode(mspByteArray.get(), mFiveGMMCause->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FiveGMMCause")     ;
			throw lTssDiaMsgException;
		}
		mFiveGMMCause->mAvpDecodedFlag = true;
	}
	return mFiveGMMCause;
}

Unsigned32* FiveGSRANNASReleaseCause::getFiveGSMCause(){
	if(NULL == mFiveGSMCause) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FiveGSMCause is Null");
		throw lTssDiaMsgException;
	}
	if(!mFiveGSMCause->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFiveGSMCause->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FiveGSMCause is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFiveGSMCause->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFiveGSMCause->Decode(mspByteArray.get(), mFiveGSMCause->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FiveGSMCause")     ;
			throw lTssDiaMsgException;
		}
		mFiveGSMCause->mAvpDecodedFlag = true;
	}
	return mFiveGSMCause;
}

list<NGAPCause*>* FiveGSRANNASReleaseCause::getNGAPCauseGrpList()
{
	if(mNGAPCauseGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "NGAPCause is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mNGAPCauseGrpList)
	{
		if(mNGAPCauseGrpList != NULL)
		{
		if(mNGAPCauseGrpList->size() == 0)
		{
			mTagsPresent[FiveGSRANNASReleaseCause_NGAPCAUSE] = 0;
			mNGAPCauseGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "NGAPCause is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "NGAPCause is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NGAPCause")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mNGAPCauseGrpList;
}

list<NGAPCause*>* FiveGSRANNASReleaseCause::setNGAPCauseGrpList(){
	mTagsPresent[FiveGSRANNASReleaseCause_NGAPCAUSE] = 1;
	if(mNGAPCauseGrpList == NULL)
		mNGAPCauseGrpList = new list<NGAPCause*>;
	mNGAPCauseGrpList->clear();
	return mNGAPCauseGrpList;
}

void FiveGSRANNASReleaseCause::resetNGAPCauseGrpList(){
	mTagsPresent[FiveGSRANNASReleaseCause_NGAPCAUSE] = 0;
	if(mNGAPCauseGrpList != NULL)
		delete mNGAPCauseGrpList;
}



int FiveGSRANNASReleaseCause::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case FiveGSRANNASReleaseCause_FIVEGMMCAUSE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(573);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 160;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(160))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mFiveGMMCause->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFiveGMMCause->getAvpOffsetLen().first], mFiveGMMCause->getAvpOffsetLen().second);
						array->offset += mFiveGMMCause->getAvpOffsetLen().second;
						array->size += mFiveGMMCause->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FiveGMMCause");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFiveGMMCause->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FiveGMMCause");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FiveGSRANNASReleaseCause_FIVEGSMCAUSE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(574);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 160;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(160))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mFiveGSMCause->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFiveGSMCause->getAvpOffsetLen().first], mFiveGSMCause->getAvpOffsetLen().second);
						array->offset += mFiveGSMCause->getAvpOffsetLen().second;
						array->size += mFiveGSMCause->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FiveGSMCause");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFiveGSMCause->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FiveGSMCause");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FiveGSRANNASReleaseCause_NGAPCAUSE:
			{
				if( mNGAPCauseGrpList->size() <= 0) {
					break;
				}

				mNGAPCauseGrpIterator = this->getNGAPCauseGrpList()->begin();
				while(mNGAPCauseGrpIterator != mNGAPCauseGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(575);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 160;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(160))
						{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(((*mNGAPCauseGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding NGAPCause");
						throw lTssDiaMsgException;
					}
					
					mNGAPCauseGrpIterator++;
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


int FiveGSRANNASReleaseCause::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 573:
				{
					if( NULL == this->setFiveGMMCause())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FiveGMMCause");
						throw lTssDiaMsgException;
					}
					mFiveGMMCause->setAvpCode(573);
					mFiveGMMCause->setAvpVendorId(lVenderId);
					mFiveGMMCause->SetDataType((DiameterDataType)3);
					mFiveGMMCause->mspByteArray = mspByteArray;
					mFiveGMMCause->mAvpDecodedFlag = false;
					mFiveGMMCause->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 574:
				{
					if( NULL == this->setFiveGSMCause())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FiveGSMCause");
						throw lTssDiaMsgException;
					}
					mFiveGSMCause->setAvpCode(574);
					mFiveGSMCause->setAvpVendorId(lVenderId);
					mFiveGSMCause->SetDataType((DiameterDataType)3);
					mFiveGSMCause->mspByteArray = mspByteArray;
					mFiveGSMCause->mAvpDecodedFlag = false;
					mFiveGSMCause->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 575:
				{
					mTagsPresent[FiveGSRANNASReleaseCause_NGAPCAUSE] = 1;
					NGAPCause *lNGAPCause = new NGAPCause();
					if( lNGAPCause == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding NGAPCause");
						throw lTssDiaMsgException;
					}
					lNGAPCause->setAvpCode(575);
					lNGAPCause->SetDataType((DiameterDataType)6);
					lNGAPCause->mspByteArray = mspByteArray;
					lNGAPCause->mAvpDecodedFlag = false;
					lNGAPCause->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mNGAPCauseGrpList == NULL)
						this->setNGAPCauseGrpList();
					mNGAPCauseGrpList->push_back(lNGAPCause);
					mBaseInterfaceList.push_back(lNGAPCause);
					
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


DiameterBaseInterface* FiveGSRANNASReleaseCause::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FiveGSRANNASReleaseCause")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 573:
			{
				if(mFiveGMMCause != NULL)
					return mFiveGMMCause->Find(array, avpCode);
				else
					return NULL;
			}
			case 574:
			{
				if(mFiveGSMCause != NULL)
					return mFiveGSMCause->Find(array, avpCode);
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


BOOLEAN FiveGSRANNASReleaseCause::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FiveGSRANNASReleaseCause")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 573:
			{
				if(mFiveGMMCause != NULL)
				{
					DiameterBaseInterface* inf =  mFiveGMMCause->Find(this->mspByteArray.get(), avpCode);
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
			case 574:
			{
				if(mFiveGSMCause != NULL)
				{
					DiameterBaseInterface* inf =  mFiveGSMCause->Find(this->mspByteArray.get(), avpCode);
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
			case 575:
			{
				if(mNGAPCauseGrpList != NULL)
				{
					for(auto itr = mNGAPCauseGrpList->begin(); itr != mNGAPCauseGrpList->end(); ++itr)
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
std::shared_ptr<byteArray> FiveGSRANNASReleaseCause::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN FiveGSRANNASReleaseCause::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FiveGSRANNASReleaseCause")     ;
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
			case 573:
			{
				if(mFiveGMMCause != NULL)
				{
					DiameterBaseInterface* inf =  mFiveGMMCause->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 574:
			{
				if(mFiveGSMCause != NULL)
				{
					DiameterBaseInterface* inf =  mFiveGSMCause->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 575:
			{
				if(mNGAPCauseGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mNGAPCauseGrpList->begin(); itr != mNGAPCauseGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mNGAPCauseGrpList->begin(); itr != mNGAPCauseGrpList->end(); ++itr)
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


INT32 FiveGSRANNASReleaseCause::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 FiveGSRANNASReleaseCause::getAvpCode()
{
	return mAvpCode;
}
INT32 FiveGSRANNASReleaseCause::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 FiveGSRANNASReleaseCause::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 FiveGSRANNASReleaseCause::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> FiveGSRANNASReleaseCause::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void FiveGSRANNASReleaseCause::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case FiveGSRANNASReleaseCause_FIVEGMMCAUSE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "573" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FiveGMMCause" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getFiveGMMCause()->Display(tab+1);
			}
				break;
			case FiveGSRANNASReleaseCause_FIVEGSMCAUSE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "574" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FiveGSMCause" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
				this->getFiveGSMCause()->Display(tab+1);
			}
				break;
			case FiveGSRANNASReleaseCause_NGAPCAUSE:
			{
				if( mNGAPCauseGrpList->size() <= 0) {
					break;
				}

				mNGAPCauseGrpIterator = this->getNGAPCauseGrpList()->begin();
				while(mNGAPCauseGrpIterator != this->getNGAPCauseGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "575" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "NGAPCause" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(160)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(160)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(160)==true)?"Protected":""));
					(*mNGAPCauseGrpIterator)->Display(tab+1);
					mNGAPCauseGrpIterator++;

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


BOOLEAN FiveGSRANNASReleaseCause::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<3> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case FiveGSRANNASReleaseCause_FIVEGMMCAUSE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 573");
				}
				else
					sprintf(lMissingAvpInfo, "%s,573", lMissingAvpInfo);
			}
				break;
			case FiveGSRANNASReleaseCause_FIVEGSMCAUSE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 574");
				}
				else
					sprintf(lMissingAvpInfo, "%s,574", lMissingAvpInfo);
			}
				break;
			case FiveGSRANNASReleaseCause_NGAPCAUSE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 575");
				}
				else
					sprintf(lMissingAvpInfo, "%s,575", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
