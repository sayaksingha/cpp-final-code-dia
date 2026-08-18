#ifndef SD_EVENTREPORTINDICATION_H
#define SD_EVENTREPORTINDICATION_H
#include "DiameterTLVUtil.h"

#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"

#include "TssDiameterMsgException.h"

#include "DiameterDataTypes.h"

#include "sd/include/ANTrusted.h"
#include "sd/include/EventTrigger.h"
#include "sd/include/UserCSGInformation.h"
#include "sd/include/IPCANType.h"
#include "sd/include/RATType.h"
#include "sd/include/TraceData.h"
#include "sd/include/PresenceReportingAreaInformation.h"
using namespace std;

namespace SD{
typedef enum _tags_EventReportIndication
{
	EventReportIndication_ANTRUSTED	= 0,
	EventReportIndication_EVENTTRIGGER	= 1,
	EventReportIndication_USERCSGINFORMATION	= 2,
	EventReportIndication_IPCANTYPE	= 3,
	EventReportIndication_ANGWADDRESS	= 4,
	EventReportIndication_3GPPSGSNADDRESS	= 5,
	EventReportIndication_3GPPSGSNIPV6ADDRESS	= 6,
	EventReportIndication_3GPPSGSNMCCMNC	= 7,
	EventReportIndication_FRAMEDIPADDRESS	= 8,
	EventReportIndication_RATTYPE	= 9,
	EventReportIndication_RAI	= 10,
	EventReportIndication_3GPPUSERLOCATIONINFO	= 11,
	EventReportIndication_TRACEDATA	= 12,
	EventReportIndication_TRACEREFERENCE	= 13,
	EventReportIndication_3GPP2BSID	= 14,
	EventReportIndication_3GPPMSTIMEZONE	= 15,
	EventReportIndication_ROUTINGRULEIDENTIFIER	= 16,
	EventReportIndication_UELOCALIPADDRESS	= 17,
	EventReportIndication_HENBLOCALIPADDRESS	= 18,
	EventReportIndication_UDPSOURCEPORT	= 19,
	EventReportIndication_PRESENCEREPORTINGAREAINFORMATION	= 20,
}EventReportIndication_tags;

		//! Class Definition
		/*!		ClassName is EventReportIndication
		*/
class EventReportIndication : public DiameterBaseInterface
{
	private:

		bitset<21> mTagsPresent;

		bitset<21> mMandatoryAvpCheckVal;

		bitset<21> mMandatoryAvpSetVal;

		unsigned mTag;

		BOOLEAN mDecodeFlag = false;

		vector<DiameterBaseInterface*> mBaseInterfaceList;

		UINT32 mAvpCode = 0;

		UINT32 mAvpVendorId = 0;

		pair<INT16,INT16> mAvpOffsetLen;

		ANTrusted*		mANTrusted;

		list<EventTrigger*>* 		mEventTriggerList;

		list<EventTrigger*>::iterator 		mEventTriggerIterator;

		IPCANType*		mIPCANType;

		list<Address*>* 		mANGWAddressList;

		list<Address*>::iterator 		mANGWAddressIterator;

		OctetString*		m3GPPSGSNAddress;

		OctetString*		m3GPPSGSNIPv6Address;

		OctetString*		m3GPPSGSNMCCMNC;

		OctetString*		mFramedIPAddress;

		RATType*		mRATType;

		OctetString*		mRAI;

		OctetString*		m3GPPUserLocationInfo;

		OctetString*		mTraceReference;

		OctetString*		m3GPP2BSID;

		OctetString*		m3GPPMSTimeZone;

		OctetString*		mRoutingRuleIdentifier;

		Address*		mUELocalIPAddress;

		Address*		mHeNBLocalIPAddress;

		Unsigned32*		mUDPSourcePort;




		UserCSGInformation*	mUserCSGInformationGrp;










		TraceData*	mTraceDataGrp;








		PresenceReportingAreaInformation*	mPresenceReportingAreaInformationGrp;

