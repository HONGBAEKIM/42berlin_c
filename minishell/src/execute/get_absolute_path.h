/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:00:58 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:30:44 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ABSOLUTE_PATH_H
# define GET_ABSOLUTE_PATH_H

# include "main.h"

char	*get_absolute_path(char *program_name, t_msh *g_msh);
char	**get_path_env_split(t_msh *g_msh);
char	*get_correct_path(char *program_name, char **path_env_split, \
t_msh *g_msh);
void	add_slash(char ***path_env_split);

#endif
