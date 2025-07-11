/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:23:06 by mhashir           #+#    #+#             */
/*   Updated: 2023/09/04 03:31:12 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	temp_copy(const unsigned char *s, unsigned char *d, size_t n)
{
	unsigned char	temp[1000];
	size_t			i;

	i = 0;
	while (i < n)
	{
		temp[i] = s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d[i] = temp[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (d == NULL && s == NULL)
		return (NULL);
	if (d == s)
		return (d);
	if (d > s && d < (s + n))
	{
		temp_copy(s, d, n);
		d = d + n;
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
