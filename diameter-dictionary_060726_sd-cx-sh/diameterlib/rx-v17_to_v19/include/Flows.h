#ifndef RX_FLOWS_H
#define RX_FLOWS_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

using namespace std;

namespace RX{
typedef enum _tags_Flows
{
	Flows_MEDIACOMPONENTNUMBER	= 0,
	Flows_FLOWNUMBER	= 1,
}Flows_tags;

		//! Class Definition
		/*!		ClassName is Flows
		*/
class Flows : public DiameterBaseInterface
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

		Unsigned32*		mMediaComponentNumber;

		list<Unsigned32*>* 		mFlowNumberList;

		list<Unsigned32*>::iterator 		mFlowNumberIterator;




	public:
		Flows();

		Flows(const Flows &objFlows) {

		mTagsPresent = objFlows.mTagsPresent;

		mMandatoryAvpCheckVal = objFlows.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFlows.mMandatoryAvpSetVal;

		mTag = objFlows.mTag;

		mDecodeFlag = objFlows.mDecodeFlag;

		if(objFlows.mMediaComponentNumber != NULL)
		mMediaComponentNumber = new Unsigned32(*(objFlows.mMediaComponentNumber));

		}

		void operator = (const Flows &objFlows) {

		mTagsPresent = objFlows.mTagsPresent;

		mMandatoryAvpCheckVal = objFlows.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objFlows.mMandatoryAvpSetVal;

		mTag = objFlows.mTag;

		mDecodeFlag = objFlows.mDecodeFlag;

		if(objFlows.mMediaComponentNumber != NULL)
		mMediaComponentNumber = new Unsigned32(*(objFlows.mMediaComponentNumber));

		}

		virtual ~Flows();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MediaComponentNumber for datatype Flows
		*/
		Unsigned32* setMediaComponentNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MediaComponentNumber for datatype Flows
		*/
		void resetMediaComponentNumber();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MediaComponentNumber for datatype Flows
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMediaComponentNumber();

		list<Unsigned32*>* getFlowNumberList();

		list<Unsigned32*>* setFlowNumberList();

		void resetFlowNumberList();

		//! Function to Decode
		/*!		Function to Decode datatype Flows
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype Flows
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype Flows
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype Flows
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype Flows
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
