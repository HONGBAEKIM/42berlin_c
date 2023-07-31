/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_pipes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:04:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/25 10:43:24 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections_pipes.h"

/*
** Creates a 2D array of ints where each subarray will represent a pipe, meaning
** it will have 2 ints:
** - [0] reading end of the pipe
** - [1] writing end of the pipe
** @param:	- [int] number of simple commands to be executed
** @return:	[int **] 2D array of ints. It's NULL-terminated to call free_arr()
** Line-by-line comments:
** @6		We effectively need (nb_cmds - 1) pipes but we also need the array
**			to be NULL-terminated
** @15		The function pipe() requires an array of 2 pre-allocated ints. It
**			enables reading and writing from different processes
*/

int	**init_pipes(int nb_cmds)
{
	int	**pipes;
	int	i;

	if (nb_cmds == 1)
		return (0);
	pipes = ft_calloc(nb_cmds, sizeof(int *));
	if (!pipes)
		quit_program(EXIT_FAILURE);
	i = 0;
	while (i < nb_cmds - 1)
	{
		pipes[i] = ft_calloc(2, sizeof(int));
		if (!pipes[i])
			quit_program(EXIT_FAILURE);
		if (pipe(pipes[i]) == -1)
			quit_program(EXIT_FAILURE);
		i++;
	}
	//printf("pipes : %i\n", **pipes);
	return (pipes);
}

/*
** Adjusts the input / output streams to implement piping and redirections. One
** thing we need to keep in mind: redirections (e.g. >, <) have priority over
** pipes!
** @param:	- [t_list *] linked list with redirections (t_redir *) as nodes
** 			- [t_cmd_table *] current command table being executed
**			- [int] index of the current process
** Line-by-line comments:
** @6		Parses redirs and open all relevant files. In case, there are more
**			than one redirection of either input or output, we only keep the
**			last one
** @7		There can be issues with opening files (like file invalid). Inside
**			open_all_files(), the exit_status has been set so we can return
** @8&10	We only need to set piping if there are no redirections
** @8		If first process then no piping
** @9		We read from the pipe (process_index - 1)[0] because the previous
**			index write to that same pipe but to its writing end [1]
** @10-11	If last process then no piping
** @12		We write to [1] so that the next simple command can read from [0]
*/

void	set_redirs_pipes(t_list *redirs,
						t_cmd_table *cmd_table,
						int process_index)
{
	int	**pipes;
	int	nb_cmds;

	printf("%s\n", "8.3.5.4.0.set_redirs_pipes");
	pipes = cmd_table->pipes;
	printf("%s\n", "8.3.5.4.1.set_redirs_pipes");
	nb_cmds = cmd_table->nb_cmds;
	printf("%s\n", "8.3.5.4.2.set_redirs_pipes");
	if (open_all_files(redirs) == EXIT_FAILURE)
	{
		printf("%s\n", "8.3.5.4.3.set_redirs_pipes");
		return ;
	}
	if (!has_redirs(redirs, "<") && !has_redirs(redirs, "<<")
		&& process_index != 0)
	{
		printf("%s\n", "8.3.5.4.4.set_redirs_pipes");
		// printf("%s", "> ");
		dup2(pipes[process_index - 1][0], STDIN_FILENO);
	}
	/* else if (!has_redirs(redirs, "<") && process_index != 0)
	{
		printf("%s\n", "8.3.5.4.4.set_redirs_pipes");
		dup2(pipes[process_index - 1][0], STDIN_FILENO);
	} */
	if (!has_redirs(redirs, ">") && !has_redirs(redirs, ">>")
		&& process_index != nb_cmds - 1)
	{
		printf("%s\n", "8.3.5.4.5.set_redirs_pipes");
		dup2(pipes[process_index][1], STDOUT_FILENO);
	}
	printf("%s\n", "8.3.5.4.6.set_redirs_pipes");
	g_msh.exit_status = EXIT_SUCCESS;
	printf("%s\n", "8.3.5.4.7.set_redirs_pipes");
}

/* void	set_redirs_pipes(t_list *redirs,
						t_cmd_table *cmd_table,
						int process_index)
{
	int	**pipes;
	int	nb_cmds;

	printf("%s\n", "8.3.5.4.0.set_redirs_pipes");
	pipes = cmd_table->pipes;
	printf("%s\n", "8.3.5.4.1.set_redirs_pipes");
	nb_cmds = cmd_table->nb_cmds;
	printf("%s\n", "8.3.5.4.2.set_redirs_pipes");
	if (open_all_files(redirs) == EXIT_FAILURE)
	{
		printf("%s\n", "8.3.5.4.3.set_redirs_pipes");
		return ;
	}
	if (!has_redirs(redirs, "<") && !has_redirs(redirs, "<<") 
		&& process_index != 0)
	{
		printf("%s\n", "8.3.5.4.4.set_redirs_pipes");
		dup2(pipes[process_index - 1][0], STDIN_FILENO);
	}
	if (!has_redirs(redirs, ">") && !has_redirs(redirs, ">>")
		&& process_index != nb_cmds - 1)
	{
		printf("%s\n", "8.3.5.4.5.set_redirs_pipes");
		dup2(pipes[process_index][1], STDOUT_FILENO);
	}
	printf("%s\n", "8.3.5.4.6.set_redirs_pipes");
	g_msh.exit_status = EXIT_SUCCESS;
	printf("%s\n", "8.3.5.4.7.set_redirs_pipes");
} */

