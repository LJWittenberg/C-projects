#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	char *end;
	double rds =  strtod(argv[1], &end);
	if ( *end != 0){
		fprintf(stderr, "Argument %s ist keine natürliche Zahl und kann daher nicht in eine Fließkommazahl gecastet werden", argv[1]);
	}
	printf("\n  Umfang des Kreises: %lf", 2*rds*M_PI);
	printf("\n Bei einem Radius von %lf hat der dazugehörige Kreis einen Flächeninhalt von: %lf Längeneinheiten.\n", rds, M_PI*(rds*rds));
return 0;
}

