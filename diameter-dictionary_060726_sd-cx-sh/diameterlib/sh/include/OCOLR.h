#ifndef SH_OCOLR_H
#define SH_OCOLR_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sh/include/OCReportType.h"
using namespace std;

namespace SH{
typedef enum _tags_OCOLR
{
	OCOLR_OCSEQUENCENUMBER	= 0,
	OCOLR_OCREPORTTYPE	= 1,
	OCOLR_OCREDUCTIONPERCENTAGE	= 2,
	OCOLR_OCVALIDITYDURATION	= 3,
}OCOLR_tags;

		//! Class Definition
		/*!		ClassName is OCOLR
		*/
class OCOLR : public DiameterBaseInterface
{
	private:

		bitset<4> mTagsPresent;

		bitset<4> mMandatoryAvpCheckVal;

		bitset<4> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		Unsigned64*		mOCSequenceNumber;

		OCReportType*		mOCReportType;

		Unsigned32*		mOCReductionPercentage;

		Unsigned32*		mOCValidityDuration;






	public:
		OCOLR();

		OCOLR(const OCOLR &objOCOLR) {

		mTagsPresent = objOCOLR.mTagsPresent;

		mMandatoryAvpCheckVal = objOCOLR.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objOCOLR.mMandatoryAvpSetVal;

		mTag = objOCOLR.mTag;

		mDecodeFlag = objOCOLR.mDecodeFlag;

		if(objOCOLR.mOCSequenceNumber != NULL)
		mOCSequenceNumber = new Unsigned64(*(objOCOLR.mOCSequenceNumber));

		if(objOCOLR.mOCReportType != NULL)
		mOCReportType = new OCReportType(*(objOCOLR.mOCReportType));

		if(objOCOLR.mOCReductionPercentage != NULL)
		mOCReductionPercentage = new Unsigned32(*(objOCOLR.mOCReductionPercentage));

		if(objOCOLR.mOCValidityDuration != NULL)
		mOCValidityDuration = new Unsigned32(*(objOCOLR.mOCValidityDuration));

		}

		void operator = (const OCOLR &objOCOLR) {

		mTagsPresent = objOCOLR.mTagsPresent;

		mMandatoryAvpCheckVal = objOCOLR.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objOCOLR.mMandatoryAvpSetVal;

		mTag = objOCOLR.mTag;

		mDecodeFlag = objOCOLR.mDecodeFlag;

		if(objOCOLR.mOCSequenceNumber != NULL)
		mOCSequenceNumber = new Unsigned64(*(objOCOLR.mOCSequenceNumber));

		if(objOCOLR.mOCReportType != NULL)
		mOCReportType = new OCReportType(*(objOCOLR.mOCReportType));

		if(objOCOLR.mOCReductionPercentage != NULL)
		mOCReductionPercentage = new Unsigned32(*(objOCOLR.mOCReductionPercentage));

		if(objOCOLR.mOCValidityDuration != NULL)
		mOCValidityDuration = new Unsigned32(*(objOCOLR.mOCValidityDuration));

		}

		virtual ~OCOLR();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument OCSequenceNumber for datatype OCOLR
		*/
		Unsigned64* setOCSequenceNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OCSequenceNumber for datatype OCOLR
		*/
		void resetOCSequenceNumber();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument OCSequenceNumber for datatype OCOLR
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getOCSequenceNumber();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument OCReportType for datatype OCOLR
		*/
		OCReportType* setOCReportType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OCReportType for datatype OCOLR
		*/
		void resetOCReportType();

		//!Function to get values
		/*!		Function to get OCReportType type of argument OCReportType for datatype OCOLR
		Throws exception of which type and Summary of Exception
		*/
		OCReportType* getOCReportType();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OCReductionPercentage for datatype OCOLR
		*/
		Unsigned32* setOCReductionPercentage();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OCReductionPercentage for datatype OCOLR
		*/
		void resetOCReductionPercentage();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OCReductionPercentage for datatype OCOLR
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOCReductionPercentage();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument OCValidityDuration for datatype OCOLR
		*/
		Unsigned32* setOCValidityDuration();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OCValidityDuration for datatype OCOLR
		*/
		void resetOCValidityDuration();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument OCValidityDuration for datatype OCOLR
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getOCValidityDuration();

		//! Function to Decode
		/*!		Function to Decode datatype OCOLR
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype OCOLR
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype OCOLR
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype OCOLR
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype OCOLR
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
