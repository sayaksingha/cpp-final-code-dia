#ifndef RX_CHARGINGRULEREMOVE_H
#define RX_CHARGINGRULEREMOVE_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace RX{
typedef enum _tags_ChargingRuleRemove
{
	ChargingRuleRemove_CHARGINGRULENAME	= 0,
}ChargingRuleRemove_tags;

		//! Class Definition
		/*!		ClassName is ChargingRuleRemove
		*/
class ChargingRuleRemove : public DiameterBaseInterface
{
	private:

		bitset<1> mTagsPresent;

		bitset<1> mMandatoryAvpCheckVal;

		bitset<1> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mChargingRuleName;



	public:
		ChargingRuleRemove();

		ChargingRuleRemove(const ChargingRuleRemove &objChargingRuleRemove) {

		mTagsPresent = objChargingRuleRemove.mTagsPresent;

		mMandatoryAvpCheckVal = objChargingRuleRemove.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objChargingRuleRemove.mMandatoryAvpSetVal;

		mTag = objChargingRuleRemove.mTag;

		mDecodeFlag = objChargingRuleRemove.mDecodeFlag;

		if(objChargingRuleRemove.mChargingRuleName != NULL)
		mChargingRuleName = new OctetString(*(objChargingRuleRemove.mChargingRuleName));

		}

		void operator = (const ChargingRuleRemove &objChargingRuleRemove) {

		mTagsPresent = objChargingRuleRemove.mTagsPresent;

		mMandatoryAvpCheckVal = objChargingRuleRemove.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objChargingRuleRemove.mMandatoryAvpSetVal;

		mTag = objChargingRuleRemove.mTag;

		mDecodeFlag = objChargingRuleRemove.mDecodeFlag;

		if(objChargingRuleRemove.mChargingRuleName != NULL)
		mChargingRuleName = new OctetString(*(objChargingRuleRemove.mChargingRuleName));

		}

		virtual ~ChargingRuleRemove();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ChargingRuleName for datatype ChargingRuleRemove
		*/
		OctetString* setChargingRuleName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ChargingRuleName for datatype ChargingRuleRemove
		*/
		void resetChargingRuleName();

		//!Function to get values
		/*!		Function to get OctetString type of argument ChargingRuleName for datatype ChargingRuleRemove
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getChargingRuleName();

		//! Function to Decode
		/*!		Function to Decode datatype ChargingRuleRemove
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ChargingRuleRemove
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ChargingRuleRemove
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ChargingRuleRemove
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ChargingRuleRemove
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
