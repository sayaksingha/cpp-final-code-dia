#ifndef CX_ASSOCIATEDIDENTITIES_H
#define CX_ASSOCIATEDIDENTITIES_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace CX{
typedef enum _tags_AssociatedIdentities
{
	AssociatedIdentities_USERNAME	= 0,
}AssociatedIdentities_tags;

		//! Class Definition
		/*!		ClassName is AssociatedIdentities
		*/
class AssociatedIdentities : public DiameterBaseInterface
{
	private:

		bitset<1> mTagsPresent;

		bitset<1> mMandatoryAvpCheckVal;

		bitset<1> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		list<OctetString*>* 		mUserNameList;

		list<OctetString*>::iterator 		mUserNameIterator;



	public:
		AssociatedIdentities();

		AssociatedIdentities(const AssociatedIdentities &objAssociatedIdentities) {

		mTagsPresent = objAssociatedIdentities.mTagsPresent;

		mMandatoryAvpCheckVal = objAssociatedIdentities.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAssociatedIdentities.mMandatoryAvpSetVal;

		mTag = objAssociatedIdentities.mTag;

		mDecodeFlag = objAssociatedIdentities.mDecodeFlag;

		}

		void operator = (const AssociatedIdentities &objAssociatedIdentities) {

		mTagsPresent = objAssociatedIdentities.mTagsPresent;

		mMandatoryAvpCheckVal = objAssociatedIdentities.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAssociatedIdentities.mMandatoryAvpSetVal;

		mTag = objAssociatedIdentities.mTag;

		mDecodeFlag = objAssociatedIdentities.mDecodeFlag;

		}

		virtual ~AssociatedIdentities();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		list<OctetString*>* getUserNameList();

		list<OctetString*>* setUserNameList();

		void resetUserNameList();

		//! Function to Decode
		/*!		Function to Decode datatype AssociatedIdentities
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype AssociatedIdentities
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype AssociatedIdentities
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype AssociatedIdentities
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AssociatedIdentities
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
