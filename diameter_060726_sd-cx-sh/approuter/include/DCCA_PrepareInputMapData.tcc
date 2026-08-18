#include "DCCA_PrepareInputMapData.h"

//--------------------------------------------------------------------------------------------------------------------------------------------
// METHOD      : DecodeRequest() 
// DESCRIPTION : Does nothing
// PARAMETER   : std::shared_ptr<T_DIA_MSG>, list<int>, multimap< int, boost::any >
// RETURN      : BOOLEAN 
// THROWS      : None
//--------------------------------------------------------------------------------------------------------------------------------------------
template < typename T_DIA_MSG >
bool DCCA_PrepareInputMapData<T_DIA_MSG>::DecodeRequest( T_DIA_MSG &DiaMsgObj, 
		list<int> &InputAvpList, 
		multimap< int, boost::any >  &InputMapData , string &lSessionId )
{


	try{
		int mApplnId = (int)DiaMsgObj->getApplnId();
		InputMapData.insert( make_pair( DCCA_CONFIG_HDLR()->mApplnIdAvpCode, mApplnId)); // make configuration.

		for ( auto lit = InputAvpList.begin(); lit != InputAvpList.end(); lit++)
		{
			list<DiameterBaseInterface*> _List;
			bool _AvpNotFndFlg = DiaMsgObj->FindAll(NULL, *lit , _List, true);

			if(_AvpNotFndFlg)
			{
				for( auto* _sitem  : _List)
				{
					switch( _sitem->GetDataType() )
					{
						case  UNSIGNED32_TYPE :
							{
								int avpValue = (int)(reinterpret_cast<Unsigned32*>(_sitem))->getValue();
								InputMapData.insert(make_pair(*lit, avpValue));
							}
							break;
						case  ENUMERATED_TYPE :
							{
								int avpValue = (int)(reinterpret_cast<Integer32*>(_sitem))->getValue();
								InputMapData.insert(make_pair(*lit, avpValue));
							}
							break;
						case  INTEGER32_TYPE  :
							{
								int avpValue = (reinterpret_cast<Integer32*>(_sitem))->getValue();
								InputMapData.insert(make_pair(*lit, avpValue));
							}
							break;
						case  INTEGER64_TYPE  :
							{
								int avpValue = (int)(reinterpret_cast<Integer64*>(_sitem))->getValue();
								InputMapData.insert(make_pair(*lit, avpValue));
							}
							break;
						case  UNSIGNED64_TYPE :
							{
								int avpValue = (int)(reinterpret_cast<Unsigned64*>(_sitem))->getValue();
								InputMapData.insert(make_pair(*lit, avpValue));
							}
							break;
						case ADDRESS_TYPE:
							{
								string avpValue  = (reinterpret_cast<Address*>(_sitem))->ToString();
								InputMapData.insert(make_pair(*lit, avpValue));
							}
							break;
						case OCTETSTRING_TYPE :
							{
								string avpValue = (reinterpret_cast<OctetString*>(_sitem))->ToString();
								InputMapData.insert(make_pair(*lit, avpValue));
							}
							break;
						default:
							{
								AAA_LOG((LM_ERROR,"%T |CC_IP_MAP_GEN| SId:%s AVP:%d DT:%d Invalid data type\n", 
											lSessionId.c_str(), *lit, _sitem->GetDataType() ));
								//errorr
							}
					}
				}
			}
			else
			{
				AAA_LOG((LM_ERROR,"%T |CC_IP_MAP_GEN| SId:%s AVP:%d Avp details not present\n", lSessionId.c_str(), *lit ));
			}
		}
	}
	catch(TssDiameterMsgException d)
	{
		AAA_LOG((LM_ERROR,"%T |CC_IP_MAP_GEN| SId:%s Exception occured while decoding input param\n", lSessionId.c_str() ));
		return false;
	}

	return true;
}

//--------------------------------------------------------------------------------------------------------------------------------------------
// METHOD      : DecodeRequest() 
// DESCRIPTION : Does nothing
// PARAMETER   : std::shared_ptr<T_DIA_MSG>, list<int>, multimap< int, boost::any >
// RETURN      : BOOLEAN 
// THROWS      : None
//--------------------------------------------------------------------------------------------------------------------------------------------
	template < typename T_DIA_MSG >
bool DCCA_PrepareInputMapData<T_DIA_MSG>::DisplayMapData( multimap< INT32, boost::any >  &InputMapData )
{
	for ( auto it = InputMapData.begin(); it != InputMapData.end(); it++)
	{
		try
		{ 
			if ( it->second.type() == typeid(string))
			{
				string lData = boost::any_cast<string>(it->second);
				cout << " Key:" << it->first << " Data:" << lData << "\n";
			}
			else if ( it->second.type() == typeid(int))
			{
				int  lData = boost::any_cast<int>(it->second);
				cout << " Key:" << it->first << " Data:" << lData << "\n";
			}	
			else
			{
				//Invalid data type.
			}
		}
		catch (boost::bad_any_cast &e)
		{
			//Casting error
		}
	}
	return true;
} 

