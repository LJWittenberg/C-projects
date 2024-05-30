/*
 * @pythatri
 *
 * This program prints all natrual numbers for 1<=a<b<c<=m
 * m is given to the program by the user.
 * the numbers a,b and c are declared and initialized in the main function of this program.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main(int argc, char *argv[]){
	if(argc > 2){
		fprintf(stderr, "Superfluous argument was given! Only zero or one are allowed.\n");
		return 1;
	}
	if(!isdigit(argv[1][1])){
		fprintf(stderr, "Given argument %s is not a natrual number. \n", argv[1]);
		return 1;
	}
	if(argc == 1){
		int m = 100;
                int a,b,c;
                b=2;
                c=3;
                for(a=1; a<b;a++){
                        for(b=a+1; b<c;b++){
                                for(c=b+1; c<=m;c++){
                                        if((a*a)+(b*b)==(c*c)){
                                                printf("%i %i %i \n", a, b, c);
                                        }
                                }
                        }
                }

	}
	else{
		char *end;
		int m = strtol(argv[1], &end, 10);
		int a,b,c;
		b=2;
		c=3;
		for(a=1; a<b;a++){
			for(b=a+1; b<c;b++){
				for(c=b+1; c<=m;c++){
					if((a*a)+(b*b)==(c*c)){
						printf("%i %i %i \n", a, b, c);
					}
				}
			}
		}
	}
	return 0;
}
