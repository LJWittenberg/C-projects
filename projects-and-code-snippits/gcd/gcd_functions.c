#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"gcd_functions.h"
#include<math.h>
#include<stdio.h>

/*
 * defines the function gcd from gcd_function.h
 */
int gcd(int a, int b){
	int temp;
	int count = 0;
	while(1){
		if(b!=0){
			temp = a;
			a = b;
			b = temp % a;
			count++;
		}
		else if(b == 0){
			printf("number of iterations: %i\n", count);
			return a;
		}

	}
}
int gcdcount(int a, int b){
	int temp;
	int count = 0;
        while(1){
		if(b!=0){
			temp = a;
			a = b;
			b = temp % a;
			count++;
		}
		else if(b == 0){
                        return count;
		}
	}
}


int verbose(int a, int b){
	int temp;
	while(1){
		if(b!=0){
			printf("%i divided by %i = %i + %i\n", a, b, a/b, a%b);
			temp = a;
			a = b;
			b = temp % a;
		}
		else if(b == 0){
			printf("rest = 0 --> the gcd is %i\n", a);
			return 1;
		}
	}
}

/*
 * defines the function scm from gcd_functions.h
 * the function converts the string into an integer
 * than the function checks which string is greater.
 * if the the strings are equal return one of them.
 * if one is greater then the other the function frist oders the strings by their size.
 * using an algorithm the function returns the smallst common multiple.
 */
int scm(int a, int b){
	int max;
	if(a > b){
		max = a;
	}
	else if(b > a){
		max = b;
	}
	else{
		return a;
	}
	while(1){
		if((max % a == 0) && (max % b == 0)){
			return max;
		}
		else{
			max++;
		}
	}

}


/**
 * defines the function argparse_int() from gcd_functions.h
 * This function converts decimal numbers, binary numbers and hexadecimal numbers into integers.
 * hexadecimal numbers and binary number have to be defined with the propper prefix.
 * binary: 0B0001101 for example
 * hexadecimal: 0xF7 for example
 */
int argparse_int(const char *str, int *value){
        char *end;
        char binary[strlen(str)-3];
        char hexch = 'x';
        char b1 = '0';
        char b2 = 'b';
        /* looking the prefix */
        /* if the str starts with a letter chancel*/
        if(isalpha(str[0])){
                return 0;
        }
        if(str[0] == b1 && str[1] == b2){
                for(int i=0; str[i]!='\0';i++){
                        binary[i] = (char)str[i+2];
                }
                int gzw = strtol(binary, &end, 2);
                value[0] = gzw;
                return 1;
        }
        /* hexadecimal */
        else if(str[1] == hexch){
                long int gzw = strtol(str, &end, 16);
                value[0] = gzw;
                return 1;
        }
        /*decimal*/
        else{
        long int gzw = strtol(str, &end, 10);
        value[0] = gzw;
        return 1;
        }
}
