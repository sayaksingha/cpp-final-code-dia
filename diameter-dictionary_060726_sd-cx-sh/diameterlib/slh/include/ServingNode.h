#ifndef SLH_SERVINGNODE_H
#define SLH_SERVINGNODE_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SLH{
typedef enum _tags_ServingNode
{
	ServingNode_SGSNNUMBER	= 0,
	ServingNode_SGSNNAME	= 1,
	ServingNode_SGSNREALM	= 2,
	ServingNode_MMENAME	= 3,
	ServingNode_MMEREALM	= 4,
	ServingNode_MSCNUMBER	= 5,
	ServingNode_3GPPAAASERVERNAME	= 6,
	ServingNode_LCSCAPABILITIESSETS	= 7,
	ServingNode_GMLCADDRESS	= 8,
}ServingNode_tags;

		//! Class Definition
		/*!		ClassName is ServingNode
		*/
class ServingNode : public DiameterBaseInterface
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

		list<OctetString*>* 		mGMLCAddressList;

		list<OctetString*>::iterator 		mGMLCAddressIterator;











	public:
		ServingNode();

		ServingNode(const ServingNode &objServingNode) {

		mTagsPresent = objServingNode.mTagsPresent;

		mMandatoryAvpCheckVal = objServingNode.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objServingNode.mMandatoryAvpSetVal;

		mTag = objServingNode.mTag;

		mDecodeFlag = objServingNode.mDecodeFlag;

		if(objServingNode.mSGSNNumber != NULL)
		mSGSNNumber = new OctetString(*(objServingNode.mSGSNNumber));

		if(objServingNode.mSGSNName != NULL)
		mSGSNName = new OctetString(*(objServingNode.mSGSNName));

		if(objServingNode.mSGSNRealm != NULL)
		mSGSNRealm = new OctetString(*(objServingNode.mSGSNRealm));

		if(objServingNode.mMMEName != NULL)
		mMMEName = new OctetString(*(objServingNode.mMMEName));

		if(objServingNode.mMMERealm != NULL)
		mMMERealm = new OctetString(*(objServingNode.mMMERealm));

		if(objServingNode.mMSCNumber != NULL)
		mMSCNumber = new OctetString(*(objServingNode.mMSCNumber));

		if(objServingNode.m3GPPAAAServerName != NULL)
		m3GPPAAAServerName = new OctetString(*(objServingNode.m3GPPAAAServerName));

		if(objServingNode.mLCSCapabilitiesSets != NULL)
		mLCSCapabilitiesSets = new Unsigned32(*(objServingNode.mLCSCapabilitiesSets));

		}

		void operator = (const ServingNode &objServingNode) {

		mTagsPresent = objServingNode.mTagsPresent;

		mMandatoryAvpCheckVal = objServingNode.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objServingNode.mMandatoryAvpSetVal;

		mTag = objServingNode.mTag;

		mDecodeFlag = objServingNode.mDecodeFlag;

		if(objServingNode.mSGSNNumber != NULL)
		mSGSNNumber = new OctetString(*(objServingNode.mSGSNNumber));

		if(objServingNode.mSGSNName != NULL)
		mSGSNName = new OctetString(*(objServingNode.mSGSNName));

		if(objServingNode.mSGSNRealm != NULL)
		mSGSNRealm = new OctetString(*(objServingNode.mSGSNRealm));

		if(objServingNode.mMMEName != NULL)
		mMMEName = new OctetString(*(objServingNode.mMMEName));

		if(objServingNode.mMMERealm != NULL)
		mMMERealm = new OctetString(*(objServingNode.mMMERealm));

		if(objServingNode.mMSCNumber != NULL)
		mMSCNumber = new OctetString(*(objServingNode.mMSCNumber));

		if(objServingNode.m3GPPAAAServerName != NULL)
		m3GPPAAAServerName = new OctetString(*(objServingNode.m3GPPAAAServerName));

		if(objServingNode.mLCSCapabilitiesSets != NULL)
		mLCSCapabilitiesSets = new Unsigned32(*(objServingNode.mLCSCapabilitiesSets));

		}

		virtual ~ServingNode();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SGSNNumber for datatype ServingNode
		*/
		OctetString* setSGSNNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SGSNNumber for datatype ServingNode
		*/
		void resetSGSNNumber();

		//!Function to get values
		/*!		Function to get OctetString type of argument SGSNNumber for datatype ServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSGSNNumber();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SGSNName for datatype ServingNode
		*/
		OctetString* setSGSNName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SGSNName for datatype ServingNode
		*/
		void resetSGSNName();

		//!Function to get values
		/*!		Function to get OctetString type of argument SGSNName for datatype ServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSGSNName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument SGSNRealm for datatype ServingNode
		*/
		OctetString* setSGSNRealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SGSNRealm for datatype ServingNode
		*/
		void resetSGSNRealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument SGSNRealm for datatype ServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getSGSNRealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MMEName for datatype ServingNode
		*/
		OctetString* setMMEName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MMEName for datatype ServingNode
		*/
		void resetMMEName();

		//!Function to get values
		/*!		Function to get OctetString type of argument MMEName for datatype ServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMMEName();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MMERealm for datatype ServingNode
		*/
		OctetString* setMMERealm();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MMERealm for datatype ServingNode
		*/
		void resetMMERealm();

		//!Function to get values
		/*!		Function to get OctetString type of argument MMERealm for datatype ServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMMERealm();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument MSCNumber for datatype ServingNode
		*/
		OctetString* setMSCNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MSCNumber for datatype ServingNode
		*/
		void resetMSCNumber();

		//!Function to get values
		/*!		Function to get OctetString type of argument MSCNumber for datatype ServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getMSCNumber();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPAAAServerName for datatype ServingNode
		*/
		OctetString* set3GPPAAAServerName();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPAAAServerName for datatype ServingNode
		*/
		void reset3GPPAAAServerName();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPAAAServerName for datatype ServingNode
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPAAAServerName();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument LCSCapabilitiesSets for datatype ServingNode
		*/
		Unsigned32* setLCSCapabilitiesSets();

		//! Function to reset 
		/*!		Function to reset NULL type of argument LCSCapabilitiesSets for datatype ServingNode
		*/
		void resetLCSCapabilitiesSets();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument LCSCapabilitiesSets for datatype ServingNode
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getLCSCapabilitiesSets();

		list<OctetString*>* getGMLCAddressList();

		list<OctetString*>* setGMLCAddressList();

		void resetGMLCAddressList();

		//! Function to Decode
		/*!		Function to Decode datatype ServingNode
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ServingNode
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ServingNode
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ServingNode
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ServingNode
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
