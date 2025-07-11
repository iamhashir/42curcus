/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_keyhooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:40:25 by mhashir          #+#    #+#             */
/*   Updated: 2024/07/06 03:53:47 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <ApplicationServices/ApplicationServices.h>

int	handler_esc(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	mouse_keyhook(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == 5)
	{
		fractol->zoom *= 1.05;
	}
	fractol_render(fractol);
	return (0);
}

int	julia_moves(int x, int y, t_fractol *fractol)
{
	t_mappingrange	range_x;
	t_mappingrange	range_y;

	if (!ft_strncmp(fractol->name, "julia", 5) && !fractol->is_locked)
	{
		range_x.n_min = -2;
		range_x.n_max = +2;
		range_x.o_min = 0;
		range_x.o_max = WIDTH;
		fractol->julia_posx = map(x, range_x) * fractol->zoom;
		range_y.n_min = +2;
		range_y.n_max = -2;
		range_y.o_min = 0;
		range_y.o_max = HEIGHT;
		fractol->julia_posy = map(y, range_y) * fractol->zoom;
		fractol_render(fractol);
	}
	return (0);
}
