#ifndef CX_SIPDIGESTAUTHENTICATE_H
#define CX_SIPDIGESTAUTHENTICATE_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace CX{
typedef enum _tags_SIPDigestAuthenticate
{
	SIPDigestAuthenticate_DIGESTREALM	= 0,
	SIPDigestAuthenticate_DIGESTALGORITHM	= 1,
	SIPDigestAuthenticate_DIGESTQOP	= 2,
	SIPDigestAuthenticate_DIGESTHA1	= 3,
	SIPDigestAuthenticate_ALTERNATEDIGESTALGORITHM	= 4,
	SIPDigestAuthenticate_ALTERNATEDIGESTHA1	= 5,
}SIPDigestAuthenticate_tags;

		//! Class Definition
		/*!		ClassName is SIPDigestAuthenticate
		*/
class SIPDigestAuthenticate : public DiameterBaseInterface
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

		OctetString*		mDigestRealm;

		OctetString*		mDigestAlgorithm;

		OctetString*		mDigestQoP;

		OctetString*		mDigestHA1;

		OctetString*		mAlternateDigestAlgorithm;

		OctetString*		mAlternateDigestHA1;








	public:
		SIPDigestAuthenticate();

		SIPDigestAuthenticate(const SIPDigestAuthenticate &objSIPDigestAuthenticate) {

		mTagsPresent = objSIPDigestAuthenticate.mTagsPresent;

		mMandatoryAvpCheckVal = objSIPDigestAuthenticate.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSIPDigestAuthenticate.mMandatoryAvpSetVal;

		mTag = objSIPDigestAuthenticate.mTag;

		mDecodeFlag = objSIPDigestAuthenticate.mDecodeFlag;

		if(objSIPDigestAuthenticate.mDigestRealm != NULL)
		mDigestRealm = new OctetString(*(objSIPDigestAuthenticate.mDigestRealm));

		if(objSIPDigestAuthenticate.mDigestAlgorithm != NULL)
		mDigestAlgorithm = new OctetString(*(objSIPDigestAuthenticate.mDigestAlgorithm));

		if(objSIPDigestAuthenticate.mDigestQoP != NULL)
		mDigestQoP = new OctetString(*(objSIPDigestAuthenticate.mDigestQoP));

		if(objSIPDigestAuthenticate.mDigestHA1 != NULL)
		mDigestHA1 = new OctetString(*(objSIPDigestAuthenticate.mDigestHA1));

		if(objSIPDigestAuthenticate.mAlternateDigestAlgorithm != NULL)
		mAlternateDigestAlgorithm = new OctetString(*(objSIPDigestAuthenticate.mAlternateDigestAlgorithm));

		if(objSIPDigestAuthenticate.mAlternateDigestHA1 != NULL)
		mAlternateDigestHA1 = new OctetString(*(objSIPDigestAuthenticate.mAlternateDigestHA1));

		}

		void operator = (const SIPDigestAuthenticate &objSIPDigestAuthenticate) {

		mTagsPresent = objSIPDigestAuthenticate.mTagsPresent;

		mMandatoryAvpCheckVal = objSIPDigestAuthenticate.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSIPDigestAuthenticate.mMandatoryAvpSetVal;

		mTag = objSIPDigestAuthenticate.mTag;

		mDecodeFlag = objSIPDigestAuthenticate.mDecodeFlag;

		if(objSIPDigestAuthenticate.mDigestRealm != NULL)
		mDigestRealm = new OctetString(*(objSIPDigestAuthenticate.mDigestRealm));

		if(objSIPDigestAuthenticate.mDigestAlgorithm != NULL)
		mDigestAlgorithm = new OctetString(*(objSIPDigestAuthenticate.mDigestAlgorithm));

		if(objSIPDigestAuthenticate.mDigestQoP != NULL)
		mDigestQoP = new OctetString(*(objSIPDigestAuthenticate.mDigestQoP));

		if(objSIPDigestAuthenticate.mDigestHA1 != NULL)
		mDigestHA1 = new OctetString(*(objSIPDigestAuthenticate.mDigestHA1));

		if(objSIPDigestAuthenticate.mAlternateDigestAlgorithm != NULL)
		mAlternateDigestAlgorithm = new OctetString(*(objSIPDigestAuthenticate.mAlternateDigestAlgorithm));

		if(objSIPDigestAuthenticate.mAlternateDigestHA1 != NULL)
		mAlternateDigestHA1 = new OctetString(*(objSIPDigestAuthenticate.mAlternateDigestHA1));

		}

		virtual ~SIPDigestAuthenticate();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DigestRealm for datatype SIPDigestAuthenticate
		*/
		OctetString* setDigestRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DigestRealm for datatype SIPDigestAuthenticate
		*/
		void resetDigestRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DigestRealm for datatype SIPDigestAuthenticate
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDigestRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DigestAlgorithm for datatype SIPDigestAuthenticate
		*/
		OctetString* setDigestAlgorithm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DigestAlgorithm for datatype SIPDigestAuthenticate
		*/
		void resetDigestAlgorithm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DigestAlgorithm for datatype SIPDigestAuthenticate
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDigestAlgorithm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DigestQoP for datatype SIPDigestAuthenticate
		*/
		OctetString* setDigestQoP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DigestQoP for datatype SIPDigestAuthenticate
		*/
		void resetDigestQoP();

		//!Function to get values
		/*!		Function to get OctetString type of argument DigestQoP for datatype SIPDigestAuthenticate
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDigestQoP();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DigestHA1 for datatype SIPDigestAuthenticate
		*/
		OctetString* setDigestHA1();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DigestHA1 for datatype SIPDigestAuthenticate
		*/
		void resetDigestHA1();

		//!Function to get values
		/*!		Function to get OctetString type of argument DigestHA1 for datatype SIPDigestAuthenticate
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDigestHA1();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument AlternateDigestAlgorithm for datatype SIPDigestAuthenticate
		*/
		OctetString* setAlternateDigestAlgorithm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AlternateDigestAlgorithm for datatype SIPDigestAuthenticate
		*/
		void resetAlternateDigestAlgorithm();

		//!Function to get values
		/*!		Function to get OctetString type of argument AlternateDigestAlgorithm for datatype SIPDigestAuthenticate
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getAlternateDigestAlgorithm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument AlternateDigestHA1 for datatype SIPDigestAuthenticate
		*/
		OctetString* setAlternateDigestHA1();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AlternateDigestHA1 for datatype SIPDigestAuthenticate
		*/
		void resetAlternateDigestHA1();

		//!Function to get values
		/*!		Function to get OctetString type of argument AlternateDigestHA1 for datatype SIPDigestAuthenticate
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getAlternateDigestHA1();

		//! Function to Decode
		/*!		Function to Decode datatype SIPDigestAuthenticate
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype SIPDigestAuthenticate
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SIPDigestAuthenticate
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SIPDigestAuthenticate
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SIPDigestAuthenticate
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
