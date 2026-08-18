# @(#) $Id: Makefile,v 1.1.2.3.2.9 2024/12/20 07:20:19 mrafi Exp $
ROOTDIR = $(PROJ_HOME)/tssdra/src

include $(ROOTDIR)/makeutil/header.mod

DEFS += -DCOMMONOAM -lACE
#SONAME=libTSSDRA.so
#################################################################
# define the list of source files.
SRCS = DraMain.cc\
                 Dra.cc\
                 DRA_UpccRechargeHttpRelay.cc\
                 DRA_EvrWriter.cc

SRCS := $(SRCS:%=$(SRCDIR)/%)

# define the include flags.
INCLFLAGS = -I $(ROOTDIR)/include\
            -I $(ROOTDIR)/drautil/include \
            -I $(ROOTDIR)/kernel/include\
                                -I $(ACE_HOME)/ACE_wrappers/ace\
                                -I $(ACE_HOME)/ACE_wrappers/\
                                -I $(TDSDIR)/libdiameter/include\
                                -I $(TDSDIR)/sctplibdiameter/include\
                                -I $(TDSDIR)/include\
                                -I $(TDSDIR)/dcca/include\
                                -I $(TDSDIR)/approuter/include\
                                -I $(ROOTDIR)/http/include\
                                -I $(ROOTDIR)/pcrfwrapper/include\
                                -I $(TDSDIR)/parser/include\
                                -I $(TDSDIR)/diautil/include\
                                -I $(TDSDIR)/peg/include\
                                -I $(TDSDIR)/syncredis/include\
                                -I $(DIA_PARSE)/include\
            -I $(DIA_PARSE)/diameterlib/\
            -I $(DIA_PARSE)/diameterutil/include\
            -I $(UTILDIR)/include/\
            -I $(UTILDIR)/processlock/include/\
                                -I $(TDSDIR)/rbtree/include\
                                -I $(UTILDIR)/objectpool/include/\
                                -I $(UTILDIR)/configinfo/include/\
                                -I $(UTILDIR)/trace/include/\
                                -I $(UTILDIR)/log/include/\
                                -I $(UTILDIR)/msgq/include/\
                           -I $(UTILDIR)/redissentinel/include/\
                                -I $(TPDIR)/redis-plus-plus-master/src/sw/redis++\
                                -I $(UTILDIR)/redissentinel/include/\
                                -I $(TPDIR)/redis-plus-plus-master/src/\
                                -I $(TPDIR)/hiredis/include/\
				#-I /home/tsstp/cvs/Thirdparty/src/librdkafka-2.4.0/src-cpp\
                                #-I $(TPINCL)/sw/redis++/\

ifneq (,$(findstring 64,$(shell getconf LONG_BIT) ))
   LIBDL=
   LIBSSL=/usr/lib64/libssl.so
   LIBEXPAT=/usr/lib64/libexpat.so
   LIBPTHREAD=/usr/lib64/libpthread.so
else
   LIBDL=
   LIBSSL=/usr/lib/libssl.so
   LIBEXPAT=/usr/lib/libexpat.so
   LIBPTHREAD=/usr/lib/libpthread.so
endif

                                #-I /home/anandhv/cvs/util/src/redissentinel/include/\
                                -I $(TPINCL)/sw/redis++/\
                                -I $(TP_HOME)/redis-plus-plus/src/sw/redis++/cxx11\
                                -I $(TP_HOME)/redis-plus-plus/src/sw/redis++/no_tls\
                                -I $(TP_HOME)/redis-plus-plus-master/src/\
                                -I $(TP_HOME)/redis-plus-plus-master/include/\
                                -I $(TP_HOME)/../include/sw/redis++/\
                                -I /home/anandhv/cvs/Thirdparty/src/redis-plus-plus-master/include/\
                                -I /home/anandhv/cvs/Thirdparty/src/redis-plus-plus-master/include/sw/redis++/

                        #-I $(UTILDIR)/protocolstack/include\
            -I $(UTILDIR)/protocolstack/smpp/include\
            -I $(UTILDIR)/protocolstack/cimd2/include\
            -I $(UTILDIR)/octet/include\
            -I $(UTILDIR)/thirdparty/TDAPI/include\

