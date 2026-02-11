#include "unistd.h"
#include "stdio.h"

void put_nbr(int n){
	if(n>9)
		put_nbr(n/10);
	char c=(n % 10 + '0');
	write(1,&c,1);
}
 


int main(int c , char **v){
	int i=0;
	int flag =0;
	 
	if(c == 2  ){
		while(v[1][i]!='\0' && (v[1][i] =='\t' || v[1][i] == ' '))
			i++;
		while(v[1][i]!='\0'){
			if(v[1][i] =='\t' || v[1][i] ==' ')
			{
				flag=1;
				i++;
			}
			if(!(v[1][i] =='\t' || v[1][i] ==' ') && v[1][i]!='\0')
			{
				if(flag==1){
					write(1,"   ",3);
				}
				write(1,&v[1][i],1);
				flag =0;
				i++;
			}
		}
	}
 
	 
		write(1,"\n",1);
	 
	
	// put_nbr(i);

	
}