/**
 * @file
 */
#include <stdint.h>
#ifndef _INTEGRAL_FUNC_H
#define _INTEGRAL_FUNC_H

double integral_sum(double (*f)(double x, void *userdata), void *userdata, double a, double b, uint64_t steps);

double integral_mc(double (*f)(double x, void *userdata), void *userdata, double a, double b, uint64_t steps);

#endif
