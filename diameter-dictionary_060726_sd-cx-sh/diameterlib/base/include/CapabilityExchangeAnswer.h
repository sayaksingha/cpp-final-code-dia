#ifndef BASE_CAPABILITYEXCHANGEANSWER_H
#define BASE_CAPABILITYEXCHANGEANSWER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "base/include/VendorSpecificApplicationId.h"
#include "base/include/CCRequestType.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace BASE{
typedef enum _tags_CapabilityExchangeAnswer
{
	CapabilityExchangeAnswer_SESSIONID	= 0,
	CapabilityExchangeAnswer_RESULTCODE	= 1,
	CapabilityExchangeAnswer_ORIGINHOST	= 2,
	CapabilityExchangeAnswer_ORIGINREALM	= 3,
	CapabilityExchangeAnswer_HOSTIPADDRESS	= 4,
	CapabilityExchangeAnswer_VENDORID	= 5,
	CapabilityExchangeAnswer_PRODUCTNAME	= 6,
	CapabilityExchangeAnswer_ORIGINSTATEID	= 7,
	CapabilityExchangeAnswer_ERRORMESSAGE	= 8,
	CapabilityExchangeAnswer_SUPPORTEDVENDORID	= 9,
	CapabilityExchangeAnswer_AUTHAPPLICATIONID	= 10,
	CapabilityExchangeAnswer_INBANDSECURITYID	= 11,
	CapabilityExchangeAnswer_ACCTAPPLICATIONID	= 12,
	CapabilityExchangeAnswer_VENDORSPECIFICAPPLICATIONID	= 13,
	CapabilityExchangeAnswer_FIRMWAREREVISION	= 14,
	CapabilityExchangeAnswer_CCREQUESTTYPE	= 15,
}CapabilityExchangeAnswer_tags;

		//! Class Definition
		/*!		ClassName is CapabilityExchangeAnswer
		*/
class CapabilityExchangeAnswer : public DiameterBase 
{
	private:

		bitset<16> mTagsPresent;

		bitset<16> mMandatoryAvpCheckVal;

		bitset<16> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		Unsigned32*		mResultCode;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		list<Address*>* 		mHostIPAddressList;

		list<Address*>::iterator 		mHostIPAddressIterator;

		Integer32*		mVendorId;

		OctetString*		mProductName;

		Unsigned32*		mOriginStateId;

		OctetString*		mErrorMessage;

		list<Integer32*>* 		mSupportedVendorIdList;

		list<Integer32*>::iterator 		mSupportedVendorIdIterator;

		list<Integer32*>* 		mAuthApplicationIdList;

		list<Integer32*>::iterator 		mAuthApplicationIdIterator;

		Integer32*		mInbandSecurityId;

		list<Unsigned32*>* 		mAcctApplicationIdList;

		list<Unsigned32*>::iterator 		mAcctApplicationIdIterator;

		Integer32*		mFirmwareRevision;

		CCRequestType*		mCCRequestType;















		list<VendorSpecificApplicationId*>*	mVendorSpecificApplicationIdGrpList;
		list<VendorSpecificApplicationId*>::iterator	mVendorSpecificApplicationIdGrpIterator;



	public:
		CapabilityExchangeAnswer();

		CapabilityExchangeAnswer(const CapabilityExchangeAnswer &objCapabilityExchangeAnswer) {

		mTagsPresent = objCapabilityExchangeAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objCapabilityExchangeAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCapabilityExchangeAnswer.mMandatoryAvpSetVal;

		mTag = objCapabilityExchangeAnswer.mTag;

		mDecodeFlag = objCapabilityExchangeAnswer.mDecodeFlag;

		if(objCapabilityExchangeAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objCapabilityExchangeAnswer.mSessionId));

