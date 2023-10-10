/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_move_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:58 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 11:41:35 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// for all functions below...
// both camera direction and camera plane must be rotated
void	rotate_left(cub_main *m)
{
	double	dir_x0;
	double	plane_x0;

	dir_x0 = m->dir.x;
	m->dir.x = m->dir.x * cos(m->rot_speed) - m->dir.y * sin(m->rot_speed);
	m->dir.y = dir_x0 * sin(m->rot_speed) + m->dir.y * cos(m->rot_speed);
	plane_x0 = m->plane.x;
	m->plane.x = m->plane.x * cos(m->rot_speed)
		- m->plane.y * sin(m->rot_speed);
	m->plane.y = plane_x0 * sin(m->rot_speed)
		+ m->plane.y * cos(m->rot_speed);
}

void	rotate_right(cub_main *m)
{
	double	dir_x0;
	double	plane_x0;

	dir_x0 = m->dir.x;
	m->dir.x = m->dir.x * cos(-m->rot_speed) - m->dir.y * sin(-m->rot_speed);
	m->dir.y = dir_x0 * sin(-m->rot_speed) + m->dir.y * cos(-m->rot_speed);
	plane_x0 = m->plane.x;
	m->plane.x = m->plane.x * cos(-m->rot_speed)
		- m->plane.y * sin(-m->rot_speed);
	m->plane.y = plane_x0 * sin(-m->rot_speed)
		+ m->plane.y * cos(-m->rot_speed);
}

