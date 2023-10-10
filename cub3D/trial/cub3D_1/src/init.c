/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:37:45 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/28 15:17:05 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


static void set_data(t_cub *cub)
{
	cub->data.pos_x0 = 150; //later I should put function where player starts
	cub->data.pos_y0 = 210; //later I should put function where player starts
	cub->data.pos_ang = 0.0;
}

void	cub_init(int ac, char **av, t_cub *cub)
{
	mlx_image_t	*img;

	
	cub = (t_cub *)malloc(sizeof(t_cub));
	if (!cub)
		return (NULL);
	set_data(cub);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "name", true);
	if (!cub->mlx)
		return (NULL);
	// Create and display the image.
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->img)
		return (NULL);
	img = cub->img;
	if (mlx_image_to_window(cub->mlx, cub->img, 0, 0) < 0)
		return (NULL);
	//img = cub->img;
	//cub->map = NULL;
	// cub->rgb = SILVER;
	// cub->line_rgb = BLACK;
}

