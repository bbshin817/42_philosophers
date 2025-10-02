/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/10/02 20:12:02 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_log(t_philo *philo, char *message)
{
	size_t	time;

	pthread_mutex_lock(&philo->program->write_lock);
	if (is_someone_died(philo) == 1)
	{
		pthread_mutex_unlock(&philo->program->write_lock);
		return ;
	}
	time = get_current_time() - philo->program->start_at;
	printf("\x1b[32m%zu\x1b[39m %d %s\n", time, philo->id, message);
	pthread_mutex_unlock(&philo->program->write_lock);
	return ;
}

void	ms_sleep(size_t ms)
{
	size_t	time;

	time = get_current_time();
	while ((get_current_time() - time) <= ms)
		usleep(500);
	return ;
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() went wrong!\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	is_someone_died(t_philo	*philo)
{
	int	r;

	pthread_mutex_lock(&philo->program->died_lock);
	r = philo->program->is_someone_died;
	pthread_mutex_unlock(&philo->program->died_lock);
	return (r);
}
