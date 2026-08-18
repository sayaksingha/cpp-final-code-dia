#ifndef CX_SUBSCRIPTIONINFO_H
#define CX_SUBSCRIPTIONINFO_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace CX{
typedef enum _tags_SubscriptionInfo
{
	SubscriptionInfo_CALLIDSIPHEADER	= 0,
	SubscriptionInfo_FROMSIPHEADER	= 1,
	SubscriptionInfo_TOSIPHEADER	= 2,
	SubscriptionInfo_RECORDROUTE	= 3,
	SubscriptionInfo_CONTACT	= 4,
}SubscriptionInfo_tags;

		//! Class Definition
		/*!		ClassName is SubscriptionInfo
		*/
class SubscriptionInfo : public DiameterBaseInterface
{
	private:

		bitset<5> mTagsPresent;

		bitset<5> mMandatoryAvpCheckVal;

		bitset<5> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mCallIDSIPHeader;

		OctetString*		mFromSIPHeader;

		OctetString*		mToSIPHeader;

		OctetString*		mRecordRoute;

		OctetString*		mContact;







	public:
		SubscriptionInfo();

		SubscriptionInfo(const SubscriptionInfo &objSubscriptionInfo) {

		mTagsPresent = objSubscriptionInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objSubscriptionInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSubscriptionInfo.mMandatoryAvpSetVal;

		mTag = objSubscriptionInfo.mTag;

		mDecodeFlag = objSubscriptionInfo.mDecodeFlag;

		if(objSubscriptionInfo.mCallIDSIPHeader != NULL)
		mCallIDSIPHeader = new OctetString(*(objSubscriptionInfo.mCallIDSIPHeader));

		if(objSubscriptionInfo.mFromSIPHeader != NULL)
		mFromSIPHeader = new OctetString(*(objSubscriptionInfo.mFromSIPHeader));

		if(objSubscriptionInfo.mToSIPHeader != NULL)
		mToSIPHeader = new OctetString(*(objSubscriptionInfo.mToSIPHeader));

		if(objSubscriptionInfo.mRecordRoute != NULL)
		mRecordRoute = new OctetString(*(objSubscriptionInfo.mRecordRoute));

		if(objSubscriptionInfo.mContact != NULL)
		mContact = new OctetString(*(objSubscriptionInfo.mContact));

		}

		void operator = (const SubscriptionInfo &objSubscriptionInfo) {

		mTagsPresent = objSubscriptionInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objSubscriptionInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSubscriptionInfo.mMandatoryAvpSetVal;

		mTag = objSubscriptionInfo.mTag;

		mDecodeFlag = objSubscriptionInfo.mDecodeFlag;

		if(objSubscriptionInfo.mCallIDSIPHeader != NULL)
		mCallIDSIPHeader = new OctetString(*(objSubscriptionInfo.mCallIDSIPHeader));

		if(objSubscriptionInfo.mFromSIPHeader != NULL)
		mFromSIPHeader = new OctetString(*(objSubscriptionInfo.mFromSIPHeader));

		if(objSubscriptionInfo.mToSIPHeader != NULL)
		mToSIPHeader = new OctetString(*(objSubscriptionInfo.mToSIPHeader));

		if(objSubscriptionInfo.mRecordRoute != NULL)
		mRecordRoute = new OctetString(*(objSubscriptionInfo.mRecordRoute));

		if(objSubscriptionInfo.mContact != NULL)
		mContact = new OctetString(*(objSubscriptionInfo.mContact));

		}

		virtual ~SubscriptionInfo();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument CallIDSIPHeader for datatype SubscriptionInfo
		*/
		OctetString* setCallIDSIPHeader();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CallIDSIPHeader for datatype SubscriptionInfo
		*/
		void resetCallIDSIPHeader();

		//!Function to get values
		/*!		Function to get OctetString type of argument CallIDSIPHeader for datatype SubscriptionInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getCallIDSIPHeader();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FromSIPHeader for datatype SubscriptionInfo
		*/
		OctetString* setFromSIPHeader();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FromSIPHeader for datatype SubscriptionInfo
		*/
		void resetFromSIPHeader();

		//!Function to get values
		/*!		Function to get OctetString type of argument FromSIPHeader for datatype SubscriptionInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFromSIPHeader();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ToSIPHeader for datatype SubscriptionInfo
		*/
		OctetString* setToSIPHeader();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ToSIPHeader for datatype SubscriptionInfo
		*/
		void resetToSIPHeader();

		//!Function to get values
		/*!		Function to get OctetString type of argument ToSIPHeader for datatype SubscriptionInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getToSIPHeader();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument RecordRoute for datatype SubscriptionInfo
		*/
		OctetString* setRecordRoute();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RecordRoute for datatype SubscriptionInfo
		*/
		void resetRecordRoute();

		//!Function to get values
		/*!		Function to get OctetString type of argument RecordRoute for datatype SubscriptionInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getRecordRoute();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument Contact for datatype SubscriptionInfo
		*/
		OctetString* setContact();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Contact for datatype SubscriptionInfo
		*/
		void resetContact();

		//!Function to get values
		/*!		Function to get OctetString type of argument Contact for datatype SubscriptionInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getContact();

		//! Function to Decode
		/*!		Function to Decode datatype SubscriptionInfo
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype SubscriptionInfo
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SubscriptionInfo
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SubscriptionInfo
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SubscriptionInfo
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
