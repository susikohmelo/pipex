/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:21:00 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/04 18:56:23 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	sign_error(int sign)
{
	if (sign < 0)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long		rval;
	int			sign;

	i = 0;
	rval = 0;
	sign = 1;
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\r'
			|| nptr[i] == '\n' || nptr[i] == '\v' || nptr[i] == '\f'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		rval = rval * 10 + nptr[i] - '0';
		if (LONG_MAX / 10 < rval * 10)
			return (sign_error(sign));
		i++;
	}
	return (rval * sign);
}
