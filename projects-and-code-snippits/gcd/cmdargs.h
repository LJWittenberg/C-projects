/**
 * @file
 */

#ifndef _CMDARGS_H_
#define _CMDARGS_H_

/** Holds all the possible command line arguments */
struct cmdargs
{
	int a; /**< The frist divisor */
	int b; /**< The second divisor */
	int verbose; /**< int to represent if the compiler flag --verbose is given  */
	int lcm;
	int measure_time; /**< int to represent if the compiler flag -- measure-time is given */
	const char *iteration_map; /** variable to check if the compiler flag interation-map is given. */
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

#endif
