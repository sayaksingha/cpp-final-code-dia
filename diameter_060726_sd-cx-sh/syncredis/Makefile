# @(#) $Id:
#
ROOTDIR = $(PROJ_HOME)/protocol/diameter/tayanaBase/src

include $(ROOTDIR)/makeutil.s/header.mod

DEFS += -DCOMMONOAM
SONAME=libsyncredis.so
######################################################################
# define the include flags.
# define the list of source files.
SRCS =  Redis.cc\
		  RedisPool.cc

SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I include\
				-I $(UTILDIR)/log/include\
				-I $(UTILDIR)/trace/include\
				-I $(UTILDIR)/configinfo/include\
				-I $(UTILDIR)/msgq/include\
            -I $(ROOTDIR)/include\
            -I $(ROOTDIR)/parser/include\
            -I $(ROOTDIR)/rbtree/include\
            -I $(ROOTDIR)/diautil/include\
            -I $(ROOTDIR)/include\
            -I $(ROOTDIR)/include\
            -I $(DIA_PARSE)/include\
            -I $(DIA_PARSE)/diameterutil/include/\
            -I $(DIA_PARSE)/diameterlib/\
            -I $(ROOTDIR)/tdsutil/include\
            -I $(ROOTDIR)/peg/include\
            -I $(ROOTDIR)/libdiameter/include\
				-I $(ROOTDIR)/approuter/include\
            -I $(ACE_HOME)/ACE_wrappers/ace\
            -I $(ACE_HOME)/ACE_wrappers/\
				-I $(UTILDIR)/include/\
				-I $(UTILDIR)/objectpool/include/\
				#-I $(TPINCL)/\

######################################################################
LIBFLAGS = 

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1 =  Redis.o RedisPool.o
		
OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1=
#/usr/lib64/libtcmalloc.so\
		#/usr/local/lib/libtcmalloc.a\

# output file name.
OFILE1= libsyncredis.so

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
OLIB =  $(OFILE1)
OLIB := $(OLIB:%=$(LIBDIR)/%)

########################################################################
# List of all libraries to be created
OSLIB =  $(OFILE1) 
OSLIB := $(OSLIB:%=$(LIBDIR)/%)


########################################################################

include $(ROOTDIR)/makeutil.s/footer.mod
# DO NOT DELETE
