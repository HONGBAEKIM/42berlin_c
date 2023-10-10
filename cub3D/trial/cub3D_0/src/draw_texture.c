/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:24:29 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/28 13:41:49 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_floor_ceiling(t_cub *cub, int x)
{
	int	y;

	y = 0;
	while (y < cub->draw_start)
	{
		mlx_put_pixel(cub->img, x, y, cub->ceiling_color);
		y++;
	}
	y = cub->draw_end;
	while (y < HEIGHT)
	{
		mlx_put_pixel(cub->img, x, y, cub->floor_color);
		y++;
	}
}

void	draw_texture3(t_cub *cub, int x, int tex_x)
{
	double		step;
	double		tex_pos;
	int			y;
	u_int8_t	*pixel;
	int			tex_y;

	printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.8.draw_texture3.0");
	// How much to increase the texture coordinate per screen pixel

	//
	cub->textures[cub->wall_direction]->height = 0;
	printf("cub->line_height : %d\n", cub->line_height);
	
	printf("cub->textures[cub->wall_direction]->height : %d\n", cub->textures[cub->wall_direction]->height);


	step = 1.0 * cub->textures[cub->wall_direction]->height / cub->line_height;
	printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.8.draw_texture3.1");
	
	// Starting texture coordinate
	tex_pos = (cub->draw_start - cub->pitch - HEIGHT / 2 + cub->line_height / 2)
		* step;
	printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.8.draw_texture3.2");
	
	y = cub->draw_start;
	printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.8.draw_texture3.3");

	while (y < cub->draw_end)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		tex_y = (int)tex_pos & (cub->textures[cub->wall_direction]->height - 1);
		tex_pos += step;
		pixel = &cub->textures[cub->wall_direction]->pixels[(tex_x + tex_y
				* cub->textures[cub->wall_direction]->width)
			* cub->textures[cub->wall_direction]->bytes_per_pixel];
		mlx_put_pixel(cub->img, x, y,
			pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
		y++;
	}
	printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.8.draw_texture3.4");

}

void	draw_texture2(t_cub *cub, int x)
{
	double	wall_x; //where exactly the wall was hit
	int		tex_x;

	//calculate value of wallX
	printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.0");
	if (cub->side == 0)
	{
		printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.1");
		wall_x = cub->data.pos_y0 + cub->data.perp_wall_dist * cub->data.raydir_y;
	}
	else
	{
		printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.2");
		wall_x = cub->data.pos_x0 + cub->data.perp_wall_dist * cub->data.raydir_x;
	}
	printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.3");

	wall_x -= floor((wall_x));
	printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.4");

	//x coordinate on the texture
	
	
	
	
	printf("wall_x : %f\n", wall_x);
	printf("cub->textures[cub->wall_direction]->width : %f\n", wall_x);

	//tex_x = (int)(wall_x * cub->textures[cub->wall_direction]->width);
	tex_x = 0;
	printf("tex_x : %d\n", tex_x);

	
	printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.5");

	if (cub->side == 0 && cub->data.raydir_x > 0)
	{
		printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.6");
		tex_x = cub->textures[cub->wall_direction]->width - tex_x - 1;
	}
	if (cub->side == 1 && cub->data.raydir_y < 0)
	{
		printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.7");
		tex_x = cub->textures[cub->wall_direction]->width - tex_x - 1;
	}
	printf("%s\n", "5.raycast.6.draw_texture.11.draw_texture2.8");

	draw_texture3(cub, x, tex_x);



}

void	draw_texture(t_cub *cub, int x)
{
	printf("%s\n", "5.raycast.6.draw_texture.0");
	cub->draw_start = 0;
	printf("%s\n", "5.raycast.6.draw_texture.1");

	cub->draw_end = 0;
	printf("%s\n", "5.raycast.6.draw_texture.2");

	//Calculate height of line to draw on screen
    cub->line_height = (int)(WIDTH / cub->data.perp_wall_dist);
	printf("%s\n", "5.raycast.6.draw_texture.3");

	//calculate lowest and highest pixel to fill in current stripe
	//cub->draw_start = -cub->line_height / 2 + HEIGHT / 2;
	cub->draw_start = -cub->line_height / 2 + HEIGHT / 2 + cub->pitch;
	printf("%s\n", "5.raycast.6.draw_texture.4");

	if (cub->draw_start < 0)
	{
		printf("%s\n", "5.raycast.6.draw_texture.5");
		cub->draw_start = 0;
	}
	
	//cub->draw_end = m->line_height / 2 + HEIGHT / 2;
	printf("%s\n", "5.raycast.6.draw_texture.6");

	cub->draw_end = cub->line_height / 2 + HEIGHT / 2 + cub->pitch;
	printf("%s\n", "5.raycast.6.draw_texture.7");

	if (cub->draw_end >= HEIGHT || cub->draw_end < 0)
	{
		printf("%s\n", "5.raycast.6.draw_texture.8");
		cub->draw_end = HEIGHT - 1;
	}
	printf("%s\n", "5.raycast.6.draw_texture.9");
	
	draw_floor_ceiling(cub, x);
	printf("%s\n", "5.raycast.6.draw_texture.10");

	draw_texture2(cub, x);


}