#ifndef RX_ASANSWER_H
#define RX_ASANSWER_H
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
#include "rx/include/RedirectHostUsage.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace RX{
typedef enum _tags_ASAnswer
{
	ASAnswer_SESSIONID	= 0,
	ASAnswer_DRMP	= 1,
	ASAnswer_ORIGINHOST	= 2,
	ASAnswer_ORIGINREALM	= 3,
	ASAnswer_RESULTCODE	= 4,
	ASAnswer_OCSUPPORTEDFEATURES	= 5,
	ASAnswer_OCOLR	= 6,
	ASAnswer_ORIGINSTATEID	= 7,
	ASAnswer_ERRORMESSAGE	= 8,
	ASAnswer_ERRORREPORTINGHOST	= 9,
	ASAnswer_FAILEDAVP	= 10,
	ASAnswer_REDIRECTHOST	= 11,
	ASAnswer_REDIRECTHOSTUSAGE	= 12,
	ASAnswer_REDIRECTMAXCACHETIME	= 13,
	ASAnswer_PROXYINFO	= 14,
}ASAnswer_tags;

		//! Class Definition
		/*!		ClassName is ASAnswer
		*/
class ASAnswer : public DiameterBase 
{
	private:

		bitset<15> mTagsPresent;

		bitset<15> mMandatoryAvpCheckVal;

		bitset<15> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		Unsigned32*		mResultCode;

		Unsigned32*		mOriginStateId;

		OctetString*		mErrorMessage;

		OctetString*		mErrorReportingHost;

		list<OctetString*>* 		mRedirectHostList;

		list<OctetString*>::iterator 		mRedirectHostIterator;

		RedirectHostUsage*		mRedirectHostUsage;

		Unsigned32*		mRedirectMaxCacheTime;







		OCSupportedFeatures*	mOCSupportedFeaturesGrp;

		OCOLR*	mOCOLRGrp;




		list<FailedAVP*>*	mFailedAVPGrpList;
		list<FailedAVP*>::iterator	mFailedAVPGrpIterator;




		list<RX::ProxyInfo*>*	mProxyInfoGrpList;
		list<RX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;

	public:
		ASAnswer();

		ASAnswer(const ASAnswer &objASAnswer) {

		mTagsPresent = objASAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objASAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objASAnswer.mMandatoryAvpSetVal;

		mTag = objASAnswer.mTag;

		mDecodeFlag = objASAnswer.mDecodeFlag;

		if(objASAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objASAnswer.mSessionId));

		if(objASAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objASAnswer.mDRMP));

		if(objASAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objASAnswer.mOriginHost));

		if(objASAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objASAnswer.mOriginRealm));

		if(objASAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objASAnswer.mResultCode));

		if(objASAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objASAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objASAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objASAnswer.mOCOLRGrp);
		 }
		if(objASAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objASAnswer.mOriginStateId));

		if(objASAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objASAnswer.mErrorMessage));

		if(objASAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objASAnswer.mErrorReportingHost));

		if(objASAnswer.mFailedAVPGrpList != NULL)
		 {
		 mFailedAVPGrpList = new list<FailedAVP*>;
		 for( auto element : *objASAnswer.mFailedAVPGrpList)
		 {
				 FailedAVP *lFailedAVP =  new FailedAVP(*element);
				 mFailedAVPGrpList->push_back(lFailedAVP);
		 }
		 }
		if(objASAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objASAnswer.mRedirectHostUsage));

		if(objASAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objASAnswer.mRedirectMaxCacheTime));

		if(objASAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objASAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const ASAnswer &objASAnswer) {

		mTagsPresent = objASAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objASAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objASAnswer.mMandatoryAvpSetVal;

		mTag = objASAnswer.mTag;

		mDecodeFlag = objASAnswer.mDecodeFlag;

		if(objASAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objASAnswer.mSessionId));

		if(objASAnswer.mDRMP != NULL)
		mDRMP = new DRMP(*(objASAnswer.mDRMP));

		if(objASAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objASAnswer.mOriginHost));

		if(objASAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objASAnswer.mOriginRealm));

		if(objASAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objASAnswer.mResultCode));

		if(objASAnswer.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objASAnswer.mOCSupportedFeaturesGrp);
		 }
		if(objASAnswer.mOCOLRGrp != NULL)
		 {
				 mOCOLRGrp =  new OCOLR(*objASAnswer.mOCOLRGrp);
		 }
		if(objASAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objASAnswer.mOriginStateId));

		if(objASAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objASAnswer.mErrorMessage));

		if(objASAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objASAnswer.mErrorReportingHost));

		if(objASAnswer.mFailedAVPGrpList != NULL)
		 {
		 mFailedAVPGrpList = new list<FailedAVP*>;
		 for( auto element : *objASAnswer.mFailedAVPGrpList)
		 {
				 FailedAVP *lFailedAVP =  new FailedAVP(*element);
				 mFailedAVPGrpList->push_back(lFailedAVP);
		 }
		 }
		if(objASAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objASAnswer.mRedirectHostUsage));

		if(objASAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objASAnswer.mRedirectMaxCacheTime));

		if(objASAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objASAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~ASAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype ASAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype ASAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype ASAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype ASAnswer
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype ASAnswer
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype ASAnswer
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype ASAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype ASAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype ASAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype ASAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype ASAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype ASAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype ASAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype ASAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype ASAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		OCOLR* getOCOLR();

		OCOLR* setOCOLR();

		void resetOCOLR();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype ASAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype ASAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype ASAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype ASAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype ASAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype ASAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorReportingHost for datatype ASAnswer
		*/
		OctetString* setErrorReportingHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorReportingHost for datatype ASAnswer
		*/
		void resetErrorReportingHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorReportingHost for datatype ASAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorReportingHost();

		list<FailedAVP*>* getFailedAVPGrpList();

		list<FailedAVP*>* setFailedAVPGrpList();

		void resetFailedAVPGrpList();

		list<OctetString*>* getRedirectHostList();

		list<OctetString*>* setRedirectHostList();

		void resetRedirectHostList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RedirectHostUsage for datatype ASAnswer
		*/
		RedirectHostUsage* setRedirectHostUsage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectHostUsage for datatype ASAnswer
		*/
		void resetRedirectHostUsage();

		//!Function to get values
		/*!		Function to get RedirectHostUsage type of argument RedirectHostUsage for datatype ASAnswer
		Throws exception of which type and Summary of Exception
		*/
		RedirectHostUsage* getRedirectHostUsage();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RedirectMaxCacheTime for datatype ASAnswer
		*/
		Unsigned32* setRedirectMaxCacheTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectMaxCacheTime for datatype ASAnswer
		*/
		void resetRedirectMaxCacheTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RedirectMaxCacheTime for datatype ASAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRedirectMaxCacheTime();

		list<RX::ProxyInfo*>* getProxyInfoGrpList();

		list<RX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype ASAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype ASAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ASAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ASAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ASAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
