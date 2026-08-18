#include "sd/include/QoSInformation.h"

using namespace SD;
BOOLEAN QoSInformation::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

QoSInformation::QoSInformation()
{
	mQoSClassIdentifier = NULL;
	mMaxRequestedBandwidthUL = NULL;
	mMaxRequestedBandwidthDL = NULL;
	mExtendedMaxRequestedBWUL = NULL;
	mExtendedMaxRequestedBWDL = NULL;
	mGuaranteedBitrateUL = NULL;
	mGuaranteedBitrateDL = NULL;
	mExtendedGBRUL = NULL;
	mExtendedGBRDL = NULL;
	mBearerIdentifier = NULL;
	mAllocationRetentionPriorityGrp = NULL;
	mAPNAggregateMaxBitrateUL = NULL;
	mAPNAggregateMaxBitrateDL = NULL;
	mExtendedAPNAMBRUL = NULL;
	mExtendedAPNAMBRDL = NULL;
	mConditionalAPNAggregateMaxBitrateGrpList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<16>(string("0000001001100111"));
	mMandatoryAvpSetVal.reset();
}

QoSInformation::~QoSInformation()
{
	if(mQoSClassIdentifier != NULL)
		delete mQoSClassIdentifier;
	if(mMaxRequestedBandwidthUL != NULL)
		delete mMaxRequestedBandwidthUL;
	if(mMaxRequestedBandwidthDL != NULL)
		delete mMaxRequestedBandwidthDL;
	if(mExtendedMaxRequestedBWUL != NULL)
		delete mExtendedMaxRequestedBWUL;
	if(mExtendedMaxRequestedBWDL != NULL)
		delete mExtendedMaxRequestedBWDL;
	if(mGuaranteedBitrateUL != NULL)
		delete mGuaranteedBitrateUL;
	if(mGuaranteedBitrateDL != NULL)
		delete mGuaranteedBitrateDL;
	if(mExtendedGBRUL != NULL)
		delete mExtendedGBRUL;
	if(mExtendedGBRDL != NULL)
		delete mExtendedGBRDL;
	if(mBearerIdentifier != NULL)
		delete mBearerIdentifier;
	if(mAllocationRetentionPriorityGrp != NULL)
		delete mAllocationRetentionPriorityGrp;
	if(mAPNAggregateMaxBitrateUL != NULL)
		delete mAPNAggregateMaxBitrateUL;
	if(mAPNAggregateMaxBitrateDL != NULL)
		delete mAPNAggregateMaxBitrateDL;
	if(mExtendedAPNAMBRUL != NULL)
		delete mExtendedAPNAMBRUL;
	if(mExtendedAPNAMBRDL != NULL)
		delete mExtendedAPNAMBRDL;
	if(mConditionalAPNAggregateMaxBitrateGrpList != NULL){
		mConditionalAPNAggregateMaxBitrateGrpIterator = mConditionalAPNAggregateMaxBitrateGrpList->begin();
		while(mConditionalAPNAggregateMaxBitrateGrpIterator != mConditionalAPNAggregateMaxBitrateGrpList->end()){
	if(*mConditionalAPNAggregateMaxBitrateGrpIterator != NULL)
			delete (*mConditionalAPNAggregateMaxBitrateGrpIterator);
			mConditionalAPNAggregateMaxBitrateGrpIterator++;
		}
		delete mConditionalAPNAggregateMaxBitrateGrpList;
	}
}

QoSClassIdentifier* QoSInformation::setQoSClassIdentifier(){
	mMandatoryAvpSetVal [QoSInformation_QOSCLASSIDENTIFIER] = 1;
	if(mQoSClassIdentifier == NULL)
	{
		mQoSClassIdentifier = new QoSClassIdentifier();
		mTagsPresent[QoSInformation_QOSCLASSIDENTIFIER] = 1;
		return mQoSClassIdentifier;
	}
	return mQoSClassIdentifier;
}

void QoSInformation::resetQoSClassIdentifier(){
	mTagsPresent[QoSInformation_QOSCLASSIDENTIFIER] = 0;
	if(mQoSClassIdentifier != NULL)
	{
		delete mQoSClassIdentifier; 
		mQoSClassIdentifier = NULL;
	}
}

Unsigned32* QoSInformation::setMaxRequestedBandwidthUL(){
	mMandatoryAvpSetVal [QoSInformation_MAXREQUESTEDBANDWIDTHUL] = 1;
	if(mMaxRequestedBandwidthUL == NULL)
	{
		mMaxRequestedBandwidthUL = new Unsigned32();
		mTagsPresent[QoSInformation_MAXREQUESTEDBANDWIDTHUL] = 1;
		return mMaxRequestedBandwidthUL;
	}
	return mMaxRequestedBandwidthUL;
}

void QoSInformation::resetMaxRequestedBandwidthUL(){
	mTagsPresent[QoSInformation_MAXREQUESTEDBANDWIDTHUL] = 0;
	if(mMaxRequestedBandwidthUL != NULL)
	{
		delete mMaxRequestedBandwidthUL; 
		mMaxRequestedBandwidthUL = NULL;
	}
}

Unsigned32* QoSInformation::setMaxRequestedBandwidthDL(){
	mMandatoryAvpSetVal [QoSInformation_MAXREQUESTEDBANDWIDTHDL] = 1;
	if(mMaxRequestedBandwidthDL == NULL)
	{
		mMaxRequestedBandwidthDL = new Unsigned32();
		mTagsPresent[QoSInformation_MAXREQUESTEDBANDWIDTHDL] = 1;
		return mMaxRequestedBandwidthDL;
	}
	return mMaxRequestedBandwidthDL;
}

void QoSInformation::resetMaxRequestedBandwidthDL(){
	mTagsPresent[QoSInformation_MAXREQUESTEDBANDWIDTHDL] = 0;
	if(mMaxRequestedBandwidthDL != NULL)
	{
		delete mMaxRequestedBandwidthDL; 
		mMaxRequestedBandwidthDL = NULL;
	}
}

Unsigned32* QoSInformation::setExtendedMaxRequestedBWUL(){
	if(mExtendedMaxRequestedBWUL == NULL)
	{
		mExtendedMaxRequestedBWUL = new Unsigned32();
		mTagsPresent[QoSInformation_EXTENDEDMAXREQUESTEDBWUL] = 1;
		return mExtendedMaxRequestedBWUL;
	}
	return mExtendedMaxRequestedBWUL;
}

void QoSInformation::resetExtendedMaxRequestedBWUL(){
	mTagsPresent[QoSInformation_EXTENDEDMAXREQUESTEDBWUL] = 0;
	if(mExtendedMaxRequestedBWUL != NULL)
	{
		delete mExtendedMaxRequestedBWUL; 
		mExtendedMaxRequestedBWUL = NULL;
	}
}

