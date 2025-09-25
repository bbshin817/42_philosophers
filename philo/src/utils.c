/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/09/25 17:14:29 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_log(int philo_id, char *message)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld.%ld %d %s", tv.tv_sec, (tv.tv_usec / 1000), philo_id, message);
	return ;
}

void	ms_sleep(int ms)
{
	usleep(ms * 1000);
	return ;
}