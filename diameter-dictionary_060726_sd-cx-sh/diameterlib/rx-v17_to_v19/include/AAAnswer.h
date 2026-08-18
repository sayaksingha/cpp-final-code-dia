#ifndef RX_AAANSWER_H
#define RX_AAANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"
#include "rx/include/ProxyInfo.h"
#include "rx/include/DRMP.h"
#include "rx/include/ExperimentalResult.h"
#include "rx/include/AuthSessionState.h"
#include "rx/include/AccessNetworkChargingIdentifier.h"
#include "rx/include/AcceptableServiceInfo.h"
#include "rx/include/ANTrusted.h"
#include "rx/include/IPCANType.h"
#include "rx/include/MAInformation.h"
#include "rx/include/Flows.h"
#include "rx/include/OCSupportedFeatures.h"
#include "rx/include/OCOLR.h"
#include "rx/include/SupportedFeatures.h"
#include "rx/include/SubscriptionId.h"
#include "rx/include/UserEquipmentInfo.h"
#include "rx/include/UserEquipmentInfoExtension.h"
#include "rx/include/FailedAVP.h"
#include "rx/include/RedirectHostUsage.h"
#include "rx/include/Load.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace RX{
typedef enum _tags_AAAnswer
{
	AAAnswer_SESSIONID	= 0,
	AAAnswer_DRMP	= 1,
	AAAnswer_AUTHAPPLICATIONID	= 2,
	AAAnswer_ORIGINHOST	= 3,
	AAAnswer_ORIGINREALM	= 4,
	AAAnswer_RESULTCODE	= 5,
	AAAnswer_EXPERIMENTALRESULT	= 6,
	AAAnswer_AUTHSESSIONSTATE	= 7,
	AAAnswer_ACCESSNETWORKCHARGINGIDENTIFIER	= 8,
	AAAnswer_ACCESSNETWORKCHARGINGADDRESS	= 9,
	AAAnswer_ACCEPTABLESERVICEINFO	= 10,
	AAAnswer_ANGWADDRESS	= 11,
	AAAnswer_ANTRUSTED	= 12,
	AAAnswer_SERVICEAUTHORIZATIONINFO	= 13,
	AAAnswer_IPCANTYPE	= 14,
	AAAnswer_MAINFORMATION	= 15,
	AAAnswer_NETLOCACCESSSUPPORT	= 16,
	AAAnswer_RATTYPE	= 17,
	AAAnswer_FLOWS	= 18,
	AAAnswer_OCSUPPORTEDFEATURES	= 19,
	AAAnswer_OCOLR	= 20,
	AAAnswer_SUPPORTEDFEATURES	= 21,
	AAAnswer_SUBSCRIPTIONID	= 22,
	AAAnswer_USEREQUIPMENTINFO	= 23,
	AAAnswer_USEREQUIPMENTINFOEXTENSION	= 24,
	AAAnswer_3GPPSGSNMCCMNC	= 25,
	AAAnswer_NID	= 26,
	AAAnswer_CLASS	= 27,
	AAAnswer_ERRORMESSAGE	= 28,
	AAAnswer_ERRORREPORTINGHOST	= 29,
	AAAnswer_FAILEDAVP	= 30,
	AAAnswer_RETRYINTERVAL	= 31,
	AAAnswer_ORIGINSTATEID	= 32,
	AAAnswer_REDIRECTHOST	= 33,
	AAAnswer_REDIRECTHOSTUSAGE	= 34,
	AAAnswer_REDIRECTMAXCACHETIME	= 35,
	AAAnswer_PROXYINFO	= 36,
	AAAnswer_LOAD	= 37,
}AAAnswer_tags;

		//! Class Definition
		/*!		ClassName is AAAnswer
		*/
class AAAnswer : public DiameterBase 
{
	private:

		bitset<38> mTagsPresent;

		bitset<38> mMandatoryAvpCheckVal;

		bitset<38> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		Integer32*		mAuthApplicationId;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		Unsigned32*		mResultCode;

		AuthSessionState*		mAuthSessionState;

		Address*		mAccessNetworkChargingAddress;

		list<Address*>* 		mANGWAddressList;

		list<Address*>::iterator 		mANGWAddressIterator;

		ANTrusted*		mANTrusted;

