/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:00:45 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:00:46 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_UTILS_H
# define EXECUTE_UTILS_H

# include "main.h"

int		is_builtin(t_list *tokens);
char	**convert_list_to_arr(t_list *lst);
int		has_relative_path(char *first_token);
int		has_absolute_path(char *first_token);

#endif
