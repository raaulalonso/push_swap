/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:01:25 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/16 21:22:47 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	movements_for_five(t_node **head_a, t_node **head_b, int min)
{
	t_node	*current;
	int		movements;

	movements = 0;
	current = *head_a;
	while (current != NULL && current->data != min)
	{
		current = current->next;
		movements++;
	}
	while (current != NULL && (*head_b)->data > current->data)
	{
		current = current->next;
		movements++;
	}
	if (current == NULL)
		return (-1);
	return (movements);
}

void	insert_into_a(int movements, t_node **head_a, t_node **head_b)
{
	int	f;

	f = 0;
	if (movements > ft_lstsize(*head_a) / 2)
	{
		movements = ft_lstsize(*head_a) - movements;
		f = 1;
	}
	while (movements > 0)
	{
		if (f == 1)
			rev_rotate(&*head_a, 1);
		else
			rotate(&*head_a, 1);
		movements--;
	}
	push(&*head_b, &*head_a, 1);
}

int	check_min(t_node **head_a, int min)
{
	t_node	*current;

	current = *head_a;
	while (current != NULL)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}
