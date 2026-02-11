#include "unistd.h"

void ulstr(char *str){
	while(*str)
		{
			if(*str >='A' && *str<='Z')
			{
				*str = *str + 32;
			}
			else if(*str >='a' && *str<='z')
			{
				*str = *str - 32;
			}
			write(1,str,1);
			str++;

		}
	}

int main(int c, char **v){
	if(c == 2){

	ulstr(v[1]);
	}
	write(1,"\n",1);
}