#ifndef CX_RESTORATIONINFO_H
#define CX_RESTORATIONINFO_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/SubscriptionInfo.h"
#include "cx/include/PCSCFSubscriptionInfo.h"
using namespace std;

namespace CX{
typedef enum _tags_RestorationInfo
{
	RestorationInfo_PATH	= 0,
	RestorationInfo_CONTACT	= 1,
	RestorationInfo_INITIALCSEQSEQUENCENUMBER	= 2,
	RestorationInfo_CALLIDSIPHEADER	= 3,
	RestorationInfo_SUBSCRIPTIONINFO	= 4,
	RestorationInfo_PCSCFSUBSCRIPTIONINFO	= 5,
}RestorationInfo_tags;

		//! Class Definition
		/*!		ClassName is RestorationInfo
		*/
class RestorationInfo : public DiameterBaseInterface
{
	private:

		bitset<6> mTagsPresent;

		bitset<6> mMandatoryAvpCheckVal;

		bitset<6> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mPath;

		OctetString*		mContact;

		Unsigned32*		mInitialCSeqSequenceNumber;

		OctetString*		mCallIDSIPHeader;






		SubscriptionInfo*	mSubscriptionInfoGrp;

		PCSCFSubscriptionInfo*	mPCSCFSubscriptionInfoGrp;

	public:
		RestorationInfo();

		RestorationInfo(const RestorationInfo &objRestorationInfo) {

		mTagsPresent = objRestorationInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objRestorationInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRestorationInfo.mMandatoryAvpSetVal;

		mTag = objRestorationInfo.mTag;

		mDecodeFlag = objRestorationInfo.mDecodeFlag;

		if(objRestorationInfo.mPath != NULL)
		mPath = new OctetString(*(objRestorationInfo.mPath));

		if(objRestorationInfo.mContact != NULL)
		mContact = new OctetString(*(objRestorationInfo.mContact));

		if(objRestorationInfo.mInitialCSeqSequenceNumber != NULL)
		mInitialCSeqSequenceNumber = new Unsigned32(*(objRestorationInfo.mInitialCSeqSequenceNumber));

		if(objRestorationInfo.mCallIDSIPHeader != NULL)
		mCallIDSIPHeader = new OctetString(*(objRestorationInfo.mCallIDSIPHeader));

		if(objRestorationInfo.mSubscriptionInfoGrp != NULL)
		 {
				 mSubscriptionInfoGrp =  new SubscriptionInfo(*objRestorationInfo.mSubscriptionInfoGrp);
		 }
		if(objRestorationInfo.mPCSCFSubscriptionInfoGrp != NULL)
		 {
				 mPCSCFSubscriptionInfoGrp =  new PCSCFSubscriptionInfo(*objRestorationInfo.mPCSCFSubscriptionInfoGrp);
		 }
		}

		void operator = (const RestorationInfo &objRestorationInfo) {

		mTagsPresent = objRestorationInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objRestorationInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRestorationInfo.mMandatoryAvpSetVal;

		mTag = objRestorationInfo.mTag;

		mDecodeFlag = objRestorationInfo.mDecodeFlag;

		if(objRestorationInfo.mPath != NULL)
		mPath = new OctetString(*(objRestorationInfo.mPath));

		if(objRestorationInfo.mContact != NULL)
		mContact = new OctetString(*(objRestorationInfo.mContact));

		if(objRestorationInfo.mInitialCSeqSequenceNumber != NULL)
		mInitialCSeqSequenceNumber = new Unsigned32(*(objRestorationInfo.mInitialCSeqSequenceNumber));

		if(objRestorationInfo.mCallIDSIPHeader != NULL)
		mCallIDSIPHeader = new OctetString(*(objRestorationInfo.mCallIDSIPHeader));

		if(objRestorationInfo.mSubscriptionInfoGrp != NULL)
		 {
				 mSubscriptionInfoGrp =  new SubscriptionInfo(*objRestorationInfo.mSubscriptionInfoGrp);
		 }
		if(objRestorationInfo.mPCSCFSubscriptionInfoGrp != NULL)
		 {
				 mPCSCFSubscriptionInfoGrp =  new PCSCFSubscriptionInfo(*objRestorationInfo.mPCSCFSubscriptionInfoGrp);
		 }
		}

		virtual ~RestorationInfo();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument Path for datatype RestorationInfo
		*/
		OctetString* setPath();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Path for datatype RestorationInfo
		*/
		void resetPath();

		//!Function to get values
		/*!		Function to get OctetString type of argument Path for datatype RestorationInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPath();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument Contact for datatype RestorationInfo
		*/
		OctetString* setContact();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Contact for datatype RestorationInfo
		*/
		void resetContact();

		//!Function to get values
		/*!		Function to get OctetString type of argument Contact for datatype RestorationInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getContact();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument InitialCSeqSequenceNumber for datatype RestorationInfo
		*/
		Unsigned32* setInitialCSeqSequenceNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument InitialCSeqSequenceNumber for datatype RestorationInfo
		*/
		void resetInitialCSeqSequenceNumber();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument InitialCSeqSequenceNumber for datatype RestorationInfo
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getInitialCSeqSequenceNumber();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument CallIDSIPHeader for datatype RestorationInfo
		*/
		OctetString* setCallIDSIPHeader();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CallIDSIPHeader for datatype RestorationInfo
		*/
		void resetCallIDSIPHeader();

		//!Function to get values
		/*!		Function to get OctetString type of argument CallIDSIPHeader for datatype RestorationInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getCallIDSIPHeader();

		SubscriptionInfo* getSubscriptionInfo();

		SubscriptionInfo* setSubscriptionInfo();

		void resetSubscriptionInfo();

		PCSCFSubscriptionInfo* getPCSCFSubscriptionInfo();

		PCSCFSubscriptionInfo* setPCSCFSubscriptionInfo();

		void resetPCSCFSubscriptionInfo();

		//! Function to Decode
		/*!		Function to Decode datatype RestorationInfo
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype RestorationInfo
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype RestorationInfo
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype RestorationInfo
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RestorationInfo
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
