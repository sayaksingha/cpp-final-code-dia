#ifndef DCCA_APP_ROUTE_H
#define DCCA_APP_ROUTE_H

#include "DCCA_Header.h"
#include "DCCA_ConfigHandler.h" 

//Class to Execute rules..
class DCCA_RouteRuleExecuter
{
	public:
		virtual bool SetValue( int &avpCode, string &avpName, boost::any avpList) = 0;
		virtual bool Execute( multimap< int, boost::any> &DataMap, int &MatchedLen, string &lSessionId) = 0;
		virtual int  GetAvpCode() = 0;
		virtual void Display() = 0;
};

//Class to Execute rules..
class DCCA_String: public DCCA_RouteRuleExecuter
{
	private:
		//Member variables
		int            mAvpCode;
		string         mAvpName; //Not mandatory.
		list<string>   mRuleList;

		//Methods
		bool GetValue( boost::any &Val, string &Data );
		bool IsMatched( string &RegExp, string &InputStr, int &MatchedLen );

	public:
		//Constructor
		DCCA_String();
		//Destructor
		~DCCA_String();

		//Methods
		bool Execute( multimap< int, boost::any> &DataMap, int &MatchedLen, string &lSessionId);
		bool SetValue( int &avpCode, string &avpName, boost::any avpList);
		int  GetAvpCode();
		void Display();
};

//Class to Execute rules..
class DCCA_Numeric: public DCCA_RouteRuleExecuter
{
	private:
		//Member variables
		int            mAvpCode;
		string         mAvpName; //Not mandatory.
		list<int>      mRuleList;

		//Methods
		bool GetValue( boost::any &Val, int &Data, string &lSessionId );
		bool IsMatched( int &StoredData, int &Input, string &lSessionId );

	public:
		//Constructor
		DCCA_Numeric();
		//Destructor
		~DCCA_Numeric();

		//Methods
		bool Execute( multimap< int, boost::any> &DataMap, int &MatchedLen, string &lSessionId);
		bool SetValue( int &avpCode, string &avpName, boost::any avpList);
		int  GetAvpCode();
		void Display();
};


class DCCA_ProxyHandler
{
	public:
		DCCA_ProxyHandler() {
		}

		virtual ~DCCA_ProxyHandler() {
		}

		/// This function is called when incomming request message is received
		virtual AAAReturnCode RequestMsg(DiameterMsg &msg,
				DiameterPeerEntry *source,
				DiameterPeerEntry *&dest) {
			// Incomming request messages are received here.
			return (AAA_ERR_SUCCESS);
		}

		/// This function is called when incomming answer message is received
		virtual AAAReturnCode AnswerMsg(DiameterMsg &msg,
				DiameterPeerEntry *source,
				DiameterPeerEntry *&dest) {
			return (AAA_ERR_SUCCESS);
		}

		/// This function is called when incomming error message is received
		virtual AAAReturnCode ErrorMsg(DiameterMsg &msg,
				DiameterPeerEntry *source,
				DiameterPeerEntry *&dest) {
			return (AAA_ERR_SUCCESS);
		}

		virtual int GetModuleId()= 0;
};



//Class to store Application Rule................
class DCCA_RouteRuleDet
{
	public:
		DCCA_RouteRuleDet(){}
		~DCCA_RouteRuleDet(){}

		int                                          mApplicationID;
		string                                       mApplicationName;
		list<shared_ptr<DCCA_RouteRuleExecuter> >    mRouteRuleExecuterList;
};

//Class to store Application Ruleset................
class DCCA_RouteRule
{
	public:
		string                     mKey;
		list<DCCA_RouteRuleDet>    mRouteRuleDet;
};


class DCCA_StoreMatchLen
{
   public:
    DCCA_StoreMatchLen(int ApplicationId, int Len):mApplicationId(ApplicationId),mLen(Len){}
    DCCA_StoreMatchLen(){}

    int mApplicationId;
    int mLen;

    static bool SMSortfunction ( DCCA_StoreMatchLen a, DCCA_StoreMatchLen b)
    {
       return (a.mLen > b.mLen);
    }
};

class DCCA_LastRouteInfo
{
	public:
		DCCA_LastRouteInfo( int applnId): mApplicationId(applnId),mLastSentCounter(0){}

		int   mApplicationId;
		int   mLastSentCounter;

		void SetLastSentCounter( int &Counter)
		{
			mLastSentCounter = Counter;
		}

		static bool Sortfunction ( DCCA_LastRouteInfo *a, DCCA_LastRouteInfo *b)
		{
			return (a->mLastSentCounter > b->mLastSentCounter);
		}
};

enum DCCA_RouteIdentfier
{
	DCCA_SERVER    = 1,
	DCCA_CLIENT    = 2,
	DCCA_PROXY     = 3
};


class DCCA_LoadAvpDetails
{
	public:

	//DCCA_LoadAvpDetails(DCCA_RouteIdentfier RouteId);	
	DCCA_LoadAvpDetails();	

	//Methods
	bool   	DecodeAvpInfo( boost::property_tree::ptree pt, list<DCCA_AvpInfo>  &_AvpInfoList);

	bool 	  	Decode( boost::property_tree::ptree pt, list<DCCA_AvpInfo>  &_AvpInfoList );

	bool 	  	LoadAvpDetails();

	void 	  	Display(bool lAvpNameMap);

	map< string, DCCA_AvpInfo>    mAvpInfoANMap; 

