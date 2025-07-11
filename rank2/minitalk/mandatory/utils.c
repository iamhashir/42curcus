/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:33:40 by mhashir           #+#    #+#             */
/*   Updated: 2024/04/05 15:46:06 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	while (*str >= '0' && *str <= '9')
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long n, char *base, int i, int *std_output)
{
	if (n < 0)
	{
		*std_output += write(1, "-", 1);
		n = -n;
	}
	if (n / i > 0)
		ft_putnbr(n / i, base, i, std_output);
	*std_output += write(1, &base[n % i], 1);
}
