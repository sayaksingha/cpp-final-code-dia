#ifndef RX_MEDIACOMPONENTDESCRIPTION_H
#define RX_MEDIACOMPONENTDESCRIPTION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "rx/include/MediaSubComponent.h"
#include "rx/include/MediaType.h"
#include "rx/include/FlowStatus.h"
#include "rx/include/ReservationPriority.h"
using namespace std;

namespace RX{
typedef enum _tags_MediaComponentDescription
{
	MediaComponentDescription_MEDIACOMPONENTNUMBER	= 0,
	MediaComponentDescription_MEDIASUBCOMPONENT	= 1,
	MediaComponentDescription_AFAPPLICATIONIDENTIFIER	= 2,
	MediaComponentDescription_MEDIATYPE	= 3,
	MediaComponentDescription_MAXREQUESTEDBANDWIDTHUL	= 4,
	MediaComponentDescription_MAXREQUESTEDBANDWIDTHDL	= 5,
	MediaComponentDescription_FLOWSTATUS	= 6,
	MediaComponentDescription_RESERVATIONPRIORITY	= 7,
	MediaComponentDescription_RSBANDWIDTH	= 8,
	MediaComponentDescription_RRBANDWIDTH	= 9,
	MediaComponentDescription_CODECDATA	= 10,
}MediaComponentDescription_tags;

		//! Class Definition
		/*!		ClassName is MediaComponentDescription
		*/
class MediaComponentDescription : public DiameterBaseInterface
{
	private:

		bitset<11> mTagsPresent;

		bitset<11> mMandatoryAvpCheckVal;

		bitset<11> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		Unsigned32*		mMediaComponentNumber;

		OctetString*		mAFApplicationIdentifier;

		MediaType*		mMediaType;

		Unsigned32*		mMaxRequestedBandwidthUL;

		Unsigned32*		mMaxRequestedBandwidthDL;

		FlowStatus*		mFlowStatus;

		ReservationPriority*		mReservationPriority;

		Unsigned32*		mRSBandwidth;

		Unsigned32*		mRRBandwidth;

		list<OctetString*>* 		mCodecDataList;

		list<OctetString*>::iterator 		mCodecDataIterator;



		list<MediaSubComponent*>*	mMediaSubComponentGrpList;
		list<MediaSubComponent*>::iterator	mMediaSubComponentGrpIterator;










	public:
		MediaComponentDescription();

		MediaComponentDescription(const MediaComponentDescription &objMediaComponentDescription) {

		mTagsPresent = objMediaComponentDescription.mTagsPresent;

		mMandatoryAvpCheckVal = objMediaComponentDescription.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMediaComponentDescription.mMandatoryAvpSetVal;

		mTag = objMediaComponentDescription.mTag;

		mDecodeFlag = objMediaComponentDescription.mDecodeFlag;

		if(objMediaComponentDescription.mMediaComponentNumber != NULL)
		mMediaComponentNumber = new Unsigned32(*(objMediaComponentDescription.mMediaComponentNumber));

		if(objMediaComponentDescription.mMediaSubComponentGrpList != NULL)
		 {
		 mMediaSubComponentGrpList = new list<MediaSubComponent*>;
		 for( auto element : *objMediaComponentDescription.mMediaSubComponentGrpList)
		 {
				 MediaSubComponent *lMediaSubComponent =  new MediaSubComponent(*element);
				 mMediaSubComponentGrpList->push_back(lMediaSubComponent);
		 }
		 }
		if(objMediaComponentDescription.mAFApplicationIdentifier != NULL)
		mAFApplicationIdentifier = new OctetString(*(objMediaComponentDescription.mAFApplicationIdentifier));

		if(objMediaComponentDescription.mMediaType != NULL)
		mMediaType = new MediaType(*(objMediaComponentDescription.mMediaType));

		if(objMediaComponentDescription.mMaxRequestedBandwidthUL != NULL)
		mMaxRequestedBandwidthUL = new Unsigned32(*(objMediaComponentDescription.mMaxRequestedBandwidthUL));

		if(objMediaComponentDescription.mMaxRequestedBandwidthDL != NULL)
		mMaxRequestedBandwidthDL = new Unsigned32(*(objMediaComponentDescription.mMaxRequestedBandwidthDL));

		if(objMediaComponentDescription.mFlowStatus != NULL)
		mFlowStatus = new FlowStatus(*(objMediaComponentDescription.mFlowStatus));

		if(objMediaComponentDescription.mReservationPriority != NULL)
		mReservationPriority = new ReservationPriority(*(objMediaComponentDescription.mReservationPriority));

		if(objMediaComponentDescription.mRSBandwidth != NULL)
		mRSBandwidth = new Unsigned32(*(objMediaComponentDescription.mRSBandwidth));

		if(objMediaComponentDescription.mRRBandwidth != NULL)
		mRRBandwidth = new Unsigned32(*(objMediaComponentDescription.mRRBandwidth));

		}

