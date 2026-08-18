#ifndef CX_PCSCFSUBSCRIPTIONINFO_H
#define CX_PCSCFSUBSCRIPTIONINFO_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace CX{
typedef enum _tags_PCSCFSubscriptionInfo
{
	PCSCFSubscriptionInfo_CALLIDSIPHEADER	= 0,
	PCSCFSubscriptionInfo_FROMSIPHEADER	= 1,
	PCSCFSubscriptionInfo_TOSIPHEADER	= 2,
	PCSCFSubscriptionInfo_CONTACT	= 3,
}PCSCFSubscriptionInfo_tags;

		//! Class Definition
		/*!		ClassName is PCSCFSubscriptionInfo
		*/
class PCSCFSubscriptionInfo : public DiameterBaseInterface
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

		OctetString*		mCallIDSIPHeader;

		OctetString*		mFromSIPHeader;

		OctetString*		mToSIPHeader;

		OctetString*		mContact;






	public:
		PCSCFSubscriptionInfo();

		PCSCFSubscriptionInfo(const PCSCFSubscriptionInfo &objPCSCFSubscriptionInfo) {

		mTagsPresent = objPCSCFSubscriptionInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objPCSCFSubscriptionInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPCSCFSubscriptionInfo.mMandatoryAvpSetVal;

		mTag = objPCSCFSubscriptionInfo.mTag;

		mDecodeFlag = objPCSCFSubscriptionInfo.mDecodeFlag;

		if(objPCSCFSubscriptionInfo.mCallIDSIPHeader != NULL)
		mCallIDSIPHeader = new OctetString(*(objPCSCFSubscriptionInfo.mCallIDSIPHeader));

		if(objPCSCFSubscriptionInfo.mFromSIPHeader != NULL)
		mFromSIPHeader = new OctetString(*(objPCSCFSubscriptionInfo.mFromSIPHeader));

		if(objPCSCFSubscriptionInfo.mToSIPHeader != NULL)
		mToSIPHeader = new OctetString(*(objPCSCFSubscriptionInfo.mToSIPHeader));

		if(objPCSCFSubscriptionInfo.mContact != NULL)
		mContact = new OctetString(*(objPCSCFSubscriptionInfo.mContact));

		}

		void operator = (const PCSCFSubscriptionInfo &objPCSCFSubscriptionInfo) {

		mTagsPresent = objPCSCFSubscriptionInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objPCSCFSubscriptionInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPCSCFSubscriptionInfo.mMandatoryAvpSetVal;

		mTag = objPCSCFSubscriptionInfo.mTag;

		mDecodeFlag = objPCSCFSubscriptionInfo.mDecodeFlag;

		if(objPCSCFSubscriptionInfo.mCallIDSIPHeader != NULL)
		mCallIDSIPHeader = new OctetString(*(objPCSCFSubscriptionInfo.mCallIDSIPHeader));

		if(objPCSCFSubscriptionInfo.mFromSIPHeader != NULL)
		mFromSIPHeader = new OctetString(*(objPCSCFSubscriptionInfo.mFromSIPHeader));

		if(objPCSCFSubscriptionInfo.mToSIPHeader != NULL)
		mToSIPHeader = new OctetString(*(objPCSCFSubscriptionInfo.mToSIPHeader));

		if(objPCSCFSubscriptionInfo.mContact != NULL)
		mContact = new OctetString(*(objPCSCFSubscriptionInfo.mContact));

		}

		virtual ~PCSCFSubscriptionInfo();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument CallIDSIPHeader for datatype PCSCFSubscriptionInfo
		*/
		OctetString* setCallIDSIPHeader();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CallIDSIPHeader for datatype PCSCFSubscriptionInfo
		*/
		void resetCallIDSIPHeader();

		//!Function to get values
		/*!		Function to get OctetString type of argument CallIDSIPHeader for datatype PCSCFSubscriptionInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getCallIDSIPHeader();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FromSIPHeader for datatype PCSCFSubscriptionInfo
		*/
		OctetString* setFromSIPHeader();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FromSIPHeader for datatype PCSCFSubscriptionInfo
		*/
		void resetFromSIPHeader();

		//!Function to get values
		/*!		Function to get OctetString type of argument FromSIPHeader for datatype PCSCFSubscriptionInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFromSIPHeader();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ToSIPHeader for datatype PCSCFSubscriptionInfo
		*/
		OctetString* setToSIPHeader();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ToSIPHeader for datatype PCSCFSubscriptionInfo
		*/
		void resetToSIPHeader();

		//!Function to get values
		/*!		Function to get OctetString type of argument ToSIPHeader for datatype PCSCFSubscriptionInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getToSIPHeader();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument Contact for datatype PCSCFSubscriptionInfo
		*/
		OctetString* setContact();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Contact for datatype PCSCFSubscriptionInfo
		*/
		void resetContact();

		//!Function to get values
		/*!		Function to get OctetString type of argument Contact for datatype PCSCFSubscriptionInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getContact();

		//! Function to Decode
		/*!		Function to Decode datatype PCSCFSubscriptionInfo
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype PCSCFSubscriptionInfo
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype PCSCFSubscriptionInfo
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype PCSCFSubscriptionInfo
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype PCSCFSubscriptionInfo
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
