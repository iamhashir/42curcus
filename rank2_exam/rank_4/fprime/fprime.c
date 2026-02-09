#include "stdlib.h"
#include "stdio.h"
void fprime(int n){

	int i = 1;
	if(n ==1)
		printf("1");
	while(++i <=n){
		if(n%i == 0){
			printf("%d",i);
			if(i == n)
				break;
			printf("*");
			n/=i;
			i=1;
		}
	}

}

int main(int c, char **v){
	if (c == 2){
		fprime(atoi(v[1]));
	}
	printf("\n");
}