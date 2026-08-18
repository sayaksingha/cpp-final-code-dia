#ifndef RX_MAINFORMATION_H
#define RX_MAINFORMATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "rx/include/IPCANType.h"
using namespace std;

namespace RX{
typedef enum _tags_MAInformation
{
	MAInformation_IPCANTYPE	= 0,
	MAInformation_RATTYPE	= 1,
	MAInformation_MAINFORMATIONACTION	= 2,
}MAInformation_tags;

		//! Class Definition
		/*!		ClassName is MAInformation
		*/
class MAInformation : public DiameterBaseInterface
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

		IPCANType*		mIPCANType;

		Unsigned32*		mRATType;

		Unsigned32*		mMAInformationAction;





	public:
		MAInformation();

		MAInformation(const MAInformation &objMAInformation) {

		mTagsPresent = objMAInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objMAInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMAInformation.mMandatoryAvpSetVal;

		mTag = objMAInformation.mTag;

		mDecodeFlag = objMAInformation.mDecodeFlag;

		if(objMAInformation.mIPCANType != NULL)
		mIPCANType = new IPCANType(*(objMAInformation.mIPCANType));

		if(objMAInformation.mRATType != NULL)
		mRATType = new Unsigned32(*(objMAInformation.mRATType));

		if(objMAInformation.mMAInformationAction != NULL)
		mMAInformationAction = new Unsigned32(*(objMAInformation.mMAInformationAction));

		}

		void operator = (const MAInformation &objMAInformation) {

		mTagsPresent = objMAInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objMAInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMAInformation.mMandatoryAvpSetVal;

		mTag = objMAInformation.mTag;

		mDecodeFlag = objMAInformation.mDecodeFlag;

		if(objMAInformation.mIPCANType != NULL)
		mIPCANType = new IPCANType(*(objMAInformation.mIPCANType));

		if(objMAInformation.mRATType != NULL)
		mRATType = new Unsigned32(*(objMAInformation.mRATType));

		if(objMAInformation.mMAInformationAction != NULL)
		mMAInformationAction = new Unsigned32(*(objMAInformation.mMAInformationAction));

		}

		virtual ~MAInformation();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument IPCANType for datatype MAInformation
		*/
		IPCANType* setIPCANType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument IPCANType for datatype MAInformation
		*/
		void resetIPCANType();

		//!Function to get values
		/*!		Function to get IPCANType type of argument IPCANType for datatype MAInformation
		Throws exception of which type and Summary of Exception
		*/
		IPCANType* getIPCANType();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RATType for datatype MAInformation
		*/
		Unsigned32* setRATType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RATType for datatype MAInformation
		*/
		void resetRATType();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RATType for datatype MAInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRATType();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MAInformationAction for datatype MAInformation
		*/
		Unsigned32* setMAInformationAction();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MAInformationAction for datatype MAInformation
		*/
		void resetMAInformationAction();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MAInformationAction for datatype MAInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMAInformationAction();

		//! Function to Decode
		/*!		Function to Decode datatype MAInformation
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype MAInformation
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype MAInformation
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype MAInformation
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype MAInformation
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
