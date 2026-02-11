#include <unistd.h>

// int main(int argc, char **argv)
// {
// 	int i = 0;
// 	int j = 0;
// 	if (argc == 3)
// 	{
// 		while (argv[2][j] && argv[1][i])
// 		{
// 			if (argv[2][j] == argv[1][i])
// 				i++;
// 			j++;
// 		}
// 		if (argv[1][i] == '\0')
// 			write(1, "1", 1);
// 		else
// 			write(1, "0", 1);
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }

int main(int c, char **v)
{

	char *s;
	char *s1;
	s = v[1];
	s1 = v[2];

	int i, j;
	if (c == 3)
	{

		while (s[i] && s1[j])
		{
			if (s[i] == s1[j])
				i++;
			j++;
		}
		if (s[i] == '\0')
		{
			write(1, "1", 1);
		}
		else
		{
			write(1, "0", 1);
		}
	}
	write(1, "\n", 1);
}