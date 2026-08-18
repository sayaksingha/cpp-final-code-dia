// @(#) $Id: aaa_client.h,v 1.1.4.1.2.1.2.1 2024/05/15 13:08:41 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_client.h
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
#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "aaa_data_defs.h"
#include "aaa_peer_fsm.h"
#include "aaa_route_msg_router.h"
#include "aaa_error_msg.h"

class AAA_ClientCall : public AAA_Job
{
   public:
      AAA_ClientCall(std::unique_ptr<DiameterMsg> msg):msg(msg) {
      }
      virtual int Serve() {

         DIAMETER_MSG_ROUTER()->RequestMsg(msg, NULL);

         // if the processing is completed done then we can delete
         // ourselves since there will be no more use for this
         // instance.
         Delete();

         // make sure we return 0 here so that we don't get re-scheduled
         // automatically by the AAA_GroupedJob in AAA_Task. Returning
         // 0 is an indication to the grouped job that there are no
         // more pending transaction in this AAA_Job
         return (0);
      }
   protected:
      virtual int Schedule(AAA_Job*, size_t backlogSize=1) {
         // This is simply a stub function to make sure
         // compiler does not complain on pure virtual methods
         return (0);
      }
	private:
		std::unique_ptr<DiameterMsg> msg;

};

#endif /* __CLIENT_H__ */
