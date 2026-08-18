# @(#) $Id:
#
ROOTDIR = $(PROJ_HOME)/protocol/diameter/tayanaBase/src

include $(ROOTDIR)/makeutil.s/header.mod

DEFS += -DCOMMONOAM
SONAME=libdiaBaseUtil.so
######################################################################
# define the include flags.
# define the list of source files.
SRCS =  aaa_xml_sax_parser.cc\
	aaa_rbtree.cc\
		  #ThrottleManagerV1.cc\
		   ThrottleManagerV2.cc\

SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I include\
	    -I $(ROOTDIR)/libdiameter/include\
	    -I $(ROOTDIR)/diautil/include\
	    -I $(ROOTDIR)/include\
	    -I $(ROOTDIR)/peg/include\
	    -I $(DIA_PARSE)/diameterlib/include\
	    -I $(DIA_PARSE)/diameterutil/include\
	    -I $(UTILDIR)/include\
	    -I $(UTILDIR)/log/include\
	    -I $(UTILDIR)/trace/include\
	    -I $(UTILDIR)/configinfo/include\
	    -I $(UTILDIR)/msgq/include\
	    -I $(TPINCL)/\
	    -I $(ACE_HOME)/ACE_wrappers/ace\
	    -I $(ACE_HOME)/ACE_wrappers/ACEXML/common\
	    -I $(ACE_HOME)/ACE_wrappers/\

######################################################################
LIBFLAGS = $(DIA_PARSE)/diameterutil/lib/libDiameterUtil.a\

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1 =  aaa_rbtree.o\
	 aaa_xml_sax_parser.o\
			#ThrottleManagerV1.o\
			ThrottleManagerV2.o\
		
OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1=

# output file name.
OFILE1= libdiaBaseUtil.so

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)


######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS2 =  aaa_rbtree.o\
	 aaa_xml_sax_parser.o\
			#ThrottleManagerV1.o\
			ThrottleManagerV2.o\

OBJS2:= $(OBJS2:%=$(OBJDIR)/%)

# list of libraries.
LIBS2=

# output file name.
OFILE2= libdiaBaseUtil.a

# Program dependencies
$(OFILE2): $(LIBDIR)/$(OFILE2)
$(LIBDIR)/$(OFILE2): $(OBJS2) $(LIBS2)

######################################################################
# List of all object files
OBJS = $(OBJS1) $(OBJS2)

########################################################################
# List of all executables to be created
PROG =
PROG := $(PROG:%=$(BINDIR)/%)

########################################################################
# List of all libraries to be created
OLIB =  $(OFILE2)
OLIB := $(OLIB:%=$(LIBDIR)/%)

########################################################################
# List of all libraries to be created
OSLIB =  $(OFILE1) 
OSLIB := $(OSLIB:%=$(LIBDIR)/%)


########################################################################

include $(ROOTDIR)/makeutil.s/footer.mod
# DO NOT DELETE
