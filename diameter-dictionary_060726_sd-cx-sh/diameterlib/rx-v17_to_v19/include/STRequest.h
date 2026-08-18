#ifndef RX_STREQUEST_H
#define RX_STREQUEST_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"
#include "rx/include/ProxyInfo.h"
#include "rx/include/DRMP.h"
#include "rx/include/TerminationCause.h"
#include "rx/include/OCSupportedFeatures.h"
#include "base/include/DiameterBase.h"
#include "DiameterBaseInterface.h"
#include "base/include/DiameterMsgHeader.h"
using namespace std;

namespace RX{
typedef enum _tags_STRequest
{
	STRequest_SESSIONID	= 0,
	STRequest_DRMP	= 1,
	STRequest_ORIGINHOST	= 2,
	STRequest_ORIGINREALM	= 3,
	STRequest_DESTINATIONREALM	= 4,
	STRequest_AUTHAPPLICATIONID	= 5,
	STRequest_TERMINATIONCAUSE	= 6,
	STRequest_DESTINATIONHOST	= 7,
	STRequest_OCSUPPORTEDFEATURES	= 8,
	STRequest_REQUIREDACCESSINFO	= 9,
	STRequest_CLASS	= 10,
	STRequest_ORIGINSTATEID	= 11,
	STRequest_PROXYINFO	= 12,
	STRequest_ROUTERECORD	= 13,
}STRequest_tags;

		//! Class Definition
		/*!		ClassName is STRequest
		*/
class STRequest : public DiameterBase 
{
	private:

		bitset<14> mTagsPresent;

		bitset<14> mMandatoryAvpCheckVal;

		bitset<14> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		OctetString*		mSessionId;

		DRMP*		mDRMP;

		OctetString*		mOriginHost;

		OctetString*		mOriginRealm;

		OctetString*		mDestinationRealm;

		Integer32*		mAuthApplicationId;

		TerminationCause*		mTerminationCause;

		OctetString*		mDestinationHost;

		list<OctetString*>* 		mRequiredAccessInfoList;

		list<OctetString*>::iterator 		mRequiredAccessInfoIterator;

		OctetString*		mClass;

		Unsigned32*		mOriginStateId;

		list<OctetString*>* 		mRouteRecordList;

		list<OctetString*>::iterator 		mRouteRecordIterator;










		OCSupportedFeatures*	mOCSupportedFeaturesGrp;




		list<RX::ProxyInfo*>*	mProxyInfoGrpList;
		list<RX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;


	public:
		STRequest();

		STRequest(const STRequest &objSTRequest) {

		mTagsPresent = objSTRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objSTRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSTRequest.mMandatoryAvpSetVal;

		mTag = objSTRequest.mTag;

		mDecodeFlag = objSTRequest.mDecodeFlag;

		if(objSTRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objSTRequest.mSessionId));

		if(objSTRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objSTRequest.mDRMP));

