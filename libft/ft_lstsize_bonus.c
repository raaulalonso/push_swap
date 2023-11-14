/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:52:09 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 10:33:17 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst != 0)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
