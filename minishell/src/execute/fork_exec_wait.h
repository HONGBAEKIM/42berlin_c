/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec_wait.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:00:54 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:44:21 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_EXEC_WAIT_H
# define FORK_EXEC_WAIT_H

# include "main.h"

void	exec_child(char **tokens, char **envp, int nb_cmds, int **pipes, \
t_msh *g_msh);
void	exec_parent(t_list **pids, t_msh *g_msh);
void	close_all_pipes(int **pipes, int nb_cmds);

#endif
