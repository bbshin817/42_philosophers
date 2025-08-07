/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:42:03 by user              #+#    #+#             */
/*   Updated: 2025/07/28 10:46:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str2int(char *str)
{
	int	result;
	int	digit;

	result = 0;
	digit = 0;
	while ('0' <= *str && *str <= '9')
	{
		digit = *str - '0';
		result = result * 10 + digit;
		str++;
	}
	return (result);
}