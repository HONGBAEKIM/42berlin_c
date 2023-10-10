/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:41:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:32:24 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_image(cub_main *cub)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx_put_pixel(cub->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}
