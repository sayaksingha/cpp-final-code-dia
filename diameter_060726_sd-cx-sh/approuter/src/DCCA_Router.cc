#include<DCCA_Router.h>

//-------------------------------------------------------------------------------------------------------
// METHOD      : DCCA_String() 
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
DCCA_String::DCCA_String()
{

}

//-------------------------------------------------------------------------------------------------------
// METHOD      : ~DCCA_String() 
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
DCCA_String::~DCCA_String()
{

}

//-------------------------------------------------------------------------------------------------------
// METHOD      : GetValue()
// DESCRIPTION :
// PARAMETER   : boost::any &Val, string &Data
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_String::GetValue( boost::any &Val, string &Data)
{
	try
	{
		Data = boost::any_cast<string>(Val);
		return true;
	}
	catch (boost::bad_any_cast &e)
	{
		//boost::cast error
	}
	return false;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : IsMatched()
// DESCRIPTION :
// PARAMETER   : const string &RegExp, string &InputStr, int &MatchedLen
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_String::IsMatched( string &RegExp, string &InputStr, int &MatchedLen)
{
	MatchedLen = 0; //Reset
	boost::regex lRegex (RegExp);
	boost::match_results < std::string::const_iterator > lMatch;

	int lRet = boost::regex_match (InputStr, lMatch, lRegex);

	if (0 == lRet || ( lMatch[0].matched == false))
	{
		//Not matched.
//		AAA_LOG((LM_DEBUG,""));
		return false;
	}

	for (unsigned int i=1; i < lMatch.size(); i++)
	{
		if ( lMatch[i].length() != 0)
			MatchedLen += lMatch[i].length();
	}
	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Execute()
// DESCRIPTION :
// PARAMETER   : multimap< int, boost::any> &DataMap, int &MatchedLen
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_String::Execute( multimap< int, boost::any> &DataMap, int &MatchedLen, string &lSessionId)
{
	pair <multimap<int, boost::any>::iterator, multimap<int, boost::any>::iterator> mmit;
	mmit = DataMap.equal_range(mAvpCode);

	if ( mmit.first ==  mmit.second)
	{
		//Avp not found Error.. Need to add log
		//Check for the default value. ----Need to think about this
		AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| SId:%s AVP:%d AvpNot found\n", lSessionId.c_str(), mAvpCode));//TBC-Anshul 28-dec
		return false;
	}
	else
	{
		for( auto mmcit = mmit.first; mmcit != mmit.second; mmcit++)
		{
			string lInputStr;
			if ( GetValue( mmcit->second, lInputStr))
			{
				for ( auto it = mRuleList.begin(); it != mRuleList.end(); it++)
				{
					if ( IsMatched( *it, lInputStr, MatchedLen))
					{
						//Matched...
						AAA_LOG((LM_DEBUG,"%T |CC_APP_ROUTER| Sid:%s AVP:%d SD:%s condition matched\n",
                           lSessionId.c_str(), mAvpCode, lInputStr.c_str() )); //TBC-Anshul 28-dec
						return true;
					}
				}
			}
		}
	}
	//Nothing matched.
	AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| SId:%s AVP:%d Condition not matched\n", lSessionId.c_str(), mAvpCode));//TBC-Anshul -28-dec
	return false;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : SetValue()
// DESCRIPTION :
// PARAMETER   : int &avpCode, string &avpName, boost::any &avpList
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_String::SetValue( int &avpCode, string &avpName, boost::any avpList)
{
	try
	{
		mRuleList = boost::any_cast<list<string> >(avpList);
	}
	catch (boost::bad_any_cast &e)
	{
		//boost::cast error
		return false;
	}
	mAvpCode = avpCode;
	mAvpName = avpName;
	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : GetAvpCode()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : int
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
int DCCA_String::GetAvpCode()
{
	return mAvpCode; 
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Display()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : void
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void  DCCA_String::Display()
{
	DCCA_DEF_PRINT_STR();
	DCCA_PRINT_LINE();
	DCCA_PRINT_DATA( "AvpCode",  mAvpCode, "AvpName", mAvpName);
	DCCA_PRINT_HYPEN_LINE();

	auto it = mRuleList.begin(); 
	int count = 1;
	while( it != mRuleList.end())
	{
		string lFirstData = *it;
		string lConterNameF = "RULE->" + count;
		it++;
		count++;
		string lSecondData  = ""; 
		string lConterNameS = "";
		if ( it != mRuleList.end())
		{
			lConterNameS = "RULE->" + count;
			count++;
			lSecondData = *it;
		}

		DCCA_PRINT_DATA( lConterNameF,  lFirstData, lConterNameS, lSecondData);
	}
	DCCA_PRINT_LINE();
	return ; 
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : DCCA_Numeric()  
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
DCCA_Numeric::DCCA_Numeric()
{

}

//-------------------------------------------------------------------------------------------------------
// METHOD      : ~DCCA_Numeric()
// DESCRIPTION :
// PARAMETER   : None
// RETURN      : None
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
DCCA_Numeric::~DCCA_Numeric()
{

}

//-------------------------------------------------------------------------------------------------------
// METHOD      : GetValue()
// DESCRIPTION : 
// PARAMETER   : boost::any &Val, int &Data
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_Numeric::GetValue( boost::any &Val, int &Data, string &lSessionId)
{
	try
	{
		Data = boost::any_cast<int>(Val);
		return true;
	}
	catch (boost::bad_any_cast &e)
	{
		AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| SId:%s bad cast cought Err:%s\n", lSessionId.c_str(), e.what()));
	}
	return false;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : IsMatched
// DESCRIPTION :
// PARAMETER   : int &StoredData, int &Input
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_Numeric::IsMatched( int &StoredData, int &Input, string &lSessionId)
{
	if ( StoredData == -99) //Wild card
	{
		AAA_LOG((LM_DEBUG,"%T |CC_APP_ROUTER| SId:%s SD:%d IP:%d RuleMatched \n", lSessionId.c_str(), StoredData, Input));
		return true;
	}

	if ( StoredData == Input)
	{
		AAA_LOG((LM_DEBUG,"%T |CC_APP_ROUTER| SId:%s SD:%d IP:%d RuleMatched \n", lSessionId.c_str(), StoredData, Input));
		return true;
	}

	AAA_LOG((LM_DEBUG,"%T |CC_APP_ROUTER| SId:%s SD:%d IP:%d RuleNotMatched \n", lSessionId.c_str(), StoredData, Input));
	return false;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Execute
// DESCRIPTION : 
// PARAMETER   : multimap< int, boost::any> &DataMap, int &MatchedLen
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_Numeric::Execute( multimap< int, boost::any> &DataMap, int &MatchedLen, string &lSessionId)
{
	MatchedLen = 0;
	pair <multimap<int, boost::any>::iterator, multimap<int, boost::any>::iterator> mmit;
	mmit = DataMap.equal_range(mAvpCode);

	if ( mmit.first ==  mmit.second)
	{
		//Avp not found Error.. Need to add log
		//Check for the default value. ----Need to think about this
		AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| SId:%s AVP:%d AvpNot found\n", lSessionId.c_str(), mAvpCode));
		return false;
	}
	else
	{
		for( auto mmcit = mmit.first; mmcit != mmit.second; mmcit++)
		{
			int lInput;
			if ( GetValue( mmcit->second, lInput, lSessionId))
			{
				for ( auto it = mRuleList.begin(); it != mRuleList.end(); it++)
				{
					if ( IsMatched(*it, lInput, lSessionId))
					{
						//Matched...
						AAA_LOG((LM_DEBUG,"%T |CC_APP_ROUTER| SId:%s AVP:%d SD:%d IP:%d condition matched\n", 
									lSessionId.c_str(), mAvpCode, lInput, *it ));
						return true;
					}
				}
			}
		}
	}
	//Nothing matched.
	AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| SId:%s AVP:%d Condition not matched\n", lSessionId.c_str(), mAvpCode));
	return false;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : SetValue
// DESCRIPTION :
// PARAMETER   : int &avpCode, string &avpName, boost::any &avpList
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_Numeric::SetValue( int &avpCode, string &avpName, boost::any avpList)
{
	try
	{
		mRuleList = boost::any_cast<list<int> >(avpList);
	}
	catch (boost::bad_any_cast &e)
	{
		AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| AN:%s AVP:%d Bad cast cought: err:%s\n", avpName.c_str(), avpCode, e.what()));
		return false;
	}
	mAvpCode = avpCode;
	mAvpName = avpName;
	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : GetAvpCode()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : int
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
int DCCA_Numeric::GetAvpCode()
{
	return mAvpCode; 
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Display()
// DESCRIPTION :
// PARAMETER   : 
// RETURN      : void
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void  DCCA_Numeric::Display()
{
	DCCA_DEF_PRINT_STR();
	DCCA_PRINT_LINE();
	DCCA_PRINT_DATA( "AvpCode",  mAvpCode, "AvpName", mAvpName);
	DCCA_PRINT_HYPEN_LINE();

	auto it = mRuleList.begin(); 
	int count = 1;
	while( it != mRuleList.end())
	{
		string lFirstData = to_string(*it);
		string lConterNameF = "RULE->" + count;
		it++;
		count++;
		string lSecondData  = ""; 
		string lConterNameS = "";

		if ( it != mRuleList.end())
		{
			lConterNameS = "RULE->" + count;
			count++;
			lSecondData = to_string(*it);
		}
		DCCA_PRINT_DATA( lConterNameF,  lFirstData, lConterNameS, lSecondData);
	}
	DCCA_PRINT_LINE();
	return ; 
}

//*******************************************************************************************************
//CLASS: DCCA_LoadAvpDetails
//*******************************************************************************************************

//-------------------------------------------------------------------------------------------------------
// METHOD      : DCCA_LoadAvpDetails()
// DESCRIPTION :
// PARAMETER   : boost::property_tree::ptree, list<DCCA_AvpInfo>
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
//DCCA_LoadAvpDetails::DCCA_LoadAvpDetails( DCCA_RouteIdentfier lIdentifier)
DCCA_LoadAvpDetails::DCCA_LoadAvpDetails( )
{
	mFileName = DCCA_CONFIG_HDLR()->mAvpFileName;
	mFilePath = DCCA_CONFIG_HDLR()->mAvpFilePath;
	//mRouteIdentifier = lIdentifier;
}
//-------------------------------------------------------------------------------------------------------
// METHOD      : DecodeAvpInfo()
// DESCRIPTION :
// PARAMETER   : boost::property_tree::ptree, list<DCCA_AvpInfo>
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_LoadAvpDetails::DecodeAvpInfo( boost::property_tree::ptree pt, list<DCCA_AvpInfo>  &_AvpInfoList)
{
	bool           lAddFlag  = true;
	DCCA_AvpInfo   lAvpInfo;
	bool		  lAvpFlag  = false;
	bool		  lAvpNFlag = false;
	bool		  lDtFlag   = false;

	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child(""))
	{
		if ( boost::iequals(v.first, ""))
		{
			if (!v.second.empty())
			{
				lAddFlag = false;
				if (!DecodeAvpInfo(v.second, _AvpInfoList))
				{
					AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| Key:%s Failed to decode avp rules\n", v.first.c_str() ));
					return false;
				}
				continue;
			}
		}

		if ( boost::iequals(v.first, "AVP_CODE"))
		{
			lAvpFlag = true;
			lAvpInfo.mAvpCode = stoi(v.second.data());
		}
		else if ( boost::iequals(v.first, "AVP_NAME"))
		{
			lAvpNFlag = true;
			lAvpInfo.mAvpName = v.second.data();
		}
		else if ( boost::iequals(v.first, "DATA_TYPE"))
		{
			lDtFlag = true;
			if ( boost::iequals(v.second.data(), "NUMERIC"))
			{
				lAvpInfo.mAvpDataType = DCCA_NUMERIC;
			}
			else
			{
				lAvpInfo.mAvpDataType = DCCA_STRING;
			}
		}
	}

	if ( lAddFlag)
	{
		if ( lDtFlag && lAvpNFlag && lAvpFlag ) {
			_AvpInfoList.push_back(lAvpInfo);
		}
		else  {
			AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| DTF:%d ANFlg:%d AvpFlg:%d Failed to decode avp rules\n", lDtFlag, lAvpNFlag, lAvpFlag ));
			return false;
		}
	}

	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Decode()
// DESCRIPTION :
// PARAMETER   : boost::property_tree::ptree, list<DCCA_AvpInfo>
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_LoadAvpDetails::Decode( boost::property_tree::ptree pt, list<DCCA_AvpInfo>  &_AvpInfoList )
{
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child(""))
	{
		if ( boost::iequals(v.first, "APPLICATION_ROUTE_AVP_DET"))
		{
			if (!v.second.empty())
			{
				if (!DecodeAvpInfo(v.second, _AvpInfoList))
				{
					AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| Key:%s Failed to decode avp rules\n", v.first.c_str() ));
					return false;
				}
			}
		}
	}
	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Decode()
// DESCRIPTION :
// PARAMETER   : boost::property_tree::ptree, list<DCCA_AvpInfo>
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_LoadAvpDetails::LoadAvpDetails()
{
	try
	{
		list<DCCA_AvpInfo>           _AvpInfoList;
      string                        lRouteIdStr;

      switch(mRouteIdentifier)
      {
         case DCCA_SERVER:
            {
               lRouteIdStr = "server";
            }
            break;
         case DCCA_CLIENT:
            {
               lRouteIdStr = "client";
            }
            break;
         case DCCA_PROXY:
            {
               lRouteIdStr = "proxy";
            }
            break;
         default:
            {
               lRouteIdStr = "proxy";
            }
      }

      string            mFileFP = mFilePath + "/" + lRouteIdStr  + "/" + mFileName ;

		boost::property_tree::ptree  pt;

		boost::property_tree::read_json(mFileFP, pt);

		if ( !Decode(pt, _AvpInfoList))
		{
			AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| Failed load avp map details\n"));
			return false;
		}
		int count = 1;
		for ( auto it = _AvpInfoList.begin(); it != _AvpInfoList.end(); it++)
		{
			it->mAvpPosition = count;
			it->mPriority = DCCA_MAX_ROUTE_BIT_SUPPORTED - count;
			count++;
			mAvpInfoANMap.insert(make_pair(it->mAvpName, *it));
			mAvpInfoACMap.insert(make_pair(it->mAvpCode, *it));
		}
			AAA_LOG((LM_DEBUG,"%T |CC_APP_ROUTER| success load avp map details\n"));
		return true;
	}
	catch (std::exception const& e)
	{
		AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| Json read err. err:%s .Failed load read avp map details\n", e.what() ));
	}
	return false;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Display()
// DESCRIPTION :
// PARAMETER   : DCCA_InputRouteRule
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DCCA_LoadAvpDetails::Display(bool lAvpNameMap)
{
	DCCA_DEF_PRINT_STR();
	DCCA_PRINT_HYPEN_LINE();
	if ( lAvpNameMap )
	{
		for( auto it = mAvpInfoANMap.begin(); it != mAvpInfoANMap.end(); it++)
		{
			DCCA_PRINT_LINE();
			DCCA_PRINT_DATA( "HKey", it->first, "AvpName", it->second.mAvpName );
			DCCA_PRINT_DATA( "AvpCode", it->second.mAvpCode, "DataType", it->second.mAvpDataType );
			DCCA_PRINT_DATA( "Priority", it->second.mPriority, "Position", it->second.mAvpPosition );
			DCCA_PRINT_LINE();
		}
	}
	else
	{
		for( auto it = mAvpInfoACMap.begin(); it != mAvpInfoACMap.end(); it++)
		{
			DCCA_PRINT_LINE();
			DCCA_PRINT_DATA( "HKey", it->first, "AvpName", it->second.mAvpName );
			DCCA_PRINT_DATA( "AvpCode", it->second.mAvpCode, "DataType", it->second.mAvpDataType );
			DCCA_PRINT_DATA( "Priority", it->second.mPriority, "Position", it->second.mAvpPosition );
			DCCA_PRINT_LINE();
		}

	}
	DCCA_PRINT_HYPEN_LINE();
	return;
}


//*******************************************************************************************************
//CLASS: DCCA_PrepareRouteRegData
//*******************************************************************************************************
//-------------------------------------------------------------------------------------------------------
// METHOD      : GetApplicationValue()
// DESCRIPTION :
// PARAMETER   : boost::property_tree::ptree, list<string>
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool  DCCA_PrepareRouteRegData::GetApplicationValue(boost::property_tree::ptree pt, list<string> &lDataList)
{
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child(""))
	{
		lDataList.push_back(v.second.data());
	}
	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : DecodeApplicationDet()
// DESCRIPTION :
// PARAMETER   : boost::property_tree::ptree, DCCA_InputRouteRule
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool  DCCA_PrepareRouteRegData::DecodeApplicationDet(boost::property_tree::ptree pt, DCCA_InputRouteRule &_InputRouteRule)
{
	string       lKeyName;
	list<string> lDataList;
	bool         lAddFlag = true;
	map<string,list<string> > lRuleMap;

	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child(""))
	{
		if ( boost::iequals(v.first, ""))
		{
			if (!v.second.empty())
			{
				lAddFlag = false;
				if (!DecodeApplicationDet(v.second, _InputRouteRule))
				{
					AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| Key:%s Error decoding application input data\n", v.first.c_str() ));
					return false;
				}
				continue;
			}
		}
		else
		{
			lKeyName = v.first;
			if (!v.second.empty())
			{
				if (!GetApplicationValue( v.second, lDataList))
				{
					AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| Key:%s Error decoding application input data\n", v.first.c_str() ));
					return false;
				}
			}

			lRuleMap.insert(make_pair(lKeyName, lDataList));
			AAA_LOG((LM_DEBUG , "%T |CC_APP_ROUTER| data is inserted into rule map\n")); //TBC-Anshul 26-12-18
			lKeyName = "";
			lDataList.clear();
		}
	}

	if (lAddFlag)
	{
		_InputRouteRule.mRuleSetList.push_back(lRuleMap);
	}
	AAA_LOG((LM_DEBUG , "%T |CC_APP_ROUTER| success decoding application input data\n"));
	return true;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : DecodeApplication()
// DESCRIPTION :
// PARAMETER   : boost::property_tree::ptree, DCCA_InputRouteRule 
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_PrepareRouteRegData::DecodeApplication( boost::property_tree::ptree pt, DCCA_InputRouteRule &_InputRouteRule)
{
	bool lApplnIdFlg 	= false;
	bool lApplnNameFlg 	= false;
	bool lRuleSetFlg 	= false;

	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child(""))
	{
		if ( boost::iequals(v.first, "APPLICATION_NAME"))
		{
			lApplnIdFlg = true;
			_InputRouteRule.mApplicationName = v.second.data();
		}
		else if ( boost::iequals(v.first, "APPLICATION_ID"))
		{
			lApplnNameFlg = true;
			_InputRouteRule.mApplicationId   = stoi(v.second.data());
		}
		else if ( boost::iequals(v.first, "RULE_SET"))
		{
			lRuleSetFlg = true;
			DecodeApplicationDet(v.second, _InputRouteRule);
		}
	}

	if ( lApplnIdFlg && lApplnNameFlg && lRuleSetFlg) 
		return true; 

	AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| Key:APPLICATION_NAME-T Error decoding application input data\n"));
	return false;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Decode()
// DESCRIPTION :
// PARAMETER   : boost::property_tree::ptree, DCCA_InputRouteRule
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_PrepareRouteRegData::Decode( boost::property_tree::ptree pt, DCCA_InputRouteRule &_InputRouteRule )
{
	bool lApplnFlg = false;
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child(""))
	{
		if ( boost::iequals(v.first, "APPLICATION"))
		{
			if (!v.second.empty())
			{
				lApplnFlg = true;
				if(!DecodeApplication(v.second, _InputRouteRule))
				{
					AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| Key:%s Error decoding application input data\n", v.first.c_str() ));
					return false;
				}
			}
		}
	}

	if (lApplnFlg)
		return true;

	AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| Key:APPLICATION Error decoding application input data\n"));
	return false;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : PrepareRouteRegData()
// DESCRIPTION :
// PARAMETER   : string, string, DCCA_InputRouteRule
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
bool DCCA_PrepareRouteRegData::PrepareRouteRegData(string path, string fileName, DCCA_InputRouteRule &_InputRouteRule)
{
	try
	{
		string lFileNamePath = path + fileName;
		boost::property_tree::ptree pt;
		boost::property_tree::read_json(lFileNamePath, pt);
		Decode(pt, _InputRouteRule );
		return true;
	}
	catch (std::exception const& e)
	{
		AAA_LOG((LM_ERROR,"%T |CC_APP_ROUTER| Json read err. err:%s .Failed load Application Input rules details\n", e.what() ));
	}
	return false;
}

//-------------------------------------------------------------------------------------------------------
// METHOD      : Display()
// DESCRIPTION :
// PARAMETER   : DCCA_InputRouteRule
// RETURN      : bool
// THROWS      : None
//-------------------------------------------------------------------------------------------------------
void DCCA_PrepareRouteRegData::Display(DCCA_InputRouteRule &_InputRouteRule)
{
	DCCA_DEF_PRINT_STR();
	DCCA_PRINT_LINE();
	DCCA_PRINT_DATA( "ApplnName", _InputRouteRule.mApplicationName, "ApplnId", _InputRouteRule.mApplicationId);
	DCCA_PRINT_HYPEN_LINE();

	for( auto loit = _InputRouteRule.mRuleSetList.begin();
			loit != _InputRouteRule.mRuleSetList.end();
			loit++ )
	{
		for( auto it = loit->begin(); it != loit->end(); it++)
		{
			DCCA_PRINT_DATA( "Key:", it->first, "", "");
			auto lit = it->second.begin();
			int count = 1;
			while(lit != it->second.end())
			{
				string lFirstData = *lit;
				string lConterNameF = "RULE->" + count;
				lit++;
				count++;
				string lSecondData  = ""; 
				string lConterNameS = "";
				if ( lit != it->second.end())
				{
					lConterNameS = "RULE->" + count;
					count++;
					lSecondData = *lit;
				}

				DCCA_PRINT_DATA( lConterNameF,  lFirstData, lConterNameS, lSecondData);
			}
		}
	}
	DCCA_PRINT_LINE();
	return;
}

