#ifndef _TE_BINDING_H_
#define _TE_BINDING_H_
#include"tinyexpr.h"
struct te_context{
	te_expr *expr;
	te_variable vars;
	double x;
};
int te_context_init(struct te_context *bind, const char *function);

int te_context_deinit(struct te_context *bind);

double te_context_eval(struct te_context *bind, double);
#endif
