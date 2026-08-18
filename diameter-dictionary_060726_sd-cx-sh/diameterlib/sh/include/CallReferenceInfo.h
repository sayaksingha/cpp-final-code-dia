#ifndef SH_CALLREFERENCEINFO_H
#define SH_CALLREFERENCEINFO_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SH{
typedef enum _tags_CallReferenceInfo
{
	CallReferenceInfo_CALLREFERENCENUMBER	= 0,
	CallReferenceInfo_ASNUMBER	= 1,
}CallReferenceInfo_tags;

		//! Class Definition
		/*!		ClassName is CallReferenceInfo
		*/
class CallReferenceInfo : public DiameterBaseInterface
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

		OctetString*		mCallReferenceNumber;

		OctetString*		mASNumber;




	public:
		CallReferenceInfo();

		CallReferenceInfo(const CallReferenceInfo &objCallReferenceInfo) {

		mTagsPresent = objCallReferenceInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objCallReferenceInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCallReferenceInfo.mMandatoryAvpSetVal;

		mTag = objCallReferenceInfo.mTag;

		mDecodeFlag = objCallReferenceInfo.mDecodeFlag;

		if(objCallReferenceInfo.mCallReferenceNumber != NULL)
		mCallReferenceNumber = new OctetString(*(objCallReferenceInfo.mCallReferenceNumber));

		if(objCallReferenceInfo.mASNumber != NULL)
		mASNumber = new OctetString(*(objCallReferenceInfo.mASNumber));

		}

		void operator = (const CallReferenceInfo &objCallReferenceInfo) {

		mTagsPresent = objCallReferenceInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objCallReferenceInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objCallReferenceInfo.mMandatoryAvpSetVal;

		mTag = objCallReferenceInfo.mTag;

		mDecodeFlag = objCallReferenceInfo.mDecodeFlag;

		if(objCallReferenceInfo.mCallReferenceNumber != NULL)
		mCallReferenceNumber = new OctetString(*(objCallReferenceInfo.mCallReferenceNumber));

		if(objCallReferenceInfo.mASNumber != NULL)
		mASNumber = new OctetString(*(objCallReferenceInfo.mASNumber));

		}

		virtual ~CallReferenceInfo();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument CallReferenceNumber for datatype CallReferenceInfo
		*/
		OctetString* setCallReferenceNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CallReferenceNumber for datatype CallReferenceInfo
		*/
		void resetCallReferenceNumber();

		//!Function to get values
		/*!		Function to get OctetString type of argument CallReferenceNumber for datatype CallReferenceInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getCallReferenceNumber();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ASNumber for datatype CallReferenceInfo
		*/
		OctetString* setASNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ASNumber for datatype CallReferenceInfo
		*/
		void resetASNumber();

		//!Function to get values
		/*!		Function to get OctetString type of argument ASNumber for datatype CallReferenceInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getASNumber();

		//! Function to Decode
		/*!		Function to Decode datatype CallReferenceInfo
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype CallReferenceInfo
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype CallReferenceInfo
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype CallReferenceInfo
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype CallReferenceInfo
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
