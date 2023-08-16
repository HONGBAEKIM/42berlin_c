/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:52:27 by hongbaki          #+#    #+#             */
/*   Updated: 2023/08/15 12:04:15 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

int	ft_env(t_list *env, t_msh *g_msh)
{
	char	*env_str;

	save_last_token(g_msh->curr_cmd_table, g_msh);
	while (env)
	{
		env_str = (char *)env->data;
		if (ft_strchr(env_str, '='))
			printf("%s\n", env_str);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}
