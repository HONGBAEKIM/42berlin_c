/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:51:46 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/08 09:51:50 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_echo.h"

int	ft_echo(t_list *tokens)
{
	int		line_break;
	int		flag_time;
	char	*arg;

	flag_time = 1;
	line_break = 1;
	while (tokens)
	{
		arg = tokens->data;
		if (flag_time && arg[0] == '-' && has_repeated_char_in_str('n', arg, 1))
			line_break = 0;
		else
		{
			if (!flag_time)
				ft_putchar_fd(' ', STDOUT_FILENO);
			flag_time = 0;
			ft_putstr_fd(arg, STDOUT_FILENO);
		}
		tokens = tokens->next;
	}
	if (line_break)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

int	has_repeated_char_in_str(char repeat_chr, char *str, unsigned int start)
{
	unsigned int	i;

	i = start;
	while (str[i])
	{
		if (str[i] != repeat_chr)
			return (0);
		i++;
	}
	return (1);
}
