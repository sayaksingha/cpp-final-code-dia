#ifndef CX_SIPAUTHDATAITEM_H
#define CX_SIPAUTHDATAITEM_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/SIPDigestAuthenticate.h"
using namespace std;

namespace CX{
typedef enum _tags_SIPAuthDataItem
{
	SIPAuthDataItem_SIPITEMNUMBER	= 0,
	SIPAuthDataItem_SIPAUTHENTICATIONSCHEME	= 1,
	SIPAuthDataItem_SIPAUTHENTICATE	= 2,
	SIPAuthDataItem_SIPAUTHORIZATION	= 3,
	SIPAuthDataItem_SIPAUTHENTICATIONCONTEXT	= 4,
	SIPAuthDataItem_CONFIDENTIALITYKEY	= 5,
	SIPAuthDataItem_INTEGRITYKEY	= 6,
	SIPAuthDataItem_SIPDIGESTAUTHENTICATE	= 7,
	SIPAuthDataItem_FRAMEDIPADDRESS	= 8,
	SIPAuthDataItem_FRAMEDIPV6PREFIX	= 9,
	SIPAuthDataItem_FRAMEDINTERFACEID	= 10,
	SIPAuthDataItem_LINEIDENTIFIER	= 11,
}SIPAuthDataItem_tags;

		//! Class Definition
		/*!		ClassName is SIPAuthDataItem
		*/
class SIPAuthDataItem : public DiameterBaseInterface
{
	private:

		bitset<12> mTagsPresent;

		bitset<12> mMandatoryAvpCheckVal;

		bitset<12> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		Unsigned32*		mSIPItemNumber;

		OctetString*		mSIPAuthenticationScheme;

		OctetString*		mSIPAuthenticate;

		OctetString*		mSIPAuthorization;

		OctetString*		mSIPAuthenticationContext;

		OctetString*		mConfidentialityKey;

		OctetString*		mIntegrityKey;

		OctetString*		mFramedIPAddress;

		OctetString*		mFramedIPv6Prefix;

		Unsigned64*		mFramedInterfaceId;

		list<OctetString*>* 		mLineIdentifierList;

		list<OctetString*>::iterator 		mLineIdentifierIterator;









		SIPDigestAuthenticate*	mSIPDigestAuthenticateGrp;





	public:
		SIPAuthDataItem();

		SIPAuthDataItem(const SIPAuthDataItem &objSIPAuthDataItem) {

		mTagsPresent = objSIPAuthDataItem.mTagsPresent;

		mMandatoryAvpCheckVal = objSIPAuthDataItem.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSIPAuthDataItem.mMandatoryAvpSetVal;

		mTag = objSIPAuthDataItem.mTag;

		mDecodeFlag = objSIPAuthDataItem.mDecodeFlag;

		if(objSIPAuthDataItem.mSIPItemNumber != NULL)
		mSIPItemNumber = new Unsigned32(*(objSIPAuthDataItem.mSIPItemNumber));

		if(objSIPAuthDataItem.mSIPAuthenticationScheme != NULL)
		mSIPAuthenticationScheme = new OctetString(*(objSIPAuthDataItem.mSIPAuthenticationScheme));

		if(objSIPAuthDataItem.mSIPAuthenticate != NULL)
		mSIPAuthenticate = new OctetString(*(objSIPAuthDataItem.mSIPAuthenticate));

		if(objSIPAuthDataItem.mSIPAuthorization != NULL)
		mSIPAuthorization = new OctetString(*(objSIPAuthDataItem.mSIPAuthorization));

		if(objSIPAuthDataItem.mSIPAuthenticationContext != NULL)
		mSIPAuthenticationContext = new OctetString(*(objSIPAuthDataItem.mSIPAuthenticationContext));

		if(objSIPAuthDataItem.mConfidentialityKey != NULL)
		mConfidentialityKey = new OctetString(*(objSIPAuthDataItem.mConfidentialityKey));

		if(objSIPAuthDataItem.mIntegrityKey != NULL)
		mIntegrityKey = new OctetString(*(objSIPAuthDataItem.mIntegrityKey));

		if(objSIPAuthDataItem.mSIPDigestAuthenticateGrp != NULL)
		 {
				 mSIPDigestAuthenticateGrp =  new SIPDigestAuthenticate(*objSIPAuthDataItem.mSIPDigestAuthenticateGrp);
		 }
		if(objSIPAuthDataItem.mFramedIPAddress != NULL)
		mFramedIPAddress = new OctetString(*(objSIPAuthDataItem.mFramedIPAddress));

		if(objSIPAuthDataItem.mFramedIPv6Prefix != NULL)
		mFramedIPv6Prefix = new OctetString(*(objSIPAuthDataItem.mFramedIPv6Prefix));

		if(objSIPAuthDataItem.mFramedInterfaceId != NULL)
		mFramedInterfaceId = new Unsigned64(*(objSIPAuthDataItem.mFramedInterfaceId));

		}

