#ifndef SD_USAGEMONITORINGINFORMATION_H
#define SD_USAGEMONITORINGINFORMATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/GrantedServiceUnit.h"
#include "sd/include/UsedServiceUnit.h"
#include "sd/include/UsageMonitoringLevel.h"
#include "sd/include/UsageMonitoringReport.h"
#include "sd/include/UsageMonitoringSupport.h"
using namespace std;

namespace SD{
typedef enum _tags_UsageMonitoringInformation
{
	UsageMonitoringInformation_MONITORINGKEY	= 0,
	UsageMonitoringInformation_GRANTEDSERVICEUNIT	= 1,
	UsageMonitoringInformation_USEDSERVICEUNIT	= 2,
	UsageMonitoringInformation_QUOTACONSUMPTIONTIME	= 3,
	UsageMonitoringInformation_USAGEMONITORINGLEVEL	= 4,
	UsageMonitoringInformation_USAGEMONITORINGREPORT	= 5,
	UsageMonitoringInformation_USAGEMONITORINGSUPPORT	= 6,
}UsageMonitoringInformation_tags;

		//! Class Definition
		/*!		ClassName is UsageMonitoringInformation
		*/
class UsageMonitoringInformation : public DiameterBaseInterface
{
	private:

		bitset<7> mTagsPresent;

		bitset<7> mMandatoryAvpCheckVal;

		bitset<7> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mMonitoringKey;

		Unsigned32*		mQuotaConsumptionTime;

		UsageMonitoringLevel*		mUsageMonitoringLevel;

		UsageMonitoringReport*		mUsageMonitoringReport;

		UsageMonitoringSupport*		mUsageMonitoringSupport;



		list<GrantedServiceUnit*>*	mGrantedServiceUnitGrpList;
		list<GrantedServiceUnit*>::iterator	mGrantedServiceUnitGrpIterator;

		list<UsedServiceUnit*>*	mUsedServiceUnitGrpList;
		list<UsedServiceUnit*>::iterator	mUsedServiceUnitGrpIterator;





	public:
		UsageMonitoringInformation();

		UsageMonitoringInformation(const UsageMonitoringInformation &objUsageMonitoringInformation) {

		mTagsPresent = objUsageMonitoringInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objUsageMonitoringInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUsageMonitoringInformation.mMandatoryAvpSetVal;

		mTag = objUsageMonitoringInformation.mTag;

		mDecodeFlag = objUsageMonitoringInformation.mDecodeFlag;

		if(objUsageMonitoringInformation.mMonitoringKey != NULL)
		mMonitoringKey = new OctetString(*(objUsageMonitoringInformation.mMonitoringKey));

		if(objUsageMonitoringInformation.mGrantedServiceUnitGrpList != NULL)
		 {
		 mGrantedServiceUnitGrpList = new list<GrantedServiceUnit*>;
		 for( auto element : *objUsageMonitoringInformation.mGrantedServiceUnitGrpList)
		 {
				 GrantedServiceUnit *lGrantedServiceUnit =  new GrantedServiceUnit(*element);
				 mGrantedServiceUnitGrpList->push_back(lGrantedServiceUnit);
		 }
		 }
		if(objUsageMonitoringInformation.mUsedServiceUnitGrpList != NULL)
		 {
		 mUsedServiceUnitGrpList = new list<UsedServiceUnit*>;
		 for( auto element : *objUsageMonitoringInformation.mUsedServiceUnitGrpList)
		 {
				 UsedServiceUnit *lUsedServiceUnit =  new UsedServiceUnit(*element);
				 mUsedServiceUnitGrpList->push_back(lUsedServiceUnit);
		 }
		 }
		if(objUsageMonitoringInformation.mQuotaConsumptionTime != NULL)
		mQuotaConsumptionTime = new Unsigned32(*(objUsageMonitoringInformation.mQuotaConsumptionTime));

		if(objUsageMonitoringInformation.mUsageMonitoringLevel != NULL)
		mUsageMonitoringLevel = new UsageMonitoringLevel(*(objUsageMonitoringInformation.mUsageMonitoringLevel));

		if(objUsageMonitoringInformation.mUsageMonitoringReport != NULL)
		mUsageMonitoringReport = new UsageMonitoringReport(*(objUsageMonitoringInformation.mUsageMonitoringReport));

		if(objUsageMonitoringInformation.mUsageMonitoringSupport != NULL)
		mUsageMonitoringSupport = new UsageMonitoringSupport(*(objUsageMonitoringInformation.mUsageMonitoringSupport));

		}