		Unsigned32*		mServiceAuthorizationInfo;

		IPCANType*		mIPCANType;

		Unsigned32*		mNetLocAccessSupport;

		Unsigned32*		mRATType;

		OctetString*		m3GPPSGSNMCCMNC;

		OctetString*		mNID;

		OctetString*		mClass;

		OctetString*		mErrorMessage;

		OctetString*		mErrorReportingHost;

		Unsigned32*		mRetryInterval;

		Unsigned32*		mOriginStateId;

		list<OctetString*>* 		mRedirectHostList;

		list<OctetString*>::iterator 		mRedirectHostIterator;

		RedirectHostUsage*		mRedirectHostUsage;

		Unsigned32*		mRedirectMaxCacheTime;








		ExperimentalResult*	mExperimentalResultGrp;


		list<AccessNetworkChargingIdentifier*>*	mAccessNetworkChargingIdentifierGrpList;
		list<AccessNetworkChargingIdentifier*>::iterator	mAccessNetworkChargingIdentifierGrpIterator;


		AcceptableServiceInfo*	mAcceptableServiceInfoGrp;





		list<MAInformation*>*	mMAInformationGrpList;
		list<MAInformation*>::iterator	mMAInformationGrpIterator;



		list<Flows*>*	mFlowsGrpList;
		list<Flows*>::iterator	mFlowsGrpIterator;

		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		OCOLR*	mOCOLRGrp;

		list<SupportedFeatures*>*	mSupportedFeaturesGrpList;
		list<SupportedFeatures*>::iterator	mSupportedFeaturesGrpIterator;

		list<SubscriptionId*>*	mSubscriptionIdGrpList;
		list<SubscriptionId*>::iterator	mSubscriptionIdGrpIterator;

		UserEquipmentInfo*	mUserEquipmentInfoGrp;

		UserEquipmentInfoExtension*	mUserEquipmentInfoExtensionGrp;






		list<FailedAVP*>*	mFailedAVPGrpList;
		list<FailedAVP*>::iterator	mFailedAVPGrpIterator;






		list<RX::ProxyInfo*>*	mProxyInfoGrpList;
		list<RX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;

		list<Load*>*	mLoadGrpList;
		list<Load*>::iterator	mLoadGrpIterator;

	public:
		AAAnswer();

		AAAnswer(const AAAnswer &objAAAnswer) {

		mTagsPresent = objAAAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objAAAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAAAnswer.mMandatoryAvpSetVal;

		mTag = objAAAnswer.mTag;

		mDecodeFlag = objAAAnswer.mDecodeFlag;

		if(objAAAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objAAAnswer.mSessionId));

