#ifndef SD_QOSINFORMATION_H
#define SD_QOSINFORMATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/QoSClassIdentifier.h"
#include "sd/include/AllocationRetentionPriority.h"
#include "sd/include/ConditionalAPNAggregateMaxBitrate.h"
using namespace std;

namespace SD{
typedef enum _tags_QoSInformation
{
	QoSInformation_QOSCLASSIDENTIFIER	= 0,
	QoSInformation_MAXREQUESTEDBANDWIDTHUL	= 1,
	QoSInformation_MAXREQUESTEDBANDWIDTHDL	= 2,
	QoSInformation_EXTENDEDMAXREQUESTEDBWUL	= 3,
	QoSInformation_EXTENDEDMAXREQUESTEDBWDL	= 4,
	QoSInformation_GUARANTEEDBITRATEUL	= 5,
	QoSInformation_GUARANTEEDBITRATEDL	= 6,
	QoSInformation_EXTENDEDGBRUL	= 7,
	QoSInformation_EXTENDEDGBRDL	= 8,
	QoSInformation_BEARERIDENTIFIER	= 9,
	QoSInformation_ALLOCATIONRETENTIONPRIORITY	= 10,
	QoSInformation_APNAGGREGATEMAXBITRATEUL	= 11,
	QoSInformation_APNAGGREGATEMAXBITRATEDL	= 12,
	QoSInformation_EXTENDEDAPNAMBRUL	= 13,
	QoSInformation_EXTENDEDAPNAMBRDL	= 14,
	QoSInformation_CONDITIONALAPNAGGREGATEMAXBITRATE	= 15,
}QoSInformation_tags;

		//! Class Definition
		/*!		ClassName is QoSInformation
		*/
class QoSInformation : public DiameterBaseInterface
{
	private:

		bitset<16> mTagsPresent;

		bitset<16> mMandatoryAvpCheckVal;

		bitset<16> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		QoSClassIdentifier*		mQoSClassIdentifier;

		Unsigned32*		mMaxRequestedBandwidthUL;

		Unsigned32*		mMaxRequestedBandwidthDL;

		Unsigned32*		mExtendedMaxRequestedBWUL;

		Unsigned32*		mExtendedMaxRequestedBWDL;

		Unsigned32*		mGuaranteedBitrateUL;

		Unsigned32*		mGuaranteedBitrateDL;

		Unsigned32*		mExtendedGBRUL;

		Unsigned32*		mExtendedGBRDL;

		OctetString*		mBearerIdentifier;

		Unsigned32*		mAPNAggregateMaxBitrateUL;

		Unsigned32*		mAPNAggregateMaxBitrateDL;

		Unsigned32*		mExtendedAPNAMBRUL;

		Unsigned32*		mExtendedAPNAMBRDL;












		AllocationRetentionPriority*	mAllocationRetentionPriorityGrp;





		list<ConditionalAPNAggregateMaxBitrate*>*	mConditionalAPNAggregateMaxBitrateGrpList;
		list<ConditionalAPNAggregateMaxBitrate*>::iterator	mConditionalAPNAggregateMaxBitrateGrpIterator;

	public:
		QoSInformation();

