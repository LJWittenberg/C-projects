/**
 * @file
 *
 * Test for functions in gcd_functions.c
 */
#include<stdio.h>
#include <assert.h>
#include <math.h>
#include <stdint.h>
/* Include the interface of the module under testing */
#include "integral_func.h"
#include"te_binding.h"
/******************************************************/
double f(double x, void *userdata){
        double f = te_context_eval(userdata,x);
        return f;
}

static void test__integrate_calculates_values(void)
{
	double (*f_ptr)(double,void*) = &f;
	double x;
	double a = 2.0;
	double b = 4.0;
	uint64_t stp = 10000;
	struct te_context fvx;
	const char *func = "x";
	fvx.vars = (te_variable){"x",&x};
	int terr = te_context_init(&fvx,func);
	assert(terr == 0);
	double ft = (*f_ptr)(a,&fvx);
	double f = integral_sum((*f_ptr),&fvx,a,b,stp);
	printf("%f %f\n", ft, f);
	//assert(fabs(f + 8.0) < 1e-5);
	te_context_deinit(&fvx);
	printf("funktion funktioniert!!!!!\n");
}
/**
 * Main entry for the test.
 */
int main(int argc, char **argv)
{
        test__integrate_calculates_values();
        return 0;
}
