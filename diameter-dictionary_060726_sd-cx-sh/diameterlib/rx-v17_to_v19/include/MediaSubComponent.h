#ifndef RX_MEDIASUBCOMPONENT_H
#define RX_MEDIASUBCOMPONENT_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "rx/include/FlowStatus.h"
#include "rx/include/FlowUsage.h"
using namespace std;

namespace RX{
typedef enum _tags_MediaSubComponent
{
	MediaSubComponent_FLOWNUMBER	= 0,
	MediaSubComponent_FLOWDESCRIPTION	= 1,
	MediaSubComponent_FLOWSTATUS	= 2,
	MediaSubComponent_FLOWUSAGE	= 3,
	MediaSubComponent_MAXREQUESTEDBANDWIDTHUL	= 4,
	MediaSubComponent_MAXREQUESTEDBANDWIDTHDL	= 5,
}MediaSubComponent_tags;

		//! Class Definition
		/*!		ClassName is MediaSubComponent
		*/
class MediaSubComponent : public DiameterBaseInterface
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

		Unsigned32*		mFlowNumber;

		list<OctetString*>* 		mFlowDescriptionList;

		list<OctetString*>::iterator 		mFlowDescriptionIterator;

		FlowStatus*		mFlowStatus;

		FlowUsage*		mFlowUsage;

		Unsigned32*		mMaxRequestedBandwidthUL;

		Unsigned32*		mMaxRequestedBandwidthDL;








	public:
		MediaSubComponent();

		MediaSubComponent(const MediaSubComponent &objMediaSubComponent) {

		mTagsPresent = objMediaSubComponent.mTagsPresent;

		mMandatoryAvpCheckVal = objMediaSubComponent.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMediaSubComponent.mMandatoryAvpSetVal;

		mTag = objMediaSubComponent.mTag;

		mDecodeFlag = objMediaSubComponent.mDecodeFlag;

		if(objMediaSubComponent.mFlowNumber != NULL)
		mFlowNumber = new Unsigned32(*(objMediaSubComponent.mFlowNumber));

		if(objMediaSubComponent.mFlowStatus != NULL)
		mFlowStatus = new FlowStatus(*(objMediaSubComponent.mFlowStatus));

		if(objMediaSubComponent.mFlowUsage != NULL)
		mFlowUsage = new FlowUsage(*(objMediaSubComponent.mFlowUsage));

		if(objMediaSubComponent.mMaxRequestedBandwidthUL != NULL)
		mMaxRequestedBandwidthUL = new Unsigned32(*(objMediaSubComponent.mMaxRequestedBandwidthUL));

		if(objMediaSubComponent.mMaxRequestedBandwidthDL != NULL)
		mMaxRequestedBandwidthDL = new Unsigned32(*(objMediaSubComponent.mMaxRequestedBandwidthDL));

		}

		void operator = (const MediaSubComponent &objMediaSubComponent) {

		mTagsPresent = objMediaSubComponent.mTagsPresent;

		mMandatoryAvpCheckVal = objMediaSubComponent.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMediaSubComponent.mMandatoryAvpSetVal;

		mTag = objMediaSubComponent.mTag;

		mDecodeFlag = objMediaSubComponent.mDecodeFlag;

		if(objMediaSubComponent.mFlowNumber != NULL)
		mFlowNumber = new Unsigned32(*(objMediaSubComponent.mFlowNumber));

		if(objMediaSubComponent.mFlowStatus != NULL)
		mFlowStatus = new FlowStatus(*(objMediaSubComponent.mFlowStatus));

		if(objMediaSubComponent.mFlowUsage != NULL)
		mFlowUsage = new FlowUsage(*(objMediaSubComponent.mFlowUsage));

		if(objMediaSubComponent.mMaxRequestedBandwidthUL != NULL)
		mMaxRequestedBandwidthUL = new Unsigned32(*(objMediaSubComponent.mMaxRequestedBandwidthUL));

		if(objMediaSubComponent.mMaxRequestedBandwidthDL != NULL)
		mMaxRequestedBandwidthDL = new Unsigned32(*(objMediaSubComponent.mMaxRequestedBandwidthDL));

		}

		virtual ~MediaSubComponent();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument FlowNumber for datatype MediaSubComponent
		*/
		Unsigned32* setFlowNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FlowNumber for datatype MediaSubComponent
		*/
		void resetFlowNumber();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument FlowNumber for datatype MediaSubComponent
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getFlowNumber();

		list<OctetString*>* getFlowDescriptionList();

		list<OctetString*>* setFlowDescriptionList();

		void resetFlowDescriptionList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument FlowStatus for datatype MediaSubComponent
		*/
		FlowStatus* setFlowStatus();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FlowStatus for datatype MediaSubComponent
		*/
		void resetFlowStatus();

		//!Function to get values
		/*!		Function to get FlowStatus type of argument FlowStatus for datatype MediaSubComponent
		Throws exception of which type and Summary of Exception
		*/
		FlowStatus* getFlowStatus();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument FlowUsage for datatype MediaSubComponent
		*/
		FlowUsage* setFlowUsage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FlowUsage for datatype MediaSubComponent
		*/
		void resetFlowUsage();

		//!Function to get values
		/*!		Function to get FlowUsage type of argument FlowUsage for datatype MediaSubComponent
		Throws exception of which type and Summary of Exception
		*/
		FlowUsage* getFlowUsage();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MaxRequestedBandwidthUL for datatype MediaSubComponent
		*/
		Unsigned32* setMaxRequestedBandwidthUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MaxRequestedBandwidthUL for datatype MediaSubComponent
		*/
		void resetMaxRequestedBandwidthUL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MaxRequestedBandwidthUL for datatype MediaSubComponent
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMaxRequestedBandwidthUL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MaxRequestedBandwidthDL for datatype MediaSubComponent
		*/
		Unsigned32* setMaxRequestedBandwidthDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MaxRequestedBandwidthDL for datatype MediaSubComponent
		*/
		void resetMaxRequestedBandwidthDL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MaxRequestedBandwidthDL for datatype MediaSubComponent
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMaxRequestedBandwidthDL();

		//! Function to Decode
		/*!		Function to Decode datatype MediaSubComponent
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype MediaSubComponent
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype MediaSubComponent
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype MediaSubComponent
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype MediaSubComponent
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
