/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 02:30:04 by mhashir           #+#    #+#             */
/*   Updated: 2024/07/06 03:47:29 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <string.h>

int	julia_valid_check(const char *param)
{
	int	decimal_point_count;
	int	length;
	int	valid;
	int	i;

	decimal_point_count = 0;
	length = (int)strlen(param);
	valid = 1;
	i = 0;
	while (i < length)
	{
		if (param[i] == '.')
		{
			decimal_point_count++;
		}
		else if (!isdigit(param[i]) && (param[i] != '-' || i != 0))
		{
			valid = 0;
			break ;
		}
		i++;
	}
	if (decimal_point_count > 1)
		valid = 0;
	return (valid);
}
