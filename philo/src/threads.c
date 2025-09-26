/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/09/27 01:18:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_someone_dead(t_program *program)
{
	int	r;

	pthread_mutex_lock(&program->dead_lock);
	r = program->is_someone_died;
	pthread_mutex_unlock(&program->dead_lock);
	return (r);
}

void*	philo_thread(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ms_sleep(philo->program->time_to_eat / 2);
	while (!philo->is_dead)
	{
		philo_think(philo);
		if (philo_eat(philo->program, philo) == -1)
			break;
		philo_sleep(philo->program, philo);
	}
	return NULL;
}
