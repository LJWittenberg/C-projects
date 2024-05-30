/**
 * @file
 *
 * Test for functions in gcd_functions.c
 */
#include <assert.h>

/* Include the interface of the module under testing */
#include "gcd_functions.h"

/******************************************************/

static void test__gcd_calculates_commons(void)
{
	int a = 45;
	int b = 35;
	int intt;
	const char t1[] = "2";
	const char t2[] = "-2";
	const char t3[] = "a";
	const char t4[] = "0x0A";
	const char t5[] = "0b1010";
	assert(5 == gcd(a,b));
	assert(315 == scm(a,b));
	assert(45 == scm(a,a));
	assert(45 == gcd(a,a));
	assert(315 == scm(b,a));
	assert(1 == argparse_int(t1, &intt));
	assert(2 == intt);
	assert(1 == argparse_int(t2, &intt));
	assert(-2 == intt);
	assert(0 == argparse_int(t3, &intt));
	assert(1 == argparse_int(t4, &intt));
	assert(10 == intt);
	assert(1 == argparse_int(t5, &intt));
	assert(10 == intt);
	assert(1 == verbose(a,b));
}

/**
 * Main entry for the test.
 */
int main(int argc, char **argv)
{
        test__gcd_calculates_commons();
        return 0;
}
