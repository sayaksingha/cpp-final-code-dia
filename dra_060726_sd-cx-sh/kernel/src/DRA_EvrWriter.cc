#include "DRA_EvrWriter.h"

#define DRA_MAX_TIME_LEN 20

ACE_Mutex*     DRA_EvrWriter::m_ObjGuard = new ACE_Mutex();

bool DRA_EvrWriter::start()
{
   mEvrFile = NULL;
	if (! m_Active && (activate() == 0)) { //Only one thread for Generating EVR....
   }
   return m_Active;
}

void DRA_EvrWriter::stop()
{
   AAA_LOG((LM_INFO, "%T |EVR-Writer| Stopping thread\n"));
   m_Active = false;
   m_Condition.signal();
}

int DRA_EvrWriter::SendReq(std::shared_ptr<DiameterBase> rBasePtr, MsccInfoMap &rMsccInfoMap, bool lTccTimeoutFlag)
{
   if (m_Active != true)
      return -1;
	std::shared_ptr<EvrInfo> lEvrInfo = make_shared<EvrInfo>();

	std::shared_ptr<DiameterBase> lBase = rBasePtr;
	lEvrInfo->mDiameterBase    = rBasePtr;
	lEvrInfo->mMsccInfoMap     = rMsccInfoMap;
	lEvrInfo->mTccTimeOutFlag  = lTccTimeoutFlag;
 
   m_SendQueue.Enqueue(lEvrInfo);
   m_Condition.signal();
   return 0;
}

int DRA_EvrWriter::svc()
{
   m_Active = true;
   AAA_LOG((LM_INFO, "%T |EVR-Writer| started Evr thread\n"));

	int     lHour         = 0;
   time_t t             = time(NULL);
   struct tm local_tm;

   localtime_r(&t, &local_tm);
   lHour = local_tm.tm_hour;

   do
   {
      AAA_MutexScopeLock guard(m_Condition.mutex());
      m_Condition.wait();

		t           = time(NULL);
      localtime_r(&t, &local_tm);

      if ( local_tm.tm_hour !=  lHour)
      {
         lHour = local_tm.tm_hour;
         EvrFileClose();
         //EvrFileopen(local_tm);
      }

      while (! m_SendQueue.IsEmpty())
		{
			std::shared_ptr<EvrInfo> lEvrInfo         = m_SendQueue.Dequeue();
			std::shared_ptr<DiameterBase> lBaseMsgPtr = lEvrInfo->mDiameterBase;

			if(lEvrInfo->mTccTimeOutFlag)
			{
				string lEvr = "";
				//string lSessionId = lBaseMsgPtr->getSessionId()->ToString();

				try
				{
					lEvr = "0," + lBaseMsgPtr -> getSessionId()->ToString() + ",0,0,0,0,0";
				}
				catch(...)
				{
					lEvr = "0,0,0,0,0,0,0";
				}

				try
				{
               if(lEvrInfo->mMsccInfoMap.empty())
               {
                  lEvr.append("{0,0,0,0,0,0,9999,0}");
               }

               //auto lMsccInfoMapIt = rMsccInfoMap.find(lRG);
               for(auto lMsccInfoMapIt = lEvrInfo->mMsccInfoMap.begin();lMsccInfoMapIt!=lEvrInfo->mMsccInfoMap.end();lMsccInfoMapIt++)
               {
                  lEvr.append("{");
                  MsccInfo lMsccInfo = lMsccInfoMapIt->second;;
                  lEvr.append(to_string(lMsccInfoMapIt->first));
                  lEvr.append(",0,0,");
                  lEvr.append(to_string(lMsccInfo.mGsuTotal));
                  lEvr.append(",0,");
                  lEvr.append(to_string(lMsccInfo.mUsuTotal));
                  lEvr.append(",9999,0}");
               }
            }
            catch(...)
            {
               lEvr.append("{0,0,0,0,0,0,9999,0}");
            }
			
				UINT32 lApplId = 0;

				if(lBaseMsgPtr != NULL)
				{
					lApplId = lBaseMsgPtr->getApplnId();	
				}
				else
				{
					lApplId = 0;
				}

				if(!writeEvr(lEvr, lApplId))
				{
					//AAA_LOG((LM_ERROR, "%T |EVR-Writer| Failed to write EVR SID:%s\n", lSessionId.c_str()));
				}
				else
				{
					//AAA_LOG((LM_DEBUG, "%T |EVR-Writer|Success to write EVR SID:%s\n", lSessionId.c_str()));
				}

				continue;
			}

         if ( lBaseMsgPtr != NULL)
         {

            string lSessionId = lBaseMsgPtr->getSessionId()->ToString();
            AAA_LOG((LM_INFO, "%T |EVR-Writer| Evr Request Received, SID:%s\n",lSessionId.c_str()));
            //ProcessMessage
            switch(lBaseMsgPtr->getApplnId())
            {
               case AAA_Ro_APP_ID:
                  {
                     switch(lBaseMsgPtr->getCmdCode())
                     {
                        case AAA_CCR_MSG:
                           {
                              if( lBaseMsgPtr->getRequestBit())
                              {
                                 AAA_LOG((LM_ERROR,
                                          "%T |EVR-Writer| CCR is not supported. CC:%d.\n",
                                          lBaseMsgPtr->getCmdCode()));
                                 continue;
                              }
										else
										{
											string lJsonData = "";
											if ( false == this->FormEvrMsg( lBaseMsgPtr, lEvrInfo->mMsccInfoMap, lJsonData))
											{
												AAA_LOG((LM_ERROR,
															"%T |EVR-Writer| Failed to Form Evr Msg. CC:%d, SID:%s\n",
															lBaseMsgPtr->getCmdCode(), lSessionId.c_str()));
												continue;
											}

											UINT32 lApplId = lBaseMsgPtr->getApplnId();
											//Write to file
											if(!writeEvr(lJsonData, lApplId))
											{
												AAA_LOG((LM_DEBUG, "%T |EVR-Writer| Failed to write EVR SID:%s\n", lSessionId.c_str()));
											}
											else
											{
												AAA_LOG((LM_DEBUG, "%T |EVR-Writer| EVR Successfully written SID:%s\n", lSessionId.c_str()));
											}
										}
									}
							}
						}
						break;
					case AAA_Gx_APP_ID:
						{

						}
						break;
				}
			}
		}
	}while(m_Active);
	return 0;
}

