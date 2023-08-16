/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:01:18 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:01:20 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include "main.h"

void	init_termcaps(t_termcaps *termcaps, t_msh *g_msh);
int		has_capabilities(t_termcaps *termcaps);
void	turn_off_canonical_mode(t_termcaps *termcaps, t_msh *g_msh);
void	turn_on_canonical_mode(t_termcaps *termcaps, t_msh *g_msh);
int		ft_putint(int c);

#endif
