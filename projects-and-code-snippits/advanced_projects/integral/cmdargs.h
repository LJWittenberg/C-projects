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
        const char *f;
        int steps;
        int measure_time;
        int monte_carlo;
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