		QoSInformation(const QoSInformation &objQoSInformation) {

		mTagsPresent = objQoSInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objQoSInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objQoSInformation.mMandatoryAvpSetVal;

		mTag = objQoSInformation.mTag;

		mDecodeFlag = objQoSInformation.mDecodeFlag;

		if(objQoSInformation.mQoSClassIdentifier != NULL)
		mQoSClassIdentifier = new QoSClassIdentifier(*(objQoSInformation.mQoSClassIdentifier));

		if(objQoSInformation.mMaxRequestedBandwidthUL != NULL)
		mMaxRequestedBandwidthUL = new Unsigned32(*(objQoSInformation.mMaxRequestedBandwidthUL));

		if(objQoSInformation.mMaxRequestedBandwidthDL != NULL)
		mMaxRequestedBandwidthDL = new Unsigned32(*(objQoSInformation.mMaxRequestedBandwidthDL));

		if(objQoSInformation.mExtendedMaxRequestedBWUL != NULL)
		mExtendedMaxRequestedBWUL = new Unsigned32(*(objQoSInformation.mExtendedMaxRequestedBWUL));

		if(objQoSInformation.mExtendedMaxRequestedBWDL != NULL)
		mExtendedMaxRequestedBWDL = new Unsigned32(*(objQoSInformation.mExtendedMaxRequestedBWDL));

		if(objQoSInformation.mGuaranteedBitrateUL != NULL)
		mGuaranteedBitrateUL = new Unsigned32(*(objQoSInformation.mGuaranteedBitrateUL));

		if(objQoSInformation.mGuaranteedBitrateDL != NULL)
		mGuaranteedBitrateDL = new Unsigned32(*(objQoSInformation.mGuaranteedBitrateDL));

		if(objQoSInformation.mExtendedGBRUL != NULL)
		mExtendedGBRUL = new Unsigned32(*(objQoSInformation.mExtendedGBRUL));

		if(objQoSInformation.mExtendedGBRDL != NULL)
		mExtendedGBRDL = new Unsigned32(*(objQoSInformation.mExtendedGBRDL));

		if(objQoSInformation.mBearerIdentifier != NULL)
		mBearerIdentifier = new OctetString(*(objQoSInformation.mBearerIdentifier));

		if(objQoSInformation.mAllocationRetentionPriorityGrp != NULL)
		 {
				 mAllocationRetentionPriorityGrp =  new AllocationRetentionPriority(*objQoSInformation.mAllocationRetentionPriorityGrp);
		 }
		if(objQoSInformation.mAPNAggregateMaxBitrateUL != NULL)
		mAPNAggregateMaxBitrateUL = new Unsigned32(*(objQoSInformation.mAPNAggregateMaxBitrateUL));

		if(objQoSInformation.mAPNAggregateMaxBitrateDL != NULL)
		mAPNAggregateMaxBitrateDL = new Unsigned32(*(objQoSInformation.mAPNAggregateMaxBitrateDL));

		if(objQoSInformation.mExtendedAPNAMBRUL != NULL)
		mExtendedAPNAMBRUL = new Unsigned32(*(objQoSInformation.mExtendedAPNAMBRUL));

		if(objQoSInformation.mExtendedAPNAMBRDL != NULL)
		mExtendedAPNAMBRDL = new Unsigned32(*(objQoSInformation.mExtendedAPNAMBRDL));

		if(objQoSInformation.mConditionalAPNAggregateMaxBitrateGrpList != NULL)
		 {
		 mConditionalAPNAggregateMaxBitrateGrpList = new list<ConditionalAPNAggregateMaxBitrate*>;
		 for( auto element : *objQoSInformation.mConditionalAPNAggregateMaxBitrateGrpList)
		 {
				 ConditionalAPNAggregateMaxBitrate *lConditionalAPNAggregateMaxBitrate =  new ConditionalAPNAggregateMaxBitrate(*element);
				 mConditionalAPNAggregateMaxBitrateGrpList->push_back(lConditionalAPNAggregateMaxBitrate);
		 }
		 }
		}

