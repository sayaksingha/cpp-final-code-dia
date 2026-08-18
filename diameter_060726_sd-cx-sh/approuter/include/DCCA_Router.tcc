#include "DCCA_Header.h"
#include "DCCA_Router.h"

//-------------------------------------------------------------
// METHOD      : DCCA_ApplicationRouter_S()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::DCCA_ApplicationRouter_S()
{	
	//DCCA_LoadAvpDetails(ROUTE_APPLICATION_IDENTIFIER);
	mRouteIdentifier = ROUTE_APPLICATION_IDENTIFIER;
	LastMsgCounter = 1;
}

//-------------------------------------------------------------
// METHOD      : DCCA_ApplicationRouter_S()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::DCCA_ApplicationRouter_S( DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ> const& DCCA_ApplicationRouterObj)
{
}

//-------------------------------------------------------------
// METHOD      : DCCA_ApplicationRouter_S()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>& DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::operator=( DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ> const& DCCA_ApplicationRouterObj)
{
	DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>  *DCCA_ApplicationRouterPtr = new DCCA_ApplicationRouter_S();
	return *DCCA_ApplicationRouterPtr;
}

//-------------------------------------------------------------
// METHOD      : GetInstance()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>* DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::GetInstance()
{
	if( mDCCA_ApplicationRouter == NULL)
	{
		lock_guard<mutex> myLock(*mMutexLock);
		if ( mDCCA_ApplicationRouter == NULL)
		{
			mDCCA_ApplicationRouter = new DCCA_ApplicationRouter_S();
			if (!mDCCA_ApplicationRouter->Init()) // Loading data will be taken care by thread
			{
				AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| Error loading Routing configuration\n"));
				delete mDCCA_ApplicationRouter;
				mDCCA_ApplicationRouter = 0;
			}
		}
	}
	return mDCCA_ApplicationRouter;
}

