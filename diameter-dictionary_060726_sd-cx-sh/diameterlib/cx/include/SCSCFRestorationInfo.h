#ifndef CX_SCSCFRESTORATIONINFO_H
#define CX_SCSCFRESTORATIONINFO_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "cx/include/RestorationInfo.h"
using namespace std;

namespace CX{
typedef enum _tags_SCSCFRestorationInfo
{
	SCSCFRestorationInfo_USERNAME	= 0,
	SCSCFRestorationInfo_RESTORATIONINFO	= 1,
	SCSCFRestorationInfo_REGISTRATIONTIMEOUT	= 2,
	SCSCFRestorationInfo_SIPAUTHENTICATIONSCHEME	= 3,
}SCSCFRestorationInfo_tags;

		//! Class Definition
		/*!		ClassName is SCSCFRestorationInfo
		*/
class SCSCFRestorationInfo : public DiameterBaseInterface
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

		OctetString*		mUserName;

		Time*		mRegistrationTimeOut;

		OctetString*		mSIPAuthenticationScheme;



		list<RestorationInfo*>*	mRestorationInfoGrpList;
		list<RestorationInfo*>::iterator	mRestorationInfoGrpIterator;



	public:
		SCSCFRestorationInfo();

		SCSCFRestorationInfo(const SCSCFRestorationInfo &objSCSCFRestorationInfo) {

		mTagsPresent = objSCSCFRestorationInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objSCSCFRestorationInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSCSCFRestorationInfo.mMandatoryAvpSetVal;

		mTag = objSCSCFRestorationInfo.mTag;

		mDecodeFlag = objSCSCFRestorationInfo.mDecodeFlag;

		if(objSCSCFRestorationInfo.mUserName != NULL)
		mUserName = new OctetString(*(objSCSCFRestorationInfo.mUserName));

		if(objSCSCFRestorationInfo.mRestorationInfoGrpList != NULL)
		 {
		 mRestorationInfoGrpList = new list<RestorationInfo*>;
		 for( auto element : *objSCSCFRestorationInfo.mRestorationInfoGrpList)
		 {
				 RestorationInfo *lRestorationInfo =  new RestorationInfo(*element);
				 mRestorationInfoGrpList->push_back(lRestorationInfo);
		 }
		 }
		if(objSCSCFRestorationInfo.mRegistrationTimeOut != NULL)
		mRegistrationTimeOut = new Time(*(objSCSCFRestorationInfo.mRegistrationTimeOut));

		if(objSCSCFRestorationInfo.mSIPAuthenticationScheme != NULL)
		mSIPAuthenticationScheme = new OctetString(*(objSCSCFRestorationInfo.mSIPAuthenticationScheme));

		}

		void operator = (const SCSCFRestorationInfo &objSCSCFRestorationInfo) {

		mTagsPresent = objSCSCFRestorationInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objSCSCFRestorationInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSCSCFRestorationInfo.mMandatoryAvpSetVal;

		mTag = objSCSCFRestorationInfo.mTag;

		mDecodeFlag = objSCSCFRestorationInfo.mDecodeFlag;

		if(objSCSCFRestorationInfo.mUserName != NULL)
		mUserName = new OctetString(*(objSCSCFRestorationInfo.mUserName));

		if(objSCSCFRestorationInfo.mRestorationInfoGrpList != NULL)
		 {
		 mRestorationInfoGrpList = new list<RestorationInfo*>;
		 for( auto element : *objSCSCFRestorationInfo.mRestorationInfoGrpList)
		 {
				 RestorationInfo *lRestorationInfo =  new RestorationInfo(*element);
				 mRestorationInfoGrpList->push_back(lRestorationInfo);
		 }
		 }
		if(objSCSCFRestorationInfo.mRegistrationTimeOut != NULL)
		mRegistrationTimeOut = new Time(*(objSCSCFRestorationInfo.mRegistrationTimeOut));

		if(objSCSCFRestorationInfo.mSIPAuthenticationScheme != NULL)
		mSIPAuthenticationScheme = new OctetString(*(objSCSCFRestorationInfo.mSIPAuthenticationScheme));

		}

		virtual ~SCSCFRestorationInfo();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument UserName for datatype SCSCFRestorationInfo
		*/
		OctetString* setUserName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UserName for datatype SCSCFRestorationInfo
		*/
		void resetUserName();

		//!Function to get values
		/*!		Function to get OctetString type of argument UserName for datatype SCSCFRestorationInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getUserName();

		list<RestorationInfo*>* getRestorationInfoGrpList();

		list<RestorationInfo*>* setRestorationInfoGrpList();

		void resetRestorationInfoGrpList();

		//!Function to set values
		/*!		Function to set the recent Time type of argument RegistrationTimeOut for datatype SCSCFRestorationInfo
		*/
		Time* setRegistrationTimeOut();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RegistrationTimeOut for datatype SCSCFRestorationInfo
		*/
		void resetRegistrationTimeOut();

		//!Function to get values
		/*!		Function to get Time type of argument RegistrationTimeOut for datatype SCSCFRestorationInfo
		Throws exception of which type and Summary of Exception
		*/
		Time* getRegistrationTimeOut();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SIPAuthenticationScheme for datatype SCSCFRestorationInfo
		*/
		OctetString* setSIPAuthenticationScheme();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SIPAuthenticationScheme for datatype SCSCFRestorationInfo
		*/
		void resetSIPAuthenticationScheme();

		//!Function to get values
		/*!		Function to get OctetString type of argument SIPAuthenticationScheme for datatype SCSCFRestorationInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSIPAuthenticationScheme();

		//! Function to Decode
		/*!		Function to Decode datatype SCSCFRestorationInfo
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype SCSCFRestorationInfo
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SCSCFRestorationInfo
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SCSCFRestorationInfo
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SCSCFRestorationInfo
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
