#include "sd/include/FinalUnitIndication.h"

using namespace SD;
BOOLEAN FinalUnitIndication::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

FinalUnitIndication::FinalUnitIndication()
{
	mFinalUnitAction = NULL;
	mRestrictionFilterRuleList = NULL;
	mFilterIdList = NULL;
	mRedirectServerGrp = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<4>(string("1111"));
	mMandatoryAvpSetVal.reset();
}

FinalUnitIndication::~FinalUnitIndication()
{
	if(mFinalUnitAction != NULL)
		delete mFinalUnitAction;
	if(mRestrictionFilterRuleList != NULL){
		mRestrictionFilterRuleIterator = mRestrictionFilterRuleList->begin();
		while(mRestrictionFilterRuleIterator != mRestrictionFilterRuleList->end()){
			delete (*mRestrictionFilterRuleIterator);
			mRestrictionFilterRuleIterator++;
		}
		delete mRestrictionFilterRuleList;
	}
	if(mFilterIdList != NULL){
		mFilterIdIterator = mFilterIdList->begin();
		while(mFilterIdIterator != mFilterIdList->end()){
			delete (*mFilterIdIterator);
			mFilterIdIterator++;
		}
		delete mFilterIdList;
	}
	if(mRedirectServerGrp != NULL)
		delete mRedirectServerGrp;
}

FinalUnitAction* FinalUnitIndication::setFinalUnitAction(){
	mMandatoryAvpSetVal [FinalUnitIndication_FINALUNITACTION] = 1;
	if(mFinalUnitAction == NULL)
	{
		mFinalUnitAction = new FinalUnitAction();
		mTagsPresent[FinalUnitIndication_FINALUNITACTION] = 1;
		return mFinalUnitAction;
	}
	return mFinalUnitAction;
}

void FinalUnitIndication::resetFinalUnitAction(){
	mTagsPresent[FinalUnitIndication_FINALUNITACTION] = 0;
	if(mFinalUnitAction != NULL)
	{
		delete mFinalUnitAction; 
		mFinalUnitAction = NULL;
	}
}

FinalUnitAction* FinalUnitIndication::getFinalUnitAction(){
	if(NULL == mFinalUnitAction) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FinalUnitAction is Null");
		throw lTssDiaMsgException;
	}
	if(!mFinalUnitAction->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFinalUnitAction->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FinalUnitAction is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFinalUnitAction->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFinalUnitAction->Decode(mspByteArray.get(), mFinalUnitAction->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FinalUnitAction")     ;
			throw lTssDiaMsgException;
		}
		mFinalUnitAction->mAvpDecodedFlag = true;
	}
	return mFinalUnitAction;
}

