/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:34:16 by mhashir          #+#    #+#             */
/*   Updated: 2024/11/19 19:41:56 by mhashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_ceiling_color(t_mlx *mlx, char *str)
{
	if (!mlx->map.color_of_ceiling)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.shade_of_ceiling = ft_strdup(str);
		mlx->map.color_of_ceiling = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	set_floor_color(t_mlx *mlx, char *str)
{
	if (!mlx->map.color_of_floor)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.shade_of_floor = ft_strdup(str);
		mlx->map.color_of_floor = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}
