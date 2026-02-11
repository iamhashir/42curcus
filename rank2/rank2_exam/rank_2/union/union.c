#include "unistd.h"
void unions(char *str, char *s){

	int seen[255]={0};
	// char *s = str;
	while(*str){
		if(!seen[*str])
		{
			write(1,str,1);
			seen[*str] = 1;
		}	
		str++;
	}
	while(*s){
		if(!seen[*s])
		{
			write(1,s,1);
			
			seen[*s] =1;

		}
		s++;
	}

}
int main(int c , char **v){
	if(c ==3)
		unions(v[1],v[2]);
	write(1,"\n",1);
}