list<OctetString*>* FinalUnitIndication::getRestrictionFilterRuleList()
{
	if(mRestrictionFilterRuleList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RestrictionFilterRule is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mRestrictionFilterRuleList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RestrictionFilterRule is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RestrictionFilterRule")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mRestrictionFilterRuleList;
}

list<OctetString*>* FinalUnitIndication::setRestrictionFilterRuleList() {
	mTagsPresent[FinalUnitIndication_RESTRICTIONFILTERRULE] = 1;
	if(mRestrictionFilterRuleList == NULL)
		mRestrictionFilterRuleList = new list<OctetString*>;
	mMandatoryAvpSetVal [FinalUnitIndication_RESTRICTIONFILTERRULE] = 1;
	mRestrictionFilterRuleList->clear();
	return mRestrictionFilterRuleList;
}

void FinalUnitIndication::resetRestrictionFilterRuleList(){
	mTagsPresent[FinalUnitIndication_RESTRICTIONFILTERRULE] = 0;
	if(mRestrictionFilterRuleList != NULL)
		delete mRestrictionFilterRuleList;
}

list<OctetString*>* FinalUnitIndication::getFilterIdList()
{
	if(mFilterIdList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FilterId is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mFilterIdList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FilterId is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FilterId")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mFilterIdList;
}

list<OctetString*>* FinalUnitIndication::setFilterIdList() {
	mTagsPresent[FinalUnitIndication_FILTERID] = 1;
	if(mFilterIdList == NULL)
		mFilterIdList = new list<OctetString*>;
	mMandatoryAvpSetVal [FinalUnitIndication_FILTERID] = 1;
	mFilterIdList->clear();
	return mFilterIdList;
}

void FinalUnitIndication::resetFilterIdList(){
	mTagsPresent[FinalUnitIndication_FILTERID] = 0;
	if(mFilterIdList != NULL)
		delete mFilterIdList;
}

RedirectServer* FinalUnitIndication::getRedirectServer()
{
	if(mRedirectServerGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectServer is Null");
		throw lTssDiaMsgException;
	}
	if(!mRedirectServerGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRedirectServerGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RedirectServer is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRedirectServerGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRedirectServerGrp->Decode(mspByteArray.get(), mRedirectServerGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectServer")     ;
			throw lTssDiaMsgException;
		}
		mRedirectServerGrp->mAvpDecodedFlag = true;
	}
	return mRedirectServerGrp;
}

RedirectServer* FinalUnitIndication::setRedirectServer(){
	if(mRedirectServerGrp == NULL)
		mRedirectServerGrp = new RedirectServer();
	mTagsPresent[FinalUnitIndication_REDIRECTSERVER] = 1;
	mMandatoryAvpSetVal[FinalUnitIndication_REDIRECTSERVER] = 1;
	return mRedirectServerGrp;
}

void FinalUnitIndication::resetRedirectServer(){
	mTagsPresent[FinalUnitIndication_REDIRECTSERVER] = 0;
	if(mRedirectServerGrp != NULL)
		delete mRedirectServerGrp;
}



int FinalUnitIndication::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case FinalUnitIndication_FINALUNITACTION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(449);
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
					if(!mFinalUnitAction->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFinalUnitAction->getAvpOffsetLen().first], mFinalUnitAction->getAvpOffsetLen().second);
						array->offset += mFinalUnitAction->getAvpOffsetLen().second;
						array->size += mFinalUnitAction->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FinalUnitAction");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFinalUnitAction->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FinalUnitAction");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FinalUnitIndication_RESTRICTIONFILTERRULE:
			{
					if( mRestrictionFilterRuleList->size() <= 0) {
						break;
					}

					mRestrictionFilterRuleIterator = this->getRestrictionFilterRuleList()->begin();
					while(mRestrictionFilterRuleIterator != mRestrictionFilterRuleList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(438);
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
					if(!(*mRestrictionFilterRuleIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mRestrictionFilterRuleIterator)->getAvpOffsetLen().first], (*mRestrictionFilterRuleIterator)->getAvpOffsetLen().second);
						array->offset += (*mRestrictionFilterRuleIterator)->getAvpOffsetLen().second;
						array->size += (*mRestrictionFilterRuleIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mRestrictionFilterRuleIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mRestrictionFilterRuleIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RestrictionFilterRule");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mRestrictionFilterRuleIterator++;
						continue;
					}
						if(((*mRestrictionFilterRuleIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mRestrictionFilterRuleIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RestrictionFilterRule");
							throw lTssDiaMsgException;
						}
						mRestrictionFilterRuleIterator++;
				}
				}
				break;
			case FinalUnitIndication_FILTERID:
			{
					if( mFilterIdList->size() <= 0) {
						break;
					}

					mFilterIdIterator = this->getFilterIdList()->begin();
					while(mFilterIdIterator != mFilterIdList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(11);
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
					if(!(*mFilterIdIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mFilterIdIterator)->getAvpOffsetLen().first], (*mFilterIdIterator)->getAvpOffsetLen().second);
						array->offset += (*mFilterIdIterator)->getAvpOffsetLen().second;
						array->size += (*mFilterIdIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mFilterIdIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mFilterIdIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FilterId");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mFilterIdIterator++;
						continue;
					}
						if(((*mFilterIdIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mFilterIdIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FilterId");
							throw lTssDiaMsgException;
						}
						mFilterIdIterator++;
				}
				}
				break;
			case FinalUnitIndication_REDIRECTSERVER:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(434);
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
				if((this->getRedirectServer()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RedirectServer");
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


int FinalUnitIndication::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 449:
				{
						mMandatoryAvpSetVal [FinalUnitIndication_FINALUNITACTION] = 1;
					if( NULL == this->setFinalUnitAction())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FinalUnitAction");
						throw lTssDiaMsgException;
					}
					mFinalUnitAction->setAvpCode(449);
					mFinalUnitAction->setAvpVendorId(lVenderId);
					mFinalUnitAction->SetDataType((DiameterDataType)7);
					mFinalUnitAction->mspByteArray = mspByteArray;
					mFinalUnitAction->mAvpDecodedFlag = false;
					mFinalUnitAction->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 438:
				{
						mMandatoryAvpSetVal [FinalUnitIndication_RESTRICTIONFILTERRULE] = 1;
					mTagsPresent[FinalUnitIndication_RESTRICTIONFILTERRULE] = 1;
					OctetString *lRestrictionFilterRule = new OctetString();
					if( lRestrictionFilterRule == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RestrictionFilterRule");
						throw lTssDiaMsgException;
					}
					lRestrictionFilterRule->setAvpCode(438);
					lRestrictionFilterRule->setAvpVendorId(lVenderId);
					lRestrictionFilterRule->SetDataType((DiameterDataType)5);
					lRestrictionFilterRule->mspByteArray = mspByteArray;
					lRestrictionFilterRule->mAvpDecodedFlag = false;
					lRestrictionFilterRule->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mRestrictionFilterRuleList == NULL)
						this->setRestrictionFilterRuleList();
					mRestrictionFilterRuleList->push_back(lRestrictionFilterRule);
					
				}
				break;
			case 11:
				{
						mMandatoryAvpSetVal [FinalUnitIndication_FILTERID] = 1;
					mTagsPresent[FinalUnitIndication_FILTERID] = 1;
					OctetString *lFilterId = new OctetString();
					if( lFilterId == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FilterId");
						throw lTssDiaMsgException;
					}
					lFilterId->setAvpCode(11);
					lFilterId->setAvpVendorId(lVenderId);
					lFilterId->SetDataType((DiameterDataType)5);
					lFilterId->mspByteArray = mspByteArray;
					lFilterId->mAvpDecodedFlag = false;
					lFilterId->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mFilterIdList == NULL)
						this->setFilterIdList();
					mFilterIdList->push_back(lFilterId);
					
				}
				break;
			case 434:
				{
						mMandatoryAvpSetVal [FinalUnitIndication_REDIRECTSERVER] = 1;
					mTagsPresent[FinalUnitIndication_REDIRECTSERVER] = 1;
						if( NULL == this->setRedirectServer()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RedirectServer");
						throw lTssDiaMsgException;
						}
					mRedirectServerGrp->setAvpCode(434);
					mRedirectServerGrp->SetDataType((DiameterDataType)6);
					mRedirectServerGrp->mspByteArray = mspByteArray;
					mRedirectServerGrp->mAvpDecodedFlag = false;
					mRedirectServerGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mRedirectServerGrp);
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


DiameterBaseInterface* FinalUnitIndication::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FinalUnitIndication")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 449:
			{
				if(mFinalUnitAction != NULL)
					return mFinalUnitAction->Find(array, avpCode);
				else
					return NULL;
			}
			case 438:
			{
				if(mRestrictionFilterRuleList != NULL && mRestrictionFilterRuleList->size() > 0)
					return (mRestrictionFilterRuleList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 11:
			{
				if(mFilterIdList != NULL && mFilterIdList->size() > 0)
					return (mFilterIdList->back())->Find(array, avpCode);
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


BOOLEAN FinalUnitIndication::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FinalUnitIndication")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 449:
			{
				if(mFinalUnitAction != NULL)
				{
					DiameterBaseInterface* inf =  mFinalUnitAction->Find(this->mspByteArray.get(), avpCode);
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
			case 438:
			{
				if(mRestrictionFilterRuleList != NULL)
				{
					for(auto itr = mRestrictionFilterRuleList->begin(); itr != mRestrictionFilterRuleList->end(); ++itr)
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
			case 11:
			{
				if(mFilterIdList != NULL)
				{
					for(auto itr = mFilterIdList->begin(); itr != mFilterIdList->end(); ++itr)
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
			case 434:
			{
				if(mRedirectServerGrp != NULL)
				{
						pBaseInterface.push_back(mRedirectServerGrp);
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
std::shared_ptr<byteArray> FinalUnitIndication::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN FinalUnitIndication::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FinalUnitIndication")     ;
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
			case 449:
			{
				if(mFinalUnitAction != NULL)
				{
					DiameterBaseInterface* inf =  mFinalUnitAction->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 438:
			{
				if(mRestrictionFilterRuleList != NULL)
				{
					for(auto itr = mRestrictionFilterRuleList->begin(); itr != mRestrictionFilterRuleList->end(); ++itr)
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
			case 11:
			{
				if(mFilterIdList != NULL)
				{
					for(auto itr = mFilterIdList->begin(); itr != mFilterIdList->end(); ++itr)
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
			case 434:
			{
				if(mRedirectServerGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mRedirectServerGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mRedirectServerGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
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


INT32 FinalUnitIndication::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 FinalUnitIndication::getAvpCode()
{
	return mAvpCode;
}
INT32 FinalUnitIndication::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 FinalUnitIndication::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 FinalUnitIndication::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> FinalUnitIndication::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void FinalUnitIndication::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case FinalUnitIndication_FINALUNITACTION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "449" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FinalUnitAction" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getFinalUnitAction()->Display(tab+1);
			}
				break;
			case FinalUnitIndication_RESTRICTIONFILTERRULE:
			{
				if( mRestrictionFilterRuleList->size() <= 0) {
					break;
				}

				mRestrictionFilterRuleIterator = this->getRestrictionFilterRuleList()->begin();
				while(mRestrictionFilterRuleIterator != this->getRestrictionFilterRuleList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "438" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RestrictionFilterRule" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mRestrictionFilterRuleIterator)->Display(tab+1);
					mRestrictionFilterRuleIterator++;

				};

			}
				break;
			case FinalUnitIndication_FILTERID:
			{
				if( mFilterIdList->size() <= 0) {
					break;
				}

				mFilterIdIterator = this->getFilterIdList()->begin();
				while(mFilterIdIterator != this->getFilterIdList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "11" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FilterId" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mFilterIdIterator)->Display(tab+1);
					mFilterIdIterator++;

				};

			}
				break;
			case FinalUnitIndication_REDIRECTSERVER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "434" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RedirectServer" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getRedirectServer()->Display(tab+1);
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


BOOLEAN FinalUnitIndication::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<4> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case FinalUnitIndication_FINALUNITACTION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 449");
				}
				else
					sprintf(lMissingAvpInfo, "%s,449", lMissingAvpInfo);
			}
				break;
			case FinalUnitIndication_RESTRICTIONFILTERRULE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 438");
				}
				else
					sprintf(lMissingAvpInfo, "%s,438", lMissingAvpInfo);
			}
				break;
			case FinalUnitIndication_FILTERID:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 11");
				}
				else
					sprintf(lMissingAvpInfo, "%s,11", lMissingAvpInfo);
			}
				break;
			case FinalUnitIndication_REDIRECTSERVER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 434");
				}
				else
					sprintf(lMissingAvpInfo, "%s,434", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
