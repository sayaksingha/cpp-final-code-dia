#ifndef SH_VENDORSPECIFICAPPLICATIONID_H
#define SH_VENDORSPECIFICAPPLICATIONID_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SH{
typedef enum _tags_VendorSpecificApplicationId
{
	VendorSpecificApplicationId_VENDORID	= 0,
	VendorSpecificApplicationId_AUTHAPPLICATIONID	= 1,
	VendorSpecificApplicationId_ACCTAPPLICATIONID	= 2,
}VendorSpecificApplicationId_tags;

		//! Class Definition
		/*!		ClassName is VendorSpecificApplicationId
		*/
class VendorSpecificApplicationId : public DiameterBaseInterface
{
	private:

		bitset<3> mTagsPresent;

		bitset<3> mMandatoryAvpCheckVal;

		bitset<3> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		Unsigned32*		mVendorId;

		Unsigned32*		mAuthApplicationId;

		Unsigned32*		mAcctApplicationId;





	public:
		VendorSpecificApplicationId();

		VendorSpecificApplicationId(const VendorSpecificApplicationId &objVendorSpecificApplicationId) {

		mTagsPresent = objVendorSpecificApplicationId.mTagsPresent;

		mMandatoryAvpCheckVal = objVendorSpecificApplicationId.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objVendorSpecificApplicationId.mMandatoryAvpSetVal;

		mTag = objVendorSpecificApplicationId.mTag;

		mDecodeFlag = objVendorSpecificApplicationId.mDecodeFlag;

		if(objVendorSpecificApplicationId.mVendorId != NULL)
		mVendorId = new Unsigned32(*(objVendorSpecificApplicationId.mVendorId));

		if(objVendorSpecificApplicationId.mAuthApplicationId != NULL)
		mAuthApplicationId = new Unsigned32(*(objVendorSpecificApplicationId.mAuthApplicationId));

		if(objVendorSpecificApplicationId.mAcctApplicationId != NULL)
		mAcctApplicationId = new Unsigned32(*(objVendorSpecificApplicationId.mAcctApplicationId));

		}

		void operator = (const VendorSpecificApplicationId &objVendorSpecificApplicationId) {

		mTagsPresent = objVendorSpecificApplicationId.mTagsPresent;

		mMandatoryAvpCheckVal = objVendorSpecificApplicationId.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objVendorSpecificApplicationId.mMandatoryAvpSetVal;

		mTag = objVendorSpecificApplicationId.mTag;

		mDecodeFlag = objVendorSpecificApplicationId.mDecodeFlag;

		if(objVendorSpecificApplicationId.mVendorId != NULL)
		mVendorId = new Unsigned32(*(objVendorSpecificApplicationId.mVendorId));

		if(objVendorSpecificApplicationId.mAuthApplicationId != NULL)
		mAuthApplicationId = new Unsigned32(*(objVendorSpecificApplicationId.mAuthApplicationId));

		if(objVendorSpecificApplicationId.mAcctApplicationId != NULL)
		mAcctApplicationId = new Unsigned32(*(objVendorSpecificApplicationId.mAcctApplicationId));

		}

		virtual ~VendorSpecificApplicationId();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument VendorId for datatype VendorSpecificApplicationId
		*/
		Unsigned32* setVendorId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument VendorId for datatype VendorSpecificApplicationId
		*/
		void resetVendorId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument VendorId for datatype VendorSpecificApplicationId
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getVendorId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument AuthApplicationId for datatype VendorSpecificApplicationId
		*/
		Unsigned32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype VendorSpecificApplicationId
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument AuthApplicationId for datatype VendorSpecificApplicationId
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getAuthApplicationId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument AcctApplicationId for datatype VendorSpecificApplicationId
		*/
		Unsigned32* setAcctApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AcctApplicationId for datatype VendorSpecificApplicationId
		*/
		void resetAcctApplicationId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument AcctApplicationId for datatype VendorSpecificApplicationId
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getAcctApplicationId();

		//! Function to Decode
		/*!		Function to Decode datatype VendorSpecificApplicationId
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype VendorSpecificApplicationId
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype VendorSpecificApplicationId
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype VendorSpecificApplicationId
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype VendorSpecificApplicationId
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
