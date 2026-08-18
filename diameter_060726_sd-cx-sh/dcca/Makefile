# @(#) $Id:
#
ROOTDIR = $(PROJ_HOME)/protocol/diameter/tayanaBase/src

include $(ROOTDIR)/makeutil.s/header.mod

DEFS += -DCOMMONOAM
SONAME=libdcca.so

######################################################################
# define the include flags.
# define the list of source files.
SRCS = diameter_cc_proxy_fsm.cc\
		 diameter_cc_proxy_rx_fsm.cc\
		 diameter_cc_proxy_sy_fsm.cc\
		 diameter_cc_proxy_s6a_fsm.cc\
		 diameter_cc_proxy_slh_fsm.cc\
                 diameter_cc_proxy_sd_fsm.cc\
                 diameter_cc_proxy_sh_fsm.cc\
		 diameter_cc_proxy_cx_fsm.cc\
                 diameter_cc_proxy_session.cc\
		 diameter_cc_application.cc\
   	 DRA_RelayRspEventWriter.cc\
	#	 diameter_cc_application_old_sessionDb.cc\



SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I include\
            -I $(ROOTDIR)/include\
            -I $(ROOTDIR)/libdiameter/include\
            -I $(ROOTDIR)/diautil/include\
            -I $(ROOTDIR)/parser/include\
	    -I $(ROOTDIR)/include\
	    -I $(ROOTDIR)/include\
	    -I $(ROOTDIR)/db/include\
	    -I $(ROOTDIR)/tdsutil/include\
	    -I $(ROOTDIR)/rbtree/include\
	    -I $(ROOTDIR)/peg/include\
	    -I $(ROOTDIR)/approuter/include\
	    -I $(ROOTDIR)/syncredis/include\
	    -I $(ACE_HOME)/ACE_wrappers/ace\
	    -I $(ACE_HOME)/ACE_wrappers/\
	    -I $(DIA_PARSE)/include\
	    -I $(DIA_PARSE)/diameterlib/\
            -I $(DIA_PARSE)/diameterutil/include\
            -I $(UTILDIR)/include\
	    -I $(UTILDIR)/log/include\
	    -I $(UTILDIR)/trace/include\
	    -I $(UTILDIR)/configinfo/include\
	    -I $(UTILDIR)/msgq/include\
	    -I $(TPINCL)/\
		 -I $(UTILDIR)/objectpool/include/\
		 #-I /home/anandhv/cvs/diameter_apps/src/tssdra/src/include/\
		 #-I /home/anandhv/cvs/diameter_apps/src/tssdra/src/drautil/include/\
		 #-I /home/anandhv/cvs/diameter_apps/src/tssdra/src/http/include/

######################################################################
LIBFLAGS = $(ROOTDIR)/rbtree/lib/libTssRBTree.a 

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1 = diameter_cc_proxy_fsm.o\
		  diameter_cc_proxy_rx_fsm.o\
		  diameter_cc_proxy_sy_fsm.o\
		  diameter_cc_proxy_s6a_fsm.o\
		  diameter_cc_proxy_slh_fsm.o\
		  diameter_cc_proxy_session.o\
                  diameter_cc_proxy_sd_fsm.o\
                  diameter_cc_proxy_sh_fsm.o\
                  diameter_cc_proxy_cx_fsm.o\
                  diameter_cc_application.o\
		  DRA_RelayRspEventWriter.o\
		  #diameter_cc_application_old_sessionDb.o\

OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1=$(ROOTDIR)//lib/libPegUtil.so\
		$(ROOTDIR)/rbtree/lib/libTssRBTree.a\
		#/usr/local/lib/libtcmalloc.a\

# output file name.
OFILE1= libdcca.so

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)

######################################################################
# List of all object files
OBJS = $(OBJS1)

########################################################################
# List of all executables to be created
PROG =
PROG := $(PROG:%=$(BINDIR)/%)
########################################################################
# List of all libraries to be created
OSLIB =  $(OFILE1)
OSLIB := $(OSLIB:%=$(LIBDIR)/%)


########################################################################

include $(ROOTDIR)/makeutil.s/footer.mod
