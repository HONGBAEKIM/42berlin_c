/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:14:23 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 11:55:11 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str, cub_main *cub)
{
	write(2, "Error\n", 6);
	write(2, str, (int)ft_strlen(str));
	if (cub)
		free_cub(cub);
	exit(EXIT_FAILURE);
}

void	delete_textures(cub_main *cub)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		mlx_delete_texture(cub->textures[i]);
		i++;
	}
}

void	closehook(void *param)
{
	cub_main	*cub;

	cub = (cub_main *)param;
	mlx_terminate(cub->mlx);
	free_cub(cub);
	exit(EXIT_FAILURE);
}
