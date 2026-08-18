static const char *id = " @(#) $Id: aaa_application.cc,v 1.1.4.1.2.1.2.8 2019/12/27 19:48:12 anandhv Exp $";
//----------------------------------------------------------------------
// NAME
// aaa_application.cc
//
// COPYRIGHT
// Tayana Software Solutions Pvt Ltd -- Copyright(C) 2007
// All rights reserved. No part of this computer program
// may be used or reproduced in any form by any
// means without prior written permission of
// Tayana Software Solutions Pvt Ltd
//
// DESCRIPTION
//
// Originated :                                     Date:
//----------------------------------------------------------------------
//#include "aaa_xml_data.h"
#include "aaa_application.h"
//#include "aaa_log_facility.h"

ACE_Logging_Strategy DiameterLogFacility::logging_strategy;
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAAReturnCode DiameterApplication::Open(char *cfgfile)
{
    /// sanity check
    if ( false == m_Task.Running() || false == m_OtherTask.Running()) 
	 {
        AAA_LOG((LM_ERROR, "%T |APP_BASE| Task MUST be running before openning core\n"));
        return (AAA_ERR_FAILURE);
    }
	

    /// make sure we have a reactor
    int i;
    for (i = 0; i < 10; i ++) 
	 {
      // if (! m_Task.reactor()) 
       if (! m_OtherTask.reactor()) 
		 {
           ACE_Time_Value tm(0, 100);
           ACE_OS::sleep(tm);
       }
       else 
		 {
           break;
       }
    }

    if (i >= 10) 
	 {
        AAA_LOG((LM_ERROR, "%T |APP_BASE| Task reactor is not running, aborting start\n"));
        return (AAA_ERR_FAILURE);
    }
	
	 //Peer connection history file	
	 if(NULL == getenv("PRODUCT_HOME")) 
	 {
			AAA_LOG((LM_ERROR, "%T |APP_BASE| PRODUCT_HOME env not set\n"));
			return (AAA_ERR_FAILURE);
	 }	
	 DIAMETER_CFG_STARTUP()->productHome = string(getenv("PRODUCT_HOME"));
	 DIAMETER_CFG_STARTUP()->startupTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); 
    /// parse config filename
    try 
	 {
        DiameterXMLConfigParser parser;
        parser.Load(m_OtherTask , cfgfile);
    }
    catch (OD_Utl_XML_SaxException e) 
	 {
        AAA_LOG((LM_INFO, "%T |APP_BASE| Parsing problem [%d]: %s, for file %s\n",
                e.Code(), e.Description().c_str(), cfgfile));
        return (AAA_ERR_PARSING_ERROR);
    }
    catch (...) 
	 {
        AAA_LOG((LM_INFO, "%T |APP_BASE| Unknown parsing problem for file %s\n",
                cfgfile));
        return (AAA_ERR_PARSING_ERROR);
    }

    /// setup configure logging
    if ( DIAMETER_CFG_LOG()->logFile.c_str()[0] != '\0') 
       DiameterLogFacility::Open(*DIAMETER_CFG_LOG(),m_OtherTask);

    /// initialize origin state
    DIAMETER_CFG_RUNTIME()->originStateId = time(0);

    /// initialize dictionary 
