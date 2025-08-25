/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:33:57 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:34:16 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tos;
	unsigned char		*tod;
	size_t				c;

	c = 0;
	tod = (unsigned char *)dest;
	tos = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (c < n)
	{
		tod[c] = tos[c];
		c++;
	}
	return (dest);
}
