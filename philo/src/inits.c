/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:37:19 by user              #+#    #+#             */
/*   Updated: 2025/10/02 19:15:52 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_program(t_program *program, int argc, char *argv[])
{
	pthread_mutex_init(&program->died_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	program->start_at = get_current_time();
	program->number_of_philos = ft_str2int(argv[1]);
	program->time_to_die = ft_str2int(argv[2]);
	program->time_to_eat = ft_str2int(argv[3]);
	program->time_to_sleep = ft_str2int(argv[4]);
	program->must_eats_count = -1;
	program->is_someone_died = 0;
	if (5 < argc)
		program->must_eats_count = ft_str2int(argv[5]);
	return ;
}

void	init_forks(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->number_of_philos)
	{
		pthread_mutex_init(&program->forks[i], NULL);
		i++;
	}
	return ;
}

void	init_philos(t_program *pg, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < pg->number_of_philos)
	{
		pthread_mutex_init(&philos[i].meal_lock, NULL);
		philos[i].id = (i + 1);
		philos[i].program = pg;
		philos[i].meals_count = 0;
		philos[i].left_fork = &pg->forks[i];
		philos[i].last_meal_at = get_current_time();
		if (pg->number_of_philos - 1 == i)
			philos[i].right_fork = &pg->forks[0];
		else
			philos[i].right_fork = &pg->forks[i + 1];
		i++;
	}
	return ;
}

int	destroy_all(t_program *pg, t_philo *philos, int is_error)
{
	int	i;

	if (is_error == 1)
		printf("Failed to create philo threads.\n");
	i = -1;
	pthread_mutex_destroy(&pg->write_lock);
	pthread_mutex_destroy(&pg->died_lock);
	while (++i < pg->number_of_philos)
	{
		pthread_mutex_destroy(&pg->forks[i]);
		pthread_mutex_destroy(&philos[i].meal_lock);
	}
	return (is_error);
}

int	launch(t_program *pg, t_philo *philos)
{
	pthread_t	monitor_t;
	pthread_t	threads[PHILO_MAX];
	int			i;

	i = -1;
	while (++i < pg->number_of_philos)
	{
		if (pthread_create(&threads[i], NULL, &philo_thread, (void *)&philos[i])
			!= 0)
			return (destroy_all(pg, philos, 1));
	}
	if (pthread_create(&monitor_t, NULL, &monitor, (void *)philos) != 0)
		return (destroy_all(pg, philos, 1));
	if (pthread_join(monitor_t, NULL) != 0)
		return (destroy_all(pg, philos, 1));
	i = -1;
	while (++i < pg->number_of_philos)
		if (pthread_join(threads[i], NULL) != 0)
			return (destroy_all(pg, philos, 1));
	return (destroy_all(pg, philos, 0));
}
