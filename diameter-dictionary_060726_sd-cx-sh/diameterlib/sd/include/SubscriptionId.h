#ifndef SD_SUBSCRIPTIONID_H
#define SD_SUBSCRIPTIONID_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/SubscriptionIdType.h"
using namespace std;

namespace SD{
typedef enum _tags_SubscriptionId
{
	SubscriptionId_SUBSCRIPTIONIDTYPE	= 0,
	SubscriptionId_SUBSCRIPTIONIDDATA	= 1,
}SubscriptionId_tags;

		//! Class Definition
		/*!		ClassName is SubscriptionId
		*/
class SubscriptionId : public DiameterBaseInterface
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

		SubscriptionIdType*		mSubscriptionIdType;

		OctetString*		mSubscriptionIdData;




	public:
		SubscriptionId();

		SubscriptionId(const SubscriptionId &objSubscriptionId) {

		mTagsPresent = objSubscriptionId.mTagsPresent;

		mMandatoryAvpCheckVal = objSubscriptionId.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSubscriptionId.mMandatoryAvpSetVal;

		mTag = objSubscriptionId.mTag;

		mDecodeFlag = objSubscriptionId.mDecodeFlag;

		if(objSubscriptionId.mSubscriptionIdType != NULL)
		mSubscriptionIdType = new SubscriptionIdType(*(objSubscriptionId.mSubscriptionIdType));

		if(objSubscriptionId.mSubscriptionIdData != NULL)
		mSubscriptionIdData = new OctetString(*(objSubscriptionId.mSubscriptionIdData));

		}

		void operator = (const SubscriptionId &objSubscriptionId) {

		mTagsPresent = objSubscriptionId.mTagsPresent;

		mMandatoryAvpCheckVal = objSubscriptionId.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objSubscriptionId.mMandatoryAvpSetVal;

		mTag = objSubscriptionId.mTag;

		mDecodeFlag = objSubscriptionId.mDecodeFlag;

		if(objSubscriptionId.mSubscriptionIdType != NULL)
		mSubscriptionIdType = new SubscriptionIdType(*(objSubscriptionId.mSubscriptionIdType));

		if(objSubscriptionId.mSubscriptionIdData != NULL)
		mSubscriptionIdData = new OctetString(*(objSubscriptionId.mSubscriptionIdData));

		}

		virtual ~SubscriptionId();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument SubscriptionIdType for datatype SubscriptionId
		*/
		SubscriptionIdType* setSubscriptionIdType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SubscriptionIdType for datatype SubscriptionId
		*/
		void resetSubscriptionIdType();

		//!Function to get values
		/*!		Function to get SubscriptionIdType type of argument SubscriptionIdType for datatype SubscriptionId
		Throws exception of which type and Summary of Exception
		*/
		SubscriptionIdType* getSubscriptionIdType();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SubscriptionIdData for datatype SubscriptionId
		*/
		OctetString* setSubscriptionIdData();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SubscriptionIdData for datatype SubscriptionId
		*/
		void resetSubscriptionIdData();

		//!Function to get values
		/*!		Function to get OctetString type of argument SubscriptionIdData for datatype SubscriptionId
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSubscriptionIdData();

		//! Function to Decode
		/*!		Function to Decode datatype SubscriptionId
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype SubscriptionId
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype SubscriptionId
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype SubscriptionId
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype SubscriptionId
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
