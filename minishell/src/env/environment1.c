/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:56:29 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/15 11:52:35 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

void	replace_envs(t_list **tokens, t_list *redirs, t_msh *g_msh)
{
	t_list	*token;
	t_redir	*redir;

	token = *tokens;
	while (token)
	{
		replace_env_single_token((char **)&token->data, g_msh);
		token = token->next;
	}
	if (ft_lstsize(*tokens) > 1 && (char)*((char *)(*tokens)->data) != '\0')
		ft_lstclear_if(tokens, is_token_empty, free);
	while (redirs)
	{
		redir = redirs->data;
		replace_env_single_token(&redir->direction, g_msh);
		redirs = redirs->next;
	}
}

/* void	replace_envs(t_list **tokens, t_list *redirs, t_msh *g_msh)
{
	t_list	*token;
	t_redir	*redir;

	token = *tokens;
	while (token)
	{
		//replace if there is dollar sign
		replace_env_single_token((char **)&token->data, g_msh);
		token = token->next;
	}
	if (ft_lstsize(*tokens) > 1 && (char)*((char *)(*tokens)->data) != '\0')
		ft_lstclear_if(tokens, is_token_empty, free);
	while (redirs)
	{
		redir = redirs->data;
		replace_env_single_token(&redir->direction, g_msh);
		redirs = redirs->next;
	}
} */

void	replace_env_single_token(char **token, t_msh *g_msh)
{
	t_list	*split_token;
	t_list	*tmp;
	char	*token_piece;

	split_token = get_split_token(*token, g_msh);
	tmp = split_token;
	while (tmp)
	{
		token_piece = tmp->data;
		if (!ft_strcmp(token_piece, "~") || !ft_strncmp(token_piece, "~/", 2))
			replace_tilde_with_home((char **)&tmp->data, g_msh);
		else if (*token_piece != '\'')
		{
			if (*token_piece == '$' && ft_strcmp(token_piece, "$_") != 0
				&& ft_strcmp(token_piece, "$?") != 0 && *(token_piece + 1) != 0)
				replace_one_var((char **)&tmp->data, g_msh);
			else
				replace_vars_with_values((char **)&tmp->data, g_msh);
			replace_status_env((char **)&tmp->data, g_msh->exit_status, g_msh);
		}
		delete_quotes((char *)tmp->data);
		tmp = tmp->next;
	}
	free(*token);
	*token = join_split_token(split_token, g_msh);
	ft_lstclear(&split_token, free);
}

/* void	replace_env_single_token(char **token, t_msh *g_msh)
{
	t_list	*split_token;
	t_list	*tmp;
	char	*token_piece;

	//save token token token
	//"$TERM"'$PATH'hello1"hel'lo2"'hel"lo3'
	//"$TERM"
	//'$PATH'
	//hello1
	//"hel'lo2"
	//'hel"lo3'

	split_token = get_split_token(*token, g_msh);
	tmp = split_token;
	while (tmp)
	{
		token_piece = tmp->data;
		if (!ft_strcmp(token_piece, "~") || !ft_strncmp(token_piece, "~/", 2))
			replace_tilde_with_home((char **)&tmp->data, g_msh);
		else if (*token_piece != '\'')
		{
			if (*token_piece == '$' && ft_strcmp(token_piece, "$_") != 0
				&& ft_strcmp(token_piece, "$?") != 0 && *(token_piece + 1) != 0)
				replace_one_var((char **)&tmp->data, g_msh);
			else
				replace_vars_with_values((char **)&tmp->data, g_msh);
			replace_status_env((char **)&tmp->data, g_msh->exit_status, g_msh);
		}
		delete_quotes((char *)tmp->data);
		tmp = tmp->next;
	}
	free(*token);
	*token = join_split_token(split_token, g_msh);
} */

void	replace_vars_with_values(char **str, t_msh *g_msh)
{
	int		i;
	char	*var;
	char	*value;
	char	*final;

	i = -1;
	while (str[0][++i])
	{
		if (str[0][i] == '$' && !ft_strchr("? ", str[0][i + 1])
			&& str[0][i + 1] != '\0')
		{
			var = get_var_name(&str[0][i], g_msh);
			if (ft_strcmp(var, "$_") == 0)
				value = get_last_exec_name((var + 1), g_msh);
			else
				value = ft_getenv((var + 1), g_msh);
			final = replace_midstring(*str, var, value, i, g_msh);
			free(*str);
			*str = final;
			free(var);
			i += ft_strlen(value) - 1;
			if (value)
				free(value);
		}
	}
}

void	replace_tilde_with_home(char **token, t_msh *g_msh)
{
	char	*home_path;

	home_path = ft_getenv("HOME", g_msh);
	if (!token[0][1])
	{
		free(*token);
		*token = home_path;
	}
	else
		tilde_join(token, &home_path, g_msh);
}

/* void	replace_tilde_with_home(char **token, t_msh *g_msh)
{
	char	*home_path;

	home_path = ft_getenv("HOME", g_msh);
	//check just '~' is given and replace with home path
	if (!token[0][1])
	{
		free(*token);
		*token = home_path;
	}
	else
	// '~' + 'path'
		tilde_join(token, &home_path, g_msh);
} */

char	*get_last_exec_name(char *underscore, t_msh *g_msh)
{
	char	*value;
	char	*temp;

	value = ft_getenv(underscore, g_msh);
	if (is_path_executable(value))
	{
		temp = ft_strdup(ft_strrchr(value, '/') + 1);
		if (temp == 0)
			quit_program(EXIT_FAILURE, g_msh);
		free(value);
		value = temp;
		return (value);
	}
	else
		return (value);
}

/* char	*get_last_exec_name(char *underscore, t_msh *g_msh)
{
	char	*value;
	char	*temp;

	//maybe not needed
	value = ft_getenv(underscore, g_msh);
	//if yes, print out end of '/ + 000000000 '
	if (is_path_executable(value))
	{
		temp = ft_strdup(ft_strrchr(value, '/') + 1);
		if (temp == 0)
			quit_program(EXIT_FAILURE, g_msh);
		free(value);
		value = temp;
		return (value);
	}
	else //else print out all path
		return (value);
} */
