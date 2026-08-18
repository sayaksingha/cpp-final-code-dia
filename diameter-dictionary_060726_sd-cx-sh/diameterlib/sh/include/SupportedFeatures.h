#ifndef SH_SUPPORTEDFEATURES_H
#define SH_SUPPORTEDFEATURES_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SH{
typedef enum _tags_SupportedFeatures
{
	SupportedFeatures_VENDORID	= 0,
	SupportedFeatures_FEATURELISTID	= 1,
	SupportedFeatures_FEATURELIST	= 2,
}SupportedFeatures_tags;

		//! Class Definition
		/*!		ClassName is SupportedFeatures
		*/
class SupportedFeatures : public DiameterBaseInterface
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

		Unsigned32*		mVendorId;

		Unsigned32*		mFeatureListID;

		Unsigned32*		mFeatureList;





	public:
		SupportedFeatures();

		SupportedFeatures(const SupportedFeatures &objSupportedFeatures) {

		mTagsPresent = objSupportedFeatures.mTagsPresent;

		mMandatoryAvpCheckVal = objSupportedFeatures.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSupportedFeatures.mMandatoryAvpSetVal;

		mTag = objSupportedFeatures.mTag;

		mDecodeFlag = objSupportedFeatures.mDecodeFlag;

		if(objSupportedFeatures.mVendorId != NULL)
		mVendorId = new Unsigned32(*(objSupportedFeatures.mVendorId));

		if(objSupportedFeatures.mFeatureListID != NULL)
		mFeatureListID = new Unsigned32(*(objSupportedFeatures.mFeatureListID));

		if(objSupportedFeatures.mFeatureList != NULL)
		mFeatureList = new Unsigned32(*(objSupportedFeatures.mFeatureList));

		}

		void operator = (const SupportedFeatures &objSupportedFeatures) {

		mTagsPresent = objSupportedFeatures.mTagsPresent;

		mMandatoryAvpCheckVal = objSupportedFeatures.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSupportedFeatures.mMandatoryAvpSetVal;

		mTag = objSupportedFeatures.mTag;

		mDecodeFlag = objSupportedFeatures.mDecodeFlag;

		if(objSupportedFeatures.mVendorId != NULL)
		mVendorId = new Unsigned32(*(objSupportedFeatures.mVendorId));

		if(objSupportedFeatures.mFeatureListID != NULL)
		mFeatureListID = new Unsigned32(*(objSupportedFeatures.mFeatureListID));

		if(objSupportedFeatures.mFeatureList != NULL)
		mFeatureList = new Unsigned32(*(objSupportedFeatures.mFeatureList));

		}

		virtual ~SupportedFeatures();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument VendorId for datatype SupportedFeatures
		*/
		Unsigned32* setVendorId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument VendorId for datatype SupportedFeatures
		*/
		void resetVendorId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument VendorId for datatype SupportedFeatures
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getVendorId();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument FeatureListID for datatype SupportedFeatures
		*/
		Unsigned32* setFeatureListID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FeatureListID for datatype SupportedFeatures
		*/
		void resetFeatureListID();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument FeatureListID for datatype SupportedFeatures
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getFeatureListID();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument FeatureList for datatype SupportedFeatures
		*/
		Unsigned32* setFeatureList();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FeatureList for datatype SupportedFeatures
		*/
		void resetFeatureList();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument FeatureList for datatype SupportedFeatures
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getFeatureList();

		//! Function to Decode
		/*!		Function to Decode datatype SupportedFeatures
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype SupportedFeatures
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SupportedFeatures
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SupportedFeatures
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SupportedFeatures
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
