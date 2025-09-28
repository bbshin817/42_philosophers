/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/09/29 02:45:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->start_at_lock);
	philo->start_at = get_current_time();
	pthread_mutex_unlock(&philo->start_at_lock);
	if (philo->id % 2 == 0)
		ms_sleep(1);
	while (1)
	{
		philo_eat(philo->program, philo);
		philo_sleep(philo->program, philo);
		philo_think(philo);
	}
	return (NULL);
}
