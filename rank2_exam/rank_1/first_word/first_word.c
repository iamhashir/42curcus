#include "unistd.h"

void f(char *str){
	while(*str==' ')
		str++;
	while(*str){
	
		if(*str==' '){
			break;
		}
	write(1,str,1);
	str++;
	}
}

int main(int c, char **argv){
	int i =0;
	if(c==2)
		f(argv[1]);
	write(1,"\n",1);
}