		if(objSTRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSTRequest.mOriginHost));

		if(objSTRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSTRequest.mOriginRealm));

		if(objSTRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objSTRequest.mDestinationRealm));

		if(objSTRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objSTRequest.mAuthApplicationId));

		if(objSTRequest.mTerminationCause != NULL)
		mTerminationCause = new TerminationCause(*(objSTRequest.mTerminationCause));

		if(objSTRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objSTRequest.mDestinationHost));

		if(objSTRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objSTRequest.mOCSupportedFeaturesGrp);
		 }
		if(objSTRequest.mClass != NULL)
		mClass = new OctetString(*(objSTRequest.mClass));

		if(objSTRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objSTRequest.mOriginStateId));

		if(objSTRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objSTRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const STRequest &objSTRequest) {

		mTagsPresent = objSTRequest.mTagsPresent;

		mMandatoryAvpCheckVal = objSTRequest.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSTRequest.mMandatoryAvpSetVal;

		mTag = objSTRequest.mTag;

		mDecodeFlag = objSTRequest.mDecodeFlag;

		if(objSTRequest.mSessionId != NULL)
		mSessionId = new OctetString(*(objSTRequest.mSessionId));

		if(objSTRequest.mDRMP != NULL)
		mDRMP = new DRMP(*(objSTRequest.mDRMP));

		if(objSTRequest.mOriginHost != NULL)
		mOriginHost = new OctetString(*(objSTRequest.mOriginHost));

		if(objSTRequest.mOriginRealm != NULL)
		mOriginRealm = new OctetString(*(objSTRequest.mOriginRealm));

		if(objSTRequest.mDestinationRealm != NULL)
		mDestinationRealm = new OctetString(*(objSTRequest.mDestinationRealm));

		if(objSTRequest.mAuthApplicationId != NULL)
		mAuthApplicationId = new Integer32(*(objSTRequest.mAuthApplicationId));

		if(objSTRequest.mTerminationCause != NULL)
		mTerminationCause = new TerminationCause(*(objSTRequest.mTerminationCause));

		if(objSTRequest.mDestinationHost != NULL)
		mDestinationHost = new OctetString(*(objSTRequest.mDestinationHost));

		if(objSTRequest.mOCSupportedFeaturesGrp != NULL)
		 {
				 mOCSupportedFeaturesGrp =  new OCSupportedFeatures(*objSTRequest.mOCSupportedFeaturesGrp);
		 }
		if(objSTRequest.mClass != NULL)
		mClass = new OctetString(*(objSTRequest.mClass));

		if(objSTRequest.mOriginStateId != NULL)
		mOriginStateId = new Unsigned32(*(objSTRequest.mOriginStateId));

		if(objSTRequest.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objSTRequest.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~STRequest();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SessionId for datatype STRequest
		*/
		OctetString* setSessionId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SessionId for datatype STRequest
		*/
		void resetSessionId();

		//!Function to get values
		/*!		Function to get OctetString type of argument SessionId for datatype STRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSessionId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument DRMP for datatype STRequest
		*/
		DRMP* setDRMP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DRMP for datatype STRequest
		*/
		void resetDRMP();

		//!Function to get values
		/*!		Function to get DRMP type of argument DRMP for datatype STRequest
		Throws exception of which type and Summary of Exception
		*/
		DRMP* getDRMP();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginHost for datatype STRequest
		*/
		OctetString* setOriginHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginHost for datatype STRequest
		*/
		void resetOriginHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginHost for datatype STRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginHost();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OriginRealm for datatype STRequest
		*/
		OctetString* setOriginRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginRealm for datatype STRequest
		*/
		void resetOriginRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument OriginRealm for datatype STRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOriginRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationRealm for datatype STRequest
		*/
		OctetString* setDestinationRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationRealm for datatype STRequest
		*/
		void resetDestinationRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationRealm for datatype STRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationRealm();

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument AuthApplicationId for datatype STRequest
		*/
		Integer32* setAuthApplicationId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AuthApplicationId for datatype STRequest
		*/
		void resetAuthApplicationId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument AuthApplicationId for datatype STRequest
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getAuthApplicationId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument TerminationCause for datatype STRequest
		*/
		TerminationCause* setTerminationCause();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TerminationCause for datatype STRequest
		*/
		void resetTerminationCause();

		//!Function to get values
		/*!		Function to get TerminationCause type of argument TerminationCause for datatype STRequest
		Throws exception of which type and Summary of Exception
		*/
		TerminationCause* getTerminationCause();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument DestinationHost for datatype STRequest
		*/
		OctetString* setDestinationHost();

		//! Function to reset 
		/*!		Function to reset NULL type of argument DestinationHost for datatype STRequest
		*/
		void resetDestinationHost();

		//!Function to get values
		/*!		Function to get OctetString type of argument DestinationHost for datatype STRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getDestinationHost();

		OCSupportedFeatures* getOCSupportedFeatures();

		OCSupportedFeatures* setOCSupportedFeatures();

		void resetOCSupportedFeatures();

		list<OctetString*>* getRequiredAccessInfoList();

		list<OctetString*>* setRequiredAccessInfoList();

		void resetRequiredAccessInfoList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument Class for datatype STRequest
		*/
		OctetString* setClass();

		//! Function to reset 
		/*!		Function to reset NULL type of argument Class for datatype STRequest
		*/
		void resetClass();

		//!Function to get values
		/*!		Function to get OctetString type of argument Class for datatype STRequest
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getClass();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OriginStateId for datatype STRequest
		*/
		Unsigned32* setOriginStateId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OriginStateId for datatype STRequest
		*/
		void resetOriginStateId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OriginStateId for datatype STRequest
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOriginStateId();

		list<RX::ProxyInfo*>* getProxyInfoGrpList();

		list<RX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		list<OctetString*>* getRouteRecordList();

		list<OctetString*>* setRouteRecordList();

		void resetRouteRecordList();

		//! Function to Decode
		/*!		Function to Decode datatype STRequest
		*/
		int Decode(byteArray *array, INT16 lMLen = 0, UINT16 *parsedBytes=NULL);
		//! Function to Find
		/*!		Function to Find datatype STRequest
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype STRequest
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype STRequest
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype STRequest
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
