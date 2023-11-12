/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:53:37 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/12 18:21:28 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	finish_sort(node_t **head_a, node_t **head_b, int min_b)
{
	int	i;
	int	lst_size;

	i = 0;
	lst_size = ft_lstsize(*head_b);
	while (i < lst_size)
	{
		push(&*head_b, &*head_a, 1);
		i++;
	}
	while ((*head_a)->data != min_b)
	{
		rev_rotate(&*head_a, 1);
	}
}

void	sort_loop(node_t **head_a, node_t **head_b, int *max_b, int *min_b)
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

void	big_sort(node_t **head_a, node_t **head_b)
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
