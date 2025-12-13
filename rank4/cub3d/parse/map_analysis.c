/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analysis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:33:19 by mhashir          #+#    #+#             */
/*   Updated: 2024/11/19 14:23:09 by mhashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_position_enclosed(char **map, int row, int colum)
{
	if (colum < 1 || row < 1 || !map[row + 1] || !map[row][colum + 1])
	{
		return (1);
	}
	if (map[row + 1][colum] != ' ' && map[row - 1][colum] != ' '
		&& map[row][colum - 1] != ' ' && map[row][colum + 1] != ' ')
		return (0);
	return (1);
}

int	analyze_map_enclosure(t_mlx *mlx)
{
	int	row;
	int	colum;

	row = 0;
	while (mlx->map.map[row])
	{
		colum = 0;
		while (mlx->map.map[row][colum])
		{
			if (mlx->map.map[row][colum] == '0')
			{
				if (is_position_enclosed(mlx->map.map, row, colum))
					return (1);
			}
			++colum;
		}
		++row;
	}
	return (0);
}

int	check_horizontal_borders(t_mlx *mlx, int row, int colum)
{
	int	start_c;

	start_c = colum;
	while (mlx->map.map[row][colum])
	{
		if (mlx->map.map[row][colum] == '1')
			break ;
		if (mlx->map.map[row][colum] == '0')
			return (1);
		colum++;
	}
	colum = start_c;
	while (colum >= 0)
	{
		if (mlx->map.map[row][colum] == '1')
			break ;
		if (mlx->map.map[row][colum] == '0')
			return (1);
		--colum;
	}
	return (0);
}

int	check_vertical_borders(t_mlx *mlx, int row, int colum)
{
	int	start_r;

	start_r = row;
	while (mlx->map.map[row])
	{
		if (mlx->map.map[row][colum] == '1')
			break ;
		if (mlx->map.map[row][colum] == '0')
			return (1);
		row++;
	}
	row = start_r;
	while (row >= 0)
	{
		if (mlx->map.map[row][colum] == '1')
			break ;
		if (mlx->map.map[row][colum] == '0')
			return (1);
		--row;
	}
	return (0);
}

int	is_map_surrounded_by_walls(t_mlx *mlx, char **map, int r, int c)
{
	if (c < 1 || r < 1 || !map[r + 1] || !map[r][c + 1])
		return (1);
	if (map[r + 1][c] != ' ' && map[r - 1][c] != ' ' && map[r][c - 1] != ' '
		&& map[r][c + 1] != ' ')
	{
		mlx->player.pos_x = (double)r + 0.5;
		mlx->player.pos_y = (double)c + 0.5;
		return (0);
	}
	return (1);
}
