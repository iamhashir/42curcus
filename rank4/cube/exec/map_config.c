/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:29:24 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 23:29:25 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_valid_identifier(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3)
		|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
		return (1);
	return (0);
}

int	process_map_textures(t_mlx *mlx, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
		return (parse_north_texture(mlx, str));
	else if (!ft_strncmp(str, "SO ", 3))
		return (parse_south_texture(mlx, str));
	else if (!ft_strncmp(str, "WE ", 3))
		return (parse_west_texture(mlx, str));
	else if (!ft_strncmp(str, "EA ", 3))
		return (parse_east_texture(mlx, str));
	return (0);
}

int	process_map_colors(t_mlx *mlx, char *str)
{
	if (!ft_strncmp(str, "F ", 2))
		return (set_floor_color(mlx, str));
	else if (!ft_strncmp(str, "C ", 2))
		return (set_ceiling_color(mlx, str));
	return (0);
}
