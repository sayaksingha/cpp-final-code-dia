#ifndef SH_USERIDENTITY_H
#define SH_USERIDENTITY_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SH{
typedef enum _tags_UserIdentity
{
	UserIdentity_PUBLICIDENTITY	= 0,
	UserIdentity_MSISDN	= 1,
	UserIdentity_EXTERNALIDENTIFIER	= 2,
}UserIdentity_tags;

		//! Class Definition
		/*!		ClassName is UserIdentity
		*/
class UserIdentity : public DiameterBaseInterface
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

		OctetString*		mPublicIdentity;

		OctetString*		mMSISDN;

		OctetString*		mExternalIdentifier;





	public:
		UserIdentity();

		UserIdentity(const UserIdentity &objUserIdentity) {

		mTagsPresent = objUserIdentity.mTagsPresent;

		mMandatoryAvpCheckVal = objUserIdentity.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserIdentity.mMandatoryAvpSetVal;

		mTag = objUserIdentity.mTag;

		mDecodeFlag = objUserIdentity.mDecodeFlag;

		if(objUserIdentity.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objUserIdentity.mPublicIdentity));

		if(objUserIdentity.mMSISDN != NULL)
		mMSISDN = new OctetString(*(objUserIdentity.mMSISDN));

		if(objUserIdentity.mExternalIdentifier != NULL)
		mExternalIdentifier = new OctetString(*(objUserIdentity.mExternalIdentifier));

		}

		void operator = (const UserIdentity &objUserIdentity) {

		mTagsPresent = objUserIdentity.mTagsPresent;

		mMandatoryAvpCheckVal = objUserIdentity.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserIdentity.mMandatoryAvpSetVal;

		mTag = objUserIdentity.mTag;

		mDecodeFlag = objUserIdentity.mDecodeFlag;

		if(objUserIdentity.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objUserIdentity.mPublicIdentity));

		if(objUserIdentity.mMSISDN != NULL)
		mMSISDN = new OctetString(*(objUserIdentity.mMSISDN));

		if(objUserIdentity.mExternalIdentifier != NULL)
		mExternalIdentifier = new OctetString(*(objUserIdentity.mExternalIdentifier));

		}

		virtual ~UserIdentity();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PublicIdentity for datatype UserIdentity
		*/
		OctetString* setPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PublicIdentity for datatype UserIdentity
		*/
		void resetPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument PublicIdentity for datatype UserIdentity
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MSISDN for datatype UserIdentity
		*/
		OctetString* setMSISDN();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MSISDN for datatype UserIdentity
		*/
		void resetMSISDN();

		//!Function to get values
		/*!		Function to get OctetString type of argument MSISDN for datatype UserIdentity
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMSISDN();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ExternalIdentifier for datatype UserIdentity
		*/
		OctetString* setExternalIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExternalIdentifier for datatype UserIdentity
		*/
		void resetExternalIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument ExternalIdentifier for datatype UserIdentity
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getExternalIdentifier();

		//! Function to Decode
		/*!		Function to Decode datatype UserIdentity
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype UserIdentity
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UserIdentity
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UserIdentity
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UserIdentity
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
