#include "printsincos.h"
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[]){
	if( argc > 2 || argc == 1){
		fprintf(stderr, "Dem Programm wurden zu viele Argumente übergeben oder es wurde keine übergeben. Es wird der Standardparameter 18 verwendet!\n");
		printsincos(18);
		return 0;
	}
	char *end;
	int teiler = strtol(argv[1], &end, 10);
	printsincos(teiler);


return 0;
}
