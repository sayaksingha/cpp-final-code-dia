#ifndef RX_CCMONEY_H
#define RX_CCMONEY_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "rx/include/UnitValue.h"
using namespace std;

namespace RX{
typedef enum _tags_CCMoney
{
	CCMoney_UNITVALUE	= 0,
	CCMoney_CURRENCYCODE	= 1,
}CCMoney_tags;

		//! Class Definition
		/*!		ClassName is CCMoney
		*/
class CCMoney : public DiameterBaseInterface
{
	private:

		bitset<2> mTagsPresent;

		bitset<2> mMandatoryAvpCheckVal;

		bitset<2> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		Unsigned64*		mCurrencyCode;


		list<UnitValue*>*	mUnitValueGrpList;
		list<UnitValue*>::iterator	mUnitValueGrpIterator;


	public:
		CCMoney();

		CCMoney(const CCMoney &objCCMoney) {

		mTagsPresent = objCCMoney.mTagsPresent;

		mMandatoryAvpCheckVal = objCCMoney.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCCMoney.mMandatoryAvpSetVal;

		mTag = objCCMoney.mTag;

		mDecodeFlag = objCCMoney.mDecodeFlag;

		if(objCCMoney.mUnitValueGrpList != NULL)
		 {
		 mUnitValueGrpList = new list<UnitValue*>;
		 for( auto element : *objCCMoney.mUnitValueGrpList)
		 {
				 UnitValue *lUnitValue =  new UnitValue(*element);
				 mUnitValueGrpList->push_back(lUnitValue);
		 }
		 }
		if(objCCMoney.mCurrencyCode != NULL)
		mCurrencyCode = new Unsigned64(*(objCCMoney.mCurrencyCode));

		}

		void operator = (const CCMoney &objCCMoney) {

		mTagsPresent = objCCMoney.mTagsPresent;

		mMandatoryAvpCheckVal = objCCMoney.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCCMoney.mMandatoryAvpSetVal;

		mTag = objCCMoney.mTag;

		mDecodeFlag = objCCMoney.mDecodeFlag;

		if(objCCMoney.mUnitValueGrpList != NULL)
		 {
		 mUnitValueGrpList = new list<UnitValue*>;
		 for( auto element : *objCCMoney.mUnitValueGrpList)
		 {
				 UnitValue *lUnitValue =  new UnitValue(*element);
				 mUnitValueGrpList->push_back(lUnitValue);
		 }
		 }
		if(objCCMoney.mCurrencyCode != NULL)
		mCurrencyCode = new Unsigned64(*(objCCMoney.mCurrencyCode));

		}

		virtual ~CCMoney();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		list<UnitValue*>* getUnitValueGrpList();

		list<UnitValue*>* setUnitValueGrpList();

		void resetUnitValueGrpList();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument CurrencyCode for datatype CCMoney
		*/
		Unsigned64* setCurrencyCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CurrencyCode for datatype CCMoney
		*/
		void resetCurrencyCode();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument CurrencyCode for datatype CCMoney
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getCurrencyCode();

		//! Function to Decode
		/*!		Function to Decode datatype CCMoney
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype CCMoney
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype CCMoney
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype CCMoney
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CCMoney
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
