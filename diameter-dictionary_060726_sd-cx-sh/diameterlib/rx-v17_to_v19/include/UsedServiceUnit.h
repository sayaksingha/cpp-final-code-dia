#ifndef RX_USEDSERVICEUNIT_H
#define RX_USEDSERVICEUNIT_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "rx/include/TariffTimeChange.h"
#include "rx/include/CCMoney.h"
using namespace std;

namespace RX{
typedef enum _tags_UsedServiceUnit
{
	UsedServiceUnit_TARIFFTIMECHANGE	= 0,
	UsedServiceUnit_CCTIME	= 1,
	UsedServiceUnit_CCMONEY	= 2,
	UsedServiceUnit_CCTOTALOCTETS	= 3,
	UsedServiceUnit_CCINPUTOCTETS	= 4,
	UsedServiceUnit_CCOUTPUTOCTETS	= 5,
	UsedServiceUnit_CCSERVICESPECIFICUNITS	= 6,
}UsedServiceUnit_tags;

		//! Class Definition
		/*!		ClassName is UsedServiceUnit
		*/
class UsedServiceUnit : public DiameterBaseInterface
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

		TariffTimeChange*		mTariffTimeChange;

		Unsigned32*		mCCTime;

		Unsigned64*		mCCTotalOctets;

		Unsigned64*		mCCInputOctets;

		Unsigned64*		mCCOutputOctets;

		Unsigned64*		mCCServiceSpecificUnits;




		list<CCMoney*>*	mCCMoneyGrpList;
		list<CCMoney*>::iterator	mCCMoneyGrpIterator;





	public:
		UsedServiceUnit();

		UsedServiceUnit(const UsedServiceUnit &objUsedServiceUnit) {

		mTagsPresent = objUsedServiceUnit.mTagsPresent;

		mMandatoryAvpCheckVal = objUsedServiceUnit.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUsedServiceUnit.mMandatoryAvpSetVal;

		mTag = objUsedServiceUnit.mTag;

		mDecodeFlag = objUsedServiceUnit.mDecodeFlag;

		if(objUsedServiceUnit.mTariffTimeChange != NULL)
		mTariffTimeChange = new TariffTimeChange(*(objUsedServiceUnit.mTariffTimeChange));

		if(objUsedServiceUnit.mCCTime != NULL)
		mCCTime = new Unsigned32(*(objUsedServiceUnit.mCCTime));

		if(objUsedServiceUnit.mCCMoneyGrpList != NULL)
		 {
		 mCCMoneyGrpList = new list<CCMoney*>;
		 for( auto element : *objUsedServiceUnit.mCCMoneyGrpList)
		 {
				 CCMoney *lCCMoney =  new CCMoney(*element);
				 mCCMoneyGrpList->push_back(lCCMoney);
		 }
		 }
		if(objUsedServiceUnit.mCCTotalOctets != NULL)
		mCCTotalOctets = new Unsigned64(*(objUsedServiceUnit.mCCTotalOctets));

		if(objUsedServiceUnit.mCCInputOctets != NULL)
		mCCInputOctets = new Unsigned64(*(objUsedServiceUnit.mCCInputOctets));

		if(objUsedServiceUnit.mCCOutputOctets != NULL)
		mCCOutputOctets = new Unsigned64(*(objUsedServiceUnit.mCCOutputOctets));

		if(objUsedServiceUnit.mCCServiceSpecificUnits != NULL)
		mCCServiceSpecificUnits = new Unsigned64(*(objUsedServiceUnit.mCCServiceSpecificUnits));

		}

		void operator = (const UsedServiceUnit &objUsedServiceUnit) {

		mTagsPresent = objUsedServiceUnit.mTagsPresent;

		mMandatoryAvpCheckVal = objUsedServiceUnit.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUsedServiceUnit.mMandatoryAvpSetVal;

		mTag = objUsedServiceUnit.mTag;

		mDecodeFlag = objUsedServiceUnit.mDecodeFlag;

		if(objUsedServiceUnit.mTariffTimeChange != NULL)
		mTariffTimeChange = new TariffTimeChange(*(objUsedServiceUnit.mTariffTimeChange));

		if(objUsedServiceUnit.mCCTime != NULL)
		mCCTime = new Unsigned32(*(objUsedServiceUnit.mCCTime));

		if(objUsedServiceUnit.mCCMoneyGrpList != NULL)
		 {
		 mCCMoneyGrpList = new list<CCMoney*>;
		 for( auto element : *objUsedServiceUnit.mCCMoneyGrpList)
		 {
				 CCMoney *lCCMoney =  new CCMoney(*element);
				 mCCMoneyGrpList->push_back(lCCMoney);
		 }
		 }
		if(objUsedServiceUnit.mCCTotalOctets != NULL)
		mCCTotalOctets = new Unsigned64(*(objUsedServiceUnit.mCCTotalOctets));

		if(objUsedServiceUnit.mCCInputOctets != NULL)
		mCCInputOctets = new Unsigned64(*(objUsedServiceUnit.mCCInputOctets));

		if(objUsedServiceUnit.mCCOutputOctets != NULL)
		mCCOutputOctets = new Unsigned64(*(objUsedServiceUnit.mCCOutputOctets));

		if(objUsedServiceUnit.mCCServiceSpecificUnits != NULL)
		mCCServiceSpecificUnits = new Unsigned64(*(objUsedServiceUnit.mCCServiceSpecificUnits));

		}

		virtual ~UsedServiceUnit();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument TariffTimeChange for datatype UsedServiceUnit
		*/
		TariffTimeChange* setTariffTimeChange();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TariffTimeChange for datatype UsedServiceUnit
		*/
		void resetTariffTimeChange();

		//!Function to get values
		/*!		Function to get TariffTimeChange type of argument TariffTimeChange for datatype UsedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		TariffTimeChange* getTariffTimeChange();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument CCTime for datatype UsedServiceUnit
		*/
		Unsigned32* setCCTime();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCTime for datatype UsedServiceUnit
		*/
		void resetCCTime();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument CCTime for datatype UsedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getCCTime();

		list<CCMoney*>* getCCMoneyGrpList();

		list<CCMoney*>* setCCMoneyGrpList();

		void resetCCMoneyGrpList();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument CCTotalOctets for datatype UsedServiceUnit
		*/
		Unsigned64* setCCTotalOctets();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCTotalOctets for datatype UsedServiceUnit
		*/
		void resetCCTotalOctets();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument CCTotalOctets for datatype UsedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getCCTotalOctets();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument CCInputOctets for datatype UsedServiceUnit
		*/
		Unsigned64* setCCInputOctets();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCInputOctets for datatype UsedServiceUnit
		*/
		void resetCCInputOctets();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument CCInputOctets for datatype UsedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getCCInputOctets();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument CCOutputOctets for datatype UsedServiceUnit
		*/
		Unsigned64* setCCOutputOctets();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCOutputOctets for datatype UsedServiceUnit
		*/
		void resetCCOutputOctets();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument CCOutputOctets for datatype UsedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getCCOutputOctets();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument CCServiceSpecificUnits for datatype UsedServiceUnit
		*/
		Unsigned64* setCCServiceSpecificUnits();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CCServiceSpecificUnits for datatype UsedServiceUnit
		*/
		void resetCCServiceSpecificUnits();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument CCServiceSpecificUnits for datatype UsedServiceUnit
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getCCServiceSpecificUnits();

		//! Function to Decode
		/*!		Function to Decode datatype UsedServiceUnit
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype UsedServiceUnit
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UsedServiceUnit
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UsedServiceUnit
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UsedServiceUnit
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
