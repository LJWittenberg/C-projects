/**
 * @file
 */

#ifndef _CMDARGS_H_
#define _CMDARGS_H_

/** Holds all the possible command line arguments */
struct cmdargs
{
	int **a; // array with two dimensions to store the coordinates of initialized live cells.
		 // The first dimension represents the y-axis and the second dimension represents the x-axis
	int max_rows;
};

/**
 * Parse the given command line arguments into the cmdargs struct.
 *
 * @param cmdargs
 * @param argc the size of argv as supplied in main(). 
 * @param argv the the array of arguments as supplied in main().
 * @return 1 on success, 0 on failure.
 */
int cmdargs_parse(struct cmdargs *cmdargs, int argc, char *argv[], int r, int c);
//
int argparse_int(char *str);
//
void delete_buffer(struct cmdargs game);
#endif
