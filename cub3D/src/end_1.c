/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:14:39 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:29:09 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_c(t_map *map)
{
	int	i;

	i = 0;
	if (map->data_c)
	{
		while (i < map->nrows)
			free(map->data_c[i++]);
		free(map->data_c);
	}
}

void	free_map_i(t_map *map)
{
	int	i;

	i = 0;
	if (map->data_i != NULL)
	{
		while (i < map->nrows)
			free(map->data_i[i++]);
		free(map->data_i);
	}
}

void	ft_tex_paths(cub_main *cub)
{
	int	n;

	n = 0;
	while (n < NUM_TEXTURES)
	{
		if (cub->tex_paths[n])
			free(cub->tex_paths[n]);
		n++;
	}
}

void	free_cub(cub_main *cub)
{
	if ((cub->fd != -1))
		close(cub->fd);
	if (cub->texture_alloc == true)
		delete_textures(cub);
	if (cub->map.c_alloc == 1)
		free_map_c(&cub->map);
	if (cub->map.i_alloc == 1)
		free_map_i(&cub->map);
	if (cub->tex_paths_alloc == true)
		ft_tex_paths(cub);
}
