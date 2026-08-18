#ifndef CX_SERVERASSIGNMENTREQUEST_H
#define CX_SERVERASSIGNMENTREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/DRMP.h"
#include "cx/include/VendorSpecificApplicationId.h"
#include "cx/include/AuthSessionState.h"
#include "cx/include/OCSupportedFeatures.h"
#include "cx/include/SupportedFeatures.h"
#include "cx/include/ServerAssignmentType.h"
#include "cx/include/UserDataAlreadyAvailable.h"
#include "cx/include/SCSCFRestorationInfo.h"
#include "cx/include/MultipleRegistrationIndication.h"
#include "cx/include/SessionPriority.h"
#include "cx/include/FailedPCSCF.h"
#include "cx/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace CX{
typedef enum _tags_ServerAssignmentRequest
{
	ServerAssignmentRequest_SESSIONID	= 0,
	ServerAssignmentRequest_DRMP	= 1,
	ServerAssignmentRequest_VENDORSPECIFICAPPLICATIONID	= 2,
	ServerAssignmentRequest_AUTHSESSIONSTATE	= 3,
	ServerAssignmentRequest_ORIGINHOST	= 4,
	ServerAssignmentRequest_ORIGINREALM	= 5,
	ServerAssignmentRequest_DESTINATIONHOST	= 6,
	ServerAssignmentRequest_DESTINATIONREALM	= 7,
	ServerAssignmentRequest_USERNAME	= 8,
	ServerAssignmentRequest_OCSUPPORTEDFEATURES	= 9,
	ServerAssignmentRequest_SUPPORTEDFEATURES	= 10,
	ServerAssignmentRequest_PUBLICIDENTITY	= 11,
	ServerAssignmentRequest_WILDCARDEDPUBLICIDENTITY	= 12,
	ServerAssignmentRequest_SERVERNAME	= 13,
	ServerAssignmentRequest_SERVERASSIGNMENTTYPE	= 14,
	ServerAssignmentRequest_USERDATAALREADYAVAILABLE	= 15,
	ServerAssignmentRequest_SCSCFRESTORATIONINFO	= 16,
	ServerAssignmentRequest_MULTIPLEREGISTRATIONINDICATION	= 17,
	ServerAssignmentRequest_SESSIONPRIORITY	= 18,
	ServerAssignmentRequest_SARFLAGS	= 19,
	ServerAssignmentRequest_FAILEDPCSCF	= 20,
	ServerAssignmentRequest_PROXYINFO	= 21,
	ServerAssignmentRequest_ROUTERECORD	= 22,
}ServerAssignmentRequest_tags;

		//! Class Definition
		/*!		ClassName is ServerAssignmentRequest
		*/
class ServerAssignmentRequest : public DiameterBase 
{
	private:

		bitset<23> mTagsPresent;

		bitset<23> mMandatoryAvpCheckVal;

		bitset<23> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mDestinationHost;

		OctetString*		mDestinationRealm;

		OctetString*		mUserName;

		list<OctetString*>* 		mPublicIdentityList;

		list<OctetString*>::iterator 		mPublicIdentityIterator;

		OctetString*		mWildcardedPublicIdentity;

		OctetString*		mServerName;

		ServerAssignmentType*		mServerAssignmentType;

		UserDataAlreadyAvailable*		mUserDataAlreadyAvailable;

		MultipleRegistrationIndication*		mMultipleRegistrationIndication;

		SessionPriority*		mSessionPriority;

		Unsigned32*		mSARFlags;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;







		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;






		SCSCFRestorationInfo*	mSCSCFRestorationInfoGrp;




		FailedPCSCF*	mFailedPCSCFGrp;

		list<CX::ProxyInfo*>*	mProxyInfoGrpList;
		list<CX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		ServerAssignmentRequest();

		ServerAssignmentRequest(const ServerAssignmentRequest &objServerAssignmentRequest) {

		mTagsPresent = objServerAssignmentRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objServerAssignmentRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objServerAssignmentRequest.mMandatoryAvpSetVal;

		mTag = objServerAssignmentRequest.mTag;

		mDecodeFlag = objServerAssignmentRequest.mDecodeFlag;

		if(objServerAssignmentRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objServerAssignmentRequest.mSessionId));

