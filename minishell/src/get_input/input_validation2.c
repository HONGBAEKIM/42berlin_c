/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:11:48 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:58:07 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"

int	has_char_at_end(const char *input, char c, char *err_message, t_msh *g_msh)
{
	int		check;
	char	*cpy;
	int		len;

	cpy = ft_strtrim(input, WHITE_SPACE);
	if (!cpy)
		quit_program(EXIT_FAILURE, g_msh);
	len = ft_strlen(cpy);
	if (cpy[len - 1] == c)
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

int	has_forbidden_sequence(const char *input, char *test, char *err_message, \
t_msh *g_msh)
{
	int		check;
	char	*trimmed;

	trimmed = ft_strtrim_all(input, WHITE_SPACE);
	if (!trimmed)
		quit_program(EXIT_FAILURE, g_msh);
	if (ft_strstr_quotes(trimmed, test) != 0)
	{
		check = 1;
		ft_strcpy(err_message, "syntax error near unexpected token `");
		ft_strlcat(err_message, test, 1);
		ft_strcat(err_message, "'");
	}
	else
		check = 0;
	free(trimmed);
	return (check);
}

int	has_spaces_between_char(const char *input, char c, char *err_message)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			skip_quotes(input, &i);
		if (input[i] == c && input[i + 1] == ' ')
		{
			i++;
			skip_spaces((char *)input, &i);
			if (input[i] == c)
			{
				ft_strcpy(err_message, "syntax error near unexpected token `");
				ft_strlcat(err_message, &c, 1);
				ft_strcat(err_message, "'");
				return (1);
			}
		}
		if (input[i])
			i++;
	}
	return (0);
}

int	has_non_supported(const char *input, char *test, char *err_message)
{
	int		check;

	if (ft_strstr_quotes((char *)input, test) != 0)
	{
		check = 1;
		ft_strcpy(err_message, "\"");
		ft_strcat(err_message, test);
		ft_strcat(err_message, "\" not supported");
	}
	else
		check = 0;
	return (check);
}

int	has_non_supported_one(const char *input, char *test, char *err_message)
{
	int		check;
	char	*tmp;

	check = 0;
	tmp = (char *)input;
	while (tmp)
	{
		tmp = ft_strstr_quotes(tmp, test);
		if (tmp != 0 && *(tmp + 1) != *test)
		{
			check = 1;
			break ;
		}
		else if (tmp != 0 && *(tmp + 1) == *test)
			tmp += 2;
	}
	if (check)
	{
		ft_strcpy(err_message, "\"");
		ft_strcat(err_message, test);
		ft_strcat(err_message, "\" not supported");
	}
	return (check);
}
