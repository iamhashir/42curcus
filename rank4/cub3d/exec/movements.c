/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:21:43 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:21:44 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	strafe_player_left(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x - dir_y * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x -= dir_y * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y + dir_x * 0.05)] != '1')
		mlx->player.pos_y += dir_x * 0.05;
}

void	strafe_player_right(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x + dir_y * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x += dir_y * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y - dir_x * 0.05)] != '1')
		mlx->player.pos_y -= dir_x * 0.05;
}

void	move_player_forward(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x + dir_x * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x += dir_x * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y + dir_y * 0.05)] != '1')
		mlx->player.pos_y += dir_y * 0.05;
}

void	move_player_backward(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x - dir_x * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x -= dir_x * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y - dir_y * 0.05)] != '1')
		mlx->player.pos_y -= dir_y * 0.05;
}
