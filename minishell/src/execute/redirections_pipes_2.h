/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_pipes_2.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:01:02 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/15 18:20:34 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_PIPES_2_H
# define REDIRECTIONS_PIPES_2_H

# include "main.h"

int		open_hd_file(t_redir *redir, int prev_fd, int flags, \
mode_t permissions, t_msh *g_msh);
void	read_heredoc_file(t_redir *redir, t_msh *g_msh);
void	read_heredoc_file_2(char *whole_str, t_redir *redir, \
t_msh *g_msh);

#endif
