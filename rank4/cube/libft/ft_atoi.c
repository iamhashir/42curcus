/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:33:48 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:33:49 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	long long int	x;
	int				sign;

	x = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = sign * -1;
	while (*str >= '0' && *str <= '9')
	{
		if ((x > LONG_MAX / 10) || \
			(x == LONG_MAX / 10 && (*str - 48) > LONG_MAX % 10))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		x = (10 * x) + (*str++ - 48);
	}
	return (sign * x);
}
