/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:15:20 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:38:20 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycast(void *param)
{
	t_main	*cub;
	int		x;

	cub = (t_main *)param;
	move_player(cub);
	clear_image(cub);
	x = 0;
	while (x < WIN_WIDTH)
	{
		cub->raydr = calc_ray_dir(x, cub->raydr, cub->dir, cub->plane);
		cub->map_pos.x = cub->pos.x;
		cub->map_pos.y = cub->pos.y;
		cub->delta_dist = calc_delta_dist(cub->delta_dist, cub->raydr);
		calc_step_and_side_dist(cub);
		perform_dda(cub);
		if (cub->side == 0)
			cub->perp_wall_dist = cub->side_dist.x - cub->delta_dist.x;
		else
			cub->perp_wall_dist = cub->side_dist.y - cub->delta_dist.y;
		draw_tex(cub, x);
		x++;
	}
}

/* 
// in while loop:
// calculate ray position and direction
// length of ray from current position to next x or y-side
void	ft_raycast(void *param)
{
	t_main	*cub;
	int		x;

	cub = (t_main *)param;
	move_player(cub);
	clear_image(cub);
	x = 0;
	while (x < WIN_WIDTH)
	{
		cub->raydr = calc_ray_dir(x, cub->raydr, cub->dir, cub->plane);
		cub->map_pos.x = cub->pos.x;
		cub->map_pos.y = cub->pos.y;
		cub->delta_dist = calc_delta_dist(cub->delta_dist, cub->raydr);
		calc_step_and_side_dist(cub);
		perform_dda(cub);
		//keep track of which side of the wall the ray hits: 
		//either the horizontal side (0) or the vertical side (1)
		if (cub->side == 0)
			cub->perp_wall_dist = cub->side_dist.x - cub->delta_dist.x;
			//store the perpendicular distance from the player's current position 
			//to the nearest wall that the ray has intersected.
		else
			cub->perp_wall_dist = cub->side_dist.y - cub->delta_dist.y;
		draw_tex(cub, x);
		x++;
	}
} 
*/
