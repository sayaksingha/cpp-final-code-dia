#ifndef RX_STANSWER_H
#define RX_STANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"
#include "rx/include/ProxyInfo.h"
#include "rx/include/DRMP.h"
#include "rx/include/OCSupportedFeatures.h"
#include "rx/include/OCOLR.h"
#include "rx/include/FailedAVP.h"
#include "rx/include/SponsoredConnectivityData.h"
#include "rx/include/FiveGSRANNASReleaseCause.h"
#include "rx/include/WirelineUserLocationInfo.h"
#include "rx/include/RedirectHostUsage.h"
#include "rx/include/Load.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace RX{
typedef enum _tags_STAnswer
{
	STAnswer_SESSIONID	= 0,
	STAnswer_DRMP	= 1,
	STAnswer_ORIGINHOST	= 2,
	STAnswer_ORIGINREALM	= 3,
	STAnswer_RESULTCODE	= 4,
	STAnswer_ERRORMESSAGE	= 5,
	STAnswer_ERRORREPORTINGHOST	= 6,
	STAnswer_OCSUPPORTEDFEATURES	= 7,
	STAnswer_OCOLR	= 8,
	STAnswer_FAILEDAVP	= 9,
	STAnswer_SPONSOREDCONNECTIVITYDATA	= 10,
	STAnswer_ORIGINSTATEID	= 11,
	STAnswer_3GPPUSERLOCATIONINFO	= 12,
	STAnswer_USERLOCATIONINFOTIME	= 13,
	STAnswer_3GPPMSTIMEZONE	= 14,
	STAnswer_RANNASRELEASECAUSE	= 15,
	STAnswer_FIVEGSRANNASRELEASECAUSE	= 16,
	STAnswer_3GPPSGSNMCCMNC	= 17,
	STAnswer_NID	= 18,
	STAnswer_TWANIDENTIFIER	= 19,
	STAnswer_TCPSOURCEPORT	= 20,
	STAnswer_UDPSOURCEPORT	= 21,
	STAnswer_UELOCALIPADDRESS	= 22,
	STAnswer_NETLOCACCESSSUPPORT	= 23,
	STAnswer_WIRELINEUSERLOCATIONINFO	= 24,
	STAnswer_CLASS	= 25,
	STAnswer_REDIRECTHOST	= 26,
	STAnswer_REDIRECTHOSTUSAGE	= 27,
	STAnswer_REDIRECTMAXCACHETIME	= 28,
	STAnswer_PROXYINFO	= 29,
	STAnswer_LOAD	= 30,
}STAnswer_tags;

		//! Class Definition
		/*!		ClassName is STAnswer
		*/
class STAnswer : public DiameterBase 
{
	private:

		bitset<31> mTagsPresent;

		bitset<31> mMandatoryAvpCheckVal;

		bitset<31> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		Unsigned32*		mResultCode;

		OctetString*		mErrorMessage;

		OctetString*		mErrorReportingHost;

		Unsigned32*		mOriginStateId;

		OctetString*		m3GPPUserLocationInfo;

		Time*		mUserLocationInfoTime;

		OctetString*		m3GPPMSTimeZone;

		OctetString*		mRANNASReleaseCause;

		OctetString*		m3GPPSGSNMCCMNC;

		OctetString*		mNID;

		OctetString*		mTWANIdentifier;

		Unsigned32*		mTCPSourcePort;

		Unsigned32*		mUDPSourcePort;

		Address*		mUELocalIPAddress;

		Unsigned32*		mNetLocAccessSupport;

		OctetString*		mClass;

		list<OctetString*>* 		mRedirectHostList;

		list<OctetString*>::iterator 		mRedirectHostIterator;

		RedirectHostUsage*		mRedirectHostUsage;

		Unsigned32*		mRedirectMaxCacheTime;









		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		OCOLR*	mOCOLRGrp;

		list<FailedAVP*>*	mFailedAVPGrpList;
		list<FailedAVP*>::iterator	mFailedAVPGrpIterator;

		list<SponsoredConnectivityData*>*	mSponsoredConnectivityDataGrpList;
		list<SponsoredConnectivityData*>::iterator	mSponsoredConnectivityDataGrpIterator;






