/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:34:02 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/20 17:34:03 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdlib.h>//free, malloc
# include <unistd.h>//read, write
# include <stdio.h>//printf
# include <readline/readline.h>//readline
# include <readline/history.h>//add_history
# include <signal.h>//handle_signals
# include <termios.h>//control terminal Input and Output
# include <string.h>//
# include <stdbool.h>//

# define ARGUMENT_INPUT_ERROR "ARGUMENT INPUT ERROR"

/* typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;


typedef struct s_lexer
{
	char	*str;
	t_tokens	token;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_data
{
	
}	t_data;
 */


#endif