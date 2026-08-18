#ifndef SD_FLOWINFORMATION_H
#define SD_FLOWINFORMATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/PacketFilterUsage.h"
#include "sd/include/FlowDirection.h"
using namespace std;

namespace SD{
typedef enum _tags_FlowInformation
{
	FlowInformation_FLOWDESCRIPTION	= 0,
	FlowInformation_PACKETFILTERIDENTIFIER	= 1,
	FlowInformation_PACKETFILTERUSAGE	= 2,
	FlowInformation_TOSTRAFFICCLASS	= 3,
	FlowInformation_SECURITYPARAMETERINDEX	= 4,
	FlowInformation_FLOWLABEL	= 5,
	FlowInformation_FLOWDIRECTION	= 6,
	FlowInformation_ROUTINGRULEIDENTIFIER	= 7,
}FlowInformation_tags;

		//! Class Definition
		/*!		ClassName is FlowInformation
		*/
class FlowInformation : public DiameterBaseInterface
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

		OctetString*		mFlowDescription;

		OctetString*		mPacketFilterIdentifier;

		PacketFilterUsage*		mPacketFilterUsage;

		OctetString*		mToSTrafficClass;

		OctetString*		mSecurityParameterIndex;

		OctetString*		mFlowLabel;

		FlowDirection*		mFlowDirection;

		OctetString*		mRoutingRuleIdentifier;










	public:
		FlowInformation();

		FlowInformation(const FlowInformation &objFlowInformation) {

		mTagsPresent = objFlowInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objFlowInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFlowInformation.mMandatoryAvpSetVal;

		mTag = objFlowInformation.mTag;

		mDecodeFlag = objFlowInformation.mDecodeFlag;

		if(objFlowInformation.mFlowDescription != NULL)
		mFlowDescription = new OctetString(*(objFlowInformation.mFlowDescription));

		if(objFlowInformation.mPacketFilterIdentifier != NULL)
		mPacketFilterIdentifier = new OctetString(*(objFlowInformation.mPacketFilterIdentifier));

		if(objFlowInformation.mPacketFilterUsage != NULL)
		mPacketFilterUsage = new PacketFilterUsage(*(objFlowInformation.mPacketFilterUsage));

		if(objFlowInformation.mToSTrafficClass != NULL)
		mToSTrafficClass = new OctetString(*(objFlowInformation.mToSTrafficClass));

		if(objFlowInformation.mSecurityParameterIndex != NULL)
		mSecurityParameterIndex = new OctetString(*(objFlowInformation.mSecurityParameterIndex));

		if(objFlowInformation.mFlowLabel != NULL)
		mFlowLabel = new OctetString(*(objFlowInformation.mFlowLabel));

		if(objFlowInformation.mFlowDirection != NULL)
		mFlowDirection = new FlowDirection(*(objFlowInformation.mFlowDirection));

		if(objFlowInformation.mRoutingRuleIdentifier != NULL)
		mRoutingRuleIdentifier = new OctetString(*(objFlowInformation.mRoutingRuleIdentifier));

		}

		void operator = (const FlowInformation &objFlowInformation) {

		mTagsPresent = objFlowInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objFlowInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFlowInformation.mMandatoryAvpSetVal;

		mTag = objFlowInformation.mTag;

		mDecodeFlag = objFlowInformation.mDecodeFlag;

		if(objFlowInformation.mFlowDescription != NULL)
		mFlowDescription = new OctetString(*(objFlowInformation.mFlowDescription));

		if(objFlowInformation.mPacketFilterIdentifier != NULL)
		mPacketFilterIdentifier = new OctetString(*(objFlowInformation.mPacketFilterIdentifier));

		if(objFlowInformation.mPacketFilterUsage != NULL)
		mPacketFilterUsage = new PacketFilterUsage(*(objFlowInformation.mPacketFilterUsage));

		if(objFlowInformation.mToSTrafficClass != NULL)
		mToSTrafficClass = new OctetString(*(objFlowInformation.mToSTrafficClass));

		if(objFlowInformation.mSecurityParameterIndex != NULL)
		mSecurityParameterIndex = new OctetString(*(objFlowInformation.mSecurityParameterIndex));

		if(objFlowInformation.mFlowLabel != NULL)
		mFlowLabel = new OctetString(*(objFlowInformation.mFlowLabel));

		if(objFlowInformation.mFlowDirection != NULL)
		mFlowDirection = new FlowDirection(*(objFlowInformation.mFlowDirection));

		if(objFlowInformation.mRoutingRuleIdentifier != NULL)
		mRoutingRuleIdentifier = new OctetString(*(objFlowInformation.mRoutingRuleIdentifier));

		}

		virtual ~FlowInformation();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FlowDescription for datatype FlowInformation
		*/
		OctetString* setFlowDescription();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FlowDescription for datatype FlowInformation
		*/
		void resetFlowDescription();

		//!Function to get values
		/*!		Function to get OctetString type of argument FlowDescription for datatype FlowInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFlowDescription();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PacketFilterIdentifier for datatype FlowInformation
		*/
		OctetString* setPacketFilterIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PacketFilterIdentifier for datatype FlowInformation
		*/
		void resetPacketFilterIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument PacketFilterIdentifier for datatype FlowInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPacketFilterIdentifier();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument PacketFilterUsage for datatype FlowInformation
		*/
		PacketFilterUsage* setPacketFilterUsage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PacketFilterUsage for datatype FlowInformation
		*/
		void resetPacketFilterUsage();

		//!Function to get values
		/*!		Function to get PacketFilterUsage type of argument PacketFilterUsage for datatype FlowInformation
		Throws exception of which type and Summary of Exception
		*/
		PacketFilterUsage* getPacketFilterUsage();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ToSTrafficClass for datatype FlowInformation
		*/
		OctetString* setToSTrafficClass();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ToSTrafficClass for datatype FlowInformation
		*/
		void resetToSTrafficClass();

		//!Function to get values
		/*!		Function to get OctetString type of argument ToSTrafficClass for datatype FlowInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getToSTrafficClass();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SecurityParameterIndex for datatype FlowInformation
		*/
		OctetString* setSecurityParameterIndex();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SecurityParameterIndex for datatype FlowInformation
		*/
		void resetSecurityParameterIndex();

		//!Function to get values
		/*!		Function to get OctetString type of argument SecurityParameterIndex for datatype FlowInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSecurityParameterIndex();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FlowLabel for datatype FlowInformation
		*/
		OctetString* setFlowLabel();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FlowLabel for datatype FlowInformation
		*/
		void resetFlowLabel();

		//!Function to get values
		/*!		Function to get OctetString type of argument FlowLabel for datatype FlowInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFlowLabel();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument FlowDirection for datatype FlowInformation
		*/
		FlowDirection* setFlowDirection();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FlowDirection for datatype FlowInformation
		*/
		void resetFlowDirection();

		//!Function to get values
		/*!		Function to get FlowDirection type of argument FlowDirection for datatype FlowInformation
		Throws exception of which type and Summary of Exception
		*/
		FlowDirection* getFlowDirection();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument RoutingRuleIdentifier for datatype FlowInformation
		*/
		OctetString* setRoutingRuleIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RoutingRuleIdentifier for datatype FlowInformation
		*/
		void resetRoutingRuleIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument RoutingRuleIdentifier for datatype FlowInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getRoutingRuleIdentifier();

		//! Function to Decode
		/*!		Function to Decode datatype FlowInformation
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype FlowInformation
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype FlowInformation
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype FlowInformation
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype FlowInformation
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
