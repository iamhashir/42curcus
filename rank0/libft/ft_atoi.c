/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:24:39 by mhashir           #+#    #+#             */
/*   Updated: 2023/09/04 02:56:58 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;
	unsigned long long	max;

	res = 0;
	sign = 1;
	max = 9223372036854775807;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' )
	{
		res = res * 10 + *str - '0';
		if (res > max && sign == 1)
			return (-1);
		if (res > max + 1 && sign == -1)
			return (0);
		str++;
	}
	return (res * sign); 
}
