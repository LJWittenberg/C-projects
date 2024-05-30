/*
 * @file sub.c
 *
 * This project subtracts one natural number from a second natrual number.
 * The user decides what value these numbers have.
 * The program can accept decimal, Hexadecimal and binary numbers.
 * sub.c is the main driver of the program and contains the main function which can be used to operate the program.
 */
#include<stdio.h>
#include<stdlib.h>
#include"sub_function.h"

/*
 * @param argc = integer of arguments given by the user.
 * @param argv[] argument for the numbers.
 */
int main(int argc, char **argv){
	int x[10],y[10];
	x[0]=0;
	y[0]=0;
	if(argc < 3){
		fprintf(stderr, "Not enough arguments given!\n");
			return 1;
	}
	else if(argc > 3){
		fprintf(stderr, "Too many arguments given!\n");
			return 1;
	}
	argparse_int(argv[1], x);
	argparse_int(argv[2], y);
	printf("%d\n", sub(x[0],y[0]));
	return 0;
}
