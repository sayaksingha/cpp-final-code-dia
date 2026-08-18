#include "rx/include/SponsoredConnectivityData.h"

using namespace RX;
BOOLEAN SponsoredConnectivityData::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

SponsoredConnectivityData::SponsoredConnectivityData()
{
	mSponsorIdentity = NULL;
	mApplicationServiceProviderIdentity = NULL;
	mSponsoringAction = NULL;
	mGrantedServiceUnitGrp = NULL;
	mUsedServiceUnitGrp = NULL;
	mProxyInfoGrpList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<6>(string("111000"));
	mMandatoryAvpSetVal.reset();
}

SponsoredConnectivityData::~SponsoredConnectivityData()
{
	if(mSponsorIdentity != NULL)
		delete mSponsorIdentity;
	if(mApplicationServiceProviderIdentity != NULL)
		delete mApplicationServiceProviderIdentity;
	if(mSponsoringAction != NULL)
		delete mSponsoringAction;
	if(mGrantedServiceUnitGrp != NULL)
		delete mGrantedServiceUnitGrp;
	if(mUsedServiceUnitGrp != NULL)
		delete mUsedServiceUnitGrp;
	if(mProxyInfoGrpList != NULL){
		mProxyInfoGrpIterator = mProxyInfoGrpList->begin();
		while(mProxyInfoGrpIterator != mProxyInfoGrpList->end()){
	if(*mProxyInfoGrpIterator != NULL)
			delete (*mProxyInfoGrpIterator);
			mProxyInfoGrpIterator++;
		}
		delete mProxyInfoGrpList;
	}
}

OctetString* SponsoredConnectivityData::setSponsorIdentity(){
	if(mSponsorIdentity == NULL)
	{
		mSponsorIdentity = new OctetString();
		mTagsPresent[SponsoredConnectivityData_SPONSORIDENTITY] = 1;
		return mSponsorIdentity;
	}
	return mSponsorIdentity;
}

void SponsoredConnectivityData::resetSponsorIdentity(){
	mTagsPresent[SponsoredConnectivityData_SPONSORIDENTITY] = 0;
	if(mSponsorIdentity != NULL)
	{
		delete mSponsorIdentity; 
		mSponsorIdentity = NULL;
	}
}

OctetString* SponsoredConnectivityData::setApplicationServiceProviderIdentity(){
	if(mApplicationServiceProviderIdentity == NULL)
	{
		mApplicationServiceProviderIdentity = new OctetString();
		mTagsPresent[SponsoredConnectivityData_APPLICATIONSERVICEPROVIDERIDENTITY] = 1;
		return mApplicationServiceProviderIdentity;
	}
	return mApplicationServiceProviderIdentity;
}

void SponsoredConnectivityData::resetApplicationServiceProviderIdentity(){
	mTagsPresent[SponsoredConnectivityData_APPLICATIONSERVICEPROVIDERIDENTITY] = 0;
	if(mApplicationServiceProviderIdentity != NULL)
	{
		delete mApplicationServiceProviderIdentity; 
		mApplicationServiceProviderIdentity = NULL;
	}
}

SponsoringAction* SponsoredConnectivityData::setSponsoringAction(){
	if(mSponsoringAction == NULL)
	{
		mSponsoringAction = new SponsoringAction();
		mTagsPresent[SponsoredConnectivityData_SPONSORINGACTION] = 1;
		return mSponsoringAction;
	}
	return mSponsoringAction;
}

void SponsoredConnectivityData::resetSponsoringAction(){
	mTagsPresent[SponsoredConnectivityData_SPONSORINGACTION] = 0;
	if(mSponsoringAction != NULL)
	{
		delete mSponsoringAction; 
		mSponsoringAction = NULL;
	}
}