/*
** Checks if the redirs linked list has redirections of the specified type
** @param:	- [t_list *] linked list with redirs (t_redir *) as nodes
**			- [char *] type of redirection we are looking for. Can be
**					   either ">", ">>" or "<"
** @return:	[int] true or false
*/

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

/*
** Opens all files. Only the last of its type is left open, others are closed.
** For input type, we create them and leave them empty
** @param:	- [t_list *] linked list with redirs (t_redir *) as nodes
** @return:	[int] EXIT_SUCCESS or EXIT_FAILURE
** Line-by-line comments:
** @16-17	If any of the open_file() calls returned -1, it means there was an
**			error
*/

/* void	sigint_heredoc(int sig)
{
	(void)sig;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	quit_program(EXIT_CMD_INTERRUPTED);
} */

int	open_all_files(t_list *redirs)
{
	int		fd_i;
	int		fd_o;
	t_redir	*redir;
	char	*name;
	char	*str;
	char	*whole_str;
	char	*tmp;
	
	//char	*str_expand_check;
	


	fd_i = -2;
	fd_o = -2;
	printf("%s\n", "8.3.5.4.2.0.open_all_files");
	while (redirs)
	{
		printf("%s\n", "8.3.5.4.2.1.open_all_files");
		redir = (t_redir *)redirs->data;
		printf("%s\n", "8.3.5.4.2.2.open_all_files");
		if (!ft_strcmp(redir->type, "<"))
		{
			printf("%s\n", "8.3.5.4.2.3.open_all_files");
			fd_i = open_file(redir, fd_i, O_RDONLY, 0);
		}
		else if (!ft_strcmp(redir->type, "<<"))
		{
			printf("%s\n", "8.3.5.4.2.4.open_all_files");
			whole_str = ft_strdup("");
			while (1)
			{
				str = readline("heredoc>");
				if (!str)
					break ;
				name = (char *)redir->direction;
				//printf("name : %s\n", name);
				if (!ft_strcmp(str, (char *)name))
				{
					free(str);
					break;
				}
				tmp = ft_strjoin(whole_str, str);
				free(str);
				free(whole_str);
				whole_str = ft_strjoin(tmp, "\n");
				free(tmp);
			}
			printf("%s\n", whole_str);

			fd_i = open_file(redir, fd_i, O_RDONLY, 0666);
			printf("1. fd_i : %d\n", fd_i);
			if (fd_i == -1)
				write_exec_error(redir->direction, "heredoc can't be created");
			//redirs->data = str;
			//printf("%s\n", whole_str);
			//signal(SIGINT, sigint_heredoc);
			// if (redir->direction == redirs->data)
			
			// fd_i = open_file(redir, fd_i, O_RDONLY, 0644);
			// if (fd_i == -1)
			// 	write_exec_error(redir->direction, "heredoc can't be created");
			
			/* fd_i = open_file(redir, fd_i, O_RDONLY, 0);
			printf("1. fd_i : %d\n", fd_i);
			if (fd_i == -1)
			 	write_exec_error(redir->direction, "open heredoc failed"); */
		}
		else if (!ft_strcmp(redir->type, ">"))
		{
			printf("%s\n", "8.3.5.4.2.5.open_all_files");
			fd_o = open_file(redir, fd_o, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		}
		else if (!ft_strcmp(redir->type, ">>"))
		{
			printf("%s\n", "8.3.5.4.2.6.open_all_files");
			fd_o = open_file(redir, fd_o, O_WRONLY | O_CREAT | O_APPEND, 0666);
		}
		if (fd_i == -1 || fd_o == -1)
		{
			printf("%s\n", "8.3.5.4.2.7.open_all_files");
			return (EXIT_FAILURE);
		}
		printf("%s\n", "8.3.5.4.2.8.open_all_files");
		redirs = redirs->next;
		
	}
	return (EXIT_SUCCESS);
}


/*
** Opens a single file based on the flags and permissions passed
** @param:	- [t_list *] linked list with redirs (t_redir *) as nodes
**			- [int] previous file descriptor. If -2 then no file has been opened
**                  otherwise it means, another file is about to be opened and
**                  we need to close the previous one
**			- [int] flags in a bit field format
**			- [mode_t] permissions in a bit field format
** @return:	[int] file descriptor of the new file opened. Or -1 if error
** Line-by-line comments:
** @4-5		If -2 then no file has been opened previously. Otherwise it means,
**			another file is about to be opened and we need to close the
**			previous one
** @15-19	Set input stream directed from fd instead of STDIN or STOUDOUT and
**			close the fd. Closing it doesn't mean that it isn't active
*/

int	open_file(t_redir *redir, int prev_fd, int flags, mode_t permissions)
{
	char	*file_name;
	int		new_fd;

	printf("%s\n", "8.3.5.4.2.4.0.open_files");
	if (prev_fd != -2)
	{
		close(prev_fd);
	}
	printf("%s\n", "8.3.5.4.2.4.1.open_files");
	file_name = redir->direction;
	printf("%s\n", "8.3.5.4.2.4.2.open_files");
	new_fd = open(file_name, flags, permissions);
	printf("%s\n", "8.3.5.4.2.4.3.open_files");
	if (new_fd == -1)
	{
		printf("%s\n", "8.3.5.4.2.4.4.open_files");
		write_msh_exec_error(file_name, strerror(errno));
		g_msh.exit_status = errno;
	}
	else
	{
		printf("%s\n", "8.3.5.4.2.4.5.open_files");
		if (!ft_strcmp(redir->type, "<") || !ft_strcmp(redir->type, "<<"))
		{
			printf("%s\n", "8.3.5.4.2.4.6.open_files");
			dup2(new_fd, STDIN_FILENO);
		}
		else if (!ft_strcmp(redir->type, ">") || !ft_strcmp(redir->type, ">>"))
		{
			printf("%s\n", "8.3.5.4.2.4.7.open_files");
			dup2(new_fd, STDOUT_FILENO);
		}
		printf("%s\n", "8.3.5.4.2.4.8.open_files");
		close(new_fd);
	}
	return (new_fd);
}
/* 
int	open_file(t_redir *redir, int prev_fd, int flags, mode_t permissions)
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
		g_msh.exit_status = errno;
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
} */



/* int	open_all_files(t_list *redirs)
{
	int		fd_i;
	int		fd_o;
	t_redir	*redir;
	char	*str = NULL;
	
	
	//char	*str_expand_check;
	//char	*whole_str;


	fd_i = -2;
	fd_o = -2;
	printf("%s\n", "8.3.5.4.2.0.open_all_files");
	while (redirs)
	{
		printf("%s\n", "8.3.5.4.2.1.open_all_files");
		redir = (t_redir *)redirs->data;
		printf("%s\n", "8.3.5.4.2.2.open_all_files");
		if (!ft_strcmp(redir->type, "<"))
		{
			printf("%s\n", "8.3.5.4.2.3.open_all_files");
			fd_i = open_file(redir, fd_i, O_RDONLY, 0);
		}
		else if (!ft_strcmp(redir->type, "<<"))
		{
			printf("%s\n", "8.3.5.4.2.4.open_all_files");
			//signal(SIGINT, sigint_heredoc);
			
			while (1)
			{
				
				char	*line = readline("heredoc>");
				if (!line)
					break ;
				
				if (str == NULL)
					str = strdup(line);
				else
				{
					char	*tmp = str;
					str = malloc(strlen(tmp) + strlen(line) + 2);
					// +2 for newline and null-terminator
					//sprintf(str, "%s\n%s", tmp, line);
					printf("%s\n",str);
					free(tmp);
				}
				free(line);
			}
			redirs->data = str;
			// Save the concatenated heredoc string


			//ft_lst_print_s(redirs->data);
			//free(str);
			printf("0. fd_i : %d\n", fd_i);	
			// fd_i = open_file(redir, fd_i, O_CREAT | O_RDWR, 0644);
			// printf("1. fd_i : %d\n", fd_i);
			// if (fd_i == -1)
			// 	write_exec_error(redir->direction, "heredoc can't be created");
			
			
			
			fd_i = open_file(redir, fd_i, O_RDONLY, 0);
			if (fd_i == -1)
				write_exec_error(redir->direction, "open heredoc failed");
			printf("2. fd_i : %d\n", fd_i);
			
			//fd_i = open_file(redir, fd_i, O_WRONLY | O_CREAT | O_TRUNC, 0666);

		}
		else if (!ft_strcmp(redir->type, ">"))
		{
			printf("%s\n", "8.3.5.4.2.5.open_all_files");
			fd_o = open_file(redir, fd_o, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		}
		else if (!ft_strcmp(redir->type, ">>"))
		{
			printf("%s\n", "8.3.5.4.2.6.open_all_files");
			fd_o = open_file(redir, fd_o, O_WRONLY | O_CREAT | O_APPEND, 0666);
		}
		if (fd_i == -1 || fd_o == -1)
		{
			printf("%s\n", "8.3.5.4.2.7.open_all_files");
			return (EXIT_FAILURE);
		}
		printf("%s\n", "8.3.5.4.2.8.open_all_files");
		redirs = redirs->next;
	}
	return (EXIT_SUCCESS);
} */



/* int	open_all_files(t_list *redirs)
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
			fd_i = open_file(redir, fd_i, O_RDONLY, 0);
		else if (!ft_strcmp(redir->type, "<<"))
			fd_i = open_file(redir, fd_i, O_RDONLY, 0);
		else if (!ft_strcmp(redir->type, ">"))
			fd_o = open_file(redir, fd_o, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		else if (!ft_strcmp(redir->type, ">>"))
			fd_o = open_file(redir, fd_o, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (fd_i == -1 || fd_o == -1)
			return (EXIT_FAILURE);
		redirs = redirs->next;
	}
	return (EXIT_SUCCESS);
} */