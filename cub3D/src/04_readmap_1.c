/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_readmap_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:58:29 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:35:49 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map_characters(cub_main *cub, char *onechar)
{
	int	read_check;

	while (1)
	{
		read_check = read(cub->fd, onechar, 1);
		if (read_check <= 0)
			break ;
		if (cub->char_read != '0' && cub->char_read != '1'
			&& cub->char_read != 'N' && cub->char_read != 'E'
			&& cub->char_read != 'S' && cub->char_read != 'W'
			&& cub->char_read != ' ' && cub->char_read != '\n')
			ft_error(ERR_INVALID_MAP_CHAR, cub);
		if (cub->char_read == '\n')
		{
			if (cub->map.ncols > cub->map.longest_ncols)
				cub->map.longest_ncols = cub->map.ncols;
			cub->map.ncols = 0;
			cub->map.nrows++;
		}
		else
			cub->map.ncols++;
		cub->char_read = *onechar;
	}
}

void	get_map_dims(cub_main *cub)
{
	char	onechar;

	cub->map.longest_ncols = 0;
	cub->map.nrows = 0;
	cub->map.ncols = 0;
	read_map_characters(cub, &onechar);
	cub->map.nrows++;
	if (cub->map.ncols > cub->map.longest_ncols)
		cub->map.longest_ncols = cub->map.ncols;
	cub->map.ncols = cub->map.longest_ncols;
	cub->map.data_c = 0;
}

void	process_row(cub_main *cub, int row)
{
	int		col;
	bool	detectingendoftheline;
	char	onechar;

	detectingendoftheline = 0;
	col = 0;
	while (col < cub->map.ncols)
	{
		if (detectingendoftheline == 0)
		{
			if (read(cub->fd, &onechar, 1) == 0)
				detectingendoftheline = 1;
			if (col == 0 && onechar == '\n')
				read(cub->fd, &onechar, 1);
			if (col > 0 && onechar == '\n')
				detectingendoftheline = 1;
		}
		if (detectingendoftheline == 0)
			cub->map.data_c[row][col] = onechar;
		if (detectingendoftheline == 1)
			cub->map.data_c[row][col] = ' ';
		col++;
	}
}

static void	malloc_map_c(cub_main *cub)
{
	int		i;
	t_map	*map;

	map = &cub->map;
	map->data_c = (char **)malloc(map->nrows * sizeof(char *) + sizeof(char *));
	if (!map->data_c)
		ft_error(ERR_MEM_ROWPTR, cub);
	map->data_c[map->nrows] = 0;
	map->c_alloc = 1;
	i = 0;
	while (i < map->nrows)
	{
		map->data_c[i] = (char *)malloc(map->ncols * sizeof(char) + 1);
		if (!map->data_c[i])
			ft_error(ERR_MEM_ROW, cub);
		map->data_c[i][map->ncols] = '\0';
		i++;
	}
}

void	fill_map(cub_main *cub)
{
	char	onechar;
	int		i;
	int		row;

	malloc_map_c(cub);
	close(cub->fd);
	cub->fd = open(cub->filename, O_RDONLY);
	if (cub->fd == -1)
		ft_error(ERR_FILE, cub);
	i = 0;
	while (i < cub->total_chars_read - 1)
	{
		read(cub->fd, &onechar, 1);
		i++;
	}
	row = 0;
	while (row < cub->map.nrows)
		process_row(cub, row++);
	close(cub->fd);
}

