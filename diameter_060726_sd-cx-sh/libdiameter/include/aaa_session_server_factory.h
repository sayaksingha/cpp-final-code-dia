// @(#) $Id: aaa_session_server_factory.h,v 1.1.4.1.2.1 2018/02/21 23:00:48 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_session_server_factory.h
//
// COPYRIGHT
// TSS : - Copyright (C) 2001 Tayana Software Solution Pvt Ltd.,
//         All rights reserved. No part of this computer program
//         may be used or reproduced in any form by any
//         means without prior written permission of
//         Tayana Software Solution Pvt Ltd.
//
// DESCRIPTION
//
// Originated:
//----------------------------------------------------------------
#ifndef __AAA_SESSION_SERVER_FACTORY_H__
#define __AAA_SESSION_SERVER_FACTORY_H__

#include "aaa_session.h"

class DIAMETERBASEPROTOCOL_EXPORT DiameterServerSessionFactory
{
    public:
       virtual ~DiameterServerSessionFactory() { 
       }
       diameter_unsigned32_t GetApplicationId() { 
           return m_ApplicationId; 
       }

       // This function is implemented by derived class
       virtual DiameterSessionIO *CreateInstance() = 0;

    protected:
       DiameterServerSessionFactory(AAA_Task &task,
                                diameter_unsigned32_t appId) :
           m_Task(task),
           m_ApplicationId(appId) { 
       }

    protected:
       AAA_Task &m_Task;
       diameter_unsigned32_t m_ApplicationId;
};

template<class SESSION_SERVER>
class DiameterServerSessionAllocator : 
    public DiameterServerSessionFactory
{
    public:
       DiameterServerSessionAllocator(AAA_Task &task,
                                  diameter_unsigned32_t appId) : 
            DiameterServerSessionFactory(task, appId) { 
       }
       DiameterSessionIO *CreateInstance() {
            return new SESSION_SERVER(m_Task, m_ApplicationId);
       }
};

#endif

