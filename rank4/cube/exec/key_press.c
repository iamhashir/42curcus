/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:21:49 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:21:50 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

int	handle_key_release(int keycode, t_mlx *mlx)
{
	if (keycode == 0)
		mlx->key_a = 0;
	else if (keycode == 1)
		mlx->key_s = 0;
	else if (keycode == 13)
		mlx->key_w = 0;
	else if (keycode == 2)
		mlx->key_d = 0;
	else if (keycode == 53)
		cleanup_and_exit(mlx);
	else if (keycode == 123)
		mlx->key_left = 0;
	else if (keycode == 124)
		mlx->key_right = 0;
	return (0);
}

int	cleanup_and_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img[0].img_ptr);
	mlx_destroy_image(mlx->mlx, mlx->img[1].img_ptr);
	mlx_destroy_image(mlx->mlx, mlx->img[2].img_ptr);
	mlx_destroy_image(mlx->mlx, mlx->img[3].img_ptr);
	mlx_destroy_image(mlx->mlx, mlx->img[4].img_ptr);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_game_resources(mlx);
	write(1, "close game window success\n", 26);
	exit(0);
}

int	handle_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 0)
		mlx->key_a = 1;
	else if (keycode == 1)
		mlx->key_s = 1;
	else if (keycode == 13)
		mlx->key_w = 1;
	else if (keycode == 2)
		mlx->key_d = 1;
	else if (keycode == 53)
		cleanup_and_exit(mlx);
	else if (keycode == 123)
		mlx->key_left = 1;
	else if (keycode == 124)
		mlx->key_right = 1;
	return (0);
}

void	rotate_player_counterclockwise(t_mlx *mlx)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = mlx->player.dir_x;
	mlx->player.dir_x = mlx->player.dir_x * cos(0.05) - mlx->player.dir_y
		* sin(0.05);
	mlx->player.dir_y = olddir_x * sin(0.05) + mlx->player.dir_y * cos(0.05);
	oldplane_x = mlx->player.plane_x;
	mlx->player.plane_x = mlx->player.plane_x * cos(0.05) - mlx->player.plane_y
		* sin(0.05);
	mlx->player.plane_y = oldplane_x * sin(0.05) + mlx->player.plane_y
		* cos(0.05);
}

void	rotate_player_clockwise(t_mlx *mlx)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = mlx->player.dir_x;
	mlx->player.dir_x = mlx->player.dir_x * cos(-0.05) - mlx->player.dir_y
		* sin(-0.05);
	mlx->player.dir_y = olddir_x * sin(-0.05) + mlx->player.dir_y * cos(-0.05);
	oldplane_x = mlx->player.plane_x;
	mlx->player.plane_x = mlx->player.plane_x * cos(-0.05) - mlx->player.plane_y
		* sin(-0.05);
	mlx->player.plane_y = oldplane_x * sin(-0.05) + mlx->player.plane_y
		* cos(-0.05);
}
