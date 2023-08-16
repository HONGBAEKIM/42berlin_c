/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:07:16 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:58:51 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_input.h"

char	*get_input(t_dlist *input_history, t_termcaps *termcaps, t_msh *g_msh)
{
	char	*input;
	char	buf[BUFSIZ];
	int		i;
	int		nb_char_read;

	i = 0;
	ft_bzero(buf, BUFSIZ);
	while (!ft_strchr(buf, '\n'))
	{
		nb_char_read = read(STDIN_FILENO, &buf[i], BUFSIZ - i);
		if (is_up_down_arrow(&buf[i], termcaps))
			parse_input_history(&input_history, termcaps, buf, &i);
		else if (!ft_strcmp(&buf[i], termcaps->backspace))
			delete_single_char(termcaps, buf, &i);
		else if (nb_char_read > 2 || (nb_char_read == 1 && is_ctrl(buf[i])))
			ft_bzero(&buf[i], BUFSIZ - i);
		else if (buf[i] == CTRL_C)
			reset_cmd_line(buf, &i, &input_history, g_msh);
		else if (buf[i] == CTRL_D)
			exit_program(buf, i, g_msh);
		else
			i += write(STDOUT_FILENO, &buf[i], nb_char_read);
	}
	input = extract_input(buf, i, g_msh);
	return (input);
}

/* char	*get_input(t_dlist *input_history, t_termcaps *termcaps, t_msh *g_msh)
{
	char	*input;
	char	buf[BUFSIZ];
	int		i;
	int		nb_char_read;

	i = 0;
	ft_bzero(buf, BUFSIZ);
	while (!ft_strchr(buf, '\n'))
	{
		// read as much as possible with (BUFSIZ - i)// &buf[i] points
		//to the memory address starting position. We use BUFSIZ so
		//we don't have buffer overflow while reading.
		nb_char_read = read(STDIN_FILENO, &buf[i], BUFSIZ - i);
		if (is_up_down_arrow(&buf[i], termcaps))
			parse_input_history(&input_history, termcaps, buf, &i);
		else if (!ft_strcmp(&buf[i], termcaps->backspace))
			delete_single_char(termcaps, buf, &i);
		else if (nb_char_read > 2 || (nb_char_read == 1 && is_ctrl(buf[i])))
			ft_bzero(&buf[i], BUFSIZ - i);
		else if (buf[i] == CTRL_C)
			reset_cmd_line(buf, &i, &input_history, g_msh);
		else if (buf[i] == CTRL_D)
			exit_program(buf, i, g_msh);
		else
			i += write(STDOUT_FILENO, &buf[i], nb_char_read);
	}
	input = extract_input(buf, i, g_msh);
	return (input);
} */

int	is_up_down_arrow(char *buf, t_termcaps *termcaps)
{
	int	check;

	if (!ft_strcmp(termcaps->up_arrow, buf))
		check = 1;
	else if (!ft_strcmp(termcaps->down_arrow, buf))
		check = 1;
	else
		check = 0;
	return (check);
}

void	parse_input_history(t_dlist **input_history,
							t_termcaps *termcaps,
							char *buf,
							int *i)
{
	char	*input;

	if (!has_history(*input_history, termcaps, &buf[*i]))
	{
		ft_bzero(&buf[*i], BUFSIZ - *i);
		return ;
	}
	if (!ft_strcmp(termcaps->up_arrow, &buf[*i]) && !(*input_history)->next)
		input = (*input_history)->data;
	else if (!ft_strcmp(termcaps->up_arrow, &buf[*i]))
	{
		input = (*input_history)->data;
		*input_history = (*input_history)->next;
	}
	else if (!ft_strcmp(termcaps->down_arrow, &buf[*i]))
	{
		*input_history = (*input_history)->prev;
		input = (*input_history)->data;
	}
	tputs(termcaps->del_line, 1, ft_putint);
	tputs(termcaps->set_cursor_begin, 1, ft_putint);
	write_prompt();
	ft_bzero(buf, BUFSIZ);
	ft_strcpy(buf, input);
	*i = write(STDOUT_FILENO, buf, ft_strlen(buf));
}

/* void	parse_input_history(t_dlist **input_history,
							t_termcaps *termcaps,
							char *buf,
							int *i)
{
	char	*input;

	if (!has_history(*input_history, termcaps, &buf[*i]))
	{
		ft_bzero(&buf[*i], BUFSIZ - *i);
		return ;
	}
	if (!ft_strcmp(termcaps->up_arrow, &buf[*i]) && !(*input_history)->next)
	//first up_arrow
		input = (*input_history)->data;
	else if (!ft_strcmp(termcaps->up_arrow, &buf[*i]))
	//more than one up_arrow
	{
		input = (*input_history)->data;
		*input_history = (*input_history)->next;
	}
	else if (!ft_strcmp(termcaps->down_arrow, &buf[*i]))
	{
		*input_history = (*input_history)->prev;
		input = (*input_history)->data;
	}
	//ft_putint returns 1, because write functions returns 1 upon called
	//but write never prints int.
	tputs(termcaps->del_line, 1, ft_putint);
	tputs(termcaps->set_cursor_begin, 1, ft_putint);
	write_prompt();
	ft_bzero(buf, BUFSIZ);
	ft_strcpy(buf, input);
	*i = write(STDOUT_FILENO, buf, ft_strlen(buf));
} */

int	has_history(t_dlist *input_history, t_termcaps *termcaps, char *buf)
{
	int	check;

	if (!input_history)
		check = 0;
	else if (!ft_strcmp(termcaps->down_arrow, buf) && !input_history->prev)
		check = 0;
	else
		check = 1;
	return (check);
}

void	delete_single_char(t_termcaps *termcaps, char *buf, int *i)
{
	int	nb_char_to_delete;

	if (*i == 0 || ft_isascii(buf[*i - 1]))
		nb_char_to_delete = 1;
	else
		nb_char_to_delete = 2;
	ft_bzero(&buf[*i - nb_char_to_delete], BUFSIZ - *i + nb_char_to_delete);
	tputs(termcaps->del_line, 1, ft_putint);
	tputs(termcaps->set_cursor_begin, 1, ft_putint);
	write_prompt();
	*i = write(STDOUT_FILENO, buf, ft_strlen(buf));
}

/* void	delete_single_char(t_termcaps *termcaps, char *buf, int *i)
{
	int	nb_char_to_delete;

	if (*i == 0 || ft_isascii(buf[*i - 1]))
		nb_char_to_delete = 1;
	else
		nb_char_to_delete = 2;
	ft_bzero(&buf[*i - nb_char_to_delete], BUFSIZ - *i + nb_char_to_delete);
	//keep the buffer open to use
	tputs(termcaps->del_line, 1, ft_putint);
	tputs(termcaps->set_cursor_begin, 1, ft_putint);
	write_prompt();
	*i = write(STDOUT_FILENO, buf, ft_strlen(buf));
} */