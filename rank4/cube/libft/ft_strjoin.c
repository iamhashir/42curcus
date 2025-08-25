/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:34:43 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:34:46 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sub;
	size_t	f;
	size_t	w;

	f = 0;
	w = 0;
	if (s1 != NULL && s2 != NULL)
	{
		sub = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
		if (sub == NULL)
			return (NULL);
		while (s1[w])
		{
			sub[w] = s1[w];
			w++;
		}
		while (s2[f])
		{
			sub[w + f] = s2[f];
			f++;
		}
		sub[w + f] = '\0';
		return (sub);
	}
	return (NULL);
}
