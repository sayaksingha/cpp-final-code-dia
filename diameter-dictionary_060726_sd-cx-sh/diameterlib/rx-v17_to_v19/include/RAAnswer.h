#ifndef RX_RAANSWER_H
#define RX_RAANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"
#include "rx/include/ProxyInfo.h"
#include "rx/include/DRMP.h"
#include "rx/include/ExperimentalResult.h"
#include "rx/include/OCSupportedFeatures.h"
#include "rx/include/OCOLR.h"
#include "rx/include/MediaComponentDescription.h"
#include "rx/include/RedirectHostUsage.h"
#include "rx/include/FailedAVP.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace RX{
typedef enum _tags_RAAnswer
{
	RAAnswer_SESSIONID	= 0,
	RAAnswer_DRMP	= 1,
	RAAnswer_ORIGINHOST	= 2,
	RAAnswer_ORIGINREALM	= 3,
	RAAnswer_RESULTCODE	= 4,
	RAAnswer_EXPERIMENTALRESULT	= 5,
	RAAnswer_OCSUPPORTEDFEATURES	= 6,
	RAAnswer_OCOLR	= 7,
	RAAnswer_MEDIACOMPONENTDESCRIPTION	= 8,
	RAAnswer_SERVICEURN	= 9,
	RAAnswer_ORIGINSTATEID	= 10,
	RAAnswer_CLASS	= 11,
	RAAnswer_ERRORMESSAGE	= 12,
	RAAnswer_ERRORREPORTINGHOST	= 13,
	RAAnswer_REDIRECTHOST	= 14,
	RAAnswer_REDIRECTHOSTUSAGE	= 15,
	RAAnswer_REDIRECTMAXCACHETIME	= 16,
	RAAnswer_FAILEDAVP	= 17,
	RAAnswer_PROXYINFO	= 18,
}RAAnswer_tags;

		//! Class Definition
		/*!		ClassName is RAAnswer
		*/
class RAAnswer : public DiameterBase 
{
	private:

		bitset<19> mTagsPresent;

		bitset<19> mMandatoryAvpCheckVal;

		bitset<19> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		Unsigned32*		mResultCode;

		OctetString*		mServiceURN;

		Unsigned32*		mOriginStateId;

		OctetString*		mClass;

		OctetString*		mErrorMessage;

		OctetString*		mErrorReportingHost;

		list<OctetString*>* 		mRedirectHostList;

		list<OctetString*>::iterator 		mRedirectHostIterator;

		RedirectHostUsage*		mRedirectHostUsage;

		Unsigned32*		mRedirectMaxCacheTime;







		ExperimentalResult*	mExperimentalResultGrp;

		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		OCOLR*	mOCOLRGrp;

		list<MediaComponentDescription*>*	mMediaComponentDescriptionGrpList;
		list<MediaComponentDescription*>::iterator	mMediaComponentDescriptionGrpIterator;









		list<FailedAVP*>*	mFailedAVPGrpList;
		list<FailedAVP*>::iterator	mFailedAVPGrpIterator;

		list<RX::ProxyInfo*>*	mProxyInfoGrpList;
		list<RX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;

	public:
		RAAnswer();

		RAAnswer(const RAAnswer &objRAAnswer) {

		mTagsPresent = objRAAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objRAAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRAAnswer.mMandatoryAvpSetVal;

		mTag = objRAAnswer.mTag;

		mDecodeFlag = objRAAnswer.mDecodeFlag;

		if(objRAAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objRAAnswer.mSessionId));

