/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:34:39 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:34:40 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = ft_strlen(s);
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
	{
		return (0);
	}
	ft_memcpy(dest, s, i);
	dest[i] = '\0';
	return (dest);
}
