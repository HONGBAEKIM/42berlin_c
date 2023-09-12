/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:59:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/12 14:30:39 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


t_fdf	*fdf_init(int32_t width, int32_t height, char *name);
void clear_image(mlx_image_t *img, int32_t width, int32_t height, int32_t bg_color);
static void ft_hook(void* param);

void mlx_fill_square(mlx_image_t *img, int x, int y, int size, int color);
void displayMap(t_fdf *fdf);
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
    int block_size = 50; // Adjust the size of each map block

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


// Print the window width and height.
static void ft_hook(void* param)
{
	t_fdf *fdf = param;
	mlx_image_t	*img;

	img = fdf->img;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
	{
		greenDotY -= 5;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		displayMap(fdf);
		mlx_put_pixel(img, greenDotX, greenDotY, GREEN);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
	{
		greenDotY += 5;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		displayMap(fdf);
		mlx_put_pixel(img, greenDotX, greenDotY, GREEN);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
	{
		greenDotX -= 5;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		displayMap(fdf);
		mlx_put_pixel(img, greenDotX, greenDotY, GREEN);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
	{
		greenDotX += 5;
		clear_image(fdf->img, WIDTH, HEIGHT, 0x000000);
		displayMap(fdf);
		mlx_put_pixel(img, greenDotX, greenDotY, GREEN);
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
	mlx_put_pixel(img, greenDotX, greenDotY, GREEN);

	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(fdf->mlx, ft_hook, fdf);

	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (EXIT_SUCCESS);
}