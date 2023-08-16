/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:12:21 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/15 18:33:31 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	init_termcaps(t_termcaps *termcaps, t_msh *g_msh)
{
	char	*term_type;

	if (tcgetattr(STDIN_FILENO, &termcaps->old_term) == -1)
		quit_program(EXIT_FAILURE, g_msh);
	term_type = ft_getenv("TERM", g_msh);
	if (!term_type)
		quit_program(EXIT_FAILURE, g_msh);
	if (tgetent(termcaps->buffer, term_type) <= 0)
		quit_program(EXIT_FAILURE, g_msh);
	else if (!has_capabilities(termcaps))
		quit_program(EXIT_FAILURE, g_msh);
	free(term_type);
}

/* void	init_termcaps(t_termcaps *termcaps, t_msh *g_msh)
{
	char	*term_type;

	if (tcgetattr(STDIN_FILENO, &termcaps->old_term) == -1)
		quit_program(EXIT_FAILURE, g_msh);
	//when we change the canonical mode capture the state of stdin 
	//and put it to old_term
	//so we can manipulate hou std_in works.
	term_type = ft_getenv("TERM", g_msh);
	//get whatever is after TERM in env.
	if (!term_type)
		quit_program(EXIT_FAILURE, g_msh);
	if (tgetent(termcaps->buffer, term_type) <= 0)
	//Terminal capabilities describe various aspects of 
	//how the terminal handles input and output, supports colors, 
	//handles cursor movement, and other terminal-related features.
		quit_program(EXIT_FAILURE, g_msh);
	
	else if (!has_capabilities(termcaps))
	//input capabilities
		quit_program(EXIT_FAILURE, g_msh);
	free(term_type);
} */

int	has_capabilities(t_termcaps *termcaps)
{
	int	check;

	termcaps->keys_on = tgetstr("ks", &termcaps->buffer);
	if (termcaps->keys_on)
		tputs(termcaps->keys_on, 1, ft_putint);
	termcaps->keys_off = tgetstr("ke", &termcaps->buffer);
	termcaps->up_arrow = tgetstr("ku", &termcaps->buffer);
	termcaps->down_arrow = tgetstr("kd", &termcaps->buffer);
	termcaps->backspace = tgetstr("kb", &termcaps->buffer);
	termcaps->del_line = tgetstr("dl", &termcaps->buffer);
	termcaps->set_cursor_begin = tgetstr("cr", &termcaps->buffer);
	if (!termcaps->keys_on || !termcaps->keys_off
		|| !termcaps->up_arrow || !termcaps->down_arrow
		|| !termcaps->backspace || !termcaps->del_line
		|| !termcaps->set_cursor_begin)
		check = 0;
	else
		check = 1;
	return (check);
}

//now terminal works only after pressing enter.
//put this feature of terminal in old_term.
void	turn_off_canonical_mode(t_termcaps *termcaps, t_msh *g_msh)
{
	termcaps->new_term = termcaps->old_term;
	termcaps->new_term.c_lflag &= ~(ICANON | ECHO | ISIG | IEXTEN | IXON);
	termcaps->new_term.c_cc[VMIN] = 1;
	termcaps->new_term.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &termcaps->new_term) == -1)
		quit_program(EXIT_FAILURE, g_msh);
}

//now make terminal work whenever you type something, meaning
//no need to press enter.
//put this feature of terminal in new_term.
void	turn_on_canonical_mode(t_termcaps *termcaps, t_msh *g_msh)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &termcaps->old_term) == -1)
		quit_program(EXIT_FAILURE, g_msh);
}

int	ft_putint(int c)
{
	return (write(1, &c, 1));
}
