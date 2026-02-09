// Assignment name  : search_and_replace
// Expected files   : search_and_replace.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program called search_and_replace that takes 3 arguments, the first
// arguments is a string in which to replace a letter (2nd argument) by
// another one (3rd argument).

// If the number of arguments is not 3, just display a newline.

// If the second argument is not contained in the first one (the string)
// then the program simply rewrites the string followed by a newline.

// Examples:
// $>./search_and_replace "Papache est un sabre" "a" "o"
// Popoche est un sobre
// $>./search_and_replace "zaz" "art" "zul" | cat -e
// $
// $>./search_and_replace "zaz" "r" "u" | cat -e
// zaz$
// $>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
// $
// $>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
// ZaZ eT David aiME le METal.$
// $>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
// eNcOre Un ExEmPle Pas Facile a Ecrire $

#include "unistd.h"
int main(int c,char **argv){
	char *s= argv[1];
	char *a=s;
	char *rep=argv[2];
	char *word= argv[3];
	if(c==4 && *(rep+1)=='\0' && *(word+1)=='\0'){
		while(*a){
			if(*a==*rep){
				*a=*word;
			}
			write(1,a,1);
			a++;
		}
	}
	write(1,"\n",1);

}