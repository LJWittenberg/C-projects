#include "printsincos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printsincos(int teiler){
	double gteiler = 360.0 / teiler;
	for(double i = 0; i <=360; i+= gteiler){
		printf("%.3lf\t %.3lf\t%.3lf\n", i, sin(i*(M_PI/180)), cos(i*(M_PI/180)));
	}

}
