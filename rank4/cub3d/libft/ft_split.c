/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:34:29 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:34:31 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countsep(char const *str, char sep)
{
	int		c;
	int		i;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			c++;
			while (str[i] != sep && str[i])
				i++;
		}
		else
			i++;
	}
	return (c);
}

static int	ft_len(char const *s, char const c, int i)
{
	int		size;

	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

static void	ft_free(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free (s);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**split;
	int		i;
	int		a;

	if (!s)
		return (NULL);
	count = ft_countsep(s, c);
	split = (char **)malloc (sizeof(char *) * (count + 1));
	if (split == NULL)
		return (NULL);
	i = -1;
	a = 0;
	while (++i < count)
	{
		while (s[a] == c && s[a])
			a++;
		split[i] = ft_substr(s, a, ft_len(s, c, a));
		if (split[i] == NULL)
			ft_free(split, i);
		a += ft_len(s, c, a);
	}
	split[i] = NULL;
	return (split);
}
