#include<stdio.h>
#include<stdlib.h>
#include"gcd_functions.h"
#include"cmdargs.h"
#include"write_pgm.h"
#include<string.h>
#include<time.h>
/*
 * @file gcd.c
 * Program to find the greatest common divisor of two integers using the euclidean algorithm.
 * This c-program contains the main function.
 * The two natrual numbers are given to this program by the user.
 * the main program then converts the arguments into integers, checks which of the two numbers is bigger or if they are equal.
 * the main program prints the greatest common divisor of the arguments.
 * the functions necessary for these operations can be found in other c-programs in the gcd directory.
 * the program can use the flags --lcm and --verbose.
 * the program only supports one flag at a time
 */
int main(int argc, char **argv){
	if(argc < 3){
		fprintf(stderr,"Not enough arguments given!\n");
		return EXIT_FAILURE;
        }
	struct cmdargs gcdargs;
	cmdargs_parse(&gcdargs, argc, argv);
	if(gcdargs.verbose == 1){
		verbose(gcdargs.a,gcdargs.b);
	return 0;
	}
	if(gcdargs.lcm == 1){
		printf("%i\n", scm(gcdargs.a, gcdargs.b));
	return 0;
	}
	if(gcdargs.iteration_map){
		int n = 0;
		int maxvalue = 0;//gcdcount(gcdargs.a,gcdargs.b);
		unsigned char *buf = malloc(gcdargs.a*gcdargs.b);
		for(int i = 1; i < gcdargs.a;i++){
			for(int j = 1; j < gcdargs.b;j++){
				// printf("%i\n", gcdcount(i,j)); // for me to control the process.
				buf[n] = gcdcount(i,j);
				if(buf[n] > maxvalue){
					maxvalue = buf[n];
				}
				n++;
			}
		}
		write_pgm(gcdargs.iteration_map,buf,gcdargs.a,gcdargs.b,maxvalue);
		free(buf);
	}
	if(gcdargs.measure_time == 1){
		struct timespec start, finish;
		clock_gettime(CLOCK_MONOTONIC,&start);
                int n = 0;
                unsigned char *buf = malloc(gcdargs.a*gcdargs.b);
                for(int i = 1; i < gcdargs.a;i++){
                        for(int j = 1; j < gcdargs.b;j++){
                                buf[n] = gcdcount(i,j);
                                n++;
			}
		}
		clock_gettime(CLOCK_MONOTONIC,&finish);
		int secs = finish.tv_sec - start.tv_sec;
		int nsecs = abs(finish.tv_nsec - start.tv_nsec);
		printf("%i.%i Sekunden\n", secs, nsecs);
	}
	printf("%i \n",gcd(gcdargs.a, gcdargs.b));
return 0;
}

