#ifndef BASE_ABORTSESSIONANSWER_H
#define BASE_ABORTSESSIONANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "base/include/ProxyInfo.h"
#include "base/include/CCRequestType.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/RedirectHostUsage.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace BASE{
typedef enum _tags_AbortSessionAnswer
{
	AbortSessionAnswer_SESSIONID	= 0,
	AbortSessionAnswer_RESULTCODE	= 1,
	AbortSessionAnswer_ORIGINHOST	= 2,
	AbortSessionAnswer_ORIGINREALM	= 3,
	AbortSessionAnswer_USERNAME	= 4,
	AbortSessionAnswer_ORIGINSTATEID	= 5,
	AbortSessionAnswer_ERRORMESSAGE	= 6,
	AbortSessionAnswer_ERRORREPORTINGHOST	= 7,
	AbortSessionAnswer_REDIRECTHOST	= 8,
	AbortSessionAnswer_REDIRECTHOSTUSAGE	= 9,
	AbortSessionAnswer_REDIRECTMAXCACHETIME	= 10,
	AbortSessionAnswer_PROXYINFO	= 11,
	AbortSessionAnswer_CCREQUESTTYPE	= 12,
}AbortSessionAnswer_tags;

		//! Class Definition
		/*!		ClassName is AbortSessionAnswer
		*/
class AbortSessionAnswer : public DiameterBase 
{
	private:

		bitset<13> mTagsPresent;

		bitset<13> mMandatoryAvpCheckVal;

		bitset<13> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		Unsigned32*		mResultCode;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mUserName;

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
		AbortSessionAnswer();

		AbortSessionAnswer(const AbortSessionAnswer &objAbortSessionAnswer) {

		mTagsPresent = objAbortSessionAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objAbortSessionAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAbortSessionAnswer.mMandatoryAvpSetVal;

		mTag = objAbortSessionAnswer.mTag;

		mDecodeFlag = objAbortSessionAnswer.mDecodeFlag;

		if(objAbortSessionAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objAbortSessionAnswer.mSessionId));

		if(objAbortSessionAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objAbortSessionAnswer.mResultCode));

		if(objAbortSessionAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objAbortSessionAnswer.mOriginHost));

		if(objAbortSessionAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objAbortSessionAnswer.mOriginRealm));

		if(objAbortSessionAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objAbortSessionAnswer.mUserName));

		if(objAbortSessionAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objAbortSessionAnswer.mOriginStateId));

		if(objAbortSessionAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objAbortSessionAnswer.mErrorMessage));

		if(objAbortSessionAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objAbortSessionAnswer.mErrorReportingHost));

		if(objAbortSessionAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objAbortSessionAnswer.mRedirectHostUsage));

		if(objAbortSessionAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objAbortSessionAnswer.mRedirectMaxCacheTime));

		if(objAbortSessionAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objAbortSessionAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objAbortSessionAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objAbortSessionAnswer.mCCRequestType));

		}

		void operator = (const AbortSessionAnswer &objAbortSessionAnswer) {

		mTagsPresent = objAbortSessionAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objAbortSessionAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAbortSessionAnswer.mMandatoryAvpSetVal;

		mTag = objAbortSessionAnswer.mTag;

		mDecodeFlag = objAbortSessionAnswer.mDecodeFlag;

		if(objAbortSessionAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objAbortSessionAnswer.mSessionId));

		if(objAbortSessionAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objAbortSessionAnswer.mResultCode));

		if(objAbortSessionAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objAbortSessionAnswer.mOriginHost));

		if(objAbortSessionAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objAbortSessionAnswer.mOriginRealm));

		if(objAbortSessionAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objAbortSessionAnswer.mUserName));

		if(objAbortSessionAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objAbortSessionAnswer.mOriginStateId));

		if(objAbortSessionAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objAbortSessionAnswer.mErrorMessage));

		if(objAbortSessionAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objAbortSessionAnswer.mErrorReportingHost));

		if(objAbortSessionAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objAbortSessionAnswer.mRedirectHostUsage));

		if(objAbortSessionAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objAbortSessionAnswer.mRedirectMaxCacheTime));

		if(objAbortSessionAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objAbortSessionAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objAbortSessionAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objAbortSessionAnswer.mCCRequestType));

		}

		virtual ~AbortSessionAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype AbortSessionAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype AbortSessionAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype AbortSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype AbortSessionAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype AbortSessionAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype AbortSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype AbortSessionAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype AbortSessionAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype AbortSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype AbortSessionAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype AbortSessionAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype AbortSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype AbortSessionAnswer
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype AbortSessionAnswer
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype AbortSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype AbortSessionAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype AbortSessionAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype AbortSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype AbortSessionAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype AbortSessionAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype AbortSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorReportingHost for datatype AbortSessionAnswer
		*/
		OctetString* setErrorReportingHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorReportingHost for datatype AbortSessionAnswer
		*/
		void resetErrorReportingHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorReportingHost for datatype AbortSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorReportingHost();

		list<OctetString*>* getRedirectHostList();

		list<OctetString*>* setRedirectHostList();

		void resetRedirectHostList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RedirectHostUsage for datatype AbortSessionAnswer
		*/
		RedirectHostUsage* setRedirectHostUsage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectHostUsage for datatype AbortSessionAnswer
		*/
		void resetRedirectHostUsage();

		//!Function to get values
		/*!		Function to get RedirectHostUsage type of argument RedirectHostUsage for datatype AbortSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		RedirectHostUsage* getRedirectHostUsage();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RedirectMaxCacheTime for datatype AbortSessionAnswer
		*/
		Unsigned32* setRedirectMaxCacheTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectMaxCacheTime for datatype AbortSessionAnswer
		*/
		void resetRedirectMaxCacheTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RedirectMaxCacheTime for datatype AbortSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRedirectMaxCacheTime();

		list<ProxyInfo*>* getProxyInfoGrpList();

		list<ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype AbortSessionAnswer
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype AbortSessionAnswer
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype AbortSessionAnswer
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype AbortSessionAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype AbortSessionAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype AbortSessionAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype AbortSessionAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AbortSessionAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
