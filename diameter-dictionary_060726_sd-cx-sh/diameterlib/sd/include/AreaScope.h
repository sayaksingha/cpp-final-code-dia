#ifndef SD_AREASCOPE_H
#define SD_AREASCOPE_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace SD{
typedef enum _tags_AreaScope
{
	AreaScope_CELLGLOBALIDENTITY	= 0,
	AreaScope_ETUTRANCELLGLOBALIDENTITY	= 1,
	AreaScope_ROUTINGAREAIDENTITY	= 2,
	AreaScope_LOCATIONAREAIDENTITY	= 3,
	AreaScope_TRACKINGAREAIDENTITY	= 4,
}AreaScope_tags;

		//! Class Definition
		/*!		ClassName is AreaScope
		*/
class AreaScope : public DiameterBaseInterface
{
	private:

		bitset<5> mTagsPresent;

		bitset<5> mMandatoryAvpCheckVal;

		bitset<5> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		list<OctetString*>* 		mCellGlobalIdentityList;

		list<OctetString*>::iterator 		mCellGlobalIdentityIterator;

		list<OctetString*>* 		mETUTRANCellGlobalIdentityList;

		list<OctetString*>::iterator 		mETUTRANCellGlobalIdentityIterator;

		list<OctetString*>* 		mRoutingAreaIdentityList;

		list<OctetString*>::iterator 		mRoutingAreaIdentityIterator;

		list<OctetString*>* 		mLocationAreaIdentityList;

		list<OctetString*>::iterator 		mLocationAreaIdentityIterator;

		list<OctetString*>* 		mTrackingAreaIdentityList;

		list<OctetString*>::iterator 		mTrackingAreaIdentityIterator;







	public:
		AreaScope();

		AreaScope(const AreaScope &objAreaScope) {

		mTagsPresent = objAreaScope.mTagsPresent;

		mMandatoryAvpCheckVal = objAreaScope.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAreaScope.mMandatoryAvpSetVal;

		mTag = objAreaScope.mTag;

		mDecodeFlag = objAreaScope.mDecodeFlag;

		}

		void operator = (const AreaScope &objAreaScope) {

		mTagsPresent = objAreaScope.mTagsPresent;

		mMandatoryAvpCheckVal = objAreaScope.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAreaScope.mMandatoryAvpSetVal;

		mTag = objAreaScope.mTag;

		mDecodeFlag = objAreaScope.mDecodeFlag;

		}

		virtual ~AreaScope();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		list<OctetString*>* getCellGlobalIdentityList();

		list<OctetString*>* setCellGlobalIdentityList();

		void resetCellGlobalIdentityList();

		list<OctetString*>* getETUTRANCellGlobalIdentityList();

		list<OctetString*>* setETUTRANCellGlobalIdentityList();

		void resetETUTRANCellGlobalIdentityList();

		list<OctetString*>* getRoutingAreaIdentityList();

		list<OctetString*>* setRoutingAreaIdentityList();

		void resetRoutingAreaIdentityList();

		list<OctetString*>* getLocationAreaIdentityList();

		list<OctetString*>* setLocationAreaIdentityList();

		void resetLocationAreaIdentityList();

		list<OctetString*>* getTrackingAreaIdentityList();

		list<OctetString*>* setTrackingAreaIdentityList();

		void resetTrackingAreaIdentityList();

		//! Function to Decode
		/*!		Function to Decode datatype AreaScope
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype AreaScope
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype AreaScope
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype AreaScope
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AreaScope
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
