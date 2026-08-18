#include "rx/include/MediaSubComponent.h"

using namespace RX;
BOOLEAN MediaSubComponent::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

MediaSubComponent::MediaSubComponent()
{
	mFlowNumber = NULL;
	mFlowDescriptionList = NULL;
	mFlowStatus = NULL;
	mFlowUsage = NULL;
	mMaxRequestedBandwidthUL = NULL;
	mMaxRequestedBandwidthDL = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<6>(string("111111"));
	mMandatoryAvpSetVal.reset();
}

MediaSubComponent::~MediaSubComponent()
{
	if(mFlowNumber != NULL)
		delete mFlowNumber;
	if(mFlowDescriptionList != NULL){
		mFlowDescriptionIterator = mFlowDescriptionList->begin();
		while(mFlowDescriptionIterator != mFlowDescriptionList->end()){
			delete (*mFlowDescriptionIterator);
			mFlowDescriptionIterator++;
		}
		delete mFlowDescriptionList;
	}
	if(mFlowStatus != NULL)
		delete mFlowStatus;
	if(mFlowUsage != NULL)
		delete mFlowUsage;
	if(mMaxRequestedBandwidthUL != NULL)
		delete mMaxRequestedBandwidthUL;
	if(mMaxRequestedBandwidthDL != NULL)
		delete mMaxRequestedBandwidthDL;
}

Unsigned32* MediaSubComponent::setFlowNumber(){
	mMandatoryAvpSetVal [MediaSubComponent_FLOWNUMBER] = 1;
	if(mFlowNumber == NULL)
	{
		mFlowNumber = new Unsigned32();
		mTagsPresent[MediaSubComponent_FLOWNUMBER] = 1;
		return mFlowNumber;
	}
	return mFlowNumber;
}

void MediaSubComponent::resetFlowNumber(){
	mTagsPresent[MediaSubComponent_FLOWNUMBER] = 0;
	if(mFlowNumber != NULL)
	{
		delete mFlowNumber; 
		mFlowNumber = NULL;
	}
}

FlowStatus* MediaSubComponent::setFlowStatus(){
	mMandatoryAvpSetVal [MediaSubComponent_FLOWSTATUS] = 1;
	if(mFlowStatus == NULL)
	{
		mFlowStatus = new FlowStatus();
		mTagsPresent[MediaSubComponent_FLOWSTATUS] = 1;
		return mFlowStatus;
	}
	return mFlowStatus;
}

void MediaSubComponent::resetFlowStatus(){
	mTagsPresent[MediaSubComponent_FLOWSTATUS] = 0;
	if(mFlowStatus != NULL)
	{
		delete mFlowStatus; 
		mFlowStatus = NULL;
	}
}

FlowUsage* MediaSubComponent::setFlowUsage(){
	mMandatoryAvpSetVal [MediaSubComponent_FLOWUSAGE] = 1;
	if(mFlowUsage == NULL)
	{
		mFlowUsage = new FlowUsage();
		mTagsPresent[MediaSubComponent_FLOWUSAGE] = 1;
		return mFlowUsage;
	}
	return mFlowUsage;
}

void MediaSubComponent::resetFlowUsage(){
	mTagsPresent[MediaSubComponent_FLOWUSAGE] = 0;
	if(mFlowUsage != NULL)
	{
		delete mFlowUsage; 
		mFlowUsage = NULL;
	}
}

Unsigned32* MediaSubComponent::setMaxRequestedBandwidthUL(){
	mMandatoryAvpSetVal [MediaSubComponent_MAXREQUESTEDBANDWIDTHUL] = 1;
	if(mMaxRequestedBandwidthUL == NULL)
	{
		mMaxRequestedBandwidthUL = new Unsigned32();
		mTagsPresent[MediaSubComponent_MAXREQUESTEDBANDWIDTHUL] = 1;
		return mMaxRequestedBandwidthUL;
	}
	return mMaxRequestedBandwidthUL;
}

void MediaSubComponent::resetMaxRequestedBandwidthUL(){
	mTagsPresent[MediaSubComponent_MAXREQUESTEDBANDWIDTHUL] = 0;
	if(mMaxRequestedBandwidthUL != NULL)
	{
		delete mMaxRequestedBandwidthUL; 
		mMaxRequestedBandwidthUL = NULL;
	}
}

