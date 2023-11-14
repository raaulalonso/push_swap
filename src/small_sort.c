/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:26:20 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 10:30:54 by raalonso         ###   ########.fr       */
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

void	small_sort(t_node **head_a, int num)
{
	if (num == 2)
		swap(&*head_a, 1);
	if (num == 3)
		three_sort(&*head_a);
}
