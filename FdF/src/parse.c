/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:20:22 by hongbaki          #+#    #+#             */
/*   Updated: 2023/03/29 22:20:24 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	get_color(t_fdf *fdf, char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == ',')
			return (ft_atoi_base(&str[i + 3], 16) * 256 + 0xff);
		i++;
	}
	return (fdf->line_rgb);
}

static void	fill_points(t_fdf *fdf, char **array, t_map *map)
{
	unsigned int	i;
	float			height;

	i = 0;
	map->cols = 0;
	while (array[i])
	{
		if (array[i][0] != '\n')
		{
			height = ft_at oi(array[i]);
			if (height > map->highest)
				map->highest = height;
			if (height < map->lowest)
				map->lowest = height;
			if (!map->point)
				map->point = pt_new(height, get_color(fdf, array[i]));
			else
				pt_add_back(map->point, \
					pt_new(height, get_color(fdf, array[i])));
			map->cols++;
		}
		i++;
	}
}

static void	get_points(t_fdf *fdf, int fd, t_map *map)
{
	char	*line;
	char	**array;
	t_point	*new_point;

	new_point = NULL;
	line = get_next_line(fd);
	while (line)
	{
		array = ft_split(line, ' ');
		map->rows++;
		fill_points(fdf, array, map);
		free(line);
		free_array(array);
		line = get_next_line(fd);
	}
}

t_map	*parse(t_fdf *fdf, int fd)
{
	t_map	*map;
	float	x_spacing;
	float	y_spacing;

	map = map_new();
	get_points(fdf, fd, map);
	x_spacing = WIDTH / (float)((map->cols + map->rows));
	y_spacing = (HEIGHT - map->highest + map->lowest)
		/ (float)((map->cols + map->rows + 2));
	map->spacing = floor(y_spacing);
	map->x_start = round(map->spacing * map->rows);
	map->y_start = round(map->spacing + map->highest);
	return (map);
}

/* 
static unsigned int	get_color(t_fdf *fdf, char *str)
{
	size_t	i;

	i = 0;
	
	while (i < ft_strlen(str))
	{
		if (str[i] == ',')
		{
			//printf("num : %u\n", ft_atoi_base(&str[i + 3], 16) * 256  + 255);
			 
			ex)  elem-col.fdf
			
			ft_atoi_base(&str[i + 3], 16) 
			
						  (R)(B)(G)	
			&str[i + 3] =  FF0000
						= (Red)    FF(255) * (256)^2 = 16711680
						  (Green)  00(  0) * (256)^1 = 0
						  (Blue)   00(  0) * (256)^0 = 0
			
			and add FF at the last position

			 				FF0000FF
							with (*256 +255)

			
			return (ft_atoi_base(&str[i + 3], 16) * 256 + 255);
		}
		i++;
	}
	return (fdf->line_rgb);
}

static void	fill_points(t_fdf *fdf, char **array, t_map *map)
{
	unsigned int	i;
	float			height;

	i = 0;
	map->cols = 0;
	while (array[i])
	{
		if (array[i][0] != '\n')
		{
			height = ft_atoi(array[i]);
			if (height > map->highest)
				map->highest = height;
			if (height < map->lowest)
				map->lowest = height;
			if (!map->point)
				map->point = pt_new(height, get_color(fdf, array[i]));
			else
				pt_add_back(map->point, pt_new(height, get_color(fdf, array[i])));		
			map->cols++;
		}
		i++;
	}
}

static void	get_points(t_fdf *fdf, int fd, t_map *map)
{
	char	*line;
	char	**array;
	t_point	*new_point;

	//line = NULL;
	new_point = NULL;
	line = get_next_line(fd);
	//printf("0line : %s\n",line);
	while (line)
	{
		//printf("1line : %s\n",line);
		array = ft_split(line, ' ');
		map->rows++;
		fill_points(fdf, array, map);
		free(line);
		free_array(array);
		//line = NULL;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	//if (!line)
	//	stop(ERR_FD); 
}

t_map	*parse(t_fdf *fdf, int fd)
{
	t_map	*map;
	float	x_spacing;
	float	y_spacing;


	map = map_new();
	get_points(fdf, fd, map);
	x_spacing = WIDTH / (float)((map->cols + map->rows));
	printf("map->cols : %d\n",map->cols);
	printf("map->rows : %d\n",map->rows);
	printf("x_spacing : %f\n",x_spacing);
	y_spacing = (HEIGHT - map->highest + map->lowest)
		/ (float)((map->rows + map->cols + 2));
	printf("y_spacing : %f\n",y_spacing);

	if (x_spacing > y_spacing)
	{
		map->spacing = floor(y_spacing);
		printf("map->spacing : %f\n",map->spacing);
	}
	else
	{
		map->spacing = floor(x_spacing);
		printf("map->spacing : %f\n",map->spacing);
	}
	map->x_start = round(map->spacing * map->rows);
	printf("map->x_start : %f\n",map->x_start);
	map->y_start = round(map->spacing + map->highest);
	printf("map->y_start : %f\n",map->y_start);
	return (map);
}



The floor() function 
ex1) 3.67 -> 3.00
ex2) 3.50 -> 3.00
ex3) 3.32 -> 3.00

The round() function 
ex1) 3.67 -> 4.00
ex2) 3.50 -> 4.00
ex3) 3.32 -> 3.00

*/
