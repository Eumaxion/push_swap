/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:40:46 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/01 18:08:27 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static long	convert(const char *nptr, int i, int sign, long result)
{
	int	digit;

	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		digit = nptr[i] - '0';
		if (result > (LONG_MAX - digit) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + digit;
		i++;
	}
	return (result * sign);
}

long	ft_atol(const char *nptr)
{
	int			i;
	int			sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	result = convert(nptr, i, sign, result);
	return (result);
}
