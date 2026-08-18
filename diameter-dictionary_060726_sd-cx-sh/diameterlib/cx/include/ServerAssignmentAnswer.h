#ifndef CX_SERVERASSIGNMENTANSWER_H
#define CX_SERVERASSIGNMENTANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/DRMP.h"
#include "cx/include/VendorSpecificApplicationId.h"
#include "cx/include/ExperimentalResult.h"
#include "cx/include/AuthSessionState.h"
#include "cx/include/OCSupportedFeatures.h"
#include "cx/include/OCOLR.h"
#include "cx/include/Load.h"
#include "cx/include/SupportedFeatures.h"
#include "cx/include/ChargingInformation.h"
#include "cx/include/AssociatedIdentities.h"
#include "cx/include/LooseRouteIndication.h"
#include "cx/include/SCSCFRestorationInfo.h"
#include "cx/include/AssociatedRegisteredIdentities.h"
#include "cx/include/PriviledgedSenderIndication.h"
#include "cx/include/AllowedWAFWWSFIdentities.h"
#include "cx/include/FailedAVP.h"
#include "cx/include/ProxyInfo.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace CX{
typedef enum _tags_ServerAssignmentAnswer
{
	ServerAssignmentAnswer_SESSIONID	= 0,
	ServerAssignmentAnswer_DRMP	= 1,
	ServerAssignmentAnswer_VENDORSPECIFICAPPLICATIONID	= 2,
	ServerAssignmentAnswer_RESULTCODE	= 3,
	ServerAssignmentAnswer_EXPERIMENTALRESULT	= 4,
	ServerAssignmentAnswer_AUTHSESSIONSTATE	= 5,
	ServerAssignmentAnswer_ORIGINHOST	= 6,
	ServerAssignmentAnswer_ORIGINREALM	= 7,
	ServerAssignmentAnswer_USERNAME	= 8,
	ServerAssignmentAnswer_OCSUPPORTEDFEATURES	= 9,
	ServerAssignmentAnswer_OCOLR	= 10,
	ServerAssignmentAnswer_LOAD	= 11,
	ServerAssignmentAnswer_SUPPORTEDFEATURES	= 12,
	ServerAssignmentAnswer_USERDATA	= 13,
	ServerAssignmentAnswer_CHARGINGINFORMATION	= 14,
	ServerAssignmentAnswer_ASSOCIATEDIDENTITIES	= 15,
	ServerAssignmentAnswer_LOOSEROUTEINDICATION	= 16,
	ServerAssignmentAnswer_SCSCFRESTORATIONINFO	= 17,
	ServerAssignmentAnswer_ASSOCIATEDREGISTEREDIDENTITIES	= 18,
	ServerAssignmentAnswer_SERVERNAME	= 19,
	ServerAssignmentAnswer_WILDCARDEDPUBLICIDENTITY	= 20,
	ServerAssignmentAnswer_PRIVILEDGEDSENDERINDICATION	= 21,
	ServerAssignmentAnswer_ALLOWEDWAFWWSFIDENTITIES	= 22,
	ServerAssignmentAnswer_ERRORMESSAGE	= 23,
	ServerAssignmentAnswer_FAILEDAVP	= 24,
	ServerAssignmentAnswer_PROXYINFO	= 25,
	ServerAssignmentAnswer_ROUTERECORD	= 26,
}ServerAssignmentAnswer_tags;

		//! Class Definition
		/*!		ClassName is ServerAssignmentAnswer
		*/
class ServerAssignmentAnswer : public DiameterBase 
{
	private:

		bitset<27> mTagsPresent;

		bitset<27> mMandatoryAvpCheckVal;

		bitset<27> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		Unsigned32*		mResultCode;

		AuthSessionState*		mAuthSessionState;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mUserName;

		OctetString*		mUserData;

		LooseRouteIndication*		mLooseRouteIndication;

		OctetString*		mServerName;

		OctetString*		mWildcardedPublicIdentity;

		PriviledgedSenderIndication*		mPriviledgedSenderIndication;

		OctetString*		mErrorMessage;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;




		VendorSpecificApplicationId*	mVendorSpecificApplicationIdGrp;


		ExperimentalResult*	mExperimentalResultGrp;





		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		OCOLR*	mOCOLRGrp;

		list<Load*>*	mLoadGrpList;
		list<Load*>::iterator	mLoadGrpIterator;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;


		ChargingInformation*	mChargingInformationGrp;

		AssociatedIdentities*	mAssociatedIdentitiesGrp;


