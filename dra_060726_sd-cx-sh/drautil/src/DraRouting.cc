//----------------------------------------------------------------------
// NAME :  DraRouting.cc
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

#include "DraRouting.h"

void* StartFilePollTimer(void *ptr)
{
	//pthread_t lThreadId1   = pthread_self();
	bool		 reloadFlag   =  false;

	DraRouting *lObj = (DraRouting*) ptr;
	while(true)
	{
		struct stat routingFile_info;
		if (stat(lObj->mroutingFile.c_str(), &routingFile_info) == 0) 
		{
			time_t lRoutingFileTime = routingFile_info.st_mtime;
			time_t lDiff 				= lObj->mRoutingFileTime - lRoutingFileTime;

			if(lDiff != 0 &&  lObj->mReloadFlag)
			{
				reloadFlag = true;
				lObj->mRoutingFileTime = lRoutingFileTime;
			}
		}

		struct stat dictFile_info;
		if (stat(lObj->mdictionaryFile.c_str(), &dictFile_info) == 0) 
		{
			time_t lDictFileTime = dictFile_info.st_mtime;
			time_t lDiff 			= lObj->mDictFileTime - lDictFileTime;

			if(lDiff != 0 && lObj->mReloadFlag)
			{
				reloadFlag = true;
				lObj->mDictFileTime = lDictFileTime;
			}
		}


		if(reloadFlag == true )
		{
			reloadFlag = false;
			lObj->Reload();
		}
		sleep(1);
	}
	pthread_exit(NULL);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DraRouting::~DraRouting()
{
}
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DraRouting::Reset()
{
	mApplicationData.connectedPeer.clear();
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
//bool DraRouting::Init(std::string dictFile, std::string appFile)
DraRouting::DraRouting( std::string dictFile, std::string appFile , bool &returnVal ):
	DraParser((char*) dictFile.c_str(), (char*) appFile.c_str())
{
	mCount 		= 0;
	mWTSkipCnt  = 0;

	mdictionaryFile = dictFile;
	mroutingFile	 = appFile;

	struct stat routingFile_info;
	if (stat(mroutingFile.c_str(), &routingFile_info) == 0) 
	{
		mRoutingFileTime = routingFile_info.st_mtime;
		//		strftime(mRoutingFileTimeStr, 36, "%d.%m.%Y %H:%M:%S", localtime(&mRoutingFileTime));
	}
	else
		returnVal = false;

	struct stat dictFile_info;
	if (stat(mdictionaryFile.c_str(), &dictFile_info) == 0) 
	{
		mDictFileTime = dictFile_info.st_mtime;
	}
	else
		returnVal = false;


	//Create a thread;
	//StartFilePollTimer()
	//AB - Commented because take alot of cpu. need to think about better approch
	/*void*             (*lpFuncPtr)(void *);
	pthread_attr_t    lThreadAttr;
	int               lRetVal;

	pthread_t lThreadId1;
	pthread_attr_init (&lThreadAttr);
	pthread_attr_setdetachstate (&lThreadAttr, PTHREAD_CREATE_DETACHED);

	lpFuncPtr = StartFilePollTimer;

	lRetVal = pthread_create(&lThreadId1, &lThreadAttr, lpFuncPtr, this);

	if(lRetVal != 0)
	{
		printf("pthread_create failed for StartFilePollTimer");
		returnVal = false;
	}*/

	//	cout << "TBR DraRouting -- Dict " << dictFile << " appFile "  << appFile <<endl;
	returnVal = true;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
bool DraRouting::CheckPeer(std::string peerKey , DiameterPeerEntry *&destPeer , string sid )
{
	std::string peerName;
   peerName.clear ();

	//Works in C++17
	//list<ActivePeerData>::iterator iter = std::find(mApplicationData.activePeerList.begin(), mApplicationData.activePeerList.end(), peerKey);
	//list<ActivePeerData>::iterator iter = mApplicationData.activePeerList.find(peerKey);

	/*if(iter != mApplicationData.activePeerList.end())
	{
		peerName = iter->peerValue;
	}*/

	//--------- TBR --------------------
	/*int xRan;
	srand( time(0)); // This will ensure a really randomized number by help of time.

	xRan=rand()%10+1; // Randomizing the number between 1-10.
	cout << "Rand:" << xRan << endl;

	if(xRan <= 7)
		return true;
	else
		return false;*/
	//--------- TBR --------------------

	for(list<ActivePeerData>::iterator Iterator = mApplicationData.activePeerList.begin();
			Iterator != mApplicationData.activePeerList.end(); ++Iterator)
	{
		if(strncmp(Iterator->peerName.c_str(), peerKey.c_str() , Iterator->peerName.size()) == 0)
		{
			peerName = Iterator->peerValue;

			break;
		}
	}


	if ( peerName.size () )
	{
		DiameterPeerEntry *peer = NULL;

		peer = DIAMETER_PEER_TABLE()->Lookup(  peerName );

		if ( peer )
		{
			if (peer->IsOpen())
			{
				destPeer = peer;
				peer->Dump();
				AAA_LOG((LM_DEBUG, "%T |DRA_APP| PEER:%s STATUS:AVAILABLE Sid:%s\n",peerName.c_str() , sid.c_str()));
				return true;	
			}
			else
			{
				AAA_LOG((LM_DEBUG, "%T |DRA_APP| PEER:%s STATUS:UNAVAILABLE Sid:%s\n",peerName.c_str() , sid.c_str() ));
			}
		}
	}

	AAA_LOG((LM_DEBUG, "%T |DRA_APP| PEER:%s Check PeerLookup Failed sid:%s \n",peerName.c_str() , sid.c_str() ));
			

	return false;
}


//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
bool DraRouting::CheckPeerStatus(DiameterPeerEntry *destPeer )
{
	if (destPeer)
	{
		return (destPeer->IsOpen() == true ) ? true : false ;
	}
	return false;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DraRouting::Reload()
{
	this->reload((char*) mdictionaryFile.c_str(), (char*) mroutingFile.c_str());
}
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
//Active PeerData 
std::list<ActivePeerData> DraRouting::getActivePeerData()
{
	return mApplicationData.activePeerList;
} 

bool DraRouting::getAlias(std::string &lPeerName, std::string &lAlias)
{
	auto lRet = mApplicationData.activePeerMap.find(lPeerName);
	if(lRet != mApplicationData.activePeerMap.end())
	{
		lAlias = lRet->second;
		return true;
	}
   return false;
}
//Returns Supported AVPs in application file	
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
std::map<int,DictionaryData> DraRouting::getSupportedAVP()
{
	return mApplicationData.avpSupportedData;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
bool DraRouting::getAvpCodePathDet( int applicationid, UINT32 avpCode, AvpCodePathDet &lAvpCodePathDet )
{
	string lMapKey = std::to_string(applicationid)+"_"+std::to_string(avpCode);

	auto it = mApplicationData.avpCodePathData.find(lMapKey);
	if (it != mApplicationData.avpCodePathData.end())
	{
		lAvpCodePathDet = it->second;
		return true;
	}
	return false;
}

//-------------------------------------------------------------------------------
// METHOD      : getAVPDataType
// DESCRIPTION : Returns AVP Datatype
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
std::string DraRouting::getAVPDataType(int code)
{
	std::string dataType;

	map<int,DictionaryData>::iterator it = mDictionaryDataMap.find(code);

	if(it != mDictionaryDataMap.end())
	{
		dataType = it->second.typeName;
	}

	return dataType;
}
//-------------------------------------------------------------------------------
// METHOD      : getAVPDataType
// DESCRIPTION : Returns AVP Datatype
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
EnumRoutingType DraRouting::getRoutingType ( )
{
	return mApplicationData.routingData.routingType;		
}




//-------------------------------------------------------------------------------
// METHOD      : getPeer
// DESCRIPTION : 
// PARAMETER   : int code[], string value[], int cnt, bool &result
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
bool DraRouting::getPeer( DiameterPeerEntry *&dest , string sid )
{   
	switch(mApplicationData.routingData.routingType)
	{
		case ROUND_ROBIN:
			AAA_LOG((LM_DEBUG,"%T |DRA_APP| Routing Configured Type:ROUND_ROBIN Sid:%s \n", sid.c_str()));
			return findRRPeer(mApplicationData.routingData.routingTypeName, dest , sid);
		case FAIL_OVER:
			AAA_LOG((LM_DEBUG,"%T |DRA_APP| Routing Configured Type:FAIL_OVER Sid:%s \n", sid.c_str()));
			return findFOPeer(mApplicationData.routingData.routingTypeName, dest , sid);
		case WEIGHTAGE:
			AAA_LOG((LM_DEBUG,"%T |DRA_APP| Routing Configured Type:WEIGHTAGE Sid:%s\n" , sid.c_str()));
			return findWTPeer(mApplicationData.routingData.routingTypeName, dest , sid );
		case UNKNOWN:
		default		:
			AAA_LOG((LM_DEBUG,"%T |DRA_APP| Routing Configured Type:UNKNOWN GotType[%d] Sid:%s \n" , 
						mApplicationData.routingData.routingType , sid.c_str() ));
			return false;
		break;
	}
	return true;
}

//-------------------------------------------------------------------------------
// METHOD      : getPeer
// DESCRIPTION : 
// PARAMETER   : int code[], string value[], int cnt, bool &result
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
bool DraRouting::getPeer(multimap<int,std::string> codeMap, DiameterPeerEntry *&dest , string sid)
{
	bool result = false ;

	switch(mApplicationData.routingData.routingType)
	{
		case AVP_BASED:
			if(!DRA_CONFIG_HDLR()->mApplRoutingLogic)
				return findAVPPeer(codeMap, result, dest , sid );
			else
				return findAVPPeerList(codeMap, result, dest , sid );
			break;
		case UNKNOWN:
		default		:
			{
				result = false;
				return result;
			}
			break;
	};

	return result;
}


//-------------------------------------------------------------------------------
// METHOD      : evaluteExp
// DESCRIPTION : Evaluate Exp - for AVP
// PARAMETER   : bool expRes1, bool expRes2, string operation
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
//Evaluate Exp - for AVP
bool DraRouting::evaluteExp(bool expRes1, bool expRes2, string operation)
{
	if(operation == "OR")
	{
		return (expRes1 || expRes2);
	}
	else if(operation == "AND")
	{
		return (expRes1 && expRes2);
	}
	else if(operation == "NONE" || operation == "")
	{
		return true;
	}
	else
	{
		return false;
	}
	return true;
}


//-------------------------------------------------------------------------------
// METHOD      : IsMatch
// DESCRIPTION : Reg Exp Matching
// PARAMETER   : char * pMatchRegex, char * pStr
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
bool DraRouting::IsMatch(char * pMatchRegex, char * pStr)
{
	string lMatchRegex (pMatchRegex);
	string lStr (pStr);

	boost::regex lRegex (lMatchRegex);
	boost::match_results < std::string::const_iterator > lWhat;

//nt lRet = boost::regex_match (lStr, lWhat, lRegex , std::match_default | std::match_partial);
   int lRet = boost::regex_match (lStr, lWhat, lRegex,
         boost::match_default | boost::match_partial);

//		std::match_default );
//		std::match_default | std::match_partial);

	if (0 == lRet)
	{
		return false;
	}
	return lWhat[0].matched;
}

//-------------------------------------------------------------------------------
// METHOD      : getActiveDefPeer
// DESCRIPTION : Function used for Default Peer
// PARAMETER   : 
// RETURN      : std::string
// THROWS      :
//-------------------------------------------------------------------------------
bool DraRouting::getActiveDefPeer(DiameterPeerEntry *&dest , string sid)
{
	//ACE_Read_Guard<ACE_RW_Mutex> guard(mRoutingMutex);
	std::string peer;
	std::string defPeerName = mApplicationData.routingData.defaultRouting;

	map<std::string,std::string>::iterator it = mApplicationData.defaultForms.find(defPeerName);

	if(it != mApplicationData.defaultForms.end())
	{
		peer = it->second;
		AAA_LOG((LM_DEBUG,"%T |DRA_APP| Setting to Default PeerKey:%s\n", defPeerName.c_str(), sid.c_str()));
		
		if((CheckPeer(peer, dest, sid )))
			return true;
		else 
			return false;
		//Is Active
	}
	return false;
}

//-------------------------------------------------------------------------------
// METHOD      : findRRPeer
// DESCRIPTION : Function used for Round Robin
// PARAMETER   : 
// RETURN      : std::string
// THROWS      :
//-------------------------------------------------------------------------------
/*bool DraRouting::findRRPeer(std::string keyName, DiameterPeerEntry *&dest , string sid )
{

	std::lock_guard<std::mutex> lk(mRRRoutingMutex);
	//ACE_Read_Guard<ACE_RW_Mutex> guard(mRoutingMutex);
	static int	iteratorIndex = 0;
	string lCurrPeer ;
	bool   keyFound  = false;

	map<std::string,RRPeerData>::iterator it = mApplicationData.roundRobinForms.find(keyName);

	if(it != mApplicationData.roundRobinForms.end())
	{
		RRPeerData lRRPeerData;

		lRRPeerData = it->second;

		lCurrPeer   = lRRPeerData.currentPeer;



		std::list<std::string>::iterator iter = lRRPeerData.roundRobinPeerList.begin();

		size_t lPeerWeightageSize = lRRPeerData.roundRobinPeerList.size();

		if(iter != lRRPeerData.roundRobinPeerList.end())
		{
			std::advance ( iter , iteratorIndex);	

			while ( lPeerWeightageSize ) 
			{
				keyFound = false;

				iteratorIndex = 
					(iteratorIndex+1 >= lRRPeerData.roundRobinPeerList.size())?0:++iteratorIndex;

				if(CheckPeer(lCurrPeer , dest, sid))
				{
					lRRPeerData.currentPeer     = *iter;
               mApplicationData.connectedPeer = lRRPeerData.currentPeer;
					break;		
				}
				iter++;	
				lCurrPeer = *iter;
				lPeerWeightageSize--;
				
			}
		}	
		if ( keyFound )
		{
			mApplicationData.roundRobinForms[keyName] = lRRPeerData;
			return true;
		}
	}

	return getActiveDefPeer(dest , sid );
}

*/

bool DraRouting::findRRPeer(std::string keyName, DiameterPeerEntry *&dest , string sid )
{
    std::lock_guard<std::mutex> lk(mRRRoutingMutex);
    static int  iteratorIndex = 0;
    string lCurrPeer;
    bool keyFound = false;

    auto it = mApplicationData.roundRobinForms.find(keyName);
    if (it != mApplicationData.roundRobinForms.end())
    {
        RRPeerData lRRPeerData = it->second;
        lCurrPeer = lRRPeerData.currentPeer;

        auto iter = lRRPeerData.roundRobinPeerList.begin();
        size_t lPeerWeightageSize = lRRPeerData.roundRobinPeerList.size();

        if (!lRRPeerData.roundRobinPeerList.empty())
        {
            std::advance(iter, iteratorIndex); // Start from the current iterator position

            while (lPeerWeightageSize)
            {
                if (CheckPeer(*iter, dest, sid)) // Check *iter instead of lCurrPeer
                {
                    lRRPeerData.currentPeer = *iter;
                    mApplicationData.connectedPeer = lRRPeerData.currentPeer;
                    keyFound = true;
                    iteratorIndex = (iteratorIndex + 1) % lRRPeerData.roundRobinPeerList.size(); // Move to next peer only if found
                    break;
                }

                iter++;
                if (iter == lRRPeerData.roundRobinPeerList.end())
                {
                    iter = lRRPeerData.roundRobinPeerList.begin(); // Reset to beginning if needed
                }

                lPeerWeightageSize--;
            }
        }

        if (keyFound) // Only update if a peer was found
        {
            mApplicationData.roundRobinForms[keyName] = lRRPeerData;
            return true;
        }
    }

    return getActiveDefPeer(dest, sid);
}

//-------------------------------------------------------------------------------
// METHOD      : findFOPeer
// DESCRIPTION : Function used for Fail Over
// PARAMETER   : 
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
bool DraRouting::findFOPeer(std::string keyName, DiameterPeerEntry *&dest , string sid)
{
//	std::string keyName = mApplicationData.routingData.routingTypeName;

	//ACE_Read_Guard<ACE_RW_Mutex> guard(mRoutingMutex);

	std::lock_guard<std::mutex> lk(mFORoutingMutex);
	map<std::string,FOPeerData>::iterator it =
		mApplicationData.failOverForms.find( keyName);

	if(it != mApplicationData.failOverForms.end())
	{
		FOPeerData	lFOPeerData;

		lFOPeerData = it->second;

		mApplicationData.connectedPeer = lFOPeerData.primaryPeer; //Returning;
		if((CheckPeer(mApplicationData.connectedPeer , dest , sid )))
		{
			return true;
		}

		mApplicationData.connectedPeer = lFOPeerData.secondaryPeer; //Returning;
		if((CheckPeer(mApplicationData.connectedPeer , dest , sid )))
		{
			return true;
		}
		else 
			return getActiveDefPeer(dest, sid);
	}

	return true;
}

//-------------------------------------------------------------------------------
// METHOD      : findWTPeer
// DESCRIPTION : Function used for Weightage
// PARAMETER   : none
// RETURN      : std::string
// THROWS      :
//-------------------------------------------------------------------------------
/*bool DraRouting::findWTPeer(std::string keyName, DiameterPeerEntry *&dest)
  {
  ACE_Read_Guard<ACE_RW_Mutex> guard(mRoutingMutex);

  std::string lTempPeer;
  std::string lCurrPeer;
  bool 	keyFound 			 = true;

//	std::string keyName = mApplicationData.routingData.routingTypeName;

map<std::string,WTPeerData>::iterator it = mApplicationData.weightageForms.find(keyName);

if(it != mApplicationData.weightageForms.end())
{
WTPeerData	lWTPeerData;

lWTPeerData = it->second;
lCurrPeer   = lWTPeerData.currentPeer;
static int	iteratorIndex = 0;

map<std::string,std::string>::iterator iter = lWTPeerData.peerWeightage.find(lWTPeerData.currentPeer);

if(iter != lWTPeerData.peerWeightage.end())
{
// lWeightage.c_str --> Can be Stored as interger - HV 
std::string lWeightage = iter->second;
map<std::string,std::string>::iterator Iterator = lWTPeerData.peerWeightage.begin(); 

size_t lPeerWeightageSize = lWTPeerData.peerWeightage.size();

std::advance ( Iterator , iteratorIndex);	

while ( lPeerWeightageSize ) 
{
if(lWTPeerData.processedCnt >= atoi(lWeightage.c_str()) || (false ==  CheckPeer(lCurrPeer, dest) ) )
{
keyFound 			       = false;

lWTPeerData.processedCnt = lWTPeerData.processedCnt >= atoi(lWeightage.c_str()) ? 0:lWTPeerData.processedCnt;

iteratorIndex = 
(iteratorIndex+1 >= lWTPeerData.peerWeightage.size())?0:++iteratorIndex;

lWTPeerData.currentPeer = Iterator->first;

if(CheckPeer(lWTPeerData.currentPeer , dest))
{
keyFound 			      			= true;
++lWTPeerData.processedCnt;
mApplicationData.connectedPeer 			  = lWTPeerData.currentPeer;
mApplicationData.weightageForms[keyName] = lWTPeerData;
break;
}
Iterator++;
lPeerWeightageSize--;
}
else
{
keyFound 			      					  = true;
++lWTPeerData.processedCnt;
mApplicationData.connectedPeer 			  = lWTPeerData.currentPeer;
mApplicationData.weightageForms[keyName] = lWTPeerData;
break;
}
}
}

if ( keyFound )
{	
return true;
}
}
//Is Available need to add
return getActiveDefPeer(dest);
}*/

//-------------------------------------------------------------------------------
// METHOD      : findWTPeer
// DESCRIPTION : Function used for Weightage
// PARAMETER   : none
// RETURN      : std::string
// THROWS      :
//-------------------------------------------------------------------------------
bool DraRouting::findWTPeer(std::string keyName, DiameterPeerEntry *&dest , string sid )
{
	//ACE_Read_Guard<ACE_RW_Mutex> guard(mRoutingMutex);
	std::lock_guard<std::mutex> lk(mWTRoutingMutex);
	//std::cout << "TBR findWTPeer::" << keyName << endl;

	AAA_LOG((LM_DEBUG, "%T |DRA_APP| WEIGHTAGE Peer key: %s Sid:%s\n",
				keyName.c_str(), sid.c_str()));
	map<std::string,WTPeerData>::iterator it = mApplicationData.weightageForms.find(keyName);
	
	if(it != mApplicationData.weightageForms.end())
	{
		WTPeerData	lWTPeerData = it->second;

		/*for(map<std::string,PeerWeightageData>::iterator it1 = lWTPeerData.peerWeightage.begin(); it1 != lWTPeerData.peerWeightage.end(); it1++)
		{
			cout << "TBR Weigthage PeerName : " << it1->first << endl;
		}*/

		//Reset skipPeerFlag
		if(mWTSkipCnt >= lWTPeerData.peerWeightage.size())
		{
			//std::lock_guard<std::mutex> lk(mRoutingMutex);
			mWTSkipCnt = 0;
			for(map<std::string,PeerWeightageData>::iterator it1 = lWTPeerData.peerWeightage.begin(); it1 != lWTPeerData.peerWeightage.end(); ++it1)
			{
				PeerWeightageData lPeerWeightageData = it1->second;

				lPeerWeightageData.processedWeight 		= 0;
				lPeerWeightageData.skipPeer		  		= false;
				lWTPeerData.peerWeightage[it1->first] 	= lPeerWeightageData;
			}
			lWTPeerData.currentPeer = lWTPeerData.peerWeightage.begin()->first;

			mApplicationData.weightageForms[keyName] = lWTPeerData;
		}

		int	iteratorIndex = 0;
		map<std::string,PeerWeightageData>::iterator iter = lWTPeerData.peerWeightage.find(lWTPeerData.currentPeer);

		if(iter != lWTPeerData.peerWeightage.end())
		{
			bool peerFound = false;
			//map<std::string,PeerWeightageData>::iterator Iterator = lWTPeerData.peerWeightage.begin();

			size_t lPeerWeightageSize = lWTPeerData.peerWeightage.size();

			//std::advance ( Iterator , iteratorIndex);
			// std::advance ( iter, iteratorIndex);

			while ( lPeerWeightageSize )
			{
				if(iter == lWTPeerData.peerWeightage.end())
					iter = lWTPeerData.peerWeightage.begin();

				std::string lCurrPeer     					= iter->first;
				PeerWeightageData lPeerWeightageData 	= iter->second;
					

				bool lPeerFndFlg = false;
				if((lPeerFndFlg = CheckPeer(lCurrPeer , dest , sid )) && (lPeerWeightageData.skipPeer != true))
				{
					iteratorIndex =
						(iteratorIndex+1 >= lWTPeerData.peerWeightage.size())?0:++iteratorIndex;

					if(iteratorIndex <= 0)
					{
						iter = lWTPeerData.peerWeightage.begin();
					}
					else
					{
						std::advance ( iter , iteratorIndex);
					}

					if(iter == lWTPeerData.peerWeightage.end())
						iter = lWTPeerData.peerWeightage.begin();


					lPeerWeightageData.processedWeight++;

					if(lPeerWeightageData.processedWeight >= lPeerWeightageData.maxWeight)
					{
						lPeerWeightageData.skipPeer = true;
						mWTSkipCnt++;
					}
					lWTPeerData.peerWeightage[lCurrPeer]  		= lPeerWeightageData;
					lWTPeerData.currentPeer 						= iter->first;
					{
						//std::lock_guard<std::mutex> lk(mRoutingMutex);
						mApplicationData.connectedPeer 				= lWTPeerData.currentPeer;
						//mApplicationData.weightageForms.clear();
						mApplicationData.weightageForms[keyName]  = lWTPeerData;
					}	

					peerFound 											= true;

					break;
				}
				else if(!lPeerFndFlg)
				{
						mWTSkipCnt++;
						//Reset skipPeerFlag
						if(mWTSkipCnt >= lWTPeerData.peerWeightage.size())
						{
							//std::lock_guard<std::mutex> lk(mRoutingMutex);
							mWTSkipCnt = 0;
							for(map<std::string,PeerWeightageData>::iterator it1 = lWTPeerData.peerWeightage.begin(); it1 != lWTPeerData.peerWeightage.end(); ++it1)
							{
								PeerWeightageData lPeerWeightageData = it1->second;
								lPeerWeightageData.processedWeight     = 0;
								lPeerWeightageData.skipPeer            = false;
								lWTPeerData.peerWeightage[it1->first]  = lPeerWeightageData;
							}
						}
				}
				iter++;
				lPeerWeightageSize--;
			}
			if(peerFound != true)
				return getActiveDefPeer(dest , sid );
			else
			{
				return true;
			}
		}
	}
	//Is Available need to add
	return getActiveDefPeer(dest , sid );
}

//-------------------------------------------------------------------------------
// METHOD      : findAVPPeer
// DESCRIPTION : Function used for AVP Based
// PARAMETER   : int code[], string value[], int cnt, bool &resu`lt
// RETURN      : std::string
// THROWS      :
//-------------------------------------------------------------------------------
bool DraRouting::findAVPPeer(multimap<int,std::string> codeMap, bool &result, DiameterPeerEntry *&dest, string sid)
{
	std::lock_guard<std::mutex> lk(mAVPRoutingMutex);
	//ACE_Read_Guard<ACE_RW_Mutex> guard(mRoutingMutex);

	//-----------TBR --------------
/*	Commented by Abhishek Chhabra as This loop is only for Debug ...
 *	for(map<int,std::string>::iterator Iterator = codeMap.begin(); Iterator != codeMap.end(); ++Iterator)
	{
		AAA_LOG((LM_DEBUG, "%T |DRA_APP| Code:%d Value:%s Sid:%s \n",Iterator->first, Iterator->second.c_str(), sid.c_str()));
	}
	//-----------TBR --------------
*/
	/*for(list<std::string>::iterator lIterator = mApplicationData.routingData.routingTypeNameList.begin();
	  lIterator != mApplicationData.routingData.routingTypeNameList.end(); lIterator++)*/
	
   for(multimap<std::string,std::string>::iterator lIterator = mApplicationData.routingData.avpRoutingMap.begin();
			lIterator != mApplicationData.routingData.avpRoutingMap.end(); ++lIterator)
	{
		std::string keyName 			= lIterator->first;
		//std::string keyMethodName 	= mApplicationData.routingData.methodName;
		std::string keyMethodName 	= lIterator->second;
		std::string lastOper;
		lastOper.clear();

		map<std::string,std::map<int,AVPPeerData>>::iterator it = mApplicationData.avpForms.find(keyName);//AVP Name

		if(it != mApplicationData.avpForms.end())
		{
			map<int,AVPPeerData> lAVPPeerDataMap = it->second;
			bool lContinue 							 = true;
			int cnt										 = codeMap.size();
			int i											 = 0;
			bool resultSet[cnt-1]					 ;

			//Code Checking
			//for(int i = 0; ((i < cnt) && (lContinue == true)); i++)
			for(map<int,std::string>::iterator Iterator = codeMap.begin(); Iterator != codeMap.end(); ++Iterator)
			{
				map<int,AVPPeerData>::iterator iter = lAVPPeerDataMap.find(Iterator->first);
				if(iter != lAVPPeerDataMap.end())
				{
					AVPPeerData lAVPPeerData = iter->second;
					std::string lRegExp = lAVPPeerData.avpValue;

					if(true == IsMatch((char*)lRegExp.c_str(), (char*)Iterator->second.c_str()))
					{
						//std::cout << "TBR::::: true:" << Iterator->second.c_str() << " AVP Name::" << keyName << endl;
						AAA_LOG((LM_DEBUG, "%T |DRA_APP| Exp:%s RegExp:%s Key:%s Method:%s Sid:%s\n",
									Iterator->second.c_str(),lRegExp.c_str(),keyName.c_str(),keyMethodName.c_str(), sid.c_str() ));
						resultSet[i] = true;
						if(i > 0)
						{
							result = evaluteExp(resultSet[i-1], resultSet[i], lastOper);
							if(result == false)
							{
								lContinue = false;
							}
							lastOper = lAVPPeerData.avpOperation;
						}
						else
						{
							lastOper = lAVPPeerData.avpOperation;
							result = true;
						}
					}
					else
					{
						resultSet[i] = false;
						lContinue 	 = false;
						result = false;
					}
				}
				else
				{
					AAA_LOG((LM_DEBUG, "%T |DRA_APP| AVP not found, Key:%s Method:%s AVPCode:%d Sid:%s\n",
								keyName.c_str(),keyMethodName.c_str(),Iterator->first , sid.c_str()));
					//lContinue = false;//TBC Shilpa 
				}
				i++;
			}
			//Is Available need to add
			if(lContinue == true)
			{
				//TBC Check - FO/WT
				map<std::string,EnumRoutingType>::iterator iter2 = mApplicationData.routingNameMap.find(keyMethodName);
				if(iter2 != mApplicationData.routingNameMap.end())
				{
					EnumRoutingType lRoutingType = iter2->second;
					switch(lRoutingType)
					{
						case ROUND_ROBIN:
						{
							if(false == findRRPeer(keyMethodName, dest, sid))
							{
								return false;
							}
							AAA_LOG((LM_DEBUG, "%T |DRA_APP| Routing Type:AVP_BASED, Method Type:ROUND_ROBIN Key:%s Method:%s Sid:%s\n"
										,keyName.c_str(),keyMethodName.c_str(), sid.c_str()));
							return true;
						}
						case FAIL_OVER:
						{
							if (false == findFOPeer(keyMethodName, dest, sid))
							{
								return false;
							}
							AAA_LOG((LM_DEBUG, "%T |DRA_APP| Routing Type:AVP_BASED, Method Type:FAIL_OVER Key:%s Method:%s Sid:%s DH:%s\n",
										keyName.c_str(),keyMethodName.c_str(), sid.c_str(),dest->GetPeerName().c_str()));
							return true ;
						}
						case WEIGHTAGE:
						{
							if(false == findWTPeer(keyMethodName, dest, sid ))
							{
								return false;
							}
							AAA_LOG((LM_DEBUG, "%T |DRA_APP| Routing Type:AVP_BASED, Method Type:WEIGHTAGE Key:%s Method:%s Sid:%s\n",
										keyName.c_str(),keyMethodName.c_str(), sid.c_str() , dest->GetPeerName().c_str()));
							return true;
							
						}
						case UNKNOWN:
						default		:
							{
								AAA_LOG((LM_ERROR, "%T |DRA_APP| Unknown Routing Type, Key:%s Method:%s RoutingType:%d Sid:%s\n",
											keyName.c_str(),keyMethodName.c_str(),lRoutingType , sid.c_str()));
							}
							break;
					}
				}
				else
				{
					AAA_LOG((LM_ERROR, "%T |DRA_APP| Method not found, Key:%s Method:%s Sid::%s\n",
								keyName.c_str(),keyMethodName.c_str(), sid.c_str()));
				}
			}
			else
			{
				i			 = 0;
				lContinue = true;
					AAA_LOG((LM_ERROR, "%T |DRA_APP| Match not found, Key:%s Method:%s Sid:%s\n",
								keyName.c_str(),keyMethodName.c_str() , sid.c_str()));
				//AAA_LOG((LM_DEBUG, "%T |DRA_APP| Not matched Exp:%s RegExp:%s Key:%s Method:%s\n",Iterator->second.c_str(),lRegExp.c_str(),keyName.c_str(),keyMethodName.c_str() ));
				continue;
			}
		}
	}
	
	if(getActiveDefPeer(dest, sid))
	{
		AAA_LOG((LM_DEBUG, "%T |DRA_APP| DraRouting::findAVPPeer Sid:%s Dest:%s\n",
					sid.c_str(),dest->GetPeerName().c_str()));
		return true;
	}
	return false;
}

//-------------------------------------------------------------------------------
// METHOD      : findAVPPeer
// DESCRIPTION : Function used for AVP Based
// PARAMETER   : int code[], string value[], int cnt, bool &result
// RETURN      : std::string
// THROWS      :
//-------------------------------------------------------------------------------
/*bool DraRouting::findAVPPeerList(multimap<int,std::string> codeMapArg, bool &result, DiameterPeerEntry *&dest, string sid)
{
        std::lock_guard<std::mutex> lk(mAVPRoutingMutex);
        
        multimap<int,std::string> codeMap;
	std::string subscriptionType = "";

        for(map<int,std::string>::iterator Iterator = codeMapArg.begin(); Iterator != codeMapArg.end(); ++Iterator)
        {
                AAA_LOG((LM_DEBUG, "%T |DRA_APP| Code:%d Value:%s Sid:%s \n",Iterator->first, Iterator->second.c_str(), sid.c_str()));
                
                /*
		 * if((Iterator->first == 450 && Iterator->second.compare("1") == 0) 
                 *     && (Iterator->first == 444 && Iterator->second.length() > 12))
                 *  continue;
		bool shouldDiscard = false;
		if (Iterator->first == 450) 
		{
        		subscriptionType = Iterator->second;
		}
		if (Iterator->first == 444) 
		{
			cout<< " \n\n subscription Type is: "<< subscriptionType <<endl;
			if (subscriptionType == "3" || subscriptionType == "4") 
			{
				if (Iterator->second.length() > 128) shouldDiscard = true;
			}
			else if(subscriptionType == "1") 
			{
				// Default strict validation for unknown or E164 types
				if (Iterator->second.length() > 15) shouldDiscard = true;
			}

		}

		if (shouldDiscard)
			continue;	
                codeMap.insert(make_pair(Iterator->first, Iterator->second));
        }

        /*for(list<std::string>::iterator lIterator = mApplicationData.routingData.routingTypeNameList.begin();
          lIterator != mApplicationData.routingData.routingTypeNameList.end(); lIterator++)*
        for(multimap<std::string,std::string>::iterator lIterator = mApplicationData.routingData.avpRoutingMap.begin();
                        lIterator != mApplicationData.routingData.avpRoutingMap.end(); ++lIterator)
        {

                std::string keyName                     = lIterator->first;
                //std::string keyMethodName     = mApplicationData.routingData.methodName;
                std::string keyMethodName       = lIterator->second;
                std::string lastOper;
                lastOper.clear();

                map<std::string,std::list<AVPPeerData>>::iterator it = mApplicationData.avpFormsList.find(keyName);//AVP Name

                if(it != mApplicationData.avpFormsList.end())
                {
                        list<AVPPeerData> lAVPPeerDataList = it->second;
                        bool lContinue                     = true;
                        int cnt                            = codeMap.size();
                        int i                              = 0;
                        bool resultSet[cnt-1];

                        for(list<AVPPeerData>::iterator IteList = lAVPPeerDataList.begin(); IteList!=lAVPPeerDataList.end(); ++IteList)
                        {
                                //if(( map<int,std::string>::iterator lRet = codeMap.find(IteList->code)) != codeMap.end())
                                map<int,std::string>::iterator lRet = codeMap.find(IteList->code);
                                if(lRet != codeMap.end())
                                {
                                        std::string lRegExp = IteList->avpValue;
        //============ TBR ================
        AAA_LOG((LM_DEBUG, "%T |DRA_APP_TBR| Code:%d Exp:%s RegExp:%s Key:%s Method:%s Sid:%s TBR \n",
                 lRet->first,
                 lRet->second.c_str(),
                 lRegExp.c_str(),
                 keyName.c_str(),
                 keyMethodName.c_str(), 
                 sid.c_str() ));
        //============ TBR ================
                                        if(true == IsMatch((char*)lRegExp.c_str(), (char*)lRet->second.c_str() ))
                                        {
                                                AAA_LOG((LM_DEBUG, "%T |DRA_APP| Exp:%s RegExp:%s Key:%s Method:%s Sid:%s\n",
                                                                        lRet->second.c_str(),lRegExp.c_str(),keyName.c_str(),keyMethodName.c_str(), sid.c_str() ));
                                                resultSet[i] = true;
                                                if(i > 0)
                                                {
                                                        result = evaluteExp(resultSet[i-1], resultSet[i], lastOper);
                                                        if(result == false)
                                                        {
                                                                lContinue = false;
                                                        }
                                                        lastOper = IteList->avpOperation;
                                                }
                                                else
                                                {
                                                        lastOper = IteList->avpOperation;
                                                        result = true;
                                                }
                                        }
                                        else
                                        {
                                                resultSet[i] = false;
                                                lContinue    = false;
                                                result       = false;
                                        }
                                }
                                else
                                {
                                        AAA_LOG((LM_DEBUG, "%T |DRA_APP| AVP not found, Key:%s Method:%s AVPCode:%d Sid:%s\n",
                                                                keyName.c_str(),keyMethodName.c_str(),lRet->first , sid.c_str()));
                                        lContinue = false;
                                }
                                i++;

                        }
                        //Is Available need to add
                        if(lContinue == true)
                        {
                                //TBC Check - FO/WT
                                map<std::string,EnumRoutingType>::iterator iter2 = mApplicationData.routingNameMap.find(keyMethodName);
                                if(iter2 != mApplicationData.routingNameMap.end())
                                {
                                        EnumRoutingType lRoutingType = iter2->second;
                                        switch(lRoutingType)
                                        {
                                                case ROUND_ROBIN:
                                                {
																	if(false == findRRPeer(keyMethodName, dest, sid))
																	{
																		return false;
																	}
                                                        AAA_LOG((LM_DEBUG, "%T |DRA_APP| Routing Type:AVP_BASED, Method Type:ROUND_ROBIN Key:%s Method:%s Sid:%s\n"
                                                                                ,keyName.c_str(),keyMethodName.c_str(), sid.c_str()));
                                                        return true;
                                                }
                                                case FAIL_OVER:
                                                {
                                                        if(false == findFOPeer(keyMethodName, dest, sid))
																		  {
																			  return false;
																		  }
                                                        AAA_LOG((LM_DEBUG, "%T |DRA_APP| Routing Type:AVP_BASED, Method Type:FAIL_OVER Key:%s Method:%s Sid:%s\n",
                                                                                keyName.c_str(),keyMethodName.c_str(), sid.c_str()));
                                                        return true ;
                                                }
                                                case WEIGHTAGE:
                                                {
                                                        if( false == findWTPeer(keyMethodName, dest, sid ))
																		  {
																			  return false;
																		  }
                                                        AAA_LOG((LM_DEBUG, "%T |DRA_APP| Routing Type:AVP_BASED, Method Type:WEIGHTAGE Key:%s Method:%s Sid:%s \n",
                                                                                keyName.c_str(),keyMethodName.c_str(), sid.c_str()));
                                                        return true;
                                                }
                                                case UNKNOWN:
                                                default         :
                                                        {
                                                                AAA_LOG((LM_ERROR, "%T |DRA_APP| Unknown Routing Type, Key:%s Method:%s RoutingType:%d Sid:%s\n",
                                                                                        keyName.c_str(),keyMethodName.c_str(),lRoutingType , sid.c_str()));
                                                        }
                                                        break;
                                        }
                                }
                                else
                                {
                                        AAA_LOG((LM_ERROR, "%T |DRA_APP| Method not found, Key:%s Method:%s Sid::%s\n",
                                                                keyName.c_str(),keyMethodName.c_str(), sid.c_str()));
                                }
                        }
                        else
                        {
                                i                        = 0;
                                lContinue = true;
                                        AAA_LOG((LM_ERROR, "%T |DRA_APP| Match not found, Key:%s Method:%s Sid:%s\n",
                                                                keyName.c_str(),keyMethodName.c_str() , sid.c_str()));
                                //AAA_LOG((LM_DEBUG, "%T |DRA_APP| Not matched Exp:%s RegExp:%s Key:%s Method:%s\n",Iterator->second.c_str(),lRegExp.c_str(),keyName.c_str(),keyMethodName.c_str() ));
                                continue;
                        }
                }
        }

		  if (getActiveDefPeer(dest, sid))
		  {
			  AAA_LOG((LM_DEBUG, "%T |DRA_APP| DraRouting::findAVPPeer Sid:%s Dest:%s\n",
						  sid.c_str(),dest->GetPeerName().c_str()));
			  return true;
		  }
		  return false;
}
*/

bool DraRouting::findAVPPeerList(const multimap<int,std::string>& codeMapArg, bool &result, DiameterPeerEntry *&dest, string sid)
{
        std::lock_guard<std::mutex> lk(mAVPRoutingMutex);

        multimap<int,std::string> codeMap;
        std::vector<int> discardedAVPs;

        // 1. Pre-extract all Subscription-Id-Types (AVP 450) to preserve their order
        std::vector<std::string> subscriptionTypes;
        auto range450 = codeMapArg.equal_range(450);
        for (auto it = range450.first; it != range450.second; ++it)
        {
            subscriptionTypes.push_back(it->second);
        }

        size_t count444 = 0;

        for(auto Iterator = codeMapArg.begin(); Iterator != codeMapArg.end(); ++Iterator)
        {
            AAA_LOG((LM_DEBUG, "%T |DRA_APP| Code:%d Value:%s Sid:%s \n",
                     Iterator->first, Iterator->second.c_str(), sid.c_str()));

            bool shouldDiscard = false;

            if (Iterator->first == 444)
            {
                // Correlate the current Subscription-Id-Data (444) with its matching Subscription-Id-Type (450)
                std::string subscriptionType = "";
                if (count444 < subscriptionTypes.size())
                {
                    subscriptionType = subscriptionTypes[count444];
                }
                count444++;

                AAA_LOG((LM_DEBUG, "%T |DRA_APP| Correlated Subscription-Id-Data index %d with Type: %s\n",
                         static_cast<int>(count444 - 1), 
                         subscriptionType.empty() ? "N/A" : subscriptionType.c_str()));

                if (subscriptionType == "3" || subscriptionType == "4")
                {
                    if (Iterator->second.length() > 128)
                    {
                        shouldDiscard = true;
                    }
                }
                else if (subscriptionType == "1" || subscriptionType.empty())
                {
                    // Default strict validation for E164/unknown types or missing type
                    if (Iterator->second.length() > 15)
                    {
                        shouldDiscard = true;
                    }
                }
            }

            if (shouldDiscard)
            {
                AAA_LOG((LM_ERROR, "%T |DRA_APP| Match Failed AVP Code:%d Value:%s due to length validation failure\n",
                         Iterator->first, Iterator->second.c_str()));
                discardedAVPs.push_back(Iterator->first);
                continue;
            }

            codeMap.insert(*Iterator);
        }

        for(multimap<std::string,std::string>::iterator lIterator = mApplicationData.routingData.avpRoutingMap.begin();
                        lIterator != mApplicationData.routingData.avpRoutingMap.end(); ++lIterator)
        {
                std::string keyName                     = lIterator->first;
                std::string keyMethodName       = lIterator->second;
                std::string lastOper;
                lastOper.clear();

                auto it = mApplicationData.avpFormsList.find(keyName);

                if(it != mApplicationData.avpFormsList.end())
                {
                        list<AVPPeerData> lAVPPeerDataList = it->second;
                        bool lContinue                     = true;
                        int cnt                            = codeMap.size();
                        int i                              = 0;

                        // Fix stack corruption by using std::vector
                        std::vector<bool> resultSet(lAVPPeerDataList.size(), false);

                        for(list<AVPPeerData>::iterator IteList = lAVPPeerDataList.begin(); IteList!=lAVPPeerDataList.end(); ++IteList)
                        {
                                bool matchedAny = false;
                                std::string lRegExp = IteList->avpValue;
                                auto range = codeMap.equal_range(IteList->code);

                                for (auto mapIt = range.first; mapIt != range.second; ++mapIt)
                                {
                                        AAA_LOG((LM_DEBUG, "%T |DRA_APP_TBR| Code:%d Exp:%s RegExp:%s Key:%s Method:%s Sid:%s TBR \n",
                                                 mapIt->first, mapIt->second.c_str(), lRegExp.c_str(), keyName.c_str(), keyMethodName.c_str(), sid.c_str() ));

                                        if(true == IsMatch((char*)lRegExp.c_str(), (char*)mapIt->second.c_str() ))
                                        {
                                                AAA_LOG((LM_DEBUG, "%T |DRA_APP| Exp:%s RegExp:%s Key:%s Method:%s Sid:%s\n",
                                                         mapIt->second.c_str(), lRegExp.c_str(), keyName.c_str(), keyMethodName.c_str(), sid.c_str() ));
                                                matchedAny = true;
                                                break;
                                        }
                                }

                                if (matchedAny)
                                {
                                        resultSet[i] = true;
                                        if(i > 0)
                                        {
                                                result = evaluteExp(resultSet[i-1], resultSet[i], lastOper);
                                                if(result == false)
                                                {
                                                        lContinue = false;
                                                }
                                                lastOper = IteList->avpOperation;
                                        }
                                        else
                                        {
                                                lastOper = IteList->avpOperation;
                                                result = true;
                                        }
                                }
                                else
                                {
                                        if (range.first != range.second) {
                                                AAA_LOG((LM_DEBUG, "%T |DRA_APP| Regex did not match any values for Code:%d Sid:%s\n",
                                                         IteList->code, sid.c_str()));
                                        } else {
                                                bool wasDiscarded = false;
                                                for (int dCode : discardedAVPs) {
                                                    if (dCode == IteList->code) {
                                                        wasDiscarded = true;
                                                        break;
                                                    }
                                                }

                                                if (wasDiscarded) {
                                                        AAA_LOG((LM_DEBUG, "%T |DRA_APP| AVP validation failed (invalid length), Key:%s Method:%s AVPCode:%d Sid:%s\n",
                                                                 keyName.c_str(), keyMethodName.c_str(), IteList->code, sid.c_str()));
                                                } else {
                                                        AAA_LOG((LM_DEBUG, "%T |DRA_APP| AVP not found, Key:%s Method:%s AVPCode:%d Sid:%s\n",
                                                                 keyName.c_str(), keyMethodName.c_str(), IteList->code, sid.c_str()));
                                                }
                                        }
                                        resultSet[i] = false;
                                        lContinue    = false;
                                        result       = false;
                                }
                                i++;
                        }

                        if(lContinue == true)
                        {
                                auto iter2 = mApplicationData.routingNameMap.find(keyMethodName);
                                if(iter2 != mApplicationData.routingNameMap.end())
                                {
                                        EnumRoutingType lRoutingType = iter2->second;
                                        switch(lRoutingType)
                                        {
                                                case ROUND_ROBIN:
                                                {
                                                        if(false == findRRPeer(keyMethodName, dest, sid))
                                                        {
                                                                return false;
                                                        }
                                                        return true;
                                                }
                                                case FAIL_OVER:
                                                {
                                                        if(false == findFOPeer(keyMethodName, dest, sid))
                                                        {
                                                                return false;
                                                        }
                                                        return true ;
                                                }
                                                case WEIGHTAGE:
                                                {
                                                        if( false == findWTPeer(keyMethodName, dest, sid ))
                                                        {
                                                                return false;
                                                        }
                                                        return true;
                                                }
                                                case UNKNOWN:
                                                default:
                                                        AAA_LOG((LM_ERROR, "%T |DRA_APP| Unknown Routing Type, Key:%s Method:%s RoutingType:%d Sid:%s\n",
                                                                 keyName.c_str(),keyMethodName.c_str(),lRoutingType , sid.c_str()));
                                                        break;
                                        }
                                }
                                else
                                {
                                        AAA_LOG((LM_ERROR, "%T |DRA_APP| Method not found, Key:%s Method:%s Sid::%s\n",
                                                 keyName.c_str(),keyMethodName.c_str(), sid.c_str()));
                                }
                        }
                        else
                        {
                                i = 0;
                                lContinue = true;
                                AAA_LOG((LM_ERROR, "%T |DRA_APP| Match not found, Key:%s Method:%s Sid:%s\n",
                                         keyName.c_str(),keyMethodName.c_str() , sid.c_str()));
                                continue;
                        }
                }
        }

        if (getActiveDefPeer(dest, sid))
        {
                AAA_LOG((LM_DEBUG, "%T |DRA_APP| DraRouting::findAVPPeer Sid:%s Dest:%s\n",
                         sid.c_str(),dest->GetPeerName().c_str()));
                return true;
        }
        return false;
}

