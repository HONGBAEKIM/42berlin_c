/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:54:19 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:08:53 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unset.h"

int	ft_unset(t_list *tokens, t_list **env, t_msh *g_msh)
{
	char	*token_str;

	while (tokens)
	{
		token_str = tokens->data;
		if (!has_valid_identifier_unset(token_str))
			return (EXIT_FAILURE);
		if (has_only_one_cmd(g_msh))
			if (is_env_var(token_str, *env))
				delete_env_var(token_str, env);
		tokens = tokens->next;
	}
	return (EXIT_SUCCESS);
}

void	delete_env_var(char *var, t_list **env)
{
	t_list	*env_ptr;
	int		i;
	char	*cur_env;
	int		env_index;

	env_ptr = *env;
	env_index = 0;
	while (env_ptr)
	{
		i = 0;
		cur_env = (char *)(env_ptr->data);
		while (var[i] && cur_env[i] && (var[i] == cur_env[i]))
			i++;
		if (!var[i] && (cur_env[i] == '=' || cur_env[i] == '\0' ))
		{
			ft_lstdel_node_nbr(env, env_index, ft_delete_list_str);
			return ;
		}
		env_index++;
		env_ptr = env_ptr->next;
	}
}

void	ft_delete_list_str(void *data)
{
	free(data);
	data = 0;
}