Unsigned32* QoSInformation::setExtendedMaxRequestedBWDL(){
	if(mExtendedMaxRequestedBWDL == NULL)
	{
		mExtendedMaxRequestedBWDL = new Unsigned32();
		mTagsPresent[QoSInformation_EXTENDEDMAXREQUESTEDBWDL] = 1;
		return mExtendedMaxRequestedBWDL;
	}
	return mExtendedMaxRequestedBWDL;
}

void QoSInformation::resetExtendedMaxRequestedBWDL(){
	mTagsPresent[QoSInformation_EXTENDEDMAXREQUESTEDBWDL] = 0;
	if(mExtendedMaxRequestedBWDL != NULL)
	{
		delete mExtendedMaxRequestedBWDL; 
		mExtendedMaxRequestedBWDL = NULL;
	}
}

Unsigned32* QoSInformation::setGuaranteedBitrateUL(){
	mMandatoryAvpSetVal [QoSInformation_GUARANTEEDBITRATEUL] = 1;
	if(mGuaranteedBitrateUL == NULL)
	{
		mGuaranteedBitrateUL = new Unsigned32();
		mTagsPresent[QoSInformation_GUARANTEEDBITRATEUL] = 1;
		return mGuaranteedBitrateUL;
	}
	return mGuaranteedBitrateUL;
}

void QoSInformation::resetGuaranteedBitrateUL(){
	mTagsPresent[QoSInformation_GUARANTEEDBITRATEUL] = 0;
	if(mGuaranteedBitrateUL != NULL)
	{
		delete mGuaranteedBitrateUL; 
		mGuaranteedBitrateUL = NULL;
	}
}

Unsigned32* QoSInformation::setGuaranteedBitrateDL(){
	mMandatoryAvpSetVal [QoSInformation_GUARANTEEDBITRATEDL] = 1;
	if(mGuaranteedBitrateDL == NULL)
	{
		mGuaranteedBitrateDL = new Unsigned32();
		mTagsPresent[QoSInformation_GUARANTEEDBITRATEDL] = 1;
		return mGuaranteedBitrateDL;
	}
	return mGuaranteedBitrateDL;
}

void QoSInformation::resetGuaranteedBitrateDL(){
	mTagsPresent[QoSInformation_GUARANTEEDBITRATEDL] = 0;
	if(mGuaranteedBitrateDL != NULL)
	{
		delete mGuaranteedBitrateDL; 
		mGuaranteedBitrateDL = NULL;
	}
}

Unsigned32* QoSInformation::setExtendedGBRUL(){
	if(mExtendedGBRUL == NULL)
	{
		mExtendedGBRUL = new Unsigned32();
		mTagsPresent[QoSInformation_EXTENDEDGBRUL] = 1;
		return mExtendedGBRUL;
	}
	return mExtendedGBRUL;
}

void QoSInformation::resetExtendedGBRUL(){
	mTagsPresent[QoSInformation_EXTENDEDGBRUL] = 0;
	if(mExtendedGBRUL != NULL)
	{
		delete mExtendedGBRUL; 
		mExtendedGBRUL = NULL;
	}
}

Unsigned32* QoSInformation::setExtendedGBRDL(){
	if(mExtendedGBRDL == NULL)
	{
		mExtendedGBRDL = new Unsigned32();
		mTagsPresent[QoSInformation_EXTENDEDGBRDL] = 1;
		return mExtendedGBRDL;
	}
	return mExtendedGBRDL;
}

void QoSInformation::resetExtendedGBRDL(){
	mTagsPresent[QoSInformation_EXTENDEDGBRDL] = 0;
	if(mExtendedGBRDL != NULL)
	{
		delete mExtendedGBRDL; 
		mExtendedGBRDL = NULL;
	}
}

OctetString* QoSInformation::setBearerIdentifier(){
	mMandatoryAvpSetVal [QoSInformation_BEARERIDENTIFIER] = 1;
	if(mBearerIdentifier == NULL)
	{
		mBearerIdentifier = new OctetString();
		mTagsPresent[QoSInformation_BEARERIDENTIFIER] = 1;
		return mBearerIdentifier;
	}
	return mBearerIdentifier;
}

void QoSInformation::resetBearerIdentifier(){
	mTagsPresent[QoSInformation_BEARERIDENTIFIER] = 0;
	if(mBearerIdentifier != NULL)
	{
		delete mBearerIdentifier; 
		mBearerIdentifier = NULL;
	}
}

Unsigned32* QoSInformation::setAPNAggregateMaxBitrateUL(){
	if(mAPNAggregateMaxBitrateUL == NULL)
	{
		mAPNAggregateMaxBitrateUL = new Unsigned32();
		mTagsPresent[QoSInformation_APNAGGREGATEMAXBITRATEUL] = 1;
		return mAPNAggregateMaxBitrateUL;
	}
	return mAPNAggregateMaxBitrateUL;
}

void QoSInformation::resetAPNAggregateMaxBitrateUL(){
	mTagsPresent[QoSInformation_APNAGGREGATEMAXBITRATEUL] = 0;
	if(mAPNAggregateMaxBitrateUL != NULL)
	{
		delete mAPNAggregateMaxBitrateUL; 
		mAPNAggregateMaxBitrateUL = NULL;
	}
}

Unsigned32* QoSInformation::setAPNAggregateMaxBitrateDL(){
	if(mAPNAggregateMaxBitrateDL == NULL)
	{
		mAPNAggregateMaxBitrateDL = new Unsigned32();
		mTagsPresent[QoSInformation_APNAGGREGATEMAXBITRATEDL] = 1;
		return mAPNAggregateMaxBitrateDL;
	}
	return mAPNAggregateMaxBitrateDL;
}

void QoSInformation::resetAPNAggregateMaxBitrateDL(){
	mTagsPresent[QoSInformation_APNAGGREGATEMAXBITRATEDL] = 0;
	if(mAPNAggregateMaxBitrateDL != NULL)
	{
		delete mAPNAggregateMaxBitrateDL; 
		mAPNAggregateMaxBitrateDL = NULL;
	}
}

Unsigned32* QoSInformation::setExtendedAPNAMBRUL(){
	if(mExtendedAPNAMBRUL == NULL)
	{
		mExtendedAPNAMBRUL = new Unsigned32();
		mTagsPresent[QoSInformation_EXTENDEDAPNAMBRUL] = 1;
		return mExtendedAPNAMBRUL;
	}
	return mExtendedAPNAMBRUL;
}

void QoSInformation::resetExtendedAPNAMBRUL(){
	mTagsPresent[QoSInformation_EXTENDEDAPNAMBRUL] = 0;
	if(mExtendedAPNAMBRUL != NULL)
	{
		delete mExtendedAPNAMBRUL; 
		mExtendedAPNAMBRUL = NULL;
	}
}

