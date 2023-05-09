/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:26:45 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/20 19:26:46 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *data_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) data_pointer;
	pthread_mutex_lock(&philo->data->print);
	printf("philo->data->dead: %d\n", philo->data->dead);
	pthread_mutex_unlock(&philo->data->print);
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished >= philo->data->num_philo)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*supervisor(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	while (philo->data->dead == 0)
	{	
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			messages(DIED, philo);
		if (philo->eat_cont == philo->data->num_meals)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->eat_cont++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	philo->time_to_die = get_time() + philo->data->time_die;
	if (pthread_create(&philo->t1, NULL, &supervisor, (void *)philo))
		return ((void *)1);	
	while (philo->data->dead == 0)
	{
		eat(philo);
		if (philo->data->num_philo != 1)
			messages(IS_THINKING, philo);
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	thread_init(t_data *data)
{
	int			i;
	pthread_t	t0;

	data->start_time = get_time();
	if (data->num_meals > 0)
	{
		if (pthread_create(&t0, NULL, &monitor, &data->philos[0]))
			return (ft_error(CREATING_THREADS_ERROR, data));
		pthread_detach(t0);
	}
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
			return (ft_error(CREATING_THREADS_ERROR, data));
		ft_usleep(1);
	}
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_join(data->tid[i], NULL) && data->num_philo != 1)
			return (ft_error(JOINING_THREADS_ERROR, data));
		
	}
	return (0);
}

/* 
void	*monitor(void *data_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) data_pointer;
	pthread_mutex_lock(&philo->data->print);
	printf("philo->data->dead: %d\n", philo->data->dead);
	pthread_mutex_unlock(&philo->data->print);
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished >= philo->data->num_philo)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*supervisor(void *philo_pointer)
{
	t_philo	*philo;

	printf("XXX-4-1-2-0-XXX\n");
	philo = (t_philo *) philo_pointer;
		printf("XXX-4-1-2-1-XXX\n");
	while (philo->data->dead == 0)
	{	
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			messages(DIED, philo);
		if (philo->eat_cont == philo->data->num_meals)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->eat_cont++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	printf("XXX-4-1-2-6-XXX\n");
	return ((void *)0);
}

void	*routine(void *philo_pointer)
{
	t_philo	*philo;

	printf("XXX-4-1-0-XXX\n");
	philo = (t_philo *) philo_pointer;
	printf("XXX-4-1-1-XXX\n");
	philo->time_to_die = get_time() + philo->data->time_die;
	printf("XXX-4-1-2-XXX\n");
	if (pthread_create(&philo->t1, NULL, &supervisor, (void *)philo))
		return ((void *)1);	
	printf("XXX-4-1-3-XXX\n");
	while (philo->data->dead == 0)
	{
		printf("XXX-4-1-4-XXX\n");
		eat(philo);
		printf("XXX-4-1-5-XXX\n");
		if (philo->data->num_philo != 1)
			messages(IS_THINKING, philo);
	}
	printf("XXX-4-1-6-XXX\n");
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	printf("XXX-4-1-7-XXX\n");
	return ((void *)0);
}

int	thread_init(t_data *data)
{
	int			i;
	pthread_t	t0;

	data->start_time = get_time();
	if (data->num_meals > 0)
	{
		if (pthread_create(&t0, NULL, &monitor, &data->philos[0]))
			return (ft_error(CREATING_THREADS_ERROR, data));
		pthread_detach(t0);
	}
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
			return (ft_error(CREATING_THREADS_ERROR, data));
		ft_usleep(1);
	}
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_join(data->tid[i], NULL) && data->num_philo != 1)
			return (ft_error(JOINING_THREADS_ERROR, data));
		
	}
	return (0);
*/