#include"cmdargs.h"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"integral_func.h"
#include"te_binding.h"
#include<time.h>
double f(double x, void *userdata){
        double f = te_context_eval((struct te_context*)userdata,x);
        return f;
}

void integrate(double (*f)(double x, void *userdata), void *userdata, double a, double b, uint64_t steps, int monte){
	if(monte == 1){
		double flaecheninhalt = integral_mc(f,userdata,a,b,steps);
                printf("%.9f\n", flaecheninhalt);
                te_context_deinit(userdata);
	}
	else{
        	double flaecheninhalt = integral_sum(f,userdata,a,b,steps);
        	printf("%.9f\n", flaecheninhalt);
        	te_context_deinit(userdata);

	}

}

int main(int argc, char **argv){

	struct cmdargs function_f;
	cmdargs_parse(&function_f, argc, argv);
	struct te_context fvx;
	te_context_init(&fvx,function_f.f);

	/*if(function_f.monte_carlo == 1){
		double flaecheninhalt = integral_mc(f, &fvx, function_f.a, function_f.b, function_f.steps);
        	printf("%.9f %s\n", flaecheninhalt, function_f.f);
        	te_context_deinit(&fvx);
		return 0;
	}
*/
	if(function_f.measure_time == 1){
		struct timespec start, finish;
		clock_gettime(CLOCK_MONOTONIC,&start);
		double flaecheninhalt = integral_sum(f, &fvx, function_f.a, function_f.b, function_f.steps);
		printf("%.9f %s\n", flaecheninhalt, function_f.f);
		te_context_deinit(&fvx);

		clock_gettime(CLOCK_MONOTONIC,&finish);
		int secs = finish.tv_sec - start.tv_sec;
		int nsecs = abs(finish.tv_nsec - start.tv_nsec);
		printf("%i.%i Sekunden\n", secs, nsecs);
		return 0;
	}

	integrate(f, &fvx, function_f.a, function_f.b, function_f.steps,function_f.monte_carlo);
/*
	double flaecheninhalt = integral_sum(f, &fvx, function_f.a, function_f.b, function_f.steps);
	printf("%.9f %s\n", flaecheninhalt, function_f.f);
	te_context_deinit(&fvx);
*/
return 0;
}
