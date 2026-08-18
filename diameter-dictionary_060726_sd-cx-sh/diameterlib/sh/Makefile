# @(#) $Id:
ROOTDIR = $(DIAPARSE_HOME)

include $(ROOTDIR)/makeutil/header.mod

DEFS += -DCOMMONOAM
#SONAME=libShInterface.so.$(DIAMETER_MAJOR_VERSION).$(DIAMETER_MINOR_VERSION)

######################################################################
# define the include flags.
# define the list of source files.
SRCS = \
CallReferenceInfo.cc\
ExperimentalResult.cc\
FailedAVP.cc\
Load.cc\
OCOLR.cc\
OCSupportedFeatures.cc\
ProfileUpdateRequest.cc\
ProxyInfo.cc\
PushNotificationAnswer.cc\
PushNotificationRequest.cc\
RepositoryDataID.cc\
SubscribeNotificationsAnswer.cc\
SubscribeNotificationsRequest.cc\
SupportedFeatures.cc\
UserDataAnswer.cc\
UserDataRequest.cc\
UserIdentity.cc\
VendorSpecificApplicationId.cc\
ProfileUpdateAnswer.cc\
SupportedApplications.cc\

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
CallReferenceInfo.o\
ExperimentalResult.o\
FailedAVP.o\
Load.o\
OCOLR.o\
OCSupportedFeatures.o\
ProfileUpdateRequest.o\
ProxyInfo.o\
PushNotificationAnswer.o\
PushNotificationRequest.o\
RepositoryDataID.o\
SubscribeNotificationsAnswer.o\
SubscribeNotificationsRequest.o\
SupportedFeatures.o\
UserDataAnswer.o\
UserDataRequest.o\
UserIdentity.o\
VendorSpecificApplicationId.o\
ProfileUpdateAnswer.o\
SupportedApplications.o\

OBJS1:= $(OBJS1:%=$(OBJDIR)/%)

# list of libraries.
LIBS1= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\

# output file name.
OFILE1= libShInterface.a

# Program dependencies
$(OFILE1): $(LIBDIR)/$(OFILE1)
$(LIBDIR)/$(OFILE1): $(OBJS1) $(LIBS1)

######################################################################
#    ********** For Library creation ***********
# list of generated object files.
OBJS2= \
CallReferenceInfo.o\
ExperimentalResult.o\
FailedAVP.o\
Load.o\
OCOLR.o\
OCSupportedFeatures.o\
ProfileUpdateRequest.o\
ProxyInfo.o\
PushNotificationAnswer.o\
PushNotificationRequest.o\
RepositoryDataID.o\
SubscribeNotificationsAnswer.o\
SubscribeNotificationsRequest.o\
SupportedFeatures.o\
UserDataAnswer.o\
UserDataRequest.o\
UserIdentity.o\
VendorSpecificApplicationId.o\
ProfileUpdateAnswer.o\
SupportedApplications.o\


OBJS2:= $(OBJS2:%=$(OBJDIR)/%)

# list of libraries.

LIBS2= $(DIAPARSE_HOME)/diameterutil/lib/libDiameterUtil.a\

# output file name.
OFILE2= libShInterface.so

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
