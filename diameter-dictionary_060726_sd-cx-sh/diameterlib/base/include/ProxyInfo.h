#ifndef BASE_PROXYINFO_H
#define BASE_PROXYINFO_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace BASE{
typedef enum _tags_ProxyInfo
{
	ProxyInfo_PROXYHOST	= 0,
	ProxyInfo_PROXYSTATE	= 1,
}ProxyInfo_tags;

		//! Class Definition
		/*!		ClassName is ProxyInfo
		*/
class ProxyInfo : public DiameterBaseInterface
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

		OctetString*		mProxyHost;

		OctetString*		mProxyState;




	public:
		ProxyInfo();

		ProxyInfo(const ProxyInfo &objProxyInfo) {

		mTagsPresent = objProxyInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objProxyInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objProxyInfo.mMandatoryAvpSetVal;

		mTag = objProxyInfo.mTag;

		mDecodeFlag = objProxyInfo.mDecodeFlag;

		if(objProxyInfo.mProxyHost != NULL)
		mProxyHost = new OctetString(*(objProxyInfo.mProxyHost));

		if(objProxyInfo.mProxyState != NULL)
		mProxyState = new OctetString(*(objProxyInfo.mProxyState));

		}

		void operator = (const ProxyInfo &objProxyInfo) {

		mTagsPresent = objProxyInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objProxyInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objProxyInfo.mMandatoryAvpSetVal;

		mTag = objProxyInfo.mTag;

		mDecodeFlag = objProxyInfo.mDecodeFlag;

		if(objProxyInfo.mProxyHost != NULL)
		mProxyHost = new OctetString(*(objProxyInfo.mProxyHost));

		if(objProxyInfo.mProxyState != NULL)
		mProxyState = new OctetString(*(objProxyInfo.mProxyState));

		}

		virtual ~ProxyInfo();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ProxyHost for datatype ProxyInfo
		*/
		OctetString* setProxyHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ProxyHost for datatype ProxyInfo
		*/
		void resetProxyHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ProxyHost for datatype ProxyInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getProxyHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ProxyState for datatype ProxyInfo
		*/
		OctetString* setProxyState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ProxyState for datatype ProxyInfo
		*/
		void resetProxyState();

		//!Function to get values
		/*!		Function to get OctetString type of argument ProxyState for datatype ProxyInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getProxyState();

		//! Function to Decode
		/*!		Function to Decode datatype ProxyInfo
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ProxyInfo
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ProxyInfo
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ProxyInfo
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ProxyInfo
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
