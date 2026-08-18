#include "cx/include/FailedPCSCF.h"

using namespace CX;
BOOLEAN FailedPCSCF::isPresent(int tag){
	return (mTagsPresent[tag])?true:false;
}

FailedPCSCF::FailedPCSCF()
{
	mPCSCFFQDN = NULL;
	mPCSCFIPAddressList = NULL;
	mTagsPresent.reset();
	mMandatoryAvpCheckVal= bitset<2>(string("00"));
	mMandatoryAvpSetVal.reset();
}

FailedPCSCF::~FailedPCSCF()
{
	if(mPCSCFFQDN != NULL)
		delete mPCSCFFQDN;
	if(mPCSCFIPAddressList != NULL){
		mPCSCFIPAddressIterator = mPCSCFIPAddressList->begin();
		while(mPCSCFIPAddressIterator != mPCSCFIPAddressList->end()){
			delete (*mPCSCFIPAddressIterator);
			mPCSCFIPAddressIterator++;
		}
		delete mPCSCFIPAddressList;
	}
}

OctetString* FailedPCSCF::setPCSCFFQDN(){
	if(mPCSCFFQDN == NULL)
	{
		mPCSCFFQDN = new OctetString();
		mTagsPresent[FailedPCSCF_PCSCFFQDN] = 1;
		return mPCSCFFQDN;
	}
	return mPCSCFFQDN;
}

void FailedPCSCF::resetPCSCFFQDN(){
	mTagsPresent[FailedPCSCF_PCSCFFQDN] = 0;
	if(mPCSCFFQDN != NULL)
	{
		delete mPCSCFFQDN; 
		mPCSCFFQDN = NULL;
	}
}

OctetString* FailedPCSCF::getPCSCFFQDN(){
	if(NULL == mPCSCFFQDN) {
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PCSCFFQDN is Null");
		throw lTssDiaMsgException;
	}
	if(!mPCSCFFQDN->mAvpDecodedFlag)
	{
			if(mspByteArray.get() == NULL)
			{
			mPCSCFFQDN->mAvpDecodedFlag = true;
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PCSCFFQDN is Null");
			throw lTssDiaMsgException;
			}
		mspByteArray.get()->offset = 0;
		mspByteArray.get()->offset = mPCSCFFQDN->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(mPCSCFFQDN->Decode(mspByteArray.get(), mPCSCFFQDN->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PCSCFFQDN")     ;
			throw lTssDiaMsgException;
		}
		mPCSCFFQDN->mAvpDecodedFlag = true;
	}
	return mPCSCFFQDN;
}

list<Address*>* FailedPCSCF::getPCSCFIPAddressList()
{
	if(mPCSCFIPAddressList == NULL)
	{
		TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PCSCFIPAddress is Null");
		throw lTssDiaMsgException;
	}
	for(auto itr : *mPCSCFIPAddressList)
	{
		if(!itr->mAvpDecodedFlag)
		{
			if(mspByteArray.get() == NULL)
			{
				itr->mAvpDecodedFlag = true;
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_OBJ_NULL, "PCSCFIPAddress is Null");
				throw lTssDiaMsgException;
			}
			itr->mspByteArray.get()->offset = 0;
			itr->mspByteArray.get()->offset = itr->getAvpOffsetLen().first;
			UINT16 lBytesDecoded = 0;
			if(itr->Decode(itr->mspByteArray.get(), itr->getAvpOffsetLen().second, &lBytesDecoded)< 0)
			{
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PCSCFIPAddress")     ;
				throw lTssDiaMsgException;
			}
			itr->mAvpDecodedFlag = true;
		}
	}
	return mPCSCFIPAddressList;
}

list<Address*>* FailedPCSCF::setPCSCFIPAddressList() {
	mTagsPresent[FailedPCSCF_PCSCFIPADDRESS] = 1;
	if(mPCSCFIPAddressList == NULL)
		mPCSCFIPAddressList = new list<Address*>;
	mPCSCFIPAddressList->clear();
	return mPCSCFIPAddressList;
}

void FailedPCSCF::resetPCSCFIPAddressList(){
	mTagsPresent[FailedPCSCF_PCSCFIPADDRESS] = 0;
	if(mPCSCFIPAddressList != NULL)
		delete mPCSCFIPAddressList;
}



