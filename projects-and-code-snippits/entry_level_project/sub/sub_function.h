/**
 * @file sub_function.h
 */
#ifndef _SUB_FUNCTION_H
#define _SUB_FUNCTION_H

/**
 * This Header file contains the sub function and the argparse_int function.
 * sub function subtracts two integer numbers from oneanother
 * the main purpose is to provide inditional exercise for Unit-testing and documentation.
 * The arguments x and y are the numbers to be substracted.
 * The function argpase_int converts a char str into a integer. futher information on the function (Inizialisierung).
 */
int sub(int x, int y);

int argparse_int(const char *str, int *value);

#endif
