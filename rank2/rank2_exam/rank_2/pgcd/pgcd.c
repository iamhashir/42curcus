#include "stdlib.h"
#include "stdio.h"
void pgcd(char *s1, char *s2){
	
	int num1 = atoi(s1);
	int num2 = atoi(s2);
	if(num1>0 && num2>0){
		while (num1 != num2)
		{
			if(num1>num2)
				num1-=num2;
			else{
				num2-=num1;
			}
		}
		printf("%d",num1);
	}
}

int main(int c, char **v){
	if (c == 3)
		pgcd(v[1],v[2]);
	printf("\n");
}