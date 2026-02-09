// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays this string after rotating it
// one word to the left.

// Thus, the first word becomes the last, and others stay in the same order.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// Words will be separated by only one space in the output.

// If there's less than one argument, the program displays \n.

// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring "first" "2" "11000000"
// first
// $>
// $>./rostring | cat -e
// $
// $>

// "   hashir     malik    is    written   "
#include "unistd.h"

// void rostring(char *str){
// 	char *start = str;
// 	char *end = str;
// 	int len_f=0;
// 	int has_printed = 0;
// 	while(*start && (*start =='\t' || *start ==' ')){
// 		start++;
// 	}
// 	end = start;
// 	while(*end && (*end !=' ' && *end !='\t'))
// 	{
// 		end++;
// 		len_f++;
// 	}

// 	while(*end){
// 		while(*end=='\t' || *end==' ' )
// 			end++;
// 		if(*end)
// 		{	
// 			if(has_printed)
// 				write(1," ",1);
// 			while(*end &&(*end!='\t' && *end!=' ' ))
// 			{
// 				write(1,end,1);
// 				end++;
//  			}
// 			has_printed=1;
// 		}
// 	}
// 	if(has_printed)
// 		write(1," ",1);
// 	write(1,start,len_f);

// 	// write(1,"\n",1);
// }

void rostring(char *str);
int main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	write(1, "\n", 1);
	return 0;
}
// ----------------8<-------------[ START TEST 
//         💻 TEST
// ./a.out "abc   " 
//         🔎 YOUR OUTPUT:
// abc        🗝 EXPECTED OUTPUT:
// abc$
// ----------------8<------------- END TEST ]



// "   hashir     malik    is    written   "




void rostring(char *str){

	char *start = str;
	char *end = str;

	int len_f = 0;
	int has_printed = 0;

	while(*start && (*start ==' ' || *start =='\t')){
		start++;
	}
	end = start;
	while(*end && (*end !=' ' && *end !='\t')){
		end++;
		len_f++;
	}
	while(*end)
	{
		while(*end=='\t' || *end==' ')
			end++;
		if(*end){
			if(has_printed)
				write(1," ",1);
			while(*end && (*end!=' ' && *end !='\t')){
				write(1,end,1);
				end++;
			}
			has_printed =1;
		}
	}
	if(has_printed)
		write(1," ",1);
	write(1,start,len_f);
	 
}