/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:01:37 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:01:39 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MEMORY_H
# define FREE_MEMORY_H

# include "main.h"

void	free_msh(t_msh *msh);
void	free_ast(t_ast *ast);
void	free_cmd_table(void *cmd_table);
void	free_cmd(void *cmd);
void	free_redir(void *redir);

#endif
