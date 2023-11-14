/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:25:06 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/14 10:30:28 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*Push the first node from the list pointed by head_1 
to the first position in the list pointed by head_2.*/
void	push(t_node **head_1, t_node **head_2, int print)
{
	t_node	*tmp;

	if (head_1 != NULL)
	{
		tmp = *head_2;
		*head_2 = *head_1;
		*head_1 = (*head_1)->next;
		(*head_2)->next = tmp;
		if (print == 1)
			ft_printf("pa\n");
		else if (print == 2)
			ft_printf("pb\n");
	}
}
