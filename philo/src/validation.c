/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:21:37 by user              #+#    #+#             */
/*   Updated: 2025/09/29 01:52:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/*
this function checks these points.
- is a value number ?
- is a value more than 0 ?
- is a value less than 200 when an index is 1 ?
- is a value more than 60 an index between 2 and 4 ?
*/
int	is_allow_values(char *str[], int size)
{
	int	i;
	int	num;

	i = 1;
	while (i < size)
	{
		if (!ft_is_number(str[i]))
			return (0);
		num = ft_str2int(str[i]);
		if (num <= 0 || (i == 1 && 200 < num)
			|| (2 <= i && i <= 4 && num < 60))
			return (0);
		i++;
	}
	return (1);
}
