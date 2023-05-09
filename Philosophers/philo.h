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

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define INPUT_IS_NOT_A_POSITIVE_INTEGER "INPUT IS NOT A POSITIVE INTEGER"
# define INPUT_IS_OUT_OF_RANGE "INPUT IS OUT OF RANGE"
# define ARGC_IS_LESS_THAN_5_MORE_THAN_6 "ARGC IS LESS THAN 5 MORE THAN 6"
# define ALLOCATING_THREADS_IDS_ERROR "ALLOCATING THREADS IDS ERROR"
# define ALLOCATING_FORKS_ERROR "ALLOCATING FORKS ERROR"
# define ALLOCATING_PHILOS_ERROR "ALLOCATING PHILOS ERROR"
# define CREATING_THREADS_ERROR "CREATING THREADS ERROR"
# define JOINING_THREADS_ERROR "JOINING THREADS ERROR"
# define HAS_TAKEN_RIGHT_FORK "HAS TAKEN A RIGHT FORK"
# define HAS_TAKEN_LEFT_FORK "HAS TAKEN A LEFT FORK"
# define IS_THINKING "IS THINKING"
# define IS_SLEEPING "IS SLEEPING"
# define IS_EATING "IS EATING"
# define DIED "DIED"

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				eat_cont;
	int				eating;
	unsigned int	time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*rightfork;
	pthread_mutex_t	*leftfork;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	int				num_philo;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	int				num_meals;
	int				dead;
	int				finished;
	unsigned int	start_time;
	pthread_t		*tid;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	print;
}	t_data;

int				ft_atoi(const char *str);
int				ft_error(char *str, t_data *data);
int				ft_strcmp(char *s1, char *s2);
void			messages(char *str, t_philo *philo);
void			ft_exit(t_data *data);
int				ft_usleep(unsigned int time);
int				init(t_data *data, char **av);
int				thread_init(t_data *data);
int				check_input_is_number(char **av);
void			eat(t_philo *philo);
void	*supervisor(void *philo_pointer);
void			*routine(void *philo_pointer);
int				ft_av_check(char **str);
unsigned int	get_time(void);

#endif
/*
typedef struct s_philo
{
	struct s_data	*data;
	//to use data from data
	
	pthread_t		t1;
	//fist thread's ID
	
	int				id;
	// philo Number ex)first one, second one
	
	int				eat_cont;
	//count how many times eat for each philo 
	
	int				eating;
	//to check current situation eating(1) or not(0)
	
	unsigned int	time_to_die;
	//get_time() + philo->data->time_die
	
	pthread_mutex_t	lock;
	pthread_mutex_t	*rightfork;
	pthread_mutex_t	*leftfork;
}	t_philo;

typedef struct s_data
{
	
	t_philo			*philos;
	
	int				num_philo;
	//av[1] The number of philosophers and also the number of forks
	
	unsigned int	time_die;
	//av[2] The time a philosopher must fast to die
	
	unsigned int	time_eat;
	//av[3] The time it takes for a philos to eat
	
	unsigned int	time_sleep;
	//av[4] The time a philos will spend sleeping
	
	int				num_meals;//av[5]  
	//If all philos have eaten at least num_meals, simulation stops
	
	int				dead;
	
	int				finished;
	//when (av[5] == philo->eat_cont) count each person      finished ++;
	
	unsigned int	start_time;
	
	pthread_t		*tid;
	//pthread's ID
	
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	print;
}	t_data;
*/