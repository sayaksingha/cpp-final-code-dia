#ifndef SLH_ADDITIONALSERVINGNODE_H
#define SLH_ADDITIONALSERVINGNODE_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SLH{
typedef enum _tags_AdditionalServingNode
{
	AdditionalServingNode_SGSNNUMBER	= 0,
	AdditionalServingNode_SGSNNAME	= 1,
	AdditionalServingNode_SGSNREALM	= 2,
	AdditionalServingNode_MMENAME	= 3,
	AdditionalServingNode_MMEREALM	= 4,
	AdditionalServingNode_MSCNUMBER	= 5,
	AdditionalServingNode_3GPPAAASERVERNAME	= 6,
	AdditionalServingNode_LCSCAPABILITIESSETS	= 7,
	AdditionalServingNode_GMLCADDRESS	= 8,
}AdditionalServingNode_tags;

		//! Class Definition
		/*!		ClassName is AdditionalServingNode
		*/
class AdditionalServingNode : public DiameterBaseInterface
{
	private:

		bitset<9> mTagsPresent;

		bitset<9> mMandatoryAvpCheckVal;

		bitset<9> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		OctetString*		mSGSNNumber;

		OctetString*		mSGSNName;

		OctetString*		mSGSNRealm;

		OctetString*		mMMEName;

		OctetString*		mMMERealm;

		OctetString*		mMSCNumber;

		OctetString*		m3GPPAAAServerName;

		Unsigned32*		mLCSCapabilitiesSets;

		list<Address*>* 		mGMLCAddressList;

		list<Address*>::iterator 		mGMLCAddressIterator;











	public:
		AdditionalServingNode();

		AdditionalServingNode(const AdditionalServingNode &objAdditionalServingNode) {

		mTagsPresent = objAdditionalServingNode.mTagsPresent;

		mMandatoryAvpCheckVal = objAdditionalServingNode.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAdditionalServingNode.mMandatoryAvpSetVal;

		mTag = objAdditionalServingNode.mTag;

		mDecodeFlag = objAdditionalServingNode.mDecodeFlag;

		if(objAdditionalServingNode.mSGSNNumber != NULL)
		mSGSNNumber = new OctetString(*(objAdditionalServingNode.mSGSNNumber));

		if(objAdditionalServingNode.mSGSNName != NULL)
		mSGSNName = new OctetString(*(objAdditionalServingNode.mSGSNName));

		if(objAdditionalServingNode.mSGSNRealm != NULL)
		mSGSNRealm = new OctetString(*(objAdditionalServingNode.mSGSNRealm));

		if(objAdditionalServingNode.mMMEName != NULL)
		mMMEName = new OctetString(*(objAdditionalServingNode.mMMEName));

		if(objAdditionalServingNode.mMMERealm != NULL)
		mMMERealm = new OctetString(*(objAdditionalServingNode.mMMERealm));

		if(objAdditionalServingNode.mMSCNumber != NULL)
		mMSCNumber = new OctetString(*(objAdditionalServingNode.mMSCNumber));

		if(objAdditionalServingNode.m3GPPAAAServerName != NULL)
		m3GPPAAAServerName = new OctetString(*(objAdditionalServingNode.m3GPPAAAServerName));

		if(objAdditionalServingNode.mLCSCapabilitiesSets != NULL)
		mLCSCapabilitiesSets = new Unsigned32(*(objAdditionalServingNode.mLCSCapabilitiesSets));

		}

