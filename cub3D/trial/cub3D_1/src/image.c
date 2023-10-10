/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:41:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/14 11:42:03 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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