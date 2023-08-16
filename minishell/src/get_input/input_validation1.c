/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:10:44 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:55:51 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"

int	is_input_valid(const char *input, t_msh *g_msh)
{
	int		check;
	char	err_message[100];

	ft_bzero(err_message, 0);
	if (*input == '\0' || ft_strisspace((char *)input))
		check = 0;
	else if (!is_input_valid_unexpected_token(input, err_message, g_msh)
		|| !is_input_valid_not_supported(input, err_message))
	{
		check = 0;
		g_msh->exit_status = ENOEXEC;
		write_msh_error(err_message);
	}
	else
		check = 1;
	return (check);
}

/* int	is_input_valid(const char *input, t_msh *g_msh)
{
	int		check;
	char	err_message[100];

	ft_bzero(err_message, 0);
	if (*input == '\0' || ft_strisspace((char *)input))
		check = 0;
	else if (!is_input_valid_unexpected_token(input, err_message, g_msh)
		|| !is_input_valid_not_supported(input, err_message))
	{
		check = 0;
		// error number for exit_status
		g_msh->exit_status = ENOEXEC;
		write_msh_error(err_message);
	}
	else
		check = 1;
	return (check);
} */

int	is_input_valid_unexpected_token(const char *input, char *err_message, \
t_msh *g_msh)
{
	int		check;

	if (has_quotes_open(input, err_message)
		|| has_char_at_beginning(input, '|', err_message, g_msh)
		|| has_char_at_beginning(input, ';', err_message, g_msh)
		|| has_char_at_end(input, '|', err_message, g_msh)
		|| has_char_at_end(input, '<', err_message, g_msh)
		|| has_char_at_end(input, '>', err_message, g_msh)
		|| has_char_at_end(input, '&', err_message, g_msh)
		|| has_forbidden_sequence(input, ";;", err_message, g_msh)
		|| has_forbidden_sequence(input, "|;", err_message, g_msh)
		|| has_forbidden_sequence(input, "&;", err_message, g_msh)
		|| has_forbidden_sequence(input, ";|", err_message, g_msh)
		|| has_forbidden_sequence(input, ";&", err_message, g_msh)
		|| has_forbidden_sequence(input, ">>>", err_message, g_msh)
		|| has_spaces_between_char(input, '|', err_message)
		|| has_spaces_between_char(input, '>', err_message))
		check = 0;
	else
		check = 1;
	return (check);
}

int	is_input_valid_not_supported(const char *input, char *err_message)
{
	int		check;

	if (has_non_supported(input, "*", err_message)
		|| has_non_supported(input, "\\", err_message)
		|| has_non_supported_one(input, "&", err_message))
		check = 0;
	else
		check = 1;
	return (check);
}

int	has_quotes_open(const char *input, char *err_message)
{
	int	check;
	int	has_dquotes_open;
	int	has_squotes_open;

	check = 1;
	has_dquotes_open = 0;
	has_squotes_open = 0;
	while (*input)
	{
		if (*input == '"' && has_squotes_open == 0)
			has_dquotes_open = !has_dquotes_open;
		else if (*input == '\'' && has_dquotes_open == 0)
			has_squotes_open = !has_squotes_open;
		input++;
	}
	if (has_dquotes_open || has_squotes_open)
	{
		check = 1;
		ft_strcpy(err_message, "syntax error: open quotes");
	}
	else
		check = 0;
	return (check);
}

int	has_char_at_beginning(const char *input, char c, char *err_message, \
t_msh *g_msh)
{
	int		check;
	char	*cpy;

	cpy = ft_strtrim(input, WHITE_SPACE);
	if (!cpy)
		quit_program(EXIT_FAILURE, g_msh);
	if (cpy[0] == c)
	{
		check = 1;
		ft_strcpy(err_message, "syntax error near unexpected token `");
		ft_strlcat(err_message, &c, 1);
		ft_strlcat(err_message, "'", 2);
	}
	else
		check = 0;
	free(cpy);
	return (check);
}