	public:
		EventReportIndication();

		EventReportIndication(const EventReportIndication &objEventReportIndication) {

		mTagsPresent = objEventReportIndication.mTagsPresent;

		mMandatoryAvpCheckVal = objEventReportIndication.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objEventReportIndication.mMandatoryAvpSetVal;

		mTag = objEventReportIndication.mTag;

		mDecodeFlag = objEventReportIndication.mDecodeFlag;

		if(objEventReportIndication.mANTrusted != NULL)
		mANTrusted = new ANTrusted(*(objEventReportIndication.mANTrusted));

		if(objEventReportIndication.mUserCSGInformationGrp != NULL)
		 {
				 mUserCSGInformationGrp =  new UserCSGInformation(*objEventReportIndication.mUserCSGInformationGrp);
		 }
		if(objEventReportIndication.mIPCANType != NULL)
		mIPCANType = new IPCANType(*(objEventReportIndication.mIPCANType));

		if(objEventReportIndication.m3GPPSGSNAddress != NULL)
		m3GPPSGSNAddress = new OctetString(*(objEventReportIndication.m3GPPSGSNAddress));

		if(objEventReportIndication.m3GPPSGSNIPv6Address != NULL)
		m3GPPSGSNIPv6Address = new OctetString(*(objEventReportIndication.m3GPPSGSNIPv6Address));

		if(objEventReportIndication.m3GPPSGSNMCCMNC != NULL)
		m3GPPSGSNMCCMNC = new OctetString(*(objEventReportIndication.m3GPPSGSNMCCMNC));

		if(objEventReportIndication.mFramedIPAddress != NULL)
		mFramedIPAddress = new OctetString(*(objEventReportIndication.mFramedIPAddress));

		if(objEventReportIndication.mRATType != NULL)
		mRATType = new RATType(*(objEventReportIndication.mRATType));

		if(objEventReportIndication.mRAI != NULL)
		mRAI = new OctetString(*(objEventReportIndication.mRAI));

		if(objEventReportIndication.m3GPPUserLocationInfo != NULL)
		m3GPPUserLocationInfo = new OctetString(*(objEventReportIndication.m3GPPUserLocationInfo));

		if(objEventReportIndication.mTraceDataGrp != NULL)
		 {
				 mTraceDataGrp =  new TraceData(*objEventReportIndication.mTraceDataGrp);
		 }
		if(objEventReportIndication.mTraceReference != NULL)
		mTraceReference = new OctetString(*(objEventReportIndication.mTraceReference));

		if(objEventReportIndication.m3GPP2BSID != NULL)
		m3GPP2BSID = new OctetString(*(objEventReportIndication.m3GPP2BSID));

		if(objEventReportIndication.m3GPPMSTimeZone != NULL)
		m3GPPMSTimeZone = new OctetString(*(objEventReportIndication.m3GPPMSTimeZone));

		if(objEventReportIndication.mRoutingRuleIdentifier != NULL)
		mRoutingRuleIdentifier = new OctetString(*(objEventReportIndication.mRoutingRuleIdentifier));

		if(objEventReportIndication.mUELocalIPAddress != NULL)
		mUELocalIPAddress = new Address(*(objEventReportIndication.mUELocalIPAddress));

		if(objEventReportIndication.mHeNBLocalIPAddress != NULL)
		mHeNBLocalIPAddress = new Address(*(objEventReportIndication.mHeNBLocalIPAddress));

		if(objEventReportIndication.mUDPSourcePort != NULL)
		mUDPSourcePort = new Unsigned32(*(objEventReportIndication.mUDPSourcePort));

		if(objEventReportIndication.mPresenceReportingAreaInformationGrp != NULL)
		 {
				 mPresenceReportingAreaInformationGrp =  new PresenceReportingAreaInformation(*objEventReportIndication.mPresenceReportingAreaInformationGrp);
		 }
		}

