/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:55:21 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:20:58 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

int	get_texture_color(t_mlx *mlx, int texy)
{
	if (mlx->ray.raydir_y < 0)
	{
		if (mlx->ray.side == 1)
			return (mlx->img[EA].data[64 * texy + mlx->ray.tex_x]);
		else if (mlx->ray.raydir_x > 0)
			return (mlx->img[NO].data[64 * texy + mlx->ray.tex_x]);
		else
			return (mlx->img[SO].data[64 * texy + mlx->ray.tex_x]);
	}
	if (mlx->ray.raydir_y >= 0)
	{
		if (mlx->ray.side == 1)
			return (mlx->img[WE].data[64 * texy + mlx->ray.tex_x]);
		else if (mlx->ray.raydir_x > 0)
			return (mlx->img[NO].data[64 * texy + mlx->ray.tex_x]);
		else
			return (mlx->img[SO].data[64 * texy + mlx->ray.tex_x]);
	}
	return (0);
}

void	render_wall_column(t_mlx *mlx, int x, int assign_start, int assign_end)
{
	int		texy;
	int		y;
	int		color;
	double	tex_pos;
	int		line_height;

	line_height = (int)((double)HEIGHT / mlx->ray.perp_wall_dist);
	mlx->ray.wallx -= floor((mlx->ray.wallx));
	mlx->ray.tex_x = (int)(mlx->ray.wallx * (double)64);
	if (mlx->ray.side == 0 && mlx->ray.raydir_x > 0)
		mlx->ray.tex_x = 64 - mlx->ray.tex_x - 1;
	if (mlx->ray.side == 1 && mlx->ray.raydir_y < 0)
		mlx->ray.tex_x = 64 - mlx->ray.tex_x - 1;
	mlx->ray.step = 1.0 * 64 / line_height;
	tex_pos = (assign_start - (double)HEIGHT / 2 + (double)line_height / 2)
		* mlx->ray.step;
	y = assign_start;
	while (y < assign_end)
	{
		texy = (int)tex_pos & (64 - 1);
		tex_pos += mlx->ray.step;
		color = get_texture_color(mlx, texy);
		mlx->buf[y][x] = color;
		y++;
	}
}

int	convert_rgb_to_hex(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	draw_vertical_line(t_mlx *mlx, int assign_start, int assign_end, int x)
{
	int	y;

	if (mlx->ray.side == 0)
		mlx->ray.wallx = mlx->player.pos_y + mlx->ray.perp_wall_dist
			* mlx->ray.raydir_y;
	else
		mlx->ray.wallx = mlx->player.pos_x + mlx->ray.perp_wall_dist
			* mlx->ray.raydir_x;
	render_wall_column(mlx, x, assign_start, assign_end);
	if (assign_end < 0)
		assign_end = HEIGHT;
	y = assign_end + 1;
	while (y < HEIGHT)
	{
		mlx->buf[y][x] = convert_rgb_to_hex(mlx->map.floor_r, mlx->map.floor_g,
				mlx->map.floor_b);
		mlx->buf[HEIGHT - y - 1][x] = convert_rgb_to_hex(mlx->map.ceil_r,
				mlx->map.ceil_g, mlx->map.ceil_b);
		y++;
	}
}
