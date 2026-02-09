// res = res * 10 + str -'0';
#include "stdlib.h"
#include "stdio.h"
int	ft_atoi(const char *str){
	long int result = 0;
	int sign = 1;

	if(*str=='-'){
		sign = -1;
		str++;
	}
	if(*str=='+'){
		str++;
	}

	while(*str && *str != ' '&& *str != '\t'&& *str != '\n' && *str>='0' && *str <='9'){
		result = result *10 + *str -'0';
		str++;
	}
	if(result >= 2147483647 || result <= -2147483647){
		result=2147483647;
		// return 0;
	}
	return result * sign;
}

// int main(){
// 	char *n = "Ceci permet de decouvrir le fonctionnement de ton ft_atoi.";
// 	printf("%i\n",ft_atoi( n));
// 	printf("\t%i\t",atoi( n));
// }