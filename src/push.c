/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:25:06 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/10 20:27:19 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Push the first node from the list pointed by head_1 
to the first position in the list pointed by head_2.*/
void	push(node_t **head_1, node_t **head_2)
{
	node_t	*tmp;

	if (head_1 != NULL)
	{
		tmp = *head_2;
		*head_2 = *head_1;
		*head_1 = (*head_1)->next;
		(*head_2)->next = tmp;
	}
}
