# @(#) $Id:
#
ROOTDIR = $(PROJ_HOME)/protocol/diameter/tayanaBase/src

include $(ROOTDIR)/makeutil.s/header.mod

DEFS += -DCOMMONOAM
SONAME=libPegUtil.so
######################################################################
# define the include flags.
# define the list of source files.
SRCS =  DiameterPeg.cc\

SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I $(ROOTDIR)/peg/include\

######################################################################
LIBFLAGS = 

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1 =  DiameterPeg.o


OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1=#/usr/local/lib/libtcmalloc.a\

# output file name.
OFILE1= libPegUtil.so

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)


######################################################################
# List of all object files
OBJS = $(OBJS1) $(OBJS2)

########################################################################
# List of all executables to be created
PROG =
PROG := $(PROG:%=$(BINDIR)/%)

########################################################################
# List of all libraries to be created
OLIB =  
OLIB := $(OLIB:%=$(LIBDIR)/%)

########################################################################
# List of all libraries to be created
OSLIB =  $(OFILE1) 
OSLIB := $(OSLIB:%=$(LIBDIR)/%)


########################################################################

include $(ROOTDIR)/makeutil.s/footer.mod
# DO NOT DELETE
