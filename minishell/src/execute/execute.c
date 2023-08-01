/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:40:32 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/25 10:23:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/*
** Executes all the command tables extracted by get_ast() from the user input
** @param:	- [t_ast *] struct with a list of cmd_table (t_cmd_table *) as nodes
** Line-by-line comments:
** @7		Edge case: if the "exit" program name is used alongside others
**			simple commands we don't have to execute it. If it's the only simple
**			simple command, we do.
**			The way we implemented the execution, the exec_cmd() only has access
**			to the simple command it's executing. So we set a pointer to the
**			current cmd_table in our global variable struct so that it can check
**			if the cmd_table currently being executed only has one cmd or not
** @9		Each time a cmd_table is executed, we need to set the env _ to the
**			last token of the cmd_table
*/

void	exec_ast(t_ast *ast)
{
	t_list	*cmd_table;
	char	*delimiter;

	//printf("%s\n", "8.0.exec_ast");
	cmd_table = ast->cmd_tables;
	//printf("%s\n", "8.1.exec_ast");
	while (cmd_table)
	{	
		//printf("%s\n", "8.2.exec_ast");
		g_msh.curr_cmd_table = cmd_table->data;
		//printf("%s\n", "8.3.exec_ast");
		exec_cmd_table(g_msh.curr_cmd_table);
		//printf("%s\n", "8.4.exec_ast");
		save_last_token(g_msh.curr_cmd_table);
		//printf("%s\n", "8.5.exec_ast");
		delimiter = g_msh.curr_cmd_table->delimiter;
		//printf("%s\n", "8.6.exec_ast");
		if (!ft_strcmp(delimiter, "&&") && g_msh.exit_status != EXIT_SUCCESS)
		{
			//printf("%s\n", "8.7.exec_ast");
			break ;
		}
		//printf("%s\n", "8.8.exec_ast");
		if (!ft_strcmp(delimiter, "||") && g_msh.exit_status == EXIT_SUCCESS)
		{
		
			break ;
		}
		//printf("%s\n", "8.8.exec_ast");
		cmd_table = cmd_table->next;
	}
}

/*
** Executes all the simple commands inside a command table. It does it
** consecutively and redirecting the input and output of the commands depending
** on the redirections and pipes. Redirections have priority over pipes.
** @param:	- [t_cmd_table *] current command table being executed
** Line-by-line comments:
** @7		We need (nb_cmds - 1) pipes to make all simple commands communicate.
**			We allocate a 2D array where each subarray will have 2 ints:
**			- [0] reading end of the pipe
**			- [1] writing end of the pipe
** @15		Each child process closed all the pipes, now the parent needs to do	
**			it one last time
** @16		All simple commands are executed asynchronously, so we'll only be
** 			executing the parent process once we looped through the list.
**			The parent process basically:
**			- Reaps the children processes
**			- Sets the exit_status of the last simple command executed
** @18-19	Exit values of the builtin function are set as soon as they are
** 			finished. For child process, they are set when its death is reaped
**			by the parent in exec_parent(). So in exec_builtin(), if it's the
**			last simple command, we set the return value
*/

void	exec_cmd_table(t_cmd_table *cmd_table)
{
	t_list	*cmds;
	int		i;

	//printf("%s\n", "8.3.0.exec_cmd_table");
	cmd_table->return_value = -1;
	//printf("%s\n", "8.3.1.exec_cmd_table");
	cmds = cmd_table->cmds;
	//printf("%s\n", "8.3.2.exec_cmd_table");
	cmd_table->nb_cmds = ft_lstsize(cmds);
	//printf("%s\n", "8.3.3.exec_cmd_table");
	cmd_table->pipes = init_pipes(cmd_table->nb_cmds);
	//printf("%s\n", "8.3.4.exec_cmd_table");
	i = 0;
	while (i < cmd_table->nb_cmds)
	{
		//printf("%s\n", "8.3.5.exec_cmd_table");
		exec_cmd(cmds->data, cmd_table, i);
		cmds = cmds->next;
		i++;
	}
	//printf("%s\n", "8.3.6.exec_cmd_table");
	close_all_pipes(cmd_table->pipes, cmd_table->nb_cmds);
	//printf("%s\n", "8.3.7.exec_cmd_table");
	exec_parent(&cmd_table->pids);
	// printf("%s\n", "8.3.8.exec_cmd_table");
	free_arr((void **)cmd_table->pipes);
	if (cmd_table->return_value != -1)
		g_msh.exit_status = cmd_table->return_value;
}