Unsigned32* MediaSubComponent::setMaxRequestedBandwidthDL(){
	mMandatoryAvpSetVal [MediaSubComponent_MAXREQUESTEDBANDWIDTHDL] = 1;
	if(mMaxRequestedBandwidthDL == NULL)
	{
		mMaxRequestedBandwidthDL = new Unsigned32();
		mTagsPresent[MediaSubComponent_MAXREQUESTEDBANDWIDTHDL] = 1;
		return mMaxRequestedBandwidthDL;
	}
	return mMaxRequestedBandwidthDL;
}

void MediaSubComponent::resetMaxRequestedBandwidthDL(){
	mTagsPresent[MediaSubComponent_MAXREQUESTEDBANDWIDTHDL] = 0;
	if(mMaxRequestedBandwidthDL != NULL)
	{
		delete mMaxRequestedBandwidthDL; 
		mMaxRequestedBandwidthDL = NULL;
	}
}

Unsigned32* MediaSubComponent::getFlowNumber(){
	if(NULL == mFlowNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mFlowNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFlowNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFlowNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFlowNumber->Decode(mspByteArray.get(), mFlowNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowNumber")     ;
			throw lTssDiaMsgException;
		}
		mFlowNumber->mAvpDecodedFlag = true;
	}
	return mFlowNumber;
}

list<OctetString*>* MediaSubComponent::getFlowDescriptionList()
{
	if(mFlowDescriptionList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowDescription is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mFlowDescriptionList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowDescription is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowDescription")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mFlowDescriptionList;
}

list<OctetString*>* MediaSubComponent::setFlowDescriptionList() {
	mTagsPresent[MediaSubComponent_FLOWDESCRIPTION] = 1;
	if(mFlowDescriptionList == NULL)
		mFlowDescriptionList = new list<OctetString*>;
	mMandatoryAvpSetVal [MediaSubComponent_FLOWDESCRIPTION] = 1;
	mFlowDescriptionList->clear();
	return mFlowDescriptionList;
}

void MediaSubComponent::resetFlowDescriptionList(){
	mTagsPresent[MediaSubComponent_FLOWDESCRIPTION] = 0;
	if(mFlowDescriptionList != NULL)
		delete mFlowDescriptionList;
}

FlowStatus* MediaSubComponent::getFlowStatus(){
	if(NULL == mFlowStatus) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowStatus is Null");
		throw lTssDiaMsgException;
	}
	if(!mFlowStatus->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFlowStatus->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowStatus is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFlowStatus->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFlowStatus->Decode(mspByteArray.get(), mFlowStatus->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowStatus")     ;
			throw lTssDiaMsgException;
		}
		mFlowStatus->mAvpDecodedFlag = true;
	}
	return mFlowStatus;
}

FlowUsage* MediaSubComponent::getFlowUsage(){
	if(NULL == mFlowUsage) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowUsage is Null");
		throw lTssDiaMsgException;
	}
	if(!mFlowUsage->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mFlowUsage->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "FlowUsage is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mFlowUsage->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mFlowUsage->Decode(mspByteArray.get(), mFlowUsage->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowUsage")     ;
			throw lTssDiaMsgException;
		}
		mFlowUsage->mAvpDecodedFlag = true;
	}
	return mFlowUsage;
}

Unsigned32* MediaSubComponent::getMaxRequestedBandwidthUL(){
	if(NULL == mMaxRequestedBandwidthUL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MaxRequestedBandwidthUL is Null");
		throw lTssDiaMsgException;
	}
	if(!mMaxRequestedBandwidthUL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMaxRequestedBandwidthUL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MaxRequestedBandwidthUL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMaxRequestedBandwidthUL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMaxRequestedBandwidthUL->Decode(mspByteArray.get(), mMaxRequestedBandwidthUL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MaxRequestedBandwidthUL")     ;
			throw lTssDiaMsgException;
		}
		mMaxRequestedBandwidthUL->mAvpDecodedFlag = true;
	}
	return mMaxRequestedBandwidthUL;
}

Unsigned32* MediaSubComponent::getMaxRequestedBandwidthDL(){
	if(NULL == mMaxRequestedBandwidthDL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MaxRequestedBandwidthDL is Null");
		throw lTssDiaMsgException;
	}
	if(!mMaxRequestedBandwidthDL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMaxRequestedBandwidthDL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MaxRequestedBandwidthDL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMaxRequestedBandwidthDL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMaxRequestedBandwidthDL->Decode(mspByteArray.get(), mMaxRequestedBandwidthDL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MaxRequestedBandwidthDL")     ;
			throw lTssDiaMsgException;
		}
		mMaxRequestedBandwidthDL->mAvpDecodedFlag = true;
	}
	return mMaxRequestedBandwidthDL;
}



