/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/10/02 20:25:21 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (is_someone_died(philo) == 0)
	{
		if (philo->id % 2 == 0)
			philo_eat_r2l(philo->program, philo);
		else
			philo_eat_l2r(philo->program, philo);
		philo_sleep(philo->program, philo);
		philo_think(philo);
	}
	return (NULL);
}
