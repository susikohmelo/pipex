/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:49:02 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/06 14:26:14 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rstr;

	if (!s || !f)
		return (0);
	i = ft_strlen(s);
	rstr = malloc((i + 1) * sizeof(char));
	if (!rstr)
		return (0);
	i = 0;
	while (s[i])
	{
		rstr[i] = f(i, s[i]);
		i++;
	}
	rstr[i] = '\0';
	return (rstr);
}
