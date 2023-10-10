/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:43:10 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/14 21:23:55 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



//Bresenham's algorithm
//
void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1) 
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1) 
	{		

		mlx_put_pixel(img, x0, y0, GREEN);
        if (x0 == x1 && y0 == y1) 
		{
            break;
        }
        e2 = err;
        if (e2 > -dx) 
		{
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy) 
		{
            err += dx;
            y0 += sy;
        }

/* 		int	hit = 0;
		while (hit == 0)
		{
			if ()
			{

			}	
			else
			{
				
			}
			if ()
				hit == 1;
		} */
    }
}
