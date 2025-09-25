/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:37:19 by user              #+#    #+#             */
/*   Updated: 2025/09/25 18:30:34 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_program(t_program *program, int argc, char *argv[])
{
	program->number_of_philos = ft_str2int(argv[1]);
	program->time_to_die = ft_str2int(argv[2]);
	program->time_to_eat = ft_str2int(argv[3]);
	program->time_to_sleep = ft_str2int(argv[4]);
	if (5 < argc)
		program->time_to_sleep = ft_str2int(argv[5]);
	else
		program->time_to_sleep = 0;
	return ;
}

void	init_forks(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->number_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return ;
}

void	init_philos(t_program *program, pthread_mutex_t *forks, t_philo *philos)
{
	int				i;

	i = 0;
	while (i < program->number_of_philos)
	{
		philos[i].id = (i + 1);
		philos[i].is_dead = 0;
		philos[i].program = program;
		philos[i].forks = forks;
		philos[i].last_meal_at = get_current_time();
		i++;
	}
	return ;
}

void	init_threads(t_program *program, t_philo *philos, pthread_t *threads, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->number_of_philos)
	{
		pthread_create(&threads[i], NULL, &philo_thread, (void *)&philos[i]);
		i++;
	}
	i = 0;
	while (i < program->number_of_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	i = 0;
	while (i < program->number_of_philos)
	{
		pthread_detach(threads[i]);
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	return ;
}