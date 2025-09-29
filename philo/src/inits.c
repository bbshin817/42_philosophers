/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:37:19 by user              #+#    #+#             */
/*   Updated: 2025/09/29 16:10:00 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_program(t_program *program, int argc, char *argv[])
{
	pthread_mutex_init(&program->write_lock, NULL);
	program->start_at = get_current_time();
	program->number_of_philos = ft_str2int(argv[1]);
	program->time_to_die = ft_str2int(argv[2]);
	program->time_to_eat = ft_str2int(argv[3]);
	program->time_to_sleep = ft_str2int(argv[4]);
	program->must_eats_count = -1;
	if (5 < argc)
		program->must_eats_count = ft_str2int(argv[5]);
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

void	init_philos(t_program *pg, pthread_mutex_t *forks, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < pg->number_of_philos)
	{
		pthread_mutex_init(&philos[i].meal_lock, NULL);
		philos[i].id = (i + 1);
		philos[i].program = pg;
		philos[i].meals_count = 0;
		philos[i].left_fork = &forks[i];
		philos[i].last_meal_at = get_current_time();
		if (pg->number_of_philos - 1 == i)
			philos[i].right_fork = &forks[0];
		else
			philos[i].right_fork = &forks[i + 1];
		i++;
	}
	return ;
}

void	init_threads(t_program *pg, t_philo *philos, pthread_mutex_t *forks)
{
	pthread_t	monitor_t;
	pthread_t	threads[PHILO_MAX];
	int			i;

	i = -1;
	while (++i < pg->number_of_philos)
		pthread_create(&threads[i], NULL, &philo_thread, (void *)&philos[i]);
	pthread_create(&monitor_t, NULL, &monitor, (void *)philos);
	pthread_join(monitor_t, NULL);
	i = -1;
	// pthread_mutex_unlock(&philos[0].program->write_lock);
	while (++i < pg->number_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&philos[i].meal_lock);
		pthread_detach(threads[i]);
	}
	return ;
}
