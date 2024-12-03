/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:20:45 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/29 19:06:41 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

static void	assign_strs(char *ptr, const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
}

static int	assign_ptrs(char **ptrs, const char *s, char c)
{
	int	a;
	int	b;
	int	indx;

	a = 0;
	indx = 0;
	while (s[a])
	{
		if (s[a] == c)
			a++;
		else
		{
			b = 0;
			while (s[a + b] != c && s[a + b])
				b++;
			ptrs[indx] = malloc((b + 1) * sizeof(char));
			if (!ptrs[indx])
				pipexit("separating command input failed", 0);
			assign_strs(ptrs[indx], s + a, c);
			indx++;
			a += b;
		}
	}
	return (1);
}

static char	**allocate_ptrs(char **ptrs, const char *s, char c)
{
	int	i;
	int	ptrc;

	i = 0;
	ptrc = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			ptrc++;
		i++;
	}
	ptrs = malloc((ptrc + 1) * sizeof(char *));
	if (!ptrs)
		return (0);
	ptrs[ptrc] = 0;
	return (ptrs);
}

char	**ft_csplit(char const *s, char c)
{
	char	**ptrs;
	char	*exception;
	int		i;

	ptrs = 0;
	ptrs = allocate_ptrs(ptrs, s, c);
	if (!ptrs)
		return (0);
	if (assign_ptrs(ptrs, s, c) != 1)
		return (0);
	if (*s == ' ')
	{
		i = 0;
		while (s[i] == ' ')
			i++;
		while (s[i] != ' ' && s[i])
			i++;
		exception = malloc((i + 1) * sizeof(char));
		if (!exception)
			pipexit("separating command input failed", 0);
		ft_strlcpy(exception, s, i + 1);
		free(ptrs[0]);
		ptrs[0] = exception;
	}
	return (ptrs);
}
