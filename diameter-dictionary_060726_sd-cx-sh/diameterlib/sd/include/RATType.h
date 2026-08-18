#ifndef SD_RATTYPE_H
#define SD_RATTYPE_H

#include "DiameterTLVUtil.h"
#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"
#include "TssDiameterMsgException.h"
#include "base/include/DiameterMsgHeader.h"

namespace SD {class RATType:public Integer32
{
public:
	INT32  setValue(UINT32 val)
	{
		switch(val)
		{
			case 0:
			case 1:
			case 3:
			case 4:
			case 5:
			case 1000:
			case 1001:
			case 1002:
			case 1003:
			case 1004:
			case 1006:
			case 1007:
			case 1008:
			case 1039:
			case 1040:
			case 2000:
			case 2001:
			case 2002:
			case 2003:
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

