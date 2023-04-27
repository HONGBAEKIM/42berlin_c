/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:36:22 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/27 10:36:23 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif


int	ft_strlen(char *str)
{
	int	i = 0;
	
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i = 0;
	
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i = -1;
	int	j = 0;
	char	*str;
	
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}



char	*read_save_all(int fd, char *static_buffer)
{
	char	*buffer;
	int	size = 1;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
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
	int	i = 0;
	char	*line;
	
	if (!static_buffer[i])
		return (NULL);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
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

char	*nextline(char *static_buffer)
{
	int	i = 0;
	int	j = 0;
	char	*nextline;
	
	
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	nextline = malloc(sizeof(char) * BUFFER_SIZE);
	if (!nextline)
		return (NULL);
	i++;
	while (static_buffer[i])
		nextline[j++] = static_buffer[i++];
	nextline[j] = '\0';
	//nextline[i] = '\0';
	free(static_buffer);
	return (nextline);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buffer = read_save_all(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	line = oneline(static_buffer);
	static_buffer = nextline(static_buffer);
	return (line);
}

/*
#include <stdio.h>

int	main()
{
	char	*line;
	int	fd;
	int	ln = 1;

	fd = open("test.txt", O_RDONLY);
	while (ln < 10)
	{
		line = get_next_line(fd);
		printf("@line %d : %s", ln, line);
		free(line);
		ln++;
	}	
	close(fd);
	return (0);
}*/
