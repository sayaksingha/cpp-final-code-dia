#ifndef SD_OCSUPPORTEDFEATURES_H
#define SD_OCSUPPORTEDFEATURES_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SD{
typedef enum _tags_OCSupportedFeatures
{
	OCSupportedFeatures_OCFEATUREVECTOR	= 0,
}OCSupportedFeatures_tags;

		//! Class Definition
		/*!		ClassName is OCSupportedFeatures
		*/
class OCSupportedFeatures : public DiameterBaseInterface
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

		Unsigned64*		mOCFeatureVector;



	public:
		OCSupportedFeatures();

		OCSupportedFeatures(const OCSupportedFeatures &objOCSupportedFeatures) {

		mTagsPresent = objOCSupportedFeatures.mTagsPresent;

		mMandatoryAvpCheckVal = objOCSupportedFeatures.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objOCSupportedFeatures.mMandatoryAvpSetVal;

		mTag = objOCSupportedFeatures.mTag;

		mDecodeFlag = objOCSupportedFeatures.mDecodeFlag;

		if(objOCSupportedFeatures.mOCFeatureVector != NULL)
		mOCFeatureVector = new Unsigned64(*(objOCSupportedFeatures.mOCFeatureVector));

		}

		void operator = (const OCSupportedFeatures &objOCSupportedFeatures) {

		mTagsPresent = objOCSupportedFeatures.mTagsPresent;

		mMandatoryAvpCheckVal = objOCSupportedFeatures.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objOCSupportedFeatures.mMandatoryAvpSetVal;

		mTag = objOCSupportedFeatures.mTag;

		mDecodeFlag = objOCSupportedFeatures.mDecodeFlag;

		if(objOCSupportedFeatures.mOCFeatureVector != NULL)
		mOCFeatureVector = new Unsigned64(*(objOCSupportedFeatures.mOCFeatureVector));

		}

		virtual ~OCSupportedFeatures();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument OCFeatureVector for datatype OCSupportedFeatures
		*/
		Unsigned64* setOCFeatureVector();

		//! Function to reset 
		/*!		Function to reset NULL type of argument OCFeatureVector for datatype OCSupportedFeatures
		*/
		void resetOCFeatureVector();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument OCFeatureVector for datatype OCSupportedFeatures
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getOCFeatureVector();

		//! Function to Decode
		/*!		Function to Decode datatype OCSupportedFeatures
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype OCSupportedFeatures
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype OCSupportedFeatures
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype OCSupportedFeatures
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype OCSupportedFeatures
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
