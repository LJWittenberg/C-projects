/**
 * @file add.c
 *
 * This is the main driver of the program, i.e.,
 * the program, which is then used by the user.
 */
#include <stdio.h>
#include <stdlib.h>

#include "core.h"

/**
 * The progam's main entry point.
 *
 * @param argc number of arguments given by the user
 * @param argv the argument vector
 */
int main(int argc, char **argv)
{
	int x[10],y[10];
	x[0]=0;
	y[0]=0;

	if (argc < 3)
	{
		fprintf(stderr,"Not enough arguments given!\n");
		return EXIT_FAILURE;
	}

	/* Normally, we would check for wrong input formats (i.e., no numbers) */
	argparse_int(argv[1], x);
	argparse_int(argv[2], y);
		printf("%d\n",add(x[0],y[0]));

	return EXIT_SUCCESS;
}
