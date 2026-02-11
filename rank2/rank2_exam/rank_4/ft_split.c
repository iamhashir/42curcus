#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
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
	int word_count = 0;
	char *p = str;
	while (*p)
	{
		while (*p && (*p == ' ' || *p == '\t' || *p == '\n'))
			p++;
		if (*p)
		{
			word_count++;
			while (*p && *p != ' ' && *p != '\t' && *p != '\n')
				p++;
		}
	}

	char **words = malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return NULL;

	p = str;
	int i = 0;
	while (*p)
	{
		while (*p && (*p == ' ' || *p == '\t' || *p == '\n'))
			p++;
		if (*p)
		{
			int word_len = 0;
			char *q = p;
			while (*q && *q != ' ' && *q != '\t' && *q != '\n')
			{
				word_len++;
				q++;
			}
			char *word = malloc((word_len + 1) * sizeof(char));
			if (!word)
				return NULL;
			ft_strncpy(word, p, word_len);
			word[word_len] = '\0';
			words[i++] = word;
			p = q;
		}
	}
	words[i] = NULL;
	return words;
}
int main(){
	char **s=ft_split("hashir is hashing");
	printf("%s",s[4]);
	for (int i = 0; s[i] != NULL; i++) {
        free(s[i]);
    }
	free(s);
}
 
 
//  int wc(char *str)
// {
// 	int wc = 0;
// 	while (*str != '\0')
// 	{
// 		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
// 			str++;
// 		if (*str)
// 		{
// 			wc++;
// 			while (*str && *str != ' ' && *str != '\t' && *str != '\n')
// 				str++;
// 		}
// 	}
// 	return wc;
// }
// #include "string.h"

// int main()
// {
// 	char *str = " a";
// 	int word_count = wc(str);
// 	char *p = str;
// 	// printf("%i",word_count);
// 	char **temp = malloc(sizeof(char *) * word_count + 1);
// 	int len = 0;
// 	while (*str)
// 	{
// 		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
// 			str++;
// 		if (*str)
// 		{
// 			while (*str && (*str != ' ' && *str != '\t' && *str != '\n'))
// 			{
// 				len++;
// 				str++;
// 			}
// 		}
// 		str++;
// 	}
// 	printf("%i", len);

// 	free(temp);

// 	return 0;
// }

// while (*str)
// 	{

// 		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
// 			str++;

// 		if (*str)
// 		{
// 			wc++;
// 			while (*str && (*str != '\n' || *str != '\t' || *str != ' '))
// 				str++;
// 			printf("-%c-", *str);
// 		}
// 		str++;
// 	}