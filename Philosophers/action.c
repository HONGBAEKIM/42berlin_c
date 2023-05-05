/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:26:34 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/20 19:26:35 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (ft_error("gettimeofday() FAILURE\n", NULL));
	return ((tv.tv_sec * (unsigned int)1000) + (tv.tv_usec / 1000));
}

void	messages(char *str, t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->data->print);//
	time = get_time() - philo->data->start_time;
	if (ft_strcmp(DIED, str) == 0 && philo->data->dead == 0)
	{
		printf("%lld %d %s\n", time, philo->id, str);
		philo->data->dead = 1;
	}
	if (!philo->data->dead)
		printf("%lld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->print);//
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->rightfork);//
	messages(HAS_TAKEN_RIGHT_FORK, philo);
	pthread_mutex_lock(philo->leftfork);//
	messages(HAS_TAKEN_LEFT_FORK, philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->leftfork);//
	pthread_mutex_unlock(philo->rightfork);//
	messages(IS_SLEEPING, philo);
	ft_usleep(philo->data->time_sleep);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);//
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->data->time_die;
	messages(IS_EATING, philo);
	philo->eat_cont++;
	ft_usleep(philo->data->time_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);//
	drop_forks(philo);
}

/* 

//to bring current time
//tv_sec is seconds
//tv_usec is microseconds
unsigned int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (unsigned int)1000) + (tv.tv_usec / 1000));
} 

*/