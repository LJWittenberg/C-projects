/**
 * @file
 */
#ifndef _CORE_H
#define _CORE_H

#include <stddef.h>

/**
 * This is a simple function to add two integer
 * values. It main purpose is to demonstrate
 * the testing.
 *
 * @param x first summand
 * @param y second summand
 * @param verbose defines the pointer to a buffer where verbose output
 *                is written to
 * @param verbose_len defines the length of the verbose buffer
 * @return the sum of x and y
 */
int add(int x, int y, char *verbose, size_t verbose_len);

#endif
