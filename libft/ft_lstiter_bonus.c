/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:13:12 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 10:32:48 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_node *lst, void (*f)(int))
{
	while (lst != 0)
	{
		f(lst->data);
		lst = lst->next;
	}
}