		list<FiveGSRANNASReleaseCause*>*	mFiveGSRANNASReleaseCauseGrpList;
		list<FiveGSRANNASReleaseCause*>::iterator	mFiveGSRANNASReleaseCauseGrpIterator;








		list<WirelineUserLocationInfo*>*	mWirelineUserLocationInfoGrpList;
		list<WirelineUserLocationInfo*>::iterator	mWirelineUserLocationInfoGrpIterator;





		list<RX::ProxyInfo*>*	mProxyInfoGrpList;
		list<RX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;

		list<Load*>*	mLoadGrpList;
		list<Load*>::iterator	mLoadGrpIterator;

	public:
		STAnswer();

		STAnswer(const STAnswer &objSTAnswer) {

		mTagsPresent = objSTAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objSTAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSTAnswer.mMandatoryAvpSetVal;

		mTag = objSTAnswer.mTag;

		mDecodeFlag = objSTAnswer.mDecodeFlag;

		if(objSTAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objSTAnswer.mSessionId));

		if(objSTAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objSTAnswer.mDRMP));

		if(objSTAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSTAnswer.mOriginHost));

		if(objSTAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSTAnswer.mOriginRealm));

		if(objSTAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objSTAnswer.mResultCode));

		if(objSTAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objSTAnswer.mErrorMessage));

		if(objSTAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objSTAnswer.mErrorReportingHost));

		if(objSTAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objSTAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objSTAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objSTAnswer.mOCOLRGrp);
		 }
		if(objSTAnswer.mFailedAVPGrpList != NULL)
		 {
		 mFailedAVPGrpList = new list<FailedAVP*>;
		 for( auto element : *objSTAnswer.mFailedAVPGrpList)
		 {
				 FailedAVP *lFailedAVP =  new FailedAVP(*element);
				 mFailedAVPGrpList->push_back(lFailedAVP);
		 }
		 }
		if(objSTAnswer.mSponsoredConnectivityDataGrpList != NULL)
		 {
		 mSponsoredConnectivityDataGrpList = new list<SponsoredConnectivityData*>;
		 for( auto element : *objSTAnswer.mSponsoredConnectivityDataGrpList)
		 {
				 SponsoredConnectivityData *lSponsoredConnectivityData =  new SponsoredConnectivityData(*element);
				 mSponsoredConnectivityDataGrpList->push_back(lSponsoredConnectivityData);
		 }
		 }
		if(objSTAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objSTAnswer.mOriginStateId));

		if(objSTAnswer.m3GPPUserLocationInfo != NULL)
		m3GPPUserLocationInfo = new OctetString(*(objSTAnswer.m3GPPUserLocationInfo));

		if(objSTAnswer.mUserLocationInfoTime != NULL)
		mUserLocationInfoTime = new Time(*(objSTAnswer.mUserLocationInfoTime));

		if(objSTAnswer.m3GPPMSTimeZone != NULL)
		m3GPPMSTimeZone = new OctetString(*(objSTAnswer.m3GPPMSTimeZone));

		if(objSTAnswer.mRANNASReleaseCause != NULL)
		mRANNASReleaseCause = new OctetString(*(objSTAnswer.mRANNASReleaseCause));

		if(objSTAnswer.mFiveGSRANNASReleaseCauseGrpList != NULL)
		 {
		 mFiveGSRANNASReleaseCauseGrpList = new list<FiveGSRANNASReleaseCause*>;
		 for( auto element : *objSTAnswer.mFiveGSRANNASReleaseCauseGrpList)
		 {
				 FiveGSRANNASReleaseCause *lFiveGSRANNASReleaseCause =  new FiveGSRANNASReleaseCause(*element);
				 mFiveGSRANNASReleaseCauseGrpList->push_back(lFiveGSRANNASReleaseCause);
		 }
		 }
		if(objSTAnswer.m3GPPSGSNMCCMNC != NULL)
		m3GPPSGSNMCCMNC = new OctetString(*(objSTAnswer.m3GPPSGSNMCCMNC));

		if(objSTAnswer.mNID != NULL)
		mNID = new OctetString(*(objSTAnswer.mNID));

		if(objSTAnswer.mTWANIdentifier != NULL)
		mTWANIdentifier = new OctetString(*(objSTAnswer.mTWANIdentifier));

		if(objSTAnswer.mTCPSourcePort != NULL)
		mTCPSourcePort = new Unsigned32(*(objSTAnswer.mTCPSourcePort));

		if(objSTAnswer.mUDPSourcePort != NULL)
		mUDPSourcePort = new Unsigned32(*(objSTAnswer.mUDPSourcePort));

		if(objSTAnswer.mUELocalIPAddress != NULL)
		mUELocalIPAddress = new Address(*(objSTAnswer.mUELocalIPAddress));

		if(objSTAnswer.mNetLocAccessSupport != NULL)
		mNetLocAccessSupport = new Unsigned32(*(objSTAnswer.mNetLocAccessSupport));

		if(objSTAnswer.mWirelineUserLocationInfoGrpList != NULL)
		 {
		 mWirelineUserLocationInfoGrpList = new list<WirelineUserLocationInfo*>;
		 for( auto element : *objSTAnswer.mWirelineUserLocationInfoGrpList)
		 {
				 WirelineUserLocationInfo *lWirelineUserLocationInfo =  new WirelineUserLocationInfo(*element);
				 mWirelineUserLocationInfoGrpList->push_back(lWirelineUserLocationInfo);
		 }
		 }
		if(objSTAnswer.mClass != NULL)
		mClass = new OctetString(*(objSTAnswer.mClass));

		if(objSTAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objSTAnswer.mRedirectHostUsage));

		if(objSTAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objSTAnswer.mRedirectMaxCacheTime));

		if(objSTAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objSTAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objSTAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objSTAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		}

		void operator = (const STAnswer &objSTAnswer) {

		mTagsPresent = objSTAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objSTAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSTAnswer.mMandatoryAvpSetVal;

		mTag = objSTAnswer.mTag;

		mDecodeFlag = objSTAnswer.mDecodeFlag;

		if(objSTAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objSTAnswer.mSessionId));

		if(objSTAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objSTAnswer.mDRMP));

		if(objSTAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSTAnswer.mOriginHost));

		if(objSTAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSTAnswer.mOriginRealm));

		if(objSTAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objSTAnswer.mResultCode));

		if(objSTAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objSTAnswer.mErrorMessage));

		if(objSTAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objSTAnswer.mErrorReportingHost));

		if(objSTAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objSTAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objSTAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objSTAnswer.mOCOLRGrp);
		 }
		if(objSTAnswer.mFailedAVPGrpList != NULL)
		 {
		 mFailedAVPGrpList = new list<FailedAVP*>;
		 for( auto element : *objSTAnswer.mFailedAVPGrpList)
		 {
				 FailedAVP *lFailedAVP =  new FailedAVP(*element);
				 mFailedAVPGrpList->push_back(lFailedAVP);
		 }
		 }
		if(objSTAnswer.mSponsoredConnectivityDataGrpList != NULL)
		 {
		 mSponsoredConnectivityDataGrpList = new list<SponsoredConnectivityData*>;
		 for( auto element : *objSTAnswer.mSponsoredConnectivityDataGrpList)
		 {
				 SponsoredConnectivityData *lSponsoredConnectivityData =  new SponsoredConnectivityData(*element);
				 mSponsoredConnectivityDataGrpList->push_back(lSponsoredConnectivityData);
		 }
		 }
		if(objSTAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objSTAnswer.mOriginStateId));

		if(objSTAnswer.m3GPPUserLocationInfo != NULL)
		m3GPPUserLocationInfo = new OctetString(*(objSTAnswer.m3GPPUserLocationInfo));

		if(objSTAnswer.mUserLocationInfoTime != NULL)
		mUserLocationInfoTime = new Time(*(objSTAnswer.mUserLocationInfoTime));

		if(objSTAnswer.m3GPPMSTimeZone != NULL)
		m3GPPMSTimeZone = new OctetString(*(objSTAnswer.m3GPPMSTimeZone));

		if(objSTAnswer.mRANNASReleaseCause != NULL)
		mRANNASReleaseCause = new OctetString(*(objSTAnswer.mRANNASReleaseCause));

		if(objSTAnswer.mFiveGSRANNASReleaseCauseGrpList != NULL)
		 {
		 mFiveGSRANNASReleaseCauseGrpList = new list<FiveGSRANNASReleaseCause*>;
		 for( auto element : *objSTAnswer.mFiveGSRANNASReleaseCauseGrpList)
		 {
				 FiveGSRANNASReleaseCause *lFiveGSRANNASReleaseCause =  new FiveGSRANNASReleaseCause(*element);
				 mFiveGSRANNASReleaseCauseGrpList->push_back(lFiveGSRANNASReleaseCause);
		 }
		 }
		if(objSTAnswer.m3GPPSGSNMCCMNC != NULL)
		m3GPPSGSNMCCMNC = new OctetString(*(objSTAnswer.m3GPPSGSNMCCMNC));

		if(objSTAnswer.mNID != NULL)
		mNID = new OctetString(*(objSTAnswer.mNID));

		if(objSTAnswer.mTWANIdentifier != NULL)
		mTWANIdentifier = new OctetString(*(objSTAnswer.mTWANIdentifier));

		if(objSTAnswer.mTCPSourcePort != NULL)
		mTCPSourcePort = new Unsigned32(*(objSTAnswer.mTCPSourcePort));

		if(objSTAnswer.mUDPSourcePort != NULL)
		mUDPSourcePort = new Unsigned32(*(objSTAnswer.mUDPSourcePort));

		if(objSTAnswer.mUELocalIPAddress != NULL)
		mUELocalIPAddress = new Address(*(objSTAnswer.mUELocalIPAddress));

		if(objSTAnswer.mNetLocAccessSupport != NULL)
		mNetLocAccessSupport = new Unsigned32(*(objSTAnswer.mNetLocAccessSupport));

		if(objSTAnswer.mWirelineUserLocationInfoGrpList != NULL)
		 {
		 mWirelineUserLocationInfoGrpList = new list<WirelineUserLocationInfo*>;
		 for( auto element : *objSTAnswer.mWirelineUserLocationInfoGrpList)
		 {
				 WirelineUserLocationInfo *lWirelineUserLocationInfo =  new WirelineUserLocationInfo(*element);
				 mWirelineUserLocationInfoGrpList->push_back(lWirelineUserLocationInfo);
		 }
		 }
		if(objSTAnswer.mClass != NULL)
		mClass = new OctetString(*(objSTAnswer.mClass));

		if(objSTAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objSTAnswer.mRedirectHostUsage));

		if(objSTAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objSTAnswer.mRedirectMaxCacheTime));

		if(objSTAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objSTAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objSTAnswer.mLoadGrpList != NULL)
		 {
		 mLoadGrpList = new list<Load*>;
		 for( auto element : *objSTAnswer.mLoadGrpList)
		 {
				 Load *lLoad =  new Load(*element);
				 mLoadGrpList->push_back(lLoad);
		 }
		 }
		}

		virtual ~STAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype STAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype STAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype STAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype STAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype STAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype STAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype STAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype STAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype STAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype STAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype STAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype STAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorReportingHost for datatype STAnswer
		*/
		OctetString* setErrorReportingHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorReportingHost for datatype STAnswer
		*/
		void resetErrorReportingHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorReportingHost for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorReportingHost();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		OCOLR* getOCOLR();

		OCOLR* setOCOLR();

		void resetOCOLR();

		list<FailedAVP*>* getFailedAVPGrpList();

		list<FailedAVP*>* setFailedAVPGrpList();

		void resetFailedAVPGrpList();

		list<SponsoredConnectivityData*>* getSponsoredConnectivityDataGrpList();

		list<SponsoredConnectivityData*>* setSponsoredConnectivityDataGrpList();

		void resetSponsoredConnectivityDataGrpList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype STAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype STAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPUserLocationInfo for datatype STAnswer
		*/
		OctetString* set3GPPUserLocationInfo();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPUserLocationInfo for datatype STAnswer
		*/
		void reset3GPPUserLocationInfo();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPUserLocationInfo for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPUserLocationInfo();

		//!Function to set values
		/*!		Function to set the recent Time type of argument UserLocationInfoTime for datatype STAnswer
		*/
		Time* setUserLocationInfoTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserLocationInfoTime for datatype STAnswer
		*/
		void resetUserLocationInfoTime();

		//!Function to get values
		/*!		Function to get Time type of argument UserLocationInfoTime for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		Time* getUserLocationInfoTime();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPMSTimeZone for datatype STAnswer
		*/
		OctetString* set3GPPMSTimeZone();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPMSTimeZone for datatype STAnswer
		*/
		void reset3GPPMSTimeZone();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPMSTimeZone for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPMSTimeZone();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument RANNASReleaseCause for datatype STAnswer
		*/
		OctetString* setRANNASReleaseCause();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RANNASReleaseCause for datatype STAnswer
		*/
		void resetRANNASReleaseCause();

		//!Function to get values
		/*!		Function to get OctetString type of argument RANNASReleaseCause for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getRANNASReleaseCause();

		list<FiveGSRANNASReleaseCause*>* getFiveGSRANNASReleaseCauseGrpList();

		list<FiveGSRANNASReleaseCause*>* setFiveGSRANNASReleaseCauseGrpList();

		void resetFiveGSRANNASReleaseCauseGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPSGSNMCCMNC for datatype STAnswer
		*/
		OctetString* set3GPPSGSNMCCMNC();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPSGSNMCCMNC for datatype STAnswer
		*/
		void reset3GPPSGSNMCCMNC();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPSGSNMCCMNC for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPSGSNMCCMNC();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument NID for datatype STAnswer
		*/
		OctetString* setNID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument NID for datatype STAnswer
		*/
		void resetNID();

		//!Function to get values
		/*!		Function to get OctetString type of argument NID for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getNID();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TWANIdentifier for datatype STAnswer
		*/
		OctetString* setTWANIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TWANIdentifier for datatype STAnswer
		*/
		void resetTWANIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument TWANIdentifier for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTWANIdentifier();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument TCPSourcePort for datatype STAnswer
		*/
		Unsigned32* setTCPSourcePort();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TCPSourcePort for datatype STAnswer
		*/
		void resetTCPSourcePort();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument TCPSourcePort for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getTCPSourcePort();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument UDPSourcePort for datatype STAnswer
		*/
		Unsigned32* setUDPSourcePort();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UDPSourcePort for datatype STAnswer
		*/
		void resetUDPSourcePort();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument UDPSourcePort for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getUDPSourcePort();

		//!Function to set values
		/*!		Function to set the recent Address type of argument UELocalIPAddress for datatype STAnswer
		*/
		Address* setUELocalIPAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UELocalIPAddress for datatype STAnswer
		*/
		void resetUELocalIPAddress();

		//!Function to get values
		/*!		Function to get Address type of argument UELocalIPAddress for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		Address* getUELocalIPAddress();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument NetLocAccessSupport for datatype STAnswer
		*/
		Unsigned32* setNetLocAccessSupport();

		//! Function to reset 
		/*!		Function to reset NULL type of argument NetLocAccessSupport for datatype STAnswer
		*/
		void resetNetLocAccessSupport();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument NetLocAccessSupport for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getNetLocAccessSupport();

		list<WirelineUserLocationInfo*>* getWirelineUserLocationInfoGrpList();

		list<WirelineUserLocationInfo*>* setWirelineUserLocationInfoGrpList();

		void resetWirelineUserLocationInfoGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument Class for datatype STAnswer
		*/
		OctetString* setClass();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Class for datatype STAnswer
		*/
		void resetClass();

		//!Function to get values
		/*!		Function to get OctetString type of argument Class for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getClass();

		list<OctetString*>* getRedirectHostList();

		list<OctetString*>* setRedirectHostList();

		void resetRedirectHostList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RedirectHostUsage for datatype STAnswer
		*/
		RedirectHostUsage* setRedirectHostUsage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectHostUsage for datatype STAnswer
		*/
		void resetRedirectHostUsage();

		//!Function to get values
		/*!		Function to get RedirectHostUsage type of argument RedirectHostUsage for datatype STAnswer
		Throws exception of which type and Summary of Exception
		*/
		RedirectHostUsage* getRedirectHostUsage();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RedirectMaxCacheTime for datatype STAnswer
		*/
		Unsigned32* setRedirectMaxCacheTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectMaxCacheTime for datatype STAnswer
		*/
		void resetRedirectMaxCacheTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RedirectMaxCacheTime for datatype STAnswer
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
		/*!		Function to Decode datatype STAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype STAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype STAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype STAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype STAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
