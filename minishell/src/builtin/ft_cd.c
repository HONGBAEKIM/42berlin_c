/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:30:51 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/24 17:10:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

/*
** Tries to change directories, updating PWD and OLDPWD in case of success
** @param:	- [t_list *] tokens in current command (different arguments)
**			- [t_list **] environment variable linked list
** @return:	[int] exit status (1 if unsuccessful)
** Line-by-line comments:
** @1-7		Get current directory for OLDPWD
** @8-9		Prints correct error messages without changing directory
** @10-11	Tries to change directories
*/

int	ft_cd(t_list *tokens, t_list **env)
{
	char	pwd[MAX_PATH];

	//printf("%s\n", "8.3.5.7.5.0.ft_cd");
	if (getcwd(pwd, MAX_PATH) == NULL)
	{
		//printf("%s\n", "8.3.5.7.5.1.ft_cd");
		write_msh_exec_error("cd", strerror(errno));
		return (errno);
	}
	if (!has_only_one_cmd())
	{
		//printf("%s\n", "8.3.5.7.5.2.ft_cd");
		return (only_cd_errors(tokens));
	}
	else
	{
		//printf("%s\n", "8.3.5.7.5.3.ft_cd");
		return (execute_cd(tokens, env, pwd));
	}
	//printf("%s\n", "8.3.5.7.5.4.ft_cd");
	printf("getcwd : %s\n" ,getcwd(pwd, MAX_PATH));
}

/*
** Change directories, first it saves the current directory to update OLDPWD
** env var then based on the arguments it wll change to different places
** @param:	- [t_list *] tokens in current command (different arguments)
**			- [t_list **] environment variable linked list
**			- [char *] current working directory
** @return:	[int] exit status (1 if unsuccessful)
** Line-by-line comments:
** @4-5		Change to home in case of no args
** @11-12	Change to old_pwd in case of hyphen
** @13-14	Change to any other absolute or relative path
** @15-16	Error message in case of failure
*/

int	execute_cd(t_list *tokens, t_list **env, char *pwd)
{
	char	*arg;
	int		status;

	//printf("%s\n", "8.3.5.7.5.3.0.execute_cd");
	if (tokens == 0)
	{
		//printf("%s\n", "8.3.5.7.5.3.1.execute_cd");
		status = change_dir_home(pwd, env);
	}
	else if (tokens->next != 0)
	{
		//printf("%s\n", "8.3.5.7.5.3.2.execute_cd");
		status = cd_error_messsage("cd", "too many arguments");
	}
	else
	{
		//printf("%s\n", "8.3.5.7.5.3.3.execute_cd");
		arg = tokens->data;
		//printf("%s\n", "8.3.5.7.5.3.4.execute_cd");
		if (!ft_strcmp(arg, "-"))
		{
			//printf("%s\n", "8.3.5.7.5.3.5.execute_cd");
			status = change_to_old_dir(pwd, env);
		}
		else if (chdir(arg) == EXIT_SUCCESS)
		{
			//printf("%s\n", "8.3.5.7.5.3.6.execute_cd");
			status = update_directories(pwd, env);
		}
		else
		{
			//printf("%s\n", "8.3.5.7.5.3.7.execute_cd");
			status = other_invalid_error("cd", errno, arg);
		}
	}
	return (status);
}

/*
** Prints out errors to stderror (without executing cd) in case of
** multiple commands by using a combination of opendir and stat
** @param:	- [t_list *] arguments following cd command
** @return:	[int] function exit status
** Line-by-line comments:
** @12-13	Execution permission is needed to enter a directory
*/

int	only_cd_errors(t_list *tokens)
{
	char	*arg;
	int		status;

	status = 0;
	if (tokens == 0)
		status = cd_env_error_check("HOME");
	else if (tokens->next != 0)
		status = cd_error_messsage("cd", "too many arguments");
	else
	{
		arg = tokens->data;
		if (ft_strcmp(arg, "-") == 0)
			status = cd_env_error_check("OLDPWD");
		else
			status = cd_path_error_check(arg);
	}
	return (status);
}

/*
** Changes directory to home
** @param:	- [char *] directory before changing (for future OLDPWD)
**			- [t_list **] environment variable linked list pointer
** @return:	[int] exit status
** Line-by-line comments:
** @12		Function changes directory and returns 0 on success 
** @13		Function will update the environment variable linked list with the
**			new working directory values
** @14-15	Error message in case of failure
*/

int	change_dir_home(char *cur_pwd, t_list **env)
{
	int		status;
	char	*home;

	//printf("%s\n", "8.3.5.7.5.3.1.0.change_dir_home");
	home = ft_getenv("HOME");
	//printf("%s\n", "8.3.5.7.5.3.1.1.change_dir_home");
	if (home == 0)
	{
		//printf("%s\n", "8.3.5.7.5.3.1.2.change_dir_home");
		write_msh_exec_error("cd", "HOME not set");
		status = EXIT_FAILURE;
	}
	else if (*home == '\0')
	{
		//printf("%s\n", "8.3.5.7.5.3.1.3.change_dir_home");
		status = EXIT_SUCCESS;
	}
	else
	{
		if (chdir(home) == 0)
		{
			//printf("%s\n", "8.3.5.7.5.3.1.4.change_dir_home");
			status = update_directories(cur_pwd, env);
		}
		else
		{
			//printf("%s\n", "8.3.5.7.5.3.1.5.change_dir_home");
			status = other_invalid_error("cd", errno, home);
		}
		// printf("%s\n", "8.3.5.7.5.3.1.6.change_dir_home");
		home = EXIT_SUCCESS;
	}
	if (home)
	{
		//printf("%s\n", "8.3.5.7.5.3.1.7.change_dir_home");
		free(home);
	}
	return (status);
}

/*
** Changes directory to the old directory
** @param:	- [char *] directory before changing (for future OLDPWD)
**			- [t_list **] environment variable linked list pointer
** @return:	[int] exit status
** Line-by-line comments:
** @15		Function will update the environment variable linked list with the
**			new working directory values
** @17-18	Error message in case of failure
*/

int	change_to_old_dir(char *cur_pwd, t_list **env)
{
	char	*old_dir;
	int		status;

	old_dir = ft_getenv("OLDPWD");
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
			status = update_directories(cur_pwd, env);
		}
		else
			status = other_invalid_error("cd", errno, old_dir);
	}
	if (old_dir)
		free(old_dir);
	return (status);
}
