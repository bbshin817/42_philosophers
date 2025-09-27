/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:37:19 by user              #+#    #+#             */
/*   Updated: 2025/09/27 18:19:24 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_program(t_program *program, int argc, char *argv[])
{
	pthread_mutex_init(&program->dead_lock, NULL);
	program->start_at = get_current_time();
	program->number_of_philos = ft_str2int(argv[1]);
	program->time_to_die = ft_str2int(argv[2]);
	program->time_to_eat = ft_str2int(argv[3]);
	program->time_to_sleep = ft_str2int(argv[4]);
	program->is_someone_died = 0;
	program->must_eats_count = -1;
	if (5 < argc)
		program->must_eats_count  = ft_str2int(argv[5]);
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
	int	i;

	i = 0;
	while (i < program->number_of_philos)
	{
		pthread_mutex_init(&philos[i].write_lock, NULL);
		pthread_mutex_init(&philos[i].dead_lock, NULL);
		pthread_mutex_init(&philos[i].meal_lock, NULL);
		philos[i].id = (i + 1);
		philos[i].is_dead = 0;
		philos[i].program = program;
		philos[i].meals_count = 0;
		/* left fork */
		philos[i].left_fork = &forks[i];
		/* right fork*/
		if (program->number_of_philos - 1 == i)
			philos[i].right_fork = &forks[0];
		else
			philos[i].right_fork = &forks[i + 1];
		philos[i].last_meal_at = get_current_time();
		i++;
	}
	return ;
}

void	init_threads(t_program *program, t_philo *philos, pthread_mutex_t *forks)
{
	pthread_t	monitor_t;
	pthread_t	threads[PHILO_MAX];
	int			i;

	i = -1;
	while (++i < program->number_of_philos)
		pthread_create(&threads[i], NULL, &philo_thread, (void *)&philos[i]);
	pthread_create(&monitor_t, NULL, &monitor, (void *)philos);
	i = -1;
	while (++i < program->number_of_philos)
		pthread_join(threads[i], NULL);
	pthread_join(monitor_t, NULL);
	i = -1;
	while (++i < program->number_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&philos[i].write_lock);
		pthread_mutex_destroy(&philos[i].dead_lock);
		pthread_mutex_destroy(&philos[i].meal_lock);
	}
	pthread_mutex_destroy(&program->dead_lock);
	return ;
}