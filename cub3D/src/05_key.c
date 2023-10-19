/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:56:47 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:33:44 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keys_ws(mlx_key_data_t keydata, t_main *cub)
{
	if (keydata.key == MLX_KEY_W)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			cub->key_w_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			cub->key_w_pressed = 0;
	}
	if (keydata.key == MLX_KEY_S)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			cub->key_s_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			cub->key_s_pressed = 0;
	}
}

void	keys_ad(mlx_key_data_t keydata, t_main *cub)
{
	if (keydata.key == MLX_KEY_A)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			cub->key_a_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			cub->key_a_pressed = 0;
	}
	if (keydata.key == MLX_KEY_D)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			cub->key_d_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			cub->key_d_pressed = 0;
	}
}

void	keys_left_right(mlx_key_data_t keydata, t_main *cub)
{
	if (keydata.key == MLX_KEY_LEFT)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			cub->key_left_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			cub->key_left_pressed = 0;
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			cub->key_right_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			cub->key_right_pressed = 0;
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_main	*cub;

	cub = (t_main *)param;
	keys_ws(keydata, param);
	keys_ad(keydata, param);
	keys_left_right(keydata, param);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(cub->mlx);
		free_cub(cub);
		exit(0);
	}
}