bool DRA_EvrWriter::FormEvrMsg(std::shared_ptr<DiameterBase> lDimeterBase, MsccInfoMap &rMsccInfoMap, string &lEvr)
{
	/*
		Time Stamp mili sec, T bit flag, 

		Session Id, request number, Hbhid, OH, Request Type (Initial/update/Terminate ), Result Code, 
		{ RG, Service id, GSU : per request, consolidated, USU : Per request, consolidated, result code, fui },
		{ RG, Service id, GSU : per request, consolicated, USU : Per request, consolidated, result code, fui }
		*/
	try
	{
		//std::shared_ptr<RO::CCAnswer> lCCAns = std::dynamic_pointer_cast<RO::CCAnswer>(lDimeterBase);
      //lCCAns->Decode ( lCCAns->mspByteArray.get());	

		std::shared_ptr<RO::CCAnswer> lCCAnsPtr = std::dynamic_pointer_cast<RO::CCAnswer>(lDimeterBase);
      std::shared_ptr<RO::CCAnswer> lCCAns = std::make_shared<RO::CCAnswer>();
      lCCAns->Decode ( lCCAnsPtr->mspByteArray.get());
	
	
		lEvr = to_string(lCCAns -> getTransBit());
		lEvr.append(",");

		lEvr.append(lCCAns -> getSessionId()->ToString());
		lEvr.append(",");
		lEvr.append(to_string(lCCAns -> getCCRequestNumber() -> getValue()));
		lEvr.append(",");
		lEvr.append(to_string(lCCAns -> getHopByHopId()));
		lEvr.append(",");
		lEvr.append(lCCAns -> getOriginHost()->ToString());
		lEvr.append(",");

		lEvr.append(to_string(lCCAns -> getCCRequestType() -> getValue()));
		lEvr.append(",");
		lEvr.append(to_string(lCCAns -> getResultCode() -> getValue()));
		lEvr.append(",");


		try
		{
			//auto lMSCC = reinterpret_cast<RO::CCAnswer*>(lDimeterBase.get())->getMultipleServicesCreditControlGrpList();
			auto lMSCC = lCCAns->getMultipleServicesCreditControlGrpList();

			for(auto it = lMSCC->begin(); it != lMSCC->end(); it++)
			{
				lEvr.append("{");
				UINT32 lRG = 0;	
				try
				{
					//lEvr.append(to_string((*it) -> getRatingGroup()->getValue()));
					lRG = (*it) -> getRatingGroup()->getValue();
					lEvr.append(to_string(lRG));
					lEvr.append(",");
				}
				catch(...)
				{
					lRG = 0;
					lEvr.append("0,");
					AAA_LOG((LM_DEBUG, "%T |EVR-Writer| Rating Grp not FOUND\n"));
				}

				try
				{
					auto lServiceId  = (*it) -> getServiceIdentifierList();
					if(lServiceId->begin() != (*it) -> getServiceIdentifierList() -> end())
					{
						lEvr.append(to_string((*lServiceId->begin()) -> getValue()));
						lEvr.append(",");
					}
				}
				catch(...)
				{
					lEvr.append("0,");
					AAA_LOG((LM_DEBUG, "%T |EVR-Writer| Service Id not FOUND\n"));
				}

				try
				{
					lEvr.append(to_string((*it)->getGrantedServiceUnit()->getCCTotalOctets()->getValue()));
					lEvr.append(",");
				}
				catch(...)
				{
					lEvr.append("0,");
				}

				//USU map
				try
				{
					MsccInfo lMsccInfo ;
					auto lMsccInfoMapIt = rMsccInfoMap.find(lRG);
					if(lMsccInfoMapIt != rMsccInfoMap.end())
					{
						lMsccInfo = lMsccInfoMapIt->second;

						lEvr.append(to_string(lMsccInfo.mGsuTotal));
						lEvr.append(",");
						lEvr.append(to_string(lMsccInfo.mUsuCurrent));
						lEvr.append(",");
						lEvr.append(to_string(lMsccInfo.mUsuTotal));
						lEvr.append(",");
					}
					else
					{
						lEvr.append("0,0,0,");
					}
				}
				catch(...)
				{
					lEvr.append("0,0,0,");
				}

				try
				{
					lEvr.append(to_string((*it)->getResultCode()->getValue()));
					lEvr.append(",");
				}
				catch(...)
				{
					lEvr.append("0,");
				}

				try
				{
					lEvr.append(to_string((*it)->getFinalUnitIndication()->getFinalUnitAction()->getValue()));
				}	
				catch(...)
				{
					lEvr.append("0");
				}
				lEvr.append("}");
			}
		}
		catch(...)
		{
			try
			{
				if(rMsccInfoMap.empty())
				{
					lEvr.append("{0,0,0,0,0,0,0,0}");
					return true;
				}

				//auto lMsccInfoMapIt = rMsccInfoMap.find(lRG);
				for(auto lMsccInfoMapIt = rMsccInfoMap.begin();lMsccInfoMapIt!=rMsccInfoMap.end();lMsccInfoMapIt++)
				{
					lEvr.append("{");
					MsccInfo lMsccInfo = lMsccInfoMapIt->second;;
					lEvr.append(to_string(lMsccInfoMapIt->first));
					lEvr.append(",0,0,");
					lEvr.append(to_string(lMsccInfo.mGsuTotal));
					lEvr.append(",0,");
					lEvr.append(to_string(lMsccInfo.mUsuTotal));
					lEvr.append(",0,0}");
				}

			}
			catch(...)
			{
				lEvr.append("{0,0,0,0,0,0,0,0}");
			}
			return true;

			//AAA_LOG((LM_DEBUG, "%T |EVR-Writer| Exception in Mscc decode\n"));
			//return false;
		}
		return true;
	}
	catch(...)
	{
		AAA_LOG((LM_DEBUG, "%T |EVR-Writer| Exception in Mscc basic param decode\n"));
		return false;
	}
}

