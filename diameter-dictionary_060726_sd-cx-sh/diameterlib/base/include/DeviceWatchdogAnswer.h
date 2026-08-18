#ifndef BASE_DEVICEWATCHDOGANSWER_H
#define BASE_DEVICEWATCHDOGANSWER_H
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
typedef enum _tags_DeviceWatchdogAnswer
{
	DeviceWatchdogAnswer_SESSIONID	= 0,
	DeviceWatchdogAnswer_RESULTCODE	= 1,
	DeviceWatchdogAnswer_ORIGINHOST	= 2,
	DeviceWatchdogAnswer_ORIGINREALM	= 3,
	DeviceWatchdogAnswer_ERRORMESSAGE	= 4,
	DeviceWatchdogAnswer_ORIGINSTATEID	= 5,
	DeviceWatchdogAnswer_CCREQUESTTYPE	= 6,
}DeviceWatchdogAnswer_tags;

		//! Class Definition
		/*!		ClassName is DeviceWatchdogAnswer
		*/
class DeviceWatchdogAnswer : public DiameterBase 
{
	private:

		bitset<7> mTagsPresent;

		bitset<7> mMandatoryAvpCheckVal;

		bitset<7> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		Unsigned32*		mResultCode;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mErrorMessage;

		Unsigned32*		mOriginStateId;

		CCRequestType*		mCCRequestType;









	public:
		DeviceWatchdogAnswer();

		DeviceWatchdogAnswer(const DeviceWatchdogAnswer &objDeviceWatchdogAnswer) {

		mTagsPresent = objDeviceWatchdogAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objDeviceWatchdogAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objDeviceWatchdogAnswer.mMandatoryAvpSetVal;

		mTag = objDeviceWatchdogAnswer.mTag;

		mDecodeFlag = objDeviceWatchdogAnswer.mDecodeFlag;

		if(objDeviceWatchdogAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objDeviceWatchdogAnswer.mSessionId));

		if(objDeviceWatchdogAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objDeviceWatchdogAnswer.mResultCode));

		if(objDeviceWatchdogAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objDeviceWatchdogAnswer.mOriginHost));

		if(objDeviceWatchdogAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objDeviceWatchdogAnswer.mOriginRealm));

		if(objDeviceWatchdogAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objDeviceWatchdogAnswer.mErrorMessage));

		if(objDeviceWatchdogAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objDeviceWatchdogAnswer.mOriginStateId));

		if(objDeviceWatchdogAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objDeviceWatchdogAnswer.mCCRequestType));

		}

		void operator = (const DeviceWatchdogAnswer &objDeviceWatchdogAnswer) {

		mTagsPresent = objDeviceWatchdogAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objDeviceWatchdogAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objDeviceWatchdogAnswer.mMandatoryAvpSetVal;

		mTag = objDeviceWatchdogAnswer.mTag;

		mDecodeFlag = objDeviceWatchdogAnswer.mDecodeFlag;

		if(objDeviceWatchdogAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objDeviceWatchdogAnswer.mSessionId));

		if(objDeviceWatchdogAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objDeviceWatchdogAnswer.mResultCode));

		if(objDeviceWatchdogAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objDeviceWatchdogAnswer.mOriginHost));

		if(objDeviceWatchdogAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objDeviceWatchdogAnswer.mOriginRealm));

		if(objDeviceWatchdogAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objDeviceWatchdogAnswer.mErrorMessage));

		if(objDeviceWatchdogAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objDeviceWatchdogAnswer.mOriginStateId));

		if(objDeviceWatchdogAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objDeviceWatchdogAnswer.mCCRequestType));

		}

		virtual ~DeviceWatchdogAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype DeviceWatchdogAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype DeviceWatchdogAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype DeviceWatchdogAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype DeviceWatchdogAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype DeviceWatchdogAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype DeviceWatchdogAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype DeviceWatchdogAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype DeviceWatchdogAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype DeviceWatchdogAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype DeviceWatchdogAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype DeviceWatchdogAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype DeviceWatchdogAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype DeviceWatchdogAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype DeviceWatchdogAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype DeviceWatchdogAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype DeviceWatchdogAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype DeviceWatchdogAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype DeviceWatchdogAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype DeviceWatchdogAnswer
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype DeviceWatchdogAnswer
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype DeviceWatchdogAnswer
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype DeviceWatchdogAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype DeviceWatchdogAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype DeviceWatchdogAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype DeviceWatchdogAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype DeviceWatchdogAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
