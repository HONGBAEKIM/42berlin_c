/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:42:31 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/28 13:45:15 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void displayMap(t_cub *cub) 
{
    int x = 0, y = 0;
    int block_size = 100; // Adjust the size of each map block
	char cub3dMap[MAPWIDTH][MAPHEIGHT] = 
	{
		{'1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', 'N', '1'},
		{'1', '1', '1', '1', '1', '1'}
	};

    printf("%s\n", "3.displayMap.0");
    while (y < MAPHEIGHT) 
	{
        x = 0;
        while (x < MAPWIDTH) 
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
