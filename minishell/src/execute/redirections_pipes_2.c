/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_pipes_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:11:36 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/15 18:20:00 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections_pipes_2.h"

void	catch_sigint_hd(int signum)
{
	(void)signum;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	g_code_exit = 1;
}

int	open_hd_file(t_redir *redir, int prev_fd, int flags, \
mode_t permissions, t_msh *g_msh)
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
		if (!ft_strcmp(redir->type, "<<"))
		{
			dup2(new_fd, STDIN_FILENO);
			close(new_fd);
			unlink(file_name);
		}
	}
	return (new_fd);
}

void	read_heredoc_file(t_redir *redir, t_msh *g_msh)
{
	char	*whole_str;

	whole_str = ft_strdup("");
	read_heredoc_file_2(whole_str, redir, g_msh);
}

void	read_heredoc_file_2(char *whole_str, t_redir *redir, t_msh *g_msh)
{
	char	*str;
	char	*tmp;
	char	*name;

	signal(SIGINT, catch_sigint_hd);
	while (1) 
	{
		str = readline("heredoc>");
		if (!str)
			return ;
		name = (char *)redir->direction;
		if (!ft_strcmp(str, (char *)name)) 
		{
			free(str);
			break ;
		}
		replace_vars_with_values(&str, g_msh);
		tmp = ft_strjoin(whole_str, str);
		free(whole_str);
		free(str);
		whole_str = ft_strjoin(tmp, "\n");
		free(tmp);
		if (g_code_exit == 1)
			return (free(whole_str));
	}
	printf("%s", whole_str);
	free(whole_str);
}
