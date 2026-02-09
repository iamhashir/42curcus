																																																				 #include <stdio.h>
 #include <stdlib.h>
// int	check_sign(int n)
// {
// 	if (n < 0)
// 		return (1); 
// 	return (0); 
// }

// size_t	ft_counter(int n)
// {
// 	size_t	counter;

// 	counter = 0;
// 	if (n == 0)
// 		counter++;
// 	while (n != 0)
// 	{
// 		n /= 10;
// 		counter++;
// 	}
// 	return (counter);
// }

// char	*ft_itoa(int n)
// {
// 	char	*itoa;
// 	int		sign;
// 	long	nbr;
// 	int		i;

// 	nbr = n;
// 	sign = check_sign(nbr);
// 	itoa = malloc(ft_counter(nbr) + sign + 1);
// 	if (!itoa)
// 		return (NULL);
// 	i = ft_counter(nbr)+ sign;
// 	itoa[i] = '\0';
// 	if (n < 0)
// 	{
// 		itoa[0] = '-';
// 		nbr = -nbr;
// 	}
// 	while (i-- > sign)
// 	{
// 		itoa[i] = '0' + (nbr % 10);
// 		nbr /= 10;
// 	}
// 	return (itoa);
// }

int ft_count(int i){
	int c = 1;
	if(i<0){
		i = -i;
	}
	if(i>9){
		return c + ft_count(i/10);
	}
	return c;
}
int csign(int a ){
	if (a<0){
		return 1;
	}
	return 0;
}
char *ft_itoa(int a){
	int nbr = a;
	int sign= csign(a);
	char *itoa = malloc(ft_count(a)+sign + 1);

	if(!itoa){
		return NULL;
	}
	int i = ft_count(nbr) + sign;

	if(nbr<0){
		itoa[0]='-';
		nbr = -nbr;
	}
	while(i-- >sign){
		itoa[i]= nbr % 10 + '0';
		nbr/=10;
	}
	return itoa;

}

int main(){

	printf("%s",ft_itoa(-123 ));
}