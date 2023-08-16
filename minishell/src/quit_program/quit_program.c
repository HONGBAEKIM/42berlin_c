/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:17:22 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:59:55 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit_program.h"

void	quit_program(int exit_code, t_msh *g_msh)
{
	t_termcaps	*termcaps;

	termcaps = &g_msh->termcaps;
	if (termcaps->keys_off)
		tputs(termcaps->keys_off, 1, ft_putint);
	turn_on_canonical_mode(termcaps, g_msh);
	free_msh(g_msh);
	exit(exit_code);
}
