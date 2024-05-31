/**
 * @file
 *
 * Test for functions in gcd_functions.c
 */
#include <assert.h>
#include <math.h>
#include <stdint.h>
/* Include the interface of the module under testing */
#include"te_binding.h"
#include"tinyexpr.h"
#include<stdio.h>
/******************************************************/

static void test__te_binding_calculates_expressions(void)
{
	double x = 0.5;
	struct te_context tststrc;
	const char *testfunc = "2*sqrt(1-x^2)";
	tststrc.vars = (te_variable){"x",&x};
	int errtesting = te_context_init(&tststrc,testfunc);
	printf("%i\n", errtesting);
	assert(errtesting == 0);
	double eval = te_context_eval(&tststrc,x);
	printf("%f\n", eval);
	assert(fabs(eval - 1.73205) < 1e-5);
	te_context_deinit(&tststrc);

}

int main(int argc, char **argv)
{
        test__te_binding_calculates_expressions();
        return 0;
}
