#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, const char **argv){
	for(int i = 0; i < argc-1;i++){
		for(int j = 0; j < strlen(argv[i+1]);j++){
			printf("%s\n", &argv[i+1][j]);
		}
	}
return 0;
}
