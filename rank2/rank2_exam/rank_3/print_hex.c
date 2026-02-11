
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

void print_hex(int n){
	if(n>16)
		print_hex(n/16);
	write(1, &"0123456789abcdef"[n%16],1);
}
int main(int c, char **v){
	int s1 = atoi(v[1]);
	print_hex(s1);
}