		void operator = (const SIPAuthDataItem &objSIPAuthDataItem) {

		mTagsPresent = objSIPAuthDataItem.mTagsPresent;

		mMandatoryAvpCheckVal = objSIPAuthDataItem.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSIPAuthDataItem.mMandatoryAvpSetVal;

		mTag = objSIPAuthDataItem.mTag;

		mDecodeFlag = objSIPAuthDataItem.mDecodeFlag;

		if(objSIPAuthDataItem.mSIPItemNumber != NULL)
		mSIPItemNumber = new Unsigned32(*(objSIPAuthDataItem.mSIPItemNumber));

		if(objSIPAuthDataItem.mSIPAuthenticationScheme != NULL)
		mSIPAuthenticationScheme = new OctetString(*(objSIPAuthDataItem.mSIPAuthenticationScheme));

		if(objSIPAuthDataItem.mSIPAuthenticate != NULL)
		mSIPAuthenticate = new OctetString(*(objSIPAuthDataItem.mSIPAuthenticate));

		if(objSIPAuthDataItem.mSIPAuthorization != NULL)
		mSIPAuthorization = new OctetString(*(objSIPAuthDataItem.mSIPAuthorization));

		if(objSIPAuthDataItem.mSIPAuthenticationContext != NULL)
		mSIPAuthenticationContext = new OctetString(*(objSIPAuthDataItem.mSIPAuthenticationContext));

		if(objSIPAuthDataItem.mConfidentialityKey != NULL)
		mConfidentialityKey = new OctetString(*(objSIPAuthDataItem.mConfidentialityKey));

		if(objSIPAuthDataItem.mIntegrityKey != NULL)
		mIntegrityKey = new OctetString(*(objSIPAuthDataItem.mIntegrityKey));

		if(objSIPAuthDataItem.mSIPDigestAuthenticateGrp != NULL)
		 {
				 mSIPDigestAuthenticateGrp =  new SIPDigestAuthenticate(*objSIPAuthDataItem.mSIPDigestAuthenticateGrp);
		 }
		if(objSIPAuthDataItem.mFramedIPAddress != NULL)
		mFramedIPAddress = new OctetString(*(objSIPAuthDataItem.mFramedIPAddress));

		if(objSIPAuthDataItem.mFramedIPv6Prefix != NULL)
		mFramedIPv6Prefix = new OctetString(*(objSIPAuthDataItem.mFramedIPv6Prefix));

		if(objSIPAuthDataItem.mFramedInterfaceId != NULL)
		mFramedInterfaceId = new Unsigned64(*(objSIPAuthDataItem.mFramedInterfaceId));

		}

		virtual ~SIPAuthDataItem();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument SIPItemNumber for datatype SIPAuthDataItem
		*/
		Unsigned32* setSIPItemNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SIPItemNumber for datatype SIPAuthDataItem
		*/
		void resetSIPItemNumber();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument SIPItemNumber for datatype SIPAuthDataItem
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getSIPItemNumber();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SIPAuthenticationScheme for datatype SIPAuthDataItem
		*/
		OctetString* setSIPAuthenticationScheme();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SIPAuthenticationScheme for datatype SIPAuthDataItem
		*/
		void resetSIPAuthenticationScheme();

