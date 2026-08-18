#ifndef SD_FIXEDUSERLOCATIONINFO_H
#define SD_FIXEDUSERLOCATIONINFO_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SD{
typedef enum _tags_FixedUserLocationInfo
{
	FixedUserLocationInfo_SSID	= 0,
	FixedUserLocationInfo_BSSID	= 1,
	FixedUserLocationInfo_LOGICALACCESSID	= 2,
	FixedUserLocationInfo_PHYSICALACCESSID	= 3,
}FixedUserLocationInfo_tags;

		//! Class Definition
		/*!		ClassName is FixedUserLocationInfo
		*/
class FixedUserLocationInfo : public DiameterBaseInterface
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

		OctetString*		mSSID;

		OctetString*		mBSSID;

		OctetString*		mLogicalAccessID;

		OctetString*		mPhysicalAccessID;






	public:
		FixedUserLocationInfo();

		FixedUserLocationInfo(const FixedUserLocationInfo &objFixedUserLocationInfo) {

		mTagsPresent = objFixedUserLocationInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objFixedUserLocationInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFixedUserLocationInfo.mMandatoryAvpSetVal;

		mTag = objFixedUserLocationInfo.mTag;

		mDecodeFlag = objFixedUserLocationInfo.mDecodeFlag;

		if(objFixedUserLocationInfo.mSSID != NULL)
		mSSID = new OctetString(*(objFixedUserLocationInfo.mSSID));

		if(objFixedUserLocationInfo.mBSSID != NULL)
		mBSSID = new OctetString(*(objFixedUserLocationInfo.mBSSID));

		if(objFixedUserLocationInfo.mLogicalAccessID != NULL)
		mLogicalAccessID = new OctetString(*(objFixedUserLocationInfo.mLogicalAccessID));

		if(objFixedUserLocationInfo.mPhysicalAccessID != NULL)
		mPhysicalAccessID = new OctetString(*(objFixedUserLocationInfo.mPhysicalAccessID));

		}

		void operator = (const FixedUserLocationInfo &objFixedUserLocationInfo) {

		mTagsPresent = objFixedUserLocationInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objFixedUserLocationInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFixedUserLocationInfo.mMandatoryAvpSetVal;

		mTag = objFixedUserLocationInfo.mTag;

		mDecodeFlag = objFixedUserLocationInfo.mDecodeFlag;

		if(objFixedUserLocationInfo.mSSID != NULL)
		mSSID = new OctetString(*(objFixedUserLocationInfo.mSSID));

		if(objFixedUserLocationInfo.mBSSID != NULL)
		mBSSID = new OctetString(*(objFixedUserLocationInfo.mBSSID));

		if(objFixedUserLocationInfo.mLogicalAccessID != NULL)
		mLogicalAccessID = new OctetString(*(objFixedUserLocationInfo.mLogicalAccessID));

		if(objFixedUserLocationInfo.mPhysicalAccessID != NULL)
		mPhysicalAccessID = new OctetString(*(objFixedUserLocationInfo.mPhysicalAccessID));

		}

		virtual ~FixedUserLocationInfo();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SSID for datatype FixedUserLocationInfo
		*/
		OctetString* setSSID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SSID for datatype FixedUserLocationInfo
		*/
		void resetSSID();

		//!Function to get values
		/*!		Function to get OctetString type of argument SSID for datatype FixedUserLocationInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSSID();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument BSSID for datatype FixedUserLocationInfo
		*/
		OctetString* setBSSID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument BSSID for datatype FixedUserLocationInfo
		*/
		void resetBSSID();

		//!Function to get values
		/*!		Function to get OctetString type of argument BSSID for datatype FixedUserLocationInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getBSSID();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument LogicalAccessID for datatype FixedUserLocationInfo
		*/
		OctetString* setLogicalAccessID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LogicalAccessID for datatype FixedUserLocationInfo
		*/
		void resetLogicalAccessID();

		//!Function to get values
		/*!		Function to get OctetString type of argument LogicalAccessID for datatype FixedUserLocationInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getLogicalAccessID();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PhysicalAccessID for datatype FixedUserLocationInfo
		*/
		OctetString* setPhysicalAccessID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PhysicalAccessID for datatype FixedUserLocationInfo
		*/
		void resetPhysicalAccessID();

		//!Function to get values
		/*!		Function to get OctetString type of argument PhysicalAccessID for datatype FixedUserLocationInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPhysicalAccessID();

		//! Function to Decode
		/*!		Function to Decode datatype FixedUserLocationInfo
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype FixedUserLocationInfo
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype FixedUserLocationInfo
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype FixedUserLocationInfo
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype FixedUserLocationInfo
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
