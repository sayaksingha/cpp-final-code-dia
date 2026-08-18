#ifndef CX_SERVERCAPABILITIES_H
#define CX_SERVERCAPABILITIES_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace CX{
typedef enum _tags_ServerCapabilities
{
	ServerCapabilities_MANDATORYCAPABILITY	= 0,
	ServerCapabilities_OPTIONALCAPABILITY	= 1,
	ServerCapabilities_SERVERNAME	= 2,
}ServerCapabilities_tags;

		//! Class Definition
		/*!		ClassName is ServerCapabilities
		*/
class ServerCapabilities : public DiameterBaseInterface
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

		list<Unsigned32*>* 		mMandatoryCapabilityList;

		list<Unsigned32*>::iterator 		mMandatoryCapabilityIterator;

		list<Unsigned32*>* 		mOptionalCapabilityList;

		list<Unsigned32*>::iterator 		mOptionalCapabilityIterator;

		list<OctetString*>* 		mServerNameList;

		list<OctetString*>::iterator 		mServerNameIterator;





	public:
		ServerCapabilities();

		ServerCapabilities(const ServerCapabilities &objServerCapabilities) {

		mTagsPresent = objServerCapabilities.mTagsPresent;

		mMandatoryAvpCheckVal = objServerCapabilities.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objServerCapabilities.mMandatoryAvpSetVal;

		mTag = objServerCapabilities.mTag;

		mDecodeFlag = objServerCapabilities.mDecodeFlag;

		}

		void operator = (const ServerCapabilities &objServerCapabilities) {

		mTagsPresent = objServerCapabilities.mTagsPresent;

		mMandatoryAvpCheckVal = objServerCapabilities.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objServerCapabilities.mMandatoryAvpSetVal;

		mTag = objServerCapabilities.mTag;

		mDecodeFlag = objServerCapabilities.mDecodeFlag;

		}

		virtual ~ServerCapabilities();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		list<Unsigned32*>* getMandatoryCapabilityList();

		list<Unsigned32*>* setMandatoryCapabilityList();

		void resetMandatoryCapabilityList();

		list<Unsigned32*>* getOptionalCapabilityList();

		list<Unsigned32*>* setOptionalCapabilityList();

		void resetOptionalCapabilityList();

		list<OctetString*>* getServerNameList();

		list<OctetString*>* setServerNameList();

		void resetServerNameList();

		//! Function to Decode
		/*!		Function to Decode datatype ServerCapabilities
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ServerCapabilities
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ServerCapabilities
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ServerCapabilities
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ServerCapabilities
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
