/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:41:57 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/06 14:33:55 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_length(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		ilen;
	long	nl;

	nl = n;
	ilen = int_length(nl);
	str = malloc((ilen + 1) * sizeof(char));
	if (!str)
		return (0);
	i = ilen - 1;
	ft_bzero(str, (ilen + 1) * sizeof(char));
	if (nl < 0)
	{
		str[0] = '-';
		nl *= -1;
	}
	while (ilen > 0 && str[i] != '-')
	{
		str[i] = nl % 10 + '0';
		nl /= 10;
		ilen--;
		i--;
	}
	return (str);
}
