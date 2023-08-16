/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:02:15 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/15 18:32:09 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_ast
{
	t_list			*cmd_tables;
}				t_ast;

typedef struct s_cmd_table
{
	t_list			*cmds;
	char			*delimiter;
	int				nb_cmds;
	int				**pipes;
	t_list			*pids;
	int				return_value;
}				t_cmd_table;

typedef struct s_cmd
{
	t_list		*tokens;
	t_list		*redirs;
}				t_cmd;

typedef struct s_redir
{
	char			*direction;
	char			type[2];
}				t_redir;

typedef struct s_termcaps
{
	struct termios	old_term;	
	struct termios	new_term;	
	char			*buffer;
	char			*keys_on;
	char			*keys_off;
	char			*up_arrow;
	char			*down_arrow;
	char			*backspace;
	char			*del_line;
	char			*set_cursor_begin;
}				t_termcaps;

typedef struct s_msh
{
	t_dlist			*input_history;
	t_ast			*ast;
	t_termcaps		termcaps;
	t_list			*dup_envp;
	int				exit_status;
	t_cmd_table		*curr_cmd_table;
}				t_msh;

#endif
