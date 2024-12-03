/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:21:41 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/06 14:20:52 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstring;
	unsigned long	i;
	unsigned long	s1len;
	unsigned long	s2len;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	newstring = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!newstring)
		return (0);
	i = 0;
	while (i < s1len + s2len)
	{
		if (i < s1len)
			newstring[i] = s1[i];
		else
			newstring[i] = s2[i - s1len];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
