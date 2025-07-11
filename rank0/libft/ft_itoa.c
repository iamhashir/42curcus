/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:17:28 by mhashir           #+#    #+#             */
/*   Updated: 2023/09/05 00:02:14 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_sign(int n)
{
	if (n < 0)
		return (1); 
	return (0); 
}

size_t	ft_counter(int n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		counter++;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		sign;
	long	nbr;
	int		i;

	nbr = n;
	sign = check_sign(nbr);
	itoa = malloc(ft_counter(nbr) + sign + 1);
	if (!itoa)
		return (NULL);
	i = ft_counter(nbr)+ sign;
	itoa[i] = '\0';
	if (n < 0)
	{
		itoa[0] = '-';
		nbr = -nbr;
	}
	while (i-- > sign)
	{
		itoa[i] = 48 + (nbr % 10);
		nbr /= 10;
	}
	return (itoa);
}
