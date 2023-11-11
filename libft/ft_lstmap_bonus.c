/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:19:32 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/11 13:50:45 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

node_t	*ft_lstmap(node_t *lst, int (*f)(int), void (*del)(int))
{
	node_t	*new;
	node_t	*head;
	node_t	*tmp;

	if (lst)
	{
		head = ft_lstnew(f(lst->data));
		if (!head)
			return (0);
		tmp = lst->next;
		while (tmp)
		{
			new = ft_lstnew(f(tmp->data));
			if (!new)
			{
				ft_lstclear(&tmp, del);
				return (0);
			}
			ft_lstadd_back(&head, new);
			tmp = tmp->next;
		}
		return (head);
	}
	return (0);
}