void DRA_EvrWriter::EvrFileClose()
{
   if(mEvrFile != NULL)
   {
	   AAA_LOG((LM_DEBUG, "%T |EVR-Writer| FN:%s. File closed\n", mFileWPath.c_str()));
	   fclose(mEvrFile);
	   mEvrFile = NULL;
   }
}

bool DRA_EvrWriter::EvrFileopen(struct tm &local_tm, UINT32 &lApplId)
{
	char lTime[DRA_MAX_TIME_LEN] = "" ;
	snprintf( lTime, DRA_MAX_TIME_LEN, "%02d%02d%04d-%02d", local_tm.tm_mday, (local_tm.tm_mon + 1), (local_tm.tm_year + 1900), local_tm.tm_hour);
	string lTimeStr(lTime);
	string lFileName = "DRA_"+ to_string(lApplId) +"_DETAILED_EVR_" + lTimeStr ;

	//mFileWPath = DRA_CONFIG_HDLR()->mUpccRechEvrFilePath + "/" + lFileName;
	mFileWPath = "/opt/dra/var/evr/" + lFileName;

	mEvrFile = fopen(mFileWPath.c_str(), "a+");

	if (mEvrFile == NULL)
	{
		AAA_LOG((LM_ERROR, "%T |EVR-Writer| FN:%s. File open error", mFileWPath.c_str()));
		return false;
	}
	else
	{
		string lHeader = "|Time-stamp|T-Bit|SID|Request-Number|HH-Id|OH|Request-Type|Result-Code|{Rating-Grp|Service-Id|GSU|GSU-Total|USU|USU-Total|Result-Code|FUI}|\n";

		fprintf(mEvrFile ,"%s" , lHeader.c_str());
		fflush ( mEvrFile );
	}

	AAA_LOG((LM_DEBUG, "%T |EVR-Writer| FN:%s. File opened\n", mFileWPath.c_str()));
	return true;
}

