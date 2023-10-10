/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_move_wsad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:16:19 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:32:50 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forwards(cub_main *cub)
{
	if (cub->map.data_i[(int)(cub->pos.x + cub->dir.x
			* cub->move_speed)][(int)(cub->pos.y)] == 0)
		cub->pos.x += cub->dir.x * cub->move_speed;
	if (cub->map.data_i[(int)(cub->pos.x)][(int)(cub->pos.y + cub->dir.y
			* cub->move_speed)] == 0)
		cub->pos.y += cub->dir.y * cub->move_speed;
}

void	move_backwards(cub_main *cub)
{
	if (cub->map.data_i[(int)(cub->pos.x - cub->dir.x
			* cub->move_speed)][(int)(cub->pos.y)] == 0)
		cub->pos.x -= cub->dir.x * cub->move_speed;
	if (cub->map.data_i[(int)(cub->pos.x)][(int)(cub->pos.y - cub->dir.y
			* cub->move_speed)] == 0)
		cub->pos.y -= cub->dir.y * cub->move_speed;
}

void	move_left(cub_main *cub)
{
	if (cub->map.data_i[(int)(cub->pos.x + -cub->dir.y
			* cub->move_speed)][(int)(cub->pos.y)] == 0)
		cub->pos.x += -cub->dir.y * cub->move_speed;
	if (cub->map.data_i[(int)(cub->pos.x)][(int)(cub->pos.y + cub->dir.x
			* cub->move_speed)] == 0)
		cub->pos.y += cub->dir.x * cub->move_speed;
}

void	move_right(cub_main *cub)
{
	if (cub->map.data_i[(int)(cub->pos.x + cub->dir.y
			* cub->move_speed)][(int)(cub->pos.y)] == 0)
		cub->pos.x += cub->dir.y * cub->move_speed;
	if (cub->map.data_i[(int)(cub->pos.x)][(int)(cub->pos.y + -cub->dir.x
		* cub->move_speed)] == 0)
		cub->pos.y += -cub->dir.x * cub->move_speed;
}

void	move_player(cub_main *cub)
{
	if (cub->key_w_pressed)
		move_forwards(cub);
	if (cub->key_s_pressed)
		move_backwards(cub);
	if (cub->key_a_pressed)
		move_left(cub);
	if (cub->key_d_pressed)
		move_right(cub);
	if (cub->key_left_pressed)
		rotate_left(cub);
	if (cub->key_right_pressed)
		rotate_right(cub);
}

/* 
//when the map int is 0 then move           not 1 or ' ' 
//move forward if no wall in front of you
void	move_forwards(cub_main *cub)
{
	if (cub->map.data_i[(int)(cub->pos.x + cub->dir.x
			* cub->move_speed)][(int)(cub->pos.y)] == 0)
		cub->pos.x += cub->dir.x * cub->move_speed;
	if (cub->map.data_i[(int)(cub->pos.x)][(int)(cub->pos.y + cub->dir.y
			* cub->move_speed)] == 0)
		cub->pos.y += cub->dir.y * cub->move_speed;

}

//move backwards if no wall behind you
void	move_backwards(cub_main *cub)
{
	if (cub->map.data_i[(int)(cub->pos.x - cub->dir.x
			* cub->move_speed)][(int)(cub->pos.y)] == 0)
		cub->pos.x -= cub->dir.x * cub->move_speed;
	if (cub->map.data_i[(int)(cub->pos.x)][(int)(cub->pos.y - cub->dir.y
			* cub->move_speed)] == 0)
		cub->pos.y -= cub->dir.y * cub->move_speed;
}

// move left if no wall on the left side
void	move_left(cub_main *cub)
{
	if (cub->map.data_i[(int)(cub->pos.x + -cub->dir.y
			* cub->move_speed)][(int)(cub->pos.y)] == 0)
		cub->pos.x += -cub->dir.y * cub->move_speed;
	if (cub->map.data_i[(int)(cub->pos.x)][(int)(cub->pos.y + cub->dir.x
			* cub->move_speed)] == 0)
		cub->pos.y += cub->dir.x * cub->move_speed;
}

// move right if no wall on the right side
void	move_right(cub_main *cub)
{
	if (cub->map.data_i[(int)(cub->pos.x + cub->dir.y
			* cub->move_speed)][(int)(cub->pos.y)] == 0)
		cub->pos.x += cub->dir.y * cub->move_speed;
	if (cub->map.data_i[(int)(cub->pos.x)][(int)(cub->pos.y + -cub->dir.x
		* cub->move_speed)] == 0)
		cub->pos.y += -cub->dir.x * cub->move_speed;
} 



// if (mouse_moved)
// 	rotate_mouse(m);
void	move_player(cub_main *cub)
{
	if (cub->key_w_pressed)
		move_forwards(cub);
	if (cub->key_s_pressed)
		move_backwards(cub);
	if (cub->key_a_pressed)
		move_left(cub);
	if (cub->key_d_pressed)
		move_right(cub);
	if (cub->key_left_pressed)
		rotate_left(cub);
	if (cub->key_right_pressed)
		rotate_right(cub);
} 
*/
