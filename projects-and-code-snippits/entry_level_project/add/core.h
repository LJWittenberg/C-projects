/**
 * @file
 */
#ifndef _CORE_H
#define _CORE_H

/**
 * This is a simple function to add two integer
 * values. It main purpose is to demonstrate
 * the testing.
 *
 * @param x first summand
 * @param y second summand
 * @return the sum of x and y
 */
int add(int x, int y);

int argparse_int(const char *str, int *value);

#endif
