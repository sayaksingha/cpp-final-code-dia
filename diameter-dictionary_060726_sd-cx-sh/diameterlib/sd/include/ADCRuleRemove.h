#ifndef SD_ADCRULEREMOVE_H
#define SD_ADCRULEREMOVE_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SD{
typedef enum _tags_ADCRuleRemove
{
	ADCRuleRemove_ADCRULENAME	= 0,
	ADCRuleRemove_ADCRULEBASENAME	= 1,
}ADCRuleRemove_tags;

		//! Class Definition
		/*!		ClassName is ADCRuleRemove
		*/
class ADCRuleRemove : public DiameterBaseInterface
{
	private:

		bitset<2> mTagsPresent;

		bitset<2> mMandatoryAvpCheckVal;

		bitset<2> mMandatoryAvpSetVal;

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




	public:
		ADCRuleRemove();

		ADCRuleRemove(const ADCRuleRemove &objADCRuleRemove) {

		mTagsPresent = objADCRuleRemove.mTagsPresent;

		mMandatoryAvpCheckVal = objADCRuleRemove.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objADCRuleRemove.mMandatoryAvpSetVal;

		mTag = objADCRuleRemove.mTag;

		mDecodeFlag = objADCRuleRemove.mDecodeFlag;

		}

		void operator = (const ADCRuleRemove &objADCRuleRemove) {

		mTagsPresent = objADCRuleRemove.mTagsPresent;

		mMandatoryAvpCheckVal = objADCRuleRemove.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objADCRuleRemove.mMandatoryAvpSetVal;

		mTag = objADCRuleRemove.mTag;

		mDecodeFlag = objADCRuleRemove.mDecodeFlag;

		}

		virtual ~ADCRuleRemove();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		list<OctetString*>* getADCRuleNameList();

		list<OctetString*>* setADCRuleNameList();

		void resetADCRuleNameList();

		list<OctetString*>* getADCRuleBaseNameList();

		list<OctetString*>* setADCRuleBaseNameList();

		void resetADCRuleBaseNameList();

		//! Function to Decode
		/*!		Function to Decode datatype ADCRuleRemove
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ADCRuleRemove
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ADCRuleRemove
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ADCRuleRemove
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ADCRuleRemove
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