bool DRA_EvrWriter::writeEvr(string &lEvrData, UINT32 &lApplId)
{
	string  lLogStr      = "";
	time_t  t            = time(NULL);
	struct  tm local_tm;
	localtime_r(&t, &local_tm);

	if (mEvrFile == NULL)
	{
		if (!EvrFileopen(local_tm, lApplId))
		{
			return false;
		}
	}

	//time_t  t                    = time(NULL);
	//struct  tm local_tm;
	localtime_r(&t, &local_tm);
	char lTime[DRA_MAX_TIME_LEN+4] = "" ;

	struct timeval tp;
	::gettimeofday(&tp, NULL);

	//snprintf( lTime, DRA_MAX_TIME_LEN, "%04d/%02d/%02d %02d:%02d:%02d", (local_tm.tm_year + 1900), (local_tm.tm_mon + 1) , local_tm.tm_mday, local_tm.tm_hour, local_tm.tm_min, local_tm.tm_sec);
	snprintf( lTime, DRA_MAX_TIME_LEN+4, "%02d/%02d/%04d %02d:%02d:%02d:%03ld", local_tm.tm_mday, (local_tm.tm_mon + 1), (local_tm.tm_year + 1900), local_tm.tm_hour, local_tm.tm_min, local_tm.tm_sec, tp.tv_usec);

	string lTimeStr(lTime);

	lEvrData = lTimeStr + "," + lEvrData + "\n";

	fprintf(mEvrFile ,"%s" , lEvrData.c_str());
	fflush ( mEvrFile );
	return true;
}
