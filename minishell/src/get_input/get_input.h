/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:01:10 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:59:29 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_INPUT_H
# define GET_INPUT_H

# include "main.h"

/*
** File get_input1.c
*/

char	*get_input(t_dlist *input_history, t_termcaps *termcaps, t_msh *g_msh);
int		is_up_down_arrow(char *buf, t_termcaps *termcaps);
void	parse_input_history(t_dlist **input_history,
			t_termcaps *termcaps,
			char *buf,
			int *i);
int		has_history(t_dlist *input_history, t_termcaps *termcaps, char *buf);
void	delete_single_char(t_termcaps *termcaps, char *buf, int *i);

/*
** File get_input2.c
*/

void	reset_cmd_line(char *buf, int *i, t_dlist **input_history, \
t_msh *g_msh);
void	exit_program(char *buf, int i, t_msh *g_msh);
char	*extract_input(char *buf, int i, t_msh *g_msh);

#endif