Unsigned32* QoSInformation::setExtendedAPNAMBRDL(){
	if(mExtendedAPNAMBRDL == NULL)
	{
		mExtendedAPNAMBRDL = new Unsigned32();
		mTagsPresent[QoSInformation_EXTENDEDAPNAMBRDL] = 1;
		return mExtendedAPNAMBRDL;
	}
	return mExtendedAPNAMBRDL;
}

void QoSInformation::resetExtendedAPNAMBRDL(){
	mTagsPresent[QoSInformation_EXTENDEDAPNAMBRDL] = 0;
	if(mExtendedAPNAMBRDL != NULL)
	{
		delete mExtendedAPNAMBRDL; 
		mExtendedAPNAMBRDL = NULL;
	}
}

QoSClassIdentifier* QoSInformation::getQoSClassIdentifier(){
	if(NULL == mQoSClassIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "QoSClassIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mQoSClassIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mQoSClassIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "QoSClassIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mQoSClassIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mQoSClassIdentifier->Decode(mspByteArray.get(), mQoSClassIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding QoSClassIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mQoSClassIdentifier->mAvpDecodedFlag = true;
	}
	return mQoSClassIdentifier;
}

Unsigned32* QoSInformation::getMaxRequestedBandwidthUL(){
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

Unsigned32* QoSInformation::getMaxRequestedBandwidthDL(){
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

Unsigned32* QoSInformation::getExtendedMaxRequestedBWUL(){
	if(NULL == mExtendedMaxRequestedBWUL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedMaxRequestedBWUL is Null");
		throw lTssDiaMsgException;
	}
	if(!mExtendedMaxRequestedBWUL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExtendedMaxRequestedBWUL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedMaxRequestedBWUL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExtendedMaxRequestedBWUL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExtendedMaxRequestedBWUL->Decode(mspByteArray.get(), mExtendedMaxRequestedBWUL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedMaxRequestedBWUL")     ;
			throw lTssDiaMsgException;
		}
		mExtendedMaxRequestedBWUL->mAvpDecodedFlag = true;
	}
	return mExtendedMaxRequestedBWUL;
}

Unsigned32* QoSInformation::getExtendedMaxRequestedBWDL(){
	if(NULL == mExtendedMaxRequestedBWDL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedMaxRequestedBWDL is Null");
		throw lTssDiaMsgException;
	}
	if(!mExtendedMaxRequestedBWDL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExtendedMaxRequestedBWDL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedMaxRequestedBWDL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExtendedMaxRequestedBWDL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExtendedMaxRequestedBWDL->Decode(mspByteArray.get(), mExtendedMaxRequestedBWDL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedMaxRequestedBWDL")     ;
			throw lTssDiaMsgException;
		}
		mExtendedMaxRequestedBWDL->mAvpDecodedFlag = true;
	}
	return mExtendedMaxRequestedBWDL;
}

Unsigned32* QoSInformation::getGuaranteedBitrateUL(){
	if(NULL == mGuaranteedBitrateUL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GuaranteedBitrateUL is Null");
		throw lTssDiaMsgException;
	}
	if(!mGuaranteedBitrateUL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mGuaranteedBitrateUL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GuaranteedBitrateUL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mGuaranteedBitrateUL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mGuaranteedBitrateUL->Decode(mspByteArray.get(), mGuaranteedBitrateUL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GuaranteedBitrateUL")     ;
			throw lTssDiaMsgException;
		}
		mGuaranteedBitrateUL->mAvpDecodedFlag = true;
	}
	return mGuaranteedBitrateUL;
}

Unsigned32* QoSInformation::getGuaranteedBitrateDL(){
	if(NULL == mGuaranteedBitrateDL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GuaranteedBitrateDL is Null");
		throw lTssDiaMsgException;
	}
	if(!mGuaranteedBitrateDL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mGuaranteedBitrateDL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GuaranteedBitrateDL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mGuaranteedBitrateDL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mGuaranteedBitrateDL->Decode(mspByteArray.get(), mGuaranteedBitrateDL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GuaranteedBitrateDL")     ;
			throw lTssDiaMsgException;
		}
		mGuaranteedBitrateDL->mAvpDecodedFlag = true;
	}
	return mGuaranteedBitrateDL;
}

Unsigned32* QoSInformation::getExtendedGBRUL(){
	if(NULL == mExtendedGBRUL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedGBRUL is Null");
		throw lTssDiaMsgException;
	}
	if(!mExtendedGBRUL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExtendedGBRUL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedGBRUL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExtendedGBRUL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExtendedGBRUL->Decode(mspByteArray.get(), mExtendedGBRUL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedGBRUL")     ;
			throw lTssDiaMsgException;
		}
		mExtendedGBRUL->mAvpDecodedFlag = true;
	}
	return mExtendedGBRUL;
}

Unsigned32* QoSInformation::getExtendedGBRDL(){
	if(NULL == mExtendedGBRDL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedGBRDL is Null");
		throw lTssDiaMsgException;
	}
	if(!mExtendedGBRDL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExtendedGBRDL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedGBRDL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExtendedGBRDL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExtendedGBRDL->Decode(mspByteArray.get(), mExtendedGBRDL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedGBRDL")     ;
			throw lTssDiaMsgException;
		}
		mExtendedGBRDL->mAvpDecodedFlag = true;
	}
	return mExtendedGBRDL;
}

OctetString* QoSInformation::getBearerIdentifier(){
	if(NULL == mBearerIdentifier) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "BearerIdentifier is Null");
		throw lTssDiaMsgException;
	}
	if(!mBearerIdentifier->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mBearerIdentifier->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "BearerIdentifier is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mBearerIdentifier->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mBearerIdentifier->Decode(mspByteArray.get(), mBearerIdentifier->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding BearerIdentifier")     ;
			throw lTssDiaMsgException;
		}
		mBearerIdentifier->mAvpDecodedFlag = true;
	}
	return mBearerIdentifier;
}

AllocationRetentionPriority* QoSInformation::getAllocationRetentionPriority()
{
	if(mAllocationRetentionPriorityGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AllocationRetentionPriority is Null");
		throw lTssDiaMsgException;
	}
	if(!mAllocationRetentionPriorityGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAllocationRetentionPriorityGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "AllocationRetentionPriority is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAllocationRetentionPriorityGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAllocationRetentionPriorityGrp->Decode(mspByteArray.get(), mAllocationRetentionPriorityGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AllocationRetentionPriority")     ;
			throw lTssDiaMsgException;
		}
		mAllocationRetentionPriorityGrp->mAvpDecodedFlag = true;
	}
	return mAllocationRetentionPriorityGrp;
}

AllocationRetentionPriority* QoSInformation::setAllocationRetentionPriority(){
	if(mAllocationRetentionPriorityGrp == NULL)
		mAllocationRetentionPriorityGrp = new AllocationRetentionPriority();
	mTagsPresent[QoSInformation_ALLOCATIONRETENTIONPRIORITY] = 1;
	return mAllocationRetentionPriorityGrp;
}

