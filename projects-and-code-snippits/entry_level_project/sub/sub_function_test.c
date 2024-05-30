/**
 * @file
 *
 * Test for functions in sub_function.c
 */
#include <assert.h>

/* Include the interface of the module under testing */
#include "sub_function.h"

/******************************************************/

static void test__sub_calculates_sum(void)
{
	int testint;
	const char strhex[] = "0x0A";
	const char strbin[] = "0b1010";
	const char strdec[] = "10";
	const char stralp[] = "a10"; 
        assert(0 == sub(3,3));
        assert(2 == sub(1,-1));
	assert(1 == argparse_int(strhex, &testint));
	assert(-9 == sub(1,testint));
	assert(1 == argparse_int(strbin, &testint));
	assert(-9 == sub(1,testint));
	assert(1 == argparse_int(strdec, &testint));
	assert(0 == sub(10,testint));
	assert(0 == argparse_int(stralp, &testint));
}

/**
 * Main entry for the test.
 */
int main(int argc, char **argv)
{
        test__sub_calculates_sum();
        return 0;
}
