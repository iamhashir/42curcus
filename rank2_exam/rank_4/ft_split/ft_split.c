// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

// char    **ft_split(char *str);
#include "stdlib.h"
#include "stdio.h"
char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}
char **ft_split(char *str)
{
	int wcount = 0;
	char *p = str;
	char *q = str;

	while (*p)
	{
		while (*p && (*p == ' ' || *p == '\t' || *p == '\n'))
			p++;
		if (*p)
		{
			wcount++;
			while (*p && (*p != ' ' && *p != '\t' && *p != '\n'))
				p++;
		}
	}
	char **words = malloc(sizeof(char *) * wcount + 1);
	p = str;
	int i = 0;
	while (*p)
	{
		while (*p && (*p == ' ' || *p == '\t' || *p == '\n'))
			p++;
		if (*p)
		{
			q = p;
			int wlen = 0;
			while (*p && (*p != ' ' && *p != '\t' && *p != '\n'))
			{
				wlen++;
				p++;
			}
			char *word = malloc(sizeof(char *) * wlen + 1);
			char *start = word;
			while( *q && wlen > 0){
				*word++=*q++;
				wlen--;
			}
			*word='\0';
			word = start;
			// word[wlen] = '\0';w
			words[i++] = word;
			q = p;
		}
	}
	words[i] = NULL;

	return words;
}
// int main()
// {
//  	printf("%s", ft_split("hashir is writing this")[0]);
// }