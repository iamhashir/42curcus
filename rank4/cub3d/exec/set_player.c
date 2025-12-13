/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:21:23 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:23:18 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../cub3d.h"

void	initialize_ns_direction(t_mlx *mlx, int north)
{
	if (north)
	{
		mlx->player.dir_x = -1;
		mlx->player.dir_y = 0;
		mlx->player.plane_x = 0;
		mlx->player.plane_y = 0.66;
	}
	else
	{
		mlx->player.dir_x = 1;
		mlx->player.dir_y = 0;
		mlx->player.plane_x = 0;
		mlx->player.plane_y = -0.66;
	}
}

void	initialize_we_direction(t_mlx *mlx, int west)
{
	if (west)
	{
		mlx->player.dir_x = 0;
		mlx->player.dir_y = -1;
		mlx->player.plane_x = -0.66;
		mlx->player.plane_y = 0;
	}
	else
	{
		mlx->player.dir_x = 0;
		mlx->player.dir_y = 1;
		mlx->player.plane_x = 0.66;
		mlx->player.plane_y = 0;
	}
}

void	setup_player_orientation(t_mlx *mlx)
{
	if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y] == 'W')
		initialize_we_direction(mlx, 1);
	else if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y]
		== 'E')
		initialize_we_direction(mlx, 0);
	else if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y]
		== 'N')
		initialize_ns_direction(mlx, 1);
	else if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y]
		== 'S')
		initialize_ns_direction(mlx, 0);
}

void	initialize_game_view(t_mlx *mlx)
{
	int	x;
	int	y;

	setup_player_orientation(mlx);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx->buf[y][x] = 0;
			++x;
		}
		++y;
	}
}
