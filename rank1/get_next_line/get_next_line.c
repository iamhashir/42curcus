/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:23:35 by mhashir           #+#    #+#             */
/*   Updated: 2024/02/22 22:49:04 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buf, char **backup)
{
	char	*char_temp;
	int		read_line;

	read_line = 1;
	while (read_line != 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
		{
			free(*backup);
			*backup = NULL;
			return (0);
		}
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!*backup)
			*backup = ft_strdup("");
		char_temp = *backup;
		*backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (*backup);
}

char	*fetch_sub(char *line)
{
	char	*backup;
	size_t	count;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buf = (char *)malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = read_line(fd, buf, &backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = fetch_sub(line);
	return (line);
}
