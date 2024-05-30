#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
int main(int argc, char *argv[]){
	char *end;
	if(argc > 2){
		fprintf(stderr, "Superfluous argument was given! Only one is allowed.\n");
		return 1;
	}
        if(argc <  2){
                fprintf(stderr, "Required natural number is missing!\n");
                return 1;
        }
        /** Es wird nur eine Zahl bearbeitet.*/
	for(int i = 0; argv[1][i]!='\0';i++){
		if(!isdigit(argv[1][i])){
			fprintf(stderr, "Given agrument '%s' is no vaild natural number\n", argv[1]);
			return 1;
		}
	}
	long int  nnumber = strtol(argv[1], &end, 10);
	if(nnumber < 0){
		fprintf(stderr, "Given agrument '%s' is no vaild natural number\n", argv[1]);
		return 1;
	}

	int getsum(int crosssum){
		int sum = 0;
		while(crosssum > 0){
			sum += crosssum % 10;
			crosssum = crosssum/10;
		}
		return sum;
	}
	printf("Die Quersumme von %li = %i.\n", nnumber, getsum(nnumber));
	return 0;
}