//    DiameterDictionaryManager dm;
//    dm.init((char*)DIAMETER_CFG_PARSER()->dictionary.c_str());

    /// initialize garbage collectors

    //DIAMETER_PRXOY_SESSION()->Initialize(m_Task);

	// Need to pass with diff thread
    DIAMETER_IO_GC_ROOT()->Initialize(m_GCTask);

    //DIAMETER_PEER_ENTRY_ROOT()->Initialize(m_OtherTask);// added 
    //DIAMETER_IO_PR_ROOT()->Initialize(m_OtherTask);

    AAA_LOG((LM_EMERGENCY, "%T |APP_BASE| Starting diameter core\n"));

	 DiameterHostIdData *hostId = DIAMETER_HOST_ID_TABLE()->First();
	 while (hostId) {
	    DiameterPeerAcceptor *lDiameterPeerAcceptor;
	    ACE_NEW_NORETURN(lDiameterPeerAcceptor, DiameterPeerAcceptor);

		 if( hostId->disable_host == 0 )
		 {
			 lDiameterPeerAcceptor->Start(hostId);
			 DIAMETER_HOST_LIST()->m_PeerAccptrList.push_back(lDiameterPeerAcceptor);
		 }
	    //m_PeerAccptrList.push_back(lDiameterPeerAcceptor);
	    //DIAMETER_HOST_LIST()->m_PeerAccptrList.push_back(lDiameterPeerAcceptor);
		 hostId = DIAMETER_HOST_ID_TABLE()->Next(hostId);
	 }

	 // start contacting peers
    DiameterPeerConnector::Start();

	 //if(DIAMETER_CFG_TRANSPORT()->retx_interval_flag)
	 //{
    		/// start re-transmission timer
    		ACE_Time_Value interval
             (DIAMETER_CFG_TRANSPORT()->retx_interval/DIAMETER_ROUTER_RETX_DIVISOR, 0);

    		//m_ReTxHandler.Handle() = m_OtherTask.ScheduleTimer
          //   (&m_ReTxHandler, 0, interval, interval);
	 //}
    return (AAA_ERR_SUCCESS);
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAAReturnCode DiameterApplication::RegisterServerSessionFactory
    (DiameterServerSessionFactory &factory)
{
    if (DiameterConfigValidation::IsApplicationIdSupported(factory.GetApplicationId())) 
	 {
        return m_SessionMsgRx.SessionFactoryMap().Add(factory) ? 
             AAA_ERR_SUCCESS : AAA_ERR_FAILURE;
    }
    return AAA_ERR_FAILURE;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAAReturnCode DiameterApplication::RemoveServerSessionFactory
    (diameter_unsigned32_t appId)
{
    return m_SessionMsgRx.SessionFactoryMap().Remove(appId) ? 
        AAA_ERR_SUCCESS : AAA_ERR_FAILURE;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAAReturnCode DiameterApplication::RegisterProxyHandler(AAA_ProxyHandler &handler)
{
	for(auto const & ApplicationId : handler.ApplicationIdList())
	{
		AAA_LOG((LM_INFO, "%T |APP_BASE| Registering Proxy Application, App-Id:%d\n",ApplicationId));
		if (!DiameterConfigValidation::IsApplicationIdSupported(ApplicationId)) 
		{
			AAA_LOG((LM_ERROR, "%T |APP_BASE| Unsupported App-Id:%d\n",ApplicationId));
			return AAA_ERR_FAILURE;
		}
	}
	return m_SessionMsgRx.ProxyHandlerMap().Add(handler) ? AAA_ERR_SUCCESS : AAA_ERR_FAILURE;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAAReturnCode DiameterApplication::RemoveProxyHandler(diameter_unsigned32_t appId)
{
    AAA_LOG((LM_INFO, "%T |APP_BASE| De-Registering Proxy Application App-Id:%d\n",appId));
    return m_SessionMsgRx.ProxyHandlerMap().Remove(appId) ? 
            AAA_ERR_SUCCESS : AAA_ERR_FAILURE;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAAReturnCode DiameterApplication::RegisterProxySyncHopByHopId(AAA_SyncHopByHopHandler &handler)
{
	DIAMETER_MSG_ROUTER()->RegisterSyncProxyHopByHopId(&handler);
	return AAA_ERR_SUCCESS;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAAReturnCode DiameterApplication::RemoveProxySyncHopByHopId()
{
	DIAMETER_MSG_ROUTER()->RemoveSyncProxyHopByHopId();
	return AAA_ERR_SUCCESS;
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
AAAReturnCode DiameterApplication::Close()
{
    AAA_LOG((LM_INFO, "%T |APP_BASE| Stopping diameter core\n"));

	 //if(DIAMETER_CFG_TRANSPORT()->retx_interval_flag)
    //{	
    	/// cancel re-transmission timer
    	//AB- m_OtherTask.CancelTimer(m_ReTxHandler.Handle(), 0);
	 //}
    /// disconnect from peers
    DiameterPeerConnector::Stop(AAA_DISCONNECT_REBOOTING);

	 //DiameterPeerAcceptorList::iterator it = m_PeerAccptrList.begin();
	 DiameterPeerAcceptorList::iterator it = DIAMETER_HOST_LIST()->m_PeerAccptrList.begin();
	 //for (; it != m_PeerAccptrList.end(); it++) {
	 for (; it != DIAMETER_HOST_LIST()->m_PeerAccptrList.end(); it++) {
		 (*it)->Stop();
	 }

    /// wait for any open peers to close
    while (DiameterPeerConnector::GetNumOpenPeers() > 0) 
	 {
        ACE_Time_Value tm(0, 100);
        ACE_OS::sleep(tm);
    }
    AAA_LOG((LM_INFO, "%T |APP_BASE| All peers connection(s) closed\n"));
    DIAMETER_PEER_TABLE()->Clear();

    /// release garbage collectors
	 //DIAMETER_PRXOY_SESSION()->Release();
    DIAMETER_IO_GC_ROOT()->Release();
    //DIAMETER_IO_PR_ROOT()->Release();

    /// close logging facility
    DiameterLogFacility::Close();

    return (AAA_ERR_SUCCESS);
}
