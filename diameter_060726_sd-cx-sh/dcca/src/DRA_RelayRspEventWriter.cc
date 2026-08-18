#include "DRA_RelayRspEventWriter.h"
#define DRA_MAX_TIME_LEN 20
ACE_Mutex* 				  		DRA_RelayRspEventWriter::m_ObjGuard = new ACE_Mutex();
DRA_RelayRspEventWriter*   DRA_RelayRspEventWriter::mDRA_RelayRspEventWriter = 0;

//-------------------------------------------------------------------------------------------------------
// METHOD      : Instance()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : DRA_RelayRspEventWriter
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
DRA_RelayRspEventWriter* DRA_RelayRspEventWriter::Instance()
{
	if( mDRA_RelayRspEventWriter == NULL)
	{
		AAA_MutexScopeLock guard(*m_ObjGuard);
		if ( mDRA_RelayRspEventWriter == NULL)
		{
			mDRA_RelayRspEventWriter = new DRA_RelayRspEventWriter();
			if ( !mDRA_RelayRspEventWriter->Start())
			{
				Destroy();
			}
		}
	}
	return mDRA_RelayRspEventWriter;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Destroy()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : void
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DRA_RelayRspEventWriter::Destroy()
{
	delete mDRA_RelayRspEventWriter;
	mDRA_RelayRspEventWriter = 0;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Start()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DRA_RelayRspEventWriter::Start() {
	mEvrFile = NULL;
	AAA_LOG((LM_INFO, "%T |APP_RELAY_EVR| Starting Evr writer thread"));
	if (! m_Active && (activate() == 0)) { //Only one thread for Generating EVR....
		m_Active = true;
	}
	return m_Active;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Stop()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : void
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DRA_RelayRspEventWriter::Stop()
{
	AAA_LOG((LM_INFO, "%T |APP_RELAY_EVR| Stopping Evr writer thread"));
	m_Active = false;
	EvrFileClose();
	m_Condition.signal();
	// wait for thread to exit
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : SendReq
// DESCRIPTION :
// PARAMETER   : td::shared_ptr<DRA_HttpResponse>, std::shared_ptr<DRA_HttpReq>, string, bool
// RETURN      : int
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
int DRA_RelayRspEventWriter::SendReq(std::shared_ptr<string> &rJsonStr)
{
	m_SendQueue.Enqueue(rJsonStr);
	m_Condition.signal();
	return (0);
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : EvrFileopen()
// DESCRIPTION :
// PARAMETER   : struct tm 
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DRA_RelayRspEventWriter::EvrFileopen(struct tm &local_tm)
{
	char lTime[DRA_MAX_TIME_LEN] = "" ;
	snprintf( lTime, DRA_MAX_TIME_LEN, "%04d%02d%02d-%02d", (local_tm.tm_year + 1900), (local_tm.tm_mon + 1) , local_tm.tm_mday, local_tm.tm_hour);
	string lTimeStr(lTime);
	string mFileName = "DRA_UPCC_RELAY_EVR_" + lTimeStr ;

	//mFileWPath = DRA_CONFIG_HDLR()->mUpccRechEvrFilePath + "/" + mFileName;
	mFileWPath = "/opt/dra/var/evr/" + mFileName;

	mEvrFile = fopen(mFileWPath.c_str(), "a+");

	if (mEvrFile == NULL)
	{
		AAA_LOG((LM_ERROR, "%T |APP_RELAY_EVR| FN:%s. File open error", mFileWPath.c_str()));
		return false;
	}
	AAA_LOG((LM_DEBUG, "%T |APP_RELAY_EVR| FN:%s. File opened\n", mFileWPath.c_str()));
	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : EvrFileClose()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : void
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DRA_RelayRspEventWriter::EvrFileClose()
{
	AAA_LOG((LM_DEBUG, "%T |APP_RELAY_EVR| FN:%s. File closed\n", mFileWPath.c_str()));
	fclose(mEvrFile);
	mEvrFile = NULL;
}	

//-------------------------------------------------------------------------------------------------------
// METHOD      : Write()
// DESCRIPTION :
// PARAMETER   : std::shared_ptr<DRA_EventMsg>
// RETURN      : void
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DRA_RelayRspEventWriter::write( std::shared_ptr<string> &rJsonStr)
{
	string  lLogStr 		= "";	
	time_t  t 				= time(NULL);
	struct  tm local_tm;
	localtime_r(&t, &local_tm);

	if (mEvrFile == NULL)
	{
		if (!EvrFileopen(local_tm))
		{
			AAA_LOG((LM_ERROR, "%T |APP_RELAY_EVR|  Failed to write EVR \n"));
			return ;
		}
	}

	char lTime[DRA_MAX_TIME_LEN] = "" ;
	snprintf( lTime, DRA_MAX_TIME_LEN, "%04d/%02d/%02d %02d:%02d:%02d", (local_tm.tm_year + 1900), (local_tm.tm_mon + 1) , local_tm.tm_mday, local_tm.tm_hour, local_tm.tm_min, local_tm.tm_sec);
	string lTimeStr(lTime);

	string lEvrData = lTimeStr;
	lEvrData.append("::\n"); 
	lEvrData.append(*rJsonStr); 					

	AAA_LOG((LM_DEBUG, "%T |APP_RELAY_EVR| EVR write success \n"));

	fprintf(mEvrFile ,"%s" , lEvrData.c_str());
	fflush ( mEvrFile );
	return;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : svc()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : int
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
int DRA_RelayRspEventWriter::svc()
{
	int 	 lHour 			= 0;
	time_t t 				= time(NULL);
	struct tm local_tm;

	localtime_r(&t, &local_tm);
	lHour = local_tm.tm_hour;

	do
	{
		t 				= time(NULL);
		localtime_r(&t, &local_tm);

		if ( local_tm.tm_hour !=  lHour)
		{
			lHour = local_tm.tm_hour;
			EvrFileClose();
			EvrFileopen(local_tm);	
		}

		AAA_MutexScopeLock guard(m_Condition.mutex());
		m_Condition.wait();
		while (! m_SendQueue.IsEmpty())
		{
			std::shared_ptr<string> lJsonStr = m_SendQueue.Dequeue();
			AAA_LOG((LM_ERROR, "%T |APP_RELAY_EVR|  EVR Received\n"));
			if ( lJsonStr.use_count() != 0)
			{
				write(lJsonStr);
			}
		}
	} while (m_Active);

	return (0);
}




