#ifndef SD_ALLOCATIONRETENTIONPRIORITY_H
#define SD_ALLOCATIONRETENTIONPRIORITY_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/PreemptionCapability.h"
#include "sd/include/PreemptionVulnerability.h"
using namespace std;

namespace SD{
typedef enum _tags_AllocationRetentionPriority
{
	AllocationRetentionPriority_PRIORITYLEVEL	= 0,
	AllocationRetentionPriority_PREEMPTIONCAPABILITY	= 1,
	AllocationRetentionPriority_PREEMPTIONVULNERABILITY	= 2,
}AllocationRetentionPriority_tags;

		//! Class Definition
		/*!		ClassName is AllocationRetentionPriority
		*/
class AllocationRetentionPriority : public DiameterBaseInterface
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

		Unsigned32*		mPriorityLevel;

		PreemptionCapability*		mPreemptionCapability;

		PreemptionVulnerability*		mPreemptionVulnerability;





	public:
		AllocationRetentionPriority();

		AllocationRetentionPriority(const AllocationRetentionPriority &objAllocationRetentionPriority) {

		mTagsPresent = objAllocationRetentionPriority.mTagsPresent;

		mMandatoryAvpCheckVal = objAllocationRetentionPriority.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAllocationRetentionPriority.mMandatoryAvpSetVal;

		mTag = objAllocationRetentionPriority.mTag;

		mDecodeFlag = objAllocationRetentionPriority.mDecodeFlag;

		if(objAllocationRetentionPriority.mPriorityLevel != NULL)
		mPriorityLevel = new Unsigned32(*(objAllocationRetentionPriority.mPriorityLevel));

		if(objAllocationRetentionPriority.mPreemptionCapability != NULL)
		mPreemptionCapability = new PreemptionCapability(*(objAllocationRetentionPriority.mPreemptionCapability));

		if(objAllocationRetentionPriority.mPreemptionVulnerability != NULL)
		mPreemptionVulnerability = new PreemptionVulnerability(*(objAllocationRetentionPriority.mPreemptionVulnerability));

		}

		void operator = (const AllocationRetentionPriority &objAllocationRetentionPriority) {

		mTagsPresent = objAllocationRetentionPriority.mTagsPresent;

		mMandatoryAvpCheckVal = objAllocationRetentionPriority.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAllocationRetentionPriority.mMandatoryAvpSetVal;

		mTag = objAllocationRetentionPriority.mTag;

		mDecodeFlag = objAllocationRetentionPriority.mDecodeFlag;

		if(objAllocationRetentionPriority.mPriorityLevel != NULL)
		mPriorityLevel = new Unsigned32(*(objAllocationRetentionPriority.mPriorityLevel));

		if(objAllocationRetentionPriority.mPreemptionCapability != NULL)
		mPreemptionCapability = new PreemptionCapability(*(objAllocationRetentionPriority.mPreemptionCapability));

		if(objAllocationRetentionPriority.mPreemptionVulnerability != NULL)
		mPreemptionVulnerability = new PreemptionVulnerability(*(objAllocationRetentionPriority.mPreemptionVulnerability));

		}

		virtual ~AllocationRetentionPriority();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument PriorityLevel for datatype AllocationRetentionPriority
		*/
		Unsigned32* setPriorityLevel();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PriorityLevel for datatype AllocationRetentionPriority
		*/
		void resetPriorityLevel();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument PriorityLevel for datatype AllocationRetentionPriority
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getPriorityLevel();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument PreemptionCapability for datatype AllocationRetentionPriority
		*/
		PreemptionCapability* setPreemptionCapability();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PreemptionCapability for datatype AllocationRetentionPriority
		*/
		void resetPreemptionCapability();

		//!Function to get values
		/*!		Function to get PreemptionCapability type of argument PreemptionCapability for datatype AllocationRetentionPriority
		Throws exception of which type and Summary of Exception
		*/
		PreemptionCapability* getPreemptionCapability();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument PreemptionVulnerability for datatype AllocationRetentionPriority
		*/
		PreemptionVulnerability* setPreemptionVulnerability();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PreemptionVulnerability for datatype AllocationRetentionPriority
		*/
		void resetPreemptionVulnerability();

		//!Function to get values
		/*!		Function to get PreemptionVulnerability type of argument PreemptionVulnerability for datatype AllocationRetentionPriority
		Throws exception of which type and Summary of Exception
		*/
		PreemptionVulnerability* getPreemptionVulnerability();

		//! Function to Decode
		/*!		Function to Decode datatype AllocationRetentionPriority
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype AllocationRetentionPriority
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype AllocationRetentionPriority
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype AllocationRetentionPriority
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AllocationRetentionPriority
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
