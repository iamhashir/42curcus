/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:48:27 by mhashir           #+#    #+#             */
/*   Updated: 2023/09/04 03:32:57 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split_memory(char **split, size_t i)
{
	while (i > 0)
	{
		i--;
		free(split[i]);
	}
	free(split);
}

static size_t	word_count(const char *s, char c)
{
	size_t	counted;
	size_t	i;

	i = 0;
	counted = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			counted++;
		while (s[i] != c && s[i])
			i++;
	}
	return (counted);
}

static void	find_positions(char const *s, char c, size_t *start, size_t *end)
{
	while (s[*start] && s[*start] == c)
		(*start)++;
	*end = *start;
	while (s[*end] && s[*end] != c)
		(*end)++;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	split = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !(split))
		return (NULL);
	while (i < word_count(s, c))
	{
		find_positions(s, c, &start, &end);
		split[i] = ft_substr(s, start, end - start);
		if (split[i] == NULL)
			return (free_split_memory(split, i), NULL);
		start = end;
		i++;
	}
	split[i] = NULL;
	return (split);
}
