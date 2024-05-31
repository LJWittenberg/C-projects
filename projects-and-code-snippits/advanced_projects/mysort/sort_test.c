/*
 * @file
 *
 * Test for functions in sort.c
 */
#include <assert.h>

/* Include the interface of the module under testing */
#include "sort.h"

/******************************************************/
static void test__sort_calculates_order(void)
{
	const char *argarrtst[] = {"5", "3", "12", "1", "6", "9"};
	int argarr[6];
	for(int i= 0; i<6;i++){
		argparse_intArray(argarrtst[i],i,argarr);
	}
        int selctest [] = {5, 3, 12, 1, 6, 9};
	assert(1 == sort(selctest, 6));
	assert(1 == selctest[0]);
	assert(0 == argparse_intArray(argarrtst[0],0,argarr));
	assert(5 == argarr[0]);
	assert(3 == selctest[1]);
	assert(5 == selctest[2]);
	assert(6 == selctest[3]);
	assert(9 == selctest[4]);
	assert(12 == selctest[5]);
	assert(0 == reverse(selctest,5));
	assert(0 == prntaln(selctest,6));
}

/**
 * Main entry for the test.
 */
int main(int argc, char **argv)
{
        test__sort_calculates_order();
        return 0;
}
