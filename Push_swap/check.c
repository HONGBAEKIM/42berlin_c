/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:29:06 by hongbaki          #+#    #+#             */
/*   Updated: 2023/03/07 14:29:07 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int	num, char **av, int	i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}


static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_overflow(char *args)
{
	long long	tmp;

	tmp = ft_atoll(args);
	if (tmp >= -2147483648 && tmp <= 2147483647)
		return (1);
	return (0);
}

void	ft_check_args(int ac, char **av)
{
	int	i;
	long	tmp;
	char **args;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_overflow(args[i]))
			ft_error("Error");
		if (!ft_isnum(args[i]))
			ft_error("Error");
		if (ft_contains(tmp, args, i))
			ft_error("Error");
		i++;
	}
	if (ac == 2)
		ft_free(args);
}
