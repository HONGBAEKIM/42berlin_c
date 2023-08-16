/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:01:21 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:54:36 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	exec_ast(t_ast *ast, t_msh *g_msh)
{
	t_list	*cmd_table;
	char	*delimiter;

	cmd_table = ast->cmd_tables;
	while (cmd_table)
	{
		g_msh->curr_cmd_table = cmd_table->data;
		exec_cmd_table(g_msh->curr_cmd_table, g_msh);
		save_last_token(g_msh->curr_cmd_table, g_msh);
		delimiter = g_msh->curr_cmd_table->delimiter;
		if (!ft_strcmp(delimiter, "&&") && g_msh->exit_status != EXIT_SUCCESS)
			break ;
		if (!ft_strcmp(delimiter, "||") && g_msh->exit_status == EXIT_SUCCESS)
			break ;
		cmd_table = cmd_table->next;
	}
}

void	exec_cmd_table(t_cmd_table *cmd_table, t_msh *g_msh)
{
	t_list	*cmds;
	int		i;

	cmd_table->return_value = -1;
	cmds = cmd_table->cmds;
	cmd_table->nb_cmds = ft_lstsize(cmds);
	cmd_table->pipes = init_pipes(cmd_table->nb_cmds, g_msh);
	i = 0;
	while (i < cmd_table->nb_cmds)
	{
		exec_cmd(cmds->data, cmd_table, i, g_msh);
		cmds = cmds->next;
		i++;
	}
	close_all_pipes(cmd_table->pipes, cmd_table->nb_cmds);
	exec_parent(&cmd_table->pids, g_msh);
	free_arr((void **)cmd_table->pipes);
	if (cmd_table->return_value != -1)
		g_msh->exit_status = cmd_table->return_value;
}

void	exec_cmd(t_cmd *cmd, t_cmd_table *cmd_table, int process_index, \
t_msh *g_msh)
{
	int	saved_stdin;
	int	saved_stdout;
	int	nb_cmds;

	nb_cmds = cmd_table->nb_cmds;
	replace_envs(&cmd->tokens, cmd->redirs, g_msh);
	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	set_redirs_pipes(cmd->redirs, cmd_table, process_index, g_msh);
	if (g_msh->exit_status == EXIT_SUCCESS && cmd->tokens != 0)
	{
		if (is_builtin(cmd->tokens))
			exec_builtin(cmd->tokens, &g_msh->dup_envp, nb_cmds, process_index, \
			g_msh);
		else
			exec_program(cmd->tokens, cmd_table, g_msh);
	}
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
}

/* void	exec_cmd(t_cmd *cmd, t_cmd_table *cmd_table, int process_index, \
 *g_msh)
{
	"      env      "
	int	saved_stdin;
	int	saved_stdout;
	int	nb_cmds;

	nb_cmds = cmd_table->nb_cmds;
	replace_envs(&cmd->tokens, cmd->redirs, g_msh);
	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	set_redirs_pipes(cmd->redirs, cmd_table, process_index, g_msh);
	if (g_msh->exit_status == EXIT_SUCCESS && cmd->tokens != 0)
	{
		if (is_builtin(cmd->tokens))
			exec_builtin(cmd->tokens, &g_msh->dup_envp, nb_cmds, process_index, \
			g_msh);
		else
			exec_program(cmd->tokens, cmd_table, g_msh);
	}
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
} */

void	exec_builtin(t_list *tokens,
					t_list **env,
					int nb_cmds,
					int process_index, t_msh *g_msh)
{
	char	*program_name;

	program_name = tokens->data;
	if (!ft_strcmp(program_name, "exit"))
		g_msh->exit_status = ft_exit(tokens->next, g_msh);
	else if (!ft_strcmp(program_name, "echo"))
		g_msh->exit_status = ft_echo(tokens->next);
	else if ((!ft_strcmp(program_name, "env")) && ft_lstsize(tokens) == 1)
		g_msh->exit_status = ft_env(*env, g_msh);
	else if (!ft_strcmp(program_name, "cd"))
		g_msh->exit_status = ft_cd(tokens->next, env, g_msh);
	else if (!ft_strcmp(program_name, "pwd"))
		g_msh->exit_status = ft_pwd();
	else if (!ft_strcmp(program_name, "export"))
		g_msh->exit_status = ft_export(tokens->next, env, g_msh);
	else if (!ft_strcmp(program_name, "unset"))
		g_msh->exit_status = ft_unset(tokens->next, env, g_msh);
	if (process_index == nb_cmds - 1)
		g_msh->curr_cmd_table->return_value = g_msh->exit_status;
}

void	exec_program(t_list *lst_tokens, t_cmd_table *cmd_table, t_msh *g_msh)
{
	char	**tokens;
	char	**envp;
	long	pid;
	t_list	*new_node;

	tokens = convert_list_to_arr(lst_tokens);
	envp = convert_list_to_arr(g_msh->dup_envp);
	pid = fork();
	if (pid < 0)
		quit_program(EXIT_FAILURE, g_msh);
	else if (pid == 0)
		exec_child(tokens, envp, cmd_table->nb_cmds, cmd_table->pipes, g_msh);
	new_node = ft_lstnew((void *)pid);
	if (!new_node)
		quit_program(EXIT_FAILURE, g_msh);
	ft_lstadd_back(&cmd_table->pids, new_node);
	free(tokens);
	free(envp);
}
