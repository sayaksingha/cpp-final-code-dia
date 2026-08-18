#ifndef BASE_DISCONNECTCAUSE_H
#define BASE_DISCONNECTCAUSE_H

#include "DiameterTLVUtil.h"
#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"
#include "TssDiameterMsgException.h"
#include "base/include/DiameterMsgHeader.h"

namespace BASE {class DisconnectCause:public Integer32
{
public:
	INT32  setValue(UINT32 val)
	{
		switch(val)
		{
			case 0:
			case 1:
			case 2:
				Integer32::setValue(val);
				return 0;
			default:
				TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE, "Unsupported Enumerated value");
				throw lTssDiaMsgException;
		}
	}
};
}
#endif