OctetString* SponsoredConnectivityData::getSponsorIdentity(){
	if(NULL == mSponsorIdentity) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SponsorIdentity is Null");
		throw lTssDiaMsgException;
	}
	if(!mSponsorIdentity->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSponsorIdentity->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SponsorIdentity is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSponsorIdentity->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSponsorIdentity->Decode(mspByteArray.get(), mSponsorIdentity->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SponsorIdentity")     ;
			throw lTssDiaMsgException;
		}
		mSponsorIdentity->mAvpDecodedFlag = true;
	}
	return mSponsorIdentity;
}

OctetString* SponsoredConnectivityData::getApplicationServiceProviderIdentity(){
	if(NULL == mApplicationServiceProviderIdentity) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ApplicationServiceProviderIdentity is Null");
		throw lTssDiaMsgException;
	}
	if(!mApplicationServiceProviderIdentity->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mApplicationServiceProviderIdentity->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ApplicationServiceProviderIdentity is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mApplicationServiceProviderIdentity->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mApplicationServiceProviderIdentity->Decode(mspByteArray.get(), mApplicationServiceProviderIdentity->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ApplicationServiceProviderIdentity")     ;
			throw lTssDiaMsgException;
		}
		mApplicationServiceProviderIdentity->mAvpDecodedFlag = true;
	}
	return mApplicationServiceProviderIdentity;
}

SponsoringAction* SponsoredConnectivityData::getSponsoringAction(){
	if(NULL == mSponsoringAction) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SponsoringAction is Null");
		throw lTssDiaMsgException;
	}
	if(!mSponsoringAction->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSponsoringAction->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SponsoringAction is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSponsoringAction->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSponsoringAction->Decode(mspByteArray.get(), mSponsoringAction->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SponsoringAction")     ;
			throw lTssDiaMsgException;
		}
		mSponsoringAction->mAvpDecodedFlag = true;
	}
	return mSponsoringAction;
}

GrantedServiceUnit* SponsoredConnectivityData::getGrantedServiceUnit()
{
	if(mGrantedServiceUnitGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GrantedServiceUnit is Null");
		throw lTssDiaMsgException;
	}
	if(!mGrantedServiceUnitGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mGrantedServiceUnitGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "GrantedServiceUnit is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mGrantedServiceUnitGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mGrantedServiceUnitGrp->Decode(mspByteArray.get(), mGrantedServiceUnitGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GrantedServiceUnit")     ;
			throw lTssDiaMsgException;
		}
		mGrantedServiceUnitGrp->mAvpDecodedFlag = true;
	}
	return mGrantedServiceUnitGrp;
}

GrantedServiceUnit* SponsoredConnectivityData::setGrantedServiceUnit(){
	if(mGrantedServiceUnitGrp == NULL)
		mGrantedServiceUnitGrp = new GrantedServiceUnit();
	mTagsPresent[SponsoredConnectivityData_GRANTEDSERVICEUNIT] = 1;
	mMandatoryAvpSetVal[SponsoredConnectivityData_GRANTEDSERVICEUNIT] = 1;
	return mGrantedServiceUnitGrp;
}

void SponsoredConnectivityData::resetGrantedServiceUnit(){
	mTagsPresent[SponsoredConnectivityData_GRANTEDSERVICEUNIT] = 0;
	if(mGrantedServiceUnitGrp != NULL)
		delete mGrantedServiceUnitGrp;
}

UsedServiceUnit* SponsoredConnectivityData::getUsedServiceUnit()
{
	if(mUsedServiceUnitGrp == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsedServiceUnit is Null");
		throw lTssDiaMsgException;
	}
	if(!mUsedServiceUnitGrp->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mUsedServiceUnitGrp->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "UsedServiceUnit is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mUsedServiceUnitGrp->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mUsedServiceUnitGrp->Decode(mspByteArray.get(), mUsedServiceUnitGrp->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsedServiceUnit")     ;
			throw lTssDiaMsgException;
		}
		mUsedServiceUnitGrp->mAvpDecodedFlag = true;
	}
	return mUsedServiceUnitGrp;
}

