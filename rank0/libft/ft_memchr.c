/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:05:08 by mhashir           #+#    #+#             */
/*   Updated: 2023/08/27 02:06:31 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		ch;

	ch = c;
	p = s;
	while (n > 0)
	{
		if (*p == ch)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}
