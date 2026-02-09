#include "unistd.h"
void inter(char *s,char *c){
	char seen[255]= {0};
	int  i = 0 ;
	int  j = 0 ;
		i = 0;
	while(s[i]){
		j = 0;
		while(c[j]){
			if(s[i]==s[j]){
				if(!seen[s[i]]){
					seen[s[i]] =1;
					write(1,&s[i],1);
				}
				break;
			}
			j++;
		}
		i++;
	}

}
int main(){

	inter("padinton", "paqefwtdjetyiytjneytjoeyjnejeyj"  );
}