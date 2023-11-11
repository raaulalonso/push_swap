/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:02:36 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/11 13:46:59 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

node_t	*ft_lstnew(int content)
{
	node_t	*lst;

	lst = malloc(sizeof(node_t));
	if (!lst)
		return (0);
	lst->data = content;
	lst->next = 0;
	return (lst);
}
