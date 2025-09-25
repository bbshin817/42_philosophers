/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:37:19 by user              #+#    #+#             */
/*   Updated: 2025/09/25 18:27:29 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char *argv[])
{
	t_program			program;
	t_philo				philos[PHILO_MAX];
	pthread_mutex_t		forks[PHILO_MAX];
	pthread_t			threads[PHILO_MAX];

	if (argc < 5 || 6 < argc || !is_allow_values(argv, argc))
	{
		printf("Error: You entered invalid parameters.\n");
		return (-1);
	}
	init_program(&program, argc, argv);
	init_forks(&program, forks);
	init_philos(&program, forks, philos);
	init_threads(&program, philos, threads, forks);
	return (0);
}
