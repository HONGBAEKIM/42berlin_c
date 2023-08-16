/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:50:54 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/15 11:50:13 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

int	ft_cd(t_list *tokens, t_list **env, t_msh *g_msh)
{
	char	pwd[MAX_PATH];

	if (getcwd(pwd, MAX_PATH) == NULL)
	{
		write_msh_exec_error("cd", strerror(errno));
		return (errno);
	}
	if (!has_only_one_cmd(g_msh))
		return (only_cd_errors(tokens, g_msh));
	else
		return (execute_cd(tokens, env, pwd, g_msh));
	printf("getcwd : %s\n", getcwd(pwd, MAX_PATH));
}

int	execute_cd(t_list *tokens, t_list **env, char *pwd, t_msh *g_msh)
{
	char	*arg;
	int		status;

	if (tokens == 0)
		status = change_dir_home(pwd, env, g_msh);
	else if (tokens->next != 0)
		status = cd_error_messsage("cd", "too many arguments");
	else
	{
		arg = tokens->data;
		if (!ft_strcmp(arg, "-"))
			status = change_to_old_dir(pwd, env, g_msh);
		else if (chdir(arg) == EXIT_SUCCESS)
			status = update_directories(pwd, env, g_msh);
		else
			status = other_invalid_error("cd", errno, arg);
	}
	return (status);
}

int	only_cd_errors(t_list *tokens, t_msh *g_msh)
{
	char	*arg;
	int		status;

	status = 0;
	if (tokens == 0)
		status = cd_env_error_check("HOME", g_msh);
	else if (tokens->next != 0)
		status = cd_error_messsage("cd", "too many arguments");
	else
	{
		arg = tokens->data;
		if (ft_strcmp(arg, "-") == 0)
			status = cd_env_error_check("OLDPWD", g_msh);
		else
			status = cd_path_error_check(arg);
	}
	return (status);
}

int	change_dir_home(char *cur_pwd, t_list **env, t_msh *g_msh)
{
	int		status;
	char	*home;

	home = ft_getenv("HOME", g_msh);
	if (home == 0)
	{
		write_msh_exec_error("cd", "HOME not set");
		status = EXIT_FAILURE;
	}
	else if (*home == '\0')
	{
		status = EXIT_SUCCESS;
	}
	else
	{
		if (chdir(home) == 0)
			status = update_directories(cur_pwd, env, g_msh);
		else
			status = other_invalid_error("cd", errno, home);
	}
	free(home);
	return (status);
}

int	change_to_old_dir(char *cur_pwd, t_list **env, t_msh *g_msh)
{
	char	*old_dir;
	int		status;

	old_dir = ft_getenv("OLDPWD", g_msh);
	if (old_dir == 0 || *old_dir == '\0')
	{
		write_msh_exec_error("cd", "OLDPWD not set");
		status = EXIT_FAILURE;
	}
	else
	{
		if (chdir(old_dir) == 0)
		{
			printf("%s\n", old_dir);
			status = update_directories(cur_pwd, env, g_msh);
		}
		else
			status = other_invalid_error("cd", errno, old_dir);
	}
	if (old_dir)
		free(old_dir);
	return (status);
}
