#ifndef BASE_DISCONNECTPEERREQUEST_H
#define BASE_DISCONNECTPEERREQUEST_H
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
typedef enum _tags_DisconnectPeerRequest
{
	DisconnectPeerRequest_SESSIONID	= 0,
	DisconnectPeerRequest_ORIGINHOST	= 1,
	DisconnectPeerRequest_ORIGINREALM	= 2,
	DisconnectPeerRequest_DISCONNECTCAUSE	= 3,
	DisconnectPeerRequest_CCREQUESTTYPE	= 4,
}DisconnectPeerRequest_tags;

		//! Class Definition
		/*!		ClassName is DisconnectPeerRequest
		*/
class DisconnectPeerRequest : public DiameterBase 
{
	private:

		bitset<5> mTagsPresent;

		bitset<5> mMandatoryAvpCheckVal;

		bitset<5> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		DisconnectCause*		mDisconnectCause;

		CCRequestType*		mCCRequestType;







	public:
		DisconnectPeerRequest();

		DisconnectPeerRequest(const DisconnectPeerRequest &objDisconnectPeerRequest) {

		mTagsPresent = objDisconnectPeerRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objDisconnectPeerRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objDisconnectPeerRequest.mMandatoryAvpSetVal;

		mTag = objDisconnectPeerRequest.mTag;

		mDecodeFlag = objDisconnectPeerRequest.mDecodeFlag;

		if(objDisconnectPeerRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objDisconnectPeerRequest.mSessionId));

		if(objDisconnectPeerRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objDisconnectPeerRequest.mOriginHost));

		if(objDisconnectPeerRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objDisconnectPeerRequest.mOriginRealm));

		if(objDisconnectPeerRequest.mDisconnectCause != NULL)
		mDisconnectCause = new DisconnectCause(*(objDisconnectPeerRequest.mDisconnectCause));

		if(objDisconnectPeerRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objDisconnectPeerRequest.mCCRequestType));

		}

		void operator = (const DisconnectPeerRequest &objDisconnectPeerRequest) {

		mTagsPresent = objDisconnectPeerRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objDisconnectPeerRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objDisconnectPeerRequest.mMandatoryAvpSetVal;

		mTag = objDisconnectPeerRequest.mTag;

		mDecodeFlag = objDisconnectPeerRequest.mDecodeFlag;

		if(objDisconnectPeerRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objDisconnectPeerRequest.mSessionId));

		if(objDisconnectPeerRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objDisconnectPeerRequest.mOriginHost));

		if(objDisconnectPeerRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objDisconnectPeerRequest.mOriginRealm));

		if(objDisconnectPeerRequest.mDisconnectCause != NULL)
		mDisconnectCause = new DisconnectCause(*(objDisconnectPeerRequest.mDisconnectCause));

		if(objDisconnectPeerRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objDisconnectPeerRequest.mCCRequestType));

		}

		virtual ~DisconnectPeerRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype DisconnectPeerRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype DisconnectPeerRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype DisconnectPeerRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype DisconnectPeerRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype DisconnectPeerRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype DisconnectPeerRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype DisconnectPeerRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype DisconnectPeerRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype DisconnectPeerRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DisconnectCause for datatype DisconnectPeerRequest
		*/
		DisconnectCause* setDisconnectCause();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DisconnectCause for datatype DisconnectPeerRequest
		*/
		void resetDisconnectCause();

		//!Function to get values
		/*!		Function to get DisconnectCause type of argument DisconnectCause for datatype DisconnectPeerRequest
		Throws exception of which type and Summary of Exception
		*/
		DisconnectCause* getDisconnectCause();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype DisconnectPeerRequest
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype DisconnectPeerRequest
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype DisconnectPeerRequest
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype DisconnectPeerRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype DisconnectPeerRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype DisconnectPeerRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype DisconnectPeerRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype DisconnectPeerRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
