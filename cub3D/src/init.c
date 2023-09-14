/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:37:45 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/14 16:05:21 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


static void set_data(t_cub *cub)
{
	cub->data.pos_x0 = 150;
	cub->data.pos_y0 = 210;
	cub->data.pos_ang = 0.0;
}

t_cub	*cub_init(int32_t width, int32_t height, char *name)
{
	t_cub	*cub;
	

	
	cub = (t_cub *)malloc(sizeof(t_cub));
	if (!cub)
		return (NULL);
	set_data(cub);
	cub->mlx = mlx_init(width, height, name, true);
	if (!cub->mlx)
		return (NULL);
	// Create and display the image.
	cub->img = mlx_new_image(cub->mlx, width, height);
	if (!cub->img)
		return (NULL);
	//cub->map = NULL;
	// cub->rgb = SILVER;
	// cub->line_rgb = BLACK;
	return (cub);
}

