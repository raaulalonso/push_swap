/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:25:04 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/10 20:33:04 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Moves the first node of the list to the end.*/
void	rotate(node_t **head)
{
	node_t	*current;

	if (head != NULL)
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = *head;
		*head = (*head)->next;
		current->next->next = NULL;
	}
}

/*Rotates both stacks.*/
void	rotate_both(node_t **head_a, node_t **head_b)
{
	rotate(&*head_a);
	rotate(&*head_b);
}

/*Moves the last node of the list to the start.*/
void	rev_rotate(node_t **head)
{
	node_t	*current;

	if (*head != NULL)
	{
		current = *head;
		while (current->next->next != NULL)
			current = current->next;
		current->next->next = *head;
		*head = current->next;
		current->next = NULL;
	}
}

/*Reverse rotates both stacks.*/
void	rev_rotate_both(node_t **head_a, node_t **head_b)
{
	rev_rotate(&*head_a);
	rev_rotate(&*head_b);
}
