/**
 * @file
 */

#include "cmdargs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

int cmdargs_parse(struct cmdargs *cmdargs, int argc, char *argv[]){
        char *end;
        /* Initialize default values */
        *cmdargs = (struct cmdargs){0};
	/* Initialize steps with default value of 100000*/
	cmdargs->steps = 100000;

        /* Represents the current positional index */
        int positional_index = 0;

        /* We go though each argument in argv exept the first one (which normally
         * is the program's relative path) and and try to make something out of it.
         */
        for (int i = 1; i < argc; i++){
                if (strcmp(argv[i],"--steps") == 0){
                        cmdargs->steps = strtol(argv[i+1], &end, 10);
                }
                else if(strcmp(argv[i], "--monte-carlo") == 0){
                        cmdargs->monte_carlo = 1;
                }
                else if(strcmp(argv[i], "--measure-time") == 0){
                        cmdargs->measure_time = 1;
                }
                else if (!strncmp(argv[i], "--", 2)){
                        fprintf(stderr, "Unknown flag %s\n", argv[i]);
                        return 0;
                }
		else {
                        switch (positional_index){
                                case 0:
                                        cmdargs->a = argparse_int(argv[i]);
                                        break;

                                case 1:
                                        cmdargs->b = argparse_int(argv[i]);
                                        break;

				case 2:
					cmdargs->f =  &argv[i][0];
					break;
                        }
                        positional_index++;
                }
        }
        if (positional_index < 3)
        {
                /* Too few mandatory positional arguments */
                fprintf(stderr,"Not enough arguments given!\n");
                return 0;
        }
        if (positional_index > 3)
        {
                /* Too many positional arguments */
                fprintf(stderr,"Too many arguments given!\n");
                return 0;
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
