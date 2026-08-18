#ifndef RX_CALLEEINFORMATION_H
#define RX_CALLEEINFORMATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace RX{
typedef enum _tags_CalleeInformation
{
	CalleeInformation_CALLEDPARTYADDRESS	= 0,
	CalleeInformation_REQUESTEDPARTYADDRESS	= 1,
	CalleeInformation_CALLEDASSERTEDIDENTITY	= 2,
}CalleeInformation_tags;

		//! Class Definition
		/*!		ClassName is CalleeInformation
		*/
class CalleeInformation : public DiameterBaseInterface
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

		OctetString*		mCalledPartyAddress;

		OctetString*		mRequestedPartyAddress;

		OctetString*		mCalledAssertedIdentity;





	public:
		CalleeInformation();

		CalleeInformation(const CalleeInformation &objCalleeInformation) {

		mTagsPresent = objCalleeInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objCalleeInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCalleeInformation.mMandatoryAvpSetVal;

		mTag = objCalleeInformation.mTag;

		mDecodeFlag = objCalleeInformation.mDecodeFlag;

		if(objCalleeInformation.mCalledPartyAddress != NULL)
		mCalledPartyAddress = new OctetString(*(objCalleeInformation.mCalledPartyAddress));

		if(objCalleeInformation.mRequestedPartyAddress != NULL)
		mRequestedPartyAddress = new OctetString(*(objCalleeInformation.mRequestedPartyAddress));

		if(objCalleeInformation.mCalledAssertedIdentity != NULL)
		mCalledAssertedIdentity = new OctetString(*(objCalleeInformation.mCalledAssertedIdentity));

		}

		void operator = (const CalleeInformation &objCalleeInformation) {

		mTagsPresent = objCalleeInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objCalleeInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCalleeInformation.mMandatoryAvpSetVal;

		mTag = objCalleeInformation.mTag;

		mDecodeFlag = objCalleeInformation.mDecodeFlag;

		if(objCalleeInformation.mCalledPartyAddress != NULL)
		mCalledPartyAddress = new OctetString(*(objCalleeInformation.mCalledPartyAddress));

		if(objCalleeInformation.mRequestedPartyAddress != NULL)
		mRequestedPartyAddress = new OctetString(*(objCalleeInformation.mRequestedPartyAddress));

		if(objCalleeInformation.mCalledAssertedIdentity != NULL)
		mCalledAssertedIdentity = new OctetString(*(objCalleeInformation.mCalledAssertedIdentity));

		}

		virtual ~CalleeInformation();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument CalledPartyAddress for datatype CalleeInformation
		*/
		OctetString* setCalledPartyAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CalledPartyAddress for datatype CalleeInformation
		*/
		void resetCalledPartyAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument CalledPartyAddress for datatype CalleeInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getCalledPartyAddress();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument RequestedPartyAddress for datatype CalleeInformation
		*/
		OctetString* setRequestedPartyAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RequestedPartyAddress for datatype CalleeInformation
		*/
		void resetRequestedPartyAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument RequestedPartyAddress for datatype CalleeInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getRequestedPartyAddress();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument CalledAssertedIdentity for datatype CalleeInformation
		*/
		OctetString* setCalledAssertedIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CalledAssertedIdentity for datatype CalleeInformation
		*/
		void resetCalledAssertedIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument CalledAssertedIdentity for datatype CalleeInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getCalledAssertedIdentity();

		//! Function to Decode
		/*!		Function to Decode datatype CalleeInformation
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype CalleeInformation
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype CalleeInformation
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype CalleeInformation
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CalleeInformation
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
