#ifndef SLH_FAILEDAVP_H
#define SLH_FAILEDAVP_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SLH{
typedef enum _tags_FailedAVP
{
	FailedAVP_ERRORMESSAGE	= 0,
}FailedAVP_tags;

		//! Class Definition
		/*!		ClassName is FailedAVP
		*/
class FailedAVP : public DiameterBaseInterface
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

		OctetString*		mErrorMessage;



	public:
		FailedAVP();

		FailedAVP(const FailedAVP &objFailedAVP) {

		mTagsPresent = objFailedAVP.mTagsPresent;

		mMandatoryAvpCheckVal = objFailedAVP.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFailedAVP.mMandatoryAvpSetVal;

		mTag = objFailedAVP.mTag;

		mDecodeFlag = objFailedAVP.mDecodeFlag;

		if(objFailedAVP.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objFailedAVP.mErrorMessage));

		}

		void operator = (const FailedAVP &objFailedAVP) {

		mTagsPresent = objFailedAVP.mTagsPresent;

		mMandatoryAvpCheckVal = objFailedAVP.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFailedAVP.mMandatoryAvpSetVal;

		mTag = objFailedAVP.mTag;

		mDecodeFlag = objFailedAVP.mDecodeFlag;

		if(objFailedAVP.mErrorMessage != NULL)
		mErrorMessage = new OctetString(*(objFailedAVP.mErrorMessage));

		}

		virtual ~FailedAVP();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ErrorMessage for datatype FailedAVP
		*/
		OctetString* setErrorMessage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ErrorMessage for datatype FailedAVP
		*/
		void resetErrorMessage();

		//!Function to get values
		/*!		Function to get OctetString type of argument ErrorMessage for datatype FailedAVP
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getErrorMessage();

		//! Function to Decode
		/*!		Function to Decode datatype FailedAVP
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype FailedAVP
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype FailedAVP
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype FailedAVP
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype FailedAVP
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
