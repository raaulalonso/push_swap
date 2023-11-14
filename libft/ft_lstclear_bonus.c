/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:59:33 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 10:32:36 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_node **lst, void (*del)(int))
{
	t_node	*aux;
	t_node	*next;

	aux = *lst;
	while (aux)
	{
		next = aux->next;
		ft_lstdelone(aux, del);
		aux = next;
	}
	(*lst) = 0;
}
