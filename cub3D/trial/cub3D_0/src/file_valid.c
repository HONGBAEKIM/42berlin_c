/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:58:52 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:03:53 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	cub_extension(char *cub_file)
{
	int	i;
	char	**str;

	i = 0;
	str = ft_split(cub_file, '.');
	while (str[i])
		i++;
	i--;
	if (!ft_strcmp(str[i], "cub"))
	{
		ft_free_array(str);
		return (1);
	}
	ft_free_array(str);
	error_msg(nonvalidfile);
	return (0);
	
}

static bool	file_name(char *cub_file)
{
	char	*tmp;

	tmp = cub_file;
	while (ft_strchr(tmp, '/') != NULL)
		tmp = ft_strchr(tmp, '/') + 1;
	if (!tmp && ft_strlen(cub_file) - 4 == 0)
		return (0);
	else if (ft_strlen(tmp) - 4 == 0)
		return (0);
	return (1);
}

bool	check_file_valid(char *cub_file, t_cub *cub)
{
	if (cub_extension(cub_file) == 0)
		return (0);
	if (file_name(cub_file) == 0)
		return (0);
	if (read_file(cub_file, cub))
		return (0);
}