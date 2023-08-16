/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:13:45 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/08 10:13:46 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"

char	*ft_strstr_quotes(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (!(*to_find))
		return (str);
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			skip_quotes(str, &i);
		if (!ft_strncmp(&str[i], to_find, ft_strlen(to_find)))
			return (&str[i]);
		if (str[i])
			i++;
	}
	return (0);
}

void	skip_quotes(const char *input, int *curr_pos)
{
	int		has_double_quotes_open;
	int		has_single_quotes_open;

	has_double_quotes_open = 0;
	has_single_quotes_open = 0;
	while (input[*curr_pos])
	{
		if (input[*curr_pos] == '"' && has_single_quotes_open == 0)
			has_double_quotes_open = !has_double_quotes_open;
		else if (input[*curr_pos] == '\'' && has_double_quotes_open == 0)
			has_single_quotes_open = !has_single_quotes_open;
		(*curr_pos)++;
		if (!has_double_quotes_open && !has_single_quotes_open)
			break ;
	}
}

void	skip_spaces(const char *input, int *curr_pos)
{
	while (input[*curr_pos] && ft_isspace(input[*curr_pos]))
		(*curr_pos)++;
}

void	skip_letters(const char *input, int *curr_pos)
{
	if (input[*curr_pos] == '$' || input[*curr_pos] == '/')
		(*curr_pos)++;
	while (input[*curr_pos] && !is_quote(input[*curr_pos])
		&& input[*curr_pos] != '$' && input[*curr_pos] != '/')
		(*curr_pos)++;
}

void	delete_quotes(char *token)
{
	int	i;
	int	has_double_quotes_open;
	int	has_single_quotes_open;

	i = 0;
	has_double_quotes_open = 0;
	has_single_quotes_open = 0;
	while (token[i])
	{
		if (token[i] == '"' && has_single_quotes_open == 0)
		{
			has_double_quotes_open = !has_double_quotes_open;
			ft_strcpy(&token[i], (const char *)&token[i + 1]);
			continue ;
		}
		else if (token[i] == '\'' && has_double_quotes_open == 0)
		{
			has_single_quotes_open = !has_single_quotes_open;
			ft_strcpy(&token[i], (const char *)&token[i + 1]);
			continue ;
		}
		i++;
	}
}
