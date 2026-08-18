#ifndef SD_COLLECTIONPERIODRRMLTE_H
#define SD_COLLECTIONPERIODRRMLTE_H

#include "DiameterTLVUtil.h"
#include "DiameterBaseInterface.h"

#include "DiameterBasicDecEnc.h"
#include "TssDiameterMsgException.h"
#include "base/include/DiameterMsgHeader.h"

namespace SD {class CollectionPeriodRRMLTE:public Integer32
{
public:
	INT32  setValue(UINT32 val)
	{
		switch(val)
		{
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

