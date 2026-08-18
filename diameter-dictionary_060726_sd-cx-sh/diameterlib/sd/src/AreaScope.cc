#include "sd/include/AreaScope.h"

using namespace SD;
BOOLEAN AreaScope::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

AreaScope::AreaScope()
{
	mCellGlobalIdentityList = NULL;
	mETUTRANCellGlobalIdentityList = NULL;
	mRoutingAreaIdentityList = NULL;
	mLocationAreaIdentityList = NULL;
	mTrackingAreaIdentityList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<5>(string("00000"));
	mMandatoryAvpSetVal.reset();
}

AreaScope::~AreaScope()
{
	if(mCellGlobalIdentityList != NULL){
		mCellGlobalIdentityIterator = mCellGlobalIdentityList->begin();
		while(mCellGlobalIdentityIterator != mCellGlobalIdentityList->end()){
			delete (*mCellGlobalIdentityIterator);
			mCellGlobalIdentityIterator++;
		}
		delete mCellGlobalIdentityList;
	}
	if(mETUTRANCellGlobalIdentityList != NULL){
		mETUTRANCellGlobalIdentityIterator = mETUTRANCellGlobalIdentityList->begin();
		while(mETUTRANCellGlobalIdentityIterator != mETUTRANCellGlobalIdentityList->end()){
			delete (*mETUTRANCellGlobalIdentityIterator);
			mETUTRANCellGlobalIdentityIterator++;
		}
		delete mETUTRANCellGlobalIdentityList;
	}
	if(mRoutingAreaIdentityList != NULL){
		mRoutingAreaIdentityIterator = mRoutingAreaIdentityList->begin();
		while(mRoutingAreaIdentityIterator != mRoutingAreaIdentityList->end()){
			delete (*mRoutingAreaIdentityIterator);
			mRoutingAreaIdentityIterator++;
		}
		delete mRoutingAreaIdentityList;
	}
	if(mLocationAreaIdentityList != NULL){
		mLocationAreaIdentityIterator = mLocationAreaIdentityList->begin();
		while(mLocationAreaIdentityIterator != mLocationAreaIdentityList->end()){
			delete (*mLocationAreaIdentityIterator);
			mLocationAreaIdentityIterator++;
		}
		delete mLocationAreaIdentityList;
	}
	if(mTrackingAreaIdentityList != NULL){
		mTrackingAreaIdentityIterator = mTrackingAreaIdentityList->begin();
		while(mTrackingAreaIdentityIterator != mTrackingAreaIdentityList->end()){
			delete (*mTrackingAreaIdentityIterator);
			mTrackingAreaIdentityIterator++;
		}
		delete mTrackingAreaIdentityList;
	}
}

list<OctetString*>* AreaScope::getCellGlobalIdentityList()
{
	if(mCellGlobalIdentityList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CellGlobalIdentity is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mCellGlobalIdentityList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "CellGlobalIdentity is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CellGlobalIdentity")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mCellGlobalIdentityList;
}

list<OctetString*>* AreaScope::setCellGlobalIdentityList() {
	mTagsPresent[AreaScope_CELLGLOBALIDENTITY] = 1;
	if(mCellGlobalIdentityList == NULL)
		mCellGlobalIdentityList = new list<OctetString*>;
	mCellGlobalIdentityList->clear();
	return mCellGlobalIdentityList;
}

void AreaScope::resetCellGlobalIdentityList(){
	mTagsPresent[AreaScope_CELLGLOBALIDENTITY] = 0;
	if(mCellGlobalIdentityList != NULL)
		delete mCellGlobalIdentityList;
}

