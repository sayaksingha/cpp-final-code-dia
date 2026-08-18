#ifndef BASE_DISCONNECTPEERANSWER_H
#define BASE_DISCONNECTPEERANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "base/include/CCRequestType.h"
#include "base/include/DiameterBase.h"
#include "base/include/DisconnectCause.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace BASE{
typedef enum _tags_DisconnectPeerAnswer
{
	DisconnectPeerAnswer_SESSIONID	= 0,
	DisconnectPeerAnswer_RESULTCODE	= 1,
	DisconnectPeerAnswer_ORIGINHOST	= 2,
	DisconnectPeerAnswer_ORIGINREALM	= 3,
	DisconnectPeerAnswer_ERRORMESSAGE	= 4,
	DisconnectPeerAnswer_CCREQUESTTYPE	= 5,
}DisconnectPeerAnswer_tags;

		//! Class Definition
		/*!		ClassName is DisconnectPeerAnswer
		*/
class DisconnectPeerAnswer : public DiameterBase 
{
	private:

		bitset<6> mTagsPresent;

		bitset<6> mMandatoryAvpCheckVal;

		bitset<6> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		Unsigned32*		mResultCode;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mErrorMessage;

		CCRequestType*		mCCRequestType;








	public:
		DisconnectPeerAnswer();

		DisconnectPeerAnswer(const DisconnectPeerAnswer &objDisconnectPeerAnswer) {

		mTagsPresent = objDisconnectPeerAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objDisconnectPeerAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objDisconnectPeerAnswer.mMandatoryAvpSetVal;

		mTag = objDisconnectPeerAnswer.mTag;

		mDecodeFlag = objDisconnectPeerAnswer.mDecodeFlag;

		if(objDisconnectPeerAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objDisconnectPeerAnswer.mSessionId));

		if(objDisconnectPeerAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objDisconnectPeerAnswer.mResultCode));

		if(objDisconnectPeerAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objDisconnectPeerAnswer.mOriginHost));

		if(objDisconnectPeerAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objDisconnectPeerAnswer.mOriginRealm));

		if(objDisconnectPeerAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objDisconnectPeerAnswer.mErrorMessage));

		if(objDisconnectPeerAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objDisconnectPeerAnswer.mCCRequestType));

		}

		void operator = (const DisconnectPeerAnswer &objDisconnectPeerAnswer) {

		mTagsPresent = objDisconnectPeerAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objDisconnectPeerAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objDisconnectPeerAnswer.mMandatoryAvpSetVal;

		mTag = objDisconnectPeerAnswer.mTag;

		mDecodeFlag = objDisconnectPeerAnswer.mDecodeFlag;

		if(objDisconnectPeerAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objDisconnectPeerAnswer.mSessionId));

		if(objDisconnectPeerAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objDisconnectPeerAnswer.mResultCode));

		if(objDisconnectPeerAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objDisconnectPeerAnswer.mOriginHost));

		if(objDisconnectPeerAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objDisconnectPeerAnswer.mOriginRealm));

		if(objDisconnectPeerAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objDisconnectPeerAnswer.mErrorMessage));

		if(objDisconnectPeerAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objDisconnectPeerAnswer.mCCRequestType));

		}

		virtual ~DisconnectPeerAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype DisconnectPeerAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype DisconnectPeerAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype DisconnectPeerAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype DisconnectPeerAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype DisconnectPeerAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype DisconnectPeerAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype DisconnectPeerAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype DisconnectPeerAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype DisconnectPeerAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype DisconnectPeerAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype DisconnectPeerAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype DisconnectPeerAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype DisconnectPeerAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype DisconnectPeerAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype DisconnectPeerAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype DisconnectPeerAnswer
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype DisconnectPeerAnswer
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype DisconnectPeerAnswer
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype DisconnectPeerAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype DisconnectPeerAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype DisconnectPeerAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype DisconnectPeerAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype DisconnectPeerAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
