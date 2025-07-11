/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 02:28:50 by mhashir           #+#    #+#             */
/*   Updated: 2024/07/06 04:08:12 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_parse(t_fractol *fractal, char **av)
{
	if (av[2] == NULL || av[3] == NULL)
	{
		ft_putstr_fd("Please provide both Julia parameters.\n", STDERR_FILENO);
		return (0);
	}
	if (!julia_valid_check(av[2]) || !julia_valid_check(av[3]))
	{
		ft_putstr_fd("Invalid Julia parameters",
			STDERR_FILENO);
		return (0);
	}
	fractal->julia_posx = ft_atodbl(av[2]);
	fractal->julia_posy = ft_atodbl(av[3]);
	if (fractal->julia_posx < -2 || fractal->julia_posx > 2
		|| fractal->julia_posy < -2
		|| fractal->julia_posy > 2)
	{
		ft_putstr_fd("Julia parameters should be between -2 and 2.\n",
			STDERR_FILENO);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		fractol_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else if (4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		if (!julia_parse(&fractal, av))
		{
			exit(EXIT_FAILURE);
		}
		fractal_init(&fractal);
		fractol_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
