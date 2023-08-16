/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:01:32 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:01:34 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "main.h"

t_ast		*get_ast(const char *input, t_msh *g_msh);
t_cmd_table	*get_cmd_table(const char *input, int *curr_pos, t_msh *g_msh);
t_cmd		*get_cmd(const char *input, int *curr_pos, t_msh *g_msh);
t_redir		*get_redir(const char *input, int *curr_pos, t_msh *g_msh);
char		*get_token(const char *input, int *curr_pos, t_msh *g_msh);

#endif
