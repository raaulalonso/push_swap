/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:25:01 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/11 12:28:16 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Swaps the first two nodes in a list.*/
void	swap(node_t **head, int print)
{
	node_t	*tmp;

	if (*head != NULL && (*head)->next != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = (*head)->next;
		(*head)->next = tmp;
		if (print == 1)
			ft_printf("sa\n");
		else if (print == 2)
			ft_printf("sb\n");
	}
}

void	swap_both(node_t **head_a, node_t **head_b)
{
	swap(&*head_a, 3);
	swap(&*head_b, 3);
	ft_printf("ss\n");
}
