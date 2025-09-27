/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:36:11 by user              #+#    #+#             */
/*   Updated: 2025/09/27 18:22:31 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* include other headers */
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/* defines */
#ifndef PHILO_MAX
# define PHILO_MAX 200
#endif

#ifndef THREAD_DELAY_MS
# define THREAD_DELAY_MS 1
#endif

/* structures */
typedef	enum
{
	THINKING,
	EATING,
	SLEEPING
}	t_philo_state;

typedef struct s_program
{
	int				number_of_philos;
	size_t			start_at;
	pthread_mutex_t	dead_lock;
	int				is_someone_died;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				must_eats_count;
}	t_program;

typedef struct s_philo
{
	int				id;
	int				is_dead;
	t_philo_state	state;
	size_t			last_meal_at;
	size_t			start_at;
	int				meals_count;
	t_program		*program;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
}	t_philo;

/* inits.c */
void	init_program(t_program *program, int argc, char *argv[]);
void	init_philos(t_program *program, pthread_mutex_t *forks, t_philo *philos);
void	init_forks(t_program *program, pthread_mutex_t *forks);
void	init_threads(t_program *program, t_philo *philos, pthread_mutex_t *forks);

/* monitor.c */
void*	monitor(void *arg);

/* normalization.c */
int		ft_str2int(char *str);

/* philo_actions.c */
void	philo_sleep(t_program *program, t_philo *philo);
void	philo_think(t_philo *philo);
int		philo_eat(t_program *program, t_philo *philo);

/* threads.c */
void*	philo_thread(void *arg);
int		is_me_died(t_philo *philo);

/* utils.c */
void	print_log(t_philo *philo, char *message);
void	ms_sleep(int ms);
size_t	get_current_time();

/* validation.c */
int		ft_is_number(char *str);
int		is_allow_values(char *str[], int size);

#endif