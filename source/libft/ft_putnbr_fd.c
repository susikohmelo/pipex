/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:15:36 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/06 14:32:44 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	towrite[1];
	long	nl;

	nl = n;
	if (nl < 0)
	{
		nl *= -1;
		write(fd, "-", 1);
	}
	if (nl / 10 > 0)
		ft_putnbr_fd(nl / 10, fd);
	towrite[0] = nl % 10 + '0';
	write(fd, towrite, 1);
}
