#ifndef SD_TRACEDATA_H
#define SD_TRACEDATA_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/TraceDepth.h"
#include "sd/include/MDTConfiguration.h"
using namespace std;

namespace SD{
typedef enum _tags_TraceData
{
	TraceData_TRACEREFERENCE	= 0,
	TraceData_TRACEDEPTH	= 1,
	TraceData_TRACENETYPELIST	= 2,
	TraceData_TRACEINTERFACELIST	= 3,
	TraceData_TRACEEVENTLIST	= 4,
	TraceData_OMCID	= 5,
	TraceData_TRACECOLLECTIONENTITY	= 6,
	TraceData_MDTCONFIGURATION	= 7,
}TraceData_tags;

		//! Class Definition
		/*!		ClassName is TraceData
		*/
class TraceData : public DiameterBaseInterface
{
	private:

		bitset<8> mTagsPresent;

		bitset<8> mMandatoryAvpCheckVal;

		bitset<8> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mTraceReference;

		TraceDepth*		mTraceDepth;

		OctetString*		mTraceNETypeList;

		OctetString*		mTraceInterfaceList;

		OctetString*		mTraceEventList;

		OctetString*		mOMCId;

		Address*		mTraceCollectionEntity;









		MDTConfiguration*	mMDTConfigurationGrp;

	public:
		TraceData();

		TraceData(const TraceData &objTraceData) {

		mTagsPresent = objTraceData.mTagsPresent;

		mMandatoryAvpCheckVal = objTraceData.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objTraceData.mMandatoryAvpSetVal;

		mTag = objTraceData.mTag;

		mDecodeFlag = objTraceData.mDecodeFlag;

		if(objTraceData.mTraceReference != NULL)
		mTraceReference = new OctetString(*(objTraceData.mTraceReference));

		if(objTraceData.mTraceDepth != NULL)
		mTraceDepth = new TraceDepth(*(objTraceData.mTraceDepth));

		if(objTraceData.mTraceNETypeList != NULL)
		mTraceNETypeList = new OctetString(*(objTraceData.mTraceNETypeList));

		if(objTraceData.mTraceInterfaceList != NULL)
		mTraceInterfaceList = new OctetString(*(objTraceData.mTraceInterfaceList));

		if(objTraceData.mTraceEventList != NULL)
		mTraceEventList = new OctetString(*(objTraceData.mTraceEventList));

		if(objTraceData.mOMCId != NULL)
		mOMCId = new OctetString(*(objTraceData.mOMCId));

		if(objTraceData.mTraceCollectionEntity != NULL)
		mTraceCollectionEntity = new Address(*(objTraceData.mTraceCollectionEntity));

		if(objTraceData.mMDTConfigurationGrp != NULL)
		 {
				 mMDTConfigurationGrp =  new MDTConfiguration(*objTraceData.mMDTConfigurationGrp);
		 }
		}

		void operator = (const TraceData &objTraceData) {

		mTagsPresent = objTraceData.mTagsPresent;

		mMandatoryAvpCheckVal = objTraceData.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objTraceData.mMandatoryAvpSetVal;

		mTag = objTraceData.mTag;

		mDecodeFlag = objTraceData.mDecodeFlag;

		if(objTraceData.mTraceReference != NULL)
		mTraceReference = new OctetString(*(objTraceData.mTraceReference));

		if(objTraceData.mTraceDepth != NULL)
		mTraceDepth = new TraceDepth(*(objTraceData.mTraceDepth));

		if(objTraceData.mTraceNETypeList != NULL)
		mTraceNETypeList = new OctetString(*(objTraceData.mTraceNETypeList));

		if(objTraceData.mTraceInterfaceList != NULL)
		mTraceInterfaceList = new OctetString(*(objTraceData.mTraceInterfaceList));

		if(objTraceData.mTraceEventList != NULL)
		mTraceEventList = new OctetString(*(objTraceData.mTraceEventList));

		if(objTraceData.mOMCId != NULL)
		mOMCId = new OctetString(*(objTraceData.mOMCId));

		if(objTraceData.mTraceCollectionEntity != NULL)
		mTraceCollectionEntity = new Address(*(objTraceData.mTraceCollectionEntity));

		if(objTraceData.mMDTConfigurationGrp != NULL)
		 {
				 mMDTConfigurationGrp =  new MDTConfiguration(*objTraceData.mMDTConfigurationGrp);
		 }
		}

		virtual ~TraceData();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TraceReference for datatype TraceData
		*/
		OctetString* setTraceReference();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TraceReference for datatype TraceData
		*/
		void resetTraceReference();

		//!Function to get values
		/*!		Function to get OctetString type of argument TraceReference for datatype TraceData
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTraceReference();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument TraceDepth for datatype TraceData
		*/
		TraceDepth* setTraceDepth();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TraceDepth for datatype TraceData
		*/
		void resetTraceDepth();

		//!Function to get values
		/*!		Function to get TraceDepth type of argument TraceDepth for datatype TraceData
		Throws exception of which type and Summary of Exception
		*/
		TraceDepth* getTraceDepth();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TraceNETypeList for datatype TraceData
		*/
		OctetString* setTraceNETypeList();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TraceNETypeList for datatype TraceData
		*/
		void resetTraceNETypeList();

		//!Function to get values
		/*!		Function to get OctetString type of argument TraceNETypeList for datatype TraceData
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTraceNETypeList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TraceInterfaceList for datatype TraceData
		*/
		OctetString* setTraceInterfaceList();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TraceInterfaceList for datatype TraceData
		*/
		void resetTraceInterfaceList();

		//!Function to get values
		/*!		Function to get OctetString type of argument TraceInterfaceList for datatype TraceData
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTraceInterfaceList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TraceEventList for datatype TraceData
		*/
		OctetString* setTraceEventList();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TraceEventList for datatype TraceData
		*/
		void resetTraceEventList();

		//!Function to get values
		/*!		Function to get OctetString type of argument TraceEventList for datatype TraceData
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTraceEventList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument OMCId for datatype TraceData
		*/
		OctetString* setOMCId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OMCId for datatype TraceData
		*/
		void resetOMCId();

		//!Function to get values
		/*!		Function to get OctetString type of argument OMCId for datatype TraceData
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getOMCId();

		//!Function to set values
		/*!		Function to set the recent Address type of argument TraceCollectionEntity for datatype TraceData
		*/
		Address* setTraceCollectionEntity();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TraceCollectionEntity for datatype TraceData
		*/
		void resetTraceCollectionEntity();

		//!Function to get values
		/*!		Function to get Address type of argument TraceCollectionEntity for datatype TraceData
		Throws exception of which type and Summary of Exception
		*/
		Address* getTraceCollectionEntity();

		MDTConfiguration* getMDTConfiguration();

		MDTConfiguration* setMDTConfiguration();

		void resetMDTConfiguration();

		//! Function to Decode
		/*!		Function to Decode datatype TraceData
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype TraceData
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype TraceData
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype TraceData
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype TraceData
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
