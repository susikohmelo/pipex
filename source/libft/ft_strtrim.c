/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:12:40 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/07 11:50:34 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trimchar(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		begin;
	int		ending;

	if (!set || !s1)
		return (0);
	ending = ft_strlen(s1);
	begin = 0;
	while (s1[begin] && is_trimchar(s1[begin], set) == 1)
		begin++;
	while (is_trimchar(s1[ending - 1], set) == 1 && ending > begin)
		ending--;
	newstr = ft_substr(s1, begin, ending - begin);
	return (newstr);
}
