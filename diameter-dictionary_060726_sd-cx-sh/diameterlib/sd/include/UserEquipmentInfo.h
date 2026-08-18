#ifndef SD_USEREQUIPMENTINFO_H
#define SD_USEREQUIPMENTINFO_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/UserEquipmentInfoType.h"
using namespace std;

namespace SD{
typedef enum _tags_UserEquipmentInfo
{
	UserEquipmentInfo_USEREQUIPMENTINFOTYPE	= 0,
	UserEquipmentInfo_USEREQUIPMENTINFOVALUE	= 1,
}UserEquipmentInfo_tags;

		//! Class Definition
		/*!		ClassName is UserEquipmentInfo
		*/
class UserEquipmentInfo : public DiameterBaseInterface
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

		UserEquipmentInfoType*		mUserEquipmentInfoType;

		OctetString*		mUserEquipmentInfoValue;




	public:
		UserEquipmentInfo();

		UserEquipmentInfo(const UserEquipmentInfo &objUserEquipmentInfo) {

		mTagsPresent = objUserEquipmentInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objUserEquipmentInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserEquipmentInfo.mMandatoryAvpSetVal;

		mTag = objUserEquipmentInfo.mTag;

		mDecodeFlag = objUserEquipmentInfo.mDecodeFlag;

		if(objUserEquipmentInfo.mUserEquipmentInfoType != NULL)
		mUserEquipmentInfoType = new UserEquipmentInfoType(*(objUserEquipmentInfo.mUserEquipmentInfoType));

		if(objUserEquipmentInfo.mUserEquipmentInfoValue != NULL)
		mUserEquipmentInfoValue = new OctetString(*(objUserEquipmentInfo.mUserEquipmentInfoValue));

		}

		void operator = (const UserEquipmentInfo &objUserEquipmentInfo) {

		mTagsPresent = objUserEquipmentInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objUserEquipmentInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserEquipmentInfo.mMandatoryAvpSetVal;

		mTag = objUserEquipmentInfo.mTag;

		mDecodeFlag = objUserEquipmentInfo.mDecodeFlag;

		if(objUserEquipmentInfo.mUserEquipmentInfoType != NULL)
		mUserEquipmentInfoType = new UserEquipmentInfoType(*(objUserEquipmentInfo.mUserEquipmentInfoType));

		if(objUserEquipmentInfo.mUserEquipmentInfoValue != NULL)
		mUserEquipmentInfoValue = new OctetString(*(objUserEquipmentInfo.mUserEquipmentInfoValue));

		}

		virtual ~UserEquipmentInfo();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument UserEquipmentInfoType for datatype UserEquipmentInfo
		*/
		UserEquipmentInfoType* setUserEquipmentInfoType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserEquipmentInfoType for datatype UserEquipmentInfo
		*/
		void resetUserEquipmentInfoType();

		//!Function to get values
		/*!		Function to get UserEquipmentInfoType type of argument UserEquipmentInfoType for datatype UserEquipmentInfo
		Throws exception of which type and Summary of Exception
		*/
		UserEquipmentInfoType* getUserEquipmentInfoType();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserEquipmentInfoValue for datatype UserEquipmentInfo
		*/
		OctetString* setUserEquipmentInfoValue();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserEquipmentInfoValue for datatype UserEquipmentInfo
		*/
		void resetUserEquipmentInfoValue();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserEquipmentInfoValue for datatype UserEquipmentInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserEquipmentInfoValue();

		//! Function to Decode
		/*!		Function to Decode datatype UserEquipmentInfo
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype UserEquipmentInfo
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UserEquipmentInfo
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UserEquipmentInfo
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UserEquipmentInfo
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
