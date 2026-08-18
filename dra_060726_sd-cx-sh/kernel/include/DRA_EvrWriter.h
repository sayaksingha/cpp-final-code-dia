//----------------------------------------------------------------------
// NAME :  Dra.cc
//
// COPYRIGHT :  Tayana Software Solutions Pvt Ltd -- Copyright(C) 2018
//              All rights reserved. No part of this computer program
//              may be used or reproduced in any form by any
//              means without prior written permission of
//              Tayana Software Solutions Pvt Ltd
//
// DESCRIPTION
//
// Originated :                                     Date:
//----------------------------------------------------------------------

#include "ro/include/CCRequest.h"
#include "ro/include/CCAnswer.h"
#include "gx/include/CCRequest.h"
#include "gx/include/CCAnswer.h"
#include "resultcodes.h"
#include "aaa_data_defs.h"
#include "TdraStructs.h"
#include <sys/time.h>

typedef map<UINT32, MsccInfo> MsccInfoMap;

struct EvrInfo
{
	std::shared_ptr<DiameterBase> mDiameterBase;
	MsccInfoMap mMsccInfoMap;
	bool mTccTimeOutFlag;
};

class DRA_EvrWriter : public ACE_Task<ACE_MT_SYNCH>
{
	public:
	DRA_EvrWriter(): m_Active(false),m_Condition(*(new ACE_Mutex))
	{}

	~DRA_EvrWriter()
	{}

	bool start();
	void stop();
	int  svc();
	bool writeEvr(string &lEvrData, UINT32 &lApplId);
	bool EvrFileopen(struct tm &local_tm, UINT32 &lApplId);
	void EvrFileClose();
	bool FormEvrMsg(std::shared_ptr<DiameterBase> lDimeterBase, MsccInfoMap &rMsccInfoMap, string &lEvr);
   int  SendReq(std::shared_ptr<DiameterBase> rBasePtr, MsccInfoMap &, bool lTccTimeoutFlag = 0);

	private:
	bool                                                     m_Active;
	ACE_Condition<ACE_Mutex>                                 m_Condition;
	//AAA_ProtectedQueue<std::shared_ptr<DiameterBase>>      m_SendQueue;
	AAA_ProtectedQueue<std::shared_ptr<EvrInfo>>             m_SendQueue;
	static   ACE_Mutex                                       *m_ObjGuard;
	FILE *                                                   mEvrFile = NULL ;
	string 																	mFileWPath;
};

typedef ACE_Singleton<DRA_EvrWriter, ACE_Thread_Mutex> DRA_EvrWriter_S;
#define DRA_DETAILED_EVR_WRITER() DRA_EvrWriter_S::instance()
