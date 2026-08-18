#ifndef SH_REPOSITORYDATAID_H
#define SH_REPOSITORYDATAID_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SH{
typedef enum _tags_RepositoryDataID
{
	RepositoryDataID_SERVICEINDICATION	= 0,
	RepositoryDataID_SEQUENCENUMBER	= 1,
}RepositoryDataID_tags;

		//! Class Definition
		/*!		ClassName is RepositoryDataID
		*/
class RepositoryDataID : public DiameterBaseInterface
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

		OctetString*		mServiceIndication;

		Unsigned32*		mSequenceNumber;




	public:
		RepositoryDataID();

		RepositoryDataID(const RepositoryDataID &objRepositoryDataID) {

		mTagsPresent = objRepositoryDataID.mTagsPresent;

		mMandatoryAvpCheckVal = objRepositoryDataID.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRepositoryDataID.mMandatoryAvpSetVal;

		mTag = objRepositoryDataID.mTag;

		mDecodeFlag = objRepositoryDataID.mDecodeFlag;

		if(objRepositoryDataID.mServiceIndication != NULL)
		mServiceIndication = new OctetString(*(objRepositoryDataID.mServiceIndication));

		if(objRepositoryDataID.mSequenceNumber != NULL)
		mSequenceNumber = new Unsigned32(*(objRepositoryDataID.mSequenceNumber));

		}

		void operator = (const RepositoryDataID &objRepositoryDataID) {

		mTagsPresent = objRepositoryDataID.mTagsPresent;

		mMandatoryAvpCheckVal = objRepositoryDataID.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objRepositoryDataID.mMandatoryAvpSetVal;

		mTag = objRepositoryDataID.mTag;

		mDecodeFlag = objRepositoryDataID.mDecodeFlag;

		if(objRepositoryDataID.mServiceIndication != NULL)
		mServiceIndication = new OctetString(*(objRepositoryDataID.mServiceIndication));

		if(objRepositoryDataID.mSequenceNumber != NULL)
		mSequenceNumber = new Unsigned32(*(objRepositoryDataID.mSequenceNumber));

		}

		virtual ~RepositoryDataID();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument ServiceIndication for datatype RepositoryDataID
		*/
		OctetString* setServiceIndication();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ServiceIndication for datatype RepositoryDataID
		*/
		void resetServiceIndication();

		//!Function to get values
		/*!		Function to get OctetString type of argument ServiceIndication for datatype RepositoryDataID
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getServiceIndication();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument SequenceNumber for datatype RepositoryDataID
		*/
		Unsigned32* setSequenceNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument SequenceNumber for datatype RepositoryDataID
		*/
		void resetSequenceNumber();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument SequenceNumber for datatype RepositoryDataID
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getSequenceNumber();

		//! Function to Decode
		/*!		Function to Decode datatype RepositoryDataID
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype RepositoryDataID
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype RepositoryDataID
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype RepositoryDataID
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype RepositoryDataID
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
