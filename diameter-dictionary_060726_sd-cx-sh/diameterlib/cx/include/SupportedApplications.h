#ifndef CX_SUPPORTEDAPPLICATIONS_H
#define CX_SUPPORTEDAPPLICATIONS_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/VendorSpecificApplicationId.h"
using namespace std;

namespace CX{
typedef enum _tags_SupportedApplications
{
	SupportedApplications_AUTHAPPLICATIONID	= 0,
	SupportedApplications_ACCTAPPLICATIONID	= 1,
	SupportedApplications_VENDORSPECIFICAPPLICATIONID	= 2,
}SupportedApplications_tags;

		//! Class Definition
		/*!		ClassName is SupportedApplications
		*/
class SupportedApplications : public DiameterBaseInterface
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

		list<Unsigned32*>* 		mAuthApplicationIdList;

		list<Unsigned32*>::iterator 		mAuthApplicationIdIterator;

		list<Unsigned32*>* 		mAcctApplicationIdList;

		list<Unsigned32*>::iterator 		mAcctApplicationIdIterator;




		list<VendorSpecificApplicationId*>*	mVendorSpecificApplicationIdGrpList;
		list<VendorSpecificApplicationId*>::iterator	mVendorSpecificApplicationIdGrpIterator;

	public:
		SupportedApplications();

		SupportedApplications(const SupportedApplications &objSupportedApplications) {

		mTagsPresent = objSupportedApplications.mTagsPresent;

		mMandatoryAvpCheckVal = objSupportedApplications.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSupportedApplications.mMandatoryAvpSetVal;

		mTag = objSupportedApplications.mTag;

		mDecodeFlag = objSupportedApplications.mDecodeFlag;

		if(objSupportedApplications.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objSupportedApplications.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		}

		void operator = (const SupportedApplications &objSupportedApplications) {

		mTagsPresent = objSupportedApplications.mTagsPresent;

		mMandatoryAvpCheckVal = objSupportedApplications.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSupportedApplications.mMandatoryAvpSetVal;

		mTag = objSupportedApplications.mTag;

		mDecodeFlag = objSupportedApplications.mDecodeFlag;

		if(objSupportedApplications.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objSupportedApplications.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		}

		virtual ~SupportedApplications();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		list<Unsigned32*>* getAuthApplicationIdList();

		list<Unsigned32*>* setAuthApplicationIdList();

		void resetAuthApplicationIdList();

		list<Unsigned32*>* getAcctApplicationIdList();

		list<Unsigned32*>* setAcctApplicationIdList();

		void resetAcctApplicationIdList();

		list<VendorSpecificApplicationId*>* getVendorSpecificApplicationIdGrpList();

		list<VendorSpecificApplicationId*>* setVendorSpecificApplicationIdGrpList();

		void resetVendorSpecificApplicationIdGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype SupportedApplications
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype SupportedApplications
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SupportedApplications
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SupportedApplications
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SupportedApplications
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
