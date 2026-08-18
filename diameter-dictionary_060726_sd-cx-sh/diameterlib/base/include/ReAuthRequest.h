#ifndef BASE_REAUTHREQUEST_H
#define BASE_REAUTHREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "base/include/ProxyInfo.h"
#include "base/include/CCRequestType.h"
#include "base/include/DiameterBase.h"
#include "base/include/RedirectHostUsage.h"
#include "base/include/ReAuthRequestType.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace BASE{
typedef enum _tags_ReAuthRequest
{
	ReAuthRequest_SESSIONID	= 0,
	ReAuthRequest_ORIGINHOST	= 1,
	ReAuthRequest_ORIGINREALM	= 2,
	ReAuthRequest_ORIGINSTATEID	= 3,
	ReAuthRequest_DESTINATIONREALM	= 4,
	ReAuthRequest_DESTINATIONHOST	= 5,
	ReAuthRequest_REAUTHREQUESTTYPE	= 6,
	ReAuthRequest_AUTHAPPLICATIONID	= 7,
	ReAuthRequest_USERNAME	= 8,
	ReAuthRequest_PROXYINFO	= 9,
	ReAuthRequest_ROUTERECORD	= 10,
	ReAuthRequest_CCREQUESTTYPE	= 11,
}ReAuthRequest_tags;

		//! Class Definition
		/*!		ClassName is ReAuthRequest
		*/
class ReAuthRequest : public DiameterBase 
{
	private:

		bitset<12> mTagsPresent;

		bitset<12> mMandatoryAvpCheckVal;

		bitset<12> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		Unsigned32*		mOriginStateId;

		OctetString*		mDestinationRealm;

		OctetString*		mDestinationHost;

		ReAuthRequestType*		mReAuthRequestType;

		Integer32*		mAuthApplicationId;

		OctetString*		mUserName;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;

		CCRequestType*		mCCRequestType;











		list<ProxyInfo*>*	mProxyInfoGrpList;
		list<ProxyInfo*>::iterator	mProxyInfoGrpIterator;



	public:
		ReAuthRequest();

		ReAuthRequest(const ReAuthRequest &objReAuthRequest) {

		mTagsPresent = objReAuthRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objReAuthRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objReAuthRequest.mMandatoryAvpSetVal;

		mTag = objReAuthRequest.mTag;

		mDecodeFlag = objReAuthRequest.mDecodeFlag;

		if(objReAuthRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objReAuthRequest.mSessionId));

		if(objReAuthRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objReAuthRequest.mOriginHost));

		if(objReAuthRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objReAuthRequest.mOriginRealm));

		if(objReAuthRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objReAuthRequest.mOriginStateId));

		if(objReAuthRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objReAuthRequest.mDestinationRealm));

		if(objReAuthRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objReAuthRequest.mDestinationHost));

		if(objReAuthRequest.mReAuthRequestType != NULL)
		mReAuthRequestType = new ReAuthRequestType(*(objReAuthRequest.mReAuthRequestType));

		if(objReAuthRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objReAuthRequest.mAuthApplicationId));

		if(objReAuthRequest.mUserName != NULL)
		mUserName = new OctetString(*(objReAuthRequest.mUserName));

		if(objReAuthRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objReAuthRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objReAuthRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objReAuthRequest.mCCRequestType));

		}

		void operator = (const ReAuthRequest &objReAuthRequest) {

		mTagsPresent = objReAuthRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objReAuthRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objReAuthRequest.mMandatoryAvpSetVal;

		mTag = objReAuthRequest.mTag;

		mDecodeFlag = objReAuthRequest.mDecodeFlag;

		if(objReAuthRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objReAuthRequest.mSessionId));

		if(objReAuthRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objReAuthRequest.mOriginHost));

		if(objReAuthRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objReAuthRequest.mOriginRealm));

		if(objReAuthRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objReAuthRequest.mOriginStateId));

		if(objReAuthRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objReAuthRequest.mDestinationRealm));

		if(objReAuthRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objReAuthRequest.mDestinationHost));

		if(objReAuthRequest.mReAuthRequestType != NULL)
		mReAuthRequestType = new ReAuthRequestType(*(objReAuthRequest.mReAuthRequestType));

		if(objReAuthRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objReAuthRequest.mAuthApplicationId));

		if(objReAuthRequest.mUserName != NULL)
		mUserName = new OctetString(*(objReAuthRequest.mUserName));

		if(objReAuthRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objReAuthRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objReAuthRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objReAuthRequest.mCCRequestType));

		}

		virtual ~ReAuthRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype ReAuthRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype ReAuthRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype ReAuthRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype ReAuthRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype ReAuthRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype ReAuthRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype ReAuthRequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype ReAuthRequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype ReAuthRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype ReAuthRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype ReAuthRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype ReAuthRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ReAuthRequestType for datatype ReAuthRequest
		*/
		ReAuthRequestType* setReAuthRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ReAuthRequestType for datatype ReAuthRequest
		*/
		void resetReAuthRequestType();

		//!Function to get values
		/*!		Function to get ReAuthRequestType type of argument ReAuthRequestType for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		ReAuthRequestType* getReAuthRequestType();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument AuthApplicationId for datatype ReAuthRequest
		*/
		Integer32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype ReAuthRequest
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument AuthApplicationId for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getAuthApplicationId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype ReAuthRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype ReAuthRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype ReAuthRequest
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
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype ReAuthRequest
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype ReAuthRequest
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype ReAuthRequest
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype ReAuthRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype ReAuthRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ReAuthRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ReAuthRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ReAuthRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