		void operator = (const QoSInformation &objQoSInformation) {

		mTagsPresent = objQoSInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objQoSInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objQoSInformation.mMandatoryAvpSetVal;

		mTag = objQoSInformation.mTag;

		mDecodeFlag = objQoSInformation.mDecodeFlag;

		if(objQoSInformation.mQoSClassIdentifier != NULL)
		mQoSClassIdentifier = new QoSClassIdentifier(*(objQoSInformation.mQoSClassIdentifier));

		if(objQoSInformation.mMaxRequestedBandwidthUL != NULL)
		mMaxRequestedBandwidthUL = new Unsigned32(*(objQoSInformation.mMaxRequestedBandwidthUL));

		if(objQoSInformation.mMaxRequestedBandwidthDL != NULL)
		mMaxRequestedBandwidthDL = new Unsigned32(*(objQoSInformation.mMaxRequestedBandwidthDL));

		if(objQoSInformation.mExtendedMaxRequestedBWUL != NULL)
		mExtendedMaxRequestedBWUL = new Unsigned32(*(objQoSInformation.mExtendedMaxRequestedBWUL));

		if(objQoSInformation.mExtendedMaxRequestedBWDL != NULL)
		mExtendedMaxRequestedBWDL = new Unsigned32(*(objQoSInformation.mExtendedMaxRequestedBWDL));

		if(objQoSInformation.mGuaranteedBitrateUL != NULL)
		mGuaranteedBitrateUL = new Unsigned32(*(objQoSInformation.mGuaranteedBitrateUL));

		if(objQoSInformation.mGuaranteedBitrateDL != NULL)
		mGuaranteedBitrateDL = new Unsigned32(*(objQoSInformation.mGuaranteedBitrateDL));

		if(objQoSInformation.mExtendedGBRUL != NULL)
		mExtendedGBRUL = new Unsigned32(*(objQoSInformation.mExtendedGBRUL));

		if(objQoSInformation.mExtendedGBRDL != NULL)
		mExtendedGBRDL = new Unsigned32(*(objQoSInformation.mExtendedGBRDL));

		if(objQoSInformation.mBearerIdentifier != NULL)
		mBearerIdentifier = new OctetString(*(objQoSInformation.mBearerIdentifier));

		if(objQoSInformation.mAllocationRetentionPriorityGrp != NULL)
		 {
				 mAllocationRetentionPriorityGrp =  new AllocationRetentionPriority(*objQoSInformation.mAllocationRetentionPriorityGrp);
		 }
		if(objQoSInformation.mAPNAggregateMaxBitrateUL != NULL)
		mAPNAggregateMaxBitrateUL = new Unsigned32(*(objQoSInformation.mAPNAggregateMaxBitrateUL));

		if(objQoSInformation.mAPNAggregateMaxBitrateDL != NULL)
		mAPNAggregateMaxBitrateDL = new Unsigned32(*(objQoSInformation.mAPNAggregateMaxBitrateDL));

		if(objQoSInformation.mExtendedAPNAMBRUL != NULL)
		mExtendedAPNAMBRUL = new Unsigned32(*(objQoSInformation.mExtendedAPNAMBRUL));

		if(objQoSInformation.mExtendedAPNAMBRDL != NULL)
		mExtendedAPNAMBRDL = new Unsigned32(*(objQoSInformation.mExtendedAPNAMBRDL));

		if(objQoSInformation.mConditionalAPNAggregateMaxBitrateGrpList != NULL)
		 {
		 mConditionalAPNAggregateMaxBitrateGrpList = new list<ConditionalAPNAggregateMaxBitrate*>;
		 for( auto element : *objQoSInformation.mConditionalAPNAggregateMaxBitrateGrpList)
		 {
				 ConditionalAPNAggregateMaxBitrate *lConditionalAPNAggregateMaxBitrate =  new ConditionalAPNAggregateMaxBitrate(*element);
				 mConditionalAPNAggregateMaxBitrateGrpList->push_back(lConditionalAPNAggregateMaxBitrate);
		 }
		 }
		}

		virtual ~QoSInformation();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument QoSClassIdentifier for datatype QoSInformation
		*/
		QoSClassIdentifier* setQoSClassIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument QoSClassIdentifier for datatype QoSInformation
		*/
		void resetQoSClassIdentifier();

