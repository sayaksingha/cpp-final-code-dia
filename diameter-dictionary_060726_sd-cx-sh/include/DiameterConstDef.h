#ifndef INCL_TSS_DIAMETER_CONST_DEF_H
#define INCL_TSS_DIAMETER_CONST_DEF_H
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <libgen.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/poll.h>
#include <openssl/md5.h>
#include <sys/syscall.h>
#include <vector>
#include <algorithm>
#include <map>
#include <expat.h>
#include "Types.h"
#include <sys/stat.h>
#include <list>
#include <bits/stdc++.h>

#include "TssLimits.h"

using namespace std;
#define DIA_APPLN_ID_SIZE						4
#define DIA_HOP_BY_HOP_ID_SIZE					4
#define DIA_END_TO_END_ID_SIZE					4
#define DIA_AVP_CODE_SIZE						4
#define DIA_AVPCODE_N_FLAG_SIZE					5
#define DIA_AVP_LEN_SIZE						3
#define DIA_CMD_CODE_SIZE						3
#define DIA_VERSION_SIZE						1
#define DIA_VENDER_SPEC_APPLN_ID_SIZE		4
#define DIA_DEFAULT_VENDER_SPEC_APPLN_ID	10415
#define DIA_GET_VENDER_SPEC_BIT			0x80
#define DIA_GET_MANDATARY_SPEC_BIT			0x40
#define DIA_GET_PROTECTED_SPEC_BIT			0x20
#define DIA_HEADER_LEN						20
#define DIA_CMD_CODE_START_INDEX				5
#define TSS_DIA_MSG_REQ_BIT_POS			7
#define TSS_DIA_MSG_PXY_BIT_POS			6
#define TSS_DIA_MSG_ERR_BIT_POS			5
#define TSS_DIA_MSG_TRANS_BIT_POS		4
#define TSS_MAX_EXCEPTION_NAME_LEN		50
#define TSS_MAX_EXCEPTION_STR_LEN		300
#define TSS_MAX_DIAMETER_IPV4_LEN		6
#define TSS_MAX_DIAMETER_TIME_LEN		4

#define TSS_MAX_DIAMETER_SESSION_ID_LEN		150

#define BOOST_SHARED_PTR_HPP_INCLUDED

#ifndef SS7_MAX_ADDRESS_LEN
#define SS7_MAX_ADDRESS_LEN          20
#endif

#define ASCII_OFFSET                0x30
#define BYTE_RESET_VAL              0x00
#define ONE_NIBBLE_SHIFT            0x04
#define ONE_BYTE_SHIFT              0x08
#define LOWER_NIBBLE_MASK           0x0F
#define UPPER_NIBBLE_MASK           0xF0
#define NIBBLE_FILLER               0xF0
#define MAX_IMSI_LEN                16
//#define MAX_DIAMETER_PACKET_SIZE    1024*1024*2
#define MAX_DIAMETER_PACKET_SIZE    30000 

#define SYS_TIME_NTP_COMPENSATION   2208988800 // 25,567 * 24 * 60 * 60 ==> NTP starts from 1990 jan 1 and system time                                                  from 1970 jan 1 

#ifndef NULLPTR
#define NULLPTR                     0x00
#endif


#define DIA_GET_COUNTER_LST(var,obj,fun)\
   try\
   {\
      list<Counters*>::iterator x = obj->fun()->begin();\
      for (; x != obj->fun()->end(); x++)\
      {\
         Counters vcid          = new Counters ();\
         vcid.counterID         = (*x)->getCounterID()->getValue();\
         vcid.counterValue      = (*x)->getCounterValue()->getValue();\
         vcid.counterExpiryDate = (*x)->getCounterExpiry()->getValue();\
         vcid.minValue          = (*x)->getMinValue()->getValue();\
         vcid.maxValue          = (*x)->getMaxValue()->getValue();\
         vcid.priority          = (*x)->getPriority()->getValue();\
         vcid.counterCategory   = (*x)->getCounterCategory()->getValue();\
            var.push_back(vcid);\
      }\
   }\
   catch  (TssDiameterMsgException &st )\
   {\
   }\

#define DIA_GET_BALANCE_LST(var,obj,fun)\
   try\
   {\
      list<Balance*>::iterator x = obj->fun()->begin();\
      for (; x != obj->fun()->end(); x++)\
      {\
         Balance vbalance       = new Balance ();\
         vbalance.counterID         = (*x)->getBalanceID()->getValue();\
         vbalance.counterValue      = (*x)->getBalnceValue()->getValue();\
         vbalance.counterExpiryDate = (*x)->getBalanceExpiry()->getValue();\
         vbalance.minValue          = (*x)->getMinValue()->getValue();\
         vbalance.maxValue          = (*x)->getMaxValue()->getValue();\
         vbalance.priority          = (*x)->getPriority()->getValue();\
         vbalance.counterCategory   = (*x)->getBalanceCategory()->getValue();\
            var.push_back(vbalance);\
      }\
   }\
   catch  (TssDiameterMsgException &st )\
   {\
   }\

