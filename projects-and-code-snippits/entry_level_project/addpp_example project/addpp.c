/**
 * @file
 *
 * This is the main driver of the program, i.e.,
 * the program, which is then used by the user.
 */
#include <stdio.h>
#include <stdlib.h>

#include "cmdargs.h"
#include "core.h"

/**
 * The length of the verbose buffer.
 *
 * Often, it is better not to use define like here but const variables.
 * The define is used for demonstration purposes.
 */
#define VERBOSE_LEN 100

/**
 * The progam's main entry point.
 *
 * @param argc number of arguments given by the user
 * @param argv the argument vector
 */
int main(int argc, char **argv)
{
	struct cmdargs cmdargs;

	int sum;
	char verbose_buf[VERBOSE_LEN];
	char *verbose;

	if (!cmdargs_parse(&cmdargs, argc, argv))
	{
		return EXIT_FAILURE;
	}

	/* If verbose is requested, let verbose point to the buffer */
	if (cmdargs.verbose) verbose = verbose_buf;
	else verbose = NULL;

	sum = add(cmdargs.x,cmdargs.y, verbose, sizeof(verbose_buf));
	if (verbose)
	{
		printf("%s\n", verbose);
	} else
	{
		printf("%d\n", sum);
	}

	return EXIT_SUCCESS;
}
