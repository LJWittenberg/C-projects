/**
 * Implements the core of the algorithm.
 *
 * @file core.c
 */

#include "core.h"

#include <stdio.h>

int add(int x, int y, char *verbose, size_t verbose_len)
{
	int sum = x + y;
	if (verbose)
	{
		snprintf(verbose, verbose_len, "%d + %d = %d", x, y, sum);
	}
	return x + y;
}
