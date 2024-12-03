/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:57:20 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/08 13:19:07 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	memoryuse;
	void	*newmemory;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((SIZE_MAX / size) < nmemb)
		return (0);
	memoryuse = nmemb * size;
	newmemory = malloc(memoryuse);
	if (!newmemory)
		return (newmemory);
	i = 0;
	while (i < memoryuse)
	{
		((unsigned char *)newmemory)[i] = 0;
		i++;
	}
	return (newmemory);
}
