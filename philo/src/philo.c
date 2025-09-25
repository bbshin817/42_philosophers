/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/09/25 18:28:24 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_sleep(t_program *program, t_philo *philo)
{
	print_log(philo->id, "is sleeping");
	ms_sleep(program->time_to_sleep);
	return ;
}

void	philo_think(t_program *program, t_philo *philo)
{
	print_log(philo->id, "is thinking");
	(void)program;
	return ;
}

int	check_died(t_philo *philo, size_t try_eat_at)
{
	size_t	time_to_eat;

	time_to_eat = philo->program->time_to_eat;
	if (time_to_eat < get_current_time() - philo->last_meal_at
		|| time_to_eat < get_current_time() - try_eat_at)
	{
		print_log(philo->id, "died");
		philo->is_dead = 1;
		return (-1);
	}
	return (0);
}

void	philo_eat(t_program *program, t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	size_t				try_eat_at;

	// use left fork
	if (1 == philo->id)
		left_fork = &philo->forks[program->number_of_philos - 1];
	else
		left_fork = &philo->forks[philo->id - 1];
	// use right fork
	if (200 == philo->id)
		right_fork = &philo->forks[0];
	else
		right_fork = &philo->forks[philo->id];
	try_eat_at = get_current_time();
	pthread_mutex_lock(left_fork);
	pthread_mutex_lock(right_fork);
	// フォークの使用を試みた時刻と、実際にフォークを手にした時刻の差分をとり、それがtime_to_eatを超えていたらdie
	if (check_died(philo, try_eat_at) == -1)
		return;
	philo->last_meal_at = get_current_time();
	print_log(philo->id, "has taken a fork");
	print_log(philo->id, "is eating");
	ms_sleep(program->time_to_eat);
	pthread_mutex_unlock(left_fork);
	pthread_mutex_unlock(right_fork);
	return ;
}