#ifndef BASE_CAPABILITYEXCHANGEREQUEST_H
#define BASE_CAPABILITYEXCHANGEREQUEST_H
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
typedef enum _tags_CapabilityExchangeRequest
{
	CapabilityExchangeRequest_SESSIONID	= 0,
	CapabilityExchangeRequest_ORIGINHOST	= 1,
	CapabilityExchangeRequest_ORIGINREALM	= 2,
	CapabilityExchangeRequest_HOSTIPADDRESS	= 3,
	CapabilityExchangeRequest_VENDORID	= 4,
	CapabilityExchangeRequest_PRODUCTNAME	= 5,
	CapabilityExchangeRequest_ORIGINSTATEID	= 6,
	CapabilityExchangeRequest_SUPPORTEDVENDORID	= 7,
	CapabilityExchangeRequest_AUTHAPPLICATIONID	= 8,
	CapabilityExchangeRequest_INBANDSECURITYID	= 9,
	CapabilityExchangeRequest_ACCTAPPLICATIONID	= 10,
	CapabilityExchangeRequest_VENDORSPECIFICAPPLICATIONID	= 11,
	CapabilityExchangeRequest_FIRMWAREREVISION	= 12,
	CapabilityExchangeRequest_SOURCEMODULEID	= 13,
	CapabilityExchangeRequest_DESTMODULEID	= 14,
	CapabilityExchangeRequest_CCREQUESTNUMBER	= 15,
	CapabilityExchangeRequest_RESULTCODE	= 16,
	CapabilityExchangeRequest_CCREQUESTTYPE	= 17,
	CapabilityExchangeRequest_UNIQUEMSGREFNO	= 18,
}CapabilityExchangeRequest_tags;

		//! Class Definition
		/*!		ClassName is CapabilityExchangeRequest
		*/
class CapabilityExchangeRequest : public DiameterBase 
{
	private:

		bitset<19> mTagsPresent;

		bitset<19> mMandatoryAvpCheckVal;

		bitset<19> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		list<Address*>* 		mHostIPAddressList;

		list<Address*>::iterator 		mHostIPAddressIterator;

		Integer32*		mVendorId;

		OctetString*		mProductName;

		Unsigned32*		mOriginStateId;

		list<Integer32*>* 		mSupportedVendorIdList;

		list<Integer32*>::iterator 		mSupportedVendorIdIterator;

		list<Integer32*>* 		mAuthApplicationIdList;

		list<Integer32*>::iterator 		mAuthApplicationIdIterator;

		Integer32*		mInbandSecurityId;

		list<Unsigned32*>* 		mAcctApplicationIdList;

		list<Unsigned32*>::iterator 		mAcctApplicationIdIterator;

		Integer32*		mFirmwareRevision;

		Integer32*		mSourceModuleId;

		Integer32*		mDestModuleId;

		Unsigned32*		mCCRequestNumber;

		Unsigned32*		mResultCode;

		CCRequestType*		mCCRequestType;

		OctetString*		mUniqueMsgRefNo;













		list<VendorSpecificApplicationId*>*	mVendorSpecificApplicationIdGrpList;
		list<VendorSpecificApplicationId*>::iterator	mVendorSpecificApplicationIdGrpIterator;








	public:
		CapabilityExchangeRequest();

		CapabilityExchangeRequest(const CapabilityExchangeRequest &objCapabilityExchangeRequest) {

		mTagsPresent = objCapabilityExchangeRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objCapabilityExchangeRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCapabilityExchangeRequest.mMandatoryAvpSetVal;

		mTag = objCapabilityExchangeRequest.mTag;

		mDecodeFlag = objCapabilityExchangeRequest.mDecodeFlag;

		if(objCapabilityExchangeRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objCapabilityExchangeRequest.mSessionId));

