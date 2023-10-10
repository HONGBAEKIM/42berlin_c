/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:37:45 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:09:03 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(int argc, char **argv, cub_main *cub)
{
	cub->map.data_c = 0;
	cub->map.data_i = 0;
	cub->texture_alloc = 0;
	cub->tex_paths_alloc = 0;
	cub->map.c_alloc = 0;
	cub->map.i_alloc = 0;
	cub->dir.x = 0;
	cub->dir.y = 0;
	read_subject_file(argv, cub);
	if (argc == 3 && !ft_strcmp(argv[2], "test"))
		print_cub_file_summary(cub);
	cub->move_speed = SQRS_PER_SEC / 100; 
	cub->rot_speed = RADS_PER_SEC / 100;
	cub->pitch = 100;
	cub->key_w_pressed = 0;
	cub->key_s_pressed = 0;
	cub->key_a_pressed = 0;
	cub->key_d_pressed = 0;
	cub->key_left_pressed = 0;
	cub->key_right_pressed = 0;
}

void	init_fileflags(cub_main *cub)
{
	cub->fileflags.no = 0;
	cub->fileflags.so = 0;
	cub->fileflags.we = 0;
	cub->fileflags.ea = 0;
	cub->fileflags.f = 0;
	cub->fileflags.c = 0;
}

/* void	init_cub(t_cub *cub, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_putstr("Error\n");
	cub = (t_cub *)malloc(sizeof(t_cub));
	if (!cub)
		return (NULL);
	set_data(cub);
	cub->mlx = mlx_init(width, height, name, true);
	if (!cub->mlx)
		return (NULL);
	// Create and display the image.
	cub->img = mlx_new_image(cub->mlx, width, height);
	if (!cub->img)
		return (NULL);
	//cub->map = NULL;
	// cub->rgb = SILVER;
	// cub->line_rgb = BLACK;
	return (cub);
} */
