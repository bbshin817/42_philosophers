/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/09/25 18:19:31 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_log(int philo_id, char *message)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld%ld %d %s\n", tv.tv_sec, (tv.tv_usec / 1000), philo_id, message);
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

int	get_diff_micros(struct timeval tv1, struct timeval tv2)
{
	size_t	time_1;
	size_t	time_2;

	time_1 = tv1.tv_sec * 1000 + tv1.tv_usec / 1000;
	time_2 = tv2.tv_sec * 1000 + tv2.tv_usec / 1000;
	// printf("[Diff] %lu\n", time_2 - time_1);
	return (time_2 - time_1);
}