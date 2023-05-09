/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:49:52 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/20 18:49:59 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->lock);
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

int	ft_error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_exit(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || 6 < ac)
	{
		ft_error(ARGC_IS_LESS_THAN_5_MORE_THAN_6, NULL);
		return (1);
	}
	if (check_input_is_number(av))
	{
		ft_error(INPUT_IS_NOT_A_POSITIVE_INTEGER, NULL);
		return (1);
	}
	if (init(&data, av))
		return (1);
	if (thread_init(&data))
		return (1);
	ft_exit(&data);
	return (0);
}

/* 
void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);//
		pthread_mutex_destroy(&data->philos[i].lock);//
	}
	pthread_mutex_destroy(&data->print);//
	pthread_mutex_destroy(&data->lock);//
	if (data->tid)//
		free(data->tid);
	if (data->forks)//
		free(data->forks);
	if (data->philos)//
		free(data->philos);
}

int	ft_error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_exit(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	printf("XXX-0-XXX\n");

	if (ac < 5 || 6 < ac)
	{
		ft_error(ARGC_IS_LESS_THAN_5_MORE_THAN_6, NULL);
		printf("XXX-1-XXX\n");
		return (1);
	}
	if (check_input_is_number(av))
	{
		ft_error(INPUT_IS_NOT_A_POSITIVE_INTEGER, NULL);
		printf("XXX-2-XXX\n");
		return (1);
	}
	if (init(&data, av))
	{
		printf("XXX-3-XXX\n");
		return (1);
	}
	printf("XXX-3-0-XXX\n");
	if (thread_init(&data))
	{
		printf("XXX-5-XXX\n");
		return (1);
	}
	printf("XXX-6-XXX\n");
	ft_exit(&data);
	printf("XXX-7-XXX\n");
	return (0);
} */