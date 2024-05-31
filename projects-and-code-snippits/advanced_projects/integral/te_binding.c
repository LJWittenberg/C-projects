#include"te_binding.h"
#include"tinyexpr.h"
#include<stdio.h>
#include<stdlib.h>
int te_context_init(struct te_context *bind, const char *function){
	int err = 0;
	te_variable varr = {.name="x", .address=&bind->x};
	bind->vars = varr;
	bind->expr = te_compile(function,&bind->vars,1,&err);
	return err;
}

int te_context_deinit(struct te_context *bind){
	te_free(bind->expr);
	return 0;

}

double te_context_eval(struct te_context *bind, double x){
	bind->x = x;
	double fval = te_eval(bind->expr);
	return fval;
}
