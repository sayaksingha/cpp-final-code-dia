#ifndef RX_ACCEPTABLESERVICEINFO_H
#define RX_ACCEPTABLESERVICEINFO_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "rx/include/MediaComponentDescription.h"
using namespace std;

namespace RX{
typedef enum _tags_AcceptableServiceInfo
{
	AcceptableServiceInfo_MEDIACOMPONENTDESCRIPTION	= 0,
	AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHUL	= 1,
	AcceptableServiceInfo_MAXREQUESTEDBANDWIDTHDL	= 2,
}AcceptableServiceInfo_tags;

		//! Class Definition
		/*!		ClassName is AcceptableServiceInfo
		*/
class AcceptableServiceInfo : public DiameterBaseInterface
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

		Unsigned32*		mMaxRequestedBandwidthUL;

		Unsigned32*		mMaxRequestedBandwidthDL;


		list<MediaComponentDescription*>*	mMediaComponentDescriptionGrpList;
		list<MediaComponentDescription*>::iterator	mMediaComponentDescriptionGrpIterator;



	public:
		AcceptableServiceInfo();

		AcceptableServiceInfo(const AcceptableServiceInfo &objAcceptableServiceInfo) {

		mTagsPresent = objAcceptableServiceInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objAcceptableServiceInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAcceptableServiceInfo.mMandatoryAvpSetVal;

		mTag = objAcceptableServiceInfo.mTag;

		mDecodeFlag = objAcceptableServiceInfo.mDecodeFlag;

		if(objAcceptableServiceInfo.mMediaComponentDescriptionGrpList != NULL)
		 {
		 mMediaComponentDescriptionGrpList = new list<MediaComponentDescription*>;
		 for( auto element : *objAcceptableServiceInfo.mMediaComponentDescriptionGrpList)
		 {
				 MediaComponentDescription *lMediaComponentDescription =  new MediaComponentDescription(*element);
				 mMediaComponentDescriptionGrpList->push_back(lMediaComponentDescription);
		 }
		 }
		if(objAcceptableServiceInfo.mMaxRequestedBandwidthUL != NULL)
		mMaxRequestedBandwidthUL = new Unsigned32(*(objAcceptableServiceInfo.mMaxRequestedBandwidthUL));

		if(objAcceptableServiceInfo.mMaxRequestedBandwidthDL != NULL)
		mMaxRequestedBandwidthDL = new Unsigned32(*(objAcceptableServiceInfo.mMaxRequestedBandwidthDL));

		}

		void operator = (const AcceptableServiceInfo &objAcceptableServiceInfo) {

		mTagsPresent = objAcceptableServiceInfo.mTagsPresent;

		mMandatoryAvpCheckVal = objAcceptableServiceInfo.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objAcceptableServiceInfo.mMandatoryAvpSetVal;

		mTag = objAcceptableServiceInfo.mTag;

		mDecodeFlag = objAcceptableServiceInfo.mDecodeFlag;

		if(objAcceptableServiceInfo.mMediaComponentDescriptionGrpList != NULL)
		 {
		 mMediaComponentDescriptionGrpList = new list<MediaComponentDescription*>;
		 for( auto element : *objAcceptableServiceInfo.mMediaComponentDescriptionGrpList)
		 {
				 MediaComponentDescription *lMediaComponentDescription =  new MediaComponentDescription(*element);
				 mMediaComponentDescriptionGrpList->push_back(lMediaComponentDescription);
		 }
		 }
		if(objAcceptableServiceInfo.mMaxRequestedBandwidthUL != NULL)
		mMaxRequestedBandwidthUL = new Unsigned32(*(objAcceptableServiceInfo.mMaxRequestedBandwidthUL));

		if(objAcceptableServiceInfo.mMaxRequestedBandwidthDL != NULL)
		mMaxRequestedBandwidthDL = new Unsigned32(*(objAcceptableServiceInfo.mMaxRequestedBandwidthDL));

		}

		virtual ~AcceptableServiceInfo();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		list<MediaComponentDescription*>* getMediaComponentDescriptionGrpList();

		list<MediaComponentDescription*>* setMediaComponentDescriptionGrpList();

		void resetMediaComponentDescriptionGrpList();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MaxRequestedBandwidthUL for datatype AcceptableServiceInfo
		*/
		Unsigned32* setMaxRequestedBandwidthUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MaxRequestedBandwidthUL for datatype AcceptableServiceInfo
		*/
		void resetMaxRequestedBandwidthUL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MaxRequestedBandwidthUL for datatype AcceptableServiceInfo
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMaxRequestedBandwidthUL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MaxRequestedBandwidthDL for datatype AcceptableServiceInfo
		*/
		Unsigned32* setMaxRequestedBandwidthDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MaxRequestedBandwidthDL for datatype AcceptableServiceInfo
		*/
		void resetMaxRequestedBandwidthDL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MaxRequestedBandwidthDL for datatype AcceptableServiceInfo
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMaxRequestedBandwidthDL();

		//! Function to Decode
		/*!		Function to Decode datatype AcceptableServiceInfo
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype AcceptableServiceInfo
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype AcceptableServiceInfo
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype AcceptableServiceInfo
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype AcceptableServiceInfo
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
