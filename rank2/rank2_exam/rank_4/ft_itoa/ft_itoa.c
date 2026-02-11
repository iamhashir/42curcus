// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:
#include "stdio.h"
#include "stdlib.h"
char	*ft_itoa(int n){
	char *result;
	int count = 0;
	int nbr = n;

	if(n<0)
		count++;
	while(nbr!=0){
		nbr/=10;
		count++;
	}
	
	result = malloc(sizeof(char)*count + 1);
	result[count]='\0';
	nbr=n;
	if(n==0){
		return "0";
	}
	if(nbr<0){
		result[0]='-';
		nbr=-nbr;
	}
	while(nbr)
	{
		result[--count] = nbr %10 + '0';
		nbr/=10;
	}
	return result;
}
// int main(){
// 	printf("%s",(ft_itoa(-13268) ));
// }