/* void	read_map_characters(cub_main *cub, char *onechar)
{
	int read_check;
	
	while (1)
	{
		read_check = read(cub->fd, onechar, 1);
		//if there is nothing more to read, from file descriptor
		//the function will exit
		if (read_check <= 0)
			break ;
		if (cub->char_read != '0' && cub->char_read != '1'
			&& cub->char_read != 'N' && cub->char_read != 'E'
			&& cub->char_read != 'S' && cub->char_read != 'W'
			&& cub->char_read != ' ' && cub->char_read != '\n')
			ft_error(ERR_INVALID_MAP_CHAR, cub);
		if (cub->char_read == '\n')
		{
			if (cub->map.ncols > cub->map.longest_ncols)
				cub->map.longest_ncols = cub->map.ncols;
			cub->map.ncols = 0;
			cub->map.nrows++;
		}
		else
			cub->map.ncols++;
		cub->char_read = *onechar;
	}
}



void	get_map_dims(cub_main *cub)
{
	char	onechar;
	//char	onechar[1];
	//int		longest_ncols;

	cub->map.longest_ncols = 0;
	cub->map.nrows = 0;
	cub->map.ncols = 0;
	read_map_characters(cub, &onechar);
	cub->map.nrows++;
	if (cub->map.ncols > cub->map.longest_ncols)
		cub->map.longest_ncols = cub->map.ncols;
	// printf("cub->map.longest_ncols : %d\n",cub->map.longest_ncols);
	// printf("cub->map.ncols : %d\n",cub->map.ncols);
	// printf("cub->map.nrows : %d\n",cub->map.nrows);
	


	cub->map.ncols = cub->map.longest_ncols;
	
	cub->map.data_c = 0;
}

// 'read' re-reads the file
// 'while (i < m->total_chars_read - 1)' seeks to start of map
void	process_row(cub_main *cub, int row)
{
	int		col;
	bool	detectingendoftheline;
	char	onechar;


	detectingendoftheline = 0;
	col = 0;
	while (col < cub->map.ncols)
	{
		if (detectingendoftheline == 0)
		{
			//when read == 0
			if (read(cub->fd, &onechar, 1) == 0)
				detectingendoftheline = 1;
			//first letter of the line and just \n line then read next
			if (col == 0 && onechar == '\n')
				read(cub->fd, &onechar, 1);
			//end of the lined\n", read(cub->fd, &onechar, 1));
			if (col > 0 && onechar == '\n')
				detectingendoftheline = 1;
		}
		//here save   from all the char info   to the map.cata_c one by one
		if (detectingendoftheline == 0)
			cub->map.data_c[row][col] = onechar;
		if (detectingendoftheline == 1)
			cub->map.data_c[row][col] = ' ';
		col++;
	}
}

static void	malloc_map_c(cub_main *cub)
{
	int		i;
	t_map	*map;

	map = &cub->map;
	// printf("0.cub->map.nrows %d\n", cub->map.nrows);
	// printf("0.cub->map.ncols %d\n", cub->map.ncols);


	// + sizeof(char *)    
	// it allocate enough memory to hold the additional pointers
	map->data_c = (char **)malloc(map->nrows * sizeof(char *) + sizeof(char *));
	if (!map->data_c)
		ft_error(ERR_MEM_ROWPTR, cub);
	map->data_c[map->nrows] = 0;
	map->c_alloc = 1;
	i = 0;
	while (i < map->nrows)
	{
		map->data_c[i] = (char *)malloc(map->ncols * sizeof(char) + 1);
		if (!map->data_c[i])
			ft_error(ERR_MEM_ROW, cub);
		//printf("0.map->data_c %s\n", *map->data_c);
		map->data_c[i][map->ncols] = '\0';
		i++;
	}
	
}

//initializing and filling the map data structure.
void	fill_map(cub_main *cub)
{
	
	//char	onechar[1];
	char	onechar;
	int		i;
	int		row;

	malloc_map_c(cub);
 	close(cub->fd);
	cub->fd = open(cub->filename, O_RDONLY);
	if (cub->fd == -1)
		ft_error(ERR_FILE, cub);
	i = 0;
	while (i < cub->total_chars_read - 1)
	{
		read(cub->fd, &onechar, 1);
		//printf("read(cub->fd, &onechar, 1) : %zd\n", read(cub->fd, &onechar, 1));
		i++;
	}
	row = 0;
	while (row < cub->map.nrows)
		process_row(cub, row++);
	close(cub->fd);
} */
