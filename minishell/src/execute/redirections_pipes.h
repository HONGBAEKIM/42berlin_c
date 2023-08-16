/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_pipes.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:01:05 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/15 11:58:44 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_PIPES_H
# define REDIRECTIONS_PIPES_H

# include "main.h"

int		**init_pipes(int nb_cmds, t_msh *g_msh);
void	set_redirs_pipes(t_list *redirs,
			t_cmd_table *cmd_table,
			int process_index, t_msh *g_msh);
int		has_redirs(t_list *redirs, char *type);
int		open_all_files(t_list *redirs, t_msh *g_msh);
int		of(t_redir *redir, int prev_fd, int flags, mode_t permissions, \
t_msh *g_msh);

#endif
