/**
 * @file
 */
#ifndef _GCD_FUNCTION_H
#define _GCD_FUNCTION_H

/**
 * Recursive implementation to find the gcd (greatest common divisor) of two integers using the euclidean algorithm.
 * @param a first integer
 * @param b second integer
 * return the greatest common divisor of a and b
 */
int gcd(int a, int b);

int gcdcount(int a, int b);

int verbose(int a, int b);

/*
 * function to print the smallest common multiple of two integers using the euclidean algorithm.
 * @param a frist integer
 * @param b second integer
 * return the smallest common multiple of a and b
 * this function works only with decimal numbers
 */
int scm(int a, int b);

/*
 * function to convert a char array int a integer.
 * @param *str to be converted string
 * @param value int variable to store the converted integer.
 */
int argparse_int(const char *str, int *value);

#endif