//-------------------------------------------------------------
// METHOD      : GetInstance()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
bool DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::Init()
{
	if (!this->DCCA_LoadAvpDetails::LoadAvpDetails())
		return false;

	return true;
}
//-------------------------------------------------------------------------------------------------------
// METHOD      : Register() 
// DESCRIPTION : 
// PARAMETER   : DCCA_InputRouteRule, shared_ptr<DCCA_INTERFACE_OBJ>, bool
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
bool DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::Register(DCCA_InputRouteRule &InputRouteRule, std::shared_ptr<DCCA_INTERFACE_OBJ> ptr, bool lRegFlg)
{
	//Upgrade the lock to get Exclusive lock
	boost::upgrade_lock< boost::shared_mutex > lock(mMutexAccess);
	boost::upgrade_to_unique_lock< boost::shared_mutex > uniqueLock(lock);
	//now we have exclusive access

	if ( lRegFlg )
	{
		auto mRMCIt = mRouteMap.find(InputRouteRule.mApplicationId);

		if ( mRMCIt !=  mRouteMap.end())
		{
			AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| AID:%d AN:%s Registration failed. Already application exist.\n", 
						InputRouteRule.mApplicationId, InputRouteRule.mApplicationName.c_str()));
			//Already registerd... send delete and register/ update
			return false;
		}
	}
	//list< map< string, list<string> > > mRuleSetList;
	for ( auto it = InputRouteRule.mRuleSetList.begin(); it != InputRouteRule.mRuleSetList.end(); it++)
	{
		//map< string, list<string> >
		DCCA_RouteRuleDet lRouteDet;
		std::bitset<DCCA_MAX_ROUTE_BIT_SUPPORTED>  lAvpBitSet;

		lRouteDet.mApplicationID   = InputRouteRule.mApplicationId;
		lRouteDet.mApplicationName = InputRouteRule.mApplicationName;

		for( auto mit = it->begin(); mit != it->end(); mit++)
		{
			auto lAvpIt = mAvpInfoANMap.find(mit->first);

			if ( lAvpIt == mAvpInfoANMap.end())
			{
				//Key name not found in master priority map..............
				AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| AID:%d AN:%s AVPName:%s Avp Details Mapping table not there. Registration failed.\n", 
							InputRouteRule.mApplicationId, InputRouteRule.mApplicationName.c_str(), mit->first.c_str()));
				return false;
			}

			lAvpBitSet[lAvpIt->second.mPriority] = 1;

			auto lAvpCntIt = mAvpMap.find(lAvpIt->second.mAvpCode);

			if (lAvpCntIt != mAvpMap.end() )
			{
				lAvpCntIt->second++;
			}
			else
			{
				mAvpMap.insert( make_pair( lAvpIt->second.mAvpCode, 1));
				mAvpList.push_back(lAvpIt->second.mAvpCode);
			}

			switch ( lAvpIt->second.mAvpDataType)
			{
				case DCCA_NUMERIC:
					{
						list<int>   lNumericList;
						//list<string>
						for( auto lit = mit->second.begin(); lit != mit->second.end(); lit++)
						{
							lNumericList.push_back(stoi(*lit));
							//try
							//{
							//	lNumericList.push_back(boost::any_cast<int>(*lit));
							//}
							//catch (boost::bad_any_cast &e)
							//{
						   //		AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| AID:%d AN:%s AVPName:%s DT:%d. bad cast cought: Err:%s. Registration failed.\n", 
							//				InputRouteRule.mApplicationId, InputRouteRule.mApplicationName.c_str(), mit->first.c_str(), lAvpIt->second.mAvpDataType, e.what()));
							//	return false;
							//}
						}

						shared_ptr<DCCA_RouteRuleExecuter> lRuleExePtr ( new DCCA_Numeric());
						lRuleExePtr->SetValue(lAvpIt->second.mAvpCode, lAvpIt->second.mAvpName, lNumericList);
						lRouteDet.mRouteRuleExecuterList.push_back(lRuleExePtr);
					}
					break;
				case DCCA_STRING:
					{
						list<string>   lStrList;
						//list<string>
						for( auto lit = mit->second.begin(); lit != mit->second.end(); lit++)
						{
							lStrList.push_back(*lit);
							//try
							//{
							//	lStrList.push_back(boost::any_cast<string>(*lit));
							//}
							//catch (boost::bad_any_cast &e)
							//{
							//	AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| AID:%d AN:%s AVPName:%s DT:%d. bad cast cought: Err:%s. Registration failed.\n", 
							//				InputRouteRule.mApplicationId, InputRouteRule.mApplicationName.c_str(), mit->first.c_str(), lAvpIt->second.mAvpDataType, e.what()));
							//	return false;
							//}
						}
						shared_ptr<DCCA_RouteRuleExecuter> lRuleExePtr ( new DCCA_String());
						lRuleExePtr->SetValue(lAvpIt->second.mAvpCode, lAvpIt->second.mAvpName, lStrList);
						lRouteDet.mRouteRuleExecuterList.push_back(lRuleExePtr);
					}
					break;
				case DCCA_INVALID:
				default:
					{
						AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| AID:%d AN:%s AVPName:%s DT:%d. Invalid datatype. Registration failed.\n", 
									InputRouteRule.mApplicationId, InputRouteRule.mApplicationName.c_str(), mit->first.c_str(), lAvpIt->second.mAvpDataType));
						return false;
					}
			}
		}

		//Add Rule Here.. once come out of the loop.
		//Prepare key.
		string lHKey = lAvpBitSet.to_string<char,string::traits_type, string::allocator_type>();

		auto mRRIt = mRouteRuleList.find(lHKey);

		if ( mRRIt != mRouteRuleList.end())
		{
			mRRIt->second.mRouteRuleDet.push_back(lRouteDet);
		}
		else
		{
			DCCA_RouteRule lRouteRule;
			lRouteRule.mKey = lHKey;
			lRouteRule.mRouteRuleDet.push_back(lRouteDet);
			mRouteRuleList.insert( make_pair(lRouteRule.mKey, lRouteRule));
		}
	}

	DCCA_RouteObjStore lRouteObjStore;
	lRouteObjStore.mApplicationId   = InputRouteRule.mApplicationId;
	lRouteObjStore.mRouterInterface = ptr;

	mRouteMap.insert( make_pair(lRouteObjStore.mApplicationId, lRouteObjStore));

	DCCA_LastRouteInfo lDCCA_LastRouteInfo( InputRouteRule.mApplicationId);
	mLastRouteInfo.insert( make_pair(InputRouteRule.mApplicationId, lDCCA_LastRouteInfo));

	AAA_LOG((LM_INFO,"%T |CC_APP_ROUTER| AID:%d AN:%s Registration sucess.\n", 
				InputRouteRule.mApplicationId, InputRouteRule.mApplicationName.c_str()));

	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Update 
