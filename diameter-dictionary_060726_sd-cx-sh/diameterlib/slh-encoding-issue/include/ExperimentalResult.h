#ifndef SLH_EXPERIMENTALRESULT_H
#define SLH_EXPERIMENTALRESULT_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SLH{
typedef enum _tags_ExperimentalResult
{
	ExperimentalResult_VENDORID	= 0,
	ExperimentalResult_EXPERIMENTALRESULTCODE	= 1,
}ExperimentalResult_tags;

		//! Class Definition
		/*!		ClassName is ExperimentalResult
		*/
class ExperimentalResult : public DiameterBaseInterface
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

		Integer32*		mVendorId;

		Unsigned32*		mExperimentalResultCode;




	public:
		ExperimentalResult();

		ExperimentalResult(const ExperimentalResult &objExperimentalResult) {

		mTagsPresent = objExperimentalResult.mTagsPresent;

		mMandatoryAvpCheckVal = objExperimentalResult.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objExperimentalResult.mMandatoryAvpSetVal;

		mTag = objExperimentalResult.mTag;

		mDecodeFlag = objExperimentalResult.mDecodeFlag;

		if(objExperimentalResult.mVendorId != NULL)
		mVendorId = new Integer32(*(objExperimentalResult.mVendorId));

		if(objExperimentalResult.mExperimentalResultCode != NULL)
		mExperimentalResultCode = new Unsigned32(*(objExperimentalResult.mExperimentalResultCode));

		}

		void operator = (const ExperimentalResult &objExperimentalResult) {

		mTagsPresent = objExperimentalResult.mTagsPresent;

		mMandatoryAvpCheckVal = objExperimentalResult.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objExperimentalResult.mMandatoryAvpSetVal;

		mTag = objExperimentalResult.mTag;

		mDecodeFlag = objExperimentalResult.mDecodeFlag;

		if(objExperimentalResult.mVendorId != NULL)
		mVendorId = new Integer32(*(objExperimentalResult.mVendorId));

		if(objExperimentalResult.mExperimentalResultCode != NULL)
		mExperimentalResultCode = new Unsigned32(*(objExperimentalResult.mExperimentalResultCode));

		}

		virtual ~ExperimentalResult();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Integer32 type of argument VendorId for datatype ExperimentalResult
		*/
		Integer32* setVendorId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument VendorId for datatype ExperimentalResult
		*/
		void resetVendorId();

		//!Function to get values
		/*!		Function to get Integer32 type of argument VendorId for datatype ExperimentalResult
		Throws exception of which type and Summary of Exception
		*/
		Integer32* getVendorId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ExperimentalResultCode for datatype ExperimentalResult
		*/
		Unsigned32* setExperimentalResultCode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExperimentalResultCode for datatype ExperimentalResult
		*/
		void resetExperimentalResultCode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ExperimentalResultCode for datatype ExperimentalResult
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getExperimentalResultCode();

		//! Function to Decode
		/*!		Function to Decode datatype ExperimentalResult
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ExperimentalResult
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ExperimentalResult
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ExperimentalResult
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ExperimentalResult
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
