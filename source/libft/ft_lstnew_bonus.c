/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:54 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/05 15:38:40 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rnode;

	rnode = malloc(sizeof(t_list));
	if (!rnode)
		return (rnode);
	rnode->content = content;
	rnode->next = 0;
	return (rnode);
}
