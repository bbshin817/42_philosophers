/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:36:11 by user              #+#    #+#             */
/*   Updated: 2025/09/24 21:19:44 by sbaba            ###   ########.fr       */
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

/* defines */
#ifndef PHILO_MAX
# define PHILO_MAX 200
#endif

/* structures */
typedef	enum
{
	THINKING,
	EATING,
	SLEEPING
}	t_philo_state;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	t_philo_state	state;
	size_t			start_at;
	size_t			last_meal_at;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
}	t_philo;


#endif