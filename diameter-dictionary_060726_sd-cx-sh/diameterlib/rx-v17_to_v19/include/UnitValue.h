#ifndef RX_UNITVALUE_H
#define RX_UNITVALUE_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace RX{
typedef enum _tags_UnitValue
{
	UnitValue_VALUEDIGITS	= 0,
	UnitValue_EXPONENT	= 1,
}UnitValue_tags;

		//! Class Definition
		/*!		ClassName is UnitValue
		*/
class UnitValue : public DiameterBaseInterface
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

		Integer64*		mValueDigits;

		Integer32*		mExponent;




	public:
		UnitValue();

		UnitValue(const UnitValue &objUnitValue) {

		mTagsPresent = objUnitValue.mTagsPresent;

		mMandatoryAvpCheckVal = objUnitValue.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUnitValue.mMandatoryAvpSetVal;

		mTag = objUnitValue.mTag;

		mDecodeFlag = objUnitValue.mDecodeFlag;

		if(objUnitValue.mValueDigits != NULL)
		mValueDigits = new Integer64(*(objUnitValue.mValueDigits));

		if(objUnitValue.mExponent != NULL)
		mExponent = new Integer32(*(objUnitValue.mExponent));

		}

		void operator = (const UnitValue &objUnitValue) {

		mTagsPresent = objUnitValue.mTagsPresent;

		mMandatoryAvpCheckVal = objUnitValue.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUnitValue.mMandatoryAvpSetVal;

		mTag = objUnitValue.mTag;

		mDecodeFlag = objUnitValue.mDecodeFlag;

		if(objUnitValue.mValueDigits != NULL)
		mValueDigits = new Integer64(*(objUnitValue.mValueDigits));

		if(objUnitValue.mExponent != NULL)
		mExponent = new Integer32(*(objUnitValue.mExponent));

		}

		virtual ~UnitValue();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Integer64 type of argument ValueDigits for datatype UnitValue
		*/
		Integer64* setValueDigits();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ValueDigits for datatype UnitValue
		*/
		void resetValueDigits();

		//!Function to get values
		/*!		Function to get Integer64 type of argument ValueDigits for datatype UnitValue
		Throws exception of which type and Summary of Exception
		*/
		Integer64* getValueDigits();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument Exponent for datatype UnitValue
		*/
		Integer32* setExponent();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Exponent for datatype UnitValue
		*/
		void resetExponent();

		//!Function to get values
		/*!		Function to get Integer32 type of argument Exponent for datatype UnitValue
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getExponent();

		//! Function to Decode
		/*!		Function to Decode datatype UnitValue
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype UnitValue
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UnitValue
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UnitValue
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UnitValue
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
