#ifndef CX_FAILEDPCSCF_H
#define CX_FAILEDPCSCF_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace CX{
typedef enum _tags_FailedPCSCF
{
	FailedPCSCF_PCSCFFQDN	= 0,
	FailedPCSCF_PCSCFIPADDRESS	= 1,
}FailedPCSCF_tags;

		//! Class Definition
		/*!		ClassName is FailedPCSCF
		*/
class FailedPCSCF : public DiameterBaseInterface
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

		OctetString*		mPCSCFFQDN;

		list<Address*>* 		mPCSCFIPAddressList;

		list<Address*>::iterator 		mPCSCFIPAddressIterator;




	public:
		FailedPCSCF();

		FailedPCSCF(const FailedPCSCF &objFailedPCSCF) {

		mTagsPresent = objFailedPCSCF.mTagsPresent;

		mMandatoryAvpCheckVal = objFailedPCSCF.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFailedPCSCF.mMandatoryAvpSetVal;

		mTag = objFailedPCSCF.mTag;

		mDecodeFlag = objFailedPCSCF.mDecodeFlag;

		if(objFailedPCSCF.mPCSCFFQDN != NULL)
		mPCSCFFQDN = new OctetString(*(objFailedPCSCF.mPCSCFFQDN));

		}

		void operator = (const FailedPCSCF &objFailedPCSCF) {

		mTagsPresent = objFailedPCSCF.mTagsPresent;

		mMandatoryAvpCheckVal = objFailedPCSCF.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFailedPCSCF.mMandatoryAvpSetVal;

		mTag = objFailedPCSCF.mTag;

		mDecodeFlag = objFailedPCSCF.mDecodeFlag;

		if(objFailedPCSCF.mPCSCFFQDN != NULL)
		mPCSCFFQDN = new OctetString(*(objFailedPCSCF.mPCSCFFQDN));

		}

		virtual ~FailedPCSCF();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument PCSCFFQDN for datatype FailedPCSCF
		*/
		OctetString* setPCSCFFQDN();

		//! Function to reset 
		/*!		Function to reset NULL type of argument PCSCFFQDN for datatype FailedPCSCF
		*/
		void resetPCSCFFQDN();

		//!Function to get values
		/*!		Function to get OctetString type of argument PCSCFFQDN for datatype FailedPCSCF
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getPCSCFFQDN();

		list<Address*>* getPCSCFIPAddressList();

		list<Address*>* setPCSCFIPAddressList();

		void resetPCSCFIPAddressList();

		//! Function to Decode
		/*!		Function to Decode datatype FailedPCSCF
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype FailedPCSCF
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype FailedPCSCF
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype FailedPCSCF
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype FailedPCSCF
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
