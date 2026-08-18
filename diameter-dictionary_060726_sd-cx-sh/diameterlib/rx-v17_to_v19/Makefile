# @(#) $Id:
ROOTDIR = $(DIAPARSE_HOME)

include $(ROOTDIR)/makeutil/header.mod

DEFS += -DCOMMONOAM
#SONAME=libRxInterface.so.$(DIAMETER_MAJOR_VERSION).$(DIAMETER_MINOR_VERSION)

######################################################################
# define the include flags.
# define the list of source files.
SRCS = \
AAAnswer.cc\
AARequest.cc\
ASAnswer.cc\
ASRequest.cc\
AcceptableServiceInfo.cc\
AccessNetworkChargingIdentifier.cc\
CCMoney.cc\
CalleeInformation.cc\
ChargingRuleRemove.cc\
ExperimentalResult.cc\
FailedAVP.cc\
FiveGSRANNASReleaseCause.cc\
Flows.cc\
GrantedServiceUnit.cc\
Load.cc\
MAInformation.cc\
MediaComponentDescription.cc\
MediaSubComponent.cc\
NGAPCause.cc\
OCOLR.cc\
OCSupportedFeatures.cc\
ProxyInfo.cc\
RAAnswer.cc\
RARequest.cc\
STAnswer.cc\
STRequest.cc\
SponsoredConnectivityData.cc\
SubscriptionId.cc\
SupportedFeatures.cc\
UnitValue.cc\
UsedServiceUnit.cc\
UserEquipmentInfo.cc\
UserEquipmentInfoExtension.cc\
WirelineUserLocationInfo.cc\

SRCS := $(SRCS:%=$(SRCDIR)/%)
######################################################################
INCLFLAGS = -I $(DIAPARSE_HOME)/include\
            -I $(DIAPARSE_HOME)/diameterlib/\
            -I $(DIAPARSE_HOME)/diameterutil/include\
            -I $(UTIL_HOME)/include\


######################################################################
LIBFLAGS =  #$(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\
            $(DIAPARSE_HOME)/diameterlib/base/lib/libBaseInterface.a\

LIBDIR = lib

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS1= \
AAAnswer.o\
AARequest.o\
ASAnswer.o\
ASRequest.o\
AcceptableServiceInfo.o\
AccessNetworkChargingIdentifier.o\
CCMoney.o\
CalleeInformation.o\
ChargingRuleRemove.o\
ExperimentalResult.o\
FailedAVP.o\
FiveGSRANNASReleaseCause.o\
Flows.o\
GrantedServiceUnit.o\
Load.o\
MAInformation.o\
MediaComponentDescription.o\
MediaSubComponent.o\
NGAPCause.o\
OCOLR.o\
OCSupportedFeatures.o\
ProxyInfo.o\
RAAnswer.o\
RARequest.o\
STAnswer.o\
STRequest.o\
SponsoredConnectivityData.o\
SubscriptionId.o\
SupportedFeatures.o\
UnitValue.o\
UsedServiceUnit.o\
UserEquipmentInfo.o\
UserEquipmentInfoExtension.o\
WirelineUserLocationInfo.o\

OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\

# output file name.
OFILE1= libRxInterface.a

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS2= \
AAAnswer.o\
AARequest.o\
ASAnswer.o\
ASRequest.o\
AcceptableServiceInfo.o\
AccessNetworkChargingIdentifier.o\
CCMoney.o\
CalleeInformation.o\
ChargingRuleRemove.o\
ExperimentalResult.o\
FailedAVP.o\
FiveGSRANNASReleaseCause.o\
Flows.o\
GrantedServiceUnit.o\
Load.o\
MAInformation.o\
MediaComponentDescription.o\
MediaSubComponent.o\
NGAPCause.o\
OCOLR.o\
OCSupportedFeatures.o\
ProxyInfo.o\
RAAnswer.o\
RARequest.o\
STAnswer.o\
STRequest.o\
SponsoredConnectivityData.o\
SubscriptionId.o\
SupportedFeatures.o\
UnitValue.o\
UsedServiceUnit.o\
UserEquipmentInfo.o\
UserEquipmentInfoExtension.o\
WirelineUserLocationInfo.o\


OBJS2:= $(OBJS2:%=$(OBJDIR)/%)

# list of libraries.

LIBS2= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\

# output file name.
OFILE2= libRxInterface.so

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
