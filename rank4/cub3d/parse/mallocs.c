/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:01:19 by mhashir          #+#    #+#             */
/*   Updated: 2024/11/19 14:23:09 by mhashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	copy_map_to_memory(t_mlx *mlx, char **strs, int max)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (!is_map_valid(strs[i]))
			return (1);
		ft_strlcpy(mlx->map.map[i], strs[i], max);
		++i;
	}
	return (0);
}

int	find_width(char **strs)
{
	int	i;
	int	max;
	int	z;

	i = 0;
	while (strs[i])
	{
		z = 0;
		while (strs[i][z])
			++z;
		if (z > max)
			max = z;
		++i;
	}
	return (max);
}

int	allocate_map_memory(t_mlx *mlx, char **strs)
{
	int	i;
	int	max;

	i = 0;
	while (strs[i])
		++i;
	mlx->map.size = i;
	mlx->map.map = malloc(sizeof(char *) * (i + 1));
	if (!mlx->map.map)
		return (1);
	max = find_width(strs);
	mlx->map.max = max;
	i = 0;
	while (strs[i])
	{
		mlx->map.map[i] = malloc(sizeof(char) * (max + 1));
		if (!mlx->map.map[i])
			return (1);
		++i;
	}
	mlx->map.map[i] = 0;
	if (copy_map_to_memory(mlx, strs, max))
		return (1);
	return (0);
}
