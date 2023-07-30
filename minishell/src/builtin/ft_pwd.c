/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:11:26 by gleal             #+#    #+#             */
/*   Updated: 2021/05/24 17:19:34 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pwd.h"

/*
** Prints current working directory
** @return:	[int] exit status 
*/

int	ft_pwd(void)
{
	char	pwd[MAX_PATH];

	printf("%s\n", "8.3.5.7.6.0.hello");
	if (getcwd(pwd, MAX_PATH) == NULL)
	{
		printf("%s\n", "8.3.5.7.6.2.hello");
		return (EXIT_FAILURE);
	}
	printf("%s\n", "8.3.5.7.6.3.hello");
	printf("%s\n", pwd);
	printf("%s\n", "8.3.5.7.6.4.hello");
	return (EXIT_SUCCESS);
}
