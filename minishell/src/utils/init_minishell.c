/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:18:15 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/08 10:18:16 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_minishell.h"

void	init_minishell(char **envp, t_msh *g_msh)
{
	if (!isatty(STDIN_FILENO))
		quit_program(EXIT_FAILURE, g_msh);
	ft_bzero(g_msh, sizeof(t_msh));
	duplicate_env(&g_msh->dup_envp, envp, g_msh);
	unset_oldpwd(g_msh);
	increment_shlvl(g_msh);
	init_termcaps(&g_msh->termcaps, g_msh);
	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, catch_sigquit);
}

/* void	init_minishell(char **envp, t_msh *g_msh)
{
	if (!isatty(STDIN_FILENO))
		quit_program(EXIT_FAILURE, g_msh);
	ft_bzero(g_msh, sizeof(t_msh));
	duplicate_env(&g_msh->dup_envp, envp, g_msh);
	//check if there is a OLDPWD then replace if not create one.
	unset_oldpwd(g_msh);
	increment_shlvl(g_msh);
	init_termcaps(&g_msh->termcaps, g_msh);
	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, catch_sigquit);
} */