#include "unistd.h"

void print_hex(int n){
	if(n>=16)
		print_hex(n/16);
	write(1,&"0123456789abcdef"[n%16],1);
}
int atois(char *s){
	int result = 0;

	while(*s){
		result = result *10 + *s - '0';
		s++;
	}
	return result;
}
int main(int c, char **v){
	if(c == 2)
		print_hex(atois(v[1]));
	write(1,"\n",1);
}