void QoSInformation::resetAllocationRetentionPriority(){
	mTagsPresent[QoSInformation_ALLOCATIONRETENTIONPRIORITY] = 0;
	if(mAllocationRetentionPriorityGrp != NULL)
		delete mAllocationRetentionPriorityGrp;
}

Unsigned32* QoSInformation::getAPNAggregateMaxBitrateUL(){
	if(NULL == mAPNAggregateMaxBitrateUL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "APNAggregateMaxBitrateUL is Null");
		throw lTssDiaMsgException;
	}
	if(!mAPNAggregateMaxBitrateUL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAPNAggregateMaxBitrateUL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "APNAggregateMaxBitrateUL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAPNAggregateMaxBitrateUL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAPNAggregateMaxBitrateUL->Decode(mspByteArray.get(), mAPNAggregateMaxBitrateUL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding APNAggregateMaxBitrateUL")     ;
			throw lTssDiaMsgException;
		}
		mAPNAggregateMaxBitrateUL->mAvpDecodedFlag = true;
	}
	return mAPNAggregateMaxBitrateUL;
}

Unsigned32* QoSInformation::getAPNAggregateMaxBitrateDL(){
	if(NULL == mAPNAggregateMaxBitrateDL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "APNAggregateMaxBitrateDL is Null");
		throw lTssDiaMsgException;
	}
	if(!mAPNAggregateMaxBitrateDL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mAPNAggregateMaxBitrateDL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "APNAggregateMaxBitrateDL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mAPNAggregateMaxBitrateDL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mAPNAggregateMaxBitrateDL->Decode(mspByteArray.get(), mAPNAggregateMaxBitrateDL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding APNAggregateMaxBitrateDL")     ;
			throw lTssDiaMsgException;
		}
		mAPNAggregateMaxBitrateDL->mAvpDecodedFlag = true;
	}
	return mAPNAggregateMaxBitrateDL;
}

Unsigned32* QoSInformation::getExtendedAPNAMBRUL(){
	if(NULL == mExtendedAPNAMBRUL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedAPNAMBRUL is Null");
		throw lTssDiaMsgException;
	}
	if(!mExtendedAPNAMBRUL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExtendedAPNAMBRUL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedAPNAMBRUL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExtendedAPNAMBRUL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExtendedAPNAMBRUL->Decode(mspByteArray.get(), mExtendedAPNAMBRUL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedAPNAMBRUL")     ;
			throw lTssDiaMsgException;
		}
		mExtendedAPNAMBRUL->mAvpDecodedFlag = true;
	}
	return mExtendedAPNAMBRUL;
}

Unsigned32* QoSInformation::getExtendedAPNAMBRDL(){
	if(NULL == mExtendedAPNAMBRDL) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedAPNAMBRDL is Null");
		throw lTssDiaMsgException;
	}
	if(!mExtendedAPNAMBRDL->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mExtendedAPNAMBRDL->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ExtendedAPNAMBRDL is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mExtendedAPNAMBRDL->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mExtendedAPNAMBRDL->Decode(mspByteArray.get(), mExtendedAPNAMBRDL->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedAPNAMBRDL")     ;
			throw lTssDiaMsgException;
		}
		mExtendedAPNAMBRDL->mAvpDecodedFlag = true;
	}
	return mExtendedAPNAMBRDL;
}

