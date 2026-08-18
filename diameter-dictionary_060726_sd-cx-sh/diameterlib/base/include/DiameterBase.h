#ifndef DIAMETERBASE
#define DIAMETERBASE

#include "DiameterTLVUtil.h"
#include "DiameterBasicDecEnc.h"
#include "DiameterBaseInterface.h"

#include "TssDiameterMsgException.h"
#include "base/include/DiameterMsgHeader.h"
#include "base/include/CCRequestType.h"
#include "base/include/ProxyInfo.h"
#include "base/include/VendorSpecificApplicationId.h"
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
using namespace BASE; 

class DiameterBase : public DiameterBaseInterface
{
	public:
	 DiameterBase();
	virtual ~DiameterBase();

	DiameterMsgHeader*				decodeDiameterMsgHeader (byteArray *array);
	DiameterMsgHeader*				getDiameterMsgHeader();
	BOOLEAN								setDiameterMsgHeader( UINT8 mVersion, 
																 UINT8 mCmdFlg, UINT32 mCmdCode, UINT32 mApplId, UINT32 mHopByHopId, UINT32 mEndToEndId);

	BOOLEAN								setVersion(UINT8  mVersion);
	BOOLEAN								setCmdFlag(UINT8 mCmdFlg);
	BOOLEAN								setCmdCode(UINT32 mCmdCode); 
	BOOLEAN								setApplnId(UINT32 mApplId);
	BOOLEAN								setHopByHopId(UINT32 mHopByHopId);
	BOOLEAN								setEndToEndId(UINT32 mEndToEndId);
	BOOLEAN								setRequestBit(BOOLEAN rBit);
	BOOLEAN								setErrorBit(BOOLEAN eBit);
	BOOLEAN								setProxyBit(BOOLEAN pBit);
	BOOLEAN								setTransBit(BOOLEAN tBit);
	
	UINT8									getVersion();
	UINT8									getCmdFlag();
	UINT32								getCmdCode();
	UINT32								getApplnId();
	UINT32								getHopByHopId();
	UINT32								getEndToEndId();
	BOOLEAN								getRequestBit();
	BOOLEAN								getErrorBit();
	BOOLEAN								getProxyBit();
	BOOLEAN								getTransBit();
	INT32							Decode(byteArray *array,INT16 lMLen = 0, UINT16 *parsedBytes = NULL);
	INT32							Encode(byteArray *array);
	void						Display(UINT32 tab);
	DiameterBaseInterface*						Find(byteArray *array, UINT32 avpCode);
	BOOLEAN						FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
	BOOLEAN						FindAll(byteArray *array, std::map<int,UINT32> &avpCodeMap, int &size, int key, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false);
   std::shared_ptr<byteArray> GetByteArray();   
	virtual Integer32* 		setAuthApplicationId();
	virtual Integer32* 		getAuthApplicationId();
	virtual void 		resetAuthApplicationId();
	virtual list<Integer32*>*	getAuthApplicationIdList();
	virtual list<Integer32*>*	setAuthApplicationIdList();
	virtual void	resetAuthApplicationIdList();
	virtual Unsigned32* 		setCCRequestNumber();
	virtual Unsigned32* 		getCCRequestNumber();
	virtual void 		resetCCRequestNumber();
	virtual CCRequestType* 		setCCRequestType();
	virtual CCRequestType* 		getCCRequestType();
	virtual void 		resetCCRequestType();
	virtual Integer32* 		setDestModuleId();
	virtual Integer32* 		getDestModuleId();
	virtual void 		resetDestModuleId();
	virtual OctetString* 		setDestinationHost();
	virtual OctetString* 		getDestinationHost();
	virtual void 		resetDestinationHost();
	virtual OctetString* 		setDestinationRealm();
	virtual OctetString* 		getDestinationRealm();
	virtual void 		resetDestinationRealm();
	virtual OctetString* 		setOriginHost();
	virtual OctetString* 		getOriginHost();
	virtual void 		resetOriginHost();
	virtual OctetString* 		setOriginRealm();
	virtual OctetString* 		getOriginRealm();
	virtual void 		resetOriginRealm();
	virtual Unsigned32* 		setResultCode();
	virtual Unsigned32* 		getResultCode();
	virtual void 		resetResultCode();
	virtual list<OctetString*>*	getRouteRecordList();
	virtual list<OctetString*>*	setRouteRecordList();
	virtual void	resetRouteRecordList();
	virtual OctetString* 		setSessionId();
	virtual OctetString* 		getSessionId();
	virtual void 		resetSessionId();
	virtual Integer32* 		setSourceModuleId();
	virtual Integer32* 		getSourceModuleId();
	virtual void 		resetSourceModuleId();
	virtual OctetString* 		setUniqueMsgRefNo();
	virtual OctetString* 		getUniqueMsgRefNo();
	virtual void 		resetUniqueMsgRefNo();
	virtual OctetString* 		setUserName();
	virtual OctetString* 		getUserName();
	virtual void 		resetUserName();
	
	protected:
	DiameterMsgHeader			*mDiameterMsgHeader;
};

#endif
