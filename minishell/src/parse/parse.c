/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:37:25 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/25 11:23:43 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/*
** Extracts the Abstract Syntax Tree (AST) out of the input entered in cmd line.
** In this case, the AST is a list that has a cmd_table per node and each
** cmd_table has a list a simple command per node. Each simple command has a 
** list of tokens and list of redirections
** @param:	- [const char *] the unchanged line entered in stdin
** @return:	[t_ast *] struct with a list of cmd_tables
** Line-by-line comments:
** @11		We pass down the reference of the curr_pos to keep track of the
** 			parsing executed by every subsequent function
** @15		In exec_ast(), we'll want to execute the cmd_table in entering order
**			so we need to add to the back each new cmd_table
*/

t_ast	*get_ast(const char *input)
{
	t_ast	*ast;
	t_list	*cmd_table;
	int		curr_pos;

	printf("%s\n", "7.0.get_ast");
	ast = ft_calloc(1, sizeof(t_ast));
	printf("%s\n", "7.1.get_ast");
	if (!ast)
	{
		printf("%s\n", "7.2.get_ast");
		quit_program(EXIT_FAILURE);
	}
	curr_pos = 0;
	while (input[curr_pos])
	{
		printf("%s\n", "7.3.get_ast");
		skip_spaces(input, &curr_pos);
		printf("%s\n", "7.4.get_ast");
		cmd_table = ft_lstnew((void *)get_cmd_table(input, &curr_pos));
		printf("%s\n", "7.5.get_ast");
		if (!cmd_table)
		{
			printf("%s\n", "7.6.get_ast");
			quit_program(EXIT_FAILURE);
		}
		printf("%s\n", "7.7.get_ast");
		ft_lstadd_back(&ast->cmd_tables, cmd_table);
		printf("%s\n", "7.8.get_ast");
	}
	return (ast);
}

/*
** Gets a command table, which is a series of simple commands to execute
** @param:	- [const char *] the unchanged line entered in stdin
**			- [int *] the current parsing position within the input  
** @return:	[t_cmd_table *] struct with list of simple cmds and the delimiter
**							that seperates this cmd_table from the next
** Line-by-line comments:
** @14-15	If the next character is '|' then it means there is another simple
**			command. But "||" would mean that the cmd_table would be over. In
** 			the case of "||" is will be flagged by is_cmd_table_delimiter()
**			All error handling is done before by is_input_valid() so we don't
**			need to be on the lookout for bad syntax
*/

t_cmd_table	*get_cmd_table(const char *input, int *curr_pos)
{
	t_cmd_table	*cmd_table;
	t_list		*cmd;

	printf("%s\n", "7.4.0.get_cmd_table");
	cmd_table = ft_calloc(1, sizeof(t_cmd_table));
	printf("%s\n", "7.4.1.get_cmd_table");
	if (!cmd_table)
	{
		//printf("%s\n", "7.4.2.get_cmd_table");
		quit_program(EXIT_FAILURE);
	}
	while (input[*curr_pos] && !is_cmd_table_delimiter(&input[*curr_pos]))
	{
		printf("%s\n", "7.4.3.get_cmd_table");
		skip_spaces(input, curr_pos);
		printf("%s\n", "7.4.4.get_cmd_table");
		cmd = ft_lstnew((void *)get_cmd(input, curr_pos));
		printf("%s\n", "7.4.5.get_cmd_table");
		if (!cmd)
		{
			//printf("%s\n", "7.4.6.get_cmd_table");
			quit_program(EXIT_FAILURE);
		}
		printf("%s\n", "7.4.7.get_cmd_table");
		ft_lstadd_back(&cmd_table->cmds, cmd);
		printf("%s\n", "7.4.8.get_cmd_table");
		if (input[*curr_pos] == '|' && input[*curr_pos + 1] != '|')
			(*curr_pos)++;
	}
	printf("%s\n", "7.4.9.get_cmd_table");
	cmd_table->delimiter = get_cmd_table_delimiter(input, curr_pos);
	printf("%s\n", "7.4.10.get_cmd_table");
	return (cmd_table);
}

/*
** Gets a simple command, which is a series of tokens or redirections. Tokens
** and redirection aren't necessarily sorted. This is a valid simple command:
** > redir1 program_name token1 >> redir2 token2 token3 < redir3
** @param:	- [const char *] the unchanged line entered in stdin
**			- [int *] the current parsing position within the input  
** @return:	[t_cmd *] struct with a list of tokens and a list of redirection
** 					  in order of entering
** Line-by-line comments:
** @7		Parse until simple command is finished (i.e. '\0', ';' or '|')
** @9		If not '>' or '<', then it's a token
** @16		If '>' or '<', then it's a redirection
*/

