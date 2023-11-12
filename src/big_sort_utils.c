/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:56:30 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/12 19:00:06 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	insert_into_b(int movements, int f, node_t **head_a, node_t **head_b)
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

void	move_cheaper(node_t **head_a, node_t *cheaper)
{
	int		movements;
	node_t	*current_a;
	int		f;

	f = 0;
	movements = 0;
	current_a = *head_a;
	while (current_a != cheaper)
	{
		current_a = current_a->next;
		movements++;
	}
	if (movements > ft_lstsize(*head_a) / 2)
	{
		movements = ft_lstsize(*head_a) - movements;
		f = 1;
	}
	while (movements != 0)
	{
		if (f == 1)
			rev_rotate(&*head_a, 1);
		else
			rotate(&*head_a, 1);
		movements--;
	}
}

int	movements_tomax(node_t *current_a, node_t **head_b, int max_b)
{
	int		movements;
	node_t	*current_b;

	movements = 0;
	current_b = *head_b;
	while (current_b != NULL && current_a->data != max_b)
	{
		current_b = current_b->next;
		movements++;
	}
	return (movements);
}

int	get_price(node_t **head_b, node_t *current_a, int max_b, int min_b)
{
	int	movements;

	movements = 0;
	if (current_a->data > max_b || current_a->data < min_b)
		movements = movements_tomax(current_a, &*head_b, max_b);
	else
		movements = get_movements(&current_a, &*head_b, max_b);
	if (movements > ft_lstsize(*head_b) / 2)
		movements = ft_lstsize(*head_b) - movements;
	return (movements);
}

node_t	*get_cheaper(node_t **head_a, node_t **head_b, int max_b, int min_b)
{
	node_t	*current_a;
	node_t	*cheaper;
	int		price;
	int		i;

	current_a = *head_a;
	price = 0;
	i = 0;
	while (current_a != NULL)
	{
		if (get_price(&*head_b, current_a, max_b, min_b) + i < price
			|| price == 0)
		{
			price = get_price(&*head_b, current_a, max_b, min_b) + i + 1;
			cheaper = current_a;
		}
		current_a = current_a->next;
		i++;
	}
	return (cheaper);
}

int	get_movements(node_t **head_a, node_t **head_b, int max_b)
{
	node_t	*current_a;
	node_t	*current_b;
	int		movements;

	current_b = *head_b;
	current_a = *head_a;
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

void	put_above_max(node_t **head_a, node_t **head_b, int max_b)
{
	int		movements;
	node_t	*current_b;
	int		f;

	f = 0;
	movements = 0;
	current_b = *head_b;
	while (current_b->data != max_b)
	{
		current_b = current_b->next;
		movements++;
	}
	if (movements > ft_lstsize(*head_b) / 2)
	{
		movements = ft_lstsize(*head_b) - movements;
		f = 1;
	}
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

void	check_max_min(node_t **head_a, node_t **head_b, int *max_b, int *min_b)
{
	node_t	*current_a;
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
