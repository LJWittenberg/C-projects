.PHONY: all
all: add

add: add.o core.o
	gcc add.o core.o -oadd

core_test: core_test.o core.o
	gcc core_test.o core.o -o core_test

add.o: add.c core.h
	gcc -Wall -Werror -c add.c -oadd.o

core_test.o: core_test.c core.h
	gcc -Wall -Werror -c core_test.c -ocore_test.o

core.o: core.c core.h
	gcc -Wall -Werror -c core.c -ocore.o

core_test_coverage: core.c core_test.c core.h
	gcc --coverage -g core.c core_test.c -o core_test_coverage

.PHONY: test
test: core_test
	./core_test

doxygen: Doxyfile
	doxygen
	make -C latex
	cd latex; \
	mv refman.pdf ..
	mv refman.pdf add.pdf

.PHONY: coverage
coverage: core_test_coverage
	./core_test_coverage
#	gcov ./core_test.c
#	gcov ./core.c
#	gcov ./add.c
	gcovr --html-details ./core_test_coverage
	firefox *.html

.PHONY: clean
clean:
	rm add add.o core.o core_test core_test.o core_test_coverage-core.gcda core_test_coverage-core.gcno core_test_coverage-core_test.gcda core_test_coverage-core_test.gcno core_test_coverage core_test_coverage.css core_test_coverage.core.c.254c0f2e11cf9db1939e16d396e6f811.html core_test_coverage.functions.html core_test_coverage.core_test.c.e4d52600e3bca712a23f708812db5906.html latex html add.pdf -r
