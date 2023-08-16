/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:02:11 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/15 18:16:11 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <string.h>
# include <fcntl.h>
# include <curses.h>
# include <termcap.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/libft.h"
# include "../libft_utils/libft_utils.h"

# include "structs.h"
# include "constants.h"

# include "builtin_utils.h"
# include "ft_cd.h"
# include "ft_exit.h"
# include "ft_echo.h"
# include "ft_env.h"
# include "ft_pwd.h"
# include "ft_export.h"
# include "ft_unset.h"

# include "environment.h"
# include "environment_utils.h"

# include "execute.h"
# include "execute_utils.h"
# include "fork_exec_wait.h"
# include "redirections_pipes.h"
# include "redirections_pipes_2.h"
# include "get_absolute_path.h"

# include "parse.h"
# include "parse_utils.h"
# include "get_input.h"
# include "input_validation.h"

# include "quit_program.h"
# include "free_memory.h"

# include "termcaps.h"

# include "init_minishell.h"
# include "signals.h"
# include "write_err_message.h"
# include "write_prompt.h"
# include "utils.h"

extern int	g_code_exit;
#endif