int FailedPCSCF::Encode(byteArray *array)
{
	INT32 lTempHtonlVar = 0;

	for(unsigned int i = 0 ; i < mTagsPresent.size() ; ++i )
	{

		if(!mTagsPresent[i])
			continue;
		unsigned lengthOffset = 0;
		switch(i)
		{
			case FailedPCSCF_PCSCFFQDN:
			{
					array->size+=4;
					lTempHtonlVar =  htonl(665);
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
					if(!mPCSCFFQDN->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[mPCSCFFQDN->getAvpOffsetLen().first], mPCSCFFQDN->getAvpOffsetLen().second);
						array->offset += mPCSCFFQDN->getAvpOffsetLen().second;
						array->size += mPCSCFFQDN->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( mPCSCFFQDN->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -(mPCSCFFQDN->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PCSCFFQDN");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						continue;
					}
					if((mPCSCFFQDN->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, mPCSCFFQDN->getLength()) == false)){ 
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PCSCFFQDN");
						throw lTssDiaMsgException;
					}
				}
				break;
			case FailedPCSCF_PCSCFIPADDRESS:
			{
					if( mPCSCFIPAddressList->size() <= 0) {
						break;
					}

					mPCSCFIPAddressIterator = this->getPCSCFIPAddressList()->begin();
					while(mPCSCFIPAddressIterator != mPCSCFIPAddressList->end())
					{
						lengthOffset = 0;
						array->size+=4;
					lTempHtonlVar =  htonl(666);
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
					if(!(*mPCSCFIPAddressIterator)->mAvpDecodedFlag)
					{
						memcpy(array->byte+array->offset, &mspByteArray.get()->byte[(*mPCSCFIPAddressIterator)->getAvpOffsetLen().first], (*mPCSCFIPAddressIterator)->getAvpOffsetLen().second);
						array->offset += (*mPCSCFIPAddressIterator)->getAvpOffsetLen().second;
						array->size += (*mPCSCFIPAddressIterator)->getAvpOffsetLen().second;
						UINT8 lPaddingLen = 0;
						if ( (*mPCSCFIPAddressIterator)->getAvpOffsetLen().second%4 != 0)
						{
							lPaddingLen = (4 -((*mPCSCFIPAddressIterator)->getAvpOffsetLen().second%4));
						}
						if(false == DiameterTLVUtil::avp_length_encode(lengthOffset, array,TSS_MAX_DIAMETER_TIME_LEN)){
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PCSCFIPAddress");
							throw lTssDiaMsgException;
						}
						array->offset += lPaddingLen;
						array->size += lPaddingLen;
						mPCSCFIPAddressIterator++;
						continue;
					}
						if(((*mPCSCFIPAddressIterator)->Encode(array) < 0) || 
							(DiameterTLVUtil::avp_length_encode(lengthOffset, array, (*mPCSCFIPAddressIterator)->getLength()) == false)){ 
							TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Error encoding PCSCFIPAddress");
							throw lTssDiaMsgException;
						}
						mPCSCFIPAddressIterator++;
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


int FailedPCSCF::Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes)
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
			case 665:
				{
					if( NULL == this->setPCSCFFQDN())
					{
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PCSCFFQDN");
						throw lTssDiaMsgException;
					}
					mPCSCFFQDN->setAvpCode(665);
					mPCSCFFQDN->setAvpVendorId(lVenderId);
					mPCSCFFQDN->SetDataType((DiameterDataType)5);
					mPCSCFFQDN->mspByteArray = mspByteArray;
					mPCSCFFQDN->mAvpDecodedFlag = false;
					mPCSCFFQDN->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

				}
				break;
			case 666:
				{
					mTagsPresent[FailedPCSCF_PCSCFIPADDRESS] = 1;
					Address *lPCSCFIPAddress = new Address();
					if( lPCSCFIPAddress == NULL ){
						mDecodeFlag = false;
						TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding PCSCFIPAddress");
						throw lTssDiaMsgException;
					}
					lPCSCFIPAddress->setAvpCode(666);
					lPCSCFIPAddress->setAvpVendorId(lVenderId);
					lPCSCFIPAddress->SetDataType((DiameterDataType)8);
					lPCSCFIPAddress->mspByteArray = mspByteArray;
					lPCSCFIPAddress->mAvpDecodedFlag = false;
					lPCSCFIPAddress->setAvpOffsetLen(array->offset,lAvpDataLen);
					array->offset+=lAvpDataLen;

					if(mPCSCFIPAddressList == NULL)
						this->setPCSCFIPAddressList();
					mPCSCFIPAddressList->push_back(lPCSCFIPAddress);
					
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


DiameterBaseInterface* FailedPCSCF::Find(byteArray *array, UINT32 avpCode)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FailedPCSCF")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 665:
			{
				if(mPCSCFFQDN != NULL)
					return mPCSCFFQDN->Find(array, avpCode);
				else
					return NULL;
			}
			case 666:
			{
				if(mPCSCFIPAddressList != NULL && mPCSCFIPAddressList->size() > 0)
					return (mPCSCFIPAddressList->back())->Find(array, avpCode);
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


BOOLEAN FailedPCSCF::FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FailedPCSCF")     ;
			throw lTssDiaMsgException;
		}
		this->mAvpDecodedFlag = true;
	}
		switch(avpCode)
		{
			case 665:
			{
				if(mPCSCFFQDN != NULL)
				{
					DiameterBaseInterface* inf =  mPCSCFFQDN->Find(this->mspByteArray.get(), avpCode);
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
			case 666:
			{
				if(mPCSCFIPAddressList != NULL)
				{
					for(auto itr = mPCSCFIPAddressList->begin(); itr != mPCSCFIPAddressList->end(); ++itr)
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
std::shared_ptr<byteArray> FailedPCSCF::GetByteArray()
{
	return mspByteArray;
}


BOOLEAN FailedPCSCF::FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface,BOOLEAN deepInspect)
{
	if(!this->mAvpDecodedFlag)
	{
		this->mspByteArray.get()->offset = 0;
		this->mspByteArray.get()->offset = this->getAvpOffsetLen().first;
		UINT16 lBytesDecoded = 0;
		if(this->Decode(mspByteArray.get(), this->getAvpOffsetLen().second, &lBytesDecoded)< 0)
		{
			TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding FailedPCSCF")     ;
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
			case 665:
			{
				if(mPCSCFFQDN != NULL)
				{
					DiameterBaseInterface* inf =  mPCSCFFQDN->Find(this->mspByteArray.get(), avpCode);
					if(inf != NULL)
					{
						pBaseInterface.push_back(inf);
					}
				}

				break;
			}
			case 666:
			{
				if(mPCSCFIPAddressList != NULL)
				{
					for(auto itr = mPCSCFIPAddressList->begin(); itr != mPCSCFIPAddressList->end(); ++itr)
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


INT32 FailedPCSCF::setAvpCode(UINT32 avpCode)
{
	mAvpCode = avpCode;
	return 0;
}
UINT32 FailedPCSCF::getAvpCode()
{
	return mAvpCode;
}
INT32 FailedPCSCF::setAvpVendorId(UINT32 avpVendorId)
{
	mAvpVendorId = avpVendorId;
	return 0;
}
UINT32 FailedPCSCF::getAvpVendorId()
{
	return mAvpVendorId;
}
INT32 FailedPCSCF::setAvpOffsetLen(INT16 offset, INT16 length)
{
	mAvpOffsetLen = make_pair(offset,length);
	return 0;
}
pair<INT16,INT16> FailedPCSCF::getAvpOffsetLen()
{
	return mAvpOffsetLen;
}



void FailedPCSCF::Display(UINT32 tab)
{
	int tempTab = tab * 3; 

	for(int i = 0; i < mTagsPresent.size() ; ++i)
	{

		if(!mTagsPresent[i])
			continue;
		switch(i)
		{
			case FailedPCSCF_PCSCFFQDN:
			{
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "665" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
				cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PCSCFFQDN" << "\n"; 
				TEXT lAvpFlg[100];
				//Hardcoded value.;
				sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
				this->getPCSCFFQDN()->Display(tab+1);
			}
				break;
			case FailedPCSCF_PCSCFIPADDRESS:
			{
				if( mPCSCFIPAddressList->size() <= 0) {
					break;
				}

				mPCSCFIPAddressIterator = this->getPCSCFIPAddressList()->begin();
				while(mPCSCFIPAddressIterator != this->getPCSCFIPAddressList()->end()) {
					cout << setw(tempTab)  << "" << "|"  << left <<  setw(12) << "AvpCode" << ":" << setw(15) << "666" << "|" << setw(12)  << "AvpType" << ":" << setw(15) << "SINGLE" << "|" << "\n"; 
					cout << setw(tempTab) << "" << "|"  << left <<  setw(12) << "AvpName" << ":" << setw(44) << "PCSCFIPAddress" << "\n"; 
					TEXT lAvpFlg[100];
					//Hardcoded value.;
					sprintf( lAvpFlg, "%s %s %s", ((DiameterTLVUtil::isVenderSpecific(128)==true)?"Vendor":""), ((DiameterTLVUtil::isMandatoryBitSet(128)==true)?"Mandatory":""), ((DiameterTLVUtil::isProtectedBitSet(128)==true)?"Protected":""));
					(*mPCSCFIPAddressIterator)->Display(tab+1);
					mPCSCFIPAddressIterator++;

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


BOOLEAN FailedPCSCF::GetMissingAvpInfo(TEXT *lMissingAvpInfo)
{
	bitset<2> lMissingAvpTag(mMandatoryAvpSetVal ^ mMandatoryAvpCheckVal);
	BOOLEAN lFirstRec = true;

	for(unsigned int i = 0 ; i < lMissingAvpTag.size(); ++i)
	{
		if(!lMissingAvpTag[i])
			continue;
		switch(i)
		{
			case FailedPCSCF_PCSCFFQDN:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 665");
				}
				else
					sprintf(lMissingAvpInfo, "%s,665", lMissingAvpInfo);
			}
				break;
			case FailedPCSCF_PCSCFIPADDRESS:
			{
				if(lFirstRec == true)
				{
					lFirstRec = false;
					sprintf(lMissingAvpInfo, "Missing Avps List: 666");
				}
				else
					sprintf(lMissingAvpInfo, "%s,666", lMissingAvpInfo);
			}
				break;
			default:
				break;
		}
	}


	return true;
}
