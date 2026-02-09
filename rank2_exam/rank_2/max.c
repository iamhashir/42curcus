#include "stdio.h"
int		max(int* tab, unsigned int len){
	int i =0;
	int c = 0;
	while(i<len){
		if(tab[i]>c){
			c = tab[i];
		}
		i++;
	}
	return c;
}

int main(){
	int tab[4]={10,4,3,5};
	printf("%d",max(tab,4));
}