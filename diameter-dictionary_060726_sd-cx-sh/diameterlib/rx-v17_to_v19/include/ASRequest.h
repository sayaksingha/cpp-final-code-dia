#ifndef RX_ASREQUEST_H
#define RX_ASREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"
#include "rx/include/ProxyInfo.h"
#include "rx/include/DRMP.h"
#include "rx/include/OCSupportedFeatures.h"
#include "rx/include/AbortCause.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace RX{
typedef enum _tags_ASRequest
{
	ASRequest_SESSIONID	= 0,
	ASRequest_DRMP	= 1,
	ASRequest_ORIGINHOST	= 2,
	ASRequest_ORIGINREALM	= 3,
	ASRequest_DESTINATIONREALM	= 4,
	ASRequest_DESTINATIONHOST	= 5,
	ASRequest_AUTHAPPLICATIONID	= 6,
	ASRequest_OCSUPPORTEDFEATURES	= 7,
	ASRequest_ABORTCAUSE	= 8,
	ASRequest_ORIGINSTATEID	= 9,
	ASRequest_PROXYINFO	= 10,
	ASRequest_ROUTERECORD	= 11,
}ASRequest_tags;

		//! Class Definition
		/*!		ClassName is ASRequest
		*/
class ASRequest : public DiameterBase 
{
	private:

		bitset<12> mTagsPresent;

		bitset<12> mMandatoryAvpCheckVal;

		bitset<12> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mDestinationRealm;

		OctetString*		mDestinationHost;

		Integer32*		mAuthApplicationId;

		AbortCause*		mAbortCause;

		Unsigned32*		mOriginStateId;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;









		OCSupportedFeatures*	mOCSupportedFeaturesGrp;



		list<RX::ProxyInfo*>*	mProxyInfoGrpList;
		list<RX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		ASRequest();

		ASRequest(const ASRequest &objASRequest) {

		mTagsPresent = objASRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objASRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objASRequest.mMandatoryAvpSetVal;

		mTag = objASRequest.mTag;

		mDecodeFlag = objASRequest.mDecodeFlag;

		if(objASRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objASRequest.mSessionId));

		if(objASRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objASRequest.mDRMP));

		if(objASRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objASRequest.mOriginHost));

		if(objASRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objASRequest.mOriginRealm));

		if(objASRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objASRequest.mDestinationRealm));

		if(objASRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objASRequest.mDestinationHost));

		if(objASRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objASRequest.mAuthApplicationId));

		if(objASRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objASRequest.mOCSupportedFeaturesGrp);
		 }
		if(objASRequest.mAbortCause != NULL)
		mAbortCause = new AbortCause(*(objASRequest.mAbortCause));

		if(objASRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objASRequest.mOriginStateId));

		if(objASRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objASRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const ASRequest &objASRequest) {

		mTagsPresent = objASRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objASRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objASRequest.mMandatoryAvpSetVal;

		mTag = objASRequest.mTag;

		mDecodeFlag = objASRequest.mDecodeFlag;

		if(objASRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objASRequest.mSessionId));

		if(objASRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objASRequest.mDRMP));

		if(objASRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objASRequest.mOriginHost));

		if(objASRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objASRequest.mOriginRealm));

		if(objASRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objASRequest.mDestinationRealm));

		if(objASRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objASRequest.mDestinationHost));

		if(objASRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objASRequest.mAuthApplicationId));

		if(objASRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objASRequest.mOCSupportedFeaturesGrp);
		 }
		if(objASRequest.mAbortCause != NULL)
		mAbortCause = new AbortCause(*(objASRequest.mAbortCause));

		if(objASRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objASRequest.mOriginStateId));

		if(objASRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objASRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~ASRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype ASRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype ASRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype ASRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype ASRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype ASRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype ASRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype ASRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype ASRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype ASRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype ASRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype ASRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype ASRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype ASRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype ASRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype ASRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype ASRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype ASRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype ASRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument AuthApplicationId for datatype ASRequest
		*/
		Integer32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype ASRequest
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument AuthApplicationId for datatype ASRequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getAuthApplicationId();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AbortCause for datatype ASRequest
		*/
		AbortCause* setAbortCause();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AbortCause for datatype ASRequest
		*/
		void resetAbortCause();

		//!Function to get values
		/*!		Function to get AbortCause type of argument AbortCause for datatype ASRequest
		Throws exception of which type and Summary of Exception
		*/
		AbortCause* getAbortCause();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype ASRequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype ASRequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype ASRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		list<RX::ProxyInfo*>* getProxyInfoGrpList();

		list<RX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype ASRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype ASRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ASRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ASRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ASRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