		void operator = (const AdditionalServingNode &objAdditionalServingNode) {

		mTagsPresent = objAdditionalServingNode.mTagsPresent;

		mMandatoryAvpCheckVal = objAdditionalServingNode.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAdditionalServingNode.mMandatoryAvpSetVal;

		mTag = objAdditionalServingNode.mTag;

		mDecodeFlag = objAdditionalServingNode.mDecodeFlag;

		if(objAdditionalServingNode.mSGSNNumber != NULL)
		mSGSNNumber = new OctetString(*(objAdditionalServingNode.mSGSNNumber));

		if(objAdditionalServingNode.mSGSNName != NULL)
		mSGSNName = new OctetString(*(objAdditionalServingNode.mSGSNName));

		if(objAdditionalServingNode.mSGSNRealm != NULL)
		mSGSNRealm = new OctetString(*(objAdditionalServingNode.mSGSNRealm));

		if(objAdditionalServingNode.mMMEName != NULL)
		mMMEName = new OctetString(*(objAdditionalServingNode.mMMEName));

		if(objAdditionalServingNode.mMMERealm != NULL)
		mMMERealm = new OctetString(*(objAdditionalServingNode.mMMERealm));

		if(objAdditionalServingNode.mMSCNumber != NULL)
		mMSCNumber = new OctetString(*(objAdditionalServingNode.mMSCNumber));

		if(objAdditionalServingNode.m3GPPAAAServerName != NULL)
		m3GPPAAAServerName = new OctetString(*(objAdditionalServingNode.m3GPPAAAServerName));

		if(objAdditionalServingNode.mLCSCapabilitiesSets != NULL)
		mLCSCapabilitiesSets = new Unsigned32(*(objAdditionalServingNode.mLCSCapabilitiesSets));

		}

		virtual ~AdditionalServingNode();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SGSNNumber for datatype AdditionalServingNode
		*/
		OctetString* setSGSNNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SGSNNumber for datatype AdditionalServingNode
		*/
		void resetSGSNNumber();

		//!Function to get values
		/*!		Function to get OctetString type of argument SGSNNumber for datatype AdditionalServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSGSNNumber();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SGSNName for datatype AdditionalServingNode
		*/
		OctetString* setSGSNName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SGSNName for datatype AdditionalServingNode
		*/
		void resetSGSNName();

		//!Function to get values
		/*!		Function to get OctetString type of argument SGSNName for datatype AdditionalServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSGSNName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SGSNRealm for datatype AdditionalServingNode
		*/
		OctetString* setSGSNRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SGSNRealm for datatype AdditionalServingNode
		*/
		void resetSGSNRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument SGSNRealm for datatype AdditionalServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSGSNRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MMEName for datatype AdditionalServingNode
		*/
		OctetString* setMMEName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MMEName for datatype AdditionalServingNode
		*/
		void resetMMEName();

		//!Function to get values
		/*!		Function to get OctetString type of argument MMEName for datatype AdditionalServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMMEName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MMERealm for datatype AdditionalServingNode
		*/
		OctetString* setMMERealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MMERealm for datatype AdditionalServingNode
		*/
		void resetMMERealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument MMERealm for datatype AdditionalServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMMERealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MSCNumber for datatype AdditionalServingNode
		*/
		OctetString* setMSCNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MSCNumber for datatype AdditionalServingNode
		*/
		void resetMSCNumber();

		//!Function to get values
		/*!		Function to get OctetString type of argument MSCNumber for datatype AdditionalServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMSCNumber();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPAAAServerName for datatype AdditionalServingNode
		*/
		OctetString* set3GPPAAAServerName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPAAAServerName for datatype AdditionalServingNode
		*/
		void reset3GPPAAAServerName();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPAAAServerName for datatype AdditionalServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPAAAServerName();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument LCSCapabilitiesSets for datatype AdditionalServingNode
		*/
		Unsigned32* setLCSCapabilitiesSets();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LCSCapabilitiesSets for datatype AdditionalServingNode
		*/
		void resetLCSCapabilitiesSets();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument LCSCapabilitiesSets for datatype AdditionalServingNode
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getLCSCapabilitiesSets();

		list<Address*>* getGMLCAddressList();

		list<Address*>* setGMLCAddressList();

		void resetGMLCAddressList();

		//! Function to Decode
		/*!		Function to Decode datatype AdditionalServingNode
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype AdditionalServingNode
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype AdditionalServingNode
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype AdditionalServingNode
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AdditionalServingNode
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
