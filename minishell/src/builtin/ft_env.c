/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:31:58 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/16 01:37:42 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

/*
** Prints environment variable string linked lists one by one
** @param:	- [t_list *] environment variable string linked list
** @return:	[int] exit status 
** Line-by-line comments:
** @3		We want the _ env variable to be /usr/bin/env when the user calls
**			env
*/

int	ft_env(t_list *env)
{
	char	*env_str;

	printf("%s\n", "8.3.5.7.4.0.ft_env");
	save_last_token(g_msh.curr_cmd_table);
	printf("%s\n", "8.3.5.7.4.1.ft_env");
	while (env)
	{
		printf("%s\n", "8.3.5.7.4.2.ft_env");
		env_str = (char *)env->data;
		printf("%s\n", "8.3.5.7.4.3.ft_env");
		if (ft_strchr(env_str, '='))
		{
			printf("%s\n", "8.3.5.7.4.4.ft_env");
			printf("%s\n", env_str);
		}
		env = env->next;
	}
	return (EXIT_SUCCESS);
}
