/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/09/27 18:39:42 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void*	philo_thread(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	philo->start_at = get_current_time();
	if (philo->id % 2 == 0)
		ms_sleep(philo->program->time_to_eat / 2);
	while (!is_me_died(philo))
	{
		if (is_me_died(philo))
			return NULL;
		philo_think(philo);
		if (philo_eat(philo->program, philo) == -1)
			return NULL;
		if (is_me_died(philo))
			return NULL;
		philo_sleep(philo->program, philo);
	}
	return NULL;
}
