# @(#) $Id:
#
ROOTDIR = $(PROJ_HOME)/protocol/diameter/tayanaBase/src

include $(ROOTDIR)/makeutil.s/header.mod

DEFS += -DCOMMONOAM -g

######################################################################
# define the include flags.
# define the list of source files.
SRCS =   tss_rbtree.cc\
			aaa_session_storage.cc\
		   aaa_rbtree_base.cc\
			stubrbtree.cc\
			stubrbtree_new.cc

SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I include\
	    -I $(ROOTDIR)/libdiameter/include\
	    -I $(ROOTDIR)/diautil/include\
	    -I $(ROOTDIR)/include\
	    -I $(ROOTDIR)/peg/include\
	    -I $(ROOTDIR)/parser/include\
	    -I $(UTILDIR)/semaphore/include\
	    -I $(ROOTDIR)/ACE_wrappers/ace\
	    -I $(ROOTDIR)/ACE_wrappers/\
	    -I $(DIA_PARSE)/include\
	    -I $(DIA_PARSE)/diameterlib/\
       -I $(DIA_PARSE)/diameterutil/include\
	    -I $(UTILDIR)/include\
	    -I $(UTILDIR)/log/include\
	    -I $(UTILDIR)/trace/include\
	    -I $(UTILDIR)/configinfo/include\
	    -I $(UTILDIR)/msgq/include\
	    -I $(ROOTDIR)/include\

######################################################################
LIBFLAGS = $(UTILDIR)/lib/libutil.a\

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1 =  tss_rbtree.o aaa_session_storage.o


OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1= 
#/usr/local/lib/libtcmalloc.a

# output file name.
OFILE1= libTssRBTree.a

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)
######################################################################
OBJS2 =  stubrbtree.o

OBJS2:= $(OBJS2:%=$(OBJDIR)/%)

# list of libraries.
LIBS2 = lib/libTssRBTree.a

# output file name.
OFILE2= StubSessionRBTree

# Program dependencies
$(OFILE2): $(BINDIR)/$(OFILE2)
$(BINDIR)/$(OFILE2): $(OBJS2) $(LIBS2)
######################################################################
OBJS3 =  stubrbtree_new.o

OBJS3:= $(OBJS3:%=$(OBJDIR)/%)

# list of libraries.
LIBS3= lib/libTssRBTree.a
# ../diautil/lib/libodutl.a

# output file name.
OFILE3= StubSessionRBTreeNew

# Program dependencies
$(OFILE3): $(BINDIR)/$(OFILE3)
$(BINDIR)/$(OFILE3): $(OBJS3) $(LIBS3)

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS4 = aaa_rbtree_base.o 
#aaa_session_storage.o

OBJS4:= $(OBJS4:%=$(OBJDIR)/%)

# list of libraries.
LIBS4 = 

# output file name.
OFILE4 = libBaseRBTree.a

# Program dependencies
$(OFILE4): $(LIBDIR)/$(OFILE4)
$(LIBDIR)/$(OFILE4): $(OBJS4) $(LIBS4)

######################################################################
# List of all object files
OBJS = $(OBJS1)  $(OBJS3)

########################################################################
# List of all executables to be created
PROG = #$(OFILE3)
PROG := $(PROG:%=$(BINDIR)/%)
########################################################################
# List of all libraries to be created
OLIB =  $(OFILE1) $(OFILE4)
OLIB := $(OLIB:%=$(LIBDIR)/%)


########################################################################

include $(ROOTDIR)/makeutil.s/footer.mod
# DO NOT DELETE

