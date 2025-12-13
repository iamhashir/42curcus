/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:34:58 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:35:00 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	f;

	if (!s1 || !s2)
	{
		return (0);
	}
	f = 0;
	while (f < n && (s1[f] || s2[f]))
	{
		if (s1[f] != s2[f])
			return (((unsigned char *)s1)[f] - ((unsigned char *)s2)[f]);
		f++;
	}
	return (0);
}
