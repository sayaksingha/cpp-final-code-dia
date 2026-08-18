#ifndef SD_USERCSGINFORMATION_H
#define SD_USERCSGINFORMATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/CSGAccessMode.h"
#include "sd/include/CSGMembershipIndication.h"
using namespace std;

namespace SD{
typedef enum _tags_UserCSGInformation
{
	UserCSGInformation_CSGID	= 0,
	UserCSGInformation_CSGACCESSMODE	= 1,
	UserCSGInformation_CSGMEMBERSHIPINDICATION	= 2,
}UserCSGInformation_tags;

		//! Class Definition
		/*!		ClassName is UserCSGInformation
		*/
class UserCSGInformation : public DiameterBaseInterface
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

		Unsigned32*		mCSGId;

		CSGAccessMode*		mCSGAccessMode;

		CSGMembershipIndication*		mCSGMembershipIndication;





	public:
		UserCSGInformation();

		UserCSGInformation(const UserCSGInformation &objUserCSGInformation) {

		mTagsPresent = objUserCSGInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objUserCSGInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserCSGInformation.mMandatoryAvpSetVal;

		mTag = objUserCSGInformation.mTag;

		mDecodeFlag = objUserCSGInformation.mDecodeFlag;

		if(objUserCSGInformation.mCSGId != NULL)
		mCSGId = new Unsigned32(*(objUserCSGInformation.mCSGId));

		if(objUserCSGInformation.mCSGAccessMode != NULL)
		mCSGAccessMode = new CSGAccessMode(*(objUserCSGInformation.mCSGAccessMode));

		if(objUserCSGInformation.mCSGMembershipIndication != NULL)
		mCSGMembershipIndication = new CSGMembershipIndication(*(objUserCSGInformation.mCSGMembershipIndication));

		}

		void operator = (const UserCSGInformation &objUserCSGInformation) {

		mTagsPresent = objUserCSGInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objUserCSGInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objUserCSGInformation.mMandatoryAvpSetVal;

		mTag = objUserCSGInformation.mTag;

		mDecodeFlag = objUserCSGInformation.mDecodeFlag;

		if(objUserCSGInformation.mCSGId != NULL)
		mCSGId = new Unsigned32(*(objUserCSGInformation.mCSGId));

		if(objUserCSGInformation.mCSGAccessMode != NULL)
		mCSGAccessMode = new CSGAccessMode(*(objUserCSGInformation.mCSGAccessMode));

		if(objUserCSGInformation.mCSGMembershipIndication != NULL)
		mCSGMembershipIndication = new CSGMembershipIndication(*(objUserCSGInformation.mCSGMembershipIndication));

		}

		virtual ~UserCSGInformation();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument CSGId for datatype UserCSGInformation
		*/
		Unsigned32* setCSGId();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CSGId for datatype UserCSGInformation
		*/
		void resetCSGId();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument CSGId for datatype UserCSGInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getCSGId();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CSGAccessMode for datatype UserCSGInformation
		*/
		CSGAccessMode* setCSGAccessMode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CSGAccessMode for datatype UserCSGInformation
		*/
		void resetCSGAccessMode();

		//!Function to get values
		/*!		Function to get CSGAccessMode type of argument CSGAccessMode for datatype UserCSGInformation
		Throws exception of which type and Summary of Exception
		*/
		CSGAccessMode* getCSGAccessMode();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument CSGMembershipIndication for datatype UserCSGInformation
		*/
		CSGMembershipIndication* setCSGMembershipIndication();

		//! Function to reset 
		/*!		Function to reset NULL type of argument CSGMembershipIndication for datatype UserCSGInformation
		*/
		void resetCSGMembershipIndication();

		//!Function to get values
		/*!		Function to get CSGMembershipIndication type of argument CSGMembershipIndication for datatype UserCSGInformation
		Throws exception of which type and Summary of Exception
		*/
		CSGMembershipIndication* getCSGMembershipIndication();

		//! Function to Decode
		/*!		Function to Decode datatype UserCSGInformation
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype UserCSGInformation
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype UserCSGInformation
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype UserCSGInformation
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype UserCSGInformation
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