list<ConditionalAPNAggregateMaxBitrate*>* QoSInformation::getConditionalAPNAggregateMaxBitrateGrpList()
{
	if(mConditionalAPNAggregateMaxBitrateGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ConditionalAPNAggregateMaxBitrate is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mConditionalAPNAggregateMaxBitrateGrpList)
	{
		if(mConditionalAPNAggregateMaxBitrateGrpList != NULL)
		{
		if(mConditionalAPNAggregateMaxBitrateGrpList->size() == 0)
		{
			mTagsPresent[QoSInformation_CONDITIONALAPNAGGREGATEMAXBITRATE] = 0;
			mConditionalAPNAggregateMaxBitrateGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ConditionalAPNAggregateMaxBitrate is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ConditionalAPNAggregateMaxBitrate is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ConditionalAPNAggregateMaxBitrate")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mConditionalAPNAggregateMaxBitrateGrpList;
}

list<ConditionalAPNAggregateMaxBitrate*>* QoSInformation::setConditionalAPNAggregateMaxBitrateGrpList(){
	mTagsPresent[QoSInformation_CONDITIONALAPNAGGREGATEMAXBITRATE] = 1;
	if(mConditionalAPNAggregateMaxBitrateGrpList == NULL)
		mConditionalAPNAggregateMaxBitrateGrpList = new list<ConditionalAPNAggregateMaxBitrate*>;
	mConditionalAPNAggregateMaxBitrateGrpList->clear();
	return mConditionalAPNAggregateMaxBitrateGrpList;
}

void QoSInformation::resetConditionalAPNAggregateMaxBitrateGrpList(){
	mTagsPresent[QoSInformation_CONDITIONALAPNAGGREGATEMAXBITRATE] = 0;
	if(mConditionalAPNAggregateMaxBitrateGrpList != NULL)
		delete mConditionalAPNAggregateMaxBitrateGrpList;
}



int QoSInformation::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case QoSInformation_QOSCLASSIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1028);
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
					if(!mQoSClassIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mQoSClassIdentifier->getAvpOffsetLen().first], mQoSClassIdentifier->getAvpOffsetLen().second);
						array->offset += mQoSClassIdentifier->getAvpOffsetLen().second;
						array->size += mQoSClassIdentifier->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding QoSClassIdentifier");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mQoSClassIdentifier->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding QoSClassIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_MAXREQUESTEDBANDWIDTHUL:
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
			case QoSInformation_MAXREQUESTEDBANDWIDTHDL:
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
			case QoSInformation_EXTENDEDMAXREQUESTEDBWUL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(554);
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
					if(!mExtendedMaxRequestedBWUL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mExtendedMaxRequestedBWUL->getAvpOffsetLen().first], mExtendedMaxRequestedBWUL->getAvpOffsetLen().second);
						array->offset += mExtendedMaxRequestedBWUL->getAvpOffsetLen().second;
						array->size += mExtendedMaxRequestedBWUL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedMaxRequestedBWUL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mExtendedMaxRequestedBWUL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedMaxRequestedBWUL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_EXTENDEDMAXREQUESTEDBWDL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(555);
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
					if(!mExtendedMaxRequestedBWDL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mExtendedMaxRequestedBWDL->getAvpOffsetLen().first], mExtendedMaxRequestedBWDL->getAvpOffsetLen().second);
						array->offset += mExtendedMaxRequestedBWDL->getAvpOffsetLen().second;
						array->size += mExtendedMaxRequestedBWDL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedMaxRequestedBWDL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mExtendedMaxRequestedBWDL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedMaxRequestedBWDL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_GUARANTEEDBITRATEUL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1026);
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
					if(!mGuaranteedBitrateUL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mGuaranteedBitrateUL->getAvpOffsetLen().first], mGuaranteedBitrateUL->getAvpOffsetLen().second);
						array->offset += mGuaranteedBitrateUL->getAvpOffsetLen().second;
						array->size += mGuaranteedBitrateUL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GuaranteedBitrateUL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mGuaranteedBitrateUL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GuaranteedBitrateUL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_GUARANTEEDBITRATEDL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1025);
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
					if(!mGuaranteedBitrateDL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mGuaranteedBitrateDL->getAvpOffsetLen().first], mGuaranteedBitrateDL->getAvpOffsetLen().second);
						array->offset += mGuaranteedBitrateDL->getAvpOffsetLen().second;
						array->size += mGuaranteedBitrateDL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GuaranteedBitrateDL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mGuaranteedBitrateDL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GuaranteedBitrateDL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_EXTENDEDGBRUL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2851);
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
					if(!mExtendedGBRUL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mExtendedGBRUL->getAvpOffsetLen().first], mExtendedGBRUL->getAvpOffsetLen().second);
						array->offset += mExtendedGBRUL->getAvpOffsetLen().second;
						array->size += mExtendedGBRUL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedGBRUL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mExtendedGBRUL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedGBRUL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_EXTENDEDGBRDL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2850);
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
					if(!mExtendedGBRDL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mExtendedGBRDL->getAvpOffsetLen().first], mExtendedGBRDL->getAvpOffsetLen().second);
						array->offset += mExtendedGBRDL->getAvpOffsetLen().second;
						array->size += mExtendedGBRDL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedGBRDL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mExtendedGBRDL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedGBRDL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_BEARERIDENTIFIER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1020);
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
					if(!mBearerIdentifier->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mBearerIdentifier->getAvpOffsetLen().first], mBearerIdentifier->getAvpOffsetLen().second);
						array->offset += mBearerIdentifier->getAvpOffsetLen().second;
						array->size += mBearerIdentifier->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mBearerIdentifier->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mBearerIdentifier->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding BearerIdentifier");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mBearerIdentifier->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mBearerIdentifier->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding BearerIdentifier");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_ALLOCATIONRETENTIONPRIORITY:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(1034);
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
				if((this->getAllocationRetentionPriority()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding AllocationRetentionPriority");
					throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_APNAGGREGATEMAXBITRATEUL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1041);
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
					if(!mAPNAggregateMaxBitrateUL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAPNAggregateMaxBitrateUL->getAvpOffsetLen().first], mAPNAggregateMaxBitrateUL->getAvpOffsetLen().second);
						array->offset += mAPNAggregateMaxBitrateUL->getAvpOffsetLen().second;
						array->size += mAPNAggregateMaxBitrateUL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding APNAggregateMaxBitrateUL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAPNAggregateMaxBitrateUL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding APNAggregateMaxBitrateUL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_APNAGGREGATEMAXBITRATEDL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(1040);
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
					if(!mAPNAggregateMaxBitrateDL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mAPNAggregateMaxBitrateDL->getAvpOffsetLen().first], mAPNAggregateMaxBitrateDL->getAvpOffsetLen().second);
						array->offset += mAPNAggregateMaxBitrateDL->getAvpOffsetLen().second;
						array->size += mAPNAggregateMaxBitrateDL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding APNAggregateMaxBitrateDL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mAPNAggregateMaxBitrateDL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding APNAggregateMaxBitrateDL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_EXTENDEDAPNAMBRUL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2849);
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
					if(!mExtendedAPNAMBRUL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mExtendedAPNAMBRUL->getAvpOffsetLen().first], mExtendedAPNAMBRUL->getAvpOffsetLen().second);
						array->offset += mExtendedAPNAMBRUL->getAvpOffsetLen().second;
						array->size += mExtendedAPNAMBRUL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedAPNAMBRUL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mExtendedAPNAMBRUL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedAPNAMBRUL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_EXTENDEDAPNAMBRDL:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(2848);
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
					if(!mExtendedAPNAMBRDL->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mExtendedAPNAMBRDL->getAvpOffsetLen().first], mExtendedAPNAMBRDL->getAvpOffsetLen().second);
						array->offset += mExtendedAPNAMBRDL->getAvpOffsetLen().second;
						array->size += mExtendedAPNAMBRDL->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedAPNAMBRDL");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mExtendedAPNAMBRDL->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ExtendedAPNAMBRDL");
						throw lTssDiaMsgException;
					}
				}
				break;
			case QoSInformation_CONDITIONALAPNAGGREGATEMAXBITRATE:
			{
				if( mConditionalAPNAggregateMaxBitrateGrpList->size() <= 0) {
					break;
				}

				mConditionalAPNAggregateMaxBitrateGrpIterator = this->getConditionalAPNAggregateMaxBitrateGrpList()->begin();
				while(mConditionalAPNAggregateMaxBitrateGrpIterator != mConditionalAPNAggregateMaxBitrateGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(2818);
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
					if(((*mConditionalAPNAggregateMaxBitrateGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ConditionalAPNAggregateMaxBitrate");
						throw lTssDiaMsgException;
					}
					
					mConditionalAPNAggregateMaxBitrateGrpIterator++;
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


int QoSInformation::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1028:
				{
						mMandatoryAvpSetVal [QoSInformation_QOSCLASSIDENTIFIER] = 1;
					if( NULL == this->setQoSClassIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding QoSClassIdentifier");
						throw lTssDiaMsgException;
					}
					mQoSClassIdentifier->setAvpCode(1028);
					mQoSClassIdentifier->setAvpVendorId(lVenderId);
					mQoSClassIdentifier->SetDataType((DiameterDataType)7);
					mQoSClassIdentifier->mspByteArray = mspByteArray;
					mQoSClassIdentifier->mAvpDecodedFlag = false;
					mQoSClassIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 516:
				{
						mMandatoryAvpSetVal [QoSInformation_MAXREQUESTEDBANDWIDTHUL] = 1;
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
						mMandatoryAvpSetVal [QoSInformation_MAXREQUESTEDBANDWIDTHDL] = 1;
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
			case 554:
				{
					if( NULL == this->setExtendedMaxRequestedBWUL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedMaxRequestedBWUL");
						throw lTssDiaMsgException;
					}
					mExtendedMaxRequestedBWUL->setAvpCode(554);
					mExtendedMaxRequestedBWUL->setAvpVendorId(lVenderId);
					mExtendedMaxRequestedBWUL->SetDataType((DiameterDataType)3);
					mExtendedMaxRequestedBWUL->mspByteArray = mspByteArray;
					mExtendedMaxRequestedBWUL->mAvpDecodedFlag = false;
					mExtendedMaxRequestedBWUL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 555:
				{
					if( NULL == this->setExtendedMaxRequestedBWDL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedMaxRequestedBWDL");
						throw lTssDiaMsgException;
					}
					mExtendedMaxRequestedBWDL->setAvpCode(555);
					mExtendedMaxRequestedBWDL->setAvpVendorId(lVenderId);
					mExtendedMaxRequestedBWDL->SetDataType((DiameterDataType)3);
					mExtendedMaxRequestedBWDL->mspByteArray = mspByteArray;
					mExtendedMaxRequestedBWDL->mAvpDecodedFlag = false;
					mExtendedMaxRequestedBWDL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1026:
				{
						mMandatoryAvpSetVal [QoSInformation_GUARANTEEDBITRATEUL] = 1;
					if( NULL == this->setGuaranteedBitrateUL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GuaranteedBitrateUL");
						throw lTssDiaMsgException;
					}
					mGuaranteedBitrateUL->setAvpCode(1026);
					mGuaranteedBitrateUL->setAvpVendorId(lVenderId);
					mGuaranteedBitrateUL->SetDataType((DiameterDataType)3);
					mGuaranteedBitrateUL->mspByteArray = mspByteArray;
					mGuaranteedBitrateUL->mAvpDecodedFlag = false;
					mGuaranteedBitrateUL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1025:
				{
						mMandatoryAvpSetVal [QoSInformation_GUARANTEEDBITRATEDL] = 1;
					if( NULL == this->setGuaranteedBitrateDL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GuaranteedBitrateDL");
						throw lTssDiaMsgException;
					}
					mGuaranteedBitrateDL->setAvpCode(1025);
					mGuaranteedBitrateDL->setAvpVendorId(lVenderId);
					mGuaranteedBitrateDL->SetDataType((DiameterDataType)3);
					mGuaranteedBitrateDL->mspByteArray = mspByteArray;
					mGuaranteedBitrateDL->mAvpDecodedFlag = false;
					mGuaranteedBitrateDL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2851:
				{
					if( NULL == this->setExtendedGBRUL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedGBRUL");
						throw lTssDiaMsgException;
					}
					mExtendedGBRUL->setAvpCode(2851);
					mExtendedGBRUL->setAvpVendorId(lVenderId);
					mExtendedGBRUL->SetDataType((DiameterDataType)3);
					mExtendedGBRUL->mspByteArray = mspByteArray;
					mExtendedGBRUL->mAvpDecodedFlag = false;
					mExtendedGBRUL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2850:
				{
					if( NULL == this->setExtendedGBRDL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedGBRDL");
						throw lTssDiaMsgException;
					}
					mExtendedGBRDL->setAvpCode(2850);
					mExtendedGBRDL->setAvpVendorId(lVenderId);
					mExtendedGBRDL->SetDataType((DiameterDataType)3);
					mExtendedGBRDL->mspByteArray = mspByteArray;
					mExtendedGBRDL->mAvpDecodedFlag = false;
					mExtendedGBRDL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1020:
				{
						mMandatoryAvpSetVal [QoSInformation_BEARERIDENTIFIER] = 1;
					if( NULL == this->setBearerIdentifier())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding BearerIdentifier");
						throw lTssDiaMsgException;
					}
					mBearerIdentifier->setAvpCode(1020);
					mBearerIdentifier->setAvpVendorId(lVenderId);
					mBearerIdentifier->SetDataType((DiameterDataType)5);
					mBearerIdentifier->mspByteArray = mspByteArray;
					mBearerIdentifier->mAvpDecodedFlag = false;
					mBearerIdentifier->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1034:
				{
					mTagsPresent[QoSInformation_ALLOCATIONRETENTIONPRIORITY] = 1;
						if( NULL == this->setAllocationRetentionPriority()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AllocationRetentionPriority");
						throw lTssDiaMsgException;
						}
					mAllocationRetentionPriorityGrp->setAvpCode(1034);
					mAllocationRetentionPriorityGrp->SetDataType((DiameterDataType)6);
					mAllocationRetentionPriorityGrp->mspByteArray = mspByteArray;
					mAllocationRetentionPriorityGrp->mAvpDecodedFlag = false;
					mAllocationRetentionPriorityGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mAllocationRetentionPriorityGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1041:
				{
					if( NULL == this->setAPNAggregateMaxBitrateUL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding APNAggregateMaxBitrateUL");
						throw lTssDiaMsgException;
					}
					mAPNAggregateMaxBitrateUL->setAvpCode(1041);
					mAPNAggregateMaxBitrateUL->setAvpVendorId(lVenderId);
					mAPNAggregateMaxBitrateUL->SetDataType((DiameterDataType)3);
					mAPNAggregateMaxBitrateUL->mspByteArray = mspByteArray;
					mAPNAggregateMaxBitrateUL->mAvpDecodedFlag = false;
					mAPNAggregateMaxBitrateUL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 1040:
				{
					if( NULL == this->setAPNAggregateMaxBitrateDL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding APNAggregateMaxBitrateDL");
						throw lTssDiaMsgException;
					}
					mAPNAggregateMaxBitrateDL->setAvpCode(1040);
					mAPNAggregateMaxBitrateDL->setAvpVendorId(lVenderId);
					mAPNAggregateMaxBitrateDL->SetDataType((DiameterDataType)3);
					mAPNAggregateMaxBitrateDL->mspByteArray = mspByteArray;
					mAPNAggregateMaxBitrateDL->mAvpDecodedFlag = false;
					mAPNAggregateMaxBitrateDL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2849:
				{
					if( NULL == this->setExtendedAPNAMBRUL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedAPNAMBRUL");
						throw lTssDiaMsgException;
					}
					mExtendedAPNAMBRUL->setAvpCode(2849);
					mExtendedAPNAMBRUL->setAvpVendorId(lVenderId);
					mExtendedAPNAMBRUL->SetDataType((DiameterDataType)3);
					mExtendedAPNAMBRUL->mspByteArray = mspByteArray;
					mExtendedAPNAMBRUL->mAvpDecodedFlag = false;
					mExtendedAPNAMBRUL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2848:
				{
					if( NULL == this->setExtendedAPNAMBRDL())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ExtendedAPNAMBRDL");
						throw lTssDiaMsgException;
					}
					mExtendedAPNAMBRDL->setAvpCode(2848);
					mExtendedAPNAMBRDL->setAvpVendorId(lVenderId);
					mExtendedAPNAMBRDL->SetDataType((DiameterDataType)3);
					mExtendedAPNAMBRDL->mspByteArray = mspByteArray;
					mExtendedAPNAMBRDL->mAvpDecodedFlag = false;
					mExtendedAPNAMBRDL->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 2818:
				{
					mTagsPresent[QoSInformation_CONDITIONALAPNAGGREGATEMAXBITRATE] = 1;
					ConditionalAPNAggregateMaxBitrate *lConditionalAPNAggregateMaxBitrate = new ConditionalAPNAggregateMaxBitrate();
					if( lConditionalAPNAggregateMaxBitrate == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ConditionalAPNAggregateMaxBitrate");
						throw lTssDiaMsgException;
					}
					lConditionalAPNAggregateMaxBitrate->setAvpCode(2818);
					lConditionalAPNAggregateMaxBitrate->SetDataType((DiameterDataType)6);
					lConditionalAPNAggregateMaxBitrate->mspByteArray = mspByteArray;
					lConditionalAPNAggregateMaxBitrate->mAvpDecodedFlag = false;
					lConditionalAPNAggregateMaxBitrate->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mConditionalAPNAggregateMaxBitrateGrpList == NULL)
						this->setConditionalAPNAggregateMaxBitrateGrpList();
					mConditionalAPNAggregateMaxBitrateGrpList->push_back(lConditionalAPNAggregateMaxBitrate);
					mBaseInterfaceList.push_back(lConditionalAPNAggregateMaxBitrate);
					
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


DiameterBaseInterface* QoSInformation::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding QoSInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1028:
			{
				if(mQoSClassIdentifier != NULL)
					return mQoSClassIdentifier->Find(array, avpCode);
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
			case 554:
			{
				if(mExtendedMaxRequestedBWUL != NULL)
					return mExtendedMaxRequestedBWUL->Find(array, avpCode);
				else
					return NULL;
			}
			case 555:
			{
				if(mExtendedMaxRequestedBWDL != NULL)
					return mExtendedMaxRequestedBWDL->Find(array, avpCode);
				else
					return NULL;
			}
			case 1026:
			{
				if(mGuaranteedBitrateUL != NULL)
					return mGuaranteedBitrateUL->Find(array, avpCode);
				else
					return NULL;
			}
			case 1025:
			{
				if(mGuaranteedBitrateDL != NULL)
					return mGuaranteedBitrateDL->Find(array, avpCode);
				else
					return NULL;
			}
			case 2851:
			{
				if(mExtendedGBRUL != NULL)
					return mExtendedGBRUL->Find(array, avpCode);
				else
					return NULL;
			}
			case 2850:
			{
				if(mExtendedGBRDL != NULL)
					return mExtendedGBRDL->Find(array, avpCode);
				else
					return NULL;
			}
			case 1020:
			{
				if(mBearerIdentifier != NULL)
					return mBearerIdentifier->Find(array, avpCode);
				else
					return NULL;
			}
			case 1041:
			{
				if(mAPNAggregateMaxBitrateUL != NULL)
					return mAPNAggregateMaxBitrateUL->Find(array, avpCode);
				else
					return NULL;
			}
			case 1040:
			{
				if(mAPNAggregateMaxBitrateDL != NULL)
					return mAPNAggregateMaxBitrateDL->Find(array, avpCode);
				else
					return NULL;
			}
			case 2849:
			{
				if(mExtendedAPNAMBRUL != NULL)
					return mExtendedAPNAMBRUL->Find(array, avpCode);
				else
					return NULL;
			}
			case 2848:
			{
				if(mExtendedAPNAMBRDL != NULL)
					return mExtendedAPNAMBRDL->Find(array, avpCode);
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


BOOLEAN QoSInformation::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding QoSInformation")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1028:
			{
				if(mQoSClassIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mQoSClassIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 554:
			{
				if(mExtendedMaxRequestedBWUL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedMaxRequestedBWUL->Find(this->mspByteArray.get(), avpCode);
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
			case 555:
			{
				if(mExtendedMaxRequestedBWDL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedMaxRequestedBWDL->Find(this->mspByteArray.get(), avpCode);
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
			case 1026:
			{
				if(mGuaranteedBitrateUL != NULL)
				{
					DiameterBaseInterface* inf =  mGuaranteedBitrateUL->Find(this->mspByteArray.get(), avpCode);
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
			case 1025:
			{
				if(mGuaranteedBitrateDL != NULL)
				{
					DiameterBaseInterface* inf =  mGuaranteedBitrateDL->Find(this->mspByteArray.get(), avpCode);
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
			case 2851:
			{
				if(mExtendedGBRUL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedGBRUL->Find(this->mspByteArray.get(), avpCode);
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
			case 2850:
			{
				if(mExtendedGBRDL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedGBRDL->Find(this->mspByteArray.get(), avpCode);
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
			case 1020:
			{
				if(mBearerIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mBearerIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 1034:
			{
				if(mAllocationRetentionPriorityGrp != NULL)
				{
						pBaseInterface.push_back(mAllocationRetentionPriorityGrp);
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
			case 1041:
			{
				if(mAPNAggregateMaxBitrateUL != NULL)
				{
					DiameterBaseInterface* inf =  mAPNAggregateMaxBitrateUL->Find(this->mspByteArray.get(), avpCode);
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
			case 1040:
			{
				if(mAPNAggregateMaxBitrateDL != NULL)
				{
					DiameterBaseInterface* inf =  mAPNAggregateMaxBitrateDL->Find(this->mspByteArray.get(), avpCode);
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
			case 2849:
			{
				if(mExtendedAPNAMBRUL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedAPNAMBRUL->Find(this->mspByteArray.get(), avpCode);
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
			case 2848:
			{
				if(mExtendedAPNAMBRDL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedAPNAMBRDL->Find(this->mspByteArray.get(), avpCode);
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
			case 2818:
			{
				if(mConditionalAPNAggregateMaxBitrateGrpList != NULL)
				{
					for(auto itr = mConditionalAPNAggregateMaxBitrateGrpList->begin(); itr != mConditionalAPNAggregateMaxBitrateGrpList->end(); ++itr)
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
std::shared_ptr<byteArray> QoSInformation::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN QoSInformation::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding QoSInformation")     ;
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
			case 1028:
			{
				if(mQoSClassIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mQoSClassIdentifier->Find(this->mspByteArray.get(), avpCode);
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
			case 554:
			{
				if(mExtendedMaxRequestedBWUL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedMaxRequestedBWUL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 555:
			{
				if(mExtendedMaxRequestedBWDL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedMaxRequestedBWDL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1026:
			{
				if(mGuaranteedBitrateUL != NULL)
				{
					DiameterBaseInterface* inf =  mGuaranteedBitrateUL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1025:
			{
				if(mGuaranteedBitrateDL != NULL)
				{
					DiameterBaseInterface* inf =  mGuaranteedBitrateDL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2851:
			{
				if(mExtendedGBRUL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedGBRUL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2850:
			{
				if(mExtendedGBRDL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedGBRDL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1020:
			{
				if(mBearerIdentifier != NULL)
				{
					DiameterBaseInterface* inf =  mBearerIdentifier->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1034:
			{
				if(mAllocationRetentionPriorityGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mAllocationRetentionPriorityGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mAllocationRetentionPriorityGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 1041:
			{
				if(mAPNAggregateMaxBitrateUL != NULL)
				{
					DiameterBaseInterface* inf =  mAPNAggregateMaxBitrateUL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 1040:
			{
				if(mAPNAggregateMaxBitrateDL != NULL)
				{
					DiameterBaseInterface* inf =  mAPNAggregateMaxBitrateDL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2849:
			{
				if(mExtendedAPNAMBRUL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedAPNAMBRUL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2848:
			{
				if(mExtendedAPNAMBRDL != NULL)
				{
					DiameterBaseInterface* inf =  mExtendedAPNAMBRDL->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 2818:
			{
				if(mConditionalAPNAggregateMaxBitrateGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mConditionalAPNAggregateMaxBitrateGrpList->begin(); itr != mConditionalAPNAggregateMaxBitrateGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mConditionalAPNAggregateMaxBitrateGrpList->begin(); itr != mConditionalAPNAggregateMaxBitrateGrpList->end(); ++itr)
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


INT32 QoSInformation::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 QoSInformation::getAvpCode()
{
	return mAvpCode;
}
INT32 QoSInformation::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 QoSInformation::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 QoSInformation::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> QoSInformation::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void QoSInformation::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case QoSInformation_QOSCLASSIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1028" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "QoSClassIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getQoSClassIdentifier()->Display(tab+1);
			}
				break;
			case QoSInformation_MAXREQUESTEDBANDWIDTHUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "516" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MaxRequestedBandwidthUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMaxRequestedBandwidthUL()->Display(tab+1);
			}
				break;
			case QoSInformation_MAXREQUESTEDBANDWIDTHDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "515" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "MaxRequestedBandwidthDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getMaxRequestedBandwidthDL()->Display(tab+1);
			}
				break;
			case QoSInformation_EXTENDEDMAXREQUESTEDBWUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "554" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExtendedMaxRequestedBWUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getExtendedMaxRequestedBWUL()->Display(tab+1);
			}
				break;
			case QoSInformation_EXTENDEDMAXREQUESTEDBWDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "555" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExtendedMaxRequestedBWDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getExtendedMaxRequestedBWDL()->Display(tab+1);
			}
				break;
			case QoSInformation_GUARANTEEDBITRATEUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1026" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "GuaranteedBitrateUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getGuaranteedBitrateUL()->Display(tab+1);
			}
				break;
			case QoSInformation_GUARANTEEDBITRATEDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1025" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "GuaranteedBitrateDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getGuaranteedBitrateDL()->Display(tab+1);
			}
				break;
			case QoSInformation_EXTENDEDGBRUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2851" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExtendedGBRUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getExtendedGBRUL()->Display(tab+1);
			}
				break;
			case QoSInformation_EXTENDEDGBRDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2850" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExtendedGBRDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getExtendedGBRDL()->Display(tab+1);
			}
				break;
			case QoSInformation_BEARERIDENTIFIER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1020" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "BearerIdentifier" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getBearerIdentifier()->Display(tab+1);
			}
				break;
			case QoSInformation_ALLOCATIONRETENTIONPRIORITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1034" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "AllocationRetentionPriority" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getAllocationRetentionPriority()->Display(tab+1);
			}
				break;
			case QoSInformation_APNAGGREGATEMAXBITRATEUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1041" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "APNAggregateMaxBitrateUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getAPNAggregateMaxBitrateUL()->Display(tab+1);
			}
				break;
			case QoSInformation_APNAGGREGATEMAXBITRATEDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1040" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "APNAggregateMaxBitrateDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getAPNAggregateMaxBitrateDL()->Display(tab+1);
			}
				break;
			case QoSInformation_EXTENDEDAPNAMBRUL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2849" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExtendedAPNAMBRUL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getExtendedAPNAMBRUL()->Display(tab+1);
			}
				break;
			case QoSInformation_EXTENDEDAPNAMBRDL:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2848" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ExtendedAPNAMBRDL" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getExtendedAPNAMBRDL()->Display(tab+1);
			}
				break;
			case QoSInformation_CONDITIONALAPNAGGREGATEMAXBITRATE:
			{
				if( mConditionalAPNAggregateMaxBitrateGrpList->size() <= 0) {
					break;
				}

				mConditionalAPNAggregateMaxBitrateGrpIterator = this->getConditionalAPNAggregateMaxBitrateGrpList()->begin();
				while(mConditionalAPNAggregateMaxBitrateGrpIterator != this->getConditionalAPNAggregateMaxBitrateGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "2818" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ConditionalAPNAggregateMaxBitrate" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mConditionalAPNAggregateMaxBitrateGrpIterator)->Display(tab+1);
					mConditionalAPNAggregateMaxBitrateGrpIterator++;

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


BOOLEAN QoSInformation::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<16> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case QoSInformation_QOSCLASSIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1028");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1028", lMissingAvpInfo);
			}
				break;
			case QoSInformation_MAXREQUESTEDBANDWIDTHUL:
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
			case QoSInformation_MAXREQUESTEDBANDWIDTHDL:
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
			case QoSInformation_EXTENDEDMAXREQUESTEDBWUL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 554");
				}
				else
					sprintf(lMissingAvpInfo, "%s,554", lMissingAvpInfo);
			}
				break;
			case QoSInformation_EXTENDEDMAXREQUESTEDBWDL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 555");
				}
				else
					sprintf(lMissingAvpInfo, "%s,555", lMissingAvpInfo);
			}
				break;
			case QoSInformation_GUARANTEEDBITRATEUL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1026");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1026", lMissingAvpInfo);
			}
				break;
			case QoSInformation_GUARANTEEDBITRATEDL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1025");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1025", lMissingAvpInfo);
			}
				break;
			case QoSInformation_EXTENDEDGBRUL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2851");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2851", lMissingAvpInfo);
			}
				break;
			case QoSInformation_EXTENDEDGBRDL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2850");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2850", lMissingAvpInfo);
			}
				break;
			case QoSInformation_BEARERIDENTIFIER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1020");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1020", lMissingAvpInfo);
			}
				break;
			case QoSInformation_ALLOCATIONRETENTIONPRIORITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1034");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1034", lMissingAvpInfo);
			}
				break;
			case QoSInformation_APNAGGREGATEMAXBITRATEUL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1041");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1041", lMissingAvpInfo);
			}
				break;
			case QoSInformation_APNAGGREGATEMAXBITRATEDL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1040");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1040", lMissingAvpInfo);
			}
				break;
			case QoSInformation_EXTENDEDAPNAMBRUL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2849");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2849", lMissingAvpInfo);
			}
				break;
			case QoSInformation_EXTENDEDAPNAMBRDL:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2848");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2848", lMissingAvpInfo);
			}
				break;
			case QoSInformation_CONDITIONALAPNAGGREGATEMAXBITRATE:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 2818");
				}
				else
					sprintf(lMissingAvpInfo, "%s,2818", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
