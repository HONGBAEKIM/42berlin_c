/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:59:26 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/14 14:00:21 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

t_list	*get_split_token(char *token, t_msh *g_msh)
{
	t_list	*split_token;
	t_list	*new_node;
	char	*token_piece;
	int		curr_pos;
	int		saved_pos;

	split_token = NULL;
	curr_pos = 0;
	saved_pos = 0;
	while (token[curr_pos])
	{
		saved_pos = curr_pos;
		if (is_quote(token[curr_pos]))
			skip_quotes((const char *)token, &curr_pos);
		else
			skip_letters((const char *)token, &curr_pos);
		token_piece = ft_substr(token, saved_pos, curr_pos - saved_pos);
		if (!token_piece)
			handle_memory_error(split_token, g_msh);
		new_node = ft_lstnew((void *)token_piece);
		if (!new_node)
			hme_with_token_piece(token_piece, split_token, g_msh);
		ft_lstadd_back(&split_token, new_node);
	}
	return (split_token);
}

/* t_list	*get_split_token(char *token, t_msh *g_msh)
{
	t_list	*split_token;
	t_list	*new_node;
	char	*token_piece;
	int		curr_pos;
	int		saved_pos;

	split_token = NULL;
	curr_pos = 0;
	saved_pos = 0;
	while (token[curr_pos])
	{
		saved_pos = curr_pos;
		if (is_quote(token[curr_pos]))
			skip_quotes((const char *)token, &curr_pos);
		else
			skip_letters((const char *)token, &curr_pos);
		token_piece = ft_substr(token, saved_pos, curr_pos - saved_pos);
		if (!token_piece)
		{
			ft_lstclear(&split_token, free);
			quit_program(EXIT_FAILURE, g_msh);
		}
		new_node = ft_lstnew((void *)token_piece);
		if (!new_node)
		{
			free(token_piece);
			ft_lstclear(&split_token, free);
			quit_program(EXIT_FAILURE, g_msh);
		}
		ft_lstadd_back(&split_token, new_node);
		free(token_piece);
	}
	if (new_node)
		ft_lstclear(&new_node, free);
	return (split_token);
} */

char	*join_split_token(t_list *split_token, t_msh *g_msh)
{
	char	*token;
	int		new_token_size;

	new_token_size = get_new_token_size(split_token);
	token = ft_calloc(new_token_size + 1, sizeof(char));
	if (!token)
		quit_program(EXIT_FAILURE, g_msh);
	while (split_token)
	{
		ft_strcat(token, (char *)split_token->data);
		split_token = split_token->next;
	}
	ft_lstclear(&split_token, free);
	return (token);
}

/* 
//list to array
char	*join_split_token(t_list *split_token, t_msh *g_msh)
{
	char	*token;
	int		new_token_size;

	new_token_size = get_new_token_size(split_token);
	token = ft_calloc(new_token_size + 1, sizeof(char));
	if (!token)
		quit_program(EXIT_FAILURE, g_msh);
	while (split_token)
	{
		ft_strcat(token, (char *)split_token->data);
		split_token = split_token->next;
	}
	ft_lstclear(&split_token, free);
	return (token);
} */

int	get_new_token_size(t_list *split_token)
{
	int		size;
	char	*token;

	size = 0;
	while (split_token)
	{
		token = split_token->data;
		size += ft_strlen(token);
		split_token = split_token->next;
	}
	return (size);
}

void	replace_one_var(char **str, t_msh *g_msh)
{
	char	*env;
	char	*trimmed;

	env = ft_getenv((*str + 1), g_msh);
	if (!env)
	{
		free(*str);
		*str = ft_strdup("");
		if (!*str)
			quit_program(EXIT_FAILURE, g_msh);
		return ;
	}
	trimmed = ft_strtrim(env, " ");
	if (!trimmed)
		quit_program(EXIT_FAILURE, g_msh);
	free(env);
	free(*str);
	*str = trimmed;
}

/* void	replace_one_var(char **str, t_msh *g_msh)
{
	char	*env;
	char	*trimmed;

	//skip '$'
	env = ft_getenv((*str + 1), g_msh);
	if (!env)
	{
		free(*str);
		*str = ft_strdup("");
		if (!*str)
			quit_program(EXIT_FAILURE, g_msh);
		return ;
	}
	//delete all white space from beginning and end.
	trimmed = ft_strtrim(env, " ");
	if (!trimmed)
		quit_program(EXIT_FAILURE, g_msh);
	free(env);
	free(*str);
	*str = trimmed;
} */
