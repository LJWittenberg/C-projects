.PHONY: all
all: mysort

mysort: mysort.o sort.o
	gcc mysort.o sort.o -omysort

sort_test: sort_test.o sort.o
	gcc sort_test.o sort.o -o sort_test

mysort.o: mysort.c sort.h
	gcc -Wall -Werror -c mysort.c -omysort.o

sort_test.o: sort_test.c sort.h
	gcc -Wall -Werror -c sort_test.c -osort_test.o

sort.o: sort.c sort.h
	gcc -Wall -Werror -c sort.c -osort.o

sort_test_coverage: sort.c sort_test.c sort.h
	gcc --coverage -g sort.c sort_test.c -o sort_test_coverage

doxygen: Doxyfile
	doxygen
	make -C latex
	cd latex; \
	mv refman.pdf ..
	mv refman.pdf mysort.pdf

.PHONY: test
test: sort_test
	./sort_test

.PHONY: coverage
coverage: sort_test_coverage
	./sort_test_coverage
#	gcov ./sort_test.c
#	gcov ./sort.c
#	gcov ./mysort.c
	gcovr --html-details ./sort_test_coverage
	firefox *.html

.PHONY: clean
clean:
	rm sort.o mysort.o mysort sort_test.o sort_test_coverage sort_test_coverage-sort.gcda sort_test_coverage-sort.gcno sort_test_coverage-sort_test.gcda sort_test_coverage-sort_test.gcno sort_test_coverage.css sort_test_coverage.functions.html sort_test_coverage.sort.c.c9257d9e777559f9c44ac6a12c636e32.html sort_test_coverage.sort_test.c.f9bfc080bbf7c9059c06d56c46420ae0.html sort.c.save sort_test html latex mysort.pdf -f
