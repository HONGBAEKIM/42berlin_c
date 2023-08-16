/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:03:10 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:44:01 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_exec_wait.h"

void	exec_child(char **tokens, char **envp, int nb_cmds, int **pipes, \
t_msh *g_msh)
{
	char	*exec_path;

	signal(SIGINT, SIG_DFL);
	close_all_pipes(pipes, nb_cmds);
	if (has_relative_path(tokens[0]) || has_absolute_path(tokens[0]))
	{
		exec_path = ft_strdup(tokens[0]);
		if (!exec_path)
			quit_program(EXIT_FAILURE, g_msh);
	}
	else
		exec_path = get_absolute_path(tokens[0], g_msh);
	execve(exec_path, tokens, envp);
	if (errno == EACCES)
		write_msh_exec_error(tokens[0], "Permission denied");
	else if (errno == ENOENT && ft_strcmp(tokens[0], "exit") != 0)
		write_msh_exec_error(tokens[0], "command not found");
	free(exec_path);
	free(tokens);
	free(envp);
	if (errno == EACCES)
		exit(EXIT_CMD_INTERRUPTED);
	else if (errno == ENOENT)
		exit(EXIT_CMD_NOT_FOUND);
	exit(errno);
}

/* 
void	exec_child(char **tokens, char **envp, int nb_cmds, int **pipes, \
 *g_msh)
{
	char	*exec_path;

	signal(SIGINT, SIG_DFL);
	close_all_pipes(pipes, nb_cmds);
	if (has_relative_path(tokens[0]) || has_absolute_path(tokens[0]))
	{
		exec_path = ft_strdup(tokens[0]);
		if (!exec_path)
			quit_program(EXIT_FAILURE, g_msh);
	}
	else
		exec_path = get_absolute_path(tokens[0], g_msh);
	//something is run, remove and replace 
	execve(exec_path, tokens, envp);
	if (errno == EACCES)
		write_msh_exec_error(tokens[0], "Permission denied");
	else if (errno == ENOENT && ft_strcmp(tokens[0], "exit") != 0)
		write_msh_exec_error(tokens[0], "command not found");
	free(exec_path);
	free(tokens);
	free(envp);
	if (errno == EACCES)
		exit(EXIT_CMD_INTERRUPTED);
	else if (errno == ENOENT)
		exit(EXIT_CMD_NOT_FOUND);
	exit(errno);
} 
*/

void	exec_parent(t_list **pids, t_msh *g_msh)
{
	long	pid;
	int		exit_info;

	exit_info = 0;
	while (*pids)
	{
		pid = (long)(*pids)->data;
		waitpid(pid, &exit_info, 0);
		if (WIFEXITED(exit_info))
			g_msh->exit_status = WEXITSTATUS(exit_info);
		else if (WIFSIGNALED(exit_info))
			g_msh->exit_status = WTERMSIG(exit_info);
		ft_lstdel_first(pids, ft_lstdel_int);
	}
}

/* void	exec_parent(t_list **pids, t_msh *g_msh)
{
	long	pid;
	int		exit_info;

	exit_info = 0;
	while (*pids)
	{
		pid = (long)(*pids)->data;
		//the parent process forks a child process, 
		//and then it waits for the child process to complete using waitpid
		waitpid(pid, &exit_info, 0);
		if (WIFEXITED(exit_info))
			g_msh->exit_status = WEXITSTATUS(exit_info);
		else if (WIFSIGNALED(exit_info))
			g_msh->exit_status = WTERMSIG(exit_info);
		ft_lstdel_first(pids, ft_lstdel_int);
	}
} */

void	close_all_pipes(int **pipes, int nb_cmds)
{
	int	i;
	int	nb_pipes;

	i = 0;
	nb_pipes = nb_cmds - 1;
	while (i < nb_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}
