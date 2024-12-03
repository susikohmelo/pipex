/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:29:59 by ljylhank          #+#    #+#             */
/*   Updated: 2024/11/05 18:23:54 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*current;
	void	*fcont;

	new = 0;
	if (!del || !lst || !f)
		return (0);
	current = lst;
	while (current)
	{
		fcont = f(current->content);
		temp = ft_lstnew(fcont);
		if (!temp)
		{
			del(fcont);
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, temp);
		current = current->next;
	}
	temp->next = 0;
	return (new);
}
