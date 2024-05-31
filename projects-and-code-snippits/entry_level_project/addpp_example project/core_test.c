/**
 * @file
 *
 * Test for functions in core.c
 */

/* Include the interface of the module under testing */
#include "core.h"

#include <assert.h>
#include <string.h>

/******************************************************/

static void test__add_calculates_sum(void)
{
	assert(5 == add(2,3, NULL, 0)); // GCOV_EXCL_BR_LINE
	assert(-2 == add(-1,-1, NULL, 0)); // GCOV_EXCL_BR_LINE

	/* The verbose_len parameter should be ignored, if verbose is NULL, test for this */
	assert(-3 == add(-1,-2, NULL, 1111111)); // GCOV_EXCL_BR_LINE
}

static void test__add_calculates_sum_and_verbose_works(void)
{
	char buf[20];

	assert(1 == add(0,1, buf, sizeof(buf))); // GCOV_EXCL_BR_LINE
	assert(0 == strcmp("0 + 1 = 1", buf)); // GCOV_EXCL_BR_LINE

	/* Also test for buffer overflows by setting the len to be too small */
	assert(3 == add(1, 2, buf, 1)); // GCOV_EXCL_BR_LINE
	assert(0 == strcmp("", buf)); // GCOV_EXCL_BR_LINE
}

/**
 * Main entry for the test.
 */
int main(int argc, char **argv)
{
	test__add_calculates_sum();
	test__add_calculates_sum_and_verbose_works();
	return 0;
}
