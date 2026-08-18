#ifndef SD_PRESENCEREPORTINGAREAINFORMATION_H
#define SD_PRESENCEREPORTINGAREAINFORMATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SD{
typedef enum _tags_PresenceReportingAreaInformation
{
	PresenceReportingAreaInformation_PRESENCEREPORTINGAREAIDENTIFIER	= 0,
	PresenceReportingAreaInformation_PRESENCEREPORTINGAREASTATUS	= 1,
	PresenceReportingAreaInformation_PRESENCEREPORTINGAREAELEMENTSLIST	= 2,
	PresenceReportingAreaInformation_PRESENCEREPORTINGAREANODE	= 3,
}PresenceReportingAreaInformation_tags;

		//! Class Definition
		/*!		ClassName is PresenceReportingAreaInformation
		*/
class PresenceReportingAreaInformation : public DiameterBaseInterface
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

		OctetString*		mPresenceReportingAreaIdentifier;

		Unsigned32*		mPresenceReportingAreaStatus;

		OctetString*		mPresenceReportingAreaElementsList;

		Unsigned32*		mPresenceReportingAreaNode;






	public:
		PresenceReportingAreaInformation();

		PresenceReportingAreaInformation(const PresenceReportingAreaInformation &objPresenceReportingAreaInformation) {

		mTagsPresent = objPresenceReportingAreaInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objPresenceReportingAreaInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPresenceReportingAreaInformation.mMandatoryAvpSetVal;

		mTag = objPresenceReportingAreaInformation.mTag;

		mDecodeFlag = objPresenceReportingAreaInformation.mDecodeFlag;

		if(objPresenceReportingAreaInformation.mPresenceReportingAreaIdentifier != NULL)
		mPresenceReportingAreaIdentifier = new OctetString(*(objPresenceReportingAreaInformation.mPresenceReportingAreaIdentifier));

		if(objPresenceReportingAreaInformation.mPresenceReportingAreaStatus != NULL)
		mPresenceReportingAreaStatus = new Unsigned32(*(objPresenceReportingAreaInformation.mPresenceReportingAreaStatus));

		if(objPresenceReportingAreaInformation.mPresenceReportingAreaElementsList != NULL)
		mPresenceReportingAreaElementsList = new OctetString(*(objPresenceReportingAreaInformation.mPresenceReportingAreaElementsList));

		if(objPresenceReportingAreaInformation.mPresenceReportingAreaNode != NULL)
		mPresenceReportingAreaNode = new Unsigned32(*(objPresenceReportingAreaInformation.mPresenceReportingAreaNode));

		}

		void operator = (const PresenceReportingAreaInformation &objPresenceReportingAreaInformation) {

		mTagsPresent = objPresenceReportingAreaInformation.mTagsPresent;

		mMandatoryAvpCheckVal = objPresenceReportingAreaInformation.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objPresenceReportingAreaInformation.mMandatoryAvpSetVal;

		mTag = objPresenceReportingAreaInformation.mTag;

		mDecodeFlag = objPresenceReportingAreaInformation.mDecodeFlag;

		if(objPresenceReportingAreaInformation.mPresenceReportingAreaIdentifier != NULL)
		mPresenceReportingAreaIdentifier = new OctetString(*(objPresenceReportingAreaInformation.mPresenceReportingAreaIdentifier));

		if(objPresenceReportingAreaInformation.mPresenceReportingAreaStatus != NULL)
		mPresenceReportingAreaStatus = new Unsigned32(*(objPresenceReportingAreaInformation.mPresenceReportingAreaStatus));

		if(objPresenceReportingAreaInformation.mPresenceReportingAreaElementsList != NULL)
		mPresenceReportingAreaElementsList = new OctetString(*(objPresenceReportingAreaInformation.mPresenceReportingAreaElementsList));

		if(objPresenceReportingAreaInformation.mPresenceReportingAreaNode != NULL)
		mPresenceReportingAreaNode = new Unsigned32(*(objPresenceReportingAreaInformation.mPresenceReportingAreaNode));

		}

		virtual ~PresenceReportingAreaInformation();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PresenceReportingAreaIdentifier for datatype PresenceReportingAreaInformation
		*/
		OctetString* setPresenceReportingAreaIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PresenceReportingAreaIdentifier for datatype PresenceReportingAreaInformation
		*/
		void resetPresenceReportingAreaIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument PresenceReportingAreaIdentifier for datatype PresenceReportingAreaInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPresenceReportingAreaIdentifier();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument PresenceReportingAreaStatus for datatype PresenceReportingAreaInformation
		*/
		Unsigned32* setPresenceReportingAreaStatus();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PresenceReportingAreaStatus for datatype PresenceReportingAreaInformation
		*/
		void resetPresenceReportingAreaStatus();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument PresenceReportingAreaStatus for datatype PresenceReportingAreaInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getPresenceReportingAreaStatus();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PresenceReportingAreaElementsList for datatype PresenceReportingAreaInformation
		*/
		OctetString* setPresenceReportingAreaElementsList();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PresenceReportingAreaElementsList for datatype PresenceReportingAreaInformation
		*/
		void resetPresenceReportingAreaElementsList();

		//!Function to get values
		/*!		Function to get OctetString type of argument PresenceReportingAreaElementsList for datatype PresenceReportingAreaInformation
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPresenceReportingAreaElementsList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument PresenceReportingAreaNode for datatype PresenceReportingAreaInformation
		*/
		Unsigned32* setPresenceReportingAreaNode();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PresenceReportingAreaNode for datatype PresenceReportingAreaInformation
		*/
		void resetPresenceReportingAreaNode();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument PresenceReportingAreaNode for datatype PresenceReportingAreaInformation
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getPresenceReportingAreaNode();

		//! Function to Decode
		/*!		Function to Decode datatype PresenceReportingAreaInformation
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype PresenceReportingAreaInformation
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype PresenceReportingAreaInformation
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype PresenceReportingAreaInformation
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype PresenceReportingAreaInformation
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
