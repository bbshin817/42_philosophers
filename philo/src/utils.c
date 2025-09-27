/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/09/27 18:02:12 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_log(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->write_lock);
	printf("%zu %d %s\n", get_current_time() - philo->program->start_at, philo->id, message);
	pthread_mutex_unlock(&philo->write_lock);
	return ;
}

void	ms_sleep(int ms)
{
	usleep(ms * 1000);
	return ;
}

size_t	get_current_time()
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() went wrong!\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	is_me_died(t_philo *philo)
{
	int	r;

	pthread_mutex_lock(&philo->dead_lock);
	r = philo->is_dead;
	pthread_mutex_unlock(&philo->dead_lock);
	return (r);
}
