// @(#) $Id: aaa_global_config.h,v 1.1.4.1.2.1 2018/02/21 23:00:44 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_global_config.h
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

/* Diameter peer fsm debugging */

#ifdef DEBUG_ALL
#define AAA_FSM_EVENT_DEBUG 1

/* Diameter router debugging */
#define AAA_ROUTE_DEBUG 1

/* Diameter acct session fsm debugging */
#define AAA_SESSION_ACCT_DEBUG 1

/* Diameter auth session fsm debugging */
#define AAA_SESSION_AUTH_DEBUG 1

/* Diameter generic session fsm debugging */
#define AAA_SESSION_DEBUG 1

/* Diameter XML config loader debugging */
#define AAA_XML_DEBUG 1

/* PANA debugging flag */
#define PANA_DEBUG 1

/* PANA FSM debugging */
#define PANA_FSM_DEBUG 1

/* PANA key generator debugging flag */
#define PANA_SA_DEBUG 1

/* PANA parser debugging flag */
#define PANA_PARSER_DEBUG 1

#else

#define AAA_FSM_EVENT_DEBUG 0

/* Diameter router debugging */
#define AAA_ROUTE_DEBUG 0

/* Diameter acct session fsm debugging */
#define AAA_SESSION_ACCT_DEBUG 0

/* Diameter auth session fsm debugging */
#define AAA_SESSION_AUTH_DEBUG 0

/* Diameter generic session fsm debugging */
#define AAA_SESSION_DEBUG 0

/* Diameter XML config loader debugging */
#define AAA_XML_DEBUG 0

/* PANA debugging flag */
#define PANA_DEBUG 0

/* PANA FSM debugging */
#define PANA_FSM_DEBUG 0

/* PANA key generator debugging flag */
#define PANA_SA_DEBUG 0

/* PANA parser debugging flag */
#define PANA_PARSER_DEBUG 0
#endif