		if(objRAAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objRAAnswer.mDRMP));

		if(objRAAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objRAAnswer.mOriginHost));

		if(objRAAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objRAAnswer.mOriginRealm));

		if(objRAAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objRAAnswer.mResultCode));

		if(objRAAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objRAAnswer.mExperimentalResultGrp);
		 }
		if(objRAAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objRAAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objRAAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objRAAnswer.mOCOLRGrp);
		 }
		if(objRAAnswer.mMediaComponentDescriptionGrpList != NULL)
		 {
		 mMediaComponentDescriptionGrpList = new list<MediaComponentDescription*>;
		 for( auto element : *objRAAnswer.mMediaComponentDescriptionGrpList)
		 {
				 MediaComponentDescription *lMediaComponentDescription =  new MediaComponentDescription(*element);
				 mMediaComponentDescriptionGrpList->push_back(lMediaComponentDescription);
		 }
		 }
		if(objRAAnswer.mServiceURN != NULL)
		mServiceURN = new OctetString(*(objRAAnswer.mServiceURN));

		if(objRAAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objRAAnswer.mOriginStateId));

		if(objRAAnswer.mClass != NULL)
		mClass = new OctetString(*(objRAAnswer.mClass));

		if(objRAAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objRAAnswer.mErrorMessage));

		if(objRAAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objRAAnswer.mErrorReportingHost));

		if(objRAAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objRAAnswer.mRedirectHostUsage));

		if(objRAAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objRAAnswer.mRedirectMaxCacheTime));

		if(objRAAnswer.mFailedAVPGrpList != NULL)
		 {
		 mFailedAVPGrpList = new list<FailedAVP*>;
		 for( auto element : *objRAAnswer.mFailedAVPGrpList)
		 {
				 FailedAVP *lFailedAVP =  new FailedAVP(*element);
				 mFailedAVPGrpList->push_back(lFailedAVP);
		 }
		 }
		if(objRAAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objRAAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const RAAnswer &objRAAnswer) {

		mTagsPresent = objRAAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objRAAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRAAnswer.mMandatoryAvpSetVal;

		mTag = objRAAnswer.mTag;

		mDecodeFlag = objRAAnswer.mDecodeFlag;

		if(objRAAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objRAAnswer.mSessionId));

		if(objRAAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objRAAnswer.mDRMP));

		if(objRAAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objRAAnswer.mOriginHost));

		if(objRAAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objRAAnswer.mOriginRealm));

		if(objRAAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objRAAnswer.mResultCode));

		if(objRAAnswer.mExperimentalResultGrp != NULL)
		 {
				 mExperimentalResultGrp =  new ExperimentalResult(*objRAAnswer.mExperimentalResultGrp);
		 }
		if(objRAAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objRAAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objRAAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objRAAnswer.mOCOLRGrp);
		 }
		if(objRAAnswer.mMediaComponentDescriptionGrpList != NULL)
		 {
		 mMediaComponentDescriptionGrpList = new list<MediaComponentDescription*>;
		 for( auto element : *objRAAnswer.mMediaComponentDescriptionGrpList)
		 {
				 MediaComponentDescription *lMediaComponentDescription =  new MediaComponentDescription(*element);
				 mMediaComponentDescriptionGrpList->push_back(lMediaComponentDescription);
		 }
		 }
		if(objRAAnswer.mServiceURN != NULL)
		mServiceURN = new OctetString(*(objRAAnswer.mServiceURN));

		if(objRAAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objRAAnswer.mOriginStateId));

		if(objRAAnswer.mClass != NULL)
		mClass = new OctetString(*(objRAAnswer.mClass));

		if(objRAAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objRAAnswer.mErrorMessage));

		if(objRAAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objRAAnswer.mErrorReportingHost));

		if(objRAAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objRAAnswer.mRedirectHostUsage));

		if(objRAAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objRAAnswer.mRedirectMaxCacheTime));

		if(objRAAnswer.mFailedAVPGrpList != NULL)
		 {
		 mFailedAVPGrpList = new list<FailedAVP*>;
		 for( auto element : *objRAAnswer.mFailedAVPGrpList)
		 {
				 FailedAVP *lFailedAVP =  new FailedAVP(*element);
				 mFailedAVPGrpList->push_back(lFailedAVP);
		 }
		 }
		if(objRAAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objRAAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~RAAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype RAAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype RAAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype RAAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype RAAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype RAAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype RAAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype RAAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype RAAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype RAAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype RAAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		ExperimentalResult* getExperimentalResult();

		ExperimentalResult* setExperimentalResult();

		void resetExperimentalResult();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		OCOLR* getOCOLR();

		OCOLR* setOCOLR();

		void resetOCOLR();

		list<MediaComponentDescription*>* getMediaComponentDescriptionGrpList();

		list<MediaComponentDescription*>* setMediaComponentDescriptionGrpList();

		void resetMediaComponentDescriptionGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ServiceURN for datatype RAAnswer
		*/
		OctetString* setServiceURN();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServiceURN for datatype RAAnswer
		*/
		void resetServiceURN();

		//!Function to get values
		/*!		Function to get OctetString type of argument ServiceURN for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getServiceURN();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype RAAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype RAAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument Class for datatype RAAnswer
		*/
		OctetString* setClass();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Class for datatype RAAnswer
		*/
		void resetClass();

		//!Function to get values
		/*!		Function to get OctetString type of argument Class for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getClass();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype RAAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype RAAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorReportingHost for datatype RAAnswer
		*/
		OctetString* setErrorReportingHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorReportingHost for datatype RAAnswer
		*/
		void resetErrorReportingHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorReportingHost for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorReportingHost();

		list<OctetString*>* getRedirectHostList();

		list<OctetString*>* setRedirectHostList();

		void resetRedirectHostList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RedirectHostUsage for datatype RAAnswer
		*/
		RedirectHostUsage* setRedirectHostUsage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectHostUsage for datatype RAAnswer
		*/
		void resetRedirectHostUsage();

		//!Function to get values
		/*!		Function to get RedirectHostUsage type of argument RedirectHostUsage for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		RedirectHostUsage* getRedirectHostUsage();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RedirectMaxCacheTime for datatype RAAnswer
		*/
		Unsigned32* setRedirectMaxCacheTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectMaxCacheTime for datatype RAAnswer
		*/
		void resetRedirectMaxCacheTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RedirectMaxCacheTime for datatype RAAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRedirectMaxCacheTime();

		list<FailedAVP*>* getFailedAVPGrpList();

		list<FailedAVP*>* setFailedAVPGrpList();

		void resetFailedAVPGrpList();

		list<RX::ProxyInfo*>* getProxyInfoGrpList();

		list<RX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype RAAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype RAAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype RAAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype RAAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RAAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
