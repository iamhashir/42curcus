#include "stdlib.h"
int     *ft_rrange(int start, int end){
	int len = (end - start) < 0 ? ((end - start) * -1) +1 :(end - start) +1 ;
	int * range = malloc(sizeof(int) * len);
	int i = 0;

	while(i<len){
		if(start<end){
			range[i] = end--; 
		}
		else{
			range[i] = end++;
		}
		i++;
	}
	return range;
}

 