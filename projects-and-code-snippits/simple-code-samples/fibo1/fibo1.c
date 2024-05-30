#include<stdio.h>
#include<math.h>

int main(){
long long fib[48];
fib[0]=0;
fib[1]=1;
	for(int i = 2; i <= 47;i++)
		fib[i]=fib[i-1]+fib[i-2];

	for(int j = 0; j <= 47;j++)
		printf("\n%u  %llu", j, fib[j]);
	return 0;

}
