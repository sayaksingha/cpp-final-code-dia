#ifndef SD_ADCRULEINSTALL_H
#define SD_ADCRULEINSTALL_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/ADCRuleDefinition.h"
using namespace std;

namespace SD{
typedef enum _tags_ADCRuleInstall
{
	ADCRuleInstall_ADCRULEDEFINITION	= 0,
	ADCRuleInstall_ADCRULENAME	= 1,
	ADCRuleInstall_ADCRULEBASENAME	= 2,
	ADCRuleInstall_MONITORINGFLAGS	= 3,
	ADCRuleInstall_RULEACTIVATIONTIME	= 4,
	ADCRuleInstall_RULEDEACTIVATIONTIME	= 5,
}ADCRuleInstall_tags;

		//! Class Definition
		/*!		ClassName is ADCRuleInstall
		*/
class ADCRuleInstall : public DiameterBaseInterface
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

		list<OctetString*>* 		mADCRuleNameList;

		list<OctetString*>::iterator 		mADCRuleNameIterator;

		list<OctetString*>* 		mADCRuleBaseNameList;

		list<OctetString*>::iterator 		mADCRuleBaseNameIterator;

		Unsigned32*		mMonitoringFlags;

		Time*		mRuleActivationTime;

		Time*		mRuleDeactivationTime;


		list<ADCRuleDefinition*>*	mADCRuleDefinitionGrpList;
		list<ADCRuleDefinition*>::iterator	mADCRuleDefinitionGrpIterator;






	public:
		ADCRuleInstall();

		ADCRuleInstall(const ADCRuleInstall &objADCRuleInstall) {

		mTagsPresent = objADCRuleInstall.mTagsPresent;

		mMandatoryAvpCheckVal = objADCRuleInstall.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objADCRuleInstall.mMandatoryAvpSetVal;

		mTag = objADCRuleInstall.mTag;

		mDecodeFlag = objADCRuleInstall.mDecodeFlag;

		if(objADCRuleInstall.mADCRuleDefinitionGrpList != NULL)
		 {
		 mADCRuleDefinitionGrpList = new list<ADCRuleDefinition*>;
		 for( auto element : *objADCRuleInstall.mADCRuleDefinitionGrpList)
		 {
				 ADCRuleDefinition *lADCRuleDefinition =  new ADCRuleDefinition(*element);
				 mADCRuleDefinitionGrpList->push_back(lADCRuleDefinition);
		 }
		 }
		if(objADCRuleInstall.mMonitoringFlags != NULL)
		mMonitoringFlags = new Unsigned32(*(objADCRuleInstall.mMonitoringFlags));

		if(objADCRuleInstall.mRuleActivationTime != NULL)
		mRuleActivationTime = new Time(*(objADCRuleInstall.mRuleActivationTime));

		if(objADCRuleInstall.mRuleDeactivationTime != NULL)
		mRuleDeactivationTime = new Time(*(objADCRuleInstall.mRuleDeactivationTime));

		}

		void operator = (const ADCRuleInstall &objADCRuleInstall) {

		mTagsPresent = objADCRuleInstall.mTagsPresent;

		mMandatoryAvpCheckVal = objADCRuleInstall.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objADCRuleInstall.mMandatoryAvpSetVal;

		mTag = objADCRuleInstall.mTag;

		mDecodeFlag = objADCRuleInstall.mDecodeFlag;

		if(objADCRuleInstall.mADCRuleDefinitionGrpList != NULL)
		 {
		 mADCRuleDefinitionGrpList = new list<ADCRuleDefinition*>;
		 for( auto element : *objADCRuleInstall.mADCRuleDefinitionGrpList)
		 {
				 ADCRuleDefinition *lADCRuleDefinition =  new ADCRuleDefinition(*element);
				 mADCRuleDefinitionGrpList->push_back(lADCRuleDefinition);
		 }
		 }
		if(objADCRuleInstall.mMonitoringFlags != NULL)
		mMonitoringFlags = new Unsigned32(*(objADCRuleInstall.mMonitoringFlags));

		if(objADCRuleInstall.mRuleActivationTime != NULL)
		mRuleActivationTime = new Time(*(objADCRuleInstall.mRuleActivationTime));

		if(objADCRuleInstall.mRuleDeactivationTime != NULL)
		mRuleDeactivationTime = new Time(*(objADCRuleInstall.mRuleDeactivationTime));

		}

		virtual ~ADCRuleInstall();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		list<ADCRuleDefinition*>* getADCRuleDefinitionGrpList();

		list<ADCRuleDefinition*>* setADCRuleDefinitionGrpList();

		void resetADCRuleDefinitionGrpList();

		list<OctetString*>* getADCRuleNameList();

		list<OctetString*>* setADCRuleNameList();

		void resetADCRuleNameList();

		list<OctetString*>* getADCRuleBaseNameList();

		list<OctetString*>* setADCRuleBaseNameList();

		void resetADCRuleBaseNameList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MonitoringFlags for datatype ADCRuleInstall
		*/
		Unsigned32* setMonitoringFlags();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MonitoringFlags for datatype ADCRuleInstall
		*/
		void resetMonitoringFlags();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MonitoringFlags for datatype ADCRuleInstall
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMonitoringFlags();

		//!Function to set values
		/*!		Function to set the recent Time type of argument RuleActivationTime for datatype ADCRuleInstall
		*/
		Time* setRuleActivationTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RuleActivationTime for datatype ADCRuleInstall
		*/
		void resetRuleActivationTime();

		//!Function to get values
		/*!		Function to get Time type of argument RuleActivationTime for datatype ADCRuleInstall
		Throws exception of which type and Summary of Exception
		*/
		Time* getRuleActivationTime();

		//!Function to set values
		/*!		Function to set the recent Time type of argument RuleDeactivationTime for datatype ADCRuleInstall
		*/
		Time* setRuleDeactivationTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RuleDeactivationTime for datatype ADCRuleInstall
		*/
		void resetRuleDeactivationTime();

		//!Function to get values
		/*!		Function to get Time type of argument RuleDeactivationTime for datatype ADCRuleInstall
		Throws exception of which type and Summary of Exception
		*/
		Time* getRuleDeactivationTime();

		//! Function to Decode
		/*!		Function to Decode datatype ADCRuleInstall
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ADCRuleInstall
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ADCRuleInstall
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ADCRuleInstall
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ADCRuleInstall
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
