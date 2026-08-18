#ifndef SD_CONDITIONALAPNAGGREGATEMAXBITRATE_H
#define SD_CONDITIONALAPNAGGREGATEMAXBITRATE_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/IPCANType.h"
#include "sd/include/RATType.h"
using namespace std;

namespace SD{
typedef enum _tags_ConditionalAPNAggregateMaxBitrate
{
	ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEUL	= 0,
	ConditionalAPNAggregateMaxBitrate_APNAGGREGATEMAXBITRATEDL	= 1,
	ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRUL	= 2,
	ConditionalAPNAggregateMaxBitrate_EXTENDEDAPNAMBRDL	= 3,
	ConditionalAPNAggregateMaxBitrate_IPCANTYPE	= 4,
	ConditionalAPNAggregateMaxBitrate_RATTYPE	= 5,
}ConditionalAPNAggregateMaxBitrate_tags;

		//! Class Definition
		/*!		ClassName is ConditionalAPNAggregateMaxBitrate
		*/
class ConditionalAPNAggregateMaxBitrate : public DiameterBaseInterface
{
	private:

		bitset<6> mTagsPresent;

		bitset<6> mMandatoryAvpCheckVal;

		bitset<6> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		Unsigned32*		mAPNAggregateMaxBitrateUL;

		Unsigned32*		mAPNAggregateMaxBitrateDL;

		Unsigned32*		mExtendedAPNAMBRUL;

		Unsigned32*		mExtendedAPNAMBRDL;

		list<IPCANType*>* 		mIPCANTypeList;

		list<IPCANType*>::iterator 		mIPCANTypeIterator;

		list<RATType*>* 		mRATTypeList;

		list<RATType*>::iterator 		mRATTypeIterator;








	public:
		ConditionalAPNAggregateMaxBitrate();

		ConditionalAPNAggregateMaxBitrate(const ConditionalAPNAggregateMaxBitrate &objConditionalAPNAggregateMaxBitrate) {

		mTagsPresent = objConditionalAPNAggregateMaxBitrate.mTagsPresent;

		mMandatoryAvpCheckVal = objConditionalAPNAggregateMaxBitrate.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objConditionalAPNAggregateMaxBitrate.mMandatoryAvpSetVal;

		mTag = objConditionalAPNAggregateMaxBitrate.mTag;

		mDecodeFlag = objConditionalAPNAggregateMaxBitrate.mDecodeFlag;

		if(objConditionalAPNAggregateMaxBitrate.mAPNAggregateMaxBitrateUL != NULL)
		mAPNAggregateMaxBitrateUL = new Unsigned32(*(objConditionalAPNAggregateMaxBitrate.mAPNAggregateMaxBitrateUL));

		if(objConditionalAPNAggregateMaxBitrate.mAPNAggregateMaxBitrateDL != NULL)
		mAPNAggregateMaxBitrateDL = new Unsigned32(*(objConditionalAPNAggregateMaxBitrate.mAPNAggregateMaxBitrateDL));

		if(objConditionalAPNAggregateMaxBitrate.mExtendedAPNAMBRUL != NULL)
		mExtendedAPNAMBRUL = new Unsigned32(*(objConditionalAPNAggregateMaxBitrate.mExtendedAPNAMBRUL));

		if(objConditionalAPNAggregateMaxBitrate.mExtendedAPNAMBRDL != NULL)
		mExtendedAPNAMBRDL = new Unsigned32(*(objConditionalAPNAggregateMaxBitrate.mExtendedAPNAMBRDL));

		}

