#ifndef SD_REDIRECTSERVER_H
#define SD_REDIRECTSERVER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/RedirectAddressType.h"
using namespace std;

namespace SD{
typedef enum _tags_RedirectServer
{
	RedirectServer_REDIRECTADDRESSTYPE	= 0,
	RedirectServer_REDIRECTSERVERADDRESS	= 1,
}RedirectServer_tags;

		//! Class Definition
		/*!		ClassName is RedirectServer
		*/
class RedirectServer : public DiameterBaseInterface
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

		RedirectAddressType*		mRedirectAddressType;

		OctetString*		mRedirectServerAddress;




	public:
		RedirectServer();

		RedirectServer(const RedirectServer &objRedirectServer) {

		mTagsPresent = objRedirectServer.mTagsPresent;

		mMandatoryAvpCheckVal = objRedirectServer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRedirectServer.mMandatoryAvpSetVal;

		mTag = objRedirectServer.mTag;

		mDecodeFlag = objRedirectServer.mDecodeFlag;

		if(objRedirectServer.mRedirectAddressType != NULL)
		mRedirectAddressType = new RedirectAddressType(*(objRedirectServer.mRedirectAddressType));

		if(objRedirectServer.mRedirectServerAddress != NULL)
		mRedirectServerAddress = new OctetString(*(objRedirectServer.mRedirectServerAddress));

		}

		void operator = (const RedirectServer &objRedirectServer) {

		mTagsPresent = objRedirectServer.mTagsPresent;

		mMandatoryAvpCheckVal = objRedirectServer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRedirectServer.mMandatoryAvpSetVal;

		mTag = objRedirectServer.mTag;

		mDecodeFlag = objRedirectServer.mDecodeFlag;

		if(objRedirectServer.mRedirectAddressType != NULL)
		mRedirectAddressType = new RedirectAddressType(*(objRedirectServer.mRedirectAddressType));

		if(objRedirectServer.mRedirectServerAddress != NULL)
		mRedirectServerAddress = new OctetString(*(objRedirectServer.mRedirectServerAddress));

		}

		virtual ~RedirectServer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RedirectAddressType for datatype RedirectServer
		*/
		RedirectAddressType* setRedirectAddressType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectAddressType for datatype RedirectServer
		*/
		void resetRedirectAddressType();

		//!Function to get values
		/*!		Function to get RedirectAddressType type of argument RedirectAddressType for datatype RedirectServer
		Throws exception of which type and Summary of Exception
		*/
		RedirectAddressType* getRedirectAddressType();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument RedirectServerAddress for datatype RedirectServer
		*/
		OctetString* setRedirectServerAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectServerAddress for datatype RedirectServer
		*/
		void resetRedirectServerAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument RedirectServerAddress for datatype RedirectServer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getRedirectServerAddress();

		//! Function to Decode
		/*!		Function to Decode datatype RedirectServer
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype RedirectServer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype RedirectServer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype RedirectServer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RedirectServer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
