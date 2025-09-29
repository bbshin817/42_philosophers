/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:23:59 by user              #+#    #+#             */
/*   Updated: 2025/09/29 16:16:34 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_should_be_die(t_philo *philo)
{
	int	should_die;

	should_die = 0;
	pthread_mutex_lock(&philo->meal_lock);
	if (philo->program->time_to_die < get_current_time()
		- philo->last_meal_at)
		should_die = 1;
	pthread_mutex_unlock(&philo->meal_lock);
	return (should_die);
}

int	is_glut(t_philo *philo)
{
	int	r;

	pthread_mutex_lock(&philo->meal_lock);
	r = 0;
	if (0 < philo->program->must_eats_count
		&& philo->program->must_eats_count <= philo->meals_count)
		r = 1;
	pthread_mutex_unlock(&philo->meal_lock);
	return (r);
}

void	kill_philo(t_philo *philo, int is_visible_message)
{
	if (is_visible_message == 1)
		print_log(philo, "\x1b[31mdied\x1b[39m");
	// pthread_mutex_lock(&philo->program->write_lock);
	return ;
}

void	*monitor(void *arg)
{
	int			i;
	int			glut_flag;
	t_philo		*philos;

	philos = (t_philo *)arg;
	while (1)
	{
		i = -1;
		while (++i < philos[0].program->number_of_philos)
			if (is_should_be_die(&philos[i]))
				return (kill_philo(&philos[i], 1), NULL);
		i = -1;
		glut_flag = 1;
		while (++i < philos[0].program->number_of_philos)
		{
			if (is_glut(&philos[i]) == 0)
			{
				glut_flag = 0;
				break ;
			}
		}
		if (glut_flag == 1)
			return (kill_philo(&philos[i], 0), NULL);
	}
	return (NULL);
}
