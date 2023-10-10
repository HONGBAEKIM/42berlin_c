/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:21:57 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/28 11:43:17 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void move_w(t_cub *cub)
{
	(cub->data.pos_x0) += cub->data.pos_x1;
	(cub->data.pos_y0) += cub->data.pos_y1;
	clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
	displayMap(cub);
	draw_line(cub->img, cub->data.pos_x0, cub->data.pos_y0 , \
	cub->data.pos_x0+(cub->data.pos_x1*80), \
	cub->data.pos_y0+(cub->data.pos_y1*80));
}

void move_s(t_cub *cub)
{
	(cub->data.pos_x0) -= cub->data.pos_x1;
	(cub->data.pos_y0) -= cub->data.pos_y1;
	clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
	displayMap(cub);
	draw_line(cub->img, cub->data.pos_x0, cub->data.pos_y0 , \
	cub->data.pos_x0+(cub->data.pos_x1*80), \
	cub->data.pos_y0+(cub->data.pos_y1*80));
}

void move_a(t_cub *cub)
{

	(cub->data.pos_x0) += cub->data.pos_y1;
	(cub->data.pos_y0) -= cub->data.pos_x1;
	clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
	displayMap(cub);
	draw_line(cub->img, cub->data.pos_x0, cub->data.pos_y0 , \
	cub->data.pos_x0+(cub->data.pos_x1*80), \
	cub->data.pos_y0+(cub->data.pos_y1*80));
}


void move_d(t_cub *cub)
{

	(cub->data.pos_x0) -= cub->data.pos_y1;
	(cub->data.pos_y0) += cub->data.pos_x1;
	clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
	displayMap(cub);
	draw_line(cub->img, cub->data.pos_x0, cub->data.pos_y0 , \
	cub->data.pos_x0+(cub->data.pos_x1*80), \
	cub->data.pos_y0+(cub->data.pos_y1*80));
}



void move(t_cub *cub)
{
	printf("%s\n", "5.raycast.2.move.0");
	cub->data.pos_x1 = cos(cub->data.pos_ang) * 5;
	printf("%s\n", "5.raycast.2.move.1");

	cub->data.pos_y1 = sin(cub->data.pos_ang) * 5;
	printf("%s\n", "5.raycast.2.move.2");

	
	
	mlx_put_pixel(cub->img, cub->data.pos_x0, cub->data.pos_y0, GREEN);
	printf("%s\n", "5.raycast.2.move.3");
	
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
	{
		rotate_left(cub);
	}
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
	{
		rotate_right(cub);
	}
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
	{
		move_w(cub);
	}
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
	{
		move_s(cub);	
	}
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
	{
		move_a(cub);	
	}
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
	{
		move_d(cub);	
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
	{
		mlx_terminate(cub->mlx);
		exit (EXIT_SUCCESS);
	}
}
