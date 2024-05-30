.PHONY: all
all: sub

sub: sub.o sub_function.o
	gcc sub.o sub_function.o -osub

sub_function_test:  sub_function.o sub_function_test.o
	gcc sub_function.o sub_function_test.o -osub_function_test

sub.o: sub.c sub_function.h
	gcc -Wall -Werror -c sub.c -osub.o

sub_function_test.o: sub_function_test.c sub_function.h
	gcc -Wall -Werror -c sub_function_test.c -osub_function_test.o


sub_function.o: sub_function.c sub_function.h
	gcc -Wall -Werror -c sub_function.c -osub_function.o

function_test_coverage: sub_function.c sub_function_test.c sub_function.h
	gcc --coverage -g sub_function.c sub_function_test.c -o function_test_coverage

doxygen: Doxyfile
	doxygen
	make -C latex
	cd latex; \
	mv refman.pdf ..
	mv refman.pdf sub.pdf

.PHONY: test
test: sub_function_test
	./sub_function_test

.PHONY: coverage
coverage: function_test_coverage
	./function_test_coverage
#	gcov ./sub_function_test.c
#	gcov ./sub_function.c
#	gcov ./sub.c
	gcovr --html-details ./sub_function_test_coverage
	firefox *.html

.PHONY: clean
clean:
	rm sub sub.o sub_function.o sub_function_test.o sub_function_test function_test_coverage function_test_coverage-sub_function.gcda function_test_coverage-sub_function.gcno function_test_coverage-sub_function_test.gcda function_test_coverage-sub_function_test.gcno sub_function_test_coverage sub_function_test_coverage.sub_function_test.c.18fb33d76b8acdda2e66bc6c753a843a.html sub_function_test_coverage.sub_function.c.d03ad4fcef1669a503def6ae4d80e901.html sub_function_test_coverage.css sub_function_test_coverage.functions.html latex html sub.pdf -f
