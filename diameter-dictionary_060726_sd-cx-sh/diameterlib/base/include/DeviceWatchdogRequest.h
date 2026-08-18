#ifndef BASE_DEVICEWATCHDOGREQUEST_H
#define BASE_DEVICEWATCHDOGREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "base/include/CCRequestType.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace BASE{
typedef enum _tags_DeviceWatchdogRequest
{
	DeviceWatchdogRequest_ORIGINHOST	= 0,
	DeviceWatchdogRequest_ORIGINREALM	= 1,
	DeviceWatchdogRequest_ORIGINSTATEID	= 2,
	DeviceWatchdogRequest_CCREQUESTTYPE	= 3,
}DeviceWatchdogRequest_tags;

		//! Class Definition
		/*!		ClassName is DeviceWatchdogRequest
		*/
class DeviceWatchdogRequest : public DiameterBase 
{
	private:

		bitset<4> mTagsPresent;

		bitset<4> mMandatoryAvpCheckVal;

		bitset<4> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		Unsigned32*		mOriginStateId;

		CCRequestType*		mCCRequestType;






	public:
		DeviceWatchdogRequest();

		DeviceWatchdogRequest(const DeviceWatchdogRequest &objDeviceWatchdogRequest) {

		mTagsPresent = objDeviceWatchdogRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objDeviceWatchdogRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objDeviceWatchdogRequest.mMandatoryAvpSetVal;

		mTag = objDeviceWatchdogRequest.mTag;

		mDecodeFlag = objDeviceWatchdogRequest.mDecodeFlag;

		if(objDeviceWatchdogRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objDeviceWatchdogRequest.mOriginHost));

		if(objDeviceWatchdogRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objDeviceWatchdogRequest.mOriginRealm));

		if(objDeviceWatchdogRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objDeviceWatchdogRequest.mOriginStateId));

		if(objDeviceWatchdogRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objDeviceWatchdogRequest.mCCRequestType));

		}

		void operator = (const DeviceWatchdogRequest &objDeviceWatchdogRequest) {

		mTagsPresent = objDeviceWatchdogRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objDeviceWatchdogRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objDeviceWatchdogRequest.mMandatoryAvpSetVal;

		mTag = objDeviceWatchdogRequest.mTag;

		mDecodeFlag = objDeviceWatchdogRequest.mDecodeFlag;

		if(objDeviceWatchdogRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objDeviceWatchdogRequest.mOriginHost));

		if(objDeviceWatchdogRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objDeviceWatchdogRequest.mOriginRealm));

		if(objDeviceWatchdogRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objDeviceWatchdogRequest.mOriginStateId));

		if(objDeviceWatchdogRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objDeviceWatchdogRequest.mCCRequestType));

		}

		virtual ~DeviceWatchdogRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype DeviceWatchdogRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype DeviceWatchdogRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype DeviceWatchdogRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype DeviceWatchdogRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype DeviceWatchdogRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype DeviceWatchdogRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype DeviceWatchdogRequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype DeviceWatchdogRequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype DeviceWatchdogRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype DeviceWatchdogRequest
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype DeviceWatchdogRequest
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype DeviceWatchdogRequest
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype DeviceWatchdogRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype DeviceWatchdogRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype DeviceWatchdogRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype DeviceWatchdogRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype DeviceWatchdogRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
