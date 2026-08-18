#ifndef CX_IDENTITYWITHEMERGENCYREGISTRATION_H
#define CX_IDENTITYWITHEMERGENCYREGISTRATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace CX{
typedef enum _tags_IdentitywithEmergencyRegistration
{
	IdentitywithEmergencyRegistration_USERNAME	= 0,
	IdentitywithEmergencyRegistration_PUBLICIDENTITY	= 1,
}IdentitywithEmergencyRegistration_tags;

		//! Class Definition
		/*!		ClassName is IdentitywithEmergencyRegistration
		*/
class IdentitywithEmergencyRegistration : public DiameterBaseInterface
{
	private:

		bitset<2> mTagsPresent;

		bitset<2> mMandatoryAvpCheckVal;

		bitset<2> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mUserName;

		OctetString*		mPublicIdentity;




	public:
		IdentitywithEmergencyRegistration();

		IdentitywithEmergencyRegistration(const IdentitywithEmergencyRegistration &objIdentitywithEmergencyRegistration) {

		mTagsPresent = objIdentitywithEmergencyRegistration.mTagsPresent;

		mMandatoryAvpCheckVal = objIdentitywithEmergencyRegistration.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objIdentitywithEmergencyRegistration.mMandatoryAvpSetVal;

		mTag = objIdentitywithEmergencyRegistration.mTag;

		mDecodeFlag = objIdentitywithEmergencyRegistration.mDecodeFlag;

		if(objIdentitywithEmergencyRegistration.mUserName != NULL)
		mUserName = new OctetString(*(objIdentitywithEmergencyRegistration.mUserName));

		if(objIdentitywithEmergencyRegistration.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objIdentitywithEmergencyRegistration.mPublicIdentity));

		}

		void operator = (const IdentitywithEmergencyRegistration &objIdentitywithEmergencyRegistration) {

		mTagsPresent = objIdentitywithEmergencyRegistration.mTagsPresent;

		mMandatoryAvpCheckVal = objIdentitywithEmergencyRegistration.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objIdentitywithEmergencyRegistration.mMandatoryAvpSetVal;

		mTag = objIdentitywithEmergencyRegistration.mTag;

		mDecodeFlag = objIdentitywithEmergencyRegistration.mDecodeFlag;

		if(objIdentitywithEmergencyRegistration.mUserName != NULL)
		mUserName = new OctetString(*(objIdentitywithEmergencyRegistration.mUserName));

		if(objIdentitywithEmergencyRegistration.mPublicIdentity != NULL)
		mPublicIdentity = new OctetString(*(objIdentitywithEmergencyRegistration.mPublicIdentity));

		}

		virtual ~IdentitywithEmergencyRegistration();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype IdentitywithEmergencyRegistration
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype IdentitywithEmergencyRegistration
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype IdentitywithEmergencyRegistration
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PublicIdentity for datatype IdentitywithEmergencyRegistration
		*/
		OctetString* setPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PublicIdentity for datatype IdentitywithEmergencyRegistration
		*/
		void resetPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument PublicIdentity for datatype IdentitywithEmergencyRegistration
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPublicIdentity();

		//! Function to Decode
		/*!		Function to Decode datatype IdentitywithEmergencyRegistration
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype IdentitywithEmergencyRegistration
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype IdentitywithEmergencyRegistration
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype IdentitywithEmergencyRegistration
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype IdentitywithEmergencyRegistration
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
