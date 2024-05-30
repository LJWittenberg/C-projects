#include <stdio.h>
#include <ctype.h>

int main(){

	int aciCh;
	for(aciCh = 32; aciCh <= 127; aciCh++){
		printf("\n %d \t %#x \t %c", aciCh, aciCh, aciCh);
		if( isalpha(aciCh)){
			printf("\t A");
		}
		if( isdigit(aciCh)){
                	printf("\t D");
		}
		else if(ispunct(aciCh) || isspace(aciCh)){
			printf("\t O");
		}

	}
return 0;
}
