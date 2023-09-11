/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:29:07 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/11 15:03:58 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	stop(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(EXIT_FAILURE);
}

static void	color_hook(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_0))
		change_color(fdf, BLACK);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		change_color(fdf, WHITE);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		change_color(fdf, RED);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_3))
		change_color(fdf, BLUE);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_4))
		change_color(fdf, SILVER);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_5))
		change_color(fdf, GREEN);
}

static void	hook(void *param)
{
	t_fdf		*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(fdf->mlx);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		translate(fdf, 'y', -50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		translate(fdf, 'y', 50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		translate(fdf, 'x', -50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		translate(fdf, 'x', 50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
		zoom(fdf, 1);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
		zoom(fdf, -1);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_UP))
		change_height(fdf, 1.1, 1);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_DOWN))
		change_height(fdf, 1.1, 0);
	color_hook(fdf);
}

static void	fdf(char *file_name)
{
	t_fdf		*fdf;
	mlx_image_t	*img;
	int			fd;

	fdf = fdf_init(WIDTH, HEIGHT, "FdF");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		stop(ERR_FD);
	fdf->map = parse(fdf, fd);
	close(fd);
	if (!fdf || !fdf->map)
		stop(ERR_INIT);
	img = fdf->img;
	draw(fdf, fdf->map);
	
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	mlx_loop_hook(fdf->mlx, &hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	exit(EXIT_SUCCESS);
	
}

int32_t	main(int argc, char *argv[])
{
	errno = 0;
	if (argc == 2)
	{
		if (check_fdfnull(argv[1], "fdf\0"))
			fdf(argv[1]);
		else
			stop(ERR_FILE_EXTENSION);
	}
	else
		stop(ERR_FILE);
	return (EXIT_SUCCESS);
}
