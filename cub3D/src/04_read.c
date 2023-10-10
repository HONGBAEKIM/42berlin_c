/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:06:20 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:34:00 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(cub_main *cub)
{
	int	i;
	int	fd;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		fd = open(cub->tex_paths[i], O_RDONLY);
		if (fd == -1)
			ft_error(ERR_TEX_PATH, cub);
		close(fd);
		cub->textures[i] = mlx_load_png(cub->tex_paths[i]);
		i++;
	}
	cub->texture_alloc = true;
}

void	read_subject_file(char **argv, cub_main *cub)
{
	int	i;

	cub->filename = argv[1];
	cub->total_chars_read = 0; 
	cub->fd = open(cub->filename, O_RDONLY);
	if (cub->fd == -1)
		ft_error(ERR_FILE, cub);
	init_fileflags(cub);
	i = 0;
	while (i++ < 6)
		read_prefixes(cub);
	while (cub->char_read == '\n')
		read_char(cub);
	get_map_dims(cub);
	fill_map(cub);
	get_player_position(cub);
	convert_map_data_c_to_i(cub);
	load_textures(cub);
}
