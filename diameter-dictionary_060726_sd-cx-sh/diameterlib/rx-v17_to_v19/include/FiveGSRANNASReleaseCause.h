#ifndef RX_FIVEGSRANNASRELEASECAUSE_H
#define RX_FIVEGSRANNASRELEASECAUSE_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "rx/include/NGAPCause.h"
using namespace std;

namespace RX{
typedef enum _tags_FiveGSRANNASReleaseCause
{
	FiveGSRANNASReleaseCause_FIVEGMMCAUSE	= 0,
	FiveGSRANNASReleaseCause_FIVEGSMCAUSE	= 1,
	FiveGSRANNASReleaseCause_NGAPCAUSE	= 2,
}FiveGSRANNASReleaseCause_tags;

		//! Class Definition
		/*!		ClassName is FiveGSRANNASReleaseCause
		*/
class FiveGSRANNASReleaseCause : public DiameterBaseInterface
{
	private:

		bitset<3> mTagsPresent;

		bitset<3> mMandatoryAvpCheckVal;

		bitset<3> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		Unsigned32*		mFiveGMMCause;

		Unsigned32*		mFiveGSMCause;




		list<NGAPCause*>*	mNGAPCauseGrpList;
		list<NGAPCause*>::iterator	mNGAPCauseGrpIterator;

	public:
		FiveGSRANNASReleaseCause();

		FiveGSRANNASReleaseCause(const FiveGSRANNASReleaseCause &objFiveGSRANNASReleaseCause) {

		mTagsPresent = objFiveGSRANNASReleaseCause.mTagsPresent;

		mMandatoryAvpCheckVal = objFiveGSRANNASReleaseCause.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFiveGSRANNASReleaseCause.mMandatoryAvpSetVal;

		mTag = objFiveGSRANNASReleaseCause.mTag;

		mDecodeFlag = objFiveGSRANNASReleaseCause.mDecodeFlag;

		if(objFiveGSRANNASReleaseCause.mFiveGMMCause != NULL)
		mFiveGMMCause = new Unsigned32(*(objFiveGSRANNASReleaseCause.mFiveGMMCause));

		if(objFiveGSRANNASReleaseCause.mFiveGSMCause != NULL)
		mFiveGSMCause = new Unsigned32(*(objFiveGSRANNASReleaseCause.mFiveGSMCause));

		if(objFiveGSRANNASReleaseCause.mNGAPCauseGrpList != NULL)
		 {
		 mNGAPCauseGrpList = new list<NGAPCause*>;
		 for( auto element : *objFiveGSRANNASReleaseCause.mNGAPCauseGrpList)
		 {
				 NGAPCause *lNGAPCause =  new NGAPCause(*element);
				 mNGAPCauseGrpList->push_back(lNGAPCause);
		 }
		 }
		}

		void operator = (const FiveGSRANNASReleaseCause &objFiveGSRANNASReleaseCause) {

		mTagsPresent = objFiveGSRANNASReleaseCause.mTagsPresent;

		mMandatoryAvpCheckVal = objFiveGSRANNASReleaseCause.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFiveGSRANNASReleaseCause.mMandatoryAvpSetVal;

		mTag = objFiveGSRANNASReleaseCause.mTag;

		mDecodeFlag = objFiveGSRANNASReleaseCause.mDecodeFlag;

		if(objFiveGSRANNASReleaseCause.mFiveGMMCause != NULL)
		mFiveGMMCause = new Unsigned32(*(objFiveGSRANNASReleaseCause.mFiveGMMCause));

		if(objFiveGSRANNASReleaseCause.mFiveGSMCause != NULL)
		mFiveGSMCause = new Unsigned32(*(objFiveGSRANNASReleaseCause.mFiveGSMCause));

		if(objFiveGSRANNASReleaseCause.mNGAPCauseGrpList != NULL)
		 {
		 mNGAPCauseGrpList = new list<NGAPCause*>;
		 for( auto element : *objFiveGSRANNASReleaseCause.mNGAPCauseGrpList)
		 {
				 NGAPCause *lNGAPCause =  new NGAPCause(*element);
				 mNGAPCauseGrpList->push_back(lNGAPCause);
		 }
		 }
		}

		virtual ~FiveGSRANNASReleaseCause();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument FiveGMMCause for datatype FiveGSRANNASReleaseCause
		*/
		Unsigned32* setFiveGMMCause();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FiveGMMCause for datatype FiveGSRANNASReleaseCause
		*/
		void resetFiveGMMCause();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument FiveGMMCause for datatype FiveGSRANNASReleaseCause
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getFiveGMMCause();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument FiveGSMCause for datatype FiveGSRANNASReleaseCause
		*/
		Unsigned32* setFiveGSMCause();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FiveGSMCause for datatype FiveGSRANNASReleaseCause
		*/
		void resetFiveGSMCause();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument FiveGSMCause for datatype FiveGSRANNASReleaseCause
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getFiveGSMCause();

		list<NGAPCause*>* getNGAPCauseGrpList();

		list<NGAPCause*>* setNGAPCauseGrpList();

		void resetNGAPCauseGrpList();

		//! Function to Decode
		/*!		Function to Decode datatype FiveGSRANNASReleaseCause
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype FiveGSRANNASReleaseCause
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype FiveGSRANNASReleaseCause
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype FiveGSRANNASReleaseCause
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype FiveGSRANNASReleaseCause
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
