#ifndef SD_LOAD_H
#define SD_LOAD_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/LoadType.h"
using namespace std;

namespace SD{
typedef enum _tags_Load
{
	Load_LOADTYPE	= 0,
	Load_LOADVALUE	= 1,
	Load_SOURCEID	= 2,
}Load_tags;

		//! Class Definition
		/*!		ClassName is Load
		*/
class Load : public DiameterBaseInterface
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

		LoadType*		mLoadType;

		Unsigned64*		mLoadValue;

		OctetString*		mSourceID;





	public:
		Load();

		Load(const Load &objLoad) {

		mTagsPresent = objLoad.mTagsPresent;

		mMandatoryAvpCheckVal = objLoad.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objLoad.mMandatoryAvpSetVal;

		mTag = objLoad.mTag;

		mDecodeFlag = objLoad.mDecodeFlag;

		if(objLoad.mLoadType != NULL)
		mLoadType = new LoadType(*(objLoad.mLoadType));

		if(objLoad.mLoadValue != NULL)
		mLoadValue = new Unsigned64(*(objLoad.mLoadValue));

		if(objLoad.mSourceID != NULL)
		mSourceID = new OctetString(*(objLoad.mSourceID));

		}

		void operator = (const Load &objLoad) {

		mTagsPresent = objLoad.mTagsPresent;

		mMandatoryAvpCheckVal = objLoad.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objLoad.mMandatoryAvpSetVal;

		mTag = objLoad.mTag;

		mDecodeFlag = objLoad.mDecodeFlag;

		if(objLoad.mLoadType != NULL)
		mLoadType = new LoadType(*(objLoad.mLoadType));

		if(objLoad.mLoadValue != NULL)
		mLoadValue = new Unsigned64(*(objLoad.mLoadValue));

		if(objLoad.mSourceID != NULL)
		mSourceID = new OctetString(*(objLoad.mSourceID));

		}

		virtual ~Load();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument LoadType for datatype Load
		*/
		LoadType* setLoadType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LoadType for datatype Load
		*/
		void resetLoadType();

		//!Function to get values
		/*!		Function to get LoadType type of argument LoadType for datatype Load
		Throws exception of which type and Summary of Exception
		*/
		LoadType* getLoadType();

		//!Function to set values
		/*!		Function to set the recent Unsigned64 type of argument LoadValue for datatype Load
		*/
		Unsigned64* setLoadValue();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LoadValue for datatype Load
		*/
		void resetLoadValue();

		//!Function to get values
		/*!		Function to get Unsigned64 type of argument LoadValue for datatype Load
		Throws exception of which type and Summary of Exception
		*/
		Unsigned64* getLoadValue();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SourceID for datatype Load
		*/
		OctetString* setSourceID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SourceID for datatype Load
		*/
		void resetSourceID();

		//!Function to get values
		/*!		Function to get OctetString type of argument SourceID for datatype Load
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSourceID();

		//! Function to Decode
		/*!		Function to Decode datatype Load
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype Load
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype Load
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype Load
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype Load
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
