#ifndef BASE_SESSIONTERMINATIONANSWER_H
#define BASE_SESSIONTERMINATIONANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "base/include/ProxyInfo.h"
#include "base/include/CCRequestType.h"
#include "base/include/DiameterBase.h"
#include "base/include/RedirectHostUsage.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace BASE{
typedef enum _tags_SessionTerminationAnswer
{
	SessionTerminationAnswer_SESSIONID	= 0,
	SessionTerminationAnswer_RESULTCODE	= 1,
	SessionTerminationAnswer_ORIGINHOST	= 2,
	SessionTerminationAnswer_ORIGINREALM	= 3,
	SessionTerminationAnswer_USERNAME	= 4,
	SessionTerminationAnswer_CLASS	= 5,
	SessionTerminationAnswer_ORIGINSTATEID	= 6,
	SessionTerminationAnswer_ERRORMESSAGE	= 7,
	SessionTerminationAnswer_ERRORREPORTINGHOST	= 8,
	SessionTerminationAnswer_REDIRECTHOST	= 9,
	SessionTerminationAnswer_REDIRECTHOSTUSAGE	= 10,
	SessionTerminationAnswer_REDIRECTMAXCACHETIME	= 11,
	SessionTerminationAnswer_PROXYINFO	= 12,
	SessionTerminationAnswer_CCREQUESTTYPE	= 13,
}SessionTerminationAnswer_tags;

		//! Class Definition
		/*!		ClassName is SessionTerminationAnswer
		*/
class SessionTerminationAnswer : public DiameterBase 
{
	private:

		bitset<14> mTagsPresent;

		bitset<14> mMandatoryAvpCheckVal;

		bitset<14> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		Unsigned32*		mResultCode;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mUserName;

		list<OctetString*>* 		mClassList;

		list<OctetString*>::iterator 		mClassIterator;

		Unsigned32*		mOriginStateId;

		OctetString*		mErrorMessage;

		OctetString*		mErrorReportingHost;

		list<OctetString*>* 		mRedirectHostList;

		list<OctetString*>::iterator 		mRedirectHostIterator;

		RedirectHostUsage*		mRedirectHostUsage;

		Unsigned32*		mRedirectMaxCacheTime;

		CCRequestType*		mCCRequestType;














		list<ProxyInfo*>*	mProxyInfoGrpList;
		list<ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		SessionTerminationAnswer();

		SessionTerminationAnswer(const SessionTerminationAnswer &objSessionTerminationAnswer) {

		mTagsPresent = objSessionTerminationAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objSessionTerminationAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSessionTerminationAnswer.mMandatoryAvpSetVal;

		mTag = objSessionTerminationAnswer.mTag;

		mDecodeFlag = objSessionTerminationAnswer.mDecodeFlag;

		if(objSessionTerminationAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objSessionTerminationAnswer.mSessionId));

		if(objSessionTerminationAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objSessionTerminationAnswer.mResultCode));

		if(objSessionTerminationAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSessionTerminationAnswer.mOriginHost));

		if(objSessionTerminationAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSessionTerminationAnswer.mOriginRealm));

		if(objSessionTerminationAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objSessionTerminationAnswer.mUserName));

		if(objSessionTerminationAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objSessionTerminationAnswer.mOriginStateId));

		if(objSessionTerminationAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objSessionTerminationAnswer.mErrorMessage));

		if(objSessionTerminationAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objSessionTerminationAnswer.mErrorReportingHost));

		if(objSessionTerminationAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objSessionTerminationAnswer.mRedirectHostUsage));

		if(objSessionTerminationAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objSessionTerminationAnswer.mRedirectMaxCacheTime));

		if(objSessionTerminationAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objSessionTerminationAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objSessionTerminationAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objSessionTerminationAnswer.mCCRequestType));

		}

		void operator = (const SessionTerminationAnswer &objSessionTerminationAnswer) {

		mTagsPresent = objSessionTerminationAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objSessionTerminationAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSessionTerminationAnswer.mMandatoryAvpSetVal;

		mTag = objSessionTerminationAnswer.mTag;

		mDecodeFlag = objSessionTerminationAnswer.mDecodeFlag;

		if(objSessionTerminationAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objSessionTerminationAnswer.mSessionId));

		if(objSessionTerminationAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objSessionTerminationAnswer.mResultCode));

		if(objSessionTerminationAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSessionTerminationAnswer.mOriginHost));

		if(objSessionTerminationAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSessionTerminationAnswer.mOriginRealm));

		if(objSessionTerminationAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objSessionTerminationAnswer.mUserName));

		if(objSessionTerminationAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objSessionTerminationAnswer.mOriginStateId));

		if(objSessionTerminationAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objSessionTerminationAnswer.mErrorMessage));

		if(objSessionTerminationAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objSessionTerminationAnswer.mErrorReportingHost));

		if(objSessionTerminationAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objSessionTerminationAnswer.mRedirectHostUsage));

		if(objSessionTerminationAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objSessionTerminationAnswer.mRedirectMaxCacheTime));

		if(objSessionTerminationAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objSessionTerminationAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objSessionTerminationAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objSessionTerminationAnswer.mCCRequestType));

		}

		virtual ~SessionTerminationAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype SessionTerminationAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype SessionTerminationAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype SessionTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype SessionTerminationAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype SessionTerminationAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype SessionTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype SessionTerminationAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype SessionTerminationAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype SessionTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype SessionTerminationAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype SessionTerminationAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype SessionTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype SessionTerminationAnswer
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype SessionTerminationAnswer
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype SessionTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		list<OctetString*>* getClassList();

		list<OctetString*>* setClassList();

		void resetClassList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype SessionTerminationAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype SessionTerminationAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype SessionTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype SessionTerminationAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype SessionTerminationAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype SessionTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorReportingHost for datatype SessionTerminationAnswer
		*/
		OctetString* setErrorReportingHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorReportingHost for datatype SessionTerminationAnswer
		*/
		void resetErrorReportingHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorReportingHost for datatype SessionTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorReportingHost();

		list<OctetString*>* getRedirectHostList();

		list<OctetString*>* setRedirectHostList();

		void resetRedirectHostList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RedirectHostUsage for datatype SessionTerminationAnswer
		*/
		RedirectHostUsage* setRedirectHostUsage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectHostUsage for datatype SessionTerminationAnswer
		*/
		void resetRedirectHostUsage();

		//!Function to get values
		/*!		Function to get RedirectHostUsage type of argument RedirectHostUsage for datatype SessionTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		RedirectHostUsage* getRedirectHostUsage();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RedirectMaxCacheTime for datatype SessionTerminationAnswer
		*/
		Unsigned32* setRedirectMaxCacheTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectMaxCacheTime for datatype SessionTerminationAnswer
		*/
		void resetRedirectMaxCacheTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RedirectMaxCacheTime for datatype SessionTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRedirectMaxCacheTime();

		list<ProxyInfo*>* getProxyInfoGrpList();

		list<ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype SessionTerminationAnswer
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype SessionTerminationAnswer
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype SessionTerminationAnswer
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype SessionTerminationAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype SessionTerminationAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SessionTerminationAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SessionTerminationAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SessionTerminationAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
