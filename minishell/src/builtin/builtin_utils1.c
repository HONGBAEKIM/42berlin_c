/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:41:00 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 12:38:31 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_utils.h"

int	update_directories(char *old_dir, t_list **env, t_msh *g_msh)
{
	char	new_dir[MAX_PATH];

	if (getcwd(new_dir, MAX_PATH) == NULL)
		return (EXIT_FAILURE);
	if (!is_env_var("PWD", *env))
		create_environment_var("PWD", env, g_msh);
	update_environment_var("PWD", new_dir, *env, g_msh); 
	if (!is_env_var("OLDPWD", *env))
		create_environment_var("OLDPWD", env, g_msh);
	update_environment_var("OLDPWD", old_dir, *env, g_msh); 
	return (EXIT_SUCCESS);
}

char	*replace_env_value(char **env_ptr, char	*var_name, char *new_value, \
							t_msh *g_msh)
{
	char	*temp;
	char	*final;

	temp = ft_strjoin(var_name, "=");
	if (!temp)
		quit_program(EXIT_FAILURE, g_msh);
	final = ft_strjoin(temp, new_value);
	if (!final)
		quit_program(EXIT_FAILURE, g_msh);
	free(temp);
	temp = 0;
	free(*env_ptr);
	*env_ptr = 0;
	return (final);
}

void	update_environment_var(char *var, char *new_value, t_list *env, \
								t_msh *g_msh)
{
	int		i;
	char	*cur_env;

	while (env)
	{
		i = 0;
		cur_env = (char *)(env->data);
		while (var[i] && cur_env[i] && (var[i] == cur_env[i]))
			i++;
		if (!var[i] && (cur_env[i] == '=' || cur_env[i] == '\0' ))
			env->data = replace_env_value(&cur_env, var, new_value, g_msh);
		env = env->next;
	}
}

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
