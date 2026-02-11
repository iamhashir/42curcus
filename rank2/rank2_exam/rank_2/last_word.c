#include "unistd.h"
int main(){
	char *abc ="hashir is malik";
	int i = 0;
	while(*abc!='\0')
		abc++;
	abc--;

	while(abc != '\0' &&*abc!=' '){
		abc--;
	}
	abc++;
	while(*abc!='\0'){
		write(1,abc,1);
		abc++;
	}
}