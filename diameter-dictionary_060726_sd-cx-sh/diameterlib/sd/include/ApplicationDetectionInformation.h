#ifndef SD_APPLICATIONDETECTIONINFORMATION_H
#define SD_APPLICATIONDETECTIONINFORMATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/FlowInformation.h"
using namespace std;

namespace SD{
typedef enum _tags_ApplicationDetectionInformation
{
	ApplicationDetectionInformation_TDFAPPLICATIONIDENTIFIER	= 0,
	ApplicationDetectionInformation_TDFAPPLICATIONINSTANCEIDENTIFIER	= 1,
	ApplicationDetectionInformation_FLOWINFORMATION	= 2,
}ApplicationDetectionInformation_tags;

		//! Class Definition
		/*!		ClassName is ApplicationDetectionInformation
		*/
class ApplicationDetectionInformation : public DiameterBaseInterface
{
	private:

		bitset<3> mTagsPresent;

		bitset<3> mMandatoryAvpCheckVal;

		bitset<3> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mTDFApplicationIdentifier;

		OctetString*		mTDFApplicationInstanceIdentifier;




		list<FlowInformation*>*	mFlowInformationGrpList;
		list<FlowInformation*>::iterator	mFlowInformationGrpIterator;

	public:
		ApplicationDetectionInformation();

		ApplicationDetectionInformation(const ApplicationDetectionInformation &objApplicationDetectionInformation) {

		mTagsPresent = objApplicationDetectionInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objApplicationDetectionInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objApplicationDetectionInformation.mMandatoryAvpSetVal;

		mTag = objApplicationDetectionInformation.mTag;

		mDecodeFlag = objApplicationDetectionInformation.mDecodeFlag;

		if(objApplicationDetectionInformation.mTDFApplicationIdentifier != NULL)
		mTDFApplicationIdentifier = new OctetString(*(objApplicationDetectionInformation.mTDFApplicationIdentifier));

		if(objApplicationDetectionInformation.mTDFApplicationInstanceIdentifier != NULL)
		mTDFApplicationInstanceIdentifier = new OctetString(*(objApplicationDetectionInformation.mTDFApplicationInstanceIdentifier));

		if(objApplicationDetectionInformation.mFlowInformationGrpList != NULL)
		 {
		 mFlowInformationGrpList = new list<FlowInformation*>;
		 for( auto element : *objApplicationDetectionInformation.mFlowInformationGrpList)
		 {
				 FlowInformation *lFlowInformation =  new FlowInformation(*element);
				 mFlowInformationGrpList->push_back(lFlowInformation);
		 }
		 }
		}

		void operator = (const ApplicationDetectionInformation &objApplicationDetectionInformation) {

		mTagsPresent = objApplicationDetectionInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objApplicationDetectionInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objApplicationDetectionInformation.mMandatoryAvpSetVal;

		mTag = objApplicationDetectionInformation.mTag;

		mDecodeFlag = objApplicationDetectionInformation.mDecodeFlag;

		if(objApplicationDetectionInformation.mTDFApplicationIdentifier != NULL)
		mTDFApplicationIdentifier = new OctetString(*(objApplicationDetectionInformation.mTDFApplicationIdentifier));

		if(objApplicationDetectionInformation.mTDFApplicationInstanceIdentifier != NULL)
		mTDFApplicationInstanceIdentifier = new OctetString(*(objApplicationDetectionInformation.mTDFApplicationInstanceIdentifier));

		if(objApplicationDetectionInformation.mFlowInformationGrpList != NULL)
		 {
		 mFlowInformationGrpList = new list<FlowInformation*>;
		 for( auto element : *objApplicationDetectionInformation.mFlowInformationGrpList)
		 {
				 FlowInformation *lFlowInformation =  new FlowInformation(*element);
				 mFlowInformationGrpList->push_back(lFlowInformation);
		 }
		 }
		}

		virtual ~ApplicationDetectionInformation();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TDFApplicationIdentifier for datatype ApplicationDetectionInformation
		*/
		OctetString* setTDFApplicationIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TDFApplicationIdentifier for datatype ApplicationDetectionInformation
		*/
		void resetTDFApplicationIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument TDFApplicationIdentifier for datatype ApplicationDetectionInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTDFApplicationIdentifier();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TDFApplicationInstanceIdentifier for datatype ApplicationDetectionInformation
		*/
		OctetString* setTDFApplicationInstanceIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TDFApplicationInstanceIdentifier for datatype ApplicationDetectionInformation
		*/
		void resetTDFApplicationInstanceIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument TDFApplicationInstanceIdentifier for datatype ApplicationDetectionInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTDFApplicationInstanceIdentifier();

		list<FlowInformation*>* getFlowInformationGrpList();

		list<FlowInformation*>* setFlowInformationGrpList();

		void resetFlowInformationGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype ApplicationDetectionInformation
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ApplicationDetectionInformation
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ApplicationDetectionInformation
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ApplicationDetectionInformation
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ApplicationDetectionInformation
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
