#include "unistd.h"
// int main(int ac , char **argv){

// 	int a[256]={0};
// 	int i =0;
// 	int j =0;
// 	if(ac == 3){
// 		while(argv[1][i])
// 		{
// 			if(!a[argv[1][i]]){
// 				write(1,&argv[1][i],1);
// 				a[argv[1][i]] = 1;
// 			}
// 			i++;
// 		}
// 		while(argv[2][j])
// 		{
// 			if(!a[argv[2][j]]){
// 				write(1,&argv[2][j],1);
// 				a[argv[2][j]] = 1;
// 			}
// 			j++;
// 		}
// 	}
// 	else{
// 		write(1,"\n",1);
// 	}
// }















int main(int c, char **v){
    if (c != 3) {
        write(1, "\n", 1);
        return 1;
    }

    unsigned char a[256] = {0};
    int i = 0;
    int j = 0;

    while (v[1][i]) {
        if (!a[v[1][i]]) {
            write(1, &v[1][i], 1);
            a[v[1][i]] = 1;
        }
        i++;
    }
    while (v[2][j]) {
        if (!a[v[2][j]]) {
            write(1, &v[2][j], 1);
            a[v[2][j]] = 1;
        }
        j++;
    }

    write(1, "\n", 1);
    return 0;
}