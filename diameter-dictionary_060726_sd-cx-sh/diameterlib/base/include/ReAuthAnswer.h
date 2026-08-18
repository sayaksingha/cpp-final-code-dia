#ifndef BASE_REAUTHANSWER_H
#define BASE_REAUTHANSWER_H
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
typedef enum _tags_ReAuthAnswer
{
	ReAuthAnswer_SESSIONID	= 0,
	ReAuthAnswer_RESULTCODE	= 1,
	ReAuthAnswer_ORIGINHOST	= 2,
	ReAuthAnswer_ORIGINREALM	= 3,
	ReAuthAnswer_USERNAME	= 4,
	ReAuthAnswer_ORIGINSTATEID	= 5,
	ReAuthAnswer_ERRORMESSAGE	= 6,
	ReAuthAnswer_ERRORREPORTINGHOST	= 7,
	ReAuthAnswer_REDIRECTHOST	= 8,
	ReAuthAnswer_REDIRECTHOSTUSAGE	= 9,
	ReAuthAnswer_REDIRECTMAXCACHETIME	= 10,
	ReAuthAnswer_PROXYINFO	= 11,
	ReAuthAnswer_CCREQUESTTYPE	= 12,
}ReAuthAnswer_tags;

		//! Class Definition
		/*!		ClassName is ReAuthAnswer
		*/
class ReAuthAnswer : public DiameterBase 
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

		OctetString*		mRedirectHost;

		RedirectHostUsage*		mRedirectHostUsage;

		Unsigned32*		mRedirectMaxCacheTime;

		CCRequestType*		mCCRequestType;













		list<ProxyInfo*>*	mProxyInfoGrpList;
		list<ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		ReAuthAnswer();

		ReAuthAnswer(const ReAuthAnswer &objReAuthAnswer) {

		mTagsPresent = objReAuthAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objReAuthAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objReAuthAnswer.mMandatoryAvpSetVal;

		mTag = objReAuthAnswer.mTag;

		mDecodeFlag = objReAuthAnswer.mDecodeFlag;

		if(objReAuthAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objReAuthAnswer.mSessionId));

		if(objReAuthAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objReAuthAnswer.mResultCode));

		if(objReAuthAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objReAuthAnswer.mOriginHost));

		if(objReAuthAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objReAuthAnswer.mOriginRealm));

		if(objReAuthAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objReAuthAnswer.mUserName));

		if(objReAuthAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objReAuthAnswer.mOriginStateId));

		if(objReAuthAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objReAuthAnswer.mErrorMessage));

		if(objReAuthAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objReAuthAnswer.mErrorReportingHost));

		if(objReAuthAnswer.mRedirectHost != NULL)
		mRedirectHost = new OctetString(*(objReAuthAnswer.mRedirectHost));

		if(objReAuthAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objReAuthAnswer.mRedirectHostUsage));

		if(objReAuthAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objReAuthAnswer.mRedirectMaxCacheTime));

		if(objReAuthAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objReAuthAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objReAuthAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objReAuthAnswer.mCCRequestType));

		}

		void operator = (const ReAuthAnswer &objReAuthAnswer) {

		mTagsPresent = objReAuthAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objReAuthAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objReAuthAnswer.mMandatoryAvpSetVal;

		mTag = objReAuthAnswer.mTag;

		mDecodeFlag = objReAuthAnswer.mDecodeFlag;

		if(objReAuthAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objReAuthAnswer.mSessionId));

		if(objReAuthAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objReAuthAnswer.mResultCode));

		if(objReAuthAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objReAuthAnswer.mOriginHost));

		if(objReAuthAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objReAuthAnswer.mOriginRealm));

		if(objReAuthAnswer.mUserName != NULL)
		mUserName = new OctetString(*(objReAuthAnswer.mUserName));

		if(objReAuthAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objReAuthAnswer.mOriginStateId));

		if(objReAuthAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objReAuthAnswer.mErrorMessage));

		if(objReAuthAnswer.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objReAuthAnswer.mErrorReportingHost));

		if(objReAuthAnswer.mRedirectHost != NULL)
		mRedirectHost = new OctetString(*(objReAuthAnswer.mRedirectHost));

		if(objReAuthAnswer.mRedirectHostUsage != NULL)
		mRedirectHostUsage = new RedirectHostUsage(*(objReAuthAnswer.mRedirectHostUsage));

		if(objReAuthAnswer.mRedirectMaxCacheTime != NULL)
		mRedirectMaxCacheTime = new Unsigned32(*(objReAuthAnswer.mRedirectMaxCacheTime));

		if(objReAuthAnswer.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objReAuthAnswer.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objReAuthAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objReAuthAnswer.mCCRequestType));

		}

		virtual ~ReAuthAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype ReAuthAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype ReAuthAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype ReAuthAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype ReAuthAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype ReAuthAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype ReAuthAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype ReAuthAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype ReAuthAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype ReAuthAnswer
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype ReAuthAnswer
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype ReAuthAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype ReAuthAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype ReAuthAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype ReAuthAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorReportingHost for datatype ReAuthAnswer
		*/
		OctetString* setErrorReportingHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorReportingHost for datatype ReAuthAnswer
		*/
		void resetErrorReportingHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorReportingHost for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorReportingHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument RedirectHost for datatype ReAuthAnswer
		*/
		OctetString* setRedirectHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectHost for datatype ReAuthAnswer
		*/
		void resetRedirectHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument RedirectHost for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getRedirectHost();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RedirectHostUsage for datatype ReAuthAnswer
		*/
		RedirectHostUsage* setRedirectHostUsage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectHostUsage for datatype ReAuthAnswer
		*/
		void resetRedirectHostUsage();

		//!Function to get values
		/*!		Function to get RedirectHostUsage type of argument RedirectHostUsage for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		RedirectHostUsage* getRedirectHostUsage();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RedirectMaxCacheTime for datatype ReAuthAnswer
		*/
		Unsigned32* setRedirectMaxCacheTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RedirectMaxCacheTime for datatype ReAuthAnswer
		*/
		void resetRedirectMaxCacheTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RedirectMaxCacheTime for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRedirectMaxCacheTime();

		list<ProxyInfo*>* getProxyInfoGrpList();

		list<ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype ReAuthAnswer
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype ReAuthAnswer
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype ReAuthAnswer
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype ReAuthAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype ReAuthAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ReAuthAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ReAuthAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ReAuthAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
