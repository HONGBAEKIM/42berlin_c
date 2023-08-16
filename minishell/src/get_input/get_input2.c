/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:10:24 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:57:49 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_input.h"

void	reset_cmd_line(char *buf, int *i, t_dlist **input_history, t_msh *g_msh)
{
	write(STDOUT_FILENO, "^C\n", ft_strlen("^C\n"));
	g_msh->exit_status = EXIT_CMD_INTERRUPTED;
	write_prompt();
	ft_bzero(buf, BUFSIZ);
	*i = 0;
	if (*input_history)
	{
		while ((*input_history)->prev)
			*input_history = (*input_history)->prev;
	}
}

/* void	reset_cmd_line(char *buf, int *i, t_dlist **input_history, t_msh *g_msh)
{
	write(STDOUT_FILENO, "^C\n", ft_strlen("^C\n"));
	g_msh->exit_status = EXIT_CMD_INTERRUPTED;
	write_prompt();
	ft_bzero(buf, BUFSIZ);
	*i = 0;
	//rewind all the history
	if (*input_history)
	{
		while ((*input_history)->prev)
			*input_history = (*input_history)->prev;
	}
} */

void	exit_program(char *buf, int i, t_msh *g_msh)
{
	if (i > 0)
	{
		buf[i] = '\0';
		return ;
	}
	ft_putstr_fd("exit\n", STDERR_FILENO);
	quit_program(g_msh->exit_status, g_msh);
}

/* void	exit_program(char *buf, int i, t_msh *g_msh)
{
	// ^D we make it '\0'
	if (i > 0)
	{
		buf[i] = '\0';
		return ;
	}
	ft_putstr_fd("exit\n", STDERR_FILENO);
	quit_program(g_msh->exit_status, g_msh);
} */

char	*extract_input(char *buf, int i, t_msh *g_msh)
{
	char	*input;

	buf[i - 1] = '\0';
	input = ft_strdup(buf);
	if (!input)
		quit_program(EXIT_FAILURE, g_msh);
	return (input);
}
