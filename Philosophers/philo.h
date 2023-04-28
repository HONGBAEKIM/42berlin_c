/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:34:02 by hongbaki          #+#    #+#             */
/*   Updated: 2023/04/20 17:34:03 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#  define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h> //useconds_t

# define INPUT_IS_NOT_A_INTEGER "INPUT IS NOT A INTEGER"
# define INPUT_IS_OUT_OF_RANGE "INPUT IS OUT OF RANGE"
# define ALLOCATING_THREADS_IDS_ERROR "ALLOCATING THREADS IDS ERROR"
# define ALLOCATING_FORKS_ERROR "ALLOCATING FORKS ERROR"
# define ALLOCATING_PHILOS_ERROR "ALLOCATING PHILOS ERROR"
# define CREATING_THREADS_ERROR "CREATING THREADS ERROR"
# define JOINING_THREADS_ERROR "JOINING THREADS ERROR"
# define HAS_TAKEN_A_FORK "has taken a fork"
# define IS_THINKING "is thinking"
# define IS_SLEEPING "is sleeping"
# define IS_EATING "is eating"
# define IS_DIED "is died"

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;//fist thread name
	int				id;
	int				eat_cont;
	int				status;
	int				eating;
	unsigned int	time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*rightfork;
	pthread_mutex_t	*leftfork;
}	t_philo;

typedef struct s_data
{
	
	int				num_philo;//av[1] The number of philosophers and also the number of forks
	int				time_die;//av[2] If a philosopher didn’t start eating time_to_die, they die
	int				time_eat;//av[3] The time it takes for a philos to eat
	int				time_sleep;//av[4] The time a philos will spend sleeping
	int				num_meals;//av[5]  If all philos have eaten at least num_meals, simulation stops
	int				dead;
	int				finished;
	int				start_time;
	pthread_t		*tid;//pthread id
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

int			ft_atoi(const char *str);
int			error(char *str, t_data *data);
int			ft_strcmp(char *s1, char *s2);
void		messages(char *str, t_philo *philo);
void		ft_exit(t_data *data);
unsigned int	get_time(void);
int			ft_usleep(useconds_t time);
int			init(t_data *data, char **av, int ac);
int			thread_init(t_data *data);
int			check_input_is_number(char **av);
void		eat(t_philo *philo);
void		*routine(void *philo_pointer);

# endif