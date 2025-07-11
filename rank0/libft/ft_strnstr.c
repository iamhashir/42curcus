/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:15:44 by mhashir           #+#    #+#             */
/*   Updated: 2023/09/04 03:35:57 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	lenn;

	if (haystack == NULL && len == 0)
		return (0);
	lenn = ft_strlen(needle);
	if (haystack == NULL && needle == NULL)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len >= lenn)
	{
		if (ft_strncmp(haystack, needle, lenn) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
