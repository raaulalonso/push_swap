/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheaper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:05:02 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/16 21:20:02 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	moves_to_max(t_node *current_b, t_node **head_b, int max_b, int *f)
{
	int	movements;

	movements = 0;
	while (current_b->data != max_b)
	{
		current_b = current_b->next;
		movements++;
	}
	if (movements > ft_lstsize(*head_b) / 2)
	{
		movements = ft_lstsize(*head_b) - movements;
		*f = 1;
	}
	return (movements);
}

int	get_price(t_node **head_b, t_node *current_a, int max_b, int min_b)
{
	int	movements;
	int	f;

	f = 0;
	movements = 0;
	if (current_a->data > max_b || current_a->data < min_b)
		movements = moves_to_max(*head_b, &*head_b, max_b, &f);
	else
		movements = get_movements(&current_a, &*head_b, max_b);
	if (movements > ft_lstsize(*head_b) / 2)
		movements = ft_lstsize(*head_b) - movements;
	return (movements);
}

t_node	*get_cheaper(t_node **head_a, t_node **head_b, int max_b, int min_b)
{
	t_node	*current_a;
	t_node	*cheaper;
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

void	move_cheaper(t_node **head_a, t_node *cheaper)
{
	int		movements;
	t_node	*current_a;
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
