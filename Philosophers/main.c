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

int	case_one(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (ft_error(CREATING_THREADS_ERROR, data));
	pthread_detach(data->tid[0]);
	while (data->dead == 0)
		ft_usleep(0);
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
	return (0);
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
		return (case_one(&data));
	if (thread_init(&data))
		return (1);
	ft_exit(&data);
	return (0);
}

/* int	main(int ac, char **av)
{
	t_data	data;

	//printf("0. Hey\n");
	if (ac < 5 || 6 < ac)
	{
		ft_error(ARGC_IS_LESS_THAN_5_AND_MORE_THAN_6, NULL);
		return (0);
	}
	//printf("1. Hey\n");
	if (check_input_is_number(av))
		return (0);
	//printf("2. Hey\n");
	if (init(&data, av))
		return (1);
	//printf("3. Hey\n");
	if (data.num_philo == 1)
		return (case_one(&data));
	//printf("4. Hey\n");
	if (thread_init(&data))
		return (0);
	//printf("5. Hey\n");
	ft_exit(&data);
	//printf("6. Hey\n");
	return (0);
} */