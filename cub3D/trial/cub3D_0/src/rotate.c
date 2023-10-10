/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:28:02 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/27 15:13:28 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void rotate_left(t_cub *cub)
{
	cub->data.pos_ang -= 0.1;
	if (cub->data.pos_ang < 0)
		cub->data.pos_ang += 2*PI;
	clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
	displayMap(cub);
	draw_line(cub->img, cub->data.pos_x0, cub->data.pos_y0, \
	cub->data.pos_x0+(cub->data.pos_x1*80), \
	cub->data.pos_y0+(cub->data.pos_y1*80));
}

void rotate_right(t_cub *cub)
{
	cub->data.pos_ang += 0.1;
	if (cub->data.pos_ang > 2*PI)
		cub->data.pos_ang -= 2*PI;
	clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
	displayMap(cub);
	draw_line(cub->img, cub->data.pos_x0, cub->data.pos_y0, \
	cub->data.pos_x0+(cub->data.pos_x1*80), \
	cub->data.pos_y0+(cub->data.pos_y1*80));
}