		if(objAAAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objAAAnswer.mDRMP));

		if(objAAAnswer.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objAAAnswer.mAuthApplicationId));

		if(objAAAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objAAAnswer.mOriginHost));

		if(objAAAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objAAAnswer.mOriginRealm));

		if(objAAAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objAAAnswer.mResultCode));

		if(objAAAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objAAAnswer.mExperimentalResultGrp);
		 }
		if(objAAAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objAAAnswer.mAuthSessionState));

		if(objAAAnswer.mAccessNetworkChargingIdentifierGrpList != NULL)
		 {
		 mAccessNetworkChargingIdentifierGrpList = new list<AccessNetworkChargingIdentifier*>;
		 for( auto element : *objAAAnswer.mAccessNetworkChargingIdentifierGrpList)
		 {
				 AccessNetworkChargingIdentifier *lAccessNetworkChargingIdentifier =  new AccessNetworkChargingIdentifier(*element);
				 mAccessNetworkChargingIdentifierGrpList->push_back(lAccessNetworkChargingIdentifier);
		 }
		 }
		if(objAAAnswer.mAccessNetworkChargingAddress != NULL)
		mAccessNetworkChargingAddress = new Address(*(objAAAnswer.mAccessNetworkChargingAddress));

		if(objAAAnswer.mAcceptableServiceInfoGrp != NULL)
		 {
				 mAcceptableServiceInfoGrp =  new AcceptableServiceInfo(*objAAAnswer.mAcceptableServiceInfoGrp);
		 }
		if(objAAAnswer.mANTrusted != NULL)
		mANTrusted = new ANTrusted(*(objAAAnswer.mANTrusted));

		if(objAAAnswer.mServiceAuthorizationInfo != NULL)
		mServiceAuthorizationInfo = new Unsigned32(*(objAAAnswer.mServiceAuthorizationInfo));

		if(objAAAnswer.mIPCANType != NULL)
		mIPCANType = new IPCANType(*(objAAAnswer.mIPCANType));

		if(objAAAnswer.mMAInformationGrpList != NULL)
		 {
		 mMAInformationGrpList = new list<MAInformation*>;
		 for( auto element : *objAAAnswer.mMAInformationGrpList)
		 {
				 MAInformation *lMAInformation =  new MAInformation(*element);
				 mMAInformationGrpList->push_back(lMAInformation);
		 }
		 }
		if(objAAAnswer.mNetLocAccessSupport != NULL)
		mNetLocAccessSupport = new Unsigned32(*(objAAAnswer.mNetLocAccessSupport));

		if(objAAAnswer.mRATType != NULL)
		mRATType = new Unsigned32(*(objAAAnswer.mRATType));

		if(objAAAnswer.mFlowsGrpList != NULL)
		 {
		 mFlowsGrpList = new list<Flows*>;
		 for( auto element : *objAAAnswer.mFlowsGrpList)
		 {
				 Flows *lFlows =  new Flows(*element);
				 mFlowsGrpList->push_back(lFlows);
		 }
		 }
		if(objAAAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objAAAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objAAAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objAAAnswer.mOCOLRGrp);
		 }
		if(objAAAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objAAAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objAAAnswer.mSubscriptionIdGrpList != NULL)
		 {
		 mSubscriptionIdGrpList = new list<SubscriptionId*>;
		 for( auto element : *objAAAnswer.mSubscriptionIdGrpList)
		 {
				 SubscriptionId *lSubscriptionId =  new SubscriptionId(*element);
				 mSubscriptionIdGrpList->push_back(lSubscriptionId);
		 }
		 }
		if(objAAAnswer.mUserEquipmentInfoGrp != NULL)
		 {
				 mUserEquipmentInfoGrp =  new UserEquipmentInfo(*objAAAnswer.mUserEquipmentInfoGrp);
		 }
		if(objAAAnswer.mUserEquipmentInfoExtensionGrp != NULL)
		 {
				 mUserEquipmentInfoExtensionGrp =  new UserEquipmentInfoExtension(*objAAAnswer.mUserEquipmentInfoExtensionGrp);
		 }
		if(objAAAnswer.m3GPPSGSNMCCMNC != NULL)
		m3GPPSGSNMCCMNC = new OctetString(*(objAAAnswer.m3GPPSGSNMCCMNC));

		if(objAAAnswer.mNID != NULL)
		mNID = new OctetString(*(objAAAnswer.mNID));

		if(objAAAnswer.mClass != NULL)
		mClass = new OctetString(*(objAAAnswer.mClass));

		if(objAAAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objAAAnswer.mErrorMessage));

		if(objAAAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objAAAnswer.mErrorReportingHost));

		if(objAAAnswer.mFailedAVPGrpList != NULL)
		 {
		 mFailedAVPGrpList = new list<FailedAVP*>;
		 for( auto element : *objAAAnswer.mFailedAVPGrpList)
		 {
				 FailedAVP *lFailedAVP =  new FailedAVP(*element);
				 mFailedAVPGrpList->push_back(lFailedAVP);
		 }
		 }
		if(objAAAnswer.mRetryInterval != NULL)
		mRetryInterval = new Unsigned32(*(objAAAnswer.mRetryInterval));

		if(objAAAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objAAAnswer.mOriginStateId));

		if(objAAAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objAAAnswer.mRedirectHostUsage));

		if(objAAAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objAAAnswer.mRedirectMaxCacheTime));

		if(objAAAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objAAAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objAAAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objAAAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		}

		void operator = (const AAAnswer &objAAAnswer) {

		mTagsPresent = objAAAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objAAAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAAAnswer.mMandatoryAvpSetVal;

		mTag = objAAAnswer.mTag;

		mDecodeFlag = objAAAnswer.mDecodeFlag;

		if(objAAAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objAAAnswer.mSessionId));

		if(objAAAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objAAAnswer.mDRMP));

		if(objAAAnswer.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objAAAnswer.mAuthApplicationId));

		if(objAAAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objAAAnswer.mOriginHost));

		if(objAAAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objAAAnswer.mOriginRealm));

		if(objAAAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objAAAnswer.mResultCode));

		if(objAAAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objAAAnswer.mExperimentalResultGrp);
		 }
		if(objAAAnswer.mAuthSessionState != NULL)
		mAuthSessionState = new AuthSessionState(*(objAAAnswer.mAuthSessionState));

		if(objAAAnswer.mAccessNetworkChargingIdentifierGrpList != NULL)
		 {
		 mAccessNetworkChargingIdentifierGrpList = new list<AccessNetworkChargingIdentifier*>;
		 for( auto element : *objAAAnswer.mAccessNetworkChargingIdentifierGrpList)
		 {
				 AccessNetworkChargingIdentifier *lAccessNetworkChargingIdentifier =  new AccessNetworkChargingIdentifier(*element);
				 mAccessNetworkChargingIdentifierGrpList->push_back(lAccessNetworkChargingIdentifier);
		 }
		 }
		if(objAAAnswer.mAccessNetworkChargingAddress != NULL)
		mAccessNetworkChargingAddress = new Address(*(objAAAnswer.mAccessNetworkChargingAddress));

		if(objAAAnswer.mAcceptableServiceInfoGrp != NULL)
		 {
				 mAcceptableServiceInfoGrp =  new AcceptableServiceInfo(*objAAAnswer.mAcceptableServiceInfoGrp);
		 }
		if(objAAAnswer.mANTrusted != NULL)
		mANTrusted = new ANTrusted(*(objAAAnswer.mANTrusted));

		if(objAAAnswer.mServiceAuthorizationInfo != NULL)
		mServiceAuthorizationInfo = new Unsigned32(*(objAAAnswer.mServiceAuthorizationInfo));

		if(objAAAnswer.mIPCANType != NULL)
		mIPCANType = new IPCANType(*(objAAAnswer.mIPCANType));

		if(objAAAnswer.mMAInformationGrpList != NULL)
		 {
		 mMAInformationGrpList = new list<MAInformation*>;
		 for( auto element : *objAAAnswer.mMAInformationGrpList)
		 {
				 MAInformation *lMAInformation =  new MAInformation(*element);
				 mMAInformationGrpList->push_back(lMAInformation);
		 }
		 }
		if(objAAAnswer.mNetLocAccessSupport != NULL)
		mNetLocAccessSupport = new Unsigned32(*(objAAAnswer.mNetLocAccessSupport));

		if(objAAAnswer.mRATType != NULL)
		mRATType = new Unsigned32(*(objAAAnswer.mRATType));

		if(objAAAnswer.mFlowsGrpList != NULL)
		 {
		 mFlowsGrpList = new list<Flows*>;
		 for( auto element : *objAAAnswer.mFlowsGrpList)
		 {
				 Flows *lFlows =  new Flows(*element);
				 mFlowsGrpList->push_back(lFlows);
		 }
		 }
		if(objAAAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objAAAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objAAAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objAAAnswer.mOCOLRGrp);
		 }
		if(objAAAnswer.mSupportedFeaturesGrpList != NULL)
		 {
		 mSupportedFeaturesGrpList = new list<SupportedFeatures*>;
		 for( auto element : *objAAAnswer.mSupportedFeaturesGrpList)
		 {
				 SupportedFeatures *lSupportedFeatures =  new SupportedFeatures(*element);
				 mSupportedFeaturesGrpList->push_back(lSupportedFeatures);
		 }
		 }
		if(objAAAnswer.mSubscriptionIdGrpList != NULL)
		 {
		 mSubscriptionIdGrpList = new list<SubscriptionId*>;
		 for( auto element : *objAAAnswer.mSubscriptionIdGrpList)
		 {
				 SubscriptionId *lSubscriptionId =  new SubscriptionId(*element);
				 mSubscriptionIdGrpList->push_back(lSubscriptionId);
		 }
		 }
		if(objAAAnswer.mUserEquipmentInfoGrp != NULL)
		 {
				 mUserEquipmentInfoGrp =  new UserEquipmentInfo(*objAAAnswer.mUserEquipmentInfoGrp);
		 }
		if(objAAAnswer.mUserEquipmentInfoExtensionGrp != NULL)
		 {
				 mUserEquipmentInfoExtensionGrp =  new UserEquipmentInfoExtension(*objAAAnswer.mUserEquipmentInfoExtensionGrp);
		 }
		if(objAAAnswer.m3GPPSGSNMCCMNC != NULL)
		m3GPPSGSNMCCMNC = new OctetString(*(objAAAnswer.m3GPPSGSNMCCMNC));

		if(objAAAnswer.mNID != NULL)
		mNID = new OctetString(*(objAAAnswer.mNID));

		if(objAAAnswer.mClass != NULL)
		mClass = new OctetString(*(objAAAnswer.mClass));

		if(objAAAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objAAAnswer.mErrorMessage));

		if(objAAAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objAAAnswer.mErrorReportingHost));

		if(objAAAnswer.mFailedAVPGrpList != NULL)
		 {
		 mFailedAVPGrpList = new list<FailedAVP*>;
		 for( auto element : *objAAAnswer.mFailedAVPGrpList)
		 {
				 FailedAVP *lFailedAVP =  new FailedAVP(*element);
				 mFailedAVPGrpList->push_back(lFailedAVP);
		 }
		 }
		if(objAAAnswer.mRetryInterval != NULL)
		mRetryInterval = new Unsigned32(*(objAAAnswer.mRetryInterval));

		if(objAAAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objAAAnswer.mOriginStateId));

		if(objAAAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objAAAnswer.mRedirectHostUsage));

		if(objAAAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objAAAnswer.mRedirectMaxCacheTime));

		if(objAAAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objAAAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objAAAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objAAAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		}

		virtual ~AAAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype AAAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype AAAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype AAAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype AAAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument AuthApplicationId for datatype AAAnswer
		*/
		Integer32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype AAAnswer
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument AuthApplicationId for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getAuthApplicationId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype AAAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype AAAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype AAAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype AAAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype AAAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype AAAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AuthSessionState for datatype AAAnswer
		*/
		AuthSessionState* setAuthSessionState();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthSessionState for datatype AAAnswer
		*/
		void resetAuthSessionState();

		//!Function to get values
		/*!		Function to get AuthSessionState type of argument AuthSessionState for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		AuthSessionState* getAuthSessionState();

		list<AccessNetworkChargingIdentifier*>* getAccessNetworkChargingIdentifierGrpList();

		list<AccessNetworkChargingIdentifier*>* setAccessNetworkChargingIdentifierGrpList();

		void resetAccessNetworkChargingIdentifierGrpList();

		//!Function to set values
		/*!		Function to set the recent Address type of argument AccessNetworkChargingAddress for datatype AAAnswer
		*/
		Address* setAccessNetworkChargingAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AccessNetworkChargingAddress for datatype AAAnswer
		*/
		void resetAccessNetworkChargingAddress();

		//!Function to get values
		/*!		Function to get Address type of argument AccessNetworkChargingAddress for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Address* getAccessNetworkChargingAddress();

		AcceptableServiceInfo* getAcceptableServiceInfo();

		AcceptableServiceInfo* setAcceptableServiceInfo();

		void resetAcceptableServiceInfo();

		list<Address*>* getANGWAddressList();

		list<Address*>* setANGWAddressList();

		void resetANGWAddressList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ANTrusted for datatype AAAnswer
		*/
		ANTrusted* setANTrusted();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ANTrusted for datatype AAAnswer
		*/
		void resetANTrusted();

		//!Function to get values
		/*!		Function to get ANTrusted type of argument ANTrusted for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		ANTrusted* getANTrusted();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ServiceAuthorizationInfo for datatype AAAnswer
		*/
		Unsigned32* setServiceAuthorizationInfo();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServiceAuthorizationInfo for datatype AAAnswer
		*/
		void resetServiceAuthorizationInfo();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ServiceAuthorizationInfo for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getServiceAuthorizationInfo();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument IPCANType for datatype AAAnswer
		*/
		IPCANType* setIPCANType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument IPCANType for datatype AAAnswer
		*/
		void resetIPCANType();

		//!Function to get values
		/*!		Function to get IPCANType type of argument IPCANType for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		IPCANType* getIPCANType();

		list<MAInformation*>* getMAInformationGrpList();

		list<MAInformation*>* setMAInformationGrpList();

		void resetMAInformationGrpList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument NetLocAccessSupport for datatype AAAnswer
		*/
		Unsigned32* setNetLocAccessSupport();

		//! Function to reset 
		/*!		Function to reset NULL type of argument NetLocAccessSupport for datatype AAAnswer
		*/
		void resetNetLocAccessSupport();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument NetLocAccessSupport for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getNetLocAccessSupport();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RATType for datatype AAAnswer
		*/
		Unsigned32* setRATType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RATType for datatype AAAnswer
		*/
		void resetRATType();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RATType for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRATType();

		list<Flows*>* getFlowsGrpList();

		list<Flows*>* setFlowsGrpList();

		void resetFlowsGrpList();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		OCOLR* getOCOLR();

		OCOLR* setOCOLR();

		void resetOCOLR();

		list<SupportedFeatures*>* getSupportedFeaturesGrpList();

		list<SupportedFeatures*>* setSupportedFeaturesGrpList();

		void resetSupportedFeaturesGrpList();

		list<SubscriptionId*>* getSubscriptionIdGrpList();

		list<SubscriptionId*>* setSubscriptionIdGrpList();

		void resetSubscriptionIdGrpList();

		UserEquipmentInfo* getUserEquipmentInfo();

		UserEquipmentInfo* setUserEquipmentInfo();

		void resetUserEquipmentInfo();

		UserEquipmentInfoExtension* getUserEquipmentInfoExtension();

		UserEquipmentInfoExtension* setUserEquipmentInfoExtension();

		void resetUserEquipmentInfoExtension();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPSGSNMCCMNC for datatype AAAnswer
		*/
		OctetString* set3GPPSGSNMCCMNC();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPSGSNMCCMNC for datatype AAAnswer
		*/
		void reset3GPPSGSNMCCMNC();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPSGSNMCCMNC for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPSGSNMCCMNC();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument NID for datatype AAAnswer
		*/
		OctetString* setNID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument NID for datatype AAAnswer
		*/
		void resetNID();

		//!Function to get values
		/*!		Function to get OctetString type of argument NID for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getNID();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument Class for datatype AAAnswer
		*/
		OctetString* setClass();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Class for datatype AAAnswer
		*/
		void resetClass();

		//!Function to get values
		/*!		Function to get OctetString type of argument Class for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getClass();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype AAAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype AAAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorReportingHost for datatype AAAnswer
		*/
		OctetString* setErrorReportingHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorReportingHost for datatype AAAnswer
		*/
		void resetErrorReportingHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorReportingHost for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorReportingHost();

		list<FailedAVP*>* getFailedAVPGrpList();

		list<FailedAVP*>* setFailedAVPGrpList();

		void resetFailedAVPGrpList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RetryInterval for datatype AAAnswer
		*/
		Unsigned32* setRetryInterval();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RetryInterval for datatype AAAnswer
		*/
		void resetRetryInterval();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RetryInterval for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRetryInterval();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype AAAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype AAAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		list<OctetString*>* getRedirectHostList();

		list<OctetString*>* setRedirectHostList();

		void resetRedirectHostList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RedirectHostUsage for datatype AAAnswer
		*/
		RedirectHostUsage* setRedirectHostUsage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectHostUsage for datatype AAAnswer
		*/
		void resetRedirectHostUsage();

		//!Function to get values
		/*!		Function to get RedirectHostUsage type of argument RedirectHostUsage for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		RedirectHostUsage* getRedirectHostUsage();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RedirectMaxCacheTime for datatype AAAnswer
		*/
		Unsigned32* setRedirectMaxCacheTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectMaxCacheTime for datatype AAAnswer
		*/
		void resetRedirectMaxCacheTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RedirectMaxCacheTime for datatype AAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRedirectMaxCacheTime();

		list<RX::ProxyInfo*>* getProxyInfoGrpList();

		list<RX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<Load*>* getLoadGrpList();

		list<Load*>* setLoadGrpList();

		void resetLoadGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype AAAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype AAAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype AAAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype AAAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AAAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
