/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:17:17 by mhashir           #+#    #+#             */
/*   Updated: 2023/09/04 23:57:30 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;
	size_t				i;

	p_dst = (unsigned char *)dst;
	p_src = (const unsigned char *)src;
	i = 0;
	if (p_dst == p_src)
		return (p_dst);
	if (p_dst == NULL && p_src == NULL)
		return (NULL);
	while (i < n)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return ((char *)p_dst);
}