		if(objCapabilityExchangeAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objCapabilityExchangeAnswer.mResultCode));

		if(objCapabilityExchangeAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objCapabilityExchangeAnswer.mOriginHost));

		if(objCapabilityExchangeAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objCapabilityExchangeAnswer.mOriginRealm));

		if(objCapabilityExchangeAnswer.mVendorId != NULL)
		mVendorId = new Integer32(*(objCapabilityExchangeAnswer.mVendorId));

		if(objCapabilityExchangeAnswer.mProductName != NULL)
		mProductName = new OctetString(*(objCapabilityExchangeAnswer.mProductName));

		if(objCapabilityExchangeAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objCapabilityExchangeAnswer.mOriginStateId));

		if(objCapabilityExchangeAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objCapabilityExchangeAnswer.mErrorMessage));

		if(objCapabilityExchangeAnswer.mInbandSecurityId != NULL)
		mInbandSecurityId = new Integer32(*(objCapabilityExchangeAnswer.mInbandSecurityId));

		if(objCapabilityExchangeAnswer.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objCapabilityExchangeAnswer.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		if(objCapabilityExchangeAnswer.mFirmwareRevision != NULL)
		mFirmwareRevision = new Integer32(*(objCapabilityExchangeAnswer.mFirmwareRevision));

		if(objCapabilityExchangeAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objCapabilityExchangeAnswer.mCCRequestType));

		}

		void operator = (const CapabilityExchangeAnswer &objCapabilityExchangeAnswer) {

		mTagsPresent = objCapabilityExchangeAnswer.mTagsPresent;

		mMandatoryAvpCheckVal = objCapabilityExchangeAnswer.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCapabilityExchangeAnswer.mMandatoryAvpSetVal;

		mTag = objCapabilityExchangeAnswer.mTag;

		mDecodeFlag = objCapabilityExchangeAnswer.mDecodeFlag;

		if(objCapabilityExchangeAnswer.mSessionId != NULL)
		mSessionId = new OctetString(*(objCapabilityExchangeAnswer.mSessionId));

		if(objCapabilityExchangeAnswer.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objCapabilityExchangeAnswer.mResultCode));

		if(objCapabilityExchangeAnswer.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objCapabilityExchangeAnswer.mOriginHost));

		if(objCapabilityExchangeAnswer.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objCapabilityExchangeAnswer.mOriginRealm));

		if(objCapabilityExchangeAnswer.mVendorId != NULL)
		mVendorId = new Integer32(*(objCapabilityExchangeAnswer.mVendorId));

		if(objCapabilityExchangeAnswer.mProductName != NULL)
		mProductName = new OctetString(*(objCapabilityExchangeAnswer.mProductName));

		if(objCapabilityExchangeAnswer.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objCapabilityExchangeAnswer.mOriginStateId));

		if(objCapabilityExchangeAnswer.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objCapabilityExchangeAnswer.mErrorMessage));

		if(objCapabilityExchangeAnswer.mInbandSecurityId != NULL)
		mInbandSecurityId = new Integer32(*(objCapabilityExchangeAnswer.mInbandSecurityId));

		if(objCapabilityExchangeAnswer.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objCapabilityExchangeAnswer.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		if(objCapabilityExchangeAnswer.mFirmwareRevision != NULL)
		mFirmwareRevision = new Integer32(*(objCapabilityExchangeAnswer.mFirmwareRevision));

		if(objCapabilityExchangeAnswer.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objCapabilityExchangeAnswer.mCCRequestType));

		}

		virtual ~CapabilityExchangeAnswer();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype CapabilityExchangeAnswer
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype CapabilityExchangeAnswer
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype CapabilityExchangeAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype CapabilityExchangeAnswer
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype CapabilityExchangeAnswer
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype CapabilityExchangeAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype CapabilityExchangeAnswer
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype CapabilityExchangeAnswer
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype CapabilityExchangeAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype CapabilityExchangeAnswer
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype CapabilityExchangeAnswer
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype CapabilityExchangeAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		list<Address*>* getHostIPAddressList();

		list<Address*>* setHostIPAddressList();

		void resetHostIPAddressList();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument VendorId for datatype CapabilityExchangeAnswer
		*/
		Integer32* setVendorId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument VendorId for datatype CapabilityExchangeAnswer
		*/
		void resetVendorId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument VendorId for datatype CapabilityExchangeAnswer
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getVendorId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ProductName for datatype CapabilityExchangeAnswer
		*/
		OctetString* setProductName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ProductName for datatype CapabilityExchangeAnswer
		*/
		void resetProductName();

		//!Function to get values
		/*!		Function to get OctetString type of argument ProductName for datatype CapabilityExchangeAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getProductName();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype CapabilityExchangeAnswer
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype CapabilityExchangeAnswer
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype CapabilityExchangeAnswer
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype CapabilityExchangeAnswer
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype CapabilityExchangeAnswer
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype CapabilityExchangeAnswer
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		list<Integer32*>* getSupportedVendorIdList();

		list<Integer32*>* setSupportedVendorIdList();

		void resetSupportedVendorIdList();

		list<Integer32*>* getAuthApplicationIdList();

		list<Integer32*>* setAuthApplicationIdList();

		void resetAuthApplicationIdList();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument InbandSecurityId for datatype CapabilityExchangeAnswer
		*/
		Integer32* setInbandSecurityId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument InbandSecurityId for datatype CapabilityExchangeAnswer
		*/
		void resetInbandSecurityId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument InbandSecurityId for datatype CapabilityExchangeAnswer
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getInbandSecurityId();

		list<Unsigned32*>* getAcctApplicationIdList();

		list<Unsigned32*>* setAcctApplicationIdList();

		void resetAcctApplicationIdList();

		list<VendorSpecificApplicationId*>* getVendorSpecificApplicationIdGrpList();

		list<VendorSpecificApplicationId*>* setVendorSpecificApplicationIdGrpList();

		void resetVendorSpecificApplicationIdGrpList();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument FirmwareRevision for datatype CapabilityExchangeAnswer
		*/
		Integer32* setFirmwareRevision();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FirmwareRevision for datatype CapabilityExchangeAnswer
		*/
		void resetFirmwareRevision();

		//!Function to get values
		/*!		Function to get Integer32 type of argument FirmwareRevision for datatype CapabilityExchangeAnswer
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getFirmwareRevision();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype CapabilityExchangeAnswer
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype CapabilityExchangeAnswer
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype CapabilityExchangeAnswer
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//! Function to Decode
		/*!		Function to Decode datatype CapabilityExchangeAnswer
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype CapabilityExchangeAnswer
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype CapabilityExchangeAnswer
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype CapabilityExchangeAnswer
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CapabilityExchangeAnswer
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