		void operator = (const MediaComponentDescription &objMediaComponentDescription) {

		mTagsPresent = objMediaComponentDescription.mTagsPresent;

		mMandatoryAvpCheckVal = objMediaComponentDescription.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objMediaComponentDescription.mMandatoryAvpSetVal;

		mTag = objMediaComponentDescription.mTag;

		mDecodeFlag = objMediaComponentDescription.mDecodeFlag;

		if(objMediaComponentDescription.mMediaComponentNumber != NULL)
		mMediaComponentNumber = new Unsigned32(*(objMediaComponentDescription.mMediaComponentNumber));

		if(objMediaComponentDescription.mMediaSubComponentGrpList != NULL)
		 {
		 mMediaSubComponentGrpList = new list<MediaSubComponent*>;
		 for( auto element : *objMediaComponentDescription.mMediaSubComponentGrpList)
		 {
				 MediaSubComponent *lMediaSubComponent =  new MediaSubComponent(*element);
				 mMediaSubComponentGrpList->push_back(lMediaSubComponent);
		 }
		 }
		if(objMediaComponentDescription.mAFApplicationIdentifier != NULL)
		mAFApplicationIdentifier = new OctetString(*(objMediaComponentDescription.mAFApplicationIdentifier));

		if(objMediaComponentDescription.mMediaType != NULL)
		mMediaType = new MediaType(*(objMediaComponentDescription.mMediaType));

		if(objMediaComponentDescription.mMaxRequestedBandwidthUL != NULL)
		mMaxRequestedBandwidthUL = new Unsigned32(*(objMediaComponentDescription.mMaxRequestedBandwidthUL));

		if(objMediaComponentDescription.mMaxRequestedBandwidthDL != NULL)
		mMaxRequestedBandwidthDL = new Unsigned32(*(objMediaComponentDescription.mMaxRequestedBandwidthDL));

		if(objMediaComponentDescription.mFlowStatus != NULL)
		mFlowStatus = new FlowStatus(*(objMediaComponentDescription.mFlowStatus));

		if(objMediaComponentDescription.mReservationPriority != NULL)
		mReservationPriority = new ReservationPriority(*(objMediaComponentDescription.mReservationPriority));

		if(objMediaComponentDescription.mRSBandwidth != NULL)
		mRSBandwidth = new Unsigned32(*(objMediaComponentDescription.mRSBandwidth));

		if(objMediaComponentDescription.mRRBandwidth != NULL)
		mRRBandwidth = new Unsigned32(*(objMediaComponentDescription.mRRBandwidth));

		}

		virtual ~MediaComponentDescription();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MediaComponentNumber for datatype MediaComponentDescription
		*/
		Unsigned32* setMediaComponentNumber();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MediaComponentNumber for datatype MediaComponentDescription
		*/
		void resetMediaComponentNumber();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MediaComponentNumber for datatype MediaComponentDescription
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMediaComponentNumber();

		list<MediaSubComponent*>* getMediaSubComponentGrpList();

		list<MediaSubComponent*>* setMediaSubComponentGrpList();

		void resetMediaSubComponentGrpList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument AFApplicationIdentifier for datatype MediaComponentDescription
		*/
		OctetString* setAFApplicationIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument AFApplicationIdentifier for datatype MediaComponentDescription
		*/
		void resetAFApplicationIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument AFApplicationIdentifier for datatype MediaComponentDescription
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getAFApplicationIdentifier();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument MediaType for datatype MediaComponentDescription
		*/
		MediaType* setMediaType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MediaType for datatype MediaComponentDescription
		*/
		void resetMediaType();

		//!Function to get values
		/*!		Function to get MediaType type of argument MediaType for datatype MediaComponentDescription
		Throws exception of which type and Summary of Exception
		*/
		MediaType* getMediaType();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MaxRequestedBandwidthUL for datatype MediaComponentDescription
		*/
		Unsigned32* setMaxRequestedBandwidthUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MaxRequestedBandwidthUL for datatype MediaComponentDescription
		*/
		void resetMaxRequestedBandwidthUL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MaxRequestedBandwidthUL for datatype MediaComponentDescription
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMaxRequestedBandwidthUL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument MaxRequestedBandwidthDL for datatype MediaComponentDescription
		*/
		Unsigned32* setMaxRequestedBandwidthDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument MaxRequestedBandwidthDL for datatype MediaComponentDescription
		*/
		void resetMaxRequestedBandwidthDL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument MaxRequestedBandwidthDL for datatype MediaComponentDescription
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getMaxRequestedBandwidthDL();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument FlowStatus for datatype MediaComponentDescription
		*/
		FlowStatus* setFlowStatus();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FlowStatus for datatype MediaComponentDescription
		*/
		void resetFlowStatus();

		//!Function to get values
		/*!		Function to get FlowStatus type of argument FlowStatus for datatype MediaComponentDescription
		Throws exception of which type and Summary of Exception
		*/
		FlowStatus* getFlowStatus();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ReservationPriority for datatype MediaComponentDescription
		*/
		ReservationPriority* setReservationPriority();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ReservationPriority for datatype MediaComponentDescription
		*/
		void resetReservationPriority();

		//!Function to get values
		/*!		Function to get ReservationPriority type of argument ReservationPriority for datatype MediaComponentDescription
		Throws exception of which type and Summary of Exception
		*/
		ReservationPriority* getReservationPriority();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RSBandwidth for datatype MediaComponentDescription
		*/
		Unsigned32* setRSBandwidth();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RSBandwidth for datatype MediaComponentDescription
		*/
		void resetRSBandwidth();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RSBandwidth for datatype MediaComponentDescription
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRSBandwidth();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument RRBandwidth for datatype MediaComponentDescription
		*/
		Unsigned32* setRRBandwidth();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RRBandwidth for datatype MediaComponentDescription
		*/
		void resetRRBandwidth();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument RRBandwidth for datatype MediaComponentDescription
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getRRBandwidth();

		list<OctetString*>* getCodecDataList();

		list<OctetString*>* setCodecDataList();

		void resetCodecDataList();

		//! Function to Decode
		/*!		Function to Decode datatype MediaComponentDescription
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype MediaComponentDescription
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype MediaComponentDescription
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype MediaComponentDescription
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype MediaComponentDescription
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
