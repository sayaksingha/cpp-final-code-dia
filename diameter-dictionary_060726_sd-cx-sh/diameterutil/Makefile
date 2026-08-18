# @(#) $Id:
ROOTDIR = $(PROJ_HOME)/protocol/diameter/tayana/src

include $(ROOTDIR)/makeutil/header_dynamic.mod

DEFS += -DCOMMONOAM

######################################################################
# define the include flags.
# define the list of source files.
SRCS = DiameterBasicDecEnc.cc\
       DiameterTLVUtil.cc\
       TssDiameterMsgException.cc\

SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I $(ROOTDIR)/diameterutil/include\
            -I $(ROOTDIR)/include\
            -I $(UTIL_HOME)/include\

######################################################################
LIBFLAGS =  $(UTIL_HOME)/lib/libutil.a\

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1= DiameterBasicDecEnc.o DiameterTLVUtil.o TssDiameterMsgException.o

OBJS1:= $(OBJS1:%=$(OBJDIR)/%) 

# list of libraries.
LIBS1=

# output file name.
OFILE1= libDiameterUtil.a

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)

######################################################################
# List of all object files
OBJS = $(OBJS1)

########################################################################
# List of all libraries to be created
OLIB =  $(OFILE1)
OLIB := $(OLIB:%=$(LIBDIR)/%)

########################################################################
# List of all executables to be created
PROG = 
PROG := $(PROG:%=$(BINDIR)/%)

########################################################################

include $(ROOTDIR)/makeutil/footer_dynamic.mod
# DO NOT DELETE
