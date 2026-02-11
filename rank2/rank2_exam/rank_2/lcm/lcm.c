#include "stdlib.h"
int pgsd(int a, int b){
	a =abs(a);
	b =abs(b);
	while(a!=b){
		if(a>b)
			a-=b;
		else
			b-=a;
	}
	return a;
}
#include "stdio.h"
unsigned int lcm(unsigned int a,unsigned int b){
	if ( a  == 0 || b == 0)
		return 0;
	if (((int)a) < 0 || ((int)b) < 0)
        return 0;
	return (a*b)/pgsd(a,b);
}
