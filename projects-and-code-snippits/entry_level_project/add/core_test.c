/**
 * @file
 *
 * Test for functions in core.c
 */
#include <assert.h>

/* Include the interface of the module under testing */
#include "core.h"

/******************************************************/

static void test__add_calculates_sum(void)
{
	int intt;
	const char t1[] = "2";
	const char t2[] = "-2";
	const char t3[] = "a";
	const char t4[] = "0x0A";
	const char t5[] = "0b1010";
	assert(6 == add(3,3));
	assert(-2 == add(-1,-1));
	assert(1 == argparse_int(t1, &intt));
	assert(2 == intt);
	assert(1 == argparse_int(t2, &intt));
	assert(-2 == intt);
	assert(0 == argparse_int(t3, &intt));
	assert(1 == argparse_int(t4, &intt));
	assert(10 == intt);
	assert(1 == argparse_int(t5, &intt));
	assert(10 == intt);
}

/**
 * Main entry for the test.
 */
int main(int argc, char **argv)
{
	test__add_calculates_sum();
	return 0;
}
