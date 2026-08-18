#ifndef BASE_ACCOUNTINGRESPONSE_H
#define BASE_ACCOUNTINGRESPONSE_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "base/include/VendorSpecificApplicationId.h"
#include "base/include/ProxyInfo.h"
#include "base/include/CCRequestType.h"
#include "base/include/AccountingRecordType.h"
#include "base/include/AccountingRealtimeRequired.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace BASE{
typedef enum _tags_AccountingResponse
{
	AccountingResponse_SESSIONID	= 0,
	AccountingResponse_RESULTCODE	= 1,
	AccountingResponse_ORIGINHOST	= 2,
	AccountingResponse_ORIGINREALM	= 3,
	AccountingResponse_ORIGINSTATEID	= 4,
	AccountingResponse_ACCOUNTINGRECORDTYPE	= 5,
	AccountingResponse_ACCOUNTINGRECORDNUMBER	= 6,
	AccountingResponse_ACCTAPPLICATIONID	= 7,
	AccountingResponse_VENDORSPECIFICAPPLICATIONID	= 8,
	AccountingResponse_USERNAME	= 9,
	AccountingResponse_ACCOUNTINGSUBSESSIONID	= 10,
	AccountingResponse_ACCTSESSIONID	= 11,
	AccountingResponse_ACCTMULTISESSIONID	= 12,
	AccountingResponse_ERRORMESSAGE	= 13,
	AccountingResponse_ERRORREPORTINGHOST	= 14,
	AccountingResponse_ACCTINTERIMINTERVAL	= 15,
	AccountingResponse_ACCOUNTINGREALTIMEREQUIRED	= 16,
	AccountingResponse_EVENTTIMESTAMP	= 17,
	AccountingResponse_PROXYINFO	= 18,
	AccountingResponse_ROUTERECORD	= 19,
	AccountingResponse_CCREQUESTTYPE	= 20,
}AccountingResponse_tags;

		//! Class Definition
		/*!		ClassName is AccountingResponse
		*/
class AccountingResponse : public DiameterBase 
{
	private:

		bitset<21> mTagsPresent;

		bitset<21> mMandatoryAvpCheckVal;

		bitset<21> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		Unsigned32*		mResultCode;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		Unsigned32*		mOriginStateId;

		AccountingRecordType*		mAccountingRecordType;

		Unsigned32*		mAccountingRecordNumber;

		Unsigned32*		mAcctApplicationId;

		OctetString*		mUserName;

		Unsigned64*		mAccountingSubSessionId;

		OctetString*		mAcctSessionId;

		OctetString*		mAcctMultiSessionId;

		OctetString*		mErrorMessage;

		OctetString*		mErrorReportingHost;

		Unsigned32*		mAcctInterimInterval;

		AccountingRealtimeRequired*		mAccountingRealtimeRequired;

		OctetString*		mEventTimestamp;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;

		CCRequestType*		mCCRequestType;










		list<VendorSpecificApplicationId*>*	mVendorSpecificApplicationIdGrpList;
		list<VendorSpecificApplicationId*>::iterator	mVendorSpecificApplicationIdGrpIterator;










		list<ProxyInfo*>*	mProxyInfoGrpList;
		list<ProxyInfo*>::iterator	mProxyInfoGrpIterator;



	public:
		AccountingResponse();

		AccountingResponse(const AccountingResponse &objAccountingResponse) {

		mTagsPresent = objAccountingResponse.mTagsPresent;

		mMandatoryAvpCheckVal = objAccountingResponse.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAccountingResponse.mMandatoryAvpSetVal;

		mTag = objAccountingResponse.mTag;

		mDecodeFlag = objAccountingResponse.mDecodeFlag;

		if(objAccountingResponse.mSessionId != NULL)
		mSessionId = new OctetString(*(objAccountingResponse.mSessionId));

		if(objAccountingResponse.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objAccountingResponse.mResultCode));

