/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:55 by user              #+#    #+#             */
/*   Updated: 2025/09/25 17:15:02 by sbaba            ###   ########.fr       */
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

int	philo_eat(t_program *program, t_philo *philo)
{
	print_log(philo->id, "is eating");
	(void)program;
	return (0);
}
