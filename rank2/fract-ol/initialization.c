/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 02:28:41 by mhashir           #+#    #+#             */
/*   Updated: 2024/07/06 03:56:40 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractol *fractol)
{
	fractol->esc_button = 4;
	fractol->iterations_defintion = 42;
	fractol->shift_posx = 0.0;
	fractol->shift_posy = 0.0;
	fractol->zoom = 1.0;
}

void	events_init(t_fractol *fractolt_fractol)
{
	mlx_key_hook(fractolt_fractol->mlx_window, key_handler, fractolt_fractol);
	mlx_mouse_hook(fractolt_fractol->mlx_window, mouse_keyhook,
		fractolt_fractol);
	mlx_hook(fractolt_fractol->mlx_window, 17, 1L << 17, handler_esc,
		fractolt_fractol);
	mlx_hook(fractolt_fractol->mlx_window, 6, 1L << 6, julia_moves,
		fractolt_fractol);
}

void	fractal_init(t_fractol *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
	{
		malloc_error();
	}
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_image (fractal->mlx_connection, fractal->img.img_ptr);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.fract_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
