#ifndef SD_REDIRECTINFORMATION_H
#define SD_REDIRECTINFORMATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/RedirectSupport.h"
#include "sd/include/RedirectAddressType.h"
using namespace std;

namespace SD{
typedef enum _tags_RedirectInformation
{
	RedirectInformation_REDIRECTSUPPORT	= 0,
	RedirectInformation_REDIRECTADDRESSTYPE	= 1,
	RedirectInformation_REDIRECTSERVERADDRESS	= 2,
}RedirectInformation_tags;

		//! Class Definition
		/*!		ClassName is RedirectInformation
		*/
class RedirectInformation : public DiameterBaseInterface
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

		RedirectSupport*		mRedirectSupport;

		RedirectAddressType*		mRedirectAddressType;

		OctetString*		mRedirectServerAddress;





	public:
		RedirectInformation();

		RedirectInformation(const RedirectInformation &objRedirectInformation) {

		mTagsPresent = objRedirectInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objRedirectInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRedirectInformation.mMandatoryAvpSetVal;

		mTag = objRedirectInformation.mTag;

		mDecodeFlag = objRedirectInformation.mDecodeFlag;

		if(objRedirectInformation.mRedirectSupport != NULL)
		mRedirectSupport = new RedirectSupport(*(objRedirectInformation.mRedirectSupport));

		if(objRedirectInformation.mRedirectAddressType != NULL)
		mRedirectAddressType = new RedirectAddressType(*(objRedirectInformation.mRedirectAddressType));

		if(objRedirectInformation.mRedirectServerAddress != NULL)
		mRedirectServerAddress = new OctetString(*(objRedirectInformation.mRedirectServerAddress));

		}

		void operator = (const RedirectInformation &objRedirectInformation) {

		mTagsPresent = objRedirectInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objRedirectInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRedirectInformation.mMandatoryAvpSetVal;

		mTag = objRedirectInformation.mTag;

		mDecodeFlag = objRedirectInformation.mDecodeFlag;

		if(objRedirectInformation.mRedirectSupport != NULL)
		mRedirectSupport = new RedirectSupport(*(objRedirectInformation.mRedirectSupport));

		if(objRedirectInformation.mRedirectAddressType != NULL)
		mRedirectAddressType = new RedirectAddressType(*(objRedirectInformation.mRedirectAddressType));

		if(objRedirectInformation.mRedirectServerAddress != NULL)
		mRedirectServerAddress = new OctetString(*(objRedirectInformation.mRedirectServerAddress));

		}

		virtual ~RedirectInformation();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RedirectSupport for datatype RedirectInformation
		*/
		RedirectSupport* setRedirectSupport();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectSupport for datatype RedirectInformation
		*/
		void resetRedirectSupport();

		//!Function to get values
		/*!		Function to get RedirectSupport type of argument RedirectSupport for datatype RedirectInformation
		Throws exception of which type and Summary of Exception
		*/
		RedirectSupport* getRedirectSupport();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RedirectAddressType for datatype RedirectInformation
		*/
		RedirectAddressType* setRedirectAddressType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectAddressType for datatype RedirectInformation
		*/
		void resetRedirectAddressType();

		//!Function to get values
		/*!		Function to get RedirectAddressType type of argument RedirectAddressType for datatype RedirectInformation
		Throws exception of which type and Summary of Exception
		*/
		RedirectAddressType* getRedirectAddressType();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument RedirectServerAddress for datatype RedirectInformation
		*/
		OctetString* setRedirectServerAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectServerAddress for datatype RedirectInformation
		*/
		void resetRedirectServerAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument RedirectServerAddress for datatype RedirectInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getRedirectServerAddress();

		//! Function to Decode
		/*!		Function to Decode datatype RedirectInformation
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype RedirectInformation
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype RedirectInformation
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype RedirectInformation
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RedirectInformation
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
