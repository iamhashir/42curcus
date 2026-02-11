#include "stdio.h"
char ft_tolower(char c){
	if(c>='A' && c <='Z')
		return c+('A'-'a');
	return c;
}

// int get_digit(char c, int digits_in_base){
// 	int max_digit;
// 	int correction = digits_in_base - 1;
// 	if(digits_in_base <= 10)
// 		max_digit =  correction + '0';
// 	else
// 		max_digit =  correction - 10 + 'a';
// 	if(c >= '0' && c<='9' && c <= max_digit)
// 		return c -'0';
// 	else if(c>='a' && c <='f' && c <= max_digit)
// 		return 10 + c - 'a';
// 	else 
// 		return (-1);
// }
 

// int ft_atoi_base(const char *str, int str_base)
// {
// 	int result = 0;
// 	int sign = 1;
// 	int digit = 0;
// 	if(str == NULL || str_base <2 || str_base >16)
// 		return 0;
// 	if(*str == '-'){
// 		sign = -1;
// 		++str;
// 	}
// 	while(*str){
// 		digit = get_digit(ft_tolower(*str),str_base);
// 		if(digit == -1)
// 			break;
// 		result = result * str_base + digit;
// 		++str;
// 	}
// 	return result* sign;
// }

int  get_digits(char c,int base){

	int max_digit;
	int correction = base -1;
	if(base<=10)
		max_digit = correction+'0';
	else{
		max_digit = correction - 10 + 'a';
	}
	if(c>='0' && c <='9' && c<=max_digit){
		return c-'0';
	}else if(c>='a' && c<='f'&& c<=max_digit)
	{
		return c + 10 - 'a';
	}else{
		return -1;
	}

}
int ft_atoi_base(char *str,int base){
	
	int atoi;
	int i = 0;
	int 	sign = 1;
	int digit= 0;
	// if(!str || *str <2 || *str >16)
	// 	return 0;  
	if (*str == '-'){
		sign = -1;
		str++;
	}
	while(*str){
		digit =  get_digits(ft_tolower(*str),base);
		if(digit == -1){
			break;
		}
		atoi = atoi * base + digit;
		str++;
	}	
	return atoi * sign;

}
 



int get_digitss(char c, int base){
	int max_digit;
	base = base -1;
	if(base >=10)
		max_digit = base + '0';
	else{
		max_digit = base + 10 -'a';
	}
	if(c<='0' && c>='9')
	{
		return c - '0';
	}else if( c<='a' && c>='f'){
		return c + 10 - 'a';
	}
	else	
		return -1;
}

int atoi(char *str, int base){
	int digit;
	int atoi;
	int sign = 1;
	if(!str || *str >16 || * str <2)
		return 0;
	if(*str == '-'){
		str++;
		sign = -1;
	}
	while(*str){
		
		digit = get_digitss(ft_tolower(*str),base);
		if(digit == -1)
			break;
		atoi = atoi * base * digit;
		str++;
	}
	return sign * atoi;
}
int main(){
	printf("%d", ft_atoi_base("a",16));
}