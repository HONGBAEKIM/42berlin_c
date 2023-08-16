/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_last_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:59:48 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/08 09:59:49 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

void	save_last_token(t_cmd_table *cmd_table, t_msh *g_msh)
{
	t_cmd	*last_simple_cmd;
	char	*last_token;
	char	*exec_path;

	last_simple_cmd = ft_lst_get_data_last_node(cmd_table->cmds);
	last_token = ft_lst_get_data_last_node(last_simple_cmd->tokens);
	if (last_token && has_only_one_cmd(g_msh))
		exec_path = convert_to_path(last_token, g_msh);
	else
	{
		exec_path = ft_strdup("");
		if (!exec_path)
			quit_program(EXIT_FAILURE, g_msh);
	}
	update_environment_var("_", exec_path, g_msh->dup_envp, g_msh); 
	free(exec_path);
}

char	*convert_to_path(char *token, t_msh *g_msh)
{
	char	*token_path;

	if (has_relative_path(token))
	{
		token_path = ft_strdup(token);
		if (!token_path)
			quit_program(EXIT_FAILURE, g_msh);
	}
	else
		token_path = get_absolute_path(token, g_msh);
	return (token_path);
}
