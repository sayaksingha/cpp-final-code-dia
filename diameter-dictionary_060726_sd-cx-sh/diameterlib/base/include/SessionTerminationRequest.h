#ifndef BASE_SESSIONTERMINATIONREQUEST_H
#define BASE_SESSIONTERMINATIONREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "base/include/ProxyInfo.h"
#include "base/include/CCRequestType.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace BASE{
typedef enum _tags_SessionTerminationRequest
{
	SessionTerminationRequest_SESSIONID	= 0,
	SessionTerminationRequest_ORIGINHOST	= 1,
	SessionTerminationRequest_ORIGINREALM	= 2,
	SessionTerminationRequest_ORIGINSTATEID	= 3,
	SessionTerminationRequest_DESTINATIONREALM	= 4,
	SessionTerminationRequest_DESTINATIONHOST	= 5,
	SessionTerminationRequest_AUTHAPPLICATIONID	= 6,
	SessionTerminationRequest_TERMINATIONCAUSE	= 7,
	SessionTerminationRequest_CLASS	= 8,
	SessionTerminationRequest_USERNAME	= 9,
	SessionTerminationRequest_PROXYINFO	= 10,
	SessionTerminationRequest_ROUTERECORD	= 11,
	SessionTerminationRequest_CCREQUESTTYPE	= 12,
}SessionTerminationRequest_tags;

		//! Class Definition
		/*!		ClassName is SessionTerminationRequest
		*/
class SessionTerminationRequest : public DiameterBase 
{
	private:

		bitset<13> mTagsPresent;

		bitset<13> mMandatoryAvpCheckVal;

		bitset<13> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		Unsigned32*		mOriginStateId;

		OctetString*		mDestinationRealm;

		OctetString*		mDestinationHost;

		Integer32*		mAuthApplicationId;

		Unsigned32*		mTerminationCause;

		list<OctetString*>* 		mClassList;

		list<OctetString*>::iterator 		mClassIterator;

		OctetString*		mUserName;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;

		CCRequestType*		mCCRequestType;












		list<ProxyInfo*>*	mProxyInfoGrpList;
		list<ProxyInfo*>::iterator	mProxyInfoGrpIterator;



	public:
		SessionTerminationRequest();

		SessionTerminationRequest(const SessionTerminationRequest &objSessionTerminationRequest) {

		mTagsPresent = objSessionTerminationRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objSessionTerminationRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSessionTerminationRequest.mMandatoryAvpSetVal;

		mTag = objSessionTerminationRequest.mTag;

		mDecodeFlag = objSessionTerminationRequest.mDecodeFlag;

		if(objSessionTerminationRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objSessionTerminationRequest.mSessionId));

		if(objSessionTerminationRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSessionTerminationRequest.mOriginHost));

		if(objSessionTerminationRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSessionTerminationRequest.mOriginRealm));

		if(objSessionTerminationRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objSessionTerminationRequest.mOriginStateId));

		if(objSessionTerminationRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objSessionTerminationRequest.mDestinationRealm));

		if(objSessionTerminationRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objSessionTerminationRequest.mDestinationHost));

		if(objSessionTerminationRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objSessionTerminationRequest.mAuthApplicationId));

		if(objSessionTerminationRequest.mTerminationCause != NULL)
		mTerminationCause = new Unsigned32(*(objSessionTerminationRequest.mTerminationCause));

		if(objSessionTerminationRequest.mUserName != NULL)
		mUserName = new OctetString(*(objSessionTerminationRequest.mUserName));

		if(objSessionTerminationRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objSessionTerminationRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objSessionTerminationRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objSessionTerminationRequest.mCCRequestType));

		}

		void operator = (const SessionTerminationRequest &objSessionTerminationRequest) {

		mTagsPresent = objSessionTerminationRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objSessionTerminationRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSessionTerminationRequest.mMandatoryAvpSetVal;

		mTag = objSessionTerminationRequest.mTag;

		mDecodeFlag = objSessionTerminationRequest.mDecodeFlag;

		if(objSessionTerminationRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objSessionTerminationRequest.mSessionId));

		if(objSessionTerminationRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSessionTerminationRequest.mOriginHost));

		if(objSessionTerminationRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSessionTerminationRequest.mOriginRealm));

		if(objSessionTerminationRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objSessionTerminationRequest.mOriginStateId));

		if(objSessionTerminationRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objSessionTerminationRequest.mDestinationRealm));

		if(objSessionTerminationRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objSessionTerminationRequest.mDestinationHost));

		if(objSessionTerminationRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objSessionTerminationRequest.mAuthApplicationId));

		if(objSessionTerminationRequest.mTerminationCause != NULL)
		mTerminationCause = new Unsigned32(*(objSessionTerminationRequest.mTerminationCause));

		if(objSessionTerminationRequest.mUserName != NULL)
		mUserName = new OctetString(*(objSessionTerminationRequest.mUserName));

		if(objSessionTerminationRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objSessionTerminationRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objSessionTerminationRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objSessionTerminationRequest.mCCRequestType));

		}

		virtual ~SessionTerminationRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype SessionTerminationRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype SessionTerminationRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype SessionTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype SessionTerminationRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype SessionTerminationRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype SessionTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype SessionTerminationRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype SessionTerminationRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype SessionTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype SessionTerminationRequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype SessionTerminationRequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype SessionTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype SessionTerminationRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype SessionTerminationRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype SessionTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype SessionTerminationRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype SessionTerminationRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype SessionTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument AuthApplicationId for datatype SessionTerminationRequest
		*/
		Integer32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype SessionTerminationRequest
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument AuthApplicationId for datatype SessionTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getAuthApplicationId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument TerminationCause for datatype SessionTerminationRequest
		*/
		Unsigned32* setTerminationCause();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TerminationCause for datatype SessionTerminationRequest
		*/
		void resetTerminationCause();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument TerminationCause for datatype SessionTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getTerminationCause();

		list<OctetString*>* getClassList();

		list<OctetString*>* setClassList();

		void resetClassList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype SessionTerminationRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype SessionTerminationRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype SessionTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		list<ProxyInfo*>* getProxyInfoGrpList();

		list<ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype SessionTerminationRequest
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype SessionTerminationRequest
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype SessionTerminationRequest
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype SessionTerminationRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype SessionTerminationRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SessionTerminationRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SessionTerminationRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SessionTerminationRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
