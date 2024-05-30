#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, const char **argv){
	char *end;
	char binary[] = {};
	int gzw;
	char hexch = 'x';
	char bin = 'b';
	if(argc == 1){
		fprintf(stderr, "Required integral number is missing!\n");
		return 1;
	}
	if(argc > 2){
		fprintf(stderr, "Superfluous argument was given! Only one are allowed.\n");
		return 1;
	}
	if(isalpha(argv[1][0])){
		fprintf(stderr, "Given argument %s is not a natrual number. \n", &argv[1][0]);
		return 1;
	}
	/* if the str is a binary */
        if(argv[1][0] == '0' && argv[1][1] == bin){
                for(int i=0; i < strlen(argv[1]);i++){
                        binary[i] = (char)argv[1][i+2];
                }
                gzw = strtol(binary, &end, 2);
	}

	/* hexadezimal */
	else if(argv[1][0] == '0' && argv[1][1] == hexch){
		gzw = strtol(argv[1], &end, 16);
	}

	else{
		gzw = strtol(argv[1], &end, 10);
	}
	if(gzw == 1){
		printf("%i is not a prim number\n", gzw);
		return 1;
	}
	for(int i = 2; i <= gzw/2; i++){
		if(gzw % i == 0){
			printf("%i is not prim number.\n", gzw);
			return 1;
		}
	}
	printf("%i is a prim number \n", gzw);

return 0;
}
