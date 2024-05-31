#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"integral_func.h"
#include <stdint.h>

/*
 * 1/3 Simpson-rule for numerical integration
 */
double integral_sum(double (*f)(double x, void *userdata), void *userdata, double a, double b, uint64_t steps){
	double result, h;
	h = (b-a)/steps;
	result = f(a,userdata) + f(b,userdata);
	for(int i = 1; i <= steps-1;i++){
		double pos = a + i*h;
		if(i%2==0){
			result += 2 * f(pos,userdata);
		}
		else {
			result += 4 * f(pos,userdata);
		}
	}
	result *= h/3;
	return result;
}

double integral_mc(double (*f)(double x, void *userdata), void *userdata, double a, double b, uint64_t steps){
	double result, rndomnum;
	double val = 0.0;

	for(int i = 0; i < steps-1; i++){
		rndomnum = a+((double)rand()/RAND_MAX) * (b-a);
		val += f(rndomnum,userdata);

	}
	result = (b-a)*val/steps;
	return result;

}