// DESCRIPTION : 
// PARAMETER   : DCCA_InputRouteRule, shared_ptr<DCCA_INTERFACE_OBJ>
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
bool DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::Update(DCCA_InputRouteRule &InputRouteRule, shared_ptr<DCCA_INTERFACE_OBJ> ptr)
{
	//De-Register first if anything resgisterd;

	DeRegister(InputRouteRule.mApplicationId);

	//Reregister Application.
	if (!Register(InputRouteRule, ptr, false))
	{
		//registration failed.
		return false;
	}

	//registration success
	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : DeRegister()
// DESCRIPTION :
// PARAMETER   : ApplnId
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
bool DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::DeRegister( int &ApplnId)
{
	//Upgrade the lock to get Exclusive lock
	boost::upgrade_lock< boost::shared_mutex > lock(mMutexAccess);
	boost::upgrade_to_unique_lock< boost::shared_mutex > uniqueLock(lock);
	//now we have exclusive access

	auto it = mRouteRuleList.begin();
	while( it != mRouteRuleList.end())
	{
		auto rit = it->second.mRouteRuleDet.begin();
		while( rit != it->second.mRouteRuleDet.end())
		{
			if ( rit->mApplicationID == ApplnId )
			{
				for ( auto *lit = rit->mRouteRuleExecuterList.begin(); lit != rit->mRouteRuleExecuterList.end(); lit++)
				{
					int lAvpCode = lit->GetAvpCode();

					auto mit = mAvpMap.find(lAvpCode);
					if ( mit != mAvpMap.end())
					{
						if ( mit->second <= 1 )
						{
							mAvpMap.erase(mit);
							auto AlIt = mAvpList.begin();
							while( AlIt != mAvpList.end())
							{
								if ( *AlIt == lAvpCode)
								{
									mAvpList.erase(AlIt);
									break;
								}
							}
						}
						else
						{
							mit->second--;
						}
					}
				}
				rit = it->second.mRouteRuleDet.erase(rit);
			}
			else
			{
				rit++;
			}
		}

		if (it->second.mRouteRuleDet.empty())
		{
			it = mRouteRuleList.erase(it);
		}
		else
		{
			it++;
		}
	}

	auto RmIt = mRouteMap.find(ApplnId);

	if ( RmIt != mRouteMap.end())
	{
		mRouteMap.erase(RmIt);
	}

	auto LRmIt = mLastRouteInfo.find(ApplnId);

	if( LRmIt !=  mLastRouteInfo.end())
	{
		mLastRouteInfo.erase(LRmIt);
	}
	//De->registration success
	AAA_LOG((LM_INFO,"%T |CC_APP_ROUTER| AID:%d DeRegistration sucess.\n", ApplnId ));
	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : GetInputAvpDetails()
// DESCRIPTION :
// PARAMETER   : NONE
// RETURN      : list<int> 
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
list<int> DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::GetInputAvpDetails()
{
	return mAvpList;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : GetApplicationId() 
// DESCRIPTION :
// PARAMETER   : Vector<DCCA_StoreMatchLen>, int
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
bool DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::GetApplicationId(vector<DCCA_StoreMatchLen>  &lVector, int &lApplnId)
{
	if (lVector.empty())
		return false;

	vector<DCCA_LastRouteInfo*>    lLastRouteInfo;

	//Aquire the unique lock 
	mMutex.lock();
	if ( LastMsgCounter >= 100000)
	{
		for ( auto vit = mLastRouteInfo.begin(); vit != mLastRouteInfo.end(); vit++)
		{
			vit->second.mLastSentCounter = 0;
		}
		LastMsgCounter = 1;
	}

	auto it = lVector.begin();

	int lFirstLen = it->mLen;

	while( it != lVector.end())
	{
		if (lFirstLen == it->mLen)
		{
			auto rit = mLastRouteInfo.find(it->mApplicationId);
			
			if (rit == mLastRouteInfo.end())
			{
				it++;
				continue;
			}

			lLastRouteInfo.push_back(&rit->second);
		}
		else
		{
			break;
		}
	}

	if ( lLastRouteInfo.empty())
	{
		//Release the unique lock 
		mMutex.unlock();
		return false;
	}

	std::sort(lLastRouteInfo.begin(), lLastRouteInfo.end(), DCCA_LastRouteInfo::Sortfunction); //Sort algorithm.

	auto lrit = lLastRouteInfo.begin();
	
	++LastMsgCounter;
	(*lrit)->SetLastSentCounter(LastMsgCounter);

	lApplnId = (*lrit)->mApplicationId;

	//Release the unique lock 
	mMutex.unlock();
	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : ApplyRRRouting 
// DESCRIPTION :
// PARAMETER   : const multimap< int , boost::any>, int, shared_ptr<DCCA_INTERFACE_OBJ>
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
bool DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::GetApplicationObj( int &applnId,
		shared_ptr<DCCA_INTERFACE_OBJ> &RouteInterface)
{
	auto lRoute = mRouteMap.find(applnId);

	if ( lRoute == mRouteMap.end())
	{
		AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| AID:%d Failed to get RouteObject.\n", applnId ));
		return false;
	}
	RouteInterface = lRoute->second.mRouterInterface;
	AAA_LOG((LM_DEBUG,"%T |CC_APP_ROUTER| AID:%d Success to get RouteObject.\n", applnId ));
	return true;
}
//-------------------------------------------------------------------------------------------------------
// METHOD      : ApplyRRRouting 
// DESCRIPTION :
// PARAMETER   : const multimap< int , boost::any>, int, shared_ptr<DCCA_INTERFACE_OBJ>
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
bool DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::ApplyRRRouting( multimap< int , boost::any> &DataMap, int &applnId,
		shared_ptr<DCCA_INTERFACE_OBJ> &RouteInterface, string &lSessionId)
{
	if ( ApplyRouting(DataMap, applnId, RouteInterface, lSessionId, true))
	{
		return true;
	}
	return false;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : ApplyRouting() 
// DESCRIPTION :
// PARAMETER   : multimap< int , boost::any>, int
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
bool DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::ApplyRouting( multimap< int , boost::any> &DataMap, int &applnId, shared_ptr<DCCA_INTERFACE_OBJ> &RouteInterface, string &lSessionId, bool lRRFlag)
{
	//Get the shared lock
	std::vector<DCCA_StoreMatchLen>   lVector;
	boost::shared_lock< boost::shared_mutex > lock(mMutexAccess);

	//Sorted reverse order of key priority..
	for ( auto rit = mRouteRuleList.rbegin(); rit != mRouteRuleList.rend(); rit++)
	{
		//key ===> rit->first
		//Data===> rit->second
		//map< string, DCCA_RouteRule > mRouteRuleList;
		bool                         lRuleMatchedFlg     = false;
		lVector.clear();
		for ( auto ait = rit->second.mRouteRuleDet.begin(); ait != rit->second.mRouteRuleDet.end(); ait++)
		{
			int   lMatchedLen = 0;
			int   lTotalLen   = 0;
			bool  lErrFlg     = false;

			if ( ait->mRouteRuleExecuterList.empty())
			{
				AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| SId:%s Rule list is empty\n", lSessionId.c_str() ));
				continue;
			}

			for ( auto asit = ait->mRouteRuleExecuterList.begin(); asit != ait->mRouteRuleExecuterList.end(); asit++ )
			{
				if ( !(*asit)->Execute(DataMap, lMatchedLen, lSessionId))
				{
					lErrFlg = true;
					break;
				}

				lTotalLen += lMatchedLen;
			}

			if ( lErrFlg)
			{
				AAA_LOG((LM_DEBUG,"%T |CC_APP_ROUTER| SId:%s Rule is not matched\n", lSessionId.c_str() ));
				continue;
			}
			lRuleMatchedFlg = true;
			DCCA_StoreMatchLen lStoreMatchLen( ait->mApplicationID, lTotalLen);
			lVector.push_back(lStoreMatchLen);
		}

		if ( !lRuleMatchedFlg)
		{
			AAA_LOG((LM_DEBUG,"%T |CC_APP_ROUTER| SId:%s Rule is not matched\n", lSessionId.c_str() ));
			continue;
		}

		std::sort(lVector.begin(), lVector.end(), DCCA_StoreMatchLen::SMSortfunction); //Sort algorithm.

		int lApplnId = 0;

		if (!lRRFlag)
		{
			auto it = lVector.begin();

			if ( it ==  lVector.end())
			{
				AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| SId:%s Error in sort algorithm\n", lSessionId.c_str() ));
				continue;
			}
			lApplnId = it->mApplicationId;
		}
		else
		{
			if (!GetApplicationId( lVector, lApplnId ))
			{
				AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| SId:%s Error in sort algorithm\n", lSessionId.c_str() ));
				continue;
			}
		}

		auto lRoute = mRouteMap.find(lApplnId);

		if ( lRoute == mRouteMap.end())
		{
			AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| SId:%s Major error. Application object not in stored. Memory corrupted.\n", lSessionId.c_str(), lApplnId ));
			continue;
		}

		applnId        = lRoute->second.mApplicationId;
		RouteInterface = lRoute->second.mRouterInterface;
		AAA_LOG((LM_INFO,"%T |CC_APP_ROUTER| SId:%s AID:%d Route found.\n", lSessionId.c_str(), lRoute->second.mApplicationId ));
		return true;
	}

	AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| SId:%s Failed to get RouteObject.\n", lSessionId.c_str() ));
	//Rule not found..
	return false;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Display()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : void
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
void  DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::Display()
{
	DCCA_DEF_PRINT_STR();
	//Dont call directly.
	for (auto it = mRouteRuleList.rbegin(); it != mRouteRuleList.rend(); it++)
	{
		DCCA_PRINT_LINE();
		DCCA_PRINT_DATA( "RoutePriority:",  it->first, "", "");

		for ( auto lit = it->second.mRouteRuleDet.begin(); lit != it->second.mRouteRuleDet.end(); lit++)
		{
			DCCA_PRINT_LINE();
			DCCA_PRINT_DATA( "ApplnName:",  lit->mApplicationName, "ApplnId", lit->mApplicationID);
			for ( auto oit = lit->mRouteRuleExecuterList.begin(); oit != lit->mRouteRuleExecuterList.end(); oit++)
			{
				(*oit)->Display();
			}
			DCCA_PRINT_LINE();
		}

	}
	return;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : DisplayReadLock()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : void
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
	template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
void  DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::DisplayReadLock()
{
	//Get the shared lock
	boost::shared_lock< boost::shared_mutex > lock(mMutexAccess);
	this->Display();
	return;
}
