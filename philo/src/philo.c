/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/09/29 02:53:52 by user             ###   ########.fr       */
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

int	philo_eat(t_program *program, t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_log(philo, "has taken a fork");
	if (philo->program->number_of_philos == 1)
	{
		ms_sleep(philo->program->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
	}
	pthread_mutex_lock(philo->right_fork);
	print_log(philo, "has taken a fork");
	pthread_mutex_lock(&philo->meal_lock);
	print_log(philo, "is eating");
	philo->last_meal_at = get_current_time();
	philo->meals_count++;
	pthread_mutex_unlock(&philo->meal_lock);
	ms_sleep(program->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}
