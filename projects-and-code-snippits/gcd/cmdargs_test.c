/**
 * @file
 *
 * Test for functions in core.c
 */
#include <assert.h>

/* Include the interface of the module under testing */
#include "cmdargs.h"

/******************************************************/

static void test__cmdargs_parse_works_with_valid_params(void)
{
	struct cmdargs cmdargs = {0};

	assert(cmdargs_parse(&cmdargs, 3, (char *[3]){"dummy", "5", "7"}) == 1);
	assert(cmdargs.a == 5);
	assert(cmdargs.b == 7);
	assert(cmdargs.verbose == 0);

	cmdargs = (struct cmdargs){0};
	assert(cmdargs_parse(&cmdargs, 3, (char *[3]){"dummy", "-5", "7"}) == 1);
	assert(cmdargs.a == -5);
	assert(cmdargs.b == 7);
	assert(cmdargs.verbose == 0);

	assert(cmdargs_parse(&cmdargs, 4, (char *[4]){"dummy", "5", "7", "3"}) == 0);
}

/******************************************************/

static void test__cmdargs_parse_works_with_valid_params_and_verbose(void)
{
	struct cmdargs cmdargs = {0};

	assert(cmdargs_parse(&cmdargs, 4, (char *[4]){"dummy", "--verbose", "5", "7"}) == 1);
	assert(cmdargs.a == 5);
	assert(cmdargs.b == 7);
	assert(cmdargs.verbose == 1);

	cmdargs = (struct cmdargs){0};
	assert(cmdargs_parse(&cmdargs, 4, (char *[4]){"dummy", "-5", "7", "--verbose"}) == 1);
	assert(cmdargs.a == -5);
	assert(cmdargs.b == 7);
	assert(cmdargs.verbose == 1);

	cmdargs = (struct cmdargs){0};
	assert(cmdargs_parse(&cmdargs, 4, (char *[4]){"dummy", "-5", "7", "--lcm"}) == 1);
	assert(cmdargs.a == -5);
	assert(cmdargs.b == 7);
	assert(cmdargs.verbose == 1);
}

/******************************************************/
/**
 * Main entry for the test.
 */
int main(int argc, char **argv)
{
        test__cmdargs_parse_works_with_valid_params();
        test__cmdargs_parse_works_with_valid_params_and_verbose();
        return 0;
}
