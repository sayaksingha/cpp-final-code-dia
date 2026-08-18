// @(#) $Id: aaa_const_def.h,v 1.1.4.1.4.1 2018/05/14 23:24:29 anandhv Exp $
#ifndef INCL_AAA_CONST_DEF_H
#define INCL_AAA_CONST_DEF_H

#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

#include <signal.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/poll.h>
#include <openssl/md5.h>

#include "Types.h"
#include "LogApi.h"
#include "ctrace.h"
#include "MsgQueue.h"
#include "ProcessLock.h"
#include "CfgRead.h"
#include "TssDbMgr.h"
#include "TCPSocket.h"
#include "GenericAseStruct.h"
#include <iomanip>

#ifndef IPC_PERM
#define IPC_PERM  0666
#endif

#ifndef SIGCFG
#define SIGCFG    10
#endif

#ifndef SIGTRC
#define SIGTRC    12
#endif

#define AAA_NAME                      ""

//----------------------------------------------------------------------
// Traces
#define TRACE_AAA_EVR_WRITER_ENV    "TRACE_AAA_EVR_WRITER"
#define TRACE_AAA_1xProc_ENV        "TRACE_AAA_1xProc"

//----------------------------------------------------------------------
// Config files
#define AAA_IPC_CFG                   "ipc.cfg"
#define AAA_KER_CFG                   "kernel.cfg"
#define AAA_SYS_CFG                   "system.cfg"
#define AAA_PRODUCT_CFG               "Product.cfg"
#define AAA_CDR_CFG                   "cdr.cfg"
#define AAA_PROV_EVR_CFG              "provEvr.cfg"
#define REDIS_CFG								"redis.cfg"

#define AAA_DB_ERR_SLEEP_TIME         100
#define AAA_DB_ERR_RETRY_ATTEMPTS     2
#define CDR_DATE_FORMAT               "%Y%m%d%H%M%S"
#define EVR_DATE_FORMAT               "%Y%m%d%H%M%S"

//#define MAX_REALM_NAME_LEN 50
//#define MAX_HOST_NAME_LEN  50

#define MAX_DIA_CMD_LEN    300

#define AAA_PRINT_SPACE \
   printf ("                ");

extern Log gLog;
extern CTrace gTrace;
extern TEXT gProcessName[];

#endif
