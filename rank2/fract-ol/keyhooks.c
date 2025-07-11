/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 02:29:52 by mhashir           #+#    #+#             */
/*   Updated: 2024/07/06 04:18:07 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
		handler_esc(fractol);
	else if (keycode == 4)
	{
		fractol->is_locked = !fractol->is_locked;
	}
	else if (!fractol->is_locked)
	{
		if (keycode == 124 || keycode == 123)
			arrow_keys_parse(fractol, keycode);
		else if (keycode == 125 || keycode == 126)
			handle_key2(fractol, keycode);
		else if (keycode == 69 || keycode == 78)
			handle_key(fractol, keycode);
	}
	fractol_render(fractol);
	return (0);
}

void	arrow_keys_parse(t_fractol *fractol, int keycode)
{
	double	shift_amount;

	shift_amount = 0.5 * fractol->zoom;
	if (keycode == 124)
		fractol->shift_posx += shift_amount;
	else if (keycode == 123)
		fractol->shift_posx -= shift_amount;
}

void	handle_key2(t_fractol *fractol, int keycode)
{
	double	shift_amount;

	shift_amount = 0.5 * fractol->zoom;
	if (keycode == 125)
		fractol->shift_posy -= shift_amount;
	else if (keycode == 126)
		fractol->shift_posy += shift_amount;
}

void	handle_key(t_fractol *fractol, int keycode)
{
	int	iteration_change;

	iteration_change = 0;
	if (keycode == 69)
		iteration_change = 10;
	else if (keycode == 78)
		iteration_change = -10;
	fractol->iterations_defintion += iteration_change;
}
