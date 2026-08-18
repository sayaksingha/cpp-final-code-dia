#ifndef SD_ADCRULEREPORT_H
#define SD_ADCRULEREPORT_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/PCCRuleStatus.h"
#include "sd/include/RuleFailureCode.h"
#include "sd/include/FinalUnitIndication.h"
using namespace std;

namespace SD{
typedef enum _tags_ADCRuleReport
{
	ADCRuleReport_ADCRULENAME	= 0,
	ADCRuleReport_ADCRULEBASENAME	= 1,
	ADCRuleReport_PCCRULESTATUS	= 2,
	ADCRuleReport_RULEFAILURECODE	= 3,
	ADCRuleReport_FINALUNITINDICATION	= 4,
}ADCRuleReport_tags;

		//! Class Definition
		/*!		ClassName is ADCRuleReport
		*/
class ADCRuleReport : public DiameterBaseInterface
{
	private:

		bitset<5> mTagsPresent;

		bitset<5> mMandatoryAvpCheckVal;

		bitset<5> mMandatoryAvpSetVal;

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

		PCCRuleStatus*		mPCCRuleStatus;

		RuleFailureCode*		mRuleFailureCode;






		FinalUnitIndication*	mFinalUnitIndicationGrp;

	public:
		ADCRuleReport();

		ADCRuleReport(const ADCRuleReport &objADCRuleReport) {

		mTagsPresent = objADCRuleReport.mTagsPresent;

		mMandatoryAvpCheckVal = objADCRuleReport.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objADCRuleReport.mMandatoryAvpSetVal;

		mTag = objADCRuleReport.mTag;

		mDecodeFlag = objADCRuleReport.mDecodeFlag;

		if(objADCRuleReport.mPCCRuleStatus != NULL)
		mPCCRuleStatus = new PCCRuleStatus(*(objADCRuleReport.mPCCRuleStatus));

		if(objADCRuleReport.mRuleFailureCode != NULL)
		mRuleFailureCode = new RuleFailureCode(*(objADCRuleReport.mRuleFailureCode));

		if(objADCRuleReport.mFinalUnitIndicationGrp != NULL)
		 {
				 mFinalUnitIndicationGrp =  new FinalUnitIndication(*objADCRuleReport.mFinalUnitIndicationGrp);
		 }
		}

		void operator = (const ADCRuleReport &objADCRuleReport) {

		mTagsPresent = objADCRuleReport.mTagsPresent;

		mMandatoryAvpCheckVal = objADCRuleReport.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objADCRuleReport.mMandatoryAvpSetVal;

		mTag = objADCRuleReport.mTag;

		mDecodeFlag = objADCRuleReport.mDecodeFlag;

		if(objADCRuleReport.mPCCRuleStatus != NULL)
		mPCCRuleStatus = new PCCRuleStatus(*(objADCRuleReport.mPCCRuleStatus));

		if(objADCRuleReport.mRuleFailureCode != NULL)
		mRuleFailureCode = new RuleFailureCode(*(objADCRuleReport.mRuleFailureCode));

		if(objADCRuleReport.mFinalUnitIndicationGrp != NULL)
		 {
				 mFinalUnitIndicationGrp =  new FinalUnitIndication(*objADCRuleReport.mFinalUnitIndicationGrp);
		 }
		}

		virtual ~ADCRuleReport();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		list<OctetString*>* getADCRuleNameList();

		list<OctetString*>* setADCRuleNameList();

		void resetADCRuleNameList();

		list<OctetString*>* getADCRuleBaseNameList();

		list<OctetString*>* setADCRuleBaseNameList();

		void resetADCRuleBaseNameList();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument PCCRuleStatus for datatype ADCRuleReport
		*/
		PCCRuleStatus* setPCCRuleStatus();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PCCRuleStatus for datatype ADCRuleReport
		*/
		void resetPCCRuleStatus();

		//!Function to get values
		/*!		Function to get PCCRuleStatus type of argument PCCRuleStatus for datatype ADCRuleReport
		Throws exception of which type and Summary of Exception
		*/
		PCCRuleStatus* getPCCRuleStatus();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RuleFailureCode for datatype ADCRuleReport
		*/
		RuleFailureCode* setRuleFailureCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RuleFailureCode for datatype ADCRuleReport
		*/
		void resetRuleFailureCode();

		//!Function to get values
		/*!		Function to get RuleFailureCode type of argument RuleFailureCode for datatype ADCRuleReport
		Throws exception of which type and Summary of Exception
		*/
		RuleFailureCode* getRuleFailureCode();

		FinalUnitIndication* getFinalUnitIndication();

		FinalUnitIndication* setFinalUnitIndication();

		void resetFinalUnitIndication();

		//! Function to Decode
		/*!		Function to Decode datatype ADCRuleReport
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ADCRuleReport
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ADCRuleReport
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ADCRuleReport
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ADCRuleReport
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
