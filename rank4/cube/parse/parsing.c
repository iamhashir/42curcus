/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:33:57 by mhashir          #+#    #+#             */
/*   Updated: 2025/07/26 05:46:59 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_cub_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len >= 4 && ft_strncmp(filename + len - 4, ".cub", 4) == 0)
		return (0);
	else
		return (1);
}

int	parsing(t_mlx *mlx, char **strs)
{
	int	i;
	int	check;

	while (*strs)
	{
		i = 0;
		while ((*strs)[i] == ' ' && !is_map_valid(*strs))
			i++;
		check = setup_map_configuration(mlx, strs, i);
		if (check == 2)
			break ;
		else if (check == 1)
			return (1);
		strs++;
	}
	return (0);
}

int	is_map_valid(char *str)
{
	int	i;
	int	check;

	i = 0;
	while (str[i] == ' ')
		++i;
	check = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'N' && str[i] != 'W'
			&& str[i] != 'E' && str[i] != 'S' && str[i] != ' ')
			return (0);
		check = 1;
		++i;
	} 
	if (str[i] == '\n' && !check)
		return (0);
	if (!str[i] && !check)
		return (0);
	return (1);
}

int	handle_newline(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == ' ')
		++i;
	while (str[i] && str[i] != '\n')
		++i;
	if (str[i] == '\n')
		++i;
	while (str[i] == '\n')
	{
		++count;
		++i;
	}
	if (count > 0 && is_map_valid(&str[i]))
		return (1);
	return (0);
}

int	analyze_newlines(char *map)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	while (map[i])
	{
		if (is_map_valid(&map[i]) && !valid)
			valid = 1;
		if (handle_newline(&map[i]) && valid)
			return (1);
		while (map[i] != '\n' && map[i])
			++i;
		if (map[i])
			++i;
	}
	return (0);
}
