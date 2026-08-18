#ifndef BASE_ABORTSESSIONREQUEST_H
#define BASE_ABORTSESSIONREQUEST_H
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
typedef enum _tags_AbortSessionRequest
{
	AbortSessionRequest_SESSIONID	= 0,
	AbortSessionRequest_ORIGINHOST	= 1,
	AbortSessionRequest_ORIGINREALM	= 2,
	AbortSessionRequest_ORIGINSTATEID	= 3,
	AbortSessionRequest_DESTINATIONREALM	= 4,
	AbortSessionRequest_DESTINATIONHOST	= 5,
	AbortSessionRequest_AUTHAPPLICATIONID	= 6,
	AbortSessionRequest_USERNAME	= 7,
	AbortSessionRequest_PROXYINFO	= 8,
	AbortSessionRequest_ROUTERECORD	= 9,
	AbortSessionRequest_CCREQUESTTYPE	= 10,
}AbortSessionRequest_tags;

		//! Class Definition
		/*!		ClassName is AbortSessionRequest
		*/
class AbortSessionRequest : public DiameterBase 
{
	private:

		bitset<11> mTagsPresent;

		bitset<11> mMandatoryAvpCheckVal;

		bitset<11> mMandatoryAvpSetVal;

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

		OctetString*		mUserName;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;

		CCRequestType*		mCCRequestType;










		list<ProxyInfo*>*	mProxyInfoGrpList;
		list<ProxyInfo*>::iterator	mProxyInfoGrpIterator;



	public:
		AbortSessionRequest();

		AbortSessionRequest(const AbortSessionRequest &objAbortSessionRequest) {

		mTagsPresent = objAbortSessionRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objAbortSessionRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAbortSessionRequest.mMandatoryAvpSetVal;

		mTag = objAbortSessionRequest.mTag;

		mDecodeFlag = objAbortSessionRequest.mDecodeFlag;

		if(objAbortSessionRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objAbortSessionRequest.mSessionId));

		if(objAbortSessionRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objAbortSessionRequest.mOriginHost));

		if(objAbortSessionRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objAbortSessionRequest.mOriginRealm));

		if(objAbortSessionRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objAbortSessionRequest.mOriginStateId));

		if(objAbortSessionRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objAbortSessionRequest.mDestinationRealm));

		if(objAbortSessionRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objAbortSessionRequest.mDestinationHost));

		if(objAbortSessionRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objAbortSessionRequest.mAuthApplicationId));

		if(objAbortSessionRequest.mUserName != NULL)
		mUserName = new OctetString(*(objAbortSessionRequest.mUserName));

		if(objAbortSessionRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objAbortSessionRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objAbortSessionRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objAbortSessionRequest.mCCRequestType));

		}

		void operator = (const AbortSessionRequest &objAbortSessionRequest) {

		mTagsPresent = objAbortSessionRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objAbortSessionRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAbortSessionRequest.mMandatoryAvpSetVal;

		mTag = objAbortSessionRequest.mTag;

		mDecodeFlag = objAbortSessionRequest.mDecodeFlag;

		if(objAbortSessionRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objAbortSessionRequest.mSessionId));

		if(objAbortSessionRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objAbortSessionRequest.mOriginHost));

		if(objAbortSessionRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objAbortSessionRequest.mOriginRealm));

		if(objAbortSessionRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objAbortSessionRequest.mOriginStateId));

		if(objAbortSessionRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objAbortSessionRequest.mDestinationRealm));

		if(objAbortSessionRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objAbortSessionRequest.mDestinationHost));

		if(objAbortSessionRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objAbortSessionRequest.mAuthApplicationId));

		if(objAbortSessionRequest.mUserName != NULL)
		mUserName = new OctetString(*(objAbortSessionRequest.mUserName));

		if(objAbortSessionRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objAbortSessionRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objAbortSessionRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objAbortSessionRequest.mCCRequestType));

		}

		virtual ~AbortSessionRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype AbortSessionRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype AbortSessionRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype AbortSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype AbortSessionRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype AbortSessionRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype AbortSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype AbortSessionRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype AbortSessionRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype AbortSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype AbortSessionRequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype AbortSessionRequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype AbortSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype AbortSessionRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype AbortSessionRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype AbortSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype AbortSessionRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype AbortSessionRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype AbortSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument AuthApplicationId for datatype AbortSessionRequest
		*/
		Integer32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype AbortSessionRequest
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument AuthApplicationId for datatype AbortSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getAuthApplicationId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype AbortSessionRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype AbortSessionRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype AbortSessionRequest
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
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype AbortSessionRequest
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype AbortSessionRequest
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype AbortSessionRequest
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype AbortSessionRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype AbortSessionRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype AbortSessionRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype AbortSessionRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AbortSessionRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