list<OctetString*>* AreaScope::getETUTRANCellGlobalIdentityList()
{
	if(mETUTRANCellGlobalIdentityList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ETUTRANCellGlobalIdentity is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mETUTRANCellGlobalIdentityList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ETUTRANCellGlobalIdentity is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ETUTRANCellGlobalIdentity")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mETUTRANCellGlobalIdentityList;
}

list<OctetString*>* AreaScope::setETUTRANCellGlobalIdentityList() {
	mTagsPresent[AreaScope_ETUTRANCELLGLOBALIDENTITY] = 1;
	if(mETUTRANCellGlobalIdentityList == NULL)
		mETUTRANCellGlobalIdentityList = new list<OctetString*>;
	mETUTRANCellGlobalIdentityList->clear();
	return mETUTRANCellGlobalIdentityList;
}

void AreaScope::resetETUTRANCellGlobalIdentityList(){
	mTagsPresent[AreaScope_ETUTRANCELLGLOBALIDENTITY] = 0;
	if(mETUTRANCellGlobalIdentityList != NULL)
		delete mETUTRANCellGlobalIdentityList;
}

list<OctetString*>* AreaScope::getRoutingAreaIdentityList()
{
	if(mRoutingAreaIdentityList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RoutingAreaIdentity is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mRoutingAreaIdentityList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "RoutingAreaIdentity is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RoutingAreaIdentity")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mRoutingAreaIdentityList;
}

list<OctetString*>* AreaScope::setRoutingAreaIdentityList() {
	mTagsPresent[AreaScope_ROUTINGAREAIDENTITY] = 1;
	if(mRoutingAreaIdentityList == NULL)
		mRoutingAreaIdentityList = new list<OctetString*>;
	mRoutingAreaIdentityList->clear();
	return mRoutingAreaIdentityList;
}

void AreaScope::resetRoutingAreaIdentityList(){
	mTagsPresent[AreaScope_ROUTINGAREAIDENTITY] = 0;
	if(mRoutingAreaIdentityList != NULL)
		delete mRoutingAreaIdentityList;
}

list<OctetString*>* AreaScope::getLocationAreaIdentityList()
{
	if(mLocationAreaIdentityList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LocationAreaIdentity is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mLocationAreaIdentityList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "LocationAreaIdentity is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LocationAreaIdentity")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mLocationAreaIdentityList;
}

list<OctetString*>* AreaScope::setLocationAreaIdentityList() {
	mTagsPresent[AreaScope_LOCATIONAREAIDENTITY] = 1;
	if(mLocationAreaIdentityList == NULL)
		mLocationAreaIdentityList = new list<OctetString*>;
	mLocationAreaIdentityList->clear();
	return mLocationAreaIdentityList;
}

void AreaScope::resetLocationAreaIdentityList(){
	mTagsPresent[AreaScope_LOCATIONAREAIDENTITY] = 0;
	if(mLocationAreaIdentityList != NULL)
		delete mLocationAreaIdentityList;
}

list<OctetString*>* AreaScope::getTrackingAreaIdentityList()
{
	if(mTrackingAreaIdentityList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TrackingAreaIdentity is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mTrackingAreaIdentityList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "TrackingAreaIdentity is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TrackingAreaIdentity")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mTrackingAreaIdentityList;
}

list<OctetString*>* AreaScope::setTrackingAreaIdentityList() {
	mTagsPresent[AreaScope_TRACKINGAREAIDENTITY] = 1;
	if(mTrackingAreaIdentityList == NULL)
		mTrackingAreaIdentityList = new list<OctetString*>;
	mTrackingAreaIdentityList->clear();
	return mTrackingAreaIdentityList;
}

void AreaScope::resetTrackingAreaIdentityList(){
	mTagsPresent[AreaScope_TRACKINGAREAIDENTITY] = 0;
	if(mTrackingAreaIdentityList != NULL)
		delete mTrackingAreaIdentityList;
}



int AreaScope::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case AreaScope_CELLGLOBALIDENTITY:
			{
					if( mCellGlobalIdentityList->size() <= 0) {
						break;
					}

					mCellGlobalIdentityIterator = this->getCellGlobalIdentityList()->begin();
					while(mCellGlobalIdentityIterator != mCellGlobalIdentityList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1604);
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
					if(!(*mCellGlobalIdentityIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mCellGlobalIdentityIterator)->getAvpOffsetLen().first], (*mCellGlobalIdentityIterator)->getAvpOffsetLen().second);
						array->offset += (*mCellGlobalIdentityIterator)->getAvpOffsetLen().second;
						array->size += (*mCellGlobalIdentityIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mCellGlobalIdentityIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mCellGlobalIdentityIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CellGlobalIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mCellGlobalIdentityIterator++;
						continue;
					}
						if(((*mCellGlobalIdentityIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mCellGlobalIdentityIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding CellGlobalIdentity");
							throw lTssDiaMsgException;
						}
						mCellGlobalIdentityIterator++;
				}
				}
				break;
			case AreaScope_ETUTRANCELLGLOBALIDENTITY:
			{
					if( mETUTRANCellGlobalIdentityList->size() <= 0) {
						break;
					}

					mETUTRANCellGlobalIdentityIterator = this->getETUTRANCellGlobalIdentityList()->begin();
					while(mETUTRANCellGlobalIdentityIterator != mETUTRANCellGlobalIdentityList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1605);
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
					if(!(*mETUTRANCellGlobalIdentityIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mETUTRANCellGlobalIdentityIterator)->getAvpOffsetLen().first], (*mETUTRANCellGlobalIdentityIterator)->getAvpOffsetLen().second);
						array->offset += (*mETUTRANCellGlobalIdentityIterator)->getAvpOffsetLen().second;
						array->size += (*mETUTRANCellGlobalIdentityIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mETUTRANCellGlobalIdentityIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mETUTRANCellGlobalIdentityIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ETUTRANCellGlobalIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mETUTRANCellGlobalIdentityIterator++;
						continue;
					}
						if(((*mETUTRANCellGlobalIdentityIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mETUTRANCellGlobalIdentityIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ETUTRANCellGlobalIdentity");
							throw lTssDiaMsgException;
						}
						mETUTRANCellGlobalIdentityIterator++;
				}
				}
				break;
			case AreaScope_ROUTINGAREAIDENTITY:
			{
					if( mRoutingAreaIdentityList->size() <= 0) {
						break;
					}

					mRoutingAreaIdentityIterator = this->getRoutingAreaIdentityList()->begin();
					while(mRoutingAreaIdentityIterator != mRoutingAreaIdentityList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1606);
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
					if(!(*mRoutingAreaIdentityIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mRoutingAreaIdentityIterator)->getAvpOffsetLen().first], (*mRoutingAreaIdentityIterator)->getAvpOffsetLen().second);
						array->offset += (*mRoutingAreaIdentityIterator)->getAvpOffsetLen().second;
						array->size += (*mRoutingAreaIdentityIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mRoutingAreaIdentityIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mRoutingAreaIdentityIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RoutingAreaIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mRoutingAreaIdentityIterator++;
						continue;
					}
						if(((*mRoutingAreaIdentityIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mRoutingAreaIdentityIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding RoutingAreaIdentity");
							throw lTssDiaMsgException;
						}
						mRoutingAreaIdentityIterator++;
				}
				}
				break;
			case AreaScope_LOCATIONAREAIDENTITY:
			{
					if( mLocationAreaIdentityList->size() <= 0) {
						break;
					}

					mLocationAreaIdentityIterator = this->getLocationAreaIdentityList()->begin();
					while(mLocationAreaIdentityIterator != mLocationAreaIdentityList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1607);
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
					if(!(*mLocationAreaIdentityIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mLocationAreaIdentityIterator)->getAvpOffsetLen().first], (*mLocationAreaIdentityIterator)->getAvpOffsetLen().second);
						array->offset += (*mLocationAreaIdentityIterator)->getAvpOffsetLen().second;
						array->size += (*mLocationAreaIdentityIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mLocationAreaIdentityIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mLocationAreaIdentityIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LocationAreaIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mLocationAreaIdentityIterator++;
						continue;
					}
						if(((*mLocationAreaIdentityIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mLocationAreaIdentityIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding LocationAreaIdentity");
							throw lTssDiaMsgException;
						}
						mLocationAreaIdentityIterator++;
				}
				}
				break;
			case AreaScope_TRACKINGAREAIDENTITY:
			{
					if( mTrackingAreaIdentityList->size() <= 0) {
						break;
					}

					mTrackingAreaIdentityIterator = this->getTrackingAreaIdentityList()->begin();
					while(mTrackingAreaIdentityIterator != mTrackingAreaIdentityList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(1603);
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
					if(!(*mTrackingAreaIdentityIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mTrackingAreaIdentityIterator)->getAvpOffsetLen().first], (*mTrackingAreaIdentityIterator)->getAvpOffsetLen().second);
						array->offset += (*mTrackingAreaIdentityIterator)->getAvpOffsetLen().second;
						array->size += (*mTrackingAreaIdentityIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mTrackingAreaIdentityIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mTrackingAreaIdentityIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TrackingAreaIdentity");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mTrackingAreaIdentityIterator++;
						continue;
					}
						if(((*mTrackingAreaIdentityIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mTrackingAreaIdentityIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding TrackingAreaIdentity");
							throw lTssDiaMsgException;
						}
						mTrackingAreaIdentityIterator++;
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


int AreaScope::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 1604:
				{
					mTagsPresent[AreaScope_CELLGLOBALIDENTITY] = 1;
					OctetString *lCellGlobalIdentity = new OctetString();
					if( lCellGlobalIdentity == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding CellGlobalIdentity");
						throw lTssDiaMsgException;
					}
					lCellGlobalIdentity->setAvpCode(1604);
					lCellGlobalIdentity->setAvpVendorId(lVenderId);
					lCellGlobalIdentity->SetDataType((DiameterDataType)5);
					lCellGlobalIdentity->mspByteArray = mspByteArray;
					lCellGlobalIdentity->mAvpDecodedFlag = false;
					lCellGlobalIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mCellGlobalIdentityList == NULL)
						this->setCellGlobalIdentityList();
					mCellGlobalIdentityList->push_back(lCellGlobalIdentity);
					
				}
				break;
			case 1605:
				{
					mTagsPresent[AreaScope_ETUTRANCELLGLOBALIDENTITY] = 1;
					OctetString *lETUTRANCellGlobalIdentity = new OctetString();
					if( lETUTRANCellGlobalIdentity == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ETUTRANCellGlobalIdentity");
						throw lTssDiaMsgException;
					}
					lETUTRANCellGlobalIdentity->setAvpCode(1605);
					lETUTRANCellGlobalIdentity->setAvpVendorId(lVenderId);
					lETUTRANCellGlobalIdentity->SetDataType((DiameterDataType)5);
					lETUTRANCellGlobalIdentity->mspByteArray = mspByteArray;
					lETUTRANCellGlobalIdentity->mAvpDecodedFlag = false;
					lETUTRANCellGlobalIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mETUTRANCellGlobalIdentityList == NULL)
						this->setETUTRANCellGlobalIdentityList();
					mETUTRANCellGlobalIdentityList->push_back(lETUTRANCellGlobalIdentity);
					
				}
				break;
			case 1606:
				{
					mTagsPresent[AreaScope_ROUTINGAREAIDENTITY] = 1;
					OctetString *lRoutingAreaIdentity = new OctetString();
					if( lRoutingAreaIdentity == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RoutingAreaIdentity");
						throw lTssDiaMsgException;
					}
					lRoutingAreaIdentity->setAvpCode(1606);
					lRoutingAreaIdentity->setAvpVendorId(lVenderId);
					lRoutingAreaIdentity->SetDataType((DiameterDataType)5);
					lRoutingAreaIdentity->mspByteArray = mspByteArray;
					lRoutingAreaIdentity->mAvpDecodedFlag = false;
					lRoutingAreaIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mRoutingAreaIdentityList == NULL)
						this->setRoutingAreaIdentityList();
					mRoutingAreaIdentityList->push_back(lRoutingAreaIdentity);
					
				}
				break;
			case 1607:
				{
					mTagsPresent[AreaScope_LOCATIONAREAIDENTITY] = 1;
					OctetString *lLocationAreaIdentity = new OctetString();
					if( lLocationAreaIdentity == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding LocationAreaIdentity");
						throw lTssDiaMsgException;
					}
					lLocationAreaIdentity->setAvpCode(1607);
					lLocationAreaIdentity->setAvpVendorId(lVenderId);
					lLocationAreaIdentity->SetDataType((DiameterDataType)5);
					lLocationAreaIdentity->mspByteArray = mspByteArray;
					lLocationAreaIdentity->mAvpDecodedFlag = false;
					lLocationAreaIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mLocationAreaIdentityList == NULL)
						this->setLocationAreaIdentityList();
					mLocationAreaIdentityList->push_back(lLocationAreaIdentity);
					
				}
				break;
			case 1603:
				{
					mTagsPresent[AreaScope_TRACKINGAREAIDENTITY] = 1;
					OctetString *lTrackingAreaIdentity = new OctetString();
					if( lTrackingAreaIdentity == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding TrackingAreaIdentity");
						throw lTssDiaMsgException;
					}
					lTrackingAreaIdentity->setAvpCode(1603);
					lTrackingAreaIdentity->setAvpVendorId(lVenderId);
					lTrackingAreaIdentity->SetDataType((DiameterDataType)5);
					lTrackingAreaIdentity->mspByteArray = mspByteArray;
					lTrackingAreaIdentity->mAvpDecodedFlag = false;
					lTrackingAreaIdentity->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mTrackingAreaIdentityList == NULL)
						this->setTrackingAreaIdentityList();
					mTrackingAreaIdentityList->push_back(lTrackingAreaIdentity);
					
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


