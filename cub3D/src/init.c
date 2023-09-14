/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:37:45 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/14 12:16:47 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_cub	*cub_init(int32_t width, int32_t height, char *name)
{
	t_cub	*cub;
	

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (!cub)
		return (NULL);
	cub->mlx = mlx_init(width, height, name, true);
	if (!cub->mlx)
		return (NULL);
	// Create and display the image.
	cub->img = mlx_new_image(cub->mlx, width, height);
	if (!cub->img)
		return (NULL);
	//cub->map = NULL;
	cub->rgb = SILVER;
	cub->line_rgb = BLACK;
	return (cub);
}
