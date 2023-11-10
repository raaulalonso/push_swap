/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:25:01 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/10 20:27:13 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Swaps the first two nodes in a list.*/
void	swap(node_t **head)
{
	node_t	*tmp;

	if ((*head)->next != NULL && *head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = (*head)->next;
		(*head)->next = tmp;
	}
}

void	swap_both(node_t **head_a, node_t **head_b)
{
	swap(&*head_a);
	swap(&*head_b);
}
