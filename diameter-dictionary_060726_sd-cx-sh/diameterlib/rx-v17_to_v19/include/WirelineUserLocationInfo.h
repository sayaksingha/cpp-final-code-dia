#ifndef RX_WIRELINEUSERLOCATIONINFO_H
#define RX_WIRELINEUSERLOCATIONINFO_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace RX{
typedef enum _tags_WirelineUserLocationInfo
{
	WirelineUserLocationInfo_HFCNODEIDENTIFIERAVP	= 0,
	WirelineUserLocationInfo_GLIIDENTIFIERAVP	= 1,
	WirelineUserLocationInfo_LINETYPEAVP	= 2,
}WirelineUserLocationInfo_tags;

		//! Class Definition
		/*!		ClassName is WirelineUserLocationInfo
		*/
class WirelineUserLocationInfo : public DiameterBaseInterface
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

		OctetString*		mHFCNodeIdentifierAVP;

		OctetString*		mGLIIdentifierAVP;

		Unsigned32*		mLineTypeAVP;





	public:
		WirelineUserLocationInfo();

		WirelineUserLocationInfo(const WirelineUserLocationInfo &objWirelineUserLocationInfo) {

		mTagsPresent = objWirelineUserLocationInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objWirelineUserLocationInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objWirelineUserLocationInfo.mMandatoryAvpSetVal;

		mTag = objWirelineUserLocationInfo.mTag;

		mDecodeFlag = objWirelineUserLocationInfo.mDecodeFlag;

		if(objWirelineUserLocationInfo.mHFCNodeIdentifierAVP != NULL)
		mHFCNodeIdentifierAVP = new OctetString(*(objWirelineUserLocationInfo.mHFCNodeIdentifierAVP));

		if(objWirelineUserLocationInfo.mGLIIdentifierAVP != NULL)
		mGLIIdentifierAVP = new OctetString(*(objWirelineUserLocationInfo.mGLIIdentifierAVP));

		if(objWirelineUserLocationInfo.mLineTypeAVP != NULL)
		mLineTypeAVP = new Unsigned32(*(objWirelineUserLocationInfo.mLineTypeAVP));

		}

		void operator = (const WirelineUserLocationInfo &objWirelineUserLocationInfo) {

		mTagsPresent = objWirelineUserLocationInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objWirelineUserLocationInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objWirelineUserLocationInfo.mMandatoryAvpSetVal;

		mTag = objWirelineUserLocationInfo.mTag;

		mDecodeFlag = objWirelineUserLocationInfo.mDecodeFlag;

		if(objWirelineUserLocationInfo.mHFCNodeIdentifierAVP != NULL)
		mHFCNodeIdentifierAVP = new OctetString(*(objWirelineUserLocationInfo.mHFCNodeIdentifierAVP));

		if(objWirelineUserLocationInfo.mGLIIdentifierAVP != NULL)
		mGLIIdentifierAVP = new OctetString(*(objWirelineUserLocationInfo.mGLIIdentifierAVP));

		if(objWirelineUserLocationInfo.mLineTypeAVP != NULL)
		mLineTypeAVP = new Unsigned32(*(objWirelineUserLocationInfo.mLineTypeAVP));

		}

		virtual ~WirelineUserLocationInfo();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument HFCNodeIdentifierAVP for datatype WirelineUserLocationInfo
		*/
		OctetString* setHFCNodeIdentifierAVP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument HFCNodeIdentifierAVP for datatype WirelineUserLocationInfo
		*/
		void resetHFCNodeIdentifierAVP();

		//!Function to get values
		/*!		Function to get OctetString type of argument HFCNodeIdentifierAVP for datatype WirelineUserLocationInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getHFCNodeIdentifierAVP();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument GLIIdentifierAVP for datatype WirelineUserLocationInfo
		*/
		OctetString* setGLIIdentifierAVP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument GLIIdentifierAVP for datatype WirelineUserLocationInfo
		*/
		void resetGLIIdentifierAVP();

		//!Function to get values
		/*!		Function to get OctetString type of argument GLIIdentifierAVP for datatype WirelineUserLocationInfo
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getGLIIdentifierAVP();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument LineTypeAVP for datatype WirelineUserLocationInfo
		*/
		Unsigned32* setLineTypeAVP();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LineTypeAVP for datatype WirelineUserLocationInfo
		*/
		void resetLineTypeAVP();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument LineTypeAVP for datatype WirelineUserLocationInfo
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getLineTypeAVP();

		//! Function to Decode
		/*!		Function to Decode datatype WirelineUserLocationInfo
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype WirelineUserLocationInfo
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype WirelineUserLocationInfo
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype WirelineUserLocationInfo
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype WirelineUserLocationInfo
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
