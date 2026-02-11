#include "unistd.h"
void snake(char *s){
	while(*s){
		
		if(*(s)=='_' && (*(s+1)>='a' && *(s+1)<='z'))
		{
			char *c = s+1;
			*c = *c-32;
			// write(1,&c,1);
			s++;
		}
		write(1,s,1);
		s++;
	}
}
int main(int c , char **v){
	if(c == 2)
		snake(v[1]);
	write(1,"\n",1);
}



