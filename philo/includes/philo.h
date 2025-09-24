/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:36:11 by user              #+#    #+#             */
/*   Updated: 2025/09/19 17:21:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/* validation.c */
int	ft_is_number(char *str);
int	is_allow_values(char *str[], int size);

/* normalization.c */
int	ft_str2int(char *str);

/* structures */
typedef	enum
{
	THINKING,
	EATING,
	SLEEPING
}	t_philo_state;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	t_philo_state	state;

	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;

}	t_philo;


#endif