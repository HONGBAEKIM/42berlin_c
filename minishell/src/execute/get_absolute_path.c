/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:03:28 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:52:44 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_absolute_path.h"

char	*get_absolute_path(char *program_name, t_msh *g_msh)
{
	char	**path_env_split;
	char	*absolute_path;

	path_env_split = get_path_env_split(g_msh);
	if (!path_env_split)
	{
		absolute_path = ft_strdup(program_name);
		if (!absolute_path)
			quit_program(EXIT_FAILURE, g_msh);
	}
	else
	{
		absolute_path = get_correct_path(program_name, path_env_split, g_msh);
		free_arr((void **)path_env_split);
	}
	return (absolute_path);
}

char	**get_path_env_split(t_msh *g_msh)
{
	char	*path_env;
	char	**path_env_split;

	path_env = ft_getenv("PATH", g_msh);
	if (!path_env)
		return (0);
	path_env_split = ft_split(path_env, ':');
	free(path_env);
	if (!path_env_split)
		quit_program(EXIT_FAILURE, g_msh);
	add_slash(&path_env_split);
	return (path_env_split);
}

void	add_slash(char ***path_env_split)
{
	int		i;
	char	*path;
	int		len;
	char	*new_path;

	i = 0;
	while ((*path_env_split)[i])
	{
		path = (*path_env_split)[i];
		len = ft_strlen(path);
		if (path[len - 1] != '/')
		{
			new_path = ft_strjoin(path, "/");
			free(path);
			(*path_env_split)[i] = new_path;
		}
		i++;
	}
}

char	*get_correct_path(char *program_name, char **path_env_split, \
t_msh *g_msh)
{
	char		*absolute_path;
	int			i;
	struct stat	statbuf;

	i = 0;
	while (path_env_split[i])
	{
		absolute_path = ft_strjoin(path_env_split[i], program_name);
		if (!absolute_path)
			quit_program(EXIT_FAILURE, g_msh);
		if (stat(absolute_path, &statbuf) == EXIT_SUCCESS)
			break ;
		free(absolute_path);
		i++;
	}
	if (!path_env_split[i])
	{
		absolute_path = ft_strdup(program_name);
		if (!absolute_path)
			quit_program(EXIT_FAILURE, g_msh);
	}
	return (absolute_path);
}

/* char	*get_correct_path(char *program_name, char **path_env_split, \
 *g_msh)
{
	char		*absolute_path;
	int			i;
	struct stat	statbuf;

	i = 0;
	while (path_env_split[i])
	{
		absolute_path = ft_strjoin(path_env_split[i], program_name);
		if (!absolute_path)
			quit_program(EXIT_FAILURE, g_msh);
		//whether a file or directory specified by its absolute path exists 
		if (stat(absolute_path, &statbuf) == EXIT_SUCCESS)
			break ;
		free(absolute_path);
		i++;
	}
	if (!path_env_split[i])
	{
		absolute_path = ft_strdup(program_name);
		if (!absolute_path)
			quit_program(EXIT_FAILURE, g_msh);
	}
	return (absolute_path);
} */