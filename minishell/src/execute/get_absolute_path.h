/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:47:12 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/25 10:30:49 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ABSOLUTE_PATH_H
# define GET_ABSOLUTE_PATH_H

# include "main.h"

char	*get_absolute_path(char *program_name);
char	**get_path_env_split(void);
char	*get_correct_path(char *program_name, char **path_env_split);
void	add_slash(char ***path_env_split);

#endif
