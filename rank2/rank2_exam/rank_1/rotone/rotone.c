#include "unistd.h"
void rotone(char *str){
	while(*str){
		if((*str >= 'A' && *str <'Z')|| (*str >= 'a' && *str <'z')){
			*str = *str + 1;
		}
		else if(*str =='z' || *str == 'Z')
		{
			*str = *str - 25;
		}
		write(1,str,1);
		str++;
	}
}
int main(int c   , char **v){
	if(c ==2)
		rotone(v[1]);
	write(1,"\n",1);
}