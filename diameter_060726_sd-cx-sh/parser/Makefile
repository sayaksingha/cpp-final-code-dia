# @(#) $Id:
#
ROOTDIR = $(PROJ_HOME)/protocol/diameter/tayanaBase/src

include $(ROOTDIR)/makeutil.s/header.mod

DEFS += -DCOMMONOAM
SONAME=libDiaHdlMsg.so

######################################################################
# define the include flags.
# define the list of source files.
SRCS =  DiaHandleMsg.cc\

SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I include\
	    -I $(ROOTDIR)/include\
	    -I $(ROOTDIR)/libdiameter/include\
	    -I $(ROOTDIR)/diautil/include\
	    -I $(ROOTDIR)/rbtree/include\
	    -I $(ROOTDIR)/parser/gx/include\
	    -I $(ROOTDIR)/peg/include\
	    -I $(DIA_PARSE)/include\
            -I $(DIA_PARSE)/diameterutil/include\
            -I $(DIA_PARSE)/diameterlib/\
            -I $(UTILDIR)/include\
	    -I $(UTILDIR)/log/include\
	    -I $(UTILDIR)/trace/include\
	    -I $(UTILDIR)/configinfo/include\
	    -I $(UTILDIR)/msgq/include\
	    -I $(TPINCL)/\
	    #-I $(ACE_HOME)/ACE_wrappers/ace\
	    -I $(ACE_HOME)/ACE_wrappers/ACEXML/common\
	    -I $(ACE_HOME)/ACE_wrappers/\
						
######################################################################
LIBFLAGS =  

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1 = DiaHandleMsg.o

OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1= 
#/usr/local/lib/libtcmalloc.a\

# output file name.
OFILE1= libDiaHdlMsg.so

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
# DO NOT DELETE
