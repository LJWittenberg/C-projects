/**
 * @file
 */

#ifndef _CMDARGS_H_
#define _CMDARGS_H_

/** Holds all the possible command line arguments */
struct cmdargs
{
  int x; /**< The first summand */
  int y; /**< The second summand */
  int verbose; /**< An flag that if specified requests verbose output */
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