		if(objServerAssignmentRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objServerAssignmentRequest.mDRMP));

		if(objServerAssignmentRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objServerAssignmentRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objServerAssignmentRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objServerAssignmentRequest.mAuthSessionState));

		if(objServerAssignmentRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objServerAssignmentRequest.mOriginHost));

		if(objServerAssignmentRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objServerAssignmentRequest.mOriginRealm));

		if(objServerAssignmentRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objServerAssignmentRequest.mDestinationHost));

		if(objServerAssignmentRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objServerAssignmentRequest.mDestinationRealm));

		if(objServerAssignmentRequest.mUserName != NULL)
		mUserName = new OctetString(*(objServerAssignmentRequest.mUserName));

		if(objServerAssignmentRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objServerAssignmentRequest.mOCSupportedFeaturesGrp);
		 }
		if(objServerAssignmentRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objServerAssignmentRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objServerAssignmentRequest.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objServerAssignmentRequest.mWildcardedPublicIdentity));

		if(objServerAssignmentRequest.mServerName != NULL)
		mServerName = new OctetString(*(objServerAssignmentRequest.mServerName));

		if(objServerAssignmentRequest.mServerAssignmentType != NULL)
		mServerAssignmentType = new ServerAssignmentType(*(objServerAssignmentRequest.mServerAssignmentType));

		if(objServerAssignmentRequest.mUserDataAlreadyAvailable != NULL)
		mUserDataAlreadyAvailable = new UserDataAlreadyAvailable(*(objServerAssignmentRequest.mUserDataAlreadyAvailable));

		if(objServerAssignmentRequest.mSCSCFRestorationInfoGrp != NULL)
		 {
				 mSCSCFRestorationInfoGrp =  new SCSCFRestorationInfo(*objServerAssignmentRequest.mSCSCFRestorationInfoGrp);
		 }
		if(objServerAssignmentRequest.mMultipleRegistrationIndication != NULL)
		mMultipleRegistrationIndication = new MultipleRegistrationIndication(*(objServerAssignmentRequest.mMultipleRegistrationIndication));

		if(objServerAssignmentRequest.mSessionPriority != NULL)
		mSessionPriority = new SessionPriority(*(objServerAssignmentRequest.mSessionPriority));

		if(objServerAssignmentRequest.mSARFlags != NULL)
		mSARFlags = new Unsigned32(*(objServerAssignmentRequest.mSARFlags));

		if(objServerAssignmentRequest.mFailedPCSCFGrp != NULL)
		 {
				 mFailedPCSCFGrp =  new FailedPCSCF(*objServerAssignmentRequest.mFailedPCSCFGrp);
		 }
		if(objServerAssignmentRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objServerAssignmentRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const ServerAssignmentRequest &objServerAssignmentRequest) {

		mTagsPresent = objServerAssignmentRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objServerAssignmentRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objServerAssignmentRequest.mMandatoryAvpSetVal;

		mTag = objServerAssignmentRequest.mTag;

		mDecodeFlag = objServerAssignmentRequest.mDecodeFlag;

		if(objServerAssignmentRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objServerAssignmentRequest.mSessionId));

		if(objServerAssignmentRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objServerAssignmentRequest.mDRMP));

		if(objServerAssignmentRequest.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objServerAssignmentRequest.mVendorSpecificApplicationIdGrp);
		 }
		if(objServerAssignmentRequest.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objServerAssignmentRequest.mAuthSessionState));

		if(objServerAssignmentRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objServerAssignmentRequest.mOriginHost));

		if(objServerAssignmentRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objServerAssignmentRequest.mOriginRealm));

		if(objServerAssignmentRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objServerAssignmentRequest.mDestinationHost));

		if(objServerAssignmentRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objServerAssignmentRequest.mDestinationRealm));

		if(objServerAssignmentRequest.mUserName != NULL)
		mUserName = new OctetString(*(objServerAssignmentRequest.mUserName));

		if(objServerAssignmentRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objServerAssignmentRequest.mOCSupportedFeaturesGrp);
		 }
		if(objServerAssignmentRequest.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objServerAssignmentRequest.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objServerAssignmentRequest.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objServerAssignmentRequest.mWildcardedPublicIdentity));

		if(objServerAssignmentRequest.mServerName != NULL)
		mServerName = new OctetString(*(objServerAssignmentRequest.mServerName));

		if(objServerAssignmentRequest.mServerAssignmentType != NULL)
		mServerAssignmentType = new ServerAssignmentType(*(objServerAssignmentRequest.mServerAssignmentType));

		if(objServerAssignmentRequest.mUserDataAlreadyAvailable != NULL)
		mUserDataAlreadyAvailable = new UserDataAlreadyAvailable(*(objServerAssignmentRequest.mUserDataAlreadyAvailable));

		if(objServerAssignmentRequest.mSCSCFRestorationInfoGrp != NULL)
		 {
				 mSCSCFRestorationInfoGrp =  new SCSCFRestorationInfo(*objServerAssignmentRequest.mSCSCFRestorationInfoGrp);
		 }
		if(objServerAssignmentRequest.mMultipleRegistrationIndication != NULL)
		mMultipleRegistrationIndication = new MultipleRegistrationIndication(*(objServerAssignmentRequest.mMultipleRegistrationIndication));

		if(objServerAssignmentRequest.mSessionPriority != NULL)
		mSessionPriority = new SessionPriority(*(objServerAssignmentRequest.mSessionPriority));

		if(objServerAssignmentRequest.mSARFlags != NULL)
		mSARFlags = new Unsigned32(*(objServerAssignmentRequest.mSARFlags));

		if(objServerAssignmentRequest.mFailedPCSCFGrp != NULL)
		 {
				 mFailedPCSCFGrp =  new FailedPCSCF(*objServerAssignmentRequest.mFailedPCSCFGrp);
		 }
		if(objServerAssignmentRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objServerAssignmentRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~ServerAssignmentRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype ServerAssignmentRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype ServerAssignmentRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype ServerAssignmentRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype ServerAssignmentRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype ServerAssignmentRequest
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype ServerAssignmentRequest
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype ServerAssignmentRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype ServerAssignmentRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype ServerAssignmentRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype ServerAssignmentRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype ServerAssignmentRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype ServerAssignmentRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype ServerAssignmentRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype ServerAssignmentRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype ServerAssignmentRequest
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype ServerAssignmentRequest
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		list<OctetString*>* getPublicIdentityList();

		list<OctetString*>* setPublicIdentityList();

		void resetPublicIdentityList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedPublicIdentity for datatype ServerAssignmentRequest
		*/
		OctetString* setWildcardedPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedPublicIdentity for datatype ServerAssignmentRequest
		*/
		void resetWildcardedPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedPublicIdentity for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ServerName for datatype ServerAssignmentRequest
		*/
		OctetString* setServerName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServerName for datatype ServerAssignmentRequest
		*/
		void resetServerName();

		//!Function to get values
		/*!		Function to get OctetString type of argument ServerName for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getServerName();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ServerAssignmentType for datatype ServerAssignmentRequest
		*/
		ServerAssignmentType* setServerAssignmentType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServerAssignmentType for datatype ServerAssignmentRequest
		*/
		void resetServerAssignmentType();

		//!Function to get values
		/*!		Function to get ServerAssignmentType type of argument ServerAssignmentType for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		ServerAssignmentType* getServerAssignmentType();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument UserDataAlreadyAvailable for datatype ServerAssignmentRequest
		*/
		UserDataAlreadyAvailable* setUserDataAlreadyAvailable();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserDataAlreadyAvailable for datatype ServerAssignmentRequest
		*/
		void resetUserDataAlreadyAvailable();

		//!Function to get values
		/*!		Function to get UserDataAlreadyAvailable type of argument UserDataAlreadyAvailable for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		UserDataAlreadyAvailable* getUserDataAlreadyAvailable();

		SCSCFRestorationInfo* getSCSCFRestorationInfo();

		SCSCFRestorationInfo* setSCSCFRestorationInfo();

		void resetSCSCFRestorationInfo();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument MultipleRegistrationIndication for datatype ServerAssignmentRequest
		*/
		MultipleRegistrationIndication* setMultipleRegistrationIndication();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MultipleRegistrationIndication for datatype ServerAssignmentRequest
		*/
		void resetMultipleRegistrationIndication();

		//!Function to get values
		/*!		Function to get MultipleRegistrationIndication type of argument MultipleRegistrationIndication for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		MultipleRegistrationIndication* getMultipleRegistrationIndication();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument SessionPriority for datatype ServerAssignmentRequest
		*/
		SessionPriority* setSessionPriority();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionPriority for datatype ServerAssignmentRequest
		*/
		void resetSessionPriority();

		//!Function to get values
		/*!		Function to get SessionPriority type of argument SessionPriority for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		SessionPriority* getSessionPriority();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument SARFlags for datatype ServerAssignmentRequest
		*/
		Unsigned32* setSARFlags();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SARFlags for datatype ServerAssignmentRequest
		*/
		void resetSARFlags();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument SARFlags for datatype ServerAssignmentRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getSARFlags();

		FailedPCSCF* getFailedPCSCF();

		FailedPCSCF* setFailedPCSCF();

		void resetFailedPCSCF();

		list<CX::ProxyInfo*>* getProxyInfoGrpList();

		list<CX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype ServerAssignmentRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype ServerAssignmentRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ServerAssignmentRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ServerAssignmentRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ServerAssignmentRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
