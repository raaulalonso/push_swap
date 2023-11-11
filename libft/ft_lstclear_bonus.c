/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:59:33 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/11 13:49:13 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(node_t **lst, void (*del)(int))
{
	node_t	*aux;
	node_t	*next;

	aux = *lst;
	while (aux)
	{
		next = aux->next;
		ft_lstdelone(aux, del);
		aux = next;
	}
	(*lst) = 0;
}