/*
** Executes a simple command. We only create a child process in exec_program().
** Meaning that builtin functions are executed on the parent process because
** functions like cd or export, need to actually change the environment
** variables so we can't execute them in a child process
** @param:	- [t_cmd *] struct with 2 linked lists, one for tokens (char *)
**						as nodes and the other for redirs (t_redir *)
** 			- [t_cmd_table *] current command table being executed
**			- [int] index of the current process
** Line-by-line comments:
** @6		For both tokens and redirections, we need to replace environment
**			variables like $HOME by their value
** @7-8		In set_redirs_pipes, we'll be messing with output and input streams
**			so we need to save the default ones to reset them back in
**			lines 17-18
** @10		Three cases where we don't execute anything:
** 			- Something went wrong with redirections (like an invalid file) so
**			we set exit_status to EXIT_SUCCESS if everything went well
**			- In replace_envs(), we might have deleted all tokens if they
**			were all invalid names
**			- No tokens have been inserted, only redirections like "> a >> b".
**			This example means we have to create 2 empty files
*/

void	exec_cmd(t_cmd *cmd, t_cmd_table *cmd_table, int process_index)
{
	int	saved_stdin;
	int	saved_stdout;
	int	nb_cmds;

	// printf("%s\n", "8.3.5.0.exec_cmd");
	nb_cmds = cmd_table->nb_cmds;
	// printf("%s\n", "8.3.5.1.exec_cmd");
	replace_envs(&cmd->tokens, cmd->redirs);
	// printf("%s\n", "8.3.5.2.exec_cmd");
	saved_stdin = dup(STDIN_FILENO);
	// printf("%s\n", "8.3.5.3.exec_cmd");
	saved_stdout = dup(STDOUT_FILENO);
	// printf("%s\n", "8.3.5.4.exec_cmd");
	set_redirs_pipes(cmd->redirs, cmd_table, process_index);
	// printf("%s\n", "8.3.5.5.exec_cmd");
	if (g_msh.exit_status == EXIT_SUCCESS && cmd->tokens != 0)
	{
		// printf("%s\n", "8.3.5.6.exec_cmd");
		if (is_builtin(cmd->tokens))
		{
			// printf("%s\n", "8.3.5.7.exec_cmd");
			exec_builtin(cmd->tokens, &g_msh.dup_envp, nb_cmds, process_index);
		}
		else
		{
			// printf("%s\n", "8.3.5.8.exec_cmd");
			exec_program(cmd->tokens, cmd_table);
		}
	}
	// printf("%s\n", "8.3.5.9.exec_cmd");
	dup2(saved_stdin, STDIN_FILENO);
	// printf("%s\n", "8.3.5.10.exec_cmd");
	dup2(saved_stdout, STDOUT_FILENO);
	// printf("%s\n", "8.3.5.11.exec_cmd");
	close(saved_stdin);
	// printf("%s\n", "8.3.5.12.exec_cmd");
	close(saved_stdout);
}

/*
** Redirects to builtin functions
** @param:	- [t_list *] list with tokens (t_token *) as nodes. Represents a
**						 simple command
**			- [t_list **] pointer to environment variable linked list
** Line-by-line comments:
** @8-9		We were only asked to deal with env with no arguments
** @18-19	We only set a special return value if it's the last simple command.
**			We might need to overwrite an exit_status set by a child process
**			that finished after this one (e.g. sleep 5 | cd wrong_directory)
*/

