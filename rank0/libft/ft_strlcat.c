/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 23:59:25 by mhashir           #+#    #+#             */
/*   Updated: 2023/09/04 03:34:51 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dst_ptr;
	const char	*src_ptr;
	size_t		src_len;
	size_t		dst_len;

	if (dst == NULL && dstsize == 0)
		return (0);
	dst_ptr = dst;
	src_ptr = src;
	while (*dst_ptr && dstsize)
	{
		dst_ptr++;
		dstsize--;
	}
	while (*src_ptr && dstsize > 1)
	{
		*dst_ptr++ = *src_ptr++;
		dstsize--;
	}
	if (dstsize > 0)
		*dst_ptr = '\0';
	src_len = ft_strlen(src_ptr);
	dst_len = dst_ptr - dst;
	return (dst_len + src_len);
}
