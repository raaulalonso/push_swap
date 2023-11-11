/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:25:04 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/11 12:29:52 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Moves the first node of the list to the end.*/
void	rotate(node_t **head, int print)
{
	node_t	*current;

	if (head != NULL && (*head)->next != NULL)
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = *head;
		*head = (*head)->next;
		current->next->next = NULL;
		if (print == 1)
			ft_printf("ra\n");
		else if (print == 2)
			ft_printf("rb\n");
	}
}

/*Rotates both stacks.*/
void	rotate_both(node_t **head_a, node_t **head_b)
{
	rotate(&*head_a, 3);
	rotate(&*head_b, 3);
	ft_printf("rr\n");
}

/*Moves the last node of the list to the start.*/
void	rev_rotate(node_t **head, int print)
{
	node_t	*current;

	if (*head != NULL && (*head)->next != NULL)
	{
		current = *head;
		while (current->next->next != NULL)
			current = current->next;
		current->next->next = *head;
		*head = current->next;
		current->next = NULL;
		if (print == 1)
			ft_printf("rra\n");
		else if (print == 2)
			ft_printf("rrb\n");
	}
}

/*Reverse rotates both stacks.*/
void	rev_rotate_both(node_t **head_a, node_t **head_b)
{
	rev_rotate(&*head_a, 3);
	rev_rotate(&*head_b, 3);
	ft_printf("rrr\n");
}
