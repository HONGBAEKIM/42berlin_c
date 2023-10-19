/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:48:59 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 11:40:14 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_main *cub)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	cub->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Raycaster", false);
	if (!cub->mlx)
		ft_error(ERR_MLX_WIN, cub);
	cub->img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cub->img)
		ft_error(ERR_MLX_IMG, cub);
	if ((mlx_image_to_window(cub->mlx, cub->img, 0, 0) < 0))
		ft_error(ERR_MLX_IMGWIN, cub);
}
