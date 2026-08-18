# @(#) $Id: header.mod,v 1.1.4.1.2.1.2.9 2024/06/14 12:40:06 mram Exp $

############ Start of system configuration section. ############

SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .cxx .cc .o .a .tcc .h .so .cxx

# use "g++" to compile c++/c source files.
#CC = $(TPDIR)/gcc11/bin/g++-11 -I$(TPINCL)
CC = g++  -I$(TPINCL) 
#-I$(UTILDIR)/log/include
#-O2

# use "javac" to compile java source files.
JAVAC = javac

# the linker is also "g++". It might be something else with other compilers.
#LD = g++ -ldl -lrt -lsctp -lpthread  -L$(TPLIB)  -lACE
#LD = g++ -ldl -lrt -lpthread -lhiredis  -L$(TPLIB)  -lACE  -levent
LD = g++ -ldl -lrt -lsctp -lpthread -L$(TPLIB) -lACE #ltcmalloc #-lboost_system -lboost_regex -lboost_serialization

# use "ar" to create libraries 
AR = ar

# use "astyle" to format source code
FORMAT = astyle

# Things you might add to DEFS: (These are defines that are used during compilation)
# -DOS=LINUX                  // If the OS is Linux
# -DOS=HPUX                   // If the OS is HP Unix
# -DOS=SOLARIS                // If the OS is Solaris
# -D_XOPEN_SOURCE
# -D_POSIX_C_SOURCE=199506L   // add IEEE Std 1003.1c-1995

#DEFS = -D_XOPEN_SOURCE=500 -D_POSIX_C_SOURCE=199506L
DEFS = -D_XOPEN_SOURCE=600 -DLINUX -DUSSD_PARAMS 

ifneq (,$(findstring 64,$(shell getconf LONG_BIT) ))
   DEFS += -D__x86_64__
endif

ifeq (1,$(CTRACE))
DEFS += -DCTRACE
endif

# Debug options
ifeq (1,$(CDEBUG))
CDEBUG = -g
#CDEBUG = -ggdb3
else
CDEBUG =
endif

# Options for code coverage utility (gcov)
# CCOV = -ftest-coverage -fprofile-arcs

# Warnings
#WFLAGS = #-Wall -W #-Wshadow -Wconversion
WFLAGS = -Wall -Wno-deprecated -Wno-write-strings # -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free

# Compiler flags go here.
CFLAGS = $(CDEBUG) $(DEFS) -ansi $(WFLAGS) $(CCOV) -std=gnu++11 -z defs
#CFLAGS = $(CDEBUG) $(DEFS) -ansi $(WFLAGS) $(CCOV) -std=gnu++17 -z defs

SONAME= 
SHFLAGS = -z defs -shared -Wl,-soname,$(SONAME) -o 

# Linker flags go here. Currently there aren't any, but if we'll switch to
# code optimization, we might add "-s" here to strip debug info and symbols.
# LDFLAGS = -static

# Compiler flags go here.
ARFLAGS = -rsuv

# use this command to erase files.
RM = /bin/rm -f

# command to create dependency file
MAKEDEP = $(CC) $(CFLAGS) -MM 
#MAKEDEP = makedepend -f- -pobj/ -- $(CFLAGS) -- $(SRCS)

############ End of system configuration section. ############

VPATH = src
OBJDIR = obj
SRCDIR = src
BINDIR = obj
EGDIR= examples

#################################################################

# top-level rule, to compile everything.
all:

