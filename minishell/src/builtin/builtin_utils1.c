/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:10:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/24 16:57:24 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_utils.h"

/*
** Updates the PWD and OLDPWD environment variables based the current and
** previous working directories
** @param:	- [char *] previous working directory
**			- [t_list **] environment variable string linked list
** @return:	[int] signs success or failure of the function
** Line-by-line comments:
** @3		Allowed function that fills buffer with null terminated string of
** 			current working directory
** @5-6 	Updates current working directory and previous directory environment
**			variables
*/

int	update_directories(char *old_dir, t_list **env)
{
	char	new_dir[MAX_PATH];

	//printf("%s\n", "8.3.5.7.5.3.1.4.0.update_directories");
	if (getcwd(new_dir, MAX_PATH) == NULL)
	{
		//printf("%s\n", "8.3.5.7.5.3.1.4.1.update_directories");
		return (EXIT_FAILURE);
	}
	if (!is_env_var("PWD", *env))
	{
		//printf("%s\n", "8.3.5.7.5.3.1.4.2.update_directories");
		create_environment_var("PWD", env);
	}
	//printf("%s\n", "8.3.5.7.5.3.1.4.3.update_directories");
	printf("new_dir : %s\n", new_dir);
	
	update_environment_var("PWD", new_dir, *env);
	//printf("%s\n", "8.3.5.7.5.3.1.4.4.update_directories");
	if (!is_env_var("OLDPWD", *env))
	{
		//printf("%s\n", "8.3.5.7.5.3.1.4.5.update_directories");
		create_environment_var("OLDPWD", env);
	}
	//printf("%s\n", "8.3.5.7.5.3.1.4.6.update_directories");
	update_environment_var("OLDPWD", old_dir, *env);
	//printf("%s\n", "8.3.5.7.5.3.1.4.7.update_directories");
	return (EXIT_SUCCESS);
}

/*
** Joins the variable name with a equal sign followed by the value
** @param:	- [char **] pointer to environment variable string to be updated
**			- [char *] name of variable
**			- [char *] updated value string
** @return:	[char *] updated string to be addded to linked list
*/

char	*replace_env_value(char **env_ptr, char	*var_name, char *new_value)
{
	char	*temp;
	char	*final;

	// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.0.replace_env_value");
	temp = ft_strjoin(var_name, "=");
	// printf("temp %s\n",temp);
	// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.1.replace_env_value");
	if (!temp)
	{
		// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.2.replace_env_value");
		quit_program(EXIT_FAILURE);
	}
	// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.3.replace_env_value");
	final = ft_strjoin(temp, new_value);
	// printf("final %s\n",final);
	// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.4.replace_env_value");
	if (!final)
	{
		// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.5.replace_env_value");
		quit_program(EXIT_FAILURE);
	}
	// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.6.replace_env_value");
	free(temp);
	// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.7.replace_env_value");
	temp = 0;
	// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.8.replace_env_value");
	free(*env_ptr);
	// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.9.replace_env_value");
	*env_ptr = 0;
	// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.10.replace_env_value");
	return (final);
}

/*
** Updates the environment variable string with a value we define
** @param:	- [char *] variable to look for in the env var linked list
**			- [char *] new value that will replace the current string
**			- [t_list *] environment variable string linked list
*/

void	update_environment_var(char *var, char *new_value, t_list *env)
{
	int		i;
	char	*cur_env;

	
	//printf("%s\n", "8.3.5.7.5.3.1.4.3.0.update_environment_var");
	while (env)
	{
		i = 0;
		//printf("%s\n", "8.3.5.7.5.3.1.4.3.1.update_environment_var");
		cur_env = (char *)(env->data);
		//printf("%s\n", "8.3.5.7.5.3.1.4.3.2.update_environment_var");
		while (var[i] && cur_env[i] && (var[i] == cur_env[i]))
		{
			// printf("%s\n", "8.3.5.7.5.3.1.4.3.3.update_environment_var");
			// printf("0.var[i] : %c\n", var[i]);
			// printf("0.cur_env[i] : %c\n", cur_env[i]);
			i++;
		}
		//printf("%s\n", "8.3.5.7.5.3.1.4.3.4.update_environment_var");
		if (!var[i] && (cur_env[i] == '=' || cur_env[i] == '\0' ))
		{
			// printf("%s\n", "8.3.5.7.5.3.1.4.3.5.update_environment_var");
			// printf("1.var[i] : %c\n", var[i]);
			// printf("1.cur_env[i] : %c\n", cur_env[i]);
			env->data = replace_env_value(&cur_env, var, new_value);
		}
		//printf("%s\n", "8.3.5.7.5.3.1.4.3.6.update_environment_var");
		env = env->next;
		//printf("%s\n", "8.3.5.7.5.3.1.4.3.7.update_environment_var");
		//printf("i : %i\n", i);
	}
}

/*
** Checks if token has invalid characters for the export function and prints an
** error message in case it does
** @param:	- [char *] export following tokens (arguments)
** @return:	[int] 1 if true 0 if false
** Line-by-line comments:
** @5		Error message array will be filled in case of invalid token
** @9		Prints char array to stderror
*/

int	has_valid_identifier_export(char *token_str)
{
	char	err_message[100];
	int		check;

	ft_bzero(err_message, 0);
	if (!is_token_valid_export(token_str, err_message))
	{
		check = 0;
		errno = ENOEXEC;
		write_msh_error(err_message);
	}
	else
		check = 1;
	return (check);
}

/*
** Checks if token string is invalid
** @param:	- [char *] export following tokens (arguments)
**			- [char *] array of chars to be printed in stderror
** @return:	[int] 1 if true 0 if false
** Line-by-line comments:
** @3		Preventing against empty/null variables
** @4		Preventing against quotes and single quotes (also, backslashes are
**			not part of the project so it wouldn't be possible anyway)
*/

int	is_token_valid_export(char *token_str, char *err_message)
{
	int		check;

	if ((token_str[0] == '=')
		|| ft_isdigit(token_str[0])
		|| ft_strchr(token_str, '\'')
		|| ft_strchr(token_str, '"'))
	{
		check = 0;
		ft_strcpy(err_message, "export: `");
		ft_strcat(err_message, token_str);
		ft_strcat(err_message, "': not a valid identifier");
	}
	else
		check = 1;
	return (check);
}
