/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:17:13 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:59:48 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_memory.h"

void	free_msh(t_msh *msh)
{
	ft_dlstclear(&msh->input_history, free);
	ft_lstclear(&msh->dup_envp, free);
	if (msh->ast != 0)
		free_ast(msh->ast);
}

void	free_ast(t_ast *ast)
{
	ft_lstclear(&ast->cmd_tables, free_cmd_table);
	free(ast);
}

void	free_cmd_table(void *cmd_table)
{
	ft_lstclear(&((t_cmd_table *)cmd_table)->cmds, free_cmd);
	free(((t_cmd_table *)cmd_table)->delimiter);
	free(cmd_table);
}

void	free_cmd(void *cmd)
{
	ft_lstclear(&((t_cmd *)cmd)->tokens, free);
	ft_lstclear(&((t_cmd *)cmd)->redirs, free_redir);
	free(cmd);
}

void	free_redir(void *redir)
{
	free(((t_redir *)redir)->direction);
	free(redir);
}
