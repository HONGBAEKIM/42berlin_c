/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:59:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:05:00 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	cub_main	cub;

	check_map_command(argc, argv);
	init_cub(argc, argv, &cub);
	if (ft_surround_check(&cub))
		ft_error(ERR_MAP_WALLS, &cub);
	if (argc == 3 && !ft_strcmp(argv[2], "test"))
		exit(0);
	init_window(&cub);
	mlx_key_hook(cub.mlx, &keyhook, &cub);
	mlx_close_hook(cub.mlx, &closehook, &cub);
	mlx_loop_hook(cub.mlx, ft_raycast, &cub);
	mlx_loop(cub.mlx);
	mlx_terminate(cub.mlx);
	free_cub(&cub);
	return (0);
}

/* 
// read map
// check all the wall 
// one with int, one with char
// error handling
// argc == 3 to check input everytime.

// understand how raycast works
// 2D -> 3d racating is math part


// 
 */