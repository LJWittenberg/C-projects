/**
 * implements the core of the algorithm
 *
 * @file sub_function.c
 */

#include<stdio.h>
#include"sub_function.h"
#include<ctype.h>
#include<stdlib.h>
/**
 * returns the result of the subtraction between the the int numbers x and y.
 */
int sub(int x, int y){
	return x-y;
}
/**
 *defines the function argparse_int() from core.h
 * This function converts decimal numbers, binary numbers and hexadecimal numbers into integers.
 * hexadecimal numbers and binary number have to be defined with the propper prefix.
 * binary: 0B0001101 for example
 * hexadecimal: 0xF7 for example
 */
int argparse_int(const char *str, int *value){
        char *end;
        char binary[] = {};
        char hexch = 'x';
        char b1 = '0';
        char b2 = 'b';
        /* looking the prefix */
        /* if the str starts with a letter chancel*/
        if(isalpha(str[0])){
                return 0;
	}
	/*binary case*/
	if(str[0] == b1 && str[1] == b2){
		for(int i=0; str[i]!='\0';i++){
			binary[i] = (char)str[i+2];
		}
		long int gzw = strtol(binary, &end, 2);
		value[0] = (int)gzw;
		return 1;
	}
	/* hexadecimal case*/
	else if(str[1] == hexch){
		long int gzw = strtol(str, &end, 16);
		value[0] = (int)gzw;
		return 1;
        }
	/*decimal case*/
	else{
	long int gzw = strtol(str, &end, 10);
	value[0] = (int)gzw;
	return 1;
	}
}
