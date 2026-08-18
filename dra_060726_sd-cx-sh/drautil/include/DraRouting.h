 // @(#) $Id: DraRouting.h,v 1.1.2.2.2.5 2021/11/26 04:23:01 anandhv Exp $";
 //-----------------------------------------------------------------------------
 // NAME           :  DraRouting.h
 //
 // COPYRIGHT      :  TSS - Copyright (C) 2009 Tayana Software Solution Pvt Ltd.,
 //                   All rights reserved. No part of this computer program
 //                   may be used or reproduced in any form by any
 //                   means without prior written permission of
 //                   Tayana Software Solution Pvt Ltd.
 //
 // DESCRIPTION
 //
 // Originated By  :  																	Date:
 //---------------------------------------------------------------------------

#ifndef INCL_DRA_LIB_ROUTING_H
#define INCL_DRA_LIB_ROUTING_H

#include "DraParser.h"
#include "aaa_peer_table.h"
#include "ace/RW_Mutex.h"
#include "DRA_ConfigHandler.h"
#include <mutex>

class DraRouting: public DraParser 
{
	public:

		~DraRouting();
      
		DraRouting(std::string dictFile, std::string appFile , bool &returnVal);
//		bool 												Init(std::string dictFile, std::string appFile);

		void 												Reload();
		virtual std::list<ActivePeerData> 		getActivePeerData();
		virtual bool getAlias(std::string &lPeerName, std::string &lAlias);
		virtual std::map<int,DictionaryData> 	getSupportedAVP();
		
		virtual bool getAvpCodePathDet( int applicationid, UINT32 avpCode, AvpCodePathDet &lAvpCodePathDet );

		bool    getPeer(multimap<int,std::string> codeMap, DiameterPeerEntry *&dest , string );
		bool    getPeer(  DiameterPeerEntry *&dest , string );
		void    Reset ();
		bool 		                     			IsOpen(std::string peerName);


		bool 	  CheckPeer(std::string peerName , DiameterPeerEntry *&peer , string );
		bool    CheckPeerStatus(DiameterPeerEntry *destPeer );

		EnumRoutingType getRoutingType ( );


		std::string 						getAVPDataType(int code);
		bool evaluteExp(bool expRes1, bool expRes2, string operation);
		void tokenizeData(char * str, list<string> &rList);
		void tokenizeData(char * str, int &key, DictionaryData &rDictionaryData);
		bool IsMatch (char * pMatchRegex, char * pStr);

		bool			getActiveDefPeer(DiameterPeerEntry *&dest , string );
		bool			findRRPeer(std::string keyName, DiameterPeerEntry *&dest , string );
		bool		   findFOPeer(std::string keyName, DiameterPeerEntry *&dest , string );
		bool 			findWTPeer(std::string keyName, DiameterPeerEntry *&dest , string );

		bool 			findAVPPeer(multimap<int,std::string> codeMap, bool &result, DiameterPeerEntry *&dest , string );
		bool        findAVPPeerList(const multimap<int,std::string>& codeMap, bool &result, DiameterPeerEntry *&dest, string sid);	
	
		std::string mdictionaryFile; 
		std::string mroutingFile;
		char 			mRoutingFileTimeStr[100];
		time_t		mRoutingFileTime;
		char 			mDictFileTimeStr[100];
		time_t		mDictFileTime;
		int			mCount;
		int			mWTSkipCnt;

		std::mutex   mRRRoutingMutex;
		std::mutex   mFORoutingMutex;
		std::mutex   mWTRoutingMutex;
		std::mutex   mAVPRoutingMutex;
		//ACE_RW_Mutex mRoutingMutex;
};

#endif 
