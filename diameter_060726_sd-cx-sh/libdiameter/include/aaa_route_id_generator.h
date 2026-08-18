// @(#) $Id: aaa_route_id_generator.h,v 1.1.4.1.2.1.2.2 2019/01/21 22:18:43 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_route_id_generator.h
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
#ifndef __ROUTE_ID_GENERATOR_H__
#define __ROUTE_ID_GENERATOR_H__

#include <time.h>
#include <stdlib.h>
#include "ace/Singleton.h"

class DiameterIdGenerator {
    public:
       virtual int Get() = 0;

    protected:
       DiameterIdGenerator() : m_Id(0) { }
       virtual ~DiameterIdGenerator() { }
       int m_Id;
};

class DiameterHopByHopGenerator : public DiameterIdGenerator {
    public:
		 DiameterHopByHopGenerator() 	
		 {
				pthread_spin_init(&m_spinlock, 0);
		 }
		 ~DiameterHopByHopGenerator()
		 {
				pthread_spin_destroy(&m_spinlock);
		 }
		
       int Get() {
				int lId = 0;
			   pthread_spin_lock(&m_spinlock);
			
           if (m_Id == 0) {
#ifndef WIN32
               struct timeval tv;
               gettimeofday(&tv, 0);
               srand((unsigned int)(tv.tv_sec + tv.tv_usec));
#else
					srand((unsigned int)time(0));
#endif
               m_Id = rand(); // random number seed
				
           }
			  ++m_Id;

			  if ( m_Id > 2147483000)
				m_Id = 0;

			 	lId = m_Id;
			  pthread_spin_unlock(&m_spinlock);
           return (lId);
       }
		 private:
			pthread_spinlock_t m_spinlock;
};

class DiameterEndToEndGenerator : public DiameterIdGenerator {
    public:
		 DiameterEndToEndGenerator() 	
		 {
				pthread_spin_init(&m_spinlock, 0);
		 }
		 ~DiameterEndToEndGenerator()	
		 {
				pthread_spin_destroy(&m_spinlock);
		 }
       int Get() {
			 pthread_spin_lock(&m_spinlock);
           if (m_Id == 0) {
#ifndef WIN32
               struct timeval tv;
               gettimeofday(&tv, 0);
               srand((unsigned int)(tv.tv_sec + tv.tv_usec));
               m_Id = (unsigned int)(tv.tv_sec) << 20; // set high 12 bit
#else
			   srand((unsigned int)time(0));
               m_Id = (unsigned int)(rand()) << 20; // set high 12 bit
#endif
           }
           m_Id &= 0xFFF00000; // clear lower 20 bits
           m_Id |= rand() & 0x000FFFFF; // set low 20 bits
			  pthread_spin_unlock(&m_spinlock);
           return (m_Id);
       }
		 private:
			pthread_spinlock_t m_spinlock;
};

typedef ACE_Singleton<DiameterHopByHopGenerator, ACE_Recursive_Thread_Mutex>
                      DiameterHopByHopGenerator_S;

#define DIAMETER_HOPBYHOP_GEN() DiameterHopByHopGenerator_S::instance()

typedef ACE_Singleton<DiameterEndToEndGenerator, ACE_Recursive_Thread_Mutex>
                      DiameterEndToEndGenerator_S;
#define DIAMETER_ENDTOEND_GEN() DiameterEndToEndGenerator_S::instance()

#endif