/*
#define DIA_SET_COUNTER_LST(var,obj,fun)\
   try \
    {\
       int                              count = 0;\
       list<Counters *>::iterator it = next( Counters->begin(), count);\
       auto lCounterspGrpList = (*it)->setCounterspGrpList();\
       Counters *lCounters = new Counters();\
       lCounterspGrpList->push_back(lCountersp);\
       list<Counters*>::iterator lCounterspIter = next(lCounterspGrpList->begin(), count1);\
       count1++;\
       (*lCounterspIter)->setBalanceID()->setValue(.mBucketId);\
       (*lCounterspIter)->setratevalue()->setValue(lWicpRateActionDet.mChargeValue);\
       (*lCounterspIter)->setrateUnit()->setValue(lWicpRateActionDet.mChargeUnit);\
       (*lCounterspIter)->setconsumptionvalue()->setValue(lWicpRateActionDet.mServiceConsumptionVal);\
       (*lCounterspIter)->setconsumptionunit()->setValue(lWicpRateActionDet.mServiceConsumptionUnit);\
    }\
   catch  (TssDiameterMsgException &st )\
   {\
   }\
*/
/*
#define TRY_GET_SUB_ID ( var,obj,fun )\
           try\
{\
   \
   var.assign(obj->fun()->getValue()? (char*)obj->fun()->getValue():"" , obj->fun()->getLength() ? obj->fun()->getLength(): 0);\
}\
        catch  (TssDiameterMsgException &st )\
{\
   var = "";\
}\
        catch (...)\
{\
   var = "";\
}\
*/



#define DIA_TRY_OCTET_STRING(var,obj,fun)\
           try\
{\
   var.assign(obj->fun()->getValue()? (char*)obj->fun()->getValue():"" , obj->fun()->getLength() ? obj->fun()->getLength(): 0);\
}\
        catch  (TssDiameterMsgException &st )\
{\
   var = "";\
}\
        catch (...)\
{\
   var = "";\
}\


#define DIA_TRY_INTEGER32(var,obj,fun)\
           try\
{\
   var = obj->fun()->getValue();\
}\
        catch  (TssDiameterMsgException &st )\
{\
   var = 0;\
}\

// CCR Request Parameter Macros

