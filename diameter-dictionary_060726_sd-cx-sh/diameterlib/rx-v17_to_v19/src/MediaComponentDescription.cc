#include "rx/include/MediaComponentDescription.h"

using namespace RX;
BOOLEAN MediaComponentDescription::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

MediaComponentDescription::MediaComponentDescription()
{
	mMediaComponentNumber = NULL;
	mMediaSubComponentGrpList = NULL;
	mAFApplicationIdentifier = NULL;
	mMediaType = NULL;
	mMaxRequestedBandwidthUL = NULL;
	mMaxRequestedBandwidthDL = NULL;
	mFlowStatus = NULL;
	mReservationPriority = NULL;
	mRSBandwidth = NULL;
	mRRBandwidth = NULL;
	mCodecDataList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<11>(string("11101111111"));
	mMandatoryAvpSetVal.reset();
}

MediaComponentDescription::~MediaComponentDescription()
{
	if(mMediaComponentNumber != NULL)
		delete mMediaComponentNumber;
	if(mMediaSubComponentGrpList != NULL){
		mMediaSubComponentGrpIterator = mMediaSubComponentGrpList->begin();
		while(mMediaSubComponentGrpIterator != mMediaSubComponentGrpList->end()){
	if(*mMediaSubComponentGrpIterator != NULL)
			delete (*mMediaSubComponentGrpIterator);
			mMediaSubComponentGrpIterator++;
		}
		delete mMediaSubComponentGrpList;
	}
	if(mAFApplicationIdentifier != NULL)
		delete mAFApplicationIdentifier;
	if(mMediaType != NULL)
		delete mMediaType;
	if(mMaxRequestedBandwidthUL != NULL)
		delete mMaxRequestedBandwidthUL;
	if(mMaxRequestedBandwidthDL != NULL)
		delete mMaxRequestedBandwidthDL;
	if(mFlowStatus != NULL)
		delete mFlowStatus;
	if(mReservationPriority != NULL)
		delete mReservationPriority;
	if(mRSBandwidth != NULL)
		delete mRSBandwidth;
	if(mRRBandwidth != NULL)
		delete mRRBandwidth;
	if(mCodecDataList != NULL){
		mCodecDataIterator = mCodecDataList->begin();
		while(mCodecDataIterator != mCodecDataList->end()){
			delete (*mCodecDataIterator);
			mCodecDataIterator++;
		}
		delete mCodecDataList;
	}
}

Unsigned32* MediaComponentDescription::setMediaComponentNumber(){
	mMandatoryAvpSetVal [MediaComponentDescription_MEDIACOMPONENTNUMBER] = 1;
	if(mMediaComponentNumber == NULL)
	{
		mMediaComponentNumber = new Unsigned32();
		mTagsPresent[MediaComponentDescription_MEDIACOMPONENTNUMBER] = 1;
		return mMediaComponentNumber;
	}
	return mMediaComponentNumber;
}

void MediaComponentDescription::resetMediaComponentNumber(){
	mTagsPresent[MediaComponentDescription_MEDIACOMPONENTNUMBER] = 0;
	if(mMediaComponentNumber != NULL)
	{
		delete mMediaComponentNumber; 
		mMediaComponentNumber = NULL;
	}
}

OctetString* MediaComponentDescription::setAFApplicationIdentifier(){
	mMandatoryAvpSetVal [MediaComponentDescription_AFAPPLICATIONIDENTIFIER] = 1;
	if(mAFApplicationIdentifier == NULL)
	{
		mAFApplicationIdentifier = new OctetString();
		mTagsPresent[MediaComponentDescription_AFAPPLICATIONIDENTIFIER] = 1;
		return mAFApplicationIdentifier;
	}
	return mAFApplicationIdentifier;
}

void MediaComponentDescription::resetAFApplicationIdentifier(){
	mTagsPresent[MediaComponentDescription_AFAPPLICATIONIDENTIFIER] = 0;
	if(mAFApplicationIdentifier != NULL)
	{
		delete mAFApplicationIdentifier; 
		mAFApplicationIdentifier = NULL;
	}
}

