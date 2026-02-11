#include "unistd.h"
int main(int c , char **v)
{
	int i =0;
	if(c ==2)
	{
		while(v[1][i]){
			if(v[1][i]=='_'){
				i++;
				v[1][i]-= 32;
			}
			write(1,&v[1][i],1);
			i++;
		}
	}
	else
	{
		write(1,&"\n",1);
	}
}