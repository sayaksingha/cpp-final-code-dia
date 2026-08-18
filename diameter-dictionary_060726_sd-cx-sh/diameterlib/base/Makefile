# @(#) $Id:
ROOTDIR = $(DIAPARSE_HOME)

include $(ROOTDIR)/makeutil/header.mod

DEFS += -DCOMMONOAM
#SONAME=libBaseInterface.so.$(DIAMETER_MAJOR_VERSION).$(DIAMETER_MINOR_VERSION)
######################################################################
# define the include flags.
# define the list of source files.
SRCS = \
AbortSessionAnswer.cc\
AbortSessionRequest.cc\
AccountingRequest.cc\
AccountingResponse.cc\
CapabilityExchangeAnswer.cc\
CapabilityExchangeRequest.cc\
DeviceWatchdogAnswer.cc\
DeviceWatchdogRequest.cc\
DisconnectPeerAnswer.cc\
DisconnectPeerRequest.cc\
ProxyInfo.cc\
ReAuthAnswer.cc\
ReAuthRequest.cc\
SessionTerminationAnswer.cc\
SessionTerminationRequest.cc\
VendorSpecificApplicationId.cc\
DiameterBase.cc\

SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I $(DIAPARSE_HOME)/include\
            -I $(DIAPARSE_HOME)/diameterlib/\
            -I $(DIAPARSE_HOME)/diameterutil/include\
            -I $(UTIL_HOME)/include\


######################################################################
LIBFLAGS =  #$(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1= \
AbortSessionAnswer.o\
AbortSessionRequest.o\
AccountingRequest.o\
AccountingResponse.o\
CapabilityExchangeAnswer.o\
CapabilityExchangeRequest.o\
DeviceWatchdogAnswer.o\
DeviceWatchdogRequest.o\
DisconnectPeerAnswer.o\
DisconnectPeerRequest.o\
ProxyInfo.o\
ReAuthAnswer.o\
ReAuthRequest.o\
SessionTerminationAnswer.o\
SessionTerminationRequest.o\
VendorSpecificApplicationId.o\
DiameterBase.o\

OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\

# output file name.
OFILE1= libBaseInterface.a

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS2= \
AbortSessionAnswer.o\
AbortSessionRequest.o\
AccountingRequest.o\
AccountingResponse.o\
CapabilityExchangeAnswer.o\
CapabilityExchangeRequest.o\
DeviceWatchdogAnswer.o\
DeviceWatchdogRequest.o\
DisconnectPeerAnswer.o\
DisconnectPeerRequest.o\
ProxyInfo.o\
ReAuthAnswer.o\
ReAuthRequest.o\
SessionTerminationAnswer.o\
SessionTerminationRequest.o\
VendorSpecificApplicationId.o\
DiameterBase.o\


OBJS2:= $(OBJS2:%=$(OBJDIR)/%)

# list of libraries.

LIBS2= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\

# output file name.
OFILE2= libBaseInterface.so

# Program dependencies
$(OFILE2): $(LIBDIR)/$(OFILE2)
$(LIBDIR)/$(OFILE2): $(OBJS2) $(LIBS2)

######################################################################
# List of all object files
OBJS = $(OBJS1) $(OBJS2)

######################################################################
# List of all libraries to be created
OLIB =  $(OFILE1)
OLIB := $(OLIB:%=$(LIBDIR)/%)

OSLIB =  $(OFILE2)
OSLIB := $(OSLIB:%=$(LIBDIR)/%)
######################################################################
# List of all executables to be created
PROG =
PROG := $(PROG:%=$(BINDIR)/%)

########################################################################

include $(ROOTDIR)/makeutil/footer.mod
# DO NOT DELETE
