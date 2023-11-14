/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:30 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 10:29:09 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	insert_into_b(int movements, int f, t_node **head_a, t_node **head_b)
{
	int	i;

	if (f == 1)
	{
		i = ft_lstsize(*head_b) - movements;
		movements = i + 1;
	}
	else
		i = movements;
	while (i != 0)
	{
		if (f == 1)
			rev_rotate(&*head_b, 2);
		else
			rotate(&*head_b, 2);
		i--;
	}
	push(&*head_a, &*head_b, 2);
}

int	movements_loop(t_node *current_b, t_node *current_a, int max_b)
{
	int	movements;

	movements = 0;
	while (current_b != NULL && max_b != current_b->data)
	{
		current_b = current_b->next;
		movements++;
	}
	while (current_b != NULL && current_a->data < current_b->data)
	{
		current_b = current_b->next;
		movements++;
	}
	if (current_b == NULL)
		return (-1);
	else
		return (movements);
}

int	get_movements(t_node **head_a, t_node **head_b, int max_b)
{
	t_node	*current_a;
	t_node	*current_b;
	int		movements;

	current_b = *head_b;
	current_a = *head_a;
	movements = 0;
	movements = movements_loop(current_b, current_a, max_b);
	if (movements == -1)
	{
		current_b = *head_b;
		movements = 0;
		while (current_b != NULL && current_a->data < current_b->data)
		{
			current_b = current_b->next;
			movements++;
		}
	}
	return (movements);
}

void	put_above_max(t_node **head_a, t_node **head_b, int max_b)
{
	int		movements;
	t_node	*current_b;
	int		f;

	f = 0;
	movements = 0;
	current_b = *head_b;
	movements = moves_to_max(current_b, &*head_b, max_b, &f);
	while (movements != 0)
	{
		if (f == 1)
			rev_rotate(&*head_b, 2);
		else
			rotate(&*head_b, 2);
		movements--;
	}
	push(&*head_a, &*head_b, 2);
}

void	check_max_min(t_node **head_a, t_node **head_b, int *max_b, int *min_b)
{
	t_node	*current_a;
	int		aux;

	current_a = *head_a;
	if (current_a->data > *max_b)
	{
		aux = current_a->data;
		put_above_max(&*head_a, &*head_b, *max_b);
		*max_b = aux;
	}
	else if (current_a->data < *min_b)
	{
		*min_b = current_a->data;
		put_above_max(&*head_a, &*head_b, *max_b);
	}
}
