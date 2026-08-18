# @(#) $Id:
#
ROOTDIR = $(PROJ_HOME)/protocol/diameter/tayanaBase/src

include $(ROOTDIR)/makeutil.s/header.mod

DEFS += -DCOMMONOAM
SONAME=libAppRouter.so

######################################################################
# define the include flags.
# define the list of source files.
SRCS = DCCA_ConfigHandler.cc\
		 DCCA_Router.cc\
		 DCCA_RouteProxyHdlr.cc\
	#	 diameter_cc_application_old_sessionDb.cc\



SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I include\
            -I $(ROOTDIR)/include\
            -I $(ROOTDIR)/libdiameter/include\
            -I $(ROOTDIR)/diautil/include\
            -I $(ROOTDIR)/dcca/include\
            -I $(ROOTDIR)/parser/include\
	    -I $(ROOTDIR)/db/include\
	    -I $(ROOTDIR)/tdsutil/include\
	    -I $(ROOTDIR)/rbtree/include\
	    -I $(ROOTDIR)/peg/include\
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
	    -I $(ROOTDIR)/syncredis/include\
	    -I $(UTILDIR)/objectpool/include/\

######################################################################
LIBFLAGS = $(ROOTDIR)/rbtree/lib/libTssRBTree.a 

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1 = DCCA_ConfigHandler.o\
		  DCCA_Router.o\
		  DCCA_RouteProxyHdlr.o\
		  #diameter_cc_application_old_sessionDb.o\

OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1= $(ROOTDIR)/rbtree/lib/libTssRBTree.a\
#		 /usr/local/lib/libtcmalloc.a\
#$(ROOTDIR)/peg/lib/libPegUtil.so\

# output file name.
OFILE1= libAppRouter.so

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
