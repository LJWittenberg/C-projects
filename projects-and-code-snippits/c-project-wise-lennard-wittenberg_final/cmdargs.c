/**
 * @file
 */

#include "cmdargs.h"
#include "gol_board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// exchanging everything with a way to loop over the input and save the first int in the first array and the second int in the second array
int cmdargs_parse(struct cmdargs *cmdargs, int argc, char *argv[], int r, int c){
	// creating two two dimensional array pointers for the board
        int **matrix1 = (int **)malloc(r*sizeof(int *));
        for(int i = 0; i < r;i++){
                matrix1[i] = (int *) malloc(c*sizeof(int));
        }
	cmdargs->a = matrix1;
	cmdargs->max_rows = r;
	int elements = 1;
	while(elements < argc){
		int dimx = argparse_int(argv[elements]);
		int dimy = argparse_int(argv[elements+1]);
		cmdargs->a[dimx][dimy] = 1;
		elements += 2;
	}
	return 0;
}
//
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
//
void delete_buffer(struct cmdargs game){
        for(int i = 0; i < game.max_rows; i++){
                free(game.a[i]);
        }
        free(game.a);
}