		void operator = (const UsageMonitoringInformation &objUsageMonitoringInformation) {

		mTagsPresent = objUsageMonitoringInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objUsageMonitoringInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUsageMonitoringInformation.mMandatoryAvpSetVal;

		mTag = objUsageMonitoringInformation.mTag;

		mDecodeFlag = objUsageMonitoringInformation.mDecodeFlag;

		if(objUsageMonitoringInformation.mMonitoringKey != NULL)
		mMonitoringKey = new OctetString(*(objUsageMonitoringInformation.mMonitoringKey));

		if(objUsageMonitoringInformation.mGrantedServiceUnitGrpList != NULL)
		 {
		 mGrantedServiceUnitGrpList = new list<GrantedServiceUnit*>;
		 for( auto element : *objUsageMonitoringInformation.mGrantedServiceUnitGrpList)
		 {
				 GrantedServiceUnit *lGrantedServiceUnit =  new GrantedServiceUnit(*element);
				 mGrantedServiceUnitGrpList->push_back(lGrantedServiceUnit);
		 }
		 }
		if(objUsageMonitoringInformation.mUsedServiceUnitGrpList != NULL)
		 {
		 mUsedServiceUnitGrpList = new list<UsedServiceUnit*>;
		 for( auto element : *objUsageMonitoringInformation.mUsedServiceUnitGrpList)
		 {
				 UsedServiceUnit *lUsedServiceUnit =  new UsedServiceUnit(*element);
				 mUsedServiceUnitGrpList->push_back(lUsedServiceUnit);
		 }
		 }
		if(objUsageMonitoringInformation.mQuotaConsumptionTime != NULL)
		mQuotaConsumptionTime = new Unsigned32(*(objUsageMonitoringInformation.mQuotaConsumptionTime));

		if(objUsageMonitoringInformation.mUsageMonitoringLevel != NULL)
		mUsageMonitoringLevel = new UsageMonitoringLevel(*(objUsageMonitoringInformation.mUsageMonitoringLevel));

		if(objUsageMonitoringInformation.mUsageMonitoringReport != NULL)
		mUsageMonitoringReport = new UsageMonitoringReport(*(objUsageMonitoringInformation.mUsageMonitoringReport));

		if(objUsageMonitoringInformation.mUsageMonitoringSupport != NULL)
		mUsageMonitoringSupport = new UsageMonitoringSupport(*(objUsageMonitoringInformation.mUsageMonitoringSupport));

		}

		virtual ~UsageMonitoringInformation();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MonitoringKey for datatype UsageMonitoringInformation
		*/
		OctetString* setMonitoringKey();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MonitoringKey for datatype UsageMonitoringInformation
		*/
		void resetMonitoringKey();

		//!Function to get values
		/*!		Function to get OctetString type of argument MonitoringKey for datatype UsageMonitoringInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMonitoringKey();

		list<GrantedServiceUnit*>* getGrantedServiceUnitGrpList();

		list<GrantedServiceUnit*>* setGrantedServiceUnitGrpList();

		void resetGrantedServiceUnitGrpList();

		list<UsedServiceUnit*>* getUsedServiceUnitGrpList();

		list<UsedServiceUnit*>* setUsedServiceUnitGrpList();

		void resetUsedServiceUnitGrpList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument QuotaConsumptionTime for datatype UsageMonitoringInformation
		*/
		Unsigned32* setQuotaConsumptionTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument QuotaConsumptionTime for datatype UsageMonitoringInformation
		*/
		void resetQuotaConsumptionTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument QuotaConsumptionTime for datatype UsageMonitoringInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getQuotaConsumptionTime();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument UsageMonitoringLevel for datatype UsageMonitoringInformation
		*/
		UsageMonitoringLevel* setUsageMonitoringLevel();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UsageMonitoringLevel for datatype UsageMonitoringInformation
		*/
		void resetUsageMonitoringLevel();

		//!Function to get values
		/*!		Function to get UsageMonitoringLevel type of argument UsageMonitoringLevel for datatype UsageMonitoringInformation
		Throws exception of which type and Summary of Exception
		*/
		UsageMonitoringLevel* getUsageMonitoringLevel();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument UsageMonitoringReport for datatype UsageMonitoringInformation
		*/
		UsageMonitoringReport* setUsageMonitoringReport();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UsageMonitoringReport for datatype UsageMonitoringInformation
		*/
		void resetUsageMonitoringReport();

		//!Function to get values
		/*!		Function to get UsageMonitoringReport type of argument UsageMonitoringReport for datatype UsageMonitoringInformation
		Throws exception of which type and Summary of Exception
		*/
		UsageMonitoringReport* getUsageMonitoringReport();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument UsageMonitoringSupport for datatype UsageMonitoringInformation
		*/
		UsageMonitoringSupport* setUsageMonitoringSupport();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UsageMonitoringSupport for datatype UsageMonitoringInformation
		*/
		void resetUsageMonitoringSupport();

		//!Function to get values
		/*!		Function to get UsageMonitoringSupport type of argument UsageMonitoringSupport for datatype UsageMonitoringInformation
		Throws exception of which type and Summary of Exception
		*/
		UsageMonitoringSupport* getUsageMonitoringSupport();

		//! Function to Decode
		/*!		Function to Decode datatype UsageMonitoringInformation
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype UsageMonitoringInformation
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UsageMonitoringInformation
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UsageMonitoringInformation
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UsageMonitoringInformation
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
