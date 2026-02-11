#include "stdio.h"
#include "unistd.h"
int ft_atoi(char *s){
	int result =0;
	while( *s=='+' || *s == '-'){
		s++;}
	while(*s ){
		result = result * 10 + *s  - '0';
		s++;
	}
	return result;
}

int is_prime(int num) {
    if (num <= 1) return 0; 
    if (num % 2 == 0 && num > 2) return 0;
	int i =3;
	while(i*i <=num ){
		if(num%i ==0) 
			return 0;
		i+=2;
	}
	
    return 1;
}
void ft_nbr(int n){
	int res = 0;
	if(n>=10)
		ft_nbr(n/10);
	res = n%10+'0';
	write(1,&res,1);
}
int main(int c , char **arg){
	int sum =0;
	int num = ft_atoi(arg[1]);
	while(num>0){
		if(is_prime(num)){
			sum+=num;
			ft_nbr(num);
			write(1,"\n",1);
			// printf(" prime number %d\n",num);
		}
		num--;
	}
	// printf("%i",sum);
	ft_nbr(sum);
}