DiameterBaseInterface* AreaScope::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AreaScope")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1604:
			{
				if(mCellGlobalIdentityList != NULL && mCellGlobalIdentityList->size() > 0)
					return (mCellGlobalIdentityList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 1605:
			{
				if(mETUTRANCellGlobalIdentityList != NULL && mETUTRANCellGlobalIdentityList->size() > 0)
					return (mETUTRANCellGlobalIdentityList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 1606:
			{
				if(mRoutingAreaIdentityList != NULL && mRoutingAreaIdentityList->size() > 0)
					return (mRoutingAreaIdentityList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 1607:
			{
				if(mLocationAreaIdentityList != NULL && mLocationAreaIdentityList->size() > 0)
					return (mLocationAreaIdentityList->back())->Find(array, avpCode);
				else
					return NULL;
			}
			case 1603:
			{
				if(mTrackingAreaIdentityList != NULL && mTrackingAreaIdentityList->size() > 0)
					return (mTrackingAreaIdentityList->back())->Find(array, avpCode);
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


BOOLEAN AreaScope::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AreaScope")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 1604:
			{
				if(mCellGlobalIdentityList != NULL)
				{
					for(auto itr = mCellGlobalIdentityList->begin(); itr != mCellGlobalIdentityList->end(); ++itr)
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
			case 1605:
			{
				if(mETUTRANCellGlobalIdentityList != NULL)
				{
					for(auto itr = mETUTRANCellGlobalIdentityList->begin(); itr != mETUTRANCellGlobalIdentityList->end(); ++itr)
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
			case 1606:
			{
				if(mRoutingAreaIdentityList != NULL)
				{
					for(auto itr = mRoutingAreaIdentityList->begin(); itr != mRoutingAreaIdentityList->end(); ++itr)
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
			case 1607:
			{
				if(mLocationAreaIdentityList != NULL)
				{
					for(auto itr = mLocationAreaIdentityList->begin(); itr != mLocationAreaIdentityList->end(); ++itr)
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
			case 1603:
			{
				if(mTrackingAreaIdentityList != NULL)
				{
					for(auto itr = mTrackingAreaIdentityList->begin(); itr != mTrackingAreaIdentityList->end(); ++itr)
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
std::shared_ptr<byteArray> AreaScope::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN AreaScope::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AreaScope")     ;
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
			case 1604:
			{
				if(mCellGlobalIdentityList != NULL)
				{
					for(auto itr = mCellGlobalIdentityList->begin(); itr != mCellGlobalIdentityList->end(); ++itr)
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
			case 1605:
			{
				if(mETUTRANCellGlobalIdentityList != NULL)
				{
					for(auto itr = mETUTRANCellGlobalIdentityList->begin(); itr != mETUTRANCellGlobalIdentityList->end(); ++itr)
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
			case 1606:
			{
				if(mRoutingAreaIdentityList != NULL)
				{
					for(auto itr = mRoutingAreaIdentityList->begin(); itr != mRoutingAreaIdentityList->end(); ++itr)
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
			case 1607:
			{
				if(mLocationAreaIdentityList != NULL)
				{
					for(auto itr = mLocationAreaIdentityList->begin(); itr != mLocationAreaIdentityList->end(); ++itr)
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
			case 1603:
			{
				if(mTrackingAreaIdentityList != NULL)
				{
					for(auto itr = mTrackingAreaIdentityList->begin(); itr != mTrackingAreaIdentityList->end(); ++itr)
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


INT32 AreaScope::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 AreaScope::getAvpCode()
{
	return mAvpCode;
}
INT32 AreaScope::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 AreaScope::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 AreaScope::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> AreaScope::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void AreaScope::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case AreaScope_CELLGLOBALIDENTITY:
			{
				if( mCellGlobalIdentityList->size() <= 0) {
					break;
				}

				mCellGlobalIdentityIterator = this->getCellGlobalIdentityList()->begin();
				while(mCellGlobalIdentityIterator != this->getCellGlobalIdentityList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1604" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "CellGlobalIdentity" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mCellGlobalIdentityIterator)->Display(tab+1);
					mCellGlobalIdentityIterator++;

				};

			}
				break;
			case AreaScope_ETUTRANCELLGLOBALIDENTITY:
			{
				if( mETUTRANCellGlobalIdentityList->size() <= 0) {
					break;
				}

				mETUTRANCellGlobalIdentityIterator = this->getETUTRANCellGlobalIdentityList()->begin();
				while(mETUTRANCellGlobalIdentityIterator != this->getETUTRANCellGlobalIdentityList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1605" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ETUTRANCellGlobalIdentity" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mETUTRANCellGlobalIdentityIterator)->Display(tab+1);
					mETUTRANCellGlobalIdentityIterator++;

				};

			}
				break;
			case AreaScope_ROUTINGAREAIDENTITY:
			{
				if( mRoutingAreaIdentityList->size() <= 0) {
					break;
				}

				mRoutingAreaIdentityIterator = this->getRoutingAreaIdentityList()->begin();
				while(mRoutingAreaIdentityIterator != this->getRoutingAreaIdentityList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1606" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "RoutingAreaIdentity" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mRoutingAreaIdentityIterator)->Display(tab+1);
					mRoutingAreaIdentityIterator++;

				};

			}
				break;
			case AreaScope_LOCATIONAREAIDENTITY:
			{
				if( mLocationAreaIdentityList->size() <= 0) {
					break;
				}

				mLocationAreaIdentityIterator = this->getLocationAreaIdentityList()->begin();
				while(mLocationAreaIdentityIterator != this->getLocationAreaIdentityList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1607" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "LocationAreaIdentity" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mLocationAreaIdentityIterator)->Display(tab+1);
					mLocationAreaIdentityIterator++;

				};

			}
				break;
			case AreaScope_TRACKINGAREAIDENTITY:
			{
				if( mTrackingAreaIdentityList->size() <= 0) {
					break;
				}

				mTrackingAreaIdentityIterator = this->getTrackingAreaIdentityList()->begin();
				while(mTrackingAreaIdentityIterator != this->getTrackingAreaIdentityList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "1603" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "TrackingAreaIdentity" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mTrackingAreaIdentityIterator)->Display(tab+1);
					mTrackingAreaIdentityIterator++;

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


BOOLEAN AreaScope::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<5> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case AreaScope_CELLGLOBALIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1604");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1604", lMissingAvpInfo);
			}
				break;
			case AreaScope_ETUTRANCELLGLOBALIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1605");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1605", lMissingAvpInfo);
			}
				break;
			case AreaScope_ROUTINGAREAIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1606");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1606", lMissingAvpInfo);
			}
				break;
			case AreaScope_LOCATIONAREAIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1607");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1607", lMissingAvpInfo);
			}
				break;
			case AreaScope_TRACKINGAREAIDENTITY:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 1603");
				}
				else
					sprintf(lMissingAvpInfo, "%s,1603", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