LIBFLAGS = $(UTILDIR)/lib/libutil.a  #$(DIA_PARSE)/diameterutil/lib/libDiameterUtil.a\

LIBDIR = lib

#################################################################
######################################################################
# list of generated object files.
OBJS1 = DraMain.o\
                  Dra.o\
                  DRA_UpccRechargeHttpRelay.o\
                  DRA_EvrWriter.o

OBJS1 := $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1 = $(UTILDIR)/lib/libutil.a\
                  $(UTILDIR)/lib/libTssRedis.a\
                  /usr/local/lib64/libredis++.a\
                  $(DIA_PARSE)/lib/libGxInterface.so\
                  $(DIA_PARSE)/lib/libS6aInterface.so\
                  $(DIA_PARSE)/lib/libRoInterface.so\
                  $(TDSDIR)/lib/libdiaBaseUtil.so\
                  $(TDSDIR)/lib/libdiameter.so\
                  $(TDSDIR)/lib/libtgmdiameter.so\
                  $(TDSDIR)/lib/libDiaHdlMsg.so\
                  $(TDSDIR)/lib/libAppRouter.so\
                  $(ROOTDIR)/lib/libHttpApi.so\
                  $(ROOTDIR)/lib/libRelayToAppln.so\
                  $(TDSDIR)/lib/libdcca.so\
                  $(ROOTDIR)/lib/libDraRouting.so\
                  $(TDSDIR)/lib/libsyncredis.so\
                  $(TDSDIR)/lib/libPegUtil.so\
                  $(DIA_PARSE)/lib/libBaseInterface.so\
                  $(DIA_PARSE)/lib/libRxInterface.so\
                  $(DIA_PARSE)/lib/libSyInterface.so\
                  $(DIA_PARSE)/lib/libSdInterface.so\
                  $(DIA_PARSE)/lib/libShInterface.so\
                  $(DIA_PARSE)/lib/libCxInterface.so\
                  $(DIA_PARSE)/lib/libSlhInterface.so\
		  /usr/local/lib/libhiredis.so\
                  $(TPDIR)/poco-1.13.3-all/lib/Linux/x86_64/libPocoXML.so\
                  $(TPDIR)/poco-1.13.3-all/lib/Linux/x86_64/libPocoUtil.so\
                  $(TPDIR)/poco-1.13.3-all/lib/Linux/x86_64/libPocoFoundation.so\
                  $(TPDIR)/poco-1.13.3-all/lib/Linux/x86_64/libPocoJSON.so\
                  $(LIBDL)\
                  $(LIBSSL)\
                  $(LIBEXPAT)\
                  $(LIBPTHREAD)\
                  /usr/lib64/libcrypto.so\
		  $(TPLIB)/librdkafka++.a\
		  $(TPLIB)/librdkafka.a\
		  -lcurl\
                  -lsasl2\
                  -lzstd\
                  #$(TPLIB)/libhiredis.so\
                  $(TP_HOME)/redis-plus-plus-master/build/lib/libredis++.a\
                  /usr/lib64/libevent.so\
                  /usr/lib64/libcrypto.so.\
                  /usr/lib64/libssl.so\
                 # $(TP_HOME)/redis-plus-plus/build/libredis++.a\
                 # $(TP_HOME)/hiredis/libhiredis.so\




        #$(TPLIB)/libboost_program_options.so\
                  $(TPLIB)/libboost_system.so.1.67.0\

# output file name.
OFILE1 = TSS_Dra

# Program dependencies
$(OFILE1): $(BINDIR)/$(OFILE1)
$(BINDIR)/$(OFILE1): $(OBJS1) $(LIBS1)


######################################################################
# List of all object files
OBJS = $(OBJS1)

########################################################################
# List of all executables to be created
PROG = $(OFILE1)
PROG := $(PROG:%=$(BINDIR)/%)

########################################################################
# List of all libraries to be created
OSLIB =
OSLIB := $(OSLIB:%=$(LIBDIR)/%)

#################################################################

include $(ROOTDIR)/makeutil/footer.mod

