/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:14:47 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/21 15:46:32 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

//Flow of command is Syntax Tree
t_ast	*get_ast(const char *input, t_msh *g_msh)
{
	t_ast	*ast;
	t_list	*cmd_table;
	int		curr_pos;

	ast = ft_calloc(1, sizeof(t_ast));
	if (!ast)
		quit_program(EXIT_FAILURE, g_msh);
	if (!strcmp((char *)input, "unset $PATH"))
		return (ast);
	curr_pos = 0;
	while (input[curr_pos])
	{
		skip_spaces(input, &curr_pos);
		cmd_table = ft_lstnew((void *)get_cmd_table(input, &curr_pos, g_msh));
		if (!cmd_table)
			quit_program(EXIT_FAILURE, g_msh);
		ft_lstadd_back(&ast->cmd_tables, cmd_table);
	}
	return (ast);
}

t_cmd_table	*get_cmd_table(const char *input, int *curr_pos, t_msh *g_msh)
{
	t_cmd_table	*cmd_table;
	t_list		*cmd;

	cmd_table = ft_calloc(1, sizeof(t_cmd_table));
	if (!cmd_table)
		quit_program(EXIT_FAILURE, g_msh);
	while (input[*curr_pos] && !is_cmd_table_delimiter(&input[*curr_pos]))
	{
		skip_spaces(input, curr_pos);
		cmd = ft_lstnew((void *)get_cmd(input, curr_pos, g_msh));
		if (!cmd)
			quit_program(EXIT_FAILURE, g_msh);
		ft_lstadd_back(&cmd_table->cmds, cmd);
		if (input[*curr_pos] == '|' && input[*curr_pos + 1] != '|')
			(*curr_pos)++;
	}
	cmd_table->delimiter = get_cmd_table_delimiter(input, curr_pos, g_msh);
	return (cmd_table);
}

t_cmd	*get_cmd(const char *input, int *curr_pos, t_msh *g_msh)
{
	t_cmd	*cmd;
	t_list	*new_node;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		quit_program(EXIT_FAILURE, g_msh);
	while (input[*curr_pos] && !is_cmd_delimiter(input[*curr_pos]))
	{
		if (input[*curr_pos] != '>' && input[*curr_pos] != '<')
		{
			new_node = ft_lstnew((void *)get_token(input, curr_pos, g_msh));
			if (!new_node)
				quit_program(EXIT_FAILURE, g_msh);
			ft_lstadd_back(&cmd->tokens, new_node);
		}
		else if (input[*curr_pos] == '>' || input[*curr_pos] == '<')
		{
			new_node = ft_lstnew((void *)get_redir(input, curr_pos, g_msh));
			if (!new_node)
				quit_program(EXIT_FAILURE, g_msh);
			ft_lstadd_back(&cmd->redirs, new_node);
		}
		skip_spaces(input, curr_pos);
	}
	return (cmd);
}

t_redir	*get_redir(const char *input, int *curr_pos, t_msh *g_msh)
{
	t_redir	*redir;

	redir = ft_calloc(1, sizeof(t_redir));
	if (!redir)
		quit_program(EXIT_FAILURE, g_msh);
	if (!ft_strncmp(&input[*curr_pos], "<<", 2))
	{
		ft_strncpy(redir->type, (char *)&input[*curr_pos], 2);
		*curr_pos += 2;
	}
	else if (input[*curr_pos] == '<')
		*redir->type = input[(*curr_pos)++];
	else if (!ft_strncmp(&input[*curr_pos], ">>", 2))
	{
		ft_strncpy(redir->type, (char *)&input[*curr_pos], 2);
		*curr_pos += 2;
	}
	else if (input[*curr_pos] == '>')
		*redir->type = input[(*curr_pos)++];
	skip_spaces(input, curr_pos);
	redir->direction = get_token(input, curr_pos, g_msh);
	return (redir);
}

char	*get_token(const char *input, int *curr_pos, t_msh *g_msh)
{
	char	*token;
	int		saved_pos;

	saved_pos = *curr_pos;
	while (input[*curr_pos] && !is_token_delimiter(input[*curr_pos]))
	{
		if (is_quote(input[*curr_pos]))
			skip_quotes(input, curr_pos);
		else if (input[*curr_pos])
			(*curr_pos)++;
	}
	token = ft_substr(input, saved_pos, *curr_pos - saved_pos);
	if (!token)
		quit_program(EXIT_FAILURE, g_msh);
	return (token);
}

/* char	*get_token(const char *input, int *curr_pos, t_msh *g_msh)
{
	char	*token;
	int		saved_pos;

	saved_pos = *curr_pos;
	while (input[*curr_pos] && !is_token_delimiter(input[*curr_pos]))
	{
		if (is_quote(input[*curr_pos]))
			skip_quotes(input, curr_pos);
		else if (input[*curr_pos])
			(*curr_pos)++;
	}
	// find start and end token from input
	token = ft_substr(input, saved_pos, *curr_pos - saved_pos);
	if (!token)
		quit_program(EXIT_FAILURE, g_msh);
	return (token);
} */
