/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:29:07 by hongbaki          #+#    #+#             */
/*   Updated: 2023/03/20 11:29:08 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img)
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	//mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_put_pixel(img, 11, 11, 0xFF0000FF);
	mlx_put_pixel(img, 12, 12, 0xFF0000FF);
	mlx_put_pixel(img, 13, 13, 0xFF0000FF);
	mlx_put_pixel(img, 14, 14, 0xFF0000FF);
	mlx_put_pixel(img, 15, 15, 0xFF0000FF);
	mlx_put_pixel(img, 16, 16, 0xFF0000FF);
	mlx_image_to_window(mlx, img, 0, 0);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}