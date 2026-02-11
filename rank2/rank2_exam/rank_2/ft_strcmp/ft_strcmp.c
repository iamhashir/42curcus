#include "string.h"
#include "stdio.h"

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] || s2[i])
// 	{
// 		if (s1[i] < s2[i])
// 			return (-1); 	//1st is less than 2nd string
// 		if (s1[i] > s2[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);	//strings are equal
// }
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}	

int main(){
printf("%i",	ft_strcmp("ABA","ABZ"));
printf("%i",	strcmp("ABA","ABZ"));
}