		void operator = (const EventReportIndication &objEventReportIndication) {

		mTagsPresent = objEventReportIndication.mTagsPresent;

		mMandatoryAvpCheckVal = objEventReportIndication.mMandatoryAvpCheckVal;

		mMandatoryAvpSetVal = objEventReportIndication.mMandatoryAvpSetVal;

		mTag = objEventReportIndication.mTag;

		mDecodeFlag = objEventReportIndication.mDecodeFlag;

		if(objEventReportIndication.mANTrusted != NULL)
		mANTrusted = new ANTrusted(*(objEventReportIndication.mANTrusted));

		if(objEventReportIndication.mUserCSGInformationGrp != NULL)
		 {
				 mUserCSGInformationGrp =  new UserCSGInformation(*objEventReportIndication.mUserCSGInformationGrp);
		 }
		if(objEventReportIndication.mIPCANType != NULL)
		mIPCANType = new IPCANType(*(objEventReportIndication.mIPCANType));

		if(objEventReportIndication.m3GPPSGSNAddress != NULL)
		m3GPPSGSNAddress = new OctetString(*(objEventReportIndication.m3GPPSGSNAddress));

		if(objEventReportIndication.m3GPPSGSNIPv6Address != NULL)
		m3GPPSGSNIPv6Address = new OctetString(*(objEventReportIndication.m3GPPSGSNIPv6Address));

		if(objEventReportIndication.m3GPPSGSNMCCMNC != NULL)
		m3GPPSGSNMCCMNC = new OctetString(*(objEventReportIndication.m3GPPSGSNMCCMNC));

		if(objEventReportIndication.mFramedIPAddress != NULL)
		mFramedIPAddress = new OctetString(*(objEventReportIndication.mFramedIPAddress));

		if(objEventReportIndication.mRATType != NULL)
		mRATType = new RATType(*(objEventReportIndication.mRATType));

		if(objEventReportIndication.mRAI != NULL)
		mRAI = new OctetString(*(objEventReportIndication.mRAI));

		if(objEventReportIndication.m3GPPUserLocationInfo != NULL)
		m3GPPUserLocationInfo = new OctetString(*(objEventReportIndication.m3GPPUserLocationInfo));

		if(objEventReportIndication.mTraceDataGrp != NULL)
		 {
				 mTraceDataGrp =  new TraceData(*objEventReportIndication.mTraceDataGrp);
		 }
		if(objEventReportIndication.mTraceReference != NULL)
		mTraceReference = new OctetString(*(objEventReportIndication.mTraceReference));

		if(objEventReportIndication.m3GPP2BSID != NULL)
		m3GPP2BSID = new OctetString(*(objEventReportIndication.m3GPP2BSID));

		if(objEventReportIndication.m3GPPMSTimeZone != NULL)
		m3GPPMSTimeZone = new OctetString(*(objEventReportIndication.m3GPPMSTimeZone));

		if(objEventReportIndication.mRoutingRuleIdentifier != NULL)
		mRoutingRuleIdentifier = new OctetString(*(objEventReportIndication.mRoutingRuleIdentifier));

		if(objEventReportIndication.mUELocalIPAddress != NULL)
		mUELocalIPAddress = new Address(*(objEventReportIndication.mUELocalIPAddress));

		if(objEventReportIndication.mHeNBLocalIPAddress != NULL)
		mHeNBLocalIPAddress = new Address(*(objEventReportIndication.mHeNBLocalIPAddress));

		if(objEventReportIndication.mUDPSourcePort != NULL)
		mUDPSourcePort = new Unsigned32(*(objEventReportIndication.mUDPSourcePort));

		if(objEventReportIndication.mPresenceReportingAreaInformationGrp != NULL)
		 {
				 mPresenceReportingAreaInformationGrp =  new PresenceReportingAreaInformation(*objEventReportIndication.mPresenceReportingAreaInformationGrp);
		 }
		}

		virtual ~EventReportIndication();

		BOOLEAN isPresent(int);

		BOOLEAN mAvpDecodedFlag = true;