void	exec_builtin(t_list *tokens,
					t_list **env,
					int nb_cmds,
					int process_index)
{
	char	*program_name;

	// printf("%s\n", "8.3.5.7.0.exec_builtin");
	program_name = tokens->data;
	// printf("%s\n", "8.3.5.7.1.exec_builtin");
	if (!ft_strcmp(program_name, "exit"))
	{
		// printf("%s\n", "8.3.5.7.2.exec_builtin");
		g_msh.exit_status = ft_exit(tokens->next);
	}
	else if (!ft_strcmp(program_name, "echo"))
	{
		// printf("%s\n", "8.3.5.7.3.exec_builtin");
		g_msh.exit_status = ft_echo(tokens->next);
	}
	else if ((!ft_strcmp(program_name, "env")) && ft_lstsize(tokens) == 1)
	{
		// printf("%s\n", "8.3.5.7.4.exec_builtin");
		g_msh.exit_status = ft_env(*env);
	}
	else if (!ft_strcmp(program_name, "cd"))
	{
		// printf("%s\n", "8.3.5.7.5.exec_builtin");
		// ft_lst_print_s(tokens->next);
		g_msh.exit_status = ft_cd(tokens->next, env);
	}
	else if (!ft_strcmp(program_name, "pwd"))
	{
		// printf("%s\n", "8.3.5.7.6.exec_builtin");
		g_msh.exit_status = ft_pwd();
	}
	else if (!ft_strcmp(program_name, "export"))
	{
		// printf("%s\n", "8.3.5.7.7.exec_builtin");
		g_msh.exit_status = ft_export(tokens->next, env);
	}
	else if (!ft_strcmp(program_name, "unset"))
	{
		// printf("%s\n", "8.3.5.7.8.exec_builtin");
		g_msh.exit_status = ft_unset(tokens->next, env);
	}
	if (process_index == nb_cmds - 1)
		g_msh.curr_cmd_table->return_value = g_msh.exit_status;
}

/*
** Executes the program inside a child process
** @param:	- [t_cmd *] struct with 2 linked lists, one for tokens (char *)
**						as nodes and the other for redirs (t_redir *)
** 			- [t_cmd_table *] current command table being executed
** Line-by-line comments:
** @6-7		execve() requires NULL terminated array of string
** @8		Fork() returns twice, a 1st time inside child process with pid == 0
**			and a 2nd time inside parent process with pid = process ID of child
**			so a value above 0
** @16		Each time we fork(), we add a node at the back. In exec_parent(),
**			we wait on dead child with waitpid(), for the first node of list.
**			We remove first node everytime we reap a process. We do that as long
**			as the queue is not empty
** @17-18	Although they are array of strings, we only need to free the
**			pointers because the individuals strings are still being used
*/

void	exec_program(t_list *lst_tokens, t_cmd_table *cmd_table)
{
	char	**tokens;
	char	**envp;
	long	pid;
	t_list	*new_node;

	// printf("%s\n", "8.3.5.8.0.exec_cmd");
	tokens = convert_list_to_arr(lst_tokens);
	// printf("%s\n", "8.3.5.8.1.exec_cmd");
	envp = convert_list_to_arr(g_msh.dup_envp);
	// printf("%s\n", "8.3.5.8.2.exec_cmd");
	pid = fork();
	// printf("%s\n", "8.3.5.8.3.exec_cmd");
	if (pid < 0)
		quit_program(EXIT_FAILURE);
	else if (pid == 0)
	{
		// printf("%s\n", "8.3.5.8.4.exec_cmd");
		exec_child(tokens, envp, cmd_table->nb_cmds, cmd_table->pipes);
	}
	new_node = ft_lstnew((void *)pid);
	if (!new_node)
		quit_program(EXIT_FAILURE);
	// printf("%s\n", "8.3.5.8.5.exec_cmd");
	ft_lstadd_back(&cmd_table->pids, new_node);
	// printf("%s\n", "8.3.5.8.6.exec_cmd");
	free(tokens);
	// printf("%s\n", "8.3.5.8.7.exec_cmd");
	free(envp);
	// printf("%s\n", "8.3.5.8.8.exec_cmd");
}
