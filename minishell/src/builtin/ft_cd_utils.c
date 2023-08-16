/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:24:20 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/15 18:24:22 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

int	cd_env_error_check(char *env, t_msh *g_msh)
{
	DIR		*dirp;
	char	*arg;
	int		status;

	arg = ft_getenv(env, g_msh);
	if (arg == 0)
		status = cd_error_messsage("cd", "HOME not set");
	else if (*arg == '\0')
		status = EXIT_SUCCESS;
	else
	{
		if (!has_x_permission(arg))
			return (EXIT_FAILURE);
		dirp = opendir(arg);
		if (dirp == NULL)
			status = other_invalid_error("cd", errno, arg);
		else
		{
			status = EXIT_SUCCESS;
			closedir(dirp);
		}
		free(arg);
	}
	return (status);
}

int	cd_path_error_check(char *path)
{
	DIR	*dirp;
	int	status;

	if (!has_x_permission(path))
		return (EXIT_FAILURE);
	dirp = opendir(path);
	if (dirp == NULL)
		status = other_invalid_error("cd", errno, path);
	else
	{
		status = EXIT_SUCCESS;
		closedir(dirp);
	}
	return (status);
}

int	cd_error_messsage(char *builtin, char *error)
{
	write_msh_exec_error(builtin, error);
	return (EXIT_FAILURE);
}

int	other_invalid_error(char *builtin, int error, char *arg)
{
	write_msh_exec_arg_error(builtin, arg, strerror(error));
	return (EXIT_FAILURE);
}

int	has_x_permission(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) == EXIT_SUCCESS)
	{
		if (statbuf.st_mode & S_IXUSR)
			return (1);
		else
		{
			write_msh_exec_arg_error("cd", path, "Permission denied");
			return (0);
		}
	}
	else
	{
		write_msh_exec_arg_error("cd", path, strerror(errno));
		return (0);
	}
}
