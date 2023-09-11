/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:59:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/11 16:42:05 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


t_fdf	*fdf_init(int32_t width, int32_t height, char *name);
// static void ft_error(void);
//void	translate(t_fdf *fdf, char xy, int amount);
static void ft_hook(void* param);
void clear_image(mlx_image_t *img, int32_t width, int32_t height, int32_t bg_color);
// t_fdf	*cub3D_init(int32_t width, int32_t height, char *name);
// t_map	*map_new(void);
// t_point	*next_row_pt(t_point *pt, int cols);
// void	draw(t_fdf *fdf, t_map *map);
// void	translate(t_fdf *fdf, char xy, int amount);
// static void	draw_reset(t_fdf *fdf);
// void ft_hook(void *param);
// static void	set_coords(t_fdf *fdf, t_point *pt, int x, int y);
// static void	drawline(mlx_image_t *img, t_coord *c0, t_coord *c1, uint32_t rgb);
// void	lh_init(t_linehelper *lh, t_coord *c0, t_coord *c1);


t_fdf	*fdf_init(int32_t width, int32_t height, char *name)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init(width, height, name, true);
	if (!fdf->mlx)
		return (NULL);
	fdf->img = mlx_new_image(fdf->mlx, width, height);
	if (!fdf->img)
		return (NULL);
	fdf->map = NULL;
	fdf->rgb = SILVER;
	fdf->line_rgb = BLACK;
	return (fdf);
}

// Exit the program as failure.
/* static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
} */


/* void	translate(t_fdf *fdf, char xy, int amount)
{
	if (xy == 'x')
	{
		fdf->map->x_start += amount;
		draw(fdf, fdf->map);
	}
	else if (xy == 'y')
	{
		fdf->map->y_start += amount;
		draw(fdf, fdf->map);
	}
} */


/* void	translate(t_fdf *fdf, char xy, int amount)
{
	if (xy == 'x')
	{
		fdf->map->x_start += amount;
		//draw(fdf, fdf->map);
	}
	else if (xy == 'y')
	{
		fdf->map->y_start += amount;
		//draw(fdf, fdf->map);
	}
} */

void clear_image(mlx_image_t *img, int32_t width, int32_t height, int32_t bg_color)
{
    int32_t x;
    int32_t y;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            mlx_put_pixel(img, x, y, bg_color);
            x++;
        }
        y++;
    }
}


// Print the window width and height.
static void ft_hook(void* param)
{
	t_fdf *fdf = param;
	mlx_image_t	*img;

	img = fdf->img;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
	{
		greenDotY -= 10;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		mlx_put_pixel(img, greenDotX, greenDotY, GREEN);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
	{
		greenDotY += 10;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		mlx_put_pixel(img, greenDotX, greenDotY, GREEN);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
	{
		greenDotX -= 10;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		mlx_put_pixel(img, greenDotX, greenDotY, GREEN);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
	{
		greenDotX += 10;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		mlx_put_pixel(img, greenDotX, greenDotY, GREEN);
	}
	
	//mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	//printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}


int32_t	main(void)
{
	t_fdf	*fdf;
	mlx_image_t	*img;
	
	fdf = fdf_init(WIDTH, HEIGHT, "FdF");
	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	/* fdf->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fdf->mlx)
		ft_error(); */


	// Create and display the image.
	/* fdf->img = mlx_new_image(mlx, 256, 256);
	if (!img)
		ft_error(); */

	// Even after the image is being displayed, we can still modify the buffer.
	//mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	img = fdf->img;
	mlx_put_pixel(img, 200, 200, GREEN);
	// mlx_put_pixel(img, 12, 12, 0xFF0000FF);
	// mlx_put_pixel(img, 13, 13, 0xFF0000FF);
	// mlx_put_pixel(img, 14, 14, 0xFF0000FF);
	// mlx_put_pixel(img, 15, 15, 0xFF0000FF);
	// mlx_put_pixel(img, 16, 16, 0xFF0000FF);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(fdf->mlx, ft_hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (EXIT_SUCCESS);
}