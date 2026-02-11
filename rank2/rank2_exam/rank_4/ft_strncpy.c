#include "stdio.h"
char *ft_strncpy (char *s1 , char *s2,int n){
	int i= 0;
	while(i<n)
		s1[i]=s2[i];
	while(i<n){
		i++;
	}
	return s1;
}
int main(){

	char src[] = "hello";
	char dest[10];

	ft_strncpy(src,dest,5);

	printf("%s",dest);
}