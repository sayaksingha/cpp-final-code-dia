# @(#) $Id: footer.mod,v 1.1.4.1 2017/11/22 00:35:11 shijuc Exp $

.PHONY : all clean cleanall depend sloc java

############ Target  ############
# top-level rule, to compile everything.
all: $(OSLIB) $(OLIB) $(PROG) $(STUBS)

$(PROG): $(LIBFLAGS)

$(STUBS): $(LIBFLAGS)

# Build libraries
$(OLIB):
	$(AR) $(ARFLAGS) $@ $^

# Build  shared libraries
$(OSLIB):
	$(LD) $(SHFLAGS) $@ $^
	@cp -f $@ $(ROOTDIR)/lib/

# Build executables
$(PROG):
	$(LD) $(LDFLAGS) $^ $(LIBFLAGS) -o $@
	@cp -f $@ $(ROOTDIR)/bin/

# Build stubs
$(STUBS):
	$(LD) $(LDFLAGS) $^ $(LIBFLAGS) -o $@
	@cp -f $@ $(ROOTDIR)/bin/stubs

#################################
# now comes a meta-rule for compiling any "C++" source file.
$(OBJDIR)/%.o: %.cc
	$(CC) $(INCLFLAGS) -fPIC $(CFLAGS) -c $< -o $@

# now comes a meta-rule for compiling any "C" source file.
$(OBJDIR)/%.o: %.c
	$(CC) $(INCLFLAGS) $(CFLAGS) -c $< -o $@

############ Clean up ############
# rule for cleaning re-compilable files.
clean:
	$(RM) $(PROG) $(OBJS) $(STUBS)

files:
	@ls -1 java/*.java > $@

java: files
	@rm -f obj/*.class
	@mkdirhier $(ROOTDIR)/wmcaoam/WEB-INF/classes
	@if test `ls -1 java/*.java 2>/dev/null| wc -l` -gt 0; then $(JAVAC) -nowarn -deprecation -classpath .:$(CLASSPATH) @files -d obj;cp -Rf obj/* $(ROOTDIR)/wmcaoam/WEB-INF/classes; fi 
	@if ! test -d $(ROOTDIR)/wmcaoam/$(CURR_DIR); then mkdirhier $(ROOTDIR)/wmcaoam/$(CURR_DIR); fi 
	@if test `ls -1 jsp/*.jsp 2>/dev/null| wc -l` -gt 0; then cp -Rf jsp/*.jsp $(ROOTDIR)/wmcaoam/$(CURR_DIR)/ ; fi

# rule for cleaning re-compilable files and libraries.
cleanall: 
	$(RM) $(PROG) $(OBJS) $(OLIB) $(OSLIB) $(OTHERS) $(STUBS)

# rule for making shared library
shared:
	$(LD) -shared -Wl,-soname,libInHdlr.so -c $< -o $@
############ SLOC ############
# rule for calculating source lines of code 
sloc:
	@grep -i -c -E '\(|\)|{|}|#|;|:|struct|class|union' $(SRCDIR)/* include/*
	@cat $(SRCDIR)/* include/* | grep -i -c -E '\(|\)|{|}|#|<|;|:|struct|class|union'

############ Format source code ############
# rule for formatting source files
format:
	@$(FORMAT) $(SRCDIR)/*.cc; rm -f $(SRCDIR)/*.orig
	@$(FORMAT) include/*.h; rm -f include/*.orig
	@$(FORMAT) include/*.tcc 2> /dev/null; rm -f include/*.orig

############ Dependencies ############
# rule for building dependency lists, and writing them to a file
# named ".depend".
depend:
#	$(RM) .depend
	@$(MAKEDEP) $(INCLFLAGS) $(SRCS) | sed 's/\(.*\)\.o[ :]*/$(OBJDIR)\/\1.o : /g' > .depend

# now add a line to include the dependency list.
# When this Makefile is used for the first time there will be no
# .depend file and make gives an error. Use "touch .depend" in 
# the directory where Makefile exists and then run "make depend" 
# to overcome this problem.

include .depend