MediaType* MediaComponentDescription::setMediaType(){
	mMandatoryAvpSetVal [MediaComponentDescription_MEDIATYPE] = 1;
	if(mMediaType == NULL)
	{
		mMediaType = new MediaType();
		mTagsPresent[MediaComponentDescription_MEDIATYPE] = 1;
		return mMediaType;
	}
	return mMediaType;
}

void MediaComponentDescription::resetMediaType(){
	mTagsPresent[MediaComponentDescription_MEDIATYPE] = 0;
	if(mMediaType != NULL)
	{
		delete mMediaType; 
		mMediaType = NULL;
	}
}

Unsigned32* MediaComponentDescription::setMaxRequestedBandwidthUL(){
	mMandatoryAvpSetVal [MediaComponentDescription_MAXREQUESTEDBANDWIDTHUL] = 1;
	if(mMaxRequestedBandwidthUL == NULL)
	{
		mMaxRequestedBandwidthUL = new Unsigned32();
		mTagsPresent[MediaComponentDescription_MAXREQUESTEDBANDWIDTHUL] = 1;
		return mMaxRequestedBandwidthUL;
	}
	return mMaxRequestedBandwidthUL;
}

void MediaComponentDescription::resetMaxRequestedBandwidthUL(){
	mTagsPresent[MediaComponentDescription_MAXREQUESTEDBANDWIDTHUL] = 0;
	if(mMaxRequestedBandwidthUL != NULL)
	{
		delete mMaxRequestedBandwidthUL; 
		mMaxRequestedBandwidthUL = NULL;
	}
}

Unsigned32* MediaComponentDescription::setMaxRequestedBandwidthDL(){
	mMandatoryAvpSetVal [MediaComponentDescription_MAXREQUESTEDBANDWIDTHDL] = 1;
	if(mMaxRequestedBandwidthDL == NULL)
	{
		mMaxRequestedBandwidthDL = new Unsigned32();
		mTagsPresent[MediaComponentDescription_MAXREQUESTEDBANDWIDTHDL] = 1;
		return mMaxRequestedBandwidthDL;
	}
	return mMaxRequestedBandwidthDL;
}

void MediaComponentDescription::resetMaxRequestedBandwidthDL(){
	mTagsPresent[MediaComponentDescription_MAXREQUESTEDBANDWIDTHDL] = 0;
	if(mMaxRequestedBandwidthDL != NULL)
	{
		delete mMaxRequestedBandwidthDL; 
		mMaxRequestedBandwidthDL = NULL;
	}
}

FlowStatus* MediaComponentDescription::setFlowStatus(){
	mMandatoryAvpSetVal [MediaComponentDescription_FLOWSTATUS] = 1;
	if(mFlowStatus == NULL)
	{
		mFlowStatus = new FlowStatus();
		mTagsPresent[MediaComponentDescription_FLOWSTATUS] = 1;
		return mFlowStatus;
	}
	return mFlowStatus;
}

void MediaComponentDescription::resetFlowStatus(){
	mTagsPresent[MediaComponentDescription_FLOWSTATUS] = 0;
	if(mFlowStatus != NULL)
	{
		delete mFlowStatus; 
		mFlowStatus = NULL;
	}
}

ReservationPriority* MediaComponentDescription::setReservationPriority(){
	if(mReservationPriority == NULL)
	{
		mReservationPriority = new ReservationPriority();
		mTagsPresent[MediaComponentDescription_RESERVATIONPRIORITY] = 1;
		return mReservationPriority;
	}
	return mReservationPriority;
}

void MediaComponentDescription::resetReservationPriority(){
	mTagsPresent[MediaComponentDescription_RESERVATIONPRIORITY] = 0;
	if(mReservationPriority != NULL)
	{
		delete mReservationPriority; 
		mReservationPriority = NULL;
	}
}

Unsigned32* MediaComponentDescription::setRSBandwidth(){
	mMandatoryAvpSetVal [MediaComponentDescription_RSBANDWIDTH] = 1;
	if(mRSBandwidth == NULL)
	{
		mRSBandwidth = new Unsigned32();
		mTagsPresent[MediaComponentDescription_RSBANDWIDTH] = 1;
		return mRSBandwidth;
	}
	return mRSBandwidth;
}

