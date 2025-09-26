/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/09/27 01:24:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_sleep(t_program *program, t_philo *philo)
{
	print_log(philo, "is sleeping");
	ms_sleep(program->time_to_sleep);
	return ;
}

void	philo_think(t_philo *philo)
{
	print_log(philo, "is thinking");
	return ;
}

int	check_died(t_philo *philo, size_t try_eat_at)
{
	size_t	time_to_eat;

	time_to_eat = philo->program->time_to_eat;
	if (time_to_eat < get_current_time() - philo->last_meal_at
		|| time_to_eat < get_current_time() - try_eat_at)
	{
		print_log(philo, "died");
		philo->is_dead = 1;
		pthread_mutex_lock(&philo->program->dead_lock);
		philo->program->is_someone_died = 1;
		pthread_mutex_unlock(&philo->program->dead_lock);
		return (-1);
	}
	return (0);
}

int	philo_eat(t_program *program, t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_log(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_log(philo, "has taken a fork");
	print_log(philo, "is eating");
	philo->last_meal_at = get_current_time();
	philo->meals_count++;
	ms_sleep(program->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}