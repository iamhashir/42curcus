/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:02:12 by mhashir          #+#    #+#             */
/*   Updated: 2024/11/19 14:23:09 by mhashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	handle_player_movement(t_mlx *mlx)
{
	if (mlx->key_a)
		strafe_player_left(mlx);
	if (mlx->key_d)
		strafe_player_right(mlx);
	if (mlx->key_w)
		move_player_forward(mlx);
	if (mlx->key_s)
		move_player_backward(mlx);
	if (mlx->key_left)
		rotate_player_counterclockwise(mlx);
	if (mlx->key_right)
		rotate_player_clockwise(mlx);
}

void	update_display(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx->img[0].data[y * WIDTH + x] = mlx->buf[y][x];
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0].img_ptr, 0, 0);
}

void	execute_frame_actions(t_mlx *mlx)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		mlx->ray.camera_x = 2 * x / (double)(WIDTH) - 1;
		setup_ray_parameters(mlx);
		compute_ray_direction(mlx);
		perform_ray_casting(mlx);
		calculate_wall_dimensions(mlx, x);
		++x;
	}
}

int	start_game_loop(t_mlx *mlx)
{
	execute_frame_actions(mlx);
	update_display(mlx);
	handle_player_movement(mlx);
	return (0);
}
