/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:53:37 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 21:39:31 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	finish_sort(t_node **head_a, t_node **head_b, int min_b)
{
	t_node	*current;
	int		i;
	int		f;

	f = 0;
	i = 0;
	while (ft_lstsize(*head_b) > 0)
	{
		push(&*head_b, &*head_a, 1);
		i++;
	}
	i = 0;
	current = *head_a;
	while (current->data != min_b)
	{
		current = current->next;
		i++;
	}
	if (i > ft_lstsize(*head_a) / 2)
	{
		f = 1;
		i = (ft_lstsize(*head_a) - i);
	}
	while (i > 0)
	{
		if (f == 1)
			rev_rotate(&*head_a, 1);
		else
			rotate(&*head_a, 1);
		i--;
	}
}

void	sort_loop(t_node **head_a, t_node **head_b, int *max_b, int *min_b)
{
	int	movements;
	int	f;

	movements = 0;
	f = 0;
	move_cheaper(&*head_a, get_cheaper(&*head_a, &*head_b, *max_b, *min_b));
	if ((*head_a)->data > *max_b || (*head_a)->data < *min_b)
		check_max_min(&*head_a, &*head_b, &*max_b, &*min_b);
	else
	{
		movements = get_movements(&*head_a, &*head_b, *max_b);
		if (movements > ft_lstsize(*head_b) / 2)
			f = 1;
		insert_into_b(movements, f, &*head_a, &*head_b);
	}
}

void	big_sort(t_node **head_a, t_node **head_b)
{
	int		i;
	int		lst_size;
	int		max_b;
	int		min_b;

	max_b = (*head_b)->data;
	min_b = (*head_b)->next->data;
	i = 0;
	lst_size = ft_lstsize(*head_a);
	while (i < lst_size)
	{
		sort_loop(&*head_a, &*head_b, &max_b, &min_b);
		i++;
	}
	finish_sort(&*head_a, &*head_b, min_b);
}
