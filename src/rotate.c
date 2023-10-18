/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:34:28 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/18 18:55:07 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	**ft_ra(t_prog stack)
{
	int	i;
	int	first;

	i = 0;
	first = stack.stack[0][0];
	while (i < stack.num_a - 1)
	{
		stack.stack[0][i] = stack.stack[0][i + 1];
		i++;
	}
	printf("ra\n");
	stack.stack[0][i] = first;
	return (stack.stack);
}

int	**ft_rb(t_prog stack)
{
	int	i;
	int	first;

	i = 0;
	first = stack.stack[1][0];
	while (i < stack.num_b - 1)
	{
		stack.stack[1][i] = stack.stack[1][i + 1];
		i++;
	}
	printf("rb\n");
	stack.stack[1][i] = first;
	return (stack.stack);
}

int	**ft_rr(t_prog stack)
{
	stack.stack = ft_ra(stack);
	stack.stack = ft_rb(stack);
	printf("rr\n");
	return (stack.stack);
}