UsedServiceUnit* SponsoredConnectivityData::setUsedServiceUnit(){
	if(mUsedServiceUnitGrp == NULL)
		mUsedServiceUnitGrp = new UsedServiceUnit();
	mTagsPresent[SponsoredConnectivityData_USEDSERVICEUNIT] = 1;
	mMandatoryAvpSetVal[SponsoredConnectivityData_USEDSERVICEUNIT] = 1;
	return mUsedServiceUnitGrp;
}

void SponsoredConnectivityData::resetUsedServiceUnit(){
	mTagsPresent[SponsoredConnectivityData_USEDSERVICEUNIT] = 0;
	if(mUsedServiceUnitGrp != NULL)
		delete mUsedServiceUnitGrp;
}

list<RX::ProxyInfo*>* SponsoredConnectivityData::getProxyInfoGrpList()
{
	if(mProxyInfoGrpList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ProxyInfo is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mProxyInfoGrpList)
	{
		if(mProxyInfoGrpList != NULL)
		{
		if(mProxyInfoGrpList->size() == 0)
		{
			mTagsPresent[SponsoredConnectivityData_PROXYINFO] = 0;
			mProxyInfoGrpList = NULL;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ProxyInfo is Null");
			throw lTssDiaMsgException;
		}
	}
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
			itr->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ProxyInfo is Null");
			throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ProxyInfo")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mProxyInfoGrpList;
}

list<RX::ProxyInfo*>* SponsoredConnectivityData::setProxyInfoGrpList(){
	mTagsPresent[SponsoredConnectivityData_PROXYINFO] = 1;
	if(mProxyInfoGrpList == NULL)
		mProxyInfoGrpList = new list<RX::ProxyInfo*>;
	mMandatoryAvpSetVal[SponsoredConnectivityData_PROXYINFO] = 1;
	mProxyInfoGrpList->clear();
	return mProxyInfoGrpList;
}

void SponsoredConnectivityData::resetProxyInfoGrpList(){
	mTagsPresent[SponsoredConnectivityData_PROXYINFO] = 0;
	if(mProxyInfoGrpList != NULL)
		delete mProxyInfoGrpList;
}



int SponsoredConnectivityData::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case SponsoredConnectivityData_SPONSORIDENTITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(531);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 32;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(32))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mSponsorIdentity->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSponsorIdentity->getAvpOffsetLen().first], mSponsorIdentity->getAvpOffsetLen().second);
						array->offset += mSponsorIdentity->getAvpOffsetLen().second;
						array->size += mSponsorIdentity->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mSponsorIdentity->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mSponsorIdentity->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SponsorIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mSponsorIdentity->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mSponsorIdentity->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SponsorIdentity");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SponsoredConnectivityData_APPLICATIONSERVICEPROVIDERIDENTITY:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(532);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 32;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(32))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mApplicationServiceProviderIdentity->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mApplicationServiceProviderIdentity->getAvpOffsetLen().first], mApplicationServiceProviderIdentity->getAvpOffsetLen().second);
						array->offset += mApplicationServiceProviderIdentity->getAvpOffsetLen().second;
						array->size += mApplicationServiceProviderIdentity->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mApplicationServiceProviderIdentity->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mApplicationServiceProviderIdentity->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ApplicationServiceProviderIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mApplicationServiceProviderIdentity->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mApplicationServiceProviderIdentity->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ApplicationServiceProviderIdentity");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SponsoredConnectivityData_SPONSORINGACTION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(542);
					memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_AVP_CODE_SIZE);
					array->offset += DIA_AVP_CODE_SIZE;
					array->size++;
					array->byte[array->offset++] = 32;
					lengthOffset = array->offset; 
					array->offset += 3; 
					array->size += 3; 
					if( true == DiameterTLVUtil::isVenderSpecific(32))
					{ 
						INT32 venderId=10415;
						array->size+=4;
						lTempHtonlVar =  htonl(venderId);
						memcpy(array->byte+array->offset, &lTempHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
					array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
					} 
					if(!mSponsoringAction->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSponsoringAction->getAvpOffsetLen().first], mSponsoringAction->getAvpOffsetLen().second);
						array->offset += mSponsoringAction->getAvpOffsetLen().second;
						array->size += mSponsoringAction->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SponsoringAction");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mSponsoringAction->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SponsoringAction");
						throw lTssDiaMsgException;
					}
				}
				break;
			case SponsoredConnectivityData_GRANTEDSERVICEUNIT:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(431);
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
				if((this->getGrantedServiceUnit()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding GrantedServiceUnit");
					throw lTssDiaMsgException;
					}
				}
				break;
			case SponsoredConnectivityData_USEDSERVICEUNIT:
			{
				array->size+=4;
					lTempHtonlVar =  htonl(530);
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
				if((this->getUsedServiceUnit()->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)) {
					TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding UsedServiceUnit");
					throw lTssDiaMsgException;
					}
				}
				break;
			case SponsoredConnectivityData_PROXYINFO:
			{
				if( mProxyInfoGrpList->size() <= 0) {
					break;
				}

				mProxyInfoGrpIterator = this->getProxyInfoGrpList()->begin();
				while(mProxyInfoGrpIterator != mProxyInfoGrpList->end())
				{
					lengthOffset = 0;
					array->size+=4;
					lTempHtonlVar =  htonl(284);
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
					if(((*mProxyInfoGrpIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ProxyInfo");
						throw lTssDiaMsgException;
					}
					
					mProxyInfoGrpIterator++;
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


int SponsoredConnectivityData::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 531:
				{
					if( NULL == this->setSponsorIdentity())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SponsorIdentity");
						throw lTssDiaMsgException;
					}
					mSponsorIdentity->setAvpCode(531);
					mSponsorIdentity->setAvpVendorId(lVenderId);
					mSponsorIdentity->SetDataType((DiameterDataType)5);
					mSponsorIdentity->mspByteArray = mspByteArray;
					mSponsorIdentity->mAvpDecodedFlag = false;
					mSponsorIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 532:
				{
					if( NULL == this->setApplicationServiceProviderIdentity())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ApplicationServiceProviderIdentity");
						throw lTssDiaMsgException;
					}
					mApplicationServiceProviderIdentity->setAvpCode(532);
					mApplicationServiceProviderIdentity->setAvpVendorId(lVenderId);
					mApplicationServiceProviderIdentity->SetDataType((DiameterDataType)5);
					mApplicationServiceProviderIdentity->mspByteArray = mspByteArray;
					mApplicationServiceProviderIdentity->mAvpDecodedFlag = false;
					mApplicationServiceProviderIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 542:
				{
					if( NULL == this->setSponsoringAction())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SponsoringAction");
						throw lTssDiaMsgException;
					}
					mSponsoringAction->setAvpCode(542);
					mSponsoringAction->setAvpVendorId(lVenderId);
					mSponsoringAction->SetDataType((DiameterDataType)7);
					mSponsoringAction->mspByteArray = mspByteArray;
					mSponsoringAction->mAvpDecodedFlag = false;
					mSponsoringAction->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 431:
				{
						mMandatoryAvpSetVal [SponsoredConnectivityData_GRANTEDSERVICEUNIT] = 1;
					mTagsPresent[SponsoredConnectivityData_GRANTEDSERVICEUNIT] = 1;
						if( NULL == this->setGrantedServiceUnit()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding GrantedServiceUnit");
						throw lTssDiaMsgException;
						}
					mGrantedServiceUnitGrp->setAvpCode(431);
					mGrantedServiceUnitGrp->SetDataType((DiameterDataType)6);
					mGrantedServiceUnitGrp->mspByteArray = mspByteArray;
					mGrantedServiceUnitGrp->mAvpDecodedFlag = false;
					mGrantedServiceUnitGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mGrantedServiceUnitGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 530:
				{
						mMandatoryAvpSetVal [SponsoredConnectivityData_USEDSERVICEUNIT] = 1;
					mTagsPresent[SponsoredConnectivityData_USEDSERVICEUNIT] = 1;
						if( NULL == this->setUsedServiceUnit()){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding UsedServiceUnit");
						throw lTssDiaMsgException;
						}
					mUsedServiceUnitGrp->setAvpCode(530);
					mUsedServiceUnitGrp->SetDataType((DiameterDataType)6);
					mUsedServiceUnitGrp->mspByteArray = mspByteArray;
					mUsedServiceUnitGrp->mAvpDecodedFlag = false;
					mUsedServiceUnitGrp->setAvpOffsetLen(array->offset,lAvpDataLen);
					mBaseInterfaceList.push_back(mUsedServiceUnitGrp);
					array->offset+=lAvpDataLen;

				}
				break;
			case 284:
				{
						mMandatoryAvpSetVal [SponsoredConnectivityData_PROXYINFO] = 1;
					mTagsPresent[SponsoredConnectivityData_PROXYINFO] = 1;
					ProxyInfo *lProxyInfo = new ProxyInfo();
					if( lProxyInfo == NULL ){
					mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ProxyInfo");
						throw lTssDiaMsgException;
					}
					lProxyInfo->setAvpCode(284);
					lProxyInfo->SetDataType((DiameterDataType)6);
					lProxyInfo->mspByteArray = mspByteArray;
					lProxyInfo->mAvpDecodedFlag = false;
					lProxyInfo->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mProxyInfoGrpList == NULL)
						this->setProxyInfoGrpList();
					mProxyInfoGrpList->push_back(lProxyInfo);
					mBaseInterfaceList.push_back(lProxyInfo);
					
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


DiameterBaseInterface* SponsoredConnectivityData::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SponsoredConnectivityData")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 531:
			{
				if(mSponsorIdentity != NULL)
					return mSponsorIdentity->Find(array, avpCode);
				else
					return NULL;
			}
			case 532:
			{
				if(mApplicationServiceProviderIdentity != NULL)
					return mApplicationServiceProviderIdentity->Find(array, avpCode);
				else
					return NULL;
			}
			case 542:
			{
				if(mSponsoringAction != NULL)
					return mSponsoringAction->Find(array, avpCode);
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


BOOLEAN SponsoredConnectivityData::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SponsoredConnectivityData")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 531:
			{
				if(mSponsorIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mSponsorIdentity->Find(this->mspByteArray.get(), avpCode);
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
			case 532:
			{
				if(mApplicationServiceProviderIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mApplicationServiceProviderIdentity->Find(this->mspByteArray.get(), avpCode);
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
			case 542:
			{
				if(mSponsoringAction != NULL)
				{
					DiameterBaseInterface* inf =  mSponsoringAction->Find(this->mspByteArray.get(), avpCode);
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
			case 431:
			{
				if(mGrantedServiceUnitGrp != NULL)
				{
						pBaseInterface.push_back(mGrantedServiceUnitGrp);
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
			case 530:
			{
				if(mUsedServiceUnitGrp != NULL)
				{
						pBaseInterface.push_back(mUsedServiceUnitGrp);
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
			case 284:
			{
				if(mProxyInfoGrpList != NULL)
				{
					for(auto itr = mProxyInfoGrpList->begin(); itr != mProxyInfoGrpList->end(); ++itr)
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
std::shared_ptr<byteArray> SponsoredConnectivityData::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN SponsoredConnectivityData::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SponsoredConnectivityData")     ;
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
			case 531:
			{
				if(mSponsorIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mSponsorIdentity->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 532:
			{
				if(mApplicationServiceProviderIdentity != NULL)
				{
					DiameterBaseInterface* inf =  mApplicationServiceProviderIdentity->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 542:
			{
				if(mSponsoringAction != NULL)
				{
					DiameterBaseInterface* inf =  mSponsoringAction->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 431:
			{
				if(mGrantedServiceUnitGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mGrantedServiceUnitGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mGrantedServiceUnitGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 530:
			{
				if(mUsedServiceUnitGrp != NULL)
				{
					if(key == size)
					{
						pBaseInterface.push_back(mUsedServiceUnitGrp);
					}
				if(deepInspect)
				{
					for(auto itr = mBaseInterfaceList.begin(); itr != mBaseInterfaceList.end(); ++itr)
					{
						mUsedServiceUnitGrp->FindAll(this->mspByteArray.get(), avpCodeMap, size, (key+1),  pBaseInterface,deepInspect);
					}
				}
				}
				break;
			}
			case 284:
			{
				if(mProxyInfoGrpList != NULL)
				{
				if(key == size)
				{
					for(auto itr = mProxyInfoGrpList->begin(); itr != mProxyInfoGrpList->end(); ++itr)
					{
						pBaseInterface.push_back(*itr);
					}

				}
					if(deepInspect)
					{
					for(auto itr = mProxyInfoGrpList->begin(); itr != mProxyInfoGrpList->end(); ++itr)
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


INT32 SponsoredConnectivityData::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 SponsoredConnectivityData::getAvpCode()
{
	return mAvpCode;
}
INT32 SponsoredConnectivityData::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 SponsoredConnectivityData::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 SponsoredConnectivityData::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> SponsoredConnectivityData::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void SponsoredConnectivityData::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case SponsoredConnectivityData_SPONSORIDENTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "531" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SponsorIdentity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getSponsorIdentity()->Display(tab+1);
			}
				break;
			case SponsoredConnectivityData_APPLICATIONSERVICEPROVIDERIDENTITY:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "532" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ApplicationServiceProviderIdentity" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getApplicationServiceProviderIdentity()->Display(tab+1);
			}
				break;
			case SponsoredConnectivityData_SPONSORINGACTION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "542" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SponsoringAction" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(32)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(32)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(32)==true)?"Protected":""));
				this->getSponsoringAction()->Display(tab+1);
			}
				break;
			case SponsoredConnectivityData_GRANTEDSERVICEUNIT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "431" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "GrantedServiceUnit" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getGrantedServiceUnit()->Display(tab+1);
			}
				break;
			case SponsoredConnectivityData_USEDSERVICEUNIT:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "530" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "UsedServiceUnit" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(96)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(96)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(96)==true)?"Protected":""));
				this->getUsedServiceUnit()->Display(tab+1);
			}
				break;
			case SponsoredConnectivityData_PROXYINFO:
			{
				if( mProxyInfoGrpList->size() <= 0) {
					break;
				}

				mProxyInfoGrpIterator = this->getProxyInfoGrpList()->begin();
				while(mProxyInfoGrpIterator != this->getProxyInfoGrpList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "284" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "GROUPED" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ProxyInfo" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(64)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(64)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(64)==true)?"Protected":""));
					(*mProxyInfoGrpIterator)->Display(tab+1);
					mProxyInfoGrpIterator++;

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


BOOLEAN SponsoredConnectivityData::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<6> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case SponsoredConnectivityData_SPONSORIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 531");
				}
				else
					sprintf(lMissingAvpInfo, "%s,531", lMissingAvpInfo);
			}
				break;
			case SponsoredConnectivityData_APPLICATIONSERVICEPROVIDERIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 532");
				}
				else
					sprintf(lMissingAvpInfo, "%s,532", lMissingAvpInfo);
			}
				break;
			case SponsoredConnectivityData_SPONSORINGACTION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 542");
				}
				else
					sprintf(lMissingAvpInfo, "%s,542", lMissingAvpInfo);
			}
				break;
			case SponsoredConnectivityData_GRANTEDSERVICEUNIT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 431");
				}
				else
					sprintf(lMissingAvpInfo, "%s,431", lMissingAvpInfo);
			}
				break;
			case SponsoredConnectivityData_USEDSERVICEUNIT:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 530");
				}
				else
					sprintf(lMissingAvpInfo, "%s,530", lMissingAvpInfo);
			}
				break;
			case SponsoredConnectivityData_PROXYINFO:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 284");
				}
				else
					sprintf(lMissingAvpInfo, "%s,284", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
