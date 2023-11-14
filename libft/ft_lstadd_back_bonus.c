/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:10:59 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 10:32:18 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_node **lst, t_node*new)
{
	t_node	*aux;

	if (*lst == 0)
		(*lst) = new;
	else
	{
		aux = ft_lstlast(*lst);
		aux->next = new;
	}
}
