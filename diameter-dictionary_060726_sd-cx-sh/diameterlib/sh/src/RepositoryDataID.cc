#include "sh/include/RepositoryDataID.h"

using namespace SH;
BOOLEAN RepositoryDataID::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

RepositoryDataID::RepositoryDataID()
{
	mServiceIndication = NULL;
	mSequenceNumber = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("01"));
	mMandatoryAvpSetVal.reset();
}

RepositoryDataID::~RepositoryDataID()
{
	if(mServiceIndication != NULL)
		delete mServiceIndication;
	if(mSequenceNumber != NULL)
		delete mSequenceNumber;
}

OctetString* RepositoryDataID::setServiceIndication(){
	mMandatoryAvpSetVal [RepositoryDataID_SERVICEINDICATION] = 1;
	if(mServiceIndication == NULL)
	{
		mServiceIndication = new OctetString();
		mTagsPresent[RepositoryDataID_SERVICEINDICATION] = 1;
		return mServiceIndication;
	}
	return mServiceIndication;
}

void RepositoryDataID::resetServiceIndication(){
	mTagsPresent[RepositoryDataID_SERVICEINDICATION] = 0;
	if(mServiceIndication != NULL)
	{
		delete mServiceIndication; 
		mServiceIndication = NULL;
	}
}

Unsigned32* RepositoryDataID::setSequenceNumber(){
	if(mSequenceNumber == NULL)
	{
		mSequenceNumber = new Unsigned32();
		mTagsPresent[RepositoryDataID_SEQUENCENUMBER] = 1;
		return mSequenceNumber;
	}
	return mSequenceNumber;
}

void RepositoryDataID::resetSequenceNumber(){
	mTagsPresent[RepositoryDataID_SEQUENCENUMBER] = 0;
	if(mSequenceNumber != NULL)
	{
		delete mSequenceNumber; 
		mSequenceNumber = NULL;
	}
}

OctetString* RepositoryDataID::getServiceIndication(){
	if(NULL == mServiceIndication) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceIndication is Null");
		throw lTssDiaMsgException;
	}
	if(!mServiceIndication->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mServiceIndication->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "ServiceIndication is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mServiceIndication->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mServiceIndication->Decode(mspByteArray.get(), mServiceIndication->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceIndication")     ;
			throw lTssDiaMsgException;
		}
		mServiceIndication->mAvpDecodedFlag = true;
	}
	return mServiceIndication;
}

Unsigned32* RepositoryDataID::getSequenceNumber(){
	if(NULL == mSequenceNumber) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SequenceNumber is Null");
		throw lTssDiaMsgException;
	}
	if(!mSequenceNumber->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mSequenceNumber->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "SequenceNumber is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mSequenceNumber->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mSequenceNumber->Decode(mspByteArray.get(), mSequenceNumber->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SequenceNumber")     ;
			throw lTssDiaMsgException;
		}
		mSequenceNumber->mAvpDecodedFlag = true;
	}
	return mSequenceNumber;
}



int RepositoryDataID::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case RepositoryDataID_SERVICEINDICATION:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(704);
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
					if(!mServiceIndication->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mServiceIndication->getAvpOffsetLen().first], mServiceIndication->getAvpOffsetLen().second);
						array->offset += mServiceIndication->getAvpOffsetLen().second;
						array->size += mServiceIndication->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mServiceIndication->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mServiceIndication->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceIndication");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mServiceIndication->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mServiceIndication->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding ServiceIndication");
						throw lTssDiaMsgException;
					}
				}
				break;
			case RepositoryDataID_SEQUENCENUMBER:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(716);
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
					if(!mSequenceNumber->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mSequenceNumber->getAvpOffsetLen().first], mSequenceNumber->getAvpOffsetLen().second);
						array->offset += mSequenceNumber->getAvpOffsetLen().second;
						array->size += mSequenceNumber->getAvpOffsetLen().second;
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SequenceNumber");
							throw lTssDiaMsgException;
						}
						continue;
					}
					if((mSequenceNumber->Encode(array) < 0) || 
						(DiameterTLVUtil::avp_length_encode(lengthOffset, array) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding SequenceNumber");
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


int RepositoryDataID::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 704:
				{
						mMandatoryAvpSetVal [RepositoryDataID_SERVICEINDICATION] = 1;
					if( NULL == this->setServiceIndication())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding ServiceIndication");
						throw lTssDiaMsgException;
					}
					mServiceIndication->setAvpCode(704);
					mServiceIndication->setAvpVendorId(lVenderId);
					mServiceIndication->SetDataType((DiameterDataType)5);
					mServiceIndication->mspByteArray = mspByteArray;
					mServiceIndication->mAvpDecodedFlag = false;
					mServiceIndication->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 716:
				{
					if( NULL == this->setSequenceNumber())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding SequenceNumber");
						throw lTssDiaMsgException;
					}
					mSequenceNumber->setAvpCode(716);
					mSequenceNumber->setAvpVendorId(lVenderId);
					mSequenceNumber->SetDataType((DiameterDataType)3);
					mSequenceNumber->mspByteArray = mspByteArray;
					mSequenceNumber->mAvpDecodedFlag = false;
					mSequenceNumber->setAvpOffsetLen(array->offset,lAvpDataLen);
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


DiameterBaseInterface* RepositoryDataID::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RepositoryDataID")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 704:
			{
				if(mServiceIndication != NULL)
					return mServiceIndication->Find(array, avpCode);
				else
					return NULL;
			}
			case 716:
			{
				if(mSequenceNumber != NULL)
					return mSequenceNumber->Find(array, avpCode);
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


BOOLEAN RepositoryDataID::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RepositoryDataID")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 704:
			{
				if(mServiceIndication != NULL)
				{
					DiameterBaseInterface* inf =  mServiceIndication->Find(this->mspByteArray.get(), avpCode);
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
			case 716:
			{
				if(mSequenceNumber != NULL)
				{
					DiameterBaseInterface* inf =  mSequenceNumber->Find(this->mspByteArray.get(), avpCode);
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
std::shared_ptr<byteArray> RepositoryDataID::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN RepositoryDataID::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding RepositoryDataID")     ;
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
			case 704:
			{
				if(mServiceIndication != NULL)
				{
					DiameterBaseInterface* inf =  mServiceIndication->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 716:
			{
				if(mSequenceNumber != NULL)
				{
					DiameterBaseInterface* inf =  mSequenceNumber->Find(this->mspByteArray.get(), avpCode);
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


INT32 RepositoryDataID::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 RepositoryDataID::getAvpCode()
{
	return mAvpCode;
}
INT32 RepositoryDataID::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 RepositoryDataID::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 RepositoryDataID::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> RepositoryDataID::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void RepositoryDataID::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case RepositoryDataID_SERVICEINDICATION:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "704" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "ServiceIndication" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(192)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(192)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(192)==true)?"Protected":""));
				this->getServiceIndication()->Display(tab+1);
			}
				break;
			case RepositoryDataID_SEQUENCENUMBER:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "716" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "SequenceNumber" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getSequenceNumber()->Display(tab+1);
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


BOOLEAN RepositoryDataID::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case RepositoryDataID_SERVICEINDICATION:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 704");
				}
				else
					sprintf(lMissingAvpInfo, "%s,704", lMissingAvpInfo);
			}
				break;
			case RepositoryDataID_SEQUENCENUMBER:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 716");
				}
				else
					sprintf(lMissingAvpInfo, "%s,716", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