int MediaSubComponent::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case MediaSubComponent_FLOWNUMBER:
			{
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
					if(!mFlowNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFlowNumber->getAvpOffsetLen().first], mFlowNumber->getAvpOffsetLen().second);
						array->offset += mFlowNumber->getAvpOffsetLen().second;
						array->size += mFlowNumber->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowNumber");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFlowNumber->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowNumber");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MediaSubComponent_FLOWDESCRIPTION:
			{
					if( mFlowDescriptionList->size() <= 0) {
						break;
					}

					mFlowDescriptionIterator = this->getFlowDescriptionList()->begin();
					while(mFlowDescriptionIterator != mFlowDescriptionList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(507);
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
					if(!(*mFlowDescriptionIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mFlowDescriptionIterator)->getAvpOffsetLen().first], (*mFlowDescriptionIterator)->getAvpOffsetLen().second);
						array->offset += (*mFlowDescriptionIterator)->getAvpOffsetLen().second;
						array->size += (*mFlowDescriptionIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mFlowDescriptionIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mFlowDescriptionIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowDescription");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mFlowDescriptionIterator++;
						continue;
					}
						if(((*mFlowDescriptionIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mFlowDescriptionIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowDescription");
							throw lTssDiaMsgException;
						}
						mFlowDescriptionIterator++;
				}
				}
				break;
			case MediaSubComponent_FLOWSTATUS:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(511);
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
					if(!mFlowStatus->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFlowStatus->getAvpOffsetLen().first], mFlowStatus->getAvpOffsetLen().second);
						array->offset += mFlowStatus->getAvpOffsetLen().second;
						array->size += mFlowStatus->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowStatus");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFlowStatus->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowStatus");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MediaSubComponent_FLOWUSAGE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(512);
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
					if(!mFlowUsage->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mFlowUsage->getAvpOffsetLen().first], mFlowUsage->getAvpOffsetLen().second);
						array->offset += mFlowUsage->getAvpOffsetLen().second;
						array->size += mFlowUsage->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowUsage");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mFlowUsage->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding FlowUsage");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MediaSubComponent_MAXREQUESTEDBANDWIDTHUL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(516);
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
					if(!mMaxRequestedBandwidthUL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMaxRequestedBandwidthUL->getAvpOffsetLen().first], mMaxRequestedBandwidthUL->getAvpOffsetLen().second);
						array->offset += mMaxRequestedBandwidthUL->getAvpOffsetLen().second;
						array->size += mMaxRequestedBandwidthUL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MaxRequestedBandwidthUL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMaxRequestedBandwidthUL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MaxRequestedBandwidthUL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MediaSubComponent_MAXREQUESTEDBANDWIDTHDL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(515);
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
					if(!mMaxRequestedBandwidthDL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMaxRequestedBandwidthDL->getAvpOffsetLen().first], mMaxRequestedBandwidthDL->getAvpOffsetLen().second);
						array->offset += mMaxRequestedBandwidthDL->getAvpOffsetLen().second;
						array->size += mMaxRequestedBandwidthDL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MaxRequestedBandwidthDL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMaxRequestedBandwidthDL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MaxRequestedBandwidthDL");
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