		std::shared_ptr<byteArray> mspByteArray;

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument ANTrusted for datatype EventReportIndication
		*/
		ANTrusted* setANTrusted();

		//! Function to reset 
		/*!		Function to reset NULL type of argument ANTrusted for datatype EventReportIndication
		*/
		void resetANTrusted();

		//!Function to get values
		/*!		Function to get ANTrusted type of argument ANTrusted for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		ANTrusted* getANTrusted();

		list<EventTrigger*>* getEventTriggerList();

		list<EventTrigger*>* setEventTriggerList();

		void resetEventTriggerList();

		UserCSGInformation* getUserCSGInformation();

		UserCSGInformation* setUserCSGInformation();

		void resetUserCSGInformation();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument IPCANType for datatype EventReportIndication
		*/
		IPCANType* setIPCANType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument IPCANType for datatype EventReportIndication
		*/
		void resetIPCANType();

		//!Function to get values
		/*!		Function to get IPCANType type of argument IPCANType for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		IPCANType* getIPCANType();

		list<Address*>* getANGWAddressList();

		list<Address*>* setANGWAddressList();

		void resetANGWAddressList();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPSGSNAddress for datatype EventReportIndication
		*/
		OctetString* set3GPPSGSNAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPSGSNAddress for datatype EventReportIndication
		*/
		void reset3GPPSGSNAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPSGSNAddress for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPSGSNAddress();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPSGSNIPv6Address for datatype EventReportIndication
		*/
		OctetString* set3GPPSGSNIPv6Address();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPSGSNIPv6Address for datatype EventReportIndication
		*/
		void reset3GPPSGSNIPv6Address();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPSGSNIPv6Address for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPSGSNIPv6Address();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPSGSNMCCMNC for datatype EventReportIndication
		*/
		OctetString* set3GPPSGSNMCCMNC();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPSGSNMCCMNC for datatype EventReportIndication
		*/
		void reset3GPPSGSNMCCMNC();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPSGSNMCCMNC for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPSGSNMCCMNC();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument FramedIPAddress for datatype EventReportIndication
		*/
		OctetString* setFramedIPAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument FramedIPAddress for datatype EventReportIndication
		*/
		void resetFramedIPAddress();

		//!Function to get values
		/*!		Function to get OctetString type of argument FramedIPAddress for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getFramedIPAddress();

		//!Function to set values
		/*!		Function to set the recent Enumerated type of argument RATType for datatype EventReportIndication
		*/
		RATType* setRATType();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RATType for datatype EventReportIndication
		*/
		void resetRATType();

		//!Function to get values
		/*!		Function to get RATType type of argument RATType for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		RATType* getRATType();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument RAI for datatype EventReportIndication
		*/
		OctetString* setRAI();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RAI for datatype EventReportIndication
		*/
		void resetRAI();

		//!Function to get values
		/*!		Function to get OctetString type of argument RAI for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getRAI();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPUserLocationInfo for datatype EventReportIndication
		*/
		OctetString* set3GPPUserLocationInfo();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPUserLocationInfo for datatype EventReportIndication
		*/
		void reset3GPPUserLocationInfo();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPUserLocationInfo for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPUserLocationInfo();

		TraceData* getTraceData();

		TraceData* setTraceData();

		void resetTraceData();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument TraceReference for datatype EventReportIndication
		*/
		OctetString* setTraceReference();

		//! Function to reset 
		/*!		Function to reset NULL type of argument TraceReference for datatype EventReportIndication
		*/
		void resetTraceReference();

		//!Function to get values
		/*!		Function to get OctetString type of argument TraceReference for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getTraceReference();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPP2BSID for datatype EventReportIndication
		*/
		OctetString* set3GPP2BSID();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPP2BSID for datatype EventReportIndication
		*/
		void reset3GPP2BSID();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPP2BSID for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPP2BSID();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument 3GPPMSTimeZone for datatype EventReportIndication
		*/
		OctetString* set3GPPMSTimeZone();