		//!Function to get values
		/*!		Function to get OctetString type of argument SIPAuthenticationScheme for datatype SIPAuthDataItem
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSIPAuthenticationScheme();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SIPAuthenticate for datatype SIPAuthDataItem
		*/
		OctetString* setSIPAuthenticate();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SIPAuthenticate for datatype SIPAuthDataItem
		*/
		void resetSIPAuthenticate();

		//!Function to get values
		/*!		Function to get OctetString type of argument SIPAuthenticate for datatype SIPAuthDataItem
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSIPAuthenticate();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SIPAuthorization for datatype SIPAuthDataItem
		*/
		OctetString* setSIPAuthorization();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SIPAuthorization for datatype SIPAuthDataItem
		*/
		void resetSIPAuthorization();

		//!Function to get values
		/*!		Function to get OctetString type of argument SIPAuthorization for datatype SIPAuthDataItem
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSIPAuthorization();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SIPAuthenticationContext for datatype SIPAuthDataItem
		*/
		OctetString* setSIPAuthenticationContext();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SIPAuthenticationContext for datatype SIPAuthDataItem
		*/
		void resetSIPAuthenticationContext();

		//!Function to get values
		/*!		Function to get OctetString type of argument SIPAuthenticationContext for datatype SIPAuthDataItem
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSIPAuthenticationContext();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ConfidentialityKey for datatype SIPAuthDataItem
		*/
		OctetString* setConfidentialityKey();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ConfidentialityKey for datatype SIPAuthDataItem
		*/
		void resetConfidentialityKey();

		//!Function to get values
		/*!		Function to get OctetString type of argument ConfidentialityKey for datatype SIPAuthDataItem
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getConfidentialityKey();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument IntegrityKey for datatype SIPAuthDataItem
		*/
		OctetString* setIntegrityKey();

		//! Function to reset 
		/*!		Function to reset NULL type of argument IntegrityKey for datatype SIPAuthDataItem
		*/
		void resetIntegrityKey();

		//!Function to get values
		/*!		Function to get OctetString type of argument IntegrityKey for datatype SIPAuthDataItem
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getIntegrityKey();

		SIPDigestAuthenticate* getSIPDigestAuthenticate();

		SIPDigestAuthenticate* setSIPDigestAuthenticate();

		void resetSIPDigestAuthenticate();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FramedIPAddress for datatype SIPAuthDataItem
		*/
		OctetString* setFramedIPAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FramedIPAddress for datatype SIPAuthDataItem
		*/
		void resetFramedIPAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument FramedIPAddress for datatype SIPAuthDataItem
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFramedIPAddress();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FramedIPv6Prefix for datatype SIPAuthDataItem
		*/
		OctetString* setFramedIPv6Prefix();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FramedIPv6Prefix for datatype SIPAuthDataItem
		*/
		void resetFramedIPv6Prefix();

		//!Function to get values
		/*!		Function to get OctetString type of argument FramedIPv6Prefix for datatype SIPAuthDataItem
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFramedIPv6Prefix();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument FramedInterfaceId for datatype SIPAuthDataItem
		*/
		Unsigned64* setFramedInterfaceId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FramedInterfaceId for datatype SIPAuthDataItem
		*/
		void resetFramedInterfaceId();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument FramedInterfaceId for datatype SIPAuthDataItem
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getFramedInterfaceId();

		list<OctetString*>* getLineIdentifierList();

		list<OctetString*>* setLineIdentifierList();

		void resetLineIdentifierList();

		//! Function to Decode
		/*!		Function to Decode datatype SIPAuthDataItem
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype SIPAuthDataItem
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SIPAuthDataItem
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SIPAuthDataItem
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SIPAuthDataItem
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
