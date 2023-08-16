/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:59:54 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/11 09:59:56 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNSET_H
# define FT_UNSET_H

# include "main.h"

int		ft_unset(t_list *tokens, t_list **env, t_msh *g_msh);
void	delete_env_var(char *var, t_list **env);
void	ft_delete_list_str(void *data);

#endif
