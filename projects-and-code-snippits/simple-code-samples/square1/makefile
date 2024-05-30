MAINSRC = square1.c

TESTSRCS =

OTHERSRCS =

#OPTIMIZE = -O2

#LDLIBS = -lm
#######################################################################
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

#######################################################################
.PHONY: all
all: $(TARGET) $(TESTCOVERTARGETS) $(TESTASANTARGETS)

.PHONY: doxygen
doxygen: Doxyfile
	doxygen
	make -C latex
	cd latex; \
	mv refman.pdf ..
	mv refman.pdf integral.pdf

.PHONY: test
test: $(TESTASANTARGETS)
	$(foreach T, $(TESTASANTARGETS), $(T) && ) true

.PHONY: coverage
coverage: $(TESTCOVERTARGETS)
	$(foreach T, $(TESTCOVERTARGETS), $(T) &&) true
	gcovr

.PHONY: clean
clean:
	rm build latex html -Rf
###########################################################################

COMMONFLAGS=-Wall -Werror -MMD -MP $(CFLAGS) $(OPTIMIZE)

$(TARGETRELEASEDIR):
	mkdir -p $@

$(TARGETRELEASEOBJS): | $(TARGETRELEASEDIR)

$(TARGETRELEASEDIR)/%.o: %.c
	gcc -c $(COMMONFLAGS) $< -o $@

$(TARGET): $(TARGETRELEASEOBJS)
	gcc $^  $(LDFLAGS) $(LDLIBS) -o $@

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

#############################################################################
