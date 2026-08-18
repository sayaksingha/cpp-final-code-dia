#ifndef RX_ACCESSNETWORKCHARGINGIDENTIFIER_H
#define RX_ACCESSNETWORKCHARGINGIDENTIFIER_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "rx/include/Flows.h"
using namespace std;

namespace RX{
typedef enum _tags_AccessNetworkChargingIdentifier
{
	AccessNetworkChargingIdentifier_ACCESSNETWORKCHARGINGIDENTIFIERVALUE	= 0,
	AccessNetworkChargingIdentifier_FLOWS	= 1,
}AccessNetworkChargingIdentifier_tags;

		//! Class Definition
		/*!		ClassName is AccessNetworkChargingIdentifier
		*/
class AccessNetworkChargingIdentifier : public DiameterBaseInterface
{
	private:

		bitset<2> mTagsPresent;

		bitset<2> mMandatoryAvpCheckVal;

		bitset<2> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mAccessNetworkChargingIdentifierValue;



		list<Flows*>*	mFlowsGrpList;
		list<Flows*>::iterator	mFlowsGrpIterator;

	public:
		AccessNetworkChargingIdentifier();

		AccessNetworkChargingIdentifier(const AccessNetworkChargingIdentifier &objAccessNetworkChargingIdentifier) {

		mTagsPresent = objAccessNetworkChargingIdentifier.mTagsPresent;

		mMandatoryAvpCheckVal = objAccessNetworkChargingIdentifier.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAccessNetworkChargingIdentifier.mMandatoryAvpSetVal;

		mTag = objAccessNetworkChargingIdentifier.mTag;

		mDecodeFlag = objAccessNetworkChargingIdentifier.mDecodeFlag;

		if(objAccessNetworkChargingIdentifier.mAccessNetworkChargingIdentifierValue != NULL)
		mAccessNetworkChargingIdentifierValue = new OctetString(*(objAccessNetworkChargingIdentifier.mAccessNetworkChargingIdentifierValue));

		if(objAccessNetworkChargingIdentifier.mFlowsGrpList != NULL)
		 {
		 mFlowsGrpList = new list<Flows*>;
		 for( auto element : *objAccessNetworkChargingIdentifier.mFlowsGrpList)
		 {
				 Flows *lFlows =  new Flows(*element);
				 mFlowsGrpList->push_back(lFlows);
		 }
		 }
		}

		void operator = (const AccessNetworkChargingIdentifier &objAccessNetworkChargingIdentifier) {

		mTagsPresent = objAccessNetworkChargingIdentifier.mTagsPresent;

		mMandatoryAvpCheckVal = objAccessNetworkChargingIdentifier.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAccessNetworkChargingIdentifier.mMandatoryAvpSetVal;

		mTag = objAccessNetworkChargingIdentifier.mTag;

		mDecodeFlag = objAccessNetworkChargingIdentifier.mDecodeFlag;

		if(objAccessNetworkChargingIdentifier.mAccessNetworkChargingIdentifierValue != NULL)
		mAccessNetworkChargingIdentifierValue = new OctetString(*(objAccessNetworkChargingIdentifier.mAccessNetworkChargingIdentifierValue));

		if(objAccessNetworkChargingIdentifier.mFlowsGrpList != NULL)
		 {
		 mFlowsGrpList = new list<Flows*>;
		 for( auto element : *objAccessNetworkChargingIdentifier.mFlowsGrpList)
		 {
				 Flows *lFlows =  new Flows(*element);
				 mFlowsGrpList->push_back(lFlows);
		 }
		 }
		}

		virtual ~AccessNetworkChargingIdentifier();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument AccessNetworkChargingIdentifierValue for datatype AccessNetworkChargingIdentifier
		*/
		OctetString* setAccessNetworkChargingIdentifierValue();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AccessNetworkChargingIdentifierValue for datatype AccessNetworkChargingIdentifier
		*/
		void resetAccessNetworkChargingIdentifierValue();

		//!Function to get values
		/*!		Function to get OctetString type of argument AccessNetworkChargingIdentifierValue for datatype AccessNetworkChargingIdentifier
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getAccessNetworkChargingIdentifierValue();

		list<Flows*>* getFlowsGrpList();

		list<Flows*>* setFlowsGrpList();

		void resetFlowsGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype AccessNetworkChargingIdentifier
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype AccessNetworkChargingIdentifier
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype AccessNetworkChargingIdentifier
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype AccessNetworkChargingIdentifier
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AccessNetworkChargingIdentifier
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
