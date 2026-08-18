#ifndef RX_SPONSOREDCONNECTIVITYDATA_H
#define RX_SPONSOREDCONNECTIVITYDATA_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"
#include "rx/include/ProxyInfo.h"
#include "rx/include/SponsoringAction.h"
#include "rx/include/GrantedServiceUnit.h"
#include "rx/include/UsedServiceUnit.h"
using namespace std;

namespace RX{
typedef enum _tags_SponsoredConnectivityData
{
	SponsoredConnectivityData_SPONSORIDENTITY	= 0,
	SponsoredConnectivityData_APPLICATIONSERVICEPROVIDERIDENTITY	= 1,
	SponsoredConnectivityData_SPONSORINGACTION	= 2,
	SponsoredConnectivityData_GRANTEDSERVICEUNIT	= 3,
	SponsoredConnectivityData_USEDSERVICEUNIT	= 4,
	SponsoredConnectivityData_PROXYINFO	= 5,
}SponsoredConnectivityData_tags;

		//! Class Definition
		/*!		ClassName is SponsoredConnectivityData
		*/
class SponsoredConnectivityData : public DiameterBaseInterface
{
	private:

		bitset<6> mTagsPresent;

		bitset<6> mMandatoryAvpCheckVal;

		bitset<6> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mSponsorIdentity;

		OctetString*		mApplicationServiceProviderIdentity;

		SponsoringAction*		mSponsoringAction;





		GrantedServiceUnit*	mGrantedServiceUnitGrp;

		UsedServiceUnit*	mUsedServiceUnitGrp;

		list<RX::ProxyInfo*>*	mProxyInfoGrpList;
		list<RX::ProxyInfo*>::iterator	mProxyInfoGrpIterator;

	public:
		SponsoredConnectivityData();

		SponsoredConnectivityData(const SponsoredConnectivityData &objSponsoredConnectivityData) {

		mTagsPresent = objSponsoredConnectivityData.mTagsPresent;

		mMandatoryAvpCheckVal = objSponsoredConnectivityData.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSponsoredConnectivityData.mMandatoryAvpSetVal;

		mTag = objSponsoredConnectivityData.mTag;

		mDecodeFlag = objSponsoredConnectivityData.mDecodeFlag;

		if(objSponsoredConnectivityData.mSponsorIdentity != NULL)
		mSponsorIdentity = new OctetString(*(objSponsoredConnectivityData.mSponsorIdentity));

		if(objSponsoredConnectivityData.mApplicationServiceProviderIdentity != NULL)
		mApplicationServiceProviderIdentity = new OctetString(*(objSponsoredConnectivityData.mApplicationServiceProviderIdentity));

		if(objSponsoredConnectivityData.mSponsoringAction != NULL)
		mSponsoringAction = new SponsoringAction(*(objSponsoredConnectivityData.mSponsoringAction));

		if(objSponsoredConnectivityData.mGrantedServiceUnitGrp != NULL)
		 {
				 mGrantedServiceUnitGrp =  new GrantedServiceUnit(*objSponsoredConnectivityData.mGrantedServiceUnitGrp);
		 }
		if(objSponsoredConnectivityData.mUsedServiceUnitGrp != NULL)
		 {
				 mUsedServiceUnitGrp =  new UsedServiceUnit(*objSponsoredConnectivityData.mUsedServiceUnitGrp);
		 }
		if(objSponsoredConnectivityData.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objSponsoredConnectivityData.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		void operator = (const SponsoredConnectivityData &objSponsoredConnectivityData) {

		mTagsPresent = objSponsoredConnectivityData.mTagsPresent;

		mMandatoryAvpCheckVal = objSponsoredConnectivityData.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSponsoredConnectivityData.mMandatoryAvpSetVal;

		mTag = objSponsoredConnectivityData.mTag;

		mDecodeFlag = objSponsoredConnectivityData.mDecodeFlag;

		if(objSponsoredConnectivityData.mSponsorIdentity != NULL)
		mSponsorIdentity = new OctetString(*(objSponsoredConnectivityData.mSponsorIdentity));

		if(objSponsoredConnectivityData.mApplicationServiceProviderIdentity != NULL)
		mApplicationServiceProviderIdentity = new OctetString(*(objSponsoredConnectivityData.mApplicationServiceProviderIdentity));

		if(objSponsoredConnectivityData.mSponsoringAction != NULL)
		mSponsoringAction = new SponsoringAction(*(objSponsoredConnectivityData.mSponsoringAction));

		if(objSponsoredConnectivityData.mGrantedServiceUnitGrp != NULL)
		 {
				 mGrantedServiceUnitGrp =  new GrantedServiceUnit(*objSponsoredConnectivityData.mGrantedServiceUnitGrp);
		 }
		if(objSponsoredConnectivityData.mUsedServiceUnitGrp != NULL)
		 {
				 mUsedServiceUnitGrp =  new UsedServiceUnit(*objSponsoredConnectivityData.mUsedServiceUnitGrp);
		 }
		if(objSponsoredConnectivityData.mProxyInfoGrpList != NULL)
		 {
		 mProxyInfoGrpList = new list<RX::ProxyInfo*>;
		 for( auto element : *objSponsoredConnectivityData.mProxyInfoGrpList)
		 {
				 ProxyInfo *lProxyInfo =  new ProxyInfo(*element);
				 mProxyInfoGrpList->push_back(lProxyInfo);
		 }
		 }
		}

		virtual ~SponsoredConnectivityData();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SponsorIdentity for datatype SponsoredConnectivityData
		*/
		OctetString* setSponsorIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SponsorIdentity for datatype SponsoredConnectivityData
		*/
		void resetSponsorIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument SponsorIdentity for datatype SponsoredConnectivityData
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSponsorIdentity();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ApplicationServiceProviderIdentity for datatype SponsoredConnectivityData
		*/
		OctetString* setApplicationServiceProviderIdentity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ApplicationServiceProviderIdentity for datatype SponsoredConnectivityData
		*/
		void resetApplicationServiceProviderIdentity();

		//!Function to get values
		/*!		Function to get OctetString type of argument ApplicationServiceProviderIdentity for datatype SponsoredConnectivityData
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getApplicationServiceProviderIdentity();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument SponsoringAction for datatype SponsoredConnectivityData
		*/
		SponsoringAction* setSponsoringAction();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SponsoringAction for datatype SponsoredConnectivityData
		*/
		void resetSponsoringAction();

		//!Function to get values
		/*!		Function to get SponsoringAction type of argument SponsoringAction for datatype SponsoredConnectivityData
		Throws exception of which type and Summary of Exception
		*/
		SponsoringAction* getSponsoringAction();

		GrantedServiceUnit* getGrantedServiceUnit();

		GrantedServiceUnit* setGrantedServiceUnit();

		void resetGrantedServiceUnit();

		UsedServiceUnit* getUsedServiceUnit();

		UsedServiceUnit* setUsedServiceUnit();

		void resetUsedServiceUnit();

		list<RX::ProxyInfo*>* getProxyInfoGrpList();

		list<RX::ProxyInfo*>* setProxyInfoGrpList();

		void resetProxyInfoGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype SponsoredConnectivityData
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype SponsoredConnectivityData
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SponsoredConnectivityData
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SponsoredConnectivityData
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SponsoredConnectivityData
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
