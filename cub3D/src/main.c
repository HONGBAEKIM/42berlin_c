/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:59:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/14 15:30:38 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


//static void	set_ray_pos(t_data *data, int x);

//void	my_mlx_resize_window(mlx_t *mlx, t_data *data, mlx_image_t *screen);

//void displayMap(char map[mapWidth][mapHeight], int x, int y, int width, int height);
// Exit the program as failure.
/* static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
} */



// Print the window width and height.


/* void	my_mlx_resize_window(mlx_t *mlx, t_data *data, mlx_image_t *screen)
{
	if (data->screen_width != mlx->width || \
		data->screen_height != mlx->height)
	{
		data->screen_width = mlx->width;
		data->screen_height = mlx->height;
		mlx_resize_image(screen, mlx->width, mlx->height);
	}
} */

/* static void	set_ray_pos(t_data *data, int x)
{
	data->camera_x = 2 * x (double)
} */



static void ft_hook(void* param)
{
	t_cub *cub = param;
	mlx_image_t	*img;
	//t_data	*data;

	
	cub->data.pos_x1 = cos(cub->data.pos_ang) * 5;
	cub->data.pos_y1 = sin(cub->data.pos_ang) * 5;
	

	img = cub->img;
	
	mlx_put_pixel(img, cub->data.pos_x0, cub->data.pos_y0, GREEN);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
	{

		cub->data.pos_ang -= 0.1;
		if (cub->data.pos_ang < 0)
			cub->data.pos_ang += 2*PI;
		clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
		displayMap(cub);
		//mlx_put_pixel(img, cub->data.pos_x, cub->data.pos_y, GREEN);
		draw_line(img, cub->data.pos_x0, cub->data.pos_y0, cub->data.pos_x0+(cub->data.pos_x1*80), cub->data.pos_y0+(cub->data.pos_y1*80), GREEN);
	}
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
	{

		cub->data.pos_ang += 0.1;
		if (cub->data.pos_ang > 2*PI)
			cub->data.pos_ang -= 2*PI;
		clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
		displayMap(cub);
		//mlx_put_pixel(img, cub->data.pos_x, cub->data.pos_y, GREEN);
		draw_line(img, cub->data.pos_x0, cub->data.pos_y0, cub->data.pos_x0+(cub->data.pos_x1*80), cub->data.pos_y0+(cub->data.pos_y1*80), GREEN);
	}
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
	{
		/* cub->data.pos_x = 150;
		cub->data.pos_y = 210; */
		(cub->data.pos_x0) += + cub->data.pos_x1;
		(cub->data.pos_y0) += + cub->data.pos_y1;
		clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
		displayMap(cub);
		//mlx_put_pixel(img, cub->data.pos_x0, cub->data.pos_y0, GREEN);
		draw_line(img, cub->data.pos_x0, cub->data.pos_y0 , cub->data.pos_x0+(cub->data.pos_x1*80), cub->data.pos_y0+(cub->data.pos_y1*80) , GREEN);
	}
	else if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
	{
		/* cub->data.pos_x = 150;
		cub->data.pos_y = 210; */
		(cub->data.pos_x0) -= cub->data.pos_x1;
		(cub->data.pos_y0) -= cub->data.pos_y1;
		clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
		displayMap(cub);
		//mlx_put_pixel(img, cub->data.pos_x0, cub->data.pos_y0, GREEN);
		draw_line(img, cub->data.pos_x0, cub->data.pos_y0 , cub->data.pos_x0+(cub->data.pos_x1*80), cub->data.pos_y0+(cub->data.pos_y1*80) , GREEN);
	}
}


/* static void ft_raycasting_hook(void* param)
{
	t_cub *cub = param;
	mlx_image_t	*img;
	//mlx_t *mlx;
	

	img = cub->img;
	int	i = 0;

	//my_mlx_resize_window(cub->mlx, &cub->data, cub->);
	displayMap(cub);
	// clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
	while (i < WIDTH)
	{
		// clear_image(cub->img, WIDTH, HEIGHT, 0x000000);
		//set_ray_pos();
		i++;
	}	
} */

int32_t	main(void)
{
	t_cub	*cub;
	mlx_image_t	*img;
/* 	cub->data.pos_x0 = 150;
	cub->data.pos_y0 = 210;
	cub->data.pos_ang = 0.0; */

	
	cub = cub_init(WIDTH, HEIGHT, "Cub");
	
	
	// MLX allows you to define its core behaviour before startup.w
	mlx_set_setting(MLX_MAXIMIZED, true);


	displayMap(cub);


	img = cub->img;
	// Even after the image is being displayed, we can still modify the buffer.

	mlx_image_to_window(cub->mlx, cub->img, 0, 0);
	
	
	//mlx_put_pixel(img, cub->data.pos_x1, cub->data.pos_y1, GREEN);

	
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	
	//mlx_loop_hook(cub->mlx, ft_raycasting_hook, cub);
	mlx_loop_hook(cub->mlx, ft_hook, cub);

	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
	return (EXIT_SUCCESS);
}