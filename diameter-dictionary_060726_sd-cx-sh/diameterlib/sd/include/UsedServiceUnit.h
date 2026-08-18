#ifndef SD_USEDSERVICEUNIT_H
#define SD_USEDSERVICEUNIT_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SD{
typedef enum _tags_UsedServiceUnit
{
	UsedServiceUnit_CCTOTALOCTETS	= 0,
	UsedServiceUnit_CCINPUTOCTETS	= 1,
	UsedServiceUnit_CCOUTPUTOCTETS	= 2,
	UsedServiceUnit_CCTIME	= 3,
}UsedServiceUnit_tags;

		//! Class Definition
		/*!		ClassName is UsedServiceUnit
		*/
class UsedServiceUnit : public DiameterBaseInterface
{
	private:

		bitset<4> mTagsPresent;

		bitset<4> mMandatoryAvpCheckVal;

		bitset<4> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		Unsigned64*		mCCTotalOctets;

		Unsigned64*		mCCInputOctets;

		Unsigned64*		mCCOutputOctets;

		Unsigned32*		mCCTime;






	public:
		UsedServiceUnit();

		UsedServiceUnit(const UsedServiceUnit &objUsedServiceUnit) {

		mTagsPresent = objUsedServiceUnit.mTagsPresent;

		mMandatoryAvpCheckVal = objUsedServiceUnit.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUsedServiceUnit.mMandatoryAvpSetVal;

		mTag = objUsedServiceUnit.mTag;

		mDecodeFlag = objUsedServiceUnit.mDecodeFlag;

		if(objUsedServiceUnit.mCCTotalOctets != NULL)
		mCCTotalOctets = new Unsigned64(*(objUsedServiceUnit.mCCTotalOctets));

		if(objUsedServiceUnit.mCCInputOctets != NULL)
		mCCInputOctets = new Unsigned64(*(objUsedServiceUnit.mCCInputOctets));

		if(objUsedServiceUnit.mCCOutputOctets != NULL)
		mCCOutputOctets = new Unsigned64(*(objUsedServiceUnit.mCCOutputOctets));

		if(objUsedServiceUnit.mCCTime != NULL)
		mCCTime = new Unsigned32(*(objUsedServiceUnit.mCCTime));

		}

		void operator = (const UsedServiceUnit &objUsedServiceUnit) {

		mTagsPresent = objUsedServiceUnit.mTagsPresent;

		mMandatoryAvpCheckVal = objUsedServiceUnit.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUsedServiceUnit.mMandatoryAvpSetVal;

		mTag = objUsedServiceUnit.mTag;

		mDecodeFlag = objUsedServiceUnit.mDecodeFlag;

		if(objUsedServiceUnit.mCCTotalOctets != NULL)
		mCCTotalOctets = new Unsigned64(*(objUsedServiceUnit.mCCTotalOctets));

		if(objUsedServiceUnit.mCCInputOctets != NULL)
		mCCInputOctets = new Unsigned64(*(objUsedServiceUnit.mCCInputOctets));

		if(objUsedServiceUnit.mCCOutputOctets != NULL)
		mCCOutputOctets = new Unsigned64(*(objUsedServiceUnit.mCCOutputOctets));

		if(objUsedServiceUnit.mCCTime != NULL)
		mCCTime = new Unsigned32(*(objUsedServiceUnit.mCCTime));

		}

		virtual ~UsedServiceUnit();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument CCTotalOctets for datatype UsedServiceUnit
		*/
		Unsigned64* setCCTotalOctets();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCTotalOctets for datatype UsedServiceUnit
		*/
		void resetCCTotalOctets();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument CCTotalOctets for datatype UsedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getCCTotalOctets();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument CCInputOctets for datatype UsedServiceUnit
		*/
		Unsigned64* setCCInputOctets();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCInputOctets for datatype UsedServiceUnit
		*/
		void resetCCInputOctets();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument CCInputOctets for datatype UsedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getCCInputOctets();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument CCOutputOctets for datatype UsedServiceUnit
		*/
		Unsigned64* setCCOutputOctets();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCOutputOctets for datatype UsedServiceUnit
		*/
		void resetCCOutputOctets();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument CCOutputOctets for datatype UsedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getCCOutputOctets();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument CCTime for datatype UsedServiceUnit
		*/
		Unsigned32* setCCTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCTime for datatype UsedServiceUnit
		*/
		void resetCCTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument CCTime for datatype UsedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getCCTime();

		//! Function to Decode
		/*!		Function to Decode datatype UsedServiceUnit
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype UsedServiceUnit
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UsedServiceUnit
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UsedServiceUnit
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UsedServiceUnit
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
