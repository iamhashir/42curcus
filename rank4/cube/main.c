/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:33:40 by mhashir          #+#    #+#             */
/*   Updated: 2025/07/28 04:24:43 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initiate_structure(t_mlx *mlx)
{
	mlx->map.map = NULL;
	mlx->map.s_comp = NULL;
	mlx->map.n_comp = NULL;
	mlx->map.w_comp = NULL;
	mlx->map.e_comp = NULL;
	mlx->map.composition_of_west = 0;
	mlx->map.composition_of_east = 0;
	mlx->map.composition_of_south = 0;
	mlx->map.composition_of_north = 0;
	mlx->map.color_of_ceiling = 0;
	mlx->map.color_of_floor = 0;
}

void	keys_initiate(t_mlx *mlx)
{
	mlx->key_a = 0;
	mlx->key_d = 0;
	mlx->key_s = 0;
	mlx->key_w = 0;
	mlx->key_left = 0;
	mlx->key_right = 0;
}

int	mlx_initiate(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (1);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Cub3D");
	if (mlx->win == NULL){
		// mlx_destroy_window(mlx->mlx, mlx->win);
		return(1);
	}
	mlx->img[0].img_ptr = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img[0].data = (int *)mlx_get_data_addr(mlx->img[0].img_ptr,
			&mlx->img[0].bpp, &mlx->img[0].size_l, &mlx->img[0].endian);
	mlx_loop_hook(mlx->mlx, start_game_loop, mlx);
	mlx_hook(mlx->win, 2, 0, handle_key_press, mlx);
	mlx_hook(mlx->win, 3, 0, handle_key_release, mlx);
	mlx_hook(mlx->win, 17, 0, cleanup_and_exit, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

int	load_and_process_map(t_mlx *mlx, char *file_name)
{
	char	**x;

	x = parse_map_file(file_name);  // Changed from read_map_file
	if (parsing(mlx, x))
	{
		free_split(x);
		return (1);
	}
	free_split(x);
	if (map_validity_check(mlx))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		initiate_structure(&mlx);
		if (load_and_process_map(&mlx, argv[1]))
		{
			free_map(&mlx);
			return (1);
		}
		initialize_game_view(&mlx);  // Changed from init_player_direction
		keys_initiate(&mlx);
		if (mlx_initiate(&mlx))
		{
			ft_putstr_fd("Error\nFailed to init mlx.\n", 2);
			return (1);
		}
	}
	else
	{
		ft_putstr_fd("Error\nInvalid arguments\nUsage ./cub3d map.cub\n", 2);
		return (1);
	}
	return (0);
}