		//! Function to reset 
		/*!		Function to reset NULL type of argument 3GPPMSTimeZone for datatype EventReportIndication
		*/
		void reset3GPPMSTimeZone();

		//!Function to get values
		/*!		Function to get OctetString type of argument 3GPPMSTimeZone for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		OctetString* get3GPPMSTimeZone();

		//!Function to set values
		/*!		Function to set the recent OctetString type of argument RoutingRuleIdentifier for datatype EventReportIndication
		*/
		OctetString* setRoutingRuleIdentifier();

		//! Function to reset 
		/*!		Function to reset NULL type of argument RoutingRuleIdentifier for datatype EventReportIndication
		*/
		void resetRoutingRuleIdentifier();

		//!Function to get values
		/*!		Function to get OctetString type of argument RoutingRuleIdentifier for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		OctetString* getRoutingRuleIdentifier();

		//!Function to set values
		/*!		Function to set the recent Address type of argument UELocalIPAddress for datatype EventReportIndication
		*/
		Address* setUELocalIPAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UELocalIPAddress for datatype EventReportIndication
		*/
		void resetUELocalIPAddress();

		//!Function to get values
		/*!		Function to get Address type of argument UELocalIPAddress for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		Address* getUELocalIPAddress();

		//!Function to set values
		/*!		Function to set the recent Address type of argument HeNBLocalIPAddress for datatype EventReportIndication
		*/
		Address* setHeNBLocalIPAddress();

		//! Function to reset 
		/*!		Function to reset NULL type of argument HeNBLocalIPAddress for datatype EventReportIndication
		*/
		void resetHeNBLocalIPAddress();

		//!Function to get values
		/*!		Function to get Address type of argument HeNBLocalIPAddress for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		Address* getHeNBLocalIPAddress();

		//!Function to set values
		/*!		Function to set the recent Unsigned32 type of argument UDPSourcePort for datatype EventReportIndication
		*/
		Unsigned32* setUDPSourcePort();

		//! Function to reset 
		/*!		Function to reset NULL type of argument UDPSourcePort for datatype EventReportIndication
		*/
		void resetUDPSourcePort();

		//!Function to get values
		/*!		Function to get Unsigned32 type of argument UDPSourcePort for datatype EventReportIndication
		Throws exception of which type and Summary of Exception
		*/
		Unsigned32* getUDPSourcePort();

		PresenceReportingAreaInformation* getPresenceReportingAreaInformation();

		PresenceReportingAreaInformation* setPresenceReportingAreaInformation();

		void resetPresenceReportingAreaInformation();

		//! Function to Decode
		/*!		Function to Decode datatype EventReportIndication
		*/
		int Decode(byteArray *array, INT16 lMsgLen, UINT16 *parsedBytes=NULL);
		UINT32 getAvpCode();
		INT32 setAvpCode(UINT32 avpCode);
		UINT32 getAvpVendorId();
		INT32 setAvpVendorId(UINT32 avpVendorId);
		pair<INT16,INT16> getAvpOffsetLen();
		INT32 setAvpOffsetLen(INT16 offset, INT16 length);
		//! Function to Find
		/*!		Function to Find datatype EventReportIndication
		*/
		DiameterBaseInterface* Find(byteArray *array, UINT32 avpCode);
		//! Function to Find multiple occurence
		/*!		Function to Find datatype EventReportIndication
		*/
		BOOLEAN FindAll(byteArray *array, UINT32 avpCode,list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		BOOLEAN FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
		std::shared_ptr<byteArray> GetByteArray( );
		//! Function to Encode
		/*!		Function to Encode datatype EventReportIndication
		*/
		int Encode(byteArray *array);
		//! Function to Display
		/*!		Function to Display datatype EventReportIndication
		*/
		void Display(UINT32 tab);
		BOOLEAN GetMissingAvpInfo(TEXT *lMissingAvpInfo);

};

}


#endif
