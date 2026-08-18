#ifndef CX_CHARGINGINFORMATION_H
#define CX_CHARGINGINFORMATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace CX{
typedef enum _tags_ChargingInformation
{
	ChargingInformation_PRIMARYEVENTCHARGINGFUNCTIONNAME	= 0,
	ChargingInformation_SECONDARYEVENTCHARGINGFUNCTIONNAME	= 1,
	ChargingInformation_PRIMARYCHARGINGCOLLECTIONFUNCTIONNAME	= 2,
	ChargingInformation_SECONDARYCHARGINGCOLLECTIONFUNCTIONNAME	= 3,
}ChargingInformation_tags;

		//! Class Definition
		/*!		ClassName is ChargingInformation
		*/
class ChargingInformation : public DiameterBaseInterface
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

		OctetString*		mPrimaryEventChargingFunctionName;

		OctetString*		mSecondaryEventChargingFunctionName;

		OctetString*		mPrimaryChargingCollectionFunctionName;

		OctetString*		mSecondaryChargingCollectionFunctionName;






	public:
		ChargingInformation();

		ChargingInformation(const ChargingInformation &objChargingInformation) {

		mTagsPresent = objChargingInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objChargingInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objChargingInformation.mMandatoryAvpSetVal;

		mTag = objChargingInformation.mTag;

		mDecodeFlag = objChargingInformation.mDecodeFlag;

		if(objChargingInformation.mPrimaryEventChargingFunctionName != NULL)
		mPrimaryEventChargingFunctionName = new OctetString(*(objChargingInformation.mPrimaryEventChargingFunctionName));

		if(objChargingInformation.mSecondaryEventChargingFunctionName != NULL)
		mSecondaryEventChargingFunctionName = new OctetString(*(objChargingInformation.mSecondaryEventChargingFunctionName));

		if(objChargingInformation.mPrimaryChargingCollectionFunctionName != NULL)
		mPrimaryChargingCollectionFunctionName = new OctetString(*(objChargingInformation.mPrimaryChargingCollectionFunctionName));

		if(objChargingInformation.mSecondaryChargingCollectionFunctionName != NULL)
		mSecondaryChargingCollectionFunctionName = new OctetString(*(objChargingInformation.mSecondaryChargingCollectionFunctionName));

		}

		void operator = (const ChargingInformation &objChargingInformation) {

		mTagsPresent = objChargingInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objChargingInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objChargingInformation.mMandatoryAvpSetVal;

		mTag = objChargingInformation.mTag;

		mDecodeFlag = objChargingInformation.mDecodeFlag;

		if(objChargingInformation.mPrimaryEventChargingFunctionName != NULL)
		mPrimaryEventChargingFunctionName = new OctetString(*(objChargingInformation.mPrimaryEventChargingFunctionName));

		if(objChargingInformation.mSecondaryEventChargingFunctionName != NULL)
		mSecondaryEventChargingFunctionName = new OctetString(*(objChargingInformation.mSecondaryEventChargingFunctionName));

		if(objChargingInformation.mPrimaryChargingCollectionFunctionName != NULL)
		mPrimaryChargingCollectionFunctionName = new OctetString(*(objChargingInformation.mPrimaryChargingCollectionFunctionName));

		if(objChargingInformation.mSecondaryChargingCollectionFunctionName != NULL)
		mSecondaryChargingCollectionFunctionName = new OctetString(*(objChargingInformation.mSecondaryChargingCollectionFunctionName));

		}

		virtual ~ChargingInformation();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PrimaryEventChargingFunctionName for datatype ChargingInformation
		*/
		OctetString* setPrimaryEventChargingFunctionName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PrimaryEventChargingFunctionName for datatype ChargingInformation
		*/
		void resetPrimaryEventChargingFunctionName();

		//!Function to get values
		/*!		Function to get OctetString type of argument PrimaryEventChargingFunctionName for datatype ChargingInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPrimaryEventChargingFunctionName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SecondaryEventChargingFunctionName for datatype ChargingInformation
		*/
		OctetString* setSecondaryEventChargingFunctionName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SecondaryEventChargingFunctionName for datatype ChargingInformation
		*/
		void resetSecondaryEventChargingFunctionName();

		//!Function to get values
		/*!		Function to get OctetString type of argument SecondaryEventChargingFunctionName for datatype ChargingInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSecondaryEventChargingFunctionName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PrimaryChargingCollectionFunctionName for datatype ChargingInformation
		*/
		OctetString* setPrimaryChargingCollectionFunctionName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PrimaryChargingCollectionFunctionName for datatype ChargingInformation
		*/
		void resetPrimaryChargingCollectionFunctionName();

		//!Function to get values
		/*!		Function to get OctetString type of argument PrimaryChargingCollectionFunctionName for datatype ChargingInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPrimaryChargingCollectionFunctionName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SecondaryChargingCollectionFunctionName for datatype ChargingInformation
		*/
		OctetString* setSecondaryChargingCollectionFunctionName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SecondaryChargingCollectionFunctionName for datatype ChargingInformation
		*/
		void resetSecondaryChargingCollectionFunctionName();

		//!Function to get values
		/*!		Function to get OctetString type of argument SecondaryChargingCollectionFunctionName for datatype ChargingInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSecondaryChargingCollectionFunctionName();

		//! Function to Decode
		/*!		Function to Decode datatype ChargingInformation
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ChargingInformation
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ChargingInformation
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ChargingInformation
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ChargingInformation
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
