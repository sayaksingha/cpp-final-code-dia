# @(#) $Id:
ROOTDIR = $(PROJ_HOME)/tssdra/src

include $(ROOTDIR)/makeutil/header.mod

DEFS += -DCOMMONOAM -DACE_LACKS_STROPTS_H #-DDEV_TEST

SONAME=libDraRouting.so

SRCS = DraParser.cc\
       DraRouting.cc\
		 DRA_ConfigHandler.cc\


SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I include\
            -I $(ROOTDIR)/include\
            -I $(ROOTDIR)/http/include\
            -I $(ROOTDIR)/drautil/include\
            -I $(DIA_PARSE)/include\
            -I $(DIA_PARSE)/diameterlib/\
            -I $(DIA_PARSE)/diameterutil/include\
	    -I $(TDSDIR)/include\
	    -I $(TDSDIR)/libdiameter/include\
	    -I $(TDSDIR)/diautil/include\
	    -I $(TDSDIR)/peg/include\
	    -I $(TDSDIR)/parser/include\
	    -I $(TDSDIR)/dcca/include\
            -I $(UTILDIR)/include\
       -I $(UTILDIR)/log/include\
       -I $(UTILDIR)/trace/include\
       -I $(UTILDIR)/configinfo/include\
       -I $(UTILDIR)/msgq/include\
       -I $(TPLIB)\
       -I $(BOOST)/\

######################################################################

ifneq (,$(findstring 64,$(shell getconf LONG_BIT) ))
LIBEXPAT=/usr/lib64/libexpat.so
else
LIBEXPAT=/usr/lib/libexpat.a
endif

#################################################################
# define the library flags.
LIBFLAGS = -lboost_regex 

#################################################################


######################################################################
# define the library flags.
LIBDIR = lib

######################################################################
# list of generated object files.
OBJS1 = DraParser.o\
		  DraRouting.o\
		  DRA_ConfigHandler.o

OBJS1 := $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1 =

# output file name.
#OFILE1 = libDRARouting.a
OFILE1 = libDraRouting.so

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
OSLIB = $(OFILE1)
OSLIB := $(OSLIB:%=$(LIBDIR)/%)

########################################################################

########################################################################
include $(ROOTDIR)/makeutil/footer.mod
# DO NOT DELETE
