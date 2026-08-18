#ifndef CX_DEREGISTRATIONREASON_H
#define CX_DEREGISTRATIONREASON_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/ReasonCode.h"
using namespace std;

namespace CX{
typedef enum _tags_DeregistrationReason
{
	DeregistrationReason_REASONCODE	= 0,
	DeregistrationReason_REASONINFO	= 1,
}DeregistrationReason_tags;

		//! Class Definition
		/*!		ClassName is DeregistrationReason
		*/
class DeregistrationReason : public DiameterBaseInterface
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

		ReasonCode*		mReasonCode;

		OctetString*		mReasonInfo;




	public:
		DeregistrationReason();

		DeregistrationReason(const DeregistrationReason &objDeregistrationReason) {

		mTagsPresent = objDeregistrationReason.mTagsPresent;

		mMandatoryAvpCheckVal = objDeregistrationReason.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objDeregistrationReason.mMandatoryAvpSetVal;

		mTag = objDeregistrationReason.mTag;

		mDecodeFlag = objDeregistrationReason.mDecodeFlag;

		if(objDeregistrationReason.mReasonCode != NULL)
		mReasonCode = new ReasonCode(*(objDeregistrationReason.mReasonCode));

		if(objDeregistrationReason.mReasonInfo != NULL)
		mReasonInfo = new OctetString(*(objDeregistrationReason.mReasonInfo));

		}

		void operator = (const DeregistrationReason &objDeregistrationReason) {

		mTagsPresent = objDeregistrationReason.mTagsPresent;

		mMandatoryAvpCheckVal = objDeregistrationReason.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objDeregistrationReason.mMandatoryAvpSetVal;

		mTag = objDeregistrationReason.mTag;

		mDecodeFlag = objDeregistrationReason.mDecodeFlag;

		if(objDeregistrationReason.mReasonCode != NULL)
		mReasonCode = new ReasonCode(*(objDeregistrationReason.mReasonCode));

		if(objDeregistrationReason.mReasonInfo != NULL)
		mReasonInfo = new OctetString(*(objDeregistrationReason.mReasonInfo));

		}

		virtual ~DeregistrationReason();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ReasonCode for datatype DeregistrationReason
		*/
		ReasonCode* setReasonCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ReasonCode for datatype DeregistrationReason
		*/
		void resetReasonCode();

		//!Function to get values
		/*!		Function to get ReasonCode type of argument ReasonCode for datatype DeregistrationReason
		Throws exception of which type and Summary of Exception
		*/
		ReasonCode* getReasonCode();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ReasonInfo for datatype DeregistrationReason
		*/
		OctetString* setReasonInfo();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ReasonInfo for datatype DeregistrationReason
		*/
		void resetReasonInfo();

		//!Function to get values
		/*!		Function to get OctetString type of argument ReasonInfo for datatype DeregistrationReason
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getReasonInfo();

		//! Function to Decode
		/*!		Function to Decode datatype DeregistrationReason
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype DeregistrationReason
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype DeregistrationReason
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype DeregistrationReason
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype DeregistrationReason
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
