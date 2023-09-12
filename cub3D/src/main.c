/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:59:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/12 17:11:13 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


t_fdf	*fdf_init(int32_t width, int32_t height, char *name);
void clear_image(mlx_image_t *img, int32_t width, int32_t height, int32_t bg_color);

void mlx_fill_square(mlx_image_t *img, int x, int y, int size, int color);
void displayMap(t_fdf *fdf);
void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color);
static void ft_hook(void* param);

//void displayMap(char map[mapWidth][mapHeight], int x, int y, int width, int height);
// Exit the program as failure.
/* static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
} */

t_fdf	*fdf_init(int32_t width, int32_t height, char *name)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init(width, height, name, true);
	if (!fdf->mlx)
		return (NULL);
	// Create and display the image.
	fdf->img = mlx_new_image(fdf->mlx, width, height);
	if (!fdf->img)
		return (NULL);
	//fdf->map = NULL;
	fdf->rgb = SILVER;
	fdf->line_rgb = BLACK;
	return (fdf);
}

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

char cub3dMap[mapWidth][mapHeight] = 
{
    {'1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '1'},
    {'1', '1', '0', '0', 'N', '1'},
    {'1', '1', '1', '1', '1', '1'}
};


void mlx_fill_square(mlx_image_t *img, int x, int y, int size, int color)
{
    int end_x = x + size - 1;
    int end_y = y + size - 1;

    while (y < end_y)
    {
        int current_x = x;
        while (current_x < end_x)
        {
            mlx_put_pixel(img, current_x, y, color);
            current_x++;
        }
        y++;
    }
}

void displayMap(t_fdf *fdf) 
{
    int x = 0, y = 0;
    int block_size = 100; // Adjust the size of each map block

    while (y < mapHeight) 
	{
        x = 0;
        while (x < mapWidth) 
		{
            int color = 0;

            // Define colors for different map elements (customize as needed)
            if (cub3dMap[x][y] == '1')
                color = WHITE; // Wall
            else if (cub3dMap[x][y] == '0')
                color = BLACK; // Empty space
            else if (cub3dMap[x][y] == 'N')
                color = RED; // Player position

            // Draw a block at (x, y) with the specified color
            mlx_fill_square(fdf->img, x * block_size, y * block_size, block_size, color);
            x++;
        }
        y++;
    }
}

//Bresenham's algorithm
void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color) 
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1) 
	{
        mlx_put_pixel(img, x0, y0, color);

        if (x0 == x1 && y0 == y1) {
            break;
        }

        e2 = err;

        if (e2 > -dx) {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dy) {
            err += dx;
            y0 += sy;
        }
    }
}

#include <math.h>
#define PI 3.1415926535
double pa = 0.0;
int	py = 210;
int	px = 150;

// Print the window width and height.
static void ft_hook(void* param)
{
	t_fdf *fdf = param;
	mlx_image_t	*img;
	
	int	pdx = cos(pa) * 5;
	int	pdy = sin(pa) * 5;

	img = fdf->img;
	
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
	{
		// px -= 10;
		pa -= 0.1;
		if (pa < 0)
			pa += 2*PI;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		displayMap(fdf);
		mlx_put_pixel(img, px, py, GREEN);
		draw_line(img, px, py, px+(pdx*5), py+(pdy*5), GREEN);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
	{
		//px += 10;
		pa += 0.1;
		if (pa > 2*PI)
			pa -= 2*PI;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		displayMap(fdf);
		mlx_put_pixel(img, px, py, GREEN);
		draw_line(img, px, py, px+(pdx*5), py+(pdy*5), GREEN);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
	{
		//py -= 10;
		px += pdx;
		py += pdy;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		displayMap(fdf);
		mlx_put_pixel(img, px, py, GREEN);
		draw_line(img, px, py , px+(pdx*5), py+(pdy*5) , GREEN);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
	{
		//py += 10;
		px -= pdx;
		py -= pdy;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		displayMap(fdf);
		mlx_put_pixel(img, px, py, GREEN);
		draw_line(img, px, py , px+(pdx*5), py+(pdy*5) , GREEN);
	}

	

}


int32_t	main(void)
{
	t_fdf	*fdf;
	mlx_image_t	*img;
	
	fdf = fdf_init(WIDTH, HEIGHT, "FdF");
	
	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);


	displayMap(fdf);


	img = fdf->img;
	// Even after the image is being displayed, we can still modify the buffer.

	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	
	mlx_put_pixel(img, px, py, GREEN);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(fdf->mlx, ft_hook, fdf);

	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (EXIT_SUCCESS);
}