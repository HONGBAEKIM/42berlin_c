/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:26:48 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/20 19:26:49 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	val;

	neg = 1;
	i = 0;
	val = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = -neg;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + str[i] - '0';
		i++;
	}
	return (val * neg);
}

int	check_input_is_number(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (ft_error(INPUT_IS_NOT_A_INTEGER, NULL));
	}
	return (0);
}

int	ft_usleep(unsigned int time)
{
	unsigned int	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}


/* 
int	input_checker(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				j++;
				//continue ;
			}
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (error(ERR_IN_1, NULL));
			j++;
		}
		i++;
	}
	return (0);
} 
*/