		//!Function to get values
		/*!		Function to get QoSClassIdentifier type of argument QoSClassIdentifier for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		QoSClassIdentifier* getQoSClassIdentifier();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MaxRequestedBandwidthUL for datatype QoSInformation
		*/
		Unsigned32* setMaxRequestedBandwidthUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MaxRequestedBandwidthUL for datatype QoSInformation
		*/
		void resetMaxRequestedBandwidthUL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MaxRequestedBandwidthUL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMaxRequestedBandwidthUL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MaxRequestedBandwidthDL for datatype QoSInformation
		*/
		Unsigned32* setMaxRequestedBandwidthDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MaxRequestedBandwidthDL for datatype QoSInformation
		*/
		void resetMaxRequestedBandwidthDL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MaxRequestedBandwidthDL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMaxRequestedBandwidthDL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ExtendedMaxRequestedBWUL for datatype QoSInformation
		*/
		Unsigned32* setExtendedMaxRequestedBWUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExtendedMaxRequestedBWUL for datatype QoSInformation
		*/
		void resetExtendedMaxRequestedBWUL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ExtendedMaxRequestedBWUL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getExtendedMaxRequestedBWUL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ExtendedMaxRequestedBWDL for datatype QoSInformation
		*/
		Unsigned32* setExtendedMaxRequestedBWDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExtendedMaxRequestedBWDL for datatype QoSInformation
		*/
		void resetExtendedMaxRequestedBWDL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ExtendedMaxRequestedBWDL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getExtendedMaxRequestedBWDL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument GuaranteedBitrateUL for datatype QoSInformation
		*/
		Unsigned32* setGuaranteedBitrateUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument GuaranteedBitrateUL for datatype QoSInformation
		*/
		void resetGuaranteedBitrateUL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument GuaranteedBitrateUL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getGuaranteedBitrateUL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument GuaranteedBitrateDL for datatype QoSInformation
		*/
		Unsigned32* setGuaranteedBitrateDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument GuaranteedBitrateDL for datatype QoSInformation
		*/
		void resetGuaranteedBitrateDL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument GuaranteedBitrateDL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getGuaranteedBitrateDL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ExtendedGBRUL for datatype QoSInformation
		*/
		Unsigned32* setExtendedGBRUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExtendedGBRUL for datatype QoSInformation
		*/
		void resetExtendedGBRUL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ExtendedGBRUL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getExtendedGBRUL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ExtendedGBRDL for datatype QoSInformation
		*/
		Unsigned32* setExtendedGBRDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExtendedGBRDL for datatype QoSInformation
		*/
		void resetExtendedGBRDL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ExtendedGBRDL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getExtendedGBRDL();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument BearerIdentifier for datatype QoSInformation
		*/
		OctetString* setBearerIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument BearerIdentifier for datatype QoSInformation
		*/
		void resetBearerIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument BearerIdentifier for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getBearerIdentifier();

		AllocationRetentionPriority* getAllocationRetentionPriority();

		AllocationRetentionPriority* setAllocationRetentionPriority();

		void resetAllocationRetentionPriority();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument APNAggregateMaxBitrateUL for datatype QoSInformation
		*/
		Unsigned32* setAPNAggregateMaxBitrateUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument APNAggregateMaxBitrateUL for datatype QoSInformation
		*/
		void resetAPNAggregateMaxBitrateUL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument APNAggregateMaxBitrateUL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getAPNAggregateMaxBitrateUL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument APNAggregateMaxBitrateDL for datatype QoSInformation
		*/
		Unsigned32* setAPNAggregateMaxBitrateDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument APNAggregateMaxBitrateDL for datatype QoSInformation
		*/
		void resetAPNAggregateMaxBitrateDL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument APNAggregateMaxBitrateDL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getAPNAggregateMaxBitrateDL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ExtendedAPNAMBRUL for datatype QoSInformation
		*/
		Unsigned32* setExtendedAPNAMBRUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExtendedAPNAMBRUL for datatype QoSInformation
		*/
		void resetExtendedAPNAMBRUL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ExtendedAPNAMBRUL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getExtendedAPNAMBRUL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ExtendedAPNAMBRDL for datatype QoSInformation
		*/
		Unsigned32* setExtendedAPNAMBRDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExtendedAPNAMBRDL for datatype QoSInformation
		*/
		void resetExtendedAPNAMBRDL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ExtendedAPNAMBRDL for datatype QoSInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getExtendedAPNAMBRDL();

		list<ConditionalAPNAggregateMaxBitrate*>* getConditionalAPNAggregateMaxBitrateGrpList();

		list<ConditionalAPNAggregateMaxBitrate*>* setConditionalAPNAggregateMaxBitrateGrpList();

		void resetConditionalAPNAggregateMaxBitrateGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype QoSInformation
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype QoSInformation
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype QoSInformation
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype QoSInformation
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype QoSInformation
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
