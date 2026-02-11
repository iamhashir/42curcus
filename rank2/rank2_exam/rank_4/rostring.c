#include <unistd.h>

void rostring(char *str)
{
	int i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	int start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	int end = i;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i])
	{
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
			{
				while (str[i] == ' ' || str[i] == '\t')
					i++;
				if (str[i])
					write(1, " ", 1);
			}
			else 
				write(1, &str[i++], 1);
		}
		write(1, " ", 1);
	}
	while (start < end)
		write(1, &str[start++], 1);
}

int main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);
}