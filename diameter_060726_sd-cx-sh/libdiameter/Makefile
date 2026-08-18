# @(#) $Id:
#
ROOTDIR = $(PROJ_HOME)/protocol/diameter/tayanaBase/src

include $(ROOTDIR)/makeutil.s/header.mod

DEFS += -DCOMMONOAM
SONAME=libdiameter.so
######################################################################
# define the include flags.
# define the list of source files.
SRCS = aaa_application.cc\
		 aaa_peer_fsm.cc\
		 aaa_peer_table.cc\
		 aaa_session_db.cc\
		 aaa_route_msg_router.cc\
		 aaa_route_table.cc\
		 aaa_session_attributes.cc\
		 aaa_transport_collector.cc\
		 aaa_xml_data.cc\
		 aaa_session_msg_rx.cc\
		 aaa_redis_pool.cc

#		 aaa_session_server.cc\
		 aaa_session_client.cc\
		 aaa_session_auth_client_fsm.cc\
		 aaa_session_auth_server_fsm.cc\

SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I include\
            -I $(ROOTDIR)/include\
            -I $(ROOTDIR)/parser/include\
            -I $(ROOTDIR)/rbtree/include\
            -I $(ROOTDIR)/diautil/include\
	    -I $(ROOTDIR)/include\
	    -I $(ROOTDIR)/include\
	    -I $(ROOTDIR)/db/include\
	    -I $(ROOTDIR)/tdsutil/include\
	    -I $(ROOTDIR)/peg/include\
	    -I $(ROOTDIR)/syncredis/include\
	    -I $(ROOTDIR)/approuter/include\
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
            #-I $(ROOTDIR)/dcca/include\
            -I $(ROOTDIR)/approuter/include\
	
######################################################################
LIBFLAGS = 

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1 = aaa_application.o  aaa_peer_fsm.o\
        aaa_peer_table.o aaa_route_msg_router.o aaa_route_table.o\
        aaa_session_attributes.o\
        aaa_session_msg_rx.o\
        aaa_transport_collector.o\
        aaa_session_db.o\
        aaa_xml_data.o\
		  aaa_redis_pool.o

#	 	  aaa_session_server.o\
		  aaa_session_client.o\
        aaa_session_auth_client_fsm.o\
        aaa_session_auth_server_fsm.o\


OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1= #/usr/local/lib/libtcmalloc.a\
# output file name.
OFILE1= libdiameter.so

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)

######################################################################
OBJS2 = DynamicCfgParser.o

OBJS2:= $(OBJS2:%=$(OBJDIR)/%)

# list of libraries.
LIBS2= lib/libdiameter.a\
		 #/usr/local/lib/libtcmalloc.a

# output file name.
OFILE2= libdynamicCfg.a

# Program dependencies
$(OFILE2): $(LIBDIR)/$(OFILE2)
$(LIBDIR)/$(OFILE2): $(OBJS2) $(LIBS2)

######################################################################
# List of all object files
OBJS = $(OBJS1) # $(OBJS2) $(OBJS3)

########################################################################
# List of all executables to be created
PROG =
PROG := $(PROG:%=$(BINDIR)/%)
########################################################################
# List of all libraries to be created
OSLIB =  $(OFILE1) #$(OFILE2)
OSLIB := $(OSLIB:%=$(LIBDIR)/%)


########################################################################

include $(ROOTDIR)/makeutil.s/footer.mod
# DO NOT DELETE
