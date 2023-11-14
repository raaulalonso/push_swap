/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:26:20 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 21:39:11 by raalonso         ###   ########.fr       */
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

void	five_sort_movements(t_node **head_a, t_node **head_b, int min)
{
	t_node	*current;
	int		i;
	int		j;
	int		f;

	i = 0;
	j = 0;
	f = 0;
	current = *head_a;
	while (current != NULL && current->data != min)
	{
		current = current->next;
		i++;
	}
	while (current != NULL && (*head_b)->data > current->data)
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
	{
		i = 0;
		current = *head_a;
		while (current != NULL && (*head_b)->data > current->data)
		{
			current = current->next;
			i++;
		}
		if (current == NULL)
		{
			finish_five_sort(&*head_a, min);
			push(&*head_b, &*head_a, 1);
			return ;
		}
	}
	if (i > ft_lstsize(*head_a) / 2)
	{
		i = ft_lstsize(*head_a) - i;
		f = 1;
		j = i + 1;
	}
	else
		j = i;
	while (i > 0)
	{
		if (f == 1)
			rev_rotate(&*head_a, 1);
		else
			rotate(&*head_a, 1);
		i--;
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

void	finish_five_sort(t_node **head_a, int min)
{
	t_node	*current;
	int		i;
	int		f;

	i = 0;
	f = 0;
	current = *head_a;
	while (current->data != min)
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

void	five_sort(t_node **head_a, t_node **head_b)
{
	int	i;
	int	movements;
	int	min;

	i = 0;
	movements = 0;
	while (ft_lstsize(*head_a) > 3)
		push(&*head_a, &*head_b, 2);
	three_sort(&*head_a);
	min = (*head_a)->data;
	while (i <= ft_lstsize(*head_b))
	{
		five_sort_movements(&*head_a, &*head_b, check_min(&*head_a, min));
		i++;
	}
	min = check_min(&*head_a, min);
	if ((*head_a)->data != min)
		finish_five_sort(&*head_a, min);
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