	map< int,    DCCA_AvpInfo>    mAvpInfoACMap;

	protected:	
	string 					mFileName; //ReadFromEnv.
	string 					mFilePath;
	DCCA_RouteIdentfier 	mRouteIdentifier;

};


//Class to store Appliocation object................
//Need to make Singleton class.
template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
class DCCA_ApplicationRouter_S: private DCCA_LoadAvpDetails
{
	private:

		// Private so that it can  not be called
		DCCA_ApplicationRouter_S();  

		// copy constructor is private
		DCCA_ApplicationRouter_S(DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ> const&);             

		// assignment operator is private
		DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>& operator=(DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>  const&);  

		//Member variables.
		map< string, DCCA_RouteRule > mRouteRuleList;
		//mPriority 
		map< int , int >              mAvpMap; 

		list<int>                     mAvpList;
		//AvpCode, Count
		map<int, DCCA_LastRouteInfo>  mLastRouteInfo;

		//Inner class
		class DCCA_RouteObjStore
		{
			public:
				DCCA_RouteObjStore(){}
				~DCCA_RouteObjStore(){}

				int                              mApplicationId;
				shared_ptr<DCCA_INTERFACE_OBJ>   mRouterInterface;
		};

		//Member variables.
		map< int, DCCA_RouteObjStore> 	mRouteMap;
		//mApplicationId,

		boost::shared_mutex           	mMutexAccess;

		boost::mutex                  	mMutex;

		static mutex                     *mMutexLock;

		static DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER,DCCA_INTERFACE_OBJ>   *mDCCA_ApplicationRouter;

		bool 			GetApplicationId(vector<DCCA_StoreMatchLen>  &lVector, int &lApplnId);

	public:
		bool        Register(DCCA_InputRouteRule &InputRouteRule, shared_ptr<DCCA_INTERFACE_OBJ> ptr, bool lRegFlg = true);

		bool        Update(DCCA_InputRouteRule &InputRouteRule, shared_ptr<DCCA_INTERFACE_OBJ> ptr);

		bool        DeRegister( int &applnId);

		bool        ApplyRouting( multimap< int , boost::any> &DataMap, int &applnId, 
				shared_ptr<DCCA_INTERFACE_OBJ> &RouteInterface, string &lSessionId, bool lRRFlag = false);

		bool        ApplyRRRouting( multimap< int , boost::any> &DataMap, int &applnId, 
				shared_ptr<DCCA_INTERFACE_OBJ> &RouteInterface, string &lSessionId );

		bool        GetApplicationObj( int &applnId, shared_ptr<DCCA_INTERFACE_OBJ> &RouteInterface);

		bool        DisplayApplicationDet();

		bool        LoadAvpDetails();

		void        Display();

		void 	  		DisplayReadLock();

		bool    		Init();

		list<int>   GetInputAvpDetails();

		int  	  		LastMsgCounter;

		static DCCA_ApplicationRouter_S*  GetInstance();

};

template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ >
DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER,DCCA_INTERFACE_OBJ>* 	DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER,DCCA_INTERFACE_OBJ>::mDCCA_ApplicationRouter = NULL;

template <DCCA_RouteIdentfier ROUTE_APPLICATION_IDENTIFIER, class DCCA_INTERFACE_OBJ>
mutex* 				DCCA_ApplicationRouter_S<ROUTE_APPLICATION_IDENTIFIER, DCCA_INTERFACE_OBJ>::mMutexLock = new mutex;


class DCCA_PrepareRouteRegData
{
	//Prepare Input for Registration.....
	bool 	  GetApplicationValue(boost::property_tree::ptree pt, list<string> &lDataList);

	bool 	  DecodeApplicationDet(boost::property_tree::ptree pt, DCCA_InputRouteRule &_InputRouteRule);

	bool	  DecodeApplication( boost::property_tree::ptree pt, DCCA_InputRouteRule &_InputRouteRule);

	bool    Decode( boost::property_tree::ptree pt, DCCA_InputRouteRule &_InputRouteRule );

	public:

	bool 	  PrepareRouteRegData(string path, string fileName, DCCA_InputRouteRule &_InputRouteRule);

	void    Display(DCCA_InputRouteRule &_InputRouteRule);
};


#define DCCA_PROXY_ROUTE_INSTANCE() DCCA_ApplicationRouter_S<DCCA_PROXY,DCCA_ProxyHandler>::GetInstance()

#define DCCA_DEF_PRINT_STR()\
	string lMacrostr;

#define DCCA_PRINT_DATA( _FirstName, _FirstVal, _SecName, _SecVal)\
	cout.setf(ios_base::left, ios_base::adjustfield);\
cout.width(20);\
cout.fill(' ');\
lMacrostr = "| " + std::string(_FirstName);\
cout << lMacrostr;\
cout << ":";\
cout << " ";\
cout.width(29);\
cout.fill(' ');\
cout << _FirstVal;\
cout.width(20);\
cout.fill(' ');\
lMacrostr = "| " + std::string(_SecName);\
cout<<lMacrostr;\
cout << ":";\
cout << " ";\
cout.width(29);\
cout.fill(' ');\
cout << _SecVal;\
cout << "|" << endl;

#define DCCA_PRINT_LINE()\
	cout << "|*****************************************************************************************************|"  << endl;

#define DCCA_PRINT_HYPEN_LINE()\
	cout << "|-----------------------------------------------------------------------------------------------------|"  << endl;


#endif 
