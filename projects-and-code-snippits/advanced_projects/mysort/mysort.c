#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sort.h"

/*
 *@file mysort.c
 * program to sort an int array by length.
 * the standard sort is from smallest to biggest integer
 * the program support two flags:
 * --print-as-lines
 * --reverse --> largest to smallest
 * @param int arrsort is the array the given integer numbers are stored in.
 * The length is argc-1
 * the program is makeing use of the for loops to check for flags.
 * note only one flag can be used at any given time.
 */

int main(int argc, char **argv){
	int arrsort[argc-1];
	for(int i = 0; i <argc-1;i++){
		if(strcmp(argv[i],"--reverse")==0 || strcmp(argv[i],"--print-as-lines")==0){
			argparse_intArray(argv[i+2],i,arrsort);
		}
		argparse_intArray(argv[i+1],i,arrsort);
	}
	sort(arrsort,argc-1);
	for(int j = 0; j <argc-1;j++){
		if(strcmp(argv[j],"--reverse")==0){
			reverse(arrsort,argc-2);
			return 0;
		}
		else if(strcmp(argv[j],"--print-as-lines")==0){
			prntaln(arrsort,argc-1);
			return 0;
		}
	}
	for(int i = 0; i < argc-1;i++){
		printf("%i ", arrsort[i]);
	}
	printf("\n");

return 0;
}
