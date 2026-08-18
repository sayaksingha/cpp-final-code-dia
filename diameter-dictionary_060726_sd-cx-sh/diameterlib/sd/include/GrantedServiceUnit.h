#ifndef SD_GRANTEDSERVICEUNIT_H
#define SD_GRANTEDSERVICEUNIT_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SD{
typedef enum _tags_GrantedServiceUnit
{
	GrantedServiceUnit_CCTOTALOCTETS	= 0,
	GrantedServiceUnit_CCINPUTOCTETS	= 1,
	GrantedServiceUnit_CCOUTPUTOCTETS	= 2,
	GrantedServiceUnit_CCTIME	= 3,
}GrantedServiceUnit_tags;

		//! Class Definition
		/*!		ClassName is GrantedServiceUnit
		*/
class GrantedServiceUnit : public DiameterBaseInterface
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
		GrantedServiceUnit();

		GrantedServiceUnit(const GrantedServiceUnit &objGrantedServiceUnit) {

		mTagsPresent = objGrantedServiceUnit.mTagsPresent;

		mMandatoryAvpCheckVal = objGrantedServiceUnit.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objGrantedServiceUnit.mMandatoryAvpSetVal;

		mTag = objGrantedServiceUnit.mTag;

		mDecodeFlag = objGrantedServiceUnit.mDecodeFlag;

		if(objGrantedServiceUnit.mCCTotalOctets != NULL)
		mCCTotalOctets = new Unsigned64(*(objGrantedServiceUnit.mCCTotalOctets));

		if(objGrantedServiceUnit.mCCInputOctets != NULL)
		mCCInputOctets = new Unsigned64(*(objGrantedServiceUnit.mCCInputOctets));

		if(objGrantedServiceUnit.mCCOutputOctets != NULL)
		mCCOutputOctets = new Unsigned64(*(objGrantedServiceUnit.mCCOutputOctets));

		if(objGrantedServiceUnit.mCCTime != NULL)
		mCCTime = new Unsigned32(*(objGrantedServiceUnit.mCCTime));

		}

		void operator = (const GrantedServiceUnit &objGrantedServiceUnit) {

		mTagsPresent = objGrantedServiceUnit.mTagsPresent;

		mMandatoryAvpCheckVal = objGrantedServiceUnit.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objGrantedServiceUnit.mMandatoryAvpSetVal;

		mTag = objGrantedServiceUnit.mTag;

		mDecodeFlag = objGrantedServiceUnit.mDecodeFlag;

		if(objGrantedServiceUnit.mCCTotalOctets != NULL)
		mCCTotalOctets = new Unsigned64(*(objGrantedServiceUnit.mCCTotalOctets));

		if(objGrantedServiceUnit.mCCInputOctets != NULL)
		mCCInputOctets = new Unsigned64(*(objGrantedServiceUnit.mCCInputOctets));

		if(objGrantedServiceUnit.mCCOutputOctets != NULL)
		mCCOutputOctets = new Unsigned64(*(objGrantedServiceUnit.mCCOutputOctets));

		if(objGrantedServiceUnit.mCCTime != NULL)
		mCCTime = new Unsigned32(*(objGrantedServiceUnit.mCCTime));

		}

		virtual ~GrantedServiceUnit();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument CCTotalOctets for datatype GrantedServiceUnit
		*/
		Unsigned64* setCCTotalOctets();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCTotalOctets for datatype GrantedServiceUnit
		*/
		void resetCCTotalOctets();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument CCTotalOctets for datatype GrantedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getCCTotalOctets();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument CCInputOctets for datatype GrantedServiceUnit
		*/
		Unsigned64* setCCInputOctets();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCInputOctets for datatype GrantedServiceUnit
		*/
		void resetCCInputOctets();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument CCInputOctets for datatype GrantedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getCCInputOctets();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument CCOutputOctets for datatype GrantedServiceUnit
		*/
		Unsigned64* setCCOutputOctets();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCOutputOctets for datatype GrantedServiceUnit
		*/
		void resetCCOutputOctets();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument CCOutputOctets for datatype GrantedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getCCOutputOctets();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument CCTime for datatype GrantedServiceUnit
		*/
		Unsigned32* setCCTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCTime for datatype GrantedServiceUnit
		*/
		void resetCCTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument CCTime for datatype GrantedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getCCTime();

		//! Function to Decode
		/*!		Function to Decode datatype GrantedServiceUnit
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype GrantedServiceUnit
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype GrantedServiceUnit
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype GrantedServiceUnit
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype GrantedServiceUnit
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
