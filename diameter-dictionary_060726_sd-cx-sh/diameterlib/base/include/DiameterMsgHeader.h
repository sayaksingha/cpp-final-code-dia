#ifndef BASE_DIAMETERMSGHEADER_H
#define BASE_DIAMETERMSGHEADER_H

#include "DiameterConstDef.h"
struct diamerterCmdFlag
{
	UINT8 rBit:1;
	UINT8 pBit:1;
	UINT8 eBit:1;
	UINT8 tBit:1;
	UINT8 reservedBits:4;
};


class DiameterMsgHeader
{
	public:
	DiameterMsgHeader():
		mVersion(1),
		mMsgLen(0),
		mCmdCode(0),
		mApplId(0),
		mHopByHopId(0),
		mEndToEndId(0)
	{
		 memset(&mCmdFlg, 0, sizeof(diamerterCmdFlag));
	}

	~DiameterMsgHeader()
	{
	}

	UINT8  mVersion;
	UINT32 mMsgLen;
 	diamerterCmdFlag mCmdFlg;
	UINT32 mCmdCode;
	UINT32 mApplId;
	UINT32 mHopByHopId;
	UINT32 mEndToEndId;
};

#endif