		if(objAccountingResponse.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objAccountingResponse.mOriginHost));

		if(objAccountingResponse.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objAccountingResponse.mOriginRealm));

		if(objAccountingResponse.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objAccountingResponse.mOriginStateId));

		if(objAccountingResponse.mAccountingRecordType != NULL)
		mAccountingRecordType = new AccountingRecordType(*(objAccountingResponse.mAccountingRecordType));

		if(objAccountingResponse.mAccountingRecordNumber != NULL)
		mAccountingRecordNumber = new Unsigned32(*(objAccountingResponse.mAccountingRecordNumber));

		if(objAccountingResponse.mAcctApplicationId != NULL)
		mAcctApplicationId = new Unsigned32(*(objAccountingResponse.mAcctApplicationId));

		if(objAccountingResponse.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objAccountingResponse.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		if(objAccountingResponse.mUserName != NULL)
		mUserName = new OctetString(*(objAccountingResponse.mUserName));

		if(objAccountingResponse.mAccountingSubSessionId != NULL)
		mAccountingSubSessionId = new Unsigned64(*(objAccountingResponse.mAccountingSubSessionId));

		if(objAccountingResponse.mAcctSessionId != NULL)
		mAcctSessionId = new OctetString(*(objAccountingResponse.mAcctSessionId));

		if(objAccountingResponse.mAcctMultiSessionId != NULL)
		mAcctMultiSessionId = new OctetString(*(objAccountingResponse.mAcctMultiSessionId));

		if(objAccountingResponse.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objAccountingResponse.mErrorMessage));

		if(objAccountingResponse.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objAccountingResponse.mErrorReportingHost));

		if(objAccountingResponse.mAcctInterimInterval != NULL)
		mAcctInterimInterval = new Unsigned32(*(objAccountingResponse.mAcctInterimInterval));

		if(objAccountingResponse.mAccountingRealtimeRequired != NULL)
		mAccountingRealtimeRequired = new AccountingRealtimeRequired(*(objAccountingResponse.mAccountingRealtimeRequired));

		if(objAccountingResponse.mEventTimestamp != NULL)
		mEventTimestamp = new OctetString(*(objAccountingResponse.mEventTimestamp));

		if(objAccountingResponse.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objAccountingResponse.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objAccountingResponse.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objAccountingResponse.mCCRequestType));

		}

		void operator = (const AccountingResponse &objAccountingResponse) {

		mTagsPresent = objAccountingResponse.mTagsPresent;

		mMandatoryAvpCheckVal = objAccountingResponse.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAccountingResponse.mMandatoryAvpSetVal;

		mTag = objAccountingResponse.mTag;

		mDecodeFlag = objAccountingResponse.mDecodeFlag;

		if(objAccountingResponse.mSessionId != NULL)
		mSessionId = new OctetString(*(objAccountingResponse.mSessionId));

		if(objAccountingResponse.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objAccountingResponse.mResultCode));

		if(objAccountingResponse.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objAccountingResponse.mOriginHost));

		if(objAccountingResponse.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objAccountingResponse.mOriginRealm));

		if(objAccountingResponse.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objAccountingResponse.mOriginStateId));

		if(objAccountingResponse.mAccountingRecordType != NULL)
		mAccountingRecordType = new AccountingRecordType(*(objAccountingResponse.mAccountingRecordType));

		if(objAccountingResponse.mAccountingRecordNumber != NULL)
		mAccountingRecordNumber = new Unsigned32(*(objAccountingResponse.mAccountingRecordNumber));

		if(objAccountingResponse.mAcctApplicationId != NULL)
		mAcctApplicationId = new Unsigned32(*(objAccountingResponse.mAcctApplicationId));

		if(objAccountingResponse.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objAccountingResponse.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		if(objAccountingResponse.mUserName != NULL)
		mUserName = new OctetString(*(objAccountingResponse.mUserName));

		if(objAccountingResponse.mAccountingSubSessionId != NULL)
		mAccountingSubSessionId = new Unsigned64(*(objAccountingResponse.mAccountingSubSessionId));

		if(objAccountingResponse.mAcctSessionId != NULL)
		mAcctSessionId = new OctetString(*(objAccountingResponse.mAcctSessionId));

		if(objAccountingResponse.mAcctMultiSessionId != NULL)
		mAcctMultiSessionId = new OctetString(*(objAccountingResponse.mAcctMultiSessionId));

		if(objAccountingResponse.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objAccountingResponse.mErrorMessage));

		if(objAccountingResponse.mErrorReportingHost != NULL)
		mErrorReportingHost = new OctetString(*(objAccountingResponse.mErrorReportingHost));

		if(objAccountingResponse.mAcctInterimInterval != NULL)
		mAcctInterimInterval = new Unsigned32(*(objAccountingResponse.mAcctInterimInterval));

		if(objAccountingResponse.mAccountingRealtimeRequired != NULL)
		mAccountingRealtimeRequired = new AccountingRealtimeRequired(*(objAccountingResponse.mAccountingRealtimeRequired));

		if(objAccountingResponse.mEventTimestamp != NULL)
		mEventTimestamp = new OctetString(*(objAccountingResponse.mEventTimestamp));

		if(objAccountingResponse.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<ProxyInfo*>;
		 for( auto element : *objAccountingResponse.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		if(objAccountingResponse.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objAccountingResponse.mCCRequestType));

		}

		virtual ~AccountingResponse();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype AccountingResponse
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype AccountingResponse
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype AccountingResponse
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype AccountingResponse
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype AccountingResponse
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype AccountingResponse
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype AccountingResponse
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype AccountingResponse
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype AccountingResponse
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype AccountingResponse
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AccountingRecordType for datatype AccountingResponse
		*/
		AccountingRecordType* setAccountingRecordType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AccountingRecordType for datatype AccountingResponse
		*/
		void resetAccountingRecordType();

		//!Function to get values
		/*!		Function to get AccountingRecordType type of argument AccountingRecordType for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		AccountingRecordType* getAccountingRecordType();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument AccountingRecordNumber for datatype AccountingResponse
		*/
		Unsigned32* setAccountingRecordNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AccountingRecordNumber for datatype AccountingResponse
		*/
		void resetAccountingRecordNumber();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument AccountingRecordNumber for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getAccountingRecordNumber();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument AcctApplicationId for datatype AccountingResponse
		*/
		Unsigned32* setAcctApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AcctApplicationId for datatype AccountingResponse
		*/
		void resetAcctApplicationId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument AcctApplicationId for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getAcctApplicationId();

		list<VendorSpecificApplicationId*>* getVendorSpecificApplicationIdGrpList();

		list<VendorSpecificApplicationId*>* setVendorSpecificApplicationIdGrpList();

		void resetVendorSpecificApplicationIdGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype AccountingResponse
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype AccountingResponse
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument AccountingSubSessionId for datatype AccountingResponse
		*/
		Unsigned64* setAccountingSubSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AccountingSubSessionId for datatype AccountingResponse
		*/
		void resetAccountingSubSessionId();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument AccountingSubSessionId for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getAccountingSubSessionId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument AcctSessionId for datatype AccountingResponse
		*/
		OctetString* setAcctSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AcctSessionId for datatype AccountingResponse
		*/
		void resetAcctSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument AcctSessionId for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getAcctSessionId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument AcctMultiSessionId for datatype AccountingResponse
		*/
		OctetString* setAcctMultiSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AcctMultiSessionId for datatype AccountingResponse
		*/
		void resetAcctMultiSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument AcctMultiSessionId for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getAcctMultiSessionId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype AccountingResponse
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype AccountingResponse
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorReportingHost for datatype AccountingResponse
		*/
		OctetString* setErrorReportingHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorReportingHost for datatype AccountingResponse
		*/
		void resetErrorReportingHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorReportingHost for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorReportingHost();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument AcctInterimInterval for datatype AccountingResponse
		*/
		Unsigned32* setAcctInterimInterval();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AcctInterimInterval for datatype AccountingResponse
		*/
		void resetAcctInterimInterval();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument AcctInterimInterval for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getAcctInterimInterval();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument AccountingRealtimeRequired for datatype AccountingResponse
		*/
		AccountingRealtimeRequired* setAccountingRealtimeRequired();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AccountingRealtimeRequired for datatype AccountingResponse
		*/
		void resetAccountingRealtimeRequired();

		//!Function to get values
		/*!		Function to get AccountingRealtimeRequired type of argument AccountingRealtimeRequired for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		AccountingRealtimeRequired* getAccountingRealtimeRequired();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument EventTimestamp for datatype AccountingResponse
		*/
		OctetString* setEventTimestamp();

		//! Function to reset 
		/*!		Function to reset NULL type of argument EventTimestamp for datatype AccountingResponse
		*/
		void resetEventTimestamp();

		//!Function to get values
		/*!		Function to get OctetString type of argument EventTimestamp for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getEventTimestamp();

		list<ProxyInfo*>* getProxyInfoGrpList();

		list<ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype AccountingResponse
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype AccountingResponse
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype AccountingResponse
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype AccountingResponse
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype AccountingResponse
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype AccountingResponse
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype AccountingResponse
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AccountingResponse
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
