// @(#) $Id: aaa_session_factory.h,v 1.1.4.1.2.1 2018/02/21 23:00:47 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_session_factory.h
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
#ifndef __AAA_SESSION_FACTORY_H__
#define __AAA_SESSION_FACTORY_H__

#include "aaa_data_defs.h"
#include "diameter_api.h"

class DiameterServerSessionFactoryList
{
    private:
        typedef enum {
            SPC_ARC = 271
        };
    public:
        void Add(AAAServerSessionFactory *factory) {
            m_FactoryList.push_back(factory);
        }
        AAAServerSessionFactory *Lookup(DiameterMsg &msg) {
            std::list<AAAServerSessionFactory*>::iterator i =
                m_FactoryList.begin();
            for (; i != m_FactoryList.end(); i++) {
                if (msg.hdr.appId == (*i)->GetApplicationId()) {
		    if ((msg.hdr.code == SPC_ARC) &&
			((*i)->GetType() != AAA_STYPE_ACCOUNTING)) {
		      continue;
		    }
                    return *i;
                }
            }
            return 0;
        }
        void Remove(AAAServerSessionFactory *factory) {
            std::list<AAAServerSessionFactory*>::iterator i =
                m_FactoryList.begin();
            for (; i != m_FactoryList.end(); i++) {
                if ((*i) == factory) {
                    m_FactoryList.erase(i);
                    break;
                }
            }
        }

    private:
        std::list<AAAServerSessionFactory*> m_FactoryList;
};

#endif // __AAA_SESSION_FACTORY_H__


