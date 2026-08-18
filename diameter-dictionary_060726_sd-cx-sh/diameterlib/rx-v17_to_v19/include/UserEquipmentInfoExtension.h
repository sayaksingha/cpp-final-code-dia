#ifndef RX_USEREQUIPMENTINFOEXTENSION_H
#define RX_USEREQUIPMENTINFOEXTENSION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace RX{
typedef enum _tags_UserEquipmentInfoExtension
{
	UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEISV	= 0,
	UserEquipmentInfoExtension_USEREQUIPMENTINFOMAC	= 1,
	UserEquipmentInfoExtension_USEREQUIPMENTINFOEUI64	= 2,
	UserEquipmentInfoExtension_USEREQUIPMENTINFOMODIFIEDEUI64	= 3,
	UserEquipmentInfoExtension_USEREQUIPMENTINFOIMEI	= 4,
}UserEquipmentInfoExtension_tags;

		//! Class Definition
		/*!		ClassName is UserEquipmentInfoExtension
		*/
class UserEquipmentInfoExtension : public DiameterBaseInterface
{
	private:

		bitset<5> mTagsPresent;

		bitset<5> mMandatoryAvpCheckVal;

		bitset<5> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mUserEquipmentInfoIMEISV;

		OctetString*		mUserEquipmentInfoMAC;

		OctetString*		mUserEquipmentInfoEUI64;

		OctetString*		mUserEquipmentInfoModifiedEUI64;

		OctetString*		mUserEquipmentInfoIMEI;







	public:
		UserEquipmentInfoExtension();

		UserEquipmentInfoExtension(const UserEquipmentInfoExtension &objUserEquipmentInfoExtension) {

		mTagsPresent = objUserEquipmentInfoExtension.mTagsPresent;

		mMandatoryAvpCheckVal = objUserEquipmentInfoExtension.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserEquipmentInfoExtension.mMandatoryAvpSetVal;

		mTag = objUserEquipmentInfoExtension.mTag;

		mDecodeFlag = objUserEquipmentInfoExtension.mDecodeFlag;

		if(objUserEquipmentInfoExtension.mUserEquipmentInfoIMEISV != NULL)
		mUserEquipmentInfoIMEISV = new OctetString(*(objUserEquipmentInfoExtension.mUserEquipmentInfoIMEISV));

		if(objUserEquipmentInfoExtension.mUserEquipmentInfoMAC != NULL)
		mUserEquipmentInfoMAC = new OctetString(*(objUserEquipmentInfoExtension.mUserEquipmentInfoMAC));

		if(objUserEquipmentInfoExtension.mUserEquipmentInfoEUI64 != NULL)
		mUserEquipmentInfoEUI64 = new OctetString(*(objUserEquipmentInfoExtension.mUserEquipmentInfoEUI64));

		if(objUserEquipmentInfoExtension.mUserEquipmentInfoModifiedEUI64 != NULL)
		mUserEquipmentInfoModifiedEUI64 = new OctetString(*(objUserEquipmentInfoExtension.mUserEquipmentInfoModifiedEUI64));

		if(objUserEquipmentInfoExtension.mUserEquipmentInfoIMEI != NULL)
		mUserEquipmentInfoIMEI = new OctetString(*(objUserEquipmentInfoExtension.mUserEquipmentInfoIMEI));

		}

		void operator = (const UserEquipmentInfoExtension &objUserEquipmentInfoExtension) {

		mTagsPresent = objUserEquipmentInfoExtension.mTagsPresent;

		mMandatoryAvpCheckVal = objUserEquipmentInfoExtension.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserEquipmentInfoExtension.mMandatoryAvpSetVal;

		mTag = objUserEquipmentInfoExtension.mTag;

		mDecodeFlag = objUserEquipmentInfoExtension.mDecodeFlag;

		if(objUserEquipmentInfoExtension.mUserEquipmentInfoIMEISV != NULL)
		mUserEquipmentInfoIMEISV = new OctetString(*(objUserEquipmentInfoExtension.mUserEquipmentInfoIMEISV));

		if(objUserEquipmentInfoExtension.mUserEquipmentInfoMAC != NULL)
		mUserEquipmentInfoMAC = new OctetString(*(objUserEquipmentInfoExtension.mUserEquipmentInfoMAC));

		if(objUserEquipmentInfoExtension.mUserEquipmentInfoEUI64 != NULL)
		mUserEquipmentInfoEUI64 = new OctetString(*(objUserEquipmentInfoExtension.mUserEquipmentInfoEUI64));

		if(objUserEquipmentInfoExtension.mUserEquipmentInfoModifiedEUI64 != NULL)
		mUserEquipmentInfoModifiedEUI64 = new OctetString(*(objUserEquipmentInfoExtension.mUserEquipmentInfoModifiedEUI64));

		if(objUserEquipmentInfoExtension.mUserEquipmentInfoIMEI != NULL)
		mUserEquipmentInfoIMEI = new OctetString(*(objUserEquipmentInfoExtension.mUserEquipmentInfoIMEI));

		}

		virtual ~UserEquipmentInfoExtension();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserEquipmentInfoIMEISV for datatype UserEquipmentInfoExtension
		*/
		OctetString* setUserEquipmentInfoIMEISV();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserEquipmentInfoIMEISV for datatype UserEquipmentInfoExtension
		*/
		void resetUserEquipmentInfoIMEISV();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserEquipmentInfoIMEISV for datatype UserEquipmentInfoExtension
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserEquipmentInfoIMEISV();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserEquipmentInfoMAC for datatype UserEquipmentInfoExtension
		*/
		OctetString* setUserEquipmentInfoMAC();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserEquipmentInfoMAC for datatype UserEquipmentInfoExtension
		*/
		void resetUserEquipmentInfoMAC();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserEquipmentInfoMAC for datatype UserEquipmentInfoExtension
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserEquipmentInfoMAC();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserEquipmentInfoEUI64 for datatype UserEquipmentInfoExtension
		*/
		OctetString* setUserEquipmentInfoEUI64();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserEquipmentInfoEUI64 for datatype UserEquipmentInfoExtension
		*/
		void resetUserEquipmentInfoEUI64();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserEquipmentInfoEUI64 for datatype UserEquipmentInfoExtension
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserEquipmentInfoEUI64();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserEquipmentInfoModifiedEUI64 for datatype UserEquipmentInfoExtension
		*/
		OctetString* setUserEquipmentInfoModifiedEUI64();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserEquipmentInfoModifiedEUI64 for datatype UserEquipmentInfoExtension
		*/
		void resetUserEquipmentInfoModifiedEUI64();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserEquipmentInfoModifiedEUI64 for datatype UserEquipmentInfoExtension
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserEquipmentInfoModifiedEUI64();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserEquipmentInfoIMEI for datatype UserEquipmentInfoExtension
		*/
		OctetString* setUserEquipmentInfoIMEI();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserEquipmentInfoIMEI for datatype UserEquipmentInfoExtension
		*/
		void resetUserEquipmentInfoIMEI();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserEquipmentInfoIMEI for datatype UserEquipmentInfoExtension
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserEquipmentInfoIMEI();

		//! Function to Decode
		/*!		Function to Decode datatype UserEquipmentInfoExtension
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype UserEquipmentInfoExtension
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UserEquipmentInfoExtension
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UserEquipmentInfoExtension
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UserEquipmentInfoExtension
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
