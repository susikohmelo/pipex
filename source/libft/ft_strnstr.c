/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:41:35 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/07 11:52:04 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	subi;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			subi = 0;
			while (big[i + subi] && i + subi < len)
			{
				if (little[subi + 1] == '\0')
					return ((char *)big + i);
				if (little[subi + 1] != big[i + subi + 1])
					break ;
				subi++;
			}
		}
		i++;
	}
	return (0);
}
