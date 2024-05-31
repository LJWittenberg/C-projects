# A makefile that can be used more conveniently to create larger projects in CE22 Grundlagen der Programmierung

# This is the name of the source file that contains the main() function
MAINSRC = addpp.c

# This is a list of names of the source files that each represent a driver of a test suite. Each of them contains
# an individual main() function that drives the test for the corresponding unit.
TESTSRCS = core_test.c cmdargs_test.c

# This is a list of all the other source files
OTHERSRCS = cmdargs.c core.c

# Specifiy optimization options like -O3
OPTIMIZE =

# Specify additional compile flags
CFLAGS =

# Specify additional linker flags
LDFLAGS =

# Specify additional linker libs if needed (e.g., -lm)
LDLIBS =

####################################################################
# In theory, you don't need to change that much in the following
# section and after the next one, except for fixing bugs or adding
# new features

TARGETRELEASEDIR = build/release
TESTCOVERDIR     = build/coverage
TESTASANDIR      = build/asan

OTHEROBJS = $(OTHERSRCS:.c=.o)

TARGETRELEASEOBJS = $(addprefix $(TARGETRELEASEDIR)/,$(MAINSRC:.c=.o) $(OTHEROBJS))
TARGETRELEASEDEPS = $(TARGETRELEASEOBJS:.o=.d)

TESTCOVEROBJS      = $(addprefix $(TESTCOVERDIR)/,$(TESTSRCS:.c=.o))
TESTCOVEROTHEROBJS = $(addprefix $(TESTCOVERDIR)/,$(OTHEROBJS))
TESTCOVERDEPS      = $(TESTCOVEROBJS:.o=.d) $(TESTCOVEROTHEROBJS:.o=.d)

TESTASANOBJS      = $(addprefix $(TESTASANDIR)/,$(TESTSRCS:.c=.o))
TESTASANOTHEROBJS = $(addprefix $(TESTASANDIR)/,$(OTHEROBJS))
TESTASANDEPS      = $(TESTASANOBJS:.o=.d) $(TESTASANOTHEROBJS:.o=.d)

TARGET            = $(addprefix $(TARGETRELEASEDIR)/,$(MAINSRC:.c=))
TESTCOVERTARGETS  = $(addprefix $(TESTCOVERDIR)/,$(TESTSRCS:.c=))
TESTASANTARGETS   = $(addprefix $(TESTASANDIR)/,$(TESTSRCS:.c=))

###########################################################################
# Adapt this section as needed

.PHONY: all
all: $(TARGET) $(TESTCOVERTARGETS) $(TESTASANTARGETS)

.PHONY: clean
clean:
	rm -Rf build html latex

.PHONY: doxygen
doxygen: Doxyfile
	doxygen
	make -C latex
	cd latex; \
	mv refman.pdf ..
	mv refman.pdf addpp.pdf

.PHONY: coverage
coverage: $(TESTCOVERTARGETS)
	$(foreach T, $(TESTCOVERTARGETS), $(T) &&) true
	gcovr 

.PHONY: test
test: $(TESTASANTARGETS)
# This is a tricky one, we have to call each test target individually
# We construct this by using a foreach statement and the shell command
# 'true' that just exists with a return value of 0 meaning success.
	$(foreach T, $(TESTASANTARGETS), $(T) && ) true

###########################################################################
# This section most likely doesn't need to change

COMMONFLAGS=-Wall -Werror -MMD -MP $(CFLAGS) $(OPTIMIZE)

$(TARGETRELEASEDIR):
	mkdir -p $@

$(TARGETRELEASEOBJS): | $(TARGETRELEASEDIR)

$(TARGETRELEASEDIR)/%.o: %.c
	gcc -c $(COMMONFLAGS) $< -o $@

$(TARGET): $(TARGETRELEASEOBJS)
	gcc $^ $(LDFLAGS) $(LDLIBS) -o $@

-include $(TARGETRELEASEDEPS)

###########################################################################

$(TESTCOVERDIR):
	mkdir -p $@

$(TESTCOVEROBJS) $(TESTCOVEROTHEROBJS): | $(TESTCOVERDIR)

$(TESTCOVERDIR)/%.o: %.c
	gcc -c --coverage $(COMMONFLAGS) $< -o $@

$(TESTCOVERDIR)/%: $(TESTCOVERDIR)/%.o $(TESTCOVEROTHEROBJS)
	gcc $^ $(LDFLAGS) --coverage $(LDLIBS) -o $@

-include $(TESTCOVERDEPS)

###########################################################################

$(TESTASANDIR):
	mkdir -p $@

$(TESTASANOBJS) $(TESTASANOTHEROBJS): | $(TESTASANDIR)

$(TESTASANDIR)/%.o: %.c
	gcc -c -g -fsanitize=address $(COMMONFLAGS) $< -o $@

$(TESTASANDIR)/%: $(TESTASANDIR)/%.o $(TESTASANOTHEROBJS)
	gcc $^ $(LDFLAGS) -g -fsanitize=address $(LDLIBS) -o $@

-include $(TESTASANDEPS)

###########################################################################
