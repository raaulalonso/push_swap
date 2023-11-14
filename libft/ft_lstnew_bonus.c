/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:02:36 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 10:33:12 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstnew(int content)
{
	t_node	*lst;

	lst = malloc(sizeof(t_node));
	if (!lst)
		return (0);
	lst->data = content;
	lst->next = 0;
	return (lst);
}
