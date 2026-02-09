#include "unistd.h"
void rot13(char *str){

	while(*str){
		if((*str >='A' && *str<='M') || *str >='a' && *str<='m'){
			*str= *str + 13;
		}
		else if((*str >='N' && *str<='Z') || *str >='n' && *str<='z'){
			*str= *str - 13;
		}
		write(1,str,1);
		str++;
	}
}
int main(int c,char  **v){

	if(c == 2){
		rot13(v[1]);
	}
	write(1,"\n",1);

}