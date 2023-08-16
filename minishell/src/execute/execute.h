/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:00:49 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:53:07 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "main.h"

void	exec_ast(t_ast *ast, t_msh *g_msh);
void	exec_cmd_table(t_cmd_table *cmd_table, t_msh *g_msh);
void	exec_cmd(t_cmd *cmd, t_cmd_table *cmd_table, int process_index, \
t_msh *g_msh);
void	exec_builtin(t_list *tokens,
			t_list **env,
			int nb_cmds,
			int process_index, t_msh *g_msh);
void	exec_program(t_list *lst_tokens, t_cmd_table *cmd_table, t_msh *g_msh);

#endif
