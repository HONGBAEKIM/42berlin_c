/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_pipes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:09:38 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/15 12:07:17 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections_pipes.h"

int	**init_pipes(int nb_cmds, t_msh *g_msh)
{
	int	**pipes;
	int	i;

	if (nb_cmds == 1)
		return (0);
	pipes = ft_calloc(nb_cmds, sizeof(int *));
	if (!pipes)
		quit_program(EXIT_FAILURE, g_msh);
	i = 0;
	while (i < nb_cmds - 1)
	{
		pipes[i] = ft_calloc(2, sizeof(int));
		if (!pipes[i])
			quit_program(EXIT_FAILURE, g_msh);
		if (pipe(pipes[i]) == -1)
			quit_program(EXIT_FAILURE, g_msh);
		i++;
	}
	return (pipes);
}

void	set_redirs_pipes(t_list *redirs,
						t_cmd_table *cmd_table,
						int process_index, t_msh *g_msh)
{
	int	**pipes;
	int	nb_cmds;

	pipes = cmd_table->pipes;
	nb_cmds = cmd_table->nb_cmds;
	if (open_all_files(redirs, g_msh) == EXIT_FAILURE)
		return ;
	if (!has_redirs(redirs, "<") && (!has_redirs(redirs, "<<") \
	&& process_index != 0))
		dup2(pipes[process_index - 1][0], STDIN_FILENO);
	if (!has_redirs(redirs, ">") && !has_redirs(redirs, ">>") \
	&& process_index != nb_cmds - 1)
		dup2(pipes[process_index][1], STDOUT_FILENO);
	g_msh->exit_status = EXIT_SUCCESS;
}

int	has_redirs(t_list *redirs, char *type)
{
	int		check;
	t_redir	*redir;

	check = 0;
	while (redirs)
	{
		redir = (t_redir *)redirs->data;
		if (!ft_strcmp(redir->type, type))
		{
			check = 1;
			break ;
		}
		redirs = redirs->next;
	}
	return (check);
}

int	open_all_files(t_list *redirs, t_msh *g_msh)
{
	int		fd_i;
	int		fd_o;
	t_redir	*redir;

	fd_i = -2;
	fd_o = -2;
	while (redirs)
	{
		redir = (t_redir *)redirs->data;
		if (!ft_strcmp(redir->type, "<"))
			fd_i = of(redir, fd_i, O_RDONLY, 0, g_msh);
		else if (!ft_strcmp(redir->type, "<<"))
		{
			read_heredoc_file(redir, g_msh);
			fd_i = open_hd_file(redir, fd_i, O_RDONLY | O_CREAT, 0644, g_msh);
		}
		else if (!ft_strcmp(redir->type, ">>"))
			fd_o = of(redir, fd_o, O_WRONLY | O_CREAT | O_APPEND, 0666, g_msh);
		else if (!ft_strcmp(redir->type, ">"))
			fd_o = of(redir, fd_o, O_WRONLY | O_CREAT | O_TRUNC, 0666, g_msh);
		if (fd_i == -1 || fd_o == -1)
			return (EXIT_FAILURE);
		redirs = redirs->next;
	}
	return (EXIT_SUCCESS);
}

/* int	open_all_files(t_list *redirs, t_msh *g_msh)
{
	int		fd_i;
	int		fd_o;
	t_redir	*redir;

	fd_i = -2;
	fd_o = -2;
	while (redirs)
	{
		redir = (t_redir *)redirs->data;
		if (!ft_strcmp(redir->type, "<"))
			fd_i = of(redir, fd_i, O_RDONLY, 0, g_msh);
		else if (!ft_strcmp(redir->type, "<<"))
		{
			read_heredoc_file(redir, g_msh);
			fd_i = open_heredoc_file(redir, fd_i, O_RDONLY | O_CREAT, 0, g_msh);
		}
		else if (!ft_strcmp(redir->type, ">"))
			fd_o = of(redir, fd_o, O_WRONLY | O_CREAT | O_TRUNC, \
			0666, g_msh);
		else if (!ft_strcmp(redir->type, ">>"))
			fd_o = of(redir, fd_o, O_WRONLY | O_CREAT | O_APPEND, \
			0666, g_msh);
		if (fd_i == -1 || fd_o == -1)
			return (EXIT_FAILURE);
		redirs = redirs->next;
	}
	return (EXIT_SUCCESS);
} */

int	of(t_redir *redir, int prev_fd, int flags, mode_t permissions, \
t_msh *g_msh)
{
	char	*file_name;
	int		new_fd;

	if (prev_fd != -2)
		close(prev_fd);
	file_name = redir->direction;
	new_fd = open(file_name, flags, permissions);
	if (new_fd == -1)
	{
		write_msh_exec_error(file_name, strerror(errno));
		g_msh->exit_status = errno;
	}
	else
	{
		if (!ft_strcmp(redir->type, "<") || !ft_strcmp(redir->type, "<<"))
			dup2(new_fd, STDIN_FILENO);
		else if (!ft_strcmp(redir->type, ">") || !ft_strcmp(redir->type, ">>"))
			dup2(new_fd, STDOUT_FILENO);
		close(new_fd);
	}
	return (new_fd);
}
