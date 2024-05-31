all: sincos
.PHONY: all

sincos.o: sincos.c printsincos.h
	gcc -Wall -Werror -c sincos.c -osincos.o

printsincos.o: printsincos.c printsincos.h
	gcc -Wall -Werror -c printsincos.c -oprintsincos.o

sincos: sincos.o printsincos.o printsincos.h
	gcc sincos.o printsincos.o -osincos -lm

.PHONY: clean
clean:
	rm  sincos.o printsincos.o sincos 
