/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/09/29 01:53:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_log(t_philo *philo, char *message)
{
	size_t	time;

	pthread_mutex_lock(&philo->program->write_lock);
	time = get_current_time() - philo->program->start_at;
	printf("\x1b[32m%zu\x1b[39m %d %s\n", time, philo->id, message);
	pthread_mutex_unlock(&philo->program->write_lock);
	return ;
}

void	ms_sleep(int ms)
{
	usleep(ms * 1000);
	return ;
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() went wrong!\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
