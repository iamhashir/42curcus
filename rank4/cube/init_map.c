/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:21:55 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 23:11:00 by mhashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

int	verify_map_format(t_mlx *mlx, char **strs)
{
	if (allocate_map_memory(mlx, strs))
	{
		ft_putstr_fd("Error\n Failed to initialize map.\n", 2);
		return (1);
	}
	if (validate_map_structure(mlx))
	{
		ft_putstr_fd("Error\n Map is not in correct format.\n", 2);
		return (1);
	}
	return (0);
}

int	check_map_elements_complete(t_mlx *mlx)
{
	if (mlx->map.composition_of_north && mlx->map.composition_of_south
		&& mlx->map.composition_of_west && mlx->map.composition_of_east
		&& mlx->map.color_of_floor && mlx->map.color_of_ceiling)
		return (1);
	return (0);
}

int	process_map_elements(t_mlx *mlx, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
	{
		if (parse_north_texture(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "SO ", 3))
	{
		if (parse_south_texture(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "WE ", 3))
	{
		if (parse_west_texture(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "EA ", 3))
	{
		if (parse_east_texture(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "F ", 2))
	{
		if (set_floor_color(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "C ", 2))
	{
		if (set_ceiling_color(mlx, str))
			return (1);
	}
	return (0);
}

int	is_valid_identifier(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3)
		|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
		return (1);
	return (0);
}

int	setup_map_configuration(t_mlx *mlx, char **strs, int i)
{
	if (is_valid_identifier(&(*strs)[i]))
	{
		if (process_map_elements(mlx, &(*strs)[i]))
			return (1);
	}
	else if (is_map_valid(*strs) && check_map_elements_complete(mlx))
	{
		if (verify_map_format(mlx, strs))
			return (1);
		return (2);
	}
	else
	{
		ft_putstr_fd("Error\n Invalid characters in the map "
			"or fields are missing\n", 2);
		return (1);
	}
	return (0);
}