t_cmd	*get_cmd(const char *input, int *curr_pos)
{
	t_cmd	*cmd;
	t_list	*new_node;

	printf("%s\n", "7.4.4.0.get_cmd");
	cmd = ft_calloc(1, sizeof(t_cmd));
	printf("%s\n", "7.4.4.1.get_cmd");
	if (!cmd)
	{
		printf("%s\n", "7.4.4.2.get_cmd");
		quit_program(EXIT_FAILURE);
	}
	while (input[*curr_pos] && !is_cmd_delimiter(input[*curr_pos]))
	{
		//printf("0.*curr_pos : %d\n",*curr_pos);
		printf("%s\n", "7.4.4.3.get_cmd");
		if (input[*curr_pos] != '>' && input[*curr_pos] != '<')
		{
			printf("%s\n", "7.4.4.4.get_cmd");
			new_node = ft_lstnew((void *)get_token(input, curr_pos));
			printf("%s\n", "7.4.4.5.get_cmd");
			if (!new_node)
			{
				printf("%s\n", "7.4.4.6.get_cmd");
				quit_program(EXIT_FAILURE);
			}
			printf("%s\n", "7.4.4.7.get_cmd");
			ft_lstadd_back(&cmd->tokens, new_node);
		}
		else if (input[*curr_pos] == '>' || input[*curr_pos] == '<')
		{
			printf("%s\n", "7.4.4.8.get_cmd");
			new_node = ft_lstnew((void *)get_redir(input, curr_pos));
			printf("%s\n", "7.4.4.9.get_cmd");
			if (!new_node)
			{
				printf("%s\n", "7.4.4.10.get_cmd");
				quit_program(EXIT_FAILURE);
			}
			printf("%s\n", "7.4.4.11.get_cmd");
			ft_lstadd_back(&cmd->redirs, new_node);
		}
		printf("%s\n", "7.4.4.12.get_cmd");
		skip_spaces(input, curr_pos);
	}
	return (cmd);
}

/*
** Gets a single redirection
** @param:	- [const char *] the unchanged line entered in stdin
**			- [int *] the current parsing position within the input  
** @return:	[t_redir *] struct with a string with the direction and the type
** Line-by-line comments:
** @6-14	Gets the type
** @16		Gets the file. The file_name is stored inside a t_token because
** 			we need to know the delimiter around the redirection
*/

t_redir	*get_redir(const char *input, int *curr_pos)
{
	t_redir	*redir;

	printf("%s\n", "7.4.4.8.0.get_redir");
	redir = ft_calloc(1, sizeof(t_redir));
	printf("%s\n", "7.4.4.8.1.get_redir");
	if (!redir)
		quit_program(EXIT_FAILURE);
	if (!ft_strncmp(&input[*curr_pos], "<<", 2))
	{
		printf("%s\n", "7.4.4.8.1-0.get_redir");
		ft_strncpy(redir->type, (char *)&input[*curr_pos], 2);
		*curr_pos += 2;
	}
	else if (input[*curr_pos] == '<')
	{
		printf("%s\n", "7.4.4.8.2.get_redir");
		*redir->type = input[(*curr_pos)++];
		//printf("this is redir %c\n\n\n", redir->direction);
		//printf("0.*curr_pos : %d\n", *curr_pos);
		//printf("0.input[(*curr_pos) : %s\n", input);
	}
	else if (!ft_strncmp(&input[*curr_pos], ">>", 2))
	{
		printf("%s\n", "7.4.4.8.3.get_redir");
		//*redir->type = input[(*curr_pos)++];
		//*redir->type = input[(*curr_pos)++];
		ft_strncpy(redir->type, (char *)&input[*curr_pos], 2);
		*curr_pos += 2;
	}
	else if (input[*curr_pos] == '>')
	{
		printf("%s\n", "7.4.4.8.4.get_redir");
		*redir->type = input[(*curr_pos)++];
	}
	
	printf("%s\n", "7.4.4.8.5.get_redir");
	skip_spaces(input, curr_pos);
	printf("%s\n", "7.4.4.8.6.get_redir");
	redir->direction = get_token(input, curr_pos);
	printf("%s\n", "7.4.4.8.7.get_redir");
	return (redir);
}

/*
** Gets a token, which represents one argument in the cmd_line. It can
** either be a word or a string of words if quotes are used.
** Example of single valid tokens:
** - hello
** - "$TERM"'$PATH'hello1"hel'lo2"'hel"lo3'
** - hello1"hel'lo2"'hel"lo3'"$TERM"'$PATH'
** @param:	- [const char *] the unchanged line entered in stdin
**			- [int *] the current parsing position within the input  
** @return:	[char *] a str representing a single token like a program name or
**					 program argument
** Line-by-line comments:
** @4		We need to save the beginning of the token so that we can extract
**			the string once we have found the end of the token
*/

char	*get_token(const char *input, int *curr_pos)
{
	char	*token;
	int		saved_pos;

	saved_pos = *curr_pos;
	//printf("*curr_pos : %d\n",*curr_pos);

	while (input[*curr_pos] && !is_token_delimiter(input[*curr_pos]))
	{
		if (is_quote(input[*curr_pos]))
			skip_quotes(input, curr_pos);
		else if (input[*curr_pos])
			(*curr_pos)++;
	}
	//printf("saved_pos : %d\n",saved_pos);

	token = ft_substr(input, saved_pos, *curr_pos - saved_pos);
	//printf("token : %s\n",token);
	if (!token)
		quit_program(EXIT_FAILURE);
	return (token);
}



