#include "unistd.h"

int calpha(char s){
	if(s>='A' && s <='Z'){
		return 1;
	}
	return 0;
}

int salpha(char s){
	if(s>='a' && s <='z'){
		return 1;
	}
	return 0;
}

void rstr(char *s){
	char c;
	if(salpha(s[0])){
		 c = s[0]-32;
		write(1,&c,1);
		s++;
	}
	while(*s){
		if(calpha(*s)){
			*s=*s+32;
			// write(1,&c,1);
		}
		if(((*(s+1)==' '|| *(s+1)=='\0')) && (calpha(*s)||salpha(*s)) && !(calpha(*s)))
			*s=*s-32;
		write(1,s,1);
		s++;
	}
}

int main(int c, char **v){
	int i = 1;
	if(c>=2){
		while(i<c){
			rstr(v[i]);
			write(1,"\n",1);
			i++;
		}

	}
	else
		write(1,"\n",1);
}