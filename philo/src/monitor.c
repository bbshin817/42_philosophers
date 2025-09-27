/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:23:59 by user              #+#    #+#             */
/*   Updated: 2025/09/27 18:42:41 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_should_be_die(t_philo *philo)
{
	int	should_die;

	should_die = 0;
	pthread_mutex_lock(&philo->meal_lock);
	// スレッド開始からtime_to_die経過しており、一度も食事してなかったら
	if (philo->program->time_to_die < get_current_time() - philo->start_at && 0 == philo->meals_count)
		should_die = 1;
	// 最後に食事した時刻からtime_to_die経過していたら
	if (philo->program->time_to_die < get_current_time() - philo->last_meal_at)
		should_die = 1;
	// オプション引数が設定されており、必要以上食べていれば
	if (philo->program->must_eats_count != -1 && philo->program->must_eats_count < philo->meals_count)
		should_die = 1;
	pthread_mutex_unlock(&philo->meal_lock);
	return (should_die);
}

void*	monitor(void *arg)
{
	int			i;
	t_philo		*philos;

	philos = (t_philo *)arg;
	while(1)
	{
		i = -1;
		while (++i < philos[0].program->number_of_philos)
		{
			if (is_should_be_die(&philos[i]))
			{
				pthread_mutex_lock(&philos[i].dead_lock);
				philos[i].is_dead = 1;
				philos[i].program->is_someone_died = 1;
				print_log(&philos[i], "died");
				pthread_mutex_unlock(&philos[i].dead_lock);
				break;
			}
		}
		if (philos[0].program->is_someone_died == 1)
		{
			while (++i < philos[0].program->number_of_philos)
			{
				pthread_mutex_lock(&philos[i].dead_lock);
				philos[i].is_dead = 1;
				pthread_mutex_unlock(&philos[i].dead_lock);
			}
			break;
		}
	}
	return NULL;
}