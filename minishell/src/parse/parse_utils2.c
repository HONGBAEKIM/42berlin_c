/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:14:20 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/08 10:14:21 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"

int	is_cmd_table_delimiter(const char *str)
{
	int	check;

	if (*str == ';')
		check = 1;
	else if (!ft_strncmp((char *)str, "||", 2))
		check = 1;
	else if (!ft_strncmp((char *)str, "&&", 2))
		check = 1;
	else
		check = 0;
	return (check);
}

int	is_cmd_delimiter(char c)
{
	int	check;

	if (c == ';')
		check = 1;
	else if (c == '|')
		check = 1;
	else if (c == '&')
		check = 1;
	else
		check = 0;
	return (check);
}

int	is_token_delimiter(char c)
{
	int	check;

	if (ft_strchr(WHITE_SPACE, c) != 0)
		check = 1;
	else if (c == ';')
		check = 1;
	else if (c == '|')
		check = 1;
	else if (c == '&')
		check = 1;
	else if (c == '<')
		check = 1;
	else if (c == '>')
		check = 1;
	else
		check = 0;
	return (check);
}

char	*get_cmd_table_delimiter(const char *input, int *curr_pos, t_msh *g_msh)
{
	char	*delimiter;

	delimiter = 0;
	if (input[*curr_pos] == '\0')
		delimiter = ft_strdup("");
	else if (input[*curr_pos] == ';')
		delimiter = ft_strdup(";");
	else if (!ft_strncmp((char *)&input[*curr_pos], "||", 2))
		delimiter = ft_strdup("||");
	else if (!ft_strncmp((char *)&input[*curr_pos], "&&", 2))
		delimiter = ft_strdup("&&");
	if (!delimiter)
		quit_program(EXIT_FAILURE, g_msh);
	(*curr_pos) += ft_strlen(delimiter);
	return (delimiter);
}

int	is_ctrl(char c)
{
	int	check;

	if (c == CTRL_C || c == CTRL_D || c == ENTER_KEYCAP)
		check = 0;
	else if ((0 <= c && c <= 31) || c == 127)
		check = 1;
	else
		check = 0;
	return (check);
}
