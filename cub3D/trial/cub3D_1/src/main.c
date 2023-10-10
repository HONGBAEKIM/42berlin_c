/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:59:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/28 16:13:40 by hongbaki         ###   ########.fr       */
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







int	main(int ac, char **av)
{
	t_cub	cub;
	
	if (ac != 2)
	{
		error_msg(ERR_ARGC);
		return (1);
	}
	if (check_file_valid(av[1], &cub) == false)
		return (1);

	
	printf("%s\n", "0.");

	//cub = 
	cub_init(ac, av, &cub);

	printf("%s\n", "1.");

	// MLX allows you to define its core behaviour before startup.w
	mlx_set_setting(MLX_MAXIMIZED, true);

	printf("%s\n", "2.");

	displayMap(&cub);

	printf("%s\n", "3.");

	

	printf("%s\n", "4.");

	
		
	printf("%s\n", "5.");
	
	mlx_loop_hook(cub.mlx, &raycast, &cub);	
	
	printf("%s\n", "6.");

	mlx_loop(cub.mlx);

	printf("%s\n", "7.");

	mlx_terminate(cub.mlx);

	printf("%s\n", "8.");
	
	return (EXIT_SUCCESS);
}