		list<SCSCFRestorationInfo*>*	mSCSCFRestorationInfoGrpList;
		list<SCSCFRestorationInfo*>::iterator	mSCSCFRestorationInfoGrpIterator;

		AssociatedRegisteredIdentities*	mAssociatedRegisteredIdentitiesGrp;




		AllowedWAFWWSFIdentities*	mAllowedWAFWWSFIdentitiesGrp;


		FailedAVP*	mFailedAVPGrp;

		list<CX::ProxyInfo*>*	mProxyInfoGrpList;
		list<CX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		ServerAssignmentAnswer();

		ServerAssignmentAnswer(const ServerAssignmentAnswer &objServerAssignmentAnswer) {

		mTagsPresent = objServerAssignmentAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objServerAssignmentAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objServerAssignmentAnswer.mMandatoryAvpSetVal;

		mTag = objServerAssignmentAnswer.mTag;

		mDecodeFlag = objServerAssignmentAnswer.mDecodeFlag;

		if(objServerAssignmentAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objServerAssignmentAnswer.mSessionId));

		if(objServerAssignmentAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objServerAssignmentAnswer.mDRMP));

		if(objServerAssignmentAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objServerAssignmentAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objServerAssignmentAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objServerAssignmentAnswer.mResultCode));

		if(objServerAssignmentAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objServerAssignmentAnswer.mExperimentalResultGrp);
		 }
		if(objServerAssignmentAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objServerAssignmentAnswer.mAuthSessionState));

		if(objServerAssignmentAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objServerAssignmentAnswer.mOriginHost));

		if(objServerAssignmentAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objServerAssignmentAnswer.mOriginRealm));

		if(objServerAssignmentAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objServerAssignmentAnswer.mUserName));

		if(objServerAssignmentAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objServerAssignmentAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objServerAssignmentAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objServerAssignmentAnswer.mOCOLRGrp);
		 }
		if(objServerAssignmentAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objServerAssignmentAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objServerAssignmentAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objServerAssignmentAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objServerAssignmentAnswer.mUserData != NULL)
		mUserData = new OctetString(*(objServerAssignmentAnswer.mUserData));

		if(objServerAssignmentAnswer.mChargingInformationGrp != NULL)
		 {
				 mChargingInformationGrp =  new ChargingInformation(*objServerAssignmentAnswer.mChargingInformationGrp);
		 }
		if(objServerAssignmentAnswer.mAssociatedIdentitiesGrp != NULL)
		 {
				 mAssociatedIdentitiesGrp =  new AssociatedIdentities(*objServerAssignmentAnswer.mAssociatedIdentitiesGrp);
		 }
		if(objServerAssignmentAnswer.mLooseRouteIndication != NULL)
		mLooseRouteIndication = new LooseRouteIndication(*(objServerAssignmentAnswer.mLooseRouteIndication));

		if(objServerAssignmentAnswer.mSCSCFRestorationInfoGrpList != NULL)
		 {
		 mSCSCFRestorationInfoGrpList = new list<SCSCFRestorationInfo*>;
		 for( auto element : *objServerAssignmentAnswer.mSCSCFRestorationInfoGrpList)
		 {
				 SCSCFRestorationInfo *lSCSCFRestorationInfo =  new SCSCFRestorationInfo(*element);
				 mSCSCFRestorationInfoGrpList->push_back(lSCSCFRestorationInfo);
		 }
		 }
		if(objServerAssignmentAnswer.mAssociatedRegisteredIdentitiesGrp != NULL)
		 {
				 mAssociatedRegisteredIdentitiesGrp =  new AssociatedRegisteredIdentities(*objServerAssignmentAnswer.mAssociatedRegisteredIdentitiesGrp);
		 }
		if(objServerAssignmentAnswer.mServerName != NULL)
		mServerName = new OctetString(*(objServerAssignmentAnswer.mServerName));

		if(objServerAssignmentAnswer.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objServerAssignmentAnswer.mWildcardedPublicIdentity));

		if(objServerAssignmentAnswer.mPriviledgedSenderIndication != NULL)
		mPriviledgedSenderIndication = new PriviledgedSenderIndication(*(objServerAssignmentAnswer.mPriviledgedSenderIndication));

		if(objServerAssignmentAnswer.mAllowedWAFWWSFIdentitiesGrp != NULL)
		 {
				 mAllowedWAFWWSFIdentitiesGrp =  new AllowedWAFWWSFIdentities(*objServerAssignmentAnswer.mAllowedWAFWWSFIdentitiesGrp);
		 }
		if(objServerAssignmentAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objServerAssignmentAnswer.mErrorMessage));

		if(objServerAssignmentAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objServerAssignmentAnswer.mFailedAVPGrp);
		 }
		if(objServerAssignmentAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objServerAssignmentAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const ServerAssignmentAnswer &objServerAssignmentAnswer) {

		mTagsPresent = objServerAssignmentAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objServerAssignmentAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objServerAssignmentAnswer.mMandatoryAvpSetVal;

		mTag = objServerAssignmentAnswer.mTag;

		mDecodeFlag = objServerAssignmentAnswer.mDecodeFlag;

		if(objServerAssignmentAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objServerAssignmentAnswer.mSessionId));

		if(objServerAssignmentAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objServerAssignmentAnswer.mDRMP));

		if(objServerAssignmentAnswer.mVendorSpecificApplicationIdGrp != NULL)
		 {
				 mVendorSpecificApplicationIdGrp =  new VendorSpecificApplicationId(*objServerAssignmentAnswer.mVendorSpecificApplicationIdGrp);
		 }
		if(objServerAssignmentAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objServerAssignmentAnswer.mResultCode));

		if(objServerAssignmentAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objServerAssignmentAnswer.mExperimentalResultGrp);
		 }
		if(objServerAssignmentAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objServerAssignmentAnswer.mAuthSessionState));

		if(objServerAssignmentAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objServerAssignmentAnswer.mOriginHost));

		if(objServerAssignmentAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objServerAssignmentAnswer.mOriginRealm));

		if(objServerAssignmentAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objServerAssignmentAnswer.mUserName));

		if(objServerAssignmentAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objServerAssignmentAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objServerAssignmentAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objServerAssignmentAnswer.mOCOLRGrp);
		 }
		if(objServerAssignmentAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objServerAssignmentAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		if(objServerAssignmentAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objServerAssignmentAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objServerAssignmentAnswer.mUserData != NULL)
		mUserData = new OctetString(*(objServerAssignmentAnswer.mUserData));

		if(objServerAssignmentAnswer.mChargingInformationGrp != NULL)
		 {
				 mChargingInformationGrp =  new ChargingInformation(*objServerAssignmentAnswer.mChargingInformationGrp);
		 }
		if(objServerAssignmentAnswer.mAssociatedIdentitiesGrp != NULL)
		 {
				 mAssociatedIdentitiesGrp =  new AssociatedIdentities(*objServerAssignmentAnswer.mAssociatedIdentitiesGrp);
		 }
		if(objServerAssignmentAnswer.mLooseRouteIndication != NULL)
		mLooseRouteIndication = new LooseRouteIndication(*(objServerAssignmentAnswer.mLooseRouteIndication));

		if(objServerAssignmentAnswer.mSCSCFRestorationInfoGrpList != NULL)
		 {
		 mSCSCFRestorationInfoGrpList = new list<SCSCFRestorationInfo*>;
		 for( auto element : *objServerAssignmentAnswer.mSCSCFRestorationInfoGrpList)
		 {
				 SCSCFRestorationInfo *lSCSCFRestorationInfo =  new SCSCFRestorationInfo(*element);
				 mSCSCFRestorationInfoGrpList->push_back(lSCSCFRestorationInfo);
		 }
		 }
		if(objServerAssignmentAnswer.mAssociatedRegisteredIdentitiesGrp != NULL)
		 {
				 mAssociatedRegisteredIdentitiesGrp =  new AssociatedRegisteredIdentities(*objServerAssignmentAnswer.mAssociatedRegisteredIdentitiesGrp);
		 }
		if(objServerAssignmentAnswer.mServerName != NULL)
		mServerName = new OctetString(*(objServerAssignmentAnswer.mServerName));

		if(objServerAssignmentAnswer.mWildcardedPublicIdentity != NULL)
		mWildcardedPublicIdentity = new OctetString(*(objServerAssignmentAnswer.mWildcardedPublicIdentity));

		if(objServerAssignmentAnswer.mPriviledgedSenderIndication != NULL)
		mPriviledgedSenderIndication = new PriviledgedSenderIndication(*(objServerAssignmentAnswer.mPriviledgedSenderIndication));

		if(objServerAssignmentAnswer.mAllowedWAFWWSFIdentitiesGrp != NULL)
		 {
				 mAllowedWAFWWSFIdentitiesGrp =  new AllowedWAFWWSFIdentities(*objServerAssignmentAnswer.mAllowedWAFWWSFIdentitiesGrp);
		 }
		if(objServerAssignmentAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objServerAssignmentAnswer.mErrorMessage));

		if(objServerAssignmentAnswer.mFailedAVPGrp != NULL)
		 {
				 mFailedAVPGrp =  new FailedAVP(*objServerAssignmentAnswer.mFailedAVPGrp);
		 }
		if(objServerAssignmentAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<CX::ProxyInfo*>;
		 for( auto element : *objServerAssignmentAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~ServerAssignmentAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype ServerAssignmentAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype ServerAssignmentAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype ServerAssignmentAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype ServerAssignmentAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		VendorSpecificApplicationId* getVendorSpecificApplicationId();

		VendorSpecificApplicationId* setVendorSpecificApplicationId();

		void resetVendorSpecificApplicationId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype ServerAssignmentAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype ServerAssignmentAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype ServerAssignmentAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype ServerAssignmentAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype ServerAssignmentAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype ServerAssignmentAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype ServerAssignmentAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype ServerAssignmentAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype ServerAssignmentAnswer
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype ServerAssignmentAnswer
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		OCOLR* getOCOLR();

		OCOLR* setOCOLR();

		void resetOCOLR();

		list<Load*>* getLoadGrpList();

		list<Load*>* setLoadGrpList();

		void resetLoadGrpList();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserData for datatype ServerAssignmentAnswer
		*/
		OctetString* setUserData();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserData for datatype ServerAssignmentAnswer
		*/
		void resetUserData();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserData for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserData();

		ChargingInformation* getChargingInformation();

		ChargingInformation* setChargingInformation();

		void resetChargingInformation();

		AssociatedIdentities* getAssociatedIdentities();

		AssociatedIdentities* setAssociatedIdentities();

		void resetAssociatedIdentities();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument LooseRouteIndication for datatype ServerAssignmentAnswer
		*/
		LooseRouteIndication* setLooseRouteIndication();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LooseRouteIndication for datatype ServerAssignmentAnswer
		*/
		void resetLooseRouteIndication();

		//!Function to get values
		/*!		Function to get LooseRouteIndication type of argument LooseRouteIndication for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		LooseRouteIndication* getLooseRouteIndication();

		list<SCSCFRestorationInfo*>* getSCSCFRestorationInfoGrpList();

		list<SCSCFRestorationInfo*>* setSCSCFRestorationInfoGrpList();

		void resetSCSCFRestorationInfoGrpList();

		AssociatedRegisteredIdentities* getAssociatedRegisteredIdentities();

		AssociatedRegisteredIdentities* setAssociatedRegisteredIdentities();

		void resetAssociatedRegisteredIdentities();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ServerName for datatype ServerAssignmentAnswer
		*/
		OctetString* setServerName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServerName for datatype ServerAssignmentAnswer
		*/
		void resetServerName();

		//!Function to get values
		/*!		Function to get OctetString type of argument ServerName for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getServerName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument WildcardedPublicIdentity for datatype ServerAssignmentAnswer
		*/
		OctetString* setWildcardedPublicIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument WildcardedPublicIdentity for datatype ServerAssignmentAnswer
		*/
		void resetWildcardedPublicIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument WildcardedPublicIdentity for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getWildcardedPublicIdentity();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument PriviledgedSenderIndication for datatype ServerAssignmentAnswer
		*/
		PriviledgedSenderIndication* setPriviledgedSenderIndication();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PriviledgedSenderIndication for datatype ServerAssignmentAnswer
		*/
		void resetPriviledgedSenderIndication();

		//!Function to get values
		/*!		Function to get PriviledgedSenderIndication type of argument PriviledgedSenderIndication for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		PriviledgedSenderIndication* getPriviledgedSenderIndication();

		AllowedWAFWWSFIdentities* getAllowedWAFWWSFIdentities();

		AllowedWAFWWSFIdentities* setAllowedWAFWWSFIdentities();

		void resetAllowedWAFWWSFIdentities();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype ServerAssignmentAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype ServerAssignmentAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype ServerAssignmentAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		FailedAVP* getFailedAVP();

		FailedAVP* setFailedAVP();

		void resetFailedAVP();

		list<CX::ProxyInfo*>* getProxyInfoGrpList();

		list<CX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype ServerAssignmentAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype ServerAssignmentAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ServerAssignmentAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ServerAssignmentAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ServerAssignmentAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
