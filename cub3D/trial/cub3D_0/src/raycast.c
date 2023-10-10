/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:34:28 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/28 11:43:48 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// camera_x = x-coordinate in camera space
void	calc_ray_dir(t_data *data, int x)
{
	//double	camera_x;

	data->camera_x = 2 * x / (double)WIDTH - 1;
	data->camera_x = -data->camera_x;
	data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
	data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
	
	
	
	
	//I should put all data from t_cub to t_data





	data->map_pos_x = (int) data->pos_x0;
	data->map_pos_y = (int) data->pos_y0;
	//return (raydr);
}

void	calc_delta_dist(t_data *data)
{
	if (data->raydir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1 / data->raydir_x);
	if (data->raydir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->raydir_y);
	//return (data->delta_dist);
}

//calculate step and initial side_dist
void	calc_step_and_side_dist(t_cub *cub)
{
	if (cub->data.raydir_x < 0)
	{
		cub->data.step_x = -1;
		cub->data.side_dist_x = (cub->data.pos_x0 - cub->data.map_pos_x) * cub->data.delta_dist_x;
	}
	else
	{
		cub->data.step_x = 1;
		cub->data.side_dist_x = (cub->data.map_pos_x + 1.0 - cub->data.pos_x0) * cub->data.delta_dist_x;
	}
	if (cub->data.raydir_y < 0)
	{
		cub->data.step_y = -1;
		cub->data.side_dist_y = (cub->data.pos_y0 - cub->data.map_pos_y) * cub->data.delta_dist_y;
	}
	else
	{
		cub->data.step_y = 1;
		cub->data.side_dist_y = (cub->data.map_pos_y + 1.0 - cub->data.pos_y0) * cub->data.delta_dist_y;
	}
}

void	handle_wall_hit(t_cub *cub, int side)
{
	cub->side = side;
	if (side == 0)
	{
		if (cub->data.step_x < 0)
			cub->wall_direction = NO_TEXTURE;
		else
			cub->wall_direction = SO_TEXTURE;
	}
	else
	{
		if (cub->data.step_y < 0)
			cub->wall_direction = WE_TEXTURE;
		else
			cub->wall_direction = EA_TEXTURE;
	}
}


void	perform_dda(t_cub *cub)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (cub->data.side_dist_x < cub->data.side_dist_y)
		{
			cub->data.side_dist_x += cub->data.delta_dist_x;
			cub->data.map_pos_x += cub->data.step_x;
			side = 0;
		}
		else
		{
			cub->data.side_dist_y += cub->data.delta_dist_y;
			cub->data.map_pos_y += cub->data.step_y;
			side = 1;
		}
		if (cub->map.data_i[cub->data.map_pos_x][cub->data.map_pos_y] > 0)
		{
			hit = 1;
			handle_wall_hit(cub, side);
		}
	}
}


void	raycast(void *param)
{
	t_cub	*cub;
	int	x;
	
	printf("%s\n", "5.raycast.0");
	cub = param;
	printf("%s\n", "5.raycast.1");

	
	move(cub);
	printf("%s\n", "5.raycast.2");

	x = 0;
	printf("%s\n", "5.raycast.3");

	while (x < WIDTH)
	{
		printf("%s\n", "5.raycast.4");
		calc_ray_dir(&cub->data, x);
		printf("%s\n", "5.raycast.5");
		draw_texture(cub, x);
		printf("%s\n", "5.raycast.6");
		x++;
	}
}