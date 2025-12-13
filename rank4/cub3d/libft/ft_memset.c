/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:34:01 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:34:13 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tob;
	size_t			co;

	co = 0;
	tob = (unsigned char *)b;
	while (co < len)
	{
		tob[co] = (unsigned char)c;
		co++;
	}
	return (b);
}
