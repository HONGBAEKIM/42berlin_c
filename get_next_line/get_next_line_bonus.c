/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:45:31 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/05 12:45:31 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_save_all(int fd, char *static_buffer)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(static_buffer, '\n') && size)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(static_buffer);
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	free(buffer);
	return (static_buffer);
}

char	*oneline(char *static_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!static_buffer[i])
		return (NULL);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next_line(char *static_buffer)
{
	int		i;
	int		j;
	char	*nextline;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	nextline = malloc(sizeof(char) * (ft_strlen(static_buffer) - i + 1));
	if (!nextline)
		return (NULL);
	i++;
	j = 0;
	while (static_buffer[i])
		nextline[j++] = static_buffer[i++];
	nextline[j] = '\0';
	free(static_buffer);
	return (nextline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_buffer[4000096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_buffer[fd] = read_save_all(fd, static_buffer[fd]);
	if (!static_buffer[fd])
		return (NULL);
	line = oneline(static_buffer[fd]);
	static_buffer[fd] = next_line(static_buffer[fd]);
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int		linenumber;
	int		fd;

	linenumber = 1;
	fd = open("test.txt", O_RDONLY);
	while (linenumber < 5)
	{
		line = get_next_line(fd);
		printf("@line %d: %s", linenumber, line);
		linenumber++;
	}
	close(fd);
	return (0);
}*/
