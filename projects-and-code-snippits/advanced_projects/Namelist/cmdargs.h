/**
 * @file
 */

#ifndef _CMDARGS_H_
#define _CMDARGS_H_

/** Holds all the possible command line arguments */
struct cmdargs
{
	/*
	 * @param sort_by_gender variable to check if the user wants to sort the List by gender.
	*/
        int sorts_by_gender; // --gender_sort executes function five.
	int sorts_by_alpha; // --alpha_sort executes function four
	int topX; // --top executes function three. A integer value has to be added after this command and seperated with a whitespace.
	int ptruntil;
};

/**
 * Parse the given command line arguments into the cmdargs struct.
 *
 * @param cmdargs
 * @param argc the size of argv as supplied in main(). 
 * @param argv the the array of arguments as supplied in main().
 * @return 1 on success, 0 on failure.
 */
int cmdargs_parse(struct cmdargs *cmdargs, int argc, char *argv[]);

int argparse_int(char *str);

#endif
