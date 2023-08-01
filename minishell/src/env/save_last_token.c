/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_last_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:48:00 by gleal             #+#    #+#             */
/*   Updated: 2021/05/17 09:47:58 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

/*
** Adds last token to environment variable underscore
** @param:	- [t_cmd_table *] latest command table
** Line-by-line comments:
** @11-12	Last command and token from command table
** @15-20	Edge case: there are no tokens like "> a > b"
*/

void	save_last_token(t_cmd_table *cmd_table)
{
	t_cmd	*last_simple_cmd;
	char	*last_token;
	char	*exec_path;

	// printf("%s\n", "8.4.0.save_last_token");
	last_simple_cmd = ft_lst_get_data_last_node(cmd_table->cmds);
	// printf("%s\n", "8.4.1.save_last_token");
	last_token = ft_lst_get_data_last_node(last_simple_cmd->tokens);
	// printf("%s\n", "8.4.2.save_last_token");
	if (last_token && has_only_one_cmd())
	{
		// printf("%s\n", "8.4.3.save_last_token");
		exec_path = convert_to_path(last_token);
	}
	else
	{
		// printf("%s\n", "8.4.4.save_last_token");
		exec_path = ft_strdup("");
		// printf("%s\n", "8.4.5.save_last_token");
		if (!exec_path)
			quit_program(EXIT_FAILURE);
	}
	// printf("%s\n", "8.4.6.save_last_token");
	update_environment_var("_", exec_path, g_msh.dup_envp);
	// printf("%s\n", "8.4.7.save_last_token");
	free(exec_path);
	// printf("%s\n", "8.4.8.save_last_token");
}

/*
** In case we call an executable inside the path directory, we will get the
** corresponding absolute path
** @param:	- [char *] last token	
** @return:	[char *] string to be stored inside underscore var
*/

char	*convert_to_path(char *token)
{
	char	*token_path;

	// printf("%s\n", "8.4.3.0.convert_to_path");
	if (has_relative_path(token))
	{
		// printf("%s\n", "8.4.3.2.convert_to_path");
		token_path = ft_strdup(token);
		if (!token_path)
		{
			// printf("%s\n", "8.4.3.3.convert_to_path");
			quit_program(EXIT_FAILURE);
		}
	}
	else
	{
		// printf("%s\n", "8.4.3.4.convert_to_path");
		token_path = get_absolute_path(token);
	}
	return (token_path);
}