int MediaSubComponent::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 509:
				{
						mMandatoryAvpSetVal [MediaSubComponent_FLOWNUMBER] = 1;
					if( NULL == this->setFlowNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowNumber");
						throw lTssDiaMsgException;
					}
					mFlowNumber->setAvpCode(509);
					mFlowNumber->setAvpVendorId(lVenderId);
					mFlowNumber->SetDataType((DiameterDataType)3);
					mFlowNumber->mspByteArray = mspByteArray;
					mFlowNumber->mAvpDecodedFlag = false;
					mFlowNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 507:
				{
						mMandatoryAvpSetVal [MediaSubComponent_FLOWDESCRIPTION] = 1;
					mTagsPresent[MediaSubComponent_FLOWDESCRIPTION] = 1;
					OctetString *lFlowDescription = new OctetString();
					if( lFlowDescription == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowDescription");
						throw lTssDiaMsgException;
					}
					lFlowDescription->setAvpCode(507);
					lFlowDescription->setAvpVendorId(lVenderId);
					lFlowDescription->SetDataType((DiameterDataType)5);
					lFlowDescription->mspByteArray = mspByteArray;
					lFlowDescription->mAvpDecodedFlag = false;
					lFlowDescription->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mFlowDescriptionList == NULL)
						this->setFlowDescriptionList();
					mFlowDescriptionList->push_back(lFlowDescription);
					
				}
				break;
			case 511:
				{
						mMandatoryAvpSetVal [MediaSubComponent_FLOWSTATUS] = 1;
					if( NULL == this->setFlowStatus())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowStatus");
						throw lTssDiaMsgException;
					}
					mFlowStatus->setAvpCode(511);
					mFlowStatus->setAvpVendorId(lVenderId);
					mFlowStatus->SetDataType((DiameterDataType)7);
					mFlowStatus->mspByteArray = mspByteArray;
					mFlowStatus->mAvpDecodedFlag = false;
					mFlowStatus->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 512:
				{
						mMandatoryAvpSetVal [MediaSubComponent_FLOWUSAGE] = 1;
					if( NULL == this->setFlowUsage())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FlowUsage");
						throw lTssDiaMsgException;
					}
					mFlowUsage->setAvpCode(512);
					mFlowUsage->setAvpVendorId(lVenderId);
					mFlowUsage->SetDataType((DiameterDataType)7);
					mFlowUsage->mspByteArray = mspByteArray;
					mFlowUsage->mAvpDecodedFlag = false;
					mFlowUsage->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 516:
				{
						mMandatoryAvpSetVal [MediaSubComponent_MAXREQUESTEDBANDWIDTHUL] = 1;
					if( NULL == this->setMaxRequestedBandwidthUL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MaxRequestedBandwidthUL");
						throw lTssDiaMsgException;
					}
					mMaxRequestedBandwidthUL->setAvpCode(516);
					mMaxRequestedBandwidthUL->setAvpVendorId(lVenderId);
					mMaxRequestedBandwidthUL->SetDataType((DiameterDataType)3);
					mMaxRequestedBandwidthUL->mspByteArray = mspByteArray;
					mMaxRequestedBandwidthUL->mAvpDecodedFlag = false;
					mMaxRequestedBandwidthUL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 515:
				{
						mMandatoryAvpSetVal [MediaSubComponent_MAXREQUESTEDBANDWIDTHDL] = 1;
					if( NULL == this->setMaxRequestedBandwidthDL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MaxRequestedBandwidthDL");
						throw lTssDiaMsgException;
					}
					mMaxRequestedBandwidthDL->setAvpCode(515);
					mMaxRequestedBandwidthDL->setAvpVendorId(lVenderId);
					mMaxRequestedBandwidthDL->SetDataType((DiameterDataType)3);
					mMaxRequestedBandwidthDL->mspByteArray = mspByteArray;
					mMaxRequestedBandwidthDL->mAvpDecodedFlag = false;
					mMaxRequestedBandwidthDL->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* MediaSubComponent::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaSubComponent")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 509:
			{
				if(mFlowNumber != NULL)
					return mFlowNumber->Find(array, avpCode);
				else
					return NULL;
			}
			case 507:
			{
				if(mFlowDescriptionList != NULL && mFlowDescriptionList->size() > 0)
					return (mFlowDescriptionList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 511:
			{
				if(mFlowStatus != NULL)
					return mFlowStatus->Find(array, avpCode);
				else
					return NULL;
			}
			case 512:
			{
				if(mFlowUsage != NULL)
					return mFlowUsage->Find(array, avpCode);
				else
					return NULL;
			}
			case 516:
			{
				if(mMaxRequestedBandwidthUL != NULL)
					return mMaxRequestedBandwidthUL->Find(array, avpCode);
				else
					return NULL;
			}
			case 515:
			{
				if(mMaxRequestedBandwidthDL != NULL)
					return mMaxRequestedBandwidthDL->Find(array, avpCode);
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


BOOLEAN MediaSubComponent::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaSubComponent")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 509:
			{
				if(mFlowNumber != NULL)
				{
					DiameterBaseInterface* inf =  mFlowNumber->Find(this->mspByteArray.get(), avpCode);
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
			case 507:
			{
				if(mFlowDescriptionList != NULL)
				{
					for(auto itr = mFlowDescriptionList->begin(); itr != mFlowDescriptionList->end(); ++itr)
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
			case 511:
			{
				if(mFlowStatus != NULL)
				{
					DiameterBaseInterface* inf =  mFlowStatus->Find(this->mspByteArray.get(), avpCode);
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
			case 512:
			{
				if(mFlowUsage != NULL)
				{
					DiameterBaseInterface* inf =  mFlowUsage->Find(this->mspByteArray.get(), avpCode);
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
			case 516:
			{
				if(mMaxRequestedBandwidthUL != NULL)
				{
					DiameterBaseInterface* inf =  mMaxRequestedBandwidthUL->Find(this->mspByteArray.get(), avpCode);
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
			case 515:
			{
				if(mMaxRequestedBandwidthDL != NULL)
				{
					DiameterBaseInterface* inf =  mMaxRequestedBandwidthDL->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> MediaSubComponent::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN MediaSubComponent::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaSubComponent")     ;
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
			case 509:
			{
				if(mFlowNumber != NULL)
				{
					DiameterBaseInterface* inf =  mFlowNumber->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 507:
			{
				if(mFlowDescriptionList != NULL)
				{
					for(auto itr = mFlowDescriptionList->begin(); itr != mFlowDescriptionList->end(); ++itr)
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
			case 511:
			{
				if(mFlowStatus != NULL)
				{
					DiameterBaseInterface* inf =  mFlowStatus->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 512:
			{
				if(mFlowUsage != NULL)
				{
					DiameterBaseInterface* inf =  mFlowUsage->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 516:
			{
				if(mMaxRequestedBandwidthUL != NULL)
				{
					DiameterBaseInterface* inf =  mMaxRequestedBandwidthUL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 515:
			{
				if(mMaxRequestedBandwidthDL != NULL)
				{
					DiameterBaseInterface* inf =  mMaxRequestedBandwidthDL->Find(this->mspByteArray.get(), avpCode);
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


INT32 MediaSubComponent::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 MediaSubComponent::getAvpCode()
{
	return mAvpCode;
}
INT32 MediaSubComponent::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 MediaSubComponent::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 MediaSubComponent::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> MediaSubComponent::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void MediaSubComponent::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case MediaSubComponent_FLOWNUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "509" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getFlowNumber()->Display(tab+1);
			}
				break;
			case MediaSubComponent_FLOWDESCRIPTION:
			{
				if( mFlowDescriptionList->size() <= 0) {
					break;
				}

				mFlowDescriptionIterator = this->getFlowDescriptionList()->begin();
				while(mFlowDescriptionIterator != this->getFlowDescriptionList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "507" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowDescription" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mFlowDescriptionIterator)->Display(tab+1);
					mFlowDescriptionIterator++;

				};

			}
				break;
			case MediaSubComponent_FLOWSTATUS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "511" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowStatus" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getFlowStatus()->Display(tab+1);
			}
				break;
			case MediaSubComponent_FLOWUSAGE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "512" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowUsage" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getFlowUsage()->Display(tab+1);
			}
				break;
			case MediaSubComponent_MAXREQUESTEDBANDWIDTHUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "516" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MaxRequestedBandwidthUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMaxRequestedBandwidthUL()->Display(tab+1);
			}
				break;
			case MediaSubComponent_MAXREQUESTEDBANDWIDTHDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "515" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MaxRequestedBandwidthDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMaxRequestedBandwidthDL()->Display(tab+1);
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


BOOLEAN MediaSubComponent::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<6> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case MediaSubComponent_FLOWNUMBER:
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
			case MediaSubComponent_FLOWDESCRIPTION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 507");
				}
				else
					sprintf(lMissingAvpInfo, "%s,507", lMissingAvpInfo);
			}
				break;
			case MediaSubComponent_FLOWSTATUS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 511");
				}
				else
					sprintf(lMissingAvpInfo, "%s,511", lMissingAvpInfo);
			}
				break;
			case MediaSubComponent_FLOWUSAGE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 512");
				}
				else
					sprintf(lMissingAvpInfo, "%s,512", lMissingAvpInfo);
			}
				break;
			case MediaSubComponent_MAXREQUESTEDBANDWIDTHUL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 516");
				}
				else
					sprintf(lMissingAvpInfo, "%s,516", lMissingAvpInfo);
			}
				break;
			case MediaSubComponent_MAXREQUESTEDBANDWIDTHDL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 515");
				}
				else
					sprintf(lMissingAvpInfo, "%s,515", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