		void operator = (const ConditionalAPNAggregateMaxBitrate &objConditionalAPNAggregateMaxBitrate) {

		mTagsPresent = objConditionalAPNAggregateMaxBitrate.mTagsPresent;

		mMandatoryAvpCheckVal = objConditionalAPNAggregateMaxBitrate.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objConditionalAPNAggregateMaxBitrate.mMandatoryAvpSetVal;

		mTag = objConditionalAPNAggregateMaxBitrate.mTag;

		mDecodeFlag = objConditionalAPNAggregateMaxBitrate.mDecodeFlag;

		if(objConditionalAPNAggregateMaxBitrate.mAPNAggregateMaxBitrateUL != NULL)
		mAPNAggregateMaxBitrateUL = new Unsigned32(*(objConditionalAPNAggregateMaxBitrate.mAPNAggregateMaxBitrateUL));

		if(objConditionalAPNAggregateMaxBitrate.mAPNAggregateMaxBitrateDL != NULL)
		mAPNAggregateMaxBitrateDL = new Unsigned32(*(objConditionalAPNAggregateMaxBitrate.mAPNAggregateMaxBitrateDL));

		if(objConditionalAPNAggregateMaxBitrate.mExtendedAPNAMBRUL != NULL)
		mExtendedAPNAMBRUL = new Unsigned32(*(objConditionalAPNAggregateMaxBitrate.mExtendedAPNAMBRUL));

		if(objConditionalAPNAggregateMaxBitrate.mExtendedAPNAMBRDL != NULL)
		mExtendedAPNAMBRDL = new Unsigned32(*(objConditionalAPNAggregateMaxBitrate.mExtendedAPNAMBRDL));

		}

		virtual ~ConditionalAPNAggregateMaxBitrate();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument APNAggregateMaxBitrateUL for datatype ConditionalAPNAggregateMaxBitrate
		*/
		Unsigned32* setAPNAggregateMaxBitrateUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument APNAggregateMaxBitrateUL for datatype ConditionalAPNAggregateMaxBitrate
		*/
		void resetAPNAggregateMaxBitrateUL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument APNAggregateMaxBitrateUL for datatype ConditionalAPNAggregateMaxBitrate
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getAPNAggregateMaxBitrateUL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument APNAggregateMaxBitrateDL for datatype ConditionalAPNAggregateMaxBitrate
		*/
		Unsigned32* setAPNAggregateMaxBitrateDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument APNAggregateMaxBitrateDL for datatype ConditionalAPNAggregateMaxBitrate
		*/
		void resetAPNAggregateMaxBitrateDL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument APNAggregateMaxBitrateDL for datatype ConditionalAPNAggregateMaxBitrate
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getAPNAggregateMaxBitrateDL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ExtendedAPNAMBRUL for datatype ConditionalAPNAggregateMaxBitrate
		*/
		Unsigned32* setExtendedAPNAMBRUL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExtendedAPNAMBRUL for datatype ConditionalAPNAggregateMaxBitrate
		*/
		void resetExtendedAPNAMBRUL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ExtendedAPNAMBRUL for datatype ConditionalAPNAggregateMaxBitrate
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getExtendedAPNAMBRUL();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument ExtendedAPNAMBRDL for datatype ConditionalAPNAggregateMaxBitrate
		*/
		Unsigned32* setExtendedAPNAMBRDL();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ExtendedAPNAMBRDL for datatype ConditionalAPNAggregateMaxBitrate
		*/
		void resetExtendedAPNAMBRDL();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument ExtendedAPNAMBRDL for datatype ConditionalAPNAggregateMaxBitrate
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getExtendedAPNAMBRDL();

		list<IPCANType*>* getIPCANTypeList();

		list<IPCANType*>* setIPCANTypeList();

		void resetIPCANTypeList();

		list<RATType*>* getRATTypeList();

		list<RATType*>* setRATTypeList();

		void resetRATTypeList();

		//! Function to Decode
		/*!		Function to Decode datatype ConditionalAPNAggregateMaxBitrate
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype ConditionalAPNAggregateMaxBitrate
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype ConditionalAPNAggregateMaxBitrate
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype ConditionalAPNAggregateMaxBitrate
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype ConditionalAPNAggregateMaxBitrate
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
