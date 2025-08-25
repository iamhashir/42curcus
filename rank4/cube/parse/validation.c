/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:56:32 by mhashir          #+#    #+#             */
/*   Updated: 2024/11/19 14:23:09 by mhashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validate_map_structure(t_mlx *mlx)
{
	if (mlx->map.max < 3 || mlx->map.size < 3)
		return (1);
	if (analyze_map_spaces(mlx))
		return (1);
	if (validate_top_bottom_walls(mlx))
		return (1);
	if (validate_side_walls(mlx))
		return (1);
	if (validate_starting_position(mlx))
		return (1);
	if (analyze_map_enclosure(mlx))
		return (1);
	return (0);
}

int	analyze_map_spaces(t_mlx *mlx)
{
	int	row;
	int	colum;

	row = 0;
	while (mlx->map.map[row])
	{
		colum = 0;
		while (mlx->map.map[row][colum])
		{
			if (mlx->map.map[row][colum] == ' ')
			{
				if (check_vertical_borders(mlx, row, colum))
					return (1);
				if (check_horizontal_borders(mlx, row, colum))
					return (1);
			}
			++colum;
		}
		++row;
	}
	return (0);
}

int	validate_top_bottom_walls(t_mlx *mlx)
{
	int	colum;

	colum = 0;
	while (mlx->map.map[0][colum])
	{
		if (mlx->map.map[0][colum] == ' ' || mlx->map.map[0][colum] == '1')
			;
		else
			return (1);
		++colum;
	}
	colum = 0;
	while (mlx->map.map[mlx->map.size - 1][colum])
	{
		if (mlx->map.map[mlx->map.size - 1][colum] == ' '
			|| mlx->map.map[mlx->map.size - 1][colum] == '1')
			;
		else
			return (1);
		++colum;
	}
	return (0);
}

int	validate_side_walls(t_mlx *mlx)
{
	int	row;

	row = 0;
	while (mlx->map.map[row])
	{
		if (mlx->map.map[row][0] == ' ' || mlx->map.map[row][0] == '1')
			;
		else
			return (1);
		++row;
	}
	row = 0;
	while (mlx->map.map[row])
	{
		if (mlx->map.map[row][mlx->map.max - 1] == ' '
			|| mlx->map.map[row][mlx->map.max - 1] == '1')
			;
		else
			return (1);
		++row;
	}
	return (0);
}

int	validate_starting_position(t_mlx *mlx)
{
	int	row;
	int	c;
	int	found;

	row = 0;
	found = 0;
	while (mlx->map.map[row])
	{
		c = 0;
		while (mlx->map.map[row][c])
		{
			if (mlx->map.map[row][c] == 'E' || mlx->map.map[row][c] == 'N'
				|| mlx->map.map[row][c] == 'W' || mlx->map.map[row][c] == 'S')
			{
				if (is_map_surrounded_by_walls(mlx, mlx->map.map, row, c))
					return (1);
				found++;
			}
			++c;
		}
		++row;
	}
	if (found != 1)
		return (1);
	return (0);
}
