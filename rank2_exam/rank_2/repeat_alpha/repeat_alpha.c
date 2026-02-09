// Assignment name  : repeat_alpha
// Expected files   : repeat_alpha.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called repeat_alpha that takes a string and display it
// repeating each alphabetical character as many times as its alphabetical index,
// followed by a newline.

// 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

// Case remains unchanged.

// If the number of arguments is not 1, just display a newline.

// Examples:

// $>./repeat_alpha "abc"
// abbccc
// $>./repeat_alpha "Alex." | cat -e
// Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
// $>./repeat_alpha 'abacadaba 42!' | cat -e
// abbacccaddddabba 42!$
// $>./repeat_alpha | cat -e
// $
// $>
// $>./repeat_alpha "" | cat -e
// $
// $>
#include <unistd.h>

void repeat_alpha(char *str)
{
	int i = 0;
	int rep;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			rep = str[i] - 'a';
		if (str[i] >= 'A' && str[i] <= 'Z')
			rep = str[i] - 'A';
		while (rep > 0)
		{
			write(1, &str[i], 1);
			rep--;
		}
		write(1, &str[i++], 1);
	}
}

int main(int ac , char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);

}