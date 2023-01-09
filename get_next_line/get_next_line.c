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
/*

#include "get_next_line.h"

/* char	*read_save_all(int fd, char *static_buffer)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(static_buffer, '\n') && size)
	{
		//read fd up to BUFFER_SIZE and save into buffer
		size = read(fd, buffer, BUFFER_SIZE);
		printf("1.size : %d\n", size);
		printf("1.buffer : %s\n", buffer);
		printf("1.static_buffer : %s\n", static_buffer);
		if (size == -1)
		{
			free(static_buffer); //I don't know why it is here actually
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0'; //added '\0' end of lines  
		static_buffer = ft_strjoin(static_buffer, buffer);
		printf("2.buffer : %s\n", buffer);
		printf("2.static_buffer : %s\n", static_buffer);
	}
	free(buffer);
	return (static_buffer);
}

char	*fixed_line(char *static_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!static_buffer[i])
		return (NULL);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	printf("4.i : %d\n", i);
	// why put number of 2 in (i + 2)
	// 1 for end of line '/0'     and another 1 for first '\0' of next line 
	line = (char *)malloc(sizeof(char) * (i + 2)); 
	if (!line)
		return (NULL);
	i = 0;
	printf("5.line : %s\n", line);
	printf("5.static_buffer : %s\n", static_buffer);
	// line == how\0
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	printf("6.i is : %d\n", i);
	printf("6.line : %s\n", line);
	printf("6.static_buffer : %s\n", static_buffer);
	// change line here
	// line == how\0 and nextline \0
	if (static_buffer[i] == '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	printf("7.i is : %d\n", i);
	printf("7.line : %s\n", line);
	printf("7.static_buffer : %s\n", static_buffer);
	// add '\0' in next line
	line[i] = '\0';
	printf("8.i is : %d\n", i);
	printf("8.line : %s\n", line);
	printf("8.static_buffer : %s\n", static_buffer);
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
	printf("10.i is : %d\n", i);
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	nextline = malloc(sizeof(char) * (ft_strlen(static_buffer) - i + 1));
	printf("10.nextline : %s\n", nextline);
	printf("10.static_buffer : %s\n", static_buffer);
	if (!nextline)
		return (NULL);
	i++;
	printf("11.i is : %d\n", i);
	j = 0;
	while (static_buffer[i])
		nextline[j++] = static_buffer[i++];
	printf("12.i is : %d\n", i);
	printf("12.j is : %d\n", j);
	printf("12.nextline : %s\n", nextline);
	printf("12.static_buffer : %s\n", static_buffer);
	nextline[j] = '\0';
	free(static_buffer);
	return (nextline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_buffer = read_save_all(fd, static_buffer);
	printf("3.static_buffer : %s\n", static_buffer);
	if (!static_buffer)
		return (NULL);
	line = fixed_line(static_buffer);
	printf("9.static_buffer : %s\n", static_buffer);
	static_buffer = next_line(static_buffer);
	printf("00.static_buffer : %s\n", static_buffer);
	return (line);
}

int	main(void)
{
	char	*line;
	int		linenumber;
	int		fd;

	linenumber = 1;
	fd = open("test.txt", O_RDONLY);
	while (linenumber < 3)
	{
		line = get_next_line(fd);
		printf("@line %d: %s", linenumber, line);
		linenumber++;
	}
	close(fd);
	return (0);
} */

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
	static char	*static_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_buffer = read_save_all(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	line = oneline(static_buffer);
	static_buffer = next_line(static_buffer);
	return (line);
}
