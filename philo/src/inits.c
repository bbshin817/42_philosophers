/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:37:19 by user              #+#    #+#             */
/*   Updated: 2025/09/25 17:31:12 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_program(t_program *program, int argc, char *argv[])
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	program->start_at = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	program->number_of_philos = ft_str2int(argv[1]);
	program->time_to_die = ft_str2int(argv[2]);
	program->time_to_eat = ft_str2int(argv[3]);
	program->time_to_sleep = ft_str2int(argv[4]);
	if (5 < argc)
		program->time_to_sleep = ft_str2int(argv[5]);
	else
		program->time_to_sleep = 0;
	return ;
}

void	init_philos(t_program *program, t_philo *philos)
{
	int				i;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	i = 0;
	while (i < program->number_of_philos)
	{
		philos[i].id = (i + 1);
		i++;
	}
	return ;
}

void	init_forks(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->number_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return ;
}