/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:44:40 by mhashir           #+#    #+#             */
/*   Updated: 2024/02/21 02:16:46 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *buf, char **backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != '\0')
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

static char	*fetch_sub(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[0] == '\0')
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
	static char	*backup[1024];
	char		*line;
	char		*buf;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = read_line(fd, buf, &backup[fd]);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup[fd] = fetch_sub(line);
	return (line);
}
