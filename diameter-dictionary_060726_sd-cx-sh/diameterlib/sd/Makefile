# @(#) $Id:
ROOTDIR = $(DIAPARSE_HOME)

include $(ROOTDIR)/makeutil/header.mod

DEFS += -DCOMMONOAM
#SONAME=libSdInterface.so.$(DIAMETER_MAJOR_VERSION).$(DIAMETER_MINOR_VERSION)

######################################################################
# define the include flags.
# define the list of source files.
SRCS = \
ADCRuleDefinition.cc\
ADCRuleInstall.cc\
ADCRuleRemove.cc\
ADCRuleReport.cc\
AllocationRetentionPriority.cc\
ApplicationDetectionInformation.cc\
ChargingInformation.cc\
ExperimentalResult.cc\
FailedAVP.cc\
FixedUserLocationInfo.cc\
FlowInformation.cc\
GrantedServiceUnit.cc\
Load.cc\
OCOLR.cc\
OCSupportedFeatures.cc\
PresenceReportingAreaInformation.cc\
ProxyInfo.cc\
QoSInformation.cc\
ReAuthAnswer.cc\
SubscriptionId.cc\
SupportedFeatures.cc\
UsageMonitoringInformation.cc\
UsedServiceUnit.cc\
UserCSGInformation.cc\
UserEquipmentInfo.cc\
UserEquipmentInfoExtension.cc\
VendorSpecificApplicationId.cc\
CreditControlRequest.cc\
CreditControlAnswer.cc\
TDFSessionAnswer.cc\
TDFSessionRequest.cc\
ConditionalAPNAggregateMaxBitrate.cc\
AreaScope.cc\
EventReportIndication.cc\
FinalUnitIndication.cc\
MDTConfiguration.cc\
RedirectInformation.cc\
RedirectServer.cc\
TraceData.cc\
ReAuthRequest.cc\

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
ADCRuleDefinition.o\
ADCRuleInstall.o\
ADCRuleRemove.o\
ADCRuleReport.o\
AllocationRetentionPriority.o\
ApplicationDetectionInformation.o\
ChargingInformation.o\
ExperimentalResult.o\
FailedAVP.o\
FixedUserLocationInfo.o\
FlowInformation.o\
GrantedServiceUnit.o\
Load.o\
OCOLR.o\
OCSupportedFeatures.o\
PresenceReportingAreaInformation.o\
ProxyInfo.o\
QoSInformation.o\
ReAuthAnswer.o\
SubscriptionId.o\
SupportedFeatures.o\
UsageMonitoringInformation.o\
UsedServiceUnit.o\
UserCSGInformation.o\
UserEquipmentInfo.o\
UserEquipmentInfoExtension.o\
VendorSpecificApplicationId.o\
CreditControlRequest.o\
CreditControlAnswer.o\
TDFSessionAnswer.o\
TDFSessionRequest.o\
ConditionalAPNAggregateMaxBitrate.o\
AreaScope.o\
EventReportIndication.o\
FinalUnitIndication.o\
MDTConfiguration.o\
RedirectInformation.o\
RedirectServer.o\
TraceData.o\
ReAuthRequest.o\

OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\

# output file name.
OFILE1= libSdInterface.a

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS2= \
ADCRuleDefinition.o\
ADCRuleInstall.o\
ADCRuleRemove.o\
ADCRuleReport.o\
AllocationRetentionPriority.o\
ApplicationDetectionInformation.o\
ChargingInformation.o\
ExperimentalResult.o\
FailedAVP.o\
FixedUserLocationInfo.o\
FlowInformation.o\
GrantedServiceUnit.o\
Load.o\
OCOLR.o\
OCSupportedFeatures.o\
PresenceReportingAreaInformation.o\
ProxyInfo.o\
QoSInformation.o\
ReAuthAnswer.o\
SubscriptionId.o\
SupportedFeatures.o\
UsageMonitoringInformation.o\
UsedServiceUnit.o\
UserCSGInformation.o\
UserEquipmentInfo.o\
UserEquipmentInfoExtension.o\
VendorSpecificApplicationId.o\
CreditControlRequest.o\
CreditControlAnswer.o\
TDFSessionAnswer.o\
TDFSessionRequest.o\
ConditionalAPNAggregateMaxBitrate.o\
AreaScope.o\
EventReportIndication.o\
FinalUnitIndication.o\
MDTConfiguration.o\
RedirectInformation.o\
RedirectServer.o\
TraceData.o\
ReAuthRequest.o\


OBJS2:= $(OBJS2:%=$(OBJDIR)/%)

# list of libraries.

LIBS2= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\

# output file name.
OFILE2= libSdInterface.so

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
