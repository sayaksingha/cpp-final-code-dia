# @(#) $Id:
ROOTDIR = $(DIAPARSE_HOME)

include $(ROOTDIR)/makeutil/header.mod

DEFS += -DCOMMONOAM
#SONAME=libCxInterface.so.$(DIAMETER_MAJOR_VERSION).$(DIAMETER_MINOR_VERSION)

######################################################################
# define the include flags.
# define the list of source files.
SRCS = \
LocationInfoAnswer.cc\
LocationInfoRequest.cc\
MultimediaAuthAnswer.cc\
MultimediaAuthRequest.cc\
PushProfileAnswer.cc\
PushProfileRequest.cc\
RegistrationTerminationAnswer.cc\
RegistrationTerminationRequest.cc\
ServerAssignmentAnswer.cc\
ServerAssignmentRequest.cc\
UserAuthorizationAnswer.cc\
UserAuthorizationRequest.cc\
ExperimentalResult.cc\
Load.cc\
OCOLR.cc\
OCSupportedFeatures.cc\
ProxyInfo.cc\
ServerCapabilities.cc\
SupportedApplications.cc\
SupportedFeatures.cc\
VendorSpecificApplicationId.cc\
AllowedWAFWWSFIdentities.cc\
AssociatedIdentities.cc\
AssociatedRegisteredIdentities.cc\
ChargingInformation.cc\
DeregistrationReason.cc\
FailedAVP.cc\
FailedPCSCF.cc\
IdentitywithEmergencyRegistration.cc\
PCSCFSubscriptionInfo.cc\
RestorationInfo.cc\
SCSCFRestorationInfo.cc\
SIPAuthDataItem.cc\
SIPDigestAuthenticate.cc\
SubscriptionInfo.cc\

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
LocationInfoAnswer.o\
LocationInfoRequest.o\
MultimediaAuthAnswer.o\
MultimediaAuthRequest.o\
PushProfileAnswer.o\
PushProfileRequest.o\
RegistrationTerminationAnswer.o\
RegistrationTerminationRequest.o\
ServerAssignmentAnswer.o\
ServerAssignmentRequest.o\
UserAuthorizationAnswer.o\
UserAuthorizationRequest.o\
ExperimentalResult.o\
Load.o\
OCOLR.o\
OCSupportedFeatures.o\
ProxyInfo.o\
ServerCapabilities.o\
SupportedApplications.o\
SupportedFeatures.o\
VendorSpecificApplicationId.o\
AllowedWAFWWSFIdentities.o\
AssociatedIdentities.o\
AssociatedRegisteredIdentities.o\
ChargingInformation.o\
DeregistrationReason.o\
FailedAVP.o\
FailedPCSCF.o\
IdentitywithEmergencyRegistration.o\
PCSCFSubscriptionInfo.o\
RestorationInfo.o\
SCSCFRestorationInfo.o\
SIPAuthDataItem.o\
SIPDigestAuthenticate.o\
SubscriptionInfo.o\

OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\

# output file name.
OFILE1= libCxInterface.a

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS2= \
LocationInfoAnswer.o\
LocationInfoRequest.o\
MultimediaAuthAnswer.o\
MultimediaAuthRequest.o\
PushProfileAnswer.o\
PushProfileRequest.o\
RegistrationTerminationAnswer.o\
RegistrationTerminationRequest.o\
ServerAssignmentAnswer.o\
ServerAssignmentRequest.o\
UserAuthorizationAnswer.o\
UserAuthorizationRequest.o\
ExperimentalResult.o\
Load.o\
OCOLR.o\
OCSupportedFeatures.o\
ProxyInfo.o\
ServerCapabilities.o\
SupportedApplications.o\
SupportedFeatures.o\
VendorSpecificApplicationId.o\
AllowedWAFWWSFIdentities.o\
AssociatedIdentities.o\
AssociatedRegisteredIdentities.o\
ChargingInformation.o\
DeregistrationReason.o\
FailedAVP.o\
FailedPCSCF.o\
IdentitywithEmergencyRegistration.o\
PCSCFSubscriptionInfo.o\
RestorationInfo.o\
SCSCFRestorationInfo.o\
SIPAuthDataItem.o\
SIPDigestAuthenticate.o\
SubscriptionInfo.o\


OBJS2:= $(OBJS2:%=$(OBJDIR)/%)

# list of libraries.

LIBS2= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\

# output file name.
OFILE2= libCxInterface.so

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
