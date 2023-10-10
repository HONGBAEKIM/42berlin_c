/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:08 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:44:21 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pt2d_d	calc_ray_dir(int x, t_pt2d_d raydr, t_pt2d_d dir, t_pt2d_d plane)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	camera_x = -camera_x;
	raydr.x = dir.x + plane.x * camera_x;
	raydr.y = dir.y + plane.y * camera_x;
	return (raydr);
}

t_pt2d_d	calc_delta_dist(t_pt2d_d delta_dist, t_pt2d_d raydr)
{
	if (raydr.x == 0)
		delta_dist.x = 1e30;
	else
		delta_dist.x = fabs(1 / raydr.x);
	if (raydr.y == 0)
		delta_dist.y = 1e30;
	else
		delta_dist.y = fabs(1 / raydr.y);
	return (delta_dist);
}

void	calc_step_and_side_dist(cub_main *cub)
{
	if (cub->raydr.x < 0)
	{
		cub->step.x = -1;
		cub->side_dist.x = (cub->pos.x - cub->map_pos.x) * cub->delta_dist.x;
	}
	else
	{
		cub->step.x = 1;
		cub->side_dist.x = (cub->map_pos.x + 1.0 - cub->pos.x) \
		* cub->delta_dist.x;
	}
	if (cub->raydr.y < 0)
	{
		cub->step.y = -1;
		cub->side_dist.y = (cub->pos.y - cub->map_pos.y) * cub->delta_dist.y;
	}
	else
	{
		cub->step.y = 1;
		cub->side_dist.y = (cub->map_pos.y + 1.0 - cub->pos.y) \
		* cub->delta_dist.y;
	}
}

void	handle_wall_hit(cub_main *cub, int side)
{
	cub->side = side;
	if (side == 0)
	{
		if (cub->step.x < 0)
			cub->wall_direction = TEXTURE_NO;
		else
			cub->wall_direction = TEXTURE_SO;
	}
	else
	{
		if (cub->step.y < 0)
			cub->wall_direction = TEXTURE_WE;
		else
			cub->wall_direction = TEXTURE_EA;
	}
}

void	perform_dda(cub_main *cub)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (cub->side_dist.x < cub->side_dist.y)
		{
			cub->side_dist.x += cub->delta_dist.x;
			cub->map_pos.x += cub->step.x;
			side = 0;
		}
		else
		{
			cub->side_dist.y += cub->delta_dist.y;
			cub->map_pos.y += cub->step.y;
			side = 1;
		}
		if (cub->map.data_i[cub->map_pos.x][cub->map_pos.y] > 0)
		{
			hit = 1;
			handle_wall_hit(cub, side);
		}
	}
}

/*
t_pt2d_d	calc_ray_dir(int x, t_pt2d_d raydr, t_pt2d_d dir, t_pt2d_d plane)
{
	double	camera_x;

	//Calculate camera_x based on the x-coordinate 
	//and the window width
	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	// Invert the camera_x value
	camera_x = -camera_x;
	// Calculate the components of the ray direction
	//printf("0.raydr.x : %f\n", raydr.x);
	
	raydr.x = dir.x + plane.x * camera_x;
	//printf("1.raydr.x : %f\n", raydr.x);
	raydr.y = dir.y + plane.y * camera_x;
	// Return the calculated ray direction
	return (raydr);
}

//it sets the corresponding delta distance 
//to a large value to avoid division by zero
t_pt2d_d	calc_delta_dist(t_pt2d_d delta_dist, t_pt2d_d raydr)
{
	// to avoid division by zero later in the code
	if (raydr.x == 0)
		delta_dist.x = 1e30;
	// calculating the distance along the x-axis 
	// based on the reciprocal of the x-component 
	// of the raydr vector
	else
		delta_dist.x = fabs(1 / raydr.x);
	if (raydr.y == 0)
		delta_dist.y = 1e30;
	else
		delta_dist.y = fabs(1 / raydr.y);
	return (delta_dist);
}

//calculate step and initial side_dist
void	calc_step_and_side_dist(cub_main *cub)
{
	//check ray direction of x is less than 0
	if (cub->raydr.x < 0)
	{
		cub->step.x = -1;
		// to know side distance,
		// check current player's position 
		// of the ray and grid(map) position.
		// side_dist is for the adjacent grid position 
		//on the positive x side
		cub->side_dist.x = (cub->pos.x - cub->map_pos.x) * cub->delta_dist.x;
	}
	else
	{
		cub->step.x = 1;
		cub->side_dist.x = (cub->map_pos.x + 1.0 - cub->pos.x) \
		* cub->delta_dist.x;
	}
	if (cub->raydr.y < 0)
	{
		cub->step.y = -1;
		cub->side_dist.y = (cub->pos.y - cub->map_pos.y) * cub->delta_dist.y;
	}
	else
	{
		cub->step.y = 1;
		cub->side_dist.y = (cub->map_pos.y + 1.0 - cub->pos.y) \
		* cub->delta_dist.y;
	}
}

void	handle_wall_hit(cub_main *cub, int side)
{
	cub->side = side;
	if (side == 0)
	{
		if (cub->step.x < 0)
			cub->wall_direction = TEXTURE_NO;
		else
			cub->wall_direction = TEXTURE_SO;
	}
	else
	{
		if (cub->step.y < 0)
			cub->wall_direction = TEXTURE_WE;
		else
			cub->wall_direction = TEXTURE_EA;
	}
}

//It calculates the intersection of a ray with walls 
//in the environment and determines which side 
//(horizontal or vertical) of the wall was hit
void	perform_dda(cub_main *cub)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (cub->side_dist.x < cub->side_dist.y)
		{
			cub->side_dist.x += cub->delta_dist.x;
			cub->map_pos.x += cub->step.x;
			side = 0;
		}
		else
		{
			cub->side_dist.y += cub->delta_dist.y;
			cub->map_pos.y += cub->step.y;
			side = 1;
		}
		if (cub->map.data_i[cub->map_pos.x][cub->map_pos.y] > 0)
		{
			hit = 1;
			handle_wall_hit(cub, side);
		}
	}
} */
