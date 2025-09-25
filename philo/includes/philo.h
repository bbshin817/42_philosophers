/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:36:11 by user              #+#    #+#             */
/*   Updated: 2025/09/25 18:26:54 by sbaba            ###   ########.fr       */
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
# define THREAD_DELAY_MS 200
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
	int		number_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eats_count;
}	t_program;

typedef struct s_philo
{
	int				id;
	int				is_dead;
	t_philo_state	state;
	size_t			last_meal_at;
	t_program		*program;
	pthread_mutex_t	*forks;
}	t_philo;

/* inits.c */
void	init_program(t_program *program, int argc, char *argv[]);
void	init_philos(t_program *program, pthread_mutex_t *forks, t_philo *philos);
void	init_forks(t_program *program, pthread_mutex_t *forks);
void	init_threads(t_program *program, t_philo *philos, pthread_t *threads, pthread_mutex_t *forks);

/* normalization.c */
int		ft_str2int(char *str);

/* philo_actions.c */
void	philo_sleep(t_program *program, t_philo *philo);
void	philo_think(t_program *program, t_philo *philo);
void	philo_eat(t_program *program, t_philo *philo);

/* threads.c */
void*	philo_thread(void *arg);

/* utils.c */
void	print_log(int philo_id, char *message);
void	ms_sleep(int ms);
size_t	get_current_time();
int		get_diff_micros(struct timeval tv1, struct timeval tv2);

/* validation.c */
int		ft_is_number(char *str);
int		is_allow_values(char *str[], int size);

#endif