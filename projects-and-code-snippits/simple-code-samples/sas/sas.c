// Warning:
// Bad code do not refactor





#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*verwendete Formeln:
*sin = Gegenkathete/Hypotenuse
*tan = Gegenkathete/Ankathete
*cos = Ankathete/Hypotenuse
*arcsin ==> (arcussinus) sin⁻¹=(Gegenkathete/Hypotenuse)
* u = a+b+c
* h_c = a*sin(beta)
* A = g*h*1/2
* 40=<gamma=>90 Grad idealerweise 
*/
int main(int argc, char *argv[]){
	char *end;
	double val = M_PI/180;
        double a = strtod(argv[1], &end);
	double gamma = strtod(argv[2], &end);
	double b = strtod(argv[3], &end);
	double wertw = cos(gamma*val);
	double c = b/wertw;
	double beta = acos(a/c)/val;
	double u = a+b+c;
	double h_c = a*sin(beta*val);
	double d_A = (c*h_c)/2;
	printf(" %.1lf %.1lf %.1lf %.1lf %.1lf %.3lf \n", b, c, gamma, beta, u, d_A);
return 0;
}
