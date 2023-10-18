/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:34:31 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/18 18:55:38 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	**ft_rra(t_prog stack)
{
	int	last;

	last = stack.stack[0][stack.num_a - 1];
	while ((stack.num_a - 1) != 0)
	{
		stack.stack[0][stack.num_a - 1] = stack.stack[0][stack.num_a - 2];
		stack.num_a--;
	}
	printf("rra\n");
	stack.stack[0][0] = last;
	return (stack.stack);
}

int	**ft_rrb(t_prog stack)
{
	int	last;

	last = stack.stack[1][stack.num_b - 1];
	while ((stack.num_b - 1) != 0)
	{
		stack.stack[1][stack.num_b - 1] = stack.stack[1][stack.num_b - 2];
		stack.num_b--;
	}
	printf("rrb\n");
	stack.stack[1][0] = last;
	return (stack.stack);
}

int	**ft_rrr(t_prog stack)
{
	stack.stack = ft_rra(stack);
	stack.stack = ft_rrb(stack);
	printf("rrr\n");
	return (stack.stack);
}