void MediaComponentDescription::resetRSBandwidth(){
	mTagsPresent[MediaComponentDescription_RSBANDWIDTH] = 0;
	if(mRSBandwidth != NULL)
	{
		delete mRSBandwidth; 
		mRSBandwidth = NULL;
	}
}

Unsigned32* MediaComponentDescription::setRRBandwidth(){
	mMandatoryAvpSetVal [MediaComponentDescription_RRBANDWIDTH] = 1;
	if(mRRBandwidth == NULL)
	{
		mRRBandwidth = new Unsigned32();
		mTagsPresent[MediaComponentDescription_RRBANDWIDTH] = 1;
		return mRRBandwidth;
	}
	return mRRBandwidth;
}

void MediaComponentDescription::resetRRBandwidth(){
	mTagsPresent[MediaComponentDescription_RRBANDWIDTH] = 0;
	if(mRRBandwidth != NULL)
	{
		delete mRRBandwidth; 
		mRRBandwidth = NULL;
	}
}

Unsigned32* MediaComponentDescription::getMediaComponentNumber(){
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

list<MediaSubComponent*>* MediaComponentDescription::getMediaSubComponentGrpList()
{
	if(mMediaSubComponentGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaSubComponent is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mMediaSubComponentGrpList)
	{
		if(mMediaSubComponentGrpList != NULL)
		{
		if(mMediaSubComponentGrpList->size() == 0)
		{
			mTagsPresent[MediaComponentDescription_MEDIASUBCOMPONENT] = 0;
			mMediaSubComponentGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaSubComponent is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaSubComponent is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaSubComponent")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mMediaSubComponentGrpList;
}

list<MediaSubComponent*>* MediaComponentDescription::setMediaSubComponentGrpList(){
	mTagsPresent[MediaComponentDescription_MEDIASUBCOMPONENT] = 1;
	if(mMediaSubComponentGrpList == NULL)
		mMediaSubComponentGrpList = new list<MediaSubComponent*>;
	mMandatoryAvpSetVal[MediaComponentDescription_MEDIASUBCOMPONENT] = 1;
	mMediaSubComponentGrpList->clear();
	return mMediaSubComponentGrpList;
}

void MediaComponentDescription::resetMediaSubComponentGrpList(){
	mTagsPresent[MediaComponentDescription_MEDIASUBCOMPONENT] = 0;
	if(mMediaSubComponentGrpList != NULL)
		delete mMediaSubComponentGrpList;
}

OctetString* MediaComponentDescription::getAFApplicationIdentifier(){
	if(NULL == mAFApplicationIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AFApplicationIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mAFApplicationIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAFApplicationIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AFApplicationIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAFApplicationIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAFApplicationIdentifier->Decode(mspByteArray.get(), mAFApplicationIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AFApplicationIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mAFApplicationIdentifier->mAvpDecodedFlag = true;
	}
	return mAFApplicationIdentifier;
}

MediaType* MediaComponentDescription::getMediaType(){
	if(NULL == mMediaType) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaType is Null");
		throw lTssDiaMsgException;
	}
	if(!mMediaType->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mMediaType->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "MediaType is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mMediaType->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mMediaType->Decode(mspByteArray.get(), mMediaType->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaType")     ;
			throw lTssDiaMsgException;
		}
		mMediaType->mAvpDecodedFlag = true;
	}
	return mMediaType;
}

Unsigned32* MediaComponentDescription::getMaxRequestedBandwidthUL(){
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

Unsigned32* MediaComponentDescription::getMaxRequestedBandwidthDL(){
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

FlowStatus* MediaComponentDescription::getFlowStatus(){
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

ReservationPriority* MediaComponentDescription::getReservationPriority(){
	if(NULL == mReservationPriority) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReservationPriority is Null");
		throw lTssDiaMsgException;
	}
	if(!mReservationPriority->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mReservationPriority->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ReservationPriority is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mReservationPriority->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mReservationPriority->Decode(mspByteArray.get(), mReservationPriority->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReservationPriority")     ;
			throw lTssDiaMsgException;
		}
		mReservationPriority->mAvpDecodedFlag = true;
	}
	return mReservationPriority;
}

Unsigned32* MediaComponentDescription::getRSBandwidth(){
	if(NULL == mRSBandwidth) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RSBandwidth is Null");
		throw lTssDiaMsgException;
	}
	if(!mRSBandwidth->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRSBandwidth->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RSBandwidth is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRSBandwidth->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRSBandwidth->Decode(mspByteArray.get(), mRSBandwidth->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RSBandwidth")     ;
			throw lTssDiaMsgException;
		}
		mRSBandwidth->mAvpDecodedFlag = true;
	}
	return mRSBandwidth;
}

Unsigned32* MediaComponentDescription::getRRBandwidth(){
	if(NULL == mRRBandwidth) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RRBandwidth is Null");
		throw lTssDiaMsgException;
	}
	if(!mRRBandwidth->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mRRBandwidth->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RRBandwidth is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mRRBandwidth->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mRRBandwidth->Decode(mspByteArray.get(), mRRBandwidth->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RRBandwidth")     ;
			throw lTssDiaMsgException;
		}
		mRRBandwidth->mAvpDecodedFlag = true;
	}
	return mRRBandwidth;
}

list<OctetString*>* MediaComponentDescription::getCodecDataList()
{
	if(mCodecDataList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CodecData is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mCodecDataList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CodecData is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CodecData")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mCodecDataList;
}

list<OctetString*>* MediaComponentDescription::setCodecDataList() {
	mTagsPresent[MediaComponentDescription_CODECDATA] = 1;
	if(mCodecDataList == NULL)
		mCodecDataList = new list<OctetString*>;
	mMandatoryAvpSetVal [MediaComponentDescription_CODECDATA] = 1;
	mCodecDataList->clear();
	return mCodecDataList;
}

void MediaComponentDescription::resetCodecDataList(){
	mTagsPresent[MediaComponentDescription_CODECDATA] = 0;
	if(mCodecDataList != NULL)
		delete mCodecDataList;
}



int MediaComponentDescription::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case MediaComponentDescription_MEDIACOMPONENTNUMBER:
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
			case MediaComponentDescription_MEDIASUBCOMPONENT:
			{
				if( mMediaSubComponentGrpList->size() <= 0) {
					break;
				}

				mMediaSubComponentGrpIterator = this->getMediaSubComponentGrpList()->begin();
				while(mMediaSubComponentGrpIterator != mMediaSubComponentGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(519);
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
					if(((*mMediaSubComponentGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MediaSubComponent");
						throw lTssDiaMsgException;
					}
					
					mMediaSubComponentGrpIterator++;
				}
				}
				break;
			case MediaComponentDescription_AFAPPLICATIONIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(504);
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
					if(!mAFApplicationIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAFApplicationIdentifier->getAvpOffsetLen().first], mAFApplicationIdentifier->getAvpOffsetLen().second);
						array->offset += mAFApplicationIdentifier->getAvpOffsetLen().second;
						array->size += mAFApplicationIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mAFApplicationIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mAFApplicationIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AFApplicationIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mAFApplicationIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mAFApplicationIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AFApplicationIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MediaComponentDescription_MEDIATYPE:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(520);
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
					if(!mMediaType->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mMediaType->getAvpOffsetLen().first], mMediaType->getAvpOffsetLen().second);
						array->offset += mMediaType->getAvpOffsetLen().second;
						array->size += mMediaType->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MediaType");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mMediaType->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding MediaType");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MediaComponentDescription_MAXREQUESTEDBANDWIDTHUL:
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
			case MediaComponentDescription_MAXREQUESTEDBANDWIDTHDL:
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
			case MediaComponentDescription_FLOWSTATUS:
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
			case MediaComponentDescription_RESERVATIONPRIORITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(458);
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
					if(!mReservationPriority->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mReservationPriority->getAvpOffsetLen().first], mReservationPriority->getAvpOffsetLen().second);
						array->offset += mReservationPriority->getAvpOffsetLen().second;
						array->size += mReservationPriority->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReservationPriority");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mReservationPriority->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ReservationPriority");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MediaComponentDescription_RSBANDWIDTH:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(522);
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
					if(!mRSBandwidth->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRSBandwidth->getAvpOffsetLen().first], mRSBandwidth->getAvpOffsetLen().second);
						array->offset += mRSBandwidth->getAvpOffsetLen().second;
						array->size += mRSBandwidth->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RSBandwidth");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRSBandwidth->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RSBandwidth");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MediaComponentDescription_RRBANDWIDTH:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(521);
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
					if(!mRRBandwidth->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mRRBandwidth->getAvpOffsetLen().first], mRRBandwidth->getAvpOffsetLen().second);
						array->offset += mRRBandwidth->getAvpOffsetLen().second;
						array->size += mRRBandwidth->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RRBandwidth");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mRRBandwidth->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RRBandwidth");
						throw lTssDiaMsgException;
					}
				}
				break;
			case MediaComponentDescription_CODECDATA:
			{
					if( mCodecDataList->size() <= 0) {
						break;
					}

					mCodecDataIterator = this->getCodecDataList()->begin();
					while(mCodecDataIterator != mCodecDataList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(524);
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
					if(!(*mCodecDataIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mCodecDataIterator)->getAvpOffsetLen().first], (*mCodecDataIterator)->getAvpOffsetLen().second);
						array->offset += (*mCodecDataIterator)->getAvpOffsetLen().second;
						array->size += (*mCodecDataIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mCodecDataIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mCodecDataIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CodecData");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mCodecDataIterator++;
						continue;
					}
						if(((*mCodecDataIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mCodecDataIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CodecData");
							throw lTssDiaMsgException;
						}
						mCodecDataIterator++;
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


int MediaComponentDescription::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
						mMandatoryAvpSetVal [MediaComponentDescription_MEDIACOMPONENTNUMBER] = 1;
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
			case 519:
				{
						mMandatoryAvpSetVal [MediaComponentDescription_MEDIASUBCOMPONENT] = 1;
					mTagsPresent[MediaComponentDescription_MEDIASUBCOMPONENT] = 1;
					MediaSubComponent *lMediaSubComponent = new MediaSubComponent();
					if( lMediaSubComponent == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaSubComponent");
						throw lTssDiaMsgException;
					}
					lMediaSubComponent->setAvpCode(519);
					lMediaSubComponent->SetDataType((DiameterDataType)6);
					lMediaSubComponent->mspByteArray = mspByteArray;
					lMediaSubComponent->mAvpDecodedFlag = false;
					lMediaSubComponent->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mMediaSubComponentGrpList == NULL)
						this->setMediaSubComponentGrpList();
					mMediaSubComponentGrpList->push_back(lMediaSubComponent);
					mBaseInterfaceList.push_back(lMediaSubComponent);
					
				}
				break;
			case 504:
				{
						mMandatoryAvpSetVal [MediaComponentDescription_AFAPPLICATIONIDENTIFIER] = 1;
					if( NULL == this->setAFApplicationIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AFApplicationIdentifier");
						throw lTssDiaMsgException;
					}
					mAFApplicationIdentifier->setAvpCode(504);
					mAFApplicationIdentifier->setAvpVendorId(lVenderId);
					mAFApplicationIdentifier->SetDataType((DiameterDataType)5);
					mAFApplicationIdentifier->mspByteArray = mspByteArray;
					mAFApplicationIdentifier->mAvpDecodedFlag = false;
					mAFApplicationIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 520:
				{
						mMandatoryAvpSetVal [MediaComponentDescription_MEDIATYPE] = 1;
					if( NULL == this->setMediaType())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaType");
						throw lTssDiaMsgException;
					}
					mMediaType->setAvpCode(520);
					mMediaType->setAvpVendorId(lVenderId);
					mMediaType->SetDataType((DiameterDataType)7);
					mMediaType->mspByteArray = mspByteArray;
					mMediaType->mAvpDecodedFlag = false;
					mMediaType->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 515:
				{
						mMandatoryAvpSetVal [MediaComponentDescription_MAXREQUESTEDBANDWIDTHUL] = 1;
					if( NULL == this->setMaxRequestedBandwidthUL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MaxRequestedBandwidthUL");
						throw lTssDiaMsgException;
					}
					mMaxRequestedBandwidthUL->setAvpCode(515);
					mMaxRequestedBandwidthUL->setAvpVendorId(lVenderId);
					mMaxRequestedBandwidthUL->SetDataType((DiameterDataType)3);
					mMaxRequestedBandwidthUL->mspByteArray = mspByteArray;
					mMaxRequestedBandwidthUL->mAvpDecodedFlag = false;
					mMaxRequestedBandwidthUL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 516:
				{
						mMandatoryAvpSetVal [MediaComponentDescription_MAXREQUESTEDBANDWIDTHDL] = 1;
					if( NULL == this->setMaxRequestedBandwidthDL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MaxRequestedBandwidthDL");
						throw lTssDiaMsgException;
					}
					mMaxRequestedBandwidthDL->setAvpCode(516);
					mMaxRequestedBandwidthDL->setAvpVendorId(lVenderId);
					mMaxRequestedBandwidthDL->SetDataType((DiameterDataType)3);
					mMaxRequestedBandwidthDL->mspByteArray = mspByteArray;
					mMaxRequestedBandwidthDL->mAvpDecodedFlag = false;
					mMaxRequestedBandwidthDL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 511:
				{
						mMandatoryAvpSetVal [MediaComponentDescription_FLOWSTATUS] = 1;
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
			case 458:
				{
					if( NULL == this->setReservationPriority())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ReservationPriority");
						throw lTssDiaMsgException;
					}
					mReservationPriority->setAvpCode(458);
					mReservationPriority->setAvpVendorId(lVenderId);
					mReservationPriority->SetDataType((DiameterDataType)7);
					mReservationPriority->mspByteArray = mspByteArray;
					mReservationPriority->mAvpDecodedFlag = false;
					mReservationPriority->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 522:
				{
						mMandatoryAvpSetVal [MediaComponentDescription_RSBANDWIDTH] = 1;
					if( NULL == this->setRSBandwidth())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RSBandwidth");
						throw lTssDiaMsgException;
					}
					mRSBandwidth->setAvpCode(522);
					mRSBandwidth->setAvpVendorId(lVenderId);
					mRSBandwidth->SetDataType((DiameterDataType)3);
					mRSBandwidth->mspByteArray = mspByteArray;
					mRSBandwidth->mAvpDecodedFlag = false;
					mRSBandwidth->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 521:
				{
						mMandatoryAvpSetVal [MediaComponentDescription_RRBANDWIDTH] = 1;
					if( NULL == this->setRRBandwidth())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RRBandwidth");
						throw lTssDiaMsgException;
					}
					mRRBandwidth->setAvpCode(521);
					mRRBandwidth->setAvpVendorId(lVenderId);
					mRRBandwidth->SetDataType((DiameterDataType)3);
					mRRBandwidth->mspByteArray = mspByteArray;
					mRRBandwidth->mAvpDecodedFlag = false;
					mRRBandwidth->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 524:
				{
						mMandatoryAvpSetVal [MediaComponentDescription_CODECDATA] = 1;
					mTagsPresent[MediaComponentDescription_CODECDATA] = 1;
					OctetString *lCodecData = new OctetString();
					if( lCodecData == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CodecData");
						throw lTssDiaMsgException;
					}
					lCodecData->setAvpCode(524);
					lCodecData->setAvpVendorId(lVenderId);
					lCodecData->SetDataType((DiameterDataType)5);
					lCodecData->mspByteArray = mspByteArray;
					lCodecData->mAvpDecodedFlag = false;
					lCodecData->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mCodecDataList == NULL)
						this->setCodecDataList();
					mCodecDataList->push_back(lCodecData);
					
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


DiameterBaseInterface* MediaComponentDescription::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaComponentDescription")     ;
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
			case 504:
			{
				if(mAFApplicationIdentifier != NULL)
					return mAFApplicationIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 520:
			{
				if(mMediaType != NULL)
					return mMediaType->Find(array, avpCode);
				else
					return NULL;
			}
			case 515:
			{
				if(mMaxRequestedBandwidthUL != NULL)
					return mMaxRequestedBandwidthUL->Find(array, avpCode);
				else
					return NULL;
			}
			case 516:
			{
				if(mMaxRequestedBandwidthDL != NULL)
					return mMaxRequestedBandwidthDL->Find(array, avpCode);
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
			case 458:
			{
				if(mReservationPriority != NULL)
					return mReservationPriority->Find(array, avpCode);
				else
					return NULL;
			}
			case 522:
			{
				if(mRSBandwidth != NULL)
					return mRSBandwidth->Find(array, avpCode);
				else
					return NULL;
			}
			case 521:
			{
				if(mRRBandwidth != NULL)
					return mRRBandwidth->Find(array, avpCode);
				else
					return NULL;
			}
			case 524:
			{
				if(mCodecDataList != NULL && mCodecDataList->size() > 0)
					return (mCodecDataList->back())->Find(array, avpCode);
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


BOOLEAN MediaComponentDescription::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaComponentDescription")     ;
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
			case 519:
			{
				if(mMediaSubComponentGrpList != NULL)
				{
					for(auto itr = mMediaSubComponentGrpList->begin(); itr != mMediaSubComponentGrpList->end(); ++itr)
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
			case 504:
			{
				if(mAFApplicationIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mAFApplicationIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 520:
			{
				if(mMediaType != NULL)
				{
					DiameterBaseInterface* inf =  mMediaType->Find(this->mspByteArray.get(), avpCode);
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
			case 516:
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
			case 458:
			{
				if(mReservationPriority != NULL)
				{
					DiameterBaseInterface* inf =  mReservationPriority->Find(this->mspByteArray.get(), avpCode);
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
			case 522:
			{
				if(mRSBandwidth != NULL)
				{
					DiameterBaseInterface* inf =  mRSBandwidth->Find(this->mspByteArray.get(), avpCode);
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
			case 521:
			{
				if(mRRBandwidth != NULL)
				{
					DiameterBaseInterface* inf =  mRRBandwidth->Find(this->mspByteArray.get(), avpCode);
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
			case 524:
			{
				if(mCodecDataList != NULL)
				{
					for(auto itr = mCodecDataList->begin(); itr != mCodecDataList->end(); ++itr)
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
std::shared_ptr<byteArray> MediaComponentDescription::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN MediaComponentDescription::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding MediaComponentDescription")     ;
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
			case 519:
			{
				if(mMediaSubComponentGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mMediaSubComponentGrpList->begin(); itr != mMediaSubComponentGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mMediaSubComponentGrpList->begin(); itr != mMediaSubComponentGrpList->end(); ++itr)
						{
							(*itr)->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1), pBaseInterface,deepInspect);
						}
					}
				}
				break;
			}
			case 504:
			{
				if(mAFApplicationIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mAFApplicationIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 520:
			{
				if(mMediaType != NULL)
				{
					DiameterBaseInterface* inf =  mMediaType->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 515:
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
			case 516:
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
			case 458:
			{
				if(mReservationPriority != NULL)
				{
					DiameterBaseInterface* inf =  mReservationPriority->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 522:
			{
				if(mRSBandwidth != NULL)
				{
					DiameterBaseInterface* inf =  mRSBandwidth->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 521:
			{
				if(mRRBandwidth != NULL)
				{
					DiameterBaseInterface* inf =  mRRBandwidth->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 524:
			{
				if(mCodecDataList != NULL)
				{
					for(auto itr = mCodecDataList->begin(); itr != mCodecDataList->end(); ++itr)
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


INT32 MediaComponentDescription::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 MediaComponentDescription::getAvpCode()
{
	return mAvpCode;
}
INT32 MediaComponentDescription::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 MediaComponentDescription::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 MediaComponentDescription::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> MediaComponentDescription::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void MediaComponentDescription::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case MediaComponentDescription_MEDIACOMPONENTNUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "518" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MediaComponentNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMediaComponentNumber()->Display(tab+1);
			}
				break;
			case MediaComponentDescription_MEDIASUBCOMPONENT:
			{
				if( mMediaSubComponentGrpList->size() <= 0) {
					break;
				}

				mMediaSubComponentGrpIterator = this->getMediaSubComponentGrpList()->begin();
				while(mMediaSubComponentGrpIterator != this->getMediaSubComponentGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "519" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MediaSubComponent" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mMediaSubComponentGrpIterator)->Display(tab+1);
					mMediaSubComponentGrpIterator++;

				};

			}
				break;
			case MediaComponentDescription_AFAPPLICATIONIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "504" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AFApplicationIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
				this->getAFApplicationIdentifier()->Display(tab+1);
			}
				break;
			case MediaComponentDescription_MEDIATYPE:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "520" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MediaType" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMediaType()->Display(tab+1);
			}
				break;
			case MediaComponentDescription_MAXREQUESTEDBANDWIDTHUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "515" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MaxRequestedBandwidthUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMaxRequestedBandwidthUL()->Display(tab+1);
			}
				break;
			case MediaComponentDescription_MAXREQUESTEDBANDWIDTHDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "516" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MaxRequestedBandwidthDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMaxRequestedBandwidthDL()->Display(tab+1);
			}
				break;
			case MediaComponentDescription_FLOWSTATUS:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "511" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "FlowStatus" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getFlowStatus()->Display(tab+1);
			}
				break;
			case MediaComponentDescription_RESERVATIONPRIORITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "458" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ReservationPriority" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getReservationPriority()->Display(tab+1);
			}
				break;
			case MediaComponentDescription_RSBANDWIDTH:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "522" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RSBandwidth" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getRSBandwidth()->Display(tab+1);
			}
				break;
			case MediaComponentDescription_RRBANDWIDTH:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "521" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RRBandwidth" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getRRBandwidth()->Display(tab+1);
			}
				break;
			case MediaComponentDescription_CODECDATA:
			{
				if( mCodecDataList->size() <= 0) {
					break;
				}

				mCodecDataIterator = this->getCodecDataList()->begin();
				while(mCodecDataIterator != this->getCodecDataList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "524" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CodecData" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
					(*mCodecDataIterator)->Display(tab+1);
					mCodecDataIterator++;

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


BOOLEAN MediaComponentDescription::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<11> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case MediaComponentDescription_MEDIACOMPONENTNUMBER:
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
			case MediaComponentDescription_MEDIASUBCOMPONENT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 519");
				}
				else
					sprintf(lMissingAvpInfo, "%s,519", lMissingAvpInfo);
			}
				break;
			case MediaComponentDescription_AFAPPLICATIONIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 504");
				}
				else
					sprintf(lMissingAvpInfo, "%s,504", lMissingAvpInfo);
			}
				break;
			case MediaComponentDescription_MEDIATYPE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 520");
				}
				else
					sprintf(lMissingAvpInfo, "%s,520", lMissingAvpInfo);
			}
				break;
			case MediaComponentDescription_MAXREQUESTEDBANDWIDTHUL:
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
			case MediaComponentDescription_MAXREQUESTEDBANDWIDTHDL:
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
			case MediaComponentDescription_FLOWSTATUS:
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
			case MediaComponentDescription_RESERVATIONPRIORITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 458");
				}
				else
					sprintf(lMissingAvpInfo, "%s,458", lMissingAvpInfo);
			}
				break;
			case MediaComponentDescription_RSBANDWIDTH:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 522");
				}
				else
					sprintf(lMissingAvpInfo, "%s,522", lMissingAvpInfo);
			}
				break;
			case MediaComponentDescription_RRBANDWIDTH:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 521");
				}
				else
					sprintf(lMissingAvpInfo, "%s,521", lMissingAvpInfo);
			}
				break;
			case MediaComponentDescription_CODECDATA:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 524");
				}
				else
					sprintf(lMissingAvpInfo, "%s,524", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
