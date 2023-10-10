/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:43:10 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:37:44 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceiling(cub_main *cub, int x)
{
	int	y;

	y = 0;
	while (y < cub->draw_start)
	{
		mlx_put_pixel(cub->img, x, y, cub->ceiling_color);
		y++;
	}
	y = cub->draw_end;
	while (y < WIN_HEIGHT)
	{
		mlx_put_pixel(cub->img, x, y, cub->floor_color);
		y++;
	}
}

void	draw_tex3(cub_main *cub, int x, int tex_x)
{
	double		step;
	double		tex_pos;
	int			y;
	u_int8_t	*pixel;
	int			tex_y;

	step = 1.0 * cub->textures[cub->wall_direction]->height / cub->line_height;
	tex_pos = 
		(cub->draw_start - cub->pitch - WIN_HEIGHT / 2 \
		+ cub->line_height / 2) * step;
	y = cub->draw_start;
	while (y < cub->draw_end)
	{
		tex_y = (int)tex_pos & (cub->textures[cub->wall_direction]->height - 1);
		tex_pos += step;
		pixel = &cub->textures[cub->wall_direction]->pixels[(tex_x + tex_y
				* cub->textures[cub->wall_direction]->width)
			* cub->textures[cub->wall_direction]->bytes_per_pixel];
		mlx_put_pixel(cub->img, x, y,
			pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
		y++;
	}
}

void	draw_tex2(cub_main *cub, int x)
{
	double	wall_x;
	int		tex_x;

	if (cub->side == 0)
		wall_x = cub->pos.y + cub->perp_wall_dist * cub->raydr.y;
	else
		wall_x = cub->pos.x + cub->perp_wall_dist * cub->raydr.x;
	wall_x -= floor((wall_x));
	tex_x = (wall_x * cub->textures[cub->wall_direction]->width);
	if (cub->side == 0 && cub->raydr.x > 0)
		tex_x = cub->textures[cub->wall_direction]->width - tex_x - 1;
	if (cub->side == 1 && cub->raydr.y < 0)
		tex_x = cub->textures[cub->wall_direction]->width - tex_x - 1;
	draw_tex3(cub, x, tex_x);
}

void	draw_tex(cub_main *cub, int x)
{
	cub->draw_start = 0;
	cub->draw_end = 0;
	cub->line_height = WIN_HEIGHT / cub->perp_wall_dist;
	cub->draw_start = -cub->line_height / 2 + WIN_HEIGHT / 2 + cub->pitch;
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	cub->draw_end = cub->line_height / 2 + WIN_HEIGHT / 2 + cub->pitch;
	if (cub->draw_end >= WIN_HEIGHT || cub->draw_end < 0)
		cub->draw_end = WIN_HEIGHT - 1;
	draw_floor_ceiling(cub, x);
	draw_tex2(cub, x);
}

/*
void	draw_floor_ceiling(cub_main *cub, int x)
{
	int	y;

	y = 0;
	while (y < cub->draw_start)
	{
		mlx_put_pixel(cub->img, x, y, cub->ceiling_color);
		y++;
	}
	y = cub->draw_end;
	while (y < WIN_HEIGHT)
	{
		mlx_put_pixel(cub->img, x, y, cub->floor_color);
		y++;
	}
}

void	draw_tex3(cub_main *cub, int x, int tex_x)
{
	double		step;
	double		tex_pos;
	int			y;
	u_int8_t	*pixel;
	int			tex_y;

	step = 1.0 * cub->textures[cub->wall_direction]->height / cub->line_height;
	tex_pos = (cub->draw_start - cub->pitch - WIN_HEIGHT / 2 + cub->line_height / 2)
		* step;
	y = cub->draw_start;
	while (y < cub->draw_end)
	{
		tex_y = (int)tex_pos & (cub->textures[cub->wall_direction]->height - 1);
		tex_pos += step;
		pixel = &cub->textures[cub->wall_direction]->pixels[(tex_x + tex_y
				* cub->textures[cub->wall_direction]->width)
			* cub->textures[cub->wall_direction]->bytes_per_pixel];
		mlx_put_pixel(cub->img, x, y,
			pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
		y++;
	}
}

///start from draw_tex2.c
void	draw_tex2(cub_main *cub, int x)
{
	double	wall_x;
	int		tex_x;

	if (cub->side == 0)
		wall_x = cub->pos.y + cub->perp_wall_dist * cub->raydr.y;
	else
		wall_x = cub->pos.x + cub->perp_wall_dist * cub->raydr.x;
	wall_x -= floor((wall_x));
	tex_x = (wall_x * cub->textures[cub->wall_direction]->width);
	if (cub->side == 0 && cub->raydr.x > 0)
		tex_x = cub->textures[cub->wall_direction]->width - tex_x - 1;
	if (cub->side == 1 && cub->raydr.y < 0)
		tex_x = cub->textures[cub->wall_direction]->width - tex_x - 1;
	draw_tex3(cub, x, tex_x);
}

// Calculate height of line to draw on screen
// check for 'cub->draw_end < 0' protects against...
// ...it going negative when outer wall reached
void	draw_tex(cub_main *cub, int x)
{
	cub->draw_start = 0;
	cub->draw_end = 0;
	cub->line_height = WIN_HEIGHT / cub->perp_wall_dist;
	//cub->draw_start from floor line
	//cub->draw_end is celling line
	//cub->pitch calculating the vertical position of the wall slice on the screen
	cub->draw_start = -cub->line_height / 2 + WIN_HEIGHT / 2 + cub->pitch;
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	cub->draw_end = cub->line_height / 2 + WIN_HEIGHT / 2 + cub->pitch;
	if (cub->draw_end >= WIN_HEIGHT || cub->draw_end < 0)
		cub->draw_end = WIN_HEIGHT - 1;
	draw_floor_ceiling(cub, x);
	draw_tex2(cub, x);
} */