#define DIA_SET_CCR_REQUEST_BIT(lCCRequest)\
   try\
   {\
      lCCRequest->setRequestBit(1);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Req bit Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Req bit UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_CCR_COMMAND_CODE(lCCRequest)\
   try\
   {\
      lCCRequest->setCmdCode(272);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Command Code Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Command Code UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_CCR_EVT_TIMESTAMP(lCCRequest)\
   try\
   {\
      lCCRequest->setEventTimestamp()->setValue(time(NULL));\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR EventTimestamp Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR EventTimestamp UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_CCR_REQUEST_SESSION_ID(lCCRequest, sessionId)\
   try\
   {\
      lCCRequest->setSessionId()->setValue(sessionId);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Session Id Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Session Id UnknownExcepion:", "");\
      return false;\
   }\


#define DIA_SET_CCR_REQUEST_TYPE(lCCRequest)\
   try\
   {\
      lCCRequest->setCCRequestType()->setValue(4);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Request Type Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Request Type UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_CCR_REQUESTED_ACTION(lCCRequest, action)\
   try\
   {\
      lCCRequest->setRequestedAction()->setValue(action);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Requested Action Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Requested Action UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_CCR_REQUEST_NUMBER(lCCRequest, reqNum)\
   try\
   {\
      lCCRequest->setCCRequestNumber()->setValue(reqNum);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Requested Numer Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Requested Number UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_CCR_ORIG_HOST(origHost)\
   try\
   {\
      lCCRequest->setOriginHost()->setValue(origHost);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Orig Host Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Orig Host UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_CCR_ORIG_REALM(origRealm)\
   try\
   {\
      lCCRequest->setOriginRealm()()->setValue(origRealm);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Orig Realm Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting Orig Realm Code UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_CCR_DEST_HOST(destHost)\
   try\
   {\
      lCCRequest->setOriginHost()->setValue(destHost);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Dest Host Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Dest Host UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_CCR_DEST_REALM(destRealm)\
   try\
   {\
      lCCRequest->setOriginHost()->setValue(destRealm);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Dest Realm Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Dest Realm UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_CCR_UNIQUE_MSG_REF_NO(lCCRequest, msgRefNum)\
   try\
   {\
      lCCRequest->setUniqueMsgRefNo()->setValue(msgRefNum);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Unique Msg Ref No Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Unique Msg Ref No UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_CCR_REVERT_TXN_ID(lCCRequest, revertTxnId)\
   try\
   {\
      lCCRequest->setRevertTransactionId()->setValue(revertTxnId);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Revert Txn Id Excepion:" << e.what() << " Msg: " << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Revert Txn Id UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_SUBS_ID(lCCRequest, subsId)\
   try\
   {\
      lCCRequest->setSubsId()->setValue(subsId);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Subscriber Id  Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Subscriber Id UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_SERVICE_IDENTIFIER(lCCRequest, srvIdentifier)\
   try\
   {\
      lCCRequest->setServiceIdentifier()->setValue(srvIdentifier);\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Service Identifier Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Service Identifier UnknownExcepion:", "");\
      return false;\
   }\

#define DIA_SET_COMMENTS(lCCRequest, comments)\
   try\
   {\
      lCCRequest->setComments()->setValue((TEXT*)comments.c_str());\
   }\
   catch(TssDiameterMsgException e)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Comments Excepion:" << e.what() << " Msg:" << e.getErrMessage(), "");\
      return false;\
   }\
   catch(...)\
   {\
      log_err(100, lLogPrefix << " Exception Occured while setting CCR Comments UnknownExcepion:", "");\
      return false;\
   }\

#define WICP_DIA_HANDLE_EXCEPTION( tid , logtext ) \
catch (TssDiameterMsgException e)\
{\
   log_err_txn( 100 , tid , " " << logtext << " TSS Diameter Exception Code: " \
       << e.getErrorCode() << " Err Msg: " << e.getErrMessage() , "" );\
}\
catch (std::exception const& e)\
{\
   log_err_txn( 100 , tid , " " << logtext << "STD Exception Code:" \
       << e.what(), "" );\
}\
catch (...)\
{\
   log_err_txn( 100 , tid , "" << logtext << "Generic Exception Code:" \
       , "" );\
}\

#define WICP_DIA_HANDLE_EXCEPTION_RETURN( tid , logtext ) \
catch (TssDiameterMsgException e)\
{\
   log_err_txn( 100 ,  tid , logtext << " TSS Diameter Exception Code: " \
       << e.getErrorCode() << " Err Msg: " << e.getErrMessage() , "" );\
   return false;\
}\
catch (std::exception const& e)\
{\
   log_err_txn( 100 , tid , logtext << "STD Exception Code:" , "" );\
   return false;\
}\
catch (...)\
{\
   log_err_txn( 100, tid , logtext << "Generic Exception Code " , "" );\
   return false;\
}\


#define WICP_DIA_SET_UINT8PTR_VALUES( req, setfun,  var)\
try\
{\
  req->setfun()->setValue((TEXT*)var); \
}\
catch(TssDiameterMsgException d)\
{\
    log_err_txn( 100 ,txnId , \
          " Diameter Exception occured. EC:" << d.getErrorCode() << " ErrMsg:" << d.getErrMessage() << " Fun:"<<#setfun <<" Val:"<< (TEXT*)var, "" );\
    req->re##setfun(); \
}\
catch(std::exception const& e)\
{\
    log_err_txn( 100 ,txnId , \
          " std::exception occured. ErrMsg:" << e.what() << " Fun:"<<#setfun <<" Val:"<< (TEXT*)var, "" );\
    req->re##setfun(); \
}\
catch(...)\
{\
    log_err_txn( 100 ,txnId , \
          " Generic Exception occured at Fun:"<<#setfun <<" Val:"<< (TEXT*)var, "" );\
    req->re##setfun(); \
}\

#define WICP_DIA_SET_TEXT_VALUES( req, setfun,  var)\
try\
{\
  req->setfun()->setValue(var); \
}\
catch(TssDiameterMsgException d)\
{\
    log_err_txn( 100 ,txnId , \
          " Diameter Exception occured. EC:" << d.getErrorCode() << " ErrMsg:" << d.getErrMessage() << " Fun:"<<#setfun <<" Val:"<< (TEXT*)var  , "" );\
    req->re##setfun(); \
}\
catch(std::exception const& e)\
{\
    log_err_txn( 100 ,txnId , \
          " std::exception occured. ErrMsg:" << e.what() << " Fun:"<<#setfun <<" Val:"<< (TEXT*)var, "" );\
    req->re##setfun(); \
}\
catch(...)\
{\
    log_err_txn( 100 ,txnId , \
          " Generic Exception occured at Fun:"<<#setfun <<" Val:"<< (TEXT*)var, "" );\
    req->re##setfun(); \
}\

#define WICP_DIA_SET_STRING_VALUES( req, setfun,  var)\
try\
{\
  req->setfun()->setValue((TEXT*)var.c_str()); \
}\
catch(TssDiameterMsgException d)\
{\
    log_err_txn( 100 ,txnId , \
          " Diameter Exception occured. EC:" << d.getErrorCode() << " ErrMsg:" << d.getErrMessage() << " Fun:"<<#setfun <<" Val:"<< var  , "" );\
    req->re##setfun(); \
}\
catch(std::exception const& e)\
{\
    log_err_txn( 100 ,txnId , \
          " std::exception occured. ErrMsg:" << e.what() << " Fun:"<<#setfun <<" Val:"<< var, "" );\
    req->re##setfun(); \
}\
catch(...)\
{\
    log_err_txn( 100 ,txnId , \
          " Generic Exception occured at Fun:"<<#setfun <<" Val:"<< var, "" );\
    req->re##setfun(); \
}\

#define WICP_DIA_SET_INT_VALUES( req, setfun,  var)\
try\
{\
  req->setfun()->setValue(var); \
}\
catch(TssDiameterMsgException d)\
{\
    log_err_txn( 100 , txnId , \
           " Diameter Exception occured. EC:" << d.getErrorCode() << " ErrMsg:" << d.getErrMessage() << " Fun:"<<#setfun <<" Val:"<< var << " invoking re"<<#setfun , "" );\
    req->re##setfun(); \
}\
catch(std::exception const& e)\
{\
    log_err_txn( 100 ,txnId , \
          " std::exception occured. ErrMsg:" << e.what() << " Fun:"<<#setfun <<" Val:"<< var, "" );\
    req->re##setfun(); \
}\
catch(...)\
{\
    log_err_txn( 100 ,txnId , \
          " Generic Exception occured at Fun:"<<#setfun <<" Val:"<< var, "" );\
    req->re##setfun(); \
}

#define WICP_DIA_SET_ITERATOR_INT_VALUES( lItr , setfun,  var)\
try\
{\
  (*lItr)->setfun()->setValue(var); \
}\
catch(TssDiameterMsgException d)\
{\
    log_err_txn( 100 ,  txnId , \
           " Diameter Exception occured. EC:" << d.getErrorCode() << " ErrMsg:" << d.getErrMessage() << " Fun:"<<#setfun <<" Val:"<< var  , "" );\
    req->re##setfun(); \
}\

#define WICP_DIA_GET_STRING_VALUES( req, getfun, strVar)\
try\
{\
   strVar = req->getfun()->ToString(); \
}\
catch(TssDiameterMsgException d)\
{\
   log_err_txn( 100 , txnId ,  \
          " Diameter Exception occured. EC:" << d.getErrorCode() << " ErrMsg:" << d.getErrMessage() << " Fun:"<< #getfun  , "" );\
}\

#define WICP_DIA_GET_ITERATOR_TXT_VALUES( lItr , getfun,  strVar)\
try\
{\
  strVar = (*lItr)->getfun()->ToString(); \
}\
catch(TssDiameterMsgException d)\
{\
    log_err_txn( 100 ,  txnId , \
           " Diameter Exception occured. EC:" << d.getErrorCode() << " ErrMsg:" << d.getErrMessage()  << " Fun:"<< #getfun , "" );\
}\


#define WICP_DIA_GET_ITERATOR_INT_VALUES( lItr , getfun,  intVar)\
try\
{\
  intVar = (*lItr)->getfun()->getValue(); \
}\
catch(TssDiameterMsgException d)\
{\
    log_err_txn( 100 , txnId , \
           " Diameter Exception occured. EC:" << d.getErrorCode() << " ErrMsg:" << d.getErrMessage()  << " Fun:"<< #getfun , "" );\
}\

#define WICP_DIA_SET_ITERATOR_TXT_VALUES( lItr , setfun,  var)\
try\
{\
  (*lItr)->setfun()->setValue((TEXT*)var.c_str()); \
}\
catch(TssDiameterMsgException d)\
{\
    log_err_txn( 100 , txnId , \
           " Diameter Exception occured. EC:" << d.getErrorCode() << " ErrMsg:" << d.getErrMessage()  << " Fun:"<< #setfun <<" Val:"<< var, "" );\
}\

















#endif
