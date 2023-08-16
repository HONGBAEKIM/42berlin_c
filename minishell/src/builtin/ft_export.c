/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:53:12 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:36:39 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_export.h"

int	ft_export(t_list *tokens, t_list **env, t_msh *g_msh)
{
	char	*var;
	char	*token_str;

	if (tokens == 0)
		print_all_exported_vars(*env, g_msh);
	while (tokens)
	{
		token_str = tokens->data;
		if (!has_valid_identifier_export(token_str))
			return (EXIT_FAILURE);
		if (has_only_one_cmd(g_msh))
		{
			var = get_var_name(token_str, g_msh);
			if (is_env_var(var, *env))
			{
				if (ft_strchr(token_str, '='))
					update_env_var_with_token(token_str, var, *env, g_msh);
			}
			else
				create_environment_var(token_str, env, g_msh);
			free(var);
		}
		tokens = tokens->next;
	}
	return (EXIT_SUCCESS);
}

void	print_all_exported_vars(t_list *env, t_msh *g_msh)
{
	t_list	*sorted_env;
	t_list	*tmp;
	char	*env_str;
	int		i;

	sorted_env = get_sorted_env(env, g_msh);
	tmp = sorted_env;
	while (tmp)
	{
		i = 0;
		env_str = (char *)tmp->data;
		if (ft_strchr(env_str, '='))
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			while (env_str[i] != '=')
				ft_putchar_fd(env_str[i++], STDOUT_FILENO);
			printf("=\"%s\"\n", &env_str[++i]);
		}
		else
			printf("declare -x %s\n", env_str);
		tmp = tmp->next;
	}
	ft_lstclear(&sorted_env, ft_lstdel_int);
}

void	update_env_var_with_token(char *token_str, char *var, \
t_list *env, t_msh *g_msh)
{
	char	*value;

	value = get_value_name(token_str, g_msh);
	update_environment_var(var, value, env, g_msh); 
	free(value);
}

void	create_environment_var(char *token_str, t_list **env, t_msh *g_msh)
{
	t_list	*new_var;
	char	*new_var_str;

	new_var_str = ft_strdup(token_str);
	if (new_var_str == 0)
		quit_program(EXIT_FAILURE, g_msh);
	new_var = ft_lstnew(new_var_str);
	if (new_var == 0)
		quit_program(EXIT_FAILURE, g_msh);
	ft_lstadd_front(env, new_var);
}

t_list	*get_sorted_env(t_list *env, t_msh *g_msh)
{
	t_list	*sorted_env;

	sorted_env = ft_lstdup(env);
	if (!sorted_env)
		quit_program(EXIT_FAILURE, g_msh);
	ft_lst_sort_str(&sorted_env, ft_strcmp);
	return (sorted_env);
}
