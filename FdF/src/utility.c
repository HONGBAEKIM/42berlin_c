/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:20:34 by hongbaki          #+#    #+#             */
/*   Updated: 2023/03/29 22:20:34 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	check_fdfnull(char *test_map, char *fdfnull)
{
	int	test_map_len;
	int	i;

	test_map_len = ft_strlen(test_map);
	i = test_map_len - 4;
	if (test_map[i] == '.' && ft_strncmp(&test_map[i + 1], fdfnull, 3) == 0)
		return (1);
	return (0);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_isblank(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
