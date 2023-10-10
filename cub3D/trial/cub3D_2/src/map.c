/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:42:31 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/29 09:22:14 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void displayMap(t_cub *cub) 
{
    int x = 0, y = 0;
    int block_size = 100; // Adjust the size of each map block
	char cub3dMap[mapWidth][mapHeight] = 
	{
		{'1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', 'N', '1'},
		{'1', '1', '1', '1', '1', '1'}
	};
    mlx_image_t	*img;

    img = cub->img;

	mlx_image_to_window(cub->mlx, cub->img, 0, 0);

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
            mlx_fill_square(cub->img, x * block_size, y * block_size, block_size, color);
            x++;
        }
        y++;
    }
}
