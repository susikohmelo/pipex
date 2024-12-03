/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:41:32 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/06 14:22:53 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_nul(char *str, size_t size)
{
	size_t	len;

	len = 0;
	while (len <= size)
	{
		if (!str[len])
			return (1);
		len++;
	}
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	if (has_nul(dst, size) == 1)
		dlen = ft_strlen(dst);
	else
		dlen = size;
	slen = ft_strlen((char *)src);
	if (size <= dlen)
		return (size + slen);
	while (dlen + i < size - 1 && src[i])
	{
		dst[dlen + i] = ((char *)src)[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
