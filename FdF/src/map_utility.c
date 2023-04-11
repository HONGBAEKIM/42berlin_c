/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:20:16 by hongbaki          #+#    #+#             */
/*   Updated: 2023/03/29 22:20:17 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map_new(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		stop(ERR_MAP_INIT);
	map->point = NULL;
	map->cols = 0;
	map->rows = 0;
	map->spacing = 0;
	map->x_start = 0;
	map->y_start = 0;
	map->highest = -2147483648;
	map->lowest = (float)2147483647;
	return (map);
}

void	translate(t_fdf *fdf, char xy, int amount)
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
}

void	zoom(t_fdf *fdf, int amount)
{
	fdf->map->spacing += amount;
	draw(fdf, fdf->map);
}

void	change_height(t_fdf *fdf, float factor, int up)
{
	t_point	*pt;

	pt = fdf->map->point;
	while (pt)
	{
		if (up == 1)
			pt->height = pt->height * factor;
		else
			pt->height = pt->height / factor;
		pt = pt->next;
	}
	draw(fdf, fdf->map);
}

void	change_color(t_fdf *fdf, uint32_t rgb)
{
	fdf->rgb = rgb;
	draw(fdf, fdf->map);
}

/* Real data can hold a value 4 bytes in size, 
meaning it has 7 digits of precision. 
Float data can hold 8 bytes, 
or 15 places after the decimal point. */
