/**
 * @file
 */

#include "cmdargs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

int cmdargs_parse(struct cmdargs *cmdargs, int argc, char *argv[]){
        /* Initialize default values */
        *cmdargs = (struct cmdargs){0};


        /* We go though each argument in argv exept the first one (which normally
         * is the program's relative path) and and try to make something out of it.
	*/
        for (int i = 1; i < argc; i++){
		 if(strcmp(argv[i], "--gender_sort") == 0){
			cmdargs->sorts_by_gender = 1;
                }
		if(strcmp(argv[i], "--alpha_sort") == 0){
                        cmdargs->sorts_by_alpha = 1;
                }
		if(strcmp(argv[i], "--top") == 0){
			cmdargs->topX = 1;
                        cmdargs->ptruntil = argparse_int(argv[i+1]);
                }
        }
        return 1;
}

int argparse_int(char *str){
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
                        binary[i] = str[i+2];
                }
                int gzw = strtol(binary, &end, 2);
                return gzw;
        }
        /* hexadecimal */
        else if(str[1] == hexch){
                long int gzw = strtol(str, &end, 16);
                return gzw;
        }
        /*decimal*/
        else{
        long int gzw = strtol(str, &end, 10);
        return gzw;
        }
}
