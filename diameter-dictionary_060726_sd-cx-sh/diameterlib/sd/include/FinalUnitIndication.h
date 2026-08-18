#ifndef SD_FINALUNITINDICATION_H
#define SD_FINALUNITINDICATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/FinalUnitAction.h"
#include "sd/include/RedirectServer.h"
using namespace std;

namespace SD{
typedef enum _tags_FinalUnitIndication
{
	FinalUnitIndication_FINALUNITACTION	= 0,
	FinalUnitIndication_RESTRICTIONFILTERRULE	= 1,
	FinalUnitIndication_FILTERID	= 2,
	FinalUnitIndication_REDIRECTSERVER	= 3,
}FinalUnitIndication_tags;

		//! Class Definition
		/*!		ClassName is FinalUnitIndication
		*/
class FinalUnitIndication : public DiameterBaseInterface
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

		FinalUnitAction*		mFinalUnitAction;

		list<OctetString*>* 		mRestrictionFilterRuleList;

		list<OctetString*>::iterator 		mRestrictionFilterRuleIterator;

		list<OctetString*>* 		mFilterIdList;

		list<OctetString*>::iterator 		mFilterIdIterator;





		RedirectServer*	mRedirectServerGrp;

	public:
		FinalUnitIndication();

		FinalUnitIndication(const FinalUnitIndication &objFinalUnitIndication) {

		mTagsPresent = objFinalUnitIndication.mTagsPresent;

		mMandatoryAvpCheckVal = objFinalUnitIndication.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFinalUnitIndication.mMandatoryAvpSetVal;

		mTag = objFinalUnitIndication.mTag;

		mDecodeFlag = objFinalUnitIndication.mDecodeFlag;

		if(objFinalUnitIndication.mFinalUnitAction != NULL)
		mFinalUnitAction = new FinalUnitAction(*(objFinalUnitIndication.mFinalUnitAction));

		if(objFinalUnitIndication.mRedirectServerGrp != NULL)
		 {
				 mRedirectServerGrp =  new RedirectServer(*objFinalUnitIndication.mRedirectServerGrp);
		 }
		}

		void operator = (const FinalUnitIndication &objFinalUnitIndication) {

		mTagsPresent = objFinalUnitIndication.mTagsPresent;

		mMandatoryAvpCheckVal = objFinalUnitIndication.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFinalUnitIndication.mMandatoryAvpSetVal;

		mTag = objFinalUnitIndication.mTag;

		mDecodeFlag = objFinalUnitIndication.mDecodeFlag;

		if(objFinalUnitIndication.mFinalUnitAction != NULL)
		mFinalUnitAction = new FinalUnitAction(*(objFinalUnitIndication.mFinalUnitAction));

		if(objFinalUnitIndication.mRedirectServerGrp != NULL)
		 {
				 mRedirectServerGrp =  new RedirectServer(*objFinalUnitIndication.mRedirectServerGrp);
		 }
		}

		virtual ~FinalUnitIndication();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument FinalUnitAction for datatype FinalUnitIndication
		*/
		FinalUnitAction* setFinalUnitAction();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FinalUnitAction for datatype FinalUnitIndication
		*/
		void resetFinalUnitAction();

		//!Function to get values
		/*!		Function to get FinalUnitAction type of argument FinalUnitAction for datatype FinalUnitIndication
		Throws exception of which type and Summary of Exception
		*/
		FinalUnitAction* getFinalUnitAction();

		list<OctetString*>* getRestrictionFilterRuleList();

		list<OctetString*>* setRestrictionFilterRuleList();

		void resetRestrictionFilterRuleList();

		list<OctetString*>* getFilterIdList();

		list<OctetString*>* setFilterIdList();

		void resetFilterIdList();

		RedirectServer* getRedirectServer();

		RedirectServer* setRedirectServer();

		void resetRedirectServer();

		//! Function to Decode
		/*!		Function to Decode datatype FinalUnitIndication
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype FinalUnitIndication
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype FinalUnitIndication
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype FinalUnitIndication
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype FinalUnitIndication
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
