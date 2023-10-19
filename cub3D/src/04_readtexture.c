/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_readtexture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:05:50 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:16:53 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_wall_tex_path(t_main *cub)
{
	char	path_str[PATH_MAX];
	int		i;

	i = 0;
	while (1)
	{
		if (cub->char_read == '\n')
			break ;
		path_str[i] = cub->char_read;
		i++;
		read_char(cub);
	}
	path_str[i] = '\0';
	return (ft_strdup(path_str));
}

int	choose_tex_path_index(char *path)
{
	if (!ft_strcmp(path, "NO"))
		return (0);
	if (!ft_strcmp(path, "SO"))
		return (1);
	if (!ft_strcmp(path, "WE"))
		return (2);
	if (!ft_strcmp(path, "EA"))
		return (3);
	return (-1);
}

bool	read_tex_prefix(t_main *cub, char *path)
{
	bool	*chosen_fileflag;
	int		tex_path_index;

	if (match_char(cub, path[0]))
	{
		read_char(cub);
		if (match_char(cub, path[1]))
		{
			read_char(cub);
			while (cub->char_read == ' ')
				read_char(cub);
			chosen_fileflag = choose_fileflag(cub, path);
			if (*chosen_fileflag == 1)
				ft_error(ERR_DUPL_TEX, cub);
			tex_path_index = choose_tex_path_index(path);
			cub->tex_paths[tex_path_index] = read_wall_tex_path(cub);
			cub->tex_paths_alloc = true;
			*chosen_fileflag = true;
			return (1);
		}
		else
			ft_error(ERR_PREFIXES, cub);
	}
	return (0);
}

/* //PATH_MAX is 4096
char	*read_wall_tex_path(t_main *cub)
{
	char	path_str[4096];
	int		i;

	i = 0;
	while (1)
	{
		if (cub->char_read == '\n')
			break ;
		path_str[i] = cub->char_read;
		i++;
		read_char(cub);
	}
	path_str[i] = '\0';
	return (ft_strdup(path_str));
}

int	choose_tex_path_index(char *path)
{
	if (!ft_strcmp(path, "NO"))
		return (0);
	if (!ft_strcmp(path, "SO"))
		return (1);
	if (!ft_strcmp(path, "WE"))
		return (2);
	if (!ft_strcmp(path, "EA"))
		return (3);
	return (-1);
}

bool	read_tex_prefix(t_main *cub, char *path)
{
	bool	*chosen_fileflag;
	int		tex_path_index;

	if (match_char(cub, path[0]))
	{
		read_char(cub);
		if (match_char(cub, path[1]))
		{
			read_char(cub);
			while (cub->char_read == ' ')
				read_char(cub);
			chosen_fileflag = choose_fileflag(cub, path);
			if (*chosen_fileflag == 1)
				ft_error(ERR_DUPL_TEX, cub);
			tex_path_index = choose_tex_path_index(path);
			cub->tex_paths[tex_path_index] = read_wall_tex_path(cub);
			cub->tex_paths_alloc = true;
			*chosen_fileflag = true;
			return (1);
		}
		else
			ft_error(ERR_PREFIXES, cub);
	}
	return (0);
} */
