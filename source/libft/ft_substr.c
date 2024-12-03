/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:09:54 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/07 11:51:10 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_str(char	*newstr)
{
	newstr = malloc(sizeof(char));
	if (!newstr)
		return (0);
	newstr[0] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	if (!s)
		return (0);
	newstr = 0;
	if (ft_strlen(s) < start)
		return (empty_str(newstr));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (0);
	i = 0;
	while (i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
