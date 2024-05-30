/**
 * @file
 */

#include "cmdargs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmdargs_parse(struct cmdargs *cmdargs, int argc, char *argv[]){
	char *end;
	/* Initialize default values */
	*cmdargs = (struct cmdargs){0};

	/* Represents the current positional index */
	int positional_index = 0;

	/* We go though each argument in argv exept the first one (which normally
	 * is the program's relative path) and and try to make something out of it.
	 */
        for (int i = 1; i < argc; i++){
                if (strcmp(argv[i],"--verbose") == 0){
                        cmdargs->verbose = 1;
                }
		else if(strcmp(argv[i], "--lcm") == 0){
			cmdargs->lcm = 1;
		}
		else if(strcmp(argv[i], "--iteration-map") == 0){
			cmdargs->iteration_map = argv[i+1];
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
                                        cmdargs->a = strtol(argv[i], &end, 10);
                                        break;

                                case 1:
                                        cmdargs->b = strtol(argv[i], &end, 10);
                                        break;
                        }
                        positional_index++;
                }
        }

        if (positional_index < 2)
        {
                /* Too few mandatory positional arguments */
                fprintf(stderr,"Not enough arguments given!\n");
                return 0;
        }
        if (positional_index > 2)
        {
                /* Too many positional arguments */
                fprintf(stderr,"Too many arguments given!\n");
                return 0;
        }
        return 1;
}
