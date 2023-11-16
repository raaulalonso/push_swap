/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:26:20 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/16 21:23:02 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/* 2 | 1 | 3 */
/* 3 | 1 | 2 */
/* 2 | 3 | 1 */
/* 3 | 2 | 1 */
/* 1 | 3 | 2 */
void	three_sort(t_node **head_a)
{
	if ((*head_a)->next->data < (*head_a)->data
		&& (*head_a)->data < (*head_a)->next->next->data)
		swap(&*head_a, 1);
	else if ((*head_a)->next->data < (*head_a)->next->next->data
		&& (*head_a)->next->next->data < (*head_a)->data)
		rotate(&*head_a, 1);
	else if ((*head_a)->next->next->data < (*head_a)->data
		&& (*head_a)->data < (*head_a)->next->data)
		rev_rotate(&*head_a, 1);
	else if ((*head_a)->next->next->data < (*head_a)->next->data
		&& (*head_a)->next->data < (*head_a)->data)
	{
		swap(&*head_a, 1);
		rev_rotate(&*head_a, 1);
	}
	else if ((*head_a)->data < (*head_a)->next->next->data
		&& (*head_a)->next->next->data < (*head_a)->next->data)
	{
		swap(&*head_a, 1);
		rotate(&*head_a, 1);
	}
}

void	five_sort_loop(t_node **head_a, t_node **head_b, int min)
{
	t_node	*current;
	int		movements;
	int		f;

	f = 0;
	movements = movements_for_five(&*head_a, &*head_b, min);
	if (movements == -1)
	{
		movements = 0;
		current = *head_a;
		while (current != NULL && (*head_b)->data > current->data)
		{
			current = current->next;
			movements++;
		}
		if (current == NULL)
		{
			finish_sort(&*head_a, min);
			push(&*head_b, &*head_a, 1);
			return ;
		}
	}
	insert_into_a(movements, &*head_a, &*head_b);
}

void	five_sort(t_node **head_a, t_node **head_b)
{
	int	i;
	int	movements;
	int	min;
	int	lst_size;

	i = 0;
	movements = 0;
	while (ft_lstsize(*head_a) > 3)
		push(&*head_a, &*head_b, 2);
	three_sort(&*head_a);
	min = (*head_a)->data;
	lst_size = ft_lstsize(*head_b);
	while (i <= lst_size - 1)
	{
		five_sort_loop(&*head_a, &*head_b, check_min(&*head_a, min));
		i++;
	}
	min = check_min(&*head_a, min);
	if ((*head_a)->data != min)
		finish_sort(&*head_a, min);
}

void	small_sort(t_node **head_a, t_node **head_b, int num)
{
	if (num == 2)
		swap(&*head_a, 1);
	else if (num == 3)
		three_sort(&*head_a);
	else if (num > 3)
		five_sort(&*head_a, &*head_b);
}