		if(objCapabilityExchangeRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objCapabilityExchangeRequest.mOriginHost));

		if(objCapabilityExchangeRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objCapabilityExchangeRequest.mOriginRealm));

		if(objCapabilityExchangeRequest.mVendorId != NULL)
		mVendorId = new Integer32(*(objCapabilityExchangeRequest.mVendorId));

		if(objCapabilityExchangeRequest.mProductName != NULL)
		mProductName = new OctetString(*(objCapabilityExchangeRequest.mProductName));

		if(objCapabilityExchangeRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objCapabilityExchangeRequest.mOriginStateId));

		if(objCapabilityExchangeRequest.mInbandSecurityId != NULL)
		mInbandSecurityId = new Integer32(*(objCapabilityExchangeRequest.mInbandSecurityId));

		if(objCapabilityExchangeRequest.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objCapabilityExchangeRequest.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		if(objCapabilityExchangeRequest.mFirmwareRevision != NULL)
		mFirmwareRevision = new Integer32(*(objCapabilityExchangeRequest.mFirmwareRevision));

		if(objCapabilityExchangeRequest.mSourceModuleId != NULL)
		mSourceModuleId = new Integer32(*(objCapabilityExchangeRequest.mSourceModuleId));

		if(objCapabilityExchangeRequest.mDestModuleId != NULL)
		mDestModuleId = new Integer32(*(objCapabilityExchangeRequest.mDestModuleId));

		if(objCapabilityExchangeRequest.mCCRequestNumber != NULL)
		mCCRequestNumber = new Unsigned32(*(objCapabilityExchangeRequest.mCCRequestNumber));

		if(objCapabilityExchangeRequest.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objCapabilityExchangeRequest.mResultCode));

		if(objCapabilityExchangeRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objCapabilityExchangeRequest.mCCRequestType));

		if(objCapabilityExchangeRequest.mUniqueMsgRefNo != NULL)
		mUniqueMsgRefNo = new OctetString(*(objCapabilityExchangeRequest.mUniqueMsgRefNo));

		}

		void operator = (const CapabilityExchangeRequest &objCapabilityExchangeRequest) {

		mTagsPresent = objCapabilityExchangeRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objCapabilityExchangeRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCapabilityExchangeRequest.mMandatoryAvpSetVal;

		mTag = objCapabilityExchangeRequest.mTag;

		mDecodeFlag = objCapabilityExchangeRequest.mDecodeFlag;

		if(objCapabilityExchangeRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objCapabilityExchangeRequest.mSessionId));

		if(objCapabilityExchangeRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objCapabilityExchangeRequest.mOriginHost));

		if(objCapabilityExchangeRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objCapabilityExchangeRequest.mOriginRealm));

		if(objCapabilityExchangeRequest.mVendorId != NULL)
		mVendorId = new Integer32(*(objCapabilityExchangeRequest.mVendorId));

		if(objCapabilityExchangeRequest.mProductName != NULL)
		mProductName = new OctetString(*(objCapabilityExchangeRequest.mProductName));

		if(objCapabilityExchangeRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objCapabilityExchangeRequest.mOriginStateId));

		if(objCapabilityExchangeRequest.mInbandSecurityId != NULL)
		mInbandSecurityId = new Integer32(*(objCapabilityExchangeRequest.mInbandSecurityId));

		if(objCapabilityExchangeRequest.mVendorSpecificApplicationIdGrpList != NULL)
		 {
		 mVendorSpecificApplicationIdGrpList = new list<VendorSpecificApplicationId*>;
		 for( auto element : *objCapabilityExchangeRequest.mVendorSpecificApplicationIdGrpList)
		 {
				 VendorSpecificApplicationId *lVendorSpecificApplicationId =  new VendorSpecificApplicationId(*element);
				 mVendorSpecificApplicationIdGrpList->push_back(lVendorSpecificApplicationId);
		 }
		 }
		if(objCapabilityExchangeRequest.mFirmwareRevision != NULL)
		mFirmwareRevision = new Integer32(*(objCapabilityExchangeRequest.mFirmwareRevision));

		if(objCapabilityExchangeRequest.mSourceModuleId != NULL)
		mSourceModuleId = new Integer32(*(objCapabilityExchangeRequest.mSourceModuleId));

		if(objCapabilityExchangeRequest.mDestModuleId != NULL)
		mDestModuleId = new Integer32(*(objCapabilityExchangeRequest.mDestModuleId));

		if(objCapabilityExchangeRequest.mCCRequestNumber != NULL)
		mCCRequestNumber = new Unsigned32(*(objCapabilityExchangeRequest.mCCRequestNumber));

		if(objCapabilityExchangeRequest.mResultCode != NULL)
		mResultCode = new Unsigned32(*(objCapabilityExchangeRequest.mResultCode));

		if(objCapabilityExchangeRequest.mCCRequestType != NULL)
		mCCRequestType = new CCRequestType(*(objCapabilityExchangeRequest.mCCRequestType));

		if(objCapabilityExchangeRequest.mUniqueMsgRefNo != NULL)
		mUniqueMsgRefNo = new OctetString(*(objCapabilityExchangeRequest.mUniqueMsgRefNo));

		}

		virtual ~CapabilityExchangeRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype CapabilityExchangeRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype CapabilityExchangeRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype CapabilityExchangeRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype CapabilityExchangeRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype CapabilityExchangeRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype CapabilityExchangeRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		list<Address*>* getHostIPAddressList();

		list<Address*>* setHostIPAddressList();

		void resetHostIPAddressList();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument VendorId for datatype CapabilityExchangeRequest
		*/
		Integer32* setVendorId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument VendorId for datatype CapabilityExchangeRequest
		*/
		void resetVendorId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument VendorId for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getVendorId();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ProductName for datatype CapabilityExchangeRequest
		*/
		OctetString* setProductName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ProductName for datatype CapabilityExchangeRequest
		*/
		void resetProductName();

		//!Function to get values
		/*!		Function to get OctetString type of argument ProductName for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getProductName();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype CapabilityExchangeRequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype CapabilityExchangeRequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		list<Integer32*>* getSupportedVendorIdList();

		list<Integer32*>* setSupportedVendorIdList();

		void resetSupportedVendorIdList();

		list<Integer32*>* getAuthApplicationIdList();

		list<Integer32*>* setAuthApplicationIdList();

		void resetAuthApplicationIdList();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument InbandSecurityId for datatype CapabilityExchangeRequest
		*/
		Integer32* setInbandSecurityId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument InbandSecurityId for datatype CapabilityExchangeRequest
		*/
		void resetInbandSecurityId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument InbandSecurityId for datatype CapabilityExchangeRequest
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
		/*!		Function to set the recent Integer32 type of argument FirmwareRevision for datatype CapabilityExchangeRequest
		*/
		Integer32* setFirmwareRevision();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FirmwareRevision for datatype CapabilityExchangeRequest
		*/
		void resetFirmwareRevision();

		//!Function to get values
		/*!		Function to get Integer32 type of argument FirmwareRevision for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getFirmwareRevision();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument SourceModuleId for datatype CapabilityExchangeRequest
		*/
		Integer32* setSourceModuleId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SourceModuleId for datatype CapabilityExchangeRequest
		*/
		void resetSourceModuleId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument SourceModuleId for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getSourceModuleId();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument DestModuleId for datatype CapabilityExchangeRequest
		*/
		Integer32* setDestModuleId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestModuleId for datatype CapabilityExchangeRequest
		*/
		void resetDestModuleId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument DestModuleId for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getDestModuleId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument CCRequestNumber for datatype CapabilityExchangeRequest
		*/
		Unsigned32* setCCRequestNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestNumber for datatype CapabilityExchangeRequest
		*/
		void resetCCRequestNumber();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument CCRequestNumber for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getCCRequestNumber();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ResultCode for datatype CapabilityExchangeRequest
		*/
		Unsigned32* setResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ResultCode for datatype CapabilityExchangeRequest
		*/
		void resetResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ResultCode for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getResultCode();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CCRequestType for datatype CapabilityExchangeRequest
		*/
		CCRequestType* setCCRequestType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCRequestType for datatype CapabilityExchangeRequest
		*/
		void resetCCRequestType();

		//!Function to get values
		/*!		Function to get CCRequestType type of argument CCRequestType for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		CCRequestType* getCCRequestType();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UniqueMsgRefNo for datatype CapabilityExchangeRequest
		*/
		OctetString* setUniqueMsgRefNo();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UniqueMsgRefNo for datatype CapabilityExchangeRequest
		*/
		void resetUniqueMsgRefNo();

		//!Function to get values
		/*!		Function to get OctetString type of argument UniqueMsgRefNo for datatype CapabilityExchangeRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUniqueMsgRefNo();

		//! Function to Decode
		/*!		Function to Decode datatype CapabilityExchangeRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype CapabilityExchangeRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype CapabilityExchangeRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype CapabilityExchangeRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CapabilityExchangeRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
