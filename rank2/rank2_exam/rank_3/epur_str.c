#include "unistd.h"
int main(int c, char **gv){
	 

	if( c == 2)
	{
		int i = 0;
		int flag = 1;
		while(gv[1][i] == ' ' || gv[1][i] == '\t') 
				i++; 
		while(gv[1][i]) {
			if(gv[1][i] == ' ' || gv[1][i] == '\t') {
				if(flag == 1){
					write(1,&" ",1);
					flag++;
				}
			}
			if(!(gv[1][i] == ' ' || gv[1][i] == '\t')) {
				write(1,&gv[1][i],1);
				i++;
				flag = 1;
			}
			if(gv[1][i] == '\0'){
				break;
			}	
		}
	}  
	else {
		write(1,&"\n",1);
	}
}





















// #include <unistd.h>

// int main(int argc, char const *argv[])
// {
// 	int i;
// 	int flg;

// 	if (argc == 2)
// 	{
// 		i = 0;
// 		while (argv[1][i] == ' ' || argv[1][i] == '\t')
// 			i += 1;
// 		while (argv[1][i])
// 		{
// 			if (argv[1][i] == ' ' || argv[1][i] == '\t')
// 				flg = 1;
// 			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
// 			{
// 				if (flg)
// 					write(1, " ", 1);
// 				flg = 0;
// 				write(1, &argv[1][i], 1);
// 			}
// 			i += 1;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }