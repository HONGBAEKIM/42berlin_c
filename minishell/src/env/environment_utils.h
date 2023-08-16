/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:00:30 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 10:12:18 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_UTILS_H
# define ENVIRONMENT_UTILS_H

# include "main.h"

/*
** File environment_utils1.c
*/

int		is_env_var(char *potential_var, t_list *env);
char	*get_var_name(char *str, t_msh *g_msh);
int		ft_strnstr_iterator(char *haystack, char *needle, size_t len);
char	*replace_midstring(char *original, char *old_substr, char *new_substr, \
int replace_i, t_msh *g_msh);
void	tilde_join(char **str, char **home_path, t_msh *g_msh);

/*
** File environment_utils2.c
*/

char	*get_value_name(char *str, t_msh *g_msh);
int		is_token_empty(void *data);
void	unset_oldpwd(t_msh *g_msh);
void	replace_string(char *str, char **env_ptr, t_msh *g_msh);
void	increment_shlvl(t_msh *g_msh);

#endif
