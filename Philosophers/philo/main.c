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

int	one_philo(t_data *data)
{
	pthread_mutex_lock(&data->print);
	printf("philo->data->dead: %d\n", data->dead);
	pthread_mutex_unlock(&data->print);
	data->start_time = get_time();
	eat(data->philos);
	pthread_create(&data->tid[0], NULL, &supervisor, &data->philos[0]);
	pthread_detach(data->tid[0]);
	while (data->dead == 0)
		ft_usleep(1);
	ft_exit(data);
	return (0);
}

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
	if (data.num_philo == 1)
		return (one_philo(&data));
	if (thread_init(&data))
		return (1);
	ft_exit(&data);
	return (0);
}

/* int	one_philo(t_data *data)
{

	//pthread_mutex_lock(&data->print);
	//printf("philo->data->dead: %d\n", data->dead);
	//pthread_mutex_unlock(&data->print); 
	
	
	
	
	data->start_time = get_time();
	eat(data->philos);
	printf("XXX-4-0-XXX\n");
	pthread_create(&data->tid[0], NULL, &supervisor, &data->philos[0]);
	//pthread_create(&philo->t1, NULL, &supervisor, (void *)philo);
	//pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]);
	printf("XXX-4-1-XXX\n");
	pthread_detach(data->tid[0]);
	ft_usleep(0);
	while (data->dead == 0)
	{
		ft_usleep(1);
		
	}
	//data->dead = 1;
	
	
	

	
	printf("XXX-4-2-XXX\n");
	

	printf("XXX-4-3-XXX\n");


	printf("XXX-4-4-XXX\n");


	ft_exit(data);
	printf("XXX-4-5-XXX\n");

	return (0);
}

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

	printf("XXX-0-XXX\n");
	if (ac < 5 || 6 < ac)
	{
		printf("XXX-1-XXX\n");
		ft_error(ARGC_IS_LESS_THAN_5_MORE_THAN_6, NULL);
		return (1);
	}
	if (check_input_is_number(av))
	{
		printf("XXX-2-XXX\n");
		ft_error(INPUT_IS_NOT_A_POSITIVE_INTEGER, NULL);
		return (1);
	}
	if (init(&data, av))
	{
		printf("XXX-3-XXX\n");
		return (1);
	}
	if (data.num_philo == 1)
	{
		printf("XXX-4-XXX\n");
		
		return (one_philo(&data));
	}
	if (thread_init(&data))
	{
		printf("XXX-5-XXX\n");
		return (1);
	}
	printf("XXX-6-XXX\n");
	ft_exit(&data);
	printf("XXX-7-XXX\n");
	return (0);
}*/