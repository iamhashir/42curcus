/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:21:28 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:21:29 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

int	display_error(char *str, char *fd)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	i = 0;
	while (fd[i])
	{
		write(1, &fd[i], 1);
		i++;
	}
	return (i);
}

int	validate_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		exit(display_error("Error\n could not open file ", filename));
	}
	if (check_cub_extension(filename) == 1)
	{
		close(fd);
		exit(display_error("Error\n could not read file without .cub ",
				filename));
	}
	return (fd);
}

int	validate_map_content(char *map)
{
	if (!map)
	{
		ft_putstr_fd("Error\n Failed to read map.\n", 2);
		return (1);
	}
	if (analyze_newlines(map))
	{
		free(map);
		ft_putstr_fd("Error\n Map has newline.\n", 2);
		return (1);
	}
	return (0);
}

char	*load_map_data(int fd)
{
	char	*str;
	char	buffer[42];
	int		bytes;
	char	*temp;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	bytes = read(fd, buffer, 41);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		temp = ft_strjoin(str, buffer);
		free(str);
		if (!temp)
			return (NULL);
		str = temp;
		bytes = read(fd, buffer, 41);
	}
	if (bytes == -1)
		return (free(str), NULL);
	return (str);
}

char	**parse_map_file(char *filename)
{
	int		fd;
	char	*total;
	char	**x;

	fd = validate_map_file(filename);
	total = load_map_data(fd);
	if (!total)
	{
		display_error("Error\n reading map", filename);
		close(fd);
		return (NULL);
	}
	if (validate_map_content(total))
	{
		close(fd);
		display_error("Map checking failed\n", filename);
		exit(1);
	}
	x = ft_split(total, '\n');
	free(total);
	close(fd);
	if (x == NULL)
		return (display_error("Error splitting map\n", filename), NULL);
	return (x);
}
