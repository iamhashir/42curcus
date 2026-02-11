#include "stdio.h"
int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    return (n &( n - 1)) == 0;
}

int main(){
	printf("%d",is_power_of_2(64));
}