# @(#) $Id:
ROOTDIR = $(PROJ_HOME)/protocol/diameter/tayana/src

include $(ROOTDIR)/makeutil/header.mod

DEFS += -DCOMMONOAM

######################################################################
# define the list of source files.
SRCS = DiameterCreateSource.cc\
		 diameter.l\
		 diameter.y\
 
SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
# define the include flags.
INCLFLAGS =	-I $(ROOTDIR)/kernel/include\
		-I $(ROOTDIR)/include\
		-I $(ROOTDIR)/diameterlib/include\
		-I $(ROOTDIR)/diameterutil/include\
		-I $(UTIL_HOME)/include\

######################################################################
LIBFLAGS =  

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1= 

OBJS1:= $(OBJS1:%=$(OBJDIR)/%) 

# list of libraries.
LIBS1= 

# output file name.
OFILE1=

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS2= diameter.tab.o diameter.yy.o DiameterCreateSource.o

OBJS2:= $(OBJS2:%=$(OBJDIR)/%) 

# list of libraries.
LIBS2= /usr/lib64/libfl.a

# output file name.
OFILE2=DiameterCreateSource 

# Program dependencies
$(OFILE2): $(BINDIR)/$(OFILE2)
$(BINDIR)/$(OFILE2): $(OBJS2) $(LIBS2)

######################################################################
# List of all object files
OBJS = $(OBJS2) #$(OBJS1) 

########################################################################
# List of all libraries to be created
OLIB =  
OLIB := $(OLIB:%=$(LIBDIR)/%)

########################################################################
# List of all executables to be created
PROG = $(OFILE2)
PROG := $(PROG:%=$(BINDIR)/%)

########################################################################

include $(ROOTDIR)/makeutil/footer.mod
# DO NOT DELETE
